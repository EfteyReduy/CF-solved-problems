#include<bits/stdc++.h>
using namespace std;
string encryption(string s, string repetedKey)
{
	string ans="";
	for(int i=0; i<s.size(); i++){
		int x = s[i] - 'A';
		int y = repetedKey[i] - 'A';
		int z = (x+y) % 26;
		char c = z + 'A';
		ans += c;
	}
	return ans;
}
string decryption(string s, string repetedKey)
{
	string ans="";
	for(int i=0; i<s.size(); i++){
		int x = s[i] - 'A';
		int y = repetedKey[i] - 'A';
		int z = (x-y+26) % 26;
		char c = z + 'A';
		ans += c;
	}
	return ans;
}

string makeSpaceFree(string s){
	string x = "";
	for(int i=0; i<s.size(); i++){
		if(s[i] != ' ') x += s[i];
	}
	return x;
}

string makeRepetedKey(string key, int len){
	string tem="";
	while(1){
		if(tem.size() >= len) break;
		tem += key;
	}
	string repetedKey = "";
	for(int i=0; i<len; i++){
		repetedKey += tem[i];
	}
	return repetedKey;
}
int main()
{
	cout<<"Enter the plain text: ";
	string s;
	getline(cin, s);
	cout<<endl;
	cout<<"Enter the keyword: ";
	string key;
	cin>>key;
	cout<<endl;

	for(int i=0; i<s.size(); i++){
		s[i] = toupper(s[i]);
	}
	for(int i=0; i<s.size(); i++){
		key[i] = toupper(key[i]);
	}
	string spaceFreePlainText = makeSpaceFree(s);
	string repetedKey = makeRepetedKey(key, s.size());

	string cipher = encryption(spaceFreePlainText, repetedKey);
	cout << "Cipher text : "<< cipher << endl;
	string plain = decryption(cipher, repetedKey);
	cout << "Plain text : "<< plain << endl;
}


