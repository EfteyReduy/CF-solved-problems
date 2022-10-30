#include<bits/stdc++.h>
#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;

main()
{
    long long n, x=0, y=0, las;
    cin>>n;
    vector<int>fir, sec;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if(a>0)
            fir.push_back(a), x+=a;
        else
            sec.push_back(abs(a)), y=y+abs(a);

        if(i==n-1)
        {
            las=a;
        }
    }
    bool f=false;

    if(x>y)
    {
        cout<<"first"<<endl;
        f=true;
    }
    else if(x<y)
    {
        cout<<"second"<<endl;
        f=true;
    }
    else if(x==y)
    {
        for(int i=0; i<fir.size() and i<sec.size(); i++)
        {
            if((fir[i]>sec[i] and !f))
            {
                cout<<"first"<<endl;
                f=true;
                break;
            }
            else if(fir[i]<sec[i] and !f)
            {
                cout<<"second"<<endl;
                f=true;
                break;
            }
        }
        if(fir.size()>sec.size() and !f)
        {
            cout<<"first"<<endl;
            f=true;
        }
        else if( fir.size()<sec.size() and !f)
        {
            cout<<"second"<<endl;
            f=true;
        }

    }

    if(!f)
    {
        if(las>0)
        {
            cout<<"first"<<endl;
        }
        else
        {
            cout<<"second"<<endl;
        }
    }

}
