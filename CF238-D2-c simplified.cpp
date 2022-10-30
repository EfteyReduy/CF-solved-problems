#include<bits/stdc++.h>

using namespace std;

main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n;

    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+=(arr[i][j]*arr[j][i]);
        }
    }
    sum%=2;

    int q, t=0;
    cin>>q;
    string s="";
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1 or x==2)
        {
            int a;
            cin>>a;
            t++;
        }
        else{
            sum+=t;
            sum%=2;
            if(sum==1)
            {
                s+='1';
            }
            else
            {
                s+='0';
            }
            t=0;
        }
    }

    cout<<s<<endl;

}
