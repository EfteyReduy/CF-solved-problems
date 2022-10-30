#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    int p;
    cin>>n>>p;

    double ans=0;
    vector<double>vec, tor;
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        if(b<a)
            swap(a,b);
        a--;
        int x=(b/p)-(a/p);

        int y=b-a;
        tor.push_back(x);
        vec.push_back(y);
    }

    double a=2*1000*(1-(((vec[0]-tor[0])/vec[0])*((vec[n-1]-tor[n-1])/vec[n-1])));
    ans=a;
    for(int i=1; i<n; i++)
    {
        double x=2*1000*(1-(((vec[i]-tor[i])/vec[i])*((vec[i-1]-tor[i-1])/vec[i-1])));
        ans+=x;
    }
    cout<<fixed<<setprecision(7);
    cout<<ans<<endl;

}
