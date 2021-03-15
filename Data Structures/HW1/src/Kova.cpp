/**
* @file Data_Structur_Assignment_1
* @description Heap bellek de oluşturulan kovaların içlerinde birer top tutarak çeşitli işlemler yapması.
* @course Örgün Eğitim 1/A
* @assignment Birinci(1) Ödev
* @date 11.10.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#include <iostream>
#include<Windows.h>
#include "Kova.HPP"




using namespace std;


	Kova::Kova()
	{

		// Kova nesnesi oluştuğu zaman oluşan nesneye kova şekli atanıyor.
		kova[0][0] = ' '; kova[1][0] = ' '; kova[2][0] = '.';
		kova[0][1] = ' '; kova[1][1] = '.';	kova[2][1] = ' ';
		kova[0][2] = '.'; kova[1][2] = ' ';	kova[2][2] = ' ';
		kova[0][3] = '|'; kova[1][3] = ' ';	kova[2][3] = ' ';
		kova[0][4] = '.'; kova[1][4] = ' ';	kova[2][4] = ' ';
		kova[0][5] = ' '; kova[1][5] = '.';	kova[2][5] = ' ';
		kova[0][6] = ' '; kova[1][6] = ' ';	kova[2][6] = '.';

		kova[3][0] = '#'; kova[4][0] = '#';
		kova[3][1] = ' '; kova[4][1] = ' ';
		kova[3][2] = ' '; kova[4][2] = ' ';
		kova[3][3] = ' '; kova[4][3] = '-'; 
		kova[3][4] = ' '; kova[4][4] = ' ';
		kova[3][5] = ' '; kova[4][5] = ' ';
		kova[3][6] = '#'; kova[4][6] = '#';


		kova[5][0] = '#';
		kova[5][1] = ' ';
		kova[5][2] = ' ';
		kova[5][3] = ' ';
		kova[5][4] = ' ';
		kova[5][5] = ' ';
		kova[5][6] = '#';

		kova[6][0] = '#';
		kova[6][1] = '#';
		kova[6][2] = '#';
		kova[6][3] = '#';
		kova[6][4] = '#';
		kova[6][5] = '#';
		kova[6][6] = '#';

		// Kova nesnesi oluştuğu zaman renk değeri random olarak atanıyor.
		renk = rand() % 15;
	}
	int Kova::getRenk()
	{
		//renk fonksiyon içinde atandığı için geri çeviriliyor.
		return renk;
	}
	void Kova::setDegeriDegistir(char gelenDeger)
	{
		// Kova içine top eklendiği zaman topun harfini gerekli yere atıyor.
		kova[4][3] = gelenDeger;
	}
	void Kova::kovaBastir()
	{
		
		for (int satir = 0; satir < 7; satir++)
		{
			//Kovaların tutulduğu dizide satır değerlerini döndürüyor.
			for (int sutun = 0; sutun < 7; sutun++)
			{
				//Kovaların tutulduğu dizide sutun değerlerini döndürüyor.
				cout << kova[satir][sutun];
			}
			cout << endl;
		}
	}

	Top* Kova::getTopTutucu()
	{
		return topTutucu;
	}

	void Kova::setTopTutucu(Top *Adres)
	{
		topTutucu = Adres;
	}
