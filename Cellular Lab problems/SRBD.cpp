#include<bits/stdc++.h>

using namespace std;

int parent[100000+5], rnk[100000+5];

void make_set(int v, int r) {
    rnk[v] = r;
    parent[v] = v;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void rnk_updt(int r){
    rnk[r]+=1;
    int v=find_set(r);
    if(rnk[r]<rnk[v])
    {
        swap(r,v);
    }
    else if(rnk[r]==rnk[v])
    {
        if(r<v){
            swap(r,v);
        }
    }
    parent[v]=r;
    parent[r]=r;
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (rnk[a] < rnk[b])
            swap(a, b);
        else if(rnk[a]==rnk[b])
        {
            if(a<b)
                swap(a,b);
        }
        parent[b] = a;
        parent[a] = a;
    }
}

int main()
{
    int n, q;
    cin>>n>>q;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        make_set(arr[i], n-i);
    }
    while(q--)
    {
        int t, x, y;
        cin>>t;
        if(t==1)
        {
            cin>>x>>y;
            union_sets(x, y);
        }
        else{
            cin>>x;
            if(t==2)
            {
                ///update ranks
                rnk_updt(x);
            }
            if(t==3)
            {
                ///display result
                y=find_set(x);
                cout<<y<<endl;
            }
        }
    }


    return 0;
}



