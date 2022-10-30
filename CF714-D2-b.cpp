#include<bits/stdc++.h>
using namespace std;


main()
{
    int n;
    cin>>n;
    set<int>s;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        s.insert(a);
    }
    set<int>::iterator it=s.begin();
    if(s.size()>3)
    {
        cout<<"NO"<<endl;
    }
    else{
        if(s.size()==3)
        {
            int a=*it;
            it++;
            int b=*it;
            it++;
            int c=*it;
            if(b-a!=c-b)
            {
                cout<<"NO"<<endl;
            }
            else
                cout<<"YES"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
}
