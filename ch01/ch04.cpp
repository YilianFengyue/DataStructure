//长整数加法
#include <iostream>
using namespace std;
int main()
{
    int L[10];
    //位数
    int n=0;
    cout<<"请输入位数";
    cin>>n;
    int a=0;
    int b=0;
    int i=n/10;
    for(int j=1;j<=i+1;j++)
    while (n>=0)
    {
        if(n<10)
        {
            cout<<"请输入最后10位"<<endl;
        }else{
            cout<<"请输入第"<<n<<"到"<<n-10<<"位:"<<endl;
        }
        cout<<"a:";
        cin>>L[n/10];
        cout<<"b:";
        cin>>L[n/10];
        n-=10;
    }
    
}