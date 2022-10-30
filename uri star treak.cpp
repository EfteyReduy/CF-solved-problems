#include<bits/stdc++.h>
using namespace std;


#define jor(a) !(a&1) /// jor means EVEN number
#define bjor(a) (a&1) /// bjor means ODD number
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

typedef long long ll;

int main()
{
    FAST
    ll n; cin>>n;
	ll sum=0;
	ll a[n];
	for(int i=0; i<n; i++) cin>>a[i], sum+=a[i];

	ll indx=-1;
	for(int i=0; i<n; i++){
		if(jor(a[i])) {indx = i; break;}
	}
	if(indx==-1){
		cout<<n<<" "<<sum-n<<endl;
		return 0;
	}

	ll z = indx;
	ll ans = indx+1;
	for(int i=0; i<indx; i++){
		if(a[i]>1) ans++;
	}

	cout<<z+1<<" "<<sum - ans<<endl;

	return 0;

}
