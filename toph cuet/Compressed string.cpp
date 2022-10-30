#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s, ss="";
        cin>>s;
        int n=s.length();
        if(s[n-1]=='a')
        {
            for(int i=0; i<n; i++)
            {
                if(s[i]=='b')
                {
                    cout<<s[i];
                    break;
                }
            }
        }
        cout<<s[n-1]<<endl;
    }
}
