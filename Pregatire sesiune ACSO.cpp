#include <iostream>

using namespace std;

/*
	Sa se scrie in limbaj de asamblare o functie definita astfel:

	int strAdd(char *sir, unsigned int sirMaxLength, char *toAdd)

	sir si toAdd sunt pointeri catre siruri de caractere terminate prin '\0'
	sirMaxLength - indica numarul total de caractere al tabloului indicat prin parametrul sir

	Functia va adauga in continuarea textului din variabila sir, textul din variabila toAdd si va returna 1.
	In cazul in care prin aceasta adaugare s-ar depasi numarul total de caractere al taboului indicat prin
	parametrul sir, adaugarea nu se va mai face, iar functia va returna 0

*/


int strAdd(char* sir, unsigned sirMaxLength, char* toAdd)
{
	_asm
	{
		mov esi, [ebp + 8]         //adresa sirului sir
		mov ecx, 0                 //ecx = 0 - il folosim ca index
		_bucla_size_sir:           //calculam mai intai dimensiunea sirului sir
		mov al, [esi + ecx]        //al = sir[ecx]
			cmp al, '\0'               //comparam al cu '\0'

			//ultimele doua instructiuni din blocul de mai sus pot fi inlocuite cu
			//cmp byte ptr [esi + ecx], '\0'

			je _sf_bucla_size_sir      //daca am ajuns la '\0', iesim din bucla, am parcurs sirul
			inc ecx                    //altfel, incrementam indexul
			jmp _bucla_size_sir        //reluam bucla

			//la sfarsitul buclei de mai sus in ecx se va regasi numarul de elemente din sir

		_sf_bucla_size_sir:
		mov esi, [ebp + 16]       //adresa sirului toAdd
			mov edx, 0                //edx = 0 - il folosim ca index
			_bucla_size_toadd :       //calculam dimensiunea sirului toAdd
			mov al, [esi + edx]       //al = toAdd[edx]
			cmp al, '\0'              //comparam al cu '\0'
			je _sf_bucla_size_toadd   //daca am ajuns la '\0', iesim din bucla, am parcurs sirul
			inc edx                   //altfel, incrementam indexul
			jmp _bucla_size_toadd     //reluam bucla

			//la sfarsitul buclei de mai sus in edx se va regasi numarul de elemente din sir

		_sf_bucla_size_toadd:

		mov ebx, ecx            //ebx = ecx (numarul de elemente din sirul sir)
			add ebx, edx            //ebx = ebx + ecx (nr. elem. din sir + nr. elem. din toAdd)
			inc ebx                 //ebx = ebx + 1 (adaugam si un caracter '\0')
			cmp ebx, [ebp + 12]     //comparam dimensiunea sirurilor concatenate cu dimensiunea maxima a primului sir
			ja _nu_incape           //daca e mai mare, nu putem concatena al doilea sir la primul, sarim la _nu_incape
			mov edx, 0              //edx = 0 - il folosim ca index sa parcurgem toAdd
			mov esi, [ebp + 8]      //esi = adresa primului sirului sir
			mov edi, [ebp + 16]     //edi = adresa sirului toAdd
			_bucla_adaugare:
		cmp ecx, ebx            //comparam indexul cu care parcugem sirul sir cu dimensiunea finala (ecx este egal cu indexul elementului '\0' din sirul sir)
			ja _sfarsit_adaugare    //daca e mai mare, am terminat de adaugat elementele sirului toAdd, sarim la _sfarsit_adaugare
			mov al, [edi + edx]     //al = toAdd[edx]
			mov[esi + ecx], al     //sir[ecx] = toAdd[edx]
			inc edx                 //incrementam indexul cu care parcurgem toAdd
			inc ecx                 //incrementam indexul cu care parcurgem sir
			jmp _bucla_adaugare     //reia bucla de adaugare

			_nu_incape :
		mov eax, 0              //daca nu pot concatena sirurile, returnez 0
			jmp _final              //sari la final

			_sfarsit_adaugare :
		mov al, '\0'            //al = '\0'
			mov[esi + ecx], al     //dupa concatenare, trebuie sa punem la sfarsitul sirului add un '\0'
			mov eax, 1              //returnam 1

			_final :
	}
}



int main()
{
	char sir[10] = "Ana";
	char toadd[] = " are"; //pentru " are mere" rezultatul va fi 0
	int rezultat;

	rezultat = strAdd(sir, 10, toadd);
	cout << rezultat << '\n' << sir << '\n';

	return 0;
}