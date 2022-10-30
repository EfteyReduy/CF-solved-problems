#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    long long sum=0, ans=0, arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    string s;
    cin>>s;
   // reverse(s.begin(), s.end());
//
//    string st="";
//    bool t=false;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i]=='0')
        {
            sum+=arr[i];
        }
        else{
            ans+=max(sum,arr[i]);
            sum=min(sum, arr[i]);
        }
    }
    cout<<ans<<endl;

}
