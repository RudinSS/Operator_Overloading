#include <iostream>
#include <conio.h>
#include "include/persegiPanjang.hpp"
using namespace std;

// NAMA       : Jihad Amal Farid
// NRP        : 5024211072
// DEPARTEMEN : Teknik Komputer
// KELAS 	  : Proglan B

void endProgram(){
    system("cls || clear");
    getch();
}

int main(){
    int pilihan;
    const char *index[4] = {"xmin", "xmax", "ymin", "ymax"};
    float panjang, lebar, tx, ty;
    persegiPanjang pp3(0,0,0,0);


    cout << "Masukkan Data Persegi Panjang 1" << endl;
    cout << "Panjang (Sumbu X) : "; cin >> panjang;
    cout << "Lebar (Sumbu Y) : "; cin >> lebar;
    cout << "Titik Tengah X : "; cin >> tx;
    cout << "Titik Tengah Y : "; cin >> ty; cout << endl;
    persegiPanjang pp1(tx, ty, panjang, lebar);

    cout << "Masukkan Data Persegi Panjang 2" << endl;
    cout << "Panjang (Sumbu X) : "; cin >> panjang;
    cout << "Lebar (Sumbu Y) : "; cin >> lebar; 
    cout << "Titik Tengah X : "; cin >> tx;
    cout << "Titik Tengah Y : "; cin >> ty; cout << endl;
    persegiPanjang pp2(tx, ty, panjang, lebar);

    system("cls || clear");

    while (true){
		cout << endl;
        cout << "Data Awal" << endl;
        cout << "PERSEGI PANJANG 1" << endl; 
        pp1.output();
        cout << endl;
        cout << "PERSEGI PANJANG 2" << endl;
        pp2.output();
        cout << endl << endl;
        cout << "Pilih operator yang digunakan (1-6)" << endl;
        cout << "1. +" << endl;
        cout << "2. -" << endl;
        cout << "3. ++" << endl;
        cout << "4. --" << endl;
        cout << "5. []" << endl;
        cout << "6. ==" << endl;
		cout << "7. (exit)" << endl;
        cout << "Pilihan anda : "; cin >> pilihan;
        switch (pilihan){
        case 1:
            {
                system("cls || clear");
                cout << endl;
                cout << "OPERATOR + (Hasil Penjumlahan antara pp1 dan pp2)" << endl;
                pp3 = pp1 + pp2;
                if (pp1==pp2){
                    pp3.output();
                }
                getch();
            }
            break;
        case 2:
            {
                system("cls || clear");
                cout << endl;
                cout << "OPERATOR - (Hasil Pengurangan antara pp1 dan pp2)" << endl;
                pp3 = pp1 - pp2;
                if (pp1==pp2){
                    pp3.output();
                }
                getch();
            }
            break;
        case 3:
            {
                system("cls || clear");
                cout << endl;
                cout << "OPERATOR ++ (Luas persegi panjang 2 kali lebih besar)" << endl;
                cout << "Masukkan Persegi Panjang yang ingin dikenakan operator ++ (1 atau 2) : "; cin >> pilihan; cout << endl;
                if (pilihan == 1){
                    ++pp1;
                    cout << "Persegi Panjang 1 setelah diberi Operator ++ : " << endl;
                    pp1.output();
                    --pp1;
                }else if(pilihan == 2){
                    ++pp2;
                    cout << "Persegi Panjang 2 setelah diberi Operator ++ : " << endl;
                    pp2.output();
                    --pp2;
                }
                getch();
            }
            break;
        case 4:
            {
                system("cls || clear");
                cout << endl;
                cout << "OPERATOR -- (Luas persegi panjang 2 kali lebih kecil)" << endl;
                cout << "Persegi Panjang yang ingin dikenakan operator -- (1 atau 2): "; cin >> pilihan; cout << endl;
                if (pilihan == 1){
                    --pp1;
                    cout << "Persegi Panjang 1 setelah diberi Operator -- : " << endl;
                    pp1.output();
                    ++pp1;
                }else if(pilihan == 2){
                    --pp2;
                    cout << "Persegi Panjang 2 setelah diberi Operator -- : " << endl;
                    pp2.output();
                    ++pp2;
                }
                getch(); 
            }
            break;
        case 5:
            {
                system("cls || clear");
                cout << endl;
                cout << "OPERATOR [] (Perbandingan indeks pp1 dan pp2)" << endl;
                cout << "1. x min" << endl;
                cout << "2. x max" << endl;
                cout << "3. y min" << endl;
                cout << "4. y max" << endl;
                cout << "Masukkan operator yang ingin dibandingkan : "; cin >> pilihan; cout << endl;

                cout << "Nilai " << index[pilihan-1] << " Pp1 : " << pp1[pilihan] << endl;
                cout << "Nilai " << index[pilihan-1] << " Pp2 : " << pp2[pilihan] << endl;
                if (pp1[pilihan] > pp2[pilihan]){
                    cout << index[pilihan-1] << " pp1 lebih besar dari " << index[pilihan-1] << " pp2" << endl;
                }else if(pp2[pilihan] > pp1[pilihan]){
                    cout << index[pilihan-1] << " pp2 lebih besar dari " << index[pilihan-1] << " pp1" << endl;;
                }else{
                    cout << "Kedua " << index[pilihan-1] << " sama" << endl;
                }
                getch();    
            }
            break;
        case 6:
            {
                system("cls || clear");
                cout << endl;
                cout << "OPERATOR == (Pembuktian Kedua Persegi panjang saling beririsan/tidak)" << endl;
                if (pp1==pp2){
                    cout << "Kedua persegi panjang beririsan" << endl;
                }else{
                    cout << "Kedua persegi panjang tidak beririsan" << endl;
                }
                getch(); 
            }
            break;
		case 7:
            endProgram();
            return 0;
        }
    }
}