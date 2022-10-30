#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    if(n<6)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<"1 2"<<endl;
        cout<<"1 3"<<endl;
        cout<<"2 5"<<endl;
        cout<<"2 4"<<endl;
        for(int i=6; i<=n; i++)
        {
            cout<<i<<" "<<1<<endl;
        }
    }

    for(int i=2; i<=n; i++)
    {
        cout<<i<<" "<<1<<endl;
    }
}
