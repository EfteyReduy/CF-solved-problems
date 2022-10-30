#include<bits/stdc++.h>

#define mod 1000000007

using namespace std;

long long state[1000003];

//long long func(int i)
//{
//    cout<<"I am at position : "<<i<<endl;
//    if(i<0)
//        return 0;
//
//    if(i==0)
//        return 1;
//    if(state[i]!=-1)
//        return state[i];
//    else{
//        return state[i]=(func(i-1)%mod+func(i-2)%mod+func(i-3)%mod+func(i-4)%mod+func(i-5)%mod+func(i-6)%mod)%mod;
//    }
//
//}
//
//
main()
{
    for(int i=0; i<1000003; i++)
    {
        state[i]=-1;
    }
    int n;
    cin>>n;
    state[0]=0;
    state[1]=1;
    state[2]=2;
    state[3]=4;
    state[4]=8;
    state[5]=16;
    state[6]=32;


    long long ans=0;
    for(int i=7; i<=n; i++)
    {
        state[i]=state[i-1]+state[i-2]+state[i-3]+state[i-4]+state[i-5]+state[i-6];
        state[i]%=mod;
    }
    cout<<state[n]<<endl;

}
