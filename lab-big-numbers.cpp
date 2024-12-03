#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


string removeLeadingZeros(const string& str) {
	size_t i = 0;
	while (i < str.size() && str[i] == '0') {
		i++;
	}
	if (i == str.size()) {
		return "0";
	}
	return str.substr(i); 
}


string addStrings(string num1, string num2) {
	size_t lenght1 = num1.size();
	size_t lenght2 = num2.size();
	if (lenght1 < lenght2) {
		num1 = string(lenght2 - lenght1, '0') + num1;
	}
	else if (lenght1 > lenght2) {
		num2 = string(lenght1 - lenght2, '0') + num2;
	}
	int leftover = 0;
	size_t lenghtMax = num2.size();
	string result = "";
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0; i < lenghtMax; ++i) {
		int digitCombmined = 0;
		int digit1 = num1[i] - '0';
		int digit2 = num2[i] - '0';
		digitCombmined = digit1 + digit2 + leftover;
		if (digitCombmined > 9) {
			digitCombmined = digitCombmined - 10;
			leftover = 1;
		}
		else {
			leftover = 0;
		}
		result.push_back(digitCombmined + '0');
	}
	reverse(result.begin(), result.end());
	if (leftover == 1) {
		result.insert(result.begin(), leftover + '0');
	}

	return removeLeadingZeros(result);
}


string substractStrings(string num1, string num2) {
	size_t length1 = num1.size();
	size_t length2 = num2.size();
	if (length1 < length2) {
		num1 = string(length2 - length1, '0') + num1;
	}
	else if (length1 > length2) {
		num2 = string(length1 - length2, '0') + num2;
	}
	int leftover = 0; 
	size_t lengthMax = max(length1, length2);
	string result = "";
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0; i < lengthMax; ++i) {
		int digit1 = num1[i] - '0';  
		int digit2 = num2[i] - '0';  
		if (leftover == 1) {
			digit1 -= 1;
		}
		if (digit2 > digit1) {
			digit1 += 10; 
			leftover = 1; 
		}
		else {
			leftover = 0;  
		}
		int digitSubtracted = digit1 - digit2;  
		result.push_back(digitSubtracted + '0');  
	}
	reverse(result.begin(), result.end());

	return removeLeadingZeros(result);  
}


string multiplyStrings(string num1, string num2) {
	if (num1 == "0" || num2 == "0") {
		return "0";
	}
	int lenght1 = num1.size();
	int lenght2 = num2.size();
	string result(lenght1 + lenght2, '0'); 
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());
	for (int i = 0; i < lenght1; ++i) {
		for (int j = 0; j < lenght2; ++j) {
			int mul = (num1[i] - '0') * (num2[j] - '0'); 
			int sum = mul + (result[i + j] - '0'); 
			result[i + j] = (sum % 10) + '0'; 
			result[i + j + 1] += sum / 10; 
		}
	}
	reverse(result.begin(), result.end());

	return removeLeadingZeros(result);
}


string divideStrings(string num1, string num2) {
	if (num2 == "0") {
		cout << "Деление на 0";
		return "0";
	}
	if (num1 == "0") {
		return "0";
	}
	if (num2.size() > num1.size()) {
		return "0";  
	}
	string full = "";  
	string remains = ""; 
	for (size_t i = 0; i < num1.size(); ++i) {
		remains += num1[i];
		int count = 0;
		while (remains.size() > num2.size() || (remains.size() == num2.size() && remains >= num2)) {
			remains = substractStrings(remains, num2);  
			count++;
		}
		full += to_string(count);  
	}

	return removeLeadingZeros(full);
}	


bool isGreaterThan(string num1, string num2) {
	if (num1.size() > num2.size()) {
		return true; 
	}
	if (num1.size() < num2.size()) {
		return false; 
	}
	for (size_t i = 0; i < num1.size(); ++i) {
		if (num1[i] > num2[i]) {
			return true;  
		}
		if (num1[i] < num2[i]) {
			return false; 
		}
	}

	return false;
}


bool isLessThan(string num1, string num2) {
	if (num1.size() < num2.size()) {
		return true; 
	}
	if (num1.size() > num2.size()) {
		return false; 
	}
	for (size_t i = 0; i < num1.size(); ++i) {
		if (num1[i] < num2[i]) {
			return true; 
		}
		if (num1[i] > num2[i]) {
			return false; 
		}
	}

	return false; 
}


bool isEqualTo(string num1, string num2) {
	if (num1.size() != num2.size()) {
		return false; 
	}
	for (size_t i = 0; i < num1.size(); ++i) {
		if (num1[i] != num2[i]) {
			return false; 
		}
	}

	return true;
}


int main() {
	setlocale(LC_ALL, "Russian");
	string num1, num2;
	int var;
	cout << "Введите число 1: ";
	cin >> num1;
	cout << "Введите число 2: ";
	cin >> num2;
	while (true) {
		cout << num1 << "  ?  " << num2 << endl
			<< "Вместо '?' введите номер операции: " << endl
			<< "1. +" << endl
			<< "2. -" << endl
			<< "3. *" << endl
			<< "4. /" << endl
			<< "5. >" << endl
			<< "6. <" << endl
			<< "7. ==" << endl
			<< "0. Выход" << endl;
		cin >> var;
		if (var == 0) {
			cout << "Выход из программы..." << endl;
			break; 
		}
		if (var == 1) {
			cout << addStrings(num1, num2) << endl;
		}
		else if (var == 2) {
			cout << substractStrings(num1, num2) << endl;
		}
		else if (var == 3) {
			cout << multiplyStrings(num1, num2) << endl;
		}
		else if (var == 4) {
			cout << divideStrings(num1, num2) << endl;
		}
		else if (var == 5) {
			cout << isGreaterThan(num1, num2) << endl;
		}
		else if (var == 6) {
			cout << isLessThan(num1, num2) << endl;
		}
		else if (var == 7) {
			cout << isEqualTo(num1, num2) << endl;
		}
		else {
			cout << "Неверный ввод. Пожалуйста, попробуйте снова." << endl;
		}
	}

	return 0;
}