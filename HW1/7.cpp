
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, count = 0, total = 0;
    cout << "Enter the number of problems: ";
    cin >> N;
    vector<int> grades(N);
    cout << "Enter the grades: ";
    for (int i = 0; i < N; ++i) {
        cin >> grades[i];
        if (grades[i] > 2) count++;
        total += grades[i];
    }
    if (count < N / 2) {
        cout << "Final grade: 2" << endl;
    } else {
        cout << "Final grade: " << total / N << endl;
    }
    return 0;
}
