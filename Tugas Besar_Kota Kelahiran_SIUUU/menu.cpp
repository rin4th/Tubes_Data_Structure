#include "kota.h"

// ========= procudere Menu ==========
void menuMenambahData(ListNegara &N, char pilihan, char loop){
        cout<<"\t\tMenu Menambah Data\n\n";
        cout<<"1. Menambah Kota.\n";
        cout<<"2. Menambah data Kota Lahir penduduk.\n";
        cout<<"0. Back To Main Menu.\n";
        cout<<"\nPilih NO menu : ";
        cin>>pilihan;
        cout<<"\n";

        if (pilihan == '1'){
            while (loop == 'Y' || loop == 'y'){
                infotypeKota kota;
                cout<<"\t\tMenambah Kota\n\n";
                cout<<"Masukan Nama Kota : ";
                getline(cin, kota.namaKota);
                getline(cin, kota.namaKota);
                cout<<"Masukan Provinsi : ";
                getline(cin, kota.provinsi);
                cout<<"Masukan Jumlah Penduduk : ";
                cin>>kota.jmlPenduduk;

                adrKota newKota = createKota(kota);
                addKota(N, newKota);

                cout<<endl<<"Kota Berhasil Ditambahkan!!!"<<endl<<endl;
                cout<<"Menambah Kota lainya?? (Y/N) : ";
                cin>>loop;
                cout<<endl;
            }

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");
        }else if (pilihan == '2'){
            while (loop == 'Y' || loop == 'y'){
                infotypeOrang orang;
                string kotaLahir;
                cout<<"\t\tMenambah Kota Lahir Penduduk\n\n";
                cout<<"Masukan Nama Warga : ";
                getline(cin, orang.nama);
                getline(cin, orang.nama);
                cout<<"Masukan NIK : ";
                getline(cin, orang.nik);
                cout<<"Masukan Tanggal Lahir : ";
                getline(cin, orang.tanggal);
                cout<<"Masukan Jenis Kelamin : ";
                getline(cin, orang.jenisKelamin);
                cout<<"Masukan Kota Kelahiran : ";
                getline(cin, kotaLahir);
                cout<<"Masukan Usia : ";
                cin>>orang.usia;

                adrOrang newOrang = createOrang(orang);
                addOrang(N, kotaLahir, newOrang);

                cout<<endl<<"Data Berhasil Ditambahkan!!!"<<endl<<endl;
                cout<<"Menambah Data lainya?? (Y/N) : ";
                cin>>loop;
                cout<<endl;
            }

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");
        }else if (pilihan == '0'){
            sleep(0.5);
            system("cls");

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");
        }else{
            cout<<endl<<"WRONG INPUT!!!"<<endl<<endl;
            cout<<"Automation Back To Main Menu...";
            sleep(1);
            system("cls");
        }
}

void menuMenampilkanData(ListNegara N, char pilihan, char loop){
        while (loop == 'Y' || loop == 'y'){
            cout<<"\t\tMenu Menampilkan Data\n\n";
            cout<<"1. Menampilkan Kota.\n";
            cout<<"2. Menampilkan Kota Berdasarkan Provinsi.\n";
            cout<<"3. Menampilkan Data Penduduk pada Suatu Kota.\n";
            cout<<"4. Menampilkan Kota yang Terkecil dan Terbanyak Data.\n";
            cout<<"0. Back To Main Menu.\n";
            cout<<"\nPilih NO menu : ";
            cin>>pilihan;
            cout<<"\n";

            string namaKota;
            if (pilihan == '1'){
                cout<<"\t\tMenampilkan List Kota\n\n";
                printKota(N);

                cout<<"\n\nUlangi ? (Y/N) : ";
                cin>>loop;
                sleep(0.5);
                system("cls");

            }else if (pilihan == '2'){
                cout<<"\t\tMenampilkan List Kota By Provinsi\n\n";
                string provinsi;
                cout<<"Masukan Nama Provinsi : ";
                cin.get();
                getline(cin, provinsi);
                cout<<endl;
                printKotaByProvince(N, provinsi);

                cout<<"\n\nUlangi ? (Y/N) : ";
                cin>>loop;
                sleep(0.5);
                system("cls");

            }else if (pilihan == '3'){
                cout<<"\t\tMenampilkan Data Penduduk pada Suatu Kota\n\n";
                cout<<"Masukan Nama Kota : ";
                cin.get();
                getline(cin, namaKota);
                cout<<endl;
                printOrang(N, namaKota);

                cout<<"\n\nUlangi ? (Y/N) : ";
                cin>>loop;
                sleep(0.5);
                system("cls");

            }else if (pilihan == '4'){
                cout<<"\tMenampilkan Kota yang Terkecil dan Terbanyak Data\n\n";
                printLessPeople(N);
                cout<<endl<<"============================================"<<endl<<endl;
                printMostPeople(N);

                cout<<"\n\nUlangi ? (Y/N) : ";
                cin>>loop;
                sleep(0.5);
                system("cls");

            }else if (pilihan == '0'){
                sleep(0.5);
                system("cls");
                loop = 'N';

                cout<<"Back To Main Menu...";
                sleep(0.5);
                system("cls");

            }else{
                cout<<endl<<"WRONG INPUT!!!"<<endl<<endl;
                cout<<"Automation Back To Main Menu...";
                loop = 'N';
                sleep(1);
                system("cls");
            }
        }
}

void menuUpdateData(ListNegara &N, char pilihan, char loop){
        cout<<"\t\tMenu Update Data\n\n";
        cout<<"1. Update Kota.\n";
        cout<<"2. Update Data Orang pada Kota.\n";
        cout<<"0. Back TO Main Menu.\n";
        cout<<"\nPilih NO menu : ";
        cin>>pilihan;
        cout<<"\n";

        if (pilihan == '1'){
            while (loop == 'Y' || loop == 'y'){
                string namaKota;
                cout<<"\t\tMemperbarui Kota\n\n";
                cout<<"Masukan Nama Kota Lama : ";
                cin>>namaKota;

                adrKota foundKota = findKota(N, namaKota);

                if (foundKota != nil){
                    cout<<"\n\tMemperbarui Kota "<<infoKota(foundKota).namaKota<<endl;
                    cout<<"\nMasukan Nama Kota Baru : ";
                    getline(cin, infoKota(foundKota).namaKota);
                    getline(cin, infoKota(foundKota).namaKota);
                    cout<<"Masukan nama Provinsi Baru : ";
                    getline(cin, infoKota(foundKota).provinsi);
                    cout<<"Masukan Jumlah Penduduk Baru : ";
                    cin>>infoKota(foundKota).jmlPenduduk;

                    cout<<endl<<"Kota Berhasil Diperbarui!!!"<<endl<<endl;
                }else{
                    cout<<"\n\tKota "<<namaKota<<" Tidak Ditemukan\n\n";
                }


                cout<<"Memperbarui Kota lainya?? (Y/N) : ";
                cin>>loop;
                cout<<endl;
            }
            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");

        }else if (pilihan == '2'){
            while (loop == 'Y' || loop == 'y'){
                string nama, kota;
                cout<<"\t\tMemperbarui Data Kota Lahir Penduduk\n\n";
                cout<<"Masukan Nama Warga Yang Ingin Diperbarui : ";
                getline(cin, nama);
                getline(cin, nama);
                cout<<"Masukan Kota Kelahiran : ";
                getline(cin, kota);
                cout<<endl;

                adrOrang foundOrang = deleteOrang(N, kota, nama);

                if (foundOrang == nil){
                    cout<<"Nama "<<nama<<" Tidak Ditemukan\n";
                }else{
                    cout<<"Masukan Kota Kelahiran yang baru : ";
                    cin>>kota;
                    addOrang(N, kota, foundOrang);
                    cout<<endl<<"Data Berhasil Diperbarui!!!"<<endl<<endl;
                }


                cout<<"Memperbarui Data lainya?? (Y/N) : ";
                cin>>loop;
                cout<<endl;
            }

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");

        }else if (pilihan == '0'){
            sleep(0.5);
            system("cls");

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");

        }else{
            cout<<endl<<"WRONG INPUT!!!"<<endl<<endl;
            cout<<"Automation Back To Main Menu...";
            sleep(2);
            system("cls");
        }
}

void menuMenghapusData(ListNegara &N, char pilihan, char loop){
        cout<<"\t\tMenu Menghapus Data\n\n";
        cout<<"1. Menghapus Kota.\n";
        cout<<"2. Menghapus data Kota Lahir penduduk.\n";
        cout<<"0. Back To Main Menu.\n";
        cout<<"\nPilih NO menu : ";
        cin>>pilihan;
        cout<<"\n";

        if (pilihan == '1'){
            while (loop == 'Y' || loop == 'y'){
                string namaKota;
                cout<<"\t\tMenghapus Kota\n\n";
                cout<<"Masukan Nama Kota : ";
                getline(cin, namaKota);
                getline(cin, namaKota);

                adrKota deletedKota = deleteKota(N, namaKota);

                cout<<endl<<"Kota Berhasil Dihapus!!!"<<endl<<endl;
                cout<<"Menghapus Kota lainya?? (Y/N) : ";
                cin>>loop;
                cout<<endl;
            }

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");
        }else if (pilihan == '2'){
            while (loop == 'Y' || loop == 'y'){
                string kotaLahir, nama;
                cout<<"\t\tMenghapus Data Kota Lahir Penduduk"<<endl<<endl;
                cout<<"Masukan Nama Warga : ";
                cin.get();
                getline(cin, nama);
                cout<<"Masukan Kota Kelahiran : ";
                cin>>kotaLahir;

                adrOrang deletedData = deleteOrang(N, kotaLahir, nama);

                cout<<endl<<"Data Berhasil Dihapus!!!"<<endl<<endl;
                cout<<"Menghapus Data lainya?? (Y/N) : ";
                cin>>loop;
            }

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");
        }else if (pilihan == '0'){
            sleep(0.5);
            system("cls");

            cout<<"Back To Main Menu..."<<endl;
            sleep(0.5);
            system("cls");
        }else{
            cout<<endl<<"WRONG INPUT!!!"<<endl<<endl;
            cout<<"Automation Back To Main Menu...";
            sleep(1);
            system("cls");
        }
}

void logo(){
    cout<<
    "                                    +              #####                \n"
    "          Kelompok : SIUUUUU       / \\                                  \n"
    " _____        _____     __________/ o \\/\\_________      _________      \n"
    "|o o o|_______|    |___|               | | # # #  |____|o o o o  | /\\   \n"
    "|o o o|  * * *|: ::|. .|               |o| # # #  |. . |o o o o  |//\\\\  \n"
    "|o o o|* * *  |::  |. .| []  []  []  []|o| # # #  |. . |o o o o  |((|)) \n"
    "|o o o|**  ** |:  :|. .| []  []  []    |o| # # #  |. . |o o o o  |((|)) \n\n";
}
