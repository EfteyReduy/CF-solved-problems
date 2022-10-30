#include<bits/stdc++.h>


using namespace std;


main()
{
    string s, ans="";
    cin>>s;

    int i=0;
    for(i=0; i<s.length(); i++)
    {
        if(s[i]=='1' or s[i]=='0')
        {
            int one=0, zero=0;
            while(s[i]=='1' or s[i]=='0')
            {
                if(s[i]=='1')
                    one++;
                else
                    zero++;
                i++;
            }
            for(int j=0; j<zero; j++)
            {
                ans+='0';
            }
            for(int j=0; j<one; j++)
            {
                ans+='1';
            }
        }
        //cout<<ans<<endl;
        break;
//        }else if(s[i]=='2')
//        {
//            int one=0, two=0;
//            while(s[i]=='1' or s[i]=='2')
//            {
//                if(s[i]=='1')
//                    one++;
//                else
//                    two++;
//                i++;
//            }
//            for(int j=0; j<one; j++)
//            {
//                ans+='1';
//            }
//            for(int j=0; j<two; j++)
//            {
//                ans+='2';
//            }
//            i--;
//        }
//        else
//        {
//            ans+=s[i];
//        }
    }
    string temp="";
    int one=0;
    //cout<<i<<endl;
    for( ; i<s.length(); i++)
    {
        if(s[i]=='2' or s[i]=='0')
            temp+=s[i];
        else{
            one++;
        }

    }
    for(int j=0; j<one; j++)
    {
        ans+='1';
    }
    ans+=temp;

    cout<<ans<<endl;

}
