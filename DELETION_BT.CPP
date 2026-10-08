#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;

    Node(int val) {
        this->val = val;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

void insert(Node* root, int value) {
    if (root == nullptr)
        return;

    if (root->val < value) {

        if (root->right == nullptr) {
            Node* temp = new Node(value);
            root->right = temp;
            temp->parent = root;
        }
        else {
            insert(root->right, value);
        }
    }
    else {

        if (root->left == nullptr) {
            Node* temp = new Node(value);
            root->left = temp;
            temp->parent = root;
        }
        else {
            insert(root->left, value);
        }
    }
}
void createBT(Node* root){
    cout<<"enter the no. of nodes in tree : ";
    int n;
    cin>>n;
 int value;
    for(int i=0;i<n;i++){
        cout<<"enter value : ";
        cin>>value;
        insert(root,value);
    }
}
Node* search(Node* root, int value) {
    if (root == nullptr)
        return 0;

    if (root->val == value)
        return root;

    if (root->val < value)
        return search(root->right, value);
    else
        return search(root->left, value);
}
Node* maxNode(Node* temp){
    while(temp->right!=nullptr){
        temp=temp->right;
    }
    return temp;
}
void display(Node* root){
if(root==nullptr) return;
display(root->left);
cout<<root->val<<" ";
display(root->right);
}
void Delete(Node* root, int value) {

    root = search(root, value);

    if(root == nullptr)
        return;

    // 0 children
    if(root->left == nullptr && root->right == nullptr) {
          // If root itself is being deleted
        if (root->parent == nullptr) {
            cout << "Cannot delete the root using this function.\n";
            return;
        }
       if(root->parent->left == root) root->parent->left=nullptr;
       else root->parent->right=nullptr;
       delete root;
    }

    // 1 child
    else if(root->left == nullptr || root->right == nullptr) {
        if (root->parent == nullptr) {
                cout << "Root has one child. Root replacement needs to be handled.\n";
                return;
            }
        if(root->right==nullptr){
             
            if(root->parent->left==root){
                root->parent->left=root->left;
                root->left->parent=root->parent;
            }
            else{
                 root->parent->right=root->left;
                root->left->parent=root->parent;
            }
        }
        else {
            if(root->parent->left==root){
                root->parent->left=root->right;
            }
            else{
                root->parent->right=root->right;
            }
            root->right->parent=root->parent;
        }
        delete root;
    }

    // 2 children
    else{
        Node* temp=maxNode(root->left);
        root->val=temp->val;
        Delete(root->left,temp->val);
    }
         
}

int main(){
    Node* root=new Node(10);
    createBT(root);
        cout << "\nBST before deletion: ";
       display(root);
    cout << "\nNode's val to be deleted: ";
    int n;
    cin>>n;
    Delete(root,n);
        cout << "\nBST after deletion: ";
            display(root);


     
}
  
