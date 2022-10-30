#include<bits/stdc++.h>

using namespace std;

int main(){

    long long t, x;
    cin>>x;
    while(x)
    {
        if(x%17 == 0)
        {
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
        cin>>x;
    }
    return 0;
}
