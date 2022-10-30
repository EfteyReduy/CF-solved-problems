#include<bits/stdc++.h>

using namespace std;

main()
{
    int r,g,b;
    cin>>r>>g>>b;
    int red[r],green[g],blue[b];
    for(int i=0; i<r; i++)
    {
        cin>>red[i];
    }
    for(int i=0; i<g; i++)
    {
        cin>>green[i];
    }
    for(int i=0; i<b; i++)
    {
        cin>>blue[i];
    }
    sort(red, red+r, greater<int>());
    sort(green, green+g, greater<int>());
    sort(blue,blue+b, greater<int>());
    int ans=0, i=0, j=0, k=0, loop=3;
    while(loop>1)
    {
        int a=0, d=0, c=0, l=0, w=0;
        if(i<r)
            a=red[i];
        if(j<g)
            d=green[j];
        if(k<b)
            c=blue[k];
        bool it=true,jt=true,kt=true;

        if(a>d)
        {
            if(a>c)
            {
                l=a;
                i++;
                it=false;

                if(d>c)
                {
                    w=d;
                    j++;
                }
                else{
                    w=c;
                    k++;
                }
            }
            else
            {
                l=c;
                k++;
                kt=false;
                w=a;
                i++;
            }
        }
        else
        {
            if(d>c)
            {
                l=d;
                j++;
                jt=false;
                if(a>c)
                {
                    w=a;
                    i++;
                }
                else{
                    w=c;
                    k++;
                }
            }
            else{
                l=c;
                k++;
                kt=false;
                w=d;
                j++;
            }
        }

        /*if(w==0)
        9 4 7
17 19 19 9 20 6 1 14 11
15 12 10 20
15 10 3 20 1 16 7

        */
        cout<<"here"<<endl;
        ans=ans+(w*l);
        if(i==r)
            loop--;
        if(j==g)
            loop--;
        if(k==b)
            loop--;


    }
    cout<<ans<<endl;



    return 0;
}
