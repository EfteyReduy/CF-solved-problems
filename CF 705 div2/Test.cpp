#include<bits/stdc++.h>


typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define PP pop_back
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define I insert
#define E erase
#define B back
#define C clear
#define SZ size
#define Vi vector<int>
#define Vll vector<ll>
#define Vpii vector<pair<int, int> >
#define Vpll vector<pair< ll, ll> >

#define precision(x) cout<<fixed<<setprecision(x);
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;


void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}
int flipx(int x)
{
    if(x==0)
        return 0;
    if(x==2)
        return 5;
    if(x==5)
        return 2;
    return x;
}

main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;
        int h, m;
        cin>>h>>m;
        string s;
        cin>>s;
        int hh=(s[0]-'0')*10;
        hh+=(s[1]-'0');
        int mm=(s[3]-'0')*10;
        mm+=(s[4]-'0');
        //cout<<hh<<mm<<endl;
        n=0;
        map<int, int>mp;
        mp[0]=1;
        mp[1]=1;
        mp[2]=1;
        mp[5]=1;
        mp[8]=1;

        bool pos=true;

        while(1)
        {
            n++;
            int d1, d2;
            d2=hh/10;
            d1=hh%10;

            d1=flipx(d1);
            d2=flipx(d2);
            if(d1*10+d2<m and mp[d1]==1 and mp[d2]==1)
            {
                break;
            }
            pos=false;
            hh++;
            if(hh>=h)
            {
                hh=0;
                break;
            }
        }
        if(pos)
        {
            //cout<<"HERE"<<endl;

            while(1){
                int d1, d2;
                d1=mm/10;
                d2=mm%10;
                d1=flipx(d1);
                d2=flipx(d2);
                n++;
                if(d2*10+d1<h and mp[d1]==1 and mp[d2]==1)
                {
                    //db(mm);
                    break;
                }
                mm++;
                if(mm>=m)
                {
                    mm=0;
                    hh++;
                    if(hh>=h)
                    {
                        hh=0;
                        break;
                    }
                    while(1)
                    {
                        d1=hh/10;
                        d2=hh%10;

                        d1=flipx(d1);
                        d2=flipx(d2);
                        if(d2*10+d1<m and mp[d1]==1 and mp[d2]==1)
                        {
                            break;
                        }
                        hh++;
                        n++;
                        if(hh>=h)
                        {
                            hh=0;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        else{

            mm=n;
            mm=mm-n;
        }

        cout<<hh/10<<hh%10<<":"<<mm/10<<mm%10<<endl;

    }
    return 0;
}




