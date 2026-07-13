# Düğün Organizasyon Sistemi

Bu proje, Sakarya Üniversitesi Bilgisayar Mühendisliği Bölümü Programlamaya Giriş dersi kapsamında geliştirilmiş, dosya tabanlı bir **Düğün Organizasyon ve Yönetim Sistemi** uygulamasıdır. 
Program; düğün kayıtları, davetli yönetimi, masraf takibi ve otomatik oturma planı raporlaması gibi işlevleri nesne yönelimli programlama (OOP) prensiplerini kullanarak C++ dilinde konsol tabanlı olarak gerçekleştirmektedir.

## Özellikler

Sistem ana menü üzerinden 3 temel kategori ve bunlara bağlı alt işlemlerden oluşmaktadır:

1. **Düğün İşlemleri**
* **Düğün Ekleme:** Düğün numarası, patron bilgileri, tarih/saat, gelin/damat bilgileri, salon numarası ve ücret bilgilerini `Dugunler.txt` dosyasına kaydeder.
* **Listeleme ve Arama:** Kayıtlı düğünleri tablo biçiminde listeler veya numara bazlı detaylı arama yapar.
* **Güncelleme ve Silme:** Geçici dosyalar (`TempDugunler.txt`) vasıtasıyla veri bütünlüğünü bozmadan düğün kayıtlarını günceller veya siler.
* **Masraf Yönetimi:** Her düğüne özel harici masrafları (yemek, sanatçı vb.) ayrı dosyalarda (`Masraf_<No>.txt`) tutar ve salon ücretiyle birleştirerek genel maliyet bilançosu çıkarır.


2. **Davetli İşlemleri**
* Her düğün için dinamik olarak `Davetliler_<DugunNo>.txt` adında bağımsız davetli dosyaları üretilir.
* Davetli ekleme, listeleme, no ile arama, güncelleme ve silme (iptal) işlevleri mevcuttur.


3. **Raporlar**
* **Gelecekler / Gelemeyecekler Listesi:** Davetlilerin katılım durumuna (`gelecekMi: 1/0`) göre dinamik listeler hazırlar.
* **Otomatik Oturma Planı:** Düğüne geleceğini belirten davetlileri Gelin ve Damat tarafı olmak üzere ayırır ve her biri en fazla 6 kişilik masalara yerleşecek şekilde otomatik oturma düzeni oluşturur.



##  Proje Yapısı

```text
├── Davetli.h       # Davetli sınıfı tanımları ve fonksiyon prototipleri
├── Davetli.cpp     # Davetli ve oturma planı işlevlerinin implementasyonu
├── Dugun.h         # Dugun sınıfı tanımları ve fonksiyon prototipleri
├── Dugun.cpp       # Düğün verileri ve masraf yönetimi implementasyonu
└── Source.cpp      # Konsol menü döngüsü ve programın ana giriş noktası (main)

```

## Kullanılan Teknolojiler

* **Dil:** C++ 
* **Kütüphaneler:** `iostream`, `fstream` (Dosya giriş/çıkış işlemleri), `iomanip` (Hizalı tablo çıktıları), `string`
* **Veri Depolama:** Yapılandırılmış düz metin dosyaları (`.txt`)

## Derleme ve Çalıştırma

### Visual Studio ile (Önerilen)

1. `.sln` uzantılı çözüm dosyasını Visual Studio ile açın.
2. Üst menüden `Build > Build Solution` seçeneğine tıklayın.
3. `Local Windows Debugger` (F5) butonuna basarak programı çalıştırabilirsiniz.

## Önemli Notlar

* Verilerin dosya sistemine doğru yazılabilmesi ve düzgün okunabilmesi için metinsel girdilerde (Ad, Soyad, Adres vb.) **boşluk bırakılmamalı**, kelimeler arasında alt çizgi (`_`) kullanılmalıdır.
* Silme ve güncelleme adımlarında, programın çalıştığı dizinde yazma/silme izinlerinin açık olduğundan emin olunmalıdır.

---

### Proje Künyesi

* **Üniversite:** Sakarya Üniversitesi
* **Fakülte:** Bilgisayar ve Bilişim Bilimleri Fakültesi
* **Bölüm:** Bilgisayar Mühendisliği Bölümü
* **Ders:** Programlamaya Giriş (Proje 1)
* **Geliştirici:** Sümeyye Çetinkaya (G231210065)
* **Grup:** 1A
