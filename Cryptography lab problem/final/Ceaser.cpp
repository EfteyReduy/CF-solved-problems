
#include<bits/stdc++.h>
using namespace std;

string encrypt(string s, int key){
    int n=s.length();

    for(int i=0; i<n; i++){
        char c=s[i];
        if(c==' ') continue;

        if(c<='Z'){ // boro haater letter
        	int x = c -'A';
        	x+=key;
        	x%=26;
        	c = 'A' + x;
        }
        else{ // choto haater letter
        	int x = c -'a';
        	x+=key;
        	x%=26;
        	c = 'a' + x;
        }
        s[i]=c;
    }
    return s;
}
string decrypt(string s, int key){
    int n=s.length();

    for(int i=0; i<n; i++){
        char c=s[i];
        if(c==' ') continue;

        if(c<='Z'){ // boro haater letter
        	int x = c -'A';
        	x-=key;
        	x+=26;
        	x%=26;
        	c = 'A' + x;
        }
        else{ // choto haater letter
        	int x = c -'a';
        	x-=key;
        	x+=26;
        	x%=26;
        	c = 'a' + x;
        }
        s[i]=c;
    }
    return s;
}
main()
{
    int key;
    string plain_text="";
    cout<<"Enter the encryption key: ";
    cin>>key;
    key%=26;
    cout<<endl;
    cout<<"Enter plain text to encrypt: "<<endl;
    getline(cin, plain_text);
    getline(cin, plain_text);
    string encrypted_text=encrypt(plain_text, key);
    cout<<"The encrypted text is : "<<encrypted_text<<endl;
    cout<<"The text after decryption is :"<<decrypt(encrypted_text, key);
}
