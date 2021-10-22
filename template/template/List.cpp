#include <iostream>
#include "List.h"
using namespace std;

template <class T>
List<T>::List() {
    front = rear = now = NULL;
    qsize = 0;
}

template <class T>
List<T>::~List() {
    Node<T>* q, * p = front;
    while (p) {
        q = p->next;
        delete p;
        p = q;
    }
}

template <class T>//必须写出模板类，否则T无效
void List<T>::add(const T& t) {
    if (isFull()) {
        cout << "List is full\n";
        return;
    }
    Node<T>* newnode = new Node<T>;
    newnode->num = t;
    newnode->next = NULL;
    if (isEmpty()) {
        front = rear = newnode;
        ++qsize;
    }
    else {
        rear->next = newnode;
        qsize++;
        rear = newnode;
    }
    now = newnode;//令now指向当前节点
}

template <class T>
bool List<T>::isEmpty()const {
    return qsize == 0;
}
template <class T>
bool List<T>::isFull()const {
    return qsize == MAX;
}
