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
        int n;
        cin>>n;
        pair<int, int>p[n];
        int arr[n*2];
        set<pair<int, int>, cmpStruct>s, st;
        for(int i=0; i<n*2; i++)
        {
            cin>>arr[i];
            s.insert({arr[i], i});
        }
        sort(arr, arr+(2*n));

        int hi=arr[2*n-1], higest;
        higest=hi;
        int x;
        bool pos=true;
        auto iit=s.lower_bound({higest, 0});
        pair<int, int>pp=*iit;
//
        s.erase(iit);

        for(int j=0; j<2*n-1; j++)
        {
            x=higest+arr[j];
            st=s;
            auto iit=st.lower_bound({arr[j], 0});
            st.erase(iit);
            pos=true;
            p[0]={higest, arr[j]};
            hi=higest;
            bool taken[2*n]={0};
            for(int i=1; i<n; i++)
            {
                auto aid=st.end();
                aid--;
                pair<int, int> ppp=*aid;
                int a=ppp.first;

                int to_find=hi-a;
                hi=max(to_find, a);
                iit=st.lower_bound({a, 0});
                if(iit!=st.end())
                    st.erase(iit);
                else{
                    pos=false;
                    break;
                }
                auto it=st.lower_bound({to_find, 0});

                pair<int , int>pt;
                if(it!=st.end())
                {
                    pt=*it;
                    if(pt.first==to_find)
                    {
                        p[i]={a, to_find};
                        st.erase(it);
                    }
                    else{
                        pos=false;
                        break;
                    }
                }
                else {
                    pos=false;
                    break;
                }
            }
            if(pos==true)
                break;
        }
        if(pos)
        {
            cout<<"YES"<<endl;
            cout<<x<<endl;
            for(int i=0; i<n; i++)
            {
                cout<<p[i].first<<" "<<p[i].second<<endl;
            }
        }
        else{
            cout<<"NO"<<endl;
        }

    }
    return 0;
}


