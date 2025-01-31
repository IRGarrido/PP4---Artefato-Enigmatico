#include<iostream>
#include <list>
#include<vector>

using namespace std;

typedef unsigned int uint;

class BoyerMoore {
private:
    string text;
    string pattern;
    vector<char> latinAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.'};
    int* table;
    
public:
    BoyerMoore(string, string);
    ~BoyerMoore();
    void setTable();
};

BoyerMoore::BoyerMoore(string text, string pattern): text(text), pattern(pattern) {
    setTable();
    int step = 0;
    uint N = text.size();
    uint M = pattern.size();
    for(uint i = 0; i <= N - M; i += step) {
        // cout << "i: " << i << endl;
        step = 0;
        for(int j = M - 1; j >= 0; --j) {
            // cout << "j: " << j << endl;
            // cout << "texto: " << text[i+j] << endl;
            // cout << "padrao: " << pattern[j] << endl;
            if(pattern[j] != text[i+j]) {
                step = j - table[int(text[i+j]) - 65];
                if(step < 1 ) step = 1;
                break;
            }
        }
        if(step == 0) {
            cout << " (" << i << ")";
            step = 1;
        }
        cout << " "  << step;
    }
};

BoyerMoore::~BoyerMoore() {
    delete[] table;
};

void BoyerMoore::setTable() {
    table = new int[latinAlphabet.size()];
    for(uint i = 0; i < latinAlphabet.size(); ++i) {
        table[i] = -1;
    }
    for(uint j = 0; j < pattern.size(); ++j) {
        table[int(pattern[j]) - 65] = j;
    }
};

int main() {
    string teste = "OROBONAOROUBAROBE";
    string padrao = "ROBE";

    BoyerMoore(teste, padrao);

    return 0;
}