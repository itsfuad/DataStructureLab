#include <iostream>

class Node{
    private:
        int data;
        Node* next;
    public:
        friend class LinkedList;
};

class LinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        LinkedList(){
            head = NULL;
        }
        void Insert(int data){
            Node* newNode = new Node();
            newNode->data = data;
            
            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
        }

        void Delete(int data){
            Node* temp = head;
            Node* prev = NULL;
            while(temp != NULL){
                if(temp->data == data){
                    if(prev == NULL){
                        head = temp->next;
                    }else{
                        prev->next = temp->next;
                    }
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        void Pop(){
            Node* temp = head;
            Node* prev = NULL;
            while(temp != NULL){
                if(temp->next == NULL){
                    if(prev == NULL){
                        head = NULL;
                    }else{
                        prev->next = NULL;
                    }
                    delete temp;
                    return;
                }
                prev = temp;
                temp = temp->next;
            }
        }

        bool Search(int data){
            Node* temp = head;
            while(temp != NULL){
                if(temp->data == data){
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        void print(){
            Node* temp = head;
            std::cout << "[ ";
            while(temp != NULL){
                std::cout << temp->data;
                if(temp->next != NULL){
                    std::cout << ", ";
                }
                temp = temp->next;
            }
            std::cout << " ]" << std::endl;
        }
};


int main(){
    LinkedList list;
    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.print();
    list.Delete(3);
    list.print();
    list.Pop();
    list.print();
    std::cout << list.Search(3) << std::endl;
    std::cout << list.Search(4) << std::endl;
    return 0;
}
