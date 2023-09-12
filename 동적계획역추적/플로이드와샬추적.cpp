/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 21000000
using namespace std;

int graph[101][101];
int road[101][101];
int main(){
    for(int i=0;i<101;i++)
        fill_n(graph[i],101,INF);
    int n,m,start,end,target;
    vector<int> course;
    cin >> n;
    cin >> m;
    for(int i=1;i<=n;i++)
        graph[i][i] = 0;
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from][to] = min(graph[from][to],cost);
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(graph[i][j]>graph[i][k]+graph[k][j])
                    graph[i][j] = graph[i][k]+graph[k][j];
                    road[i][j] = k;
            }
        }
    }

    return 0;
}