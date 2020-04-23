#ifndef CONGRUENCE
#define CONGRUENCE

#include<iostream>
#include<cmath>
#include "Divisibility.h"
using namespace std;

struct LinearRes {
	long long *res;
	long long len;
	LinearRes(long long *r, long long l):res(r), len(l) {}
};

struct poly {
	long long *coef; //ϵ����n+1ά������
	long long n; //����
	poly(long long *c, long long nn):coef(c),n(nn) {}
};

struct PolyRes {
	poly q,r;
	PolyRes(poly qq, poly rr):q(qq),r(rr) {}
};

class NotMutualPrime {
	public:
		void message() {
			cout<<"������������ֵ�����أ�";
		}
};

// ����1��ͬ���ж�
bool IsCongruent(const long long &a, const long long &b, const long long &m) {
	if(m <= 0 || m > 9223372036854775807) throw InputOutOfRange();
	if((a-b)%m == 0)
		return true;
	else
		return false;
}

// ����2��ŷ������
long long EulerFunction(const long long &n) {
	if(n <= 0 || n > 9223372036854775807) throw InputOutOfRange();
	FacRes fac = PrimeFactorization(n);
	long long res = n;
	for(int i=0; i<fac.num; i++) {
		res *= *(fac.base+i)-1;
		res /= *(fac.base+i);
	}
	return res;
}

// ����3��ģ�ظ�ƽ�����㷨
long long ModularRepeatSquareMethod(const long long &b, const long long &n, const long long &m) {
	if(m <= 0 || m > 9223372036854775807) throw InputOutOfRange();
	int k = 0;
	long long tmp = n;
	while(tmp != 0) {
		k ++;
		tmp /= 2;
	}
	tmp = n;
	bool *N = new bool[k];
	for(int i=0; i<k; i++) {
		N[i] = bool(tmp%2);
		tmp /= 2;
	}
	long long A = 1;
	long long B = b%m;
	for(int i=0; i<k; i++) {
		if(N[i]) A = (A*B)%m;
		B = (B*B)%m;
	}
	return A;
}

// ����4��һ��ͬ��ʽax=b(mod m)���
// ����н⣬����������ͳ��ȣ�����޽⣬�����ָ���0
LinearRes LinearCongruence(const long long &a, const long long &b, const long long &m) {
	if(m <= 0 || m > 9223372036854775807) throw InputOutOfRange();
	long long g = gcd(a,m);
	if(b%g != 0) return LinearRes(NULL,0);
	if(b == 1) {
		BezRes br = bezout(a,m);
		while(br.s < 0) br.s += m;
		if(br.s >= m) br.s %= m;
		long long *q = new long long(br.s);
		return LinearRes(q,1);
	}
	long long tmp;
	tmp = LinearCongruence(a/g,1,m/g).res[0];
	tmp = tmp*(b/g)%(m/g);
	long long *q = new long long[g];
	for(int i=0; i<g; i++) {
		*(q+i) = tmp;
		tmp += m/g;
	}
	return LinearRes(q,g);
}

// ����5���й�ʣ�ඨ���㷨ʵ��
// N:ͬ��ʽ������b:Nάϵ����������ΪNULL���������ĸ��ʾ������-1����m:Nάģ������Ҫ���أ������׳��쳣��
long long ChineseRemainder(int N, long long *b, long long *m) {
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++) {
			if(i == j) continue;
			if(gcd(m[i],m[j]) != 1) throw NotMutualPrime();
		}
	long long *res = new long long[N];
	long long M;
	long long m_prod = 1;
	for(int i=0; i<N; i++)  m_prod *= m[i];
	for(int i=0; i<N; i++) {
		M = m_prod/m[i];
		M *= LinearCongruence(M,1,m[i]).res[0];
		res[i] = M%m_prod;
	}
	if(!b) {
		cout<<"\nx = "<<res[0]<<'*'<<"b1";
		for(int i=1; i<N; i++)
			cout<<" + "<<res[i]<<'*'<<'b'<<i+1;
		cout<<" (mod "<<m_prod<<')';
		return -1;
	}
	M = 0;
	for(int i=0; i<N; i++) {
		M += b[i]*res[i];
		M %= m_prod;
	}
	return M;
}

// ����6������ʽŷ����ó���
PolyRes PolyEuclidean(poly f, poly g) {
	int i;
	poly q(NULL,0);
	if(f.n < g.n) {
		q.n = 0;
		q.coef = new long long(0);
		return PolyRes(q,f);
	}
	q.n = f.n-g.n;
	q.coef = new long long[q.n+1];
	while(f.n >= g.n) {
		q.coef[f.n-g.n] = f.coef[f.n]/g.coef[g.n];
		for(i=0; i<=g.n; i++)
			f.coef[i+f.n-g.n] -= g.coef[i]*q.coef[f.n-g.n];
		for(i=f.n; i>=0; i--)
			if(f.coef[i] != 0) {
				f.n = i;
				break;
			}
		if(i == -1) f.n = 0;
	}
	return PolyRes(q,f);
}

// ����7��ģͬ����ټ���
long long CongruenceComputation(const long long &b, const long long &n, const long long &m) {
	if(m <= 0 || m > 9223372036854775807) throw InputOutOfRange();
	if(m == 1) return 0;
	if(IsPrime(m)) {
		if(gcd(b,m) != 1)  return 0;
		else return ModularRepeatSquareMethod(b,n%(m-1),m);
	}
	FacRes fac = PrimeFactorization(m);
	long long *B,*M;
	B = new long long[fac.num];
	M = new long long[fac.num];
	for(int i=0; i<fac.num; i++) {
		M[i] = pow(fac.base[i],fac.index[i]);
		B[i] = CongruenceComputation(b,n,M[i]);
	}
	return ChineseRemainder(fac.num,B,M);
}
#endif
