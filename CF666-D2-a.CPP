#include<bits/stdc++.h>
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s[n];
        for(int i=0; i<n; i++)
        {
            cin>>s[i];
        }
        int alpha[26]={0};
        for(int i=0; i<n; i++){
            string str=s[i];
            for(int j=0; j<str.length(); j++)
            {
                int a=str[j]-97;
                alpha[a]++;
            }

        }
        int i;
        for(i=0; i<26; i++)
        {
            if(alpha[i]%n!=0)
            {
                cout<<"no"<<endl;
                break;
            }
        }
        if(i==26)
            cout<<"yes"<<endl;


    }
}
