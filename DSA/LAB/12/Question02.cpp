#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> computePrefixFunction(const string &pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int j = 0;

    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j] && pattern[j] != '?') {
            j = lps[j - 1];
        }
        if (pattern[i] == pattern[j] || pattern[j] == '?') {
            j++;
        }
        lps[i] = j;
    }
    return lps;
}

void kmpSearchWithWildcard(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    vector<int> lps = computePrefixFunction(pattern);
    
    int i = 0;
    int j = 0;
    
    while (i < n) {
        if (j < m && (text[i] == pattern[j] || pattern[j] == '?')) {
            i++;
            j++;
        }
        
        if (j == m) {
            cout << "Match found at index " << i - j << endl;
            j = lps[j - 1];
        } else if (i < n && (text[i] != pattern[j] && pattern[j] != '?')) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

int main() {
    string text = "ABCD";
    string pattern = "A?C";

    kmpSearchWithWildcard(text, pattern);

    return 0;
}