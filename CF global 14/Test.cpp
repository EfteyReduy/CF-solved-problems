#include<bits/stdc++.h>


using namespace std;

void ces(int cas)
{
    cout<<"Case "<<cas<<": ";
}
int main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        long long n;
        cin>>n;
        ces(cas);
        long long x=sqrt(n);
        if(x*x==n)
        {
            if(x%2)
            {
                cout<<"1 "<<x<<endl;
            }
            else{
                cout<<x<<" 1"<<endl;
            }
        }
        else{
            long long rem=n-(x*x);
            long long y=rem;
            bool swp=false, ndd=false;
            if(x%2)
                ndd=true;
            if(rem>x)
            {
                rem-=x;
                y=x+2-rem;
                swp=true;
            }

            x++;
            if(swp)
            {
                swap(x,y);
            }
            if(ndd)
                swap(x,y);
            cout<<x<<" "<<y<<endl;

        }

    }
}
