# Pencarian Data Mahasiswa

Program ini adalah implementasi pencarian data mahasiswa menggunakan **C++**. Program mendukung dua metode pencarian, yaitu **Sequential Search** dan **Binary Search**, dengan data yang disimpan dalam bentuk array dinamis (`std::vector`).

## Fitur
1. **Pencarian Sequential**:
   - Mencari data mahasiswa dengan membandingkan setiap elemen satu per satu.
2. **Pencarian Binary**:
   - Mencari data mahasiswa secara efisien dengan membagi data menjadi dua bagian.
   - **Catatan**: Data harus diurutkan berdasarkan nama sebelum melakukan binary search.

## Prasyarat
- Program ditulis dalam bahasa C++.
- Kompiler yang mendukung C++11 atau versi lebih baru (contoh: g++, clang).

## Struktur Data Mahasiswa
Program menggunakan `struct` untuk menyimpan data mahasiswa, dengan atribut:
- **NIM**: Nomor Induk Mahasiswa.
- **Nama**: Nama lengkap mahasiswa.
- **Alamat**: Alamat asal mahasiswa.
- **Kelas**: Kelas mahasiswa.
- **Nilai**: Nilai akhir mahasiswa.

Contoh data mahasiswa yang digunakan:
```cpp
vector<Mahasiswa> mahasiswa = {
    {"531424112", "Muhammad Robby Darmawan", "Gorontalo", "E", 90},
    {"532414011", "Andi Jio", "Gorontalo", "E", 90},
    {"532414010", "Tono Oji", "Gorontalo", "E", 90},
    {"532414009", "Oji K", "Gorontalo", "E", 90},
    {"532414008", "Andi SK", "Gorontalo", "E", 90}
};
```

## Cara Menjalankan Program
1. **Kompilasi Program:**
   - Gunakan perintah berikut untuk mengompilasi program:
     ```bash
     g++ -o main main.cpp
     ```

2. **Jalankan Program:**
   - Setelah kompilasi berhasil, jalankan program dengan perintah:
     ```bash
     ./main
     ```

3. **Masukkan Nama Mahasiswa:**
   - Program akan meminta Anda untuk memasukkan nama mahasiswa yang ingin dicari.
   - Contoh:
     ```
     Masukkan nama mahasiswa yang dicari: Muhammad Robby Darmawan
     ```

4. **Hasil Pencarian:**
   - Jika nama ditemukan, program akan menampilkan detail mahasiswa menggunakan kedua metode pencarian.
   - Jika nama tidak ditemukan, program akan menampilkan pesan bahwa data tidak ditemukan.

## Contoh Output
### Input:
```
Masukkan nama mahasiswa yang dicari: Muhammad Robby Darmawan
```

### Output:
```
Ditemukan (Sequential Search):
NIM: 531424112
Nama: Muhammad Robby Darmawan
Alamat: Gorontalo
Kelas: E
Nilai: 90

Ditemukan (Binary Search):
NIM: 531424112
Nama: Muhammad Robby Darmawan
Alamat: Gorontalo
Kelas: E
Nilai: 90
```

### Jika Tidak Ditemukan:
```
Data tidak ditemukan (Sequential Search).
Data tidak ditemukan (Binary Search).
```

## Catatan
1. Pastikan nama yang dimasukkan sesuai dengan nama di data mahasiswa (termasuk huruf besar dan kecil).
2. Gunakan fungsi `getline` untuk memastikan input nama lengkap dapat diterima dengan benar.