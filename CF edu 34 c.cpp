#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    map<int, int>mp;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        mp[a]++;
    }
    int ans=0;
    for(auto it:mp)
    {
        ans=max(ans, it.second);
    }
    cout<<ans<<endl;
}
