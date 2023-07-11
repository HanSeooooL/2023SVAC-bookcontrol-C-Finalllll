#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define UISTARTPOINTX 10 //UI출력 X축 시작지점
#define UISTARTPOINTY 5 //UI출력 Y축 시작지점ㄴ

#define UP 72		//방향키 위
#define DOWN 80		//방향키 아래
#define LEFT 75		//방향fileLead仕?
#define RIGHT 77	//방향키 오른쪽
#define ENTER 13	//엔터키
#define ESC 27		//ESCZl

//책 구조체 선언
/*typedef struct _book {
    int prime;
    char bookname[100]; //책 이름
    char writername[30];  //저자 이름
    char company[30];   //출판사 이름
    int rent;   //0이면 보유 1이면 대여
    char rentalname[30]; //빌려간 사람 이름
    char rentaltime[20];    //빌려간 연월일
    char retutime[20];      //반납예정 연월일
} Book;*/

typedef struct _book {
    int prime;
    char* bookname; //책 이름
    char* writername;  //저자 이름
    char* company;   //출판사 이름
    int rent;   //0이면 보유 1이면 대여
    char* rentalname; //빌려간 사람 이름
    char* rentaltime;    //빌려간 연월일
    char* retutime;      //반납예정 연월일
} Book;


//Algorithm
void init_book(Book* a); //initialize book(have변수 뒤의 초기값)
int checkhowdoyouDIDNTreturn(char* returnday);  //연체일 계산
void rentthebook(Book* rentbook, char* rentperson, char* rentday, char* returnday);
void returnthebook(Book* returnbook);
Book** search_book(char* keyword, int* how);
void gettheCharactersfromUser(char** str);
void threesecondtimer(int X, int Y);
void clearbuffer(void);
int compare(const void* first, const void* second);


//file In / OUT
void addbook(char* name, Book newone);  //책 추가
void fileLead(char* name, int* n, int* rn);    //파일 불러오기
Book** getbooklist(int rentedunrented, int n, int page, int* display); //페이지에 알맞은 책의 배열을 반환하는 함수.
void savethefile(char* name);
Book** gettheAllbookList(int* n);
Book* titledisplayrentbooks(int *howmany);

//UI
void gotoxy(int x, int y);
void title(void);
void drawUI(void); //UI 그릴 때 쓰는 함수