#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    int arr[n], j, i, c=1, ans=0;
    for(i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    for(i=0; i<n; i++)
    {
        for(j=i; j<n-1; j++)
        {
            if(arr[j]>=arr[j+1])
            {
                c++;
            }
            else
                break;
        }
        for(j=i; j>0; j--)
        {
            if(arr[j]>=arr[j-1])
            {
                c++;
            }
            else
                break;
        }
        if(c>ans)
            ans=c;
        c=1;

    }
    cout<<ans<<endl;
}
