#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n, m, k;
    cin>>n>>m>>k;

    int row[n+1][2], col[m+1][2];
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    for(int i=1; i<=k; i++)
    {
        int type, num, val;
        cin>>type>>num>>val;
        if(type==1)
        {
            row[num][0]=val;
            row[num][1]=i;
        }
        else if(type==2)
        {
            col[num][0]=val;
            col[num][1]=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int r, c;
            r=row[i][0], c=col[j][0];

            if(row[i][1]>col[j][1])
            {
                cout<<r<<" ";
            }
            else{
                cout<<c<<" ";
            }
        }
        cout<<endl;
    }

}
