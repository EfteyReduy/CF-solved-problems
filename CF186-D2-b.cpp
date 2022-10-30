#include<bits/stdc++.h>
using namespace std;

#define precision(x) cout<<fixed<<setprecision(x);
bool sortinrev(const pair<double,int> &a,  const pair<double,int> &b)
{
    if(a.first==b.first)
        return (a.second<b.second);
    return (a.first > b.first);
}

main()
{
    int n;
    double t1, t2, k;
    cin>>n>>t1>>t2>>k;
    pair<double, int>p[n];
    for(int i=0; i<n; i++)
    {
        double a, b;
        cin>>a>>b;
        double x, y;
        y=(b*t1)-((b*t1*k)/100)+(a*t2);
        x=(a*t1)-((a*t1*k)/100)+(b*t2);
        x=max(x,y);
        p[i]=make_pair(x,i+1);
    }
    sort(p, p+n, sortinrev);
    //precision(2);
    for(int i=0; i<n; i++)
    {
        cout<<fixed<<setprecision(0)<<p[i].second<<" "<<fixed<<setprecision(2)<<p[i].first<<endl;
    }


}
