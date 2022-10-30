#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pari:: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/
///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

main()
{
    int a, b, x, n;
    cin>>n>>x;
    pair<int, int>s[n];
    for(int i=0; i<n; i++)
    {
        cin>>s[i].first>>s[i].second;
    }
    pair<int, int> arr[n];
    for(int i=0; i<n; i++)
    {
        a=(min(s[i].first*2,s[i].second)-min(s[i].first,s[i].second));
        arr[i]=make_pair(a, i);
    }
    ///ghapla starts from here............
    ll ans=0;
    sort(arr, arr+n, sortinrev );
    for(int i=0; i<x; i++)
    {
        s[arr[i].second].first*=2;//arr[i].first;
    }
    for(int i=0; i<n; i++)
    {
        ans=ans+min(s[i].first,s[i].second);
    }
    cout<<ans<<endl;


}
