#include <iostream>
using namespace std;

int main() {
    int n;

    cout << "masukkan jumlah elemen array : ";
    cin >> n;

    int* arr = new int [n]; //ini yang akan digunakan sebagai dynamic array (yg bisa di kecil besarkan)

    cout << "masukkan " << n << " angka: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "isi array : ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    return 0;
}
