#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

string sifrele(string metin, int anahtar)
{
    string sifreli = metin;
    for (size_t i = 0; i < metin.size(); ++i)
    {
        sifreli[i] = metin[i] + anahtar;
    }
    return sifreli;
}

string coz(string metin, int anahtar)
{
    string cozulmus = metin;
    for (size_t i = 0; i < metin.size(); ++i)
    {
        cozulmus[i] = metin[i] - anahtar;
    }
    return cozulmus;
}

class Musteri
{
protected:
    string isim;
    string soyisim;
    int id;
    string sifre;
    string adres;
    string telefonNumarasi;
    string type;

public:
    Musteri(string isim, string soyisim, int id, string sifre, string adres, string telefonNumarasi)
        : isim(isim), soyisim(soyisim), id(id), sifre(sifre), adres(adres), telefonNumarasi(telefonNumarasi), type("Normal") {}

    virtual ~Musteri() {}

    string getIsim() const { return isim; }
    string getSoyisim() const { return soyisim; }
    int getId() const { return id; }
    string getSifre() const { return sifre; }
    string getAdres() const { return adres; }
    string getTelefonNumarasi() const { return telefonNumarasi; }
    string getType() const { return type; }

    virtual void ekBilgi() const
    {
        cout << "Normal Musteri" << endl;
    }

    virtual double getOzelFaizOrani() const
    {
        return 0.0;
    }
};

class VIPMusteri : public Musteri
{
private:
    double ozelFaizOrani;

public:
    VIPMusteri(string isim, string soyisim, int id, string sifre, string adres, string telefonNumarasi, double ozelFaizOrani)
        : Musteri(isim, soyisim, id, sifre, adres, telefonNumarasi), ozelFaizOrani(ozelFaizOrani)
    {
        type = "VIP";
    }

    double getOzelFaizOrani() const override { return ozelFaizOrani; }

    void ekBilgi() const override
    {
        cout << "VIP Musteri" << endl;
        cout << "Özel Faiz Orani: " << ozelFaizOrani << "%" << endl;
    }
};

class Hesap
{
private:
    int hesapNo;
    double bakiye;
    Musteri *sahip;
    double faizOrani;
    string hesapTuru;

public:
    Hesap(int hesapNo, Musteri *sahip, double bakiye = 0.0, double faizOrani = 0.0, string hesapTuru = "Bireysel")
        : hesapNo(hesapNo), sahip(sahip), bakiye(bakiye), faizOrani(faizOrani), hesapTuru(hesapTuru) {}

    int getHesapNo() const { return hesapNo; }
    double getBakiye() const { return bakiye; }
    Musteri *getSahip() const { return sahip; }
    double getFaizOrani() const { return faizOrani; }
    string getHesapTuru() const { return hesapTuru; }

    void paraYatir(double miktar) { bakiye += miktar; }

    bool paraCek(double miktar)
    {
        bakiye -= miktar;
        return true;
    }

    double faizHesapla(int gun) const
    {
        double ozelFaizOrani = sahip->getOzelFaizOrani();
        double normalFaizOrani = (ozelFaizOrani > 0.0) ? ozelFaizOrani : faizOrani;
        return bakiye * normalFaizOrani * gun / 365.0;
    }
};

void musteriBilgileriniYaz(Musteri *musteri, ofstream &dosya)
{
    dosya << musteri->getIsim() << endl;
    dosya << musteri->getSoyisim() << endl;
    dosya << musteri->getId() << endl;
    dosya << sifrele(musteri->getSifre(), 5) << endl;
    dosya << musteri->getAdres() << endl;
    dosya << musteri->getTelefonNumarasi() << endl;
    dosya << musteri->getType() << endl;
    if (musteri->getType() == "VIP")
    {
        dosya << static_cast<VIPMusteri *>(musteri)->getOzelFaizOrani() << endl;
    }
}

Musteri *musteriBilgileriniOku(ifstream &dosya)
{
    string isim, soyisim, sifre, adres, telefonNumarasi, type;
    int id;
    double ozelFaizOrani = 0.0;

    getline(dosya, isim);
    getline(dosya, soyisim);
    dosya >> id;
    dosya.ignore();
    getline(dosya, sifre);
    sifre = coz(sifre, 5);
    getline(dosya, adres);
    getline(dosya, telefonNumarasi);
    getline(dosya, type);
    if (type == "VIP")
    {
        dosya >> ozelFaizOrani;
        dosya.ignore();
        return new VIPMusteri(isim, soyisim, id, sifre, adres, telefonNumarasi, ozelFaizOrani);
    }
    else
    {
        return new Musteri(isim, soyisim, id, sifre, adres, telefonNumarasi);
    }
}

void hesapBilgileriniYaz(Hesap *hesap, ofstream &dosya)
{
    dosya << hesap->getHesapNo() << endl;
    dosya << hesap->getSahip()->getId() << endl;
    dosya << hesap->getBakiye() << endl;
    dosya << hesap->getFaizOrani() << endl;
    dosya << hesap->getHesapTuru() << endl;
}

Hesap *hesapBilgileriniOku(ifstream &dosya, vector<Musteri *> &musteriler)
{
    int hesapNo, musteriId;
    double bakiye, faizOrani;
    string hesapTuru;

    dosya >> hesapNo >> musteriId >> bakiye >> faizOrani;
    dosya.ignore();
    getline(dosya, hesapTuru);

    Musteri *musteri = nullptr;
    for (auto &m : musteriler)
    {
        if (m->getId() == musteriId)
        {
            musteri = m;
            break;
        }
    }

    if (musteri)
    {
        return new Hesap(hesapNo, musteri, bakiye, faizOrani, hesapTuru);
    }
    return nullptr;
}

class Banka
{
private:
    vector<Musteri *> musteriler;
    vector<Hesap *> hesaplar;

public:
    void musteriEkle(Musteri *musteri)
    {
        musteriler.push_back(musteri);
    }

    void hesapEkle(Hesap *hesap)
    {
        hesaplar.push_back(hesap);
    }

    void musterileriDosyayaYaz()
    {
        ofstream dosya("musteriler.txt");
        if (dosya.is_open())
        {
            for (auto &musteri : musteriler)
            {
                musteriBilgileriniYaz(musteri, dosya);
            }
            dosya.close();
        }
    }

    void hesaplariDosyayaYaz()
    {
        ofstream dosya("hesaplar.txt");
        if (dosya.is_open())
        {
            for (auto &hesap : hesaplar)
            {
                hesapBilgileriniYaz(hesap, dosya);
            }
            dosya.close();
        }
    }

    void musterileriDosyadanOku()
    {
        ifstream dosya("musteriler.txt");
        if (dosya.is_open())
        {
            while (!dosya.eof())
            {
                Musteri *musteri = musteriBilgileriniOku(dosya);
                if (musteri)
                {
                    musteriEkle(musteri);
                }
            }
            dosya.close();
        }
    }

    void hesaplariDosyadanOku()
    {
        ifstream dosya("hesaplar.txt");
        if (dosya.is_open())
        {
            while (!dosya.eof())
            {
                Hesap *hesap = hesapBilgileriniOku(dosya, musteriler);
                if (hesap)
                {
                    hesapEkle(hesap);
                }
            }
            dosya.close();
        }
    }

    Musteri *kullaniciGirisi()
    {
        string isim, sifre;
        cout << "Isim: ";
        cin >> isim;
        cout << "Sifre: ";
        cin >> sifre;

        for (auto &musteri : musteriler)
        {
            if (musteri->getIsim() == isim && musteri->getSifre() == sifre)
            {
                return musteri;
            }
        }

        cout << "Giris basarisiz." << endl;
        return nullptr;
    }

    Musteri *yeniMusteriOlustur()
    {
        string isim, soyisim, sifre, adres, telefonNumarasi;
        int id, secim;

        cout << "1. Normal Musteri\n2. VIP Musteri\nSeciminiz: ";
        cin >> secim;

        cout << "Isim: ";
        cin >> isim;
        cout << "Soyisim: ";
        cin >> soyisim;
        cout << "ID: ";
        cin >> id;
        cout << "Sifre: ";
        cin >> sifre;
        cout << "Adres: ";
        cin >> adres;
        cout << "Telefon Numarasi: ";
        cin >> telefonNumarasi;

        if (secim == 2)
        {
            VIPMusteri *yeniVIPMusteri = new VIPMusteri(isim, soyisim, id, sifre, adres, telefonNumarasi, 5.0);
            musteriEkle(yeniVIPMusteri);
            return yeniVIPMusteri;
        }
        else
        {
            Musteri *yeniMusteri = new Musteri(isim, soyisim, id, sifre, adres, telefonNumarasi);
            musteriEkle(yeniMusteri);
            return yeniMusteri;
        }
    }

    Hesap *hesapBul(Musteri *musteri) const
    {
        for (size_t i = 0; i < hesaplar.size(); ++i)
        {
            if (hesaplar[i]->getSahip() == musteri)
            {
                return hesaplar[i];
            }
        }
        return nullptr;
    }

    void islemMenusu(Musteri *musteri)
    {
        ofstream dosya("islemler.txt", ios::app);
        if (!dosya.is_open())
        {
            cerr << "Dosya acilamadi." << endl;
            return;
        }

        dosya << "Musteri Bilgileri:" << endl;
        dosya << "Isim: " << musteri->getIsim() << endl;
        dosya << "Soyisim: " << musteri->getSoyisim() << endl;
        dosya << "ID: " << musteri->getId() << endl;
        dosya << "Adres: " << musteri->getAdres() << endl;
        dosya << "Telefon Numarasi: " << musteri->getTelefonNumarasi() << endl;
        dosya << "Musteri Turu: " << musteri->getType() << endl;
        if (musteri->getType() == "VIP")
        {
            dosya << "Ozel Faiz Orani: " << musteri->getOzelFaizOrani() << "%" << endl;
        }

        while (true)
        {
            cout << "\nHesap islemleri menusu" << endl;
            cout << "1. Para Yatirma\n2. Para Cekme\n3. Faiz Hesaplama\n4. Musteri Bilgileri\n5. Cikis\nSeciminizi yapiniz: ";
            int secim;
            cin >> secim;

            Hesap *hesap = hesapBul(musteri);

            if (!hesap)
            {
                cout << "Hesap bulunamadi." << endl;
                dosya.close();
                return;
            }

            switch (secim)
            {
            case 1:
            {
                double miktar;
                cout << "Yatirilacak miktar: ";
                cin >> miktar;
                hesap->paraYatir(miktar);
                cout << "Yeni bakiye: " << hesap->getBakiye() << endl;
                dosya << "Para Yatirma: " << miktar << ", Yeni Bakiye: " << hesap->getBakiye() << endl;
                break;
            }
            case 2:
            {
                double miktar;
                cout << "Cekilecek miktar: ";
                cin >> miktar;
                if (hesap->paraCek(miktar))
                {
                    cout << "Yeni bakiye: " << hesap->getBakiye() << endl;
                    dosya << "Para Cekme: " << miktar << ", Yeni Bakiye: " << hesap->getBakiye() << endl;
                }
                else
                {
                    cout << "Yetersiz bakiye." << endl;
                }
                break;
            }
            case 3:
            {
                int gun;
                cout << "Gun sayisi: ";
                cin >> gun;
                double faiz = hesap->faizHesapla(gun);
                cout << "Faiz tutari: " << faiz << endl;
                dosya << "Faiz Hesaplama: " << faiz << endl;
                break;
            }
            case 4:
            {
                cout << "Musteri Bilgileri:" << endl;
                cout << "Isim: " << musteri->getIsim() << endl;
                cout << "Soyisim: " << musteri->getSoyisim() << endl;
                cout << "ID: " << musteri->getId() << endl;
                cout << "Adres: " << musteri->getAdres() << endl;
                cout << "Telefon Numarasi: " << musteri->getTelefonNumarasi() << endl;
                musteri->ekBilgi();
                dosya << "Musteri Bilgileri:" << endl;
                dosya << "Isim: " << musteri->getIsim() << endl;
                dosya << "Soyisim: " << musteri->getSoyisim() << endl;
                dosya << "ID: " << musteri->getId() << endl;
                dosya << "Adres: " << musteri->getAdres() << endl;
                dosya << "Telefon Numarasi: " << musteri->getTelefonNumarasi() << endl;
                musteri->ekBilgi();
                break;
            }
            case 5:
            {

                dosya << "Son Bakiye Bilgileri:" << endl;
                dosya << "Hesap No: " << hesap->getHesapNo() << endl;
                dosya << "Bakiye: " << hesap->getBakiye() << endl;
                cout << "Cikis yapildi." << endl;
                dosya << "Cikis yapildi." << endl;
                dosya.close();
                return;
            }
            default:
                cout << "Gecersiz secim!" << endl;
            }
        }
    }

    void musterileriListele() const
    {
        cout << "\nMusteri Listesi:" << endl;
        for (size_t i = 0; i < musteriler.size(); ++i)
        {
            cout << "ID: " << musteriler[i]->getId() << ", Isim: " << musteriler[i]->getIsim() << ", Soyisim: " << musteriler[i]->getSoyisim() << ", Musteri Turu: " << musteriler[i]->getType() << endl;
        }
    }

    void hesaplariListele() const
    {
        cout << "\nHesap Listesi:" << endl;
        for (size_t i = 0; i < hesaplar.size(); ++i)
        {
            cout << "Hesap No: " << hesaplar[i]->getHesapNo() << ", Sahip ID: " << hesaplar[i]->getSahip()->getId() << ", Bakiye: " << hesaplar[i]->getBakiye() << ", Hesap Turu: " << hesaplar[i]->getHesapTuru() << endl;
        }
    }

    void eksiBakiyeHesaplariListele() const
    {
        cout << "\nEksi Bakiye Hesap Listesi:" << endl;
        for (size_t i = 0; i < hesaplar.size(); ++i)
        {
            if (hesaplar[i]->getBakiye() < 0)
            {
                cout << "Hesap No: " << hesaplar[i]->getHesapNo() << ", Sahip ID: " << hesaplar[i]->getSahip()->getId() << ", Bakiye: " << hesaplar[i]->getBakiye() << endl;
            }
        }
    }
};

int main()
{
    try
    {
        Banka banka;

        banka.musterileriDosyadanOku();
        banka.hesaplariDosyadanOku();

        int secim;
        cout << "1. Yeni Musteri Olustur\n2. Kullanici Girisi\nSeciminiz: ";
        cin >> secim;

        Musteri *musteri = nullptr;
        if (secim == 1)
        {
            musteri = banka.yeniMusteriOlustur();
            banka.musterileriDosyayaYaz();
        }
        else if (secim == 2)
        {
            musteri = banka.kullaniciGirisi();
        }
        else
        {
            cerr << "Gecersiz secim!" << endl;
            return 1;
        }

        if (!musteri)
        {
            cerr << "Giris basarisiz." << endl;
            return 1;
        }

        Hesap *hesap = banka.hesapBul(musteri);
        if (!hesap)
        {
            cout << "Yeni hesap olusturuluyor..." << endl;
            hesap = new Hesap(1001, musteri, 1000.0, 0.5, "Vadesiz");
            banka.hesapEkle(hesap);
            banka.hesaplariDosyayaYaz();
        }

        cout << "Hosgeldiniz, " << musteri->getIsim() << " " << musteri->getSoyisim() << endl;

        banka.islemMenusu(musteri);

        banka.musterileriListele();
        banka.hesaplariListele();

        banka.eksiBakiyeHesaplariListele();

        banka.musterileriDosyayaYaz();
        banka.hesaplariDosyayaYaz();
    }
    catch (...)
    {
        cerr << "Programda bir hata olustu." << endl;
        return 1;
    }

    return 0;
}
