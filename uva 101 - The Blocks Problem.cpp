#include<bits/stdc++.h>

using namespace std;


int main()
{
    int n;
    cin>>n;
    int arr[n], idx[n];
    for(int i=0; i<n; i++)
    {
        arr[i]=i;
        idx[i]=i;
    }
    stack<int>s[n];
    for(int i=0; i<n; i++)
    {
        s[i].push(i);
    }
    while(1)
    {
        string st, ss;
        cin>>st;
        if(st=="quit")
        {
            break;
        }
        int a, b;
        cin>>a>>ss>>b;
        if(a==b or idx[a]==idx[b])
            continue;

        stack<int>sa=s[idx[a]], sb=s[idx[b]];

        if(sa.empty() or sb.empty())
            continue;

        if(st=="move")
        {

            int it=sa.top();
            sa.pop();

            while(it!=a)
            {
                idx[it]=it;

                s[it].push(it);
                it=sa.top();
                sa.pop();
            }
            s[idx[a]]=sa;
            idx[a]=idx[b];
            if(ss=="onto")
            {

                it=sb.top();
                sb.pop();
                s[idx[b]].pop();
                while(it!=b)
                {
                    idx[it]=it;
                    //s[it].clear();
                    s[it].push(it);
                    it=sb.top();
                    sb.pop();
                    s[idx[b]].pop();
                }
                s[idx[b]].push(b);
                s[idx[b]].push(a);

            }
            else if(ss=="over")
            {
                s[idx[b]].push(a);
            }
        }
        else{
            stack<int>sta, stb;
            int it=sa.top();
            sa.pop();
            sta.push(it);
            while(it!=a)
            {
                it=sa.top();
                sta.push(it);
                sa.pop();
            }
            s[idx[a]]=sa;
            idx[a]=idx[b];
            if(ss=="onto")
            {
                it=sb.top();
                sb.pop();
                s[idx[b]].pop();
                //stb.push(it);
                while(it!=b)
                {
                    idx[it]=it;
                    //s[it].clear();
                    s[it].push(it);
                    stb.push(it);
                    it=sb.top();
                    sb.pop();
                    s[idx[b]].pop();
                }
                s[idx[b]].push(b);
                //s[idx[b]].push(a);
            }
            else if(ss=="over")
            {

            }
            while(!sta.empty())
            {
                it=sta.top();
                sta.pop();
                sb.push(it);
                idx[it]=idx[b];
            }
            s[idx[b]]=sb;
        }
    }
    for(int i=0; i<n; i++)
    {
        stack<int>sout=s[i], spro;
        cout<<i<<": ";
        while(!sout.empty())
        {
            int iit=sout.top();
            sout.pop();
            spro.push(iit);
        }
        while(!spro.empty())
        {
            int iit=spro.top();
            spro.pop();
            cout<<iit;
            if(!spro.empty())
                cout<<" ";
        }
        cout<<endl;

    }
}
