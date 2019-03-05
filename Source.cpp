#include <iostream>
#include <fstream>
#include <string>
//#include <cmath>

using namespace std;

int is_prime(int prst) {
	bool Nnat = true;
	int i = 2;
	while ((i*i <= prst) && Nnat) {
		Nnat = (prst % i == 0) ? !!0 : !!1;
		i++;
	};
	return Nnat;

}
int Pow(int x, int n) {
	if (x == 0) return 0;
	if (n == 0) return 1;
	else if ((n % 2) == 1) return x * Pow(x, n - 1);
	else if ((n % 2) == 0) return Pow(x*x, n / 2);
}

int main() {
	ifstream file("input1.dat");					//при необходимости сменить файл
	ofstream fileout("output1.txt", std::ios::app);	//при необходимости сменить файл
	if (file.is_open())
	{
		int timer = 0;		
		int t = 0;
		int a[6];
		string str;
		while (getline(file, str)) {
			char* buf = new char[6];
			int numbers = 0;
			strcpy_s(buf, 7, str.c_str());
			numbers = 0;
			for (int i = 0; i <= 5; i++)
			{
				int TEMP = buf[i] - '0';
				numbers+= TEMP * pow(10, 5-i);;
			}
			int temp = numbers;
			if (is_prime(numbers) == 0) {
				for (int i = 0; i <= 5; i++) {
					a[i] = is_prime(numbers + Pow(10, i));
				}
				for (int i = 0; i <= 5; i++) {
					(a[i] == 1) ? t++ : i = i;
				}
				if (t > 1) {
					fileout << numbers << "*"<<endl;

					/*функция вывода+"*"*/
				}
				else if (t = 1) {
					for (int i = 0; i <= 5; i++) {
						if (a[i] == 1) {
							fileout << numbers + Pow(10, i) << endl;//функция вывода
						}
					}
				}
			}
		}
	}
	fileout.close();
	file.close();
}

