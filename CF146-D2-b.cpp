#include<bits/stdc++.h>

#define db(x) cout<<#x<<" = "<<x<<endl
//#define mod 1073741824
using namespace std;



vector<int>divi[101];
void init(set<int>st)
{
    for(auto i:st)
    {
        int a=i;
        for(int j=2; j*j<=a; j++)
        {
            if(a%j==0)
            {
                while(a%j==0)
                {
                    divi[i].push_back(j);
                    a=a/j;
                }
            }
            if(a==0)
                break;
        }
    }
}

main()
{
    int a, b, c;
    cin>>a>>b>>c;

    map<int, int>v;
    long long ans=0, mod=1073741824, temp=0;
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            for(int k=1; k<=c; k++)
            {
                int x=i*j*k, m, cou=0;
                if(v[x]!=0)
                {
                    ans+=v[x];
                    ans=ans%mod;
                    continue;
                }
                for(m=1; m*m<=x; m++)
                {
                    if(x%m==0)
                    {
                        cou+=2;
                    }

                }
                m--;
                if(m*m==x)
                    cou--;

                v[x]=cou;
                ans+=cou;
                ans=ans%mod;
            }
        }
    }

   // cout<<v.size()<<endl;

    //cout<<temp<<endl;
    cout<<ans<<endl;


}
