#include<bits/stdc++.h>
#define INF 9999999999
using namespace std;

main()
{
//    int c=5/-2;
//    cout<<c<<endl;
//    return 0;
    long long n, m, x, y;
    cin>>n>>m>>x>>y;
    long long k, ans=0;
    cin>>k;



    for(int i=0; i<k; i++)
    {
        long long a, b, xi, yi, temp;
        cin>>a>>b;


        if(a==0)
            xi=INF;
        else
        {
            if(a>0)
            {
                xi=n-x;
            }
            else
            {

                xi=x-1;
            }
            xi=xi/a;
        }

        if(b==0)
            yi=INF;
        else
        {
            if(b<0){
                //cout<<b<<" "<<yi<<endl;
                yi=y-1;

            }
            else
                yi=m-y;
            yi=yi/b;
        }

        temp=min(abs(xi), abs(yi));
        //cout<<"temp = "<<temp<<endl;
        ans+=temp;

        x+=(temp*a);
        y+=(temp*b);
        //cout<<"x="<<x<<" y="<<y<<endl;
    }
    cout<<ans<<endl;
}
