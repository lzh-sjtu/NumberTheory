#include "Divisibility.h"


int main() {
	cout<<"\n******************************************* 第一章：整数的可除性 <程序实现> *******************************************\n"
	    <<"作者:lzh123@sjtu.edu.cn & 1084388051@qq.com\n"
	    <<"说明:\n"
	    <<"1.本程序中的正整数范围介于1-9223372036854775807之间；\n"
	    <<"2.本程序中的整数范围介于-9223372036854775808-9223372036854775807之间；\n"
	    <<"3.本程序默认使用最小非负余数。\n";
	int choice;
	do {
		cout<<"\n\n########################################### 请选择以下功能（选择0退出程序） ###########################################\n"
		    <<"1.素数判定     2.Eratoshenes素数筛选     3.Euclidean除法     4.两个整数的最大公因数和最小公倍数\n5.互素判定     6.贝祖算法实现            7.素因数分解"
		    <<"\n请输入：";
		cin>>choice;

		try {
			switch(choice) {
				case 1: {
					cout<<"\n#1# 请输入一个正整数n，判定n是否为素数:";
					long long n;
					cin>>n;
					if(IsPrime(n)) {
						cout<<n<<"为素数";
					} else {
						cout<<n<<"不为素数";
					}
					cout<<endl;
					break;
				}

				case 2: {
					cout<<"\n#2# 请输入一个正整数n，计算小于等于n的所有素数:";
					long long m;
					cin>>m;
					EraRes r = Eratoshenes(m);
					if(!r.res) {
						cout<<"无素数";
						continue;
					}
					cout<<"总共有"<<r.len<<"个素数:\n";
					for(long long i=0; i<r.len; i++) {
						if(i%5 == 0) cout<<endl;
						cout<<*(r.res+i)<<"\t";
					}
					break;
				}

				case 3: {
					cout<<"\n#3# 请输入整数a，正整数b，计算q、r使得a=q*b+r:\n";
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
						cout<<'['<<a<<"] 能被 ["<<b<<"] 整除"<<endl;
						if(a < 0) q++;
						cout<<'['<<a<<']'<<" = "<<q<<" * ["<<b<<']'<<endl;
					} else {
						cout<<'['<<a<<"] 不能被 ["<<b<<"] 整除"<<endl;
						cout<<'['<<a<<']'<<" = "<<q<<" * ["<<b<<"] + "<<r<<endl;
					}
					break;
				}

				case 4: {
					cout<<"\n#4# 请输入整数a、b，利用辗转相除法计算gcd(a,b)和LCM[a,b]:\n";
					long long a,b,g;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					g = gcd(a,b);
					cout<<"最大公因数: ("<<a<<','<<b<<") 为 "<<g<<endl;
					cout<<"最小公倍数: ["<<a<<','<<b<<"] 为 "<<abs(a*b/g)<<endl;
					break;
				}

				case 5: {
					cout<<"\n#5# 请输入整数a、b，判断两者是否互素:\n";
					long long a,b;
					cout<<"a:";
					cin>>a;
					cout<<"b:";
					cin>>b;
					if(gcd(a,b) == 1) cout<<a<<"与"<<b<<"互素"<<endl;
					else cout<<a<<"与"<<b<<"不互素"<<endl;
					break;
				}

				case 6: {
					cout<<"\n#6# 请输入正整数a、b，求得整数s、t使得(a,b) = sa+tb:\n";
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
					cout<<"\n#7# 请输入正整数n，计算n的素因数分解式:";
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
