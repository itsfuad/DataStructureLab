/*
Write a C++ program to find and remove the lowest element in a stack.
Test Data:
Input some elements onto the stack:
Stack elements are: 5 2 4 7
Find and remove the lowest element 2 from the stack.
Stack elements are: 5 4 7
Input two more elements
Stack elements are: 2 -1 5 4 7
Find and remove the lowest element -1 from the stack.
Stack elements are: 2 5 4 7
*/

#include <iostream>

class Stack {
private:
    int top;
    int arr[5];

public:
    void push(int data){
        if (top == 4){
            std::cout << "Stack is full" << std::endl;
        } else {
            top++;
            arr[top] = data;
        }
    }

    void pop(){
        if (top == -1){
            std::cout << "Stack is empty" << std::endl;
        } else {
            int popValue = arr[top];
            top--;
            std::cout << "The popped value is " << popValue << std::endl;
        }
    }

    void display(){
        std::cout << "Stack elements are: ";
        for (int i = top; i >= 0; i--){
            std::cout << arr[i] << " ";
        }
        std::cout << std::endl;
    }

    void lowest(){
        int lowest = arr[0];
        int index = 0;
        for (int i = 0; i <= top; i++){
            if (arr[i] < lowest){
                lowest = arr[i];
                index = i;
            }
        }
        std::cout << "The lowest value is " << lowest << " index " << index << std::endl;
    }

    void removeLowest(){
        int lowest = arr[0];
        for (int i = 0; i <= top; i++){
            if (arr[i] < lowest){
                lowest = arr[i];
            }
        }
        for (int i = 0; i <= top; i++){
            if (arr[i] == lowest){
                arr[i] = 0;
            }
        }

        //shift all elements to the left
        for (int i = 0; i <= top; i++){
            if (arr[i] == 0){
                for (int j = i; j < 5; j++){
                    arr[j] = arr[j+1];
                }
            }
        }

        top--;
    }

    Stack(){
        top = -1;
        for (int i = 0; i < 5; i++){
            arr[i] = 0;
        }
    }

    ~Stack(){
        std::cout << "Stack destroyed" << std::endl;
    }
};

int main() {
    Stack stack;
    stack.push(7);
    stack.push(4);
    stack.push(2);
    stack.push(5);
    stack.display();

    stack.lowest();
    stack.removeLowest();
    stack.display();

    stack.push(-1);
    stack.push(2);
    stack.display();

    stack.lowest();
    stack.removeLowest();
    stack.display();
}
