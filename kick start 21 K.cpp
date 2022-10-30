#include<bits/stdc++.h>


using namespace std;


main()
{
    int t;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        long long n, d, c, m;
        string s;

        cin>>n>>d>>c>>m;
        cin>>s;

        bool pos=true;
        int D=0;
        for(int i=0; i<n; i++)
        {
            if(s[i]=='D')
            {
                D++;
            }
        }
        if(D>d)
        {
            pos=false;
        }
        for(int i=0; i<n and D; i++)
        {

            if(s[i]=='C' )
            {
                if(c<=0)
                {
                    pos=false;
                    break;
                }

                c--;
            }
            else{
                c+=m;
                D--;
            }

        }
        cout<<"Case #"<<cas<<": ";
        if(pos)
        {
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

}
