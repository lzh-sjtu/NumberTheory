#include "QuadCongruence.h"


int main() {
	cout<<"\n*************************************** �����£�����ͬ��ʽ��ƽ��ʣ�� <����ʵ��> ****************************************\n"
	    <<"����:lzh123@sjtu.edu.cn & 1084388051@qq.com\n"
	    <<"˵��:\n"
	    <<"1.�������е���������Χ����1-9223372036854775807֮�䣻\n"
	    <<"2.�������е�������Χ����-9223372036854775808-9223372036854775807֮�䣻\n"
	    <<"3.������Ĭ��ʹ����С�Ǹ�������\n";
	int choice;
	do {
		cout<<"\n\n########################################### ��ѡ�����¹��ܣ�ѡ��0�˳����� ###########################################\n"
		    <<"1.Jacobi���ſ��ټ���"
		    <<"\n�����룺";
		cin>>choice;

		try {
			switch(choice) {
				case 1: {
					cout<<"\n#1# ����������a��������m������(a/m):\n";
					long long a;
					long long m;
					cout<<"a:";
					cin>>a;
					cout<<"m:";
					cin>>m;
					cout<<"������Ϊ��"<<Jacobi(a,m)<<endl;
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
