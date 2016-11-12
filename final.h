#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <unistd.h>
using namespace std;
#define MAZE
class Character{
	protected:
		int xloc,yloc,map;
		char symbol;
	public:

		Character(int x,int y, char sym){
			xloc=x;
			yloc=y;
			symbol=sym;
			map=1;
		}
		Character(char sym){
			symbol=sym;
		}
		int getmap(){return map;}
		int setmap(int i){map=i;}
		int getxloc(){return xloc;}
		int getyloc(){return yloc;}
		void setloc(int x,int y){
			xloc=x;
			yloc=y;
		}
		
	
};



class player:public Character{
	private:
		int counter,keynum;
	public:
		char move();
		int getcounter(){return counter;}
		int getkeynum(){return keynum;}
		void setcounter(int i){counter=i;}
		void setkeynum(int i){keynum=i;}
		player():Character(0,15,'p'){
			counter=0;
			keynum=0;
			map=1;
		}

		
	
};
class ghost:public Character{
	private:
		int exists;
	public:
		int move(player,char[20][30],int);
		ghost():Character('g'){exists=1;}
		int getexists(){return exists;}
		void setexists(int i){exists=i;}
		
};
class Game{
	private:
		char map1[20][30],map2[20][30],map3[20][30],map1print[20][30],map2print[20][30],map3print[20][30];
		ghost ghost1;
		ghost ghost2;
		ghost ghost3;
		player player1;
	public:
		void playermovemap1(char);
		void playermovemap2(char);
		void playermovemap3(char);
		void setghosts();
		void store_printmaps();
		void store_map1();
		void store_map2();
		void store_map3();
		void printmap1();
		void printmap2();
		void printmap3();
		Game(){
			store_map1();
			store_map2();
			store_map3();
			store_printmaps();
		}
		void play();
		
	
	
};