#include"first.h"
#include"func.h"

int main(void) {
	/*create();
	printf("Weclome to the JXNU\n");
	printf("欢迎使用JXNUGuide\n");
	printf("请选择您使用的角色\n");
	printf("游客请按1\n");
	printf("管理员请按2\n");
	printf("其他选择将退出系统\n");*/

	int choose;
	scanf_s("%d", &choose);

	switch (choose) {
	case 1:
		Visiter();	//转到游客界面
		break;
	case 2:
		printf("请输入管理员密码：");
		char password[PASSWORDLENGTH] = {0};
		scanf_s("%s", password, PASSWORDLENGTH);

		if (strcmp(password, PASSWORD) == False) {
			printf("密码正确，即将进入系统\n");
			Administrator();	//转入管理员界面
		}
		else {
			system("cls");
			printf("----------密码错误---------\n");
			printf("系统将在1S后返回主页面");
			Sleep(1000);
			system("cls");
		}
		break;
	default:
		printf("即将在1s后退出系统，感谢您的使用。");
		Sleep(1000);
	}

	return 0;
}