#include<bits/stdc++.h>

using namespace std;

main()
{
    string s, t;
    cin>>s>>t;

    int as[26], bt[26];

    for(int i=0; i<26; i++)
    {
        as[i]=0;
        bt[i]=0;
    }

    for(int i=0; i<s.length(); i++)
    {
        int x=s[i]-'a';
        as[x]++;
    }

    for(auto i:t)
    {
        int x=i-'a';
        bt[x]++;
    }

    for(int i=0; i<26; i++)
    {
        if(as[i]<bt[i])
        {
            cout<<"need tree"<<endl;
            return 0;
        }
    }

    int j=0, i=0;
    bool arr=false, aut=false;

    while(j<s.length() and i<t.length())
    {
        if(t[i]==s[j])
        {
            j++;
            i++;
        }
        else{
            j++;
        }
    }
    if(j>=s.length() and i<t.length())
    {
        arr=true;
    }

    if(s.length()>t.length())
    {
        aut=true;
    }

    if(arr and aut)
    {
        cout<<"both"<<endl;
    }
    else if(arr)
    {
        cout<<"array"<<endl;
    }
    else
        cout<<"automaton"<<endl;


}
