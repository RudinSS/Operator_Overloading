#include <iostream>
#include <cmath>
#include "include/persegiPanjang.hpp"
using namespace std;

void persegiPanjang::output(){
    float panjang = this->xmax - this->xmin;
	float lebar   = this->ymax - this->ymin;
	panjang = abs(panjang);
	lebar   = abs (lebar);
    
    cout << "Titik Tengah X : " << (this->xmax - this->xmin)/2 + this->xmin; cout << endl;
    cout << "Titik Tengah Y : " << (this->ymax - this->ymin)/2 + this->ymin; cout << endl;
    cout << "Panjang (Sumbu X) : " << panjang; cout << endl;
    cout << "Lebar (Sumbu Y) : " << lebar; cout << endl;
    cout << "Nilai x Min : " << this->xmin; cout << endl;
    cout << "Nilai x max : " << this->xmax; cout << endl;
    cout << "Nilai y Min : " << this->ymin; cout << endl;
    cout << "Nilai y max : " << this->ymax; cout << endl;
}

persegiPanjang::persegiPanjang(float tTengahX, float tTengahY, float panjang, float lebar){
    this->xmin = tTengahX - (panjang/2);
    this->ymin = tTengahY - (lebar/2);
    this->xmax = tTengahX + (panjang/2);
    this->ymax = tTengahY + (lebar/2);
}
//Operator (==) untuk mencari apakah 2 persegi panjang beririsan atau tidak
bool persegiPanjang::operator==(persegiPanjang const &baru)const{
    if (this->xmax > baru.xmin && this->xmin < baru.xmax && this->ymax > baru.ymin && this->ymin < baru.ymax){
        return true;
    }
	else{
        return false;
    }
}
//operator (+) menambah luasan persegi panjang dengan menggabungkan kedua luasan persegi panjang
persegiPanjang persegiPanjang::operator+(persegiPanjang const &baru){
    persegiPanjang temp(0,0,0,0);

    if (*this == baru){
        temp.xmin = min(this-> xmin,baru.xmin);
        temp.ymin = min(this-> ymin,baru.ymin);
        temp.xmax = max(this-> xmax,baru.xmax);
        temp.ymax = max(this-> ymax,baru.ymax);
    }else{
        cout << "Kedua bangun tidak beririsan" << endl;
    }
    return temp;
}
//operator (-) mengambil irisan dari kedua buah persegipanjang
persegiPanjang persegiPanjang::operator-(persegiPanjang const &baru){
    persegiPanjang temp(0,0,0,0);

    if (*this == baru){
        temp.xmin = max(this-> xmin,baru.xmin);
        temp.ymin = max(this-> ymin,baru.ymin);
        temp.xmax = min(this-> xmax,baru.xmax);
        temp.ymax = min(this-> ymax,baru.ymax);
    }else{
        cout << "Kedua bangun tidak beririsan" << endl;
    }
    return temp;
}
//operator (++) membuat luasan menjadi 2 kali luasan semula
void persegiPanjang::operator++(){
	float panjang = 0,lebar = 0,tx = 0, ty = 0;
    panjang  = (this->xmax - this->xmin);
    lebar    = (this->ymin - this->ymax);
    panjang = abs(panjang);
    lebar   = abs (lebar);
    tx     = panjang/2 + this->xmin;
    ty     = lebar/2 + this->ymin;

    panjang*=2;
    lebar*=2;

    this->xmin = tx - (panjang/2);
    this->ymin = ty - (lebar/2);
    this->xmax = tx + (panjang/2);
    this->ymax = ty + (lebar/2);
}
//operator (--) membuat luasan menjadi 1/2 kali luasan semula
void persegiPanjang::operator--(){
    float panjang = 0,lebar = 0,tx = 0, ty = 0;
    panjang  = (this->xmax - this->xmin);
    lebar    = (this->ymin - this->ymax);
    panjang = abs(panjang);
    lebar   = abs (lebar);
    tx     = panjang/2 + this->xmin;
    ty     = lebar/2 + this->ymin;

    panjang /=2;
    lebar   /=2;

    this->xmin = tx - (panjang/2);
    this->ymin = ty - (lebar/2);
    this->xmax = tx + (panjang/2);
    this->ymax = ty + (lebar/2);
}
void persegiPanjang::operator++(int){}
void persegiPanjang::operator--(int){}

float persegiPanjang::operator[](int pilihan){
    switch (pilihan){
    case 1:
        return this->xmin;
        break;
    case 2:
        return this->xmax;
        break;
    case 3:
        return this->ymin;
        break;
    case 4:
        return this->ymax;
        break;
    }
    return 0;
}