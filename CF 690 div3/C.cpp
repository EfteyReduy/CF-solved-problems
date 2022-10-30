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
        int x;
        cin>>x;
        vector<int>ans;
        if(x>45)
        {
            cout<<-1<<endl;
        }
        else
        {
            for(int i=9; i>0; i--)
            {
                if(x-i>=0)
                {
                    x-=i;
                    ans.push_back(i);
                }
            }
            sort(ans.begin(), ans.end());
            for(auto i:ans)
            {
                cout<<i;
            }

            cout<<endl;
        }
    }
}

