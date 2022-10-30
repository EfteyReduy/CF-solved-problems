#include<bits/stdc++.h>

using namespace std;

main()
{
    int h, m, hh, mm, hhh, mmm;
    string h1, h2, m1, m2, t1, t2;
    cin>>t1>>t2;

    hh=(t1[0]-'0')*10+(t1[1]-'0');
    mm=(t1[3]-'0')*10+(t1[4]-'0');
    hhh=(t2[0]-'0')*10+(t2[1]-'0');
    mmm=(t2[3]-'0')*10+(t2[4]-'0');


    h=hhh-hh;
    m=mmm-mm;
    if(m<=0)
    {
        m+=60;
        h--;
    }
    int t=h*60+m;
    t=t/2;
    h=t/60;
    m=t%60;

    hh=(hh+h)+(mm+m)/60;
    mm=(mm+m)%60;

    if(hh<10)
        cout<<0;

    cout<<hh<<":";
    if(mm<10)
        cout<<0;
    cout<<mm<<endl;



}
