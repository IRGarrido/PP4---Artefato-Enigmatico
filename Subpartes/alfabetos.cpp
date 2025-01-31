#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<string> alfabetoArtefato = {":::", ".::", ":.:", "::.", ":..", ".:.", "..:", "...", "|::", ":|:", "::|", "|.:", ".|:", ".:|", "|:.", ":|.", ":.|", "|..", ".|.", "..|", ".||", "|.|", "||.", "-.-", ".--", "--.", "---", "~~~"};
    vector<char> alfabetoLatim = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' ', '.'};

    for(int i = 0; i < 28; ++i) {
        cout << alfabetoArtefato[i] << " = " << alfabetoLatim[i] << endl;
    }
    return 0;
}