#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>
#include<string>


typedef struct node
{
	void* data;                   //������ָ��
	struct node* next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
	Node* front;                   //��ͷ
	Node* rear;                    //��β
	size_t length;                //���г���
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





//��ʼ������
LQueue* InitLQueue()
{
	LQueue* Q = (LQueue*)malloc(sizeof(LQueue));
	if (Q == NULL)
	{
		printf("�ڴ����ʧ��!");
		return NULL;
	}
	Q->front = NULL;
	Q->rear = NULL;
	Q->length = 0;
	return  Q;
}

//���ٶ���
void DestoryLQueue(LQueue* Q)
{
	Status DeLQueue(LQueue * Q);
	while (Q->front != NULL || Q->rear != NULL)
	{
		DeLQueue(Q);
	}
}

//�������Ƿ�Ϊ��
Status IsEmptyLQueue(const LQueue* Q)
{
	if (Q->front == NULL && Q->rear == NULL)
		return TRUE;
	else
		return FALSE;
}

//�鿴����ͷԪ��
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

//ȷ�����г���
int LengthLQueue(LQueue* Q, int* length)
{
	*length = Q->length;
	return TRUE;
}

//���
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

//����
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

//��ն���
void ClearLQueue(LQueue* Q)
{
	while (Q->front != NULL || Q->rear != NULL)
	{
		DeLQueue(Q);
	}
	Q->length = 0;

}

//��������
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

//�������
void output(LQueue* Q)
{
	if (IsEmptyLQueue(Q))
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	node* p = Q->front;
	printf("��ͷ->��β\n");
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

//���
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

//ѡ����������
void get_type()
{
	while (1)
	{
		type = '\0';
		printf("��ѡ������Ҫ������������ͣ���\n");
		printf("'i' Ϊ int�����Σ�\n 'f' Ϊ float���������� \n 'c' Ϊ char���ַ���!\n");
		scanf("%c", &type);
		while (getchar() != '\n');
		if (type == 'i' || type == 'f' || type == 'c')
			break;
		else
		{
			system("cls");
			printf("�������������ַ���\n");
		}
	}
}

//ѡ���֧
void get_data(void** data)
{
	if (type == 'i')
		get_int(data);
	else if (type == 'f')
		get_float(data);
	else if (type == 'c')
		get_char(data);
}

//��ȡ����
void get_int(void** data)
{
	printf("����������Ҫ�洢��������\n");
	int* p = (int*)malloc(sizeof(int));
	*p = 0;
	scanf("%d", p);
	*data = (void*)p;
	while (getchar() != '\n');
}

//��ȡ������Ԫ��
void get_float(void** data)
{
	printf("����������Ҫ�洢�ĸ�����:\n");
	float* p = (float*)malloc(sizeof(float));
	*p = 0.0;
	scanf("%f", p);
	*data = (void*)p;
	while (getchar() != '\n');
}

//��ȡ�ַ�Ԫ��
void get_char(void** data)
{
	printf("����������Ҫ�洢���ַ�:\n");
	char* p = (char*)malloc(sizeof(char));
	*p = '0';
	scanf("%c", p);
	*data = (void*)(p);
	while (getchar() != '\n');
}

//�˵�
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
			printf("**             ����ʹ�����¹���:                  **\n");
			printf("****************************************************\n");
			printf("****************************************************\n");
			printf("**            1.��ʼ������;                       **\n");
			printf("**            2.�������Ƿ�Ϊ��;                 **\n");
			printf("**            3.��ȡ����ͷԪ��;                   **\n");
			printf("**            4.���;                             **\n");
			printf("**            5.����;                             **\n");
			printf("**            6.�鿴�����ڵ�����Ԫ��;             **\n");
			printf("**            7.���г���;                         **\n");
			printf("**            8.��ն���;                         **\n");
			printf("**            0.���ٶ��в��˳�ϵͳ;               **\n");
			printf("****************************************************\n");
			printf("****************************************************\n");
			printf("��ѡ������Ҫʹ�õĹ���:\n");
			scanf("%d", &flag);
			while (getchar() != '\n');
			if (flag < 0 || flag>8)
			{
				system("cls");
				printf("�������Ӧ������!");
			}
			else
				break;
		}
		switch (flag)
		{
		case(1)://��ʼ������
			Q = InitLQueue();
			if (Q == NULL)
			{
				printf("�ڴ����ʧ�ܣ�\n");
				system("pause");
				break;
			}
			printf("���г�ʼ����ɣ�\n");
			system("pause");
			break;

		case(2)://�������Ƿ�Ϊ��
			if (IsEmptyLQueue(Q) == TRUE)
				printf("����Ϊ�գ�\n");
			else
				printf("���в�Ϊ�գ�\n");
			system("pause");
			break;

		case(3)://��ȡ����ͷԪ��
			if (IsEmptyLQueue(Q))
			{
				printf("����Ϊ�գ�\n��Ҫ��������ӣ�\n");
				system("pause");
				break;
			}
			else if (GetHeadLQueue(Q, data) == TRUE)
				LPrint(data);
			system("pause");
			break;

		case(4)://���
			if (type == 'i')
				get_int(&addData);
			else if (type == 'f')
				get_float(&addData);
			else
				get_char(&addData);
			if (EnLQueue(Q, addData) == TRUE)
				printf("�ѽ�Ԫ����ӣ�\n");
			else
			{
				printf("The room is full!!!\n");
				exit(-1);
			}
			system("pause");
			break;

		case(5)://����
			if (DeLQueue(Q) == TRUE)
				printf("�ѽ�Ԫ�س��ӣ�\n");
			else
				printf("����Ϊ�գ�\n");
			system("pause");
			break;

		case(6)://�������
			TraverseLQueue(Q, LPrint);
			//output(Q);
			system("pause");
			break;

		case(7)://�����г���
			if (LengthLQueue(Q, &length) == TRUE)
				printf("���еĳ���Ϊ %d.\n", length);
			else
			{
				printf("���ݴ���!!!\n");
				exit(-1);
			}
			system("pause");
			break;

		case(8)://��ն���
			ClearLQueue(Q);
			printf("��������գ�\n");
			system("pause");
			break;

		case(0)://���ٶ��в��ر�ϵͳ
			DestoryLQueue(Q);
			free(Q);
			printf("���������٣�\n�����ر�ϵͳ��\n��л����ʹ�ã�\n");
			system("pause");
			return;
		default:
			break;
		}
	}

}
