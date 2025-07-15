#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK = 5;

// Stack untuk menyimpan status sebelumnya
string undoStack[MAX_STACK];
int top = -1;

// Teks yang sedang ditampilkan
string currentText = "";

// Cek apakah stack kosong
bool isEmpty() {
    return top == -1;
}

// Cek apakah stack penuh
bool isFull() {
    return top == MAX_STACK - 1;
}

// Simpan teks ke stack sebelum diubah
void pushUndo(string text) {
    if (isFull()) {
        cout << "Stack overflow!\n";
        return;
    }
    undoStack[++top] = text;
}

// Kembalikan teks ke kondisi sebelum perubahan
void undo() {
    if (isEmpty()) {
        cout << "Tidak ada yang bisa di-undo!\n";
    } else {
        currentText = undoStack[top--];
        cout << "Undo berhasil.\n";
    }
}

// Tampilkan teks saat ini
void printText() {
    cout << "Teks saat ini: " << currentText << endl;
}

int main() {
    int pilihan;
    string input;

    // Tampilan Menu 
    cout << "===============================";
    cout << "\nNama = RAAFI PRAWIRA SETIAMUDO";
    cout << "\nNIM  = 32602400100";
    cout << "\n===============================\n";
    cout << "Menu Aplikasi Teks :\n";
    cout << "1. Ketik\n";
    cout << "2. Undo\n";
    cout << "3. Tampilkan teks saat ini\n";
    cout << "4. Keluar\n";

    while (true) {
        cout << "\nPilihan : ";
        cin >> pilihan;
        cin.ignore();  

        switch (pilihan) {
            case 1:
                cout << "Masukkan teks: ";
                getline(cin, input);
                pushUndo(currentText);
                currentText += input;
                break;
            case 2:
                undo();
                break;
            case 3:
                printText();
                break;
            case 4:
                cout << "Terima kasih. Program selesai.\n";
                return 0;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    }
}
