#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, k, x;
    cin>>n>>k>>x;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

    vector<int>pos;
    for(int i=0; i<n-1; i++)
    {
        if(arr[i]==arr[i+1] and arr[i]==x)
        {
            pos.push_back(i);
        }
    }
    int ans=0;
    for(int i=0; i<pos.size(); i++)
    {
        int a=pos[i]-1, b=pos[i]+2;
        while(1){
            if(a<0 or b>=n)
            {
                ans=max(ans, b-a-1);
                break;
            }
            if(arr[a]==arr[b])
            {
                if(a!=0 and arr[a-1]==arr[a])
                {
                    a-=2;
                    if(b!=n-1 and arr[b]==arr[b+1])
                    {
                        b+=2;
                    }
                    else{
                        b++;
                    }
                }
                else if(b!=n-1 and arr[b]==arr[b+1])
                {
                    b+=2;
                    a--;
                }
                else{
                    ans=max(ans, b-a-1);
                    break;
                }
            }
            else{
                ans=max(ans,b-a-1);
                break;
            }
        }
    }
    cout<<ans<<endl;

}

