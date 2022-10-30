#include<bits/stdc++.h>
using namespace std;
main()
{
    int n, m, k, t;
    cin>>n>>m>>k>>t;
    int field[k];
    int j=0,i;
    int x, y;
    for(i=0; i<k; i++)
    {

        cin>>x>>y;
        field[i]=(x-1)*m+(y-1);
    }
    sort(field, field+k);
    int a[t], b[t];
    for(i=0; i<t; i++)
    {
        cin>>a[i]>>b[i];
    }

    for(i=0; i<t; i++)
    {
        j=(a[i]-1)*m+(b[i]-1);
        for(x=0; x<k; x++)
        {
            if(field[x]>=j)
            {
                break;
            }
        }
        if(field[x]==j)
            cout<<"Waste"<<endl;
        else
        {
            int ans=(j-x)%3;
            if(ans==0)
                cout<<"Carrots"<<endl;
            else if(ans==1)
                cout<<"Kiwis"<<endl;
            else
                cout<<"Grapes"<<endl;

        }

    }
    return 0;



}
