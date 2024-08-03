#include <iostream>
#include <string>

using namespace std;

int main() {
    string metin, kelime;

    cout << "Lutfen bir metin girin: ";
    getline(cin, metin);
    cout << "Aranacak kelimeyi girin: ";
    cin >> kelime;


    int kelimeSayisi = 0;


    for (size_t i = 0; i < metin.size(); ++i) {
       
        if (metin.substr(i, kelime.size()) == kelime) {
            kelimeSayisi++; 
        }
    }

    cout << "Metinde \"" << kelime << "\" kelimesi " << kelimeSayisi << " kez geciyor." << endl;

    return 0;
}