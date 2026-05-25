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
    const int MAX_DATA = 100;
    Transaksi daftar[MAX_DATA];
    int jumlah_data = 0;

// Function Helper (Garis, Judul, Jeda, dan Nama Kelompok)
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
        cout << "\n\tTekan [ENTER] untuk kembali...";
        cin.get();
    }

// Function Rekursi
    int hitungTotalPengeluaran(Transaksi arr[], int indexAwal, int banyak_data){
        if (indexAwal >= banyak_data){
            return 0;
        }

        return arr[indexAwal].harga + hitungTotalPengeluaran(arr, indexAwal + 1, banyak_data);
    }

// Function Sub-Menu
    // Function Input Transaksi
    void inputTransaksi() {
        
        judul("INPUT TRANSAKSI BARU");

        if (jumlah_data >= MAX_DATA) {
            cout << "\n\t[!] DATA SUDAH PENUH" << endl;
            jeda();
            return;
        }

        cout << "\n [1] Nama barang          : "; 
        getline(cin, daftar[jumlah_data].barang);
        
        cout << " [2] Tanggal [YYYY-MM-DD] : "; 
        getline(cin, daftar[jumlah_data].tanggal);

        cout << " [3] Harga (Rp)           : "; 
        int tempHarga;
        
        if (tempHarga < 0){
            cout << "\n\t[!] HARGA TIDAK BOLEH MINUS" << endl;
            jeda();
            return;
        } else {
            cin >> tempHarga;
            cin.ignore();

            daftar[jumlah_data].harga = tempHarga;
        }

        cout << " [4] Kategori             " << endl;
        cout << "     =================" << endl;
        cout << "     | 1. Makanan    |" << endl;
        cout << "     | 2. Transport  |" << endl;
        cout << "     | 3. Kuliah     |" << endl;
        cout << "     | 4. Hiburan    |" << endl;
        cout << "     =================" << endl;
        cout << "     Pilih [1-4]          : ";
        int pilihKategori;
        cin >> pilihKategori;
        cin.ignore();

        if (pilihKategori == 1){
            daftar[jumlah_data].kategori = "Makanan";
        } else if(pilihKategori == 2){
            daftar[jumlah_data].kategori = "Transport";
        } else if(pilihKategori == 3){
            daftar[jumlah_data].kategori = "Kuliah";
        } else if(pilihKategori == 4){
            daftar[jumlah_data].kategori = "Hiburan";
        } else {
            daftar[jumlah_data].kategori = "Lainnya";
        }
        
        if(jumlah_data > MAX_DATA){
            cout << "\n\t[!] DATA SUDAH PENUH!" << endl;
        } else {
            jumlah_data++;
        }
        cout << endl << "\n\t[SUKSES] Transaksi berhasil disimpan!" << endl;
        jeda();
    }

    // Function Tampil Semua Data Transaksi
    void tampilSemua() {
        
        judul("DAFTAR TRANSAKSI");
        if (jumlah_data == 0) {
            cout << "\n\t[!] BELUM ADA DATA - Input terlebih dulu..." << endl;
            jeda();
            return;
        }

        for (int i = 0; i < jumlah_data; i++) {
            cout << "\n [BARANG "  << i+1 << "]-------------------------" << endl;
            cout << "   [1] Nama         : " << daftar[i].barang   << endl;
            cout << "   [2] Tanggal Beli : " << daftar[i].tanggal  << endl;
            cout << "   [3] Kategori     : " << daftar[i].kategori << endl;
            cout << "   [4] Harga (Rp)   : " << daftar[i].harga << endl;
        }
        cout << "\n -----------------------------------" << endl;
        cout << "\n\t[SELESAI] SEMUA DATA TELAH DITAMPILKAN";

        // Hitung total pengeluaran
            int total = hitungTotalPengeluaran(daftar, 0, jumlah_data - 1);
            cout << "\n\n\tTOTAL PENGELUARAN : Rp " << total << endl;
        jeda();
    }

    // Function Searching
    void cariTransaksi(){
        judul("CARI TRANSAKSI");
        if (jumlah_data == 0) {
            cout << "\n\t[!] BELUM ADA DATA - Input terlebih dulu..." << endl;
            jeda();
            return;
        }

        cout << "\n Cari berdasarkan..." << endl;
        cout << " [1] Nama Barang" << endl;
        cout << " [2] Tanggal" << endl;
        cout << " Pilih [1-2] : ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        string kataDicari;
        cout << "\n Masukkan Kata Kunci :";
        getline(cin, kataDicari);

        garis();
        bool found = false;

        for (int i = 0; i < jumlah_data; i++) {

            bool cocok;
            if (pilihan == 1){
                cocok = daftar[i].barang == kataDicari;
            } else if (pilihan == 2){
                cocok = daftar[i].tanggal == kataDicari;
            }

            if (cocok) {
                cout << "\n [BARANG "  << i+1 << "]-------------------------" << endl;
                cout << "   [1] Nama         : " << daftar[i].barang << endl;
                cout << "   [2] Tanggal Beli : " << daftar[i].tanggal << endl;
                cout << "   [3] Kategori     : " << daftar[i].kategori << endl;
                cout << "   [4] Harga (Rp)   : " << daftar[i].harga << endl;
                found = true;
            }
        }

        if (!found){
            cout << "\n\t[!] DATA TIDAK DITEMUKAN" << endl;
            jeda();
            return;
        } else {
            cout << "\n -----------------------------------" << endl;
            cout << "\n\t[SELESAI] SEMUA DATA TELAH DITAMPILKAN" << endl;
        }

        jeda();
    }

    // Function Sorting
    void urutkanTransaksi(){
        judul("URUTKAN TRANSAKSI");
        if (jumlah_data == 0) {
            cout << "\n\t[!] BELUM ADA DATA - Input terlebih dulu..." << endl;
            jeda();
            return;
        }

        cout << "\n Urutkan Berdasarkan : " << endl;
        cout << "   [1] Harga (murah ke mahal)" << endl;
        cout << "   [2] Harga (mahal ke murah)" << endl;
        cout << "   [3] Tanggal (lama ke baru)" << endl;
        cout << "   Pilih [1-3] : ";
        int pilihan;
        cin >> pilihan;
        cin.ignore();

        //Bubble sort 
        int temp;
        for (int i = 0; i < jumlah_data - 1; i++) {\
            for (int j = 0; j < jumlah_data - i - 1; j++){
                bool kondisi = false;

                if (pilihan == 1) {
                    kondisi = (daftar[j].harga > daftar[j+1].harga);
                } 
                else if (pilihan == 2) {
                    kondisi = (daftar[j].harga < daftar[j+1].harga);
                } 
                else if (pilihan == 3) { 
                    kondisi = (daftar[j].tanggal > daftar[j+1].tanggal);
                }

                if (kondisi) {
                    Transaksi temp = daftar[j];
                    daftar[j] = daftar[j+1];
                    daftar[j+1] = temp;
                }
            }
        }
        cout << endl << "\n\t[SUKSES] DATA TELAH DIURUTKAN" << endl;
        jeda();
    }

    // Function Tampilkan Analisis
    void analisisPengeluaran(){
        judul("ANALISIS PENGELUARAN");
        if (jumlah_data == 0) {
            cout << "\n\t[!] BELUM ADA DATA - Input terlebih dulu..." << endl;
            jeda();
            return;
        }

        int totMakanan = 0, totTransport = 0, totKuliah = 0, totHiburan = 0;

        for (int i = 0; i < jumlah_data; i++){
            if (daftar[i].kategori == "Makanan"){
                totMakanan   += daftar[i].harga;
            }else if (daftar[i].kategori == "Transport"){
                totTransport += daftar[i].harga;
            }else if (daftar[i].kategori == "Kuliah"){
                totKuliah    += daftar[i].harga;
            }else if (daftar[i].kategori == "Hiburan"){
                totHiburan   += daftar[i].harga;
            };
        }

        cout << "\n Pengeluaran Per Kategori" << endl;
        cout << "   [*] Makanan   : Rp " << totMakanan   << endl;
        cout << "   [*] Transport : Rp " << totTransport << endl;
        cout << "   [*] Kuliah    : Rp " << totKuliah    << endl;
        cout << "   [*] Hiburan   : Rp " << totHiburan   << endl;
        garis();

        // Total keseluruhan (rekursi)
        int totalSemua = hitungTotalPengeluaran(daftar, 0, jumlah_data - 1);
        cout << "  TOTAL SEMUA KATEGORI : Rp " << totalSemua << endl;
        garis();
        jeda();
    }

    // Function Save File
    void simpanFile(){
        judul("SIMPAN KE FILE");
        if (jumlah_data == 0) {
            cout << "\n\t[!] BELUM ADA DATA - Input terlebih dulu..." << endl;
            jeda();
            return;
        }

        ofstream simpanFile("catatan_keuangan.txt");
        if(!simpanFile.is_open()){
            cout << "\n\t[!] File Gagal Dibuat/Ditulis" << endl;
            jeda();
            return;
        }

        for (int i = 0; i < jumlah_data; i++){
            simpanFile << daftar[i].barang << ","
                        << daftar[i].tanggal << ","
                        << daftar[i].kategori << ","
                        << daftar[i].harga << endl;
        }

        simpanFile.close();

        cout << "\n\t[SUKSES] Data Berhasil Disimpan ke \"catatan_keuangan.txt\"" << endl;
        
        jeda();
    }
    
    // Function Load File
    void loadFile(){
        judul("LOAD DARI FILE");
        
        ifstream bacaFile("catatan_keuangan.txt");
        if(!bacaFile.is_open()){
            cout << "\n\t[!] File \"catatan_keuangan.txt\" Tidak Ditemukan" << endl;
            jeda();
            return;
        }
        
        jumlah_data = 0;
        while(getline(bacaFile, daftar[jumlah_data].barang, ',')){

            // untuk skip bila baris kosong
            if(daftar[jumlah_data].barang.empty() || daftar[jumlah_data].barang == "\n"){
                continue;
            }

            getline(bacaFile, daftar[jumlah_data].tanggal, ',');
            getline(bacaFile, daftar[jumlah_data].kategori, ',');
            bacaFile >> daftar[jumlah_data].harga;

            bacaFile.ignore();
            jumlah_data++;
        }
        
        // jika selesai membaca file tapi tidak ada isinya
        if (jumlah_data == 0){
            cout << "\n\t[!] Tidak Ada Data Dalam File \"catatan_keuangan.txt\"" << endl;
            jeda();
            return;
        } else {
            cout << "\n\t[SUKSES] Membaca File \"catatan_keuangan.txt\"" << endl;
        }

        jeda();
    }


// Function Utama
    int main() {
        system("color 03");
        int pilih;

        do {
            judul("PROGRAM PENGELOLAAN PENGELUARAN MAHASISWA");

            cout << "\n  [1] Input Transaksi" << endl;
            cout << "  [2] Tampil Semua Transaksi" << endl;
            cout << "  [3] Cari Transaksi" << endl;
            cout << "  [4] Urutkan Transaksi" << endl;
            cout << "  [5] Analisis Pengeluaran" << endl;
            cout << "  [6] Simpan ke File" << endl;
            cout << "  [7] Load dari File" << endl;
            cout << "  [0] Keluar" << endl;
            cout << "\n  Pilih menu [1-9]: ";
            cin >> pilih;
            cin.ignore();

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