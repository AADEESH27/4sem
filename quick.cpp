#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int l, int r){
    int p = arr[r];
    int i = l - 1;
    for(int j = l; j < r; j++){
        if(arr[j] <= p){
            i = i+1;
            swap(arr[j], arr[i]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

int findPivot(vector<int> &arr, int l, int r){
    int pivot = l + rand() % (r - l);
    swap(arr[pivot], arr[r]);
    return partition(arr, l, r);
}

void qsortRandom(vector<int> &arr, int l, int r){
    if(l < r){
        int pivot = findPivot(arr, l, r);
        qsortRandom(arr, l, pivot - 1);
        qsortRandom(arr, pivot + 1, r);
    }
}

void qsort(vector<int> &arr, int l, int r){
    if(l < r){
        int pivot = partition(arr, l, r);
        qsort(arr, l, pivot-1);
        qsort(arr, pivot+1, r);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int temp;
        cin>>temp;
        arr.push_back(temp);
    }
    qsortRandom(arr, 0, n-1);
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}