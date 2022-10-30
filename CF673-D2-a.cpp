#include<bits/stdc++.h>
using namespace std;

typedef map<int, int> Mii;
//typedef map<ll, ll> mll;

#define watch(x) cout << (#x) << " is " << (x) << endl
int main()
{
    int y;
    cin>>y;
    while(y--)
    {
        long long n,t;
        cin>>n>>t;
        int b[n]={};
        Mii  Aa, Bb;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(Aa[t-x]==0)
                b[i]=1, Aa[x]++;
            else if(Bb[t-x]==0)
            {
                b[i]=0;
                Bb[x]++;
            }
            else {
                if(Aa[t-x] >= Bb[t-x]){
                    Bb[x]++;
                    b[i]=0;
                }
                else b[i]=1, Aa[x]++;
            }
        }
        for(int i=0; i<n; i++)
        {
            cout<<b[i]<<" ";
        }
        cout<<endl;

    }
}
