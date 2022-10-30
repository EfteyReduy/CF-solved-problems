#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    pair<int, int>p[n];
	    for(int i=0; i<n; i++)
        {
            p[i].second=i;
            cin>>p[i].first;
        }

        sort(p, p+n);

        int ans[n];
        for(int i=0; i<n; i++)
        {

            if(p[i].first>=i)
            {
                ans[p[i].second]=p[i].first-i;
            }
            else{
                ans[p[i].second]=p[i].first;
            }

        }
        for(int i=0; i<n; i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;

	}

	return 0;
}
