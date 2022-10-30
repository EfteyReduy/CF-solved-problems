#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        int n, c;
        cin>>n>>c;
        cout<<"Case #"<<cas<<": ";
        if(c<n-1 or c>(n*(n+1)/2)-1)
        {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }

        int s=1, e=n, arr[n+1];
        bool point=false;

        for(int i=1; i<=n; i++)
        {
            if(c-n+i>=n-i)
            {
                if(point)
                {
                    point=false;
                    arr[s]=i;
                    s++;
                }
                else{
                    point=true;
                    arr[e]=i;
                    e--;
                }
                c-=(n-i+1);
            }
            else{
                if(point)
                {
                    arr[e]=i;
                    e--;
                }
                else{
                    arr[s]=i;
                    s++;
                }
                c--;
            }
        }
        for(int i=1; i<=n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

    }

}
