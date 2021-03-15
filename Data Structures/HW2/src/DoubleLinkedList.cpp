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
#include "DoubleLinkedList.HPP"


using namespace std;

	Iterator DoubleLinkedList::OncekiniKonumuIleBul(int konum)
	{
		int index = 0;
		Iterator* iterator = new Iterator(head);
		//Iteratore ilk dugumun adresi veriliyor.
		while (!iterator->canMove() && konum != index++) iterator->next();
		//Her dönüşte düğüm ilerliyor ve konum index e eşit olunca istenilen düğümden bir önceki düğüme gelinmiş oluyor.
		return *iterator;
		delete iterator;
	}
	DoubleLinkedList::DoubleLinkedList()
	{
		head = new Node();
		size = 0;
		sayac = 0;
	}
	void DoubleLinkedList::addLast(string data)
	{
		Iterator* iterator = new Iterator;
		*iterator = OncekiniKonumuIleBul(size);
		Node* newNext = iterator->current->next;
		iterator->current->next = new Node(data, newNext, iterator->current);

		size++;
		delete newNext;
		delete iterator;
	}
	void DoubleLinkedList::print()
	{
	
		int sayac = 0;
		//Bağlı liste sona gelmediği sürece devam ediyor.
		while (head->next != NULL)
		{
			if (head->prev == NULL)
				//Eğer düğüm ilk düğüm ise NULL yazdırılıyor.
			{
				cout << "NULL";
			}
			if (sayac == 0)
				//Dügüm girişinde ise istenen desene uygun şekiller bastırılıyor.
			{
				cout << "<-:" << head->next->data << ":<->:";

				head = head->next;
			}

			if (sayac == size - 1)
				//Dügüm çıkışında ise istenen desene uygun şekiller bastırılıyor.
			{
				cout << head->next->data << ":->";

				head = head->next;
			}

			if (sayac != 0 && sayac != size - 1)
				//Düğüm girişi veya çıkışı değil ise ara desenlere uygun şekiller yazdırılıyor.
			{
				cout << head->next->data << ":<->:";

				head = head->next;
			}

			if (head->next == NULL)
				//Eğer düğüm son düğüm ise NULL yazdırılıyor.
			{
				cout << "NULL";
			}

			sayac++;

		}
		
	}
	string DoubleLinkedList::compare(string Word)
	{
		sayac = 0;
		Iterator* iterator = new Iterator;
		string add = " - 0";
		string otherAdd = " - ";
		*iterator = OncekiniKonumuIleBul(size);
		Word = Word + add;
		//Gelen kelime ve düğümde olan kelime düğümde olan kelime ile  karşılaştırılıyor.
		while (iterator->current != NULL)
		{
			sayac++;
			//iki kelime birbirine eşit ise yeni gelen kelime yerine aralarındaki mesafe yazılıyor.
			if (iterator->getCurrent() == Word)
			{
				Word = otherAdd + to_string(sayac);
				return Word;
			}

			iterator->prev();
		}

		return Word;
		delete iterator;
		
	}
	void DoubleLinkedList::kazancHesapla(string Word)
	{
		Iterator* iterator = new Iterator;
		*iterator = OncekiniKonumuIleBul(size);
		int sayac = 0;
		string word1 = Word;
		string add = " - 0";
		word1 = word1 + add;
		while (iterator->current != NULL)
			// düğümün anlık değeri null olmadığı sürece düğüm içinde geri gidiyor.
		{
			sayac++;
			//İstenen kelime ve düğümde bir eşleşme varsa if komutu çalışıyor.
			if (iterator->getCurrent() == word1)
			{
				int sizeWord = Word.length();
				int sizeSayac = to_string(sayac).length();
				kazancSaglananByteSayisi += sizeWord - sizeSayac;
				//Eşleşme olan düğümler arasındaki uzaklığın byte değerinden uzaklığın sahip olduğu karakter sayısınin byte değeri çıkarılıp kâr hesaplanıyor.

			}

			iterator->prev();
		}
		
		delete iterator;
	}
	void DoubleLinkedList::kazancYazdir()
	{
		cout << endl;
		cout << "Kazanc :" << kazancSaglananByteSayisi << endl;
	}
	