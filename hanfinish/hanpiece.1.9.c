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

    printf("==한피스를 시작하지.==\n\n\n\n\n해적왕이 될 사나이 루피는 \n 고잉 메리호를 타고 길을 떠난다.\n\n");
    
    printf("바다를 떠돌던 중 \n칠무해 크로커타일을 만나 전투가 벌어지는데 ...\n\n");
    
    printf("강적을 만난 루피! 과연 이길 수 있을 것인가?\n\n");
    
    printf("두둥!\n\n\n");
    
    printf("press <ENTER> to continue..\n\n\n\n\n\n");

    if (start == 1) {
        getchar();
    }
    else { printf("\n"); };
    start = 0;
}

void rpturn() {
    printf("========루피 차례===========\n");
    printf(" 1. 공격!\n");
    printf(" 2. 기 모으기\n");
    printf("===========================\n\n");
    printf("루피가 할 행동을 선택하세요(1/2) : ");
    scanf_s("%d", &num1);
    if (num1 == 1) {
        printf("\n루피의 공격 : 고무고무 총! x %d \n\n", power);
        RP_at();
    }
    else if (num1 == 2) {
        printf("\n루피가 기를 모으고 있습니다...\n");
        power = power * 2;
        printf("------------------------------------\n루피       HP: %d, 기: %d배 \n", rphp, power);
        printf("크로커다일 HP: %d\n\n", crhp);
    }

}
void RP_at() {
    if (crsd == 0) {
        int damage = rpat / 2 * power;
        int crhp1 = crhp;
        crhp = (crhp - damage) > 0 ? (crhp - damage) : 0;

        printf("크로커다일 : %d-%d=%d, 모래로 변신\n\n", crhp1, damage, crhp);
        power = 1;
        printf("------------------------------------\n루피       HP: %d, 기 : %d배 \n", rphp, power);
        printf("크로커다일 : %d-%d=%d, 모래로 변신\n\n", crhp1, damage, crhp);
    }
    else {
        int damage = rpat * power;
        int crhp1 = crhp;
        crhp = (crhp - damage) > 0 ? (crhp - damage) : 0;
        printf("------------------------------------\n루피       HP: %d, 기 : %d배 \n", rphp, power);
        printf("크로커다일 : %d-%d=%d \n\n\n\n\n\n", crhp1, damage, crhp);
    }
}

void crturn() {
    printf("========크로커다일 차례===========\n");
    int cr = rand() % 3;

    if (cr == 0) {
        printf(" 크로커다일의 공격 : '사막의 폭풍!'\n");
        printf("데미지를 받아서 루피가 모아둔 기가 흩어집니다.\n");
        power = 1;
        printf("------------------------------------\n루피       HP: %d - %d = %d,기: %d배 \n", rphp, crat, (rphp - crat) > 0 ? (rphp - crat) : 0, power);

        printf("크로커다일 HP: %d\n\n\n\n\n\n\n\n", crhp);
        rphp -= crat;
    }
    else if (cr == 1) {
        crsd = 1;
        printf("크로커다일이 몸을 모래로 바꿉니다.\n");
        printf("------------------------------------\n루피       HP: %d, 기 : %d배 \n", rphp, power);
        printf("크로커다일 HP: %d, 모래로 변신 \n\n", crhp);
    }
    else {
        printf("크로커다일은 여유를 부립니다: '니가 칠무해가 뭔지 알아?'.\n");
        printf("------------------------------------\n루피       HP: %d, 기: %d배 \n", rphp, power);
        printf("크로커다일 HP: %d\n\n", crhp);
    }
}
void winner() {
    while (1) {
        rpturn();

        if (crhp <= 0) {
            printf("\n루피가 크로커다일을 쓰러뜨렸다!\n");
            int AWARD = rand() % 501 + 500;
            printf("\n승자는 루피!\n크로커다일에게 %d원을 갈취했다!\n", AWARD);
            money += AWARD;
            break;
        }
        crturn();
        if (rphp <= 0) {
            printf("\n칠무해의 벽은 너무 높았다...\n승자는 크로커다일!\n크로커다일에게 가진 돈을 모두 빼앗겼다!\n");
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