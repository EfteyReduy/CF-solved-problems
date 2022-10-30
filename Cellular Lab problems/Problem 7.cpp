#include<bits/stdc++.h>

using namespace std;

main()
{
    double hm=2;
    double fc=900;
    double hb=100;
    double d=4;
    double a_hm=(3.2*pow((log10(11.75*hm)),2)) - 4.97;

    double Lp=69.55+26.16*log10(fc)-13.82*log10(hb)-a_hm+(44.9-6.55*log10(hb))*log10(d);
    cout<<"Loss path: "<<Lp<<endl;

}

