#include<bits/stdc++.h>

using namespace std;

void solve(int cc){
    string I, P;
    cin>>I>>P;
    int i, j=0;
    bool pos=true;
    cout<<"Case #"<<cc<<": ";
    for(i=0; i<I.length(); i++)
    {
        while(j<P.length() and P[j]!=I[i])
        {
            j++;
            if(j==P.length())
            {
                if(P[j-1]!=I[i])
                    pos=false;
            }
        }
        j++;
        if(j>=P.length())
        {
            i++;
            break;
        }
    }
    if(i==I.length())
    {
        cout<<P.length()-I.length()<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}

main()
{
    int t;
    cin>>t;
    for(int cc=1; cc<=t; cc++)
    {
        string I, P;
        cin>>I>>P;
        int i, j=0;
        bool pos=true;
        cout<<"Case #"<<cc<<": ";
        for(i=0; i<I.length(); i++)
        {
            while(j<P.length() and P[j]!=I[i])
            {
                j++;
                if(j==P.length())
                {
                    if(P[j-1]!=I[i])
                        pos=false;
                }
            }
            j++;
            if(j>=P.length())
            {
                i++;
                break;
            }
        }
        if(i==I.length() and pos)
        {
            cout<<P.length()-I.length()<<endl;
        }
        else{
            cout<<"IMPOSSIBLE"<<endl;
        }
    }

}
