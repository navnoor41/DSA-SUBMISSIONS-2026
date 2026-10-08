include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        left=nullptr;
        right=nullptr;
    }
};

void insert(Node* root,int value){
    if(root==nullptr) return;
    if(root->val<value){
        if(root->right==nullptr){
            Node* temp=new Node(value);
            root->right=temp;
        }
        else{
            insert(root->right,value);
        }
    }
    if(root->val>value){
        if(root->left==nullptr){
            Node* temp=new Node(value);
            root->left=temp;
        }
        else{
            insert(root->left,value);
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
bool search(Node* root, int value) {
    if (root == nullptr)
        return false;

    if (root->val == value)
        return true;

    if (root->val < value)
        return search(root->right, value);
    else
        return search(root->left, value);
}
void display(Node* root){
    if(root==nullptr)return;
   display(root->left);
   cout<<root->val<<" ";
   display(root->right);
}
int main(){
    Node* root=new Node(10);
    createBT(root);
    display(root);
    int n;
    cout<<"value to be searched: ";
    cin>>n;
   bool t=search(root,n);
   if(t==true) cout<<"\n found!!";
   else cout<<"\n not found";
   
}
