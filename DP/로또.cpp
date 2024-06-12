#include <bits/stdc++.h>
using namespace std;
int K;
int DP[1<<13][13];
int arr[13];
void solution(){
	cin >> K;
	memset(DP, -1, sizeof(DP));
	for(int i=0;i<K;i++)
		cin >> arr[i];
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	solution();
    return 0;
}