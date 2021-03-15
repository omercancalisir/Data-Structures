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
#include <string>
#include <fstream>
#include "Oyun.HPP"
using namespace std;


int main()
{
	
	Oyun* oyun = new Oyun;

	//Sırası ile ağaçlardaki değerler okunuyor.
	oyun->degerleriOku(oyun->Benim, ".\\doc\\Benim.txt");
	oyun->degerleriOku(oyun->Rakip, ".\\doc\\Rakip.txt");

	//Değerler okunup yerleştirildikten sonra oyun başlatılıyor.
	oyun->oyunuOynat();

	system("pause");
	return 0;

}