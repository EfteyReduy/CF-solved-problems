#include <bits/stdc++.h>
using namespace std;

char table[5][5];

void generateKeyTable(string key)
{
	set<char>used;
	
	// first e normal string banaya oi string ta matrix e rakhmu
	// 1. key add kora
	// 2. bakigula add kora
	
	// key adding
	string tem="";
	for(auto t: key){
		if(used.count(t)==0){
			tem += t;
			used.insert(t);
		}
	}
	
	// bakigula adding
	for(char t='A'; t<='Z'; t++){
		if(used.count(t)==0 and t!='J'){
			tem += t;
		}
	}
	
	// matrix e string ta bosano
	int k=0;
	for(int i=0; i<5; i++){
		for(int j=0; j<5; j++){
			table[i][j] = tem[k], k++;
		}
	}
}

	string findOtherPair(char x, char y, char EorD){
		string p="";
		// first char
		int row1, row2, col1, col2;
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(x==table[i][j]) {
					row1 = i, col1 = j;
				}
			}
		}
		// second char
		for(int i=0; i<5; i++){
			for(int j=0; j<5; j++){
				if(y==table[i][j]) {
					row2 = i, col2 = j;
				}
			}
		}
		
		if(row1 == row2){
			if(EorD=='E'){
				p += table[row1][(col1+1)%5];
				p += table[row1][(col2+1)%5];
			}
			else{
				p += table[row1][(col1-1+5)%5];
				p += table[row1][(col2-1+5)%5];
			}

		}
		else if(col1 == col2){
			if(EorD=='E'){
				p += table[(row1+1)%5][col1];
				p += table[(row2+1)%5][col1];
			}
			else{
				p += table[(row1-1+5)%5][col1];
				p += table[(row2-1+5)%5][col1];
			}
		}
		else{
			p += table[row1][col2];
			p += table[row2][col1];
		}
		
		return p;
	}

string encryption(string str){
	// firt e pair kora lagbe
	string s="";
	for(int i=0; i<str.size()-1; i++){
		if(str[i]==str[i+1]){
			s+=str[i];
			s+='X';
		}
		else{
			s+=str[i];
			s+=str[i+1];
			i++;
		}
		
		if(i==str.size()-2){
			s+=str.back();
		}
	}
	if(s.size()%2==1) s+='X';
	
	string encryptedData = "";
	// every pair er jnno matrix theke encrypted data ber korbo
	for(int i=0; i<s.size()-1; i+=2){
		string tem = findOtherPair(s[i], s[i+1], 'E');
		encryptedData += tem;
	}
	
	return encryptedData;
}

string decryption(string s){
	string decryptedData = "";
	for(int i=0; i<s.size()-1; i+=2){
		string tem = findOtherPair(s[i], s[i+1],'D');
		decryptedData += tem;
	}
	
	string withOutX="";
	for(auto t: decryptedData){
		if(t!='X') withOutX += t;
	}
	return withOutX;
}

string makeSpaceFree(string s){
	string x = ""; 
	for(int i=0; i<s.size(); i++){
		if(s[i] != ' ') x += s[i];
	}
	return x;
}

int main()
{
// Raisul Islam
// MONARCHY
	cout<<"Enter the plain text: ";
	string s;
	getline(cin, s);
	cout<<endl;
	
	cout<<"Enter the keyword: ";
	string key;
	cin>>key;
	cout<<endl;
	
	// sob upper case korlam
	for(int i=0; i<s.size(); i++){
		s[i] = toupper(s[i]);
	}
	for(int i=0; i<s.size(); i++){
		key[i] = toupper(key[i]);
	}
	
	for(int i=0; i<s.size(); i++){
		if(s[i]=='J') s[i]='I';
	}
	
	string spaceFreePlainText = makeSpaceFree(s);
	
	generateKeyTable(key);
	
	//encryption
	string cipher = encryption(spaceFreePlainText);
	cout << "Cipher text : "<< cipher << endl;

	// decryption
	string plain = decryption(cipher);
	cout << "Plain text : "<< plain << endl;
}
