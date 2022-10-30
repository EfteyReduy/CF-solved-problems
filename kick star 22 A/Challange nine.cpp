#include<bits/stdc++.h>

using namespace std;

main()
{
    int t;
    cin>>t;
    for(int cc=1; cc<=t; cc++)
    {
        string num;
        cin>>num;
        int n=num.length();
        int arr[n];
        for(int i=0; i<n; i++)
        {
            arr[i]=num[i]-'0';
        }
        cout<<"Case #"<<cc<<": ";
        bool found=false;
        int cary, rem, ans, pos;

        for(int i=0; !found and i<num.length(); i++)
        {
            int x=num[i]-'0';
            rem=0, cary=0;
            for(int j=0; j<i; j++){
                int x=(cary*10)+arr[j];
                cary=x%9;
            }
            rem=cary;
            for(int j=0; j<x; j++)
            {
                if(i==0 and j==0)
                {
                    continue;
                }
                cary=rem;
                cary=cary*10+j;
                cary%=9;
                for(int j=i; j<n; j++){
                    int x=cary*10+arr[j];
                    cary=x%9;
                }
                if(cary==0)
                {
                    found=true;
                    ans=j;
                    pos=i;
                    break;
                }
            }
        }

        if(found)
        {
            cout<<"here"<<endl;
            for(int i=0; i<=pos; i++)
            {
                cout<<num[i];
            }
            cout<<ans;
            for(int i=pos+1; i<n; i++)
            {
                cout<<num[i];
            }
            cout<<endl;
        }
        else{
            cary=0;
            for(int i=0; i<n; i++)
            {
                cout<<arr[i];
                cary=cary*10+arr[i];
                cary%=9;
            }
            for(int i=0; i<10; i++)
            {
                if((((cary*10)+i)%9)==0)
                {
                    cout<<i<<endl;
                    break;
                }
            }

        }

    }
}
