#include "mylib.h"

char skaiciavimo_Strategija = 'v';


int main()
{
	int pasir;
	cout << "Generuoti studentus -1, skaityti is failo - 2\n";
	cin >> pasir;
	switch (pasir){
	case 1:{
		vector<Student> Grupe;
		cout << "Iveskite studentu skaiciu";
		int nr;
		cin >> nr;
		Grupe.reserve(nr);
		for (int i = 0; i < nr; i++) {
			Student Laikinas;
			string laikS;
			//vector <int> Vec;
			//cout << "Iveskite varda;
			//cin >> LaikS; Laikinas.SetName(laikS);
			//cout << "Iveskite pavarde: ";
			//cin >> laikS; Laikinas.SetSurname(laikS);
			//cout << "Kiek namu darbu buvo semestre? ";
			//int ndNr; cin << ndNr;
			//for (int i = 0; i < ndNr; i++)
			//{
			//	int pazim;
			//	cout << "iveskite " << i + 1 << " pazymi: ";
			//	cin >> pazim; Vec.push_back(pazim);
			//}
			//Laikinas.SetHW(Vec); Vec.clear();
			//cout << "Koks egzamino pazymis? "; cin>> ndNr;
			//Laikinas.Rezult('v');
			//cin >> Laikinas;
			Grupe.push_back(Laikinas);
			Laikinas.~Student();
		}

		//sort(Grupe.begin(),Grupe.end(),maziauVid);
		sort(Grupe.begin(), Grupe.end(), std::less<Student>());
		for (auto& duom : Grupe) cout << duom;
		break;
	}
	case 2: {
		vector<Student> Grupe;
		cout << "Iveskite failo pavadinima: ";
		system("dir *.txt");
		string vardas;
		cin >> vardas;

		Data_read(vardas, Grupe);
		sort(Grupe.begin(), Grupe.end());

		std::ofstream out_f("rezultatai.txt");
		for (auto& duom : Grupe) out_f << duom;
		out_f.close();
		break; 
	}
	}

	system("pause");
}