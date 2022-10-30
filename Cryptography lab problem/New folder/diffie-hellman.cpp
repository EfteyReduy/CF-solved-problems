#include <bits/stdc++.h>
using namespace std;

/// power ber korar jnno funciton
int power(int n, int p, int mod){
    int ans = 1;
    for(int i=1; i<=p; i++)
    {
        ans*=n;
        ans%=mod;
    }
    return ans;
}

int findAPrimitiveRoot(int n){
	for(int i=1; i<n; i++){
		set<int>SET;
		
		/// num er all power niye tar mod kore check korlam sob unique num pacchi kina
		for(int j=1; j<n; j++){
			SET.insert(power(i,j,n)); // (i^j) % n - ei jinis ta set e rakhlam
		}
		if(SET.size()==n-1) return i;
	}
}

int main()
{
	cout<<"Enter a prime number: ";
	int q;
	cin>>q;
	int alpha = findAPrimitiveRoot(q);
	
	// private key Xa and Xb. era q theke choto hobe
	int Xa, Xb;
	cout<<"Enter private key Xa: ";
	cin>>Xa;
	cout<<"Enter private key Xb: ";
	cin>>Xb;
	
	// Ya, Yb hoilo public key
	int Ya, Yb;
	Ya = power(alpha,Xa,q);
	Yb = power(alpha,Xb,q);
	
	int Ka, Kb;
	Ka = power(Yb,Xa,q);
	Kb = power(Ya,Xb,q);
	
	cout<<"Key from A: "<<Ka<<endl;
	cout<<"Key from B: "<<Kb<<endl;
}
