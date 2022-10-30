#include <bits/stdc++.h>
using namespace std;
#define lli long long int
#define ll long long

ll power(ll n, ll p)
{
	ll ans=1;
	while(p){
		if(p%2!=0) ans=(ans*n);
        n=(n*n);
		p=p/2;
	}
	return ans;
}

main(){
    ll n;
    cin>>n;
    ll arr[n], t=0, ans=1e17;
    for(int i=0;i <n; i++)
    {
        cin>>arr[i];
    }

    sort(arr, arr+n);

    ll c=1;
    while(1)
    {

        ll p=1;
        ll y=0;
        for(ll i=0; i<n; i++)
        {
            if(p>1e15)
            {
                y=-1;
                break;
            }
            y=y+abs(arr[i]-p);
            p=p*c;

        }
        if(y==-1)
        {
            break;
        }
        if(y>ans)
        {
            break;
        }

        ans=min(y,ans);

        c++;
    }
    cout<<ans<<endl;
}
