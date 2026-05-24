#include <iostream>
#include <fstream>
using namespace std;

// Struct
    struct Transaksi{
        string barang;
        string tanggal;
        string kategori;
        int harga;
    };

// Variabel Global
    const int MAKS = 100;
    Transaksi daftar[MAKS];
    int jumlah_data = 0;

// Function Helper Garis, Judul, Jeda, dan Nama Kelompok
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

    void garis() {
        cout << "----------------------------------------------" << endl;
    }

    void judul(string teksjudul) {
        namaKelompok();
        cout << "\n===============[" << teksjudul << "]===============" << endl;
    }

    void jeda() {
        cout << endl << "\n\tTekan [ENTER] untuk kembali...";
        cin.get();
    }


// Function Validasi


// Function Sub-Menu
void inputTransaksi() {
    
    judul("INPUT TRANSAKSI BARU");

    if (jumlah_data >= MAKS) {
        cout << "\n\t[!] DATA SUDAH PENUH" << endl;
        jeda();
        return;
    }

    // Menggunakan Pointer ke array
    Transaksi* t = &daftar[jumlah_data];
    cout << "\n [1] Nama barang       : "; 
    getline(cin,t->barang);
    
    cout << " [2] Tanggal [DD-MM-YYY] : "; 
    getline(cin,t->tanggal);

    cout << " [3] Harga (Rp)          : "; 
    cin >> t->harga;
    cin.ignore();

    cout << endl;
    cout << "[4] Kategori:" << endl;
    cout << "    =====================" << endl;
    cout << "    | 1. Makanan        |" << endl;
    cout << "    | 2. Transport      |" << endl;
    cout << "    | 3. Kuliah         |" << endl;
    cout << "    | 4. Hiburan        |" << endl;
    cout << "    =====================" << endl;
    cout << "    Pilih [1-4]          : ";
    int pilihKategori;
    cin >> pilihKategori;

    if (pilihKategori == 1){
        t->kategori = "Makanan";
    } else if(pilihKategori == 2){
        t->kategori = "Transport";
    } else if(pilihKategori == 3){
        t->kategori = "Kuliah";
    } else if(pilihKategori == 4){
        t->kategori = "Hiburan";
    } else {
        t->kategori = "Lainnya";
    }
    
    jumlah_data++;
    cout << endl << "\n\t[SUKSES] Transaksi berhasil disimpan!" << endl;
    jeda();
}

void tampilSemua() {
    
    judul("DAFTAR TRANSAKSI");
    if (jumlah_data == 0) {
        cout << "[!] BELUM ADA DATA - Input terlebih dulu..." << endl;
        jeda();
        return;
    }

    garis();
    Transaksi* ptr = daftar;
    for (int i = 0; i < jumlah_data; i++) {
        cout << "\n[BARANG "  << i+1 << "]--------------------" << endl;
        cout << ptr[i].barang    << "\t";
        cout << ptr[i].tanggal   << "\t";
        cout << ptr[i].kategori  << "\t";
        cout << "Rp " << ptr[i].harga << endl;
    }
    cout << "\n------------------------------" << endl;
    garis();

    // Hitung total dengan fungsi rekursif
    // int total = totalRekursif(daftar, 0);
    // cout << "  TOTAL PENGELUARAN : Rp " << total << endl;
    jeda();
}

void cariTransaksi(){
    
    judul("CARI TRANSAKSI");
    if (jumlah_data == 0) {
        cout << "[!] BELUM ADA DATA - Input terlebih dulu..." << endl;
        jeda();
        return;
    }

    cout << "  Cari berdasarkan:" << endl;
    cout << "  1. Nama Barang" << endl;
    cout << "  2. Tanggal" << endl;
    cout << "  Pilih: ";
    int pilihan;
    cin >> pilihan;

    cout << "  Kata kunci: ";
    string kataDicari;
    cin >> kataDicari;

    cout << endl;
    garis();
    bool ketemu = false;

    for (int i = 0; i < jumlah_data; i++) {
        // Pointer ke elemen ke-i
        Transaksi* p = &daftar[i];

        // Cek apakah kataDicari cocok
        string target = (pilihan == 1) ? p->barang : p->tanggal;
        if (target == kataDicari) {
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
    
    judul("URUTKAN TRANSAKSI");


    jeda();
}

void analisisPengeluaran(){
    
    judul("ANALISIS PENGELUARAN");


    jeda();
}

void simpanFile(){
    
    judul("SIMPAN KE FILE");


    jeda();
}

void loadFile(){

    judul("LOAD DARI FILE");


    jeda();
}


// Function Utama
int main() {
    system("color 03");
    int pilih;

    do {
        
        judul("PROGRAM PENGELOLAAN PENGELUARAN MAHASISWA");

        cout << "  [1] Input Transaksi" << endl;
        cout << "  [2] Tampil Semua Transaksi" << endl;
        cout << "  [3] Cari Transaksi" << endl;
        cout << "  [4] Urutkan Transaksi" << endl;
        cout << "  [5] Analisis Pengeluaran" << endl;
        cout << "  [6] Simpan ke File" << endl;
        cout << "  [7] Load dari File" << endl;
        cout << "  [0] Keluar" << endl;
        garis();
        cout << "  Pilih menu [1-9]: ";
        cin >> pilih;

        switch (pilih) {
            case 1: inputTransaksi();      
                break;
            case 2: tampilSemua();         
                break;
            case 3: cariTransaksi();       
                break;
            case 4: urutkanTransaksi();    
                break;
            case 5: analisisPengeluaran(); 
                break;
            case 6: simpanFile();          
                break;
            case 7: loadFile();            
                break;
            case 0: 
                cout << "\n\t[END] SAMPAI JUMPA!" << endl; 
                break;
            default:
                cout << "\n\t[!] Pilihan tidak valid!" << endl;
                jeda();
        }
    } while (pilih != 0);

    return 0;
}
