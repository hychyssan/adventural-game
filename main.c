#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>
#include "parsexec.h"
//当我需要引用别的文件
static char input[100] = "look around";
//定义全局变量
static bool getInput(void)
{
	printf("\n--> ");
	//你可以将他改成你喜欢的内容
	return fgets(input, sizeof input, stdin) != NULL;
	//fgets 用于收集键盘的输入
}

int main()
{
	printf("Welcome to Little Cave Adventure.\n");
	while (parseAndExecute(input) && getInput());
	printf("\nBye!\n");
	return 0;
}