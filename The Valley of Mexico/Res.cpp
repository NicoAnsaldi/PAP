#include <iostream>
#include <vector>

using namespace std;

void mostrarMatriz(vector< vector<int> >& tratadosComerciales, int cantCiudades);
int PD(int cantCiudadesRecorridas, int ciudadActual, int posibleADerecha, int posibleAIzquierda, vector<int>* recorrido, vector< vector<int> >& tratadosComerciales, int cantCiudades);


int main(){
	int cantCiudades;
	int cantTratados;

	cin >> cantCiudades;
	cin >> cantTratados;

	vector< vector<int> > tratadosComerciales(cantCiudades, vector<int>(cantCiudades, 0));
	for(int i = 0; i < cantTratados; i++){
		int ciudadA = 0;
		int ciudadB = 0;
		cin >> ciudadA;
		cin >> ciudadB;
		//El "-1" es porque la matriz va de 0 a cantCiudades-1 pero el input va de 1 a cantCiudades.
		//Y la matriz es simétrica, si la ciudad i se relaciona con la j; la j se relaciona con la i.
		tratadosComerciales[ciudadA-1][ciudadB-1] = 1;
		tratadosComerciales[ciudadB-1][ciudadA-1] = 1;
	}

	//Matriz cxc.
	//mostrarMatriz(tratadosComerciales, cantCiudades);
	vector<int> recorrido(n+1, 0);
	for(int i = 1; i <= cantCiudades; i++){
		int res = PD(0, i, i, i, &recorrido, tratadosComerciales, cantCiudades);
		if(res == cantCiudades){
			break;
		}
	}

	return 0;
}

int PD(int cantCiudadesRecorridas, int ciudadActual, int posibleADerecha, int posibleAIzquierda, vector<int>* recorrido, vector< vector<int> >& tratadosComerciales, int cantCiudades){
	if(cantCiudadesRecorridas > cantCiudades){
		return 0;
	}

	if(tratadosComerciales[ciudadActual-1][posibleAIzquierda-1] == 0 && tratadosComerciales[ciudadActual-1][posibleADerecha-1] == 0){
		return 0;
	}

	int a = PD(cantCiudadesRecorridas++, )


	return 0;
}


void mostrarMatriz(vector< vector<int> >& matriz, int x){
	for(int i = 0; i < x; i++){

		for(int j = 0; j < x; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
} 