#define CRT_NO_SECURITY_WARNINGS
#include<stdio.h>
//ͳ�������ַ����и���ĸ�ĳ��ִ���

int main()
{
	int count[26] = { 0 },i=0;
	char ch;
	printf("�������ַ�����");
    do{
		ch = getchar();
		if (ch >= 'a'&&ch <= 'z')
			++count[ch - 'a'];
		else if (ch >= 'A'&&ch <= 'Z')
			++count[ch - 'A'];
	} while (ch != '\n');
	

	
	for (i = 0; i < 26; ++i){
		printf("%4c", 'a'+i);
	}
		printf("\n");
   
	for (i = 0; i < 26; ++i){
		printf("%4d", count[i]);
	}
	printf("\n");
	return 0;

}