#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

//1. 균형점을 탐색하기 위해 일일히 탐색하는 것은 많은 시간 소모가 소요된다.
//2. 이분 탐색을 통해 접근한다면 이 수치를 상당 부분 떨어뜨릴 수 있다.
//3. 좌표는 오름차순으로 정렬되어 있다.

vector<vector<double>> outputs;
vector<double> output;
vector<pair<int,int>> arr;
vector<int> sum;
void search(int num){
	int start_pos = arr[num].first;
	int end_pos = arr[num+1].first;
	int left_weight = sum[num];
	int right_weight = sum.back() - left_weight;
	double left_pos = start_pos;
	double right_pos = end_pos;
	double mid = 0;

	while(left_pos <= right_pos){
		mid = (left_pos + right_pos) / 2;
		double left_value = left_weight / (mid*mid);
		double right_value = right_weight / (mid*mid);
		if(left_value > right_value){ //left의 값이 높으므로, right쪽으로 이동해야한다.
			left_pos = mid;
		}
		else if(left_value < right_value){
			right_pos = mid;
		}
		else{
			output.push_back(mid);
			break;
		}
	}
	return;
}

int main(int argc, char** argv)
{
	freopen("input.txt", "r", stdin);
	freopen("myoutput.txt", "w", stdout);
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N;
		cin >> N;
		arr.resize(N); // first : distacne, second: weight
		sum.resize(N);
		for(int i=0;i<N;i++){
			cin >> arr[i].first;
		}
		for(int i=0;i<N;i++){
			cin >> arr[i].second;
		}
		sum[0] = arr[0].second;
		for(int i=1;i<N;i++){
			sum[i] = sum[i-1] + arr[i].second;
		}
		for(int i=0;i<N-1;i++){
			search(i);
		}
		outputs.push_back(output);
		arr.clear();
		sum.clear();
		output.clear();
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ';
		for(auto i : it){
			cout << i << ' ';
		}
		cout << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}