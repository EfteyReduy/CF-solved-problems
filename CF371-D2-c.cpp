
#include<bits/stdc++.h>

using namespace std;


main()
{
    string S;
    cin>>S;
    long long b[]={0, 0, 0};//0, c=0, s=0;
    for(int i=0; i<S.length(); i++)
    {
        if(S[i]=='B')
            b[0]++;
        else if(S[i]=='S')
            b[1]++;
        else
            b[2]++;
    }

    long long n[3], p[3];
    for(int i=0; i<3; i++)
    {
        cin>>n[i];
    }
    for(int i=0; i<3; i++)
    {
        cin>>p[i];
    }
    long long r;
    cin>>r;

    long long lo=0, hi=10000000000000, ans=0;
    while(lo<=hi)
    {
        long long mid=(lo+hi)/2;
        long long k=r, x;
        for(int i=0; i<3; i++)
        {
            if(b[i])
            {
                x=n[i]/b[i];
                if(x<mid )
                {
                    k=k-(mid-x)*p[i]*b[i]+(n[i]%b[i])*p[i];
                }
            }
        }
        if(k<0)
            hi=mid-1;
        else if(k==0)
        {
            ans=max(ans, mid);
            break;
        }
        else if(k>0)
        {
            ans=max(ans, mid);
            lo=mid+1;
        }
    }

    cout<<ans<<endl;

}
