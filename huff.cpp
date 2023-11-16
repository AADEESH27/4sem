#include<bits/stdc++.h>
using namespace std;

struct Node{
    char data;
    int freq;
    Node *left, *right;
    Node(char data, int freq){
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

struct compare{
    bool operator()(Node *a, Node *b){
        return (a->freq > b->freq);
    }
};

void print(struct Node *root, string str){
    if(root == nullptr){
        return;
    }
    if(root->data != '#'){
        cout<<root->data<<" "<<str<<endl;
    }
    print(root->left, str+"0");
    print(root->right, str+"1");
    
}
void solve(char data[], int freq[], int size){
    Node *left, *right, *temp;
    priority_queue<Node*, vector<Node*>, compare> heap;
    for(int i = 0; i < size; i++){
        heap.push(new Node(data[i], freq[i]));
    }
    while(heap.size() != 1){
        left = heap.top();
        heap.pop();
        right = heap.top();
        heap.pop();
        temp = new Node('#', left->freq+right->freq);
        temp->left = left;
        temp->right = right;
        heap.push(temp);
    }
    print(heap.top(), "");
}

int main(){
	char data[] = {'A', 'B', 'C', 'D'};
	int freq[] = {23,12,34,10};
	solve(data, freq, 4);
	return 0;
}