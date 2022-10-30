#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>

#define db(x) cout<<#x<<" = "<<x<<endl
using namespace std;
using namespace __gnu_pbds;

main(){
    int n; cin>>n;

    tree<pair<int, int>, null_type, less<int>, rb_tree_tag,
            tree_order_statistics_node_update> s;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        s.insert({x, i});
    }
    while(1){
        cout<<"enter number";
        int x;cin>>x;
        cout<<s.order_of_key(x)<<endl;
    }
}
