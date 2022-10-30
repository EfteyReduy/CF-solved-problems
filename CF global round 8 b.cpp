#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long n, temp=1;
    cin>>n;
    long long arr[10];
    for(int i=0; i<10; i++)
    {
        arr[i]=1;
    }
    int cou=0;
    while(temp<n)
    {
        cou++;
        for(int i=0; i<10; i++)
        {
            temp=temp/arr[i];
            temp=temp*(arr[i]+1);
            arr[i]++;
            if(temp>=n)
                break;
        }
    }
    string s="codeforces";
    for(int i=0; i<s.length(); i++)
    {
        for(int j=0; j<arr[i]; j++)
        {
            cout<<s[i];
        }
    }
    cout<<endl;


}
