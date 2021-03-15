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
#include "Iterator.HPP"




using namespace std;

Iterator::Iterator() { current = NULL; }
Iterator::Iterator(Node* node) { current = node; }
void Iterator::next() { current = current->next; }
void Iterator::prev() { current = current->prev; }
const string Iterator::getCurrent() { return current->data; }
bool Iterator::canMove() { return current == NULL; }


