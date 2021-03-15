/**
* @file Data_Structures_Assignment_3
* @description İki farkli agacin soy degerlerini karsilastirip verilen durumlara gore ekleme ve silme islemi yapiyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 3.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
**/
#ifndef BinaryTree_HPP
#define BinaryTree_HPP
#include<Node.hpp>
#include <string>
#include <iostream>
using namespace std;

class BinaryTree
{

	

public:
	Node* root;
	int toplamSoySayisi;
	
public:
	BinaryTree();
	void insert(int data);
	int maxValue(Node* adres);
	void postOrder(Node * dugum);
	void soyHesapla();
	void soyHesapla(Node* dugum);
	int verilenDugumunsoySayisiHesapla(Node* dugum);
	void AraVeSil(Node*& dugum, int arananDeger);
	void sil(Node*& dugum);
	~BinaryTree();
	
	private:
	
	void insert(Node* adres, int data);
};

#endif
