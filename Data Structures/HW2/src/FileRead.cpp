/**
* @file Data_Structures_Assignment_2
* @description Dugum veri yapisinda kâr sagliyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 2.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#include <iostream>
#include<Windows.h>
#include<string>
#include<fstream>
#include "FileRead.HPP"
using namespace std;

void FileRead::readFile()
	{
		ifstream Dosya;

		Dosya.open(".\\doc\\metin.txt");

		//Dosya sonuna gelene kadar devam ediliyor.
		while (!Dosya.eof())
		{

			Dosya >> word;

			Words->kazancHesapla(word);
			word = Words->compare(word);
			Words->addLast(word);

		}
		Dosya.close();
	}
	
	void FileRead::print()
	{
		Words->print();
	}
	void FileRead::KazancYazdir()
	{
		Words->kazancYazdir();
	}
	
	FileRead::~FileRead()
	{
		delete Words;
	}
	