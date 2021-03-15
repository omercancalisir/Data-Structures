/**
* @file Data_Structures_Assignment_3
* @description İki farkli agacin soy degerlerini karsilastirip verilen durumlara gore ekleme ve silme islemi yapiyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 3.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
**/
#include <iostream>
#include<Windows.h>
#include <fstream>
#include "Oyun.HPP"

using namespace std;

//Heap bellek bölgesinde oluşan class elemanlarını temizliyor.
Oyun::~Oyun()
{
	delete Benim;
	delete Rakip;
}

//Classın değişkenlerine ilk değer ataması yapılıyor. 
Oyun::Oyun()
	{
		benimSkor = 0;
		RakipSkor = 0;
		genelSkor = 0;
	}
	
	//Oyunu verilen kurallara göre tekrar tekrar başlatıyor.
	void Oyun::oyunuOynat()
	{

		do {
			
			oyunuBaslat();
			cin.ignore();
			
		} while (benimSkor < 5 && RakipSkor < 5 && genelSkor <20);
		
			
	}
	
	//Her oyunda bir kazanan olup olmadığını kontrol ediyor.
	void Oyun::kimKazandi(int benimSoySayim, int rakipSoySayisi)
	{
		
		if (benimSoySayim > rakipSoySayisi)
		{
			//Kazanan rakip dosyası ise onun kazanma sayısını arttırıp ekrana yazıyor.
			RakipSkor++;
			genelSkor++;
			cout << "-- RAKIP TURU KAZANDI --" << endl;
		}
		else if (benimSoySayim < rakipSoySayisi)
		{
			//Kazanan benim dosyası ise onun kazanma sayısını arttırıp ekrana yazıyor.
			benimSkor++;
			genelSkor++;
			cout << "-- TEBRIKLER TURU KAZANDINIZ --" << endl;
		}
		else
		{
			//Durum berabere ise skoru kimse alamıyor genel oyun skoru arttırılıyor.
			genelSkor++;
			cout << "-- TUR BERABERE TAMAMLANDI --" << endl;
		}
	}
	
	//Ekranda gördüğümüz çıktı olan kısmı yazıyor.
	void Oyun::yazdir()
	{
	
	
		cout << "Benim Agac Postorder :" << endl;
		Benim->postOrder(Benim->root); cout << endl;
		cout << "Benim Agac Toplam Soy Sayisi :" << Benim->toplamSoySayisi << endl;
		cout << "--------------------" << endl; cout << endl;

		cout << "Rakip Agac Postorder :" << endl;
		Rakip->postOrder(Rakip->root); cout << endl;
		cout << "Rakip Agac Toplam Soy Sayisi :" << Rakip->toplamSoySayisi << endl;
		cout << endl;

		kimKazandi(Benim->toplamSoySayisi, Rakip->toplamSoySayisi); cout << endl;

		cout << "SKOR" << endl;
		cout << "Benim : " << benimSkor << endl;
		cout << "Rakip : " << RakipSkor << endl; cout << endl;


	}
	
	//Oyunda bir elin başlamasına yarayan fonksiyon
	void Oyun::oyunuBaslat()
	{
		//Soy sayıları hesaplanıyor
			Benim->soyHesapla();
			Rakip->soyHesapla();

		//Kazanan yazdırılıyor.
			yazdir();
			
			//Eşitlik var ise kökler karşılıklı değiştirilip siliniyor.
				 if (Benim->toplamSoySayisi == Rakip->toplamSoySayisi)
				 {
					
					 Rakip->insert(Benim->root->data);
					 Benim->insert(Rakip->root->data);

					 Rakip->AraVeSil(Rakip->root, Rakip->root->data);
					 Benim->AraVeSil(Benim->root, Benim->root->data);

				 }
				 //Burada kazanan rakip dosyası
				 //Kazanan kaybedenin en büyük değere sahip düğümündeki sayıyı alıyor ve kendi kök düğümünü veriyor
				 //Alınıp verilen düğümler ilk sahiplerinden siliniyor.
				 else if (Benim->toplamSoySayisi > Rakip->toplamSoySayisi)
				 {
					
					 Rakip->insert(Benim->maxValue(Benim->root));
					 Benim->AraVeSil(Benim->root, Benim->maxValue(Benim->root));

					 Benim->insert(Rakip->root->data);
					 Rakip->AraVeSil(Rakip->root, Rakip->root->data);

			     //Burada kazanan benim dosyası
				 //Kazanan kaybedenin en büyük değere sahip düğümündeki sayıyı alıyor ve kendi kök düğümünü veriyor
				 //Alınıp verilen düğümler ilk sahiplerinden siliniyor.
				 }
				 else 
				 {
					
					 Benim->insert(Rakip->maxValue(Rakip->root));
					 Rakip->AraVeSil(Rakip->root, Rakip->maxValue(Rakip->root));

					 Rakip->insert(Benim->root->data);
					 Benim->AraVeSil(Benim->root, Benim->root->data);


				 }
	}
	
	//Oyunda kullanılan ağaçlar bu fonksiyon yardımı ile txt dosyalarından okunup ağaç oluşumunda kullanılıyor.
	void Oyun::degerleriOku(BinaryTree* kontrol, string dosyaYolu)
	{
		fstream myfile(dosyaYolu, ios_base::in);

		int okunanDeger;
		//Dosya sonuan kadar okunuyor.
		while (myfile >> okunanDeger)
		{
			//Okunan değerler insert komutuna gönderiliyor.
			kontrol->insert(okunanDeger);
		}
	}
	
