#include <iostream>
#include <vector>
#include <conio.h>
#include <stdlib.h>
#include < fstream>
#include < sstream>
#include <string>
using namespace std;

// reservasi 

struct pelanggan  {
	int id;
	string nama;
	string kontak;
	string preferensi;
};
struct Reservasi {
	int idpelanggan;
	string tglreservasi;
	string detail;
};


//fungsi penambahan pelanggan 
void penambahan_pelanggan(const pelanggan& pelanggan) {
	ofstream file("pelanggan.txt", ios::app);
	if (file.is_open()) {

		file << pelanggan.id << "," << pelanggan.nama << "," << pelanggan.kontak << "," << pelanggan.preferensi << endl;
		file.close();
		cout << " Pelanggan berhasil ditambahkan ! " << endl;
	}
	else {
		cout << " Gagal membuka file pelanggan" << endl;
	}
}


void reservasi(const Reservasi&reservasi) {
	ofstream file("reservasi.txt ", ios::app);
	if (file.is_open()) {
		file << reservasi.idpelanggan << "," << reservasi.tglreservasi << "," << reservasi.detail << endl;
		file.close();
		cout << " Reservasi berhasil ditambahkan !" << endl;
	}
	else {
		cout << " Reservasi Gagal ditambahkan ! " << endl; 
	}
}

// menu pemesanan
struct Pemesanan
{
	int idpelanggan;
	string tglpemesanan;
	string detail_pemesanan;

};


void pemesanan(Pemesanan&pemesanan) {
	ofstream file("pemesanan.txt", ios::app); {
		if (file.is_open()) {
			
			file << pemesanan.idpelanggan << ", " << pemesanan.tglpemesanan << "," << pemesanan.detail_pemesanan << endl;
			file.close();
			cout << " Pesanan berhasil ditambahkan ! " << endl;

		}
		else {
			cout << " Gagal membuka file pemesanan ! " << endl;
		}
	}
}


//fungsi data pelanggan dan pemesanan 

void datapelanggan(int idpelanggan) {
	ifstream filepelanggan("pelanggan.txt");
	ifstream filereservasi("reservasi.txt");
	ifstream filepemesanan("pemesanan.txt");
	string line;


	//menampilkan data pelanggan
	cout << "\n Data pelanggan : " << endl;
	bool  caripelanggan = false;
	if (filepelanggan.is_open()) {

		while (getline(filepelanggan, line)) {
			stringstream ss(line);
			string id, nama, kontak, preferensi;
			getline(ss, id);
			getline(ss, nama);
			getline(ss, kontak);
			getline(ss, preferensi);

			if (stoi (id) == idpelanggan){

				cout << " ID : " << id << " , Nama : " << nama << " ,kontak " << kontak << " , preferensi :" << preferensi << endl;
				caripelanggan = true;

			}

		}

		filepelanggan.close();

	}
	if (!caripelanggan) {
		cout << " pelanggan tidak ditemukan ! " << endl;
		return;
	}
}




