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
    int t=1;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        stack<char>st;
        bool pos=true;
        int ext=0;
        int op=0, cl=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
                op++;
            else if(s[i]==')')
                cl++;
        }
        if(op>cl)
        {
            reverse(s.begin(), s.end());
            for(int i=0; i<s.length(); i++)
            {
                if(s[i]=='(')
                {
                    s[i]=')';
                }
                else if(s[i]==')')
                {
                    s[i]='(';
                }
            }
        }
        //cout<<s<<endl;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='(')
            {
                st.push(s[i]);
            }
            else if(s[i]=='?')
            {
                ext++;
            }
            else{
                if(st.size()>0)
                    st.pop();
                else
                {
                    if(ext>0)
                    {
                        ext--;
                    }
                    else
                        pos=false;
                }

            }

        }
        if(pos)
        {
            if(st.size()>1)
            {
                cout<<"NO"<<endl;
            }
            else if (st.size()==1)
            {
                int i=s.length();
                i--;
                if(s[i]=='?' and (ext-1)%2==0)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
            else if(ext%2==0)
            {
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }

        }
        else{
            cout<<"NO"<<endl;
        }
    }

}

