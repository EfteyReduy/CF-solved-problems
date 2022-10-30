#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    while((cin>>n && cin>>m)!=EOF)
    {
        int arr[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>arr[i][j];
            }
        }

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                int x=0;
                if(i>0){
                    x+=arr[i-1][j];
                }
                if(i<n-1){
                    x+=arr[i+1][j];
                }

                if(j>0){
                    x+=arr[i][j-1];
                }
                if(j<m-1){
                    x+=arr[i][j+1];
                }
                if(arr[i][j])
                {
                    cout<<9;
                }
                else{
                    cout<<x;
                }
            }
            cout<<endl;
        }

    }
    return 0;
}
