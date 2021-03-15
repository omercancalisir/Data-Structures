/**
* @file Data_Structur_Assignment_1
* @description Heap bellek de oluşturulan kovaların içlerinde birer top tutarak çeşitli işlemler yapması.
* @course Örgün Eğitim 1/A
* @assignment Birinci(1) Ödev
* @date 11.10.2019
* @author  Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#ifndef KOVAKONTROL_HPP
#define	KOVAKONTROL_HPP
#include "Kova.hpp"



class KovaKontrol
{
	private:
	int kovaSayisi;
	Kova** kovalar;
	
	

	
	
	public:
	Kova** getAdresTutucu();
	KovaKontrol();
	void toplariYerlestir();
	void toplariYokEt();
	void topDegistir();
	void toplariTersCevir();
	void topOlustur();
	void geciciTop();
	void istenilenSayidaKovaOlustur();
	void sekilBastir();
	void kovaDegistir();
	void kovalariTersCevir();
	bool DegerKontrol();
	void TopBellegiTemizle();
	void KovaBellegiTemizle();
};






#endif