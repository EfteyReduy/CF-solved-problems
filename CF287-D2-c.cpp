#include<bits/stdc++.h>

using namespace std;
//long long h, n, ex;
//bool path=0;
long long ans=1;
tuple< bool ,long long, long long> cou_path(bool path, long long h, long long ex)
{
    tuple<bool, long long, long long>t;
//    if(h==1)
//    {
//        if(path == 0 and ex==1)
//        {
//            t=make_tuple(1,0, 0);
//            //t[0]=1, t[1]=0, t[2]=0;
//            return t;
//
//        }
//        else if(path==1 and ex==2)
//        {
//            t=make_tuple(0,0, 0);
//            return t;
//        }
//        else{
//            if(path==0)
//            {
//                t=make_tuple(1, 1, 0);
//                return t;
//            }
//            else
//            {
//                t=make_tuple(0, 1, 0);
//                return t;
//            }
//        }
//    }

    long long a=pow(2,h);
    a=a;
    if(ex<=a/2 and path==0)
    {
        t=make_tuple(1, 1, ex);
        return t;
    }
    else if(ex>a/2 and path==1)
    {
        ex=ex-(a/2);
        t=make_tuple(0, 1, ex);
        return t;
    }
    else{
        if(path==0)
            return make_tuple(0, a, ex-(a/2));
        else
            return make_tuple(1, a, ex);
    }

}

int main()
{
    long long h, n, ex;
    cin>>h>>ex;

    bool path=0;
    for(int i=h; i>=1; i--)
    {
        tuple<bool , long long, long long> pp=cou_path(path, i, ex);

        ans+=get<1>(pp);
        path=get<0>(pp);
        ex=get<2>(pp);
    }
    cout<<ans<<endl;

}
