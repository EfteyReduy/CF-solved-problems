#include<bits/stdc++.h>

using namespace std;


main()
{
    int n, m;
    cin>>n>>m;
    long long  brr[m];
    vector<int>arr;
    set<pair<long long, long long> >ar;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        //arr.push_back(a);
        ar.insert({a,i});
    }

    for(int i=0; i<m; i++)
    {
        cin>>brr[i];
    }
    //sort(arr.begin(), arr.end() );

    bool taken[n];
    //vector<int>ans;
    for(int i=0; i<m; i++)
    {
        long long a=brr[i];
        auto bgn=ar.lower_bound({a+1,0});

        if(bgn!=ar.begin())
        {

            bgn--;
            pair<long long, long long> p=*(bgn);
            cout<<( (p.first))<<endl;
            ar.erase(bgn);
//            if((*bgn)==brr[i])
//            {
//                cout<<(*bgn)<<endl;
//                ar.erase(bgn);
//            }
//            else{
//                if(bgn==ar.begin())
//                {
//                    cout<<-1<<endl;
//                }
//                else{
//                    bgn--;
//                    cout<<(*bgn)<<endl;
//                    ar.erase(bgn);
//                }
//            }
        }
        else{
            if(bgn==ar.begin())
            {
                cout<<-1<<endl;
                continue;
            }

        }
    }

}
