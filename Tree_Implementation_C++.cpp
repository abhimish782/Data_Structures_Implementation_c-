#include<bits/stdc++.h>
using namespace std;

struct node
{
    int val;
    node* left;
    node* right;
    node(int x){
        val=x;
        left=right=nullptr;
    }
};
// Insertion in binary tree


node* insert(node*root,int value){
    if(root==nullptr){
        root=new node(value);
        return root;
    }
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp->left!=nullptr){
            q.push(root->left);
        }
        else{
            temp->left=new node(value);
            return root;
        }
        if(root->right!=nullptr) {
        q.push(root->right);
        }
        else{
            temp->right=new node(value);
            return root;
        }
    }
}

//inorder traversal 


void inorder(node* root){
    if(root==nullptr) return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

// preorder traversal 


void preorder(node* root){
    if(root==nullptr) return;
    cout<<root->val;
    preorder(root->left);
    preorder(root->right);
}

// post order traversal


void postorder(node* root){
    if(root==nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->val;
}

// height/Depth of a binary tree

int height(node* root){
    if(root==nullptr) return 0;
    else{
        return max(height(root->left),height(root->right))+1;
    }
}

// Nodes at k distance from the root

void print_Nodes_K_distance(node* root,int k){
    if(k==0) cout<<root->val;
    else{
        print_Nodes_K_distance(root->left,k-1);
        print_Nodes_K_distance(root->right,k-1);
    }
}

// Level order traversal in binary trees;

void bfs_binary_tree(node* root){
    if(root==nullptr) return ;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node* curr=q.front();
        q.pop();
        cout<<curr->val;
        if(curr->left!=nullptr) q.push(curr->left);
        if(curr->right!=nullptr)q.push(curr->right);
    }
    return;
}

// level order traversal line by line level by level
 void bfs_level_binary_tree(node* root){
    if(root==nullptr) return;
    queue<node*> q;
    q.push(root);
    while(!q.empty()){
        int level=q.size();
        for(int i=0;i<level;i++){
            node* curr=q.front();
            q.pop();
            cout<<curr->val;
            if(curr->left!=nullptr) q.push(curr->left);
            if(curr->right!=nullptr) q.push(curr->right);
        }
        cout<<endl;
    }
    return;
 }

// size of a binary tree

int SizeOfTree(node* root){
    if(root==nullptr) return 0;
    else{
        return 1+SizeOfTree(root->left)+SizeOfTree(root->right);
    }
}

int main(){
    node* root=NULL;
    int n;
    cout<<"Enter no of nodes"<<endl;
    cin>>n;
    cout<<"Enter the nodes"<<endl;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        root=insert(root,temp);
    }
    
    inorder(root);
    int h=height(root);
    cout<<"Height is"<<h;
    return 0;


}