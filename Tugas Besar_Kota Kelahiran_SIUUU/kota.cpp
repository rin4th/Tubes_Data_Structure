#include "kota.h"

void createListNegara(ListNegara &N){
    /*{F.S Mengembalikan Sebuah List Kosong}*/
    first(N) = nil;
}

adrKota createKota(infotypeKota kota){
/*{I.S Tersedia data sebuah kota
   F.S Mengembalikan alamat elmKota hasil alokasi, info berisi
   dari masukan}*/
    adrKota p = new elmKota;
    infoKota(p) = kota;
    nextKota(p) = nil;
    child(p) = nil;
    return p;
}

adrOrang createOrang(infotypeOrang orang){
/*{I.S Tersedia data seorang warga
   F.S Mengembalikan alamat elmOrang hasil alokasi, info berisi
   dari masukan}*/
    adrOrang p = new elmOrang;
    infoOrang(p) = orang;
    nextOrang(p) = nil;
    return p;
}

void addKota(ListNegara &N, adrKota kota){
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), dan sebuah
       pointer kota yang berisi alamat elmKota baru
   F.S Elemen baru yang ditambahkan sebagai elemen terakhir dari list N*/
    if (first(N) == nil){
        first(N) = kota;
    }else{
        adrKota p = first(N);
        while (nextKota(p) != nil){
            p = nextKota(p);
        }
        nextKota(p) = kota;
    }
}

void addOrang(ListNegara &N, string kota, adrOrang orang){
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), string berisi nama kota
        dan pointer orang yang berisi alamat elmOrang baru
   F.S Elemen Orang baru yang ditambahkan pada child elemen kota sebagai elemen terakhir dari child kota*/
    adrKota p = findKota(N, kota);
    if (p == nil){
        cout<<endl<<"Tidak Ada Kota "<<kota<<endl;
    }else if (child(p) == nil){
        child(p) = orang;
        infoKota(p).jmlPenduduk++;
    }else{
        adrOrang q = child(p);
        while (nextOrang(q) != nil){
            q = nextOrang(q);
        }
        nextOrang(q) = orang;
        infoKota(p).jmlPenduduk++;
    }
}

adrKota findKota(ListNegara N, string kota){
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), string berisi nama kota
   F.S Mengembalikan pointer Elemen kota yang berisi kota yang ingin dicari*/
    adrKota p = first(N);

    while (p != nil){
        if (to_lower(infoKota(p).namaKota) == to_lower(kota)){
            return p;
        }
        p = nextKota(p);
    }
    return nil;
}

adrOrang findOrang(ListNegara N, string kota, string nama){
/*{I.S Terdefinisi Sebuah ListNegara N dengan kota (mungkin kosong), string berisi nama kota, dan string berupa nama orang
   F.S Elemen orang yang berisi identitas orang yang ingin dicari dari sebuah kota*/
    adrKota p = findKota(N, kota);
    adrOrang q = child(p);

    while (q != nil){
        if (to_lower(infoOrang(q).nama) == to_lower(nama)){
            return q;
        }
        q = nextOrang(q);
    }
    return nil;
}

void printKota(ListNegara N){
/*{
 IS: terdefinisi sebuah list N (mungkin kosong)
 FS: menampilkan isi dari list N yang berisi list kota secara vertikal
}*/
    adrKota p = first(N);

    if (p == nil){
        cout<<"\nTidak Ada Kota\n";
    }else{
        int counter = 1;
        while (p != nil){
            cout<<"["<<counter<<"]\tNama Kota : "<<infoKota(p).namaKota;
            cout<<"\n\tProvinsi : "<<infoKota(p).provinsi;
            cout<<"\n\tJumlah Penduduk : "<<infoKota(p).jmlPenduduk<<endl<<endl;
            p = nextKota(p);
            counter++;
        }
    }
}

void printOrang(ListNegara N, string kota){
/*{
 IS: terdefinisi sebuah list N (mungkin kosong), dan string berupa nama kota
 FS: menampilkan isi dari child elemen kota yang berisi data warga yang lahir di sebuah kota secara vertikal
}*/
    adrKota p = findKota(N, kota);

    if (p == nil){
        cout<<"\nTidak Ada Kota "<<kota<<endl;
    }else{
        adrOrang q = child(p);
        int counter = 1;
        if (q == nil){
            cout<<"Tidak ada Data Warga";
        }
        while (q != nil){
            cout<<"["<<counter<<"]\tNama : "<<infoOrang(q).nama<<"\n\tTanggal Lahir : ";
            cout<<infoOrang(q).tanggal<<"\n\tJenis Kelamin : "<<infoOrang(q).jenisKelamin<<"\n\tUsia : "<<infoOrang(q).usia<<endl<<endl;
            q = nextOrang(q);
            counter++;
        }
    }
}

void printKotaByProvince(ListNegara N, string provinsi){
/*{
 IS: terdefinisi sebuah list N (mungkin kosong), dan string berupa nama provinsi
 FS: menampilkan isi dari list N yang berisi list kota dengan provinsi tertentu secara vertikal
}*/
    adrKota p = first(N);

    if (p == nil){
        cout<<"\nTidak Ada Kota "<<endl;
    }else{
        int counter = 1;
        while (p != nil){
            if (infoKota(p).provinsi == provinsi){
                cout<<"["<<counter<<"]\tNama Kota : "<<infoKota(p).namaKota<<"\n\tProvinsi : ";
                cout<<infoKota(p).provinsi<<"\n\tJumlah Penduduk : "<<infoKota(p).jmlPenduduk<<endl<<endl;
                p = nextKota(p);
                counter++;
            }
        }
    }
}


adrKota deleteKota(ListNegara &N, string kota){
/*{
 IS: Terdefinisi sebuah list N (mungkin kosong), dan string berupa nama kota
 FS: Mengembalikan alamat elemen kota dari list L, dan elemen tersebut dihapus dari list L
}*/
    adrKota p = findKota(N, kota);

    if (p == nil){
        // Mengecek Kota
        cout<<endl<<"Tidak terdapat Kota"<<endl;
    }else{
        // delete
        if (p == first(N)){
            // delete first
            first(N) = nextKota(p);
            nextKota(p) = nil;
        }else{
            // delete after
            adrKota q = first(N);
            while (nextKota(q) != p){
                q = nextKota(q);
            }
            nextKota(q) = nextKota(p);
            nextKota(p) = nil;
            return p;
        }
    }
    return nil;
}

adrOrang deleteOrang(ListNegara &N, string kota, string nama){
/*{
 IS: Terdefinisi sebuah list N (mungkin kosong), string berupa nama kota, dan string berupa nama seseorang
 FS: Mengembalikan alamat elemen Orang dari list elemen kota, dan elemen tersebut dihapus dari list L
}*/
    adrKota p = findKota(N, kota);

    if (p == nil){
        // Mengecek Kota
        cout<<endl<<"Tidak terdapat Kota "<<kota<<endl;
    }else{
        // delete
        if (child(p) == nil){
            cout<<endl<<"Tidak ada Data"<<endl<<endl;
        }else{
            adrOrang q = child(p);
            if (infoOrang(q).nama == nama){
                // delete first
                child(p) = nextOrang(q);
                nextOrang(q) = nil;
                return q;
            }else{
                // delete after "r"
                adrOrang r = q;
                q = nextOrang(q);
                while (q != nil){
                    if (infoOrang(q).nama == nama){
                        nextOrang(r) = nextOrang(q);
                        nextOrang(q) = nil;
                        return q;
                    }
                    q = nextOrang(q);
                }
            }
        }
    }
    return nil;
}

int countOrang(ListNegara N, string kota){
/*{I.S Terdefinisi sebuah list N (mungkin kosong), dan string berupa nama kota
   F.S Mengembalikan jumlah data Orang yang ada dalam child elemen kota}*/
    int counter = 0;
    adrKota p = findKota(N, kota);
    adrOrang q = child(p);
    while (q != nil){
        counter++;
        q = nextOrang(q);
    }
    return counter;
}

void printLessPeople(ListNegara N){
/*{I.S Terdefinisi sebuah list N (mungkin kosong)
   F.S Menampilkan data Kota dan jumlah datanya yang paling sedikit}*/
    if (first(N) ==  nil){
        cout<<"Tidak ada Kota"<<endl;
    }else{
        adrKota p = first(N);
        int lowest = countOrang(N, infoKota(p).namaKota);
        adrKota cityLow = p;
        while (p != nil){
            int temp = countOrang(N, infoKota(p).namaKota);
            if (temp < lowest){
                lowest = temp;
                cityLow = p;
            }
            p = nextKota(p);
        }
        cout<<"\tKota yang Paling Sedikit Data"<<endl<<endl;
        cout<<"Nama Kota\t: "<<infoKota(cityLow).namaKota<<endl;
        cout<<"Jumlah Penduduk\t: "<<infoKota(cityLow).jmlPenduduk<<endl;
        cout<<"Jumlah Data\t: "<<lowest<<" Data."<<endl;
    }
}

void printMostPeople(ListNegara N){
/*{I.S Terdefinisi sebuah list N (mungkin kosong)
   F.S Menampilkan data Kota dan jumlah datanya yang paling banyak}*/
    if (first(N) ==  nil){
        cout<<"Tidak ada Kota"<<endl;
    }else{
        adrKota p = first(N);
        int highest = countOrang(N, infoKota(p).namaKota);
        adrKota cityHigh = p;
        while (p != nil){
            int temp = countOrang(N, infoKota(p).namaKota);
            if (temp > highest){
                highest = temp;
                cityHigh = p;
            }
            p = nextKota(p);
        }
        cout<<"\tKota yang Paling Banyak Data"<<endl<<endl;
        cout<<"Nama Kota\t: "<<infoKota(cityHigh).namaKota<<endl;
        cout<<"Jumlah Penduduk\t: "<<infoKota(cityHigh).jmlPenduduk<<endl;
        cout<<"Jumlah Data\t: "<<highest<<" Data."<<endl;
    }
}

// utils

string to_lower(string kata){
    string data = kata;
    transform(data.begin(), data.end(), data.begin(),
    [](unsigned char c){ return std::tolower(c); });

    return data;
}

