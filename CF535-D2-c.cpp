#include<bits/stdc++.h>
using namespace std;

main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;

//    tuple<int, int, int>t[3];
    int val[3][3]={0};
    map<char, int>col;
    col['R']=0;
    col['G']=1;
    col['B']=2;

//    for(int i=0; i<s.length(); i++)
//    {
//        char c=s[i];
//        val[col[c]][i%3]++;
//    }
//    for(int i=0; i<3; i++)
//    {
//        for(int j=0; j<3; j++)
//        {
//            cout<<val[i][j]<<" ";
//        }
//        cout<<endl;
//    }
//
    string color="BGR", ans;
    int mn=s.length()+1;
    do{
        //cout<<"testing " <<color<<endl;
        int cou=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]!=color[i%3])
            {
                cou++;
            }
        }

        if(cou<mn)
        {
            ans=color;
            mn=cou;

        }
    }while(next_permutation(color.begin(),color.end()));
    cout<<mn<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<ans[i%3];
    }
    cout<<endl;

}
