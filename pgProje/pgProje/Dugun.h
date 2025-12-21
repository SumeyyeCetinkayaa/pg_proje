#ifndef DUGUN_H
#define DUGUN_H

#include <string>
using namespace std;

// Düðün bilgilerini tutan sýnýf
class Dugun
{
public:
    int dugunNo;
    string patronAd;
    string patronSoyad;
    string tarih;        // Örn: 01.01.2025
    string saat;         // Örn: 19:00
    string damatAd;
    string damatBabaAd;
    string gelinAd;
    string gelinAnneAd;
    string patronTel;
    string damatTel;
    int salonNo;
    int kisiSayisi;
    double toplamUcret;

    Dugun();

    // Dosyaya yazma
    void dosyayaYaz(ofstream& dosya) const;

    // Dosyadan okuma (okuma baþarýlýysa true döner)
    bool dosyadanOku(ifstream& dosya);
};

// Düðün dosyasý ile ilgili iþlemler
void dugunEkle();
void dugunListele();
void dugunAra();
void dugunSil();
void dugunGuncelle();

// Masraf iþlemleri
void masrafEkle();
void masrafToplamGoster();

#endif
