#include <iostream>
#include"ClientFuc.h"
using namespace std;
int interface()
{
	int select = -1;
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n  /*     1.��ԿЭ��                                            */");
	printf("\n  /*     2.��ԿУ��                                            */");
	printf("\n  /*     3.��Կע��                                            */");
	printf("\n  /*     4.��Կ�鿴                                            */");
	printf("\n  /*     0.�˳�                                                */");
	printf("\n  /*************************************************************/");
	printf("\n  /*************************************************************/");
	printf("\n\n  ѡ��:");
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