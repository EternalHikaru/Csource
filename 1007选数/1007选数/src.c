#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

int isPrime(int);
void ComNumSum(int, int, int);
int *p, num=0,n;



int main()
{
	int k,i;
	scanf("%d %d", &n, &k);//n��ѡk��
	p = (int *)calloc(n, sizeof(int));
	for (i = 0; i < n; ++i)
	{
		scanf("%d", p+i);
	}
	ComNumSum(k, 0, 0);
	printf("%d\n", num);
	free(p);
	return 0;
}

void ComNumSum(int k, int i, int sum)
{
	if (!k)//k==0ʱִ�У������ս����
	{
		if (isPrime(sum))
			num++;
	}
	else 
	for (i; i < n; ++i)
		ComNumSum(k - 1, i + 1, sum + p[i]);//**************************************//�ؼ�����(k-1)+(i+1)<=nʱ�ſ��ų�������k+i=nʱ����1������
	//k=4 i=2;
	//(1,1,p[0])->(0,2,p[0]+p[1])||(0,3,p[0]+p[2])||(0,4,p[0]+p[3])
	//(1,2,p[1])->(0,3,p[1]+p[2])||(0,4,p[0]+p[3])
	//(1.3.p[2])->(0,4,p[2]+p[3])
	//(1,4,p[3])

	//k=4,i=3
	//ͬ������
	//(2,1,p[0])����(1,2,p[0]+p[1])->(0,3,p[0]+p[1]+p[2])||(0,4,p[0]+p[1]+p[3]) ��(1,3,p[0]+p[2])->(0,4,p[0]+p[2]+p[3])
	//(2,2,p[1])����(1,3,p[1]+p[2])->(0,4,p[1]+p[2]+p[3])
	/***************/
}

int isPrime(int k)
{
	if (k % 2 == 0) return 0;
	if (k == 1||k==0) return 0;
	if (k >= 3)
	{
		for (int i = 2; i < (sqrt(k) + 1); ++i)
		{
			if (k%i == 0)return 0;
		}
		return 1;
	}
}

