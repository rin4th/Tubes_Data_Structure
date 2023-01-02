#include "kota.h"

using namespace std;

int main()
{


    // Inisialisasi Main List (ListNegara)
    ListNegara N;
    createListNegara(N);

    char menu = 'Y';

    while (menu == 'Y' || menu == 'y'){
        logo();
        cout<<"===================================================="<<endl;
        cout<<"\t\tTugas Besar"<<endl;
        cout<<"Judul\t: Kota Lahir"<<endl;
        cout<<"Tema\t: Multi Linked-List Tipe B (1 to N)"<<endl;
        cout<<"Anggota :"<<endl;
        cout<<"\t 1. Rizal Nur Arbaatun (1301210044)"<<endl;
        cout<<"\t 2. Key Immanuel (1301210302)"<<endl;
        cout<<"===================================================="<<endl;

        cout<<endl<<"\t\tMain Menu"<<endl<<endl;
        cout<<"1. Menambah Data."<<endl;
        cout<<"2. Menampilkan Data."<<endl;
        cout<<"3. Memperbarui Data."<<endl;
        cout<<"4. Menghapus Data."<<endl;
        cout<<"0. Exit."<<endl;

        char pilih;
        cout<<endl<<"Pilih NO menu : ";
        cin>>pilih;
        sleep(0.5);

        if (pilih == '1' || pilih == '2' || pilih == '3' || pilih == '4'){
            system("cls");
            cout<<"Loading..."<<endl;
            sleep(0.5);
            system("cls");
        }

        char loop = 'Y';
        switch (pilih){
        case '1':
            menuMenambahData(N, pilih, loop);
            break;
        case '2':
            menuMenampilkanData(N, pilih, loop);
            break;
        case '3':
            menuUpdateData(N, pilih, loop);
            break;
        case '4':
            menuMenghapusData(N, pilih, loop);
            break;
        case '0':
            menu = 'N';
            cout<<endl<<"Thanks For Using Our Program."<<endl;
            break;
        default:
            cout<<endl<<"WRONG INPUT!!!"<<endl<<endl;
            cout<<"Automation Back To Main Menu...";
            sleep(0.5);
            system("cls");
        }
    }

    return 0;
}
