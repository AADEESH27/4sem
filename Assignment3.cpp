#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&w,vector<int>&values,int W,int n, vector<vector<int>>&dp){
    if(n == 0 || W == 0) return 0;
    if(dp[W][n]!=-1) return dp[W][n];
    if(w[n-1]>W){
        return dp[W][n] = solve(w,values,W,n-1,dp);
    }
    else{
        return dp[W][n] =  max(values[n-1]+solve(w,values,W-w[n-1],n-1,dp) , solve(w,values,W,n-1,dp));
    }
}

int main(){
    vector<int>w = { 10, 20, 30};
    vector<int>v = {60, 100, 120 };
    int W = 50;
    int n = w.size();
    vector<vector<int>>dp(W+1,vector<int>(n+1,-1));
    cout<<solve(w,v,W,n,dp);
    return 0;
}