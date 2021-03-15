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
#include "KovaKontrol.HPP"

using namespace std;
	int main()
{
	KovaKontrol kk;



	kk.istenilenSayidaKovaOlustur();
	kk.geciciTop();



	char cevap;
	do
	{
		kk.sekilBastir();
		cout << endl;
		cout << "[1] Toplari Yerlestir" << endl;
		cout << "[2] Toplari Yoket" << endl;
		cout << "[3] Kova Degistir" << endl;
		cout << "[4] Top Degistir" << endl;
		cout << "[5] Kovalari Tersten Yerlestir" << endl;
		cout << "[6] Toplari Tersten Yerlestir" << endl;
		cout << "[7] Cikis" << endl;

		cout << ">>";
		cin >> cevap;

		switch (cevap)
		{
		case '1':
			kk.topOlustur();
			kk.toplariYerlestir();
			break;
		case '2':
			kk.toplariYokEt();
			break;
		case '3':
			kk.kovaDegistir();
			break;
		case '4':
			kk.topDegistir();
			kk.toplariYerlestir();
			break;
		case '5':
			kk.kovalariTersCevir();
			break;
		case '6':
			kk.toplariTersCevir();
			kk.toplariYerlestir();
			break;
		case '7':
			
			kk.KovaBellegiTemizle();
			break;
		default:
			cout << "hatali giris yapildi" << endl;
			system("PAUSE");
			break;
		}
		system("CLS");
	} while (cevap != '7');




	system("PAUSE");
	return 0;

}