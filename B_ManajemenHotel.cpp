#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Kamar {
private:
    int nomorKamar;
    string jenisKamar;
    bool tersedia;

public:
    Kamar(int nomor, string jenis) : nomorKamar(nomor), jenisKamar(jenis), tersedia(true) {}
    int getNomorKamar() const{
        return nomorKamar;
    }
	string getJenisKamar() const{
        return jenisKamar;
    }
    bool isTersedia() const{
        return tersedia;
    }
    void setTersedia(bool status){
        tersedia = status;
    }
};

void tampilkanKamar(const vector<Kamar>& daftarKamar){
    cout << setw(20) << left << "Nomor Kamar"
         << setw(20) << left << "Jenis Kamar"
         << setw(20) << left << "Status" << endl;
    cout << "------------------------------------------------------------" << endl;

    for (const Kamar& kamar : daftarKamar){
        cout << setw(20) << left << kamar.getNomorKamar()
             << setw(20) << left << kamar.getJenisKamar()
             << setw(20) << left << (kamar.isTersedia() ? "Tersedia" : "Dipesan") << endl;
    }
}

Kamar* cariKamar(vector<Kamar>& daftarKamar, int nomor){
    for (Kamar& kamar : daftarKamar) {
        if (kamar.getNomorKamar() == nomor) {
            return &kamar;
        }
    }
    return nullptr;
}

vector<int> cariKamarKosong(const vector<Kamar>& daftarKamar){
    vector<int> kamarKosong;
    for (const Kamar& kamar : daftarKamar){
        if (kamar.isTersedia()){
            kamarKosong.push_back(kamar.getNomorKamar());
        }
    }
    return kamarKosong;
}

void pesanKamar(vector<Kamar>& daftarKamar, int nomor){
    Kamar* kamar = cariKamar(daftarKamar, nomor);
    if (kamar != nullptr) {
        if (kamar->isTersedia()){
            kamar->setTersedia(false);
            cout << "======================================================" << endl;
            cout << "Kamar dengan nomor " << nomor << " berhasil dipesan.\n";
            cout << "======================================================" << endl;
        } else {
        	cout << "==========================================================="<< endl;
            cout << "Kamar dengan nomor " << nomor << " sedang tidak tersedia.\n";
            cout << "===========================================================" << endl;
        }
    } else {
    	cout << "======================================================" << endl;
        cout << "Kamar dengan nomor " << nomor << " tidak ditemukan.\n";
        cout << "======================================================" << endl;
    }
}

void selesaikanPemesanan(vector<Kamar>& daftarKamar, int nomor){
    Kamar* kamar = cariKamar(daftarKamar, nomor);
    if (kamar != nullptr) {
        if (!kamar->isTersedia()){
            kamar->setTersedia(true);
            cout << "Pemesanan kamar dengan nomor " << nomor << " telah diselesaikan.\n";
        } else {
            cout << "Kamar dengan nomor " << nomor << " tidak sedang dipesan.\n";
        }
    } else {
        cout << "Kamar dengan nomor " << nomor << " tidak ditemukan.\n";
    }
}

int main() {
    vector<Kamar> daftarKamar;
    stack<int> daftarKamarDipesan;
    queue<int> daftarKamarDiselesaikan;
    list<int> daftarKamarTersedia;

    daftarKamar.push_back(Kamar(1, "Standard"));
    daftarKamar.push_back(Kamar(2, "Single"));
    daftarKamar.push_back(Kamar(3, "Twin"));
    daftarKamar.push_back(Kamar(4, "Connect"));
    daftarKamar.push_back(Kamar(5, "Family Room"));

    int pilihan;
    int nomorKamar;

    do{
        cout << "==========================================\n";
        cout << "   Program Manajemen Sewa Kamar Hotel\n";
        cout << "==========================================\n";
        cout << "1. Tampilkan Daftar Kamar\n";
        cout << "2. Pesan Kamar\n";
        cout << "3. Selesaikan Pemesanan\n";
        cout << "4. Cari Kamar Kosong\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> pilihan;

        switch (pilihan){
            case 1:
                tampilkanKamar(daftarKamar);
                break;
            case 2:
                cout << "Masukkan nomor kamar yang ingin Anda pesan: ";
                cin >> nomorKamar;
                pesanKamar(daftarKamar, nomorKamar);
                if (cariKamar(daftarKamar, nomorKamar) != nullptr){
                    daftarKamarDipesan.push(nomorKamar);
                }
                break;
            case 3:
                cout << "Masukkan nomor kamar yang ingin Anda selesaikan pemesanannya: ";
                cin >> nomorKamar;
                selesaikanPemesanan(daftarKamar, nomorKamar);
                if (cariKamar(daftarKamar, nomorKamar) != nullptr){
                    daftarKamarDiselesaikan.push(nomorKamar);
                }
                break;
            case 4:
                {
                    vector<int> kamarKosong = cariKamarKosong(daftarKamar);
                    cout << "Kamar yang kosong:\n";
                    for (int nomorKamar : kamarKosong){
                        cout << nomorKamar << "\n";
                    }
                    break;
                }
            case 0:
                cout << "Terima kasih telah Memesan Kamar";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
                break;
        }

        cout << endl;
    } while (pilihan != 0);

    cout << "==========================================\n";
    while (!daftarKamarDipesan.empty()){
        cout << daftarKamarDipesan.top() << "\n";
        daftarKamarDipesan.pop();
    }

    cout << "==========================================\n";
    while (!daftarKamarDiselesaikan.empty()){
        cout << daftarKamarDiselesaikan.front() << "\n";
        daftarKamarDiselesaikan.pop();
    }

    for (const Kamar& kamar : daftarKamar){
        if (kamar.isTersedia()){
            daftarKamarTersedia.push_back(kamar.getNomorKamar());
        }
    }

    cout << "==========================================\n";
    for (const int& nomorKamar : daftarKamarTersedia) {
        cout << nomorKamar << "\n";
    }

    return 0;
}
