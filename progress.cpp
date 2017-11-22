#include <string>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "sensores.h"
//dev added
#include <stdlib.h>
#include <unistd.h>

#define DATASIZE 30	//data height/ display size
#define GRAPHWIDTH 20	//data height/ display size
#define GREFRESH 1  //global refresh rate
#define CREFRESH 3 	//chart refresh rate


using namespace std;

int time_ticks = 0;
int avg_temp, avg_moist, avg_pres;
char chartdata [GRAPHWIDTH][DATASIZE];
const char block = 'x';

//print current temp, humidiry and pressure
void get_current_stats(){
	
	cout<<"| Temperatura | Humedad | Presion |"<<endl;
	int temperature = rand() % 1000 + 1;
	cout<<"|";
	cout.width(8);
    cout<< getTemperatura();//todo: get temperatura
    cout.width(6);
	cout<<"|";
	cout.width(6);
	cout<< rand() % 30 + 1;//todo: get humedad
	cout.width(4);
	cout<<"|";
	cout.width(6);
	cout<< rand() % 50 + 1;//todo: get presion
	cout.width(4);
	cout<<"|";
}

//set column height value
void set_column_height(int col, int key){
	for (int i=0; i<DATASIZE; i++){
		chartdata[i][key]='.';
	}
	for (int i=DATASIZE-col; i<DATASIZE; i++){
		chartdata[i][key]=block;
	}
}


void get_graph(int time, int value){
	set_column_height(value/100, time%DATASIZE);
	
	for(int i=0; i<GRAPHWIDTH; i++){
		for(int j=0; j<DATASIZE; j++){
		cout<<chartdata[i][j]<<" ";
		}
		cout<<"\n";
	}

}

int main(int argc, char* argv[]) {
	//set array to 0
	for(int i=0; i< DATASIZE; i++){
		for(int j=0; j<DATASIZE; j++){
			chartdata[i][j]=0;
		}
	}

  int N = 100;
	
  for(int i = 0; i < N; i++) {
    // compute percentage
    cout<<"Datos Actuales :"<<endl;
	get_current_stats();
	cout<<"\nDatos Historicos:"<<endl;
	//print graph
	get_graph(i, rand()%1000+1);
	sleep(GREFRESH);
    system("clear");
    //cout << p << endl;
    
  }

  return 0;
}

// print progress
