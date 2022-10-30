#include<bits/stdc++.h>


typedef long long int ll;

#define PB push_back
#define PP pop_back
#define F first
#define S second

#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;

void ces(int cas)
{
    cout<<"Case "<<cas<<":\n";
}

int main()
{

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t=0;
    cin>>t;
    for(int cas=1; cas<=t; cas++)
    {
        int n;
        cin>>n;

        string number_list[n];
        map<string, vector<string>>mm;
        for(int i=0; i<n; i++)
        {
            cin>>number_list[i];
            string s="";
            for(int j=0; j<number_list[i].length(); j++)
            {
                if(j>2 and j<7)
                {
                    s+='*';
                }
                else{
                    s+=number_list[i][j];
                }
            }
            mm[s].push_back(number_list[i]);
        }
        map<string,int> suc,fail;
        string str[n], st;
        vector<string>success,failed;
        for(int i=0; i<n; i++)
        {
            cin>>str[i];
            st="";
            int j=0;
            while(str[i][j]!=',')
            {
                st+=str[i][j];
                j++;
            }
            if(str[i][j+1]=='S')
            {
                success.push_back(st);
                suc[st]++;
            }
            else{
                failed.push_back(st);
                fail[st]++;
            }

        }
        ces(cas);
        cout<<"Success list"<<endl;
        for(int i=0; i<success.size(); i++)
        {
            cout<<success[i]<<" : ";
            if(fail[success[i]])
            {
                cout<<"Confused"<<endl;
            }
            else{
                string ss=mm[success[i]].back();
                mm[success[i]].pop_back();
                cout<<ss<<endl;
            }
        }
        cout<<"Failed list"<<endl;
        for(int i=0; i<failed.size(); i++)
        {
            cout<<failed[i]<<" : ";
            if(suc[failed[i]])
            {
                cout<<"Confused"<<endl;
            }
            else{
                string ss=mm[failed[i]].back();
                mm[failed[i]].pop_back();
                cout<<ss<<endl;
            }
        }


    }
}
