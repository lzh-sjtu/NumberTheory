#ifndef DIVISIBILITY
#define DIVISIBILITY

#include<iostream>
#include<cmath>
using namespace std;

struct EraRes {
	long long *res;
	long long len;
	EraRes(long long *r,long long l):res(r),len(l) {}
};

struct BezRes {
	long long s,t,gcd;
	BezRes(long long ss,long long tt,long long g):s(ss),t(tt),gcd(g) {}
};

struct FacRes {
	int *base;
	int *index;
	int num;
};

class InputOutOfRange {
	public:
		void message() {
			cout<<"错误：您的输入值超出范围！";
		}
};


// 函数1：素数判别
bool IsPrime(const long long & n) {
	if(n <= 0 || n > 9223372036854775807) throw InputOutOfRange();
	if(n == 1) return false;

	for(long long i=2; i<=sqrt(n); i++)
		if(n%i == 0) return false;
	return true;
}

// 函数2：Eratoshenes筛法
EraRes Eratoshenes(const long long & n) {
	if(n <= 0 || n > 9223372036854775807) throw InputOutOfRange();
	if(n == 1) return EraRes(NULL,0);

	bool *sieve = new bool[n+1];
	long long num = 0;
	long long k = 0;

	sieve[0] = sieve[1] = false;
	for(long long i=2; i<=n; i++) sieve[i] = true;

	for(long long i=2; i<=sqrt(n); i++) {
		if(!IsPrime(i)) continue;
		long long ran = n/i;
		for(long long j=2; j<=ran; j++) sieve[j*i] = false;
	}


	for(long long i=2; i<=n; i++)
		if(sieve[i]) num++;

	long long *res=new long long[num];

	for(long long i=2; i<=n; i++)
		if(sieve[i]) *(res+k++) = i;

	return EraRes(res,num);
}

// 函数3.辗转相除法求最大公因数
long long gcd(long long a,long long b) {
	long long r;
	a = abs(a);
	b = abs(b);
	do {
		r = a%b;
		a = b;
		b = r;
	} while(r != 0);
	return a;
}

// 函数4.贝祖算法实现
BezRes bezout(const long long &a,const long long &b) {
	if(a <= 0 || b <= 0 || a > 9223372036854775807 || b > 9223372036854775807) throw InputOutOfRange();

	int n = 0;
	long long a1 = a;
	long long b1 = b;
	long long r1 = a1%b1;
	while(r1 != 0) {
		a1 = b1;
		b1 = r1;
		r1 = a1%b1;
		n++;
	}
	n += 3;

	long long *s,*t,*q,*r;
	s = new long long[n];
	t = new long long[n];
	q = new long long[n];
	r = new long long[n];
	s[1] = t[2] = 1;
	s[2] = t[1] = 0;
	r[0] = a;
	r[1] = b;

	int j = 2;
	while(j < n-1) {
		q[j] = r[j-2]/r[j-1];
		r[j] = r[j-2]%r[j-1];
		s[j+1] = s[j-1] - s[j]*q[j];
		t[j+1] = t[j-1] - t[j]*q[j];
		j++;
	}
	return BezRes(s[n-1],t[n-1],r[n-2]);
}

// 函数5.素因数分解
FacRes PrimeFactorization(long long n) {
	if(n <= 1) throw InputOutOfRange();

	EraRes er = Eratoshenes(int(sqrt(n)));
	FacRes fr;
	fr.base = new int[er.len+1];
	fr.index = new int[er.len+1];
	int k = 0;
	for(int i=0; i<er.len; i++) {
		if(n%er.res[i] == 0) {
			fr.base[k] = er.res[i];
			fr.index[k] = 0;
			while(n%er.res[i] == 0) {
				fr.index[k]++;
				n /= er.res[i];
			}
			k++;
		}
	}
	if(n != 1) {
		fr.base[k] = n;
		fr.index[k] = 1;
		k++;
	}
	fr.num = k;
	return fr;
}

#endif
