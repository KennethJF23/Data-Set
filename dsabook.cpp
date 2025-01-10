#include <iostream>
using namespace std;

void function(int n){
    if(n==1){
        return;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<"*";
            function(n-3);
        }
    }  
}


void function2(int k){
    int i=1,s=1;
    while(s<=k){
        i++;
        s+=i;
        printf("*");
    }
}

int main(){
    int n;
    cin>>n;
    int k;
    cin>>k;
    function2(k);
}
//The recurrence of the above code is T(n) = T(n-3) + cn^2 for some constant c>0 since each call prints n^2 asterisks and calls itself recursively on n-3.
// Using the Subtraction and Conquer Master Theorem we get T(n)=O(n^3) 
// That is Let T(n) = be defined as a positive function n and having the property
//T(n) = {c,aT(n-b) + f(n)} ifn<=1,n>1 for some constants c,a>0,b>=0,k>=0and function
//f(n) is in o(n^k) then T(n)={o(n^k) if a<1,O(n^k+1)if a=1,O(n^k*a^n/b if a>1)} 