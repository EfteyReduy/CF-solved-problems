#include<bits/stdc++.h>


typedef long long int ll;
typedef unsigned long long int ull;

#define PB push_back
#define PP pop_back
#define F first
#define S second
#define Pii pair<int, int>
#define Pll pair<ll, ll>
#define I insert
#define E erase
#define B back
#define C clear
#define SZ size
#define Vi vector<int>
#define Vll vector<ll>
#define Vpii vector<pair<int, int> >
#define Vpll vector<pair< ll, ll> >

#define precision(x) cout<<fixed<<setprecision(x);
#define db(x) cout<<#x<<" = "<<x<<endl


using namespace std;

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

/// Siv's algorithm  ==================================================================================
///====================================================================================================
//bool status[400000];
//int dif[100000]={0};
//
//void siv(int N) {
//    int sq = sqrt(N);
//
//    for (int i = 4; i <= N; i += 2) {
//        status[i] = 1;
//    }
//
//    for (int i = 3; i <= sq; i += 2) {
//        if (status[i] == 0) {
//            for (int j = i * i; j <= N; j += i)
//                status[j] = 1;
//        }
//    }
//
//    status[1] = 1;
//}
//
//void setDif(){
//    int j=0;
//    for(int i=2; i<400000 ; i++)
//    {
//        if(status[i]==0)
//        {
//            dif[j]=(i);
//            j++;
//        }
//    }
//}
///==================================================================================================

#define SSA(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() < b.size();});//sorting array of string in ascending order
#define SSD(s) sort(s.begin(), s.end(), [](string a, string b) -> bool {return a.size() > b.size();});//sorting array of string in descending order



typedef long long ll;
///       pair         ///////////////////////////////////////////////
/*  Declaring array of pair::   pair<int , int>var[10];
    making pair :: var[i]=make_pair(a, b); or, var[i].first=a;
                                              var[i].second=b;

    Declaring vector of pair::  vector<pair<int, int> >
    Sorting array of pair :: sort(var, var+n, sortinrev );

*/
///Boolian function to sort an array of pair in descending order
bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b)
{
       return (a.first > b.first);
}

///Boolian compare function for sorting array in descending order..
bool desc(const int &a, const int &b)
{
    return a>b;
}






main()
{
    //Code from here................

    long long t;
    string s;
    cin>>s;

    t=s.length();

    cout<<4<<endl;
    cout<<"R "<<2<<endl;
    cout<<"L "<<t<<endl;
    cout<<"R "<<t<<endl;
    cout<<"R "<<(4*t-5)<<endl;



    return 0;
}


/* Look for:
* the exact constraints (multiple sets are too slow for n=10^6 🙁 )
* special cases (n=1?)
* overflow (ll vs int?)
* array bounds
* if you have no idea just guess the appropriate well-known algo instead of doing nothing 😕
*/


/**
 * Use pen and paper. Solve on paper then code.
 * If there is some reasoning e.g. sequence/paths, try printing first 100 elements or 100 answers using brute and observe.
 * Read question with extreme caution. Sometimes we make question complex due to misunderstanding.
 * Prefix sum and suffix sum is highly usable concept, look for it.
 * Think of cleanest approach. If too many if else are coming then its indication of WA.
**/

