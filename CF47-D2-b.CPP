#include<bits/stdc++.h>
using namespace std;

main()
{
    string a,b,c;
    int i=0,j=0,k=0;
    cin>>a>>b>>c;

    if(a[1]=='<')
    {
        if(a[0]=='A')
            i++;
        else if(a[0]=='B')
            j++;
        else
            k++;
    }
    else
    {
        if(a[2]=='A')
            i++;
        else if(a[2]=='B')
            j++;
        else
            k++;
    }
    if(b[1]=='<')
    {
        if(b[0]=='A')
            i++;
        else if(b[0]=='B')
            j++;
        else
            k++;
    }
    else
    {
        if(b[2]=='A')
            i++;
        else if(b[2]=='B')
            j++;
        else
            k++;
    }
    if(c[1]=='<')
    {
        if(c[0]=='A')
            i++;
        else if(c[0]=='B')
            j++;
        else
            k++;
    }
    else
    {
        if(c[2]=='A')
            i++;
        else if(c[2]=='B')
            j++;
        else
            k++;
    }
    pair<int, char> ans[3];

    if(i==j)
        cout<<"Impossible"<<endl;
    else{

        ans[0]=make_pair(i,'A');
        ans[1]=make_pair(j,'B');
        ans[2]=make_pair(k,'C');
        sort(ans, ans+3);
        cout<<ans[2].second<<ans[1].second<<ans[0].second<<endl;
    }


    return 0;
}
