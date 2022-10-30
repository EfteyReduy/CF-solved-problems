#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int n=s.length(), a=0, b=0;
//        for(int i=n-1; i>=0; i--)
//        {
//            if(s[i]=='A')
//                ans++, n--;
//            else
//                break;
//        }
//

        long long ans=0;
        for(int i=n-1; i>=0; i--)
        {
            if(s[i]=='B')
                b++;
            else
                b--;

            if(b<0)
            {
                b=0;
                ans++;
            }
        }
        if(b%2)
            ans++;
        cout<<ans<<endl;

    }
}
