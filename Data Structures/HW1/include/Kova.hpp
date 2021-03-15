/**
* @file Data_Structur_Assignment_1
* @description Heap bellek de oluşturulan kovaların içlerinde birer top tutarak çeşitli işlemler yapması.
* @course Örgün Eğitim 1/A
* @assignment Birinci(1) Ödev
* @date 11.10.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#ifndef KOVA_HPP
#define	KOVA_HPP
#include "Top.hpp"
class Kova
{
	
	private:
	Top* topTutucu;
	int renk;
	char kova[7][7];
	
	public:
	Kova();
	int getRenk();
	void setDegeriDegistir(char gelenDeger);
	void kovaBastir();
	
	Top* getTopTutucu();
	void setTopTutucu(Top *Adres);
};




#endif