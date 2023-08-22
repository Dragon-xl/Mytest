#include <iostream>
#include"ClientFuc.h"
using namespace std;
int interface()
{
	int select = -1;
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n  /*     1.密钥协商                                            */");
	printf("\n  /*     2.密钥校验                                            */");
	printf("\n  /*     3.密钥注销                                            */");
	printf("\n  /*     4.密钥查看                                            */");
	printf("\n  /*     0.退出                                                */");
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n\n  选择:");
	scanf("%d", &select);
	while (getchar() != '\n');

	return select;
	
}
int main()

{
	
	
	ClientFuc fun("client.json");
	
	while (1)
	{
		int ch = interface();

		switch (ch)
		{
		case 1:
			fun.KeyAgreement();
			break;
		default:
			break;
		}
	}
	
    
    return 0;
}