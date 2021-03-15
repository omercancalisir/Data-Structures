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
#include "Node.HPP"
using namespace std;





//Yeni bir düğüm oluştuğunda sol ve sağ alanlarına NULL soy sayısına 0 içerisindeki data ya ise istenilen bir değeri yoksa 0 değerini atıyor.
Node::Node(int data = 0)
	{
		this->left = NULL;
		this->right = NULL;
		this->data = data;
		this->soy_sayisi = 0;
	}