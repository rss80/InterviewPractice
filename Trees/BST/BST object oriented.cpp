#include<iostream>
#include<vector>
using namespace std;

class BinarySearchTree{
    private:
        struct Node{
            int data;
            struct Node *left, *right;
        };
        struct Node* root;
    public:
    BinarySearchTree(){
            root = NULL;
        }
        struct Node* newNode(int data){
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = data;
            temp->left = NULL;
            temp->right = NULL;
            return temp;
        }
        void addNode(int data){
            root = addNodeHelper(root,data);
        }
        struct Node* addNodeHelper(struct Node* root, int data){
            if(root == NULL){
        		//root = newNode(data); doesnt work because addNode creates a new copy of root.
                return newNode(data);
            }else if(root->data > data){
                root->left = addNodeHelper(root->left, data);
            }else{
                root->right = addNodeHelper(root->right, data);
            }
        	// we return the root node at the end.
            return root;
        }
        void printInorderUtility(){
            printInorder(root);
        }
        void printInorder(struct Node* root){
            if(root != NULL){
                printInorder(root->left);
                cout<<root->data<<" ";
                printInorder(root->right);
            }
        }
};

int main() {
    int n;
    cin>>n;
    vector<int> values(n);
    for(int i=0;i<n;i++)
        cin>>values[i];
    BinarySearchTree *binarySearchTree = new BinarySearchTree();
    for(int i=0;i<n;i++){
        binarySearchTree->addNode(values[i]);
    }
    binarySearchTree->printInorderUtility();
	return 0;
}