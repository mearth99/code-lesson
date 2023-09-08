/*
그래프에서 연결된 모든 노드를 확인해보고 최소 경로를 찾는다.
이후 방문하지 않았던 노드를 확인해, 기존 비용보다 저렴한 경로를 확인하여 갱신해나간다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 2100000000
using namespace std;
struct plane{
    int dest;
    int cost;
    int times;
    plane(int d, int c, int t){
        dest = d;
        cost = c;
        times = t;
    }
};
struct cmp{
    bool operator()(const plane &p1, const plane &p2){
            return p1.times > p2.times;
    }
};

vector<plane> airport[101];
int node[101][10001];
void dijk(int n,int m){
    priority_queue<plane,vector<plane>,cmp> q;
    q.push(plane(1,0,0));
    node[1][0] = 0; //출발지점의 비용은 0이다.
    while(!q.empty()){
        plane target = q.top(); q.pop();
        if(node[target.dest][target.cost]<target.times) continue;
        for(auto it : airport[target.dest]){
            int nextcost = it.cost + target.cost; //현재 노드까지 탐사 비용과 다음 노드로 향하는 비용을 덧셈한다.
            int nexttime = it.times + target.times;
            if(nextcost>m) continue;
            if(nexttime < node[it.dest][nextcost]){
                node[it.dest][nextcost] = nexttime;
                q.push(plane(it.dest,nextcost,nexttime));
            }
        } 
    }
}
int main(){
    int T,n,m,k;
    cin >> T;
    while(T>0){
        cin >> n >> m >> k;
        for(int i=0;i<k;i++){
            int from,to,cost,delay;
            cin >> from >> to >> cost >> delay;
            airport[from].push_back(plane(to,cost,delay));
        }
        dijk(n,m);
        int value = INF;
        for(int i=1;i<=m;i++)
            value = min(value,node[n][i]);
        if(value==INF)
            cout <<"Poor KCM" << '\n';
        else
            cout << value << '\n';
        for(int i=0;i<=n;i++)
            airport[i].clear();
        for(int i=1;i<=n;i++)
            for(int j=0;j<=m;j++)
                node[i][j] = INF;
        T--;
    }
    return 0;
}