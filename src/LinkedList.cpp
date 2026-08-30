#include "LinkedList.h"

Node* initList() {
    Node* head = new Node;
    head->next = nullptr;
    return head;
}

void insertOrdered(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    Node* prev = head;
    Node* current = head->next;

    while (current != nullptr && current->data < value) {
        prev = current;
        current = current->next;
    }

    if (current != nullptr && current->data == value) {
        cout << "值 " << value << " 已存在，不重复插入" << endl;
        delete newNode;
        return;
    }

    prev->next = newNode;
    newNode->next = current;
    cout << "插入 " << value << " 成功" << endl;
}

bool deleteNode(Node* head, int value) {
    Node* prev = head;
    Node* current = head->next;
    while (current != nullptr && current->data != value) {
        prev = current;
        current = current->next;
    }
    if (current == nullptr) {
        cout << "未找到值 " << value << endl;
        return false;
    }
    prev->next = current->next;
    delete current;
    cout << "删除 " << value << " 成功" << endl;
    return true;
}

bool searchNode(Node* head, int value, int& pos) {
    Node* current = head->next;
    pos = 1;
    while (current != nullptr) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
        pos++;
    }
    return false;
}

int getLength(Node* head) {
    Node* current = head->next;
    int len = 0;
    while (current != nullptr) {
        len++;
        current = current->next;
    }
    return len;
}

void destroyList(Node* head) {
    Node* current = head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    cout << "链表已销毁，内存已释放" << endl;
}

void displayList(Node* head) {
    Node* current = head->next;
    if (current == nullptr) {
        cout << "链表为空" << endl;
        return;
    }
    cout << "链表元素: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}