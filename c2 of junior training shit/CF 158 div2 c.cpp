#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ll n, x;
    cin>>n>>x;

    ll arr[n], men=1e10;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        if(arr[i]<men)
        {
            men=arr[i];
        }
    }
    x--;
    int a=x;

    while(arr[a]!=men and a>=0)
    {
        a--;
    }
    if(a==-1)
    {
        for(int i=n-1; i>x; i--)
        {
            if(arr[i]==men)
            {
                a=i;
                break;
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        arr[i]-=men;
    }
    int tm=0;
    if(x>a)
    {

        for(int i=a+1; i<=x; i++)
        {
            arr[i]--;
            tm++;
        }
    }
    else if(x<a){
        for(int i=0; i<=x; i++)
        {
            arr[i]--;
            tm++;
        }

        for(int i=a+1; i<n; i++)
        {
            tm++;
            arr[i]--;
        }
    }

    //cout<<tm<<endl;
    //cout<<a<<" "<<x<<" "<<men<<endl;
    arr[a]+=(men*n)+tm;
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
