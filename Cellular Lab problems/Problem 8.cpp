#include<bits/stdc++.h>

using namespace std;

main()
{
    double fc=1.8;
    double hb=20;
    double d=pow((pow(20,2)+pow(30,2)),0.5);

    double Path_Loss=135.41+(12.49*log10(fc))-(4.99*log10(hb))+((46.84-2.34*log10(hb))*log10(d));
    cout<<Path_Loss<<endl;

}
