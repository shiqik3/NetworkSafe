#pragma once

#include<map>
#include<iostream>

static std::map<char, char> list
{
	{ 'a','1' },
	{ 'b','2' },
	{ 'c','3' },
	{ 'd','4' },
	{ 'e','5' },
	{ 'f','6' },
	{ 'g','0' },
	{ 'h','7' },
	{ 'i','8' },
	{ 'j','9' },
	{ 'k','K' },
	{ 'l','I' },
	{ 'm','M' },
	{ 'n','N' },
	{ 'o','O' },
	{ 'p','P' },
	{ 'q','Q' },
	{ 'r','R' },
	{ 's','S' },
	{ 't','T' },
	{ 'u','!' },
	{ 'v','@' },
	{ 'w','#' },
	{ 'x','$' },
	{ 'y','^' },
	{ 'z','*' }
};


char* singleTableSwap1(char* src, char *dst)
{
	//for chars
	char *p = src;
	while (*dst != '\0')
	{
		*p = list[*dst];
		p++;
		dst++;
	}
	*p = '\0';
	return src;
}

void* singleTableSwap2(FILE* src, FILE *dst)
{
	//for files
	char p = fgetc(dst);
	while (p != EOF)
	{
		p = list[p];
		fputc(p, src);
		p = fgetc(dst);
	}
	fputc(EOF, src);
	return 0;
}

//int main()
//{
//	char *a = "abcdefghijklmnxyz";
//	char *b = (char*)malloc(sizeof(a));
//	std::cout << a << std::endl;
//	singleTableSwap1(b, a);
//	std::cout << b;
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
//	singleTableSwap2(write, read);
//	fclose(read);
//	fclose(write);
//
//	std::cout << std::endl;
//	return 0;
//}