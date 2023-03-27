#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string>


typedef struct node
{
	void* data;                   //数据域指针
	struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
	Node* front;                   //队头
	Node* rear;                    //队尾
	size_t length;                //队列长度
} LQueue;

void get_type();
void get_int(void** data);
void get_float(void** data);
void get_char(void** data);
void show();
void LPrint(void* q);

typedef enum
{
	FALSE = 0, TRUE = 1
} Status;

char type;





//初始化队列
LQueue* InitLQueue()
{
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	if (Q == NULL)
	{
		printf("内存分配失败!");
		return NULL;
	}
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	return  Q;
}

//销毁队列
void DestoryLQueue(LQueue* Q)
{
	Status DeLQueue(LQueue * Q);
	while (Q->front != NULL || Q->rear != NULL)
	{
		DeLQueue(Q);
	}
}

//检查队列是否为空
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->front == NULL && Q->rear == NULL)
		return TRUE;
	else
		return FALSE;
}

//查看队列头元素
Status GetHeadLQueue(LQueue* Q, void* e)
{
	if (type == 'i')
		memcpy(e, Q->front->data, sizeof(int));
	if (type == 'f')
		memcpy(e, Q->front->data, sizeof(float));
	if (type == 'c')
		memcpy(e, Q->front->data, sizeof(char));

	return TRUE;
}

//确定队列长度
int LengthLQueue(LQueue* Q, int* length)
{
	*length = Q->length;
	return TRUE;
}

//入队
Status EnLQueue(LQueue* Q, void* data)
{
	node* p = (Node*)malloc(sizeof(node));
	if (p == NULL)
	{
		printf("Memory assignment failed!");
		return FALSE;
	}
	p->data = data;
	p->next = NULL;

	if (Q->front != NULL || Q->rear != NULL)
	{
		Q->rear->next = p;
		Q->rear = p;
	}
	else
	{
		Q->front = p;
		Q->rear = p;
	}
	Q->length++;
	return TRUE;
}

//出队
Status DeLQueue(LQueue* Q)
{
	void LPrint(void* q);
	node* p1;
	void* p2;
	if (Q->front != NULL || Q->rear != NULL)
	{
		p1 = Q->front;
		p2 = p1->data;
		if (Q->front->next == NULL)
		{
			Q->front = NULL;
			Q->rear = NULL;
		}
		else
			Q->front = p1->next;
		LPrint(p2);
		free(p1);
		free(p2);
		Q->length--;
		return TRUE;
	}
	else
	{
		printf("Queue is empty!");
		return FALSE;
	}
}

//清空队列
void ClearLQueue(LQueue* Q)
{
	while (Q->front != NULL || Q->rear != NULL)
	{
		DeLQueue(Q);
	}
	Q->length = 0;

}

//遍历函数
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q))
{
	if (IsEmptyLQueue(Q))
		return FALSE;
	int i = 1;
	node* p = Q->front;
	while (p != NULL)
	{
		if (i % 5 == 0)
			printf("\n");
		foo(p->data);
		p = p->next;
		i++;
	}
	printf("\n");
	return TRUE;
}

//输出队列
void output(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		printf("队列为空！\n");
		return;
	}
	node* p = Q->front;
	printf("队头->队尾\n");
	if (p != NULL)
	{
		while (p != NULL)
		{
			if (type == 'i')
				printf("%d->", *(int*)p->data);
			else if (type == 'f')
				printf("%f->", *(float*)p->data);
			else if (type == 'c')
				printf("%c->", *(char*)p->data);
			p = p->next;
		}
		printf("\n");
	}
}

//输出
void LPrint(void* q)
{
	if (type == 'i')//int
		printf("the int data is :%d\n", *(int*)q);
	else if (type == 'f')//float
		printf("the float data is :%f\n", *(float*)q);
	else if (type == 'c')//char
		printf("the char data is : %c\n", *(char*)q);
}

int main()
{
	get_type();
	show();
	return 0;
}

//选择输入类型
void get_type()
{
	while (1)
	{
		type = '\0';
		printf("请选择您想要输入的数据类型：、\n");
		printf("'i' 为 int（整形）\n 'f' 为 float（浮点数） \n 'c' 为 char（字符）!\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			system("cls");
			printf("请勿输入其他字符！\n");
		}
	}
}

//选择分支
void get_data(void** data)
{
	if (type == 'i')
		get_int(data);
	else if (type == 'f')
		get_float(data);
	else if (type == 'c')
		get_char(data);
}

//获取整形
void get_int(void** data)
{
	printf("请输入您想要存储的整数：\n");
	int* p = (int*)malloc(sizeof(int));
	*p = 0;
	scanf("%d", p);
	*data = (void*)p;
	while (getchar() != '\n');
}

//获取浮点数元素
void get_float(void** data)
{
	printf("请输入您想要存储的浮点数:\n");
	float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	scanf("%f", p);
	*data = (void*)p;
	while (getchar() != '\n');
}

//获取字符元素
void get_char(void** data)
{
	printf("请输入您想要存储的字符:\n");
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf("%c", p);
	*data = (void*)(p);
	while (getchar() != '\n');
}

//菜单
void show()
{
	int length = 0;
	LQueue* Q = InitLQueue();
	void* data = NULL;
	if (type == 'i')
		data = (void*)malloc(sizeof(int));
	else if (type == 'f')
		data = (void*)malloc(sizeof(float));
	else if (type == 'c')
		data = (void*)malloc(sizeof(char));
	void* addData = data;
	int flag;
	while (1)
	{
		while (1)
		{
			system("cls");
			flag = 0;
			printf("****************************************************\n");
			printf("**             您可使用如下功能:                  **\n");
			printf("****************************************************\n");
			printf("****************************************************\n");
			printf("**            1.初始化队列;                       **\n");
			printf("**            2.检查队列是否为空;                 **\n");
			printf("**            3.获取队列头元素;                   **\n");
			printf("**            4.入队;                             **\n");
			printf("**            5.出队;                             **\n");
			printf("**            6.查看队列内的所有元素;             **\n");
			printf("**            7.队列长度;                         **\n");
			printf("**            8.清空队列;                         **\n");
			printf("**            0.销毁队列并退出系统;               **\n");
			printf("****************************************************\n");
			printf("****************************************************\n");
			printf("请选择您想要使用的功能:\n");
			scanf("%d", &flag);
			while (getchar() != '\n');
			if (flag < 0 || flag>8)
			{
				system("cls");
				printf("请输入对应的数字!");
			}
			else
				break;
		}
		switch (flag)
		{
		case(1)://初始化队列
			Q = InitLQueue();
			if (Q == NULL)
			{
				printf("内存分配失败！\n");
				system("pause");
				break;
			}
			printf("队列初始化完成！\n");
			system("pause");
			break;

		case(2)://检查队列是否为空
			if (IsEmptyLQueue(Q) == TRUE)
				printf("队列为空！\n");
			else
				printf("队列不为空！\n");
			system("pause");
			break;

		case(3)://获取队列头元素
			if (IsEmptyLQueue(Q))
			{
				printf("队列为空！\n需要您进行添加！\n");
				system("pause");
				break;
			}
			else if (GetHeadLQueue(Q, data) == TRUE)
				LPrint(data);
			system("pause");
			break;

		case(4)://入队
			if (type == 'i')
				get_int(&addData);
			else if (type == 'f')
				get_float(&addData);
			else
				get_char(&addData);
			if (EnLQueue(Q, addData) == TRUE)
				printf("已将元素入队！\n");
			else
			{
				printf("The room is full!!!\n");
				exit(-1);
			}
			system("pause");
			break;

		case(5)://出队
			if (DeLQueue(Q) == TRUE)
				printf("已将元素出队！\n");
			else
				printf("队列为空！\n");
			system("pause");
			break;

		case(6)://输出队列
			TraverseLQueue(Q, LPrint);
			//output(Q);
			system("pause");
			break;

		case(7)://检测队列长度
			if (LengthLQueue(Q, &length) == TRUE)
				printf("队列的长度为 %d.\n", length);
			else
			{
				printf("数据错误!!!\n");
				exit(-1);
			}
			system("pause");
			break;

		case(8)://清空队列
			ClearLQueue(Q);
			printf("队列已清空！\n");
			system("pause");
			break;

		case(0)://销毁队列并关闭系统
			DestoryLQueue(Q);
			free(Q);
			printf("队列已销毁！\n即将关闭系统！\n感谢您的使用！\n");
			system("pause");
			return;
		default:
			break;
		}
	}

}
