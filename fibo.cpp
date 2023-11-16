#include<bits/stdc++.h>
using namespace std;

int rfib(int n){
    if(n <= 1) return n;
    return rfib(n - 1) + rfib(n - 2);
}

int ifib(int n){
    vector<int> fib;
    fib.push_back(0);
    fib.push_back(1);
    for(int i = 2; i <= n; i++){
        int temp = fib[i-2] + fib[i-1];
        fib.push_back(temp);
    }
    return fib[n];
}
int main(){
    int n;
    cin>>n;
    cout<<rfib(n)<<endl;
    cout<<ifib(n)<<endl;
    return 0;
}