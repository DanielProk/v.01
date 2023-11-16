#pragma once
#include <iomanip>
#include <numeric>
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <fstream>
#include "fast.h"
#include "mix.h"
#include <random>
#include <deque>


using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;
using std::domain_error;
using std::sort;
using std::mt19937;
using std::deque;

//extern char skaiciavimo_Strategija;

//extern string failoVardas;

using hrClock = std::chrono::high_resolution_clock;
typedef std::uniform_int_distribution<int> int_distribution;
int minimum(int a, int b);

class Student {
public:
	string Name, Surname;
	//array<int, 10> paz;
	vector<int> HW;
	int Exam;
	float Rez;
public:
	Student();
	Student(string N, string S, vector<int>H, int E);
	Student(const Student& A);
	Student& operator=(const Student& A);
	~Student();
	float Vid();
	float Med();
	void Rezult(char pas);
	//Setter
	inline void SetName(string N) { Name = N; };
	inline void SetSurname(string S) { Surname = S; };
	inline void SetHW(vector <int> Vec) { HW = Vec; };
	inline void SetExam(int n) { Exam = n; };
	//Getter
	float GetRez() const { return Rez; }
	string GetVard()const { return Name; }
	//kitos
	void printas();
	friend std::ostream& operator<<(std::ostream& out, const Student& A);
	friend std::istream& operator>>(std::istream& in, Student& a);
	//bool operator<(const Student& B);
};
bool maziauVid(const Student& A, const Student& B);
bool maziauVard(const Student& A, const Student& B);
//bool operator<(const Student& A, const Student& B);