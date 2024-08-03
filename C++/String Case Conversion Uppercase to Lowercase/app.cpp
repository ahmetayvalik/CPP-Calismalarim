#include <iostream>
#include <cctype> 

using namespace std;

int main() {
    string metin;

 
    cout << "Lutfen bir metin girin: ";
    getline(cin, metin);

   
    int i = 0;

   
    while (i < metin.size()) {
  
        if (isupper(metin[i])) {
            metin[i] = tolower(metin[i]);
        }
        
        i++;
    }

    cout << "Metinin kucuk harf hali: " << metin << endl;

    return 0;
}