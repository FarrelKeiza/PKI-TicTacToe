#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "body.h"

int main(){
		system("Color 4E"); 									/* Untuk mengganti tampilan warna, Untuk '4' adalah warna tampilan menu 
																menjadi warna merah dan 'E' warna tampilan teks menjadi warna kuning */
		ShowWindow(GetConsoleWindow(), SW_MAXIMIZE); 			/* Untuk program auto fullscreen saat pertama kali 
																di eksekusi (Memakai Library #include <windows.h> */
		int initialize; 										/* Sebagai penampung nilai integer inputan user */
		char scan; 												/* Sebagai penampung nilai char inputan user */ 
		game mainGame;
		player playerOne, playerTwo;
		readHighScore(mainGame.highScore);
		
		do{
				printMenu(); 									/* Memanggil modul printMenu(); untuk ditampilkan di program utama */
				if(initialize < 1 || initialize > 3){			/* Untuk sebagai validasi inputan user, jikalau nge input 1 > initialize > 3, 
																maka tampil string kosong*/
						printf("");
				} 																			 
				scanInteger(&initialize); 						/* Memanggil modul scanInteger(); untuk menginput nilai berdasarkan input user */
		}while(initialize < 1 || initialize > 3);				/* Kenapa memakai Do while, agar di print sekali dan, tidak akan 
													    		keluar dari perulangan jikalau input user 1 > initialize > 3 */
		
		switch(initialize){										/* Kenapa memakai switch-case, karena lebih simple secara code dibandingkan if-else */
				case 1:
						gameInitialization(&mainGame, &playerOne, &playerTwo);					/* Jikalau user meng input 1, maka program akan mengeksekusi modul gameInitialization(); */
						gameplay(mainGame, playerOne, playerTwo);
						break;
				case 2:
						do{
						printTutorial();						/* Jikalau user meng input 2, maka program akan mengeksekusi modul printTutorial(); */
						scanf(" %c", &scan);					/* Sebagai inputan user guna untuk kembali ke main menu */
								
						}while( scan != 'Y' && scan != 'y');	/* Do-while guna untuk user hanya dapat menginputkan 'Y' atau 'y' agar keluar dari perulangan*/
						main();									/* Jika berhasil keluar dari perulangan, maka akan memanggil main(); untuk kembali ke main menu */				
						
						break;
				
				case 3:
						do{
						printHighScore(mainGame.highScore);
						scanf(" %c", &scan);
								
						}while( scan != 'Y' && scan != 'y');
						main();
						break;
				case 4:
						return 0;							/* Jikalau user meng input 4, maka akan exit dari program */
		}
}

