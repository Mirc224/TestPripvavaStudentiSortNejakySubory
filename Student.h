#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip> /
class Student
{
public:
	Student();
	Student(std::string meno, std::string priezvisko, char pohlavie): m_meno(meno), m_priezvisko(priezvisko), m_pohlavie(pohlavie){}
	void nacitaj(std::istream& is);
	void vypis(std::ostream& os);
	friend std::istream& operator >>(std::istream& is, Student* b)
	{
		b->nacitaj(is); return is;
	}
	friend std::ostream& operator <<(std::ostream& os, Student* b) //takyto zapis aby sa to dalo retazit
	{
		b->vypis(os); return os;
	}
	std::string toStringStudent() 
	{ 
		std::stringstream stream;
		stream << std::fixed <<std::setprecision(2) << m_priemer;
		stream  <<  ": " + m_priezvisko + " " + m_meno + "\n";
		return stream.str(); 
	}
	double getPriemer() { return m_priemer; }
	char getPohlavie() { return m_pohlavie; }
	virtual ~Student();
private:
	enum znamky{A = 1, B, C, D, E};
	std::string m_meno;
	std::string m_priezvisko;
	char m_pohlavie;
	std::vector<char> m_znamky;
	double m_priemer;
};

