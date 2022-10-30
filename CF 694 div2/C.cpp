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

/// Siv's algorithm  ==================================================================================
///====================================================================================================
bool status[400000];
int dif[100000]={0};

void siv(int N) {
    int sq = sqrt(N);

    for (int i = 4; i <= N; i += 2) {
        status[i] = 1;
    }

    for (int i = 3; i <= sq; i += 2) {
        if (status[i] == 0) {
            for (int j = i * i; j <= N; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}

void setDif(){
    int j=0;
    for(int i=2; i<400000 ; i++)
    {
        if(status[i]==0)
        {
            dif[j]=(i);
            j++;
        }
    }
}
///==================================================================================================

#define SSA(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});//sorting array of string in ascending order
#define SSD(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() > b.size();});//sorting array of string in descending order



typedef long long ll;
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pair :: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/

///comparison structure to use customized set.............
struct cmpStruct {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first < rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

//set<pair<int, int>, cmpStruct> s;


///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<ll,ll> &a,  const pair<ll,ll> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
}/**

..........................for priority queue reference.........................

https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/?ref=rp

**/

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        ll crr[m],arr[n], cost[m];
        for(int i=0; i<m; i++)
        {
            cost[i]=0;
            crr[i]=0;
        }
        pair<ll, ll>brr[n];

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            crr[(arr[i]-1)]++;
        }
//        for(int i=0; i<m; i++)
//        {
//            cout<<crr[i]<<" ";
//        }
        for(int i=0; i<m;i++)
        {

            cin>>brr[i].first;
            cost[i]=brr[i].first;
            brr[i].second=i;
        }
        //sort(arr, arr+n);
        sort(brr, brr+m, sortinrev);
        bool vis[m]={0};
        set<int>s;
        for(int i=0; i<m; i++)
        {
            s.insert(i);
        }
        ll ans=0;
        for(int i=0; i<m; i++)
        {
            ll x=brr[i].first;
            int pos=brr[i].second;
            ll totx=crr[pos];

//            db(x);
//            db(pos);
//            db(totx);

            if(totx==0)
                continue;
            if(s.empty())
            {
                ans+=(totx*x);
                continue;
            }
            auto it=s.lower_bound(pos);
            if(it==s.end() or (*it)!=pos)
            {
                it--;
            }

            vector<int>toerase;
            if(it==s.begin())
            {
                if(*it<pos){
                    ans+=cost[*it];
                    totx--;
                    toerase.push_back((*it));
                    s.erase(it);
                }
                ans+=(totx*x);
                continue;
            }
//
//            toerase.insert(pos);
            if(*it>=pos)
                it--;
            for(  ; totx>=0; it--, totx--)
            {
                toerase.push_back((*it));
                ans+=cost[(*it)];
                if(it==s.begin())
                {
                    break;
                }
            }

            for(auto ii:toerase)
            {
                db(ii);
                s.erase(ii);
            }

            ans+=(totx*x);


        }
        cout<<ans<<endl;


    }
    return 0;
}


