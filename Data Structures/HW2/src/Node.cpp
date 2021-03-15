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
#include <string>
#include "Node.HPP"

using namespace std;

Node::Node(string data, Node* next, Node* prev)
	{
		this->data = data;
		this->next = next;
		this->prev = prev;

	}
	
	