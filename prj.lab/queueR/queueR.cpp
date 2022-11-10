#include <sstream>
#include <iostream>
#include <queueR/queueR.h>

queueR::queueR() 
    :   head(nullptr)
    {}


queueR::~queueR()
{
    while (!this->isEmpty())
    {
        this->pop();
    }
    
}
queueR& queueR::operator=(const queueR& rhs)
{
    if (this != &rhs){
        queueR temp = rhs;
        head = temp.head;
    }
    return *this;
}
void queueR::push(const int& val){
    Node* temp_ptr = head;
    if (this->isEmpty()) {
        Node* temp = new Node(val, nullptr);
        head = temp;
        return;
    }
    if (head->val > val){
        Node* temp = new Node(val, head);
        head = temp;
        return;
    }
    while (temp_ptr->next != nullptr)
    {
        if (temp_ptr->next->val <= val){
            temp_ptr = temp_ptr->next;
        }
        else {
            Node* temp = new Node(val, temp_ptr->next);
            temp_ptr->next = temp;
            return;
        }
    }
    Node* temp = new Node(val, nullptr);
    temp_ptr->next = temp;
}
void queueR::pop(){
    if(this->isEmpty()){
        throw;
    }
    Node* temp = head;
    head = head->next;
    delete temp;


}
bool queueR::isEmpty() const{
    return (head == nullptr);
}
const int& queueR::top() const{
    return head->queueR::Node::val;
}


