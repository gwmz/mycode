/*����Ӷκ�����*/
#include <iostream>

using namespace std;
int a[100];
int max_sum(int a[],int n,int best_i ,int best_j)
{
    int i=1,j,this_sum[n+1],sum[n+1];
    this_sum[0]=0;
    sum[0]=0;
    best_i=0;
    best_j=0;

    for(j=1;j<=n;j++)
    {
        this_sum[j]=this_sum[j-1]+a[j];
        if(this_sum[j]>sum[j-1])
        {
            sum[j]=this_sum[j];
            best_i=i;
            best_j=j;
        }else {
            sum[j]=sum[j-1];
        }
        if(this_sum[j]<0)//���¶�λ��ʼλ��
        {
            i=j+1;
            this_sum[j]=0;
        }
    }//for end

    cout<<"����Ӷ���ʼλ��Ϊ��"<<best_i<<endl;
    cout<<"����Ӷ��յ�λ��Ϊ��"<<best_j<<endl;

    return sum[n];
}//max_sum end
int main()
{
    int n,i,best_i,best_j;
    char flag='y';
    while(true){
        cout<<"���������еĳ���"<<endl;
        cin>>n;
        for(i=1;i<=n;i++) cin>>a[i];
        cout<<"�����е�����Ӷκ�Ϊ��"<<max_sum(a,n,best_i,best_j)<<endl;//���ü���ģ��
        cout<<"Do you want to continue?(y or n):";cin>>flag;//�Ƿ����
        if(flag=='n')break;
    }
    return 0;
}
