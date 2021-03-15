/**
* @file Data_Structur_Assignment_1
* @description Heap bellek de oluşturulan kovaların içlerinde birer top tutarak çeşitli işlemler yapması.
* @course Örgün Eğitim 1/A
* @assignment Birinci(1) Ödev
* @date 11.10.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#include <iostream>
#include <Windows.h>
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

#include <iostream>
#include "KovaKontrol.HPP"




using namespace std;

	Kova** KovaKontrol::getAdresTutucu()
	{
		return kovalar;
	}

	KovaKontrol::KovaKontrol()
	{
		int kovaSayisi;
		cout << "Kova Sayisi :";
		cin >> kovaSayisi;
		this->kovaSayisi = kovaSayisi;
		Kova** kovalar = new Kova * [kovaSayisi];
		this->kovalar = kovalar;
	
	}
	
	void KovaKontrol::toplariYerlestir()
	{
		if (!DegerKontrol())
			// Topların içindeki değer NULL değil ise ifade çalışıyor.
		{
			for (int i = 0; i < kovaSayisi; i++)
			{
				//Topların içindeki değeri değiştiriyor.
				kovalar[i]->setDegeriDegistir((kovalar[i]->getTopTutucu())->getTop());
			}
		}
	}

	void KovaKontrol::toplariYokEt()
	{
		for (int i = 0; i < kovaSayisi; i++)
		{
			// Topların adreslerini NULL yapıp kova içindeki değerlerini - yapıyor.
			kovalar[i]->setDegeriDegistir('-');
			kovalar[i]->setTopTutucu(NULL);
		}
	}

	void KovaKontrol::topDegistir()
	{
		int ilkDeger=0;
		int ikinciDeger=0;
		
		cout << "Hangi Top :"; cin >> ilkDeger;

		cout << "Hangi Top ile :"; cin >> ikinciDeger;
		
		// Basit bir swap işlemi ile toplar istenilen yerlere yerleştiriliyor. 
		Top* temp;
		//temp ilk top adresini tutuyor.
		temp = kovalar[ilkDeger - 1]->getTopTutucu();
		//ilk top adresi yerine ikinci adres atanıyor.
		kovalar[ilkDeger - 1]->setTopTutucu(kovalar[ikinciDeger - 1]->getTopTutucu());
		//ikinci top adresi yerine temp de tutulan ilk adres veriliyor.
		kovalar[ikinciDeger - 1]->setTopTutucu(temp);
	
	}
	
	void KovaKontrol::toplariTersCevir()
	{
		if (!DegerKontrol())
			// Topların içindeki değer NULL değil ise ifade çalışıyor.
		{
			// Gecici bir değer oluşturuluyor
			Top** gecici = new Top * [kovaSayisi];
			int geriSayim = kovaSayisi - 1;
			for (int i = 0; i < kovaSayisi; i++)
				// gecici degerin son elemanına topların ile elemanı atanıyor. Sırası ile toplar tersten diziliyor.
			{
				gecici[geriSayim] = kovalar[i]->getTopTutucu();
				geriSayim--;
			}
			for (int i = 0; i < kovaSayisi; i++)
			{
				// gecici değerin içindeki ters dizili toplar toplar dizisine atanıyor.
				kovalar[i]->setTopTutucu(gecici[i]);
			}
					
				
						// İşlem sonucunda heap de bellek doldurulmasın diye temizleniyor.
								delete[] gecici;
		}
	}

	void KovaKontrol::topOlustur()
	{
		if (DegerKontrol())
			// Topların içindeki değer NULL ise içeri giriyor.
		{
			for (int i = 0; i < kovaSayisi; i++)
				// Toplar sınıfına sırası ile yeni top nesneleri atanıyor.
			{
					kovalar[i]->setTopTutucu(new Top());
			}
		}
	}

	void KovaKontrol::geciciTop()
	{
		
		for (int i = 0; i < kovaSayisi; i++)
			// Kovaların içindeki adreslere NULL değerleri atanıyor.
		{
			kovalar[i]->setTopTutucu(NULL);
		}
	}
	
	void KovaKontrol::istenilenSayidaKovaOlustur()
	{

		for (int i = 0; i < kovaSayisi; i++)
		{
			// Kovalar dizisine oluşturulan yeni kovalar atanıyor.
			kovalar[i] = new Kova();
		}
	}

	void KovaKontrol::sekilBastir()
	{
		
		for (int i = 0; i < kovaSayisi; i++)
			// Yeterli sayıda kovayı bastırmak için for kullanılıyor.
		{
			// i = 0 olduğu için 1 arttırıp kullanılıyor.
			cout << i + 1 << ". kova" << endl;
			//Sırası gelen kovaya renk değeri atanıyor.
			SetConsoleTextAttribute(hConsole, kovalar[i]->getRenk());
		  
		  //Sırası gelen kova bastırılıyor.
			kovalar[i]->kovaBastir();
			cout << "kova adresi : " << kovalar[i] << endl;
			if (kovalar[i]->getTopTutucu() == NULL)
				//Top adresi null ise adres yerine null yazılıyor.
			{
				cout << "topun adresi : NULL" << endl;
			}
			else
				//Toplara değer atanmışsa atılan değerler yazılıyor. 
			{
				cout << "topun adresi :" <<  kovalar[i]->getTopTutucu() << endl;
			}
			SetConsoleTextAttribute(hConsole, 15);
		}
	}
	
	void KovaKontrol::kovaDegistir()
	{
		int ilkDeger=0;
		int ikinciDeger=0;
		
		cout << "Hangi Kova :"; cin >> ilkDeger;
		cout << "Hangi Kova ile :"; cin >> ilkDeger;
		
		//Topları değiştirme olayı gibi küçük bir swap ile istenilen 2 değerin yeri değiştiriliyor.
		Kova* temp;
		//Temp istenilen ilk kovanın adresini tutuyor.
		temp = kovalar[ilkDeger - 1];
		//Tutulan ilk kovanın adresinin yerine ikinci tutulan adres atanıyor.
		kovalar[ilkDeger - 1] = kovalar[ilkDeger - 1];
		//ikinci kova adresinin yerine temp de tutulan ilk kova adresi atanıyor.
		kovalar[ilkDeger - 1] = temp;
	}

	void KovaKontrol::kovalariTersCevir()
	{
		//Gecici bir tutucu bir kova dizi nesnesi oluşturuluyor.
		Kova** gecici = new Kova * [kovaSayisi];
		int geriSayim = kovaSayisi - 1;
		
		for (int i = 0; i < kovaSayisi; i++)
		{
			// Oluşan gecici dizinin son adresine kovalarin ilk adresi atanmaya başlıyor. Bu şekilde tüm adresler geçici kova dizisine atanıyor.
			gecici[geriSayim] = kovalar[i];
			geriSayim--;
		}
		for (int i = 0; i < kovaSayisi; i++)
		{
			//Gecici adresler tersten alınmış oldu. Kova adreslerine gecici dizide depolanan adresler verildiği zaman tersten atanmış oluyor.
			kovalar[i] = gecici[i];
		}
		
		//Heap bellek bölgesinde alan işgali olmaması için oluşturulan geçici alanlar siliniyor.
		
		delete[] gecici;
		
	}

	bool KovaKontrol::DegerKontrol()
	{
		if (kovalar[0]->getTopTutucu() == NULL)
		{
			//Topların içinde değer olup olmadığını kontrol ediyor bir çok yerde çağrılıyor.
			return true;
		}
		else
			return false;
	}
	
	void KovaKontrol::KovaBellegiTemizle()
	{
		for (int deger = 0; deger < kovaSayisi; deger++)
		{
			delete []kovalar[deger];
		}
		delete kovalar;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
