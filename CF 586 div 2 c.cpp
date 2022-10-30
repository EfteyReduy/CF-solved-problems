#include<bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cin>>s;
    if(1)
    {
        cout<<"Mike"<<endl;
    }
    int n=s.length(), i=0;
    char men=s[0];
    bool ans[n];
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<n; i++)
    {
        if(s[i]>men)
        {
            ans[i]=1;
        }
        else{
            men=min(men, s[i]);
        }
    }
    for(int i=1; i<n; i++)
    {
        if(ans[i])
        {
            cout<<"Ann"<<endl;
        }
        else{
            cout<<"Mike"<<endl;
        }
    }
}
