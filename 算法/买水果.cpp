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
    cout<<"������С����Ǯ���Լ�ˮ����������:"<<endl;
    int total,N,i,j,Count=0;
    cin>>total>>N;
    cout<<"������ÿ��ˮ���������͵���"<<endl;
    for(i=0;i<N;i++)
    {
        cin>>ite[i].first>>ite[i].second;
    }
    sort(ite,ite+N,cmp);//���۸���������
    for(i=0;i<N;i++){
        for(j=ite[i].first;j>0;j--){
            if(total>ite[i].second){    //�ж���Ǯ���Ƿ������ͼ۸��ˮ��
                total-=ite[i].second;
                Count++;
            }//for end
            else break;
        }
    }//for end
    cout<<"С��������򵽵�ˮ��������Ϊ��"<<Count<<endl;
}//solute end
int main()
{
    char flag='y';
    while(true)
    {
        solute();//����ģ��
        cout<<"Do you want to continue?(y or n):";cin>>flag;
        if(flag=='n')break;
    }
    return 0;
}
