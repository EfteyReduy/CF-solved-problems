#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        for(int i=0; i<n*2; i+=2)
        {
            cout<<s[i];
        }
        cout<<endl;
    }
}
