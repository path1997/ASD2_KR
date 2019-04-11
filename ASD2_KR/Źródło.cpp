#include<iostream>
#include<string>
#include <fstream>
#include <unordered_set> 

class KR {
public:
	std::string fraza="",nazwa_pliku,calosc="";
	char znak;
	int przypadki,il_ident_liter;
	std::fstream plik;
	std::unordered_set<char> litery;
	

	void start() {
		std::cin >> przypadki;
		for (int i = 0; i < przypadki; i++) {
			std::cin >> nazwa_pliku;
			std::cin >> fraza;
			plik.open(nazwa_pliku, std::ios::in);
			if (plik.good() == true)
			{
				while (!plik.eof())
				{
					plik >> znak;
					litery.insert(znak);
					calosc +=znak;
				}
				plik.close();
			}
			//std::cout << calosc << std::endl;
			il_ident_liter = litery.size();
			//std::cout << il_ident_liter;
			char * tablica = new char[il_ident_liter];

			std::cout << "myset contains:";
			for (std::unordered_set<int>::iterator it =0; it < il_ident_liter; ++it)
				std::cout << ' ' << *it;

			calosc = "";
			litery.clear();
		}
	}
};

int main() {
	KR k;
	k.start();
	return 0;
}