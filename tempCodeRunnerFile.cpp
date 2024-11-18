#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string NIM;
    string Nama;
    string Alamat;
    string Kelas;
    float Nilai;
};

string toLowerCase(string str) {
    for (char &c : str) {
        if (c >= 'A' && c <= 'Z') {
            c = c + ('a' - 'A');
        }
    }
    return str;
}

string trim(const string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int sequentialSearch(const Mahasiswa data[], int size, const string& nama) {
    int posisi = -1;
    string normalizedNama = toLowerCase(trim(nama));
    for (int i = 0; i < size; ++i) {
        if (toLowerCase(trim(data[i].Nama)) == normalizedNama) {
            posisi = i;
            cout << "Data Ditemukan" << endl;
            break;
        }
    }
    if (posisi == -1) {
        cout << "Data Tersebut Tidak Ada" << endl;
    }
    return posisi;
}

int binarySearch(Mahasiswa data[], int size, const string& nama) {
    int posisi = -1;
    string normalizedNama = toLowerCase(trim(nama));
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        string midNama = toLowerCase(trim(data[mid].Nama));
        if (midNama == normalizedNama) {
            posisi = mid;
            cout << "Data Ditemukan" << endl;
            break;
        }
        if (midNama < normalizedNama) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    if (posisi == -1) {
        cout << "Data Tersebut Tidak Ada" << endl;
    }
    return posisi;
}

Mahasiswa* sortData(Mahasiswa data[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data[j].Nama > data[j + 1].Nama) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    return data;
}

string printMahasiswa(const Mahasiswa& mhs) {
    return "NIM: " + mhs.NIM + "\n" +
           "Nama: " + mhs.Nama + "\n" +
           "Alamat: " + mhs.Alamat + "\n" +
           "Kelas: " + mhs.Kelas + "\n" +
           "Nilai: " + to_string(mhs.Nilai) + "\n";
}

int main() {
    Mahasiswa mahasiswa[] = {
        {"531424112", "Uji C", "Gorontalo", "E", 90},
        {"532414011", "Andi Jio", "Gorontalo", "E", 90},
        {"532414010", "Tono Oji", "Gorontalo", "E", 90},
        {"532414009", "Oji K", "Gorontalo", "E", 90},
        {"532414008", "Andi SK", "Gorontalo", "E", 90}
    };
    int size = sizeof(mahasiswa) / sizeof(mahasiswa[0]);

    string cariNama;
    char lg = 'Y';
    while (lg == 'Y' || lg == 'y') {
        cout << "Masukkan nama mahasiswa yang dicari: ";
        getline(cin, cariNama);

        cout << "\nMencari dengan Sequential Search...\n";
        int indexSeq = sequentialSearch(mahasiswa, size, cariNama);
        if (indexSeq != -1) {
            cout << "\nDitemukan (Sequential Search):\n";
            cout << printMahasiswa(mahasiswa[indexSeq]) << endl;
        } else {
            cout << "\nData tidak ditemukan (Sequential Search).\n";
        }

        Mahasiswa* sortedData = sortData(mahasiswa, size);

        cout << "\nMencari dengan Binary Search...\n";
        int indexBin = binarySearch(sortedData, size, cariNama);
        if (indexBin != -1) {
            cout << "\nDitemukan (Binary Search):\n";
            cout << printMahasiswa(mahasiswa[indexBin]) << endl;
        } else {
            cout << "\nData tidak ditemukan (Binary Search).\n";
        }

        cout << "Mau Coba Lagi (Y/T)? ";
        cin >> lg;
        cin.ignore();
    }

    return 0;
}
