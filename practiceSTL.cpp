#include<bits/stdc++.h>

using namespace std;

main()
{
    int n = 4;
    set<int>s;
    s.insert(7);
    s.insert(4);
    s.insert(58);
    s.insert(7);
    s.insert(5);
    set<int>::iterator it;
    for(it=s.begin(); it!=s.end(); it++)
    {
        cout<<*it<<endl;
    }
}
