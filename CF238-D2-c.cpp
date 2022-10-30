#include<bits/stdc++.h>

using namespace std;


int main()
{
    int t, n;
    cin>>n;

    int arr[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin>>arr[i][j];
        }
    }
    int sum=0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            sum+=(arr[i][j]*arr[j][i]);
        }
    }
    sum%=2;

    int col[n][4], state[n]={0};
    for(int j=0; j<4; j++)
    {
        for(int i=0; i<n; i++)
        {
            col[i][j]=0;
        }
    }


    for(int i=0; i<n; i++)
    {
        ///here is the problem.....
        state[i]=0;
        for(int j=0; j<n; j++)
        {
            if(i!=j){
                col[i][0]+=(arr[i][j]*arr[j][i])%2;
                col[i][1]+=(arr[i][j]*((arr[j][i]+1)))%2;
                col[i][2]+=(arr[j][i]*((arr[i][j]+1)))%2;
                col[i][3]+=(((arr[i][j]+1))*((arr[j][i]+1)))%2;
            }

        }
    }
    for(int j=0; j<n; j++)
    {
        for(int i=0; i<4; i++)
        {
            cout<<col[j][i]<<" ";
        }
        cout<<endl;
    }


//    for(int i=0; i<n; i++)
//    {
//        for(int j=0; j<n; j++)
//        {
//            cout<<(arr[i][j]+1)%2<<" ";
//        }
//        cout<<endl;
//    }
    int q;
    string str="";
    cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        if(x==1)
        {
            int c;
            cin>>c;
            c--;
            if(state[c]==0)
            {
                int temp=col[c][0]+(arr[c][c]);
                state[c]=2;
                int a=arr[c][c]+1;

                a%=2;
                arr[c][c]=a;
                int temp2=col[c][2]+(a);
                cout<<"temp = "<<temp<<endl;
                cout<<"temp2 = "<<temp2<<endl;
                temp2%=2;
                temp%=2;



                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }
            }
            else if(state[c]==1)
            {
                int temp=col[c][1]+(arr[c][c]);
                state[c]=3;
                int a=arr[c][c]+1;
                a%=2;
                arr[c][c]=a;
                int temp2=col[c][3]+(a);
                temp2%=2;
                temp%=2;
                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }
            }
            else if(state[c]==2)
            {
                int temp=col[c][2]+(arr[c][c]);
                state[c]=0;
                int a=arr[c][c]+1;
                a%=2;
                arr[c][c]=a;
                int temp2=col[c][0]+(a);
                temp2%=2;
                temp%=2;
                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }

            }
            else if(state[c]==3)
            {
                int temp=col[c][3]+(arr[c][c]);
                state[c]=1;
                int a=arr[c][c]+1;
                a%=2;
                arr[c][c]=a;
                int temp2=col[c][1]+(a);
                temp2%=2;
                temp%=2;
                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }
            }

        }
        else if(x==2)
        {
            int c;
            cin>>c;
            c--;
            if(state[c]==0)
            {
                int temp=col[c][0]+(arr[c][c]);
                state[c]=1;
                int a=arr[c][c]+1;
                a%=2;
                arr[c][c]=a;
                int temp2=col[c][1]+(a);
                temp2%=2;
                temp%=2;
                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }
            }
            else if(state[c]==1)
            {
                int temp=col[c][1]+(arr[c][c]);
                state[c]=0;
                int a=arr[c][c]+1;
                a%=2;
                arr[c][c]=a;
                int temp2=col[c][0]+(a);
                temp2%=2;
                temp%=2;
                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }
            }
            else if(state[c]==2)
            {
                int temp=col[c][2]+(arr[c][c]);
                state[c]=3;
                int a=arr[c][c]+1;
                a%=2;
                arr[c][c]=a;
                int temp2=col[c][3]+(a);
                temp2%=2;
                temp%=2;
                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }

            }
            else if(state[c]==3)
            {
                int temp=col[c][3]+(arr[c][c]);
                state[c]=2;
                int a=arr[c][c]+1;
                a%=2;
                arr[c][c]=a;
                int temp2=col[c][2]+(a);
                temp2%=2;
                temp%=2;
                if(temp2!=temp)
                {
                    sum+=1;
                    sum%=2;
                }
            }

        }
        else{
            if(sum==1)
                str+='1';
            else
                str+='0';
            cout<<str<<endl;
        }

    }
    cout<<str<<endl;


}
