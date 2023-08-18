/*
입력
첫째 줄에 정점의 개수 N (1 ≤ N ≤ 100)이 주어진다. 둘째 줄부터 N개 줄에는 그래프의 인접 행렬이 주어진다. 
i번째 줄의 j번째 숫자가 1인 경우에는 i에서 j로 가는 간선이 존재한다는 뜻이고, 0인 경우는 없다는 뜻이다. i번째 줄의 i번째 숫자는 항상 0이다.
출력
총 N개의 줄에 걸쳐서 문제의 정답을 인접행렬 형식으로 출력한다. 정점 i에서 j로 가는 길이가 양수인 경로가 있으면 i번째 줄의 j번째 숫자를 1로, 없으면 0으로 출력해야 한다.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 20000000

int main()
{
    int n,m;
    cin >> n;
    
    vector<vector<int>> city(n+1,vector<int>(n+1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> city[i][j];
        }
    }
    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(city[i][k] && city[k][j])
                    city[i][j] = 1;
            }
    }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(city[i][j])
                cout << 1 << " ";
            else
               cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}