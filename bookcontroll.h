#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define UISTARTPOINTX 10 //UI��� X�� ��������
#define UISTARTPOINTY 5 //UI��� Y�� ����������

#define UP 72		//����Ű ��
#define DOWN 80		//����Ű �Ʒ�
#define LEFT 75		//����fileLead��?
#define RIGHT 77	//����Ű ������
#define ENTER 13	//����Ű
#define ESC 27		//ESCZl

//å ����ü ����
/*typedef struct _book {
    int prime;
    char bookname[100]; //å �̸�
    char writername[30];  //���� �̸�
    char company[30];   //���ǻ� �̸�
    int rent;   //0�̸� ���� 1�̸� �뿩
    char rentalname[30]; //������ ��� �̸�
    char rentaltime[20];    //������ ������
    char retutime[20];      //�ݳ����� ������
} Book;*/

typedef struct _book {
    int prime;
    char* bookname; //å �̸�
    char* writername;  //���� �̸�
    char* company;   //���ǻ� �̸�
    int rent;   //0�̸� ���� 1�̸� �뿩
    char* rentalname; //������ ��� �̸�
    char* rentaltime;    //������ ������
    char* retutime;      //�ݳ����� ������
} Book;


//Algorithm
void init_book(Book* a); //initialize book(have���� ���� �ʱⰪ)
int checkhowdoyouDIDNTreturn(char* returnday);  //��ü�� ���
void rentthebook(Book* rentbook, char* rentperson, char* rentday, char* returnday);
void returnthebook(Book* returnbook);
Book** search_book(char* keyword, int* how);
void gettheCharactersfromUser(char** str);
void threesecondtimer(int X, int Y);
void clearbuffer(void);
int compare(const void* first, const void* second);


//file In / OUT
void addbook(char* name, Book newone);  //å �߰�
void fileLead(char* name, int* n, int* rn);    //���� �ҷ�����
Book** getbooklist(int rentedunrented, int n, int page, int* display); //�������� �˸��� å�� �迭�� ��ȯ�ϴ� �Լ�.
void savethefile(char* name);
Book** gettheAllbookList(int* n);
Book* titledisplayrentbooks(int *howmany);

//UI
void gotoxy(int x, int y);
void title(void);
void drawUI(void); //UI �׸� �� ���� �Լ�