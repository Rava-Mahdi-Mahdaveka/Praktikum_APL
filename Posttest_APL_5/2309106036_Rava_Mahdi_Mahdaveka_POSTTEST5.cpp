#include <iostream>
#include <string>
#include <limits>

#define CLEAR "cls"

using namespace std;

struct Helikopter {
    struct JenisHelikopter {
        string kecil = "Kecil";
        string sedang = "Sedang";
        string besar = "Besar";
    } jenisHelikopter;

    string nama;
    string jenis;
    int lama_sewa_hari;
};
const int maksimal_pesanan = 10;
int jumlah_pesanan = 0;
Helikopter helikopter[maksimal_pesanan];

bool login() {
    string username, password;
    int maksimal_salah = 0;
    
    while (maksimal_salah < 3) {
        cout << "=============================================================\n";
        cout << "Selamat datang di program rental helikopter\n";
        cout << "Silahkan masukkan nama admin: ";
        getline(cin, username);

        cout << "Silahkan masukkan kata sandi: ";
        getline(cin, password);

        if (username == "Rava Mahdi Mahdaveka" && password == "2309106036") {
            cout << "Login berhasil!\n";
            return true;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            cout << "Login gagal \n" ;
            maksimal_salah++;
        }
    }

    cout << "Kesempatan Anda habis, silahkan coba lain kali\n" ;
    return false;
}
void tambahPesanan(Helikopter *pesanan) {
    if (jumlah_pesanan < maksimal_pesanan) {
        cout << "Masukkan data perental helikopter:" << endl;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, pesanan[jumlah_pesanan].nama);

        Helikopter::JenisHelikopter jenis;
        cout << "Silahkan pilih jenis helikopter (1: Kecil, 2: Sedang, 3: Besar): ";
        int pilihan_jenis;
        while (true) {
            if (cin >> pilihan_jenis && pilihan_jenis >= 1 && pilihan_jenis <= 3) {
                cin.ignore();
                break;
            } else {
                cout << "Pilihan jenis helikopter tidak valid.\n Silahkan pilih jenis helikopter (1: Kecil, 2: Sedang, 3: Besar):" << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (pilihan_jenis) {
            case 1:
                pesanan[jumlah_pesanan].jenis = jenis.kecil;
                break;
            case 2:
                pesanan[jumlah_pesanan].jenis = jenis.sedang;
                break;
            case 3:
                pesanan[jumlah_pesanan].jenis = jenis.besar;
                break;
        }

        cout << "Lama sewa (dalam hari): ";
        while (!(cin >> pesanan[jumlah_pesanan].lama_sewa_hari)) {
            cout << "Input tidak valid. Masukkan lama sewa (dalam hari): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        jumlah_pesanan++;
        cout << "Data pesanan berhasil ditambahkan." << endl;
    } else {
        cout << "Kapasitas pesanan penuh. Tidak dapat menambahkan data." << endl;
    }
}


void ubahPesanan(Helikopter *pesanan) {
    if (jumlah_pesanan > 0) {
        cout << "\nData Pesanan Helikopter:\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
            cout << "\nHelikopter ke-" << i + 1 << ":\n";
            cout << "Nama: " << pesanan[i].nama << endl;
            cout << "Jenis: " << pesanan[i].jenis << endl;
            cout << "Lama sewa (dalam hari): " << pesanan[i].lama_sewa_hari << endl;
        }
        int index;
        cout << "Masukkan indeks helikopter yang akan diubah (1-" << jumlah_pesanan << "): ";
        while (!(cin >> index) || index < 1 || index > jumlah_pesanan) {
            cout << "Indeks tidak valid. Masukkan indeks helikopter yang akan diubah (1-" << jumlah_pesanan << "): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        Helikopter::JenisHelikopter jenis;
        cout << "\nMasukkan data pesanan yang baru" << endl;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, pesanan[index - 1].nama);

        cout << "Silahkan pilih jenis helikopter (1: Kecil, 2: Sedang, 3: Besar): ";
        int pilihan_jenis;
        while (true) {
            if (cin >> pilihan_jenis && pilihan_jenis >= 1 && pilihan_jenis <= 3) {
                cin.ignore();
                break;
            } else {
                cout << "Pilihan jenis helikopter tidak valid. Silakan coba lagi." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }

        switch (pilihan_jenis) {
            case 1:
                pesanan[index - 1].jenis = jenis.kecil;
                break;
            case 2:
                pesanan[index - 1].jenis = jenis.sedang;
                break;
            case 3:
                pesanan[index - 1].jenis = jenis.besar;
                break;
        }

        cout << "Lama sewa (dalam hari): ";
        while (!(cin >> pesanan[index - 1].lama_sewa_hari)) {
            cout << "Input tidak valid. Masukkan lama sewa (dalam hari): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "Data pesanan berhasil diubah." << endl;
    } else {
        cout << "Tidak ada data pesanan untuk diubah." << endl;
    }
}

void hapusPesanan(Helikopter *pesanan) {
    if (jumlah_pesanan > 0) {
        cout << "\nData Pesanan Helikopter:\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
            cout << "\nHelikopter ke-" << i + 1 << ":\n";
            cout << "Nama: " << pesanan[i].nama << endl;
            cout << "Jenis: " << pesanan[i].jenis << endl;
            cout << "Lama sewa (dalam hari): " << pesanan[i].lama_sewa_hari << endl;
        }
        int index;
        cout << "Masukkan indeks pesanan yang akan dihapus (1-" << jumlah_pesanan << "): ";
        while (!(cin >> index) || index < 1 || index > jumlah_pesanan) {
            cout <<"Indeks tidak valid. Masukkan indeks pesanan yang akan dihapus (1-" << jumlah_pesanan << "): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        for (int i = index - 1; i < jumlah_pesanan - 1; i++) {
            pesanan[i] = pesanan[i + 1];
        }

        jumlah_pesanan--;
        cout << "Data pesanan berhasil dihapus." << endl;
    } else {
        cout << "Tidak ada data pesanan untuk dihapus." << endl;
    }
}


void tampilkanData(Helikopter *pesanan) {
    if (jumlah_pesanan > 0) {
        cout << "\nData Pesanan Helikopter:\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
            cout << "\nHelikopter ke-" << i + 1 << ":\n";
            cout << "Nama: " << pesanan[i].nama << endl;
            cout << "Jenis: " << pesanan[i].jenis << endl;
            cout << "Lama sewa (dalam hari): " << pesanan[i].lama_sewa_hari << endl;
        }
    } else {
        cout << "Tidak ada data pesanan untuk ditampilkan." << endl;
    }
}

void tampilkanMenu() {
    cout << "\n===================================\n";
    cout << "Silahkan pilih menu yang tersedia" << endl;
    cout << "1. Tambah pesanan" << endl;
    cout << "2. Ubah pesanan" << endl;
    cout << "3. Hapus pesanan" << endl;
    cout << "4. Tampilkan Data pesanan" << endl;
    cout << "5. Keluar" << endl;
}

void mainMenu() {
    int pilihan;

    do {
        tampilkanMenu();
        cout << "Masukkan pilihan (1-5): ";
        while (!(cin >> pilihan) || pilihan < 1 || pilihan > 5) {
            cout << "Pilihan tidak valid. Masukkan pilihan (1-5): ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << "=========================\n";
        switch (pilihan) {
            case 1:
                system(CLEAR); 
                tambahPesanan(helikopter);
                break;
            case 2:
                system(CLEAR); 
                ubahPesanan(helikopter);
                break;
            case 3:
                system(CLEAR); 
                hapusPesanan(helikopter);
                break;
            case 4:
                system(CLEAR); 
                tampilkanData(helikopter);
                break;
            case 5:
                cout << "Program telah selesai, terima kasih." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

    } while (pilihan != 5);
}

int main() {
    if (!login()) {
        return 0;  
    }

    mainMenu();

    return 0;
}
