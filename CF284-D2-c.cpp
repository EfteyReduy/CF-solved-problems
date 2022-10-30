#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long x1, y1, x2, y2;
    cin>>x1>>y1;
    cin>>x2>>y2;

    long long n;
    cin>>n;
    long long ans=0;
    for(int i=0; i<n; i++)
    {
        long long x, y, c;
        cin>>x>>y>>c;
        long long temp1=(x*x1)+(y*y1)+c;
        long long temp2=(x*x2)+(y*y2)+c;
        if((temp1<0 and temp2>0)or(temp1>0 and temp2<0))
        {
            ans++;
        }
    }
    cout<<ans<<endl;

}
