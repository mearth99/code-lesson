//15868 치킨배달

/* 문제
이 도시에 있는 치킨집은 모두 같은 프랜차이즈이다. 프렌차이즈 본사에서는 수익을 증가시키기 위해 일부 치킨집을 폐업시키려고 한다. 
오랜 연구 끝에 이 도시에서 가장 수익을 많이 낼 수 있는  치킨집의 개수는 최대 M개라는 사실을 알아내었다.

도시에 있는 치킨집 중에서 최대 M개를 고르고, 나머지 치킨집은 모두 폐업시켜야 한다. 어떻게 고르면, 도시의 치킨 거리가 가장 작게 될지 구하는 프로그램을 작성하시오.
 */
/* 입력
첫째 줄에 N(2 ≤ N ≤ 50)과 M(1 ≤ M ≤ 13)이 주어진다.

둘째 줄부터 N개의 줄에는 도시의 정보가 주어진다.

도시의 정보는 0, 1, 2로 이루어져 있고, 0은 빈 칸, 1은 집, 2는 치킨집을 의미한다. 집의 개수는 2N개를 넘지 않으며, 적어도 1개는 존재한다. 치킨집의 개수는 M보다 크거나 같고, 13보다 작거나 같다.
*/
/* 출력
첫째 줄에 폐업시키지 않을 치킨집을 최대 M개를 골랐을 때, 도시의 치킨 거리의 최솟값을 출력한다.
*/
/* 예상
폐업해야하는 치킨의 갯수는 이미 정해져있다. 시간 제한은 1초, 메모리 제한은 512mb이다. 같은 거리에 대한 계산이 계속 달라지기 때문에, 백트래킹을 이용해야한다.
배열 A를 만들어 이미 선점했는지 안했는지 파악한다. 선점 개수가 M개라면, 치킨 거리를 계산한다. 치킨 거리를 계산했다면, 값을 비교하고 다음으로 넘어간다.
치킨집의 좌표를 구하고, 집의 좌표를 구하고 서로만 일치시킨다면?
*/
/* 결과

*/
#include <iostream>
#include <cstdlib>
#include <limits.h>
using namespace std;
int dp[51][51];
int A[51][51];
int house[101][2]; //집의 개수
int chicken[14][2]; //치킨 집의 개수
int Ch[14][2]; //M개 선택한 치킨집의 갯수
int M,output=INT32_MAX;

void Ch_test(){
    for(int i=1;i<=M;i++){
        cout << Ch[i][0] << ", " << Ch[i][1] << endl;
    }
    cout << "-----------" << endl;
}

void distance(int N){
    int City = 0;
    int home = INT32_MAX;
    int distance;
    // Ch_test();
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(dp[i][j]==1){
                for(int k=1;k<=M;k++){
                    distance = abs((Ch[k][0] - i)) + abs(Ch[k][1] - j);
                    home = min(home, distance);
                }
                City += home;
                home = 9999999;
            }
        }
    }
    output = min(output,City);
}
void cacu(int N,int count){
    for(int i=1;i<=M;i++){

            if(A[i][j]==0 && dp[i][j]==2){
                A[i][j] = 1;
                count++;
                Ch[count][0] = i;
                Ch[count][1] = j;
                if(count == M){
                    distance(N);
                    A[i][j] = 0;
                    count--;
                }
                else{
                    cacu(N,count);
                    A[i][j] = 0;
                    count--;
                }
            }
            else
                continue;
        }
    }
}
int main()
{
    int N,h_c=1,c_c=1;
    cin >> N >> M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin >> dp[i][j];
            if(dp[i][j]==1){
                house[h_c][0] = i;
                house[h_c++][1] = j;
            }
            if(dp[i][j]==2){
                chicken[c_c][0] = i;
                chicken[c_c++][1] = j;
            }
        }
    }
    cacu(N,0);
    cout << output;
}
