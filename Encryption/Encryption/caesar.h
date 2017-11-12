#pragma once
// Encryption.cpp: 定义控制台应用程序的入口点。
//

#include"stdafx.h"
#include<iostream>
#include<cstdio>

using namespace std;

char* caesar1(char* src, char *dst)
{
	//for chars
	int key = 3;
	char *p = src;
	while (*dst != '\0')
	{
		if (*dst >= 'A'&& *dst <= 'Z')
		{
			*p = (char)((*dst - 65 + key) % 26 + 65);
		}
		else if (*dst >= 'a'&& *dst <= 'z')
		{
			*p = (char)((*dst - 97 + key) % 26 + 97);
		}
		else if (*dst >= '0'&& *dst <= '9')
		{
			*p = (char)((*dst - 48 + key) % 10 + 48);
		}
		else
		{
		}
		p++;
		dst++;
	}
	*p = '\0';
	return src;
}

void* caesar2(FILE* src, FILE *dst)
{
	//for files
	int key = 3;
	char p = fgetc(dst);
	while (p != EOF)
	{
		if (p >= 'A'&& p <= 'Z')
		{
			p = (char)((p - 65 + key) % 26 + 65);
		}
		else if (p >= 'a'&& p <= 'z')
		{
			p = (char)((p - 97 + key) % 26 + 97);
		}
		else if (p >= '0'&& p <= '9')
		{
			p = (char)((p - 48 + key) % 10 + 48);
		}
		else
		{
		}
		fputc(p, src);
		p = fgetc(dst);
	}
	fputc(EOF, src);
	return 0;
}

//int main()
//{
//	char *a = "fakljfklFALJFKSAJF741947912";
//	char *b = (char*)malloc(sizeof(a));
//	cout << a << endl;
//	caesar1(b, a);
//	cout << b;
//
//
//	FILE *read;
//	errno_t	err = 1;
//	if ((err = fopen_s(&read, "dst.txt", "w+")) != 0)
//	{
//		printf("The file can not be opend\n");
//		exit(1);
//	}
//	fputs(a, read);
//	fclose(read);
//
//	if ((err = fopen_s(&read, "dst.txt", "r+")) != 0)
//	{
//		printf("The file can not be opend\n");
//		exit(1);
//	}
//	FILE *write;
//	if ((err = fopen_s(&write, "src.txt", "w+")) != 0)
//	{
//		printf("The file can not be opend\n");
//		exit(1);
//	}
//	caesar2(write, read);
//	fclose(read);
//	fclose(write);
//
//	cout << endl;
//    return 0;
//}

