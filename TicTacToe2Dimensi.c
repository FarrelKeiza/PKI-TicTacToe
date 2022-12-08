#include<stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>

char kotak[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
int cekPemenang();
void cetakPapan();

int main(){
  int player = 1, pilih, i;
  char simbol;
  do{
      cetakPapan();
      player = (player % 2) ? 1 : 2;
      printf("Player %d masukkan angka!", player);
      scanf("%d", &pilih);
      simbol = (player ==1) ? 'X' : 'O';
      if(pilih == 1 && kotak[0][0] == '1')
        kotak[0][0] = simbol;
      else if(pilih == 2 && kotak[0][1] == '2')
        kotak[0][1] = simbol;
        else if(pilih == 3 && kotak[0][2] == '3')
        kotak[0][2] = simbol;
        else if(pilih == 4 && kotak[1][0] == '4')
        kotak[1][0] = simbol;
        else if(pilih == 5 && kotak[1][1] == '5')
        kotak[1][1] = simbol;
        else if(pilih == 6 && kotak[1][2] == '6')
        kotak[1][2] = simbol;
        else if(pilih == 7 && kotak[2][0] == '7')
        kotak[2][0] = simbol;
        else if(pilih == 8 && kotak[2][1] == '8')
        kotak[2][1] = simbol;
        else if(pilih == 9 && kotak[2][2] == '9')
        kotak[2][2] = simbol;

      else {
        printf("INVALID!!!");
        player--;
        getch();
      }
      i = cekPemenang();
      player++;

    } while(i == -1);
    
    cetakPapan();
    if (i == 1){
    printf("Player %d adalah PEMENANG!!!", --player);
    } 
    else {
    printf("GAME SERI!!!");
    }

    getch();
    return 0;
}

int cekPemenang(){
    if (kotak[0][0] == kotak [0][1] && kotak[0][1] == kotak[0][2])
        return 1;
    else if (kotak[1][0] == kotak [1][1] && kotak[1][1] == kotak[1][2])
        return 1;
    else if (kotak[2][0] == kotak [2][1] && kotak[2][1] == kotak[2][2])
        return 1;
    else if (kotak[0][0] == kotak [1][0] && kotak[1][0] == kotak[2][0])
        return 1;
    else if (kotak[0][1] == kotak [1][1] && kotak[1][1] == kotak[2][1])
        return 1;
    else if (kotak[0][2] == kotak [1][2] && kotak[1][2] == kotak[2][2])
        return 1;
    else if (kotak[0][0] == kotak [1][1] && kotak[1][1] == kotak[2][2])
        return 1;
    else if (kotak[0][2] == kotak [1][1] && kotak[1][1] == kotak[2][0])
        return 1;
    else if (kotak[0][0] != kotak[0][1] && kotak[0][1] != kotak[0][2] &&
             kotak[1][0] != kotak[1][1] && kotak[1][1] != kotak[1][2] &&
             kotak[2][0] != kotak[2][1] && kotak[2][1] != kotak[2][2] &&
             kotak[0][0] != kotak[1][0] && kotak[1][0] != kotak[2][0] &&
             kotak[0][1] != kotak[1][1] && kotak[1][1] != kotak[2][1] &&
             kotak[0][2] != kotak[1][2] && kotak[1][2] != kotak[2][2] &&
             kotak[0][0] != kotak[1][1] && kotak[1][1] != kotak[2][2] &&
             kotak[0][2] != kotak[1][1] && kotak[1][1] != kotak[2][0] )

        return -1;

}

void cetakPapan()
{
    system("cls");
    printf("\n\n\t TIC TAC TOE \n\n");
    printf("Player1 (X) VS Player2 (O) \n\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", kotak[0][0], kotak[0][1], kotak[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", kotak[1][0], kotak[1][1], kotak[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", kotak[2][0], kotak[2][1], kotak[2][2]);
    printf("     |     |     \n");
}