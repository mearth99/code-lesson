#include <string>
#include <vector>
#include <algorithm>
using namespace std;
/*
N원을 money로 거슬러 주는 가짓수는 즉, money로 N원을 조합하는 경우의 수와 같다.
이를 위해서, 1원에서 N원까지 순회할 수 있다.
*/
int DP[101];
bool value[101];
int solution(int n, vector<int> money) {
    int answer = 0;
    sort(money.begin(),money.end());
    for(auto it : money){
        DP[it]++;
        value[it] = true;
    }
    for(auto it : money){
        for(int i=it;i<=n;i++){
            DP[i] = (DP[i] + DP[i-it])%1000000007;  
        }
    }
    answer = DP[n];
    return answer;
}
int main(){
    solution(5, {1,2,5});
    return 0;
}