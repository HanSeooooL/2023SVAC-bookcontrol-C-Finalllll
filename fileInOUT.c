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

    //fprintf(fp, "%d", newone.prime);    //������ȣ
    //fprintf(fp, "#");
    for (int i = 0; i < howmuchunrented; i++) {
        if (unrented[i].rent == -1)
            continue;
        fprintf(fp, "%s#", unrented[i].bookname); //å �̸�
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].writername); //����
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].company);  //���ǻ�
        fflush(stdout);
        fprintf(fp, "%d#", unrented[i].rent); //�뿩 ����
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].rentalname); //���� ���
        fflush(stdout);
        fprintf(fp, "%s#", unrented[i].rentaltime);   //���� ������
        fflush(stdout);
        fprintf(fp, "%s", unrented[i].retutime); //�ݳ����� ������
        fprintf(fp, "\n");
    }

    for (int i = 0; i < howmuchrented; i++) {
        if (rented[i].rent == -1)
            continue;
        fprintf(fp, "%s#", rented[i].bookname); //å �̸�
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].writername); //����
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].company);  //���ǻ�
        fflush(stdout);
        fprintf(fp, "%d#", rented[i].rent); //�뿩 ����
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].rentalname); //���� ���
        fflush(stdout);
        fprintf(fp, "%s#", rented[i].rentaltime);   //���� ������
        fflush(stdout);
        fprintf(fp, "%s", rented[i].retutime); //�ݳ����� ������
    }
    fclose(fp);
}

void addbook(char* name, Book newone) {
    FILE* fp;

    if (access(name, 0) != -1) {  //�̹� �����ϴ� ������ ��� ���� �߰�
        fp = fopen(name, "a");
    }
    else    //���� ��� ����
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
    unrented = (Book*)malloc(sizeof(Book) * 3);        //3ĭ �޸� �Ҵ�
    rented = (Book*)malloc(sizeof(Book) * 3);           //3ĭ �޸� �Ҵ�
    fp = fopen(name, "r");

    if (fp == NULL)
        printf("������ �����ϴ�.\n");
    else if (fp != NULL) {
        while (fgets(str, MAX_CHAR_PER_LINE, fp))    //���پ� �о���̰�
        {
            //�뿩���� �ƴ� ���� ����ü �迭 ���� ���� �߰�
            if ((*n % 3) == 0 && !(*n == 0)) {      //n�� 3���� ������ �� �������� ����, (3�� ���) n�� 0�� �ƴ� ��
                count += 1; //count�� 1 �ø���
                unrented = realloc(unrented, sizeof(Book) * (count * 3));    //�ʱⰪ�� 3ĭ�̹Ƿ� ������ ó�� �������� �� 6ĭ ������ 9ĭ. 3�� ����� ĭ�� �÷�����.
            }

            //�뿩���� ���� ����ü �迭 ���� ���� �߰�
            if ((*rn % 3) == 0 && !(*rn == 0)) {      //n�� 3���� ������ �� �������� ����, (3�� ���) n�� 0�� �ƴ� ��
                rcount += 1; //count�� 1 �ø���
                rented = realloc(rented, sizeof(Book) * (rcount * 3));    //�ʱⰪ�� 3ĭ�̹Ƿ� ������ ó�� �������� �� 6ĭ ������ 9ĭ. 3�� ����� ĭ�� �÷�����.
            }

            //���� ����
            //book.prime = atoi(strtok(str, "#"));         //������ȣ ����
            //strcpy(book.bookname, strtok(str, "#"));   //å �̸�
            getthefiletoprogram(&book.bookname, strtok(str, "#"));
            //strcpy(book.writername, strtok(NULL, "#"));       //����
            getthefiletoprogram(&book.writername, strtok(NULL, "#"));
            //strcpy(book.company, strtok(NULL, "#"));    //���ǻ�
            getthefiletoprogram(&book.company, strtok(NULL, "#"));
            book.rent = atoi(strtok(NULL, "#"));        //�뿩 ����

            if (book.rent == 0) {
                init_book(&book);
                unrented[*n] = book;                         //�迭�� ����
                *n = *n + 1;                            //�ݺ��Ҷ����� +1 (���ڵ��� ���� �ľ�)

            }

            //�뿩���� ���� ���� ����
            else {
                //strcpy(book.rentalname, strtok(NULL, "#")); //�뿩��
                getthefiletoprogram(&book.rentalname, strtok(NULL, "#"));
                //strcpy(book.rentaltime, strtok(NULL, "#")); //�뿩 ��¥
                getthefiletoprogram(&book.rentaltime, strtok(NULL, "#"));
                //strcpy(book.retutime, strtok(NULL, "#"));   //�ݳ� ���� ��¥
                getthefiletoprogram(&book.retutime, strtok(NULL, "#"));
                rented[*rn] = book;                         //�迭�� ����
                *rn = *rn + 1;                            //�ݺ��Ҷ����� +1 (���ڵ��� ���� �ľ�)
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


//�������� �˸��� å�� ������ �迭�� ��ȯ�ϴ� �Լ�.
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