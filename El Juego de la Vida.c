#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#define f 35
#define c 45
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void duplicar(int map[f][c], int map2[f][c]);
void imprimir(int map[f][c]);
void agregar(int map[f][c]);
void gotoxy(int x, int y);
void llenar(int map[f][c]);
void reiniciar(int map[f][c], int mp3[f][c]);
int main(int argc, char *argv[]) {
	char tecla;
	int j, k, cont = 0, ge = 0, na = 0, mu = 0, nv = 0, nm = 0, pn = 0, pm = 0, ct = 0, bp = 0, bp1 = 0, con = 0;
	char r;
	float pnp, pmp;
	int map[f][c];
	int map2[f][c];
	int map3[f][c];

	for(j = 0;j < f; j++){
		for(k = 0;k < c; k++){
			map[j][k] = 0;
			map3[j][k] = 0;
			map2[j][k] = 0;
		}
	}
	
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
	printf("\n\n\n\n\n\t\t\tEl Juego de la Vida");
	printf("\n\n\t\t1. Use W A S D para moverse\n\t\t2. Pulse SPACE para revivir o matar la celula\n\t\tDeben haber minimo 5 celulas vivas\n\t\t3. Presione L para iniciar el juego");
	system("pause>arch");
	
	
	do{		
		for(j = 0;j < f;j++){
			for(k = 0;k < c;k++){
				map[j][k] = map3[j][k];
			}
		}
		while(con < 5){
			llenar(map);
			ge = 0;
			for(j = 0;j < f; j++){
				for(k = 0;k < c; k++){
					if(map[j][k] == 1){	
					con++;
					}
				}
			}
			if(con < 5){
				con = 0;
			}
		}
		for(j = 0;j < f;j++){
			for(k = 0;k < c;k++){
				map3[j][k] = map[j][k];
			}
		}
		con = 0;
		while(kbhit() == 0 && bp == 0){
			imprimir(map);
			duplicar(map, map2);
		
			for(j = 0;j < f; j++){
				for(k = 0;k < c; k++){
					if(map2[j-1][k] == 1 && (j-1) >= 0){
						cont++;
					}
					if(map2[j+1][k] == 1 && (j+1)<f){
						cont++;
					}
					if(map2[j][k-1] == 1 && (k-1) >= 0){
						cont++;
					}
					if(map2[j][k+1] == 1 && (k+1) < c){
						cont++;
					}
					if(map2[j-1][k+1] == 1 && (j-1) >= 0 && (k+1) < c){
						cont++;
					}	
					if(map2[j+1][k-1] == 1 && (j+1)<f && (k-1)>=0){
						cont++;
					}
					if(map2[j-1][k-1] == 1 && (j-1)>=0 && (k-1)>=0){
						cont++;
					}
					if(map2[j+1][k+1] == 1 && (j+1)<f && (k+1)<c){
						cont++;
					}
					//Conteo de Celulas vivas adyacentes
					if(map2[j][k] == 1){
						if(cont <= 1){
							map[j][k] = 0; //Soledad
							pm++;
							bp1++;
						}
						if(cont >= 4){
							map[j][k] = 0; //Sobrepoblacion
							pm++;
							bp1++;
						}
						if(cont == 2 || cont == 3){
							map[j][k] = 1;
						}
					}
					if(map2[j][k] == 0){
						if(cont == 3){
							map[j][k] = 1;//Revivir una celula
							pn++;
							bp1++;
						}
					}
					cont = 0;
				}	
			}
			ge++;
			Sleep(100);
			if(bp1 == 0){
				bp = 1;
			}else if(bp1 > 0){
				bp1 = 0;
			}
		}//Fin del ciclo del juego
	
		for(j = 0;j < f;j++){//Contar celulas vivas y muertas
				for(k = 0;k < c;k++){
					if(map[j][k] == 1){
						nv++;
					}
					if(map[j][k] == 0){
						nm++;
					}
				}
		}
	
	ct = pn + pm;
	pnp = (float)pn / ct * 100;
	pmp = (float)pm / ct * 100;
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
	gotoxy(48,8);
	printf("Generacion %d",ge);
	gotoxy(48,9);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
	printf("PN %.3f%c \tPM %.3f%c", pnp, '%', pmp, '%');
	gotoxy(48,10);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
	printf("Numero de celulas vivas %d",nv);
	gotoxy(48,11);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
	printf("Numero de celulas muertas %d",nm);
	gotoxy(0,36);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),13);
	printf("R. Reiniciar simulacion\nN. Salir");

	fflush(stdin);
	r = toupper(getch());
	
		if(r == 'R'){
			bp = 1;
		}else if(r == 'N'){
			tecla = r;
			tecla = toupper(tecla);
		}else if(r != 'R' && r != 'N'){
			fflush(stdin);
			r = toupper(getch());
		}
	nm = 0; nv = 0; bp = 0;
}while(tecla != 'N');
	return 0;
}
void llenar(int map[f][c]){
	int fc = 0,cc = 0, faux, caux, vaux = 0, band = 0, k, j,cont = 0, ban = 0;
	char tecla = 0;
	
	map[fc][cc] = 3; 
	imprimir(map);
	fflush(stdin);
	tecla = toupper(getch());
	cont = 0;
	while(tecla != 'L' && ban != 1){
		faux=fc;
		caux=cc;
		band=0;
		for(j = 0;j < f; j++){
			for(k = 0;k < c; k++){
				if(map[j][k] == 1){
					cont++;
				}
			}
		}
		if(cont < 5){
			cont = 0;
		}
		if(tecla == 'W'){
			if((fc-1) >= 0){
				fc--;
			}
		}
		if(tecla == 'S'){
			if((fc+1) < f){
				fc++;
			}
		}
		if(tecla == 'D'){
			if((cc+1) < c){
				cc++;
			}
		}
		if(tecla == 'A'){
			if((cc-1) >= 0){
				cc--;
			}
		}
		if(tecla == 32){
			if(vaux == 0){
				map[fc][cc] = 1;
			}
			else{
				map[fc][cc] = 0;
			}
			cc++;
			band = 1;
			if(cc >= c){
				cc = 0;
			}
		}
		
		if(faux != fc || caux != cc){
			if(!band){
				map[faux][caux] = vaux;
			}
			vaux = map[fc][cc];
			map[fc][cc] = 3;
			imprimir(map);
		}
		
		fflush(stdin);
		tecla=toupper(getch());	
		if(tecla == 'L' && cont < 5){
			tecla = 0;
			cont = 0;
			ban = 0;
		}else if(tecla == 'L' && cont >=5){
			tecla = 'L';
			ban = 1;
		}
			
	}
	cont = 0;
	map[fc][cc] = vaux;
}
void imprimir(int map[f][c]){//Funcion Imprimir
	int j, k, gen, i;
	system("cls");
	for(j = 0; j < f; j++){
		for(k = 0;k < c;k++){
			if(map[j][k] == 1){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
				printf("%c", 1);
			}
			if(map[j][k] == 0){
				printf(" ");
			}
			if(map[j][k] == 3){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				printf("I");
			}
		}
		printf("\n");
	}
}

void duplicar(int map[f][c], int map2[f][c]){//Funcion de duplicar el mapa visible a un mapa auxiliar para evaluar las celulas
	int j, k;
	
	for(j = 0;j < f;j++){
		for(k = 0;k < c;k++){
			map2[j][k] = map[j][k];
		}	
	}
}

void gotoxy(int x, int y){
		HANDLE hCon;
		COORD dwPos;
		
		dwPos.X=x;
		dwPos.Y=y;
		hCon=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleCursorPosition(hCon,dwPos);
	}

