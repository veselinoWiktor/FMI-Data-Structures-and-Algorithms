#include <iostream>
#include <set>

using namespace std;

int lengthOfLongestSubstring(string s) {
    int n = s.length();
    size_t maxLength = 0;
    set<char> charSet;
    int beg = 0;

    for (int i = 0; i < n; i++) {
        if (charSet.count(s[i]) == 0) {
            charSet.insert(s[i]);
            maxLength = max(maxLength, charSet.size());
        } else {
            while (s[beg] != s[i]) {
                charSet.erase(s[beg]);
                beg++;
            }
            beg++; // Move past the duplicate character
            charSet.erase(s[beg - 1]); // Remove the duplicate character from the set
            charSet.insert(s[i]); // Insert the current character
        }
    }

    return maxLength;
}

int main()
{
    std::cout << lengthOfLongestSubstring("aabaab!bb") << std::endl; // 3
}