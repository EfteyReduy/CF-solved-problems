#include<bits/stdc++.h>
using namespace std;


main()
{
    int n, k;
    cin>>n>>k;
    vector<int>v;
    set<int>s;
    int i=1, x=0, y;

    while(x<n)
    {
        int j=i, cou=0;
        while(j%2==0)
        {
            j/=2;
            cou++;
        }

        x+=(pow(2,cou));
        s.insert(i);
        i++;

    }
    int cou=0, sub=x-n;

    while(sub>0)
    {
        if(sub%2)
        {
            int a=pow(2, cou);
            s.erase(a);
        }
        sub=sub/2;
        cou++;
    }

    if(i>k+1)
    {
        cout<<-1<<endl;
    }
    else{
        cout<<s.size()<<endl;
        for(auto i:s)
        {
            cout<<i<<" ";
        }
        cout<<endl;
    }


}
