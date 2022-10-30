#include<bits/stdc++.h>

using namespace std;

main()
{
    string st;
    cout<<"Enter a string :";
    cin>>st;
    bool pali = true;
    string sst=st;
    reverse(sst.begin(), sst.end());
    if(sst == st)
    {
        cout<<"This string is a palindrome."<<endl;
    }
    else{
        cout<<"This string is not a palindrome."<<endl;
    }
}
