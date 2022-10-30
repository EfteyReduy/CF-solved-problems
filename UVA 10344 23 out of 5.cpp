#include<bits/stdc++.h>

using namespace std;
long long a, b, c, d, e;
vector<long long>arr;
bool pos=false;
long long temp=0;
void check(int i,int sum)
{
    temp++;
    if(sum==23 and i==5)
    {
        pos=true;
        return;
    }
    if(i>=5)
    {
        return;
    }
    check(i+1, sum+arr[i]);
    check(i+1, sum-arr[i]);
    check(i+1, sum*arr[i]);
   // check(i+1, sum/arr[i]);
}


main()
{
    while(1)
    {

        long long sum=0;
        bool br=true;
        arr.clear();
        for(int i=0; i<5; i++)
        {

            cin>>a;
            arr.push_back(a);
            sum+=a;
            if(sum!=0)
            {
                br=false;
            }
        }
        sort(arr.begin(), arr.end());
        if(br)
            break;

        do{
            check(1, arr[0]);
            //cout<<temp<<endl;
            if(pos==true)
            {
                break;
            }

        }while(next_permutation(arr.begin(), arr.end()));

        if(pos==true)
        {
            cout<<"Possible"<<endl;
            pos=false;
        }
        else{
            cout<<"Impossible"<<endl;
        }

    }
}
