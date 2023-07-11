#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>
#include "bookcontroll.h"

static long changethecalendertoDays(int year, int month, int day);

void clearbuffer(void) {
    while (getchar() != '\n');
}

void init_book(Book* a) {
    a -> rentalname = (char*)malloc(sizeof(char) * 2);
    strcpy(a->rentalname, "_");
    a -> rentaltime = (char*)malloc(sizeof(char) * 2);
    strcpy(a->rentaltime, "_");
    a -> retutime = (char*)malloc(sizeof(char) * 2);
    strcpy(a->retutime, "_");
    a->rent = 0;
}

void rentthebook(Book* rentbook, char* rentperson, char* rentday, char* returnday) {
    strcpy(rentbook->rentalname, rentperson);
    strcpy(rentbook->rentaltime, rentday);
    strcpy(rentbook->retutime, returnday);
    rentbook -> rent = 1;
    savethefile("Book.txt");
}

void returnthebook(Book* returnbook) {
    returnbook -> rent = 0;
    savethefile("Book.txt");
}

Book** search_book(char* keyword, int* how) {

    Book** list, ** res;
    char* check;
    int n, * indexcheck, howmanysearched;
    howmanysearched = 0;
    list = gettheAllbookList(&n);

    indexcheck = (int*)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        check = strstr(list[i] -> bookname, keyword);
        if (check != NULL) {
            indexcheck[howmanysearched] = i;
            howmanysearched++;
            
            continue;
        }
        check = strstr(list[i] -> writername, keyword);
        if (check != NULL) {
            indexcheck[howmanysearched] = i;
            howmanysearched++;
            
            continue;
        }
        check = strstr(list[i] -> company, keyword);
        if (check != NULL) {
            indexcheck[howmanysearched] = i;
            howmanysearched++;
            
            continue;
        }
    }

    res = (Book**)malloc(sizeof(Book*) * howmanysearched);
    *how = howmanysearched;


    for (int i = 0; i < howmanysearched; i++) {
        res[i] = list[indexcheck[i]];
    }
    
    free(list);
    free(indexcheck);
    
    return res;
}

long changethecalendertoDays(int year, int month, int day) {
    long res;
    int monthdayys[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int yunmonthdayys[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    res = 0;

    //1. year
    res += ((year - 1) / 4) * 366;
    res += ((year - 1) - (year - 1) / 4) * 365;

    //2. month
    if (year % 4) {
        for (int i = 0; i < month - 1; i++) {
            res += monthdayys[i];
        }
    }
    else
        for (int i = 0; i < month - 1; i++) {
            res += yunmonthdayys[i];
        }

    //3. day
    res += day;
    return res;
}


int checkhowdoyouDIDNTreturn(char* returnday) {
    time_t raw;
    struct tm* t;
    int month, day;
    long res, returndayslong, nowdayslong;
    char year[4];

    returndayslong = 0; nowdayslong = 0;
    raw = time(NULL);
    t = localtime(&raw);

    for (int i = 0; i < 4; i++) {
        year[i] = returnday[i];
    }
    month = (returnday[4] - '0') * 10 + (returnday[5] - '0');
    day = (returnday[6] - '0') * 10 + (returnday[7] - '0');

    returndayslong = changethecalendertoDays(atoi(year), month, day);
    nowdayslong = changethecalendertoDays(t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);

    res = nowdayslong - returndayslong;
    
    return (int)res;    //
}

void gettheCharactersfromUser(char** str) {
    char tmp[4096];

    gets(tmp);

    
    *str = (char*)malloc(strlen(tmp) + 1);
    memcpy(*str, tmp, strlen(tmp) + 1);
    rewind(stdin);
}

void threesecondtimer(int X, int Y) {
    clock_t start, end;
    
    int time, max = 3;
    start = clock();
    time = 0;
    
    gotoxy(X, Y);
    printf("3");
    while(1) {
        end = clock();
        if(time != (int)((double)(end - start) / CLOCKS_PER_SEC)) {
            time = (int)((double)(end - start) / CLOCKS_PER_SEC);
            if(max - time != 0) {
                gotoxy(X, Y);
                printf("%d", max - time);
            }
        }
        if(time >= 3) {
            break;
        }
    }
}

int compare(const void* first, const void* second)
{

    if (checkhowdoyouDIDNTreturn(((Book*)first)->retutime) < checkhowdoyouDIDNTreturn(((Book*)second)->retutime))
        return 1;

    else if (checkhowdoyouDIDNTreturn(((Book*)first) -> retutime) > checkhowdoyouDIDNTreturn(((Book*)second)->retutime))
        return -1;

    else
        return 0;
}