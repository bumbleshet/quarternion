// Quarternion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<cmath>
class Quaternion {
public:
	Quaternion (int e=0, int i=0, int j=0, int k=0) {
		a = e;
		b = i;
		c = j;
		d = k;
	}
	Quaternion operator+(const Quaternion& q) {
		Quaternion qt;
		qt.a = a + q.a;
		qt.b = b + q.b;
		qt.c = c + q.c;
		qt.d = d + q.d;

		return qt;
	}
	Quaternion operator-(const Quaternion& q) {
		Quaternion qt;
		qt.a = a - q.a;
		qt.b = b - q.b;
		qt.c = c - q.c;
		qt.d = d - q.d;

		return qt;
	}
	Quaternion operator*(const Quaternion& q) {
		Quaternion qt;
		qt.a = a*q.a - b*q.b - c*q.c - d*q.d;
		qt.b = b*q.a + a*q.b + c*q.d - d*q.c;
		qt.c = a*q.c - b*q.d + c*q.a + d*q.b;
		qt.d = a*q.d + b*q.c - c*q.b + d*q.a;

		return qt;
	}
	Quaternion operator/(const Quaternion& q) {
		Quaternion qt;
		qt = *this*conj(q);

		return qt;
	}
	Quaternion conj(Quaternion q) {
		q.b = q.b*-1;
		q.c = q.c*-1;
		q.d = q.d*-1;
		return q;
	}
	Quaternion square(Quaternion q) {
		q.a = pow(q.a, 2);
		q.b = pow(q.b, 2);
		q.c = pow(q.c, 2);
		q.d = pow(q.d, 2);
		return q;
	}
private:
	int a;
	int b;
	int c;
	int d;
	friend istream& operator>>(istream& is, Quaternion& q);
	friend ostream& operator<<(ostream& os,const Quaternion& q);
};
istream& operator>>(istream& is,Quaternion& q) {
	cout << "Enter quaternion "<<endl;
	is>> q.a>> q.b>> q.c>> q.d ;
	return is;
}
ostream& operator<<(ostream& os, const Quaternion& q) {
	os << "{ " <<q.a<<" "<<q.b <<" " <<q.c<<" "<<q.d<<" }" ;
	return os;
}
int main(){
	Quaternion q1(1,2,3,4);
	Quaternion q2(1,2,3,4);
	cout << (q1 + q2)<<endl;
	cout << q1/q1 << endl;
	system("pause");
    return 0;
}

