#include<bits/stdc++.h>


using namespace std;

main()
{
    int n;
    cin>>n;
    if(n<4)
    {
        if(n==1)
            cout<<1<<endl;
        else
            cout<<"NO SOLUTION"<<endl;
    }
    else{
        for(int i=n; i>0; i--)
        {
            if(i%2==1)
                cout<<i<<" ";
        }
        for(int i=n; i>0; i--)
        {
            if(i%2==0)
            {
                cout<<i<<" ";
            }
        }
        cout<<endl;
    }
}
