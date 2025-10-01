#ifndef MY_STACK
#define MY_STACK

/*
Write your solution here.
*/

#include <iostream>

using namespace std;

class MyStack{
    private:
        int *ptr;
        int storage; 
        int stack_top = 0; 
    public:
        MyStack(int total) {
            storage = total;
            ptr = new int[storage];
        }
        void push(int user_input){
            if (stack_top == storage -1) {
                cout << "Stack is full" << endl;
            } else {
                ptr[stack_top] = user_input;
                stack_top++ ;  
            }
        }
        int pop() {
            int value = ptr[stack_top-1];
            stack_top--;
            return value; 
        }
        int top() {
            return ptr[stack_top-1];
        }
        bool isempty() {
            if (stack_top == 0) {
                return true;
            } else {
                return false;
            }
        }
        ~MyStack() {
            delete [] ptr; 
        }
};

int main() {
    int size;
    cout << "Enter stack size: ";
    cin >> size;
    MyStack stack = {size};
    char inp;
    int user;
    while (true) {
        cout << "p = push, t = top, e = pop, i = if empty  or q = quit: " << endl;
        cin >> inp;
        if (inp == 'p') {
            cin >> user;
            stack.push(user);
        } else if (inp == 'e') {
            if (stack.isempty()) {
                cout << "stack is empty" << endl;
            } else {
                user = stack.pop();
                cout << "Popped value is: " << user << endl;
            }
        } else if (inp == 't') {
           if (stack.isempty()) {
                cout << "stack is empty" << endl;
            } else {
                user = stack.top();
                cout << "Top value is: " <<  user << endl; 
            }
        } else if (inp == 'i') {
            if (stack.isempty()) {
                cout << "Stack is empty" << endl;
            } else {
                cout << "Stack is not empty" << endl;
            }
        } else if (inp == 'q') {
            break;
        } else {
            cout << "Invalid input" << endl;
        }
    }
    return 0;
}



#endif  // MY_STACK
