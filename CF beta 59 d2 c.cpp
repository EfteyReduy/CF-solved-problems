
#include<bits/stdc++.h>
using namespace std;


main()
{
    int n;
    cin>>n;
    pair<string, pair<int, int> >ps[n];
    for(int i=0; i<n; i++)
    {
        cin>>ps[i].first;
        cin>>ps[i].second.first;
        cin>>ps[i].second.second;
    }
    vector<string>vec;
    int cou=0;
    string ans="";
    for(char i='0'; i<='9'; i++)
    {
        for(char j='0'; j<='9'; j++)
        {
            if(i==j)
            {
                continue;
            }
            for(char k='0'; k<='9'; k++)
            {
                if(k==i or k==j)
                {
                    continue;
                }
                for(char l='0'; l<='9'; l++)
                {
                    if(l==i or l==j or l==k)
                    {
                        continue;
                    }
                    bool pos=true;
                    for(int x=0; x<n; x++)
                    {
                        int bul=0, cow=0;
                        string refer=ps[x].first;
                        if(refer[0]==i)bul++;
                        if(refer[1]==j)bul++;
                        if(refer[2]==k)bul++;
                        if(refer[3]==l)bul++;

                        if(refer[0]==j or refer[0]==k or refer[0]==l)
                        {
                            cow++;
                        }

                        if(refer[1]==i or refer[1]==k or refer[1]==l)
                        {
                            cow++;
                        }

                        if(refer[2]==j or refer[2]==i or refer[2]==l)
                        {
                            cow++;
                        }

                        if(refer[3]==j or refer[3]==k or refer[3]==i)
                        {
                            cow++;
                        }
                        if(bul!=ps[x].second.first or cow!=ps[x].second.second)
                        {
                            pos=false;
                            break;
                        }
                    }
                    if(pos)
                    {
                        string sst="";
                        sst+=i;
                        sst+=j;
                        sst+=k;
                        sst+=l;
                        ans=sst;
                        cou++;
                    }

                }
            }
        }
    }

    if(cou==1)
    {
        cout<<ans<<endl;
    }
    else if(cou>1)
    {
        cout<<"Need more data"<<endl;
    }
    else if(cou==0)
    {
        cout<<"Incorrect data"<<endl;
    }

}
