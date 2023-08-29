#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int zip(int length, string data){
    int index = 0;
    int dup = 1;
    string output;
    while(index+length<data.length()){
        if(data.substr(index,length)==data.substr(index+length,length)){
            index+=length;
            dup++;
        }else{
            if(dup>1){
              output += to_string(dup)+data.substr(index,length);
            }
            dup=0;
            index+=length;
        }
        
    }
    cout << output << endl;
    return output.size();
}
int solution(string s) {
    int answer = s.length();
    for(int i=1;i<=s.length()/2;i++){
        answer = min(answer,zip(i,s));
    }
    
    return answer;
}

int main(){
  string temp;
  cin >> temp;
  cout << solution(temp);
}