

/*
Implement basic stack operations of 50 size array using class and struct. Necessary functions:
void isEmpty()
void isFull()
void Push(int element)
void pop()
void topElement()
void show()
*/

#include <iostream>

template <typename T, int SIZE>
class Stack{
    private:
        T arr[SIZE];
        int top;
    public:
        Stack(){
            top = -1;
        }
        void isEmpty(){
            if(top == -1){
                std::cout << "Stack is empty" << std::endl;
            }
            else{
                std::cout << "Stack is not empty" << std::endl;
            }
        }
        void isFull(){
            if(top == SIZE-1){
                std::cout << "Stack is full" << std::endl;
            }
            else{
                std::cout << "Stack is not full" << std::endl;
            }
        }
        void push(T element){
            if(top == SIZE-1){
                std::cout << "Stack is full" << std::endl;
            }
            else{
                top++;
                arr[top] = element;
                std::cout << "Element pushed: " << element << std::endl;
            }
        }
        void pop(){
            if(top == -1){
                std::cout << "Stack is empty" << std::endl;
            }
            else{
                top--;
                std::cout << "Element popped" << std::endl;
            }
        }
        void topElement(){
            if(top == -1){
                std::cout << "Stack is empty" << std::endl;
            }
            else{
                std::cout << "Top element: " << arr[top] << std::endl;
            }
        }
        void show(){
            if(top == -1){
                std::cout << "Stack is empty" << std::endl;
            }
            else{
                std::cout << "Stack elements: ";
                for(int i = 0; i <= top; i++){
                    std::cout << arr[i] << " ";
                }
                std::cout << std::endl;
            }
        }
};


int main(){
    Stack<int, 50> s;
    s.isEmpty();
    s.isFull();
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.show();
    s.topElement();
    s.pop();
    s.show();
    s.topElement();
    s.pop();
    s.show();
    s.pop();
    s.pop();
    s.show();
}
