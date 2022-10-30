#include<bits/stdc++.h>


using namespace std;

int main()
{
    int n;
    cin>>n;
    int m=n;
    int arr[n];
    vector<int>div;


    for(int i=3; i<m; i++)
    {
        if(m%i==0)
        {
            div.push_back(i);
            while(m%i==0)
            {
                m=m/i;
            }
        }
    }

    if(m>2)
        div.push_back(m);
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }

//    cout<<div.size()<<endl;
    for(auto i:div)
    {
        int x=n/i;
       // cout<<i<<endl;
        //cout<<x<<endl;
        bool has=true;
        for(int j=0; j<x; j++)
        {

            for(int k=j; k<n; k+=x)
            {
                if(arr[k]==0)
                {
                    //cout<<"I am here at i: "<<i<<" and k :"<<k<<" and j: "<<j<<endl;
                    has=false;
                    break;
                }
            }
            if(has)
            {
                cout<<"YES"<<endl;
                return 0;
            }
            has=true;
        }


    }
    cout<<"NO"<<endl;


}
