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

void dijk(int start, vector<vector<pair<int,int>>> &graph, vector<int> &node){
    queue<pair<int,int>> q;
    q.push({start,0});
    node[start] = 0; //출발지점의 비용은 0이다.
    while(!q.empty()){
        int target = q.front().first;
        int cost = q.front().second;
        if(node[target]<cost) continue; //현재 탐사하고 있는 비용이 기존 비용보다 많으면 탐사할 필요가 없다.
        for(auto it : graph[target]){
            int nextcost = it.second + cost; //현재 노드까지 탐사 비용과 다음 노드로 향하는 비용을 덧셈한다.
            if(nextcost<node[it.first]) //현재 탐사 비용이 기존 비용보다 더 저렴하다면 탐사한다.
            {
               node[it.first] = nextcost;
               q.push({it.first,nextcost}); 
            }
        } 
    }
}
int main(){
    int n,m;
    vector<vector<pair<int,int>>> graph;
    vector<int> node(n,INF);
    for(int i=0;i<m;i++){
        int from, to, cost;
        graph[from].push_back({to,cost});
        graph[to].push_back({from,cost});
    }
    dijk(0,graph,node);
    return 0;
}