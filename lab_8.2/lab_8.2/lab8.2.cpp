#include <iostream>
#include <string>
#include <cctype>

using namespace std;
/*
abc.99xyz
a.1234bcd.5678ef
*/
int findMin(const string& str) {
    int minCount = INT_MAX, count = 0;
    bool isDigitSeq = false;

    for (char ch : str) {
        if (isdigit(ch)) {
            count++;
            isDigitSeq = true;
        }
        else {
            if (isDigitSeq) {
                minCount = min(minCount, count);
                count = 0;
            }
            isDigitSeq = false;
        }
    }
    if (isDigitSeq) minCount = min(minCount, count);
    return minCount == INT_MAX ? 0 : minCount;
}

string round(const string& str) {
    string result;
    bool afterDot = false;
    int digitCount = 0;

    for (size_t i = 0; i < str.length(); i++) {
        if (str[i] == '.') {
            afterDot = true;
            digitCount = 0;
            result += str[i];
        }
        else if (afterDot && isdigit(str[i])) {
            digitCount++;
            if (digitCount <= 2) result += str[i];
        }
        else {
            afterDot = false;
            result += str[i];
        }
    }
    return result;
}

int main() {
    string str;
    cout << "Enter string:" << endl;
    getline(cin, str);

    int minDigits = findMin(str);
    cout << "Minimum consecutive digits: " << minDigits << endl;

    string roundedStr = round(str);
    cout << "Formatted string: " << roundedStr << endl;

    return 0;
}
