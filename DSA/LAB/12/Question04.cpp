#include <iostream>
#include <string>
#include <vector>
#include <climits>
using namespace std;

void findClosestMatch(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    
    if (m > n) return;

    int minMismatches = INT_MAX;
    int bestIndex = -1;

    for (int i = 0; i <= n - m; i++) {
        int mismatches = 0;

        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                mismatches++;
            }
        }

        if (mismatches < minMismatches) {
            minMismatches = mismatches;
            bestIndex = i;
        }
    }

    if (bestIndex != -1) {
        cout << "Closest match at index " << bestIndex << " with " << minMismatches << " mismatch" << (minMismatches > 1 ? "es." : ".") << endl;
    } else {
        cout << "No match found." << endl;
    }
}

int main() {
    string text = "ABCDEFGH";
    string pattern = "BCDZ";

    findClosestMatch(text, pattern);

    return 0;
}