#include<bits/stdc++.h>

using namespace std;


main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, l;
        cin>>n>>l;

        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];

        float x, y;
        float t1=0;
        float v1=1, v2=1;
        int j=n-1, k=0;
        float p1=0, p2=l;
        vector<float> time, tim;
        float cur=0;

        tim.push_back(0);
        time.push_back(0);

        for(int i=0; i<n; i++)
        {
            time.push_back((arr[i]-cur)/v1);
            v1++;
            cur=arr[i];
        }
        cur=l;
        for(int i=n-1; i>=0; i--)
        {
            tim.push_back((cur-arr[i])/v2);
            v2++;
            cur=arr[i];
        }
        vector<float>time2;
        for(int i=n; i>=0; i--)
        {
            time2.push_back(tim[i]);
        }


        for(int i=0; i<n; i++)
        {
            if(time2[i]<time[i])
            {
                if(time2[i-1]>time[i])
                {
                    p1=(time2[i-1]-time[i])*(i+1);
                }
                else{
                    p1=(time[i]-time2[i-1])*(n-i-1);
                    p2=
                }
            }

        }



        while(p1!=p2)
        {
            p1+=(v1);
        }

    }
}
