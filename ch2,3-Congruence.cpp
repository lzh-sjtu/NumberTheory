#include "Congruence.h"


int main() {
	cout<<"\n***************************************** 第二、三章：同余基础理论 <程序实现> ******************************************\n"
	    <<"作者:lzh123@sjtu.edu.cn & 1084388051@qq.com\n"
	    <<"说明:\n"
	    <<"1.本程序中的正整数范围介于1-9223372036854775807之间；\n"
	    <<"2.本程序中的整数范围介于-9223372036854775808-9223372036854775807之间；\n"
	    <<"3.本程序默认使用最小非负余数。\n";
	int choice;
	do {
		cout<<"\n\n########################################### 请选择以下功能（选择0退出程序） ###########################################\n"
		    <<"1.同余判定   2.欧拉函数计算   3.一次同余式求解   4.一次同余式组求解   5.多项式欧几里得除法   6.模同余快速计算"
		    <<"\n请输入：";
		cin>>choice;

		try {
			switch(choice) {
				case 1: {
					cout<<"\n#1# 请输入整数a，b，m，判定a和b是否模m同余:\n";
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
						cout<<a<<" 和 "<<b<<" 模 "<<m<<" 同余";
					} else {
						cout<<a<<" 和 "<<b<<" 模 "<<m<<" 不同余";
					}
					cout<<endl;
					break;
				}

				case 2: {
					cout<<"\n#2# 请输入正整数n，计算n的欧拉函数值:";
					long long n;
					cin>>n;
					cout<<"Euler(n) = "<<EulerFunction(n);
					cout<<endl;
					break;
				}

				case 3: {
					cout<<"\n#3# 请输入正整数a，b，m，计算同余式ax=b(mod m)的解:\n";
					long long a,b,m;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					cout<<"m:";
					cin>>m;
					LinearRes lr = LinearCongruence(a,b,m);
					if(!lr.res) cout<<"同余式无解";
					else {
						cout<<"同余式的解为:\nx = ";
						cout<<lr.res[0];
						for(int i=1; i<lr.len; i++)
							cout<<", "<<lr.res[i];
						cout<<" (mod "<<m<<")";
					}
					cout<<endl;
					break;
				}

				case 4: {
					cout<<"\n#4# 中国剩余定理求解同余式组，请输入同余式个数N:";
					int N;
					cin>>N;
					long long *m = new long long[N];
					long long *b = NULL;
					cout<<"是否输入系数b？[y or n]:";
					char sign;
					cin>>sign;
					if(sign != 'y' && sign != 'n')  break;
					else {
						if(sign == 'y') {
							b = new long long[N];
							long long m_prod = 1;
							for(int i=0; i<N; i++) {
								cout<<"输入b"<<i+1<<"和m"<<i+1<<':';
								cin>>b[i]>>m[i];
								m_prod *= m[i];
							}
							cout<<"同余式组解为:\nx = "<<ChineseRemainder(N,b,m)<<" (mod "<<m_prod<<')';
						} else {
							long long m_prod = 1;
							for(int i=0; i<N; i++) {
								cout<<"输入m"<<i+1<<':';
								cin>>m[i];
								m_prod *= m[i];
							}
							cout<<"同余式组解为:";
							ChineseRemainder(N,b,m);
						}
						cout<<endl;
					}
					break;
				}

				case 5: {
					cout<<"\n#5# 多项式欧几里得除法:f=q*g+r\n";
					long long m,n;
					cout<<"请输入f的最高次数:";
					cin>>m;
					cout<<"请输入g的最高次数:";
					cin>>n;
					poly f(NULL,m);
					poly g(NULL,n);
					f.coef = new long long[m+1];
					g.coef = new long long[n+1];
					cout<<"请输入f的各次系数:\n";
					for(int i=m; i>=0; i--) {
						cout<<i<<"次系数:";
						cin>>f.coef[i];
					}
					cout<<"请输入g的各次系数:\n";
					for(int i=n; i>=0; i--) {
						cout<<i<<"次系数:";
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
					cout<<"\n#6# 计算b^n(mod m):\n";
					long long b,n,m;
					cout<<"请输入b:";
					cin>>b;
					cout<<"请输入n:";
					cin>>n;
					cout<<"请输入m:";
					cin>>m;
					cout<<"计算结果为:\n";
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
