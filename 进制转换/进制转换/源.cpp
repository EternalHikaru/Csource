#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CHAR_to_int(char p)        //�������ַ��ʹ�д��ĸת��Ϊ����
{
	if (p >= '0' && p <= '9')
		return p - '0';
	else
		return p - 'A' + 10;
}

char int_to_char(int x)        //������ת��Ϊ�����ַ���Сд��ĸ
{
	if (x >= 0 && x <= 9)
		return x + '0';
	else
		return x - 10 + 'a';
}

char int_to_CHAR(int x)        //������ת��Ϊ�����ַ����д��ĸ
{
	if (x >= 0 && x <= 9)
		return x + '0';
	else
		return x - 10 + 'A';
}

void rev_str(char arr[], int length)    //�ַ�������
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

/*��m���ƵĴ���X�����ַ���arr_m[]ת��Ϊn�����ַ���arr_n[],����arr_n[]�ַ����ĳ���*/
void m_to_n(char arr_m[], char arr_n[], int m, int n, int m_len, int *pn)
{
	*pn = 0;            //n_out�ַ���������0
	int i, j;
	for (i = 0; i < m_len;) //���ϵؽ�X����n��������������arr_n[]��ֱ��XΪ0
	{
		int r = 0;                        //������0
		for (j = i; j < m_len; j++)        //������������n����������r
		{
			int temp = CHAR_to_int(arr_m[j]) + m * r;
			r = temp % n;
			arr_m[j] = int_to_CHAR(temp / n);
		}
		arr_n[(*pn)++] = int_to_char(r);               //������r��Ӧ���ַ�д��n����
		while (arr_m[i] == '0')              //�Թ�Ϊ0�ĸ�λ
			i++;
	}
	rev_str(arr_n, *pn);     //��arr_n[]����
	arr_n[*pn] = '\0';       //��arr_n[]ĩβ���ַ���������
}

int main()
{
	int m, n;
	while (scanf("%d%d", &m, &n) != EOF)
	{
		char m_in[10000] = { 0 };
		char n_out[10000] = { 0 };
		int m_len, n_len;              //�����ַ�������
		getchar();                     //�Ե�m��n��Ļ��з�
		gets(m_in);                    //����M������X
		m_len = strlen(m_in);          //����m_in�ַ�������
		int *pn = &n_len;              //����n_out�ַ�������ָ��
		m_to_n(m_in, n_out, m, n, m_len, pn);   //����ת��
		puts(n_out);                   //�������n������
	}
	//system("pause");
	return 0;
}