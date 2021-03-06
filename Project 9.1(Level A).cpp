// Lab_9_1.cpp
// < Кузів Назар >
// Лабораторна робота № 9.1 Рівень А
//Послідовний пошук в масиві структур
// Варіант 6

#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

enum Specialty { KN, IT, MathAndEconomic, PhysicsandAndIT, TrudoveNavchany };;
string SpecialtyStr[] = { "Комп’ютерні науки", "Інформатика", "Математика та економіка","Фізика та інформатика","Трудове навчання" };

struct Student
{
	string prizv;
	int kurs;
	Specialty specialty;
	int Phisic;
	int Math;
	int IT;

}S;


void Create(Student* p, const int N);
void Print(Student* p, const int N);
int Percentage_of_Excellent_Students(Student* p, const int N);
void Print_Students_Who_Have_5_or_4_In_Physics(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	int N;
	cout << "Введіть кількість студентів N: "; cin >> N;

	Student* p = new Student[N];

	Create(p, N);
	Print(p, N);
	cout << endl;

	cout << "Процент студентів, які вчаться без трійокна (“відмінно” і “добре”). = " << Percentage_of_Excellent_Students(p, N) << "%" << endl;
	Print_Students_Who_Have_5_or_4_In_Physics(p, N);
	
	return 0;
}

void Create(Student* p, const int N)
{
	int specialty;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		
		cout << " Прізвище: "; getline(cin, p[i].prizv);
		cout << " Курс: "; cin >> p[i].kurs;
		cout << " Спеціальність (0 - Комп’ютерні науки, 1 - Інформатика, 2 - Математика та економіка, 3 - Фізика та інформатика, 4 - Трудове навчання): ";
		cin >> specialty;
		p[i].specialty = (Specialty)specialty;
		cout << " Оцінка з Фізики: "; cin >> p[i].Phisic;
		cout << " Оцінка з Математики: "; cin >> p[i].Math;
		cout << " Оцінка з Інформатики: "; cin >> p[i].IT;
		;
	}
}
void Print(Student* p, const int N)
{
	cout << "====================================================================================================================="
		<< endl;
	cout << "                                        Список студентів" << endl;
		
	cout << "====================================================================================================================="
		<< endl;
	cout << "|  № |   Прізвище   | Курс |      Спеціальність      | Оцінка з Фізики | Оцінка з Математики | Оцінка з Інформатики |"
		<< endl;
	cout << "---------------------------------------------------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(2) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(23) << left << SpecialtyStr[ p[i].specialty ] << " "
			<< "| " << setw(15) << right << p[i].Phisic << " "
			<< "| " << setw(19) << right << p[i].Math << " "
			<< "| " << setw(20) << right << p[i].IT << " |" << endl;
	}
	cout << "====================================================================================================================="
		<< endl;
	cout << endl;
}
int Percentage_of_Excellent_Students(Student* p, const int N)
{
	double P_of_S = 0;

	for (int i = 0; i < N; i++)
	{
		if (p[i].Phisic > 3 && p[i].Math > 3 && p[i].IT > 3)
			P_of_S += 1;
	}

	P_of_S = (P_of_S / N) * 100;

	return P_of_S;
}

void Print_Students_Who_Have_5_or_4_In_Physics(Student* p, const int N)
{
	int № = 0;
	cout << "Прізвища студентів, які отримали з фізики оцінки “5” або “4”: " << endl;

	for (int i = 0; i < N; i++)
	{
		if (p[i].Phisic == 4 || p[i].Phisic == 5)
			cout << ++№ << "." << p[i].prizv << endl;
	
	}


}