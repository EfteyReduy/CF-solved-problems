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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main()
{
    fastIO();
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i <n; i++)
    {
        cin>>arr[i];
        arr[i]++;
    }
    int sr, sc, fr, fc;
    cin>>sr>>sc>>fr>>fc;
    sr--;
    fr--;
    int x=sc;
    int dis[n];
    for(int i=sr; i<n; i++)
    {
        dis[i]=min(x, arr[i]);
        x=dis[i];
    }
    x=sc;
    for(int i=sr; i>=0; i--)
    {
        dis[i]=min(x, arr[i]);
        x=dis[i];
    }
    for(int i=fr+1; i<n; i++)
    {
        dis[i]=min(dis[i], dis[i-1]);
    }
    for(int i=fr-1; i>=0; i--)
    {
        dis[i]=min(dis[i], dis[i+1]);
    }

    int ans=1e9;
    for(int i=0; i<n; i++)
    {

        int temp=abs(dis[i]-fc)+abs(i-sr)+abs(i-fr);
        //db(temp);
        //cout<<dis[i]<<" ";
        ans=min(temp, ans);

    }
   // cout<<endl;
    cout<<ans<<endl;

}
/*
20
3 1 9 9 6 1 3 4 5 6 7 3 1 9 9 1 9 1 5 7
17 7 19 5
*/
