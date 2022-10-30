#include<bits/stdc++.h>

using namespace std;


main()
{
    int n, k;
    cin>>n>>k;
    vector<int>a, b, both;

    for(int i=0; i<n; i++)
    {
        int t, x, y;
        cin>>t>>x>>y;
        if(x and y)
            both.push_back(t);
        else if(x)
            a.push_back(t);
        else if(y)
            b.push_back(t);
    }
    //cout<<"a = "<<a.size()<<" b = "<<b.size()<<" both = "<<both.size()<<endl;
    int siz=min(a.size(),b.size());
    siz+=both.size();

    if(siz<k)
        cout<<-1<<endl;
    else
    {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(both.begin(), both.end());
        int x=0, y=0, z=0;
        long long ans=0;
        while(k--)
        {
            long long  temp=10000000000;
            long long  temp2=temp;
            if(x<a.size() and y<b.size())
                temp=a[x]+b[y];

            if(z<both.size())
            {
                temp2=both[z];
            }
            if(temp<temp2)
            {
                ans+=temp;
                x++, y++;
            }
            else
            {
                ans+=temp2;
                z++;
            }
        }
        cout<<ans<<endl;
    }
}
