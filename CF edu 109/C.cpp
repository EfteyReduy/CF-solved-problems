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
ll gcdExtended(ll a, ll b, ll * x, ll * y)
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


///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
}

void NO(){
    cout<<"NO"<<"\n";
}
void YES(){
    cout<<"YES"<<"\n";
}
void No(){
    cout<<"No"<<"\n";
}
void Yes(){
    cout<<"Yes"<<"\n";
}
void ces(int cas)
{
    cout<<"Case "<<cas<<": ";
}
main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        pair<int, pair<int, char> >p[n];
        for(int i=0; i<n; i++)
        {
            cin>>p[i].F;
        }
        for(int i=0; i<n; i++)
        {
            cin>>p[i].S.S;
            p[i].S.F=i;
        }

        vector<pair<int, pair<int, char> > >ep, op;

        sort(p, p+n);

        for(int i=0; i<n; i++)
        {
            if(p[i].first%2==0)
            {
                ep.push_back(p[i]);
            }
            else{
                op.push_back(p[i]);
            }
        }
        int ans[n];
        memset(ans, -1, sizeof(ans));
        stack<pair<int, pair<int, char> > >ll, rr;
        for(int i=0; i<ep.size(); i++)
        {
            pair<int, pair<int, char> >pp;
            if(ep[i].S.S=='L')
            {
                if(!rr.empty())
                {
                    pp=rr.top();
                    rr.pop();
                    int tim=ep[i].F-pp.F;
                    tim/=2;
                    ans[pp.S.F]=tim;
                    ans[ep[i].S.F]=tim;
                }
                else if(!ll.empty())
                {
                    pp=ll.top();
                    ll.pop();
                    int tim=ep[i].F+pp.F;
                    tim/=2;
                    ans[pp.S.F]=tim;
                    ans[ep[i].S.F]=tim;
                }
                else{
                    ll.push(ep[i]);
                }
            }
            else if(ep[i].S.S=='R')
            {
                rr.push(ep[i]);
            }
        }
        while(!rr.empty())
        {
            pair<int, pair<int, char> >ff, ss;
            ff=rr.top();
            rr.pop();
            if(!rr.empty())
            {
                ss=rr.top();
                rr.pop();
                int tim=m+m-ss.F-ff.F;
                tim/=2;
                ans[ff.S.F]=tim;
                ans[ss.S.F]=tim;
            }
            else{
                if(!ll.empty())
                {
                    ss=ll.top();
                    ll.pop();
                    int tim=m+m-abs(ss.F-ff.F);
                    tim/=2;
                    ans[ff.S.F]=tim;
                    ans[ss.S.F]=tim;
                }
            }
        }
//        ll.clear();
//        rr.clear();
        while(!ll.empty())
        {
            ll.pop();
        }
        while(!rr.empty())
        {
            rr.pop();
        }
        for(int i=0; i<op.size(); i++)
        {
            pair<int, pair<int, char> >pp;
            if(op[i].S.S=='L')
            {
                if(!rr.empty())
                {
                    pp=rr.top();
                    rr.pop();
                    int tim=op[i].F-pp.F;
                    tim/=2;
                    ans[pp.S.F]=tim;
                    ans[op[i].S.F]=tim;
                }
                else if(!ll.empty())
                {
                    pp=ll.top();
                    ll.pop();
                    int tim=op[i].F+pp.F;
                    tim/=2;
                    ans[pp.S.F]=tim;
                    ans[op[i].S.F]=tim;
                }
                else{
                  // cout<<"HERE at "<<op[i].S.F<<endl;
                    ll.push(op[i]);
                }
            }
            else if(op[i].S.S=='R')
            {
                rr.push(op[i]);
            }
        }

        while(!rr.empty())
        {
            pair<int, pair<int, char> >ff, ss;
            ff=rr.top();
            rr.pop();
            if(!rr.empty())
            {
                ss=rr.top();
                rr.pop();
                int tim=m+m-ss.F-ff.F;
                tim/=2;
                ans[ff.S.F]=tim;
                ans[ss.S.F]=tim;
            }
            else{
                if(!ll.empty())
                {
                    ss=ll.top();
                    ll.pop();
                    int tim=m+m-abs(ss.F-ff.F);
                    tim/=2;
                    ans[ff.S.F]=tim;
                    ans[ss.S.F]=tim;
                }
            }
        }

        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;


    }

    return 0;
}



