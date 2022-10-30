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
        cin>>s;
        n=s.length();
        vector<int>arr;
        int cou=0;
        long long ans=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='1')
                cou++;
            else
            {
                arr.push_back(cou);
                cou=0;
            }
        }
        arr.push_back(cou);
        sort(arr.begin(),arr.end() );
        for(int i=arr.size()-1; i>=0;  i-=2)
        {
            ans+=arr[i];
        }
        cout<<ans<<endl;
    }
}
