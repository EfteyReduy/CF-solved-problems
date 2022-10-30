#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    int a=n;
    deque<int>evn, odd;
    evn.push_back(a);
    while(a-2>0)
    {
        evn.push_front(a-2);
        evn.push_back(a-2);
        a-=2;
    }
    a=n-1;
    while(a>0)
    {
        odd.push_front(a);
        odd.push_back(a);
        a-=2;
    }
    for(int i=0; i<evn.size(); i++)
    {
        cout<<evn[i]<<" ";
    }
    for(int i=0; i<odd.size(); i++)
    {
        cout<<odd[i]<<" ";
    }
    cout<<n<<endl;
}
