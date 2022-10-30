#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    string str[n];

    pair<int , string> len[n];
    for(int i=0; i<n; i++)
    {
        cin>>len[i].second;
        len[i].first=len[i].second.length();
    }
    sort(len,len+n);

    int check=0;
    for(int i=0; i<n-1; i++)
    {
        string s=len[i].second;
        string st=len[i+1].second;
        int a=0;
        for(int j=0; j<len[i+1].first; j++)
        {
            if(s[a]==st[j])
            {
                a++;
            }
            else
            {

                j=j-a;
                a=0;
            }

            if(a==len[i].first)
            {
                check++;
                break;
            }
        }
    }
    if(check==n-1)
    {
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<len[i].second<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
    }
}
