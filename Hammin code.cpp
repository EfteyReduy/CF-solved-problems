#include<bits/stdc++.h>
using namespace std;

main()
{
    string st;
    cout<<"Enter the given sequence - ";
    cin>>st;

    int n=st.length();
    int total_parity=0;
    for(int i=1; i<n; i++)
    {
        if(pow(2, i)-i-1>=n)
        {
            total_parity=i;
            break;
        }
    }

    map<int, bool>mp;
    vector<int>pows;

    for(int i=0; i<=10; i++)
    {
        mp[pow(2,i)]=true;
        pows.push_back(pow(2,i));
    }
    int code[n+total_parity], j=n-1;
    for(int i=1; i<=n+total_parity and j>=0; i++)
    {
        if(!mp[i])
        {
            code[i]=(st[j]=='0'?0:1);
            j--;
        }
    }
    for(int i=0; i<pows.size() and pows[i]<=n+total_parity; i++)
    {
        int parity=0;
        code[pows[i]]=0;
        for(int j=i+1; j<=n+total_parity; j++)
        {
            if(pows[i]&j)
            {
                parity^=code[j];
            }
        }
        code[pows[i]]=parity;
    }
    cout<<"Final out put is : ";
    for(int i=n+total_parity; i>0; i--)
    {
        cout<<code[i]<<" ";
    }
    cout<<endl;
}
