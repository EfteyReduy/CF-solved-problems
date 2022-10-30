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

ll mod=1e9+7;

void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}


main()
{
    fastIO();

    int n, m, k;
    cin>>n>>m>>k;

    int dist[n][m][5], arr[n][m][5], inf=1e9;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m-1; j++)
        {
            int x;
            cin>>x;
            dist[i][j][0]=x;
            dist[i][j+1][1]=x;
        }
        dist[i][0][1]=inf;
        dist[i][m-1][0]=inf;
    }


    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<m; j++)
        {
            int x;
            cin>>x;
            dist[i][j][2]=x;
            dist[i+1][j][3]=x;
        }
    }

    if(k%2)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<-1<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
    k=k/2;


    for(int i=0; i<m; i++)
    {
        dist[0][i][3]=inf;
        dist[n-1][i][2]=inf;
    }

    int ans[n][m];


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            dist[i][j][4]=0;
            ans[i][j]=0;
        }
    }


    for(int z=0; z<k; z++)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ll x, y, z, aa;
                x=y=z=aa=1e9;
                if(j>0)
                {
                    x=(ans[i][j-1]+dist[i][j][1]);
                }
                if(j<m-1)
                {
                    y=ans[i][j+1]+dist[i][j][0];
                }

                if(i<n-1)
                {
                    z=(ans[i+1][j]+dist[i][j][2]);
                }
                if(i>0)
                {
                    aa=(ans[i-1][j]+dist[i][j][3]);
                }
                dist[i][j][4]=min({x, y, z, aa});
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans[i][j]=dist[i][j][4];
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<2*ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}

