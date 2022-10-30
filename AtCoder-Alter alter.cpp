#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    string str;
    cin>>str;

    int i, j=n-1, r=n-1, ans=0;
    for( i=0; i<j; i++)
    {
        if(str[i]=='W')
        {
            for(j=r; j>i; j--)
            {
                if(str[j]=='R')
                {
                    cout<<"hare  i, j = = "<<i<<"   "<<j<<endl;
                    r=j;
                    swap(str[i], str[j]);
                    ans++;
                    break;
                }
            }
        }
    }

    cout<<ans<<endl;
}
