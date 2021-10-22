#ifndef LIST_H_
#define LIST_H_
#include <iostream>
using namespace std;

template <class T>
struct Node {
    T num;
    Node<T>* next;
};

template <class T>
class List {
    enum { MAX = 100 };
private:
    Node<T>* front;
    Node<T>* rear;
    int qsize;
    Node<T>* now;
public:
    List();
    ~List();
    void add(const T& t);
    bool isEmpty() const;
    bool isFull() const;
    //void set(const T &t)const;
    void visit() {
        Node<T>* p = front;
        while (p) {
            cout << p->num << "  ";
            p = p->next;
        }
        cout << endl;
    }

};
#endif