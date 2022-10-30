#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string arr[n], brr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        for(int i=0; i<n; i++)
        {
            cin>>brr[i];
        }

        for(int i=0; i<n; i++)
        {
            if(arr[0][i]!=brr[0][i])
            {
                for(int j=0; j<n; j++)
                {
                    if(arr[j][i]=='1')
                        arr[j][i]='0';
                    else
                        arr[j][i]='1';
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            if(arr[i][0]!=brr[i][0])
            {
                for(int j=0; j<n; j++)
                {
                    if(arr[i][j]=='1')
                        arr[i][j]='0';
                    else
                        arr[i][j]='1';
                }
            }
        }
        bool pos=true;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(arr[i][j]!=brr[i][j])
                {
                    pos=false;
                }
            }
        }
        if(pos)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }

    }
}
