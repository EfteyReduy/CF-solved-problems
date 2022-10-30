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

void fastIO()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

void print(int arr[], int n){
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

typedef long long ll;

///comparison structure to use customized set.............
struct cmpStruct {
    bool operator() (pair<int, int> const & lhs, pair<int, int> const & rhs) const
    {
        if(lhs.first!=rhs.first)
            return lhs.first < rhs.first;
        else{
            return lhs.second<rhs.second;
        }
    }
};

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
/**

..........................for priority queue reference.........................

https://www.geeksforgeeks.org/stl-priority-queue-for-structure-or-class/?ref=rp

**/

bool sortinrev(const pair<double,int> &a,  const pair<double,int> &b)
{
       return (a.first > b.first);
}



main()
{
    fastIO();
    int t=1;
    cin>>t;
    while(t--)
    {
        ll n, m;
        cin>>n>>m;
        double val[n], wei[n];
        for(int i=0; i<n; i++)
        {
            cin>>val[i];
        }
        vector<ll>one, two;
        for(int i=0; i<n; i++)
        {
            cin>>wei[i];
            if(wei[i]==1)
            {
                one.push_back(val[i]);
            }
            else{
                two.push_back(val[i]);
            }
        }
        sort(one.begin(), one.end(), desc);
        sort(two.begin(), two.end(), desc);
        int i=0, j=0;
        ll mm=m;
        ll ans=0;
        while(i<one.size() and j<two.size() and mm>0)
        {
            mm-=one[i];
            ans+=1;
            i++;
            if(mm<=0)
            {
                break;
            }
            if(i<one.size()  and j<two.size())
            {
                if(one[i-1]+one[i]<=two[j])
                {
                    mm=mm+one[i-1];
                    mm-=two[j];
                    j++;
                    ans+=1;
                }
                else{
                    if(i<one.size())
                    {
                        mm-=one[i];
                        i+=1;
                        ans+=1;
                    }
                }
            }
            else if(i<one.size())
            {
                while(i<one.size() and mm>=0)
                {
                    mm-=one[i];
                    i++;
                    ans+=1;
                }
                break;
            }
            else if(j<two.size())
            {
                while(j<two.size() and mm>=0)
                {
                    mm-=two[j];
                    j++;
                    ans+=2;
                }
                break;
            }
        }



        if(mm>0)
        {
            while(i<one.size() )
            {
                mm-=one[i];
                i++;
                ans+=2;
            }
            while(j<two.size())
            {
                mm-=two[j];
                j++;
                ans+=2;
            }
            cout<<-1<<endl;
            cout<<mm<<endl;
        }
        else{
            cout<<ans<<endl;
        }


//        pair<double, int>p[n];
//
//        for(int i=0; i<n; i++)
//        {
//            p[i].first=val[i]/wei[i];
//            p[i].second=i;
//        }
//        sort(p, p+n, sortinrev);



    }
    return 0;
}


