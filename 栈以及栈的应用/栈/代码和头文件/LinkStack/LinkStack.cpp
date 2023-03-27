#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;             //数据域
	struct StackNode* next;   //指向下一节点
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;           //栈顶指针
	int	count;                  //栈的长度
}LinkStack;


//初始化栈,不知道如何使用
//Status initLStack(LinkStack* s)
//{
//	s = (LinkStack*)malloc(sizeof(LinkStack));
//	if (s == NULL)
//	{
//		printf("内存分配失败！");
//		return ERROR;
//	}
//	s->top = NULL;
//	s->count = 0;
//	printf("count:%d", s->count);
//	system("pause");
//	return SUCCESS;
//}

LinkStack* creatstack()
{
	LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
	if (s == NULL)
	{
		printf("内存分配失败！");
		return NULL;
	}
	s->top = NULL;
	s->count = 0;
	return s;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack* s)
{
	if (s->count == 0 || !s->top)
		return SUCCESS;
	else
		return ERROR;
}

//得到栈顶元素
Status getTopLStack(LinkStack* s, ElemType* e)
{
	if (s->top)
	{
		*e = s->top->data;
		return SUCCESS;
	}
	else
		return ERROR;
}

//输出栈()
void output(LinkStack* s)
{
	LinkStackPtr p = s->top;
	if (isEmptyLStack(s))
	{
		printf("栈为空！");
		return;
	}
	if (p != NULL)
	{
		printf("栈顶");
		while (p != NULL)
		{
			printf("->%d", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

//清空栈()
Status clearLStack(LinkStack* s)
{
	LinkStackPtr p1, p2;
	p1 = p2 = s->top;
	while (p1 != NULL)
	{
		p2 = p2->next;
		free(p1);
		p1 = p2;
	}
	s->top = NULL;
	s->count = 0;
	return SUCCESS;
}

//销毁栈
Status destroyLStack(LinkStack* s)
{

	LinkStackPtr p1, p2;
	p1 = p2 = s->top;
	while (p1 != NULL)
	{
		p2 = p2->next;
		free(p1);
		p1 = p2;
	}
	free(s);
	return SUCCESS;

}

//检测栈长度
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;
	return SUCCESS;
}

//入栈
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("内存分配失败！");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//出栈
Status popLStack(LinkStack* s, ElemType* data)
{
	LinkStackPtr p = NULL;
	if (isEmptyLStack(s))
		return ERROR;
	*data = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	s->count--;
	return SUCCESS;
}


//菜单
void menu()
{
	printf("****************************************************\n");
	printf("****************************************************\n");
	printf("**              1、初始化栈；                     **\n");
	printf("**              2、输出栈；                       **\n");
	printf("**              3、入栈；                         **\n");
	printf("**              4、出栈；                         **\n");
	printf("**              5、是否空栈；                     **\n");
	printf("**              6、清空栈；                       **\n");
	printf("**              7、销毁栈；                       **\n");
	printf("**              8、得到栈顶元素；                 **\n");
	printf("**              9、检测栈长度；                   **\n");
	printf("**              0、关闭系统；                     **\n");
	printf("****************************************************\n");
	printf("****************************************************\n");
	printf("请输入对应的数字：");

}

int main()
{
	int data = 0, choice;
	char judge;
	LinkStack* s = NULL;
	//LinkStack *s = (LinkStack*)malloc(sizeof(LinkStack));
	//s->top = NULL;
	//s->count = 0;
	while (1)
	{
		system("cls");
		menu();
		scanf("%d", &choice);
		judge = getchar();
		while (judge != '\n')
		{
			printf("输入错误！\n请重新输入：");
			scanf("%d", &choice);
			judge = getchar();
		}

		switch (choice)
		{
		case 1://初始化栈
			s = creatstack();
			printf("初始化成功！\n");
			system("pause");
			break;

		case 2://输出栈
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			output(s);
			system("pause");
			break;

		case 3://入栈
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			printf("请输入进栈的值：");
			scanf("%d", &data);
			while (judge != '\n')
			{
				printf("输入错误！\n请重新输入：");
				scanf("%d", &data);
				judge = getchar();
			}
			//if (pushLStack(&s, data))
			if (pushLStack(s, data))
				printf("入栈成功！");
			else
				printf("入栈失败！");
			system("pause");
			break;

		case 4://出栈
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			if (isEmptyLStack(s))
			{
				printf("栈为空！\n请先初始化栈！");
				system("pause");
				break;
			}
			if (popLStack(s, &data))
				printf("出栈的元素为：%d", data);
			else
				printf("出栈失败！");
			system("pause");
			break;

		case 5://是否空栈
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			if (isEmptyLStack(s))
				printf("栈为空！");
			else
				printf("栈不为空！");
			system("pause");
			break;

		case 6://清空栈
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			if (clearLStack(s))
				printf("栈已清空！");
			else
				printf("清空失败！");
			system("pause");
			break;

		case 7://销毁栈
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			if (destroyLStack(s))
				printf("栈已销毁！");
			else
				printf("销毁失败！");
			system("pause");
			break;


		case 8://得到栈顶元素
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			if (getTopLStack(s, &data))
				printf("栈顶元素为：%d", data);
			else
				printf("栈为空！");
			system("pause");
			break;

		case 9://检测栈长度
			if (s == NULL)
			{
				printf("栈不存在！\n请先初始化栈！\n");
				system("pause");
				break;
			}
			if (LStackLength(s, &data))
				printf("栈的长度为：%d\n", data);
			system("pause");
			break;

		case 0://关闭系统
			if (destroyLStack(s))
				printf("栈已销毁！\n即将关闭系统！\n感谢您的使用！\n");
			else if (s == NULL)
				printf("即将关闭系统！\n感谢您的使用！\n");
			system("pause");
			return 0;
		}

	}

	return 0;
}