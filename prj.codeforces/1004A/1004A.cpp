#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    int d = 0;
    int ans = 2; // Слева от самого левого города всегда можно построить город. Также с самым правым
    std::cin >> n >> d;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    
    for (int i = 0; i < n - 1; i++) {
        if ((v[i + 1] - v[i]) == 2 * d) {
            ans += 1;
        }
        else if ((v[i + 1] - v[i]) > 2 * d) {
            ans += 2;
        }
    }
    std::cout << ans;
}
