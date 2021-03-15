/**
* @file Data_Structures_Assignment_2
* @description Dugum veri yapisinda kâr sagliyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 2.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#ifndef ITERATOR_HPP
#define	ITERATOR_HPP
#include "Node.hpp"
class Iterator
{
	public:
	Node* current;
	Iterator();
	Iterator(Node* node);

	void next();
	void prev();
	const string getCurrent();
	bool canMove();
	
	
	
};




#endif