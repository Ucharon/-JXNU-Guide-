#pragma once

#include"first.h"
#include"heap.h"

//1.���������б�
void showInfo(void);					//������о���
void Visiter(void);						//�ο�ϵͳ
void Administrator(void);				//����Աϵͳ
void introduct(void);					//�������
void DijkstraHeap(void);					//�����ο����ھ�������������ľ��루���Ż��ĵϽ�˹�����㷨��
void Floyd(void);						//�����ο�ָ�����������������·������
void modifyInfo(void);					//�޸ľ�����Ϣ
void addInfo(void);						//��Ӿ���
void delInfo(void);						//ɾ������ 
void addPath(void);						//��ӵ�·
void delPath(void);						//ɾ����·
void create(void);						//����ͼ
void printPath(int[], int, int);		//���·����Ϣ			


//������ж���
void showInfo(void) {
	system("cls");	//����
	printf("JXNU�����б�:\n");
	for (int i = 0; i < JXNUmap.n; i++) {
		printf("%d ��%s\n", i + 1, JXNUmap.vers[i].name);
	}

	return;
}

void Visiter(void) {
	system("cls");	//����
	int choose = 0;

	while (True) {
		printf("�����ϵܣ���ӭ��������ʦ����ѧJXNU\n");
		printf("���ܲ˵�\n");
		printf("1.��������\n");
		printf("2.��ѯ��ǰλ�õ�����λ�õ����·��\n");
		printf("3.��ѯ��������λ�õ����·��\n");
		printf("4.�뿪ϵͳ\n");
		scanf_s("%d", &choose);
		system("cls");

		switch (choose) {
		case 1:
			printf("��������:\n");
			introduct();
			break;
		case 2:
			printf("�Ͻ�˹�����㷨���������·��\n");
			DijkstraHeap();
			break;
		case 3:
			printf("�������°��㿴��������������·��\n");
			Floyd();
			break;
		case 4:
			printf("��� �ص��������ˣ��ϸ��ټ�~�\n");
			return;
		default:
			printf("�ϸ�������˰ɣ��������ԣ�\n");
			break;
		}
	}

	return;
}

void introduct(void) {
	if (JXNUmap.n <= 0) {
		printf("���Ǹ���ѧУ��û���κξ���\n");
		return;
	}

	showInfo();
	printf("��Ҫ���Ǹ�����Ľ����أ���˵�ţ�");
	int num;
	scanf_s("%d", &num);
	system("cls");

	while (num < 1 || num > JXNUmap.n) {
		printf("�ⶼ�����1��%d֮�䣬�����䣡\n", JXNUmap.n);
		scanf_s("%d", &num);
	}

	printf("%s:%s\n", JXNUmap.vers[num - 1].name, JXNUmap.vers[num - 1].features);
	Sleep(1000);
	printf("����1S�󷵻�������\n");
	Sleep(1000);
	return;
}

void DijkstraHeap(void) {
	if (JXNUmap.n <= 0) {
		printf("��ͼ�����κξ��㣬������Ӿ��㣡\n");
		return;
	}

	showInfo();
	printf("�����������ڵľ�����:");
	int num;
	scanf_s("%d", &num);

	while (num < 1 || num > JXNUmap.n) {
		printf("����������󣬱��Ӧλ��1��%d֮�䣬�������룡\n", JXNUmap.n);
		scanf_s("%d", &num);
	}
	num--;

	//��ʼ��dis
	for (int i = 0; i < MaxVerNum; i++) {
		dis[i] = INFINITY;
	}

	dot t;
	t.num = num;
	t.val = 0;
	push(t);	//���

	dis[num] = 0;

	while (len) {
		dot top = pop();	//�����Ѷ�Ԫ�أ���Ϊ��С���ѣ��Ѷ�Ԫ��ֵ�϶�Ϊ��С�ģ�

		if (vis[top.num]) {	//����һ�������̾�����θı䣬
			continue;		//���Զ��п����ж���ظ�ϵ�G������ÿ��ȡ���Ķ�����С�ģ����Ա�ȡ��һ�κ�							
		}					//������ظ��ڵ㶼���Ժ���
		vis[top.num] = 1;

		for (int i = 0; i < JXNUmap.n; i++) {
			if (JXNUmap.edges[top.num][i] && !vis[i] && dis[i] > JXNUmap.edges[top.num][i] + top.val) {
				dot t;
				t.num = i;
				t.val = JXNUmap.edges[top.num][i] + top.val;
				push(t);

				//�޸ľ���
				dis[i] = JXNUmap.edges[top.num][i] + top.val;
				//��¼ǰһ���ڵ�
				pre[i] = top.num;
			}
		}
	}

	//���·�ߺ;���
	for (int i = 0; i < JXNUmap.n; i++) {
		if (i != num) {
			printf("��������%s����%s�ľ�����%dm\n",JXNUmap.vers[num].name, JXNUmap.vers[i].name, dis[i]);
			printf("·���ǣ�");
			printPath(pre, i, num);
			printf("\b\b     \n\n");
			Sleep(1000);
		}
	}

	//����vis��pre
	for (int i = 0; i < MaxVerNum; i++) {
		vis[i] = 0;
		pre[i] = 0;
	}

	system("pause");
	system("cls");

	return;
}

void printPath(int pre[], int i, int num) {
	//ʹ�õݹ�ķ������·�ߣ�
	if (i == num) {
		printf("%s->", JXNUmap.vers[num].name);
		return;
	}
	printPath(pre, pre[i], num);
	printf("%s->", JXNUmap.vers[i].name);
	
	return;
}

void Floyd(void) {

}

void Administrator(void) {
	return;
}

//����ͼ
void create(void) {
	FILE* num, * edge, * vers;

	if (fopen_s(&num, "num.txt", "r") || fopen_s(&edge, "edge.txt", "r") || fopen_s(&vers, "vers.txt", "r") != 0) {
		printf("�ļ������ڣ�");
		return;
	}
	fscanf_s(num, "%d%d", &JXNUmap.n, &JXNUmap.e);

	//��ʼ��ÿ����������
	for (int i = 0; i < MaxVerNum; i++) {
		JXNUmap.vers[i].num = i + 1;
	}

	//��ÿ���߳�ʼ��
	for (int i = 0; i < MaxVerNum; i++) {
		for (int j = 0; j < MaxVerNum; j++) {
			if (i == j)
				JXNUmap.edges[i][j] = 0;
			else
				JXNUmap.edges[i][j] = INFINITY;
		}
	}

	//����ÿ���������Ϣ
	for (int i = 0; i < JXNUmap.n; i++) {
		int j;

		//��ȡ������Ϣ
		fscanf_s(vers, "%d", &j);
		fscanf_s(vers, "%s%s", JXNUmap.vers[j].name, MaxNameLength, JXNUmap.vers[j].features, MaxDescribeLength);
	}


	//���������еı�
	for (int i = 0; i < JXNUmap.e; i++) {
		int a, b, c;
		fscanf_s(edge, "%d%d%d", &a, &b, &c);
		JXNUmap.edges[a][b] = JXNUmap.edges[b][a] = c;
	}
	fclose(num);
	fclose(edge);
	fclose(vers);

	return;
}