/*
    나머지 합
    수 N개 A1, A2, ..., AN이 주어진다. 이때, 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하는 프로그램을 작성하시오.
    즉, Ai + ... + Aj (i ≤ j) 의 합이 M으로 나누어 떨어지는 (i, j) 쌍의 개수를 구해야 한다.
*/
/*
    첫째 줄에 N과 M이 주어진다. (1 ≤ N ≤ 106, 2 ≤ M ≤ 103)
    둘째 줄에 N개의 수 A1, A2, ..., AN이 주어진다. (0 ≤ Ai ≤ 109)
    첫째 줄에 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 출력한다.
*/
/*
    수의 구간합을 구해 놓는다면 결국 수학적 식으로는 (sum[j]-sum[i]) mod M = 0이 되야한다.
    이는 곧 모듈러 공식에 의해 분배가 가능해 sum[j] % M == sum[i] % M 과 동치한다.
    따라서 서로 값이 동일한 구간 i j 를 구하면 된다. 누적합을 계산할 때마다 누적합의 나머지를 계산해
    각 나머지 개수를 ++ 시키고 이 나머지 개수는 순서를 따지지 않고 계산하니 nC2로 계산하면 된다.
    
    또한, 나머지가 정확하게 0으로 나누어 떨어지는 경우도 있기 때문에 마지막 결과값에 mod[0]을 추가헀다.
    
*/


#include <stdio.h>

int main()
{
    //선언
    int N,M;
    long long int out=0;
    long long int mod[1001]={0};
    long long int temp,sum=0;
    //입력
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        scanf("%lld",&temp);
        sum += temp;
        mod[sum%M]++;
    }
    //계산
    for(int i=0;i<M;i++)
    {
        out += mod[i]*(mod[i]-1)/2;
    }
    printf("%lld",out+mod[0]);
    
    return 0;
}