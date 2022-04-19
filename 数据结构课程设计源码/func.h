#pragma once

#include"first.h"
#include"heap.h"

//1.构建函数列表
void showInfo(void);					//输出所有景点
void Visiter(void);						//游客系统
void Administrator(void);				//管理员系统
void introduct(void);					//景点介绍
void DijkstraHeap(void);				//查找游客所在景点与其他景点的距离（堆优化的迪杰斯特拉算法）
void Floyd(void);						//查找游客指定的两个景点间的最短路径长度
void modifyInfo(void);					//修改景点信息
void addInfo(void);						//添加景点
void delInfo(void);						//删除景点 
void addPath(void);						//添加道路
void delPath(void);						//删除道路
void create(void);						//生成图
void printPath(int[], int, int);		//输出路线信息			


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
			DijkstraHeap();
			break;
		case 3:
			printf("弗洛伊德帮你看看任意两点的最短路径\n");
			Floyd();
			break;
		case 4:
			printf("这就 回到主界面了，老哥再见~\n");
			return;
		default:
			printf("老哥您输错了吧，再来试试？\n");
			break;
		}
	}

	return;
}

void introduct(void) {
	if (JXNUmap.n <= 0) {
		printf("这是个假学校，没有任何景点\n");
		return;
	}

	showInfo();
	printf("你要看那个景点的介绍呢？请说号：");
	int num;
	scanf_s("%d", &num);
	system("cls");

	while (num < 1 || num > JXNUmap.n) {
		printf("这都输错了1到%d之间，重新输！\n", JXNUmap.n);
		scanf_s("%d", &num);
	}

	printf("%s:%s\n", JXNUmap.vers[num - 1].name, JXNUmap.vers[num - 1].features);
	Sleep(1000);
	printf("即将1S后返回主界面\n");
	Sleep(1000);
	return;
}

void DijkstraHeap(void) {
	if (JXNUmap.n <= 0) {
		printf("地图中无任何景点，请先添加景点！\n");
		return;
	}

	showInfo();
	printf("请输入您所在的景点编号:");
	int num;
	scanf_s("%d", &num);

	while (num < 1 || num > JXNUmap.n) {
		printf("编号输入有误，编号应位于1～%d之间，重新输入！\n", JXNUmap.n);
		scanf_s("%d", &num);
	}
	num--;

	//初始化dis
	for (int i = 0; i < MaxVerNum; i++) {
		dis[i] = INFINITY;
	}

	dot t;
	t.num = num;
	t.val = 0;
	push(t);	//入堆

	dis[num] = 0;

	while (len) {
		dot top = pop();	//弹出堆顶元素（因为是小根堆，堆顶元素值肯定为最小的）

		if (vis[top.num]) {	//由于一个点的最短距离会多次改变，
			continue;		//所以堆中可能有多个重复系欸但，但每次取出的都是最小的，所以被取出一次后							
		}					//后面的重复节点都可以忽略
		vis[top.num] = 1;

		for (int i = 0; i < JXNUmap.n; i++) {
			if (JXNUmap.edges[top.num][i] && !vis[i] && dis[i] > JXNUmap.edges[top.num][i] + top.val) {
				dot t;
				t.num = i;
				t.val = JXNUmap.edges[top.num][i] + top.val;
				push(t);

				//修改距离
				dis[i] = JXNUmap.edges[top.num][i] + top.val;
				//记录前一个节点
				pre[i] = top.num;
			}
		}
	}

	//输出路线和距离
	for (int i = 0; i < JXNUmap.n; i++) {
		if (i != num) {
			printf("你现在在%s，到%s的距离是%dm\n", JXNUmap.vers[num].name, JXNUmap.vers[i].name, dis[i]);
			printf("路线是：");
			printPath(pre, i, num);
			printf("\b\b     \n\n");
			Sleep(1000);
		}
	}

	//重置vis，pre
	for (int i = 0; i < MaxVerNum; i++) {
		vis[i] = 0;
		pre[i] = 0;
	}

	system("pause");
	system("cls");

	return;
}

void printPath(int pre[], int i, int num) {
	//使用递归的方法输出路线！
	if (i == num) {
		printf("%s->", JXNUmap.vers[num].name);
		return;
	}
	printPath(pre, pre[i], num);
	printf("%s->", JXNUmap.vers[i].name);

	return;
}

void Floyd(void) {
	if (JXNUmap.n <= 0) {
		printf("地图中无任何景点，请先添加景点！\n");
		return;
	}

	showInfo();
	int path[MaxVerNum][MaxVerNum];
	int dist[MaxVerNum][MaxVerNum];
	int i, j, k;
	int temp;

	for (i = 0; i < JXNUmap.n; i++)
		for (j = 0; j < JXNUmap.n; j++) {
			dist[i][j] = JXNUmap.edges[i][j];
			path[i][j] = j;
		}
	for (k = 0; k < JXNUmap.n; k++)
		for (i = 0; i < JXNUmap.n; i++)
			for (j = 0; j < JXNUmap.n; j++) {
				//temp = (dist[i][k] == INFINITY || dist[k][j] == INFINITY) ? INFINITY : (dist[i][k] + dist[k][j]);
				temp = dist[i][k] + dist[k][j];
				if (dist[i][j] > temp) {
					dist[i][j] = temp;
					path[i][j] = k;
				}
			}
	int a, b;
	printf("请输入您要查询之间距离的两个景点编号，中间用空格隔开：\n");
	scanf_s("%d %d", &b, &a);
	while (a < 1 || a > JXNUmap.n || b < 1 || b > JXNUmap.n || a == b) {
		if (a == b)
			printf("请勿输入两个相同编号，重新输入！\n");
		else
			printf("编号输入有误，两个编号都应位于1～%d之间，重新输入！\n", JXNUmap.n);
		scanf_s("%d %d", &b, &a);
	}
	if (dist[a - 1][b - 1] == INFINITY) {
		printf("%s与%s之间无路径！\n", JXNUmap.vers[b - 1].name, JXNUmap.vers[a - 1].name);
		return;
	}
	else {
		printf("%s到%s的最短路径长度为：%d米\n", JXNUmap.vers[b - 1].name, JXNUmap.vers[a - 1].name, dist[a - 1][b - 1]);
		printf("路径为：");
		int pre[MaxVerNum];
		for (int i = 0; i < JXNUmap.n; i++) {
			pre[i] = path[i][b - 1];
		}
		printPath(pre, a - 1, b - 1);
		printf("\b\b  \n");

		Sleep(1000);
	}
	system("pause");
	printf("系统将在1S后回到主面板");
	Sleep(1000);
	system("cls");

	return;
}

void Administrator(void) {
	system("cls");
	while (True) {
		int choose;
		printf("只有管理员才能看到的管理系统\n");
		printf("1.景点介绍\n");
		printf("2.查找您所在的景点到其他景点的最短路径\n");
		printf("3.查找任意两个景点之间的最短路径\n");
		printf("4.修改景点信息\n");
		printf("5.增加景点信息\n");
		printf("6.删除景点信息\n");
		printf("7.增加道路\n");
		printf("8.删除道路\n");
		printf("9.退出管理系统\n");

		scanf_s("%d", &choose);
		switch (choose) {
		case 1:
			system("cls");
			printf("来我给您讲讲：\n");
			introduct();
			break;
		case 2:
			system("cls");
			printf("迪杰斯特拉算法\n");
			DijkstraHeap();
			break;
		case 3:
			system("cls");
			printf("弗洛伊德算法\n");
			Floyd();
			break;
		case 4:
			system("cls");
			printf("哪错了？给你改：\n");
			modifyInfo();
			break;
		case 5:
			system("cls");
			printf("再多写两句介绍\n");
			addInfo();
			break;
		case 6:
			system("cls");
			printf("写错了，删了吧\n");
			delInfo();
			break;
		case 7:
			system("cls");
			printf("师大又修路了\n");
			addPath();
			break;
		case 8:
			system("cls");
			printf("又修路不让走了？\n");
			delPath();
			break;
		case 9:
			system("cls");
			printf("再见~~~\n");
			return;
		default:
			system("cls");
			printf("老哥输错了，要不您再试试？\n");
			break;
		}
	}

	return;
}

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

void modifyInfo(void) {
	return;
}

void addInfo(void) {
	return;
}

void delInfo(void) {
	return;
}

void addPath(void) {
	return;
}

void delPath(void) {
	return;
}
