#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    string sss;
    cin>>sss;
    cout<<sss<<endl;
    int n, m;
    cin>>n>>m;

    int lost_to[n+1]={0};

    set<int>s;
    for(int i=1; i<=n; i++)
    {
        s.insert(i);
    }

    for(int j=0; j<m; j++)
    {
        int l, r, x;
        cin>>l>>r>>x;

        auto it=s.lower_bound(l);
        vector<int>to_erase;

        for(it; *it<=r and it!=s.end(); it++)
        {
            //cout<<"here at : "<<(*it)<<endl;
            if((*it)!=x)
            {
                lost_to[(*it)]=x;
                to_erase.push_back((*it));
            }
        }
        for(int i=0; i<to_erase.size(); i++)
        {
            s.erase(to_erase[i]);
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<lost_to[i]<<" ";
    }
    cout<<endl;

}
