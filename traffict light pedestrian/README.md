# 🚦 Pedestrian Traffic Light dengan External Interrupt (Arduino Uno)

[![Tinkercad Simulation](https://img.shields.io/badge/Tinkercad-Simulasi_Project-blue?style=for-the-badge&logo=autodesk)]https://www.tinkercad.com/things/7UwrD4YkNO4-traffict-light
[![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](#)

## 📌 Deskripsi Proyek
Proyek ini merupakan modifikasi dari sistem *Traffic Light* 4 Simpang, yang kini dikembangkan menjadi sistem **Pedestrian Traffic Light (Lampu Penyeberangan Pejalan Kaki)**. Proyek ini disusun untuk memenuhi Tugas 4 mata kuliah Pemrograman Sistem Tertanam. 

Fokus utama dari pengembangan proyek ini adalah implementasi **External Interrupt (Interupsi Perangkat Keras)**. Dengan menggunakan interupsi, mikrokontroler tidak perlu melakukan *polling* (pengecekan tombol secara terus-menerus di dalam fungsi `loop()`), melainkan dapat merespons penekanan tombol penyeberang secara instan dan asinkronus.

## ⚙️ Logika Kerja Sistem (*State Machine*)
Sistem beroperasi dengan transisi *state* berikut:

1. **Kondisi Awal (*Default State*):**
   - Lampu Kendaraan (Jalan Raya): **HIJAU**
   - Lampu Pedestrian 1 & 2: **MERAH**
2. **Saat Tombol Ditekan (*Interrupt Triggered*):**
   - Sistem merespons seketika tanpa jeda.
   - Lampu Kendaraan: Berubah menjadi **MERAH**
   - Lampu Pedestrian 1 & 2: Berubah menjadi **HIJAU** (Sistem menahan *state* ini selama 5 detik untuk memberi waktu pejalan kaki menyeberang).
3. **Fase Transisi:**
   - Setelah 5 detik, Lampu Pedestrian 1 & 2 kembali **MERAH**.
   - Lampu Kendaraan memasuki fase **KUNING** selama 2 detik sebagai peringatan bagi pengendara.
4. **Kembali ke Kondisi Awal:**
   - Lampu Kendaraan kembali **HIJAU** dan Lampu Pedestrian tetap **MERAH** hingga interupsi berikutnya dipicu.

## 🛠️ Kebutuhan Perangkat Keras (Hardware)
- 1x Arduino Uno R3
- 1x Breadboard
- 1x Push Button (Tombol Tactile)
- 7x LED (3x Merah, 1x Kuning, 3x Hijau)
- 7x Resistor (220Ω / 330Ω) untuk LED
- Kabel Jumper secukupnya

## 🔌 Pin Mapping (Alokasi GPIO)
Konfigurasi kabel dari pin digital Arduino ke komponen telah disesuaikan agar rapi dan terstruktur:

| Komponen | LED Merah | LED Kuning | LED Hijau |
| :--- | :---: | :---: | :---: |
| **Pedestrian 1 (Kiri)** | Pin 13 | - | Pin 12 |
| **Pedestrian 2 (Kanan)**| Pin 11 | - | Pin 10 |
| **Kendaraan (Jalan)** | Pin 7  | Pin 6 | Pin 5  |

**Konfigurasi Input Interupsi:**
- **Push Button:** Terhubung secara diagonal ke **Pin 2 (INT0)** dan **GND**.

## 💻 Implementasi Teknis: Interrupt & Volatile
Proyek ini menggunakan fitur `attachInterrupt()` bawaan Arduino pada pin 2 (INT0). Konfigurasi spesifik yang diterapkan meliputi:
- `INPUT_PULLUP`: Pin 2 dikonfigurasi menggunakan resistor *pull-up* internal, sehingga kondisi *default*-nya adalah `HIGH`.
- `FALLING`: Interupsi dipicu saat terjadi transisi logika dari `HIGH` ke `LOW` (saat tombol ditekan dan menghubungkan pin ke GND).
- `volatile bool`: Variabel *flag* (`adaPenyebrang`) dideklarasikan dengan *keyword* `volatile` agar mikrokontroler selalu membaca nilainya langsung dari RAM, mencegah optimasi *compiler* yang dapat menyebabkan *bug* pada pembacaan status interupsi.

## 🚀 Cara Menjalankan Simulasi
1. Buka tautan simulasi Tinkercad yang tersedia pada *badge* di atas.
2. Klik tombol **Start Simulation** di pojok kanan atas layar.
3. Observasi bahwa lampu jalan berwarna Hijau dan pedestrian berwarna Merah.
4. Klik **Push Button** untuk memicu interupsi, dan amati perubahan *state* secara *real-time*.

## 👨‍💻 Profil Pengembang
**Naufal Satrio Putra** *H1D024079 | Informatika, Fakultas Teknik* Universitas Jenderal Soedirman  
<br>
Dicoding Elite Code Reviewer (Front-End & Back-End)

---
*Dibuat untuk pemenuhan Tugas Pemrograman Sistem Tertanam - 2026*