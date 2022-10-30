#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin>>n>>m;
    //int lost_to[n+1], range[n+1];
    vector<int>lost_to(n+1, 0), range(n+1, 0);
//    for(int i=0; i<=n; i++)
//    {
//        lost_to[i]=0, range[i]=0;
//    }

    for(int j=0; j<m; j++)
    {
        int l, r, x;
        cin>>l>>r>>x;
        for(int i=l; i<=r; i++)
        {

            if(i==x)
                continue;
            if(lost_to[i]!=0)
            {
                if(lost_to[lost_to[i]]==0 and lost_to[i]!=x)
                    lost_to[lost_to[i]]=x;
                i=range[i];
                range[i]=max(range[i], r);
                continue;
            }
            lost_to[i]=x;
            range[i]=r;
//            for(int ii=1; ii<=n; ii++)
//            {
//                cout<<lost_to[ii]<<" ";
//            }
//            cout<<endl;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<lost_to[i]<<" ";
    }
    cout<<endl;

}
