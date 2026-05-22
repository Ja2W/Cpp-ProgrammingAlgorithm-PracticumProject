/*
==========================================================
   SISTEM PENCATAT PENGELUARAN MAHASISWA
   Materi: Struct, Array, Pointer, Searching,
           Sorting (Bubble Sort), Rekursi, File I/O
==========================================================
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

//===================== STRUCT ======================== //baru ditambah
struct Transaksi{
    string barang;
    string tanggal;
    string kategori;
    int harga;
};

// ================ VARIABEL GLOBAL ==================== //baru ditambah
const int MAKS = 100;
Transaksi daftar[MAKS]; //Menambahkan array of struct
int jumlah = 0;

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
    system("cls");
    namaKelompok();
    judul("INPUT TRANSAKSI BARU");

    if (jumlah >= MAKS) { //baru ditambah
        cout << "Data sudah penuh!" << endl;
    jeda();
    return;
    }
    // Menggunakan Pointer ke array
    Transaksi* t = &daftar[jumlah];
    cout << "    Nama barang    : "; cin >> t->barang;
    cout << "    Tanggal        : "; cin >> t->tanggal;
    cout << "    Harga(Rp)      : "; cin >> t->harga;

    cout << endl;
    cout << "  Kategori:" << endl;
    cout << "  1. Makanan" << endl;
    cout << "  2. Transport" << endl;
    cout << "  3. Kuliah" << endl;
    cout << "  4. Hiburan" << endl;
    cout << "  Pilih: ";
    int pilihKat;
    cin >> pilihKat;

    if      (pilihKat == 1) t->kategori = "Makanan";
    else if (pilihKat == 2) t->kategori = "Transport";
    else if (pilihKat == 3) t->kategori = "Kuliah";
    else if (pilihKat == 4) t->kategori = "Hiburan";
    else                    t->kategori = "Lainnya";

    jumlah++;
    cout << endl << "  [OK] Transaksi berhasil disimpan!" << endl;
    jeda();
}

// ================ TAMPIL SEMUA =======================
void tampilSemua() { //baru ditambah
    system("cls");
    namaKelompok();
    judul("DAFTAR TRANSAKSI");

    if (jumlah == 0) {
        cout << "Belum ada data!" << endl;
        jeda();
        return;
    }
    cout << "  No  Barang         Tanggal    Kategori     Harga" << endl;
    garis();
    Transaksi* ptr = daftar;
    for (int i = 0; i < jumlah; i++) {
        cout << "  " << i + 1 << ".  ";
        cout << ptr[i].barang    << "\t";
        cout << ptr[i].tanggal   << "\t";
        cout << ptr[i].kategori  << "\t";
        cout << "Rp " << ptr[i].harga << endl;
    }
    garis();
    // Hitung total dengan fungsi rekursif
    int total = totalRekursif(daftar, 0);
    cout << "  TOTAL PENGELUARAN : Rp " << total << endl;
    garis();
    jeda();
}

//================ SEARCHING ========================== //baru ditambah
void cariTransaksi(){
    system("cls");
    namaKelompok();
    judul("CARI TRANSAKSI");

    cout << "  Cari berdasarkan:" << endl;
    cout << "  1. Nama Barang" << endl;
    cout << "  2. Tanggal" << endl;
    cout << "  Pilih: ";
    int opt;
    cin >> opt;

    cout << "  Kata kunci: ";
    string kunci;
    cin >> kunci;

    cout << endl;
    garis();
    bool ketemu = false;

    for (int i = 0; i < jumlah; i++) {
        // Pointer ke elemen ke-i
        Transaksi* p = &daftar[i];

        // Cek apakah kunci cocok
        string target = (opt == 1) ? p->barang : p->tanggal;
        if (target == kunci) {
            cout << "  Barang   : " << p->barang   << endl;
            cout << "  Tanggal  : " << p->tanggal  << endl;
            cout << "  Kategori : " << p->kategori << endl;
            cout << "  Harga    : Rp " << p->harga << endl;
            garis();
            ketemu = true;
        }
    }
    if (!ketemu) cout << "  Data tidak ditemukan." << endl;
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
