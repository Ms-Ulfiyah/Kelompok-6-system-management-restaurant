#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <conio.h>
#include <iomanip>

using namespace std;

// Fungsi untuk registrasi pengguna
void registerUser(string& nama, string& password) {
    string kp;

    cout << "=================================================" << endl;
    cout << "||                   REGISTRASI                ||" << endl;
    cout << "=================================================" << endl;
    cout << "Masukkan nama: ";
    cin >> nama;

    while (true) {
        cout << "Masukkan password: ";
        cin >> password;

        cout << "Konfirmasi Password: ";
        cin >> kp;

        if (password == kp) {
            cout << "Registrasi Berhasil!\n" << endl;
            break;
        }
        else {
            cout << "Passwords salah. silahkan ulangi lagi.\n" << endl;
        }
    }
}

// Fungsi untuk login pengguna
bool loginUser(const string& registrasinama, const string& registrasipassword) {
    string username, password;

    cout << "=================================================" << endl;
    cout << "||                     LOGIN                   ||" << endl;
    cout << "=================================================" << endl;
    cout << "Masukkan nama: ";
    cin >> username;

    cout << "Masukkan Password: ";
    cin >> password;

    if (username == registrasinama && password == registrasipassword) {
        cout << "Login berhasil!\n" << endl;
        return true;
    }
    else {
        cout << "Kesalahan dalam memasukkan nama atau password, silahkan coba lagi\n" << endl;
        return false;
    }
}

void tampilkan_menu(const vector<string>& daftar_menu, const vector<int>& harga_menu) {
    // Hitung panjang maksimum nama menu
    size_t max_length = 0;
    for (const auto& menu : daftar_menu) {
        if (menu.length() > max_length) {
            max_length = menu.length();
        }
    }
    cout << "\n================ Menu =================\n";
    for (size_t i = 0; i < daftar_menu.size(); ++i) {
        cout << "[" << i + 1 << "] "
            << setw(max_length) << left << daftar_menu[i]
            << " = Rp. "
            << right << harga_menu[i] << "\n";
    }
    cout << "=======================================\n";
}


int pilih_menu(const vector<string>& daftar_menu, const vector<int>& harga_menu, string& nama_menu, int& jumlah_pesanan) {
    while (true) {
        tampilkan_menu(daftar_menu, harga_menu);

        int pilihan;
        cout << "\nPilih menu berdasarkan nomor: ";
        cin >> pilihan;

        if (pilihan < 1 || pilihan > static_cast<int>(daftar_menu.size())) {
            system("cls");
            cout << "Nomor menu yang dipilih tidak valid. Silakan pilih ulang.\n";
            continue;
        }

        cout << "Jumlah yang ingin dipesan: ";
        cin >> jumlah_pesanan;

        if (jumlah_pesanan <= 0) {
            system("cls");
            cout << "Jumlah tidak boleh kurang dari 1. Silakan pesan ulang.\n";
            continue;
        }

        nama_menu = daftar_menu[pilihan - 1];
        int total_harga = jumlah_pesanan * harga_menu[pilihan - 1];
        cout << "Anda memesan " << jumlah_pesanan << " " << nama_menu
            << " dengan total harga Rp " << total_harga << "\n";

        return total_harga;
    }
}

void mp() {

metode_mp:
    cout << "\nPilih metode pembayaran : \n";
    cout << " 1. Credit card \n";
    cout << " 2. Debit card \n";
    cout << " 3. E-money \n";
    int pilih_mp;
    cout << "Anda memiilih : "; cin >> pilih_mp;
    system("cls");

    // credit card 
    if (pilih_mp == 1) {

    credit_card:
        int Cc;
        cout << " Credit card : \n";
        cout << " 1. Visa \n";
        cout << " 2. Mastercard\n";
        cout << " : "; cin >> Cc;

        if (Cc == 1) {
            int id = 5616161;
            cout << "\nVISA : " << id;
            cout << "\n - Pastikan nominal pembayaran sesuai sebelum menyelesaikan transaksi \n";
            cout << " - Jika terjadi masalah, segera laporkan di 04040 \n";
            cout << " - Semua pembayaran tidak dapat dikembalikan kecuali ada kesalahan yang diakui oleh restoran \n";
        }
        else if (Cc == 2) {
            int id = 4345252;
            cout << "\nMASTERCARD : " << id;
            cout << "\n - Pastikan nominal pembayaran sesuai sebelum menyelesaikan transaksi \n";
            cout << " - Jika terjadi masalah, segera laporkan di 04040 \n";
            cout << " - Semua pembayaran tidak dapat dikembalikan kecuali ada kesalahan yang diakui oleh restoran \n";
        }
        else {
        gantiCc:
            int gmCc; // ganti metode pembayaran credit card
            cout << " maaf pilihan credit card tidak valid ganti metode pembayaran atau menggunakan kartu credit yang lain\n";
            cout << " 1.ganti metode pembayaran \n";
            cout << " 2.kartu credit lain \n";
            cout << " : "; cin >> gmCc;
            switch (gmCc) {
            case 1:
                goto metode_mp; break;
            case 2:goto credit_card; break;
            default: cout << " mohon pilih dengan benar ^^ \n";
                goto gantiCc;
                system("cls");
            }
            cout << endl;
        }
    }

    //debit
    else if (pilih_mp == 2) {
    debit:
        int dc;
        cout << " Debit card : \n";
        cout << " 1. MANDIRI \n";
        cout << " 2. BRI \n";
        cout << " 3. BCA \n";
        cout << " 4. BNI \n";
        cout << " : "; cin >> dc;

        if (dc == 1) {
            int id = 646737;
            cout << "\n MANDIRI " << id;
            cout << "\n - Pastikan nominal pembayaran sesuai sebelum menyelesaikan transaksi \n";
            cout << " - Jika terjadi masalah, segera laporkan di 04040 \n";
            cout << " - Semua pembayaran tidak dapat dikembalikan kecuali ada kesalahan yang diakui oleh restoran \n";

        }
        else if (dc == 2) {
            int id = 782737;
            cout << "\n BRI " << id;
            cout << "\n - Pastikan nominal pembayaran sesuai sebelum menyelesaikan transaksi \n";
            cout << " - Jika terjadi masalah, segera laporkan di 04040 \n";
            cout << " - Semua pembayaran tidak dapat dikembalikan kecuali ada kesalahan yang diakui oleh restoran \n";
        }
        else if (dc == 3) {
            int id = 383383;
            cout << "\n BCA " << id;
            cout << "\n - Pastikan nominal pembayaran sesuai sebelum menyelesaikan transaksi \n";
            cout << " - Jika terjadi masalah, segera laporkan di 04040 \n";
            cout << " - Semua pembayaran tidak dapat dikembalikan kecuali ada kesalahan yang diakui oleh restoran \n";
        }
        else if (dc == 4) {
            int id = 673277;
            cout << "\n BNI " << id;
            cout << "\n - Pastikan nominal pembayaran sesuai sebelum menyelesaikan transaksi \n";
            cout << " - Jika terjadi masalah, segera laporkan di 04040 \n";
            cout << " - Semua pembayaran tidak dapat dikembalikan kecuali ada kesalahan yang diakui oleh restoran \n";
        }
        else {
        gantiDc:
            int gmDc;//ganti metode debit card
            cout << " maaf pilihan bank Debit card tidak valid silahkan ganti metode atau menggunakan bank lain \n";
            cout << " 1. ganti metode \n";
            cout << " 2. bank lain \n";
            cout << " : ";  cin >> gmDc;
            switch (gmDc) {
            case 1:
                goto metode_mp; break;
            case 2:
                goto debit; break;
            default:
                cout << " mohon pilih dengan benar ^^ \n";
                goto gantiDc;
                system("cls");
            }
            cout << endl;
        }

    }
    //e-money
    else if (pilih_mp == 3) {

    e_money:
        int ey;
        cout << " E-money \n";
        cout << " 1. Gopay \n";
        cout << " 2. Dana \n";
        cout << " 3. Ovo \n";
        cout << " 4. shopeepay \n";
        cout << " : "; cin >> ey;

        if (ey == 1) {
            cout << " GOPAY \n";
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . | . |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . | . |   | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . |   |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << " nomor : 08726626262\n";
        }
        else if (ey == 2) {
            cout << " DANA  \n";
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . | . |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . | . |   | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . |   |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << " nomor : 08726626262\n";
        }
        else if (ey == 3) {
            cout << " OVO \n";
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . | . |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . | . |   | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . |   |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << " nomor : 08726626262\n";
        }
        else if (ey == 4) {
            cout << " SHOPEEPAY \n";
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . | . |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . | . |   | . |   |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "| . |   | . | . | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << "|   | . |   |   | . |" << endl;
            cout << "+---+---+---+---+---+" << endl;
            cout << " nomor : 08726626262\n";
        }
        else
        {
        gantiey:
            int gmey;//ganti metode pembayaran e-money
            cout << " maaf pilihan pembayaran tidak valid silahkan ganti metode pembayaran atau menggunakan e-money yang lain \n";
            cout << " 1.ganti metode pembayaran\n";
            cout << " 2.gunakan e-money yang lain\n";
            cout << ": "; cin >> gmey;
            switch (gmey) {
            case 1: goto metode_mp; break;
            case 2:goto e_money; break;
            default: cout << " mohon pilih dengan benar ^^ \n";
                goto gantiey;
                system("cls");

            }
            cout << endl;
        }

    }
    else {
        cout << " \nmaaf pilihan pembayaran tidak valid coba lagi \n";
        goto metode_mp;
        system("cls");

    }
    cout << endl;
}

void pesan_menu() {
    struct Pesanan {
        string nama_menu;
        int jumlah;
        int harga_total;
    };
    int  tbaw{}, tbak, td;
    string tp, tb;
    int diskon = 0;


    vector<Pesanan> daftar_pesanan;

    vector<string> makanan = {
        "Nasi Goreng Spesial",
        "Mie Goreng Seafood",
        "Ayam Bakar Madu",
        "Ikan Bakar Sambal Matah",
        "Sate Ayam",
        "Sop Buntut",
        "Rawon Daging",
        "Rendang Daging",
        "Gado-Gado",
        "Bakso Kuah"
    };
    vector<int> harga_makanan = { 22000, 21000, 22000, 50000, 25000, 25000, 50000, 25000, 50000, 20000 };

    vector<string> minuman = {
        "Es Teh Manis",
        "Es Jeruk",
        "Es Lemon",
        "Es Cendol",
        "Es Soda Gembira"
    };
    vector<int> harga_minuman = { 8000, 13000, 15000, 13000, 11000 };

    int total_harga = 0;
    char ulang;



    do {
        cout << "\n=== Kategori Menu ===\n";
        cout << "1. Makanan\n";
        cout << "2. Minuman\n";
        cout << "Pilih kategori: ";
        int kategori;
        cin >> kategori;
        system("cls");

        int total_item_harga = 0;
        string nama_menu;
        int jumlah_pesanan;

        switch (kategori) {
        case 1:
            total_item_harga = pilih_menu(makanan, harga_makanan, nama_menu, jumlah_pesanan);
            daftar_pesanan.push_back({ nama_menu, jumlah_pesanan, total_item_harga });
            break;
        case 2:
            total_item_harga = pilih_menu(minuman, harga_minuman, nama_menu, jumlah_pesanan);
            daftar_pesanan.push_back({ nama_menu, jumlah_pesanan, total_item_harga });
            break;
        default:
            cout << "Kategori tidak valid.\n";
            break;
        }


        total_harga += total_item_harga;

        cout << "\nIngin memesan lagi? (Y/T): ";
        cin >> ulang;
    } while (ulang == 'Y' || ulang == 'y');

    // Tampilkan struk akhir
    system("cls");
    cout << "\n==================== Struk Pembelian ====================\n";

    cout << setw(25) << left << "\nMenu" << setw(10) << "Jumlah" << setw(15) << "Harga Total" << endl;
    cout << "---------------------------------------------------------\n";
    for (const auto& pesanan : daftar_pesanan) {
        cout << setw(25) << left << pesanan.nama_menu << setw(10) << pesanan.jumlah << setw(15) << pesanan.harga_total << "\n";
    }
    cout << "---------------------------------------------------------\n";
    cout << setw(25) << left << "TOTAL" << setw(10) << "" << setw(15) << total_harga << "\n";
    cout << "\n=========================================================\n";

    tbaw = total_harga;
    if (total_harga >= 200000) {
        diskon = 35;
        td = diskon * total_harga / 100;
        tbak = total_harga - td;

        cout << "Selamat Anda mendapatkan diskon sebesar " << diskon << " %\n";
        cout << "Tagihan Anda sekarang adalah = " << tbak << endl;
    }
    else if (total_harga >= 150000) {
        diskon = 25;
        td = diskon * total_harga / 100;
        tbak = total_harga - td;

        cout << "Selamat Anda mendapatkan diskon sebesar " << diskon << " %\n";
        cout << "Tagihan Anda sekarang adalah = " << tbak << endl;
    }
    else if (total_harga >= 100000) {
        diskon = 10;
        td = diskon * total_harga / 100;
        tbak = total_harga - td;

        cout << "Selamat Anda mendapatkan diskon sebesar " << diskon << " %\n";
        cout << "Tagihan Anda sekarang adalah = " << tbak << endl;
    }
    else {
        cout << "Maaf Anda belum mendapatkan diskon.\n";
        cout << "Tagihan Anda adalah = " << total_harga << "\n";
    }

    cout << "\nPembayaran : ";
    mp();
}


// Fungsi untuk menulis kritik dan saran ke file
void kritik_dan_saran() {
    string kritik, nama;

    cout << "=== Kritik dan Saran ===\n";
    cout << "Nama Anda: ";
    cin.ignore();
    getline(cin, nama);

    cout << "Masukkan kritik atau saran Anda: ";
    getline(cin, kritik);

    ofstream file("kritik_dan_saran.txt", ios::app);
    if (file.is_open()) {
        file << "Nama: " << nama << "\n";
        file << "Kritik/Saran: " << kritik << "\n";
        file << "-------------------------------------\n";
        file.close();
        cout << "\nKritik dan saran Anda berhasil disimpan. Terima kasih!\n";
    }
    else {
        cout << "\nGagal menyimpan kritik dan saran.\n";
    }
}

void tampilkan_kritik_dan_saran() {
    ifstream file("kritik_dan_saran.txt");
    if (file.is_open()) {
        string line;
        cout << "=== Daftar Kritik dan Saran ===\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }
    else {
        cout << "\nTidak ada kritik dan saran yang ditemukan atau file tidak dapat dibuka.\n";
    }
}

//bagian admin 

void tambah_menu(vector<string>& daftar_menu, vector<int>& harga_menu) {
    string menu_baru;
    int harga_baru;

    cout << "\nMasukkan nama menu baru: ";
    cin.ignore();
    getline(cin, menu_baru);
    cout << "Masukkan harga menu baru: ";
    cin >> harga_baru;

    daftar_menu.push_back(menu_baru);
    harga_menu.push_back(harga_baru);

    cout << "Menu baru telah ditambahkan!\n";
}

void hapus_menu(vector<string>& daftar_menu, vector<int>& harga_menu) {
    int index;
    cout << "\nMenu yang tersedia:\n";
    for (size_t i = 0; i < daftar_menu.size(); ++i) {
        cout << "[" << i + 1 << "] " << daftar_menu[i] << " = Rp " << harga_menu[i] << "\n";
    }
    cout << "Masukkan nomor menu yang ingin dihapus: ";
    cin >> index;

    if (index >= 1 && index <= daftar_menu.size()) {
        daftar_menu.erase(daftar_menu.begin() + index - 1);
        harga_menu.erase(harga_menu.begin() + index - 1);
        cout << "Menu berhasil dihapus.\n";
    }
    else {
        cout << "Menu yang dipilih tidak valid.\n";
    }
}

void lihat_pesanan(const vector<vector<string>>& pesanan) {
    cout << "\n==================== Daftar Pesanan ====================\n";
    for (size_t i = 0; i < pesanan.size(); ++i) {
        cout << "Pesanan " << i + 1 << ": ";
        for (const auto& item : pesanan[i]) {
            cout << item << " ";
        }
        cout << "\n";
    }
    cout << "=========================================================\n";
}

void lihat_pendapatan(const vector<int>& total_harga_pesanan) {
    int total_pendapatan = 0;
    for (int harga : total_harga_pesanan) {
        total_pendapatan += harga;
    }
    cout << "\nTotal Pendapatan Hari Ini: Rp " << total_pendapatan << "\n";
}

void menu_pegawai() {
    vector<string> makanan = {
        "Nasi Goreng Spesial", "Mie Goreng Seafood", "Ayam Bakar Madu",
        "Ikan Bakar Sambal Matah", "Sate Ayam", "Sop Buntut", "Rawon Daging",
        "Rendang Daging", "Gado-Gado", "Bakso Kuah"
    };
    vector<int> harga_makanan = { 22000, 21000, 22000, 50000, 25000, 25000, 50000, 25000, 50000, 20000 };

    vector<string> minuman = {
        "Es Teh Manis", "Es Jeruk", "Es Lemon", "Es Cendol", "Es Soda Gembira"
    };
    vector<int> harga_minuman = { 8000, 13000, 15000, 13000, 11000 };

    vector<vector<string>> pesanan;
    vector<int> total_harga_pesanan;
    int pilihan;

    do {
        system("cls");
        cout << "=== Menu Pegawai ===\n";
        cout << "1. Tambah Menu\n";
        cout << "2. Hapus Menu\n";
        cout << "3. Lihat Pesanan\n";
        cout << "4. Lihat Statistik Pendapatan\n";
        cout << "5. Tampilkan Kritik dan Saran\n";
        cout << "6. Keluar\n";
        cout << "Pilih opsi: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            tambah_menu(makanan, harga_makanan);
            break;
        case 2:
            hapus_menu(makanan, harga_makanan);
            break;
        case 3:
            lihat_pesanan(pesanan);
            break;
        case 4:
            lihat_pendapatan(total_harga_pesanan);
            break;
        case 5:
            tampilkan_kritik_dan_saran();
            break;
        case 6:
            cout << "Keluar dari menu pegawai.\n";
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
        }

        if (pilihan != 6) {
            cout << "\nTekan ENTER untuk kembali ke menu pegawai...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 6);
}




int main() {
    string nama, password;
    int opsi, pilih, pilihan;

    do {
        system("cls");
        cout << "=== Aplikasi Restoran ===" << endl;
        cout << "1. Pelanggan" << endl;
        cout << "2. Pegawai" << endl;
        cout << "Pilih Opsi: ";
        cin >> pilih;
        system("cls");

        switch (pilih) {
        case 1:
            while (true) {
                cout << "=== Menu ===" << endl;
                cout << "1. Registrasi" << endl;
                cout << "2. Login" << endl;
                cout << "3. Keluar" << endl;
                cout << "Pilih Opsi: ";
                cin >> opsi;
                system("cls");

                switch (opsi) {
                case 1:
                    registerUser(nama, password);
                    break;
                case 2:
                    if (loginUser(nama, password)) {
                        int pilihan;
                        do {
                            cout << "\n=== Menu Pelanggan ===\n";
                            cout << "1. Pesan Menu\n";
                            cout << "2. Kritik dan Saran\n";
                            cout << "3. Keluar\n";
                            cout << "Pilih opsi: ";
                            cin >> pilihan;
                            system("cls");

                            switch (pilihan) {
                            case 1:
                                pesan_menu();
                                break;
                            case 2:
                                kritik_dan_saran();
                                break;
                            case 3:
                                cout << "Keluar dari menu pelanggan.\n";
                                return 0;
                            default:
                                cout << "Pilihan tidak valid.\n";
                            }
                        } while (pilihan != 4);
                    }
                    break;
                case 3:
                    cout << "Program keluar. Goodbye!" << endl;
                    return 0;
                default:
                    cout << "Pilihan tidak valid.\n";
                }
            }
            break;

        case 2:
            menu_pegawai();
            break;

        default:
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 3);

    return 0;
}
