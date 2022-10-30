#include<bits/stdc++.h>
using namespace std;

string st="";

string s;

int vis[102][10];


void func(int pos, int mod, string str, int n)
{
    if(pos>=n)
        return ;

    if(vis[pos][mod]==-1)
    {
        vis[pos][mod]=1;
        int newmod=(mod*10+(s[pos]-'0'))%8;
        if(newmod==0)
        {
            str+=s[pos];
            st=str;
            return ;
        }
        else{
           // cout<<"stack over here.. at pos : "<<pos<<endl;
            func(pos+1, mod, str, n);
            str+=s[pos];
          //  cout<<"and here also : "<<pos<<endl;
            func(pos+1, newmod, str, n);
        }
    }
//    else{
//       // cout<<"I tried to go that way"<<endl;
//    }

}



//
//void fun(int pos, int mod, string str, int n)
//{
//    if(pos>=n)
//        return ;
//
//
//    int newmod=(mod*10+(s[pos]-'0'))%8;
//    if(newmod==0)
//    {
//        str+=s[pos];
//        st=str;
//        return ;
//    }
//    else{
//        //cout<<"stack over here.. at pos : "<<pos<<endl;
//        fun(pos+1, mod, str, n);
//        str+=s[pos];
//        //cout<<"and here also : "<<pos<<endl;
//        fun(pos+1, newmod, str, n);
//    }
//}
////111111111111111111111171111111111111111111111111111112
//



main()
{
    for(int i=0; i<101; i++)
    {
        for(int j=0; j<10; j++)
        {
            vis[i][j]=-1;
        }
    }

    cin>>s;
    string str="";
    func(0, 0, str, s.length());
    if(st.length()==0)
        cout<<"NO"<<endl;
    else
    {
        cout<<"YES"<<endl;
        cout<<st<<endl;
    }

//    for(int i=0; i<101; i++)
//    {
//        for(int j=0; j<10; j++)
//        {
//            cout<<vis[i][j]<<" ";
//        }
//        cout<<endl;
//    }


}
//5521399953495399131957773999751571911139197159755793777773799119333593915333593153173775755771193715

