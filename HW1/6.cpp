
#include <iostream>
using namespace std;

bool hasSum15(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum == 15;
}

int main() {
    for (int i = 1000; i <= 9999; ++i) {
        if (hasSum15(i)) cout << i << endl;
    }
    return 0;
}
