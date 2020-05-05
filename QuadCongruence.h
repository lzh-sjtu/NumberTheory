#ifndef QUADCONGRUENCE
#define QUADCONGRUENCE

#include<iostream>
#include<cmath>
#include "Divisibility.h"
using namespace std;

class NotOdd {
	public:
		void message() {
			cout<<"错误：输入的模必须为奇数！";
		}
};

class NotPrime {
	public:
		void message() {
			cout<<"错误：勒让德符号要求底数为素数！";
		}
};

// 函数1：Legendre符号计算，即(\frac{a}{p})
int Legendre(const long long &a, const long long &p) {
	// 异常检测
	if(!IsPrime(p)) throw NotPrime();
	if(p == 2) throw NotOdd();
	if(p > 9223372036854775807) throw InputOutOfRange();

	// 取模形式简化
	long long b = a % p;

	// 容易判断的形式
	if(b % p == 0) return 0;
	if(b < 0)
		if(p % 4 == 1) return Legendre(-b,p);
		else return -1*Legendre(-b,p);
	if(b == 1) return 1;
	if(b == 2)
		if(p % 8 == 1 || p % 8 == 7) return 1;
		else return -1;

	// b为素数
	if(IsPrime(b)) {
		long long tmp = 0;
		// 二次互反律（加速算法执行过程）
		if(b < p) {
			tmp = (b-1)*(p-1)/4;
			if(tmp % 2 == 0) return Legendre(p,b);
			else return -1*Legendre(p,b);
		}
		// 直接计算（保证程序能够执行）
		for(int i=1; i<=(p-1)/2; i++)
			tmp += b*i/p;
		if(tmp % 2 == 0) return 1;
		else return -1;
	}

	// b不为素数（素因数分解）
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

// 函数2：Jacobi符号计算
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
