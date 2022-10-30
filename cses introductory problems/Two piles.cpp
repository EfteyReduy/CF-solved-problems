#include<bits/stdc++.h>

using namespace std;

main(){
    int t;
    cin>>t;
    while(t--)
    {
        int a, b;
        cin>>a>>b;

        if(a>b)
            swap(a,b);
        if(2*a<b)
        {
            cout<<"NO"<<endl;
        }
        else{
            if((a+b)%3)
            {
                cout<<"NO"<<endl;
            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}
