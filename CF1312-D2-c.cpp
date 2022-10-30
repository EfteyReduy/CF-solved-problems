#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;

    while(t--){
        long long n, k;
        cin>>n>>k;
        long long arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        long long taken[63];
        for(int i=0; i<=62; i++)
        {
            taken[i]=0;
        }

        bool ans=true;
        for(int i=0; i<n; i++)
        {
            long long a=arr[i], j=0;

            while(a>0)
            {
                long long r=a%k;
                if(r==1)
                {
                    taken[j]++;
                }
                else if(r>1)
                {
                    cout<<"NO"<<endl;
                    ans=false;
                    break;
                }
                a=a/k;
                j++;
            }
            if(!ans)
                break;
        }
        if(ans)
        {
            for(int i=0; i<62; i++)
            {
                if(taken[i]>1)
                {
                    cout<<"NO"<<endl;
                    ans=false;
                    break;
                }
            }
            if(ans)
            {
                cout<<"YES"<<endl;
            }
        }
    }

}
