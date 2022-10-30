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


main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string a, b;
        cin>>a>>b;

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        long long ar[26], br[26];
        for(int i=0; i< 26; i++)
        {
            ar[i]=0;
            br[i]=0;
        }
        for(int i=0; i< n; i++)
        {
            ar[(a[i]-'a')]++;
            br[(b[i]-'a')]++;
        }
        long long cum=0;
        bool has=true;
        for(int i=0; i<26; i++)
        {
            cum+=ar[i]-br[i];
            if(cum<0)
                has=false;
        }
        //cout<<cum<<" CUM IS "<<endl;

        if(has)
        {
            //cout<<"HERE I AM"<<endl;
            long long crr[26];
            for(int i=0; i<26; i++)
            {
                for(int j=0; j<26; j++)
                {
                    if(ar[j]>=br[j])
                    {

                        ar[j]-=br[j];
                        br[j]=0;
                    }
                }
                for(int l=0; l<26; l++)
                {
                    crr[l]=0;
                }
                int temp=k, j;
                for(j=0; j<25; j++)
                {
                    if(ar[j]>0)
                    {
                        if(ar[j]<temp)
                        {
                            has=false;
                        }
                        else{
                            ar[j]=ar[j]-temp;
                            crr[j+1]=temp;
                            temp=0;
                            break;
                        }
                    }
                }


                for(j=0; j<26; j++)
                {
                    ar[j]+=crr[j];
                    crr[j]=0;
                }


            }
            for(int j=0; j<26; j++)
            {
                if(ar[j]!=0)
                    has=false;
            }
        }

        if(has)
        {
            cout<<"YES"<<endl;

        }
        else{
            cout<<"NO"<<endl;
        }

    }
}

