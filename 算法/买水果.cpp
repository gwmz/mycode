#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;
typedef pair<int,int>P;
pair<int,int>ite[100];
bool cmp(const P a, const P b)
{
    return a.second < b.second;
}
void solute()
{
    cout<<"请输入小明的钱数以及水果的种类数:"<<endl;
    int total,N,i,j,Count=0;
    cin>>total>>N;
    cout<<"请输入每种水果的总量和单价"<<endl;
    for(i=0;i<N;i++)
    {
        cin>>ite[i].first>>ite[i].second;
    }
    sort(ite,ite+N,cmp);//按价格升序排序
    for(i=0;i<N;i++){
        for(j=ite[i].first;j>0;j--){
            if(total>ite[i].second){    //判断总钱数是否低于最低价格的水果
                total-=ite[i].second;
                Count++;
            }//for end
            else break;
        }
    }//for end
    cout<<"小明最多能买到的水果的总量为："<<Count<<endl;
}//solute end
int main()
{
    char flag='y';
    while(true)
    {
        solute();//计算模块
        cout<<"Do you want to continue?(y or n):";cin>>flag;
        if(flag=='n')break;
    }
    return 0;
}
