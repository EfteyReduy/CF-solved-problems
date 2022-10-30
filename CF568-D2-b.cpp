#include<bits/stdc++.h>
using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    int arr[n], ans[n];
    for(int i=0; i<n; i++)
        cin>>arr[i];

    int k=0, j=0;
    long long tot=0;
    multiset<int>s;
    multiset<int> :: iterator it;
    multiset<int>rej;
    for(int i=0; i<n; i++)
    {
        tot=tot+arr[i];


        while(tot>m)
        {

            it=s.end();
            it--;
            tot-=(*it);
            //cout<<" *it = "<<*it<<endl;
            rej.insert(*it);
            s.erase(it);
            j++;
            //cout<<" here "<<endl;
        }


        while(tot<=m and rej.size())
        {
            //cout<<*it<<endl;
            it=rej.begin();
            tot+=(*it);
            if(tot<=m)
            {
                j--;
                s.insert(*it);
                rej.erase(it);
                it++;


            }
            else{
                tot-=(*it);
                break;
            }
        }
        ans[i]=j;
        s.insert(arr[i]);
    }
    for(int i=0; i<n; i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}
