
#include<bits/stdc++.h>


typedef long long int ll;

#define db(x) cout<<#x<<" = "<<x<<endl  //For debugging


using namespace std;

double power(double n, ll x) //return n^x
{
	if(x == 0) return 1;
	if(x == 1) return n;
	double ans = 1.0;
	while(x){
	    if( x&1 ) ans = ans*n;
        n = n*n;
        x = x/2;
        if(ans > 1e9 or n > 1e9)
        {
            ans = -1;
            break;
        }
	}
	return ans;
}

main()
{
    double init_population, groath_rate, migrated_ppl, target_ppl;

    cin>>init_population>>groath_rate>>migrated_ppl>>target_ppl;

    double groath_factor = (1.0 + groath_rate/100.0);

    //db(groath_factor);
    ll ans = 1e15, mid;
    ll lo = 1, hi = 1e15;
    while(lo<=hi)
    {
        mid = (lo + hi)/2;

        double groath = power(groath_factor, mid);
        if(groath == -1)
        {
            hi = mid;
            continue;
        }
        double total_migrated = migrated_ppl*((1 - (groath))/(1 - groath_factor));

        double total = (init_population * groath) + total_migrated;

        if(total >= target_ppl)
        {
            ans = min(ans, mid);
            hi = mid-1;
        }
        else{
            lo = mid + 1;
        }
    }

    cout<<ans<<endl;

    return 0;
}




