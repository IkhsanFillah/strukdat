#include <iostream>
#include <string>

using namespace std;

struct Kos {
    string nama;
    int harga;
    Kos* next;
};

Kos* awal = nullptr;
Kos* akhir = nullptr;
Kos* listbaru;
Kos* bantu;
Kos* hapus;

void sisipdepan(string nama, int harga) {
    listbaru = new Kos();
    listbaru->nama = nama;
    listbaru->harga = harga;
    listbaru->next = nullptr;

    if (awal == nullptr) {
        awal = listbaru;
        akhir = listbaru;
    } else {
        listbaru->next = awal;
        awal = listbaru;
    }
}

void sisiptengah(string nama, int harga) {
    if (awal == nullptr || awal->harga > harga) {
        sisipdepan(nama, harga);
        return;
    }

    listbaru = new Kos();
    listbaru->nama = nama;
    listbaru->harga = harga;
    listbaru->next = nullptr;

    bantu = awal;
    while (bantu->next != nullptr && bantu->next->harga < harga) {
        bantu = bantu->next;
    }

    listbaru->next = bantu->next;
    bantu->next = listbaru;
}

void sisipbelakang(string nama, int harga) {
    listbaru = new Kos();
    listbaru->nama = nama;
    listbaru->harga = harga;
    listbaru->next = nullptr;

    if (akhir == nullptr) {
        awal = listbaru;
        akhir = listbaru;
    } else {
        akhir->next = listbaru;
        akhir = listbaru;
    }
}

void hapuslist(string nama) {
    bantu = awal;

    if (bantu == nullptr) {
        cout << "Kosan tidak ditemukan." << endl;
        return;
    }

    if (bantu->nama == nama) {
        awal = bantu->next;
        delete bantu;
        cout << "Kosan berhasil dihapus." << endl;
        return;
    }

    while (bantu->next != nullptr && bantu->next->nama != nama) {
        bantu = bantu->next;
    }

    if (bantu->next == nullptr) {
        cout << "Kosan tidak ditemukan." << endl;
    } else {
        hapus = bantu->next;
        bantu->next = bantu->next->next;
        if (hapus == akhir) {
            akhir = bantu;
        }
        delete hapus;
        cout << "Kosan berhasil dihapus." << endl;
    }
}

void lihatData() {
    if (awal == nullptr) {
        cout << "Data kosan tidak ditemukan." << endl;
        return;
    }

    Kos* current = awal;

    while (current != nullptr) {
        cout << "Nama Kos\t: " << current->nama << endl; 
        cout << "Harga/Bulan\t: Rp" << current->harga << endl;
        cout << endl;
        current = current->next;
    }
}

bool kembaliKeMenu() {
    char kembali;
    cout << "Kembali ke menu awal? (y/n): ";
    cin >> kembali;
    return (kembali == 'y' || kembali == 'Y');
}

int main() {
    int pilihan;

    while (true) {
        system("cls");
        cout << "Menu" << endl;
        cout << "1. Input Kosan" << endl;
        cout << "2. Lihat Data Kosan" << endl;
        cout << "3. Hapus Data Kosan" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: {
                system("cls");
                string nama;
                int harga, pilih;

                cout << "Input Data :" << endl;
                cout << "Nama kosan\t: ";
                cin.ignore();
                getline(cin, nama);

                cout << "Harga/Bulan\t: ";
                cin >> harga;
                cout << endl;
                cout << "Pilihan Sisip : " << endl;
                cout << "1. Sisip Depan" <<endl;
                cout << "2. Sisip Tengah" <<endl;
                cout << "3. Sisip Belakang" <<endl;
                cout << "Pilih : ";
                cin >> pilih;

                if (pilih == 1) {
                    sisipdepan(nama, harga);
                } else if (pilih == 2) {
                    sisiptengah(nama, harga);
                } else if (pilih == 3) {
                    sisipbelakang(nama, harga);
                } else {
                    cout << "Pilihan tidak valid." << endl;
                }

                cout << "Kosan berhasil ditambahkan." << endl;
                if (!kembaliKeMenu()) return 0;
                break;
            }
            case 2:
                system("cls");
                cout << "Data Kosan:" << endl;
                lihatData();
                if (!kembaliKeMenu()) return 0;
                break;

            case 3: {
                system("cls");
                cout << "Hapus Data Kosan" << endl;
                string nama;
                cout << "Kosan apa yang ingin di hapus: ";
                cin.ignore();
                getline(cin, nama);
                hapuslist(nama);
                if (!kembaliKeMenu()) return 0;
                break;
            }
            case 4:
                cout << "Terima kasih ya aja oh aja." << endl;
                return 0;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi dengan menginputkan angka yang tertera di menu ya bos." << endl;
                break;
        }
    }

    return 0;
}
