#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

int main()
{
	int *score, peoplenum, i,sum=0;
	double average, variance,tmp=0;

	printf("请输入数据个数：");
	scanf("%d", &peoplenum);
	score = (int *)calloc(peoplenum, sizeof(int));
	if (score != 0);
	printf("请输入所有成绩：");
	for (i = 0; i < peoplenum;++i)
	{
		scanf("%d", &score[i]);
	}
	for (i = 0; i < peoplenum; ++i)
	{
		sum += score[i];
	}
	average = sum / peoplenum;
	for (i = 0; i < peoplenum; ++i)
	{
		tmp += (score[i] - average)*(score[i] - average);
	}
	variance = tmp / peoplenum;
	printf("这%d个人的平均分是%f\n方差为%f\n", peoplenum, average, variance);
	system("pause");
	return 0;
}