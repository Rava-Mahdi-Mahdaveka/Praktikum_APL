#include <iostream>

using namespace std;

struct Helikopter {
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
        getline (cin,username);

        cout << "Silahkan masukkan kata sandi: ";
        getline (cin,password);

        if (username == "Rava Mahdi Mahdaveka" && password == "2309106036") {
            cout << "Login berhasil!\n";
            return true;
        } else {
            cout << "Login gagal \n" ;
            maksimal_salah++;
        }
    }

    cout << "Kesempatan Anda habis, silahkan coba lain kali\n" ;
    return false;
}

void tambahHelikopter() {
    if (jumlah_pesanan < maksimal_pesanan) {
        cout << "Masukkan data perental helikopter:" << endl;

        cout << "Nama: ";
        cin.ignore();
        getline(cin, helikopter[jumlah_pesanan].nama);

        cout << "silahkan pilih menu di bawah\n";
        cout << "1. Kecil\n";
        cout << "2. Sedang\n";
        cout << "3. Besar\n";
        cout << "Pilih jenis helikopter (pilih angka): ";
        int pilihan_jenis;
        cin >> pilihan_jenis;

        switch (pilihan_jenis) {
            case 1:
                helikopter[jumlah_pesanan].jenis = "1";
                break;
            case 2:
                helikopter[jumlah_pesanan].jenis = "2";
                break;
            case 3:
                helikopter[jumlah_pesanan].jenis = "3";
                break;
            default:
                cout << "Pilihan tidak valid." << endl;
                return;
        }

        cout << "Lama sewa (dalam hari): ";
        cin >> helikopter[jumlah_pesanan].lama_sewa_hari;

        jumlah_pesanan++;
        cout << "Data pesanan berhasil ditambahkan." << endl;
    } else {
        cout << "Kapasitas pesanan penuh. Tidak dapat menambahkan data." << endl;
    }
}

void ubahHelikopter() {
    if (jumlah_pesanan > 0) {
        int index;

        cout << "Masukkan indeks helikopter yang akan diubah (1-" << jumlah_pesanan << "): ";
        cin >> index;

        if (index >= 1 && index <= jumlah_pesanan) {
            cout << "Data pesanan helikopter sebelum diubah:" << endl;
            cout << "Nama: " << helikopter[index - 1].nama << endl;
            cout << "Jenis: " << helikopter[index - 1].jenis << endl;
            cout << "Lama sewa (dalam hari): " << helikopter[index - 1].lama_sewa_hari << endl;

            cout << "\nMasukkan data pesanan yang baru:" << endl;

            cout << "Nama: ";
            cin.ignore();
            getline(cin, helikopter[index - 1].nama);

            cout << "silahkan pilih menu di bawah\n";
            cout << "1. Kecil\n";
            cout << "2. Sedang\n";
            cout << "3. Besar\n";
            cout << "Pilih jenis helikopter (pilih angka): ";
            int pilihan_jenis;
            cin >> pilihan_jenis;

            switch (pilihan_jenis) {
                case 1:
                    helikopter[index - 1].jenis = "Kecil";
                    break;
                case 2:
                    helikopter[index - 1].jenis = "Sedang";
                    break;
                case 3:
                    helikopter[index - 1].jenis = "Besar";
                    break;
                default:
                    cout << "Pilihan jenis helikopter tidak valid." << endl;
                    return;
            }

            cout << "Lama sewa (dalam hari): ";
            cin >> helikopter[index - 1].lama_sewa_hari;

            cout << "Data pesanan berhasil diubah." << endl;
        } else {
            cout << "Indeks pesanan tidak valid." << endl;
        }
    } else {
        cout << "Tidak ada data pesanan untuk diubah." << endl;
    }
}

void hapusHelikopter() {
    if (jumlah_pesanan > 0) {
        int index;

        cout << "Masukkan indeks pesanan yang akan dihapus (1-" << jumlah_pesanan << "): ";
        cin >> index;

        if (index >= 1 && index <= jumlah_pesanan) {
            for (int i = index - 1; i < jumlah_pesanan - 1; i++) {
                helikopter[i] = helikopter[i + 1];
            }

            jumlah_pesanan--;
            cout << "Data pesanan berhasil dihapus." << endl;
        } else {
            cout << "Indeks pesanan tidak valid." << endl;
        }
    } else {
        cout << "Tidak ada data pesanan untuk dihapus." << endl;
    }
}

void tampilkanData() {
    if (jumlah_pesanan > 0) {
        cout << "\nData  Pesanan Helikopter:\n";
        for (int i = 0; i < jumlah_pesanan; i++) {
            cout << "Helikopter ke-" << i + 1 << ":\n";
            cout << "Nama: " << helikopter[i].nama << endl;
            cout << "Jenis: " << helikopter[i].jenis << endl;
            cout << "Lama sewa (dalam hari): " << helikopter[i].lama_sewa_hari << endl;
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

int main() {
    if (!login()) {
        return 0;  
    }

    int pilihan;

    do {
        tampilkanMenu();
        cout << "Masukkan pilihan (1-5): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahHelikopter();
                break;
            case 2:
                ubahHelikopter();
                break;
            case 3:
                hapusHelikopter();
                break;
            case 4:
                tampilkanData();
                break;
            case 5:
                cout << "Terima kasih. Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
        }

    } while (pilihan != 5);

    return 0;
}

