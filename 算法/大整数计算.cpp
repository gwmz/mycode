#include <iostream>
#include <cstring>
#include <cmath>
#define MAX_NUM 100000
using namespace std;
void Add_biginteger()
{
    string s1,s2;
    int a[MAX_NUM],b[MAX_NUM],c[MAX_NUM+1];
    int maxlen,lens1,lens2,i;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    cout << "please input two  integers:" << endl;
    cin>>s1;
    cin>>s2;
    maxlen=max(lens1=s1.size(),lens2=s2.size());
    for(i=lens1-1;i>=0;i--)a[lens1-1-i]=s1[i]-'0';//�ַ���ȥ��0���������ͳ�Ϊ����
    for(i=lens2-1;i>=0;i--)b[lens2-1-i]=s2[i]-'0';//�ַ���ȥ��0���������ͳ�Ϊ����
    for(i=0;i<maxlen;i++)
    {
        c[i]=a[i]+b[i]+c[i];
        if(c[i]>9)
        {
            c[i]=c[i]%10;//��λ
            c[i+1]=1;//��λ
        }

    }
    if(c[maxlen]==1)maxlen++;
    for(i=maxlen-1;i>=0;i--)cout<<c[i];
    cout<<endl;
}
int main()
{
    char flag='y';
    while(true)
    {
        Add_biginteger();//����ģ��
        cout<<"Do you want to continue?(y or n):";cin>>flag;
        if(flag=='n')break;
    }
    return 0;
}
