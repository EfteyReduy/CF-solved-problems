#include<bits/stdc++.h>


using namespace std;

string aPowb(long long a, long long b)
{
    string ans="1", temp="";

    for(int i=1; i<=b; i++)
    {
        long long rem=0;
        for(int j=0; j<ans.size(); j++)
        {
            long long x=ans[j]-'0';
            x*=a;
            x+=rem;
            char ch=((char)('0'+(x%10)));
            temp+=ch;
            rem=x/10;
        }
        while(rem)
        {
            char ch=((char)('0'+(rem%10)));
            temp+=ch;
            rem=rem/10;
        }
        ans=temp;
        temp="";
    }
    return ans;
}

string aMinusb(string a, string b)
{
    int n=a.length(), m=b.length();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    bool neg=false;
    if(n<m)
    {
        neg=true;
    }
    else if(n==m)
    {
        if(a<b)
        {
            neg=true;
        }
    }
    if(neg)
    {
        swap(a, b);
        swap(n, m);
    }
    string ans="";
    int rem=0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(int i=m; i<n; i++)
    {
        b+="0";
    }
    for(int i=0; i<n; i++)
    {
        int x=a[i]-'0';
        int y=b[i]-'0'+rem;
        if(x<y)
        {
            rem=1;
            x+=10;
        }
        else{
            rem=0;
        }
        char ch=x-y+'0';
        ans+=ch;
    }
    if(neg)
    {
        ans+="-";
    }
    return ans;
}

main()
{
    string atb, bta;
    long long a, b;
    cin>>a>>b;

    atb=aPowb(a,b);
    bta=aPowb(b,a);

    string ans=aMinusb(atb, bta);
    reverse(ans.begin(), ans.end());
    int i=0;
    while(ans[i]=='0')
    {
        i++;
    }
    while(i<ans.length())
    {
        cout<<ans[i];
        i++;
    }
    cout<<endl;
}
