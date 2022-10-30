#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int a, b;
    cin>>a;
    queue<int>aa, bb;
    int arr[a];
    for(int i=0; i<a; i++)
    {
        int x;
        cin>>x;
        arr[i]=x;
        aa.push(x);
    }
    cin>>b;
    int brr[b];
    for(int i=0; i<b; i++)
    {
        int x;
        cin>>x;
        brr[i]=x;
        bb.push(x);
    }
    bool inf=true;
    long long ax=0, bx=0;
    while(bb.size()!=0 and aa.size()!=0)
    {
        int x=aa.front(), y=bb.front();
        aa.pop();
        bb.pop();
        if(x>y)
        {
            aa.push(y);
            aa.push(x);
            ax++;
        }
        else{
            bb.push(x);
            bb.push(y);
            bx++;
        }
        //cout<<" NO i am stack here at ax+bx = "<<ax+bx<<endl;

        if(bb.size()==b)
        {
            int i;
            for(i=0; i<b; i++)
            {

                //cout<<"stack hare in first loop at I = "<<i<<" and ax = "<<ax<<endl;
                int tb=bb.front();
                bb.pop();
                bb.push(tb);
                if(tb!=brr[i])
                    inf=false;
            }
            if(inf)
            {
                int j;
                for(j=0; j<a; j++)
                {
                    //cout<<"stack here in second loop"<<endl;
                    int ta=aa.front();
                    aa.pop();
                    aa.push(ta);
                    if(ta!=arr[j])
                        inf=false;
                }
            }

        }
        else
            inf=false;

        if((inf and bb.size()==b) or ax+bx>1000000)
        {
            cout<<-1<<endl;
            return 0;
        }
        inf=true;

    }
    cout<<ax+bx<<" "<<(1+(ax<bx))<<endl;

}
/**
5

4 2 4 3 1

1 5

*/



