
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


// Hashing
// Hashvalue(l...r) = hsh[l] - hsh[r + 1] * base ^ (r - l + 1);
// Must call preprocess
const int MAX = 102;
ll mods[2] = {1000000007, 1000000009};
//Some back-up primes: 1072857881, 1066517951, 1040160883
ll bases[2] = {137, 281};
ll pwbase[3][MAX];

void Preprocess(){
    pwbase[0][0] = pwbase[1][0] = 1;
    for(ll i = 0; i < 2; i++){
        for(ll j = 1; j < MAX; j++){
            pwbase[i][j] = (pwbase[i][j - 1] * bases[i]) % mods[i];
        }
    }
}

struct Hashing{
    ll hsh[2][MAX];
    string str;

    void Build(){
        for(ll i = str.size() - 1; i >= 0; i--){
            for(int j = 0; j < 2; j++){
                hsh[j][i] = (hsh[j][i + 1] * bases[j] + str[i]) % mods[j];
                hsh[j][i] = (hsh[j][i] + mods[j]) % mods[j];
            }
        }
    }

    Hashing(){}
    Hashing(string _str) {str = _str; memset(hsh, 0, sizeof(hsh)); Build();}

    pair<ll,ll> GetHash(ll i, ll j){
        assert(i <= j);
        ll tmp1 = (hsh[0][i] - (hsh[0][j + 1] * pwbase[0][j - i + 1]) % mods[0]) % mods[0];
        ll tmp2 = (hsh[1][i] - (hsh[1][j + 1] * pwbase[1][j - i + 1]) % mods[1]) % mods[1];
        if(tmp1 < 0) tmp1 += mods[0];
        if(tmp2 < 0) tmp2 += mods[1];
        return make_pair(tmp1, tmp2);
    }
};



int main()
{
    int n;
    cin>>n;
    string w[n];
    bool is_possible=true;
    for(int i = 0; i < n; i++)
    {
        cin>>w[i];
    }

    string t;
    cin>>t;

    Preprocess();
    Hashing hash_t(t);
    vector< pair< int, int > > visited;
    for(int i = 0; i < n; i++)
    {
        if( w[i].length() > t.length() )
        {
            is_possible = false;
            break;
        }

        Hashing wi( w[i] );
        pair<ll, ll> hash_value = wi.GetHash( 0, w[i].length() - 1);

        bool present=false;
        for(int j = 0; j <= t.length() - w[i].length(); j++)
        {
            pair<ll, ll> hash_value_t = hash_t.GetHash( j, w[i].length() + j - 1);
            //cout<<hash_value.first<<" "<<hash_value.second<<" "<<hash_value_w.first<<" "<<hash_value_w.second<<endl;
            if(hash_value == hash_value_t)
            {
                present = true;
                visited.push_back({j, j + w[i].length() - 1});
            }
        }
        if(!present)
        {
            is_possible = false;
            break;
        }
    }

    if(is_possible)
    {
        sort(visited.begin(), visited.end());

        if(visited[0].first != 0)
        {
            is_possible = false;
        }
        else{
            int vis_till = visited[0].second;
            for(int i = 1; i < visited.size(); i++)
            {
                if( vis_till + 1 < visited[i].first )
                {
                    is_possible = false;
                    break;
                }
                else{
                    vis_till = max( vis_till, visited[i].second );
                }
            }
            if( vis_till + 1 < t.length() )
            {
                is_possible=false;
            }
        }

        if( is_possible )
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }


    return 0;
}
