#include<bits/stdc++.h>

using namespace std;


int main()
{
    double n, p;
    while((scanf("%lf \n %lf", &n, &p))!= EOF)
    {
        cout<<fixed<<setprecision(0);
        cout<<pow(p, (1.0/n))<<endl;
    }

}
