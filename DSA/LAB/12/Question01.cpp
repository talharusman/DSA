#include <iostream>
#include <string>
using namespace std;

int naivePatternSearchReverse(const string &text, const string &pattern) {
    int textLength = text.length();
    int patternLength = pattern.length();

    // Loop through the text
    for (int i = 0; i <= textLength - patternLength; i++) {
        int j;
        // Start comparing from the end of the pattern
        for (j = patternLength - 1; j >= 0; j--) {
            if (text[i + j] != pattern[j]) {
                break; // Mismatch found
            }
        }
        if (j < 0) {
            return i + pattern.size(); // Pattern found, return the starting index
        }
    }
    return -1; // Pattern not found
}

int main() {
    string text = "ABCDBACD"; // Original text to search within
    string pattern = "ABC";    // Pattern to find

    // Search for the pattern in the text
    int index = naivePatternSearchReverse(text, pattern);

    if (index != -1) {
        cout << "Reverse of pattern \"" << pattern << "\" found at index " << index << endl;
    } else {
        cout << "Reverse of pattern \"" << pattern << "\" not found in the text." << endl;
    }

    return 0;
}