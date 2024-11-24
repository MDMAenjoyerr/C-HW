
#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

unordered_map<char, string> morse = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"}, {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."}
};

string toMorse(string text) {
    string result = "";
    for (char c : text) {
        if (c >= 'a' && c <= 'z') c -= 32;
        if (morse.count(c)) result += morse[c] + " ";
    }
    return result;
}

int main() {
    string text;
    cout << "Enter text: ";
    getline(cin, text);
    cout << "Morse Code: " << toMorse(text) << endl;
    return 0;
}
