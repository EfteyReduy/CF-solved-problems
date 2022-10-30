#include<bits/stdc++.h>


using namespace std;


main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    set<int>s;

    queue<int>q;
    int ans=0;
    for(int i=0; i<n; i++)
    {
        q.push(arr[i]);
        auto it=s.find(arr[i]);

        if(it==s.end())
        {
            s.insert(arr[i]);
        }
        else
        {
            int a=arr[i];
            int x=q.front();
            q.pop();
            s.erase(x);
            while(x!=a)
            {
                x=q.front();
                q.pop();
                s.erase(x);
            }
            s.insert(arr[i]);

        }
        int y=s.size();
        ans=max(ans, y);
    }
    cout<<ans<<endl;

}
