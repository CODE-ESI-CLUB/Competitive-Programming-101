#include <iostream>
#include <string>
using namespace std;

int countPairs(string s) {
    int pairs = 0;
    for (int i = 0; i < s.length() - 1; i++)
        if ((s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'y') 
            && s[i] == s[i + 1])
            pairs++, i++;
    return pairs;
}

int main() {
    int n;
    while (cin >> n && n) {
        string word, best;
        int maxPairs = -1;
        
        while (n--) {
            cin >> word;
            int pairs = countPairs(word);
            if (pairs > maxPairs) {
                maxPairs = pairs;
                best = word;
            }
        }
        cout << best << '\n';
    }
}