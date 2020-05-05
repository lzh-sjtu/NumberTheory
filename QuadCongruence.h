#ifndef QUADCONGRUENCE
#define QUADCONGRUENCE

#include<iostream>
#include<cmath>
#include "Divisibility.h"
using namespace std;

class NotOdd {
	public:
		void message() {
			cout<<"���������ģ����Ϊ������";
		}
};

class NotPrime {
	public:
		void message() {
			cout<<"�������õ·���Ҫ�����Ϊ������";
		}
};

// ����1��Legendre���ż��㣬��(\frac{a}{p})
int Legendre(const long long &a, const long long &p) {
	// �쳣���
	if(!IsPrime(p)) throw NotPrime();
	if(p == 2) throw NotOdd();
	if(p > 9223372036854775807) throw InputOutOfRange();

	// ȡģ��ʽ��
	long long b = a % p;

	// �����жϵ���ʽ
	if(b % p == 0) return 0;
	if(b < 0)
		if(p % 4 == 1) return Legendre(-b,p);
		else return -1*Legendre(-b,p);
	if(b == 1) return 1;
	if(b == 2)
		if(p % 8 == 1 || p % 8 == 7) return 1;
		else return -1;

	// bΪ����
	if(IsPrime(b)) {
		long long tmp = 0;
		// ���λ����ɣ������㷨ִ�й��̣�
		if(b < p) {
			tmp = (b-1)*(p-1)/4;
			if(tmp % 2 == 0) return Legendre(p,b);
			else return -1*Legendre(p,b);
		}
		// ֱ�Ӽ��㣨��֤�����ܹ�ִ�У�
		for(int i=1; i<=(p-1)/2; i++)
			tmp += b*i/p;
		if(tmp % 2 == 0) return 1;
		else return -1;
	}

	// b��Ϊ�������������ֽ⣩
	FacRes fac = PrimeFactorization(b);
	int idx;
	int res = 1;
	for(int i=0; i<fac.num; i++) {
		idx = fac.index[i] % 2;
		if(idx == 0) continue;
		else res *= Legendre(fac.base[i],p);
	}
	return res;
}

// ����2��Jacobi���ż���
int Jacobi(const long long &a, const long long &m) {
	if(m <= 1 || m > 9223372036854775807) throw InputOutOfRange();
	if(m % 2 == 0) throw NotOdd();

	FacRes fac = PrimeFactorization(m);
	int idx;
	int res = 1;
	for(int i=0; i<fac.num; i++) {
		idx = fac.index[i] % 2;
		if(idx == 0) continue;
		else res *= Legendre(a,fac.base[i]);
	}
	return res;
}
#endif
