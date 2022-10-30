#include<bits/stdc++.h>

using namespace std;

bool status[400000];
int dif[100000]={0};
vector<long long>prims;

void siv() {
    int sq = sqrt(110000);

    for (int i = 4; i <= 110000; i += 2) {
        status[i] = 1;
    }

    for (int i = 3; i <= sq; i += 2) {
        if (status[i] == 0) {
            for (int j = i * i; j <= 110000; j += i)
                status[j] = 1;
        }
    }

    status[1] = 1;
}

void setDif(){
    int j=0;
    for(long long i=2; i<=110000 ; i++)
    {
        if(status[i]==0)
        {
            prims.push_back(i);
         //   dif[j]=(i);
           // j++;
        }
    }
}


void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

int main()
{
    fastIO();
    siv();
    setDif();

    int n, m;
    cin>>n>>m;
    long long arr[n][m];
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            long long a;
            cin>>a;
            auto it=lower_bound(prims.begin(), prims.end(), a);
            arr[i][j]=abs(*it-a);
        }
    }
    long long ans=10000000000;
    for(int i=0;i<n;i++)
    {
        long long temp=0;
        for(int j=0; j<m; j++)
        {
            temp+=arr[i][j];
        }
        ans=min(ans,temp);
    }

    for(int i=0;i<m;i++)
    {
        long long temp=0;
        for(int j=0; j<n; j++)
        {
            temp+=arr[j][i];
        }
        ans=min(ans,temp);
    }

    cout<<ans<<endl;
}
