#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    int r=7%n;
    if(n%2==0 or n%5==0)
    {
        cout<<-1<<endl;
        return 0;
    }

    int prevr=0, ans=1;
    bool t=true;
    while(r)
    {
        int a=r*10+7;
        ans++;
        r=a%n;
        if(a/n)
        {
            if(r==prevr)
            {
                t=false;
                break;
            }else
            {
                prevr=r;
            }
        }
    }
    if(t)
        cout<<ans<<endl;
    else
        cout<<-1<<endl;
}
