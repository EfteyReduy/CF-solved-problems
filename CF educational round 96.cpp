#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define F first
#define S second
#define vii vector<int,int>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        int j=n, ans=n/2;
        if(n%2)
            ans++;

        int i=n;
        cout<<2<<endl;
        if(n==2){
            cout<<1<<" "<<2<<endl;
         continue;
        }
        cout<<i<<" "<<i-2<<endl;
        cout<<i-1<<" "<<i-1<<endl;
        i-=1;
        while(i>2)
        {
            cout<<i<<" "<<i-2<<endl;
            i--;
        }


//        return 0;
//
//        if(n%2){
//            cout<<ans<<endl;
//            for( i=1; i<=n/2; i++)
//            {
//                cout<<i<<" "<<j<<endl;
//                j--;
//            }
//            while(i<n)
//            {
//                cout<<ans<<" "<<ans<<endl;
//                i++;
//            }
//        }
//        else{
//            ans=round((((n+2)/2)+1)/2);
//            cout<<ans<<endl;
//            j=n;
//            for(i=2; i<=n/2; i++)
//            {
//                cout<<i<<" "<<j<<endl;
//                j--;
//            }
//            int x=(n+2)/2;
//            while(i<n)
//            {
//                cout<<x<<" "<<x<<endl;
//                i++;
//            }
//            cout<<1<<" "<<x<<endl;
//        }
    }
}
