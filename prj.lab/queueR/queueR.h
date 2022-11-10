//authoring
#pragma once
#ifndef queueR_H_20221012
#define queueR_H_20221012
#include <iosfwd>

class queueR{
public:
    queueR();
    //queueR(const queueR& copy);
    ~queueR();
    queueR& operator=(const queueR& rhs);
    
    void push(const int& val);
    void pop();
    bool isEmpty() const;
    const int& top() const;
private:
    struct  Node {
        Node(const int& value, Node* next_el = nullptr) : 
        val(value), next(next_el) {}
        int val;
        Node* next;
    };
    Node* head;

};
#endif