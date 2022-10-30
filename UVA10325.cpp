#include<bits/stdc++.h>


using namespace std;

main()
{
    long long n, m;
    while(cin>>n>>m)
    {


        long long arr[m];
        for(int i=0; i<m; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+m);
        for(int i=0; i<m; i++)
        {
            for(int j=i+1; j<m; j++)
            {
                if(arr[j]%arr[i]==0)
                    arr[j]=n+1;
            }
        }
        long long ans=0;
        set<long long>st;
        for(int i=0; i<m; i++)
        {
            if(arr[i]!=n+1)
                ans+=(n/arr[i]), st.insert(arr[i]);
        }
        set<long long>s=st;
        auto ii=st.begin();
//        for(auto i:st)
//        {
//            if(i%(*ii))
//            {
//                s.insert(i*(*ii));
//            }
//        }
        for(auto ii:st)
        {
            for(auto i:s)
            {
                if((i%(ii)) and (i*(ii))/__gcd(i,ii)<=n)
                {
                    s.insert((i*(ii))/__gcd(i,ii));
                }
            }
        }
        for(auto i:st)
        {
            s.erase(i);
        }
        for(auto i:s)
        {
            ans-=(n/i);
        }
        cout<<n-ans<<endl;
    }

}
