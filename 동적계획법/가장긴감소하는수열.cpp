
#include <iostream>

using namespace std;

int dp[1001];
int v[1001];
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> v[i];
    int cur = v[0];
    dp[0] = 1;
    for(int i=1;i<n;i++){
        if(cur>v[i]){
            dp[i] = dp[i-1]+1;
            cur = v[i];
        }else{
            
        }
    }
}
