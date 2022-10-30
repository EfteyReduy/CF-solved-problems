#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define PP pop_back
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define I insert
#define E erase
#define B back
#define C clear
#define SZ size
#define Vi vector<int>
#define Vll vector<ll>
#define Vpii vector<pair<int, int> >
#define Vpll vector<pair< ll, ll> >

#define precision(x) cout<<fixed<<setprecision(x);


using namespace std;


vector<int>divisors;

void allDivisiors(long long n){
    int limit=sqrt(n+1);
    for(int i=1; i<=limit; i++){
        if(n%i==0){
            if(n/i==i) divisors.push_back(i);
            else divisors.push_back(i), divisors.push_back(n/i);
        }
    }
}


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n, x, y;
        cin>>n>>x>>y;
        ll sub=y-x;
        allDivisiors(sub);
        sort(divisors.begin(), divisors.end());
        vector<long long> v;
        v.push_back(x);
        int j=0;
        ll rem=n;
        while(j<divisors.size())
        {
            rem=n;
            ll i;
            for(i=0; i<n-1; i++)
            {
                v.push_back(v[i]+divisors[j]);
               /// rem=n-i;
                if(v[i+1]==y)
                {
                    break;
                }
            }
            rem=n-i-1;
            if(v[n-1]>=y)
            {
                break;
            }
            v.clear();
            v[0]=x;
            j++;

        }

        ll a=x;
        while(rem--)
        {
            if(a-divisors[j]>0)
            {
                a=a-divisors[j];
                v.push_back(a);
            }
            else{
                break;
            }
        }
        if(rem>0)
        {
            a=y;
            while(rem--)
            {
                if(a-divisors[j]>0)
                {
                    a=a+divisors[j];
                    v.push_back(a);
                }

            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;












        divisors.clear();
    }
}
