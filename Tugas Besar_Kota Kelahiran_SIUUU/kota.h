#ifndef KOTA_H_INCLUDED
#define KOTA_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;

#define nextKota(p) (p)->nextKota
#define nextOrang(p) (p)->nextOrang
#define child(p) (p)->child
#define infoKota(p) (p)->infoKota
#define infoOrang(p) (p)->infoOrang
#define first(p) ((p).first)
#define nil NULL

typedef struct elmKota *adrKota;
typedef struct elmOrang *adrOrang;

struct Orang{
    string nama;
    string nik;
    string tanggal;
    string jenisKelamin;
    int usia;
};

struct Kota{
    string namaKota;
    string provinsi;
    int jmlPenduduk;
};

typedef Orang infotypeOrang;
typedef Kota infotypeKota;

struct elmKota{
    infotypeKota infoKota;
    adrKota nextKota;
    adrOrang child;
};

struct elmOrang{
    infotypeOrang infoOrang;
    adrOrang nextOrang;
};

struct ListNegara{
    adrKota first;
};

// fungsionalitas dasar
void createListNegara(ListNegara &N);
/*{F.S Mengembalikan Sebuah List Kosong}*/
adrKota createKota(infotypeKota kota);
/*{I.S Tersedia data sebuah kota
   F.S Mengembalikan alamat elmKota hasil alokasi, info berisi
   dari masukan}*/
adrOrang createOrang(infotypeOrang orang);
/*{I.S Tersedia data seorang warga
   F.S Mengembalikan alamat elmOrang hasil alokasi, info berisi
   dari masukan}*/
void addKota(ListNegara &N, adrKota kota);
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), dan sebuah
       pointer kota yang berisi alamat elmKota baru
   F.S Elemen baru yang ditambahkan sebagai elemen terakhir dari list N*/
void addOrang(ListNegara &N, string kota, adrOrang orang);
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), string berisi nama kota
        dan pointer orang yang berisi alamat elmOrang baru
   F.S Elemen Orang baru yang ditambahkan pada child elemen kota sebagai elemen terakhir dari child kota*/
adrKota findKota(ListNegara N, string kota);
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), string berisi nama kota
   F.S Mengembalikan pointer Elemen kota yang berisi kota yang ingin dicari*/
adrOrang findOrang(ListNegara N, string kota, string nama);
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), string berisi nama kota, dan string berupa nama orang
   F.S Mengembalikan pointer Elemen orang yang berisi identitas orang yang ingin dicari dari sebuah kota*/
void printKota(ListNegara N);
/*{
 IS: terdefinisi sebuah list N (mungkin kosong)
 FS: menampilkan isi dari list N yang berisi list kota secara vertikal
}*/
void printOrang(ListNegara N, string kota);
/*{
 IS: terdefinisi sebuah list N (mungkin kosong), dan string berupa nama kota
 FS: menampilkan isi dari child elemen kota yang berisi data warga yang lahir di sebuah kota secara vertikal
}*/
void printKotaByProvince(ListNegara N, string provinsi);
/*{
 IS: terdefinisi sebuah list N (mungkin kosong), dan string berupa nama provinsi
 FS: menampilkan isi dari list N yang berisi list kota dengan provinsi tertentu secara vertikal
}*/
adrKota deleteKota(ListNegara &N, string kota);
/*{
 IS: Terdefinisi sebuah list N (mungkin kosong), dan string berupa nama kota
 FS: Mengembalikan alamat elemen kota dari list L, dan elemen tersebut dihapus dari list L
}*/
adrOrang deleteOrang(ListNegara &N, string kota, string nama);
/*{
 IS: Terdefinisi sebuah list N (mungkin kosong), string berupa nama kota, dan string berupa nama seseorang
 FS: Mengembalikan alamat elemen Orang dari list elemen kota, dan elemen tersebut dihapus dari list L
}*/
int countOrang(ListNegara N, string kota);
/*{I.S Terdefinisi sebuah list N (mungkin kosong), dan string berupa nama kota
   F.S Mengembalikan jumlah data Orang yang ada dalam child elemen kota}*/
void printLessPeople(ListNegara N);
/*{I.S Terdefinisi sebuah list N (mungkin kosong)
   F.S Menampilkan data Kota dan jumlah datanya yang paling sedikit}*/
void printMostPeople(ListNegara N);
/*{I.S Terdefinisi sebuah list N (mungkin kosong)
   F.S Menampilkan data Kota dan jumlah datanya yang paling banyak}*/

// procedure menu
void menuMenambahData(ListNegara &N, char pilih, char loop);
void menuMenampilkanData(ListNegara N, char pilihan, char loop);
void menuUpdateData(ListNegara &N, char pilihan, char loop);
void menuMenghapusData(ListNegara &N, char pilihan, char loop);

// utils
string to_lower(string kata);

//logo
void logo();
#endif // KOTA_H_INCLUDED
