#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    while(!progresses.empty()){
        int value=1;
        int count=0;
        for(value;progresses[0]+speeds[0]*value<100;value++){
            value;
        }
        for(int i=0;i<progresses.size();i++){
            progresses[i] += speeds[i]*value;
        }
        while(progresses[0]>=100){
            progresses.erase(progresses.begin());
            count++;
        }
        answer.push_back(count);
    }
    return answer;
}