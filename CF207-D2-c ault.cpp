#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;

    vector<int>lost_to(n+1, 0), range(n+1, 0);

    set<int>s;
    for(int i=1; i<=n; i++)
    {
        s.insert(i);
    }
    auto it=s.begin();
    cout<<endl;
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

