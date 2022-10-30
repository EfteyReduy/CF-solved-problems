#include<bits/stdc++.h>

using namespace std;

double summation(double arr[], int n){
    double total = 0;
    for(int i=0; i<n; i++)
    {
        total += arr[i];
    }
    return total;
}
double average(double arr[], int n){
    double total = summation(arr, n);
    return (double)(total)/(double)n;
}

main(){
    int n;
    cout<<"Enter the size of the array : ";
    cin>>n;
    double arr[n];
    cout<<"Enter the array."<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    double sum = 0, avg;
    int i=0;
    do{
        sum+=arr[i];
        i++;
    }while(i<n);
    cout<<"Sum using do-while loop = "<<sum<<endl;
    cout<<"Average using do-while loop = "<<sum/n<<endl;
    cout<<endl;
    sum = summation(arr, n);
    avg = average(arr, n);

    cout<<"Sum using function = "<<sum<<endl;
    cout<<"Average using function = "<<avg<<endl;

}
