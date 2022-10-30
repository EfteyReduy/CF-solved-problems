#include<bits/stdc++.h>

using namespace std;


main()
{
    int possible, n, k;
    cin>>n>>k;
    char str[n][n];

    possible=(n*n)+1;
    possible/=2;
    if(possible<k)
    {
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            str[i][j]='S';
        }
    }
    if(k)
        str[0][0]='L',k--;;

    for(int i=1; i<n; i++)
    {
        if(str[0][i-1]=='S' and k)
        {
            str[0][i]='L';
            k--;
        }
    }
    for(int i=1; i<n; i++)
    {
        if(str[i-1][0]=='S' and k)
        {
            str[i][0]='L';
            k--;
        }
        for(int j=1; j<n; j++)
        {
            if(str[i][j-1]=='S' and k)
            {
                str[i][j]='L';
                k--;
            }
            if(k==0)
                break;
        }
        if(k==0)
            break;
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<str[i][j];
        }
        cout<<endl;
    }


}
