#include<bits/stdc++.h>
using namespace std;

main()
{

        int n, m;
        cin>>n>>m;

        int a=m/n;
        if(m%n!=0)
        {
            cout<<-1<<endl;
            return 0;
        }
        int ans=0;
        while(a%2==0)
        {
            a=a/2;
            ans++;
        }
        while(a%3==0)
        {
            a=a/3;
            ans++;
        }
        if(a==1)
        {
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }

}
