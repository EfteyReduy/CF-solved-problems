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
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



typedef long long ll;


void cas(int i)
{
    cout<<"Case #"<<i<<": ";
}


main()
{
    fastIO();
    int t=1;
    cin>>t;
    for(int xx=1; xx<=t; xx++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        int dif=arr[0]-arr[1];

        bool cng[n];
        memset(cng, 0, sizeof(cng));
        int cou=1, ans=0;
        for(int i=1; i<n-1 ;i++)
        {
            int mid=arr[i-1]+arr[i+1];
            if(mid%2)
            {
                continue;
            }
            mid=mid/2;
            if(mid==arr[i])
            {
                cou++;
                continue;
            }
            else{
               // brr[i]=mid;
                int temp=3;
                int j=i-1;
                int di=mid-arr[i-1];
                while(arr[j]-arr[j-1]==di and j>0)
                {
                    temp++;
                    j--;
                }
                j=i+1;
                while(arr[j+1]-arr[j]==di and j<n-1)
                {
                    temp++;
                    j++;
                }
                ans=max(ans,temp);

            }
        }
        dif=arr[0]-arr[1];
        cou=2;
        for(int i=1; i<n-1; i++)
        {
            if(dif==arr[i]-arr[i+1])
            {
                cou++;
            }
            else{
                ans=max(ans, cou+1);
                cou=2;
                dif=arr[i]-arr[i+1];
            }
        }
        cas(xx);
        if(ans==0)
            cout<<n<<endl;
        else
            cout<<ans<<endl;

    }
    return 0;
}

