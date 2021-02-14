/*
  battleShipOne.cpp *battaglia navale contro il pc sulla costa*
  Author: Manila Mingozzi
  Date: 4-12-2020
  *Help sui codici della mappa: 0-empty; 1-ship; 2-bomb; 3-strike
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void initialize(int v[], int l){
	for (int i=0; i<l; i++){
		v[i]=0;
	}
}

void show(int v[], int l){
	for (int i=0; i<l; i++){
		switch (v[i]){
			case 0: 
				cout << "O " ;
				break;
			case 1:
				cout << "O " ;
				break;
			case 2:
				cout << "- ";
				break;
			case 3:
				cout <<"* ";	
		}
	}
	cout <<endl;
}

void arrange(int v[], int l){
	srand (time (NULL)); 
	int n =rand () % (l-1); 
	v[n]=1;
	v[n+1]=1;
	
}

void launch(int v[], int l){
	int p=-1;

      while (p<0 || p>=l+1){
		cout << "inserire le coordinate in cui sganciare la bomba (tra 1..." <<l <<") ";
		cin >> p;
	}
	p--;
	if (v[p]==0) {
	v[p]=2;
	}
	if (v[p]==1) {
	v[p]=3;
	}
}

bool weWon(int v[], int l){
	for (int i=0; i<l; i++){
		if (v[i]==1) return false ;
	}
	return true;
}

int main()
{	
	const int MAPLEGNTH = 10;
	int map[10];
	int numBomb=0;
	
	system ("color 30");
	
	cout <<"++BENVENUTO IN 'BATTAGLIA NAVALE'++" <<endl;
	
	initialize(map, MAPLEGNTH);
	arrange(map, MAPLEGNTH);
	show(map, MAPLEGNTH);
	
	while (true){
		numBomb ++;
		(launch(map, MAPLEGNTH));
		show(map, MAPLEGNTH);
		if(weWon (map, MAPLEGNTH)) break;
	}
	
	if (numBomb<=3){
		system("color 2F");
      	cout<<"Sei un fenomeno!" <<endl;
	}
	else if(numBomb<=5){
		system ("color 0a");
      	cout<<"Bravo" <<endl;
	}
	if(numBomb>5 && numBomb<=7){
		system("color 1B");
      	cout<<"Puoi fare di meglio..." <<endl;
	}
	else if (numBomb>9){
		system ("color 1f");
		cout <<"sei un po' un disastro" <<endl;
	}
	cout<<"hai distrutto la flotta nemica utilizzando "<<numBomb<<" bombe."<<endl;
	
	return 0;
}

















