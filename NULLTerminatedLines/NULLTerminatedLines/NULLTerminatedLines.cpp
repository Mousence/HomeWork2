#include <iostream>
#include <windows.h>

using namespace std;

char* to_lower(char str[]) {
	for (int i = 0;str[i] != '\0'; i++) {
		if (str[i] >= 65 && str[i] <= 90)
			str[i] += 32;
	}
	return str;
}

char* shrink(char str[]){
	int count = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if ((str[i] == 32) && (str[i + 1] == 32));
		else {
			str[count] = str[i];
			count++;
		}
	}

	str[count] = '\0';
	return str;
}

bool is_palindrome(char str[]) {
	int i = 0;
	for (; str[i]; i++); i--;
	for (int j = 0; str[j] != '\0'; j++) {
		if (str[j] != str[i])
			return 0;
		i--;
	}
	return 1;
}

int main()
{
	setlocale(LC_ALL, "");
	char* str = new char;

	cin.getline(str, 256);
	cout << endl;

	cout << to_lower(str) << endl << endl;
	cout << shrink(str) << endl;

	if (is_palindrome(str))
		cout << "Является палиндромом" << endl;
	else
		cout << "Не является палиндромом" << endl;
}