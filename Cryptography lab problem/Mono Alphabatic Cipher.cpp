#include<bits/stdc++.h>

using namespace std;

vector<pair<char, char> >maped_char, rev;

vector<pair<char, char> > make_match()
{
    vector<pair<char, char> >p;
    vector<int>vec;
    for(int i=0; i<26; i++)
    {
        vec.push_back(i);
    }
    random_shuffle(vec.begin(), vec.end());
    for(int i=0; i<26; i++)
    {
        p.push_back({'a'+vec[i], i+'a'});
    }
    return p;
}

string encrypt(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        char ch=s[i];
        int sft=0;
        if(ch==' ')
        {
            continue;
        }
        int idx=ch-'a';
        if(idx<0)
        {
            idx=ch-'A';
            sft='a'-'A';
        }
        s[i]=maped_char[idx].first-sft;
    }
    return s;
}

string decrypt(string s)
{
    for(int i=0; i<s.length(); i++)
    {
        char ch=s[i];
        int sft=0;
        if(ch==' ')
        {
            continue;
        }
        int idx=ch-'a';
        if(idx<0)
        {
            idx=ch-'A';
            sft='a'-'A';
        }
        s[i]=maped_char[idx].second-sft;
    }
    return s;
}



main()
{
    string plain_text;
    cout<<"Enter plain text : ";
    getline(cin, plain_text);

    maped_char = make_match();
    rev=maped_char;
    for(auto it:maped_char){
        cout<<it.first<<" "<<it.second<<endl;
    }
    string cipher=encrypt(plain_text);
    cout<<"The encrypted text is : "<<cipher<<endl;
    sort(maped_char.begin(), maped_char.end());
    cout<<"The decrypted text is : "<<decrypt(cipher)<<endl;
    maped_char=rev;
}
