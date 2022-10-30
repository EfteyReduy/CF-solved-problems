#include<bits/stdc++.h>



using namespace std;
void manipulate(int &arr, int n){
    int i;
    for(i=0; i<n; i++)
    {
        arr=n-i+5;
    }

}

main()
{
    int ar[10];
    manipulate(ar, 10);
    for(int i=0; i<10; i++)
    {
        cout<<ar[i]<<"  ";
    }
}
