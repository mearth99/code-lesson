#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;
int n,l,r;
int courties[51] = {0};
bool visit[51];
int gap_people[51][51] = {0};
vector<int> open_courties(){
    vector<int> check;
    check.clear();
    for(int i=0;i<n*n;i++){
        visit[i] = false;   
        for(int j=0;j<n*n;j++){
            gap_people[i][j] = abs(courties[i]-courties[j]);
            if(gap_people[i][j]>=l &&gap_people[i][j]<= r) 
                check.push_back(i);
        }
    }
    return check;
}
void BFS(int start){
    queue<int> q;
    vector<int> union_courty;
    union_courty.clear();
    visit[start] = true;
    q.push(start);
    while (!q.empty()){
        int target = q.front();
        q.pop();
        union_courty.push_back(target);
        for(int i=0;i<n*n;i++)
            if(gap_people[target][i]>=l && gap_people[target][i]<=r && !visit[i]){
                q.push(i);
                visit[i] = true;
            }
    }
    int sum = 0;
    for(auto u : union_courty)
        sum += courties[u];
    for(auto u : union_courty)
        courties[u] = sum/union_courty.size();
    return;
}

int main(){
    cin >> n >> l >> r;
    int day=0;
    for(int i=0;i<n*n;i++)
        cin >> courties[i];
    while(true){
        vector<int> check = open_courties();
        if(check.size()==0) break;
        for(auto i:check)
            if(!visit[i]) BFS(i);
        day++;
    }
    cout << day;
    return 0;
}