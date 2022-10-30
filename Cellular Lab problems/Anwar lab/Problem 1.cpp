#include<bits/stdc++.h>
#include<conio.h>
using namespace std;


main()
{
    cout<<"Enter the equation with a single operator. "<<endl;
    char ch;
    string st="";
    double num1=0, num2=0;
    char sign=0;
    for(ch = getch(); ch != '='; ch = getch())
    {
        cout<<ch;
        if(ch == '+' or ch == '-' or ch == '*' or ch == '/' or ch == '%'){
            sign=ch;
        }
        else if(sign){
            int x = ch - '0';
            num2 = num2*10 + x;
        }
        else{
            int x = ch - '0';
            num1 = num1*10 + x;
        }
        st+=ch;
    }
    cout<<endl;
    st+=ch;
    cout<<"Num 1 = "<<num1<<endl;
    cout<<"Num 2 = "<<num2<<endl;
    switch(sign){
    case '+':
        cout<<st<<num1+num2<<endl;
        break;
    case '-':
        cout<<st<<num1-num2<<endl;
        break;
    case '*':
        cout<<st<<num1*num2<<endl;
        break;
    case '/':
        if(num2==0)
        {
            cout<<"Invalid input."<<endl;
            break;
        }
        cout<<st<<num1/num2<<endl;
        break;
    case '%':
        if(num2==0)
        {
            cout<<"Invalid input."<<endl;
            break;
        }
        cout<<st<<(int)num1%(int)num2<<endl;
        break;
    }
}
