#include<bits/stdc++.h>
using namespace std;

map<char, char>mappedChar1, mappedChar2;

void make_match(){
	vector<char>c;
	for(char x='a'; x<='z'; x++){
		c.push_back(x);
	}
	random_shuffle(c.begin(), c.end());
	
	int i=0;
	for(char x='a'; x<='z'; x++){
		mappedChar1[x] = c[i];
		i++;
	}
	
	for(auto t: mappedChar1){
		mappedChar2[t.second] = t.first;
	}
}

string encrypt(string s){
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        if(ch==' ') continue;
        
        if(ch <= 'Z'){ // boro haater letter
        	char tem = tolower(ch);
        	char otherChar = mappedChar1[tem];
        	ch = toupper(otherChar);
        }
        else{ // choto haater letter
        	ch = mappedChar1[ch];
        }
        
        s[i]=ch;
    }
    return s;
}

string decrypt(string s){
    for(int i=0; i<s.length(); i++){
        char ch=s[i];
        if(ch==' ') continue;
        
        if(ch <= 'Z'){ // boro haater letter
        	char tem = tolower(ch);
        	char otherChar = mappedChar2[tem];
        	ch = toupper(otherChar);
        }
        else{ // choto haater letter
        	ch = mappedChar2[ch];
        }
        
        s[i]=ch;
    }
    return s;
}

int main()
{
    string plain_text;
    cout<<"Enter plain text : ";
    getline(cin, plain_text);

    make_match();
    
    for(auto it: mappedChar1){
        cout<<it.first<<" -> "<<it.second<<endl;
    }
    
    string cipher=encrypt(plain_text);
    cout<<"The encrypted text is : "<<cipher<<endl;
    // sort(maped_char.begin(), maped_char.end());
    cout<<"The decrypted text is : "<<decrypt(cipher)<<endl;
}
