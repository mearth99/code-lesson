#include<iosteam>
#include<limit.h>
#include<string.h>
#define MAX 100001
int arr[MAX];
pair<int,int> tree[MAX*4]; //first : min, second : max

using namespace std;
//선반에 중복이 없다면, LR사이 순서 상관없이 LR 범위에 해당하는지 안하는지 확인하면 된다.
//start == end일때 left <=  target <= right 이면 OK
//else라면 No 
pair<int,int> init(int start, int end, int node){
    if(start==end){
        tree[node].first = arr[start];
        tree[node].second = arr[start];
        return tree[node];
    }
    else{
        int mid = (start + end) /2;
        pair<int,int> left_tree = init(start, mid, node *2);
        pair<int,int> right_tree = init(mid+1, end, node *2 +1);
        int maxv = max(left_tree.second, right_tree.second);
        int minv = min(left_tree.first, right_tree.first);

    }
    return tree[node] = make_pair(minv,maxv);
}
pair<int,int>  get_section(int start, int end, int node, int left, int right){
    if(start > right || end < left) return make_pair(INT_MAX);
    
}


int main(){
    int T;
    cin >> T;
    memset(arr,0,sizeof(arr));
    memset(tree,0,sizeof(tree));
    while(T--){
       int n,k;
       cin >> n >> k;
       for(int i=0;i<n;i++){
        arr[i] = i;
       }
        init(0,n-1,1);

    }
    return 0;
}
