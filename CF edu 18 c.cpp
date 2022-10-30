#include<bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cin>>s;
    long long sum=0, tnz=0;
    map<int, int>mp;
    vector<int>vec[3];
    for(int i=0; i<s.length(); i++)
    {
        int a=s[i]-'0';
        if(a%3)
        {
            tnz++;
        }
        mp[a]++;
        sum+=a;
        vec[a%3].push_back(i);
    }
    if(sum%3==0)
    {
        cout<<s<<endl;
        return 0;
    }

    int rem=sum%3;

    if(sum<3)
    {
        if(mp[0])
        {
            cout<<0<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        return 0;
    }


    string ress=s, ans="", temp="";
    if(vec[rem].size()>0)
    {
        ress[vec[rem][vec[rem].size()-1]]='x';

        int idxx=0;
        while(ress[idxx]=='0' or ress[idxx]=='x')
        {
            idxx++;
        }
        for(int i=idxx; i<ress.length(); i++)
        {
            if(ress[i]=='x')
                continue;
            ans+=ress[i];
        }
    }
    int z=1;
    if(rem==1)
    {
        z=2;
    }
    ress=s;
    temp="";
    if(vec[z].size()>=2)
    {
        ress[vec[z][vec[z].size()-1]]='x';
        ress[vec[z][vec[z].size()-2]]='x';

        int idxx=0;
        while(ress[idxx]=='0' or ress[idxx]=='x')
        {
            idxx++;
        }
        for(int i=idxx; i<ress.length(); i++)
        {
            if(ress[i]=='x')
                continue;
            temp+=ress[i];
        }
        if(temp.length()>ans.length())
        {
            ans=temp;
        }
    }

    if(ans.length()==0)
    {
        if(mp[0])
        {
            cout<<0<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
    else{
        cout<<ans<<endl;
    }
    return 0;

}

