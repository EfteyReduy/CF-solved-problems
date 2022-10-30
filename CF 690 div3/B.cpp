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


int main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        bool pos=false;
        if(s.length()<4)
        {
            cout<<"NO"<<endl;
            continue;
        }

        if(s[0]=='2' and s[1]=='0' and s[2]=='2' and s[3]=='0')
        {
            pos=true;
        }
        if(s[0]=='2' and s[1]=='0' and s[2]=='2' and s[n-1]=='0')
        {
            pos=true;
        }
        if(s[0]=='2' and s[1]=='0' and s[n-2]=='2' and s[n-1]=='0')
        {
            pos=true;
        }
        if(s[0]=='2' and s[n-3]=='0' and s[n-2]=='2' and s[n-1]=='0')
        {
            pos=true;
        }
        if(s[n-4]=='2' and s[n-3]=='0' and s[n-2]=='2' and s[n-1]=='0')
        {
            pos=true;
        }

        if(pos)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

    }
}

