# Pengenalan Depth-First Search (DFS)

## penjekalasan Singkat
Depth-First Search (DFS) adalah salah satu algoritma pencarian atau traversal yang digunakan dalam struktur data graf. DFS bekerja dengan menjelajahi satu cabang sedalam mungkin sebelum kembali dan menjelajahi cabang lainnya. Algoritma ini menggunakan struktur stack (baik secara eksplisit dengan implementasi stack atau secara implisit melalui rekursi) untuk melacak jalur yang telah dikunjungi.[1]
Pada implementasi DFS, algoritma dimulai dari sebuah simpul awal, menandainya sebagai telah dikunjungi, lalu bergerak ke simpul yang terhubung yang belum dikunjungi. Proses ini berlanjut hingga semua simpul yang terhubung telah dikunjungi. Jika tidak ada simpul baru yang dapat dikunjungi, algoritma akan kembali ke simpul sebelumnya menggunakan mekanisme backtracking[2].

### Definisi Struktur
```c
typedef struct {
    int hubungan[MAKS_NODE][MAKS_NODE];  // Matriks adjacency
    bool dikunjungi[MAKS_NODE];           // Status kunjungan node
} Graf;
```

#### Komponen Struktur Graf
- **Matriks Hubungan**: Representasi koneksi antar node
  - `hubungan[i][j] = 1` berarti node i terhubung dengan node j
  - Simetris (hubungan dua arah)
- **Array Dikunjungi**: Melacak status node yang sudah dikunjungi

## 🧩 Strategi Inisialisasi Graf

### Fungsi `inisialisasiGraf()`
```c
void inisialisasiGraf(Graf *g) {
    // Inisialisasi matriks hubungan dan status kunjungan
    g->hubungan[0][1] = g->hubungan[1][0] = 1;
    g->hubungan[0][2] = g->hubungan[2][0] = 1;
    g->hubungan[1][3] = g->hubungan[3][1] = 1;
    // ... koneksi lainnya
}
```

#### Karakteristik Graf
- 7 node total
- Struktur berbentuk pohon/graph tidak linear
- Setiap node memiliki beberapa koneksi

## 🔢 Implementasi Tumpukan (Stack)

### Struktur Tumpukan
```c
typedef struct {
    int data[MAKS_NODE];  // Penyimpanan node
    int atas;             // Penanda top tumpukan
} Tumpukan;
```

### Operasi Tumpukan
1. `tambahKeTumpukan()`: Menambah elemen
2. `ambilDariTumpukan()`: Mengambil elemen teratas
3. `tumpukanKosong()`: Mengecek kondisi tumpukan

## 🔄 Algoritma DFS Interaktif

### Alur Penelusuran
```c
while (!WindowShouldClose()) {
    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && !tumpukanKosong(&tumpukan)) {
        int sekarang = ambilDariTumpukan(&tumpukan);
        
        // Tandai node saat ini
        if (!g.dikunjungi[sekarang]) {
            g.dikunjungi[sekarang] = true;
        }

        // Telusuri tetangga yang belum dikunjungi
        for (int i = 0; i < MAKS_NODE; i++) {
            if (g.hubungan[sekarang][i] && !g.dikunjungi[i]) {
                tambahKeTumpukan(&tumpukan, i);
            }
        }
    }
}
```

### Mekanisme Penelusuran
1. Mulai dari node 0
2. Setiap klik mouse memajukan penelusuran
3. Tambahkan tetangga yang belum dikunjungi ke tumpukan
4. Ubah warna node yang sudah dikunjungi

## 🎨 Visualisasi Graf

### Fungsi `gambarGraf()`
- Menggambar garis hubungan antar node
- Pewarnaan node:
  - Merah: Sudah dikunjungi
  - Biru: Belum dikunjungi

## 📊 Karakteristik Implementasi

### Kelebihan
- Interaktif melalui kontrol mouse
- Visualisasi real-time proses DFS
- Implementasi sederhana

### Keterbatasan
- Graf statis (hubungan tidak berubah)
- Penelusuran dimulai dari node 0 secara tetap

## 🔬 Analisis Teknis

### Kompleksitas
- Waktu: O(V + E)
  - V: Jumlah node (7 dalam kasus ini)
  - E: Jumlah edge/koneksi
- Ruang: O(V) untuk tumpukan dan status kunjungan

### Fitur Unik
- Visualisasi berbasis Raylib
- Kontrol iteratif dengan mouse
- Pewarnaan dinamis node

## 🚀 Potensi Pengembangan
1. Tambahkan input dinamis untuk struktur graf
2. Implementasi algoritma DFS dengan variasi
3. Tambahkan animasi transisi antar node
4. Support untuk graf yang lebih kompleks

## 💡 Kesimpulan
Implementasi DFS ini menggabungkan konsep algoritma penelusuran graf dengan visualisasi interaktif, memberikan pendekatan yang menarik untuk memahami mekanisme depth-first search.
