#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    int k=n/2;
    pair<int, pair<int,int> >p[n*2];
    pair<int, int> arr[n], brr[n];
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        arr[i]={a,i};
        brr[i]={b,i};
        p[i*2]={a, {i, 0}};
        p[(i*2+1)]={b, {i, 1}};
    }
    string s="", t="";
    for(int i=0; i<n; i++)
    {
        s+='0';
        t+='0';
    }
    sort(arr, arr+n);
    sort(brr, brr+n);
    sort(p, p+(n*2));

    for(int i=0; i<k; i++)
    {
        int x=arr[i].second, y=brr[i].second;

        s[x]='1';
        t[y]='1';
    }
//    if(n%2)
//    {
//        if(arr[k].first<brr[k].first)
//        {
//            s[arr[k].second]='1';
//        }
//        else{
//            t[brr[k].second]='1';
//        }
//    }

    for(int i=0; i<n; i++)
    {
        int x=p[i].second.first, y=p[i].second.second;
        if(y==0)
        {
            s[x]='1';
        }
        else{
            t[x]='1';
        }
    }

    cout<<s<<endl;
    cout<<t<<endl;


}
