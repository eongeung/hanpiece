#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

#define TRESURE 0
#define ITEM 1
#define BATTLE 2


int damage;
int Q;
int start = 0;
int blank_1;
int blank_2;
int blank_3;
int money = 1000;
int ppower;
int end;

extern int rphp;
extern int crhp;
extern int rpat;
extern int crat;

void spin(int, char);
void spin(int n, char lett) {
    for (int i = 1; i <= n; i++) {
        printf("%c", lett);
    }
}

void voyage() {

    if (Q > 11) {
        printf("\n********************\n");
        spin(10, ' ');
        printf("M");
        spin(blank_1, ' ');
        printf("?");
        blank_1--;
        printf("\n********************\n");
    }
    else if (Q == 11) {
        printf("\n********************\n          !          \n*********************");

    }
    else if (Q < 11) {
        printf("\n********************\n");
        spin(blank_3, ' ');
        printf("?");
        spin(blank_2, ' ');
        printf("M");
        blank_3--;
        blank_2++;
        printf("\n********************\n");
    }
}
void finish() {
    if (money >= 2000) {
        printf("���Ǵ� % d��带 ��� �������� �Ǿ��ٰ� �Ѵ�..", money);
        end = 0;
    }
    else if (money <= 0) {
        printf("���� ���� �� ���� ���Ǵ� ������ �����ϰ� �ȴ�...");
        end = 1;
    }
    else intro();
}

void event() {
    srand((unsigned int)time(NULL));
    int event = rand() % 3;
    if (event == 0) {
        int TR_MONEY = rand() % 500;
        printf("\n�������ڿ��� %d ��带 �߰��ߴ�!\n", TR_MONEY);
        money += TR_MONEY;
    }
    else if (event == 1) {
        int TR_power = rand() % 6 + 5;
        printf("\n�������� �߰��ߴ�!\n������ �߰� ���ݷ��� %d�� �Ǿ���.\n", TR_power);
        ppower = TR_power;

    }
    else {
        printf("\n�ƴ� ���ڴ�! ĥ���� ũ��Ŀ����!\n\n");
        srand((unsigned int)time(NULL));
        int rphp = rand() % 21 + 20;
        int rpat = rand() % 11 + 5;
        int crhp = rand() % 21 + 30;
        int crat = rand() % 11 + 10;
        printf("------------------------------------\n����       HP: %d,   ���ݷ�: %d + %d\n", rphp, rpat, ppower);
        printf("ũ��Ŀ���� HP: %d,   ���ݷ�: %d\n\n\n\n\n\n\n\n\n", crhp, crat);
        battle();
    }
}
int main() {
   
    start = 1;
    music();
    music_1();
    while (1) {
        blank_1 = 9;
        blank_2 = 0;
        blank_3 = 9;


        for (Q = 21; Q >= 1; Q--) {

            intro();
            start = 0;
            printf("������ : %d ���\n�߰� ���ݷ� : %d", money, ppower);
            voyage();
            if (Q == 11) {
                event();
                finish();
                Sleep(3000);
            }
            else {
                Sleep(200);
                system("cls");
            }
            if (end == 1) {
                break;
            }
        }

    }
    return 0;
}