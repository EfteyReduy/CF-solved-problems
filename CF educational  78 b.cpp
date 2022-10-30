#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a, b, dif, i=0;

        cin>>a>>b;
        if(a<b)
            swap(a, b);
        dif=a-b;
        long long cou=0;
        for( ; ; i++)
        {
            cou+=i;
            if(dif<=cou)
                break;
        }


        dif=cou-dif;

//        cout<<"I = "<<i<<endl;

        if(dif==0)
        {
            cout<<i<<endl;
        }
        else if(dif%2==0)
        {
            cout<<i<<endl;
        }
        else{
            if(i%2==1)
                cout<<i+2<<endl;
            else{
                cout<<i+1<<endl;
            }
        }

    }
}
