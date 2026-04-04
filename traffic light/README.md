# Traffic Light

[![Tinkercad Simulation](https://img.shields.io/badge/Tinkercad-Simulasi_Project-blue?style=for-the-badge&logo=autodesk)](https://www.tinkercad.com/things/7UwrD4YkNO4)

##  Deskripsi Proyek
Proyek ini adalah implementasi sistem tertana untuk mengendalikan simulasi lampu lalu lintas 4 simpang secara otomatis menggunakan mikrokontroler Arduino Uno.

##  Spesifikasi Sistem
Sistem ini dirancang dengan logika *state machine* sederhana yang berjalan secara berulang (*looping*), dengan mematuhi protokol lalu lintas berikut:

1. **Kondisi Default:** Semua lampu berada dalam status logika `HIGH` pada pin MERAH (menyala) sebelum siklus persimpangan pertama diaktifkan.
2. **Sekuensial Arah:** Siklus lampu hijau berjalan secara bergiliran searah jarum jam dengan urutan: **Utara → Timur → Selatan → Barat → Ulangi**.
3. **Manajemen Waktu (Timing):**
   - **Lampu Hijau:** Menyala statis selama `5000 ms` (5 detik).
   - **Lampu Kuning:** Memberikan indikasi transisi berupa efek berkedip (*blinking*) sebanyak 3 kali (interval `300 ms`), dilanjutkan dengan menyala statis selama `2000 ms` (2 detik)[cite: 26].
   - **Lampu Merah:** Kembali menyala (*state* aktif) sesaat setelah siklus hijau dan kuning pada simpang tersebut selesai.
4. **Safety Constraint:** Sistem menjamin **tidak ada lebih dari satu sisi** yang mengaktifkan lampu hijau secara bersamaan.

## Kebutuhan Perangkat Keras
- 1x Arduino Uno R3
- 1x Breadboard (Small/Full)
- 12x LED (4x Merah, 4x Kuning, 4x Hijau)
- 12x Resistor (220Ω / 330Ω)
- Kabel Jumper secukupnya

## Pin Mapping
Konfigurasi kabel dari pin digital Arduino ke komponen LED (Anoda) di-mapping secara sekuensial untuk memudahkan pembacaan kode:

| Persimpangan | LED Merah (Red) | LED Kuning (Yellow) | LED Hijau (Green) |
| :--- | :---: | :---: | :---: |
| **Utara (North)** | Pin 13 | Pin 12 | Pin 11 |
| **Timur (East)** | Pin 10 | Pin 9  | Pin 8  |
| **Selatan (South)**| Pin 7  | Pin 6  | Pin 5  |
| **Barat (West)** | Pin 4  | Pin 3  | Pin 2  |

> **Catatan:** Semua kaki Katoda LED dihubungkan secara paralel ke pin `GND` pada Arduino melalui resistor penahan arus.

## Struktur Kode & Modularitas
Sistem menggunakan pendekatan *modular design* dengan membagi program ke dalam beberapa fungsi utama:
- `setup()`: Menginisiasi pin digital 2-13 sebagai `OUTPUT` dan memanggil kondisi *default*.
- `loop()`: Mengatur antrean pemanggilan fungsi utama secara sekuensial.
- `allRed()`: Fungsi untuk memaksa semua *state* lampu menjadi Merah.
- `activateIntersection(pinRed, pinYellow, pinGreen)`: Fungsi dinamis berskala yang menerima argumen parameter pin dari persimpangan target, mengatur *timing* *delay*, dan mengeksekusi transisi *state* secara terisolasi.

## Cara Menjalankan Simulasi
1. Buka tautan simulasi Tinkercad yang tersedia pada *badge* di atas.
2. Klik tombol **Start Simulation** di pojok kanan atas layar.
3. Observasi siklus lampu yang menyala.
4. Buka tab **Code** untuk melihat dan memodifikasi *source code* secara langsung.

## Profil Pengembang
**Naufal Satrio Putra** *H1D024079 | Informatika, Fakultas Teknik* Universitas Jenderal Soedirman  
