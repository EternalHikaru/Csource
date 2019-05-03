#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CHAR_to_int(char p)        //将数字字符和大写字母转换为整数
{
	if (p >= '0' && p <= '9')
		return p - '0';
	else
		return p - 'A' + 10;
}

char int_to_char(int x)        //将整数转换为数字字符或小写字母
{
	if (x >= 0 && x <= 9)
		return x + '0';
	else
		return x - 10 + 'a';
}

char int_to_CHAR(int x)        //将整数转换为数字字符或大写字母
{
	if (x >= 0 && x <= 9)
		return x + '0';
	else
		return x - 10 + 'A';
}

void rev_str(char arr[], int length)    //字符串逆置
{
	int mid = length / 2;
	int i;
	for (i = 0; i < mid; i++)
	{
		char temp = arr[i];
		arr[i] = arr[length - 1 - i];
		arr[length - 1 - i] = temp;
	}
}

/*将m进制的大数X所在字符串arr_m[]转换为n进制字符串arr_n[],并求arr_n[]字符串的长度*/
void m_to_n(char arr_m[], char arr_n[], int m, int n, int m_len, int *pn)
{
	*pn = 0;            //n_out字符串长度清0
	int i, j;
	for (i = 0; i < m_len;) //不断地将X除以n，并将余数存入arr_n[]，直到X为0
	{
		int r = 0;                        //余数清0
		for (j = i; j < m_len; j++)        //将大整数除以n，余数存入r
		{
			int temp = CHAR_to_int(arr_m[j]) + m * r;
			r = temp % n;
			arr_m[j] = int_to_CHAR(temp / n);
		}
		arr_n[(*pn)++] = int_to_char(r);               //将余数r对应的字符写入n数组
		while (arr_m[i] == '0')              //略过为0的高位
			i++;
	}
	rev_str(arr_n, *pn);     //将arr_n[]逆置
	arr_n[*pn] = '\0';       //在arr_n[]末尾加字符串结束符
}

int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		char m_in[10000] = { 0 };
		char n_out[10000] = { 0 };
		int m_len, n_len;              //两个字符串长度
		getchar();                     //吃掉m，n后的换行符
		gets(m_in);                    //读入M进制数X
		m_len = strlen(m_in);          //计算m_in字符串长度
		int *pn = &n_len;              //定义n_out字符串长度指针
		m_to_n(m_in, n_out, m, n, m_len, pn);   //进制转换
		puts(n_out);                   //输出所求n进制数
	}
	//system("pause");
	return 0;
}