#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;

    cout<<1<<" ";
    if(n==1)
        return 0;
    int rem=n-1;

    int x=2;
    while(n/x>1)
    {
        int temp=n/x;
        for(int i=0; i<rem-temp; i++)
        {
            cout<<x/2<<" ";
        }
        x=x*2;
        rem=temp;
    }
    for(int i=1; i<rem; i++)
    {
        cout<<x/2<<" ";
    }
    int tem=(2*n)/x;

    cout<<tem*x/2<<endl;
}
