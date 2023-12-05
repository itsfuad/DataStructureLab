#include <iostream>
#include <sstream>

class Node{
    public:
        Node* prev;
        Node* next;
        int data;
};

class LinkedList{
    public:
        Node* _head;
        Node* _tail;
        LinkedList():
            _head(nullptr),
            _tail(nullptr)
        {}

        ~LinkedList(){
            Node* curr = _head;
            while(curr != nullptr){
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
        }

        void push_back(int data){
            Node* newNode = new Node();
            newNode->data = data;
            if(_head == nullptr){
                _head = newNode;
                _tail = newNode;
            }
            else{
                _tail->next = newNode;
                newNode->prev = _tail;
                _tail = newNode;
            }
        }

        void push_front(int data){
            Node* newNode = new Node();
            newNode->data = data;
            if(_head == nullptr){
                _head = newNode;
                _tail = newNode;
            }
            else{
                _head->prev = newNode;
                newNode->next = _head;
                _head = newNode;
            }
        }

        void pop_back(){
            if(_head == nullptr){
                return;
            }
            else if(_head == _tail){
                delete _head;
                _head = nullptr;
                _tail = nullptr;
            }
            else{
                Node* temp = _tail;
                _tail = _tail->prev;
                _tail->next = nullptr;
                delete temp;
            }
        }

        void pop_front(){
            if(_head == nullptr){
                return;
            }
            else if(_head == _tail){
                delete _head;
                _head = nullptr;
                _tail = nullptr;
            }
            else{
                Node* temp = _head;
                _head = _head->next;
                _head->prev = nullptr;
                delete temp;
            }
        }

        void addAfter(Node* node, int data){
            //if node is tail
            if(node->next == nullptr){
                push_back(data);
            }
            else{
                Node* newNode = new Node();
                newNode->data = data;
                newNode->prev = node;
                newNode->next = node->next;
                node->next = newNode;
                newNode->next->prev = newNode;
            }

            std::cout << "Added " << data << " after " << node->data << std::endl;
        }

        void addBefore(Node* node, int data){
            //if node is head
            if(node->prev == nullptr){
                push_front(data);
            }
            else{
                Node* newNode = new Node();
                newNode->data = data;
                newNode->next = node;
                newNode->prev = node->prev;
                node->prev = newNode;
                newNode->prev->next = newNode;
            }

            std::cout << "Added " << data << " before " << node->data << std::endl;
        }

        void removeAfter(Node* node){
            if(node->next == nullptr){
                return;
            }
            else{
                //remove the node after the given node
                Node* temp = node->next;
                node->next = temp->next;
                temp->next->prev = node;
                delete temp;

                std::cout << "Removed node after " << node->data << std::endl;
            }
        }

        void removeBefore(Node* node){
            if(node->prev == nullptr){
                return;
            }
            else{
                //remove the node before the given node
                Node* temp = node->prev;
                node->prev = temp->prev;
                temp->prev->next = node;
                delete temp;

                std::cout << "Removed node before " << node->data << std::endl;
            }
        }

        friend std::ostream& operator<<(std::ostream& os, LinkedList& list);
};


std::ostream& operator<<(std::ostream& os, LinkedList& list){
    Node* curr = list._head;
    os << "[ ";
    while(curr != nullptr){
        os << curr->data;
        curr = curr->next;
        if(curr != nullptr){
            os << ", ";
        }
    }
    os << " ]";
    return os;
}


int main(){
    LinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    std::cout << list << std::endl;
    list.pop_back();
    std::cout << list << std::endl;
    list.pop_front();
    std::cout << list << std::endl;
    list.push_front(4);
    std::cout << list << std::endl;
    list.addAfter(list._head, 5);
    std::cout << list << std::endl;
    list.addBefore(list._head, 6);
    std::cout << list << std::endl;
    list.removeAfter(list._head);
    std::cout << list << std::endl;
    list.removeBefore(list._head->next->next);
    std::cout << list << std::endl;
    return 0;
}
