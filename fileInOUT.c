#include "bookcontroll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <unistd.h>

#define MAX_CHAR_PER_LINE 1000

static Book* rented;
static Book* unrented;
static int howmuchrented;
static int howmuchunrented;

void getthefiletoprogram(char **To, char *from);

void savethefile(char* name) {
    FILE* fp;
    fp = fopen(name, "w");

    //fprintf(fp, "%d", newone.prime);    //고유번호
    //fprintf(fp, "#");
    for (int i = 0; i < howmuchunrented; i++) {
        if (unrented[i].rent == -1)
            continue;
        fprintf(fp, "%s#", unrented[i].bookname); //책 이름
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].writername); //저자
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].company);  //출판사
        fflush(stdout);
        fprintf(fp, "%d#", unrented[i].rent); //대여 여부
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].rentalname); //빌린 사람
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].rentaltime);   //빌린 연월일
        fflush(stdout);
        fprintf(fp, "%s", unrented[i].retutime); //반납예정 연월일
        fprintf(fp, "\n");
    }

    for (int i = 0; i < howmuchrented; i++) {
        if (rented[i].rent == -1)
            continue;
        fprintf(fp, "%s#", rented[i].bookname); //책 이름
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].writername); //저자
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].company);  //출판사
        fflush(stdout);
        fprintf(fp, "%d#", rented[i].rent); //대여 여부
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].rentalname); //빌린 사람
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].rentaltime);   //빌린 연월일
        fflush(stdout);
        fprintf(fp, "%s", rented[i].retutime); //반납예정 연월일
    }
    fclose(fp);
}

void addbook(char* name, Book newone) {
    FILE* fp;

    if (access(name, 0) != -1) {  //이미 존재하는 파일인 경우 내용 추가
        fp = fopen(name, "a");
    }
    else    //없는 경우 생성
        fp = fopen(name, "w");

    //fprintf(fp, "%d", newone.prime);
    //fprintf(fp, "#");
    fprintf(fp, "%s#", newone.bookname);
    fflush(stdin);
    fprintf(fp, "%s#", newone.writername);
    fflush(stdin);
    fprintf(fp, "%s#", newone.company);
    fflush(stdin);
    fprintf(fp, "%d#", newone.rent);
    fflush(stdin);
    fprintf(fp, "%s#", newone.rentalname);
    fflush(stdin);
    fprintf(fp, "%s#", newone.rentaltime);
    fflush(stdin);
    fprintf(fp, "%s", newone.retutime);
    fprintf(fp, "\n");

    fclose(fp);
}

void fileLead(char* name, int* n, int* rn) {
    FILE* fp;
    int count = 1, rcount = 1;
    char str[MAX_CHAR_PER_LINE];
    Book book;
    *n = 0;
    *rn = 0;
    free(unrented);
    free(rented);
    unrented = (Book*)malloc(sizeof(Book) * 3);        //3칸 메모리 할당
    rented = (Book*)malloc(sizeof(Book) * 3);           //3칸 메모리 할당
    fp = fopen(name, "r");

    if (fp == NULL)
        printf("파일이 없습니다.\n");
    else if (fp != NULL) {
        while (fgets(str, MAX_CHAR_PER_LINE, fp))    //한줄씩 읽어들이고
        {
            //대여중이 아닌 도서 구조체 배열 동적 길이 추가
            if ((*n % 3) == 0 && !(*n == 0)) {      //n을 3으로 나눴을 때 나머지가 없고, (3의 배수) n이 0이 아닐 때
                count += 1; //count를 1 늘리고
                unrented = realloc(unrented, sizeof(Book) * (count * 3));    //초기값이 3칸이므로 조건을 처음 만족했을 때 6칸 다음은 9칸. 3의 배수로 칸을 늘려간다.
            }

            //대여중인 도서 구조체 배열 동적 길이 추가
            if ((*rn % 3) == 0 && !(*rn == 0)) {      //n을 3으로 나눴을 때 나머지가 없고, (3의 배수) n이 0이 아닐 때
                rcount += 1; //count를 1 늘리고
                rented = realloc(rented, sizeof(Book) * (rcount * 3));    //초기값이 3칸이므로 조건을 처음 만족했을 때 6칸 다음은 9칸. 3의 배수로 칸을 늘려간다.
            }

            //공통 정보
            //book.prime = atoi(strtok(str, "#"));         //고유번호 설정
            //strcpy(book.bookname, strtok(str, "#"));   //책 이름
            getthefiletoprogram(&book.bookname, strtok(str, "#"));
            //strcpy(book.writername, strtok(NULL, "#"));       //저자
            getthefiletoprogram(&book.writername, strtok(NULL, "#"));
            //strcpy(book.company, strtok(NULL, "#"));    //출판사
            getthefiletoprogram(&book.company, strtok(NULL, "#"));
            book.rent = atoi(strtok(NULL, "#"));        //대여 여부

            if (book.rent == 0) {
                init_book(&book);
                unrented[*n] = book;                         //배열에 저장
                *n = *n + 1;                            //반복할때마다 +1 (레코드의 개수 파악)

            }

            //대여중인 도서 전용 정보
            else {
                //strcpy(book.rentalname, strtok(NULL, "#")); //대여인
                getthefiletoprogram(&book.rentalname, strtok(NULL, "#"));
                //strcpy(book.rentaltime, strtok(NULL, "#")); //대여 날짜
                getthefiletoprogram(&book.rentaltime, strtok(NULL, "#"));
                //strcpy(book.retutime, strtok(NULL, "#"));   //반납 예정 날짜
                getthefiletoprogram(&book.retutime, strtok(NULL, "#"));
                rented[*rn] = book;                         //배열에 저장
                *rn = *rn + 1;                            //반복할때마다 +1 (레코드의 개수 파악)
            }
        }
        howmuchrented = *rn;
        howmuchunrented = *n;


        fclose(fp);
    }
}

void getthefiletoprogram(char **To, char *from) {
    *To = (char*)malloc(strlen(from) + 1);
    memcpy(*To, from, strlen(from) + 1);
}


//페이지에 알맞은 책의 포인터 배열을 반환하는 함수.
//rentedunrented -> check read rent or read unrent n -> how many data in there
Book** getbooklist(int rentedunrented, int n, int page, int* display) {
    Book** list;
    *display = 5 * page;

    if (n < *display) {
        *display = n;
    }
    
    list = (Book**)malloc(sizeof(Book*) * *display % 5);
    for (int i = 5 * (page - 1); i < *display; i++) {
        if (rentedunrented == 0) {
            list[i % 5] = &unrented[i];
        }
        else
            list[i % 5] = &rented[i];
    }

    // for(int i = 5*(page - 1); i < *display; i++) {
    //     if (rentedunrented == 0) {
    //         list[i % 5] = unrented[i];
    //     }
    //     else
    //         list[i % 5] = rented[i];
    // }

    return list;
}

Book** gettheAllbookList(int* n) {
    Book** res;
    int howmany;

    howmany = howmuchrented + howmuchunrented;
    *n = howmany;

    res = (Book**)malloc(sizeof(Book*) * howmany);

    for (int i = 0; i < howmuchunrented; i++) {
        res[i] = &unrented[i];
    }
    for (int i = 0; i < howmuchrented; i++) {
        res[howmuchunrented + i] = &rented[i];
    }

    return res;
}

Book* titledisplayrentbooks(int *howmany) {
    int n = 0, rn = 0;
    int* indexcheck;
    Book* copylist, *res;
    fileLead("Book.txt", &n, &rn);
    indexcheck = (int*)malloc(sizeof(int) * rn);
    n = 0;
    for (int i = 0; i < rn; i++) {
        if (checkhowdoyouDIDNTreturn(rented[i].retutime) > 0) {
            indexcheck[n] = i;
            n += 1;
        }
    }
    copylist = (Book*)malloc(sizeof(Book) * n);
    for (int i = 0; i < n; i++) {
        copylist[i] = rented[indexcheck[i]];
    }

    free(indexcheck);
    qsort(copylist, n, sizeof(Book), compare);
    if (n > 3) n = 3;
    res = (Book*)malloc(sizeof(Book) * n);
    for (int i = 0; i < n; i++) {

        res[i] = copylist[i];

    }
    *howmany = n;
    free(copylist);

    return res;
}