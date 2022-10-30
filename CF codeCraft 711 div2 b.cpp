#include<bits/stdc++.h>

using namespace std;
void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
main()
{
    fastIO();
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n>>x;

        int arr[25];
        memset(arr, 0, sizeof(arr));
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            int cou=-1;
            while(a>0)
            {
                a=a/2;
                cou++;
            }
            arr[cou]++;
        }
        int ans=0;
        while(n)
        {
            int m=x;

            for(int i=20; i>=0; i--)
            {
                if(arr[i]>0)
                {
                    int b=(1<<i);
                    while(b<=m and arr[i]>0 and n>0)
                    {
                        m-=b;
                        n--;
                        arr[i]--;
                    }
                }
            }
            ans++;
        }
        cout<<ans<<endl;
    }

}
