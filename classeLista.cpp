/*
  classeLista.cpp
  Author:Manila Mingozzi
  Date:05-02-2021
*/
#include <string>
#include <cstdlib>
#include <time.h>
#include <iostream>
using namespace std;

class Lista{
	int l;
	string * data;
	int top=0;
	public:
	Lista (int lunghezza){
		l=lunghezza;
		data=new string[l];
		
	}
	int len(){
		cout <<l <<endl;
		return l;
	}
	void add(string v){
		if (top<100){
			data[top]=v;
			top++;
		}
	}
	int generaNumero(){
		return (rand () %20) +1;
	}
	string read(int i){
		return data[i];
	}
	void print(){
		for (int i=0; i<top; i++){
			cout<< read(i) <<endl;
		}
	}
	string write (){
      	string s;
      	int x;
		x=generaNumero();
      	for (int i=0; i<x; i++){
         		s=s+"*";
      	}
	return s;
      }
	void sort(){
		for (int k=0; k<top; k++){
			for (int i=0; i<top-1; i++){
				if (data[i]>data[i+1]){
					string temp=data[i];
					data[i]=data[i+1];
					data[i+1]=temp;
				}
			}
		}
	}
	/*void sort(){
		for (int k=0; k<top; k++){
			for (int i=0; i<top-1; i++){
				if (data[i]>data[i+1]){
					string temp=data[i];
					data[i]=data[i+1];
					data[i+1]=temp;
				}
			}
		}
	}*/	
};

int main()
{
	srand(time(NULL));

	Lista a(100);
	/*a.len();
	for (int i=0; i<100; i++){
		a.add(a.write());
	}*/

	
      a.add("Cucciolo");
      a.add("Eolo");
      a.add("Dotto");
      a.add("Gongolo");
      a.add("Pisolo");
      a.add("Mammolo");
      a.add("Brontolo");
      
	a.print();
	a.sort();
	cout <<endl <<"Vettore ordinato: " <<endl;
	a.print();
	
	return 0;
}

