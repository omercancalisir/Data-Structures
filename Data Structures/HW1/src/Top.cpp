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
#include <time.h>
#include "Top.HPP"

using namespace std;

	Top::Top()
	{
		//Top nesnesi oluştuğu zaman random bir harf ile beraber oluşuyor.
		top = harfler[rand() % 25];
	}

	char Top::getTop()
	{
		
		return top;
	}