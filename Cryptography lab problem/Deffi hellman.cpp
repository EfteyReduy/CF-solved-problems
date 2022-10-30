#include <bits/stdc++.h>
using namespace std;
int power(int m, int e, int n){
    int ans = 1;
    for(int i=1; i<=e; i++)
    {
        ans*=m;
        ans%=n;
    }
    return ans;
}

int findAPrimitiveRoot(int n){
	for(int i=1; i<n; i++){
		set<int>SET;
		for(int j=1; j<n; j++){
			int powe = power(i,j,n);
			SET.insert(powe % n);
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
	Ya = (int)power(alpha,Xa, q)%q;
	Yb = (int)power(alpha,Xb, q)%q;

	int Ka, Kb;
	Ka = (int)power(Yb,Xa, q)%q;
	Kb = (int)power(Ya,Xb, q)%q;

	cout<<"Key from A: "<<Ka<<endl;
	cout<<"Key from B: "<<Kb<<endl;
}

