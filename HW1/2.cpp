
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) cin >> arr[i];
    reverse(arr.begin(), arr.end());
    cout << "Reversed array: ";
    for (int num : arr) cout << num << " ";
    cout << endl;
    return 0;
}
