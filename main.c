#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include "parsexec.h"
//������Ҫ���ñ���ļ�
static char input[100] = "look around";
//����ȫ�ֱ���
static bool getInput(void)
{
	printf("\n--> ");
	//����Խ����ĳ���ϲ��������
	return fgets(input, sizeof input, stdin) != NULL;
	//fgets �����ռ����̵�����
}

int main()
{
	printf("Welcome to Little Cave Adventure.\n");
	while (parseAndExecute(input) && getInput());
	printf("\nBye!\n");
	return 0;
}