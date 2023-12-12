#include <iostream>

template <typename T, int SIZE>
class CircularQueue{
    public:
        CircularQueue():
            m_front(0),
            m_back(0),
            m_count(0)
        {
        }

        void enqueue(T data){
            if(isFull()){
                std::cout << "Queue is full" << std::endl;
                return;
            }
            m_array[m_back] = data;
            m_back = (m_back + 1) % SIZE;
            m_count++;
        }

        T dequeue(){
            if(isEmpty()){
                std::cout << "Queue is empty" << std::endl;
                return -1;
            }
            T data = m_array[m_front];
            m_front = (m_front + 1) % SIZE; // wrap around to the front of the array if index is at the end
            m_count--;
            return data;
        }

        bool isEmpty(){
            return m_count == 0;
        }

        bool isFull(){
            return m_count == SIZE;
        }

        void print(){
            std::cout << "Queue: [ ";
            for(int i = 0; i < m_count; i++){
                std::cout << m_array[(m_front + i) % SIZE];
                if(i < m_count - 1){
                    std::cout << ", ";
                }
            }
            std::cout << " ]" << std::endl;
        }

    private:
        T m_array[SIZE];
        int m_front;
        int m_back;
        int m_count;
};


int main(){
    CircularQueue<int, 5> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    queue.print();
    queue.dequeue();
    queue.dequeue();
    queue.print();
    queue.enqueue(6);
    queue.enqueue(7);
    queue.enqueue(8);
    queue.print();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.dequeue();
    queue.print();
    queue.enqueue(8);
    queue.enqueue(9);
    queue.enqueue(10);
    queue.enqueue(11);
    queue.enqueue(12);
    queue.print();
    return 0;
}
