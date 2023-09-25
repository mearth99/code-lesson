#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
string sell[51][51];
int node[2501];
vector<string> answer;

int Get_Parent(int x){
    if(node[x]==x) return x;
    else return node[x] = Get_Parent(node[x]);
}
void Union_Parent(int a, int b){
    a = Get_Parent(a);
    b = Get_Parent(b);
    if(a<b) node[b] = a; 
    else node[a] = b;  
}

void UPDATE(vector<string> cur){
    if(cur.size()==4){
        int r = stoi(cur[1])-1;
        int c = stoi(cur[2])-1;
        string value = cur[3];
        int x = Get_Parent(r*50+c)/50;
        int y = (Get_Parent(r*50+c)-(x*50))%50;
        sell[x][y] = value;
    }else{
        string seek = cur[1];
        string change = cur[2];
        for(int i=0;i<=50;i++)
            for(int j=0;j<=50;j++)
                if(sell[i][j]==seek) 
                    sell[i][j] = change;      
        cout << sell[50][50];
    }
}
void MERGE(vector<string> cur){
    int r1 = stoi(cur[1])-1, c1 = stoi(cur[2])-1;
    int r2 = stoi(cur[3])-1, c2 = stoi(cur[4])-1;
    int x1 = Get_Parent(r1*50+c1)/50, y1 = (Get_Parent(r1*50+c1)-(x1*50))%50;
    int x2 = Get_Parent(r2*50+c2)/50, y2 = (Get_Parent(r2*50+c2)-(x2*50))%50;
    string s1 = sell[x1][y1], s2 = sell[x2][y2];
    sell[x1][y1] = "", sell[x2][y2] = "";

    Union_Parent(r1*50+c1,r2*50+c2);
    int x = Get_Parent(r1*50+c1)/50;
    int y = (Get_Parent(r1*50+c1)-(x*50))%50;
    int temp = Get_Parent(r2*50+c2);
    if(s1.empty())
        sell[x][y] = s2;
    else
        sell[x][y] = s1;
    return;
}
void UNMERGE(vector<string> cur){
    int r = stoi(cur[1])-1;
    int c = stoi(cur[2])-1;
    int value = Get_Parent(r*50+c);
    int x = value/50;
    int y = (value-(x*50))%50;
    string s = sell[x][y];
    for(int i=0;i<2501;i++){
        if(node[i]==value){
            node[i] = i;
            int x1 = i/50;
            int y2 = i%(x*50);
            sell[x1][y2] = "";
        }
    }
    sell[r][c] = s;
    return;
}
void PRINT(vector<string> cur){
    int r = stoi(cur[1])-1;
    int c = stoi(cur[2])-1;
    int x = Get_Parent(r*50+c)/50;
    int y = (Get_Parent(r*50+c)-(x*50))%50;
    if(sell[x][y].empty()) answer.push_back("EMPTY");
    else answer.push_back(sell[x][y]);
}
vector<string> solution(vector<string> commands) {
    for(int i=0;i<2501;i++)
        node[i] = i;
    for(int i=0;i<commands.size();i++){
        vector<string> cur;
        string temp;
        stringstream ss(commands[i]);
        while(getline(ss,temp, ' '))
            cur.push_back(temp);
        if(cur[0]=="UPDATE")
            UPDATE(cur);
        else if(cur[0]=="MERGE")
            MERGE(cur);
        else if(cur[0]=="UNMERGE")
            UNMERGE(cur);
        else if(cur[0]=="PRINT")
            PRINT(cur);
    }
    return answer;
}
int main(){
    vector<string> arr = {"UPDATE 1 1 a", "UPDATE 1 2 b", "UPDATE 2 1 c", "UPDATE 2 2 d", "MERGE 1 1 1 2", "MERGE 2 2 2 1", "MERGE 2 1 1 1", "PRINT 1 1", "UNMERGE 2 2", "PRINT 1 1"};
    solution(arr);
    return 0;
}