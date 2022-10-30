#include<bits/stdc++.h>

using namespace std;


main()
{
    int n;
    cin>>n;
    int arr[100001]={0};
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        arr[a]++;
    }

    int t;
    cin>>t;

    for(int i=0; i<t; i++)
    {
        int a;
        bool temp=false;
        char ch;
        cin>>ch>>a;
        if(ch=='-'){
            arr[a]--;
        }

        else
            arr[a]++;

        a=0;
        int j;
        for(j=0; j<100001; j++)
        {
            if(arr[j]>=2)
            {
                a=a+arr[j]/2;

            }
            if(arr[j]/2>=2)
            {
                temp=true;
            }


            if(a>=4&&temp==true)
            {
                cout<<"yes"<<endl;
                break;
            }
        }
        if(j==100001)
            cout<<"no"<<endl;

    }

}
