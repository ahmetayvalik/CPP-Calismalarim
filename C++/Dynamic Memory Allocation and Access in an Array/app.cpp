#include <iostream>

using namespace std;

int main() {
    int* bellekPtr; 

    int sayi;
    cout << "Bellek tahsis etmek icin bir tamsayi girin: ";
    cin >> sayi;

   
    bellekPtr = new int[sayi]; 

    
    cout << "Bellek adresi: " << bellekPtr << endl;
    cout << "Ilk deger: " << bellekPtr[0] << endl;

    int* sonPtr = bellekPtr + sayi - 1;

    
    cout << "Son deger: " << *sonPtr << endl;

 
    delete[] bellekPtr;

    return 0;
}