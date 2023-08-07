#include <string>
#include <vector>

using namespace std;
bool S_compare(string user, string ban){
    if(user.size()!=ban.size()) return false;
    for(int i=0;i<user.size();i++){
        if(ban[i]=='*') continue;
        if(user[i]!=ban[i])
            return false
    }
    return true;
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    /*
    banned와 일치하는 user_id의 개수를 구한다. 순서와 상관없기 때문에, 가능한 경우의 수는 일치하는 리스트를 서로 곱하면 된다.
    */
    return answer;
}