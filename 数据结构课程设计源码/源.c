#include"first.h"
#include"func.h"

int main(void) {
	/*create();
	printf("Weclome to the JXNU\n");
	printf("��ӭʹ��JXNUGuide\n");
	printf("��ѡ����ʹ�õĽ�ɫ\n");
	printf("�ο��밴1\n");
	printf("����Ա�밴2\n");
	printf("����ѡ���˳�ϵͳ\n");*/

	int choose;
	scanf_s("%d", &choose);

	switch (choose) {
	case 1:
		Visiter();	//ת���οͽ���
		break;
	case 2:
		printf("���������Ա���룺");
		char password[PASSWORDLENGTH] = {0};
		scanf_s("%s", password, PASSWORDLENGTH);

		if (strcmp(password, PASSWORD) == False) {
			printf("������ȷ����������ϵͳ\n");
			Administrator();	//ת�����Ա����
		}
		else {
			system("cls");
			printf("----------�������---------\n");
			printf("ϵͳ����1S�󷵻���ҳ��");
			Sleep(1000);
			system("cls");
		}
		break;
	default:
		printf("������1s���˳�ϵͳ����л����ʹ�á�");
		Sleep(1000);
	}

	return 0;
}