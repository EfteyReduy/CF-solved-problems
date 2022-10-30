#include<bits/stdc++.h>

using namespace std;
main()
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    pair<double, double> nums[n];
    for(int i=0; i<n; i++)
    {
        int a, b;
        cin>>a>>b;
        nums[i]={a, b};
    }
    char sign;
    cout<<"Enter the operator : ";
    cin>>sign;

    for(int i=0; i<n; i++)
    {
        double num1 = nums[i].first, num2 = nums[i].second;
        switch(sign){
        case '+':
            cout<<num1+num2<<endl;
            break;
        case '-':
            cout<<num1-num2<<endl;
            break;
        case '*':
            cout<<num1*num2<<endl;
            break;
        case '/':
            if(num2==0)
            {
                cout<<"Invalid input."<<endl;
                break;
            }
            cout<<num1/num2<<endl;
            break;
        case '%':
            if(num2==0)
            {
                cout<<"Invalid input."<<endl;
                break;
            }
            cout<<(int)num1%(int)num2<<endl;
            break;
        }
    }

}
