#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n, a, b;
        cin>>n;
        cin>>a;
        bool temp=true;
        for(int i=0; i<n-1; i++)
        {
            cin>>b;
            if(a!=b)
            {
                temp = false;
            }
        }
        if(!temp)
        {
            cout<<1<<endl;
        }
        else{
            cout<<n<<endl;
        }
    }
}
