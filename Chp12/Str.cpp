#include <cctype>

#include <cstring>
#include <iostream>
#include <iterator>

#include "Str.h"

using namespace std;

ostream& operator<<(ostream& os, const Str& s) {
	copy(s.begin(), s.end(), ostream_iterator<char>(os));
	return os;
}

// �Է� ������
istream& operator>>(istream& is, Str& s) {
	// ������ �� ����
	if (s.value != 0)
		delete[] s.value;
	char c;

	while (is.get(c) && std::isspace(c))
		; // ������ �����ϴ� �� ���� ������ ����.

	// ���� ���ڰ� ���� �ִٸ� ���� ���� ���ڿ�
	// ������ ������ ���ڸ� ����.
	if (is) {
		do s += c;
		while (is.get(c) && !isspace(c));

		// ������ �о��ٸ� �ٽ� ��Ʈ���� ���ܵ�
		if (is) {
			is.unget();
		}
	}
	return is;
}

istream& getline(istream& is, Str& s) {
	// ���� �ٱ��� �б�
	char c;
	while (is.get(c) && c != '\n')
		s += c;

	return is;
}

Str operator+(const Str& s, const Str& t) {
	Str r = s;
	r += t;
	return r;
}

// Q5
Str operator+(const Str& s, const char* t) {
	Str r = s;
	r += t;
	return r;
}

// Q11
Str operator+(const char* t, const Str& s) {
	Str r(t);
	r += s;
	return r;
}

// �� ������ �߰�
bool operator<(const Str& lhs, const Str& rhs) { // Q3
	return strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator>(const Str& lhs, const Str& rhs) { // Q3
	return strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator<=(const Str& lhs, const Str& rhs) { // Q3
	return strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>=(const Str& lhs, const Str& rhs) { // Q3
	return strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}
bool operator==(const Str& lhs, const Str& rhs) { // Q4
	return strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const Str& lhs, const Str& rhs) { // Q4
	return strcmp(lhs.c_str(), rhs.c_str()) != 0;
}