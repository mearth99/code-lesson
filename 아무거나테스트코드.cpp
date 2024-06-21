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
	vector<bool> a;
	bool *b = &a[0];
}