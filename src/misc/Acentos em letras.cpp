//Descreve os códigos hexadecimais de acentos em letras
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main()
{
	char ans='n';
	
	while (ans == 'n')
	{
		cout << setw(05) << "Letra" << setw(22) << "C\xA2 \bdigo hexadecimal";
		cout << setw(23) << "C\xA2 \bdigo decimal\n";
		
		//Minúsculas
		cout << "\nMin\xA3sculas\n\n";
		
		//a
		cout << setw(05) << "\x83" << setw(20) << "83" << setw(20) << "131" << "\n\n"; //â
		cout << setw(05) << "\x85" << setw(20) << "85" << setw(20) << "133" << "\n\n"; //à
		cout << setw(05) << "\xA0" << setw(20) << "A0" << setw(20) << "160" << "\n\n"; //á
		cout << setw(05) << "\xC6" << setw(20) << "C6" << setw(20) << "198" << "\n\n"; //ã
		
		//c
		cout << setw(05) << "\x87" << setw(20) << "87" << setw(20) << "135" << "\n\n"; //ç
		
		//e
		cout << setw(05) << "\x82" << setw(20) << "82" << setw(20) << "130" << "\n\n"; //é
		cout << setw(05) << "\x88" << setw(20) << "88" << setw(20) << "136" << "\n\n"; //ê
		cout << setw(05) << "\x8A" << setw(20) << "8A" << setw(20) << "138" << "\n\n"; //è
		
		//i
		cout << setw(05) << "\x8C" << setw(20) << "8C" << setw(20) << "140" << "\n\n"; //î
		cout << setw(05) << "\x8D" << setw(20) << "8D" << setw(20) << "141" << "\n\n"; //ì
		cout << setw(05) << "\xA1" << setw(20) << "A1" << setw(20) << "161" << "\n\n"; //í
		
		//o
		cout << setw(05) << "\x93" << setw(20) << "93" << setw(20) << "147" << "\n\n"; //ô
		cout << setw(05) << "\x95" << setw(20) << "95" << setw(20) << "149" << "\n\n"; //ò
		cout << setw(05) << "\xA2" << setw(20) << "A2" << setw(20) << "162" << "\n\n"; //ó
		cout << setw(05) << "\xE5" << setw(20) << "E5" << setw(20) << "229" << "\n\n"; //õ
		
		//u
		cout << setw(05) << "\x81" << setw(20) << "81" << setw(20) << "129" << "\n\n"; //ü
		cout << setw(05) << "\x96" << setw(20) << "96" << setw(20) << "150" << "\n\n"; //û
		cout << setw(05) << "\x97" << setw(20) << "97" << setw(20) << "151" << "\n\n"; //ù
		cout << setw(05) << "\xA3" << setw(20) << "A3" << setw(20) << "163" << "\n\n"; //ú
		
		system("PAUSE");
		system ("CLS");
		
		cout << setw(05) << "Letra" << setw(22) << "C\xA2 \bdigo hexadecimal";
		cout << setw(23) << "C\xA2 \bdigo decimal\n";
		
		//Maiúsculas
		cout << "\nMai\xA3sculas\n\n";
		cout << setw(05) << "\xB5" << setw(20) << "B5" << setw(20) << "181" << "\n\n"; //Á
		cout << setw(05) << "\xB6" << setw(20) << "B6" << setw(20) << "182" << "\n\n"; //Â
		cout << setw(05) << "\xB7" << setw(20) << "B7" << setw(20) << "183" << "\n\n"; //À
		cout << setw(05) << "\xC7" << setw(20) << "C7" << setw(20) << "199" << "\n\n"; //Ã
		
		cout << setw(05) << "\x8F" << setw(20) << "8F" << setw(20) << "143" << "\n\n"; //°A
		
		cout << setw(05) << "\x80" << setw(20) << "80" << setw(20) << "128" << "\n\n"; //ç
		
		cout << setw(05) << "\x90" << setw(20) << "90" << setw(20) << "144" << "\n\n"; //É
		cout << setw(05) << "\xD2" << setw(20) << "D2" << setw(20) << "210" << "\n\n"; //Ê
		
		cout << setw(05) << "\xD6" << setw(20) << "D6" << setw(20) << "214" << "\n\n"; //Í
		cout << setw(05) << "\xD7" << setw(20) << "D7" << setw(20) << "215" << "\n\n"; //Î
		
		cout << "\nFechar janela? (y/n): ";
		cin >> ans;
		
		cout << "\n\n";
		system ("CLS");
	}
}
