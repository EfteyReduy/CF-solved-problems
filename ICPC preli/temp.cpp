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



void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(1)
    {
        ll L, L1, p=0,q=0;
        string s="";
        cin>>L>>L1;
        cin>>s;
        int i=0;
        while(s[i]!='/')
        {
            cout<<"here "<<s[i]<<endl;
            p=p*10+(s[i]-'0');
            i++;
        }
        i++;
        while(i<s.size())
        {
            cout<<"Here at i= "<<i<<endl;
            q=q*10+(s[i]-'0');
            i++;
        }

        if(p==0 and q==0 and L==0 and L1==0)
        {
            break;
        }

        cout<<p<<" "<<q<<endl;

    }

    return 0;
}




