#include<bits/stdc++.h>
using namespace std;

main()
{
    while(1){
        long long n, a, b;
        cin>>n;
        if(n==0)
            return 0;
        cin>>a>>b;
        map<long long , int>mp;
        mp[0]=1;
        long long x=0;
        for(int i=1; i>0; i++)
        {
            x=(x*x)%n;
            x=(x*a)%n;
            x+=b;
            x%=n;
            if(mp[x])
            {
                cout<<(n-mp.size()+mp[x]-1)<<endl;
                break;
            }
            else{
                mp[x]=mp.size();
            }
        }
        //cout<<(n-mp.size())<<endl;
        mp.clear();
    }
}
