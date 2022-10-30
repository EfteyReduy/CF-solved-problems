#include<bits/stdc++.h>

using namespace std;


main()
{
    map<int, int*>mp;
    int *x;
    *x = 4;
    cout<<x<<endl;
    mp[*x]=x;
    for(auto it:mp)
    {
        cout<<it.first<<"   "<<it.second<<endl;
    }
}
