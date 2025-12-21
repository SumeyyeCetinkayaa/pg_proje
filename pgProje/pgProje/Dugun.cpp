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
#include <cstdio>
#include "Dugun.h"

using namespace std;

// Düðün bilgilerinin tutulacaðý ana dosya yapýsý
const string DUGUN_DOSYA_ADI = "Dugunler.txt";

// Varsayýlan yapýcý 
Dugun::Dugun()
{
    dugunNo = 0;
    salonNo = 0;
    kisiSayisi = 0;
    toplamUcret = 0.0;
}

// Bir düðünü dosyaya tek satýr olarak yazacak
void Dugun::dosyayaYaz(ofstream& dosya) const
{
    dosya << dugunNo << " "
        << patronAd << " "
        << patronSoyad << " "
        << tarih << " "
        << saat << " "
        << damatAd << " "
        << damatBabaAd << " "
        << gelinAd << " "
        << gelinAnneAd << " "
        << patronTel << " "
        << damatTel << " "
        << salonNo << " "
        << kisiSayisi << " "
        << toplamUcret << endl;
}

// Dosyadan bir satýr düðün okur
bool Dugun::dosyadanOku(ifstream& dosya)
{
    // Bir satýr düðün kaydý okunmaya çalýþýlýyor
    if (!(dosya >> dugunNo
        >> patronAd
        >> patronSoyad
        >> tarih
        >> saat
        >> damatAd
        >> damatBabaAd
        >> gelinAd
        >> gelinAnneAd
        >> patronTel
        >> damatTel
        >> salonNo
        >> kisiSayisi
        >> toplamUcret))
    {
        return false;
    }

    return true;
}

// Yeni düðün ekleme
void dugunEkle()
{
    ofstream dosya(DUGUN_DOSYA_ADI.c_str(), ios::app);

    if (!dosya.is_open())
    {
        cout << "Dugunler.txt dosyasi acilamadi." << endl;
        return;
    }

    Dugun d;

    cout << "DUGUN NO: ";
    cin >> d.dugunNo;

    cout << "Patron adi (bosluksuz): ";
    cin >> d.patronAd;

    cout << "Patron soyadi (bosluksuz): ";
    cin >> d.patronSoyad;

    cout << "Tarih (01.01.2025 gibi): ";
    cin >> d.tarih;

    cout << "Saat (19:00 gibi): ";
    cin >> d.saat;

    cout << "Damat adi: ";
    cin >> d.damatAd;

    cout << "Damat baba adi: ";
    cin >> d.damatBabaAd;

    cout << "Gelin adi: ";
    cin >> d.gelinAd;

    cout << "Gelin anne adi: ";
    cin >> d.gelinAnneAd;

    cout << "Patron telefon: ";
    cin >> d.patronTel;

    cout << "Damat telefon: ";
    cin >> d.damatTel;

    cout << "Salon no: ";
    cin >> d.salonNo;

    cout << "Kisi sayisi: ";
    cin >> d.kisiSayisi;

    cout << "Toplam ucret (sadece salon icin): ";
    cin >> d.toplamUcret;

    // Düðünü dosyaya yaz
    d.dosyayaYaz(dosya);

    cout << "Dugun basariyla eklendi." << endl;

    dosya.close();
}

// Tüm düðünleri listeleme
void dugunListele()
{
    ifstream dosya(DUGUN_DOSYA_ADI.c_str());

    if (!dosya.is_open())
    {
        cout << "Dugunler.txt dosyasi bulunamadi." << endl;
        return;
    }

    Dugun d;

    cout << left << setw(8) << "No"
        << setw(12) << "PatronAd"
        << setw(12) << "PatronSoy"
        << setw(12) << "Tarih"
        << setw(8) << "Saat"
        << setw(10) << "Damat"
        << setw(10) << "Gelin"
        << setw(8) << "Salon"
        << setw(10) << "KisiSay"
        << setw(10) << "Ucret"
        << endl;

    cout << "--------------------------------------------------------------------------------------------" << endl;

    // Dosyadaki tüm düðünleri okuyan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        cout << left << setw(8) << d.dugunNo
            << setw(12) << d.patronAd
            << setw(12) << d.patronSoyad
            << setw(12) << d.tarih
            << setw(8) << d.saat
            << setw(10) << d.damatAd
            << setw(10) << d.gelinAd
            << setw(8) << d.salonNo
            << setw(10) << d.kisiSayisi
            << setw(10) << d.toplamUcret
            << endl;
    }

    dosya.close();
}

// Düðün arama (düðün numarasýna göre)
void dugunAra()
{
    ifstream dosya(DUGUN_DOSYA_ADI.c_str());

    if (!dosya.is_open())
    {
        cout << "Dugunler.txt dosyasi bulunamadi." << endl;
        return;
    }

    int arananNo;
    cout << "Aranan dugun no: ";
    cin >> arananNo;

    Dugun d;
    bool bulundu = false;

    // Dosyadaki her düðünü tek tek kontrol eden döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.dugunNo == arananNo)
        {
            cout << "\nDugun bulundu:" << endl;
            cout << "No          : " << d.dugunNo << endl;
            cout << "Patron      : " << d.patronAd << " " << d.patronSoyad << endl;
            cout << "Tarih       : " << d.tarih << " " << d.saat << endl;
            cout << "Damat       : " << d.damatAd << " (Baba: " << d.damatBabaAd << ")" << endl;
            cout << "Gelin       : " << d.gelinAd << " (Anne: " << d.gelinAnneAd << ")" << endl;
            cout << "Salon       : " << d.salonNo << endl;
            cout << "Kisi Sayisi : " << d.kisiSayisi << endl;
            cout << "Toplam Ucret: " << d.toplamUcret << endl;
            bulundu = true;
            break;
        }
    }

    if (!bulundu)
    {
        cout << "Bu numarada bir dugun bulunamadi." << endl;
    }

    dosya.close();
}

// Düðün silme (geçici dosya kullanarak)
void dugunSil()
{
    ifstream dosya(DUGUN_DOSYA_ADI.c_str());

    if (!dosya.is_open())
    {
        cout << "Dugunler.txt dosyasi bulunamadi." << endl;
        return;
    }

    int silinecekNo;
    cout << "Silinecek dugun no: ";
    cin >> silinecekNo;

    ofstream gecici("TempDugunler.txt");

    if (!gecici.is_open())
    {
        cout << "Gecici dosya acilamadi." << endl;
        dosya.close();
        return;
    }

    Dugun d;
    bool bulundu = false;

    // Tüm düðünleri okuyup silinecek olmayanlarý geçici dosyaya yazan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.dugunNo == silinecekNo)
        {
            // Bu düðünü yazmýyoruz => silinmiþ olacak
            bulundu = true;
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
        cout << "Silinecek dugun bulunamadi." << endl;
        // Geçici dosyayý silebiliriz
        remove("TempDugunler.txt");
        return;
    }

    // Eski dosyayý sil, geçiciyi yeniden adlandýr
    remove(DUGUN_DOSYA_ADI.c_str());
    rename("TempDugunler.txt", DUGUN_DOSYA_ADI.c_str());

    cout << "Dugun basariyla silindi." << endl;
}

// Düðün güncelleme
void dugunGuncelle()
{
    ifstream dosya(DUGUN_DOSYA_ADI.c_str());

    if (!dosya.is_open())
    {
        cout << "Dugunler.txt dosyasi bulunamadi." << endl;
        return;
    }

    int guncellenecekNo;
    cout << "Guncellenecek dugun no: ";
    cin >> guncellenecekNo;

    ofstream gecici("TempDugunler.txt");

    if (!gecici.is_open())
    {
        cout << "Gecici dosya acilamadi." << endl;
        dosya.close();
        return;
    }

    Dugun d;
    bool bulundu = false;

    // Tüm düðünleri okuyan ve istenen düðünü güncelleyip geçici dosyaya yazan döngü
    while (true)
    {
        if (!d.dosyadanOku(dosya))
        {
            break;
        }

        if (d.dugunNo == guncellenecekNo)
        {
            cout << "Yeni bilgileri giriniz (bosluksuz adlar):" << endl;

            cout << "Yeni Patron adi: ";
            cin >> d.patronAd;

            cout << "Yeni Patron soyadi: ";
            cin >> d.patronSoyad;

            cout << "Yeni Tarih: ";
            cin >> d.tarih;

            cout << "Yeni Saat: ";
            cin >> d.saat;

            cout << "Yeni Damat adi: ";
            cin >> d.damatAd;

            cout << "Yeni Damat baba adi: ";
            cin >> d.damatBabaAd;

            cout << "Yeni Gelin adi: ";
            cin >> d.gelinAd;

            cout << "Yeni Gelin anne adi: ";
            cin >> d.gelinAnneAd;

            cout << "Yeni Patron telefon: ";
            cin >> d.patronTel;

            cout << "Yeni Damat telefon: ";
            cin >> d.damatTel;

            cout << "Yeni Salon no: ";
            cin >> d.salonNo;

            cout << "Yeni Kisi sayisi: ";
            cin >> d.kisiSayisi;

            cout << "Yeni Toplam ucret: ";
            cin >> d.toplamUcret;

            bulundu = true;
        }

        d.dosyayaYaz(gecici);
    }

    dosya.close();
    gecici.close();

    if (!bulundu)
    {
        cout << "Guncellenecek dugun bulunamadi." << endl;
        remove("TempDugunler.txt");
        return;
    }

    remove(DUGUN_DOSYA_ADI.c_str());
    rename("TempDugunler.txt", DUGUN_DOSYA_ADI.c_str());

    cout << "Dugun bilgileri guncellendi." << endl;
}

// Belirli bir düðün için masraf ekleme
void masrafEkle()
{
    int dugunNo;
    cout << "Masraf eklenecek dugun no: ";
    cin >> dugunNo;

    // Masraf dosya adý: Masraf_<no>.txt
    string masrafDosya = "Masraf_";
    masrafDosya += to_string(dugunNo);
    masrafDosya += ".txt";

    ofstream dosya(masrafDosya.c_str(), ios::app);

    if (!dosya.is_open())
    {
        cout << "Masraf dosyasi acilamadi." << endl;
        return;
    }

    string aciklama;
    double tutar;
    char devam = 'e';

    // Kullanýcý masraf girmek istediði sürece tekrar eden döngü
    while (devam == 'e' || devam == 'E')
    {
        cout << "Masraf aciklama (yemek_sunum_sanatci gibi, bosluksuz): ";
        cin >> aciklama;

        cout << "Tutar: ";
        cin >> tutar;

        dosya << aciklama << " " << tutar << endl;

        cout << "Baska masraf girmek ister misiniz? (e/h): ";
        cin >> devam;
    }

    dosya.close();
    cout << "Masraflar kaydedildi." << endl;
}

// Masrafý okur ve toplamý gösterir
void masrafToplamGoster()
{
    int dugunNo;
    cout << "Masraf toplami gosterilecek dugun no: ";
    cin >> dugunNo;

    string masrafDosya = "Masraf_";
    masrafDosya += to_string(dugunNo);
    masrafDosya += ".txt";

    ifstream dosya(masrafDosya.c_str());

    if (!dosya.is_open())
    {
        cout << "Bu dugune ait masraf dosyasi bulunamadi." << endl;
        return;
    }

    string aciklama;
    double tutar;
    double toplam = 0.0;

    // Tüm masraflarý okuyup toplayan döngü
    while (dosya >> aciklama >> tutar)
    {
        toplam += tutar;
    }

    dosya.close();

    cout << "Toplam ekstra masraf: " << toplam << endl;

    // Þimdi istenirse Dugunler.txt içindeki salon ücretini de bulup toplam maliyet hesaplayabiliriz
    ifstream dDosya(DUGUN_DOSYA_ADI.c_str());
    if (!dDosya.is_open())
    {
        cout << "Dugunler.txt acilamadi, sadece ekstra masraf gosterildi." << endl;
        return;
    }

    Dugun d;
    bool bulundu = false;

    // Ýlgili düðünü bulmak için dosyayý tarayan döngü
    while (true)
    {
        if (!d.dosyadanOku(dDosya))
        {
            break;
        }

        if (d.dugunNo == dugunNo)
        {
            bulundu = true;
            break;
        }
    }

    dDosya.close();

    if (!bulundu)
    {
        cout << "Dugun bulunamadigi icin toplam maliyet hesaplanamadi." << endl;
        return;
    }

    double genelToplam = d.toplamUcret + toplam;

    cout << "Salon ucreti     : " << d.toplamUcret << endl;
    cout << "Ekstra masraflar : " << toplam << endl;
    cout << "GENEL TOPLAM     : " << genelToplam << endl;
}
