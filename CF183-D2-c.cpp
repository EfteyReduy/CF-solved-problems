#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cin>>n;
    if(n%2)
    {
        int arr[n], brr[n], crr[n];
        brr[0]=0;
        int j=n;
        for(int i=0; i<n; i++)
        {
            crr[i]=i;
        }
        for(int i=1; i<n; i++)
        {
            j--;
            brr[i]=j;

        }

        arr[0]=0;
        int i;
        for(i=0; i<(1+n)/2; i++)
        {
            arr[i]=i*2;
        }
        j=1;
        while(i<n)
        {
            arr[i]=j;
            j+=2;
            i++;
        }

        for(int i=0;  i<n; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;

        for(i=0; i<n; i++)
        {
            cout<<brr[i]<<" ";
        }
        cout<<endl;

        for(int i=0; i<n; i++)
        {
            cout<<i<<" ";
        }
        cout<<endl;


    }
    else{
        cout<<-1<<endl;
    }

}
