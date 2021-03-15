/**
* @file Data_Structures_Assignment_3
* @description İki farkli agacin soy degerlerini karsilastirip verilen durumlara gore ekleme ve silme islemi yapiyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 3.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
**/
#ifndef Oyun_HPP
#define Oyun_HPP
#include<BinaryTree.hpp>
#include <string>
#include <iostream>

class Oyun
{
	
	public:

	BinaryTree* Benim = new BinaryTree;
	BinaryTree* Rakip = new BinaryTree;
	int benimSkor;
	int RakipSkor;
	int genelSkor;
	
	public:
	Oyun();
	void degerleriOku(BinaryTree* kontrol, string dosyaIsmi);
	void oyunuBaslat();
	void yazdir();
	void kimKazandi(int benimSoySayim, int rakipSoySayisi);
	void oyunuOynat();
	~Oyun();
	

	
	
	
	
};


#endif