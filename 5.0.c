#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")

   
#define Allusers 100   
#define Lofuser 20
#define Lofpass 20

struct passworda
{
	int label; 
	char user[Lofuser];
	char pass[Lofpass];
};
void newusera();
void newuserb();
int checkusera();
int checkuserb();
int checkpassa();
int checkpassb();
int prouser1();
int prouser2();
int propass1();
int propass2();
struct passworda allusersa[Allusers];

struct passworda *usersa;


struct passwordb
{
	int label; 
	char user[Lofuser];
	char pass[Lofpass];
};

struct passwordb allusersb[Allusers];

struct passwordb *usersb;

struct A {
	int place;   //暂定10个     梅兰竹菊   桃李柳桂  南荷 北荷 
	int family;
	int year;
	int month;
	int up;   //峰时用电量 
	int down; //谷时用电量 
	int e;//总电量 
	double money; 
};
struct B {             //小区 
	double money ;
	double pjm;
	int ele;
	int pjele;
	int n;
	char * name;
};
typedef struct B B;
typedef struct A A; 


void newusera();
void newuserb();
//int password(); 
void password1(); //这部分内容是王雨桐写，然后我改了个名字
void password2(); //这部分内容是王雨桐写的 
void password3(); //这部分内容是王雨桐写，然后我改了个名字


/*以上为王雨桐的代码*/





void save(); 

void read(int i); 

void GetPreData();

void Seedata();

void Table();

void Familytable();

void px();

void search();

void searchbyplace();

void Pdital (int i);

void searchbyfamily();

void Fdital ( int i);

void kr();



 


void start();
void load();   //用户登录界面 
void option(); //系统设置界面 
void PlaySoundF();	//郭思佳的代码 
void playlist();    //郭思佳的代码 
void changecolour();//郭思佳的代码 
void GM();//管理员通道 
void new1();//
void new2();
void staff1();
void staff2();
void model();
void Add();
void Del();
void Look();
void Analysis(); 
void Change();
void Revise();
A a[4800]={0};
int n=100,sign=0;


int main(){
	int f,j,k,sum=0;
	read(1);
	read(2);
	srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
	for(f=0;f<100;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f*24+j*12+k; 
				a[sum].family=f+1;
				//a[sum].place=rand() % 10;
				if(j==0&&k==0){
					a[sum].place=rand() % 10;
				}
				else{
					a[sum].place=a[sum-k-12*j].place ;
				}
				a[sum].year=j;
				a[sum].month=k+1;
				a[sum].up=100+rand() % 101;
				a[sum].down=50+rand() % 51;
				a[sum].e=a[sum].up+a[sum].down;
				a[sum].money=a[sum].up*0.5583+a[sum].down*0.3583;
			}
		}
	}
	//
	//Table();
	system("color f1");
	start();
	return 0;
}

void save(){
//	FILE*fp;
} 

void read(int i){
	FILE *fp;
	switch(i){
		case 1:
			printf("一\n");
			fp=fopen("users1.dat","rb");
			fread(&allusersa,sizeof(allusersa),1,fp); 
			fclose(fp);
			//printf("\t\t\t账户   用户名   密码\n"); 
			//printf("\t\t检验输出：%d   %s   %s\n",allusersa[0].label,allusersa[0].user,allusersa[0].pass);
			break;
		case 2:
			printf("二\n");
			fp=fopen("users2.dat","rb");
			fread(&allusersb,sizeof(allusersb),1,fp); 
			fclose(fp);
			//printf("\t\t\t账户   用户名   密码\n");
			//printf("\t\t检验输出：%d   %s   %s\n",allusersa[0].label,allusersa[0].user,allusersa[0].pass);
			break;
	}
	
    //fwrite(allusers,sizeof(allusers),1,fp);
	//printf("%d",allusers[1].label);
	return ;
} 

void start(){
	int c;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.用户登录界面          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.系统设置              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开系统              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(1){ 
	    c=-1;//用于应对输入字母及字符的情况 
		scanf("%d",&c);
		/*重点！！！*/
		getchar();//研究一下午的成果QAQ
		  /*这个getchar()看似毫无用处，实际上却是一个关键点，如果没有这个getchar,当用户
		  输入一个字母的时候，这个程序会直接进入死循环 
			如果这里不加这个getchar,输入一个字母 a，scanf函数因为%d的缘故，会将字母送回缓冲区
			然后就会产生如下死循环循环，
			 1.scanf("%d",&c)读到一个字母，不符合要求，将字母送回缓存区
			 2.运行switch，然后出去
			 3,重新到 scanf("%d",&c)，读回之前存在缓存区的  a
			 4，无限循环
			 加了这个getchar 之后，之前存在缓存区里的 a 会被getchar读掉，结束循环
			 所以这里加个getchar,输入字母就不会报错了——郭晨光 */	
		switch(c){
			case 1:
				load();
				break;
			case 2:
				option(); 
			case 0:
				exit(0);
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}		
	}
	
	return;
}

void load (){
	int c; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.用电统计员          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.供电公司工作人员             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  3.管理员             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(1){ 
		c=-1;
		scanf("%d",&c);
		getchar(); 
		switch(c){
			case 1:
				system("cls"); 
				password1();
				system("cls");
				staff1();
				break;
			case 2:
				system("cls");
				password2();
				staff2(); 
			case 3:
				system("cls");
				password3();
				GM(); 
			case 0:
				system("cls"); 
				start();
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}
		getchar();
	}
	
	return;
}

void option (){
	int c;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          选项          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t1.选择颜色                          ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t2.选择背景音乐                      ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.返回                              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	while(1){ 
		c=-1;
		scanf("%d",&c); 
		getchar();
		switch(c){
			case 1:
				changecolour();
				break;
			case 2:
				PlaySoundF();
				break;
			case 0:
				start();
				break;
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n"); 
		}
	}	
	return;
}

void changecolour(){
	int c; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t        颜色及字体设置          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t1.淡雅格调    灰底黑字              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t2.清新俏皮    白底紫字              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t3.水光潋滟    白底蓝字              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t4.青春活力    紫底红字              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t5.动感激萌    黄底蓝字              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.返回                              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");	
	while(1){
		c=-1;
		scanf("%d",&c);
		getchar();
		while(c<0||c>5){ 
			printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
			c=-1;
			scanf("%d",&c);
			getchar();
		}
		switch(c){
			case 1:
				system("color 80");
				break;
			case 2:
				system("color f5");
				break;
			case 3:
				system("color f3");
				break;
			case 4:
				system("color d4");
				break;
			case 5:
				system("color e9");
				break;
			case 0:
				option(); 
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}
		printf("\t\t\t\t\t\t\t\t\t\t可以继续尝试其他颜色，返回上层请按0\n");
	}
}

void GM(){
	int c;
	sign=3;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     管理员          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.注册用户             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.查询数据             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  3.修改数据             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  4.数据分析             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开系统             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(1){
		c=-1;
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				Add();
				break;
			case 2:
				Look();
				break; 
			case 3:
				Change();
				break; 
			case 4:
				Analysis();
				break;
			case 0:
				load();
				break;
			default:
				printf("无该选项，请重新选择"); 
		}
	}
} 








void GetPreData(){
	int i=0,j=0,k=0,f=0,sum=0,number=0,c=0;  
	system("cls") ;
	srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          生成初始数据          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t您想生成几户人家的数据？            ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t（100户到200户之间 ）               ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.离开系统                          ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");			
	number=-1;
	scanf("%d",&number); 
	getchar(); 
	while(number<100||number>200){
		printf("\t\t\t\t\t\t\t\t\t\t输入数据有误\n\t\t\t\t\t\t\t\t\t\t请输入100到200之间的数\n");
		c=-1;
		scanf("%d",&number); 
		getchar(); 
	} 
	n=number;
	for(f=0;f<number;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f*24+j*12+k; 
				a[sum].family=f+1;
				//a[sum].place=rand() % 10;
				if(j==0&&k==0){
					a[sum].place=rand() % 10;
				}
				else{
					a[sum].place=a[sum-k-12*j].place ;
				}
				a[sum].year=j;
				a[sum].month=k+1;
				a[sum].up=100+rand() % 101;
				a[sum].down=50+rand() % 51;
				a[sum].e=a[sum].up+a[sum].down;
				a[sum].money=a[sum].up*0.5583+a[sum].down*0.3583;
			}
		}
	}
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t初始数据生成完毕                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.离开系统                          ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");	
	c=-1;
	scanf("%d",&c) ;
	getchar();
	if(c!=0){
		printf("\t\t\t\t\t\t\t\t\t\t输入有误\n");
		c=-1;
		scanf("%d",&c) ;
		getchar();
	}
	system("cls");
	Change();
	return ;
}



void Table(){
	int i=0,j=0,k=0,f=0,sum=0,c;
	double money=0;
	B b[10]={0};
	system("cls");
	printf("\n\n\n\n\n") ;
	b[0].name="梅苑"; 
	b[1].name="兰苑"; 
	b[2].name="竹苑"; 
	b[3].name="菊苑"; 
	b[4].name="桃苑"; 
	b[5].name="李苑"; 
	b[6].name="柳苑"; 
	b[7].name="桂苑"; 
	b[8].name="南荷";
	b[9].name="北荷"; 
	//printf("%s",b[1].name);
	while(1){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
		printf("\t\t\t\t\t\t\t\t\t\t      查询数据          \n\n");
		printf("\t\t\t\t\t\t\t\t\t●================================●\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                          ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t1.家庭统计表              ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                          ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t2.小区统计表              ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                          ┃\n");	
		printf("\t\t\t\t\t\t\t\t\t┃\t0.返回                    ┃\n");	
		printf("\t\t\t\t\t\t\t\t\t┃\t                          ┃\n");		
		printf("\t\t\t\t\t\t\t\t\t●================================●\n");
		c=-1;
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				Familytable();
				break;
			case 2:
				system("cls");
				printf("\t\t\t\t\t\t\t\t\t\t\t小区统计表\n");
				printf("\n\n\n");
				printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
				printf("\t\t\t\t\t| 小区 | 2017年的总用电量 | 2018年的总用电量 | 一年户均用电量 | 2017年的总用电费 | 2018年的总用电费 | 一年户均用电费 |\n");
				printf("\t\t\t\t\t|      |\t\t  |  \t\t     |\t\t      |\t\t         |\t\t    |\t\t     |\n");
				for(f=0;f<n;f++){
					for(j=0;j<2;j++){
						for(k=0;k<12;k++){
							sum=f*24+j*12+k;
							for(i=0;i<=9;i++){
								if (a[sum].place==i){
									if(j==0&&k==0)b[i].n++;
									if(j==0){
										b[i].ele+=a[sum].e;
										b[i].money+=a[sum].money;
									}
									else{
										b[i].pjele+=a[sum].e;
										b[i].pjm+=a[sum].money;
									} 
								}
							}
						}
					}
				}
				for(i=0;i<=9;i++){
					printf("\t\t\t\t\t| %s |   %5d千瓦时    |   %5d千瓦时    |   %5d千瓦时  |  %12f元  |  %12f元  | %12f元 |\n",b[i].name,b[i].ele,b[i].pjele,(b[i].ele+b[i].pjele)/b[i].n,b[i].money,b[i].pjm,b[i].money+b[i].pjm/b[i].n);
					printf("\t\t\t\t\t|      |\t\t  |  \t\t     |\t\t      |\t\t         |\t\t    |\t\t     |\n");
				}
				printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
				printf("\n\n\n");
				/*printf("\t小区  2017年的总用电费   2018年的总用电费    一年户均用电费\n");
				for(f=0;f<n;f++){
					for(j=0;j<2;j++){
						for(k=0;k<12;k++){
							sum=f+j+k;
							for(i=0;i<=9;i++){
								if(a[sum].place==i){
									if(j==0||k==0)b[i].n++;
									if(j==0){
										b[i].money+=a[sum].money;
									}
									else{
										b[i].pjm+=a[sum].money;
									} 
								}
							}
						}
					}
				}
				for(i=0;i<=9;i++){
					printf("\t%s  %12f元      %12f元     %12f元\n",b[i].name,b[i].money,b[i].pjm,b[i].money+b[i].pjm/b[i].n);
				}
				printf("\n\n\n");*/
				printf("\n\n\t\t\t\t\t\t\t\t 0 返回上层\n\n");
				while(1){
					scanf("%d",&c);
					if(c==0){
						system("cls");
						Look();
					}	
					printf("\n\n\t\t\t\t\t\t\t\t无该选项，请重新选择"); 
					getchar();
				} 
				break;
			case 0:
				system("cls");
				Look();
			default:
				printf("\n\n\t\t\t\t\t\t\t\t无该选项，请重新选择\n"); 
		}
	}
	system("cls");
	return;
}
void Familytable(){
	int i=0,j,k,f,sum,e;
	char c; 
	double money=0;
	B b[10]={0};
	sign=4;
	system("cls");
	printf("\n\n\n\n\n") ;
	b[0].name="梅苑"; 
	b[1].name="兰苑"; 
	b[2].name="竹苑"; 
	b[3].name="菊苑"; 
	b[4].name="桃苑"; 
	b[5].name="李苑"; 
	b[6].name="柳苑"; 
	b[7].name="桂苑"; 
	b[8].name="南荷";
	b[9].name="北荷"; 
	system("cls");
	
	for(i=1;i<=20;i++){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t家庭统计表 第%d页\n\n",i);
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
		printf("\t\t\t\t\t\t\t|家庭编号| 2017年的总用电量 | 2017年的总用电费 | 2018年的总用电量 | 2018年的总用电费 |\n");
		for(f=15*(i-1);f<15*i;f++){
			for(j=0;j<2;j++){
				for(k=0;k<12;k++){
					sum=f*24+j*12+k;
					if(f<n){
						if(k==0)e=0;
						if(k==0)money=0;
						money+=a[sum].money;
						e+=a[sum].up;
						e+=a[sum].down;
						if(j==0&&k==0){
							if(f<9){
								printf("\t\t\t\t\t\t\t|家庭00%d |",f+1);
							}
							else{
								if(f<99){
									printf("\t\t\t\t\t\t\t|家庭0%d |",f+1);
								}
								else printf("\t\t\t\t\t\t\t|家庭%d |",f+1);
							}
						} 
						if(j==0&&k==11)printf("    %d千瓦时    |",e);
						if(j==1&&k==11)printf("    %d千瓦时    |",e);
						if(j==0&&k==11)printf("   %f元  |",money);
						if(j==1&&k==11)printf("   %f元  |\n",money);
					}
				}
			}
			printf("\t\t\t\t\t\t\t|        |\t\t    |\t\t       |\t\t  |\t\t     |\n");
		}
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
		if(f<n){
			printf("\n\n\t\t\t\t\t\t\t\t\t1.下一页\t\t2.查看详细数据\t\t0.返回上层\n");
			scanf("%c",&c);
			getchar();
			while(c!=50&&c!=48&&c!=49) {
				printf("\n\n\t\t\t\t\t\t\t\t\t无该选项，请重新选择");
				scanf("%c",&c);
				getchar();
			}
			switch(c){
				case 48:
					Table();
					break;
				case 49:
					system("cls");
					break;
				case 50:
					Seedata();
					break;
				default: 
					break;
			}
		}
		else{
			printf("\n\n\t\t\t\t\t\t\t\t\t没有下一页了\t\t2.查看详细数据\t\t0.返回上层\n");
			scanf("%c",&c);
			getchar();
			while(c!=50&&c!=48) {
				printf("\n\n\t\t\t\t\t\t\t\t\t无该选项，请重新选择");
				scanf("%c",&c);
				getchar();
			}
			switch(c){
				case 48:
					Table();
					break;
				case 50:
					Seedata();
					break;
				default:
					printf("\n\n\t\t\t\t\t\t\t\t\t无该选项，请重新选择"); 
			}
		} 
		
	}
	
	printf("\n\n\n");
	/*printf("\t家庭  2017年的总用电费  2018年的总用电费  \n");
	for(f=0;f<n;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f+j+k; 
				if(k==0)money=0;
				money+=a[sum].money;
				if(j==0&&k==0)printf("\t家庭%d",f+1);
				if(j==0&&k==11)printf("\t%.4f元   ",money);
				if(j==1&&k==11)printf("\t  %.4f元   \n",money);
				
			}
		}
	}
	printf("\n\n\n");
	break;*/
}

void px(){
	int i,j,k,f,sum,c,max;
	B b[10]={0}; 
	system("cls");
	printf("\n\n") ;
	b[0].name="梅苑"; 
	b[1].name="兰苑"; 
	b[2].name="竹苑"; 
	b[3].name="菊苑"; 
	b[4].name="桃苑"; 
	b[5].name="李苑"; 
	b[6].name="柳苑"; 
	b[7].name="桂苑"; 
	b[8].name="南荷";
	b[9].name="北荷"; 
	printf("\t\t\t~排序系统~\n\n");
	printf("\t\t小区统计表\n");
	printf("\t小区     总用电费         总用电量       户均用电费     户均用电量   户口数\n\n");
	for(f=0;f<n;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f*24+j*12+k;
				for(i=0;i<=9;i++){
					if(a[sum].place==i){
						b[i].money+=a[sum].money;
						b[i].ele+=a[sum].e;
						if(j==0&&k==0)b[i].n++;
					}
				} 
			}
		}
	}
	for(i=0;i<=9;i++){
		b[i].pjm=b[i].money/b[i].n;
		b[i].pjele=b[i].ele/b[i].n;
	}
	for(i=0;i<=9;i++){
		printf("\t%s   %12f元    %6d千瓦时   %f元   %d千瓦时    %d户\n\n",b[i].name,b[i].money,b[i].ele,b[i].pjm,b[i].pjele,b[i].n);
	}
	printf("\n\n\n");
	while(1){
		printf("\t按总电量排序请按1\n\t按总电费排序请按2\n\t按平均电量排序请按3\n\t按平均电费排序请按4\n\t返回上级菜单请按0\n\n\n");
		scanf("%d",&c);
		switch(c){
			case 1:
				max=0;
				system("cls");
				printf("\t\t\t按总电量排序\n\n\t小区         总用电费         总用电量      户均用电费      户均用电量      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].ele<b[j].ele){
							max=j;
						}
					}
					printf("\t%s   %15f元    %6d千瓦时   %f元   %5d千瓦时    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
					b[max].ele=0; 
					max=0;
				}
				break;
			case 2:
				max=0;
				system("cls");
				printf("\t\t\t按总电费排序\n\n\t小区         总用电费         总用电量      户均用电费      户均用电量      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].money<b[j].money	){
							max=j;
						}
					}
					printf("\t%s   %15f元    %6d千瓦时   %f元   %5d千瓦时    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
					b[max].money=0; 
					max=0;
				}
				break;
			case 3:
				max=0;
				system("cls");
				printf("\t\t\t按平均电量排序\n\n\t小区         总用电费         总用电量      户均用电费      户均用电量      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].pjele	<b[j].pjele	){
							max=j;
						}
					}
					printf("\t%s   %15f元    %6d千瓦时   %f元   %5d千瓦时    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
					b[max].pjele=0; 
					max=0;
				}
				break;
			case 4:
				max=0;
				system("cls");
				printf("\t\t\t按平均电费排序\n\n\t小区         总用电费         总用电量      户均用电费      户均用电量      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].pjm	<b[j].pjm	){
							max=j;
						}
					}
					printf("\t%s   %15f元    %6d千瓦时   %f元   %5d千瓦时    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
					b[max].pjm=0; 
					max=0;
				}
				break;
			case 0:
				system("cls");
				if(sign==1){
					staff1();
				}
				else{
					GM();
				}
				break;
			default:
				printf("无该选项，请重新选择\n");
		}
		for(f=0;f<n;f++){
			for(j=0;j<2;j++){
				for(k=0;k<12;k++){
					sum=f*24+j*12+k;
					for(i=0;i<=9;i++){
						if(a[sum].place==i){
							b[i].money+=a[sum].money;
							b[i].ele+=a[sum].e;
							if(j==0&&k==0)b[i].n++;
						}
					} 
				}
			}
	}
	for(i=0;i<=9;i++){
		b[i].pjm=b[i].money/b[i].n;
		b[i].pjele=b[i].ele/b[i].n;
	}
	}
	return;
}
void kr(){
	int c=-1,x=1,max=0,k=0,j=0,f=0,i=0,fir=0,sec=0,sum=0,number=0; 
	int px[10]={0};
	B b[20]={0}; 
	B *p=b;
	system("cls");
	printf("\n\n\n\n\n") ;
	b[0].name="梅苑"; 
	b[1].name="兰苑"; 
	b[2].name="竹苑"; 
	b[3].name="菊苑"; 
	b[4].name="桃苑"; 
	b[5].name="李苑"; 
	b[6].name="柳苑"; 
	b[7].name="桂苑"; 
	b[8].name="南荷";
	b[9].name="北荷"; 
	for(f=0;f<n;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f*24+j*12+k;
				for(i=0;i<=9;i++){
					if(a[sum].place==i){
						b[i].money+=a[sum].money;
						b[i].ele+=a[sum].e;
						if(j==0&&k==0)b[i].n++;
					}
				} 
			}
		}
	}
	for(i=0;i<=9;i++){
		b[i].pjm=b[i].money/b[i].n;
		b[i].pjele=b[i].ele/b[i].n;
	}
	while(1){
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
			printf("\t\t\t\t\t\t\t\t\t\t          扩容小区模拟          \n\n");
			printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t如何判断哪些小区需要扩容？          ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t1总用电量最多的小区                 ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t2总共交电费最多的小区               ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t3平均用电量最多的小区               ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t4平均交电费最多的小区               ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t0返回                               ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
			printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
			scanf("%d",&c);
			getchar();
			switch(c){
				case 1:
					printf("\n\t\t\t\t\t\t\t\t\t\t您本次打算扩容几个小区？\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t根据您的选择，我们将选出总用电量最多的前%d个小区，作为扩容的对象\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t以下是总用电量排名前的小区的数据\n\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| 小区 |    总用电费    |   总用电量   |   户均用电费   |  户均用电量  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].ele<b[j].ele){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12f元 | %6d千瓦时 | %12f元 |  %5d千瓦时 |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
						if(k!=x-1)printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
						b[max].ele=0; 
						max=0;
					}
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\n\t\t\t\t\t\t\t\t\t\t我们推荐您扩容");
					for(i=0;i<x;i++){
						printf("%s",b[px[i]].name);
						if(i!=x){
							printf("、");
						}
					} 
					printf("这%d个小区\n\n",x);
			 		break;
				case 2:
					printf("\n\t\t\t\t\t\t\t\t\t\t您本次打算扩容几个小区？\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t根据您的选择，我们将选出总共交电费最多的前%d个小区，作为扩容的对象\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t以下是总共交电费前%d名的小区的数据\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| 小区 |    总用电费    |   总用电量   |   户均用电费   |  户均用电量  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].money<b[j].money	){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12f元 | %6d千瓦时 | %12f元 |  %5d千瓦时 |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
						if(k!=x-1)printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
						b[max].ele=0; 
						max=0;
					}
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\n\t\t\t\t\t\t\t\t\t\t我们推荐您扩容");
					for(i=0;i<x;i++){
						printf("%s",b[px[i]].name);
						if(i!=x){
							printf("、");
						}
					} 
					printf("这%d个小区\n\n",x);
					break;
				case 3:
					printf("\n\t\t\t\t\t\t\t\t\t\t您本次打算扩容几个小区？\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t根据您的选择，我们将选出平均用电量最多的前%d个小区，作为扩容的对象\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t以下是平均用电量前%d名的小区的数据\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| 小区 |    总用电费    |   总用电量   |   户均用电费   |  户均用电量  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].pjele<b[j].pjele){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12f元 | %6d千瓦时 | %12f元 |  %5d千瓦时 |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
						if(k!=x-1)printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
						b[max].pjele=0; 
						max=0;
					}
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\n\t\t\t\t\t\t\t\t\t\t我们推荐您扩容");
					for(i=0;i<x;i++){
						printf("%s",b[px[i]].name);
						if(i!=x){
							printf("、");
						}
					} 
					printf("这%d个小区\n\n",x);
					break;
				case 4:
					printf("\n\t\t\t\t\t\t\t\t\t\t您本次打算扩容几个小区？\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t根据您的选择，我们将选出平均交电费最多的前%d个小区，作为扩容的对象\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t以下是平均交电费前%d名的小区的数据\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| 小区 |    总用电费    |   总用电量   |   户均用电费   |  户均用电量  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].pjm<b[j].pjm){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12f元 | %6d千瓦时 | %12f元 |  %5d千瓦时 |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
						if(k!=x-1)printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
						b[max].pjm=0; 
						max=0;
					}
				case 0:
					if(sign==2){
						staff2();
					}
					else{
						GM();
					}
			} 
		for(f=0;f<n;f++){
			for(j=0;j<2;j++){
				for(k=0;k<12;k++){
					sum=f*24+j*12+k;
					for(i=0;i<=9;i++){
						if(a[sum].place==i){
							b[i].money+=a[sum].money;
							b[i].ele+=a[sum].e;
							if(j==0&&k==0)b[i].n++;
						}
					} 
				}
			}
		}
		for(i=0;i<=9;i++){
			b[i].pjm=b[i].money/b[i].n;
			b[i].pjele=b[i].ele/b[i].n;
		}
	}
	system("cls");
	return ;
} 
void newusera()  //王雨桐的代码 
 {
	int place=0;
	int m;
	int n;
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t欢迎注册新用电统计员\n\n\n\n");
	while(allusersa[place].label!=0)
		place++;
	//用户名部分 
	printf("\n\n\t\t请输入用户名：");	
	do
	{
		char u[Lofuser]={0};
		m=checkusera(u,place);
	}while(m);
	printf("\n\t\t该用户名可以使用,请输入密码:"); 
	
	//密码部分 
	do
	{
		char p1[Lofpass]={0},p2[Lofpass]={0};
		n=checkpassa(p1,p2,place);
	}while(n);
	printf("\n\n\n\t\t注册成功！可以回去登录啦w！"); 
	printf("\n\n\n\t\t按0返回上级菜单哦～");
{
	int a;
	do
	{	
		scanf("%d",&a); //这里我改了下，不然有可能会读入回车 
		//a=getch();      //原本的代码 
		if(a==0)
			GM(); //我进行的衔接 
			//printf("\n\n\t\t嘤，其实我是上级菜单啦～");//此处为上级菜单函数            //原本的代码 
		else
			printf("\n\n\t\t调皮，都说了按0啦～"); 
	}while(a!=48);
	//此处返回上级菜单
	return; 
}
}

void newuserb()  //王雨桐的代码 
 {
	int place=0;
	int m;
	int n;
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t欢迎注册供电系统\n\n\n\n");
	while(allusersb[place].label!=0)
		place++;
	//用户名部分 
	printf("\n\n\t\t请输入用户名：");	
	do
	{
		char u[Lofuser]={0};
		m=checkuserb(u,place);
	}while(m);
	printf("\n\t\t该用户名可以使用,请输入密码:"); 
	
	//密码部分 
	do
	{
		char p1[Lofpass]={0},p2[Lofpass]={0};
		n=checkpassb(p1,p2,place);
	}while(n);
	printf("\n\n\n\t\t注册成功！可以回去登录啦w！"); 
	printf("\n\n\n\t\t按0返回上级菜单哦～");
{
	int a;
	do
	{	
		scanf("%d",&a); //这里我改了下，不然有可能会读入回车 
		//a=getch();      //原本的代码 
		if(a==0)
			GM(); //我进行的衔接 
			//printf("\n\n\t\t嘤，其实我是上级菜单啦～");//此处为上级菜单函数            //原本的代码 
		else
			printf("\n\n\t\t调皮，都说了按0啦～"); 
	}while(a!=48);
	//此处返回上级菜单
	return; 
}
}

int checkusera(char u[Lofuser],int n)//王雨桐的代码 
{
	int k=0,j=0,t=0,judge[Allusers],sign=0;
	//输入；
	getchar();//这句是我后来添加的 ,不然会误读上面 
	while(k<Lofuser)
	{
		u[k]=getchar();
		//scanf("%c",&u[k]);
		if(u[k]=='\n')
			break;
		k++;
	}
	u[k]='\0';
	//printf("\n\n\t\t%s\n",u); 
	//printf("rua!想不到吧!"); 
	//判断是否相等，相等则重新输入
	//printf("\n\n\t\trua!想不到吧!"); 
	if(n!=0)
	{
		for(j=0;j<n;j++)
		{
			for(t=0;t<Lofuser;t++)
			{
				if(allusersa[j].user[t]==u[t])
				{
					continue;
				}
				else
				{
					judge[j]=1;
					break;
				}
			}
		}
		for(j=0;j<n;j++)
		{
			if(judge[j]==0)
			{
				sign=1;
				printf("\t\t用户名重复,请重新输入:");
				break;
			}		
		}
	}
	if(sign==0)
	{
		for(k=0;k<Lofuser;k++)
		{
			allusersa[n].user[k]=u[k];
		} 		
	}
	return sign;
}

int checkpassa(char a[Lofpass],char b[Lofpass],int n)  //王雨桐的代码 
{
	int k=0,j=0,sign=0;
	char c;
	while(k<Lofpass)
	{
		c=getch();
		if(c!=13)
		{
			a[k++]=c;
			putchar('*');				
		}
		if(c==13)
			break;
	}
	a[k]='\0';
	//printf("\n\n\t\t%s\n",p1);		
	printf("\n\t\t请确认您的密码:");
	j=0;
	while(j<Lofpass)
	{
		c=getch();
		if(c!=13)
		{
			b[j++]=c;
			putchar('*');				
		}
		if(c==13)
			break;
	}
	b[j]='\0';	
	for(j=0;j<Lofpass;j++)
	{
		if(a[j]!=b[j])
		{
			sign=1;
			printf("\n\n\t\t两次输入不一致,请重新输入:");
			break;
		}
	}
	if(sign==0)
	{
		for(k=0;k<Lofpass;k++)
		{
			allusersa[n].pass[k]=a[k];
		} 		
	}
	return sign;
}


int checkuserb(char u[Lofuser],int n)//王雨桐的代码 
{
	int k=0,j=0,t=0,judge[Allusers],sign=0;
	//输入；
	getchar();//这句是我后来添加的 ,不然会误读上面 
	while(k<Lofuser)
	{
		u[k]=getchar();
		//scanf("%c",&u[k]);
		if(u[k]=='\n')
			break;
		k++;
	}
	u[k]='\0';
	//printf("\n\n\t\t%s\n",u); 
	//printf("rua!想不到吧!"); 
	//判断是否相等，相等则重新输入
	//printf("\n\n\t\trua!想不到吧!"); 
	if(n!=0)
	{
		for(j=0;j<n;j++)
		{
			for(t=0;t<Lofuser;t++)
			{
				if(allusersb[j].user[t]==u[t])
				{
					continue;
				}
				else
				{
					judge[j]=1;
					break;
				}
			}
		}
		for(j=0;j<n;j++)
		{
			if(judge[j]==0)
			{
				sign=1;
				printf("\t\t用户名重复,请重新输入:");
				break;
			}		
		}
	}
	if(sign==0)
	{
		for(k=0;k<Lofuser;k++)
		{
			allusersb[n].user[k]=u[k];
		} 		
	}
	return sign;
}

int checkpassb(char a[Lofpass],char b[Lofpass],int n)  //王雨桐的代码 
{
	int k=0,j=0,sign=0;
	char c;
	while(k<Lofpass)
	{
		c=getch();
		if(c!=13)
		{
			a[k++]=c;
			putchar('*');				
		}
		if(c==13)
			break;
	}
	a[k]='\0';
	//printf("\n\n\t\t%s\n",p1);		
	printf("\n\t\t请确认您的密码:");
	j=0;
	while(j<Lofpass)
	{
		c=getch();
		if(c!=13)
		{
			b[j++]=c;
			putchar('*');				
		}
		if(c==13)
			break;
	}
	b[j]='\0';	
	for(j=0;j<Lofpass;j++)
	{
		if(a[j]!=b[j])
		{
			sign=1;
			printf("\n\n\t\t两次输入不一致,请重新输入:");
			break;
		}
	}
	if(sign==0)
	{
		for(k=0;k<Lofpass;k++)
		{
			allusersb[n].pass[k]=a[k];
		} 		
	}
	return sign;
}


void model(){
	int c;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.用户登录界面          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.系统设置              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开系统              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	
	
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          查询数据          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t您想查几号家庭几月几日的信息？      ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t家庭1~100，年2017~2018，月1~12      ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.离开系统                          ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	while(1){ 
		getchar();
		scanf("%c",&c);
		switch(c){
			case 49:
				load();
				break;
			case 50:
				option(); 
			case 48:
				return;
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
				break;
		}
	}
}
void staff2() //登录界面 
{
	int c; 
	sign=2;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t  供电公司统计员          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.查询数据             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.数据分析             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.返回                 \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(1){
		scanf("%d",&c);
		getchar(); 
		switch(c){
			case 1:
				Look(); 
				break;
			case 2:
				Analysis(); 
				break;
			case 0:
				load();
				break;
			default:
				printf("无该选项，请重新选择\n");
		}
	}
	return ;
}
void staff1(){
	int c=-1; 
	sign=1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t  用电统计员          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.查询数据                  \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.修改数据                \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.返回                  \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(1){
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				system("cls");
				Look(); 
				break;
			case 2:
				Change();
				break;
			case 0:
				load();
				break;
			case 4:
				//load();
				break;
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}
	}
	return ;
}
void new1(){
	
}
void new2(){
	
}
void search()
{
	int c=-1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          按要求查询          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t1.按照小区查询                      ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t2.按照用户查询                      ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.返回                              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	while(1){
		scanf("%d",&c);
		getchar();
		switch(c)
		{
			case 1:
				searchbyplace();
				break;
			case 2:
				searchbyfamily();
				break;
			case 0:
				system("cls");
				Look(); 
				break;
			default: 
				printf("\n\n\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n"); 
				break;
		}
	}
	return ;
}
	
void searchbyplace(){
	int i,j,k,f,sum,c;
	double money=0;
	B b[10]={0};
	b[0].name="梅苑"; 
	b[1].name="兰苑"; 
	b[2].name="竹苑"; 
	b[3].name="菊苑"; 
	b[4].name="桃苑"; 
	b[5].name="李苑"; 
	b[6].name="柳苑"; 
	b[7].name="桂苑"; 
	b[8].name="南荷";
	b[9].name="北荷"; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          按照小区查询          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t1.梅苑 2.兰苑 3.竹苑 4.菊苑         ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t5.桃苑 6.李苑 7.柳苑 8.桂苑         ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t9.南荷        10.北荷               ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.离开系统                          ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	while(1){
		i=-1;
		scanf("%d",&i);
		getchar();
		while(i<0||i>10){
			printf("\n\t\t\t\t\t\t\t\t\t输入错误，请重新输入\n");
			printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t1.梅苑 2.兰苑 3.竹苑 4.菊苑         ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t5.桃苑 6.李苑 7.柳苑 8.桂苑         ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t9.南荷        10.北荷               ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t0.离开系统                          ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
			printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
			scanf("%d",&i);
			getchar();
		}
		if(i!=0){
			system("cls");
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t按小区检索 第%d页\n\n",i);
			printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
			printf("\t\t\t\t\t|      |                |                |              |                |                |              |\n");
			printf("\t\t\t\t\t| 小区 |2017年的总用电量|2018年的总用电量|一年户均用电量|2017年的总用电费|2018年的总用电费|一年户均用电费|\n");
			printf("\t\t\t\t\t|      |                |                |              |                |                |              |\n");
			for(f=0;f<n;f++){
				for(j=0;j<2;j++){
					for(k=0;k<12;k++){
						sum=f*24+j*12+k;
						if (a[sum].place==i-1){
							if(j==0||k==0)b[i-1].n++;
							if(j==0){
								b[i-1].ele+=a[sum].e;
								b[i-1].money+=a[sum].money;
							}
							else{
								b[i-1].pjele+=a[sum].e;
								b[i-1].pjm+=a[sum].money;
							} 
						}
					}
				}
			}	
		}
		
		else {
			search();
		}
		printf("\t\t\t\t\t|------|----------------|----------------|--------------|----------------|----------------|--------------|\n");
		printf("\t\t\t\t\t|      |                |                |              |                |                |              |\n");
		printf("\t\t\t\t\t| %s |   %5d千瓦时  |   %5d千瓦时  | %5d千瓦时  | %12f元 | %12f元 |%12f元|\n",b[i-1].name,b[i-1].ele,b[i-1].pjele,(b[i-1].ele+b[i-1].pjele)/b[i-1].n,b[i-1].money,b[i-1].pjm,b[i-1].money+b[i-1].pjm/b[i-1].n);
		printf("\t\t\t\t\t|      |                |                |              |                |                |              |\n");
		printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
		printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t1.查看详细信息                      ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t0.返回                              ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
		printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
		c=-1;
		scanf("%d",&c);
		getchar();
		system("cls");
		while(c<0||c>1){
			system("cls"); 
			printf("\n\t\t输入错误，请重新输入\n");
			printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t1.查看详细信息                      ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t0.返回                              ┃\n");
			printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
			printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
			scanf("%d",&c);
			getchar();
		}
		if(c==1){
			Pdital (i);
		}
	}
	//printf("\t %s   %5d千瓦时       %5d千瓦时      %5d千瓦时       %12f元      %12f元     %12f元\n",b[i].name,b[i].ele,b[i].pjele,(b[i].ele+b[i].pjele)/b[i].n,b[i].money,b[i].pjm,b[i].money+b[i].pjm/b[i].n);
} 

void Pdital (int i){                   // i为第i个小区 
	int j,k,f,sum,m,month,c=-1;
	double money=0;
	B b[10]={0};
	i=i-1  ;                  //数组中的数据是从 0开始的，所以要减一 
	//B month[12]={0};
	
	b[0].name="梅苑"; 
	b[1].name="兰苑"; 
	b[2].name="竹苑"; 
	b[3].name="菊苑"; 
	b[4].name="桃苑"; 
	b[5].name="李苑"; 
	b[6].name="柳苑"; 
	b[7].name="桂苑"; 
	b[8].name="南荷";
	b[9].name="北荷"; 
	/*      计算户口数       */
	for(f=0;f<n;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f*24+j*12+k;
				if(a[sum].place==i&&j==0&&k==0)b[i].n++;
			}
		}
	}
	for(m=0;m<2;m++){  //m为页数，m=1时为第一页即第一年的数据 
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\t\t小区%s第%d年的详细信息\n\n",b[i].name,m+2017);
		printf("\t\t\t\t\t\t\t\t\t小区%s共有%d户人家\n\n",b[i].name,b[i].n);
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
		printf("\t\t\t\t\t\t\t|月份|   用电量   |   上缴电费  | 户均用电量 | 户均用电费 |\n");
		printf("\t\t\t\t\t\t\t|----|------------|-------------|------------|------------|\n");
		for(month=0;month<12;month++){  //因为我的结构体排序和小区无关，所以每个月都要重新执行一次循环 
			b[i].money=0;
			b[i].ele=0;
			for(f=0;f<n;f++){
				for(j=0;j<2;j++){
					for(k=0;k<12;k++){
						sum=f*24+j*12+k;
						if(j==m&&a[sum].place==i&&k==month){
							b[i].ele+=a[sum].e;
							b[i].money+=a[sum].money;
						}
					}
				}
			}
			b[i].pjele=b[i].ele/b[i].n; 
			b[i].pjm=b[i].money/b[i].n;
			//      printf("\t\t月份\t用电量\上缴电费\t户均用电量\t户均用电费\n\n");
			printf("\t\t\t\t\t\t\t|%2d月| %4d千瓦时 | %9.4f元 | %4d千瓦时 |%9.4f元 |\n",month+1,b[i].ele,b[i].money,b[i].pjele,b[i].pjm);
			if(month!=11){
				printf("\t\t\t\t\t\t\t|----|------------|-------------|------------|------------|\n");
			}
			else{
				printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
			}
		}
		if(m==0){
			printf("\t\t\t\t\t\t\t\t\t1.下一页\t\t 0.返回上层\n");
			c=-1;
			scanf("%d",&c);
			getchar();	
			while(c<0||c>1){
				printf("\n\t\t\t\t\t\t\t\t\t输入错误，请重新输入\n");
				scanf("%d",&c);
				getchar();
			}
			switch(c){
				case 1:
					break;
				case 0:
					searchbyplace();
					break;
				default:
					printf("\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
			}
		}
		else{
			printf("\t\t\t\t\t\t\t\t\t最后一页了\t\t 0.返回上层\n");
			c=-1;
			scanf("%d",&c);
			getchar();
			while(c!=0){
				printf("\n\t\t\t\t\t\t\t\t\t输入错误，请重新输入\n");
				scanf("%d",&c);
				getchar();
			}
			searchbyplace();
		}
	}
}

void searchbyfamily(){
	int i,j,k,f,sum,c;
	double money=0;
	B b[200]={0};
	b[0].name="梅苑"; 
	b[1].name="兰苑"; 
	b[2].name="竹苑"; 
	b[3].name="菊苑"; 
	b[4].name="桃苑"; 
	b[5].name="李苑"; 
	b[6].name="柳苑"; 
	b[7].name="桂苑"; 
	b[8].name="南荷";
	b[9].name="北荷"; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          按家庭查询          \n\n");
	while(1){	
		printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t您想查几号家庭的信息？              ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t0.离开系统                          ┃\n");
		printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
		printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
		printf("\t\t\t\t\t\t\t\t\t\t 家庭:");
		i=-1;
		scanf("%d",&i);
		getchar();
		system("cls");
		while(i<0||i>n){
			system("cls");
			printf("\n\t\t输入错误，请重新输入\n");
			printf("\t\t~按家庭索引~\n\n");
			printf("\t\t您想要查询第几户？(1~%d)\n\n",n);
			printf("\t\t~按0返回上层菜单~\n\n");
			scanf("%d",&i);
		}
		if(i!=0){
			system("cls");
			printf("\n\n\n\t\t\t\t\t\t\t\t按家庭检索 第%d页\n\n",i);
			printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
			printf("\t\t\t\t\t|       |                |                |                |                |\n");
			printf("\t\t\t\t\t| 家庭  |2017年的总用电量|2018年的总用电量|2017年的总用电费|2018年的总用电费|\n");
			printf("\t\t\t\t\t|       |                |                |                |                |\n");
			for(f=0;f<n;f++){
				for(j=0;j<2;j++){
					for(k=0;k<12;k++){
						sum=f*24+j*12+k;
						if (f==i-1){
							if(j==0){
								b[i-1].ele+=a[sum].e;
								b[i-1].money+=a[sum].money;
							}
							else{
								b[i-1].pjele+=a[sum].e;
								b[i-1].pjm+=a[sum].money;
							} 
						}
					}
				}
			}
		}	
		else {
			if(sign==3){
				GM();
			}
			else search();
		}
		if(i<9){
			printf("\t\t\t\t\t|家庭00%d|",i) ;
		} 
		if(i>=9&&i<99){
			printf("\t\t\t\t\t|家庭0%d|",i) ;
		} 
		if(i>=99){
			printf("\t\t\t\t\t|家庭%d|",i) ;
		}
		printf("  %5d千瓦时   |  %5d千瓦时   | %12f元 | %12f元 |\n",b[i-1].ele,b[i-1].pjele,b[i-1].money,b[i-1].pjm);
		printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
		printf("\n\n\t\t\t\t\t是否查询精确到月的详细信息？");
		printf("\n\n\t\t\t\t\t1.需要  0.我要继续查别的家庭\n");
		c=-1;
		scanf("%d",&c);
		getchar();
		system("cls");
		while(c<0||c>1){
			printf("\n\t\t\t\t\t输入错误，请重新输入\n");
			printf("\n\n\t\t\t\t\t是否查询精确到月的详细信息？");
			printf("\n\n\t\t\t\t\t1.需要  0.我要继续查别的家庭\n");
			scanf("%d",&c);
			getchar();
		}
		if(c==1){
			Fdital (i);
		}
	}	
}

void Fdital (int i){
	// i为第i个家庭 
	int j,k,f,sum,m,c,e=0;
	double money=0;
	B b[12]={0};//此处b结构体代表月份 
	for(m=0;m<2;m++){
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\t\t家庭%d第%d年的详细信息\n\n",i,m+2017);
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
		printf("\t\t\t\t\t\t\t| 月份 | 峰时用电量 | 谷时用电量 |   上缴电费   |\n");
		printf("\t\t\t\t\t\t\t|------|------------|------------|--------------|\n");
		for(f=0;f<n;f++){
			for(j=0;j<2;j++){
				for(k=0;k<12;k++){
					sum=f*24+j*12+k;
					if(f==i-1&&j==m){
						printf("\t\t\t\t\t\t\t|%2d月份| %d千瓦时  | %3d千瓦时  | %10f元 |\n",k+1,a[sum].up,a[sum].down,a[sum].money);
						printf("\t\t\t\t\t\t\t|------|------------|------------|--------------|\n");
					}
				}
			}
		}
		if(m==0){
			printf("\t\t\t\t\t\t\t\t1.下一页\t\t 0.返回上层\n");
			scanf("%d",&c);
			getchar();
			while(c<0||c>1){
				printf("\n\t\t\t\t\t\t\t\t输入错误，请重新输入\n");
				c=-1;
				scanf("%d",&c);
				getchar();
			}
			switch(c){
				case 1:
					break;
				case 0:
					searchbyfamily();
					break;
				default:
					printf("无该选项，请重新选择\n");
			}
		}
		else{
			printf("\t\t\t\t\t\t\t\t最后一页了\t\t 0.返回上层\n");
			c=-1;
			scanf("%d",&c);
			getchar();
			while(c!=0){
				printf("\n\t\t\t\t\t\t\t\t输入错误，请重新输入\n");
				scanf("%d",&c);
				getchar();
			}
			switch(c){
				case 0:
					searchbyfamily();
					break;
				default:
					break;
			}
			system("cls");
		}
	}
}

void Seedata(){
	int c=1,f,j,k,sum;
	system("cls"); 
	printf("\n\n\n\n");
	//printf("\t\t1 具体查看每家详细用电信息\n\t\t0 返回上级菜单\n");
	while(1){		
		switch(c){ 
			case 1:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
				printf("\t\t\t\t\t\t\t\t\t\t          查询数据          \n\n");
				printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
				printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
				printf("\t\t\t\t\t\t\t\t\t┃\t您想查几号家庭几月几日的信息？      ┃\n");
				printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
				printf("\t\t\t\t\t\t\t\t\t┃\t家庭1~100，年2017~2018，月1~12      ┃\n");
				printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
				printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
				//printf("\t\t\t您想查几号家庭几月几日的信息？\n");
				//printf("\t家庭1~100，年2017~2018，月1~12\n") ;
				printf("\n\t\t\t\t\t\t\t\t\t家庭"); 
				scanf("%d",&f);
				printf("\n\t\t\t\t\t\t\t\t\t年"); 
				scanf("%d",&j);
				printf("\n\t\t\t\t\t\t\t\t\t月"); 
				scanf("%d",&k);
				getchar();
				printf("\n"); 
				while(f<0||f>100||j<2017||j>2018||k<0||k>12){
					printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
					printf("\t\t\t\t\t\t\t\t\t\t                          \n");
					printf("\t\t\t\t\t\t\t\t\t\t                          \n");
					printf("\t\t\t\t\t\t\t\t\t\t  数据输入有误          \n");
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");
					printf("\t\t\t\t\t\t\t\t\t  家庭1~%d，年2017~2018，月1~12              \n",n);
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
					printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
					scanf("%d%d%d",&f,&j,&k);				
				}
				j=j-2017;
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
				
				
				printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
				printf("\t\t\t\t\t\t\t\t\t\t                                    \n");
				if(f<9){
					printf("\t\t\t\t\t\t\t\t\t   家庭00%d在%d年%d月的记录如下\n\n",f,j+2017,k) ;
				} 
				if(f>=9&&f<99){
					printf("\t\t\t\t\t\t\t\t\t   家庭0%d在%d年%d月的记录如下\n\n",f,j+2017,k) ;
				} 
				if(f>=99){
					printf("\t\t\t\t\t\t\t\t\t   家庭%d在%d年%d月的记录如下\n\n",f,j+2017,k) ;
				}
				sum=f*24+j*12+k;
				switch(a[sum].place)
				{
					case 0: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：梅苑\n");
						break;
					case 1: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：兰苑\n");
						break;
					case 2: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：竹苑\n");
						break;
					case 3: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：菊苑\n");
						break;
					case 4: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：桃苑\n");
						break;
					case 5: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：李苑\n");
						break;
					case 6: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：柳苑\n");
						break;
					case 7: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：桂苑\n");
						break;
					case 8: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：南荷\n");
						break;
					case 9: 
						printf("\t\t\t\t\t\t\t\t\t\t   小区：北荷\n");
						break;		
				}
				printf("\t\t\t\t\t\t\t\t\t\t                          \n");
				printf("\t\t\t\t\t\t\t\t\t\t峰时用电%d千瓦时\n",a[sum].up);
				printf("\t\t\t\t\t\t\t\t\t\t                          \n");
				printf("\t\t\t\t\t\t\t\t\t\t谷时用电%d千瓦时\n",a[sum].down);
				printf("\t\t\t\t\t\t\t\t\t\t                          \n");
				printf("\t\t\t\t\t\t\t\t\t\t应交电费%f元\n",a[sum].money);
				printf("\t\t\t\t\t\t\t\t\t\t                         \n");
				printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
				printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
				break;
				
			case 0:
				system("cls");
				switch(sign){
					case 1:
						Look();
					case 2:
						Look();
					case 3:
						Look();
					case 4:
						Familytable();
				}
				return;
				break;
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}
		printf("\t\t\t\t\t\t\t\t\t\t  1 继续\n\n\t\t\t\t\t\t\t\t\t\t  0 返回\n");
		scanf("%d",&c);
		getchar(); 
		system("cls"); 
	}	
} 




void password1()
{
	int a,place=0,m,tag,o,n;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  用电统计员登录          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  请输入账号和密码              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(allusersa[place].label!=0)
		place++;
	//printf("\n\t\t人家是第%d个(#`O′)啦",place); 
	if(place==0)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t目前无用户");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t按0返回");
		 
		do
		{	
			a=getch();
			if(a==48)
			{
				load();
				//printf("\n\n\t\t嘤，其实我是上级菜单啦～");//此处为上级菜单函数 
				return;
			}
			else
				printf("\n\n\t\t\t\t\t\t\t\t\t\t输入有误\n"); 
		}while(a!=48);
	}
	
	//用户名部分 
	printf("\n\n\t\t\t\t\t\t\t\t\t\t请输入您的用户名：");
	do
	{
		char u[Lofuser]={0};
		o=prouser1(u,place);
		//printf("\n\t\t辣鸡o=%d\n",o); 
		m=o/10;
		//printf("\n\t\t辣鸡m=%d\n",m); 
		//scanf("%d",&o);
		tag=o%10;
		//printf("\n\t\t辣鸡tag=%d\n",tag);
	}while(m);
	printf("\n\t\t\t\t\t\t\t\t\t\t用户名存在,请输入密码:"); 
	
	//密码部分 
	do
	{
		char p[Lofpass]={0};
		n=propass1(p,place,tag);
	}while(n);
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t登陆成功！"); 
	return; 
}

int prouser1(char u[Lofuser],int n)
{
	//printf("\n\t\t○○辣鸡n=%d\n",n); 
	int k=0,j=0,t,sign=1;
	int judge[Allusers]={0};
	//输入；
	while(k<Lofuser)
	{
		u[k]=getchar();
		if(u[k]=='\n')
			break;
		k++;
	}
	u[k]='\0';
	for(k=0;u[k]!='\0';k++);
	for(j=0;j<n;j++)
	{
		for(t=0;t<k+1;t++)
		{
			if(allusersa[j].user[t]==u[t])
			{
				continue;
			}
			else
			{
				break;
			}
		}
		if(t==k+1)
		{
			sign=0;
			break;
		}

	}
	if(sign==1)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t用户名不存在，请重新输入:");
	} 
	return sign*10+j;
}

int propass1(char a[Lofpass],int n,int t)
{
	int k=0,j=0,sign=0;
	char c;
	while(k<Lofpass)
	{
		c=getch();
		if(c!=13)
		{
			a[k++]=c;
			putchar('*');				
		}
		if(c==13)
			break;
	}
	a[k]='\0';
	//printf("\n\n\t\t%s\n",p1);	

	for(j=0;j<Lofpass;j++)
	{
		if(a[j]!=allusersa[t].pass[j])
		{
			sign=1;
			printf("\n\n\t\t密码错误,请重新输入:");
			break;
		}
	}
	return sign;
}



void password2()
{
	int place=0,a=0,m,tag,o,n;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  供电系统工作人员登录          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  请输入账号和密码              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(allusersb[place].label!=0)
		place++;
	//printf("\n\t\t人家是第%d个(#`O′)啦",place); 
	if(place==0)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t目前无用户");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t按0返回");
		
		do
		{	
			a=getch();
			if(a==48)
			{
				load();//此处为上级菜单函数 
				return;
			}
			else
				printf("\n\n\t\t\t\t\t\t\t\t\t\t输入有误\n"); 
		}while(a!=48);
	}
	
	//用户名部分 
	printf("\n\n\t\t\t\t\t\t\t\t\t\t请输入您的用户名：");
	do
	{
		char u[Lofuser]={0};
		o=prouser2(u,place);
		//printf("\n\t\t辣鸡o=%d\n",o); 
		m=o/10;
		//printf("\n\t\t辣鸡m=%d\n",m); 
		//scanf("%d",&o);
		tag=o%10;
		//printf("\n\t\t辣鸡tag=%d\n",tag);
	}while(m);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t用户名存在,请输入密码:"); 
	
	//密码部分 
	do
	{
		char p[Lofpass]={0};
		n=propass2(p,place,tag);
	}while(n);
	printf("\n\n\n\t\t登陆成功！"); 
	return; 
}

int prouser2(char u[Lofuser],int n)
{
	//printf("\n\t\t○○辣鸡n=%d\n",n); 
	int k=0,j=0,t,judge[Allusers],sign=1;
	//输入；
	while(k<Lofuser)
	{
		u[k]=getchar();
		//scanf("%c",&u[k]);
		if(u[k]=='\n')
			break;
		k++;
	}
	u[k]='\0';
	//printf("\n\n\t\t%s\n",u); 
	//printf("\n\n\t\trua!想不到吧!"); 
	for(k=0;u[k]!='\0';k++);
	//printf("\n\t\t人家是第%d位(#`O′)啦",k);
	for(j=0;j<n;j++)
	{
		//printf("\n\t\t●辣鸡j=%d\n",j); 
		//int o=0;
		for(t=0;t<k+1;t++)
		{
			if(allusersa[j].user[t]==u[t])
			{
				//printf("\n\t去死吧嘤嘤怪！嘤%d嘤嘤\n",t);
				continue;
			}
			else
			{
				//o=1;
				break;
			}
			//printf("\n\t去死吧嘤嘤怪！嘤%d嘤嘤\n",t);
		}
		//printf("\n\t为什么t=%d嘤嘤",t);
		if(t==k+1)
		{
			//printf("j=%d\n",j);
			//printf("\n\t\t哈哈哈哈哈哈我进来啦！"); 
			sign=0;
			//printf("\n\t为什么t=%dsdfghjklhg  k=%d  fdsdfghjkl",t,k);
			//printf("\n00000想不到我会出现吧！");
			break;
		}

	}
	//printf("\n\t呜呜呜呜%d噫呜呜噫",j);
	//printf("rua！");
	if(sign==1)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t用户名不存在，请重新输入:");
	} 
	return sign*10+j;
}

int propass2(char a[Lofpass],int n,int t)
{
	int k=0,j=0,sign=0;
	char c;
	while(k<Lofpass)
	{
		c=getch();
		if(c!=13)
		{
			a[k++]=c;
			putchar('*');				
		}
		if(c==13)
			break;
	}
	a[k]='\0';
	//printf("\n\n\t\t%s\n",p1);	

	for(j=0;j<Lofpass;j++)
	{
		if(a[j]!=allusersa[t].pass[j])
		{
			sign=1;
			printf("\n\n\t\t密码错误,请重新输入:");
			break;
		}
	}
	return sign;
}


void password3(){
	int i=0,n=0;
	char *pass=NULL;
	int count;
	time_t start,end;
	pass=(char *)malloc(10*sizeof(char));
	while(1)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
		printf("\t\t\t\t\t\t\t\t\t\t                          \n");
		printf("\t\t\t\t\t\t\t\t\t\t                          \n");
		printf("\t\t\t\t\t\t\t\t\t\t  管理员登录          \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");
		printf("\t\t\t\t\t\t\t\t\t\t  请输入密码              \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
		printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
		for(i=0;i<3;i++)
		{	
			count=0;
			while((count<=10)&&(pass[count++]=getch())!=13)
				putchar('*');
			pass[--count]='\0';
			if(!strcmp(pass,"123456"))
			{
				GM();
			}
			free(pass);
			pass=(char *)malloc(10*sizeof(char));
			system("cls");
			printf("\n\n\t\t\t\t\t\t\t\t\t\t密码错误！\n\n");
			printf("\n\n\t\t\t\t\t\t\t\t\t\t");
			printf("请再次输入密码:");
		}
		system("cls"); 
		 
	}
}


void Add(){
	int c=-1;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          注册用户          \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t1.注册用电统计员                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t2.注册供电公司工作人员              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t0.返回                              ┃\n");
	printf("\t\t\t\t\t\t\t\t\t┃\t                                    ┃\n");			
	printf("\t\t\t\t\t\t\t\t\t●==========================================●\n");
	while(1){
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				newusera();
				break;
			case 2:
				newuserb();
				break; 
			case 0:	
				GM();		
				break;
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n"); 
		}
	}	
}

void Del(){
	
}

void Look(){
	int c=-1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     查询                     \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.查看数据          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.查看表格              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  3.定向检索              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开系统              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n"); 
	while(1){
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				Seedata(); 
				break;
			case 2:
				Table(); 
				break; 
			case 3:
				search(); 
				break; 
			case 0:	
				switch(sign){
					case 1:
						staff1();
						break;
					case 2:
						staff2();
						break;
					case 3:
						GM();
						break;
				}
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}
	}		 
}

void Analysis(){
	int c;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     分析数据                     \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.拟扩容小区模拟       \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开系统             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(1){
		c=-1;
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				kr(); 
				break;
			/*case 2:
				Table(); 
				break; 
			case 3:
				search(); 
				break; */
			case 0:	
				switch(sign){
					case 1:
						staff1();
						break;
					case 2:
						staff2();
						break;
					case 3:
						GM();
						break;
				}
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}
	}	
} 
void Change(){
	int c;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     修改数据                     \n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.生成随机原始数据     \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.修改现有数据         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开系统             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	while(1){
		c=-1;
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				GetPreData(); 
				break;
			case 2:
				Revise(); 
				break; 
			/*case 3:
				search(); 
				break;*/ 
			case 0:	
				switch(sign){
					case 1:
						staff1();
						break;
					case 2:
						staff2();
						break;
					case 3:
						GM();
						break;
				}
			default:
				printf("\t\t\t\t\t\t\t\t\t\t无该选项，请重新选择\n");
		}
	}
}
void PlaySoundF()
{
	int c;
    /*for(;;)
    {
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t~播放菜单~\n\n");
        printf("\t\t1.曲目列表\n\n");
        printf("\t\t2.停止播放\n\n");
        printf("\t\t0.返回上级\n\n");
        printf("\t 请选择:");


        scanf("%d",&c);
		switch(c){
			case 1:
           
                playlist();
		break;
			case 2:
                PlaySound(NULL, 0, SND_FILENAME|SND_ASYNC);
                break;
            case 0:
			default:
				printf("无该选项，请重新选择");
		}
    }*/
} 

void playlist()
{
	int c;
    /*for(;;)
    {
        system("cls");
        printf("\n\n\n\n");
        printf("\t\t1.特典01.千年幻想交响祭\n\n");
        printf("\t\t2.特典02.科学世纪的少年少女\n\n");
        printf("\t\t0.返回上级\n\n");
        printf("\t 请选择:");


        scanf("%d",&c);
		switch(c){
			case 1:
                PlaySound(TEXT("改一下曲子"), NULL, SND_FILENAME| SND_ASYNC);
				break;
			case 2:
                PlaySound(TEXT("el.wav"), NULL, SND_FILENAME| SND_ASYNC);
                break;
            case 0:
			default:
				printf("无该选项，请重新选择");
		}
    }*/
}

void Revise(){
	int c;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.用户登录界面          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.系统设置              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.离开系统              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t●==============================●\n");
}
