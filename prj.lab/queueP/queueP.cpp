#include <sstream>
#include <iostream>
#include <queueP/queueP.h>

queueP::queueP() 
    :   head(nullptr)
    {}


queueP::~queueP()
{
    while (!this->isEmpty())
    {
        this->pop();
    }
    
}
queueP& queueP::operator=(const queueP& rhs)
{
    if (this != &rhs){
        queueP temp = rhs;
        head = temp.head;
    }
    return *this;
}
void queueP::push(const int& val){
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
void queueP::pop(){
    if(this->isEmpty()){
        throw;
    }
    Node* temp = head;
    head = head->next;
    delete temp;


}
bool queueP::isEmpty() const{
    return (head == nullptr);
}
const int& queueP::top() const{
    return head->queueP::Node::val;
}


