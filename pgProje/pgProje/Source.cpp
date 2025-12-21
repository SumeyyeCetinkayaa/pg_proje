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
#include "Dugun.h"
#include "Davetli.h"

using namespace std;

int main()
{
    int secim = -1;

    // Kullanýcý çýkmak isteyene kadar menüyü gösteren döngü
    while (secim != 0)
    {
        cout << "\n===== DUGUN ORGANIZASYON SISTEMI =====" << endl;
        cout << "1) Dugun islemleri" << endl;
        cout << "2) Davetli islemleri" << endl;
        cout << "3) Raporlar" << endl;
        cout << "0) Cikis" << endl;
        cout << "Secim: ";
        cin >> secim;

        if (secim == 1)
        {
            int s1;
            cout << "\n--- DUGUN ISLEMLERI ---" << endl;
            cout << "1) Dugun ekle" << endl;
            cout << "2) Dugunleri listele" << endl;
            cout << "3) Dugun ara" << endl;
            cout << "4) Dugun sil" << endl;
            cout << "5) Dugun guncelle" << endl;
            cout << "6) Masraf ekle" << endl;
            cout << "7) Masraf toplamini goster" << endl;
            cout << "Secim: ";
            cin >> s1;

            if (s1 == 1)      dugunEkle();
            else if (s1 == 2) dugunListele();
            else if (s1 == 3) dugunAra();
            else if (s1 == 4) dugunSil();
            else if (s1 == 5) dugunGuncelle();
            else if (s1 == 6) masrafEkle();
            else if (s1 == 7) masrafToplamGoster();
            else              cout << "Gecersiz secim." << endl;
        }
        else if (secim == 2)
        {
            int s2;
            cout << "\n--- DAVETLI ISLEMLERI ---" << endl;
            cout << "1) Davetli ekle" << endl;
            cout << "2) Davetlileri listele" << endl;
            cout << "3) Davetli ara" << endl;
            cout << "4) Davetli sil" << endl;
            cout << "5) Davetli guncelle" << endl;
            cout << "Secim: ";
            cin >> s2;

            if (s2 == 1)      davetliEkle();
            else if (s2 == 2) davetliListele();
            else if (s2 == 3) davetliAra();
            else if (s2 == 4) davetliSil();
            else if (s2 == 5) davetliGuncelle();
            else              cout << "Gecersiz secim." << endl;
        }
        else if (secim == 3)
        {
            int s3;
            cout << "\n--- RAPORLAR ---" << endl;
            cout << "1) Dugune geleceklerin listesi" << endl;
            cout << "2) Dugune gelemeyeceklerin listesi" << endl;
            cout << "3) Oturma plani olustur" << endl;
            cout << "Secim: ";
            cin >> s3;

            if (s3 == 1)      gelenleriListele();
            else if (s3 == 2) gelemeyenleriListele();
            else if (s3 == 3) oturmaPlaniOlustur();
            else              cout << "Gecersiz secim." << endl;
        }
        else if (secim == 0)
        {
            cout << "Programdan cikiliyor..." << endl;
        }
        else
        {
            cout << "Gecersiz secim." << endl;
        }
    }

    return 0;
}
