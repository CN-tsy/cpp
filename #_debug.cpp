#include<iostream>
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<windows.h>
#include<functional>

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define YELLOW 6
#define WHITE 7
using std::cout;
using std::endl;
int   cnt2=0; 

/////////////////////////////////////////////////////////////////
 
void slowprint(char a[],int b){
    int s=strlen(a);
    for(int i=0;i<s;i++){
        cout<<a[i];
        Sleep(b);
    }
}

void COLOR_PRINT(const char* s, int color) {
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | color);
printf("%s", s);
SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | WHITE);
}

namespace TSY_PRESENTS{
void cdpwn(char board[3][3]) {
    Sleep(900);
    static bool seeded = false;
    if (!seeded) { srand(time(0)); seeded = true; }

    auto try_win = [&](char target) { // 通用检查函数
        // 检查行和列
        for(int i = 0; i < 3; i++) {
            int row_cnt = 0, col_cnt = 0, row_empty = -1, col_empty = -1;
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == target) row_cnt++;
                else if(board[i][j] == '+') row_empty = j;
                
                if(board[j][i] == target) col_cnt++;
                else if(board[j][i] == '+') col_empty = j;
            }
            if(row_cnt == 2 && row_empty != -1) { board[i][row_empty] = 'C'; return true; }
            if(col_cnt == 2 && col_empty != -1) { board[col_empty][i] = 'C'; return true; }
        }

        // 检查对角线
        int diag1_cnt = 0, diag2_cnt = 0, diag1_empty = -1, diag2_empty = -1;
        for(int i = 0; i < 3; i++) {
            if(board[i][i] == target) diag1_cnt++;
            else if(board[i][i] == '+') diag1_empty = i;
            
            int j = 2 - i;
            if(board[i][j] == target) diag2_cnt++;
            else if(board[i][j] == '+') diag2_empty = i;
        }
        if(diag1_cnt == 2 && diag1_empty != -1) { 
            board[diag1_empty][diag1_empty] = 'C'; 
            return true; 
        }
        if(diag2_cnt == 2 && diag2_empty != -1) { 
            board[diag2_empty][2 - diag2_empty] = 'C'; 
            return true; 
        }
        return false;
    };

    if(try_win('C')) return; // 尝试自己胜利
    if(try_win('P')) return; // 阻止玩家胜利

    // 随机选择空位
    int empty[9][2], count = 0;
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            if(board[i][j] == '+') 
                empty[count][0]=i, empty[count++][1]=j;
    
    if(count > 0) {
        int idx = rand() % count;
        board[empty[idx][0]][empty[idx][1]] = 'C';
    }
}
void SS(char a[3][3]){
	for(int i=0;i<3;i++){
		for(int ii=0;ii<3;ii++){
			a[i][ii]='+';
		}
	}
}
void outS(char a[3][3]){
	cout<<"  a b c\n";
	for(int i=0;i<3;i++){
		cout<<endl;
		printf("%d",i);
		for(int ii=0;ii<3;ii++){
			printf(" %c",a[i][ii]);
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
	COLOR_PRINT("\nTSY PRESENTS\n制作：CN-tsy",BLUE);
	Sleep(1600);
	exit(0); 
}
void noVL(char a[3][3]) {
    if (a[0][0] != '+' && a[1][0] != '+' && a[2][0] != '+' &&
        a[0][1] != '+' && a[1][1] != '+' && a[2][1] != '+' &&
        a[0][2] != '+' && a[1][2] != '+' && a[2][2] != '+') 
	{
        Sleep(2000);
        cout << "平局！！！";
        exitPrint(); // 调用后退出程序
    }
}
void VL(char a[3][3]) {
    // 检查行胜利（0-based索引）
    for(int row=0; row<3; ++row) {
        if(a[row][0]!='+' && a[row][0]==a[row][1] && a[row][1]==a[row][2]) {
            system("cls");
            outS(a);
            printf("%s\n%c" ,(a[row][0]=='C') ? "计算机胜" : "you're the winner!!!",7);
            exitPrint();
        }
    }

    // 检查列胜利（0-based索引）
    for(int col=0; col<3; ++col) {
        if(a[0][col]!='+' && a[0][col]==a[1][col] && a[1][col]==a[2][col]) {
            system("cls");
            outS(a);
            printf("%s\n%c", (a[0][col]=='C') ? "计算机胜" : "you're the winner!!!",7);
            exitPrint();
        }
    }

    // 主对角线检查（0,0→2,2）
    if(a[0][0]!='+' && a[0][0]==a[1][1] && a[1][1]==a[2][2]) {
        system("cls");
        outS(a);
        printf("%s\n%c", (a[0][0]=='C') ? "计算机胜" : "you're the winner!!!",7);
        exitPrint();
    }

    // 副对角线检查（0,2→2,0）
    if(a[0][2]!='+' && a[0][2]==a[1][1] && a[1][1]==a[2][0]) {
        system("cls");
        outS(a);
        printf("%s\n%c", (a[0][2]=='C') ? "计算机胜" : "you're the winner!!!",7);
        exitPrint();
    }
}
void check(char a[3][3]){
	VL(a);noVL(a);
}

void HideProgram(void){
	if(cnt2==5){
		for(int i=1;i<=51;i++){
			COLOR_PRINT("\n已占用，重输",RED);
			Sleep(100);
		}
		Sleep(1000*3);
		printf("\n%c",7);
		system("已占用，重输");
		cout<<"[Warning] unknown conversion type character 'l' in format [-Wformat=]";
		Sleep(3000*2); 
		COLOR_PRINT("\n--------------------------------\nProcess exited with return value 3221225477\nPress any key to continue . . .",YELLOW);
		char a[7];
		int i=1;
		getchar();
		while(1){
			a[i]=getchar();
			if(a[i]=='\n'){
				break;
			} 
			i++;
		}
		if(a[1]=='0'&&a[2]=='7'&&a[3]=='5'&&a[4]=='1'&&a[5]=='A'){
			system("cls");
			Sleep(1500);
			slowprint("你好！\n",90);
			Sleep(1000);
			slowprint("\n很抱歉刚才吓到你\n",50);
			Sleep(2000);
			slowprint("\n这段代码是我送给你的礼物:)\n",20);
			Sleep(2000);
			slowprint("\n那纪录片还不知道什么时候弄完\n",15);
			Sleep(1900);
			slowprint("\n先拿这个先垫着吧（？）\n",50);
			Sleep(1500);
			slowprint("\n(突然想起)很高兴你能发现这里呢\n",30);
			Sleep(1900);
			slowprint("\n最后...\n",90);
			Sleep(2300);
			COLOR_PRINT("\n祝我们友谊长存!\n         ——TSY\n\n",BLUE);
			system("pause");
			exitPrint(); 
		}
		if(a[1]=='1'&&a[2]=='7'&&a[3]=='2'&&a[4]=='1'&&a[5]=='A'){
			system("cls");Sleep(1500);
			slowprint("调试...（100ms）\n",100);Sleep(1000);
			cout<<"(system(\"pause\");)";system("pause");
			exitPrint();
		}
		exit(0);
	}
}
}

////////////////函数↑↓using//////////////////////////////////////////// 

using TSY_PRESENTS::noVL;
using TSY_PRESENTS::outS;
using TSY_PRESENTS::VL;
using TSY_PRESENTS::cdpwn;
using TSY_PRESENTS::check;

////////////////using↑↓main////////////////////////////////////////////

int main(){
	int _1,cnt=0;
	char _2; 
	bool a_;
	bool b=true;
	char a[3][3];
	
	time_t now = time(NULL);
	struct tm *local_tm = localtime(&now);
	char buffer[80];
	strftime(buffer,80,"%Y-%m-%d %H:%M:%S",local_tm);
	cout<<buffer<<endl;
	COLOR_PRINT("TSY PRESENTS\nCN-tsy呈现\n",BLUE);
	
	printf("输入1自己先，输入0电脑先：");
	scanf("%d",&a_); 
	TSY_PRESENTS::SS(a);
	Sleep(500);
	system("cls");
	outS(a);
	Sleep(1500);
	if(a_){
	} else {
		cnt++;
		printf("电脑先下(试试连续五次触发“已占用，重输”哦~)");
		Sleep(1900); 
		cdpwn(a);
		system("cls");
		outS(a);
	}
	
	while(1){
		check(a);
		while(1){
			printf("\n输入下子坐标,1个空格分开(数字 字母)");
			scanf("%d %c",&_1,&_2);
			if(a[_1][_2-'a']=='+'){
				a[_1][_2-'a']='P';
				break;
			}else{
				printf("已占用，重输"); 
				cnt2++;
				TSY_PRESENTS::HideProgram();
			}
		}
		check(a);
		cdpwn(a);
		system("cls");
		outS(a);
		check(a);
		system("cls");
		outS(a);
	}

	return 0;
}
