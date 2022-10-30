#include<bits/stdc++.h>

using namespace std;


int main()
{
    string s;
    cin>>s;
    for(int i=0; i<128; i++)
    {
        char c=i;
        if(c==' ')
        {
            cout<<i<<endl;
        }
        cout<<c;
    }
    cout<<endl;

}
