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
using namespace std;
main()
{
    int n, z=0;
    cin>>n;
    int arr[n], ne=0;
    vector<int> pos, neg;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]<0)
            neg.PB(arr[i]);
        else if(arr[i]>0)
        {
            pos.PB(arr[i]);
        }
        else
        {
            z++;
        }
    }
    bool nopos=false;
    int jor=0;
    if(pos.SZ()==0)
    {
        int a=neg[0];
        pos.PB(a);
        a=neg[1];
        pos.PB(a);
        nopos=true;
    }
    int j=0;
    if(nopos)
    {
        j=2;
    }
    int a=neg.SZ()-j;
    if(a%2==0)
    {
        a--;
        jor=1;
    }
    cout<<a;
    int jj=neg.SZ();
    for(j; j<(jj-jor); j++)
    {
        cout<<" "<<neg[j];
    }
    cout<<endl;
    if(nopos)
    {
        cout<<2<<" "<<neg[0]<<" "<<neg[1]<<endl;
    }
    else{
        cout<<pos.size();
        for(int i=0; i<pos.size(); i++)
        {
            cout<<" "<<pos[i];
        }
        cout<<endl;
    }

    cout<<z+jor;
    for(int i=0; i<z; i++)
    {
        cout<<" "<<0;
    }
    if(jor)
    {
        int x=neg.size();
        cout<<" "<<neg[x-1];

    }
    cout<<endl;
}

