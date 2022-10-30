#include<bits/stdc++.h>

using namespace std;


main()
{
    string s;
    cin>>s;
    int o=0, n, v=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='o')
            o++;
        else
            v++;
    }
    pair<long long , long long >p[o+1];
    int x=0, y=0, j=0;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='o')
        {
            if(x>1)
            {
                y+=x-1;
            }
            p[j].first=y;
            j++;
            x=0;
        }
        else{
            x++;
        }
    }
    if(x){
        y+=x-1;
        p[j].first=y;
    }
    for(int i=0; i<=o; i++)
    {
        p[i].second=y-p[i].first;
    }


    long long ans=0;
    for(int i=0; i<=o; i++)
    {
        //cout<<p[i].first<<" "<<p[i].second<<endl;
        ans=ans+((p[i].first)*(p[i].second));
    }

    cout<<ans<<endl;
}
