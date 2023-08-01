#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
vector<vector<vector<int>>> pulzzes;
queue<pair<int,int>> making;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
void remove_y(vector<vector<int>> &pulzze){//세로줄을 하나 옆으로 당긴다. |
    bool flag = true;
    for(int i=0;i<pulzze.size();i++)
        if(pulzze[i][0]) flag = false;
    if(flag)
        for(int i=0;i<pulzze.size();i++){
            for(int j=1;j<pulzze.size();j++)
                pulzze[i][j-1] = pulzze[i][j];
            pulzze[i][pulzze.size()-1] = 0;
        }  
}
void remove_x(vector<vector<int>> &pulzze){//가로줄을 하나 위로 당긴다. -
    bool flag = true;
    for(int i=0;i<pulzze.size();i++)
        if(pulzze[0][i]) flag = false;
    if(flag){
        for(int i=1;i<pulzze.size();i++){
            for(int j=0;j<pulzze.size();j++)
                pulzze[i-1][j] = pulzze[i][j];
        }
        for(int i=0;i<pulzze.size();i++)
            pulzze[pulzze.size()-1][i] = 0;
    }
}
void turn(vector<vector<int>>& pulzze){
    vector<vector<int>> temp(6,vector<int>(6));
    copy(pulzze.begin(),pulzze.end(),temp.begin());
    for(int i=0; i<temp.size(); i++)
        for(int j=0; j<temp.size(); j++)
            pulzze[i][j] = temp[temp.size() - j -1][i];
}
    

void makepulzze(vector<vector<int>> &table,vector<vector<int>> pulzze){
    while(!making.empty()){
        int y = making.front().first;
        int x = making.front().second;
        making.pop();
        table[y][x] = 0;
        pulzze[y][x] = 1;
        for(int i=0;i<4;i++){
            int ny = y + dy[i];
            int nx = x + dx[i];
            if(nx>=0&&nx<table.size()&&ny>=0&&ny<table.size()){
                if(table[ny][nx])
                    making.push(make_pair(ny,nx));
            }
        }
    }
    while(!pulzze[0][0]){
        remove_y(pulzze);
        remove_x(pulzze);
        turn(pulzze);
    }
    pulzzes.push_back(pulzze);
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = -1,index = 2;
    for(int i=0;i<table.size();i++){
        for(int j=0;j<table.size();j++){
            if(table[i][j]==1){
                vector<vector<int>> pulzze(6,vector<int>(6));
                making.push(make_pair(i,j));
                makepulzze(table,pulzze);
            }
        }
    }
    turn(pulzzes[2]);
    for(int k=0;k<pulzzes.size();k++){
        for(int i=0;i<table.size();i++){
            for(int j=0;j<table.size();j++){
                cout << pulzzes[k][i][j] << " ";
            }
            cout << endl;
    }
        cout << endl;
    }
    cout << pulzzes.size();
    return answer;
}