#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

struct Mahasiswa {
    string NIM;
    string Nama;
    string Alamat;
    string Kelas;
    float Nilai;
};

int sequentialSearch(const vector<Mahasiswa>& data, const string& nama) {
    for (int i = 0; i < data.size(); ++i) {
        if (data[i].Nama == nama) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<Mahasiswa>& data, const string& nama) {
    int left = 0, right = data.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (data[mid].Nama == nama) {
            return mid;
        }
        if (data[mid].Nama < nama) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; 
}

void printMahasiswa(const Mahasiswa& mhs) {
    cout << "NIM: " << mhs.NIM << endl;
    cout << "Nama: " << mhs.Nama << endl;
    cout << "Alamat: " << mhs.Alamat << endl;
    cout << "Kelas: " << mhs.Kelas << endl;
    cout << "Nilai: " << mhs.Nilai << endl;
}

int main() {
    vector<Mahasiswa> mahasiswa = {
        {"531424112", "Muhammad Robby Darmawan", "Gorontalo", "E", 90},
        {"532414011", "Andi jio", "Bandung", "B", 90.0},
        {"532414010", "Tono oji", "Surabaya", "A", 78.0},
        {"532414009", "Siti", "Medan", "C", 88.0},
        {"532414008", "Andi", "Yogyakarta", "B", 82.5}
    };

    string cariNama;
    cout << "Masukkan nama mahasiswa yang dicari: ";
    cin >> cariNama;

    int indexSeq = sequentialSearch(mahasiswa, cariNama);
    if (indexSeq != -1) {
        cout << "\nDitemukan (Sequential Search):" << endl;
        printMahasiswa(mahasiswa[indexSeq]);
    } else {
        cout << "\nData tidak ditemukan (Sequential Search)." << endl;
    }

    sort(mahasiswa.begin(), mahasiswa.end(), [](const Mahasiswa& a, const Mahasiswa& b) {
        return a.Nama < b.Nama;
    });

    int indexBin = binarySearch(mahasiswa, cariNama);
    if (indexBin != -1) {
        cout << "\nDitemukan (Binary Search):" << endl;
        printMahasiswa(mahasiswa[indexBin]);
    } else {
        cout << "\nData tidak ditemukan (Binary Search)." << endl;
    }

    return 0;
}
