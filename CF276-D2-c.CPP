#include<bits/stdc++.h>
#define N 300005
#define ll long long

#define db(x) cout<<#x<<" = "<<x<<endl

using namespace std;



ll tree[N];

void update(int n, int val, int p){

    while(p<=n)
    {
        tree[p]+=val;
        p+=(p & -p);
    }
}

ll read(int p)
{
   long long sum=0;
   while(p>0)
   {
       sum+=tree[p];
       p-=(p & -p);
   }
   return sum;

}


int main()
{
    int n, q;
    cin>>n>>q;
    ll arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sort(arr, arr+n, greater<int>() );

    for(int i=0; i<q; i++)
    {
        int a, b;
        cin>>a>>b;
        if(a>b)
            swap(a,b);
        update(n, 1, a);
        update(n, -1, b+1);
    }

    ll cum[n];
    for(int i=0; i<n; i++)
    {
        cum[i]=read(i+1);
        //db(cum[i]);
    }
    sort(cum, cum+n, greater<int>() );
    ll ans=0;
    for(int i=0; i<n; i++)
    {
        ans+=cum[i]*arr[i];
    }
    cout<<ans<<endl;

}

