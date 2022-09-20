#include <iostream>

int main()
{
    int a = 0;
    int n = 0;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a;
        if (a % 2 == 0) {
            a -= 1; // Если число нечетное, оно станет четным, а потом снова нечетным.
            //Если четное, то станет нечетным
        }
        std::cout << a << " ";
    }
}

