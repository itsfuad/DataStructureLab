#include <iostream>

template <typename T, int SIZE>
class Queue{
private:
    T arr[SIZE];
    int front = -1;
    int back = -1;
public:
    void enqueue(T val){
        if (front == -1){
            //queue is empty. Add it on front
            arr[++front] = val;
            back++;
            std::cout << "Added " << val << " on queue" << std::endl;
        } else if (back < SIZE - 1) {
            //queue has room
            arr[++back] = val;
            std::cout << "Added " << val << " on queue" << std::endl;
        } else{
            std::cout << "Queue is full" << std::endl;
        }
    }

    void dequeue(){
        if (front >= 0 && front < SIZE - 1){
            front++;
            std::cout << "Dequeued" << std::endl;
        }
        std::cout << "Queue is empty" << std::endl;
    }

    void showQueue(){

        if (front == -1){
            std::cout << "Queue is empty" << std::endl;
            return;
        }

        std::cout << "Queue: ";
        for (int i = front; i <= back; i++){
            std::cout << arr[i] << " ";
        }
    }
};

int main()
{
    Queue<int, 5> q;
    q.showQueue();
    q.enqueue(1);
    q.enqueue(2);
    q.showQueue();
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();
    q.showQueue();


    return 0;
}
