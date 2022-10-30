#include<bits/stdc++.h>
using namespace std;
double A(int tc){
    if(tc==1){
        return .005;
    }
    else if(tc==5){
        return 1.13;
    }
    else if(tc==10){
        return 3.96;
    }
    else if (tc==20){
        return 11.1;
    }
    else if(tc==100){
        return 80.9;
    }
}
main(){
    double Au = 0.1;
    double GOS = (.5/100);
    double C[]={1, 5, 10, 20, 100};
    for(auto it: C){
        cout<<"Total supported users for available channel C = "<<it<<" is : ";
        double U = A(it)/Au;
        cout<<U<<" \nby taking ceiling value : "<<ceil(U)<<endl;
        cout<<endl;
    }
}
