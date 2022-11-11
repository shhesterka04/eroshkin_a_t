#include <sstream>
#include <iostream>

#include <queueP/queueP.h>

queueP::queueP() 
    :   head(nullptr)
    {}


queueP::~queueP()
{}
queueP& queueP::operator=(const queueP& rhs)
{}
void queueP::push(const int& val)
{}
void queueP::pop()
{}
bool queueP::isEmpty() const
{}
const int& queueP::top() const
{}


