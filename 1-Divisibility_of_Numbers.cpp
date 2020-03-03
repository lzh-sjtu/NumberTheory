#include<iostream>
#include<cmath>
using namespace std;

struct Res {
	long long *res;
	long long len;
	Res(long long *r,long long l):res(r),len(l) {}
};

bool IsPrime(const long long &);
Res Eratoshenes(const long long &);
long long gcd(long long,long long);

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
		    <<"1.�����ж�     2.Eratoshenes����ɸѡ     3.Euclidean����     4.���������������������С������     5.�����ж�"
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
					Res r = Eratoshenes(m);
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
Res Eratoshenes(const long long & n) {
	if(n <= 0 || n > 9223372036854775807) throw InputOutOfRange();
	if(n == 1) return Res(NULL,0);

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

	return Res(res,num);
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
