#include<iostream>
#include <list>
#include<vector>

using namespace std;

typedef unsigned int uint;

class Hash {
private:
    list<pair<string,char>>* hashTable;
    vector<string> artefactAlphabet = {":::", ".::", ":.:", "::.", ":..", ".:.", "..:", "...", "|::", ":|:", "::|", "|.:", ".|:", ".:|", "|:.", ":|.", ":.|", "|..", ".|.", "..|", ".||", "|.|", "||.", "-.-", ".--", "--.", "---", "~~~"};
    vector<char> latinAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.'};
public:
    Hash();
    ~Hash();
    int calculateHash(string);
    void insert(string,char latin);
    char search(string);
};

Hash::Hash() {
    hashTable = new list<pair<string, char>>[11];
    for (int i=0; i<28; ++i) {
        insert(artefactAlphabet[i], latinAlphabet[i]);
    }
}

Hash::~Hash() {
    delete[] hashTable;
}

int Hash::calculateHash(string symbols) {
    int value = 0;
    for (int i = 0; i < 3; ++i) {
        int x = int(symbols[i]);
        int aux = x;
        for(int j = 0; j<2-i; ++j) {
            aux *= 5;
        }
        value += aux;
    }
    return value;
}

void Hash::insert(string symbols,char latin) {
    int position = calculateHash(symbols)%11;
    hashTable[position].push_back(std::make_pair(symbols, latin));
}

char Hash::search(string symbols) {
    int position = calculateHash(symbols)%11;
    list<pair<string, char> >::iterator it = hashTable[position].begin();
    while (it != hashTable[position].end()) {
        if(it->first == symbols) {
            return it->second;
        }
        it++;
    }
    return '#';
}

 string upper(string codedString) {
    string newString;
    for(uint i = 0; i < codedString.size(); ++i) {
        if((int(codedString[i]) <= 122) && (int(codedString[i]) >= 97)) {
            char newChar = char(int(codedString[i]) - 32);
            newString.push_back(newChar);
        } else {
            newString.push_back(codedString[i]);
        }
    }
    return newString;
};

string cipher(string codedString) {
    int key = 0;
    while(codedString[0] != 'M') {
        if (int(codedString[0]) == 65) {
            codedString[0] = char(90);
            key++;
        }
        else {
            codedString[0] = char(int(codedString[0]) - 1);
            key++;
        }
    }
    for(uint i = 1; i <= codedString.size(); ++i) {
        if(int(codedString[i]) != 46 && int(codedString[i])!=32) {
            int j;
            if (int(codedString[i]) - key < 65) {
                j = key - int(codedString[i]) + 64;
                codedString[i] = char(90) - j;
            }
            else {
                codedString[i] = char(int(codedString[i]) - key);
            }
        }
    }
    return codedString;
}

int main(){
    Hash dictionary;

    string input;
    cin >> input;

    string translatedInput = "";

    for(uint i = 0; i < input.size() - 1; i += 3){
        char c1, c2, c3;
        c1 = input[i];
        c2 = input[i+1];
        c3 = input[i+2];

        string symbol = string(1,c1)+c2+c3;

        translatedInput += dictionary.search(symbol);
    }

    while((input != "fim")&&(input != "FIM")) {
        cin >> input;
        cout << upper(input) << endl;
    }

    cout << cipher(translatedInput);

    return 0;
}