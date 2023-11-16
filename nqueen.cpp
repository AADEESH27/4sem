#include<bits/stdc++.h>
using namespace std;

void printSolution(vector<vector<int>> board, int n) 
{ 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++)  {
            if(board[i][j]) {
                cout << "Q ";
            }
            else {
                cout << "_ ";
            }
        }
            
        cout << "\n"; 
    } 
    cout << "\n\n";
} 

bool isSafe(vector<vector<int>> board, int row, int col, int n){
    int i, j;
    for(i = 0; i < col; i++){
        if(board[row][i]){
            return false;
        }
    }
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
        if(board[i][j]){
            return false;
        }
    }
    for(i = row, j = col; j >= 0 && i < n; i++, j--){
        if(board[i][j]){
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> board, int col, int n){
    if(col >= n){
        printSolution(board, n);
    }
    for(int i = 0; i < n; i++){
        if(isSafe(board, i, col, n)){
            board[i][col] = 1;
            solve(board, col+1, n);
            board[i][col] = 0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> board(n, vector<int>(n, 0));
    solve(board, 0, n);
    return n;
}