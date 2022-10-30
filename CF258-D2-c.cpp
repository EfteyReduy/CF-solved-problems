#include<bits/stdc++.h>

using namespace std;


int main()
{
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k, d1, d2;
        cin>>n>>k>>d1>>d2;
        if(d1>d2)
            swap(d1, d2);
        if(n%3)
        {
            cout<<"no"<<endl;
            continue;
        }
        else{
            if(d1==0 and d2==0)
            {
                cout<<"yes"<<endl;
                continue;
            }
            long long rem=n-k, each_play=2*n/3;
            if(d2>each_play)
            {
                cout<<"no"<<endl;
                continue;
            }
            ///between player 1, 2, 3... keep 1 and 3 low or keep 2 low
            /// which means... player1=d1, player2=0, player3=d2; or player1=d2-d1, player2=d2, player3=0;total_req=d2+(d2-(player1));
            long long req=((d2+(d2-d1)));
            if(k-d1-d2>=0 and ((k-d1-d2)%3==0))
            {
                req=((d2+(d2-d1)));
            }
            else
            {
                req=(d2+(d2-(d2-d1)));
            }

            if(rem<req)
            {
                cout<<"no"<<endl;
            }
            else{
                cout<<"yes"<<endl;
            }
        }
    }
}
