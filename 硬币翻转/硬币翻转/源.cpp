#include<stdio.h>
#define min(a,b) a<b?a:b

int main()
{
	long long N, M, K,tmp1,tmp2,tmp3,tmp4;
	scanf("%lld %lld %lld", &N, &M, &K);
	tmp1 = N / K + 1;
	tmp2 = M / K + 1;
	tmp3 = N / K + N%K;
	tmp4 = M / K + M%K;
	if (K % 2 == 0){//KÅ¼
		if (N % 2 == 1 && M % 2 == 1) printf("-1");//NÆæMÆæ
		if (N % 2 == 0 && M % 2 == 1 && N%K == 0) printf("%lld", (N / K));//NÅ¼MÆæ
		if (N % 2 == 0 && M % 2 == 1 && N%K != 0) printf("%lld", tmp1);//NÅ¼MÆæ
		if (N % 2 == 1 && M % 2 == 0 && M%K == 0) printf("%lld", (M / K));
		if (N % 2 == 1 && M % 2 == 0 && M%K != 0) printf("%lld", tmp2);
		if (N % 2 == 0 && M % 2 == 0 && N%K == 0 && M%K == 0) printf("%lld", min(N / K, M / K));
		if (N % 2 == 0 && M % 2 == 0 && N%K != 0 && M%K == 0) printf("%lld", min(tmp1, M / K));
		if (N % 2 == 0 && M % 2 == 0 && N%K == 0 && M%K != 0) printf("%lld", min(N / K, tmp2));
		if (N % 2 == 0 && M % 2 == 0 && N%K != 0 && M%K != 0) printf("%lld", min(tmp1, tmp2));
	}
	if (K % 2 == 1){
		printf("%lld", min(tmp3, tmp4));
		putchar('\n');
	}
	return 0;
}