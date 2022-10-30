#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    string s;
    cin>>s;

    map<pair<int, int>, bool> mp;
    n=s.length();
    int x=0, y=0;
    mp[{x,y}]=1;
    bool bug=false;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='L')
        {
            mp[{x-1, y}]=1;
            mp[{x, y}]=1;
            mp[{x, y-1}]=1;
            mp[{x, y+1}]=1;

            x++;
        }
        else if(s[i]=='R')
        {

            mp[{x+1, y}]=1;
            mp[{x, y}]=1;
            mp[{x, y-1}]=1;
            mp[{x, y+1}]=1;

            x--;
        }
        if(s[i]=='U')
        {

            mp[{x-1, y}]=1;
            mp[{x, y}]=1;
            mp[{x, y-1}]=1;
            mp[{x+1, y}]=1;

            y++;
        }
        else if(s[i]=='D')
        {
            mp[{x-1, y}]=1;
            mp[{x, y}]=1;
            mp[{x, y+1}]=1;
            mp[{x+1, y}]=1;

            y--;
        }
        if(mp[{x,y}]){
            bug=true;
            break;
        }
        mp[{x,y}]=1;
    }
    if(bug){
        cout<<"BUG"<<endl;
    }
    else{
        cout<<"OK"<<endl;
    }
}
