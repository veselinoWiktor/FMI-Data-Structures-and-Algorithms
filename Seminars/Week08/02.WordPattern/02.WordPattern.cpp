#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

bool wordPattern(string pattern, string s) {
    unordered_map<char, string> sym_Word;
    unordered_set<string> mappedWords;

    stringstream st(s);
    string word;
    int CurSymPos = 0;

    while (st >> word) {
        char curSym = pattern[CurSymPos];
        if (sym_Word.find(curSym) != sym_Word.end()) {
            if (sym_Word[curSym] != word) {
                return false;
            }
        }
        else {
            if (mappedWords.find(word) != mappedWords.end()) {
                return false;
            }
            sym_Word[curSym] = word;
            mappedWords.insert(word);
        }
        CurSymPos++;
    }

    if (CurSymPos != pattern.length()) return false;
    return true;

    return true;
}

int main()
{
    std::cout << "Hello World!\n";
}