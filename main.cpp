#include <iostream>
using namespace std;

struct Mahasiswa {
    char NIM[12];
    char Nama[50];
    char Alamat[50];
    char Kelas[5];
    float Nilai;
};

char* toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + ('a' - 'A');
        }
    }
    return str;
}

char* trim(char* str) {
    int start = 0;
    while (str[start] == ' ') {
        start++;
    }
    
    int end = 0;
    while (str[end] != '\0') {
        end++;
    }
    end--;
    while (str[end] == ' ') {
        end--;
    }
    
    int j = 0;
    for (int i = start; i <= end; i++) {
        str[j++] = str[i];
    }
    str[j] = '\0';
    return str;
}

char* myStrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

int myStrcmp(const char* str1, const char* str2) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int sequentialSearch(Mahasiswa data[], int size, const char* nama) {
    int posisi = -1;
    char normalizedNama[50];
    myStrcpy(normalizedNama, nama);
    toLowerCase(normalizedNama);
    trim(normalizedNama);

    for (int i = 0; i < size; ++i) {
        char normalizedDataNama[50];
        myStrcpy(normalizedDataNama, data[i].Nama);
        toLowerCase(normalizedDataNama);
        trim(normalizedDataNama);

        if (myStrcmp(normalizedDataNama, normalizedNama) == 0) {
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

int binarySearch(Mahasiswa data[], int size, const char* nama) {
    int posisi = -1;
    char normalizedNama[50];
    myStrcpy(normalizedNama, nama);
    toLowerCase(normalizedNama);
    trim(normalizedNama);

    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        char midNama[50];
        myStrcpy(midNama, data[mid].Nama);
        toLowerCase(midNama);
        trim(midNama);

        if (myStrcmp(midNama, normalizedNama) == 0) {
            posisi = mid;
            cout << "Data Ditemukan" << endl;
            break;
        }
        if (myStrcmp(midNama, normalizedNama) < 0) {
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
            if (myStrcmp(data[j].Nama, data[j + 1].Nama) > 0) {
                swap(data[j], data[j + 1]);
            }
        }
    }
    return data;
}

char* printMahasiswa(const Mahasiswa& mhs, char* buffer) {
    sprintf(buffer, "NIM: %s\nNama: %s\nAlamat: %s\nKelas: %s\nNilai: %.2f\n", mhs.NIM, mhs.Nama, mhs.Alamat, mhs.Kelas, mhs.Nilai);
    return buffer;
}

int main() {
    const int size = 5;
    Mahasiswa mahasiswa[size] = {
        {"531424112", "Uji C", "Gorontalo", "E", 90},
        {"532414011", "Andi Jio", "Gorontalo", "E", 90},
        {"532414010", "Tono Oji", "Gorontalo", "E", 90},
        {"532414009", "Oji K", "Gorontalo", "E", 90},
        {"532414008", "Andi SK", "Gorontalo", "E", 90}
    };

    char cariNama[50];
    char lg = 'Y';
    char buffer[200];

    while (lg == 'Y' || lg == 'y') {
        cout << "Masukkan nama mahasiswa yang dicari: ";
        cin.getline(cariNama, 50);

        cout << "\nMencari dengan Sequential Search...\n";
        int indexSeq = sequentialSearch(mahasiswa, size, cariNama);
        if (indexSeq != -1) {
            cout << "\nDitemukan (Sequential Search):\n";
            cout << printMahasiswa(mahasiswa[indexSeq], buffer) << endl;
        } else {
            cout << "\nData tidak ditemukan (Sequential Search).\n";
        }

        Mahasiswa* sortedData = sortData(mahasiswa, size);

        cout << "\nMencari dengan Binary Search...\n";
        int indexBin = binarySearch(sortedData, size, cariNama);
        if (indexBin != -1) {
            cout << "\nDitemukan (Binary Search):\n";
            cout << printMahasiswa(mahasiswa[indexBin], buffer) << endl;
        } else {
            cout << "\nData tidak ditemukan (Binary Search).\n";
        }

        cout << "Mau Coba Lagi (Y/T)? ";
        cin >> lg;
        cin.ignore();
    }

    return 0;
}
