/*
    구간합 구하기
    N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터 (x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.
    첫째 줄에 표의 크기 N과 합을 구해야 하는 횟수 M이 주어진다. (1 ≤ N ≤ 1024, 1 ≤ M ≤ 100,000) 둘째 줄부터 N개의 줄에는 
    표에 채워져 있는 수가 1행부터 차례대로 주어진다. 다음 M개의 줄에는 네 개의 정수 x1, y1, x2, y2 가 주어지며, 
    (x1, y1)부터 (x2, y2)의 합을 구해 출력해야 한다. 표에 채워져 있는 수는 1,000보다 작거나 같은 자연수이다. (x1 ≤ x2, y1 ≤ y2)
*/
/*
    그 동안 배열 하나로 계산했던 구간들과는 달리 이번 구간은 N*N으로 이루어져 있으며, 구간 합은 네모가 필요하다.
    이 경우도 계산이 1초기 때문에 한번의 연산으로 세팅되어야 한다. 구간합 계산은 (1,1)에서 현재 위치까지 있는 모든 수의 합으로 놓겠다.
    그러면 output의 계산식이 나타난다. (x1,y1) (x2,y2) = (x2,y2) -(x1,y2)-(x2,y1)+(x1,y1) 이 된다.
*/
#include <stdio.h>

int sum[1025][1025];

int main()
{
    //선언
    int N,M,temp;
    
    //입력
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            scanf("%d",&temp);
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + temp;
        }
        
    }
    //계산
    for(int k=0;k<M;k++)
    {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        printf("%d\n",sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]);
    }
    return 0;
}