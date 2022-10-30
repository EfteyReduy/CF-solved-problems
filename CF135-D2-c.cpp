#include<bits/stdc++.h>


using namespace std;


int main()
{
    long long p, d;
    cin>>p>>d;
    long long tp=0, temp=p-d;




    long long x=1;
    while(p>=temp and x<=d)
    {
        //cout<<"Stack hare at temp = "<<temp<<" and x = "<<x<<endl;
        long long a=temp%(x*10);
        //cout<<" a = "<<a<<endl;
        if(a>x and a%9==0)
        {
            x=x*10;
        }
        else{
            d-=x;
            temp+=x;
            if(temp>p)
            {
                temp-=x;
                break;
            }
            else if(temp==p)
            {
                break;
            }
        }

    }
    cout<<temp<<endl;
}
