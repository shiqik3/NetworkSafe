#pragma once
// Encryption.cpp: 定义控制台应用程序的入口点。
//

#include<iostream>
#include<map>

static char* key = "monarchy";    //密钥
static char DIVISION = 'x';    //分割字符
static char vec[5][5] = { 0 };
static std::map<char, bool> list
{
	{ 'a',true },
	{ 'b',true },
	{ 'c',true },
	{ 'd',true },
	{ 'e',true },
	{ 'f',true },
	{ 'g',true },
	{ 'h',true },
	{ 'i',true },
	//{'j',true},
	//没有j，j和i并用一个格子
	{ 'k',true },
	{ 'l',true },
	{ 'm',true },
	{ 'n',true },
	{ 'o',true },
	{ 'p',true },
	{ 'q',true },
	{ 'r',true },
	{ 's',true },
	{ 't',true },
	{ 'u',true },
	{ 'v',true },
	{ 'w',true },
	{ 'x',true },
	{ 'y',true },
	{ 'z',true }
};

int check(char *c1, char *c2)
{
	int row1, row2;
	int col1, col2;
	int v1, v2;
	row1 = row2 = col1 = col2 = v1 = v2 = 5;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (vec[i][j] == *c1)
			{
				row1 = i;
				col1 = j;
			}
			if (vec[i][j] == *c2)
			{
				row2 = i;
				col2 = j;
			}
		}
		if (row1 != 5 && row2 != 5)
		{
			break;
		}
	}
	if (row1 == row2&&row1 != 5)
	{
		*c1 = vec[row1][(col1 + 1) % 5];
		*c2 = vec[row2][(col2 + 1) % 5];
		return 1;    //代表在同一行
	}
	else if (col1 == col2&&col1 != 5)
	{
		*c1 = vec[(row1 + 1) % 5][col1];
		*c2 = vec[(row2 + 1) % 5][col2];
		return 2;    //代表在同一列
	}
	else
	{
		*c1 = vec[row1][col2];
		*c2 = vec[row2][col1];
		return 0;
	}
}

char swapjtoi(char s)
{
	if (s == 'j')
	{
		return 'i';
	}
	else
		return s;
}

int init()
{
	char *p = key;
	int i = 0, j = 0;
	char c = 'a' - 1;
	while (*p != '\0')
	{
		vec[i][j] = *p;
		list[*p] = false;
		if (++j == 5) {
			i++;
			j = 0;
		}
		if (i > 4)
		{
			break;
		}
		p++;
	}
	for (; i < 5; i++)
	{
		for (; j < 5; j++)
		{
			while (!list[++c]) {}
			vec[i][j] = c;
		}
		if (j == 5)
		{
			j = 0;
		}
	}
	return 0;
}


char* playfair1(char* src, char *dst)
{
	//for chars
	init();
	char *p = src;
	char c1;
	char c2;
	while (*dst != '\0')
	{
		c1 = swapjtoi(*dst);
		if (*(dst + 1) == '\0')
		{
			c2 = DIVISION;
		}
		else
		{
			c2 = swapjtoi(*dst + 1);
		}
		//
		if (c1 == c2)
		{
			char s1 = c2;
			char s2 = DIVISION;
			c2 = DIVISION;
			check(&c1, &c2);
			check(&s1, &s2);
			*p = c1;
			*(p + 1) = c2;
			*(p + 2) = s1;
			*(p + 3) = s2;
			p += 4;
		}
		else
		{
			check(&c1, &c2);
			*p = c1;
			*(p + 1) = c2;
			p += 2;
		}
		dst += 2;;
	}
	*p = '\0';
	return src;
}

void* playfair2(FILE* src, FILE *dst)
{
	//for files
	init();
	char p;
	char c1;
	char c2;
	while ((p = fgetc(dst)) && p != EOF)
	{
		c1 = swapjtoi(p);
		if ((p = fgetc(dst)) && p != EOF)
		{
			c2 = swapjtoi(p);
		}
		else
		{
			ungetc(p, dst);
			c2 = DIVISION;
		}
		//
		if (c1 == c2)
		{
			char s1 = c2;
			char s2 = DIVISION;
			c2 = DIVISION;
			check(&c1, &c2);
			check(&s1, &s2);
			fputc(c1, src);
			fputc(c2, src);
			fputc(s1, src);
			fputc(s2, src);
		}
		else
		{
			check(&c1, &c2);
			fputc(c1, src);
			fputc(c2, src);
		}
	}
	fputc(EOF, src);
	return src;
}

//int main()
//{
//	char *a = "abcdefghijklmnxyz";
//	char *b = (char*)malloc(sizeof(a + 42));
//	std::cout << a << std::endl;
//	playfair1(b, a);
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
//	playfair2(write, read);
//	fclose(read);
//	fclose(write);
//
//	std::cout << std::endl;
//	return 0;
//}


