#include "Divisibility.h"


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
					cout<<"\n#7# ������������n������n���������ֽ�ʽ:";
					long long n;
					cin>>n;
					if(n == 1) {
						cout<<"1 = [1]";
						continue;
					}
					FacRes r = PrimeFactorization(n);
					cout<<n<<" = ";
					if(r.index[0] == 1)	cout<<'['<<r.base[0]<<"]";
					else cout<<'['<<r.base[0]<<"]^"<<r.index[0];
					for(int i=1; i<r.num; i++)
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
