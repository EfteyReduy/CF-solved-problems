#include<bits/stdc++.h>


using namespace std;

main()
{
    int n;
    cin>>n;
    string nonz;
    int ans=0;
    string s="";
    bool zr=false;
    for(int i=0; i<n; i++)
    {
        string a;
        cin>>a;
        if(a=="0")
            zr=true;
        string x=a;
        bool beauty=true;
        int zero=0, one=0;
        for(auto j:a)
        {
            if(j=='1')
                one++;
            else if(j=='0')
                zero++;
            else{
                beauty=false;
                nonz=x;
            }
        }
        if(one>1)
        {
            beauty=false;
            nonz=x;
        }
        else if(beauty){
            ans+=zero;
        }
    }
    if(!zr){
        if(nonz.size())
            cout<<nonz;
        else
            cout<<1;

        for(int i=0; i<ans; i++)
        {
            cout<<0;
        }
        cout<<endl;
    }
    else{
        cout<<0<<endl;
    }
}
