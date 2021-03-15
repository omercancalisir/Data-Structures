/**
* @file Data_Structures_Assignment_3
* @description İki farkli agacin soy degerlerini karsilastirip verilen durumlara gore ekleme ve silme islemi yapiyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 3.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
**/
#ifndef Node_HPP
#define Node_HPP
#include <string>
#include<iostream>
using namespace std;




class Node
{
	
	public:
	
	Node* left;
	Node* right;
	int data;
	int soy_sayisi;
	
	
	public:
	Node(int data);

	
};




#endif