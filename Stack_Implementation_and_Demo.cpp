#include <iostream>

template <class T, int SIZE>
class Stack{
    private:
        int top;
        T arr[SIZE];
    public:
        Stack();
        void push(T);
        T pop();
        bool isEmpty();
        bool isFull();
        void print();
};

template <class T, int SIZE>
Stack<T, SIZE>::Stack(){
    top = -1;
}

template <class T, int SIZE>
void Stack<T, SIZE>::push(T data){
    if(!isFull()){
        top++;
        arr[top] = data;
        std::cout << "Pushed " << data << " to stack" << std::endl;
    }else{
        std::cout << "Stack is full" << std::endl;
    }
}

template <class T, int SIZE>
T Stack<T, SIZE>::pop(){
    if(!isEmpty()){
        T data = arr[top];
        top--;
        std::cout << "Popped " << data << " from stack" << std::endl;
        return data;
    }else{
        std::cout << "Stack is empty" << std::endl;
    }
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isEmpty(){
    return top == -1;
}

template <class T, int SIZE>
bool Stack<T, SIZE>::isFull(){
    return top == SIZE - 1;
}

template <class T, int SIZE>
void Stack<T, SIZE>::print(){
    int length = top;
    while (length != -1){
        std::cout << arr[length--] << std::endl;
    }
}

int main(){
    Stack<int, 5> stack;
    char choice;
    do{
        std::cout << "---- Stack -----\n";
        std::cout << "1. Push Value\n";
        std::cout << "2. Pop value\n";
        std::cout << "3. Print all values\n";
        std::cout << "4. isEmpty?\n";
        std::cout << "5. Exit\n";


        std::cin >> choice;


        switch(choice){
        case '1':
            int value;
            std::cout << "Enter value: ";
            std::cin >> value;
            stack.push(value);
            break;
        case '2':
            stack.pop();
            break;
        case '3':
            stack.print();
            break;
        case '4':
            if (stack.isEmpty()){
                std::cout << "Stack is empty" << std::endl;
            } else {
                std::cout << "Stack is empty" << std::endl;
            }
            break;
        default:
            std::cout << "Invalid choice" << std::endl;
        }

    } while (choice != '5');
    return 0;
}
