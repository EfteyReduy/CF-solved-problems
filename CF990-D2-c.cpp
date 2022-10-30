#include<bits/stdc++.h>

using namespace std;
int N=300001;

int main()
{
    int n;
    cin>>n;
    string s[n];
    for(int i=0; i<n; i++)
    {
        cin>>s[i];
    }

    vector<long long> a(N, 0), b(N, 0);

//    int a[N]={0},b[N]={0};
//    memset(a,0,sizeof(a));
//    memset(b,0,sizeof(b));

    long long ans=0;
    for(int i=0; i<n; i++)
    {
        long long lft=0, rit=0;
        bool l=false, r=false;
        for(int j=0; j<s[i].length(); j++)
        {
            if(s[i][j]=='(' )
            {
                lft++;
            }else
            {
                lft--;
            }

            if(lft<0)
            {
                l=true;
            }
        }
        for(int j=s[i].length()-1; j>=0; j--)
        {
            if(s[i][j]==')')
            {
                rit++;
            }
            else {
                rit--;
            }
            if(rit<0)
            {
                r=true;
            }
        }

        if(!l and !r)
        {

            a[0]++;
            b[0]++;
            continue;
        }else if(l and r)
        {
            continue;
        }

        if(lft>0)
        {
            a[lft]++;
        }else
            b[rit]++;
    }
//0.    cout<<a[1]<< " "<<b[1]<<endl;
    for(int i=0; i<=3e5; i++)
    {
        ans+=a[i]*b[i];
    }
    cout<<ans<<endl;

    return 0;

//    cout<<cou<<endl;

}
