#include<bits/stdc++.h>

using namespace std;


main()
{
    int t, n;
    cin>>n>>t;
    map<int, int> arr;
    for(int i=0; i<n; i++)
    {
        int a;

        cin>>a;
        arr[a]++;
        cout<<a<<" occared " <<arr[a]<<"times"<<endl;
    }

}
