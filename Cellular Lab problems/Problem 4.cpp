#include<bits/stdc++.h>
using namespace std;
double Au = (2.0*3.0)/60.0;
double GOS = (2/100);
double C[]={19, 57, 100};
double cells[]={394, 98, 49};
double total=0;
double A(int tc){
    if(tc==19){
        return 12.0;
    }
    else if(tc==57){
        return 45.0;
    }
    else if(tc==100){
        return 88.0;
    }
}
void calculate(int i){
    double U = A(C[i])/Au;
    cout<<U<<" \nby taking ceiling value : "<<ceil(U)<<endl;
    cout<<"It can support total "<<U*cells[i]<<" users"<<endl;
    double ans =(U*cells[i]/2e6)*100;
    cout<<"Which is "<<ans<<"% of the total population."<<endl;
    cout<<endl;
    total += ans;
}
main(){
    cout<<"Total supported users for system A per cell is : ";
    calculate(0);
    cout<<"Total supported users for system B per cell is : ";
    calculate(1);
    cout<<"Total supported users for system C per cell is : ";
    calculate(2);
    cout<<"Market penetration of three system combined is : "<<total<<endl;
}

