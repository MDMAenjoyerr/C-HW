
#include <iostream>
#include <string>
using namespace std;

string compress(string s) {
    string result = "";
    int count = 1;
    for (size_t i = 1; i <= s.size(); ++i) {
        if (i < s.size() && s[i] == s[i - 1]) {
            count++;
        } else {
            result += s[i - 1];
            if (count > 1) result += to_string(count);
            count = 1;
        }
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;
    cout << "Compressed string: " << compress(input) << endl;
    return 0;
}
