#include <iostream>
#include <queueP/queueP.h>

int main(){
    queueR a = queueR();
    a.push(3);
    a.push(2);
    a.pop();
    if (a.isEmpty()){
        std::cout << "Queue is Empty! \n";
    }
    else{
        std::cout << "Queue is NOT Empty! \n";
    }

    std::cout << a.top();
    return 0;
}