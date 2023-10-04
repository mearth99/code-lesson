#define MOD 1000000000
#define LL long long int
#include <iostream>
using namespace std;

LL arr[1026][11][102];
int N;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int i = 1; i < 10; i++) {
		arr[1 << i][i][1] = 1;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 1; k < 1024; k++) {
				//비트 마스킹 0~9 까지
				int idx = 1 << j;
				if (arr[k][j][i] != 0) {
					if (j == 0) {
						//0이니 -> 1로 가는 수 한개 추가.
						arr[k | 1 << 1][j + 1][i + 1] = (arr[k | 1 << 1][j + 1][i + 1] + arr[k][j][i]) % MOD;
					}
					else if (j == 9) {
						//9이면, -> 8로 가는 수 한개 추가.
						arr[k | 1 << 8][j - 1][i + 1] = (arr[k | 1 << 8][j - 1][i + 1] + arr[k][j][i]) % MOD;
					}
					else {
						arr[k | 1 << (j - 1)][j - 1][i + 1] = (arr[k | 1 << (j - 1)][j - 1][i + 1] + arr[k][j][i]) % MOD;
						arr[k | 1 << (j + 1)][j + 1][i + 1] = (arr[k | 1 << (j + 1)][j + 1][i + 1] + arr[k][j][i]) % MOD;
					}
				}
			}
		}
	}

	LL sum = 0;
	for (int i = 0; i < 10; i++) {
		int idx = (1 << 10) - 1;
		sum += arr[idx][i][N];
	}
	cout << sum % MOD << "\n";
}