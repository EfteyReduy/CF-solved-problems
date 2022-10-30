#include<bits/stdc++.h>


using namespace std;


main()
{

    double a, x, y;
    x=1, y=1.1;
    cin>>a>>x>>y;
    x=x/a;
    bool possible=false;
    y=y/a;
    if(y>0 and y<1)
    {
        if(x>-0.5 and x<0.5)
        {
            cout<<1<<endl;
            possible=true;
        }
    }
    int j=1;
    y=y-1;
    for(int i=0; i<=y; i++)
    {

        if(i & 1){
            if(y>i and y<i+1)
            {
                if(x>0 and x<1)
                {
                    cout<<j+2<<endl;
                    possible=true;
                    break;
                }
                else if(x>-1 and x<0)
                {
                    cout<<j+1<<endl;
                    possible=true;
                    break;
                }
            }
            j+=2;
        }
        else{
            if(y>i and y<i+1)
            {
                if(x>-0.5 and x<0.5)
                {
                    cout<<j+1<<endl;
                    possible=true;
                    break;
                }
            }
            j++;
        }
    }

    if(!possible)
    {
        cout<<-1<<endl;
    }


}
