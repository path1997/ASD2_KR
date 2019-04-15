#include<iostream>
#include<string>
#include <fstream>
#include <functional>

class KR {
public:
	std::string fraza="",nazwa_pliku,calosc="",temp="";
	int przypadki,r_fraza,r_calosc;
	unsigned long long int hash_fraza, hash_czesc;
	std::ifstream plik;
	std::hash < std::string > haszujTekst;
	

	void start() {
		std::cin >> przypadki;
		for (int i = 0; i < przypadki; i++) {
			std::cin >> nazwa_pliku;
			std::cin.ignore();
			std::getline(std::cin, fraza);
			plik.open(nazwa_pliku, std::ios::in);
			if (plik.good() == true)
			{
				while (!plik.eof())
				{
					std::getline(plik, temp);
					calosc += temp;
				}
				plik.close();
				temp = "";
			}
			
			hash_fraza = haszujTekst(fraza);
			r_fraza = fraza.length();
			r_calosc = calosc.length();
			for (int j = 0; j < r_calosc - r_fraza; j++) {
				for (int k = j; k < j + r_fraza; k++) {
					temp += calosc[k];
				}
				hash_czesc= haszujTekst(temp);
				if (hash_czesc == hash_fraza) {
					if (temp == fraza) {
						std::cout << j << " ";
					}
				}
				temp = "";
			}
			std::cout << std::endl;
			calosc = "";
		}
		/*char d = 'e';
		char f = 'ê';
		std::cout << (int)d << " " << (int)f;*/
	}
};

int main() {
	setlocale(LC_ALL, "");
	KR k;
	k.start();
	return 0;
}