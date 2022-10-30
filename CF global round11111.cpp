#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--){
        int k, n;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>cum;
        int j=0;
        while(s[j]=='L')
            j++;
        int bgn=j;
        j=n;
        j--;
        while(s[j]=='L')
            j--;
        int ind=n-j-1;
        long long ans=0;
        int coul=0;
        for(int i=bgn; i<j; i++)
        {
            if(s[i]=='L')
            {
                coul++;
                int cou=0;
                while(s[i]=='L')
                {
                    i++;
                    cou++;
                }
                cum.push_back(cou);
            }

        }
        for(int i=0; i<n; i++)
        {
            if(s[i]=='W')
            {
                if(i>0 and s[i-1]=='W')
                    ans+=2;
                else
                    ans+=1;
            }
        }
        sort(cum.begin(), cum.end());
        coul=0;
        for(int i=0;i<n; i++)
            if(s[i]=='L')
                coul++;
        for(int i=0; i<cum.size(); i++)
        {
            //cout<<"cum ["<<i<<"] = "<<cum[i]<<endl;
            int x=k-cum[i];

            if(x>=0)
            {
                ans+=cum[i]*2+1;
            }
            else{

                ans+=((k)*2);
                k=0;
                break;
            }
            k-=cum[i];
            if(k<=0)
                break;
        }
        //cout<<"begin = " <<bgn<<" end = "<<ind<<endl;
        if(k>0)
        {
            k=min(k, bgn+ind);
            ans+=k*2;
            if(coul==n)
                ans=k*2-1;
        }
        cout<<ans<<endl;




    }
}
