/****************************************************************************
**                    SAKARYA ÜNÝVERSÝTESÝ
**                 BÝLGÝSAYAR VE BÝLÝÞÝM BÝLÝMLERÝ FAKÜLTESÝ
**                BÝLGÝSAYAR MÜHENDÝSLÝÐÝ BÖLÜMÜ
**                      PROGRAMLAMAYA GÝRÝÞÝ DERSÝ
**
**                ÖDEV NUMARASI: Proje 1
**                ÖÐRENCÝ ADI: Sümeyye Çetinkaya
**                ÖÐRENCÝ NUMARASI: G231210065
**                DERS GRUBU: 1A
****************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Davetli.h"

using namespace std;

// Varsayýlan yapýcý
Davetli::Davetli()
{
    no = 0;
    gelecekMi = 1;
}

// Bir davetliyi dosyaya tek satýr yazar
void Davetli::dosyayaYaz(ofstream& dosya) const
{
    dosya << no << " "
        << ad << " "
        << soyad << " "
        << akrabalik << " "
        << adres << " "
        << telefon << " "
        << gelecekMi << endl;
}

// Dosyadan bir davetli kaydý okur
bool Davetli::dosyadanOku(ifstream& dosya)
{
    if (!(dosya >> no
        >> ad
        >> soyad
        >> akrabalik
        >> adres
        >> telefon
        >> gelecekMi))
    {
        return false;
    }

    return true;
}

// Düðün numarasýna göre davetli dosya adý üretir
string davetliDosyaAdiUret(int dugunNo)
{
    string dosyaAdi = "Davetliler_";
    dosyaAdi += to_string(dugunNo);
    dosyaAdi += ".txt";
    return dosyaAdi;
}

// Davetli ekleme
void davetliEkle()
{
    int dugunNo;
    cout << "Davetli eklenecek dugun no: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);

    ofstream dosya(dosyaAdi.c_str(), ios::app);

    if (!dosya.is_open())
    {
        cout << "Davetli dosyasi acilamadi." << endl;
        return;
    }

    Davetli d;
    char devam = 'e';

    // Kullanýcý davetli eklemek istediði sürece çalýþan döngü
    while (devam == 'e' || devam == 'E')
    {
        cout << "Davetli no: ";
        cin >> d.no;

        cout << "Ad (bosluksuz): ";
        cin >> d.ad;

        cout << "Soyad (bosluksuz): ";
        cin >> d.soyad;

        cout << "Akrabalik (Gelin/Damat): ";
        cin >> d.akrabalik;

        cout << "Adres (bosluksuz): ";
        cin >> d.adres;

        cout << "Telefon: ";
        cin >> d.telefon;

        cout << "Gelecek mi? (1: evet, 0: hayir): ";
        cin >> d.gelecekMi;

        d.dosyayaYaz(dosya);

        cout << "Baska davetli eklemek ister misiniz? (e/h): ";
        cin >> devam;
    }

    dosya.close();
    cout << "Davetliler kaydedildi." << endl;
}

// Davetlileri listeleme
void davetliListele()
{
    int dugunNo;
    cout << "Davetlileri listelenecek dugun no: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);
    ifstream dosya(dosyaAdi.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait davetli dosyasi bulunamadi." << endl;
        return;
    }

    Davetli d;

    cout << left << setw(6) << "No"
        << setw(12) << "Ad"
        << setw(12) << "Soyad"
        << setw(10) << "Akraba"
        << setw(15) << "Adres"
        << setw(12) << "Telefon"
        << setw(10) << "GelecekMi"
        << endl;

    cout << "-----------------------------------------------------------------------------------" << endl;

    // Tüm davetlileri okuyan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        cout << left << setw(6) << d.no
            << setw(12) << d.ad
            << setw(12) << d.soyad
            << setw(10) << d.akrabalik
            << setw(15) << d.adres
            << setw(12) << d.telefon
            << setw(10) << d.gelecekMi
            << endl;
    }

    dosya.close();
}

// Davetli arama (no ile)
void davetliAra()
{
    int dugunNo;
    cout << "Davetli aranacak dugun no: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);
    ifstream dosya(dosyaAdi.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait davetli dosyasi bulunamadi." << endl;
        return;
    }

    int arananNo;
    cout << "Aranan davetli no: ";
    cin >> arananNo;

    Davetli d;
    bool bulundu = false;

    // Dosyadaki tüm davetlileri tek tek kontrol eden döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.no == arananNo)
        {
            cout << "Davetli bulundu:" << endl;
            cout << "No      : " << d.no << endl;
            cout << "Ad      : " << d.ad << endl;
            cout << "Soyad   : " << d.soyad << endl;
            cout << "Akraba  : " << d.akrabalik << endl;
            cout << "Adres   : " << d.adres << endl;
            cout << "Telefon : " << d.telefon << endl;
            cout << "Gelecek : " << d.gelecekMi << endl;
            bulundu = true;
            break;
        }
    }

    if (!bulundu)
    {
        cout << "Davetli bulunamadi." << endl;
    }

    dosya.close();
}

// Davetli silme
void davetliSil()
{
    int dugunNo;
    cout << "Davetli silinecek dugun no: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);
    ifstream dosya(dosyaAdi.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait davetli dosyasi bulunamadi." << endl;
        return;
    }

    int silinecekNo;
    cout << "Silinecek davetli no: ";
    cin >> silinecekNo;

    ofstream gecici("TempDavetli.txt");

    if (!gecici.is_open())
    {
        cout << "Gecici dosya acilamadi." << endl;
        dosya.close();
        return;
    }

    Davetli d;
    bool bulundu = false;

    // Tüm davetlileri okuyup silinmeyenleri geçici dosyaya yazan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.no == silinecekNo)
        {
            bulundu = true;
            // Bu kayýt yazýlmayacak (silinecek)
        }
        else
        {
            d.dosyayaYaz(gecici);
        }
    }

    dosya.close();
    gecici.close();

    if (!bulundu)
    {
        cout << "Silinecek davetli bulunamadi." << endl;
        remove("TempDavetli.txt");
        return;
    }

    remove(dosyaAdi.c_str());
    rename("TempDavetli.txt", dosyaAdi.c_str());

    cout << "Davetli silindi." << endl;
}

// Davetli güncelleme
void davetliGuncelle()
{
    int dugunNo;
    cout << "Davetli guncellenecek dugun no: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);
    ifstream dosya(dosyaAdi.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait davetli dosyasi bulunamadi." << endl;
        return;
    }

    int guncellenecekNo;
    cout << "Guncellenecek davetli no: ";
    cin >> guncellenecekNo;

    ofstream gecici("TempDavetli.txt");

    if (!gecici.is_open())
    {
        cout << "Gecici dosya acilamadi." << endl;
        dosya.close();
        return;
    }

    Davetli d;
    bool bulundu = false;

    // Tüm davetlileri okuyup isteneni güncelleyip geçici dosyaya yazan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.no == guncellenecekNo)
        {
            cout << "Yeni bilgileri giriniz:" << endl;

            cout << "Yeni ad (bosluksuz): ";
            cin >> d.ad;

            cout << "Yeni soyad (bosluksuz): ";
            cin >> d.soyad;

            cout << "Yeni akrabalik (Gelin/Damat): ";
            cin >> d.akrabalik;

            cout << "Yeni adres (bosluksuz): ";
            cin >> d.adres;

            cout << "Yeni telefon: ";
            cin >> d.telefon;

            cout << "Gelecek mi? (1: evet, 0: hayir): ";
            cin >> d.gelecekMi;

            bulundu = true;
        }

        d.dosyayaYaz(gecici);
    }

    dosya.close();
    gecici.close();

    if (!bulundu)
    {
        cout << "Guncellenecek davetli bulunamadi." << endl;
        remove("TempDavetli.txt");
        return;
    }

    remove(dosyaAdi.c_str());
    rename("TempDavetli.txt", dosyaAdi.c_str());

    cout << "Davetli guncellendi." << endl;
}

// Düðüne gelecekler listesi
void gelenleriListele()
{
    int dugunNo;
    cout << "Gelecekler listesi hangi dugun no icin: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);
    ifstream dosya(dosyaAdi.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait davetli dosyasi bulunamadi." << endl;
        return;
    }

    Davetli d;

    cout << "Dugune gelecek davetliler:" << endl;

    // Tüm davetlileri okuyup gelecek olanlarý yazan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.gelecekMi == 1)
        {
            cout << d.no << " - " << d.ad << " " << d.soyad
                << " (" << d.akrabalik << ")" << endl;
        }
    }

    dosya.close();
}

// Düðüne gelemeyecekler listesi
void gelemeyenleriListele()
{
    int dugunNo;
    cout << "Gelemeyecekler listesi hangi dugun no icin: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);
    ifstream dosya(dosyaAdi.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait davetli dosyasi bulunamadi." << endl;
        return;
    }

    Davetli d;

    cout << "Dugune gelemeyecek davetliler:" << endl;

    // Tüm davetlileri okuyup gelemeyecek olanlarý yazan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.gelecekMi == 0)
        {
            cout << d.no << " - " << d.ad << " " << d.soyad
                << " (" << d.akrabalik << ")" << endl;
        }
    }

    dosya.close();
}

// Oturma planý (Gelin akrabalarý ayrý, Damat akrabalarý ayrý)
void oturmaPlaniOlustur()
{
    int dugunNo;
    cout << "Oturma plani olusturulacak dugun no: ";
    cin >> dugunNo;

    string dosyaAdi = davetliDosyaAdiUret(dugunNo);
    ifstream dosya(dosyaAdi.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait davetli dosyasi bulunamadi." << endl;
        return;
    }

    // Basit bir oturma planý için sabit boyutlu diziler
    Davetli gelinTarafi[200];
    Davetli damatTarafi[200];

    int sayGelin = 0;
    int sayDamat = 0;

    Davetli d;

    // Tüm davetlileri okuyup akrabalýklarýna göre iki diziye ayýran döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.gelecekMi == 1)
        {
            if (d.akrabalik == "Gelin" || d.akrabalik == "gelin")
            {
                if (sayGelin < 200)
                {
                    gelinTarafi[sayGelin] = d;
                    sayGelin++;
                }
            }
            else if (d.akrabalik == "Damat" || d.akrabalik == "damat")
            {
                if (sayDamat < 200)
                {
                    damatTarafi[sayDamat] = d;
                    sayDamat++;
                }
            }
        }
    }

    dosya.close();

    int masaKapasite = 6;

    cout << "\nGELIN TARAFI MASALARI:" << endl;

    // Gelin tarafýný masa masa yazan döngü
    int masaNo = 1;
    int i = 0;
    while (i < sayGelin)
    {
        cout << "Masa " << masaNo << " (Gelin Akrabalari): " << endl;

        int sayac = 0;

        // Her masaya en fazla masaKapasite kadar davetli yerleþtiren iç döngü
        while (sayac < masaKapasite && i < sayGelin)
        {
            cout << "  " << gelinTarafi[i].ad << " " << gelinTarafi[i].soyad << endl;
            sayac++;
            i++;
        }

        masaNo++;
    }

    cout << "\nDAMAT TARAFI MASALARI:" << endl;

    masaNo = 1;
    i = 0;

    // Damat tarafýný masa masa yazan döngü
    while (i < sayDamat)
    {
        cout << "Masa " << masaNo << " (Damat Akrabalari): " << endl;

        int sayac = 0;

        // Her masaya en fazla masaKapasite kadar davetli yerleþtiren iç döngü
        while (sayac < masaKapasite && i < sayDamat)
        {
            cout << "  " << damatTarafi[i].ad << " " << damatTarafi[i].soyad << endl;
            sayac++;
            i++;
        }

        masaNo++;
    }
}
