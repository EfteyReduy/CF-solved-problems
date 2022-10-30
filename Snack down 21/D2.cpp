#include<bits/stdc++.h>


using namespace std;
typedef long long ll;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        ll arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        sort(arr, arr+n);
        ll cum[n];
        cum[0]=arr[0];

        for(int i=1; i<n; i++)
        {
            cum[i]=arr[i]+cum[i-1];
        }

        int strt=1, ind=n-2;

        ll ans=2e9;
        ans=((n-1)*arr[n-1])-(cum[n-1]-cum[0]);

        ans=min(ans,((arr[n-2]*(n-1))-cum[n-2]));

        ans=min(ans, (cum[n-2]-(n-1)*arr[0]));

        ans=min(ans, cum[n-1]-cum[0]-((n-1)*arr[1]));

        ll mx=cum[n-1]-arr[0], mn=cum[n-2]-arr[n-1];

        //cout<<"ans = "<<ans<<endl;
        ll lft, rit;
        for(int i=1; i<n-1; i++)
        {

            lft=(arr[i]*i)-(cum[i]-arr[0]);
            rit=(cum[n-2]-cum[i])-(arr[i]*(n-i-1));

            ans=min(ans, (lft+rit)+min(arr[i]-arr[0], arr[n-1]-arr[i]));


            //cout<<"ans = "<<ans<<" at i = "<<i<<endl;


/*
            ll xx=(arr[i]*(i+1))-(cum[i]);
            xx+=(cum[n-2]-cum[i])-(arr[i]*(n-i-2));
            ll xy=min(abs(cum[n-2]-xx), abs(cum[n-1]-arr[0]-xx));
            xy=xx+min(abs(arr[i]-arr[0]), abs(arr[i]-arr[n-1]));
            ans=min(ans, xy);
            */
        }

        //cout<<"ans = "<<ans<<endl;

        while(strt<ind)
        {
            //cout<<"Strt = "<<strt<<"   ind = "<<ind<<endl;
            ans=min(ans, abs((arr[ind]-arr[0])-(arr[n-1]-arr[strt])));

            if((arr[strt]-arr[0])<(arr[n-1]-arr[ind]))
            {
                strt++;
            }
            else{
                ind--;
            }
            if(ans==0)
            {
                break;
            }
        }
        cout<<ans<<endl;


    }
}

