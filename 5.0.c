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
	int place;   //�ݶ�10��     ÷�����   ��������  �Ϻ� ���� 
	int family;
	int year;
	int month;
	int up;   //��ʱ�õ��� 
	int down; //��ʱ�õ��� 
	int e;//�ܵ��� 
	double money; 
};
struct B {             //С�� 
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
void password1(); //�ⲿ������������ͩд��Ȼ���Ҹ��˸�����
void password2(); //�ⲿ������������ͩд�� 
void password3(); //�ⲿ������������ͩд��Ȼ���Ҹ��˸�����


/*����Ϊ����ͩ�Ĵ���*/





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
void load();   //�û���¼���� 
void option(); //ϵͳ���ý��� 
void PlaySoundF();	//��˼�ѵĴ��� 
void playlist();    //��˼�ѵĴ��� 
void changecolour();//��˼�ѵĴ��� 
void GM();//����Աͨ�� 
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
	srand((unsigned) time(NULL)); //��ʱ�����֣�ÿ�β����������һ��
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
			printf("һ\n");
			fp=fopen("users1.dat","rb");
			fread(&allusersa,sizeof(allusersa),1,fp); 
			fclose(fp);
			//printf("\t\t\t�˻�   �û���   ����\n"); 
			//printf("\t\t���������%d   %s   %s\n",allusersa[0].label,allusersa[0].user,allusersa[0].pass);
			break;
		case 2:
			printf("��\n");
			fp=fopen("users2.dat","rb");
			fread(&allusersb,sizeof(allusersb),1,fp); 
			fclose(fp);
			//printf("\t\t\t�˻�   �û���   ����\n");
			//printf("\t\t���������%d   %s   %s\n",allusersa[0].label,allusersa[0].user,allusersa[0].pass);
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
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.�û���¼����          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.ϵͳ����              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪ϵͳ              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	while(1){ 
	    c=-1;//����Ӧ��������ĸ���ַ������ 
		scanf("%d",&c);
		/*�ص㣡����*/
		getchar();//�о�һ����ĳɹ�QAQ
		  /*���getchar()���ƺ����ô���ʵ����ȴ��һ���ؼ��㣬���û�����getchar,���û�
		  ����һ����ĸ��ʱ����������ֱ�ӽ�����ѭ�� 
			������ﲻ�����getchar,����һ����ĸ a��scanf������Ϊ%d��Ե�ʣ��Ὣ��ĸ�ͻػ�����
			Ȼ��ͻ����������ѭ��ѭ����
			 1.scanf("%d",&c)����һ����ĸ��������Ҫ�󣬽���ĸ�ͻػ�����
			 2.����switch��Ȼ���ȥ
			 3,���µ� scanf("%d",&c)������֮ǰ���ڻ�������  a
			 4������ѭ��
			 �������getchar ֮��֮ǰ���ڻ�������� a �ᱻgetchar����������ѭ��
			 ��������Ӹ�getchar,������ĸ�Ͳ��ᱨ���ˡ��������� */	
		switch(c){
			case 1:
				load();
				break;
			case 2:
				option(); 
			case 0:
				exit(0);
			default:
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
		}		
	}
	
	return;
}

void load (){
	int c; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.�õ�ͳ��Ա          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.���繫˾������Ա             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  3.����Ա             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
		}
		getchar();
	}
	
	return;
}

void option (){
	int c;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          ѡ��          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t1.ѡ����ɫ                          ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t2.ѡ�񱳾�����                      ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.����                              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n"); 
		}
	}	
	return;
}

void changecolour(){
	int c; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t        ��ɫ����������          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t1.���Ÿ��    �ҵ׺���              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t2.������Ƥ    �׵�����              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t3.ˮ������    �׵�����              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t4.�ഺ����    �ϵ׺���              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t5.���м���    �Ƶ�����              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.����                              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");	
	while(1){
		c=-1;
		scanf("%d",&c);
		getchar();
		while(c<0||c>5){ 
			printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
		}
		printf("\t\t\t\t\t\t\t\t\t\t���Լ�������������ɫ�������ϲ��밴0\n");
	}
}

void GM(){
	int c;
	sign=3;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     ����Ա          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.ע���û�             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.��ѯ����             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  3.�޸�����             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  4.���ݷ���             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪ϵͳ             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
				printf("�޸�ѡ�������ѡ��"); 
		}
	}
} 








void GetPreData(){
	int i=0,j=0,k=0,f=0,sum=0,number=0,c=0;  
	system("cls") ;
	srand((unsigned) time(NULL)); //��ʱ�����֣�ÿ�β����������һ��
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          ���ɳ�ʼ����          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t�������ɼ����˼ҵ����ݣ�            ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t��100����200��֮�� ��               ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.�뿪ϵͳ                          ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");			
	number=-1;
	scanf("%d",&number); 
	getchar(); 
	while(number<100||number>200){
		printf("\t\t\t\t\t\t\t\t\t\t������������\n\t\t\t\t\t\t\t\t\t\t������100��200֮�����\n");
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
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t��ʼ�����������                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.�뿪ϵͳ                          ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");	
	c=-1;
	scanf("%d",&c) ;
	getchar();
	if(c!=0){
		printf("\t\t\t\t\t\t\t\t\t\t��������\n");
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
	b[0].name="÷Է"; 
	b[1].name="��Է"; 
	b[2].name="��Է"; 
	b[3].name="��Է"; 
	b[4].name="��Է"; 
	b[5].name="��Է"; 
	b[6].name="��Է"; 
	b[7].name="��Է"; 
	b[8].name="�Ϻ�";
	b[9].name="����"; 
	//printf("%s",b[1].name);
	while(1){
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
		printf("\t\t\t\t\t\t\t\t\t\t      ��ѯ����          \n\n");
		printf("\t\t\t\t\t\t\t\t\t��================================��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                          ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t1.��ͥͳ�Ʊ�              ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                          ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t2.С��ͳ�Ʊ�              ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                          ��\n");	
		printf("\t\t\t\t\t\t\t\t\t��\t0.����                    ��\n");	
		printf("\t\t\t\t\t\t\t\t\t��\t                          ��\n");		
		printf("\t\t\t\t\t\t\t\t\t��================================��\n");
		c=-1;
		scanf("%d",&c);
		getchar();
		switch(c){
			case 1:
				Familytable();
				break;
			case 2:
				system("cls");
				printf("\t\t\t\t\t\t\t\t\t\t\tС��ͳ�Ʊ�\n");
				printf("\n\n\n");
				printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
				printf("\t\t\t\t\t| С�� | 2017������õ��� | 2018������õ��� | һ�껧���õ��� | 2017������õ�� | 2018������õ�� | һ�껧���õ�� |\n");
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
					printf("\t\t\t\t\t| %s |   %5dǧ��ʱ    |   %5dǧ��ʱ    |   %5dǧ��ʱ  |  %12fԪ  |  %12fԪ  | %12fԪ |\n",b[i].name,b[i].ele,b[i].pjele,(b[i].ele+b[i].pjele)/b[i].n,b[i].money,b[i].pjm,b[i].money+b[i].pjm/b[i].n);
					printf("\t\t\t\t\t|      |\t\t  |  \t\t     |\t\t      |\t\t         |\t\t    |\t\t     |\n");
				}
				printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
				printf("\n\n\n");
				/*printf("\tС��  2017������õ��   2018������õ��    һ�껧���õ��\n");
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
					printf("\t%s  %12fԪ      %12fԪ     %12fԪ\n",b[i].name,b[i].money,b[i].pjm,b[i].money+b[i].pjm/b[i].n);
				}
				printf("\n\n\n");*/
				printf("\n\n\t\t\t\t\t\t\t\t 0 �����ϲ�\n\n");
				while(1){
					scanf("%d",&c);
					if(c==0){
						system("cls");
						Look();
					}	
					printf("\n\n\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��"); 
					getchar();
				} 
				break;
			case 0:
				system("cls");
				Look();
			default:
				printf("\n\n\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n"); 
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
	b[0].name="÷Է"; 
	b[1].name="��Է"; 
	b[2].name="��Է"; 
	b[3].name="��Է"; 
	b[4].name="��Է"; 
	b[5].name="��Է"; 
	b[6].name="��Է"; 
	b[7].name="��Է"; 
	b[8].name="�Ϻ�";
	b[9].name="����"; 
	system("cls");
	
	for(i=1;i<=20;i++){
		printf("\n\n\n\t\t\t\t\t\t\t\t\t\t\t��ͥͳ�Ʊ� ��%dҳ\n\n",i);
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
		printf("\t\t\t\t\t\t\t|��ͥ���| 2017������õ��� | 2017������õ�� | 2018������õ��� | 2018������õ�� |\n");
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
								printf("\t\t\t\t\t\t\t|��ͥ00%d |",f+1);
							}
							else{
								if(f<99){
									printf("\t\t\t\t\t\t\t|��ͥ0%d |",f+1);
								}
								else printf("\t\t\t\t\t\t\t|��ͥ%d |",f+1);
							}
						} 
						if(j==0&&k==11)printf("    %dǧ��ʱ    |",e);
						if(j==1&&k==11)printf("    %dǧ��ʱ    |",e);
						if(j==0&&k==11)printf("   %fԪ  |",money);
						if(j==1&&k==11)printf("   %fԪ  |\n",money);
					}
				}
			}
			printf("\t\t\t\t\t\t\t|        |\t\t    |\t\t       |\t\t  |\t\t     |\n");
		}
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
		if(f<n){
			printf("\n\n\t\t\t\t\t\t\t\t\t1.��һҳ\t\t2.�鿴��ϸ����\t\t0.�����ϲ�\n");
			scanf("%c",&c);
			getchar();
			while(c!=50&&c!=48&&c!=49) {
				printf("\n\n\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��");
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
			printf("\n\n\t\t\t\t\t\t\t\t\tû����һҳ��\t\t2.�鿴��ϸ����\t\t0.�����ϲ�\n");
			scanf("%c",&c);
			getchar();
			while(c!=50&&c!=48) {
				printf("\n\n\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��");
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
					printf("\n\n\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��"); 
			}
		} 
		
	}
	
	printf("\n\n\n");
	/*printf("\t��ͥ  2017������õ��  2018������õ��  \n");
	for(f=0;f<n;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f+j+k; 
				if(k==0)money=0;
				money+=a[sum].money;
				if(j==0&&k==0)printf("\t��ͥ%d",f+1);
				if(j==0&&k==11)printf("\t%.4fԪ   ",money);
				if(j==1&&k==11)printf("\t  %.4fԪ   \n",money);
				
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
	b[0].name="÷Է"; 
	b[1].name="��Է"; 
	b[2].name="��Է"; 
	b[3].name="��Է"; 
	b[4].name="��Է"; 
	b[5].name="��Է"; 
	b[6].name="��Է"; 
	b[7].name="��Է"; 
	b[8].name="�Ϻ�";
	b[9].name="����"; 
	printf("\t\t\t~����ϵͳ~\n\n");
	printf("\t\tС��ͳ�Ʊ�\n");
	printf("\tС��     ���õ��         ���õ���       �����õ��     �����õ���   ������\n\n");
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
		printf("\t%s   %12fԪ    %6dǧ��ʱ   %fԪ   %dǧ��ʱ    %d��\n\n",b[i].name,b[i].money,b[i].ele,b[i].pjm,b[i].pjele,b[i].n);
	}
	printf("\n\n\n");
	while(1){
		printf("\t���ܵ��������밴1\n\t���ܵ�������밴2\n\t��ƽ�����������밴3\n\t��ƽ����������밴4\n\t�����ϼ��˵��밴0\n\n\n");
		scanf("%d",&c);
		switch(c){
			case 1:
				max=0;
				system("cls");
				printf("\t\t\t���ܵ�������\n\n\tС��         ���õ��         ���õ���      �����õ��      �����õ���      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].ele<b[j].ele){
							max=j;
						}
					}
					printf("\t%s   %15fԪ    %6dǧ��ʱ   %fԪ   %5dǧ��ʱ    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
					b[max].ele=0; 
					max=0;
				}
				break;
			case 2:
				max=0;
				system("cls");
				printf("\t\t\t���ܵ������\n\n\tС��         ���õ��         ���õ���      �����õ��      �����õ���      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].money<b[j].money	){
							max=j;
						}
					}
					printf("\t%s   %15fԪ    %6dǧ��ʱ   %fԪ   %5dǧ��ʱ    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
					b[max].money=0; 
					max=0;
				}
				break;
			case 3:
				max=0;
				system("cls");
				printf("\t\t\t��ƽ����������\n\n\tС��         ���õ��         ���õ���      �����õ��      �����õ���      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].pjele	<b[j].pjele	){
							max=j;
						}
					}
					printf("\t%s   %15fԪ    %6dǧ��ʱ   %fԪ   %5dǧ��ʱ    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
					b[max].pjele=0; 
					max=0;
				}
				break;
			case 4:
				max=0;
				system("cls");
				printf("\t\t\t��ƽ���������\n\n\tС��         ���õ��         ���õ���      �����õ��      �����õ���      \n\n");
				for(k=0;k<=9;k++){
					for(j=0;j<=9;j++){
						if(b[max].pjm	<b[j].pjm	){
							max=j;
						}
					}
					printf("\t%s   %15fԪ    %6dǧ��ʱ   %fԪ   %5dǧ��ʱ    \n\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
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
				printf("�޸�ѡ�������ѡ��\n");
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
	b[0].name="÷Է"; 
	b[1].name="��Է"; 
	b[2].name="��Է"; 
	b[3].name="��Է"; 
	b[4].name="��Է"; 
	b[5].name="��Է"; 
	b[6].name="��Է"; 
	b[7].name="��Է"; 
	b[8].name="�Ϻ�";
	b[9].name="����"; 
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
			printf("\t\t\t\t\t\t\t\t\t\t          ����С��ģ��          \n\n");
			printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t����ж���ЩС����Ҫ���ݣ�          ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t1���õ�������С��                 ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t2�ܹ����������С��               ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t3ƽ���õ�������С��               ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t4ƽ�����������С��               ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t0����                               ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
			printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
			scanf("%d",&c);
			getchar();
			switch(c){
				case 1:
					printf("\n\t\t\t\t\t\t\t\t\t\t�����δ������ݼ���С����\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t��������ѡ�����ǽ�ѡ�����õ�������ǰ%d��С������Ϊ���ݵĶ���\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t���������õ�������ǰ��С��������\n\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| С�� |    ���õ��    |   ���õ���   |   �����õ��   |  �����õ���  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].ele<b[j].ele){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12fԪ | %6dǧ��ʱ | %12fԪ |  %5dǧ��ʱ |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
						if(k!=x-1)printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
						b[max].ele=0; 
						max=0;
					}
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\n\t\t\t\t\t\t\t\t\t\t�����Ƽ�������");
					for(i=0;i<x;i++){
						printf("%s",b[px[i]].name);
						if(i!=x){
							printf("��");
						}
					} 
					printf("��%d��С��\n\n",x);
			 		break;
				case 2:
					printf("\n\t\t\t\t\t\t\t\t\t\t�����δ������ݼ���С����\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t��������ѡ�����ǽ�ѡ���ܹ����������ǰ%d��С������Ϊ���ݵĶ���\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t�������ܹ������ǰ%d����С��������\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| С�� |    ���õ��    |   ���õ���   |   �����õ��   |  �����õ���  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].money<b[j].money	){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12fԪ | %6dǧ��ʱ | %12fԪ |  %5dǧ��ʱ |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
						if(k!=x-1)printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
						b[max].ele=0; 
						max=0;
					}
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\n\t\t\t\t\t\t\t\t\t\t�����Ƽ�������");
					for(i=0;i<x;i++){
						printf("%s",b[px[i]].name);
						if(i!=x){
							printf("��");
						}
					} 
					printf("��%d��С��\n\n",x);
					break;
				case 3:
					printf("\n\t\t\t\t\t\t\t\t\t\t�����δ������ݼ���С����\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t��������ѡ�����ǽ�ѡ��ƽ���õ�������ǰ%d��С������Ϊ���ݵĶ���\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t������ƽ���õ���ǰ%d����С��������\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| С�� |    ���õ��    |   ���õ���   |   �����õ��   |  �����õ���  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].pjele<b[j].pjele){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12fԪ | %6dǧ��ʱ | %12fԪ |  %5dǧ��ʱ |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
						if(k!=x-1)printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
						b[max].pjele=0; 
						max=0;
					}
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\n\t\t\t\t\t\t\t\t\t\t�����Ƽ�������");
					for(i=0;i<x;i++){
						printf("%s",b[px[i]].name);
						if(i!=x){
							printf("��");
						}
					} 
					printf("��%d��С��\n\n",x);
					break;
				case 4:
					printf("\n\t\t\t\t\t\t\t\t\t\t�����δ������ݼ���С����\n\n");
					scanf("%d",&x);
					getchar(); 
					system("cls");
					printf("\n\n\t\t\t\t\t\t\t\t��������ѡ�����ǽ�ѡ��ƽ�����������ǰ%d��С������Ϊ���ݵĶ���\n\n",x); 
					max=0;
					printf("\t\t\t\t\t\t\t\t\t\t������ƽ�������ǰ%d����С��������\n\n");
					printf("\t\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
					printf("\t\t\t\t\t\t\t\t| С�� |    ���õ��    |   ���õ���   |   �����õ��   |  �����õ���  |\n");
					printf("\t\t\t\t\t\t\t\t|------|----------------|--------------|----------------|--------------|\n");
					for(k=0;k<x;k++){
						for(j=0;j<=9;j++){
							if(b[max].pjm<b[j].pjm){
								max=j;
							}
							px[k]=max;
						}
						printf("\t\t\t\t\t\t\t\t| %s | %12fԪ | %6dǧ��ʱ | %12fԪ |  %5dǧ��ʱ |\n",b[max].name,b[max].money,b[max].ele,b[max].money/b[max].n,b[max].ele/b[max].n);
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
void newusera()  //����ͩ�Ĵ��� 
 {
	int place=0;
	int m;
	int n;
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t��ӭע�����õ�ͳ��Ա\n\n\n\n");
	while(allusersa[place].label!=0)
		place++;
	//�û������� 
	printf("\n\n\t\t�������û�����");	
	do
	{
		char u[Lofuser]={0};
		m=checkusera(u,place);
	}while(m);
	printf("\n\t\t���û�������ʹ��,����������:"); 
	
	//���벿�� 
	do
	{
		char p1[Lofpass]={0},p2[Lofpass]={0};
		n=checkpassa(p1,p2,place);
	}while(n);
	printf("\n\n\n\t\tע��ɹ������Ի�ȥ��¼��w��"); 
	printf("\n\n\n\t\t��0�����ϼ��˵�Ŷ��");
{
	int a;
	do
	{	
		scanf("%d",&a); //�����Ҹ����£���Ȼ�п��ܻ����س� 
		//a=getch();      //ԭ���Ĵ��� 
		if(a==0)
			GM(); //�ҽ��е��ν� 
			//printf("\n\n\t\t�ӣ���ʵ�����ϼ��˵�����");//�˴�Ϊ�ϼ��˵�����            //ԭ���Ĵ��� 
		else
			printf("\n\n\t\t��Ƥ����˵�˰�0����"); 
	}while(a!=48);
	//�˴������ϼ��˵�
	return; 
}
}

void newuserb()  //����ͩ�Ĵ��� 
 {
	int place=0;
	int m;
	int n;
	system("cls");
	printf("\n\n\n\n");
	printf("\t\t\t��ӭע�ṩ��ϵͳ\n\n\n\n");
	while(allusersb[place].label!=0)
		place++;
	//�û������� 
	printf("\n\n\t\t�������û�����");	
	do
	{
		char u[Lofuser]={0};
		m=checkuserb(u,place);
	}while(m);
	printf("\n\t\t���û�������ʹ��,����������:"); 
	
	//���벿�� 
	do
	{
		char p1[Lofpass]={0},p2[Lofpass]={0};
		n=checkpassb(p1,p2,place);
	}while(n);
	printf("\n\n\n\t\tע��ɹ������Ի�ȥ��¼��w��"); 
	printf("\n\n\n\t\t��0�����ϼ��˵�Ŷ��");
{
	int a;
	do
	{	
		scanf("%d",&a); //�����Ҹ����£���Ȼ�п��ܻ����س� 
		//a=getch();      //ԭ���Ĵ��� 
		if(a==0)
			GM(); //�ҽ��е��ν� 
			//printf("\n\n\t\t�ӣ���ʵ�����ϼ��˵�����");//�˴�Ϊ�ϼ��˵�����            //ԭ���Ĵ��� 
		else
			printf("\n\n\t\t��Ƥ����˵�˰�0����"); 
	}while(a!=48);
	//�˴������ϼ��˵�
	return; 
}
}

int checkusera(char u[Lofuser],int n)//����ͩ�Ĵ��� 
{
	int k=0,j=0,t=0,judge[Allusers],sign=0;
	//���룻
	getchar();//������Һ�����ӵ� ,��Ȼ��������� 
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
	//printf("rua!�벻����!"); 
	//�ж��Ƿ���ȣ��������������
	//printf("\n\n\t\trua!�벻����!"); 
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
				printf("\t\t�û����ظ�,����������:");
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

int checkpassa(char a[Lofpass],char b[Lofpass],int n)  //����ͩ�Ĵ��� 
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
	printf("\n\t\t��ȷ����������:");
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
			printf("\n\n\t\t�������벻һ��,����������:");
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


int checkuserb(char u[Lofuser],int n)//����ͩ�Ĵ��� 
{
	int k=0,j=0,t=0,judge[Allusers],sign=0;
	//���룻
	getchar();//������Һ�����ӵ� ,��Ȼ��������� 
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
	//printf("rua!�벻����!"); 
	//�ж��Ƿ���ȣ��������������
	//printf("\n\n\t\trua!�벻����!"); 
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
				printf("\t\t�û����ظ�,����������:");
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

int checkpassb(char a[Lofpass],char b[Lofpass],int n)  //����ͩ�Ĵ��� 
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
	printf("\n\t\t��ȷ����������:");
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
			printf("\n\n\t\t�������벻һ��,����������:");
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
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.�û���¼����          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.ϵͳ����              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪ϵͳ              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	
	
	
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          ��ѯ����          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t����鼸�ż�ͥ���¼��յ���Ϣ��      ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t��ͥ1~100����2017~2018����1~12      ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.�뿪ϵͳ                          ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
				break;
		}
	}
}
void staff2() //��¼���� 
{
	int c; 
	sign=2;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t  ���繫˾ͳ��Ա          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.��ѯ����             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.���ݷ���             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.����                 \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
				printf("�޸�ѡ�������ѡ��\n");
		}
	}
	return ;
}
void staff1(){
	int c=-1; 
	sign=1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t  �õ�ͳ��Ա          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.��ѯ����                  \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.�޸�����                \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.����                  \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
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
	printf("\t\t\t\t\t\t\t\t\t\t          ��Ҫ���ѯ          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t1.����С����ѯ                      ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t2.�����û���ѯ                      ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.����                              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
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
				printf("\n\n\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n"); 
				break;
		}
	}
	return ;
}
	
void searchbyplace(){
	int i,j,k,f,sum,c;
	double money=0;
	B b[10]={0};
	b[0].name="÷Է"; 
	b[1].name="��Է"; 
	b[2].name="��Է"; 
	b[3].name="��Է"; 
	b[4].name="��Է"; 
	b[5].name="��Է"; 
	b[6].name="��Է"; 
	b[7].name="��Է"; 
	b[8].name="�Ϻ�";
	b[9].name="����"; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          ����С����ѯ          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t1.÷Է 2.��Է 3.��Է 4.��Է         ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t5.��Է 6.��Է 7.��Է 8.��Է         ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t9.�Ϻ�        10.����               ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.�뿪ϵͳ                          ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	while(1){
		i=-1;
		scanf("%d",&i);
		getchar();
		while(i<0||i>10){
			printf("\n\t\t\t\t\t\t\t\t\t�����������������\n");
			printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t1.÷Է 2.��Է 3.��Է 4.��Է         ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t5.��Է 6.��Է 7.��Է 8.��Է         ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t9.�Ϻ�        10.����               ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t0.�뿪ϵͳ                          ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
			printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
			scanf("%d",&i);
			getchar();
		}
		if(i!=0){
			system("cls");
			printf("\n\n\n\t\t\t\t\t\t\t\t\t\t��С������ ��%dҳ\n\n",i);
			printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n");
			printf("\t\t\t\t\t|      |                |                |              |                |                |              |\n");
			printf("\t\t\t\t\t| С�� |2017������õ���|2018������õ���|һ�껧���õ���|2017������õ��|2018������õ��|һ�껧���õ��|\n");
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
		printf("\t\t\t\t\t| %s |   %5dǧ��ʱ  |   %5dǧ��ʱ  | %5dǧ��ʱ  | %12fԪ | %12fԪ |%12fԪ|\n",b[i-1].name,b[i-1].ele,b[i-1].pjele,(b[i-1].ele+b[i-1].pjele)/b[i-1].n,b[i-1].money,b[i-1].pjm,b[i-1].money+b[i-1].pjm/b[i-1].n);
		printf("\t\t\t\t\t|      |                |                |              |                |                |              |\n");
		printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\n");
		printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t1.�鿴��ϸ��Ϣ                      ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t0.����                              ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
		printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
		c=-1;
		scanf("%d",&c);
		getchar();
		system("cls");
		while(c<0||c>1){
			system("cls"); 
			printf("\n\t\t�����������������\n");
			printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t1.�鿴��ϸ��Ϣ                      ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t0.����                              ��\n");
			printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
			printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
			scanf("%d",&c);
			getchar();
		}
		if(c==1){
			Pdital (i);
		}
	}
	//printf("\t %s   %5dǧ��ʱ       %5dǧ��ʱ      %5dǧ��ʱ       %12fԪ      %12fԪ     %12fԪ\n",b[i].name,b[i].ele,b[i].pjele,(b[i].ele+b[i].pjele)/b[i].n,b[i].money,b[i].pjm,b[i].money+b[i].pjm/b[i].n);
} 

void Pdital (int i){                   // iΪ��i��С�� 
	int j,k,f,sum,m,month,c=-1;
	double money=0;
	B b[10]={0};
	i=i-1  ;                  //�����е������Ǵ� 0��ʼ�ģ�����Ҫ��һ 
	//B month[12]={0};
	
	b[0].name="÷Է"; 
	b[1].name="��Է"; 
	b[2].name="��Է"; 
	b[3].name="��Է"; 
	b[4].name="��Է"; 
	b[5].name="��Է"; 
	b[6].name="��Է"; 
	b[7].name="��Է"; 
	b[8].name="�Ϻ�";
	b[9].name="����"; 
	/*      ���㻧����       */
	for(f=0;f<n;f++){
		for(j=0;j<2;j++){
			for(k=0;k<12;k++){
				sum=f*24+j*12+k;
				if(a[sum].place==i&&j==0&&k==0)b[i].n++;
			}
		}
	}
	for(m=0;m<2;m++){  //mΪҳ����m=1ʱΪ��һҳ����һ������� 
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\t\tС��%s��%d�����ϸ��Ϣ\n\n",b[i].name,m+2017);
		printf("\t\t\t\t\t\t\t\t\tС��%s����%d���˼�\n\n",b[i].name,b[i].n);
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
		printf("\t\t\t\t\t\t\t|�·�|   �õ���   |   �Ͻɵ��  | �����õ��� | �����õ�� |\n");
		printf("\t\t\t\t\t\t\t|----|------------|-------------|------------|------------|\n");
		for(month=0;month<12;month++){  //��Ϊ�ҵĽṹ�������С���޹أ�����ÿ���¶�Ҫ����ִ��һ��ѭ�� 
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
			//      printf("\t\t�·�\t�õ���\�Ͻɵ��\t�����õ���\t�����õ��\n\n");
			printf("\t\t\t\t\t\t\t|%2d��| %4dǧ��ʱ | %9.4fԪ | %4dǧ��ʱ |%9.4fԪ |\n",month+1,b[i].ele,b[i].money,b[i].pjele,b[i].pjm);
			if(month!=11){
				printf("\t\t\t\t\t\t\t|----|------------|-------------|------------|------------|\n");
			}
			else{
				printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
			}
		}
		if(m==0){
			printf("\t\t\t\t\t\t\t\t\t1.��һҳ\t\t 0.�����ϲ�\n");
			c=-1;
			scanf("%d",&c);
			getchar();	
			while(c<0||c>1){
				printf("\n\t\t\t\t\t\t\t\t\t�����������������\n");
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
					printf("\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
			}
		}
		else{
			printf("\t\t\t\t\t\t\t\t\t���һҳ��\t\t 0.�����ϲ�\n");
			c=-1;
			scanf("%d",&c);
			getchar();
			while(c!=0){
				printf("\n\t\t\t\t\t\t\t\t\t�����������������\n");
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
	b[0].name="÷Է"; 
	b[1].name="��Է"; 
	b[2].name="��Է"; 
	b[3].name="��Է"; 
	b[4].name="��Է"; 
	b[5].name="��Է"; 
	b[6].name="��Է"; 
	b[7].name="��Է"; 
	b[8].name="�Ϻ�";
	b[9].name="����"; 
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          ����ͥ��ѯ          \n\n");
	while(1){	
		printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t����鼸�ż�ͥ����Ϣ��              ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t0.�뿪ϵͳ                          ��\n");
		printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
		printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
		printf("\t\t\t\t\t\t\t\t\t\t ��ͥ:");
		i=-1;
		scanf("%d",&i);
		getchar();
		system("cls");
		while(i<0||i>n){
			system("cls");
			printf("\n\t\t�����������������\n");
			printf("\t\t~����ͥ����~\n\n");
			printf("\t\t����Ҫ��ѯ�ڼ�����(1~%d)\n\n",n);
			printf("\t\t~��0�����ϲ�˵�~\n\n");
			scanf("%d",&i);
		}
		if(i!=0){
			system("cls");
			printf("\n\n\n\t\t\t\t\t\t\t\t����ͥ���� ��%dҳ\n\n",i);
			printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
			printf("\t\t\t\t\t|       |                |                |                |                |\n");
			printf("\t\t\t\t\t| ��ͥ  |2017������õ���|2018������õ���|2017������õ��|2018������õ��|\n");
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
			printf("\t\t\t\t\t|��ͥ00%d|",i) ;
		} 
		if(i>=9&&i<99){
			printf("\t\t\t\t\t|��ͥ0%d|",i) ;
		} 
		if(i>=99){
			printf("\t\t\t\t\t|��ͥ%d|",i) ;
		}
		printf("  %5dǧ��ʱ   |  %5dǧ��ʱ   | %12fԪ | %12fԪ |\n",b[i-1].ele,b[i-1].pjele,b[i-1].money,b[i-1].pjm);
		printf("\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
		printf("\n\n\t\t\t\t\t�Ƿ��ѯ��ȷ���µ���ϸ��Ϣ��");
		printf("\n\n\t\t\t\t\t1.��Ҫ  0.��Ҫ�������ļ�ͥ\n");
		c=-1;
		scanf("%d",&c);
		getchar();
		system("cls");
		while(c<0||c>1){
			printf("\n\t\t\t\t\t�����������������\n");
			printf("\n\n\t\t\t\t\t�Ƿ��ѯ��ȷ���µ���ϸ��Ϣ��");
			printf("\n\n\t\t\t\t\t1.��Ҫ  0.��Ҫ�������ļ�ͥ\n");
			scanf("%d",&c);
			getchar();
		}
		if(c==1){
			Fdital (i);
		}
	}	
}

void Fdital (int i){
	// iΪ��i����ͥ 
	int j,k,f,sum,m,c,e=0;
	double money=0;
	B b[12]={0};//�˴�b�ṹ������·� 
	for(m=0;m<2;m++){
		system("cls");
		printf("\n\n\t\t\t\t\t\t\t\t\t��ͥ%d��%d�����ϸ��Ϣ\n\n",i,m+2017);
		printf("\t\t\t\t\t\t\t+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n");
		printf("\t\t\t\t\t\t\t| �·� | ��ʱ�õ��� | ��ʱ�õ��� |   �Ͻɵ��   |\n");
		printf("\t\t\t\t\t\t\t|------|------------|------------|--------------|\n");
		for(f=0;f<n;f++){
			for(j=0;j<2;j++){
				for(k=0;k<12;k++){
					sum=f*24+j*12+k;
					if(f==i-1&&j==m){
						printf("\t\t\t\t\t\t\t|%2d�·�| %dǧ��ʱ  | %3dǧ��ʱ  | %10fԪ |\n",k+1,a[sum].up,a[sum].down,a[sum].money);
						printf("\t\t\t\t\t\t\t|------|------------|------------|--------------|\n");
					}
				}
			}
		}
		if(m==0){
			printf("\t\t\t\t\t\t\t\t1.��һҳ\t\t 0.�����ϲ�\n");
			scanf("%d",&c);
			getchar();
			while(c<0||c>1){
				printf("\n\t\t\t\t\t\t\t\t�����������������\n");
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
					printf("�޸�ѡ�������ѡ��\n");
			}
		}
		else{
			printf("\t\t\t\t\t\t\t\t���һҳ��\t\t 0.�����ϲ�\n");
			c=-1;
			scanf("%d",&c);
			getchar();
			while(c!=0){
				printf("\n\t\t\t\t\t\t\t\t�����������������\n");
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
	//printf("\t\t1 ����鿴ÿ����ϸ�õ���Ϣ\n\t\t0 �����ϼ��˵�\n");
	while(1){		
		switch(c){ 
			case 1:
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
				printf("\t\t\t\t\t\t\t\t\t\t          ��ѯ����          \n\n");
				printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
				printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
				printf("\t\t\t\t\t\t\t\t\t��\t����鼸�ż�ͥ���¼��յ���Ϣ��      ��\n");
				printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
				printf("\t\t\t\t\t\t\t\t\t��\t��ͥ1~100����2017~2018����1~12      ��\n");
				printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
				printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
				//printf("\t\t\t����鼸�ż�ͥ���¼��յ���Ϣ��\n");
				//printf("\t��ͥ1~100����2017~2018����1~12\n") ;
				printf("\n\t\t\t\t\t\t\t\t\t��ͥ"); 
				scanf("%d",&f);
				printf("\n\t\t\t\t\t\t\t\t\t��"); 
				scanf("%d",&j);
				printf("\n\t\t\t\t\t\t\t\t\t��"); 
				scanf("%d",&k);
				getchar();
				printf("\n"); 
				while(f<0||f>100||j<2017||j>2018||k<0||k>12){
					printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
					printf("\t\t\t\t\t\t\t\t\t\t                          \n");
					printf("\t\t\t\t\t\t\t\t\t\t                          \n");
					printf("\t\t\t\t\t\t\t\t\t\t  ������������          \n");
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");
					printf("\t\t\t\t\t\t\t\t\t  ��ͥ1~%d����2017~2018����1~12              \n",n);
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");
					printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
					printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
					scanf("%d%d%d",&f,&j,&k);				
				}
				j=j-2017;
				system("cls");
				printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
				
				
				printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
				printf("\t\t\t\t\t\t\t\t\t\t                                    \n");
				if(f<9){
					printf("\t\t\t\t\t\t\t\t\t   ��ͥ00%d��%d��%d�µļ�¼����\n\n",f,j+2017,k) ;
				} 
				if(f>=9&&f<99){
					printf("\t\t\t\t\t\t\t\t\t   ��ͥ0%d��%d��%d�µļ�¼����\n\n",f,j+2017,k) ;
				} 
				if(f>=99){
					printf("\t\t\t\t\t\t\t\t\t   ��ͥ%d��%d��%d�µļ�¼����\n\n",f,j+2017,k) ;
				}
				sum=f*24+j*12+k;
				switch(a[sum].place)
				{
					case 0: 
						printf("\t\t\t\t\t\t\t\t\t\t   С����÷Է\n");
						break;
					case 1: 
						printf("\t\t\t\t\t\t\t\t\t\t   С������Է\n");
						break;
					case 2: 
						printf("\t\t\t\t\t\t\t\t\t\t   С������Է\n");
						break;
					case 3: 
						printf("\t\t\t\t\t\t\t\t\t\t   С������Է\n");
						break;
					case 4: 
						printf("\t\t\t\t\t\t\t\t\t\t   С������Է\n");
						break;
					case 5: 
						printf("\t\t\t\t\t\t\t\t\t\t   С������Է\n");
						break;
					case 6: 
						printf("\t\t\t\t\t\t\t\t\t\t   С������Է\n");
						break;
					case 7: 
						printf("\t\t\t\t\t\t\t\t\t\t   С������Է\n");
						break;
					case 8: 
						printf("\t\t\t\t\t\t\t\t\t\t   С�����Ϻ�\n");
						break;
					case 9: 
						printf("\t\t\t\t\t\t\t\t\t\t   С��������\n");
						break;		
				}
				printf("\t\t\t\t\t\t\t\t\t\t                          \n");
				printf("\t\t\t\t\t\t\t\t\t\t��ʱ�õ�%dǧ��ʱ\n",a[sum].up);
				printf("\t\t\t\t\t\t\t\t\t\t                          \n");
				printf("\t\t\t\t\t\t\t\t\t\t��ʱ�õ�%dǧ��ʱ\n",a[sum].down);
				printf("\t\t\t\t\t\t\t\t\t\t                          \n");
				printf("\t\t\t\t\t\t\t\t\t\tӦ�����%fԪ\n",a[sum].money);
				printf("\t\t\t\t\t\t\t\t\t\t                         \n");
				printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
				printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
		}
		printf("\t\t\t\t\t\t\t\t\t\t  1 ����\n\n\t\t\t\t\t\t\t\t\t\t  0 ����\n");
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
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  �õ�ͳ��Ա��¼          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  �������˺ź�����              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	while(allusersa[place].label!=0)
		place++;
	//printf("\n\t\t�˼��ǵ�%d��(#`O��)��",place); 
	if(place==0)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\tĿǰ���û�");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t��0����");
		 
		do
		{	
			a=getch();
			if(a==48)
			{
				load();
				//printf("\n\n\t\t�ӣ���ʵ�����ϼ��˵�����");//�˴�Ϊ�ϼ��˵����� 
				return;
			}
			else
				printf("\n\n\t\t\t\t\t\t\t\t\t\t��������\n"); 
		}while(a!=48);
	}
	
	//�û������� 
	printf("\n\n\t\t\t\t\t\t\t\t\t\t�����������û�����");
	do
	{
		char u[Lofuser]={0};
		o=prouser1(u,place);
		//printf("\n\t\t����o=%d\n",o); 
		m=o/10;
		//printf("\n\t\t����m=%d\n",m); 
		//scanf("%d",&o);
		tag=o%10;
		//printf("\n\t\t����tag=%d\n",tag);
	}while(m);
	printf("\n\t\t\t\t\t\t\t\t\t\t�û�������,����������:"); 
	
	//���벿�� 
	do
	{
		char p[Lofpass]={0};
		n=propass1(p,place,tag);
	}while(n);
	printf("\n\n\n\t\t\t\t\t\t\t\t\t\t��½�ɹ���"); 
	return; 
}

int prouser1(char u[Lofuser],int n)
{
	//printf("\n\t\t�������n=%d\n",n); 
	int k=0,j=0,t,sign=1;
	int judge[Allusers]={0};
	//���룻
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
		printf("\n\n\t\t\t\t\t\t\t\t\t\t�û��������ڣ�����������:");
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
			printf("\n\n\t\t�������,����������:");
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
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  ����ϵͳ������Ա��¼          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  �������˺ź�����              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	while(allusersb[place].label!=0)
		place++;
	//printf("\n\t\t�˼��ǵ�%d��(#`O��)��",place); 
	if(place==0)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\tĿǰ���û�");
		printf("\n\n\t\t\t\t\t\t\t\t\t\t��0����");
		
		do
		{	
			a=getch();
			if(a==48)
			{
				load();//�˴�Ϊ�ϼ��˵����� 
				return;
			}
			else
				printf("\n\n\t\t\t\t\t\t\t\t\t\t��������\n"); 
		}while(a!=48);
	}
	
	//�û������� 
	printf("\n\n\t\t\t\t\t\t\t\t\t\t�����������û�����");
	do
	{
		char u[Lofuser]={0};
		o=prouser2(u,place);
		//printf("\n\t\t����o=%d\n",o); 
		m=o/10;
		//printf("\n\t\t����m=%d\n",m); 
		//scanf("%d",&o);
		tag=o%10;
		//printf("\n\t\t����tag=%d\n",tag);
	}while(m);
	printf("\n\n\t\t\t\t\t\t\t\t\t\t�û�������,����������:"); 
	
	//���벿�� 
	do
	{
		char p[Lofpass]={0};
		n=propass2(p,place,tag);
	}while(n);
	printf("\n\n\n\t\t��½�ɹ���"); 
	return; 
}

int prouser2(char u[Lofuser],int n)
{
	//printf("\n\t\t�������n=%d\n",n); 
	int k=0,j=0,t,judge[Allusers],sign=1;
	//���룻
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
	//printf("\n\n\t\trua!�벻����!"); 
	for(k=0;u[k]!='\0';k++);
	//printf("\n\t\t�˼��ǵ�%dλ(#`O��)��",k);
	for(j=0;j<n;j++)
	{
		//printf("\n\t\t������j=%d\n",j); 
		//int o=0;
		for(t=0;t<k+1;t++)
		{
			if(allusersa[j].user[t]==u[t])
			{
				//printf("\n\tȥ�������ӹ֣���%d����\n",t);
				continue;
			}
			else
			{
				//o=1;
				break;
			}
			//printf("\n\tȥ�������ӹ֣���%d����\n",t);
		}
		//printf("\n\tΪʲôt=%d����",t);
		if(t==k+1)
		{
			//printf("j=%d\n",j);
			//printf("\n\t\t�������������ҽ�������"); 
			sign=0;
			//printf("\n\tΪʲôt=%dsdfghjklhg  k=%d  fdsdfghjkl",t,k);
			//printf("\n00000�벻���һ���ְɣ�");
			break;
		}

	}
	//printf("\n\t��������%d��������",j);
	//printf("rua��");
	if(sign==1)
	{
		printf("\n\n\t\t\t\t\t\t\t\t\t\t�û��������ڣ�����������:");
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
			printf("\n\n\t\t�������,����������:");
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
		printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
		printf("\t\t\t\t\t\t\t\t\t\t                          \n");
		printf("\t\t\t\t\t\t\t\t\t\t                          \n");
		printf("\t\t\t\t\t\t\t\t\t\t  ����Ա��¼          \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");
		printf("\t\t\t\t\t\t\t\t\t\t  ����������              \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");
		printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
		printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
			printf("\n\n\t\t\t\t\t\t\t\t\t\t�������\n\n");
			printf("\n\n\t\t\t\t\t\t\t\t\t\t");
			printf("���ٴ���������:");
		}
		system("cls"); 
		 
	}
}


void Add(){
	int c=-1;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n") ;
	printf("\t\t\t\t\t\t\t\t\t\t          ע���û�          \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t1.ע���õ�ͳ��Ա                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t2.ע�ṩ�繫˾������Ա              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t0.����                              ��\n");
	printf("\t\t\t\t\t\t\t\t\t��\t                                    ��\n");			
	printf("\t\t\t\t\t\t\t\t\t��==========================================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n"); 
		}
	}	
}

void Del(){
	
}

void Look(){
	int c=-1;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     ��ѯ                     \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.�鿴����          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.�鿴���              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  3.�������              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪ϵͳ              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n"); 
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
		}
	}		 
}

void Analysis(){
	int c;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     ��������                     \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.������С��ģ��       \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪ϵͳ             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
		}
	}	
} 
void Change(){
	int c;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t\t     �޸�����                     \n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.�������ԭʼ����     \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.�޸���������         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪ϵͳ             \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
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
				printf("\t\t\t\t\t\t\t\t\t\t�޸�ѡ�������ѡ��\n");
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
        printf("\t\t~���Ų˵�~\n\n");
        printf("\t\t1.��Ŀ�б�\n\n");
        printf("\t\t2.ֹͣ����\n\n");
        printf("\t\t0.�����ϼ�\n\n");
        printf("\t ��ѡ��:");


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
				printf("�޸�ѡ�������ѡ��");
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
        printf("\t\t1.�ص�01.ǧ����뽻���\n\n");
        printf("\t\t2.�ص�02.��ѧ���͵�������Ů\n\n");
        printf("\t\t0.�����ϼ�\n\n");
        printf("\t ��ѡ��:");


        scanf("%d",&c);
		switch(c){
			case 1:
                PlaySound(TEXT("��һ������"), NULL, SND_FILENAME| SND_ASYNC);
				break;
			case 2:
                PlaySound(TEXT("el.wav"), NULL, SND_FILENAME| SND_ASYNC);
                break;
            case 0:
			default:
				printf("�޸�ѡ�������ѡ��");
		}
    }*/
}

void Revise(){
	int c;
	system("cls"); 
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                          \n");
	printf("\t\t\t\t\t\t\t\t\t\t  1.�û���¼����          \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  2.ϵͳ����              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");
	printf("\t\t\t\t\t\t\t\t\t\t  0.�뿪ϵͳ              \n");
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");	
	printf("\t\t\t\t\t\t\t\t\t\t                         \n");			
	printf("\t\t\t\t\t\t\t\t\t��==============================��\n");
}
