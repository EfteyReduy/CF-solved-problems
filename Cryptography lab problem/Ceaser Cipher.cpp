#include<bits/stdc++.h>

using namespace std;


string encrypt(string plain_text, int key){
    int n=plain_text.length();
    for(int i=0; i<n; i++)
    {
        unsigned char ch=plain_text[i];
        if(ch==' ')
            continue;

        if(ch<='Z')
        {
            ch+=key;
            if(ch>'Z')
                ch-=26;
        }
        else{
            ch+=key;
            if(ch>'z')
            {
                ch-=26;
            }
        }
        plain_text[i]=ch;
    }
    return plain_text;
}

string decrypt(string plain_text, int key){
    int n=plain_text.length();
    for(int i=0; i<n; i++)
    {
        unsigned char ch=plain_text[i];
        if(ch==' ')
            continue;

        if(ch<='Z')
        {
            ch-=key;
            if(ch<'A')
                ch+=26;
        }
        else{
            ch-=key;
            if(ch<'a')
            {
                ch+=26;
            }
        }
        plain_text[i]=ch;
    }
    return plain_text;
}



main()
{
    int key;
    string plain_text="";
    cout<<"Enter the encryption key: ";
    cin>>key;
    cout<<endl;
    cout<<"Enter plain text to encrypt: "<<endl;
    getline(cin, plain_text);
    getline(cin, plain_text);
    key%=26;
    string encrypted_text=encrypt(plain_text, key);
    cout<<"The encrypted text is : "<<encrypted_text<<endl;

    cout<<"The text after decryption is :"<<decrypt(encrypted_text, key);

}
