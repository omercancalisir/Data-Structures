/**
* @file Data_Structures_Assignment_2
* @description Dugum veri yapisinda kâr sagliyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 2.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#ifndef DOUBLELINKEDLIST_HPP
#define	DOUBLELINKEDLIST_HPP
#include "Iterator.hpp"
#include <string>
#include<iostream>
using namespace std;


class Iterator;

class DoubleLinkedList
{
	private:
	
	Node* head;
	int size;
	int sayac;
	int kazancSaglananByteSayisi = 0;
	
	private:
	
	Iterator OncekiniKonumuIleBul(int konum);

	
	
	public:
	
	DoubleLinkedList();
	void addLast(string data);
	void print();
	string compare(string Word);
	void kazancHesapla(string Word);
	void kazancYazdir();
	
	

	
};




#endif