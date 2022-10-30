#include<bits/stdc++.h>

using namespace std;


typedef long long ll;

int main()
{
    ll a, b;
    cin>>a>>b;
    ll gcd=__gcd(a,b);
    int n;
    cin>>n;
    set<int>s;
    for(ll i=1; i*i<=gcd; i++)
    {
        if(gcd%i==0)
        {
            s.insert(i);
            s.insert(gcd/i);
        }
    }

    while(n--)
    {
        ll l, h;
        cin>>l>>h;
        auto it=s.lower_bound(h);
        if(it!=s.end() and *it==h)
        {
            cout<<h<<endl;
        }
        else{
            if(it==s.begin())
            {
                cout<<-1<<endl;
            }
            else{
                it--;
                if(*it<=h and *it>=l)
                {
                    cout<<*it<<endl;
                }
                else{
                    cout<<-1<<endl;
                }
            }
        }
    }
}
