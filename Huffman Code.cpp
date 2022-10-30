#include<bits/stdc++.h>

using namespace std;

main()
{
    int n;
    cout<<"Enter number of symbols n = ";
    cin>>n;
    int symbl_len;
    pair<double, string> records[n];
    priority_queue<pair<double, string> >pq;

    cout<<"Enter symbol - probability pair"<<endl;
    for(int i=0; i<n; i++)
    {
        string symbol;
        double probability;
        cin>>symbol>>probability;
        records[i]={-probability, symbol};
        pq.push(records[i]);
        symbl_len=symbol.length();
    }
    stack<pair<string, string> > st;
    while(!pq.empty())
    {
        pair<double, string> left = pq.top();
        pq.pop();
        if(pq.empty())
        {
            break;
        }
        pair<double, string> right = pq.top();
        pq.pop();

        string common=left.second+right.second;
        double total=left.first+right.first;
        pq.push({total, common});
        st.push({left.second, right.second});

    }

    map<string, string> code;
    while(!st.empty())
    {
        pair<string, string> common=st.top();
        st.pop();
        string left = common.first, right = common.second;
        for(int i=0; i<left.length(); i+=symbl_len)
        {
            string ch="";
            for(int j=i; j<i+symbl_len; j++)
            {
                ch+=left[j];
            }
            code[ch]=code[ch]+"0";
        }
        for(int i=0; i<right.length(); i+=symbl_len)
        {
            string ch="";
            for(int j=i; j<i+symbl_len; j++)
            {
                ch+=right[j];
            }
            code[ch]=code[ch]+"1";
        }
    }
    cout<<"Huffman code for those given symbols are given bellow."<<endl;
    for(auto it:code)
    {
        cout<<it.first<<" --> "<<it.second<<endl;
        cout<<"---------------------------"<<endl;
    }
}






