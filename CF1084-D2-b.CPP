#include<bits/stdc++.h>

using namespace std;

main()
{
    long long n, s, tot=0, men=1e10, ind;
    cin>>n>>s;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        tot=tot+a;
        if(a<men)
        {
            men=a;
        }
    }
    long long ans=-1;
    long long sub=tot-(n*men);
//    for(int i=0; i<=men; i++)
//    {
//        if(tot%s==0)
//        {
//            ans=i;
//            break;
//        }
//        tot=tot-n;
//    }

    long long need;
    if(sub<s)
    {
        need=s-sub;
        tot=(need+n-1)/n;
        men=men-tot;
    }



    if(men<0)
    {
        cout<<-1<<endl;
    }else{
        cout<<men<<endl;
    }

}
