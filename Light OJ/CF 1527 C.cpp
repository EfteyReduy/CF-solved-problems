#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<int, vector<long long> >m;
        map<int, long long>mp;
        int a;
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            cin>>a;
            m[a].push_back(i+1);
        }
        for(auto it:m)
        {
            vector<long long>v=it.second;
            if(v.size()<2)
                continue;
            int ss=v.size();
            long long ll[ss], rr[ss];
//            ll[0]=v[0];
//            for(int i=1; i<ss; i++)
//            {
//                ll[i]=ll[i-1]+v[i];
//            }
            rr[ss-1]=n-v[ss-1]+1;
            for(int i=ss-2; i>=0; i--)
            {
                rr[i]=rr[i+1]+n-v[i]+1;
            }

            for(int i=0; i<ss-1; i++)
            {
                //cout<<ll[i]<<" "<<rr[i+1]<<endl;
                ans+=(v[i]*(rr[i+1]));
            }

        }

        cout<<ans<<endl;
    }
}
/*-

4
41
100611591 100611591 983971727 572464533 983971727 837355589 967439567 66290426 913510375 983971727 837355589 475845364 983971727 683371437 445904892 572464533 468239467 475845364 572464533 840697540 967439567 683371437 840697540 135608862 837355589 100611591 935197499 611510378 935197499 683371437 100611591 837355589 66290426 951644064 707607840 611510378 707607840 445904892 967439567 707607840 983971727


-*/
