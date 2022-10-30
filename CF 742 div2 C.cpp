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
        long long a=0, b=0;

        for(int i=0; i<s.length(); i++)
        {
            if(i%2)
            {
                a*=10;
                a+=(s[i]-'0');
            }
            else{
                b*=10;
                b+=(s[i]-'0');

            }
        }

        a++;
        b++;

        cout<<a*b-2<<endl;

    }
}
