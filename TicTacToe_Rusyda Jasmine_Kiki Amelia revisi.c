/* Nama : Rusyda Jasmine Rachmat & Kiki Rizki Amelia
	NIM : 201524059 & 201524048
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include<time.h>

//Deklarasi Modul
char bidak[3][3];
char checkwin();
void Board();
void InisialisasiBidak();
void LevelMenu();
void HowToPlay();
void About();
void PlayGame();
void PlayGameMedium();
void PlayGameHard();
void PlayerMove();
void ComputerMove();
void ComputerMoveMedium();
void ComputerMoveHard();
void QuizLevel1();
void QuizLevel2();
void QuizLevel3();

//Variabel Global
int levelmenuoption;

//Progam Utama
int main(){
	int mainmenuoption;
	printf("======= MAIN MENU =======\n");
	printf("1. Start\n");
	printf("2. How To Play\n");
	printf("3. About\n");
	printf("4. Exit\n");
	
	printf("Enter a number : "); scanf("%d", &mainmenuoption);
	
	//Kondisi saat memilih pilihan menu
	if(mainmenuoption == 1){
		LevelMenu(); //Masuk ke menu level
	}else if(mainmenuoption == 2){
		HowToPlay(); //Masuk ke help
	}else if(mainmenuoption == 3){
		About(); //Masuk ke about
	}else{
		
	}
	
	return 0;
}

//Tampilan Pilihan Level
void LevelMenu(){
	system("cls");
	
	printf("======= LEVEL MENU =======\n");
	printf("1. Easy\n");
	printf("2. Medium\n");
	printf("3. Hard\n");
	
	printf("Enter a number : "); scanf("%d", &levelmenuoption);
	
	if(levelmenuoption == 1){
		QuizLevel1(); //Masuk ke play game easy
	}else if(levelmenuoption == 2){
		QuizLevel2(); //Masuk ke quiz level 2
	}else if(levelmenuoption == 3){
		QuizLevel3(); //Masuk ke quiz level 3
	}
}

//Quiz untuk Level 1
void QuizLevel1(){
	system("cls");
	int quizanswer, result;
	
	result = 1 + 1; 
	
	do{
		printf("Hasil dari 1 + 1 adalah ");scanf("%d", &quizanswer);
		
		if(quizanswer == result){ //Jika jawaban benar, lanjut ke permainan
			PlayGame(); 
		}else{ //Jika jawaban salah, user harus menginput ulang sampai jawabannya benar
			system("cls");
			printf("Wrong answer! Try Again\n");
		}
	}while(quizanswer != result);
}

//Quiz untuk Level 2
void QuizLevel2(){
	system("cls");
	int quizanswer, result;
	
	result = 18 * 11; 
	
	do{
		printf("Hasil dari 18 x 11 adalah ");scanf("%d", &quizanswer);
		
		if(quizanswer == result){ //Jika jawaban benar, lanjut ke permainan
			PlayGame(); 
		}else{ //Jika jawaban salah, user harus menginput ulang sampai jawabannya benar
			system("cls");
			printf("Wrong answer! Try Again\n");
		}
	}while(quizanswer != result);
}

//Quiz untuk level 3
void QuizLevel3(){
	system("cls");
	int quizanswer, result;
	
	result = 5 + 2 * 3 + (10 - 1);
	
	do{
		printf("Hasil dari 5 + 2 x 3 + (10 - 1) adalah "); scanf("%d", &quizanswer);
		
		if(quizanswer == result){ //Jika jawaban benar, lanjut ke permainan
			PlayGame(); 
		}else{ //Jika jawaban salah, user harus menginput ulang sampai jawabannya benar
			system("cls");
			printf("Wrong answer! Try Again\n");
		}
	}while(quizanswer != result);
}



//Modul untuk permainan level easy dimulai
void PlayGame(){
	system("cls");
	char done; 
	printf("This is the game of Tic Tac Toe.\n"); 
	printf("You will be playing against the computer.\n"); 
	done = ' ';
	InisialisasiBidak(); 
	
	do{
		Board(); 
		PlayerMove(); 
		done = checkwin(); /* mengecek kemenangan pada inputan player */ 
		if(done!= ' ') break; /* jika terjadi kemenangan, perulangan akan berhenti!*/ 
		ComputerMove(); 
		done = checkwin(); /* mengecek kemenangan pada inputan komputer */ 
	} while(done == ' '); 
	 
	 Board();
	 
	if(done=='X'){
		printf("You won!\n");
	} 
	else{
		printf("Computer won!\n");
	}
	

}

void PlayerMove(){
	int x, y, t; 
	int batasWaktuInput;
		double waktuInput = 0;
	
	if(levelmenuoption == 1){
		batasWaktuInput = 15;
	} else if(levelmenuoption == 2){
		batasWaktuInput = 10;
	} else if(levelmenuoption == 3){
		batasWaktuInput = 5;
	} 
		t = StartTime();
		
			printf("Enter X,Y coordinates for your move: "); 
			scanf("%d%*c%d", &x, &y); 
		
		t = EndTime() - t;
		
		waktuInput = ((double) t)/CLOCKS_PER_SEC;
		
		if(waktuInput>batasWaktuInput){
			printf("Anda Melebihi Batas Waktu Lebih Dari %d Detik, Giliran di Ganti",batasWaktuInput);
			printf("\nWaktu Anda Adalah %2.f Detik", waktuInput);			
			Sleep(3000);
		}

	x--; y--; 
	
	if(bidak[x][y] != ' '){ 
		printf("Invalid move, try again.\n"); 
		PlayerMove(); 
	} 
	else{
		bidak[x][y] = 'X';
	} 
}

void InisialisasiBidak(){ 
	int i, j; 
	
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			bidak[i][j] = ' ';
		}
	} 
} 

void ComputerMove(){
	int i, j; 
	for(i=0; i<3; i++){ 
		for(j=0; j<3; j++)
		if(bidak[i][j]==' '){
			break; 	
		}
		if(bidak[i][j]==' '){
			break;
		} 
	} 
 
	if(i * j == 9) { 
		printf("Draw\n"); 
		exit(0); 
	} 
	else{
		bidak[i][j] = 'O';
	}  
}

char checkwin(){
    int i; 
	
	for(i=0; i<3; i++){
		/* check rows */ 
		if(bidak[i][0]==bidak[i][1] && bidak[i][0]==bidak[i][2]){
			return bidak[i][0];
		}
	}

	for(i=0; i<3; i++){
		/* check columns */ 
		if(bidak[0][i]==bidak[1][i] && bidak[0][i]==bidak[2][i]){
			return bidak[0][i];
		}
	}
	 
	/* test diagonals */ 
	if(bidak[0][0]==bidak[1][1] && bidak[1][1]==bidak[2][2]) {
		return bidak[0][0];
	} 
	if(bidak[0][2]==bidak[1][1] && bidak[1][1]==bidak[2][0]){
		return bidak[0][2];
	} 
	
	return ' '; 
}

void Board(){
    system("cls");
	
	printf("========== PAPAN PERMAINAN ==========\n");
	printf("You : X                  Computer : O\n");
	
	printf(" ________ ________ ________ \n");
	printf("|1,1     |1,2     |1,3     |\n");
	printf("|   %c    |  %c     |  %c     |\n", bidak[0][0], bidak[0][1], bidak [0][2]);
	printf("|________|________|________|\n");
	printf("|2,1     |2,2     |2,3     |\n");
	printf("|   %c    |  %c     |  %c     |\n", bidak[1][0], bidak[1][1], bidak [1][2]);
	printf("|________|________|________|\n");
	printf("|3,1     |3,2     |3,3     |\n");
	printf("|   %c    |  %c     |  %c     |\n", bidak[2][0], bidak[2][1], bidak [2][2]);
	printf("|________|________|________|\n");
	 
	printf("\n"); 
}

//Tampilan How To Play
void HowToPlay(){
	system("cls");
	printf("How To Play\n");
	printf(" 1. Klik start game pada main menu\n");
	printf(" 2. Pilih level\n");
	printf(" 3. Jawablah kuis yang disediakan pada setiap level\n");
	printf(" 4. Game dimulai sesuai dengan waktu yang ditentukan\n");
	printf(" 5. Jika anda mendapatkan skor sebanyak 1 poin lebih dulu dari player komputer, anda adalah pemenangnya\n");
	printf(" 6. Jika player komputer mendapatkan skor 1 poin lebih dulu dari anda, anda kalah\n");
	printf(" 7. Jika waktu habis, anda dapat kembali ke main menu\n");
	printf(" 8. Jika anda ingin keluar, silahkan klik exit pada main menu\n");
}

//Tampilan About
void About(){
	system("cls");
	printf("About\n");
	printf(" Game ini dibuat untuk melengkapi tugas besar mata kuliah dasar dasar pemrograman pada semester 1. Game ini dibuat oleh Kiki Rizki Amelia (201524048) dan Rusyda Jasmine Rachmat (201524059) dari kelas 1B - D4 Teknik Informatika\n");
}

int StartTime(){
    clock_t startInput;
    startInput = clock();

    return startInput;
}

// Modul EndTime()
// Referensi dari kelompok Arsal & Naufal
// Modul untuk mencatat waktu terakhir dihitung
int EndTime(){
    clock_t endInput;
    endInput = clock();

    return endInput;
}

