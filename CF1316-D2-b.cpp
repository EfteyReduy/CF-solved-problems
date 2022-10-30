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
        int alp[26];
        for(int i=0; i<26; i++)
        {
            alp[i]=0;
        }
        char men=124;
        for(int i=0; i<s.length(); i++)
        {
            int a=s[i]-'a';
            if(s[i]<men)
                men=s[i];
            alp[a]++;
        }
        vector<int>k;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]==men)
                k.push_back(i);
        }
        int K=1;
        string sor=s;
        sort(sor.begin(), sor.end());
        string ans=s, temp;
        for(int i=0; i<k.size(); i++)
        {
            temp="";
            for(int j=k[i]; j<s.length(); j++)
            {
                temp+=s[j];
            }
            if((s.length()-k[i]-1)%2==0)
            {
                for(int j=k[i]-1; j>=0; j--)
                {
                    temp+=s[j];
                }
            }
            else{
                for(int j=0; j<k[i]; j++)
                {
                    temp+=s[j];
                }
            }
            if(temp<ans)
            {
                ans=temp;
                K=k[i]+1;
            }
            if(ans==sor)
                break;

        }

        cout<<ans<<endl;
        cout<<K<<endl;

    }
}
