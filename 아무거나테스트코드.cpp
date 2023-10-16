#include <string>
#include <vector>
#include <set>
using namespace std;
vector<set<int>> D(8);
int getN(int N, int count){
    int output = N;
    for(int i=1;i<=count;i++){
        output = output*10+N;
    }
    return output;
}
int solution(int N, int number) {
    if(N==number) return 1;
    D[0].insert(N);
    for(int i=1;i<=7;i++){
        D[i].insert(getN(i,N));
        
    }
    
    return answer;
}