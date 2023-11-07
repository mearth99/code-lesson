#include<iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

struct climb{
    int x, y, v, flag, len;
};
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int N, K, output;
vector<int> outputs;
bool visited[8][8];

void BFS(int sy, int sx, int sv, bool sflag, int slen,  vector<vector<int>> mountain){
    queue<climb> q;       
    q.push({sx,sy,sv,sflag,slen});
    while(!q.empty()){
        int x = q.front().x; 
        int y = q.front().y;
        int v = q.front().v;
        int flag = q.front().flag;
        int len = q.front().len;
        output = max(output,len);
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx>=0 && nx<N && ny >=0 && ny<N && !visited[ny][nx]){
                if(mountain[ny][nx] < v){
                    q.push({nx,ny,mountain[ny][nx],flag,len+1});
                    visited[ny][nx] = true;
                }
                else if(mountain[ny][nx]-K < v && flag){
                    q.push({nx,ny,mountain[ny][nx]-1,0,len+1});
                    visited[ny][nx] = true;
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{
		int Maxv=0;
        output = 0;
        cin >> N >> K;
        vector<vector<int>> mountain(N,vector<int>(N));
        for(int i=0;i<N;i++){
        	for(int j=0;j<N;j++){
            	cin >> mountain[i][j];
            	Maxv = max(Maxv,mountain[i][j]);
            }
        }
          
        for(int i=0;i<N;i++){
        	for(int j=0;j<N;j++){
            	if(mountain[i][j]==Maxv)
                    BFS(i, j, mountain[i][j], true, 1, mountain);
                    memset(visited,0,sizeof(visited));
            }
        }
        outputs.push_back(output);
        for(int i=0;i<N;i++){
            mountain[i].clear();
        }
        mountain.clear();
	}
    for(auto it : outputs)
        cout << it << '\n';
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}