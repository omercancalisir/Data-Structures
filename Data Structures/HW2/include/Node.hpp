/**
* @file Data_Structures_Assignment_2
* @description Dugum veri yapisinda kâr sagliyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 2.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/
#ifndef NODE_HPP
#define	NODE_HPP
#include <iostream>
#include<string>

using namespace std;


class Node
{
	
	public:
	Node* next;
	Node* prev;
	string data;

	Node(string data = string(), Node* next = NULL, Node* prev = NULL);
	


	

};




#endif