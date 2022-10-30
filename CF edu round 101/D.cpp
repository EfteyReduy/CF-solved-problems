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
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;


// function for extended Euclidean Algorithm
int gcdExtended(ll a, ll b, ll* x, ll* y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}


ll modInverse(ll a, ll m)
{
	ll x, y;
	ll g = gcdExtended(a, m, &x, &y);
	if (g != 1)
        return -1;
		//printf("Inverse doesn't exist");
	else
	{
		ll res = (x % m + m) % m;
		//printf("Modular multiplicative inverse is %d", res);
		return res;
	}
}


void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



int main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n, k;
        cin>>n;
        set<int>s;
        bool nn=false;
        ll last;
        for(long long i=2; i<=n; i=i*i)
        {
            if(i==n)
                nn=true;
            s.insert(i);
            last=i;
            //cout<<i<<"stack "<<endl;

        }
        vector<pair<int,int>>ans;
        for(int i=n-1; i>2; i--)
        {
            if(s.find(i)==s.end())
            {
                ans.push_back({i, n});
            }
        }
        if(!nn)
        {
            auto it=s.end();
            it--;
            int x=(*it);
            ans.push_back({n, x});
            ans.push_back({n, x});
        }

        while(last>2)
        {
            ll x=last;
            last=sqrt(last);
            ans.push_back({x,last});
            ans.push_back({x,last});
            if(last==2)
                break;
        }
        cout<<ans.size()<<endl;
        for(auto i:ans)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }



    }

}


