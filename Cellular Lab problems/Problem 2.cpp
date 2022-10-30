#include<bits/stdc++.h>

using namespace std;

void cluster_size(double n, double SNRgiven, double N)
{
    double I = 6;

    double Q = sqrt(3*N);
    double SNRdb = 10*log10((pow(Q,n))/I);
    cout<<"For n = "<<n<<endl;
    if(SNRgiven <= SNRdb)
    {
        cout<<"N = "<<N<<" can be used. "<<endl;
        cout<<"Output SNRdb for N = "<<N<<" is : "<<SNRdb<<endl;
    }
    else{
        cout<<"N = "<<N<<" can not be used. "<<endl;
        cout<<"Output SNRdb for N = "<<N<<" is : "<<SNRdb<<endl;
    }
    cout<<endl;
}

main()
{
    //cluster_size(4, 15, 3);
    cluster_size(4, 15, 7);
    cluster_size(3, 15, 7);
    cluster_size(3, 15, 12);
}
