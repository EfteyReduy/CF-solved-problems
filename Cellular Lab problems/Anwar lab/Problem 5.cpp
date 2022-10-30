#include<bits/stdc++.h>
using namespace std;

main()
{
    long long n;
    cout<<"Enter a number to find its factorial : ";
    cin>>n;
    long long i, ans1=1, ans2=1;

    for(i=1; i<=n; i++)
    {
        ans1 *= i;
    }
    i = 1;
    while(i<=n)
    {
        ans2 *= i;
        i++;
    }
    if(ans1 == ans2){
        cout<<"Both the answers are same. And factorial of "<<n<<" is : "<<ans1<<endl;
    }
    else{
        cout<<"They are different."<<endl;
    }
}
