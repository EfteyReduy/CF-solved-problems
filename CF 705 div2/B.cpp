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
}


main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int h, m;
        cin>>h>>m;
        string s;
        cin>>s;
        int i, hh, mm;
        hh=mm=0;
        int val[]={0, 1, 2, 5, 8};
        map<int, int>mp;
        mp[0]=1;
        mp[1]=1;
        mp[2]=1;
        mp[5]=1;
        mp[8]=1;
        for(i=0; i<s.length(); i++)
        {
            if(s[i]==':')
                break;
            hh=hh*10;
            hh+=(s[i]-'0');
        }
        i++;
        for( ; i<s.length(); i++)
        {
            mm=mm*10;
            mm+=(s[i]-'0');
        }

        bool pos=false;
        while(1)
        {
            int rm, d1, d2;
            d1=hh%10;
            d2=hh/10;
            if(mp[d1]==1 and mp[d2]==1)
            {
                int x=d1*10+d2;
                if(x<m)
                {
                    //cout<<x<<endl;
                    break;
                }
            }
            hh++;
            pos=true;
            //cout<<"HERE"<<endl;
            if(hh==h)
            {
                hh=0;
                break;
            }
        }
        if(pos==false)
        {
            while(1)
            {
                int rm, d1, d2;
                d1=mm%10;
                d2=mm/10;
                if(mp[d1]==1 and mp[d2]==1)
                {
                    int x=d1*10+d2;
                    if(x<h)
                    {
                        break;
                    }
                }
                mm++;
                if(mm==m)
                {
                    mm=0;
                    hh++;
                    if(hh==h)
                        hh=0;
                    while(1)
                    {
                       // cout<<"HRE"<<endl;
                        int rm, d3, d4;
                        d3=hh%10;
                        d4=hh/10;
                        if(mp[d3]==1 and mp[d4]==1)
                        {
                            int x=d3*10+d4;
                            if(x<m)
                            {
                                break;
                            }
                        }
                        hh++;
                        pos=true;
                        if(hh==h){
                            hh=0;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        else{
            mm=0;
        }

//        while(1)
//        {
//            int rm, d1, d2;
//            d1=hh%10;
//            d2=hh/10;
//            if(mp[d1]==1 and mp[d2]==1)
//            {
//                int x=d1*10+d2;
//                if(x<m)
//                {
//                    //cout<<x<<endl;
//                    break;
//                }
//            }
//            hh++;
//            if(hh==h)
//                hh=0;
//        }
        cout<<hh/10<<hh%10<<":"<<mm/10<<mm%10<<endl;
    }
    return 0;
}




