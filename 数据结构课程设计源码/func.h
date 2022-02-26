#pragma once

#include"first.h"

//1.���������б�
void showInfo(void);		//������о���
void Visiter(void);			//�ο�ϵͳ
void Administrator(void);	//����Աϵͳ
void introduct(void);		//�������
void Dijkstra(void);		//�����ο����ھ�������������ľ���
void Floyd(void);			//�����ο�ָ�����������������·������
void modifyInfo(void);		//�޸ľ�����Ϣ
void addInfo(void);			//��Ӿ���
void delInfo(void);			//ɾ������ 
void addPath(void);			//��ӵ�·
void delPath(void);			//ɾ����·
void create(void);			//����ͼ


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
	return;
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