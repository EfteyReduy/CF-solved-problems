#include<bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define PP pop_back
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define I insert
#define E erase
#define B back
#define C clear
#define SZ size

using namespace std;

main()
{
    int n, m;
    cin>>n>>m;
    int arr[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        int a, b;
        cin>>a>>b;
        arr[a]=b;
    }
    int t=n/3;
    int a[t]={0},b[t]={0},c[t]={0};
    int j=0;
    for(int i=0; i<=n; i++)
    {
        if(arr[i]>0)
        {
            a[j]=i;
            b[j]=arr[i];
            c[j]=arr[arr[i]];
            if(arr[c[j]]!=a[j] or c[j])
            {
                cout<<-1<<endl;
                return 0;
            }
            else if(c[j]==0)
            {
                for(int k=0; i<n; k++)
                {
                    if(arr[k]==0)
                    {
                        c[j]=k;
                        arr[k]=-1;
                        break;
                    }
                }
            }
            arr[a[j]]=arr[b[j]]=arr[c[j]]=-1;
            j++;
        }
    }
    for(int i=0; i<j; i++)
    {
        cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
    }
    int cou=0;
    for(int i=1; i<=n; i++)
    {
        if(arr[i]==0)
        {
            cou++;
            cout<<i<<" ";
        }
        if(cou==3)
        {
            cout<<endl;
            cou=0;
        }

    }
}

