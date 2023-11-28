#include <iostream>

class Node{
    private:
        int data;
        Node* next;
        Node* prev;
    public:
        friend class DoublyLinkedList;
};

class DoublyLinkedList{
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList(){
            head = NULL;
            tail = NULL;
        }

        void Insert(int data){
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            newNode->prev = NULL;

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }
            else{
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
        }

        void Delete(int data){
            Node* temp = head;
            while(temp != NULL){
                if(temp->data == data){
                    if(temp == head){
                        head = head->next;
                        head->prev = NULL;
                    }
                    else if(temp == tail){
                        tail = tail->prev;
                        tail->next = NULL;
                    }
                    else{
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }
                    delete temp;
                    return;
                }
                temp = temp->next;
            }
        }


        void Pop(){
            Node* temp = tail;

            if(temp == NULL){
                return;
            }
            else if(temp == head){
                head = NULL;
                tail = NULL;
            }
            else{
                tail = tail->prev;
                tail->next = NULL;
            }
        }

        void Print(){
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

};


int main(){

    DoublyLinkedList list;

    list.Insert(1);
    list.Insert(2);
    list.Insert(3);
    list.Insert(4);
    list.Insert(5);
    list.Insert(6);
    list.Insert(7);
    list.Insert(8);

    list.Print();

    list.Delete(4);

    list.Print();

    list.Pop();

    list.Print();

    std::cout << list.Search(4) << std::endl;
    std::cout << list.Search(5) << std::endl;

    return 0;
}
