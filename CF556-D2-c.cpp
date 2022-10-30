#include<bits/stdc++.h>

using namespace std;


bool status[400000];
int dif[100000]={0};

void siv(int N) {
    int sq = sqrt(N);

    for (int i = 4; i <= N; i += 2) {
        status[i] = 1;
    }

    for (int i = 3; i <= sq; i += 2) {
        if (status[i] == 0) {
            for (int j = i * i; j <= N; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}

void setDif(){
    int j=0;
    for(int i=2; i<400000 ; i++)
    {
        if(status[i]==0)
        {
            dif[j]=(i);
            j++;
        }
    }
}


int main()
{
    int n;
    cin>>n;
    int one=0, two=0;
    for(int i=0; i<n; i++)
    {
        int a;
        cin>>a;
        if(a==1)
            one++;
        else
            two++;
    }
    siv(400000);
    setDif();
    int i=0;
    int j=dif[i];
    while(n)
    {
        while(j and n)
        {
            if(j>1 and two){
                cout<<2<<" ";
                j-=2;
                n--;
                two--;

            }
            else if(one){
                cout<<1<<" ";
                j--;
                n--;
                one--;
            }
            else if(two)
            {
                cout<<2<<" ";
                n--;
                two--;
                j-=2;

            }
        }
        j=dif[i+1]-dif[i];
        i++;


    }

}
