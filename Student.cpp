#include "Student.h"



Student::Student()
{

}


void Student::nacitaj(std::istream & is)
{
	is >> m_priezvisko >> m_meno >> m_pohlavie;
	for (int i = 0; i < 5; ++i)
	{
		char temp;
		is >> temp;
		m_znamky.push_back(temp);
	}
	m_priemer = 0.0;
	for (auto &p : m_znamky)
	{
		m_priemer += p - 64;
	}
	m_priemer = m_priemer / 5.0;
}

void Student::vypis(std::ostream & os)
{
	os << m_priezvisko << " " << m_meno << " " << m_pohlavie << " ";
	for (auto it = m_znamky.begin(); it != m_znamky.end(); ++it)
	{
		if (m_znamky.end() != std::next(it))
			os << *it << " ";
		else
			os << *it << std::endl;
	}
}

Student::~Student()
{
}
