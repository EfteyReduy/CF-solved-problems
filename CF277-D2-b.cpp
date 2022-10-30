#include<bits/stdc++.h>

using namespace std;


main()
{

    int n, m;
    cin>>n>>m;
    int arr[n][m], c[n], r[m];

    int crr[n][m], c1[n], r1[m];
    for(int i=0; i<n; i++)
    {
        c[i]=1;
        c1[i]=0;
    }
    for(int i=0; i<m; i++)
    {
        r1[i]=0;
        r[i]=1;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>arr[i][j];
            if(!arr[i][j])
            {
                c[i]=0;
                r[j]=0;
            }
        }
    }
    int brr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(c[i] and r[j])
            {
                brr[i][j]=1;
            }
            else
            {
                brr[i][j]=0;
            }
        }
    }



    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(brr[i][j]==1)
            {
                c1[i]=1;
                r1[j]=1;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(c1[i] or r1[j])
            {
                crr[i][j]=1;
            }
            else
            {
                crr[i][j]=0;
            }
        }
    }

    bool ans=true;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(crr[i][j]!=arr[i][j])
                ans=false;
        }
    }

    if(!ans)
    {
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cout<<brr[i][j]<<" ";
            }
            cout<<endl;
        }
    }

}
