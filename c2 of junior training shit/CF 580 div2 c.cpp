#include<bits/stdc++.h>


using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n%2)
    {
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
        return 0;
    }
    int arr[n*2+2];
    bool pos=false;
    int cou=1, s=1, e=n+1;
    for(int i=1; i<=n*2; i++)
    {
        //cou++;
        if(pos){
            arr[e]=i;
            e++;
            cou++;
        }
        else{
            arr[s]=i;
            s++;
            cou++;
        }
        if(cou==2)
        {
            cou=0;
            pos=!pos;
        }
    }
    for(int i=1; i<=n*2; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
