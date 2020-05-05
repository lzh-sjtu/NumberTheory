#include "QuadCongruence.h"


int main() {
	cout<<"\n*************************************** 第四章：二次同余式与平方剩余 <程序实现> ****************************************\n"
	    <<"作者:lzh123@sjtu.edu.cn & 1084388051@qq.com\n"
	    <<"说明:\n"
	    <<"1.本程序中的正整数范围介于1-9223372036854775807之间；\n"
	    <<"2.本程序中的整数范围介于-9223372036854775808-9223372036854775807之间；\n"
	    <<"3.本程序默认使用最小非负余数。\n";
	int choice;
	do {
		cout<<"\n\n########################################### 请选择以下功能（选择0退出程序） ###########################################\n"
		    <<"1.Jacobi符号快速计算"
		    <<"\n请输入：";
		cin>>choice;

		try {
			switch(choice) {
				case 1: {
					cout<<"\n#1# 请输入整数a，奇整数m，计算(a/m):\n";
					long long a;
					long long m;
					cout<<"a:";
					cin>>a;
					cout<<"m:";
					cin>>m;
					cout<<"计算结果为："<<Jacobi(a,m)<<endl;
					break;
				}

			}

		}


		catch(InputOutOfRange err) {
			err.message();
			continue;
		}

		catch(NotOdd err) {
			err.message();
			continue;
		}

		catch(NotPrime err) {
			err.message();
			continue;
		}

	} while(choice != 0);
	return 0;
}
