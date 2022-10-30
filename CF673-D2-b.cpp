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
        vector<int> seq[n+1];
        pair<int, int> p[n+1];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            seq[arr[i]].push_back(i+1);
        }
        for(int i=1; i<=n; i++)
        {
            p[i]=make_pair(seq[i].size(), i);

        }
        sort(p+1, p+n+1);

        int ans[n+1]={0};

        int j=1;

        int a=p[j].first;
        float y=n, z=a;
        int x=ceil(y/a);
        for(int i=1; i<x; i++)
        {
            ans[i]=-1;
        }

        bool cont =false;
        int cou=0;
        for(int i=x; i<=n; i++)
        {
            int aa=p[j].second;
            for(int j=0; j<n; j++)
            {
                if(arr[j]==aa)
                    cont=true;
                else
                    cou++;

                if((j+1)%(n/i)==0)
                {
                    if(!cont)
                    {
                        ans[i]=-1;
                        break;
                    }
                    else{
                        cont=false;

                    }
                }


            }
            if(cont)
            {
                ans[i]=p[j].second();
            }

        }

    }



}
