#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int l, r, s;
        cin>>l>>r>>s;
        vector<int>ans;
        int dif=r-l;
        map<int, int>mp;
        for(int i=n; i>0; i--)
        {
            if(s-i>=(dif*(dif+1))/2 and dif>=0)
            {
                ans.push_back(i);
                mp[i]=1;
                s-=i;
                dif--;
            }
        }
      //  cout<<s<<endl;
        if(s!=0 or ans.size()!=(r-l+1))
        {
            cout<<-1<<endl;
            continue;
        }
        int cou=1, till=1;
        for(int i=1; i<=n and cou<l; i++)
        {
            if(mp[i]==0)
            {
                cout<<i<<" ";
                cou++;
                till=i+1;
                mp[i]=1;
            }
        }
        for(int i=0; i<ans.size(); i++)
            cout<<ans[i]<<" ";
        for(int i=till; i<=n; i++)
        {
            if(!mp[i])
            {
                cout<<i<<" ";
            }
        }
        //cout<<endl;
        cout<<endl;
    }

}
