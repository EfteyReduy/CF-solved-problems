#include<bits/stdc++.h>
#define ll long long


using namespace std;

main()
{
    int t;
    cin>>t;
    ll a,b,x,y;
    cin>>a>>b>>x>>y;
    x=x-a;
    y=y-b;
    string str;
    cin>>str;
    int e=0,s=0, n=0, w=0, i;
    for(i=0; i<t; i++)
    {
//        if(str[i]=='E')
//            e++;
//        else if(str[i]=='S')
//            s++;
//        else if(str[i]=='W')
//            w++;
//        else
//            n++;

        if(x>=0)
        {
            if(y>=0)
            {
                if(str[i]=='N'&&y!=0)
                    y--;
                else if(str[i]=='E'&&x!=0)
                    x--;
                if(x==0&&y==0)
                    break;
            }
            else{
                if(str[i]=='S'&&y!=0)
                    y++;
                else if(str[i]=='E'&&x!=0)
                    x--;
                if(x==0&&y==0)
                    break;
            }
        }
        else if(x<0)
        {
            if(y>0)
            {
                if(str[i]=='N'&&y!=0)
                    y--;
                else if(str[i]=='W'&&x!=0)
                    x++;
                if(x==0&&y==0)
                    break;
            }
            else{
                if(str[i]=='S'&&y!=0)
                    y++;
                else if(str[i]=='W'&&x!=0)
                    x++;
                if(x==0&&y==0)
                    break;
            }
        }
    }
    if(i<t)
        cout<<i+1<<endl;
    else
        cout<<-1<<endl;
}
