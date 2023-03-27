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
	ElemType data;             //������
	struct StackNode* next;   //ָ����һ�ڵ�
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;           //ջ��ָ��
	int	count;                  //ջ�ĳ���
}LinkStack;


//��ʼ��ջ,��֪�����ʹ��
//Status initLStack(LinkStack* s)
//{
//	s = (LinkStack*)malloc(sizeof(LinkStack));
//	if (s == NULL)
//	{
//		printf("�ڴ����ʧ�ܣ�");
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
		printf("�ڴ����ʧ�ܣ�");
		return NULL;
	}
	s->top = NULL;
	s->count = 0;
	return s;
}

//�ж�ջ�Ƿ�Ϊ��
Status isEmptyLStack(LinkStack* s)
{
	if (s->count == 0 || !s->top)
		return SUCCESS;
	else
		return ERROR;
}

//�õ�ջ��Ԫ��
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

//���ջ()
void output(LinkStack* s)
{
	LinkStackPtr p = s->top;
	if (isEmptyLStack(s))
	{
		printf("ջΪ�գ�");
		return;
	}
	if (p != NULL)
	{
		printf("ջ��");
		while (p != NULL)
		{
			printf("->%d", p->data);
			p = p->next;
		}
		printf("\n");
	}
}

//���ջ()
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

//����ջ
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

//���ջ����
Status LStackLength(LinkStack* s, int* length)
{
	*length = s->count;
	return SUCCESS;
}

//��ջ
Status pushLStack(LinkStack* s, ElemType data)
{
	LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
	if (p == NULL)
	{
		printf("�ڴ����ʧ�ܣ�");
		return ERROR;
	}
	p->data = data;
	p->next = s->top;
	s->top = p;
	s->count++;
	return SUCCESS;
}

//��ջ
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


//�˵�
void menu()
{
	printf("****************************************************\n");
	printf("****************************************************\n");
	printf("**              1����ʼ��ջ��                     **\n");
	printf("**              2�����ջ��                       **\n");
	printf("**              3����ջ��                         **\n");
	printf("**              4����ջ��                         **\n");
	printf("**              5���Ƿ��ջ��                     **\n");
	printf("**              6�����ջ��                       **\n");
	printf("**              7������ջ��                       **\n");
	printf("**              8���õ�ջ��Ԫ�أ�                 **\n");
	printf("**              9�����ջ���ȣ�                   **\n");
	printf("**              0���ر�ϵͳ��                     **\n");
	printf("****************************************************\n");
	printf("****************************************************\n");
	printf("�������Ӧ�����֣�");

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
			printf("�������\n���������룺");
			scanf("%d", &choice);
			judge = getchar();
		}

		switch (choice)
		{
		case 1://��ʼ��ջ
			s = creatstack();
			printf("��ʼ���ɹ���\n");
			system("pause");
			break;

		case 2://���ջ
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			output(s);
			system("pause");
			break;

		case 3://��ջ
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			printf("�������ջ��ֵ��");
			scanf("%d", &data);
			while (judge != '\n')
			{
				printf("�������\n���������룺");
				scanf("%d", &data);
				judge = getchar();
			}
			//if (pushLStack(&s, data))
			if (pushLStack(s, data))
				printf("��ջ�ɹ���");
			else
				printf("��ջʧ�ܣ�");
			system("pause");
			break;

		case 4://��ջ
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			if (isEmptyLStack(s))
			{
				printf("ջΪ�գ�\n���ȳ�ʼ��ջ��");
				system("pause");
				break;
			}
			if (popLStack(s, &data))
				printf("��ջ��Ԫ��Ϊ��%d", data);
			else
				printf("��ջʧ�ܣ�");
			system("pause");
			break;

		case 5://�Ƿ��ջ
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			if (isEmptyLStack(s))
				printf("ջΪ�գ�");
			else
				printf("ջ��Ϊ�գ�");
			system("pause");
			break;

		case 6://���ջ
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			if (clearLStack(s))
				printf("ջ����գ�");
			else
				printf("���ʧ�ܣ�");
			system("pause");
			break;

		case 7://����ջ
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			if (destroyLStack(s))
				printf("ջ�����٣�");
			else
				printf("����ʧ�ܣ�");
			system("pause");
			break;


		case 8://�õ�ջ��Ԫ��
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			if (getTopLStack(s, &data))
				printf("ջ��Ԫ��Ϊ��%d", data);
			else
				printf("ջΪ�գ�");
			system("pause");
			break;

		case 9://���ջ����
			if (s == NULL)
			{
				printf("ջ�����ڣ�\n���ȳ�ʼ��ջ��\n");
				system("pause");
				break;
			}
			if (LStackLength(s, &data))
				printf("ջ�ĳ���Ϊ��%d\n", data);
			system("pause");
			break;

		case 0://�ر�ϵͳ
			if (destroyLStack(s))
				printf("ջ�����٣�\n�����ر�ϵͳ��\n��л����ʹ�ã�\n");
			else if (s == NULL)
				printf("�����ر�ϵͳ��\n��л����ʹ�ã�\n");
			system("pause");
			return 0;
		}

	}

	return 0;
}