
#include<bits/stdc++.h>



using namespace std;


main()
{
    std::cin.sync_with_stdio(false);

    int t=1;
    cin>>t;
    while(t--)
    {

        long long n, v;

        long long a=1;

        cin>>n>>v;

        long long mex=(n*(n-1))/2;

        a=n-v;
        long long men;
        if(v>=n-1)
        {
            men=n-1;
        }
        else if(v==1)
        {
            men=mex;
        }
        else{
            men=v-1;
            men+=(a*(a+1))/2;
        }

        cout<<mex<<" "<<men<<endl;
    }
    return 0;
}



