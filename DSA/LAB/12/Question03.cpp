#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

void findAnagramsRabinKarp(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();
    
    if (m > n) return;

    unordered_map<char, int> patternCount, windowCount;

    for (char c : pattern) {
        patternCount[c]++;
    }

    for (int i = 0; i < m; i++) {
        windowCount[text[i]]++;
    }

    vector<int> result;

    if (patternCount == windowCount) {
        result.push_back(0);
    }

    for (int i = m; i < n; i++) {
        windowCount[text[i]]++;
        windowCount[text[i - m]]--;

        if (windowCount[text[i - m]] == 0) {
            windowCount.erase(text[i - m]);
        }

        if (patternCount == windowCount) {
            result.push_back(i - m + 1);
        }
    }

    for (int index : result) {
        cout << index << " ";
    }
}

int main() {
    string text = "BACDGABCDA";
    string pattern = "ABCD";

    findAnagramsRabinKarp(text, pattern);

    return 0;
}