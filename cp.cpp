#include <bits/stdc++.h>
#include <set>

using namespace std;

int main(){
    set<int> s;
    int a[5]={2,3,4,5,6};
    s.insert(6);
    s.insert(0);
    s.insert(5);
    cout<<s.count(5)<<"\n";
    for(auto x:s){
        cout<<x<<"\n";
    }
    for(auto z:a){
        cout<<z<<"\n";
    }

    return 0;
}