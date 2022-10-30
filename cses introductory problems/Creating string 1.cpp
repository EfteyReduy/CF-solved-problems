#include<bits/stdc++.h>

using namespace std;

main()
{
    string s;
    cin>>s;
    int arr[26];
    for(int i=0; i<26; i++)
    {
        arr[i]=0;
    }
    for(int i=0; i<s.length(); i++)
    {
        arr[(s[i]-'a')]++;
    }
    long long ans=1;
    for(int i=2; i<=s.length(); i++)
    {
        ans=ans*i;
    }
    for(int i=0; i<26; i++)
    {
        long long div=1;
        for(int j=2; j<=arr[i]; j++)
        {
            div=div*j;
        }
        ans=ans/div;
    }
    cout<<ans<<endl;
    sort(s.begin(), s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(),s.end()));

}
