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




long long  findSubarraySum(long long arr[], long long n, long long sum)
{
	// STL map to store number of subarrays
	// starting from index zero having
	// particular value of sum.
	unordered_map<long long, long long > prevSum;

	long long res = 0, ans=0;

	// Sum of elements so far.
	long long currsum = 0;

	for (int i = 0; i < n; i++) {

		// Add current element to sum so far.
		currsum += arr[i];

		// If currsum is equal to desired sum,
		// then a new subarray is found. So
		// increase count of subarrays.
		if (currsum == sum)
        {
            res++;
            ans++;
            prevSum.clear();
            currsum=arr[i];
        }


		// currsum exceeds given sum by currsum
		// - sum. Find number of subarrays having
		// this sum and exclude those subarrays
		// from currsum by increasing count by
		// same amount.
		if (prevSum.find(currsum - sum) != prevSum.end())
        {
            res += (prevSum[currsum - sum]);
            ans++;
            prevSum.clear();
            currsum=arr[i];
        }


		// Add currsum value to count of
		// different values of sum.
		prevSum[currsum]++;
	}

	return ans;
}



void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
main()
{
    fastIO();

    long long a, b, m;
    while((scanf("%lld %lld %lld", &a, &b, &m) )== 3)
    {
        ///cin>>a>>b>>m;
        long long ans=1;

        //cout<<a<<" "<<b<<" "<<m<<endl;

        while(b>0)
        {

            if(b%2)
                ans=(ans*(a%m))%m, b--;
            else{
                a=((a%m)*(a%m));
                a=a%m;
                b=b/2;
            }
        }
        cout<<ans<<endl;


    }

}




