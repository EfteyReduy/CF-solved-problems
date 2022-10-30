#include<bits/stdc++.h>


using namespace std;


int main()
{
    int n, m;
    cin>>n>>m;
    int arr[n+1];

    pair<int, int>p;
    int dif=n;
    map<int, int>mp;
    int ar[n+1];
    for(int i=0; i<m; i++)
    {

        cin>>p.first>>p.second;
        dif=min(p.second-p.first, dif);
    }
    int x=0;
    cout<<dif+1<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<x<<" ";
        x++;
        if(x>dif)
        {
            x=0;
        }
    }


}
