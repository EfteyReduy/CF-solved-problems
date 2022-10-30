#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the given sequence - ";
    cin>>s;
    int n=s.size();

    // step 1: koyta hamming bit lagbe
    int total_parity=0;
    for(int i=1; i<n; i++){
        if(pow(2, i) >= n+i+1){
            total_parity=i;
            break;
        }
    }

	// step 2: hamming bit gula koi koi bosbe
    vector<int>pows;
    for(int i=0; i<total_parity; i++){
        pows.push_back(pow(2,i));
    }

    // step 3: hamming bit er position bad dia bakigula bosailam
    int ans[n+total_parity+1], j=n-1;
    memset(ans, 0, sizeof(ans));
    for(int i=1; i<=n+total_parity and j>=0; i++){
        if( !count(pows.begin(), pows.end(), i) ){
            ans[i] = (s[j]=='0' ? 0:1);
            j--;
        }
    }

	// stp 4: calculating hamming bits
    cout<<"Here,"<<endl;
    for(int i=0; i<pows.size(); i++){
		// full array er jesob index er i-th bit 1 oigulate gunbo 1 ache kina
		int parity=0;
    	for(int j=1; j<=n+total_parity; j++){
    		if( j&(1<<i) ){
    			parity ^= ans[j]; // xor diye even parity er kaaj kora hocche
    		}
    	}
    	cout<<"H"<<i<<" = "<<parity<<endl;
    	ans[pows[i]] = parity;
    }

    cout<<"Final output is : ";
    for(int i=n+total_parity; i>0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    //For decoding[detection of the error bit]
    cout<<"For changing one bit, select an index[form left]: ";
    int index;
    cin>>index;
    if(ans[index]==1) ans[index] = 0;
    else ans[index] = 1;

    cout<<"After changing the bit: ";
    for(int i=n+total_parity; i>0; i--){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

	// calculating D0,D1,D2...
	vector<int>D;
    cout<<"Here,"<<endl;
    for(int i=0; i<total_parity; i++){
		// full array er jesob index er i-th bit 1 oigulate gunbo 1 ache kina
		int parity=0;
    	for(int j=1; j<=n+total_parity; j++){
    		if( j&(1<<i) ){
    			parity ^= ans[j]; // xor diye even parity er kaaj kora hocche
    		}
    	}
    	cout<<"D"<<i<<" = "<<parity<<endl;
    	D.push_back(parity);
    }

    //D er value gula dia binary deciaml kora
    int errorIndex=0;
    bool start=0;
    for(int i=D.size()-1, j=0; i>=0; i--){
    	if(D[i]==1) start=1;

    	if(start==1) {
    		errorIndex += D[i] * pow(2,j);
    		j++;
    	}
    }
    cout<<"Error happend in the index no: "<<errorIndex<<endl;
}
