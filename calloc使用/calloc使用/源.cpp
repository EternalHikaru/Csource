#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<math.h>

int main()
{
	int *score, peoplenum, i;
	double average=0, variance=0,standvariance;

	printf("���������ݸ�����");
	scanf("%d", &peoplenum);
	score = (int *)calloc(peoplenum, sizeof(int));
	if (score != 0){
		printf("���������гɼ���");
		for (i = 0; i < peoplenum; ++i)
		{
			scanf("%d", &score[i]);
		}
		for (i = 0; i < peoplenum; ++i)
		{
			average += score[i];
		}
		average = average / peoplenum;
		for (i = 0; i < peoplenum; ++i)
		{
			variance += (score[i] - average)*(score[i] - average);
		}
		variance = variance / peoplenum;
		standvariance = sqrt(variance);
		printf("��%d���˵�ƽ������%f\n����Ϊ%f\n��׼��Ϊ%f\n", peoplenum, average, variance,standvariance);
	}
	system("pause");
	return 0;

}