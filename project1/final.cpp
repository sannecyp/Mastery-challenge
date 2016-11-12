/*********************************************************************
 ****** filename:final.cpp
 ****** Author:Prathik Sannecy
 ****** Date:3/13
 ****** Description:Plays a maze game

 ************************************************************************/

#include "final.h"

int main(){
	Game go;
	go.play();
	return 0;
}
 /*This function sets up the location of each ghost, as well as which map*/
void Game::setghosts()
{
	ghost1.setmap(1);
	ghost1.setloc(8,14);
	ghost2.setmap(2);
	ghost2.setloc(8,14);	
	ghost3.setmap(3);
	ghost3.setloc(1,14);
}
/*This function randomly moves the ghost in a row in the main corridor. The return is useless.*/
int ghost::move(player player1, char map[20][30],int randnum)
{
	
	int value;
	//If the ghost is more than 5 spaces away from the player	
	if((abs(player1.getxloc()-yloc)+abs(player1.getyloc()-xloc)>5))
	{
		//picks a random number that determines the direction of the ghost
		srand(time(NULL));
		value = rand() % 4;
		int pastwall=1;
		//Based on which way the ghost is determined to move, 
		//one of the while loops are chosen	
		while((value==0&&(xloc+pastwall)<18)||randnum==1)
		{
			//avoids obstacles
			if(map[xloc+pastwall][yloc]=='#'||map[xloc+pastwall][yloc]=='C'||map[xloc+pastwall][yloc]=='D'||map[xloc+pastwall][yloc]=='K'||map[xloc+pastwall][yloc]=='A'||map[xloc+pastwall][yloc]=='B')
			{
				pastwall++;
			}
			//If the ghost hits a player
			else if(map[xloc+pastwall][yloc]=='p')
				return 1;
			else
			{
				setloc(xloc+pastwall,yloc);
				return 0;
			}
			
		}
		//If the ghost is on the boundary, it goes a different 
		//direction
		if(value==0&&(xloc+pastwall)==18)
			value=1;
		pastwall=1;
		//see the previous while loop
		while(value==1&&(xloc-pastwall)>0)
		{
			if(map[xloc-pastwall][yloc]=='#'||map[xloc-pastwall][yloc]=='C'||map[xloc-pastwall][yloc]=='D'||map[xloc-pastwall][yloc]=='K'||map[xloc-pastwall][yloc]=='A'||map[xloc-pastwall][yloc]=='B')
			{
				pastwall++;
			}
			else if(map[xloc+pastwall][yloc]=='p')
				return 1;
			else
			{
				setloc(xloc-pastwall,yloc);
				return 0;
			}
			
		}
		//boundary check
		if(value==1&&(xloc-pastwall)==0)
			value=2;
		pastwall=1;
		//see the first while loop
		while(value==2&&(yloc+pastwall)<28)
		{
			if(map[xloc][yloc+pastwall]=='#'||map[xloc][yloc+pastwall]=='C'||map[xloc][yloc+pastwall]=='D'||map[xloc][yloc+pastwall]=='K'||map[xloc][yloc+pastwall]=='A'||map[xloc][yloc+pastwall]=='B')
			{
				pastwall++;
			}
			else if(map[xloc][yloc+pastwall]=='p')
				return 1;
			else
			{
				setloc(xloc,yloc+pastwall);
				return 0;
			}
			
		}
		//boundary check
		if(value==2&&(yloc+pastwall)==28)
			value=3;
		pastwall=1;
		//see the first while loop
		while(value==3&&(yloc-pastwall)>0)
		{
			if(map[xloc][yloc-pastwall]=='#'||map[xloc][yloc-pastwall]=='C'||map[xloc][yloc-pastwall]=='D'||map[xloc][yloc-pastwall]=='K'||map[xloc][yloc-pastwall]=='A'||map[xloc][yloc-pastwall]=='B')
			{
				pastwall++;
			}
			else if(map[xloc+pastwall][yloc]=='p')
				return 1;
			else
			{
				setloc(xloc,yloc-pastwall);
				return 0;
			}
			
		}
		//boundary check
		if(value==3&&(yloc-pastwall)==0)
			move(player1,map,1);
			
	}
	//If the ghost is within 5 spaces of the player
	else
	{
		int pastwall=1;
		//same movement as for if the ghost is within 5 spaces 
		//The only difference is that the movement is determined by
		//the position of the ghost with respect to the player
		if(player1.getxloc()>yloc)
		{
			//This while loop moves the ghost so it avoids obstacles
			//and checks to see if it hits the player
			while((yloc+pastwall)<28)
			{
				if(map[xloc][yloc+pastwall]=='#'||map[xloc][yloc+pastwall]=='C'||map[xloc][yloc+pastwall]=='D'||map[xloc][yloc+pastwall]=='K'||map[xloc][yloc+pastwall]=='A'||map[xloc][yloc+pastwall]=='B')
				{
					pastwall++;
				}
				else if(map[xloc][yloc+pastwall]=='p')
				{
					return 1;
				}	
				else
				{
					setloc(xloc,yloc+pastwall);
					return 0;
				}
			
			}
			
		}
		//Same as the previous if statement. This one is called for a different
		//situation of the placement of the ghost with respect to the player
		else if(player1.getxloc()<yloc)
		{
			while((yloc-pastwall)>1)
			{
				if(map[xloc][yloc-pastwall]=='#'||map[xloc][yloc-pastwall]=='C'||map[xloc][yloc-pastwall]=='D'||map[xloc][yloc-pastwall]=='K'||map[xloc][yloc-pastwall]=='A'||map[xloc][yloc-pastwall]=='B')
				{
					pastwall++;
				}
				else if(map[xloc][yloc-pastwall]=='p')
				{
					return 1;
				}
				else
				{
					setloc(xloc,yloc-pastwall);
					return 0;
				}
				
			}
		}
		//Same as the first if statement. This one is called for a different
		//situation of the placement of the ghost with respect to the player
		else if(player1.getyloc()<xloc)
		{
			while((xloc-pastwall)>1)
			{
				if(map[xloc-pastwall][yloc]=='#'||map[xloc-pastwall][yloc]=='C'||map[xloc-pastwall][yloc]=='D'||map[xloc-pastwall][yloc]=='K'||map[xloc-pastwall][yloc]=='A'||map[xloc-pastwall][yloc]=='B')
				{
					pastwall++;
				}
				else if(map[xloc-pastwall][yloc]=='p')
				{
					return 1;
				}
				else
				{
					setloc(xloc-pastwall,yloc);
					return 0;
				}
			
			}
		}
		//Same as the first if statement. This one is called for a different
		//situation of the placement of the ghost with respect to the player
		else if(player1.getyloc()>xloc)
		{
			while(((xloc+pastwall)<18))
			{
				if(map[xloc+pastwall][yloc]=='#'||map[xloc+pastwall][yloc]=='C'||map[xloc+pastwall][yloc]=='D'||map[xloc+pastwall][yloc]=='K'||map[xloc+pastwall][yloc]=='A'||map[xloc+pastwall][yloc]=='B')
				{
					pastwall++;
				}
				else if(map[xloc+pastwall][yloc]=='p')
				{
					return 1;
				
				}
				else
				{
					setloc(xloc+pastwall,yloc);
					return 0;
				}
			
			}
		}

	}
	
	

}
/*Starts the game*/
void Game::play()
{
	int reset;
	setghosts();
	while(true){
	reset=0;
	/*prints the map, moves the player, moves the first ghost, sees if the ghost hits the player. 
	Does so based on what floor the player is on*/	
	if(player1.getmap()==1)
	{
		printmap1();
		
		map1[ghost1.getxloc()][ghost1.getyloc()]=' ';
		if(ghost1.getexists()==1)
			//reset determines whether the player hit the ghost
			reset=ghost1.move(player1,map1,0);
		if(map1[ghost1.getxloc()][ghost1.getyloc()]!='C'&&ghost1.getexists()==1)
			map1[ghost1.getxloc()][ghost1.getyloc()]='G';
		/*If the player is hit by the ghost, then reset is assigned 1.
		Based on that,  both arrays with current floor (the one with actual data and the one being printed) 
		are changed so that the player and the ghost are gone. 
		After that, the player is placed at the beginning*/
		if(reset==1&&player1.getcounter()<1)
		{	
			cout<<"ghost location"<<ghost1.getyloc()<<","<<ghost1.getxloc()<<endl;
			cout<<"player location"<<player1.getxloc()<<","<<player1.getyloc()<<endl;
			ghost1.setexists(0);
			map1[ghost1.getxloc()][ghost1.getyloc()]=' ';
			map1print[ghost1.getxloc()][ghost1.getyloc()]=' ';
			map1[player1.getyloc()][player1.getxloc()]=' ';
			map1print[player1.getyloc()][player1.getxloc()]=' ';
			player1.setloc(0,15);
			player1.setmap(1);
			map1[15][0]='p';
		}
		
		playermovemap1(player1.move());
		
	}
	//If the player is on the second floor. Same as the previous 
	//if statement except for the second floor
	else if(player1.getmap()==2)
	{
		
		printmap2();
		playermovemap2(player1.move());
		map2[ghost2.getxloc()][ghost2.getyloc()]=' ';
		ghost2.move(player1,map2,0);
		if(reset==1&&player1.getcounter()<1)
		{	
			map2[player1.getyloc()-1][player1.getxloc()]==' ';
			player1.setloc(0,15);
			player1.setmap(1);
			map1[15][0]='p';
		}
		if(map2[ghost2.getxloc()][ghost2.getyloc()]!='C'&&ghost2.getexists()==1)
			map2[ghost2.getxloc()][ghost2.getyloc()]='G';
	}
	//If the player is on the third floor. Same as the first 
	//if statement except for the third floor
	else 
	{
		printmap3();
		playermovemap3(player1.move());
		map3[ghost3.getxloc()][ghost3.getyloc()]=' ';
		ghost3.move(player1,map3,0);
		if(reset==1&&player1.getcounter()<1)
		{	
			map2[player1.getyloc()-1][player1.getxloc()]==' ';
			player1.setloc(0,15);
			player1.setmap(1);
			map1[15][0]='p';
		}
		if(map3[ghost3.getxloc()][ghost3.getyloc()]!='C'&&ghost3.getexists()==1)
			map3[ghost3.getxloc()][ghost3.getyloc()]='G';
	}
	}
	
}
/*this function moves the player if the player is on map 2*/
void Game::playermovemap2(char direct)
{
	
		/*Checks to see if the player has hit anything. Based on what the player hits, something will happen*/
		/*The next few if statements are for the player to go up/down or left/right*/
		if((map2[player1.getyloc()][player1.getxloc()]=='A'||map2[player1.getyloc()+1][player1.getxloc()]=='A'||map2[player1.getyloc()-1][player1.getxloc()]=='A'||map2[player1.getyloc()][player1.getxloc()+1]=='A'||map2[player1.getyloc()][player1.getxloc()-1]=='A')&&direct=='u')
		{
			player1.setmap(3);
			player1.setloc(14,12);
			map3[12][14]=='p';
			return;
		}
		else if((map2[player1.getyloc()][player1.getxloc()]=='B'||map2[player1.getyloc()+1][player1.getxloc()]=='B'||map2[player1.getyloc()-1][player1.getxloc()]=='B'||map2[player1.getyloc()][player1.getxloc()+1]=='B'||map2[player1.getyloc()][player1.getxloc()-1]=='B')&&direct=='z')
		{
			player1.setmap(1);
			player1.setloc(14,5);
			map1[5][14]=='p';
			return;
		}
		/*based on what direction the player is going to move*/
		if (direct=='s')
		{
			/*If the player hits a wall or a door without a key*/
			if(map2[player1.getyloc()+1][player1.getxloc()]=='#' || (map2[player1.getyloc()+1][player1.getxloc()]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			/*if the player reaches a key*/
			if(map2[player1.getyloc()+1][player1.getxloc()]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			/*if the player finds a cherry*/
			else if(map2[player1.getyloc()+1][player1.getxloc()]=='C')
			{
				
				player1.setcounter(20);
				
			}
			/*to get past a door*/
			else if(map2[player1.getyloc()+1][player1.getxloc()]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			/*if the player encounters a ghost*/
			else if(map2[player1.getyloc()+1][player1.getxloc()]=='G')
			{
				ghost2.setexists(0);
				
				
				if(player1.getcounter()<1){
					map2[player1.getyloc()+1][player1.getxloc()]==' ';
					player1.setmap(1);
					player1.setloc(0,15);
					map1[15][0]='p';
					return;
				}

			}
			/*moves the player to the new spot*/
			map2[player1.getyloc()][player1.getxloc()]=' ';
			map2[player1.getyloc()+1][player1.getxloc()]='p';
			player1.setloc(player1.getxloc(),player1.getyloc()+1);
		}
		if (direct=='w')
		{
			if(map2[player1.getyloc()-1][player1.getxloc()]=='#' || (map2[player1.getyloc()-1][player1.getxloc()]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map2[player1.getyloc()-1][player1.getxloc()]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map2[player1.getyloc()-1][player1.getxloc()]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map2[player1.getyloc()-1][player1.getxloc()]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map2[player1.getyloc()-1][player1.getxloc()]=='G')
			{
				ghost2.setexists(0);
				
				
				if(player1.getcounter()<1){
					map2[player1.getyloc()-1][player1.getxloc()]==' ';
					player1.setloc(0,15);
					player1.setmap(1);
					map1[15][0]='p';
					return;
				}

			}
			map2[player1.getyloc()][player1.getxloc()]=' ';
			map2[player1.getyloc()-1][player1.getxloc()]='p';
			player1.setloc(player1.getxloc(),player1.getyloc()-1);
		}
		if (direct=='a')
		{
			if(map2[player1.getyloc()][player1.getxloc()-1]=='#' || (map2[player1.getyloc()][player1.getxloc()-1]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map2[player1.getyloc()][player1.getxloc()-1]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map2[player1.getyloc()][player1.getxloc()-1]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map2[player1.getyloc()][player1.getxloc()-1]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map2[player1.getyloc()][player1.getxloc()-1]=='G')
			{
				ghost2.setexists(0);
				
				
				if(player1.getcounter()<1){
					map2[player1.getyloc()][player1.getxloc()-1]==' ';
					player1.setloc(0,15);
					player1.setmap(1);
					map1[15][0]='p';
					return;
				}

			}
			map2[player1.getyloc()][player1.getxloc()]=' ';
			map2[player1.getyloc()][player1.getxloc()-1]='p';
			player1.setloc(player1.getxloc()-1,player1.getyloc());
		}
		if (direct=='d')
		{
			if(map2[player1.getyloc()][player1.getxloc()+1]=='#' || (map2[player1.getyloc()][player1.getxloc()+1]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map2[player1.getyloc()][player1.getxloc()+1]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map2[player1.getyloc()][player1.getxloc()+1]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map2[player1.getyloc()][player1.getxloc()+1]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map2[player1.getyloc()][player1.getxloc()+1]=='G')
			{
				ghost2.setexists(0);
				
				
				if(player1.getcounter()<1){
					map2[player1.getyloc()][player1.getxloc()+1]==' ';
					player1.setloc(0,15);
					player1.setmap(1);
					map1[15][0]='p';
					return;
				}

			}
			map2[player1.getyloc()][player1.getxloc()]=' ';
			map2[player1.getyloc()][player1.getxloc()+1]='p';
			player1.setloc(player1.getxloc()+1,player1.getyloc());
		}
}
/*same as void Game::playermovemap2(char direct) except for floor 3, which has a different design. All the functions/conditions are the same.
SEE: void game::playermovemap2(char direct)!*/
void Game::playermovemap3(char direct)
{
		if(map3[player1.getyloc()-1][player1.getxloc()]=='X')
		{
			cout<<"you won!!"<<endl;
			exit(0);
		}
		if((map3[player1.getyloc()][player1.getxloc()]=='B'||map3[player1.getyloc()+1][player1.getxloc()]=='B'||map3[player1.getyloc()-1][player1.getxloc()]=='B'||map3[player1.getyloc()][player1.getxloc()+1]=='B'||map3[player1.getyloc()][player1.getxloc()-1]=='B')&&direct=='z')
		{
			player1.setmap(2);
			player1.setloc(14,5);
			map2[5][14]=='p';
			return;
		}

		if (direct=='s')
		{
			if(map3[player1.getyloc()+1][player1.getxloc()]=='#' || (map3[player1.getyloc()+1][player1.getxloc()]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map3[player1.getyloc()+1][player1.getxloc()]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map3[player1.getyloc()+1][player1.getxloc()]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map3[player1.getyloc()+1][player1.getxloc()]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map3[player1.getyloc()+1][player1.getxloc()]=='G')
			{
				ghost3.setexists(0);
				
				
				if(player1.getcounter()<1){
					map3[player1.getyloc()+1][player1.getxloc()]==' ';
					player1.setloc(0,15);
					player1.setmap(1);
					map1[15][0]='p';
					return;
				}

			}
			map3[player1.getyloc()][player1.getxloc()]=' ';
			map3[player1.getyloc()+1][player1.getxloc()]='p';
			player1.setloc(player1.getxloc(),player1.getyloc()+1);
		}
		if (direct=='w')
		{
			if(map3[player1.getyloc()-1][player1.getxloc()]=='#' || (map3[player1.getyloc()-1][player1.getxloc()]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map3[player1.getyloc()-1][player1.getxloc()]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map3[player1.getyloc()-1][player1.getxloc()]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map3[player1.getyloc()-1][player1.getxloc()]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map3[player1.getyloc()-1][player1.getxloc()]=='G')
			{
				ghost3.setexists(0);
				
				
				if(player1.getcounter()<1){
					map3[player1.getyloc()-1][player1.getxloc()]==' ';
					player1.setloc(0,15);
					player1.setmap(1);
					map1[15][0]='p';
					return;
				}

			}
			map3[player1.getyloc()][player1.getxloc()]=' ';
			map3[player1.getyloc()-1][player1.getxloc()]='p';
			player1.setloc(player1.getxloc(),player1.getyloc()-1);
		}
		if (direct=='a')
		{
			if(map3[player1.getyloc()][player1.getxloc()-1]=='#' || (map3[player1.getyloc()][player1.getxloc()-1]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map3[player1.getyloc()][player1.getxloc()-1]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map3[player1.getyloc()][player1.getxloc()-1]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map3[player1.getyloc()][player1.getxloc()-1]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map3[player1.getyloc()][player1.getxloc()-1]=='G')
			{
				ghost3.setexists(0);
				
				
				if(player1.getcounter()<1){
					map3[player1.getyloc()][player1.getxloc()-1]==' ';
					player1.setloc(0,15);
					map1[15][0]='p';
					player1.setmap(1);
					return;
				}

			}
			map3[player1.getyloc()][player1.getxloc()]=' ';
			map3[player1.getyloc()][player1.getxloc()-1]='p';
			player1.setloc(player1.getxloc()-1,player1.getyloc());
		}
		if (direct=='d')
		{
			if(map3[player1.getyloc()][player1.getxloc()+1]=='#' || (map3[player1.getyloc()][player1.getxloc()+1]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map3[player1.getyloc()][player1.getxloc()+1]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map3[player1.getyloc()][player1.getxloc()+1]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map3[player1.getyloc()][player1.getxloc()+1]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map3[player1.getyloc()][player1.getxloc()+1]=='G')
			{
				ghost3.setexists(0);
				
				
				if(player1.getcounter()<1){
					map3[player1.getyloc()][player1.getxloc()+1]==' ';
					player1.setloc(0,15);
					player1.setmap(1);
					map1[15][0]='p';
					return;
				}

			}
			map3[player1.getyloc()][player1.getxloc()]=' ';
			map3[player1.getyloc()][player1.getxloc()+1]='p';
			player1.setloc(player1.getxloc()+1,player1.getyloc());
		}
}
/*same as void Game::playermovemap2(char direct) except for floor 3, which has a different design. All the functions/conditions are the same.
SEE: void game::playermovemap2(char direct)!*/	
void Game::playermovemap1(char direct)
{

		if((map1[player1.getyloc()][player1.getxloc()]=='A'||map1[player1.getyloc()+1][player1.getxloc()]=='A'||map1[player1.getyloc()-1][player1.getxloc()]=='A'||map1[player1.getyloc()][player1.getxloc()+1]=='A'||map1[player1.getyloc()][player1.getxloc()-1]=='A')&&direct=='u')
		{
			player1.setmap(2);
			player1.setloc(14,11);
			map2[11][14]=='p';
			return;
		}
		if (direct=='s')
		{
			if(map1[player1.getyloc()+1][player1.getxloc()]=='#' || (map1[player1.getyloc()+1][player1.getxloc()]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map1[player1.getyloc()+1][player1.getxloc()]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map1[player1.getyloc()+1][player1.getxloc()]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map1[player1.getyloc()+1][player1.getxloc()]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map1[player1.getyloc()+1][player1.getxloc()]=='G')
			{
				ghost1.setexists(0);
				
				
				if(player1.getcounter()<1){
					map1[player1.getyloc()+1][player1.getxloc()]==' ';
					player1.setloc(0,15);
					map1[15][0]='p';
					return;
				}

			}
			map1[player1.getyloc()][player1.getxloc()]=' ';
			map1[player1.getyloc()+1][player1.getxloc()]='p';
			player1.setloc(player1.getxloc(),player1.getyloc()+1);
		}
		if (direct=='w')
		{
			if(map1[player1.getyloc()-1][player1.getxloc()]=='#' || (map1[player1.getyloc()-1][player1.getxloc()]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map1[player1.getyloc()-1][player1.getxloc()]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map1[player1.getyloc()-1][player1.getxloc()]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map1[player1.getyloc()-1][player1.getxloc()]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map1[player1.getyloc()-1][player1.getxloc()]=='G')
			{
				ghost1.setexists(0);
				
				
				if(player1.getcounter()<1){
					map1[player1.getyloc()-1][player1.getxloc()]==' ';
					player1.setloc(0,15);
					map1[15][0]='p';
					return;
				}

			}
			map1[player1.getyloc()][player1.getxloc()]=' ';
			map1[player1.getyloc()-1][player1.getxloc()]='p';
			player1.setloc(player1.getxloc(),player1.getyloc()-1);
		}
		if (direct=='a')
		{
			if(map1[player1.getyloc()][player1.getxloc()-1]=='#' || (map1[player1.getyloc()][player1.getxloc()-1]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map1[player1.getyloc()][player1.getxloc()-1]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map1[player1.getyloc()][player1.getxloc()-1]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map1[player1.getyloc()][player1.getxloc()-1]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map1[player1.getyloc()][player1.getxloc()-1]=='G')
			{
				ghost1.setexists(0);
				
				
				if(player1.getcounter()<1){
					map1[player1.getyloc()][player1.getxloc()-1]==' ';
					player1.setloc(0,15);
					map1[15][0]='p';
					return;
				}

			}
			map1[player1.getyloc()][player1.getxloc()]=' ';
			map1[player1.getyloc()][player1.getxloc()-1]='p';
			player1.setloc(player1.getxloc()-1,player1.getyloc());
		}
		if (direct=='d')
		{
			if(map1[player1.getyloc()][player1.getxloc()+1]=='#' || (map1[player1.getyloc()][player1.getxloc()+1]=='D'&&player1.getkeynum()==0))
			{return;
			cout<<"hellooo";}
			else if(player1.getcounter()>0)
				player1.setcounter(player1.getcounter()-1);
			
			
			if(map1[player1.getyloc()][player1.getxloc()+1]=='K')
			{
				player1.setkeynum(player1.getkeynum()+1);
				
				
			}
			else if(map1[player1.getyloc()][player1.getxloc()+1]=='C')
			{
				
				player1.setcounter(20);
				
			}
			else if(map1[player1.getyloc()][player1.getxloc()+1]=='D'&&player1.getkeynum()>0)
			{
				player1.setkeynum(player1.getkeynum()-1);
			}
			else if(map1[player1.getyloc()][player1.getxloc()+1]=='G')
			{
				ghost1.setexists(0);
				
				
				if(player1.getcounter()<1){
					map1[player1.getyloc()][player1.getxloc()+1]==' ';
					player1.setloc(0,15);
					map1[15][0]='p';
					return;
				}

			}
			map1[player1.getyloc()][player1.getxloc()]=' ';
			map1[player1.getyloc()][player1.getxloc()+1]='p';
			player1.setloc(player1.getxloc()+1,player1.getyloc());
		}
}
	
/*takes user input. Passes the value to playermovemapX*/
char player::move()
{
	cout<<"which way to move: "<<endl;
	char direct;
	cin>>direct;
	return direct;
}
/*Stores the 1st floor as a 2d char array*/
void Game::store_map1()
{
	string line;
	ifstream datafile;
	datafile.open("map1.txt");
	if(!datafile)
		cout << "Unable to open file";
	for(int j=0;j<20;j++)
    {
        getline(datafile,line);
		for(int i=0;i<30;i++)
			map1[j][i]=line.at(i);
	}
	map1[15][0]='p';
	cout<<endl;
	for(int j=0;j<20;j++)
    {
        for(int i=0;i<30;i++)
        {
            cout<<map1[j][i];
        }
        cout<<endl;
    }
    datafile.close();
}
/*prints the 2nd floor*/
void Game::printmap2()
{
	int i,j, startx,starty,endx,endy;
	startx=player1.getxloc();
	starty=player1.getyloc();
	endx=player1.getxloc();
	endy=player1.getyloc();
	for(int i=0;startx>0 && i<5;i++)
		startx--;
	for(int i=0;starty>0 && i<5;i++)
		starty--;
	for(int i=0;endx<29 && i<5;i++)
		endx++;
	for(int i=0;endy<19 && i<5;i++)
		endy++;
	/*The array that is used to print takes starts with 
	only the first 5 spaces around the player. Then, each
	time the player moves, more characters from the actual 
	map are copied to it. That array is the one that is printed*/
	for(int j=starty;j<=endy;j++)
    {
		
        for(int i=startx;i<=endx;i++)
        {
            map2print[j][i]=map2[j][i];
        }
        cout<<endl;
    }
	for(int j=0;j<20;j++)
    {
        for(int i=0;i<30;i++)
        {
            cout<<map2print[j][i];
        }
        cout<<endl;
    }
}
/*prints the 1st floor*/
void Game::printmap1()
{
	int i,j, startx,starty,endx,endy;
	startx=player1.getxloc();
	starty=player1.getyloc();
	endx=player1.getxloc();
	endy=player1.getyloc();
	for(int i=0;startx>0 && i<5;i++)
		startx--;
	for(int i=0;starty>0 && i<5;i++)
		starty--;
	for(int i=0;endx<29 && i<5;i++)
		endx++;
	for(int i=0;endy<19 && i<5;i++)
		endy++;
	/*The array that is used to print takes starts with 
	only the first 5 spaces around the player. Then, each
	time the player moves, more characters from the actual 
	map are copied to it. That array is the one that is printed*/
	for(int j=starty;j<=endy;j++)
    {
		
        for(int i=startx;i<=endx;i++)
        {
            map1print[j][i]=map1[j][i];
        }
        cout<<endl;
    }
	for(int j=0;j<20;j++)
    {
        for(int i=0;i<30;i++)
        {
            cout<<map1print[j][i];
        }
        cout<<endl;
    }
}
/*prints the 3rd floor*/
void Game::printmap3()
{
	int i,j, startx,starty,endx,endy;
	startx=player1.getxloc();
	starty=player1.getyloc();
	endx=player1.getxloc();
	endy=player1.getyloc();
	for(int i=0;startx>0 && i<5;i++)
		startx--;
	for(int i=0;starty>0 && i<5;i++)
		starty--;
	for(int i=0;endx<29 && i<5;i++)
		endx++;
	for(int i=0;endy<19 && i<5;i++)
		endy++;
	/*The array that is used to print takes starts with 
	only the first 5 spaces around the player. Then, each
	time the player moves, more characters from the actual 
	map are copied to it. That array is the one that is printed*/
	for(int j=starty;j<=endy;j++)
    {
		
        for(int i=startx;i<=endx;i++)
        {
            map3print[j][i]=map3[j][i];
        }
        cout<<endl;
    }
	for(int j=0;j<20;j++)
    {
        for(int i=0;i<30;i++)
        {
            cout<<map3print[j][i];
        }
        cout<<endl;
    }
}
/*Stores the 2nd floor as a 2d char array*/
void Game::store_map2()
{
	string line;
	ifstream datafile;
	datafile.open("map2.txt");
	if(!datafile)
		cout << "Unable to open file";
	for(int j=0;j<20;j++)
    {
        getline(datafile,line);
		for(int i=0;i<30;i++)
			map2[j][i]=line.at(i);   
	}
	cout<<endl;
	for(int j=0;j<20;j++)
    {
        for(int i=0;i<30;i++)
        {
            cout<<map2[j][i];
        }
        cout<<endl;
    }
    datafile.close();
}
/*Stores the 3rd floor as a 2d char array*/
void Game::store_map3()
{
	string line;
	ifstream datafile;
	datafile.open("map3.txt");
	if(!datafile)
		cout << "Unable to open file";
	for(int j=0;j<20;j++)
    {
        getline(datafile,line);
		for(int i=0;i<30;i++)
			map3[j][i]=line.at(i);
  	}
	cout<<endl;
	for(int j=0;j<20;j++)
    {
        for(int i=0;i<30;i++)
        {
            cout<<map3[j][i];
        }
        cout<<endl;
    }
    datafile.close();
}
void Game::store_printmaps()
{
	for(int j=0;j<20;j++)
    {
        for(int i=0;i<30;i++)
        {
            map1print[j][i]=' ';
			map2print[j][i]=' ';
			map3print[j][i]=' ';
        }
        
    }

}


