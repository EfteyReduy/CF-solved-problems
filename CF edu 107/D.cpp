#include<bits/stdc++.h>

using namespace std;

int k;
string ss="", sc="";
bool vis[26][26]={0};
void alg(int a)
{
    for(int i=0; i<k; i++)
    {
        if(vis[a][i]==0)
        {
            vis[a][i]=1;
            char cc='a'+i;
            alg(i);
            ss+=cc;
        }
    }
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin>>n>>k;

    alg(0);

    int cou=2;
    string str=ss;
    while(str.length()<n)
    {
        for(int i=0; i<ss.length(); i++)
        {
            str+=ss[i];
            if(str.length()==n)
            {
                break;
            }
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<str[i];
    }
    cout<<endl;
    return 0;
}
