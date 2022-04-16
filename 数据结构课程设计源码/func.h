#pragma once

#include"first.h"

//1.构建函数列表
void showInfo(void);		//输出所有景点
void Visiter(void);			//游客系统
void Administrator(void);	//管理员系统
void introduct(void);		//景点介绍
void Dijkstra(void);		//查找游客所在景点与其他景点的距离
void Floyd(void);			//查找游客指定的两个景点间的最短路径长度
void modifyInfo(void);		//修改景点信息
void addInfo(void);			//添加景点
void delInfo(void);			//删除景点 
void addPath(void);			//添加道路
void delPath(void);			//删除道路
void create(void);			//生成图


//输出所有顶点
void showInfo(void) {
	system("cls");	//清屏
	printf("JXNU景点列表:\n");
	for (int i = 0; i < JXNUmap.n; i++) {
		printf("%d ：%s\n", i + 1, JXNUmap.vers[i].name);
	}

	return;
}

void Visiter(void) {
	system("cls");	//清屏
	int choose = 0;

	while (True) {
		printf("来了老弟！欢迎来到江西师范大学JXNU\n");
		printf("功能菜单\n");
		printf("1.景点描述\n");
		printf("2.查询当前位置到其它位置的最短路径\n");
		printf("3.查询任意两个位置的最短路径\n");
		printf("4.离开系统\n");
		scanf_s("%d", &choose);
		system("cls");

		switch (choose) {
		case 1:
			printf("景点描述:\n");
			introduct();
			break;
		case 2:
			printf("迪杰斯特拉算法帮你瞅瞅最短路径\n");
			Dijkstra();
			break;
		case 3:
			printf("弗洛易得帮你看看任意两点的最短路径\n");
			Floyd();
			break;
		case 4:
			printf("这就 回到主界面了，老哥再见~n");
			return;
		default:
			printf("老哥您输错了吧，再来试试？\n");
			break;
		}
	}

	return;
}

void Administrator(void) {
	return;
}

//生成图
void create(void) {
	FILE* num, * edge, * vers;

	if (fopen_s(&num, "num.txt", "r") || fopen_s(&edge, "edge.txt", "r") || fopen_s(&vers, "vers.txt", "r") != 0) {
		printf("文件不存在！");
		return;
	}
	fscanf_s(num, "%d%d", &JXNUmap.n, &JXNUmap.e);

	//初始化每个景点的序号
	for (int i = 0; i < MaxVerNum; i++) {
		JXNUmap.vers[i].num = i + 1;
	}

	//将每条边初始化
	for (int i = 0; i < MaxVerNum; i++) {
		for (int j = 0; j < MaxVerNum; j++) {
			if (i == j)
				JXNUmap.edges[i][j] = 0;
			else
				JXNUmap.edges[i][j] = INFINITY;
		}
	}

	//读入每个景点的信息
	for (int i = 0; i < JXNUmap.n; i++) {
		int j;

		//读取顶点信息
		fscanf_s(vers, "%d", &j);
		fscanf_s(vers, "%s%s", JXNUmap.vers[j].name, MaxNameLength, JXNUmap.vers[j].features, MaxDescribeLength);
	}


	//读入网络中的边
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