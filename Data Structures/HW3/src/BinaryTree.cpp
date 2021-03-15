/**
* @file Data_Structures_Assignment_3
* @description İki farkli agacin soy degerlerini karsilastirip verilen durumlara gore ekleme ve silme islemi yapiyor.
* @course 1.Ogretim / 1A sınıfı
* @assignment 3.Odev
* @date 7.11.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
**/
#include <iostream>
#include<Windows.h>
#include "BinaryTree.HPP"

using namespace std;

//Class içideki elemanlara ilk değer atamalarını yapıyor.
BinaryTree::BinaryTree()
	{
		toplamSoySayisi = 0;
		root = NULL;
	}
	
//Class içinde head bellek bölgesinde oluşan elemanlar en son siliniyor.
BinaryTree::~BinaryTree()
{
	delete root;
}

	void BinaryTree::sil(Node*& dugum)
	{
		Node* silinecekdugum = dugum;
		//Silinecek düğümün sağında bir düğüm yoksa sola ilerle komutu.
		if (dugum->right == NULL) dugum = dugum->left;
		//Silinecek düğümün solunda bir düğüm yoksa sağa ilerle komutu.
		else if (dugum->left == NULL) dugum = dugum->right;
		//silinecek düğüm iki çocuğa sahip ise
		else
		{
			silinecekdugum = dugum->left;
			Node* ebeveynNode = dugum;
			while (silinecekdugum->right != NULL)
			{
				ebeveynNode = silinecekdugum;
				silinecekdugum = silinecekdugum->right;
			}
			dugum->data = silinecekdugum->data;
			if (ebeveynNode == dugum) dugum->left = silinecekdugum->left;
			else ebeveynNode->right = silinecekdugum->left;
		}
		delete silinecekdugum;
		
	}
	
	void BinaryTree::AraVeSil(Node*& dugum, int arananDeger)
	{
		if (dugum == NULL)  false;
		//Verilen değer aranan değere eşit ise sil fonksiyonuna yollanıyor.
		if (dugum->data == arananDeger) sil(dugum);
		//Düğüm bulunana kadar postorder mantığı ile devam ediliyor.
		else if(arananDeger<dugum->data)
			 AraVeSil(dugum->left,arananDeger);
		else 
			 AraVeSil(dugum->right, arananDeger);

	}
	
	int BinaryTree::verilenDugumunsoySayisiHesapla(Node* dugum)
	{
		if (dugum == NULL)
		{
			return 0;
		}
    	// düğüm sağındaki ve solundaki her bir düğüm için değeri 1 arttırılıyor.
		return 1 + verilenDugumunsoySayisiHesapla(dugum->right) + verilenDugumunsoySayisiHesapla(dugum->left);
	
	}
	
	
	void BinaryTree::soyHesapla(Node* dugum)
	{
		if (dugum == NULL)
		{
			return;
		}
		
		//Hesaplanacak düğümün soy sayısı 0 a eşitleniyor.
		dugum->soy_sayisi = 0;
		//Postorder mantığı ile en alt düğüme iniliyor.
		soyHesapla(dugum->left);
		soyHesapla(dugum->right);
		//Toplam soy sayısı sahip olduğumuz düğümün  "verilenDugumunsoySayisiHesapla" fonksiyonunun yardımı ile bulunuyor.
		toplamSoySayisi = toplamSoySayisi + verilenDugumunsoySayisiHesapla(dugum) - 1;
		//her düğüme kendi soy sayısı veriliyor.
		dugum->soy_sayisi = verilenDugumunsoySayisiHesapla(dugum) - 1;
	}
	
	void BinaryTree::soyHesapla()
	{
		toplamSoySayisi = 0;
		soyHesapla(root);
	}
	
	
	void BinaryTree::postOrder(Node * dugum)
	{
		//Düğümün boş veya dolu olması kontrol ediliyor.
		if (dugum == NULL)
		{
			return;
		}
		//Postorder kurallarına göre ilk önce gidebildiği kadar sol tarafa daha sonra sağ tarafa gidiyor.
		postOrder(dugum->left);
		postOrder(dugum->right);
		//gidilecek yer kalmadığı zaman düğümün sahip olduğu veriyi yazdırıyor.
		cout << "<" << dugum->data << "," << dugum->soy_sayisi << "> ";
	}
	
	int BinaryTree::maxValue(Node* adres)
	{
		//Verilen düğümün sağ tarafında NULL olmadığı sürece bu tarafa gidiliyor.
		if (adres->right != NULL)
		{
			maxValue(adres->right);
		}
		//En son sağ kısma gelince burada düğüm yazılıyor.
		else
		{
			return adres->data;
		}
	}
	
	
	void BinaryTree::insert(int data)
	{
		insert(root, data);
	}
	
	
	void BinaryTree::insert(Node* adres, int data)
	{
		//Daha önce bir kök oluşmamış ise yeni oluşan düğümü kök düğüm yapıyor.
		if (root == NULL)
		{
			Node* yeniEleman = new Node(data);
			root = yeniEleman;
		}
		else
		{
			//Yeni düğümün sahip olduğu sayı karşılaştırılan düğümün sahip olduğu sayıdan büyük ise
			if (adres->data < data)
			{
				//Karşılaştırılan düğümün sağ kısmında bir düğüm yok ise yeni eleman buraya yerleştiriliyor.
				if (adres->right == NULL)
				{
					Node* yeniEleman = new Node(data);
					adres->right = yeniEleman;
				}
				//Karşılaştırılan düğümün sağa gitme olanağı var ise sağa gidilip fonksiyon tekrar çağrılıyor.
				else
				{

					insert(adres->right, data);
				}
			}
			else
			{
				//Karşılaştırılan düğümün sol kısmında bir düğüm yok ise yeni eleman buraya yerleştiriliyor.
				if (adres->left == NULL)
				{
					Node* yeniEleman = new Node(data);
					adres->left = yeniEleman;
				}
				//Karşılaştırılan düğümün sola gitme olanağı var ise sola gidilip fonksiyon tekrar çağrılıyor.
				else
				{
					insert(adres->left, data);
				}
			}
		}
		
	}