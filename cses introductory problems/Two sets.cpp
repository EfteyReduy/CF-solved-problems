#include<bits/stdc++.h>

using namespace std;

main()
{
    int t=1;
    //cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if((n*(n+1))%4)
        {
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
            vector<int>v, s;

            while(n>0)
            {
                s.push_back(n);
                n--;
                if(n)
                {
                    v.push_back(n);
                    n--;
                }

                if(n)
                {
                    v.push_back(n);
                    n--;
                }
                if(n)
                {
                    s.push_back(n);
                    n--;
                }
            }
            cout<<s.size()<<endl;
            for(int i=0; i<s.size(); i++)
            {
                cout<<s[i]<<" ";
            }
            cout<<endl;
            cout<<v.size()<<endl;
            for(int i=0; i<v.size(); i++)
            {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
}
