
#include <iostream>
#include <cmath>
using namespace std;
void solute()
{
    int N,i,j,a[100][100];
    cout<<"���������Ĳ���:"<<endl;
    cin>>N;
    cout<<"�������"<<N<<"������ÿ���ǺŴ������:"<<endl;
    for(i=0;i<N;i++)
    {
        for(j=0;j<=i;j++)
            cin>>a[i][j];
    }
    for(i=N-2;i>=0;i--)//�ɵײ���ʼ���� ���Ͻ���
    {
        for(j=0;j<=i;j++)//����
            a[i][j]=max(a[i][j]+a[i+1][j],a[i][j]+a[i+1][j+1]);//״̬ת�Ʒ���
    }
    cout<<"����Ϊ:"<<a[0][0]<<endl;

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
