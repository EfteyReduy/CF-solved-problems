#include<bits/stdc++.h>

using namespace std;


main(){

    int n;
    cin>>n;
    string s="";
    for(int i=0; i<n; i++){
        cin>>s;

        long long   res = 0, ans=0;
        long long init = 0 ;
        long long cur=0;
        for(int j=0; j<s.length(); j++)
        {
            if(s[j]=='-')
                cur--, res--;
            else
                cur++, res++;

            if(cur<0)
            {
                cur=res;
                cur+=init;
                cur=0;
                init++;
                ans+=(j+2);
//                if(j+1<s.length()){
//                    if(s[j+1]=='+')
//                        ans+=(j+1);
//                }
//                else
//                    ans+=(j+1);
            }
            else
                ans++;
        }

        cout<<ans<<endl;












//        while( 1)
//        {
//            init++;
//            long long cur = init;
//            bool ok = true;
//            long long strt=0, x=0;
//            bool done=true;
//            for(long long i = 0 ; i<s.length(); i++){
//
//                //cout<<"cur = "<<cur<<" res = "<<res<<endl;
//
//                if (s[i] == '+')
//                    cur = cur + 1, res++;
//                else
//                    cur = cur - 1, res--;
//
//                done=true;
//                if (cur < 0)
//                {
//                    cur=res;
//                    cur+=x;
//                    cur=0;
//                    x++;
//                    ans+=(i+1);
//                }
//                else
//                    ans++;
//
//
//            }
//            if (ok)
//                break;
//        }
//
//
//    cout<<ans<<endl;
//
    }
}
