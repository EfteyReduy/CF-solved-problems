    #include<bits/stdc++.h>



    typedef long long int ll;
    typedef unsigned long long int ull;

    #define pb push_back
    #define pp pop_back
    #define F first
    #define S second
    #define pii pair<int, int>
    #define pll pair<ll, ll>
    #define I insert
    #define E erase
    #define B back
    #define C clear
    #define sz size
    #define vi vector<int>
    #define vll vector<ll>
    #define vpii vector<pair<int, int> >
    #define vpll vector<pair< ll, ll> >
    #define mii map<int, int>

    #define precision(x) cout<<fixed<<setprecision(x);
    #define dg(x) cout << #x << " = " << x << endl

    using namespace std;

    //
    //int arr[1000]={0};
    //

    //int fib(int n)
    //{
    ////    if(n<=2)
    ////    {
    ////        return 1;
    ////    }
    //    arr[1]=1;
    //    arr[2]=1;
    //    if(arr[n])
    //    {
    //        return arr[n];
    //    }
    //    else{
    //        int var= fib(n-1)+fib(n-2);
    //        arr[n]=var;
    //        return var;
    //    }
    //}

    bool desc(pii &a, pii &b)
    {
        return a.second>b.second;
    }



    main()
    {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int t;
        cin>>t;
        while(t--){

            long long k,n;
            cin>>n>>k;

            if(!k)
                break;
            k--;
            long long r=sqrt(8*k+1)-1;
            long long ans=r/2;
            long long a=n-2-ans;
//            cout<<"first b after "<<a<<" deigits"<<endl;
//
//            //cout<<n-1-ans<<endl;
            ans=(ans*(ans+1))/2;
//            cout<<"ans= " <<ans<<endl;

            ans=k-ans;
            long long b=n-2-ans-a;
            //dg(b);
//            cout<<"second b after "<<b<<" degits"<<endl;
//            cout<<"and finally "<<<<" a after second b "<<endl;
//            dg(b);
//            dg(a);
//            dg((n-a-b-2));
//            break;
            for(int i=0; i<a; i++)
            {
                cout<<'a';
            }
            cout<<'b';
            for(int i=0; i<b; i++)
            {
                cout<<'a';
            }
            cout<<'b';
            for(int i=0; i<n-a-b-2; i++)
                cout<<'a';

            cout<<endl;
//           // ans=n-ans;
//            cout<<ans<<endl;
//            break;
        }


    }
