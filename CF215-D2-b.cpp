#include<bits/stdc++.h>

#define precision(x) cout<<fixed<<setprecision(x);

using namespace std;

main()
{
    int n, P, Q, A, B;
    cin>>n;
    double r[n];
    for(int i=0; i<n; i++)
    {
        cin>>r[i];
    }
    cin>> P;
    double p[P];
    for(int i=0; i<P; i++)
    {
        cin>>p[i];
    }
    cin>>Q;
    double q[Q];
    for(int i=0; i<Q; i++)
    {
        cin>>q[i];
    }
    cin>>A>>B;
    sort(r, r+n);
    sort(p, p+P);
    sort(q, q+Q);

    double p1, p2, r2=0, r1=r[n-1];

    if(1)
    {
        p1=p[P-1];
        p2=q[0];
    }
    else{
        p1=p[0];
        p2=q[Q-1];
    }
    //cout<<"r1, p1, p2, A, B = "<<r1<<" "<<p1<<" "<<p2<<" "<<A<<' '<<B<<endl;
    r2=sqrt((B*r1*r1*p1)/(B*p1+A*p2));
    precision(12);
    cout<<r2<<endl;

}
