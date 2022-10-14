/*
준서가 여행에 필요하다고 생각하는 N개의 물건이 있다. 각 물건은 무게 W와 가치 V를 가지는데, 해당 물건을 배낭에 넣어서 가면 준서가 V만큼 즐길 수 있다. 
아직 행군을 해본 적이 없는 준서는 최대 K만큼의 무게만을 넣을 수 있는 배낭만 들고 다닐 수 있다. 
준서가 최대한 즐거운 여행을 하기 위해 배낭에 넣을 수 있는 물건들의 가치의 최댓값을 알려주자.

첫 줄에 물품의 수 N(1 ≤ N ≤ 100)과 준서가 버틸 수 있는 무게 K(1 ≤ K ≤ 100,000)가 주어진다. 두 번째 줄부터 N개의 줄에 거쳐 각 물건의 무게 
W(1 ≤ W ≤ 100,000)와 해당 물건의 가치 V(0 ≤ V ≤ 1,000)가 주어진다.
입력으로 주어지는 모든 수는 정수이다.
*/

/*
이 문제는 배낭문제라고 알려진 DP문제다. 모든 가짓수를 하나하나 계산하면 2^n만큼 시간이 걸리지만, DP를 이용하여 이를 빠르게 할 수 있다.
DP의 장점은 계산된 문제를 다시 계산하지 않고 빠르게 사용한 다는 것이다. 따라서, 표를 만들어서 선택했음, 선택하지 않았음을 이용하면 최대의 즐거움을 구할 수 있을 것이다.
물건을 넣지 않는 경우 : 지금 선택한 무게가 전체 제한 무게를 초과한 경우다. D[i][j] = D[i-1][j] / W > K
물건을 넣을 수 있는 경우: 새로운 물건을 넣지 않는다, 새로운 물건을 넣는다.
이 둘중 max값을 선택하면 된다. D[i][j] = max(D[i-1][w],v_i + D[i-1][w-w_i])
*/
#include <stdio.h>
int max(int a,int b)
{
    return a>b ? a : b;
}
int main()
{
    int N,K;
    int D[101][100001]={0};
    int data[101][2];
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&data[i][0],&data[i][1]);
    }

    for(int i=1;i<=N;i++)
    {
        for(int w=1;w<=K;w++)
        {
            if(data[i][0]>w)
            {
                D[i][w] = D[i-1][w];
            }
            else
            {
                D[i][w] = max(D[i-1][w],data[i][1]+D[i-1][w-data[i][0]]);
            }
        }
    }
    printf("%d",D[N][K]);
    return 0;
}