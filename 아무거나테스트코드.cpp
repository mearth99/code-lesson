#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
/*
첫번째 사람이 원하는 모자의 크기는 4이고, 사이즈 6 또는 사이즈 7 모자를 쓸 수 있다

두번째 사람이 원하는 모자의 크기는 8이고, 사이즈 6, 사이즈 7, 사이즈 10 모자를 쓸 수 있다

세번째 사람이 원하는 모자의 크기는 2이고, 만족하는 모자는 존재하지 않는다



따라서, 위 내용을 조합해보면 첫번째 사람과 두번째 사람은 모자를 쓸 수 있고 답은 2가 된다
*/
vector<int> outputs;
vector<int> wanted;
vector<int> reals;
vector<bool> visited;

int main(int argc, char** argv)
{
	int test_case,T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case){
		int N,count=0;
		cin >> N;
		wanted.resize(N);
		reals.resize(N);
		int hats[2001] = {0};
		for(int i=0;i<N;i++){
			cin >> wanted[i];
		}
		for(int i=0;i<N;i++){
			cin >> reals[i];
			for(int j=1;j<=3;j++)
				if(reals[i]-j>=1)
					hats[reals[i]-j]++;
			for(int j=0;j<=3;j++)
				if(reals[i]+j<=2000)
					hats[reals[i]+j]++;
		}	
		sort(wanted.begin(),wanted.end());
		sort(reals.begin(),reals.end());
		for(int i=0;i<N;i++){
			if(hats[wanted[i]]>0){
				count++;
				for(int j=1;j<=3;j++)
					if(wanted[i]-j>=1)
						hats[wanted[i]-j]--;
				for(int j=0;j<=3;j++)
					if(wanted[i]+j<=2000)
						hats[wanted[i]+j]--;
			}
		}
		outputs.push_back(count);
	}
	int a = 1;
	for(auto &it : outputs){
		cout << '#' << a++ << ' ' << it << '\n';
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}