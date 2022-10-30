#include<bits/stdc++.h>

using namespace std;

main()
{
    char table[5][5];
    string key = "";
    string plain = "";
    cout<<"Enter plain text : ";
    cin>>plain;
    cout<<"Enter key : ";
    cin>>key;
    int vis[26]={0};
    int arr[25]={0};

    vector<char>vc;
    for(int i=0; i<key.length(); i++)
    {
        char ch = toupper(key[i]);
        int idx = ch-'A';
        if(!vis[idx])
        {
            vis[idx]=1;
            if(ch=='I')
            {
                vis[idx+1]=1;
            }
            else if(ch=='J')
            {
                vis[idx-1]=1;
            }
            vc.push_back(ch);
        }
    }
    for(int i=0; i<26; i++)
    {
        if(!vis[i])
        {
            if(i==9)
                continue;
            vc.push_back('A'+i);
        }
    }

    set<char> ch;
    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++)
        {
            table[i][j] = vc[i*5 + j];
            cout<<table[i][j]<<" ";
        }
        cout<<endl;
    }


}
