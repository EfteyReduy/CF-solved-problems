
#include<bits/stdc++.h>

using namespace std;


#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

typedef long long int ll;
typedef unsigned long long int ull;


void ces(int cas)
{
    cout<<"Case "<<cas<<": ";
}


priority_queue<pair<int, int >>pq;

main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        ll a, b, c, k;
        cin>>a>>b>>c;
        ll total = a+b+c;
        ces(i);
        cin>>k;
        bool pos = false;
        if(k==0)
        {
            if(a==b and b == c)
            {
                pos = true;
            }

        }
        else if(total %3 == 0)
        {
            total/=3;
            if(abs(total-a)%k or abs(total - b)%k or abs(total - c)%k)
            {
                pos=false;
            }
            else{
                pos=true;
            }
        }

        if(pos){
            cout<<"Peaceful"<<endl;
        }
        else{
            cout<<"Fight"<<endl;
        }
    }

    return 0;
}

