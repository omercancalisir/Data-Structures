/**
* @file Data_Structures_Assignment_2
* @description Dugum veri yapisinda kâr sagliyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 2.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#ifndef FILEREAD_HPP
#define	FILEREAD_HPP
#include "DoubleLinkedList.hpp"
#include <string>
class FileRead
{
	private:	
	DoubleLinkedList* Words = new DoubleLinkedList();
	string word;
	
	public:
	void readFile();
	void print();
	void KazancYazdir();

	~FileRead();

};
#endif