#include<bits/stdc++.h>
typedef long long int ll;

using namespace std;


bool status[40000];
int dif[10000]={0};
vector<ll>prim;

void siv() {
    int sq = sqrt(1000000001);

    for (int i = 4; i <= sq; i += 2) {
        status[i] = 1;
    }

    for (int i = 3; i*i<= sq; i += 2) {
        if (status[i] == 0) {
            for (int j = i * i; j <= sq; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}

void setDif(){
    int j=sqrt(1000000001);
    for(int i=2; i<=j; i++)
    {
        if(status[i]==0)
        {
            prim.push_back(i);
        }
    }
}


int main()
{
    ll n;
    cin>>n;
    siv();
    setDif();

   // cout<<"size of primes is : "<<prim.size()<<endl;
    while(n--)
    {
        ll a, b;
        cin>>a>>b;
        double x=pow(a, (1/3));
        cout<<x<<endl;
        bool pos;
        if(pos)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}
