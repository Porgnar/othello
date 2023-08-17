#include <stdio.h>


//elég self explanatory

typedef struct Sboard{
	char row0[9];
	char row1[9];
	char row2[9];
	char row3[9];
	char row4[9];
	char row5[9];
	char row6[9];
	char row7[9];
	char row8[9];
	}Sboard;	

//faszán működő struktúra "tábla" kiiratós falhoz veretős szekunder cementites kurva függvény :3


void prntbrd(Sboard bd){
	for(char i=0;i<9;i++){printf("%c ",bd.row0[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row1[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row2[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row3[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row4[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row5[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row6[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row7[i]);};
	printf("\n");
	for(char i=0;i<9;i++){printf("%c ",bd.row8[i]);};
	printf("\n");
	
};


//faszom segédmátrixprinter -.-

void prntmx(int mx[9][9]){
	for(char i=0;i<9;i++){
		for(char j=0;j<9;j++){
		printf("%d ",mx[i][j]);
		}
	printf("\n");
	}
};



int main(){
	
	//felállítom kínkeservesen a kurva táblát struktúrába, így nem lesz pointer bamboozle...talán :D
	
	Sboard 	bd={{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '},{' ',' ',' ',' ',' ',' ',' ',' ',' '}};
	bd.row4[4]='X';
	bd.row4[5]='O';
	bd.row5[4]='O';
	bd.row5[5]='X';
	
	bd.row1[0]='1';
	bd.row2[0]='2';
	bd.row3[0]='3';
	bd.row4[0]='4';
	bd.row5[0]='5';
	bd.row6[0]='6';
	bd.row7[0]='7';
	bd.row8[0]='8';
	
	char temp=48;
	
	for(char i=0;i<9;i++){
		bd.row0[i]=temp;
		temp=temp+1;
	};
	
	
	//áll a ~faszom~ öhh...tábla ^^
	
	printf("Othello játék, az első játékos az X, sor és oszlop koordinátákat adjon meg\negymás után space-el írva, az alábbi módon: 1 1 2 5 3 6 6 9...\nA játék végén az nyer, akinek több karaktere van a táblán.\n");
	
	//kezdődik a logika rész bemeneti sor oszlop választás
	
	
	int mx[9][9];
	
	for(char i=0;i<9;i++){
		mx[0][i]=bd.row0[i];
	};
	
	for(char i=0;i<9;i++){
		mx[1][i]=bd.row1[i];
	};
	
	for(char i=0;i<9;i++){
		mx[2][i]=bd.row2[i];
	};
	
	for(char i=0;i<9;i++){
		mx[3][i]=bd.row3[i];
	};
	
	for(char i=0;i<9;i++){
		mx[4][i]=bd.row4[i];
	};
	
	for(char i=0;i<9;i++){
		mx[5][i]=bd.row5[i];
	};
	
	for(char i=0;i<9;i++){
		mx[6][i]=bd.row6[i];
	};
	
	for(char i=0;i<9;i++){
		mx[7][i]=bd.row7[i];
	};
	
	for(char i=0;i<9;i++){
		mx[8][i]=bd.row8[i];
	};
	
	
	int s,o;
	int counter=0;
	
	//prntmx(mx);
	
	//printf("\n\n");
	
	prntbrd(bd);
	
	while(1){
	char decider=1;
	scanf("%d%d",&s,&o); /*szóközzel elválasztva bekérem a mátrixba a helyet, muszály vagyok duplán futtatni mert
				másképpen a mátrix pointer természete miatt túlcsordulás léphetne fel, ha beadnám az első
				sor 10. oszlopát, ami nem létezik, akkor kapnám a második sor első oszlopát a sorfolytonos
				memóriatárolás miatt, ez a geci már többször keresztbe tett >:( (pl aknakeresőnél is)*/
		
		
	if((s==0)||(o==0)||(s>8)||(o>8)){printf("kilépett a játéktérről, kérem adjon meg új számot\n");}
	
	else{	
		switch(s){
			case 1 : if(bd.row1[o]=='X'||bd.row1[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} //ha foglalt nono
					else{if(counter%2==0){bd.row1[o]='X';	//ha nem és x köre van xet
						mx[s][o]='X';
						}
						 else{bd.row1[o]='O';		//ha o köre van o-t rakok
						 mx[s][o]='O';
						 };
					}; break;
					
			
			case 2 : if(bd.row2[o]=='X'||bd.row2[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} 
					else{if(counter%2==0){bd.row2[o]='X';
						mx[s][o]='X';
						}
						 else{bd.row2[o]='O';
						 	mx[s][o]='O';
						 };
					}; break;
					
			case 3 : if(bd.row3[o]=='X'||bd.row3[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} 
					else{if(counter%2==0){bd.row3[o]='X';
						mx[s][o]='X';
						}
						 else{bd.row3[o]='O';
						 mx[s][o]='O';
						 };
					}; break;
						
			case 4 : if(bd.row4[o]=='X'||bd.row4[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} 
					else{if(counter%2==0){bd.row4[o]='X';
						mx[s][o]='X';
						}
						 else{bd.row4[o]='O';
						 mx[s][o]='O';
						 };
					}; break;
					
			case 5 : if(bd.row5[o]=='X'||bd.row5[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} 
					else{if(counter%2==0){bd.row5[o]='X';
						mx[s][o]='X';
						}
						 else{bd.row5[o]='O';
						 mx[s][o]='O';
						 };
					}; break;
			
			case 6 : if(bd.row6[o]=='X'||bd.row6[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} 
					else{if(counter%2==0){bd.row6[o]='X';
						mx[s][o]='X';
						}
						 else{bd.row6[o]='O';
						 mx[s][o]='O';
						 };
					}; break;
					
			case 7 : if(bd.row7[o]=='X'||bd.row7[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} 
					else{if(counter%2==0){bd.row7[o]='X';
						mx[s][o]='X';
						}
						 else{bd.row7[o]='O';
						 mx[s][o]='O';
						 };
					}; break;
					
			case 8 : if(bd.row8[o]=='X'||bd.row8[o]=='O'){printf("ide nem rakhat othello követ\n"); decider=0;} 
					else{if(counter%2==0){bd.row8[o]='X';
						mx[s][o]='X';
						}
						 else{bd.row8[o]='O';
						 mx[s][o]='O';
						 };
					}; break;		
					
			default: printf("meh valami beszart\n"); break;
		}	
			
		
					
	//eddig jó, most váltogatva körökben tudnak pakolászni szart a játékosok, itt jön az igazi szarba csapás
	if(decider){
		if(counter%2==0){		//ha x köre van
			if(mx[s][o-1]=='O'){		//ha xtől balra o van
					char i=1;
					while(1){
						if(mx[s][o-i]=='O'){i++;}	//akkor nézem, hogy amíg o-van megyek
						else if(mx[s][o-i]=='X'){	//ha találok xet
							for(char k=0;k<i;k++){
								mx[s][o-k]='X';	//akkor x helyéig minden o-t xre cserélek
								}//for
						break;
						}//elif
						else break;			//ha nem o vagy x van azaz a széle a pályának,
					}//léptető while			akkor nem csinálok semmit
				}//balra check if
	
			if(mx[s][o+1]=='O'){
					char i=1;
					while(1){
						if(mx[s][o+i]=='O'){i++;}
						else if(mx[s][o+i]=='X'){
							for(char k=0;k<i;k++){
								mx[s][o+k]='X';
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//jobbra check if
			
			if(mx[s-1][o]=='O'){
					char i=1;
					while(1){
						if(mx[s-i][o]=='O'){i++;}
						else if(mx[s-i][o]=='X'){
							for(char k=0;k<i;k++){
								mx[s-k][o]='X';
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//fel check if
				
			if(mx[s+1][o]=='O'){
					char i=1;
					while(1){
						if(mx[s+i][o]=='O'){i++;}
						else if(mx[s+i][o]=='X'){
							for(char k=0;k<i;k++){
								mx[s+k][o]='X';
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//le check if
			
			
			if(mx[s-1][o-1]=='O'){
					char i=1,j=1;
					while(1){
						if(mx[s-i][o-i]=='O'){i++;j++;}
						else if(mx[s-i][o-j]=='X'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s-k][o-l]='X';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//balfeldiag check if
			
			if(mx[s-1][o+1]=='O'){
					char i=1,j=1;
					while(1){
						if(mx[s-i][o+i]=='O'){i++;j++;}
						else if(mx[s-i][o+j]=='X'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s-k][o+l]='X';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//jobbfeldiag check if
			
			if(mx[s+1][o+1]=='O'){
					char i=1,j=1;
					while(1){
						if(mx[s+i][o+i]=='O'){i++;j++;}
						else if(mx[s+i][o+j]=='X'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s+k][o+l]='X';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//jobblediag check if
			
			if(mx[s+1][o-1]=='O'){			
					char i=1,j=1;
					while(1){
						if(mx[s+i][o-i]=='O'){i++;j++;}
						else if(mx[s+i][o-j]=='X'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s+k][o-l]='X';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//balleldiag check if
			
		}//ha x köre van akkor a logika ez
		
/*		
asdkhjsaokdjsakldjaslkéfhdsajkfhdsalkjfjhsadlékfjdsafjsléfjsfjdséafjafjdjéfjdsaéfjsdéajfglékfajgékfdjgfdjglékfdsjglkéfdsjgdsflg		
asdkhjsaokdjsakldjaslkéfhdsajkfhdsalkjfjhsadlékfjdsafjsléfjsfjdséafjafjdjéfjdsaéfjsdéajfglékfajgékfdjgfdjglékfdsjglkéfdsjgdsflg
asdkhjsaokdjsakldjaslkéfhdsajkfhdsalkjfjhsadlékfjdsafjsléfjsfjdséafjafjdjéfjdsaéfjsdéajfglékfajgékfdjgfdjglékfdsjglkéfdsjgdsflg
asdkhjsaokdjsakldjaslkéfhdsajkfhdsalkjfjhsadlékfjdsafjsléfjsfjdséafjafjdjéfjdsaéfjsdéajfglékfajgékfdjgfdjglékfdsjglkéfdsjgdsflg
asdkhjsaokdjsakldjaslkéfhdsajkfhdsalkjfjhsadlékfjdsafjsléfjsfjdséafjafjdjéfjdsaéfjsdéajfglékfajgékfdjgfdjglékfdsjglkéfdsjgdsflg
*/		

		//el kellett választani O körét valahogy ^^
		
		else{
			if(mx[s][o-1]=='X'){		//ha xtől balra o van
					char i=1;
					while(1){
						if(mx[s][o-i]=='X'){i++;}	//akkor nézem, hogy amíg o-van megyek
						else if(mx[s][o-i]=='O'){	//ha találok xet
							for(char k=0;k<i;k++){
								mx[s][o-k]='O';	//akkor x helyéig minden o-t xre cserélek
								}//for
						break;
						}//elif
						else break;			//ha nem o vagy x van azaz a széle a pályának,
					}//léptető while			akkor nem csinálok semmit
				}//balra check if
	
			if(mx[s][o+1]=='X'){
					char i=1;
					while(1){
						if(mx[s][o+i]=='X'){i++;}
						else if(mx[s][o+i]=='O'){
							for(char k=0;k<i;k++){
								mx[s][o+k]='O';
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//jobbra check if
			
			if(mx[s-1][o]=='X'){
					char i=1;
					while(1){
						if(mx[s-i][o]=='X'){i++;}
						else if(mx[s-i][o]=='O'){
							for(char k=0;k<i;k++){
								mx[s-k][o]='O';
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//fel check if
				
			if(mx[s+1][o]=='X'){
					char i=1;
					while(1){
						if(mx[s+i][o]=='X'){i++;}
						else if(mx[s+i][o]=='O'){
							for(char k=0;k<i;k++){
								mx[s+k][o]='O';
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//le check if
			
			
			if(mx[s-1][o-1]=='X'){
					char i=1,j=1;
					while(1){
						if(mx[s-i][o-i]=='X'){i++;j++;}
						else if(mx[s-i][o-j]=='O'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s-k][o-l]='O';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//balfeldiag check if
			
			if(mx[s-1][o+1]=='X'){
					char i=1,j=1;
					while(1){
						if(mx[s-i][o+i]=='X'){i++;j++;}
						else if(mx[s-i][o+j]=='O'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s-k][o+l]='O';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//jobbfeldiag check if
			
			if(mx[s+1][o+1]=='X'){
					char i=1,j=1;
					while(1){
						if(mx[s+i][o+i]=='X'){i++;j++;}
						else if(mx[s+i][o+j]=='O'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s+k][o+l]='O';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//jobblediag check if
			
			if(mx[s+1][o-1]=='X'){			
					char i=1,j=1;
					while(1){
						if(mx[s+i][o-i]=='X'){i++;j++;}
						else if(mx[s+i][o-j]=='O'){
							char l=0;
							for(char k=0;k<i;k++){
								mx[s+k][o-l]='O';
								l++;
								};//for
						break;
						}//elif
						else break;				
					}//léptető while
				}//balleldiag check if
		
		}//ha o köre van akkor meg ez
		
		counter++;
	
	
	/*most kell visszaraknom a vizuálisan prezentált táblába, ugyanis mint tudjuk ehhez nem nyúlhat hozzá jóesetben a játékos
	bár utólag belegondolva kurvára rácsesztem mert egy sima switchel mindet meg lehetett volna oldani egy táblán is
	struktúrák meg minden lófasz nélkül, hogy kevesebb helyet zabáljon, meg gyorsabban fusson, hisz switchhel
	le tdtam volna korlátozni az inputot megfelelő számú sor oszlopra, hogy ne legyen overflow....de mostmár kurvára mindegy
	:S :S :S :S :S :S :S :S >:(
	*/	
		
		
	for(char i=0;i<9;i++){
		bd.row1[i]=mx[1][i];
	};
	
	for(char i=0;i<9;i++){
		bd.row2[i]=mx[2][i];
	};
	
	for(char i=0;i<9;i++){
		bd.row3[i]=mx[3][i];
	};
	
	for(char i=0;i<9;i++){
		bd.row4[i]=mx[4][i];
	};
	
	for(char i=0;i<9;i++){
		bd.row5[i]=mx[5][i];
	};
	
	for(char i=0;i<9;i++){
		bd.row6[i]=mx[6][i];
	};
	
	for(char i=0;i<9;i++){
		bd.row7[i]=mx[7][i];
	};
	
	for(char i=0;i<9;i++){
		bd.row8[i]=mx[8][i];
	};	
		
		
	
	prntbrd(bd);
	//prntmx(mx);
	
	}//decider check, azaz ha tettünk be értéket egy helyre akkor fut le csak 
	
	int fin=0,xp=0,op=0;  //játék vége ellenőrzés,pontszámolás, egyszerűen megszámoltatom a pontokat, meg hogy van e üres hely
	
	
	for(char i=0;i<9;i++){
		for(char j=0;j<9;j++){
			if(mx[i][j]==' '){fin++;};
		}
	}
	
	//printf("\n\t%d\n",fin);
	
	if(fin==0){
		for(char i=0;i<9;i++){
			for(char j=0;j<9;j++){
				if(mx[i][j]=='X'){xp++;};
		}
	}
		for(char i=0;i<9;i++){
			for(char j=0;j<9;j++){
				if(mx[i][j]=='O'){op++;};
		}
	}
	
	printf("\nAz X játékos pontszáma: %d\nAz O játékos pontszáma: %d",xp,op);
	if(xp>op){printf("Az X játékos nyert, gratulálunk!\n\nKöszönjük a játékot!");}
	else{printf("Az O játékos nyert, gratulálunk!\n\nKöszönjük a játékot!");}
	break;
	break;
	}
}//utólag itt gateltem le, hogy ne lehessen overflowolni a sorokkal, vagy az oszlopokkal
	
}//játéklogika whilet zár
	
	
	//prntbrd(bd);	


return 0;
}
