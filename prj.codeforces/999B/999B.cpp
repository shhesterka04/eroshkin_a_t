#include <iostream>
#include <string>

int main()
{
    int n = 0;
    std::string str = "";
    std::cin >> n >> str;
    for (int i = 2; i <= n; i+=1) {
        if (n % i == 0) {
            for (int j = 0; j < i/2; j++) {
                std::swap(str[j], str[i - j - 1]);
            }
        }
    }
    std::cout << str;
}

