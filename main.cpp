#include <iostream>
#include <fstream>
#include <string>
#include <fstream>
#include "Student.h"
#include <set>

void factorOsoby(std::vector<Student*>& osoby, std::istream& is)
{
	while (!is.eof())
	{
		Student* temp = new Student();
		is >> temp;
		if (is.eof())
		{
			delete temp;
			break;
		}
		osoby.push_back(temp);
	}
}
void zapisHodnoty(std::vector<Student*>& osoby, std::ostream& os)
{
	for (auto &p : osoby)
	{
		os << p->toStringStudent();
	}
}

int main(int argc, char* argv[])
{
	std::vector<Student*> osoby;
	std::ifstream inputFile("studenti.txt");
	factorOsoby(osoby, inputFile);
	std::set<double> najlepsiPriemer;
	for (auto &student : osoby)
	{
		najlepsiPriemer.insert(student->getPriemer());
	}
	std::cout << "Najlepsi student a studentka!" << std::endl;
	bool najdenyNajlepsiStudent = false;
	bool najdenyNajlepsiaStudentka = false;
	std::ofstream outputFile("vystup.txt");
	for (auto &p : najlepsiPriemer)
	{
		for (auto &student : osoby)
		{
			if (p == student->getPriemer())
			{
				outputFile << student->toStringStudent();
				if (!najdenyNajlepsiStudent || !najdenyNajlepsiaStudentka)
				{
					if (student->getPohlavie() == 'M')
					{
						if (!najdenyNajlepsiStudent)
						{
							std::cout << student->toStringStudent();
							najdenyNajlepsiStudent = true;
						}
						else
							continue;
					}
					else
					{
						if (!najdenyNajlepsiaStudentka)
						{
							std::cout << student->toStringStudent();
							najdenyNajlepsiaStudentka = true;
						}
						else
							continue;
					}
				}
				else
					continue;
			}
		}
	}
	return 0;
}