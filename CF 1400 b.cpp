#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int c1, c2, n1, n2, w1, w2;
        cin>>c1>>c2>>n1>>n2>>w1>>w2;
        if(w1>w2)
        {
            swap(w1, w2);
            swap(n1,n2);
        }

        int ans=0, m=c1/w1, n=c2/w1;
        if(m+n<=n1)
        {
            cout<<m+n<<endl;
            continue;
        }
        m=0, n=0;
        for(int i=0; i<=n1; i++)
        {
            int a=c1, b=c2;
            a=a-(w1*i);
            b=b-(w1*(n1-i));
            if(a<0 or b<0)
                continue;

            m=a/w2;
            //cout<<"Hare at i = : "<<i<<endl;
            n=b/w2;
            int x=min(m+n, n2);
            ans=max(ans, (n1+x));

        }
        cout<<ans<<endl;

    }
}
