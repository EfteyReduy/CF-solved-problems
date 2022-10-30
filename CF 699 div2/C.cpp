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
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
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
        int arr[n], brr[n], prr[m];

        map<int, set<int> >ma, mb, col, mp;

        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
            //ma[arr[i]].insert(i);
        }
        for(int i=0;i <n; i++)
        {
            cin>>brr[i];
            //mb[arr[i]].insert(i);
        }
        for(int i=0; i<m; i++)
        {
            cin>>prr[i];
        }
        int ans[m], te=0;
        //memset(ans, -1, sizeof(ans));
        for(int i=0; i<n; i++)
        {
            if(arr[i]!=brr[i])
            {
                col[brr[i]].insert(i);
            }
            else{
                te++;
                mp[brr[i]].insert(i);
            }
        }
        int rem=0;
        for(int i=0; i<m; i++, rem++)
        {
            int x=prr[i];

            if(col[x].size()!=0)
            {
                auto it=col[x].begin();
                ans[i]=*it+1;
                mp[x].insert((ans[i]-1));
                col[x].erase(it);
                te++;
            }
            else{
                if(mp[x].size()!=0)
                {
                    auto it=mp[x].begin();
                    ans[i]=*it+1;
                }
                else{
                    if(te==n)
                    {
                        rem=i;
                        break;
                    }
                    vector<int>del;
                    for(auto it:col)
                    {

                        if(it.second.size()>0)
                        {
                            auto iit=it.second.begin();
                            ans[i]=*iit+1;
                            break;
                        }
                        else{
                            del.push_back(it.first);
                        }
                    }
                    for(auto it : del)
                    {
                        col.erase(it);
                    }
                }

            }

        }
        bool pos=true;
        if(rem<m)
        {
            int last=prr[m-1];

            if(mp[last].size()!=0)
            {
                auto it=mp[last].begin();
                for(int i=rem; i<m; i++)
                {
                    ans[i]=*it+1;
                }
            }
            else{
                cout<<"NO"<<endl;
                pos=false;
                continue;
            }
            //cout<<rem<<endl;
        }

        for(int i=0; i<m; i++)
        {
            arr[ans[i]-1]=prr[i];
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i]!=brr[i])
            {
                cout<<"NO"<<endl;
                pos=false;
                break;
            }
        }
        if(pos)
        {
            cout<<"YES"<<endl;
            for(int i=0; i<m; i++)
            {
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }



    }
    return 0;
}


