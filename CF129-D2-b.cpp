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
using namespace std;
main()
{
    int n, m;
    cin>>n>>m;
    int arr[n+1]={0}, ans=0, a=0;
    int v[n+1][n+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            v[i][j]=0;
        }

    }


    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        arr[a]++;
        arr[b]++;
        v[a][b]=1;
        v[b][a]=1;
    }
    for(int i=1; i<=n; i++)
    {
        if(arr[i]==0)
        {
            a++;
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }



    for(int i=1; i<=n; i++)
    {

        for(int j=1; i<=n; i++)
        {
            if(arr[i]==1)
            {
                ans++;
                for(int k=1; k<=n; k++)
                {
                    if(v[i][k]==1)
                    {
                        arr[i]=0;
                        arr[k]--;
                        v[k][i]=0;
                        v[i][k]=0;
                    }
                }
            }
        }
    }
    int i;
    for(i=0; i<=n; i++)
    {
        if(arr[i]!=0)
            break;
    }
    if(i==n+1)
        ans++;
    cout<<n-ans<<endl;
}
