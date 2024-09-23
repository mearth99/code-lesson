#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int N, cur;
long long sum = 0;
map<int, int> maps;
void solution() {
	cin >> N;
	maps[0] = -1;
	maps[300001] = -1;
	for (int i = 0; i < N; i++) {
		cin >> cur;
		auto up = maps.upper_bound(cur);
		auto lo = up;
		lo--;
		int val = max(up->second, lo->second) + 1;
		maps[cur] = val;
		sum += val;
		cout << sum << '\n';
	}
}

int main() {
	cout.tie(nullptr);
	cin.tie(nullptr); ios_base::sync_with_stdio(false);
	solution();
	return 0;
}