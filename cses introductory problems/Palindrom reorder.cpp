#include<bits/stdc++.h>

using namespace std;

void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

main()
{
    fastIO();
    double st;
    string s;
    cin>>s;
    int n=s.length();
    int arr[26];
    for(int i=0; i<26; i++)
    {
        arr[i]=0;
    }
    st=clock();
    for(int i=0; i<n; i++)
    {
        arr[(s[i]-'A')]++;
    }
    int couodd=0, oddpos=-1;
    for(int i=0; i<26; i++)
    {
        if(arr[i]%2)
        {
            oddpos=i;
            couodd++;
        }
    }
    //cout<<"OUT from"<<endl;

    if(couodd>1)
    {
        cout<<"NO SOLUTION"<<endl;
    }
    else{

        string fh="", sh="", ans="";
        for(int i=0; i<26; i++)
        {
            while(arr[i]>1)
            {
                char ch=('A'+i);
                fh=fh+ch;
                //sh=ch+sh;
                arr[i]-=2;
            }

        }
        cout<<fh;
        if(oddpos!=-1)
        {
            char ch=('A'+oddpos);
//            ans=ans+ch;
            cout<<ch;

        }
        reverse(fh.begin(), fh.end());

        cout<<fh<<endl;

        cout<<"length() of the string is "<<n<<endl;


       // cout<<(clock() - st) / CLOCKS_PER_SEC<<endl;
    }
}
