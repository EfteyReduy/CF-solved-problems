#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, arr[10]={0};
        cin>>n;
        string s;
        cin>>s;
        for(int i=0; i<n; i++)
        {
            int a=s[i]-'0';
            arr[a]++;
        }
    }
}
