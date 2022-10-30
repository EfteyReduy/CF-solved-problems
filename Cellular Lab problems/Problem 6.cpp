#include<bits/stdc++.h>
#define pi  3.1416
using namespace std;


main()
{
    double d = 5e3;
    double Eo = 1e-3;
    double d0 = 1000;

    double f = 900e6;

    double L = ((double)3e8 / f)/4.0;
    cout<<"Length of the receiving antenna L = "<<L<<endl;
    L*=4;
    double GdB = 2.55;
    double Gain = pow(10, GdB/10.0);

    cout<<"Gain is : "<<Gain<<endl;
    double ht = 50, hr = 1.5;
    double Er = (2*Eo*d0*2*pi*ht*hr)/(L*d*d);

    double Ae = (Gain*L*L)/(4*pi);

    double Pr=(Er*Er/(120*pi))*Ae;

    cout<<"The received power Pr = "<<Pr<<endl;
    cout<<"The received power in dBm is PrdBm = "<<10*log10(Pr/.001)<<endl;
}
