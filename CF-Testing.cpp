// C++ program to find number of subarrays
// with sum exactly equal to k.
    #include <bits/stdc++.h>
    using namespace std;
    typedef long long ll ;
    ll p , q ;
    int t;
    ll getans(ll d){
        long long ret = p ;
        while(ret%q==0) ret/=d ;
        return ret ;

    }
    int main()
    {
        cin >> t ;
        while(t--){
            cin >> p >> q ;
            if( p < q){
                cout << p << '\n';
                continue;
            }
             if(p == q){
                ll ans  = 1 ;
                for(ll i = 2 ; i*i<=p ; ++i){
                    if(p % i)
                        continue ;
                    ans = max(ans , max(i , p / i));
                }
                cout << ans << '\n' ;
                continue;
            }
             if(p % q){
                cout << p << '\n';
                continue;
            }
            long long ans = getans(q) ;
            for(long long i=2;i*i<=q;++i)
                if(q%i==0){
                ans = max(ans ,getans(i)) ;
                ans = max(ans ,getans(q/i));
            }
            cout << ans << endl ;
        }
    	return 0;
    }
