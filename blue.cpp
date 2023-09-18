#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

struct blue{ //필요횟수
    int point;
    int safecap;
    int report;
    int cookies;
};
    
int main(){
    blue data[200][4];
    blue need = {12670,9382,8029,10800};
    int n = 12670;
    blue region[4] = {
                    {71,14,14,14},
                    {18,88,0,0},
                    {18,0,71,0},
                    {18,0,0,60}
                    };
    
    for(int i=0;i<200;i++){
        for(int j=0;j<4;j++){
            data[i][j].cookies = region[j].cookies*(i+1); 
            data[i][j].point = region[j].point*(i+1); 
            data[i][j].safecap = region[j].safecap*(i+1); 
            data[i][j].report = region[j].report*(i+1); 
        }
    }
    //적당한 i0, i1, i2, i3 선택해서 값 만들기.(단, i0,i1,i2,i3의 합이 최소)
    int start1=0,start2=0,start3=0,start4=0, end1=199,end2=199,end3=199,end4=199, mid1,mid2,mid3,mid4;
    int start=0,end=199,mid;
    while(start1<=end1 && start2<=end2 && start3<=end3 && start4<=end4){
        mid1 = (start1+end1)/2;
        mid2 = (start2+end2)/2;
        mid3 = (start3+end3)/2;
        mid4 = (start4+end4)/2;
        int sum_cookies=0,sum_point=0,sum_safecap=0,sum_report=0;
        for(int i=0;i<3;i++){
            sum_cookies += data[mid1][i].cookies + data[mid2][i].cookies + data[mid3][i].cookies + data[mid4][i].cookies;
            sum_point += data[mid1][i].point +data[mid2][i].point+ data[mid3][i].point+ data[mid4][i].point;
            sum_safecap += data[mid1][i].safecap + data[mid2][i].safecap + data[mid3][i].safecap + data[mid4][i].safecap;
            sum_report += data[mid1][i].report + data[mid2][i].report + data[mid3][i].report + data[mid4][i].report;
        }
        
        if(sum_point<need.point)
            start1 = mid1+1;
        else
            end1 = mid1-1;
        if(sum_safecap<need.safecap)
            start2 = mid2+1;
        else
            end2 = mid2-1;
        if(sum_report<need.report)
            start3 = mid3+1;
        else
            end3 = mid3-1;
        if(sum_cookies<need.cookies)
            start4 = mid4+1;
        else
            end4 = mid4-1;
    }
    cout << mid1<<" " << mid2 <<" " << mid3 <<" " << mid4;
    return 0;
}