#include<bits/stdc++.h>

using namespace std;

double A(double channel){
    if(channel == 19)
    {
        return  12;
    }
    else if(channel == 57)
    {
        return  45;
    }
    else if(channel == 100)
    {
        return  88;
    }
}

double cells[] ={394, 98, 49};
double channels[] ={19, 57, 100};
double Au = (double)(2*3)/(double)60;
double Gos = 2/100;
double total = 0;
int Popul = 2e6;

void calculate(int i)
{
    char ch='A'+i;
    cout<<"For System "<<ch<<" :"<<endl;
    cout<<"Total supported user in a cell = "<<A(channels[i])/Au<<endl;
    double subTotal=cells[i]*(A(channels[i])/Au);
    cout<<"Total supported users in "<<cells[i]<<" cells is = "<< subTotal<<endl;
    total+=subTotal;
    cout<<"Which is "<<(subTotal*100)/Popul<<"% of the total population."<<endl;
    cout<<endl;
}

main()
{
    calculate(0);
    calculate(1);
    calculate(2);
    cout<<"Total market penetration by all three provider is = "<<(total*100)/Popul<<"% "<<endl;
}
