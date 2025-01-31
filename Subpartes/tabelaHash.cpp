#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Hash {
    private:
    list<pair<string,char>>* hashTable;
    vector<string> artefactAlphabet = {":::", ".::", ":.:", "::.", ":..", ".:.", "..:", "...", "|::", ":|:", "::|", "|.:", ".|:", ".:|", "|:.", ":|.", ":.|", "|..", ".|.", "..|", ".||", "|.|", "||.", "-.-", ".--", "--.", "---", "~~~"};
    vector<char> latimAlphabet = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.'};
public:
    Hash();
    ~Hash();
    int calculateHash(string);
    void insert(string,char latim);
    char search(string);
};
Hash::Hash() {
    hashTable = new list<pair<string, char>>[11];
    for (int i=0; i<28; ++i) {
        insert(artefactAlphabet[i], latimAlphabet[i]);
    }    

    for(int i = 0; i < 11; ++ i) {
            cout << "\n Casa " << i;
        for(auto par: hashTable[i]) {
            cout << par.second << " ";
        }
    }
}

Hash::~Hash() {
    delete[] hashTable;
}

int Hash::calculateHash(string symbols) {
    int valor=0;
    for (int i = 0; i < 3; ++i) {
        int x = int(symbols[i]);
        int aux = x;
        for(int j=0; j<2-i;++j) {
            aux*=5;
        }
        valor+=aux;
    }
    return valor;
}

void Hash::insert(string symbols,char latim) {
    int position = calculateHash(symbols)%11;
    hashTable[position].push_back(std::make_pair(symbols, latim)); 
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
}
int main() {
    Hash table;
    cout << "inicio" << endl;

    cout << table.search(":|.");
    cout << table.search(":..");
    cout << table.search("::.");
    cout << table.search("|..");
    cout << table.search("|:.");
    cout << table.search("|.|");
    cout << table.search("---");
    cout << table.search(".::");
    cout << table.search("|:.");
    cout << table.search(".::");
    cout << table.search(":::");
    cout << table.search("|:.");
    cout << table.search("~~~");
    cout << table.search("||.");
    cout << "\nfim" << endl;


    return 0;
}