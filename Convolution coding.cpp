#include<bits/stdc++.h>

using namespace std;

vector<int>generate_g(string G){
    vector<int>g;
    for(int i = 0; i < G.length(); i++)
    {
        if(G[i]=='1')
        {
            g.push_back(i);
        }
    }
    return g;
}

vector<int> multiply(vector<int> g, vector<int> m)
{
    vector<int>y;
    for(int i = 0; i < g.size(); i++)
    {
        for(int j = 0; j < m.size(); j++)
        {
            y.push_back(g[i]+m[j]);
        }
    }
    return y;
}

void printv(vector<int>v)
{
    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

main(){
    string G2 = "011", G1 = "100";
    string message;
    cout<<"Enter the message bit sequence : ";
    cin>>message;

    vector<int>g1, g2, m;

    int i=0;
    g1 = generate_g(G1);
    g2 = generate_g(G2);
    m = generate_g(message);

    vector<int>y1, y2;
    y1 = multiply(g1, m);
    y2 = multiply(g2, m);

    sort(y1.begin(), y1.end());
    sort(y2.begin(), y2.end());

    cout<<"Y1 = ";
    printv(y1);
    cout<<"Y2 = ";
    printv(y2);

    int mexlen = max(*(y1.end()-1), *(y2.end()-1));

    int code1[mexlen+1] , code2[mexlen+1];
    memset(code1, 0, sizeof(code1));
    memset(code2, 0, sizeof(code2));
    for(i=0; i<y1.size(); i++)
    {
        code1[y1[i]]^=1;
    }
    for(i=0; i<y2.size(); i++)
    {
        code2[y2[i]]^=1;
    }
    for(int i=0; i<=mexlen; i++)
    {
        cout<<code1[i]<<code2[i]<<" ";
    }
    cout<<endl;
}
