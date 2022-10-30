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


// function for extended Euclidean Algorithm
ll gcdExtended(ll a, ll b, ll * x, ll * y)
{
	if (a == 0)
	{
		*x = 0, *y = 1;
		return b;
	}
	ll x1, y1;
	ll gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

ll modInverse(ll a, ll m)
{
	ll x, y;
	ll g = gcdExtended(a, m, &x, &y);
	if (g != 1)
        return -1;
		//printf("Inverse doesn't exist");
	else
	{
		ll res = (x % m + m) % m;
		//printf("Modular multiplicative inverse is %d", res);
		return res;
	}
}


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
    for(int tcase=1; tcase<=t; tcase++)
    {
        int n, r, c;
        cin>>r>>c;
        bool table[r][c], vistd[r][c], vislr[r][c];
        int td[r][c], dt[r][c], lr[r][c], rl[r][c];
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                cin>>table[i][j];
                td[i][j]=dt[i][j]=lr[i][j]=rl[i][j]=0;
                vislr[i][j]=vistd[i][j]=0;
            }
        }


        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(table[i][j]==1 and vistd[i][j]==0)
                {
                    vistd[i][j]=1;
                    int k, cou=0;
                    for(k=i; k<r; k++)
                    {
                        if(table[k][j]==1)
                        {
                            cou++;
                            vistd[k][j]=1;
                        }
                        else{
                            //k--;
                            break;
                        }
                        td[k][j]=cou;
                    }
                    k--;
                    cou=1;
                    while(k>=i)
                    {
                        dt[k][j]=cou;
                        cou++;
                        k--;
                    }
                }
            }
        }

        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                if(table[i][j]==1 and vislr[i][j]==0)
                {
                    vislr[i][j]=1;
                    int k, cou=0;
                    for(k=j; k<c; k++)
                    {
                        if(table[i][k]==1)
                        {
                            cou++;
                            vislr[i][k]=1;
                        }
                        else{
                            //k--;
                            break;
                        }
                        lr[i][k]=cou;
                    }
                    k--;
                    cou=1;
                    while(k>=j)
                    {
                        rl[i][k]=cou;
                        cou++;
                        k--;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0; i<r; i++)
        {
            for(int j=0; j<c; j++)
            {
                int temp=0;
                int x=td[i][j], a=lr[i][j], b=rl[i][j], y=dt[i][j];
                //cout<<"( "<<x<<" "<<y<<" "<<a<<" "<<b<<" )";
                temp=(min(x,a/2)-1);
                if(temp>0)
                    ans+=temp;
                temp=(min(x,b/2)-1);
                if(temp>0)
                    ans+=temp;
                temp=(min(y/2,a)-1);
                if(temp>0)
                    ans+=temp;
                temp=(min(x/2,a)-1);
                if(temp>0)
                    ans+=temp;
                temp=(min(x/2,b)-1);
                if(temp>0)
                    ans+=temp;
                temp=(min(y,a/2)-1);
                if(temp>0)
                    ans+=temp;
                temp=(min(y,b/2)-1);
                if(temp>0)
                    ans+=temp;
                temp=(min(y/2,b)-1);
                if(temp>0)
                    ans+=temp;
            }
            //cout<<endl;
        }

        cout<<"Case #"<<tcase<<": "<<ans<<endl;

    }
    return 0;
}


