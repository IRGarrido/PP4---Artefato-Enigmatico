#include<iostream>
#include <list>
#include<vector>

using namespace std;

typedef unsigned int uint;

uint getValue(char symbol) {
    if((int(symbol) >= 65) && (int(symbol) <= 90)) {
        return (int(symbol) - 65);
    }
    if(int(symbol) == 32) {
        return 26;
    }
    if(int(symbol) == 46) {
        return 27;
    }
    return 28;
};
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
                step = j - table[getValue(text[i+j])];
                if(step < 1 ) step = 1;
                break;
            }
        }
        cout << " "  << step;
        if(step == 0) {
            cout << " (" << i << ")";
            step = 1;
        }
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
        table[getValue(pattern[j])] = j;
    }
};


int main() {
    string teste = "O ROBO NAO ROUBA ROBE O ROBE";
    string padrao = "ROBE";

    BoyerMoore(teste, padrao);

    return 0;
}