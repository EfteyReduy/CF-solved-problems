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
        string s;
        cin>>s;
        int both=0,coun=0,cloc=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='-')
                both++;
            else if(s[i]=='>')
                cloc++;
            else
                coun++;
        }

        if(coun==0 or cloc==0)
        {
            cout<<n<<endl;
            continue;
        }

        int k=n, j=0;
        for(int i=0; i<n; i++)
        {
            while(s[i]=='-')
                j++, i++;
            break;
        }
        //cout<<"here i am"<<endl;
        for(int i=n-1; i>=0; i--)
        {
            while(s[i]=='-')
                k--, i--;
            break;
        }

        long long ans=0, cou=0;
        for(int i=j; i<k; i++)
        {
            while(s[i]=='-')
            {
                cou++;
                i++;
            }
            if(cou)
                ans+=cou+1;

            cou=0;
        }
        long long x=(n-k)+j;
        ans+=x;
        if(x)
            ans+=1;

        cout<<ans<<endl;


    }
}
