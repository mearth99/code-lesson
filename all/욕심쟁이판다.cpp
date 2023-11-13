#include <bits/stdc++.h>
using namespace std;

int forest[501][501];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
struct panda{
    int y,x,r;
};
int N, Maxv=0;
void BFS(int y, int x){
    queue<panda> q;
    q.push({y,x,1});
    while(!q.empty()){
        panda cur = q.front(); q.pop();
        Maxv = max(Maxv,cur.r); 
        for(int i=0;i<4;i++){
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<N && forest[cur.y][cur.x] < forest[ny][nx]){
                q.push({ny,nx,cur.r+1});
            }
        }
    }
}


int main(){
    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> forest[i][j];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            BFS(i,j);
    cout << Maxv;
}