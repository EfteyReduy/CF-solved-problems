#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    string k, s, t;
    cin>>k>>s>>t;

    map<char, int>mk, ms, mt;
    for(int i=0; i<k.length(); i++)
    {
        mk[k[i]]++;
    }

    for(int i=0; i<s.length(); i++)
    {
        ms[s[i]]++;
    }
    for(int i=0; i<t.length(); i++)
    {
        mt[t[i]]++;
    }

    int mek, mes, met;
    mes=met=mek=0;

    for(auto i:mk)
    {
        int temp=i.second+n;
        if(temp>k.length())
        {
            temp=k.length();
        }
        if(i.second==k.length() and n==1)
            temp--;
        mek=max(mek, temp);
    }
    for(auto i:ms)
    {
        int temp=i.second+n;
        if(temp>s.length())
        {
            temp=s.length();
        }
        if(i.second==s.length() and n==1)
            temp--;
        mes=max(mes, temp);
    }
    for(auto i:mt)
    {
        int temp=i.second+n;
        if(temp>t.length())
        {
            temp=t.length();
        }
        if(i.second==t.length() and n==1)
            temp--;
        met=max(met, temp);
    }
    if(mek>mes and mek>met)
    {
        cout<<"Kuro"<<endl;
    }
    else if(mek<mes and met<mes)
    {
        cout<<"Shiro"<<endl;
    }
    else if(met>mes and met>mek)
    {
        cout<<"Katie"<<endl;
    }
    else{
        cout<<"Draw"<<endl;
    }

}
