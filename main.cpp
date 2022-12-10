#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int data;
    Node *nextAddress;
};


class List{
private:
    Node *head;
    Node *tail;
public:
    List(){
        head = nullptr;
        tail = nullptr;
    }

    bool isEmpty(){
        return head == nullptr;
    }

    void addNode(int value){
        Node *newNode = new Node;
        newNode->data = value;
        newNode->nextAddress = nullptr;
        if (isEmpty()){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->nextAddress = newNode;
        tail = newNode;
    }

    void bubbleSortLinkedList(int numberOfNodes){
        int nodeCtr;
        int ctr;
        int nodeDataCopy;
        Node* currentData;
        Node* nextNode;
        // цикл до тех пор, пока все узлы не будут отсортированы в порядке возрастания.
        for (nodeCtr = numberOfNodes - 2; nodeCtr >= 0; nodeCtr--){
            // проверяем первые два узла списка.
            currentData = head;
            nextNode = currentData->nextAddress;
            //цикл до тех пор, пока все меньший узел не будет головой нашего списка.

            for (ctr = 0; ctr <= nodeCtr; ctr ++){
                if (currentData->data > nextNode->data) {
                    nodeDataCopy = currentData->data;
                    currentData->data = nextNode->data;
                    nextNode->data = nodeDataCopy;
                }
                //переходим к следующему ноду.
                currentData = nextNode;
                nextNode = nextNode->nextAddress;
            }
        }
    }

    void print(){
        Node *currentData = head;
        while(currentData){
            cout << currentData->data << ' ';
            currentData = currentData->nextAddress;
        }
    }
};

int main(){
    List list;

    for (int i = 0; i < 5; i ++){
        int x;
        cin >> x;
        list.addNode(x);
    }

    cout << "List before sorted" << ':';
    list.print();
    list.bubbleSortLinkedList(5);
    cout << endl;
    cout << "List after sorted" << ':';
    list.print();
}