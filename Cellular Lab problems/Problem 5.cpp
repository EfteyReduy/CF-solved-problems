#include<bits/stdc++.h>

#define pi 3.1416
using namespace std;

main()
{
    double Pt = 50;
    double Pt_dBm = 10*log10(Pt/.001);
    double Pt_dBw = 10*log10(Pt/1);

    cout<<"Transmitted power in dBm = "<<Pt_dBm<<endl;
    cout<<"Transmitted power in dBw = "<<Pt_dBw<<endl;

    double gain1=1, gain2 = 1, L = 1/3, l = (3e8/ 900e6), d=100;

    double Pr = (Pt * gain1 * gain2 * pow(1.0/3.0, 2))/(pow(4*pi, 2) * pow(d,2));
    cout<<"Received power Pr = "<<Pr<<endl;
    cout<<"Received power in dB PrdBm = "<<10*log10(Pr/.001)<<endl;
    cout<<"If the receiver is 10 Km away from the transmitter, d = 10000"<<endl;
    d=10000;
    Pr = (Pt * gain1 * gain2 * 1/9)/(pow(4*pi, 2) * pow(d,2));
    cout<<"Received power Pr = "<<Pr<<endl;
    cout<<"Received power in dB PrdBm = "<<10*log10(Pr/.001)<<endl;


}
