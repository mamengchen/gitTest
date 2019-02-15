//#pragma once
//
//#define _CRT_SECURE_NO_WARNINGS
//
//#include<stdio.h>
//#include<stdlib.h>
//#include<assert.h>
//
//typedef enum State{
//	CodeState,  //代码状态
//	MissSprit,  //遇到/
//	C_StyleNote,   //c风格注释
//	Cpp_StyleNote, //c++风格注释
//	MissBit,     //遇到*
//} State;
//
//void Convert(FILE * pIn, FILE * pOut)
//{
//	State state = CodeState;
//	const char * state_desc[] = {
//		"代码状态",
//		" 遇到/ ",
//		"c风格注释",
//		"c++风个注释",
//		"遇到*"
//	};
//	int ch;
//	int nextch = 0;
//	while (1)
//	{
//		ch = fgetc(pIn);
//		if (ch == EOF)
//		{
//			break;
//		}
//		printf("读到字符：%c->.当前状态：%s->\n",(char)ch,state_desc[state]);
//		switch (state)
//		{
//		case CodeState:
//			if (ch == '/')
//			{
//				state = MissSprit;
//			}
//			fputc(ch, pOut);
//			break;
//		case MissSprit:
//			if (ch == '/')
//			{
//				state = Cpp_StyleNote;
//				fputc(ch, pOut);
//			}
//			else if (ch == '*')
//			{
//				state = C_StyleNote;
//				fputc('/', pOut);
//			}
//			else
//			{
//				state = CodeState;
//				fputc(ch, pOut);
//			}
//			break;
//		case Cpp_StyleNote:
//			if (ch == '\n')
//			{
//				state = CodeState;
//			}
//
//			break;
//		case C_StyleNote:
//			if (ch == '*')
//			{
//				state = MissBit;
//				fputc('/', pOut);
//
//			}
//			else {
//				fputc(ch, pOut);
//				if (ch == '\n') {
//					fprintf(pOut, '//');
//				}
//			}
//			break;
//		case MissBit:
//			if (ch == '/')
//			{
//				state = CodeState;
//				fputc(ch, pOut);
//				nextch = fgetc(pIn);
//				if (nextch != '\n') {
//					fputc('\n', pOut);
//				}
//				ungetc(nextch, pIn);
//			}
//			else if (ch == '*')
//			{
//				state = MissBit;
//				fputc('*', pOut);
//				fputc(ch, pOut);
//			}
//			else
//			{
//				state = C_StyleNote;
//				fputc('*', pOut);
//			}
//		default:
//			break;
//		}
//		printf("%s\n", state_desc[state]);
//	}
//}
//
//int main()
//{
//	FILE *pIn = fopen("input.c", "r");
//	if (pIn == NULL) {
//		perror("fopen input");
//		return 1;
//	}
//
//
//	FILE *pOut = fopen("output.c", "w");
//	if (pOut == NULL) {
//		perror("fopen output");
//		fclose(pIn);
//		return 1;
//	}
//
//	Convert(pIn, pOut);
//
//	fclose(pOut);
//	fclose(pIn);
//	system("pause");
//	return 0;
//}





