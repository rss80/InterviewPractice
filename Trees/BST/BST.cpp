#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int data;
    struct Node *left, *right;
};
struct Node* newNode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
struct Node* addNode(struct Node* root, int data){
    if(root == NULL){
		//root = newNode(data); doesnt work because addNode creates a new copy of root.
        return newNode(data);
    }else if(root->data > data){
        root->left = addNode(root->left, data);
    }else{
        root->right = addNode(root->right, data);
    }
	// we return the root node at the end.
    return root;
}
void printInorder(struct Node* root){
    if(root != NULL){
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
}
void printInput(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0;i<n;i++)
        cin>>values[i];
    struct Node* root = NULL;
    for(int i=0;i<n;i++){
        root = addNode(root,values[i]);
    }
    printInorder(root);
	return 0;
}
