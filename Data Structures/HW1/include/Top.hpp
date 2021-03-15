/**
* @file Data_Structur_Assignment_1
* @description Heap bellek de oluşturulan kovaların içlerinde birer top tutarak çeşitli işlemler yapması.
* @course Örgün Eğitim 1/A
* @assignment Birinci(1) Ödev
* @date 11.10.2019
* @author Melih Ensar Barışık  / Ömer Can Çalişir 
*/#ifndef TOP_HPP
#define	TOP_HPP

class Top
{
	private:
	char top;
	char harfler[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
					 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R',
					 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

	public:
	Top();
	char getTop();
	
	
};




#endif