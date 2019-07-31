#include <iostream>
using namespace std;
class Stack{
    private:
        struct Node{
            int data;
            struct Node* next;
        };
        struct Node* top;
    public:
        Stack(){
            this->top = NULL;
        }
        void push(int data){
            struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
            temp->data = data;
            if(this->top == NULL){
                temp->next = NULL;
                this->top = temp;
            }else{
                temp->next = this->top;
                this->top = temp;
            }
        }
        void pop(){
            if(top == NULL){
                cout<<"Stack is empty\n";
            }else{
                struct Node* temp = top;
                top = top->next;
                free(temp);
            }
        }
        int getTop(){
            cout<<top->data<<endl;
        }
        void printStack(){
            struct Node* ptr = top;
            while( ptr != NULL ){
                cout<<ptr->data<<endl;
                ptr = ptr->next;
            }
        }
};
int main() {
	Stack *stack = new Stack();
	stack->push(5);
	stack->push(3);
	stack->push(7);
	stack->printStack();
	cout<<"*****"<<endl;
	stack->pop();
	stack->printStack();
	cout<<"*****"<<endl;
	stack->pop();
	stack->pop();
	stack->printStack();
	cout<<"*****"<<endl;
	stack->pop();
	stack->printStack();
	return 0;
}
