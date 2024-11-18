#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

struct Mahasiswa {
    string NIM;
    string Nama;
    string Alamat;
    string Kelas;
    float Nilai;
};

string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int sequentialSearch(const vector<Mahasiswa>& data, const string& nama) {
    string normalizedNama = toLowerCase(trim(nama));
    cout << "Nama yang dicari (setelah normalisasi): " << normalizedNama << endl;

    for (int i = 0; i < data.size(); ++i) {
        string normalizedDataNama = toLowerCase(trim(data[i].Nama));
        cout << "Membandingkan dengan: " << normalizedDataNama << endl;

        if (normalizedDataNama == normalizedNama) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const vector<Mahasiswa>& data, const string& nama) {
    string normalizedNama = toLowerCase(trim(nama));
    int left = 0, right = data.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        string midNama = toLowerCase(trim(data[mid].Nama));

        cout << "Membandingkan dengan: " << midNama << endl;

        if (midNama == normalizedNama) {
            return mid;
        }
        if (midNama < normalizedNama) {
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
        {"532414011", "Andi Jio", "Gorontalo", "E", 90},
        {"532414010", "Tono Oji", "Gorontalo", "E", 90},
        {"532414009", "Oji K", "Gorontalo", "E", 90},
        {"532414008", "Andi SK", "Gorontalo", "E", 90}
    };

    string cariNama;
    cout << "Masukkan nama mahasiswa yang dicari:";
    getline(cin, cariNama);
    cout << "Nama yang dimasukkan: '" << cariNama << "' (dengan panjang " << cariNama.length() << ")" << endl;

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
