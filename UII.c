#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <Windows.h>
#include "bookcontroll.h"

void addbookUI(void); //å ��� ȭ�� o
static void finishedaddbookUI(void); //å ��� �Ϸ� ȭ�� o
static void viewbooklistUI(void); //��ϵ��� ���� ȭ��
static void searchbookUI(void); //���� �˻� ȭ��
static void bookdetailsUI(Book* one);   //�������� ��ȸ ȭ��
static void detailretouchordeleteUI(Book* one); //�������� ���� �� ���� ȭ��
void checkretouchUI(Book* old, Book afterrewrite);  //�������� Ȯ�� ȭ��
static void checkdeleteUI(Book* one);   //�������� ���� Ȯ�� ȭ��
static void rentalbookUI(Book* one);    //�뿩 ��� ȭ��
static void finishedrentalbookUI(void); //�뿩 ��� �Ϸ� ȭ��
static void returnbookUI(Book* one);    //�ݳ� ó�� ȭ��
static void finishedreturnbookUI(void);    //�ݳ� ó�� �Ϸ� ȭ��

//screens
void titlescreen(void);
void addbookscreen(void);

void gotoxy(int x, int y) {
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}




void titlescreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("���� �������� ���α׷�");
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
    }
    printf("��");
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    printf("��");
    gotoxy(51, 3);
    printf("�� ��");
    for (int i = 0; i < 10; i++) {
        gotoxy(51, 4 + i);
        printf("��");
    }
    for (int i = 0; i < 10; i++) {
        gotoxy(3, 4 + i);
        printf("��");
    }
    printf("\n   ");
    printf("��");
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    printf("��");
    for (int i = 0; i < 10; i++) {
        gotoxy(118, 4 + i);
        printf("��");
    }
    for (int i = 0; i < 10; i++) {
        gotoxy(53, 4 + i);
        printf("��");
    }

    gotoxy(51, 14);
    printf("�� ��");
    
    gotoxy(6, 5);
    printf("1. ���� ���");
    gotoxy(6, 8);
    printf("2. ��ϵ��� ����");
    gotoxy(6, 11);
    printf("0. ����");
    gotoxy(55, 4);
    printf("��ü���� ���");
    gotoxy(55, 6);
    printf(" ������                     �뿩��                   ��ü��");
    
    printf("\n");

}

void addbookscreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("      ���� ���    ");
    printf("\n\n");
    for (int i = 0; i < 3; i++) {
        printf(" ");
    }
    printf("��");
    for (int i = 0; i < 47; i++) {
        printf("��");
    }
    printf("��");

    for (int i = 0; i < 10; i++) {
        gotoxy(51, 4 + i);
        printf("��");
    }
    for (int i = 0; i < 10; i++) {
        gotoxy(3, 4 + i);
        printf("��");
    }
    printf("\n   ");
    printf("��");
    for (int i = 0; i < 47; i++) {
        printf("��");
    }
    printf("��");

    gotoxy(6, 5);
    printf("������: ");
    gotoxy(6, 8);
    printf("����: ");
    gotoxy(6, 11);
    printf("���ǻ�: ");
}

void viewbooklistscreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("    ��ϵ��� ����    ");
    printf("\n\n     ");
    printf("������: ");
    printf("\n\n     ");
    printf("������                    ����          ���ǻ�                    ");

    gotoxy(3, 17);
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    
}

void bookdetailsscreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("    �������� ��ȸ   ");
    printf("\n\n   ");
    printf("��");
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    printf("��");
    for (int i = 0; i < 12; i++) {
        gotoxy(118, 4 + i);
        printf("��");
    }
    for (int i = 0; i < 12; i++) {
        gotoxy(3, 4 + i);
        printf("��");
    }
    printf("\n   ");
    printf("��");
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    printf("��");

    gotoxy(8, 5);
    printf("������: ");
    gotoxy(8, 8);
    printf("����: ");
    gotoxy(8, 11);
    printf("���ǻ�: ");
    gotoxy(8, 14);
    printf("�뿩 ����: ");

}

void detailretouchscreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("    �������� ����/����    ");
    printf("\n\n   ");
    printf("��");
    for (int i = 0; i < 80; i++) {
        printf("��");
    }
    printf("��");
    for (int i = 0; i < 10; i++) {
        gotoxy(84, 4 + i);
        printf("��");
    }
    for (int i = 0; i < 10; i++) {
        gotoxy(3, 4 + i);
        printf("��");
    }
    printf("\n   ");
    printf("��");
    for (int i = 0; i < 80; i++) {
        printf("��");
    }
    printf("��");

    gotoxy(8, 5);
    printf("1. ������: ");
    gotoxy(8, 8);
    printf("2. ����: ");
    gotoxy(8, 11);
    printf("3. ���ǻ�: ");
}

void checkretouchscreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("    �������� ��ȸ   ");
    printf("\n\n\n   ");
    printf("��");
    for (int i = 0; i < 57; i++) {
        printf("��");
    }
    printf("��");
    for (int i = 0; i < 56; i++) {
        printf("��");
    }
    printf("��");
    for (int i = 0; i < 10; i++) {
        gotoxy(118, 5 + i);
        printf("��");
    }
    for (int i = 0; i < 10; i++) {
        gotoxy(61, 5 + i);
        printf("��");
    }
    for (int i = 0; i < 10; i++) {
        gotoxy(3, 5 + i);
        printf("��");
    }
    printf("\n   ");
    printf("��");
    for (int i = 0; i < 57; i++) {
        printf("��");
    }
    printf("��");
    for (int i = 0; i < 56; i++) {
        printf("��");
    }
    printf("��");
    gotoxy(27, 3);
    printf("����(���� ��)");
    gotoxy(87, 3);
    printf("���� ��");
    gotoxy(6, 6);
    printf("������: ");
    gotoxy(6, 9);
    printf("����: ");
    gotoxy(6, 12);
    printf("���ǻ�: ");
    gotoxy(64, 6);
    printf("������: ");
    gotoxy(64, 9);
    printf("����: ");
    gotoxy(64, 12);
    printf("���ǻ�: ");
}

void rentthebookscreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("    �����뿩 ���   ");
    printf("\n\n   ");
    printf("��");
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    printf("��");
    for (int i = 0; i < 12; i++) {
        gotoxy(118, 4 + i);
        printf("��");
    }
    for (int i = 0; i < 12; i++) {
        gotoxy(3, 4 + i);
        printf("��");
    }
    printf("\n   ");
    printf("��");
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    printf("��");

    gotoxy(8, 5);
    printf("������: ");
    gotoxy(8, 8);
    printf("����: ");
    gotoxy(8, 11);
    printf("���ǻ�: ");
    gotoxy(8, 14);
    printf("�뿩 ����: X");
    gotoxy(8, 17);
    printf("(!)��¥ �Է��� 8�ڸ� ���� ���·� �Է� ex)2023�� 7�� 12�� -> 20230712");
}

void returnthebookscreen(void) {
    gotoxy(0, 0);
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("    �����ݳ� ���   ");

    gotoxy(8, 17);
    printf("                                                                                                                         ");
    gotoxy(8, 19);
    printf("                                                                                                                         ");
    gotoxy(8, 21);
    printf("                                                                                                                         ");
    gotoxy(8, 17);
    printf("1. �ݳ�               0. ���");
}

void keywordsearchscreen(void) {
    system("cls");
    printf("\n");
    for (int i = 0; i < 50; i++) {
        printf(" ");
    }
    printf("    Ű���� �˻�    ");
    gotoxy(5, 4);
    printf("Ű����: ");
    printf("\n     ");
    printf("������                    ����          ���ǻ�                    ");
    gotoxy(64, 5);
    printf("�뿩 ����                                                                        ");
    gotoxy(3, 17);
    for (int i = 0; i < 114; i++) {
        printf("��");
    }
    gotoxy(100, 18);
    printf("0. �ڷΰ���");
}

void finishedaddbookscreen(void) {
    system("cls");
    gotoxy(56, 16);
    printf("��� �Ϸ�!");
}

void drawUI(void) {
    int cursor, X, Y;
    X = 0; Y = 0;
    system("mode con cols=124 lines=40");

    finishedaddbookscreen();
    gotoxy(X, Y);
    printf("o");
    while (1) {
        cursor = _getch();
        
        switch (cursor) {
        case RIGHT:
            gotoxy(X, Y);
            printf(" ");
            X += 1;
            gotoxy(X, Y);
            printf("o");
            break;

        case LEFT:
            gotoxy(X, Y);
            printf(" ");
            X -= 1;
            gotoxy(X, Y);
            printf("o");
            break;

        case DOWN:
            gotoxy(X, Y);
            printf(" ");
            Y += 1;
            gotoxy(X, Y);
            printf("o");
            break;

        case UP:
            gotoxy(X, Y);
            printf(" ");
            Y -= 1;
            gotoxy(X, Y);
            printf("o");
            break;

        case ESC:
            return;
        }
        gotoxy(80, 38);
        printf("%2d %2d", X, Y);
        continue;
    }
}

void title(void) {
    int choice, n;
    int a;
    Book* list;
    //printf("Ÿ��Ʋ ȭ���Դϴ�.\n");
    system("mode con cols=124 lines=40");
    while (1) {
        list = titledisplayrentbooks(&n);
        titlescreen();
        a = 8;
        for (int i = 0; i < n; i++) {
            gotoxy(56, a);
            printf("%s", list[i].bookname);
            gotoxy(83, a);
            printf("%s", list[i].rentalname);
            gotoxy(110, a);
            printf("%d", checkhowdoyouDIDNTreturn(list[i].retutime));
            a += 2;
        }
        gotoxy(6, 20);
        printf("����: ");
        scanf("%d", &choice);
        rewind(stdin);
        if (choice == 1) {
            addbookUI();
        }
        else if (choice == 2) {
            viewbooklistUI();
        }
        else if (choice == 0) {
            return;
        }
    }
}

void addbookUI(void) {
    Book newone;
    int choice;
    init_book(&newone);
    addbookscreen();
    //���� ��ũ��
    rewind(stdin);
    gotoxy(14, 5);
    //scanf("%s", newone.bookname);
    gettheCharactersfromUser(&newone.bookname);

    rewind(stdin);
    gotoxy(11, 8);
    //scanf("%s", newone.writername);
    gettheCharactersfromUser(&newone.writername);

    rewind(stdin);
    gotoxy(13, 11);
    //scanf("%s", newone.company);
    gettheCharactersfromUser(&newone.company);

    rewind(stdin);
    gotoxy(6, 19);
    printf("1. ���� 0. ���\n");
    gotoxy(6, 21);
    printf(">> ");
    scanf("%d", &choice);


    if (choice == 1) {
        addbook("Book.txt", newone);
        finishedaddbookUI();
        return;
    }
    else
        return;
}

void finishedaddbookUI(void) {
    finishedaddbookscreen();
    threesecondtimer(60, 17);
}

void printbooklist(Book a, int rentedunrented, int Y) {
    if (rentedunrented == 0) {
        gotoxy(5, Y);
        printf("%s", a.bookname);
        gotoxy(31, Y);
        printf("%s", a.writername);
        gotoxy(45, Y);
        printf("%s", a.company);
        gotoxy(68, Y);
        printf("X");
    }
    else {
        int recentdays;
        gotoxy(5, Y);
        printf("%s", a.bookname);
        gotoxy(31, Y);
        printf("%s", a.writername);
        gotoxy(45, Y);
        printf("%s", a.company);
        gotoxy(64, Y);
        printf("%s", a.rentalname);
        gotoxy(78, Y);
        printf("%s", a.retutime);
        recentdays = checkhowdoyouDIDNTreturn(a.retutime);
        if (recentdays < 0) {
            gotoxy(96, Y);
            printf("%d", abs(recentdays));
            gotoxy(109, Y);
            printf("%d", 0);
        }
        else {
            gotoxy(96, Y);
            printf("%d", 0);
            gotoxy(109, Y);
            printf("%d", recentdays);
        }

    }
    //printf("%s      %s      %s      %d\n", pagelist[i]->bookname, pagelist[i]->writername, pagelist[i]->company, pagelist[i]->rent);


}

void printnumbers(int drawdelete, int n) {
    int Y = 7;
    int a = 1;

    if (drawdelete == 1) {
        for (int i = 0; i <= n; i++) {
            gotoxy(3, Y);
            printf("  ");
            Y += 2;
        }
    }
    else {
        for (int i = 0; i <= n; i++) {
            gotoxy(3, Y);
            printf("%d.", a);
            Y += 2;
            a += 1;
        }
    }
}

void viewbooklistUI(void) {
    int n, rn, choice, changetherentedunrented = 0;      //n�� �뿩������ ���� ������ ����, rn�� �뿩���� ������ ����
    int page = 1, i, display, max, maxpage;
    Book** pagelist;
    n = 0; rn = 0;

    fileLead("Book.txt", &n, &rn);
    if (n == 0) {
        if (rn == 0) {
            printf("��ϵ� ������ �����ϴ�. \n");
            return;
        }
        else changetherentedunrented = 1;
    }

    while (1) {
        viewbooklistscreen();
        int bookchoice;
        int Y;
        if (changetherentedunrented == 0) {
            gotoxy(5, 4);
            printf("�������� ����");
            gotoxy(64, 5);
            printf("�뿩 ����                                                                        ");
            max = n;
        }
        else {
            max = rn;
            gotoxy(5, 4);
            printf("�뿩���� ����");
            gotoxy(64, 5);
            printf("�뿩��        �ݳ���         ��������      ��ü��          ");
        }

        if (max % 5 == 0) {
            maxpage = max / 5;
        }
        else
            maxpage = (max / 5) + 1;

        pagelist = getbooklist(changetherentedunrented, max, page, &display);
        Y = 7;
        for (i = 0; i <= (display - 1 )% 5; i++) {

            printbooklist(*pagelist[i], changetherentedunrented, Y);
            //printf("%s      %s      %s      %d\n", pagelist[i]->bookname, pagelist[i]->writername, pagelist[i]->company, pagelist[i]->rent);
            Y += 2;
        }
        gotoxy(13, 3);
        
        printf("%d of %d", page, maxpage);
        gotoxy(5, 18);
        if (page != 1)
            printf("1. ����������   ");
        if (max != display)
            printf("2. ����������   ");
        printf("3. ����Ʈ ����   4. Ű���� �˻�   ");
        if (changetherentedunrented == 1) {
            if (n > 0) {
                printf("5. �������� ���� ��ȸ   ");
            }
        }
        else {
            if (rn > 0) {
                printf("5. �뿩���� ���� ��ȸ   ");
            }
        }
        gotoxy(100, 18);
        printf("0. �ڷΰ���");
        gotoxy(5, 20);
        printf("��ȣ�� �Է��ϼ���. ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (page > 1) {
                page -= 1;
            }
            break;
        case 2:
            if (max != display) {
                page += 1;
            }
            break;
        case 3:
            printnumbers(0, (display - 1) % 5);
            gotoxy(5, 20);
            printf("                                                                                     ");
            gotoxy(5, 18);
            printf("                                                                                     ");
            gotoxy(5, 20);
            printf("å�� �����ϼ���: ");
            scanf("%d", &bookchoice);
            if (bookchoice == 0) {
                break;
            }

            //display�ǰ� �ִ� ���� ����Ʈ ���� ���ʿ� index + 1 ����ϴ� �ڵ� �߰�

            bookdetailsUI(pagelist[bookchoice - 1]);
            fileLead("Book.txt", &n, &rn);
            break;
        case 4:
            searchbookUI();
            fileLead("Book.txt", &n, &rn);
        case 5:
            if (changetherentedunrented) {
                if (n > 0) {
                    changetherentedunrented = 0;
                }
                else
                    printf("�߸��� �Է��Դϴ�.\n");
            }
            else {
                if (rn > 0) {
                    changetherentedunrented = 1;
                }
                else
                    printf("�߸��� �Է��Դϴ�.\n");
            }
            break;
        case 0:
            return;
        }
    }
}

void bookdetailsUI(Book* one) {
    int choice, recentdays;
    while (1) {
        bookdetailsscreen();

        gotoxy(16, 5);
        printf("%s", one->bookname);
        gotoxy(14, 8);
        printf("%s", one->writername);
        gotoxy(16, 11);
        printf("%s", one->company);
        gotoxy(19, 14);
        if (one->rent == 0) {
            printf("X");
        }
        else printf("O");

        if (one->rent == 1) {
            gotoxy(60, 5);
            printf("�뿩��: ");
            printf("%s", one->rentalname);
            gotoxy(60, 8);
            printf("�뿩��¥: ");
            printf("%s", one->rentaltime);
            gotoxy(60, 11);
            printf("�ݳ�������¥: ");
            printf("%s", one->retutime);
            gotoxy(60, 14);

            recentdays = checkhowdoyouDIDNTreturn(one->retutime);

            if (recentdays <= 0) {
                printf("���� ����: ");
                printf("%d", abs(recentdays));
            }
            else {
                printf("��ü��: ");
                printf("%d", recentdays);
            }
        }

        gotoxy(8, 17);
        printf("1. ����/����    ");
        if (one->rent == 0)
            printf("2. �뿩   \n");
        else
            printf("2. �ݳ�   \n");
        gotoxy(8, 19);
        printf("0. �ڷΰ���\n");
        gotoxy(8, 21);
        printf("��ȣ�� �Է��ϼ���. ");
        scanf("%d", &choice);
        rewind(stdin);
        switch (choice) {
        case 1:
            detailretouchordeleteUI(one);
            if (one->rent == -1)
                return;
            break;
        case 2:
            if (one->rent == 0)
                rentalbookUI(one);
            else
                returnbookUI(one);
            return;
        case 0:
            return;
        }
    }
}

void rentalbookUI(Book* one) {
    char *rentalname, *chrentalday, *chreturnday;
    int d;
    rentthebookscreen();

    gotoxy(16, 11);
    printf("%s", one->company);
    gotoxy(14, 8);
    printf("%s", one->writername);
    gotoxy(16, 5);
    printf("%s", one->bookname);

    gotoxy(8, 19);
    printf("�뿩��: ");
    gettheCharactersfromUser(&rentalname);
    while (1) {
        gotoxy(70, 19);
        printf("�뿩��: ");
        gettheCharactersfromUser(&chrentalday);
        if (strlen(chrentalday) == 8) {
            break;
        }
        else {
            gotoxy(70, 19);
            printf("                                                                       ");
        }
    }
    while (1) {
        gotoxy(70, 21);
        printf("�ݳ� ������: ");
        gettheCharactersfromUser(&chreturnday);
        if (strlen(chreturnday) == 8) {
            break;
        }
        else {
            gotoxy(70, 21);
            printf("                                                                       ");
        }
    }

    gotoxy(8, 21);
    printf("�����Ͻðڽ��ϱ�? (1 ���� 0 ���)");
    gotoxy(8, 22);
    printf(">> ");
    scanf("%d", &d);
    rewind(stdin);

    if (d == 1) {
        rentthebook(one, rentalname, chrentalday, chreturnday);
        return;
    }
    return;

}

void detailretouchordeleteUI(Book* one) {
    int choice;
    Book afterrewrite;

    afterrewrite = *one;
    detailretouchscreen();

    while (1) {

        gotoxy(18, 5);
        printf("%s", afterrewrite.bookname);
        gotoxy(18, 8);
        printf("%s", afterrewrite.writername);
        gotoxy(18, 11);
        printf("%s", afterrewrite.company);
        gotoxy(18, 14);

        if (afterrewrite.rent == 1) {
            gotoxy(43, 5);
            printf("4. �뿩��: ");
            printf("%s", afterrewrite.rentalname);
            gotoxy(43, 8);
            printf("5. �뿩 ��¥: ");
            printf("%s", afterrewrite.rentaltime);
            gotoxy(43, 11);
            printf("6. �ݳ����� ��¥");
            printf("%s", afterrewrite.retutime);
        }
        gotoxy(8, 17);
        printf("������ ��ȣ�� �Է����ּ���. (8.���� Ȯ�� 9. ���� 0. �ڷΰ���)");
        gotoxy(8, 18);
        printf(">> ");
        scanf("%d", &choice);
        rewind(stdin);
        
        gotoxy(8, 19);
        switch (choice) {
        case 1:
            printf("������: ");
            gettheCharactersfromUser(&afterrewrite.bookname);
            system("cls");
            detailretouchscreen();
            break;
        case 2:
            printf("����: ");
            gettheCharactersfromUser(&afterrewrite.writername);
            system("cls");
            detailretouchscreen();
            break;
        case 3:
            printf("���ǻ�: ");
            gettheCharactersfromUser(&afterrewrite.company);
            system("cls");
            detailretouchscreen();
            break;
        case 4:
            if (afterrewrite.rent == 0) {
                system("cls");
                detailretouchscreen();
                break;
            }
            printf("�뿩��: ");
            gettheCharactersfromUser(&afterrewrite.rentalname);
            system("cls");
            detailretouchscreen();
            break;
        case 5:
            if (afterrewrite.rent == 0) {
                system("cls");
                detailretouchscreen();
                break;
            }
            printf("�뿩��: ");
            gettheCharactersfromUser(&afterrewrite.rentaltime);
            system("cls");
            detailretouchscreen();
            break;
        case 6:
            if (afterrewrite.rent == 0) {
                system("cls");
                detailretouchscreen();
                break;
            }
            printf("�ݳ�������: ");
            gettheCharactersfromUser(&afterrewrite.retutime);
            system("cls");
            detailretouchscreen();
            break;
        case 8:
            checkretouchUI(one, afterrewrite);
            return;
        case 9:
            checkdeleteUI(one);
            return;
        case 0:
            return;
        }
    }

}

void checkretouchUI(Book* old, Book afterrewrite) {
    int choice;

    checkretouchscreen();

    gotoxy(14, 6);
    printf("%s", old->bookname);
    gotoxy(12, 9);
    printf("%s", old->writername);
    gotoxy(14, 12);
    printf("%s", old->company);
    gotoxy(72, 6);
    printf("%s", afterrewrite.bookname);
    gotoxy(70, 9);
    printf("%s", afterrewrite.writername);
    gotoxy(72, 12);
    printf("%s", afterrewrite.company);
    if (old->rent == 1) {
        gotoxy(29, 6);
        printf("�뿩��: ");
        printf("%s", old->rentalname);
        gotoxy(29, 9);
        printf("�뿩 ��¥: ");
        printf("%s", old->rentaltime);
        gotoxy(29, 12);
        printf("�ݳ� ���� ��¥: ");
        printf("%s", old->retutime);
        gotoxy(87, 6);
        printf("�뿩��: ");
        printf("%s", afterrewrite.rentalname);
        gotoxy(87, 9);
        printf("�뿩 ��¥: ");
        printf("%s", afterrewrite.rentaltime);
        gotoxy(87, 12);
        printf("�ݳ� ���� ��¥: ");
        printf("%s", afterrewrite.retutime);
    }

    gotoxy(5, 20);
    printf("1. �Ϸ�   0. ���\n\n");
    scanf("%d", &choice);
    rewind(stdin);

    if (choice == 1) {
        *old = afterrewrite;
        savethefile("Book.txt");
    }
    

    return;


}

void checkdeleteUI(Book* one) {
    int choice;


    while (1) {
        gotoxy(8, 17);
        printf("                                                                       ");
        gotoxy(8, 18);
        printf("                                                                       ");
        gotoxy(8, 17);
        printf("������ �����Ͻðڽ��ϱ�? (1 ����  0 ���)");
        gotoxy(8, 18);
        printf(">> ");
        scanf("%d", &choice);
        rewind(stdin);

        switch (choice) {
        case 1:
            one->rent = -1;
            savethefile("Book.txt");
            return;
        case 0:
            return;
        default:
            break;
        }
    }
}

void returnbookUI(Book* one) {
    int choice;

    returnthebookscreen();

    while (1) {
        gotoxy(8, 19);
        printf("                                                                                                          ");
        gotoxy(8, 19);
        printf(">> ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            returnthebook(one);
            return;

        case 2:
            return;
        default:
            return;
        }
    }
    


}

//list -> ��ϵ��� ��� ������, n -> ��ϵ� ���� ����
void searchbookUI(void) {
    char keyword[200];
    Book** searchresult;
    int n, count, Y, maxpage, choice = 100, bookchoice;
    count = 0;

    keywordsearchscreen();
    gotoxy(13, 4);
    scanf("%s", keyword);
    searchresult = search_book(keyword, &n);


    while (1) {
        if (choice == 9) {
            keywordsearchscreen();
            gotoxy(13, 4);
            scanf("%s", keyword);
            searchresult = search_book(keyword, &n);
        }
        
        if (n % 5 != 0) {
            maxpage = n / 5 + 1;
        }
        else maxpage = n / 5;
        gotoxy(13, 4);
        printf("%s", keyword);
        gotoxy(5, 3);
        printf("������: %d of %d", count + 1, maxpage);
        
        Y = 7;
        for (int i = count * 5; i < (n % 5) + count * 5; i++) {
            printbooklist(*searchresult[i], 0, Y);
            Y += 2;
        }
        gotoxy(5, 18);
        if (count != 0)
            printf("1. ����������   ");
        if (n >= 5 * (count + 1))
            printf("2. ����������   ");
        printf("3. ����Ʈ ����   ");
        printf("9. Ű���� ���Է�");
        gotoxy(5, 20);
        printf("��ȣ�� �Է��ϼ���. ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count > 0) {
                count -= 1;
            }
            break;
        case 2:
            if ((count + 1) < maxpage) {
                count + 1;
            }
            break;
        case 3:
            printnumbers(0, (((n % 5) + count * 5) - 1) % 5);
            gotoxy(5, 20);
            printf("                                                                                     ");
            gotoxy(5, 18);
            printf("                                                                                     ");
            gotoxy(5, 20);
            printf("å�� �����ϼ���: ");
            scanf("%d", &bookchoice);
            if (bookchoice == 0) {
                break;
            }

            bookdetailsUI(searchresult[bookchoice - 1]);
            fileLead("Book.txt", &Y, &bookchoice);
            break;
        case 9:
            break;
        case 0:
            return;
        }
        rewind(stdin);
    }

}