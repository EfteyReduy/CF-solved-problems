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
        int arr[n];
        map<int, int>mp;
        int prims[]={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

        int m=0;
        vector<int>vc;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            for(int j=0; j<11; j++)
            {
                if(a%prims[j]==0)
                {
                    if(mp[prims[j]]==0)
                    {
                        m++;
                        mp[prims[j]]=m;

                    }
                    vc.push_back(mp[prims[j]]);
                    break;
                }
            }
        }
        cout<<m<<endl;
        for(int i=0; i<n; i++)
        {
            cout<<vc[i]<<" ";
        }
        cout<<endl;
    }
}
