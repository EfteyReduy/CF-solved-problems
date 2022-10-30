#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    ll ans=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                vector<int> vec;
                vec.push_back(arr[i]);
                vec.push_back(arr[j]);
                vec.push_back(arr[k]);
                sort(vec.begin(), vec.end());
                if(vec[0]+vec[1]>=vec[2])
                {
                    ans++;
                }
            }
        }
    }

    cout<<ans<<endl;

}
