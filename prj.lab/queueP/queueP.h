//authoring
#pragma once
#ifndef queueP_H_20221110
#define queueP_H_20221110
#include <iosfwd>
#include <memory>

class queueP{
public:
    queueP();
    ~queueP();
    queueP& operator=(const queueP& rhs);
    
    void push(const int& val);
    void pop();
    bool isEmpty() const;
    const int& top() const;
private:
    struct  Node {
        Node(const int& value, std::unique_ptr<Node> next_el = nullptr) : 
        val(value), next(next_el) {}
        int val;
        std::unique_ptr<Node> next;
    };
    std::unique_ptr<Node> head;

};
#endif