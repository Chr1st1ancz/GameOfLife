/*
1. ziva bakterie s mene, nez dvema zivimi sousedy umira (nedostatecna populace).
2. ziva bakterie s vice, nez tremi zivimi sousedy umira na premnozeni (umira premnozenim).
3. ziva bakterie s dvema nebo tremi sousedy preziva beze zmeny do dalsi generace.
4. mrtva bakterie, s presne tremi zivimi sousedy, opet oziva (rozmnozovanim je nahrazena jinou).
*/

#include <stdio.h>
#include <stdlib.h>
#include <TIME.H>
#include <conio.h>

#define MAX_X 60
#define MAX_Y 140


int zivi_sousede(int generace[MAX_X][MAX_Y], int pozice_x, int pozice_y);
void my_sleep(unsigned duration)
{
    time_t start = time(NULL);
    double end = duration;
    time_t now;
    do {
        now = time(NULL);
    } while (difftime(now, start) < end);
}

int main(void)
{
	int gen_souc[MAX_X][MAX_Y], gen_bud[MAX_X][MAX_Y];
	int i, j;
	int sousedu;
	int znak_1=49;
	int znak_0=32;
    int znak_vod = 124;
    int znak_hor = 95;

	rand();

// inicializace pole
	for(i=0; i<MAX_X; i++){
		for(j=0; j<MAX_Y; j++){
			gen_souc[i][j] = rand() %2;
		}
	}
    system("cls");
	while(!kbhit()){
//dalsi generace
	for(i=0; i<MAX_X; i++){
		for(j=0; j<MAX_Y; j++){
			sousedu=zivi_sousede(gen_souc, i, j);
			if(gen_souc[i][j] ==1 && (sousedu==2 || sousedu==3)){
				gen_bud[i][j]=1;
			}
			else if(gen_souc[i][j]==0 && sousedu==3) {
				gen_bud[i][j]=1;
			}
			else {
				gen_bud[i][j]=0;
			}
		}
	}




// vypis soucasne generace
//	for(i=0; i<MAX_X; i++){
//		printf("\n");
//		for(j=0; j<MAX_Y; j++){
//			printf("%d",gen_souc[i][j]);
//		}
//	}
//	printf("\n--------");
        my_sleep(1);
        system("cls");
// vypis budouci generace
        int count = 0;

	for(i=0; i<MAX_X; i++){

        printf("%c",znak_vod);
       /* while(i == MAX_X && count <= MAX_X){
                printf("%c", znak_hor);
                count++;
        }*/
		printf("\n");
		for(j=0; j<MAX_Y+1; j++){
            if(j == 0){
                printf("%c",znak_vod);
            }
			if(gen_bud[i][j]==0){
//				printf(" ");
				printf("%c",znak_0);
			}
			else{
//				printf("%d",gen_bud[i][j];
				printf("%c",znak_1);
			}
			gen_souc[i][j]=gen_bud[i][j];
		}
	}




	}
	getch();
	return 0;
}

int zivi_sousede(int svet[MAX_X][MAX_Y], int pozice_x, int pozice_y){
	int i, j, pocet_sousedu=0;
	for(i=pozice_x-1; i<=pozice_x+1; i++){
		for(j=pozice_y-1; j<=pozice_y+1; j++){
			if((i==pozice_x && j==pozice_y) || (i<0 || j<0) || (i>= MAX_X || j>=MAX_Y)){
				continue;
			}
			if(svet[i][j]==1) pocet_sousedu++;
		}
	}
	return pocet_sousedu;
}
