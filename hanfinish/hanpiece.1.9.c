#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

void intro();
void rptrun();
void crtrun();
void winner();
void RP_at();

int rphp;
int crhp;
int rpat;
int crat;


int damage;
int money;
int crsd;
int num1 = 0;
int power = 1;
int start;

#define _C 1046.502
#define _D 1108.731
#define _E 1318.510
#define _F 1396.913
#define _G 1567.982
#define _A 1760.000
#define _B 1975.533

void music()
{
    
        Beep(_C, 100);
        Sleep(200);
        Beep(_D, 100);
        Sleep(200);
        Beep(_E, 100);
        Sleep(200);
        Beep(_C, 100);
        Sleep(200);
        Beep(_C, 100);
        Sleep(200);
        Beep(_C, 100);
        Sleep(200);
        Beep(_B, 100);
        Sleep(200);
    

}
void music_1()
{

    Beep(_C, 100);
    Sleep(200);
    Beep(_D, 100);
    Sleep(200);
    Beep(_E, 100);
    Sleep(200);
    Beep(_C, 100);
    Sleep(200);
    Beep(_C, 100);
    Sleep(200);
    Beep(_C, 100);
    Sleep(200);
    Beep(_A, 100);
    Sleep(200);


}

void intro() {

    printf("\n");

    printf("==���ǽ��� ��������.==\n\n\n\n\n�������� �� �糪�� ���Ǵ� \n ���� �޸�ȣ�� Ÿ�� ���� ������.\n\n");
    
    printf("�ٴٸ� ������ �� \nĥ���� ũ��ĿŸ���� ���� ������ �������µ� ...\n\n");
    
    printf("������ ���� ����! ���� �̱� �� ���� ���ΰ�?\n\n");
    
    printf("�ε�!\n\n\n");
    
    printf("press <ENTER> to continue..\n\n\n\n\n\n");

    if (start == 1) {
        getchar();
    }
    else { printf("\n"); };
    start = 0;
}

void rpturn() {
    printf("========���� ����===========\n");
    printf(" 1. ����!\n");
    printf(" 2. �� ������\n");
    printf("===========================\n\n");
    printf("���ǰ� �� �ൿ�� �����ϼ���(1/2) : ");
    scanf_s("%d", &num1);
    if (num1 == 1) {
        printf("\n������ ���� : ���� ��! x %d \n\n", power);
        RP_at();
    }
    else if (num1 == 2) {
        printf("\n���ǰ� �⸦ ������ �ֽ��ϴ�...\n");
        power = power * 2;
        printf("------------------------------------\n����       HP: %d, ��: %d�� \n", rphp, power);
        printf("ũ��Ŀ���� HP: %d\n\n", crhp);
    }

}
void RP_at() {
    if (crsd == 0) {
        int damage = rpat / 2 * power;
        int crhp1 = crhp;
        crhp = (crhp - damage) > 0 ? (crhp - damage) : 0;

        printf("ũ��Ŀ���� : %d-%d=%d, �𷡷� ����\n\n", crhp1, damage, crhp);
        power = 1;
        printf("------------------------------------\n����       HP: %d, �� : %d�� \n", rphp, power);
        printf("ũ��Ŀ���� : %d-%d=%d, �𷡷� ����\n\n", crhp1, damage, crhp);
    }
    else {
        int damage = rpat * power;
        int crhp1 = crhp;
        crhp = (crhp - damage) > 0 ? (crhp - damage) : 0;
        printf("------------------------------------\n����       HP: %d, �� : %d�� \n", rphp, power);
        printf("ũ��Ŀ���� : %d-%d=%d \n\n\n\n\n\n", crhp1, damage, crhp);
    }
}

void crturn() {
    printf("========ũ��Ŀ���� ����===========\n");
    int cr = rand() % 3;

    if (cr == 0) {
        printf(" ũ��Ŀ������ ���� : '�縷�� ��ǳ!'\n");
        printf("�������� �޾Ƽ� ���ǰ� ��Ƶ� �Ⱑ ������ϴ�.\n");
        power = 1;
        printf("------------------------------------\n����       HP: %d - %d = %d,��: %d�� \n", rphp, crat, (rphp - crat) > 0 ? (rphp - crat) : 0, power);

        printf("ũ��Ŀ���� HP: %d\n\n\n\n\n\n\n\n", crhp);
        rphp -= crat;
    }
    else if (cr == 1) {
        crsd = 1;
        printf("ũ��Ŀ������ ���� �𷡷� �ٲߴϴ�.\n");
        printf("------------------------------------\n����       HP: %d, �� : %d�� \n", rphp, power);
        printf("ũ��Ŀ���� HP: %d, �𷡷� ���� \n\n", crhp);
    }
    else {
        printf("ũ��Ŀ������ ������ �θ��ϴ�: '�ϰ� ĥ���ذ� ���� �˾�?'.\n");
        printf("------------------------------------\n����       HP: %d, ��: %d�� \n", rphp, power);
        printf("ũ��Ŀ���� HP: %d\n\n", crhp);
    }
}
void winner() {
    while (1) {
        rpturn();

        if (crhp <= 0) {
            printf("\n���ǰ� ũ��Ŀ������ �����߷ȴ�!\n");
            int AWARD = rand() % 501 + 500;
            printf("\n���ڴ� ����!\nũ��Ŀ���Ͽ��� %d���� �����ߴ�!\n", AWARD);
            money += AWARD;
            break;
        }
        crturn();
        if (rphp <= 0) {
            printf("\nĥ������ ���� �ʹ� ���Ҵ�...\n���ڴ� ũ��Ŀ����!\nũ��Ŀ���Ͽ��� ���� ���� ��� ���Ѱ��!\n");
            money = 0;
            break;
        }
    }
}


int battle(void) {

    int rphp = 0;
    int crhp = 0;
    int rpat = 0;
    int crat = 0;


    rpturn();
    crturn();
    winner();
}