/*ONLINE_JUDGE macro is not supported.*/

/*For Java the classname has to be Main.*/
#include<bits/stdc++.h>


using namespace std;


vector<int>vec;
int n;
int dp[10001][10001];

int f(int i, int j, int cost){
  if(cost>100)
  {
    return 101;
  }
  if(i>=n or j<0)
  {
    return 0;
  }

  if(i>=j)
  {
    return 0;
  }
  if(vec[i]==vec[j])
  {
    int x=f(i+1, j-1, cost);
    dp[i][j]=x;
    return dp[i][j];
  }
  else{
    int x=f(i+1, j, cost+1);
    int y=f(i, j-1, cost+1);
    dp[i+1][j]=x;
    dp[i][j-1]=y;
    return dp[i][j]=min(x, y);
  }



}

main()
{
  int t;
  cin>>t;
  int cas=1;
  while(t--)
  {
    cin>>n;
    for(int i=0; i<n; i++)
    {
      int x;
      cin>>x;
      vec.push_back(x);
    }
    cout<<"S #"<<cas<<": ";
    cout<<f(0, n-1, 0)<<endl;
    cas++;
  }
}

