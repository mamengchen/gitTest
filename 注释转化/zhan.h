#pragma once

#include<stdlib.h>
#include<stdio.h>
#include<assert.h>


typedef int ShedDataType;

#define MAX_SIZE (100)

typedef struct ShedList {
	ShedDataType array[MAX_SIZE];
	ShedDataType top;     //栈顶
} ShedList;

//初始化
void ShedListInit(ShedList * pSeq)
{
	pSeq->top = 0;
}
//销毁
void ShedListDestroy(ShedList * pSeq)
{
	pSeq->top = 0;
}

//尾增
void PushShedList(ShedList * pSeq,ShedDataType data)
{
	pSeq->array[pSeq->top++] = data;
}

//尾删
void PopShedList(ShedList * pSeq)
{
	assert(pSeq != NULL);
	pSeq->top--;
}

//查看栈顶的数据
int FindShedNode(ShedList * pSeq)
{
	return pSeq->array[pSeq->top - 1];
}

//栈中有多少数据
int MachNode(ShedList * pSeq)
{
	return pSeq->top;
}

//满了
int NodeFull(ShedList *pSeq)
{
	return pSeq->top > MAX_SIZE;
}

//空了
int Nodevoid(ShedList * pSeq)
{
	
	return pSeq->top <= 0;
}

//判断栈序列的合法性
void JodgeShedList(ShedList * pSeq, int * arr)
{
	ShedList * cur = pSeq;
	int * str = arr;
	static i = 0;
    for ( i = 1; i < 6; i++)
    {
		PushShedList(cur, i);
		while (FindShedNode(cur) == *str)
		{
				PopShedList(cur);
				str++;
				if (cur->top == 0)
				{
					break;
				}
		}
	}
	if (cur->top == 0)
	{
		printf("此序列合法：\n");
	}
	else
	{
		printf("此序列不合法: \n");
	}
}

//判断括号是否匹配
void BracketMatch(const char * pSeq, int size)
{
	ShedList array;
	ShedListInit(&array);
	
	char ch;
	char topNode;
	for (int i = 0; i < size; i++)
	{
		ch = pSeq[i];
		switch (ch)
		{
		case '(':
		case'[':
		case'{':
			PushShedList(&array, (int)ch);
			break;
		case')':
		case']':
		case'}':
			if (Nodevoid(&array))
			{
				printf("右括号多\n");
				ShedListDestroy(&array);
				return;
			}
            
			topNode = FindShedNode(&array);
			PopShedList(&array);

			if (topNode == '('&& ch != ')')
			{
				printf("不匹配\n");
				return;
			}

			if (topNode == '{'&& ch != '}')
			{
				printf("不匹配\n");
				return;
			}

			if (topNode == '['&& ch != ']')
			{
				printf("不匹配\n");
				return;
			}
			break;
		default:
			break;
		}

	}
	if (!(Nodevoid(&array)))
	{
		printf("左括号多了\n");
		return;
	}
	printf("正常匹配\n");
}


void Test1()
{
	const char * seqs[] = {
		"(())abc{[(])}",
		"(()))abc{[]}",
		"(()()abc{[]}",
		"(())abc{[]()}"
	};

	for (int i = 0; i < 4; i++) {
		BracketMatch(seqs[i], strlen(seqs[i]));
	}
}


//逆波兰表达式（后缀表达式）Reversed Polish Notation.
typedef enum {
	OPERAND,	// 操作数类型
	OPERATOR	// 操作符类型
}	Type;

typedef enum {
	ADD, SUB, MUL, DIV
}	Operator;

typedef struct {
	Type type;
	int	operand;		// 操作数
	Operator operator;		// 操作符
}	Element;

int Math(Operator operator, int a, int b)
{
	switch (operator) {
	case ADD:
		return a + b;
	case SUB:
		return a - b;
	case MUL:
		return a * b;
	case DIV:
		return a / b;
	default:
		// 不应该出现
		assert(0);
	}
}

int ReversedPolishNotation(Element * pSeq, int size)
{
	ShedList State;
	ShedListInit(&State);
	int op1, op2;
	int result;
	for (int i = 0; i < size; i++)
	{
		Element e = pSeq[i];
		switch (e.type)
		{
		case OPERAND:
			PushShedList(&State, e.operand);
			break;
		case OPERATOR:
			op2 = FindShedNode(&State); PopShedList(&State);
			op1 = FindShedNode(&State); PopShedList(&state);

			result = Math(e.Operator, op1, op2);
			PushShedList(&State, result);
			break;
		default:
			break;
		}
	}
	assert(MachNode(&State) == 1);
	result = FindShedNode(&State);
	return result;
}


void Test2()
{
	Element expression[] = {
		{
			OPERAND,
			1,
			SUB	// 这个其实没有用，随便写
		},
		{
			OPERAND,
			2,
			SUB	// 这个其实没有用，随便写
		},
		{
			OPERATOR,
			-1,	// 这个其实没有用，随便写
			ADD
		},
		{
			OPERAND,
			3,
			SUB	// 这个其实没有用，随便写
		},
		{
			OPERATOR,
			-1,	// 这个其实没有用，随便写
			ADD
		}
	};

	int result = ReversePolishNotion(expression, 5);

	printf("result = %d\n", result);
}


void Test()
{
	int i = 0;
	ShedList array;
	ShedListInit(&array);
/*	PushShedList(&array, 1);
	PushShedList(&array, 2);
	PushShedList(&array, 3);
	PushShedList(&array, 4);
	PushShedList(&array, 5);
	PushShedList(&array, 6);
	i = FindShedNode(&array);
	printf("%d\n", i);
	i = MachNode(&array);
	printf("%d\n", i);*/

	int arr[] = { 5,3,4,1,2 };
	//ShedListInit(&array);
	int arr1[] = { 4,5,3,2,1 };
	JodgeShedList(&array, arr);
	//JodgeShedList(&array, arr1);
}