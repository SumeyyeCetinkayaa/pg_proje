#ifndef DAVETLI_H
#define DAVETLI_H

#include <string>
using namespace std;

// Davetli bilgilerini tutan sýnýf
class Davetli
{
public:
    int no;
    string ad;
    string soyad;
    string akrabalik; // "Gelin" veya "Damat"
    string adres;
    string telefon;
    int gelecekMi; // 1: gelecek, 0: gelmeyecek

    Davetli();

    void dosyayaYaz(ofstream& dosya) const;
    bool dosyadanOku(ifstream& dosya);
};

// Davetli iþlemleri (içeride düðün no soruluyor)
void davetliEkle();
void davetliListele();
void davetliAra();
void davetliSil();
void davetliGuncelle();

// Raporlar
void gelenleriListele();
void gelemeyenleriListele();
void oturmaPlaniOlustur();

#endif
