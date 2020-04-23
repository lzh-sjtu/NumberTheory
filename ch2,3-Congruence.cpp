#include "Congruence.h"


int main() {
	cout<<"\n***************************************** �ڶ������£�ͬ��������� <����ʵ��> ******************************************\n"
	    <<"����:lzh123@sjtu.edu.cn & 1084388051@qq.com\n"
	    <<"˵��:\n"
	    <<"1.�������е���������Χ����1-9223372036854775807֮�䣻\n"
	    <<"2.�������е�������Χ����-9223372036854775808-9223372036854775807֮�䣻\n"
	    <<"3.������Ĭ��ʹ����С�Ǹ�������\n";
	int choice;
	do {
		cout<<"\n\n########################################### ��ѡ�����¹��ܣ�ѡ��0�˳����� ###########################################\n"
		    <<"1.ͬ���ж�   2.ŷ����������   3.һ��ͬ��ʽ���   4.һ��ͬ��ʽ�����   5.����ʽŷ����ó���   6.ģͬ����ټ���"
		    <<"\n�����룺";
		cin>>choice;

		try {
			switch(choice) {
				case 1: {
					cout<<"\n#1# ����������a��b��m���ж�a��b�Ƿ�ģmͬ��:\n";
					long long a;
					long long b;
					long long m;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					cout<<"m:";
					cin>>m;
					if(IsCongruent(a,b,m)) {
						cout<<a<<" �� "<<b<<" ģ "<<m<<" ͬ��";
					} else {
						cout<<a<<" �� "<<b<<" ģ "<<m<<" ��ͬ��";
					}
					cout<<endl;
					break;
				}

				case 2: {
					cout<<"\n#2# ������������n������n��ŷ������ֵ:";
					long long n;
					cin>>n;
					cout<<"Euler(n) = "<<EulerFunction(n);
					cout<<endl;
					break;
				}

				case 3: {
					cout<<"\n#3# ������������a��b��m������ͬ��ʽax=b(mod m)�Ľ�:\n";
					long long a,b,m;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					cout<<"m:";
					cin>>m;
					LinearRes lr = LinearCongruence(a,b,m);
					if(!lr.res) cout<<"ͬ��ʽ�޽�";
					else {
						cout<<"ͬ��ʽ�Ľ�Ϊ:\nx = ";
						cout<<lr.res[0];
						for(int i=1; i<lr.len; i++)
							cout<<", "<<lr.res[i];
						cout<<" (mod "<<m<<")";
					}
					cout<<endl;
					break;
				}

				case 4: {
					cout<<"\n#4# �й�ʣ�ඨ�����ͬ��ʽ�飬������ͬ��ʽ����N:";
					int N;
					cin>>N;
					long long *m = new long long[N];
					long long *b = NULL;
					cout<<"�Ƿ�����ϵ��b��[y or n]:";
					char sign;
					cin>>sign;
					if(sign != 'y' && sign != 'n')  break;
					else {
						if(sign == 'y') {
							b = new long long[N];
							long long m_prod = 1;
							for(int i=0; i<N; i++) {
								cout<<"����b"<<i+1<<"��m"<<i+1<<':';
								cin>>b[i]>>m[i];
								m_prod *= m[i];
							}
							cout<<"ͬ��ʽ���Ϊ:\nx = "<<ChineseRemainder(N,b,m)<<" (mod "<<m_prod<<')';
						} else {
							long long m_prod = 1;
							for(int i=0; i<N; i++) {
								cout<<"����m"<<i+1<<':';
								cin>>m[i];
								m_prod *= m[i];
							}
							cout<<"ͬ��ʽ���Ϊ:";
							ChineseRemainder(N,b,m);
						}
						cout<<endl;
					}
					break;
				}

				case 5: {
					cout<<"\n#5# ����ʽŷ����ó���:f=q*g+r\n";
					long long m,n;
					cout<<"������f����ߴ���:";
					cin>>m;
					cout<<"������g����ߴ���:";
					cin>>n;
					poly f(NULL,m);
					poly g(NULL,n);
					f.coef = new long long[m+1];
					g.coef = new long long[n+1];
					cout<<"������f�ĸ���ϵ��:\n";
					for(int i=m; i>=0; i--) {
						cout<<i<<"��ϵ��:";
						cin>>f.coef[i];
					}
					cout<<"������g�ĸ���ϵ��:\n";
					for(int i=n; i>=0; i--) {
						cout<<i<<"��ϵ��:";
						cin>>g.coef[i];
					}
					PolyRes pr = PolyEuclidean(f,g);
					cout<<"q = \n";
					cout<<pr.q.coef[pr.q.n]<<"x^"<<pr.q.n;
					for(int i=pr.q.n-1; i>=0; --i) {
						if(pr.q.coef[i] == 0)  continue;
						if(pr.q.coef[i] < 0)
							cout<<" - "<<-pr.q.coef[i]<<"x^"<<i;
						else
							cout<<" + "<<pr.q.coef[i]<<"x^"<<i;
					}
					cout<<endl;
					cout<<"r = \n";
					cout<<pr.r.coef[pr.r.n]<<"x^"<<pr.r.n;
					for(int i=pr.r.n-1; i>=0; --i) {
						if(pr.r.coef[i] == 0)  continue;
						if(pr.r.coef[i] < 0)
							cout<<" - "<<-pr.r.coef[i]<<"x^"<<i;
						else
							cout<<" + "<<pr.r.coef[i]<<"x^"<<i;
					}
					cout<<endl;
					break;
				}

				case 6: {
					cout<<"\n#6# ����b^n(mod m):\n";
					long long b,n,m;
					cout<<"������b:";
					cin>>b;
					cout<<"������n:";
					cin>>n;
					cout<<"������m:";
					cin>>m;
					cout<<"������Ϊ:\n";
					cout<<CongruenceComputation(b,n,m)<<" (mod "<<m<<')';
					cout<<endl;
					break;
				}


			}

		}


		catch(InputOutOfRange err) {
			err.message();
			continue;
		}

		catch(NotMutualPrime err) {
			err.message();
			continue;
		}

	} while(choice != 0);
	return 0;
}
