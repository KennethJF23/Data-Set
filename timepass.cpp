#include <iostream>
#include <string.h>
using namespace std;
/*void square(int n){
    if(n==1)return;
    for(int i=0;i<=n;i++){
        for(int j=1;j<=n;j++){
           cout<<"*";
           break;
        }
    }
}*/

/*void function(int n){
    int count=0;
    for(int i=n/2;i<=n;i++){
        for(int j=1;j+n/2<=n;j=j+1){
            for(int k=1;k<=n;k=k*2){
                count++;
            }
        }
    }
}*/
//Recursion classic
void towerofhanoi(int n,char from_rod,char to_rod,char aux_rod){
    if(n==0){
        return;
    }
    towerofhanoi(n-1,from_rod,aux_rod,to_rod);
    cout<<"Move disk"<<n<<"from rod"<<from_rod<<"to rod"<<to_rod<<"\n";
    towerofhanoi(n-1,aux_rod,to_rod,from_rod);
}


int main(){
    int n = 3;
    towerofhanoi (n,'A','B','C');
    char s[50]="KENNETH";
    cout<<s<<"\n";
    memset(s+5,'.',2*sizeof(char));
    cout<<s<<"\n";
    //memset only works for strings
    int arr[n];
    memset(arr,10,n*sizeof(int));
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"\n";
    }
 return 0;
}
