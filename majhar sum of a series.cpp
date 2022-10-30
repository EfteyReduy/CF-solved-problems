#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long n, i=2;
    cout<<"Enter a positive even integer ";
    cin>>n;
    long long sum=0;
    while(i<=n)
    {
        sum+=i;
        i+=2;
    }
    cout<<"The sum of the first "<<n/2<<" integer is "<<sum<<endl;
}
