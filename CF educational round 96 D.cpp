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
        int i=0;
        vector<int>runs;
        while(i<s.length())
        {
            int cou=0;
            while((s[i]=='1') && (i<s.length()))
            {
                cou++;
                i++;
            }
            if(cou>0)runs.push_back(cou);
            cou=0;
            while((s[i]=='0') && (i<s.length()))
            {
                cou++;
                i++;
            }
            if(cou>0)runs.push_back(cou);
            cou=0;

        }
        int rem=0, x=runs.size();
//        int cum[x];
//        for(i=0; i<x; i++)
//        {
//            cum[i]=0;
//        }
//        for( i=x-1; i>=0; i--)
//        {
//            if(runs[i]>1)
//            {
//                rem+=runs[i]-1;
//                runs[i]=1;
//
//            }
//            cum[i]=rem;
//        }
//        for(i=0; i<x; i++)
//        {
//            cout<<cum[i]<<" ";
//        }
//        cout<<endl;
        int ans=0, skip=0;


        for(int j=0; j<runs.size(); j++)
        {
            if(runs[j]>1)
            {
                rem=runs[j]-2;
                if(j+1==runs.size())
                    rem++;
                ans+=min(rem,skip);
                if(rem<skip){
                    skip-=rem;
                    if(j+1==runs.size())
                        skip--;
                }
                else
                    skip=0;
                ans++;
            }
            else{
                skip++;
                continue;
//                if(j+1<runs.size() and runs[j+1]>1)
//                    runs[j]--;
//                else if(j+1<runs.size())
//                    j++, skip++;
//                ans++;
            }

        }
       // cout<<"skiped = "<<skip<<endl;
        ans+=(skip/2)+(skip%2);
        cout<<ans<<endl;

    }
}

