#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    int k = 0;
    int f = 0;
    int t = 0;
    std::cin >> n >> k;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> f >> t;
        if (k >= t) {
            v[i] = f;
        }
        else
        {
            v[i] = f - (t - k);
        }
    }
    int max = v[0];
    for (int i = 1; i < n; i++) {
        if (max < v[i]) {
            max = v[i];
        }
    }
    std::cout << max;
    return 0;
}

