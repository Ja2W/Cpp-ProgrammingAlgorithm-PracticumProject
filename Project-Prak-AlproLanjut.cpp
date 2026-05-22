#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;



// Function Helper Garis & Judul
void garis() {
    cout << "--------------------------------------------" << endl;
}

void judul(string teksjudul) {
    cout << "===============[" << teksjudul << "]===============" << endl;
}

void jeda() {
    cout << endl << "  Tekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void namaKelompok(){
    system("cls");
    cout << "\n\n\t================================================" << endl;
    cout << "\t|                                              |" << endl;
    cout << "\t|            KELOMPOK 8 - PLUG IF-E            |" << endl;
    cout << "\t|  1. Juan Andre Wicaksono Wibowo (123250111)  |" << endl;
    cout << "\t|  2. Gega Ramadhan               (123250112)  |" << endl;
    cout << "\t|                                              |" << endl;
    cout << "\t|                    PROGRAM                   |" << endl;
    cout << "\t|        Pengelolaan Keuangan Mahasiswa        |" << endl;
    cout << "\t|                                              |" << endl;
    cout << "\t================================================\n\n" << endl;
}

// Function Sub-Menu
void inputTransaksi() {

    namaKelompok();
    judul("INPUT TRANSAKSI BARU");


    jeda();
}

void tampilSemua() {

    namaKelompok();
    judul("DAFTAR TRANSAKSI");


    jeda();
}

void cariTransaksi(){

    namaKelompok();
    judul("CARI TRANSAKSI");


    jeda();
}

void urutkanTransaksi(){

    namaKelompok();
    judul("URUTKAN TRANSAKSI");


    jeda();
}

void analisisPengeluaran(){

    namaKelompok();
    judul("ANALISIS PENGELUARAN");


    jeda();
}

void simpanFile(){

    namaKelompok();
    judul("SIMPAN KE FILE");


    jeda();
}

void loadFile(){

    namaKelompok();
    judul("LOAD DARI FILE");


    jeda();
}


// Function Utama
int main() {
    int pilih;

    do {
        system("CLS");

        namaKelompok();
        judul("PROGRAM PENGELOLAAN PENGELUARAN MAHASISWA");

        cout << "  1. Input Transaksi" << endl;
        cout << "  2. Tampil Semua Transaksi" << endl;
        cout << "  3. Cari Transaksi" << endl;
        cout << "  4. Urutkan Transaksi" << endl;
        cout << "  5. Analisis Pengeluaran" << endl;
        cout << "  6. Simpan ke File" << endl;
        cout << "  7. Load dari File" << endl;
        cout << "  0. Keluar" << endl;
        cout << "--------------------------------------------" << endl;
        cout << "  Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1: inputTransaksi();      break;
            case 2: tampilSemua();         break;
            case 3: cariTransaksi();       break;
            case 4: urutkanTransaksi();    break;
            case 5: analisisPengeluaran(); break;
            case 6: simpanFile();          break;
            case 7: loadFile();            break;
            case 0: 
                system("cls");
                cout << "  Sampai jumpa!" << endl; 
                break;
            default:
                cout << "  Pilihan tidak valid!" << endl;
                jeda();
        }

    } while (pilih != 0);

    return 0;
}