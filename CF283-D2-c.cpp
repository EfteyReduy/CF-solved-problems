#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    char c;
    string str[n+1];
    for(int i=0 ;i<n; i++)
    {
        cin>>str[i];
    }

    string s[n+1], temp[n+1];

    int ans=m;
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            temp[j]=s[j];
        }
        for(int j=0; j<n; j++)
        {
            temp[j]+=str[j][i];
        }

        if(is_sorted(temp, temp+n)){
            //cout<<" sorted at i = "<<i<<endl;
            for(int j=0; j<n; j++)
            {
                string st=s[j];
                st+=str[j][i];
                s[j]=st;
                //cout<<s[j]<<endl;
            }
            ans--;
        }

    }
    cout<<ans<<endl;
}
