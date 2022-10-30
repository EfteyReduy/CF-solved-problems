#include<bits/stdc++.h>

using namespace std;

main()
{
    long long x, y;
    cin>>x>>y;
    map<int,string >mp;
    mp[0]="Stan wins";
    mp[1]="Ollie wins";

    while(x and y)
    {
        bool pos=false, det=false;
        while(1){
            if(x>y)
            {
                swap(x,y);
            }
            if(y%x==0)
                break;
            if(x*2<y)
            {
                //cout<<x<<" "<<y<<endl;
                det=true;
            }
            y=y%x;
            //cout<<y<<endl;

            if(!det)
            {
                pos=pos^1;
                //cout<<"here"<<endl;
            }

        }
        cout<<mp[pos]<<endl;
        cin>>x>>y;
    }
}
