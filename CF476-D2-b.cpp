#include<bits/stdc++.h>

using namespace std;

main()
{
    string sa, sb;
    cin>>sa>>sb;
    int n=0, a=0, b=0, i, j;
    for(i=0; i<sa.size(); i++)
    {
        if(sa[i]=='+')
        {
            n++;
        }else{
            n--;
        }
    }
    for(i=0; i<sb.size(); i++)
    {
        if(sb[i]=='+')
            a++;
        else if(sb[i]=='-')
            a--;
        else
            b++;
    }
    int tar=n-a, tot=pow(2,b);

    int  x=0;
    for(i=0; i<tot; i++)
    {
        j=i;
        int k=0, cou=0;
        while (j>0 or k<b) {
            k++;
            if(j % 2){
                cou++;
            }
            else{
                cou--;
            }
            j = j / 2;
        }
        if(cou==tar)
        {
            x++;
        }
    }
    double ans=((double)x/(double)tot);
    cout<<fixed;
    cout<<setprecision(12)<< ans<<endl;




}
