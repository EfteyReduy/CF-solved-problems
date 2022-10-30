#include<bits/stdc++.h>

using namespace std;


main()
{
    string s;
    cin>>s;
    long long a, b, x, y;
    cin>>a>>b;
    vector<int>brr, arr;
    long long res=0;
    for(int i=0; i<s.length(); i++)
    {
        long long x=s[i]-'0';

        res=(res*10+x);
        res%=a;

        if(res==0)
        {
            arr.push_back(i);
        }

    }
    int n=s.length()-1, j=0;
    long long rem=0;

    for(int i=n; i>=0; i--)
    {
        long long x=s[i]-'0';
        if(x==0)
        {
            j++;
            continue;
        }

        int z=j;
        long long ans=1, temp=10;
        while(z>0)
        {
            if(z%2)
            {
                ans=ans*temp;
                ans%=b;
                z--;
            }
            else{
                temp=temp*temp;
                temp%=b;
                z=z/2;
            }
        }

        ans=ans*x;
        ans%=b;
        rem+=ans;
        rem%=b;

        if(rem==0)
            brr.push_back(i);

        j++;

    }
    sort(brr.begin(), brr.end());
    for(int i=0; i<arr.size(); i++)
    {
        auto it=lower_bound(brr.begin(), brr.end(), arr[i]+1);

        if(it!=brr.end() and *it==(arr[i]+1))
        {
            cout<<"YES"<<endl;
            //cout<<"And break point is : "<<brr[i]<<endl;
            for(int j=0; j<=arr[i]; j++)
            {
                cout<<s[j];
            }
            cout<<endl;
            for(int j=arr[i]+1; j<s.length(); j++)
            {
                cout<<s[j];
            }
            cout<<endl;
            return 0;
        }

    }
    cout<<"NO"<<endl;

}
