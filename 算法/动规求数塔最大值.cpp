
#include <iostream>
#include <cmath>
using namespace std;
void solute()
{
    int N,i,j,a[100][100];
    cout<<"请输入塔的层数:"<<endl;
    cin>>N;
    cout<<"请接下来"<<N<<"行输入每个星号代表的数:"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<=i;j++)
            cin>>a[i][j];
    }
    for(i=N-2;i>=0;i--)//由底部开始动规 不断降阶
    {
        for(j=0;j<=i;j++)//决策
            a[i][j]=max(a[i][j]+a[i+1][j],a[i][j]+a[i+1][j+1]);//状态转移方程
    }
    cout<<"最大和为:"<<a[0][0]<<endl;

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
