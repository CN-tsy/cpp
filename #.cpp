#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<windows.h>
using namespace std;
void cdpwn(char a[3][3]) {
    Sleep(900);
    // 初始化随机种子（建议在main函数中调用一次即可）
    static bool seeded = false;
    if (!seeded) {
        srand(time(NULL));
        seeded = true;
    }

    // 1. 检查计算机能否立即获胜
    // 检查所有行、列和对角线
    for (int i = 0; i < 3; i++) {
        // 检查行
        int c_count = 0, empty_col = -1;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 'C') c_count++;
            else if (a[i][j] == '+') empty_col = j;
        }
        if (c_count == 2 && empty_col != -1) {
            a[i][empty_col] = 'C';
            return;
        }

        // 检查列
        c_count = 0;
        int empty_row = -1;
        for (int j = 0; j < 3; j++) {
            if (a[j][i] == 'C') c_count++;
            else if (a[j][i] == '+') empty_row = j;
        }
        if (c_count == 2 && empty_row != -1) {
            a[empty_row][i] = 'C';
            return;
        }
    }

    // 检查对角线
    int c_count = 0, empty_index = -1;
    for (int i = 0; i < 3; i++) { // 主对角线
        if (a[i][i] == 'C') c_count++;
        else if (a[i][i] == '+') empty_index = i;
    }
    if (c_count == 2 && empty_index != -1) {
        a[empty_index][empty_index] = 'C';
        return;
    }

    c_count = 0; empty_index = -1;
    for (int i = 0; i < 3; i++) { // 副对角线
        int j = 2 - i;
        if (a[i][j] == 'C') c_count++;
        else if (a[i][j] == '+') empty_index = i;
    }
    if (c_count == 2 && empty_index != -1) {
        a[empty_index][2 - empty_index] = 'C';
        return;
    }

    // 2. 阻止玩家获胜（假设玩家使用'P'，按需修改）
    for (int i = 0; i < 3; i++) {
        // 检查行
        int p_count = 0, empty_col = -1;
        for (int j = 0; j < 3; j++) {
            if (a[i][j] == 'P') p_count++;
            else if (a[i][j] == '+') empty_col = j;
        }
        if (p_count == 2 && empty_col != -1) {
            a[i][empty_col] = 'C';
            return;
        }

        // 检查列
        p_count = 0;
        int empty_row = -1;
        for (int j = 0; j < 3; j++) {
            if (a[j][i] == 'P') p_count++;
            else if (a[j][i] == '+') empty_row = j;
        }
        if (p_count == 2 && empty_row != -1) {
            a[empty_row][i] = 'C';
            return;
        }
    }

    // 检查对角线
    int p_count = 0; empty_index = -1;
    for (int i = 0; i < 3; i++) { // 主对角线
        if (a[i][i] == 'P') p_count++;
        else if (a[i][i] == '+') empty_index = i;
    }
    if (p_count == 2 && empty_index != -1) {
        a[empty_index][empty_index] = 'C';
        return;
    }

    p_count = 0; empty_index = -1;
    for (int i = 0; i < 3; i++) { // 副对角线
        int j = 2 - i;
        if (a[i][j] == 'P') p_count++;
        else if (a[i][j] == '+') empty_index = i;
    }
    if (p_count == 2 && empty_index != -1) {
        a[empty_index][2 - empty_index] = 'C';
        return;
    }

    // 3. 优先占中心
    if (a[1][1] == '+') {
        a[1][1] = 'C';
        return;
    }

    // 4. 随机选择空角落
    int corners[4][2] = {{0,0}, {0,2}, {2,0}, {2,2}};
    for (int i = 0; i < 4; i++) {
        int idx = rand() % (4 - i) + i;
        // 交换随机选择的元素到前面
        int temp[2] = {corners[idx][0], corners[idx][1]};
        corners[idx][0] = corners[i][0];
        corners[idx][1] = corners[i][1];
        corners[i][0] = temp[0];
        corners[i][1] = temp[1];
        
        if (a[corners[i][0]][corners[i][1]] == '+') {
            a[corners[i][0]][corners[i][1]] = 'C';
            return;
        }
    }

    // 5. 随机选择空边
    int edges[4][2] = {{0,1}, {1,0}, {1,2}, {2,1}};
    for (int i = 0; i < 4; i++) {
        int idx = rand() % (4 - i) + i;
        // 交换元素
        int temp[2] = {edges[idx][0], edges[idx][1]};
        edges[idx][0] = edges[i][0];
        edges[idx][1] = edges[i][1];
        edges[i][0] = temp[0];
        edges[i][1] = temp[1];
        
        if (a[edges[i][0]][edges[i][1]] == '+') {
            a[edges[i][0]][edges[i][1]] = 'C';
            return;
        }
    }

    // 6. 如果全部填满则不做操作（理论上游戏已结束）
}

void SS(char a[3][3]){
	for(int i=1;i<=3;i++){
		for(int ii=1;ii<=3;ii++){
			a[i][ii]='+';
		}
	}
}
void outS(char a[3][3]){
	cout<<"  a b c\n";
	for(int i=1;i<=3;i++){
		cout<<endl;
		printf("%d",i);
		for(int ii=1;ii<=3;ii++){
			printf(" ");
			printf("%c",a[i][ii]);
		}
		cout<<endl;
	}
	cout<<"'P':玩家player  'C':电脑computer\n";
	return;
}
void exitPrint(void){
	Sleep(1000);
	cout<<"\n--------------------------------\n";
	cout<<"Process exited with return value 0\n";
	cout<<"3s later continue . . .";
	Sleep(3000);
	printf("\nTSY PRESENTS\n制作：CN-tsy");
	Sleep(600);
	exit(0); 
}
void noVL(char a[3][3]) {
    if (a[1][1] != '+' && a[2][1] != '+' && a[3][1] != '+' &&
        a[1][2] != '+' && a[2][2] != '+' && a[3][2] != '+' &&
        a[1][3] != '+' && a[2][3] != '+' && a[3][3] != '+') {
        Sleep(2000);
        cout << "平局！！！";
        exitPrint(); // 调用后退出程序
    }
}

void VL(char a[3][3]) {
    for (int i = 1; i <= 3; i++) {
        for (int ii = 1; ii <= 3; ii++) {
            // 检查行、列、对角线
            if ((a[i][1] == a[i][2] && a[i][2] == a[i][3] && a[i][1] != '+') ||
                (a[1][ii] == a[2][ii] && a[2][ii] == a[3][ii] && a[1][ii] != '+') ||
                (a[1][1] == a[2][2] && a[2][2] == a[3][3] && a[1][1] != '+') ||
                (a[1][3] == a[2][2] && a[2][2] == a[3][1] && a[1][3] != '+')) {
                if (a[i][ii] == 'C') {
                	system("cls");
                    outS(a);
					printf("计算机胜\n");
                } else {
                	system("cls");
                	outS(a);
                    printf("you're the winner!!!");
                }
                exitPrint(); // 调用后退出程序
            }
        }
    }
}

int main(){
	int _1,cnt=0;
	char _2; 
	bool a_;
	bool b=true;
	char a[3][3];
	printf("输入1自己先，输入0电脑先：");
	scanf("%d",&a_); 
	SS(a);
	outS(a);
	Sleep(1500);
	if(a_){
	} else {
		cnt++;
		printf("电脑先下"); 
		cdpwn(a);
		system("cls");
		outS(a);
	}
	printf("\n输入下子坐标,1个空格分开(数字 字母)");
	while(1){
		VL(a);noVL(a);
		while(1){
			scanf("%d %c",&_1,&_2);
			if(a[_1][_2-'a'+1]=='+'){
				a[_1][_2-'a'+1]='P';
				break;
			}else{
				printf("已占用，重输"); 
			}
		}
		VL(a);noVL(a);
		cdpwn(a);
		system("cls");
		outS(a);
		VL(a);noVL(a);
		system("cls");
		outS(a);
	}

	return 0;
}