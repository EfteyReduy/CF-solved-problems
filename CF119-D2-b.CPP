#include<bits/stdc++.h>

using namespace std;



main()
{
    int n, m;
    cin>>n>>m;
    vector<int>graph[n];
    for(int i=0; i<m; i++)
    {
        int a, b;

        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

}
