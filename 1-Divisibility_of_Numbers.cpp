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

struct FacRes
{
	int *base;
	int *index;
	int num;
};

bool IsPrime(const long long &);
EraRes Eratoshenes(const long long &);
long long gcd(long long,long long);
BezRes bezout(const long long &,const long long &);
FacRes PrimeFactorization(long long); 

class InputOutOfRange {
	public:
		void message() {
			cout<<"������������ֵ������Χ��";
		}
};


int main() {
	cout<<"\n******************************************* ��һ�£������Ŀɳ��� <����ʵ��> *******************************************\n"
	    <<"����:lzh123@sjtu.edu.cn & 1084388051@qq.com\n"
	    <<"˵��:\n"
	    <<"1.�������е���������Χ����1-9223372036854775807֮�䣻\n"
	    <<"2.�������е�������Χ����-9223372036854775808-9223372036854775807֮�䣻\n"
	    <<"3.������Ĭ��ʹ����С�Ǹ�������\n";
	int choice;
	do {
		cout<<"\n\n########################################### ��ѡ�����¹��ܣ�ѡ��0�˳����� ###########################################\n"
		    <<"1.�����ж�     2.Eratoshenes����ɸѡ     3.Euclidean����     4.���������������������С������\n5.�����ж�     6.�����㷨ʵ��            7.�������ֽ�"
		    <<"\n�����룺";
		cin>>choice;

		try {
			switch(choice) {
				case 1: {
					cout<<"\n#1# ������һ��������n���ж�n�Ƿ�Ϊ����:";
					long long n;
					cin>>n;
					if(IsPrime(n)) {
						cout<<n<<"Ϊ����";
					} else {
						cout<<n<<"��Ϊ����";
					}
					cout<<endl;
					break;
				}

				case 2: {
					cout<<"\n#2# ������һ��������n������С�ڵ���n����������:";
					long long m;
					cin>>m;
					EraRes r = Eratoshenes(m);
					if(!r.res) {
						cout<<"������";
						continue;
					}
					cout<<"�ܹ���"<<r.len<<"������:\n";
					for(long long i=0; i<r.len; i++) {
						if(i%5 == 0) cout<<endl;
						cout<<*(r.res+i)<<"\t";
					}
					break;
				}

				case 3: {
					cout<<"\n#3# ����������a��������b������q��rʹ��a=q*b+r:\n";
					long long a,b;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					if(b <= 0) throw InputOutOfRange();
					long long q = a/b;
					long long r = a%b;
					if(a < 0) {
						q--;
						r += b;
					}
					if(r == 0 || r == b) {
						cout<<'['<<a<<"] �ܱ� ["<<b<<"] ����"<<endl;
						if(a < 0) q++;
						cout<<'['<<a<<']'<<" = "<<q<<" * ["<<b<<']'<<endl;
					} else {
						cout<<'['<<a<<"] ���ܱ� ["<<b<<"] ����"<<endl;
						cout<<'['<<a<<']'<<" = "<<q<<" * ["<<b<<"] + "<<r<<endl;
					}
					break;
				}

				case 4: {
					cout<<"\n#4# ����������a��b������շת���������gcd(a,b)��LCM[a,b]:\n";
					long long a,b,g;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					g = gcd(a,b);
					cout<<"�������: ("<<a<<','<<b<<") Ϊ "<<g<<endl;
					cout<<"��С������: ["<<a<<','<<b<<"] Ϊ "<<abs(a*b/g)<<endl;
					break;
				}

				case 5: {
					cout<<"\n#5# ����������a��b���ж������Ƿ���:\n";
					long long a,b;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					if(gcd(a,b) == 1) cout<<a<<"��"<<b<<"����"<<endl;
					else cout<<a<<"��"<<b<<"������"<<endl;
					break;
				}

				case 6: {
					cout<<"\n#6# ������������a��b���������s��tʹ��(a,b) = sa+tb:\n";
					long long a,b;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					BezRes r = bezout(a,b);
					cout<<"s = "<<r.s<<"\nt = "<<r.t<<"\n(a,b) = "<<r.gcd<<endl;
					break;
				}
					
				case 7: {
					cout<<"\n#7# ������������n������n���������ֽ�ʽ:\n";
					long long n;
					cin>>n;
					if(n == 1)
					{
						cout<<"1 = [1]";
						continue;
					}
					FacRes r = PrimeFactorization(n);
					cout<<n<<" = ";
					if(r.index[0] == 1)	cout<<'['<<r.base[0]<<"]";
					else cout<<'['<<r.base[0]<<"]^"<<r.index[0];
					for(int i=1;i<r.num;i++)
					if(r.index[i] == 1) cout<<" * ["<<r.base[i]<<"]";
					else cout<<" * ["<<r.base[i]<<"]^"<<r.index[i];
					break;
				}
				
				}

			}


		catch(InputOutOfRange err) {
			err.message();
			continue;
		}

	} while(choice != 0);
	return 0;
}

// ����1�������б�
bool IsPrime(const long long & n) {
	if(n <= 0 || n > 9223372036854775807) throw InputOutOfRange();
	if(n == 1) return false;

	for(long long i=2; i<=sqrt(n); i++)
		if(n%i == 0) return false;
	return true;
}

// ����2��Eratoshenesɸ��
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

// ����3.շת��������������
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

// ����4.�����㷨ʵ��
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

// ����5.�������ֽ� 
FacRes PrimeFactorization(long long n)
{
	if(n <= 1) throw InputOutOfRange();
	
	EraRes er = Eratoshenes(int(sqrt(n)));
	FacRes fr;
	fr.base = new int[er.len+1];
	fr.index = new int[er.len+1];
	int k = 0;
	for(int i=0;i<er.len;i++)
	{
		if(n%er.res[i] == 0) 
		{
			fr.base[k] = er.res[i];
			fr.index[k] = 0;
			while(n%er.res[i] == 0)
			{
				fr.index[k]++;
				n /= er.res[i];
			}
			k++;
		}
	}
	if(n != 1) 
	{
		fr.base[k] = n;
		fr.index[k] = 1;
		k++;
	}
	fr.num = k;
	return fr;
}
