#include<bits/stdc++.h>

#define F first
#define S second

using namespace std;
bool rev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.second < b.second);
}
main()
{
    int n;
    cin>>n;
    pair<int, int>p[n], en[n], ex[n];
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        p[i]={a,b};
        en[i]=p[i];
        ex[i]=p[i];
    }
    sort(en, en+n);
    sort(ex, ex+n, rev);
    int ans=0;
    for(int i=0; i<n; i++)
    {
        int a=ex[i].S;
        pair<int, int>x={a+1, 0};
        auto it=lower_bound(en, en+n, x);
        int ax=it-en-(i);
        ans=max(ans, ax);
    }
    cout<<ans<<endl;

}
