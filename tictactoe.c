#include <stdio.h>
#include <stdlib.h>

_Bool player;
int input;
unsigned char x,y,i,turn,answer;
unsigned char map[9]={'1','2','3','4','5','6','7','8','9'};

int main(void){
	player=0;
	for(turn=0;turn<9;turn++){
		for(y=0;y<3;y++){
			printf("\n+---+---+---+\n|");
			for(x=0;x<3;x++){
				printf(" %c |",map[(2-y)*3+x]);
			};
		};
		printf("\n+---+---+---+\n");
		for(x=0;x<3;x++){
			if(map[x]==map[x+3]&&map[x]==map[x+6]||map[x*3]==map[x*3+1]&&map[x*3]==map[x*3+2]){
				goto win;
			}
		}
		if(map[0]==map[4]&&map[0]==map[8]||map[2]==map[4]&&map[2]==map[6]){
			goto win;
		}
		printf("Player %i now your turn:",player+1);
resteping:
		scanf("%i",&input);
		if(input<0 || input>9){
			printf("Player %i your turn invalid select from 1 to 9:",player+1);
			goto resteping;
		}
		input--;
		if(map[input]=='O' || map[input]=='X'){
			printf("Player %i your turn invalid select free ceil:",player+1);
			goto resteping;
		}
		map[input]=(player) ? 'O':'X';
		player=!player;
	};
	printf("Draw!");
	return 0;
win:
	printf("Player %i win\nCongritulation\n",!player+1);
	return 0;
}
