#include<bits/stdc++.h>

#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int n=s.length();

        int temp=0, ans=0;
        map<char, int>cou;
        for(int i=0; i<n; i++)
        {
            cou[s[i]]++;
        }
        for(auto i:cou)
        {
            ans=max(ans,i.second);
        }
        for(int i=0; i<10; i++)
        {
            char c='0'+i;
            for(int j=0; j<10; j++)
            {
                char cc='0'+j;
                for(int k=0; k<n; k++)
                {
                    if(s[k]==c)
                    {
                        k++;
                        while(s[k]!=cc and k<n)
                        {
                            k++;
                        }
                        if(s[k]==cc)
                            temp+=2;
                    }
                    else{
                        continue;
                    }
                }
                ans=max(ans, temp);
                temp=0;
            }
        }
        cout<<n-ans<<endl;
    }

}
