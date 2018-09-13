#include <iostream>
#include <vector>

using namespace std;

int cantCiudades = 0;

void mostrarMatriz(vector< vector<int> >& tratadosComerciales);
int PD(int cantCiudadesRecorridas, int ciudadActual, int posibleAIzquierda, int posibleADerecha, vector<int>& recorrido, vector< vector<int> >& tratadosComerciales);
int listaCircular(int ciudad);

int main(){
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
	//mostrarMatriz(tratadosComerciales);
	vector<int> recorrido(cantCiudades, 0);
	for(int i = 1; i <= cantCiudades; i++){
		int res = PD(1, i, listaCircular(i--), listaCircular(i++), recorrido, tratadosComerciales);
		if(res == cantCiudades){
			break;
		}
		recorrido = vector<int>(cantCiudades, 0);
	}

	for(int i = 0; i < recorrido.size(); i++){
		cout << recorrido[i] << endl;
	}

	return 0;
}

int PD(int cantCiudadesRecorridas, int ciudadActual, int posibleAIzquierda, int posibleADerecha, vector<int>& recorrido, vector< vector<int> >& tratadosComerciales){
	int izquierda = -1;
	int derecha = -1;

	if(cantCiudadesRecorridas > cantCiudades){
		return 0;
	}

	if(tratadosComerciales[ciudadActual-1][posibleAIzquierda-1] == 1){
		izquierda = PD(cantCiudadesRecorridas++, posibleAIzquierda, listaCircular(posibleAIzquierda--), posibleADerecha, recorrido, tratadosComerciales);
	}

	if(tratadosComerciales[ciudadActual-1][posibleADerecha-1] == 1){
		derecha = PD(cantCiudadesRecorridas++, posibleADerecha, posibleAIzquierda, listaCircular(posibleADerecha++), recorrido, tratadosComerciales);
	}

	if(izquierda == -1 && derecha == -1){
		return 0;
	}

	if(izquierda >= derecha){
		recorrido[ciudadActual-1] = posibleAIzquierda;
		return izquierda;
	}else{
		recorrido[ciudadActual-1] = posibleADerecha;
		return derecha;
	}
	return 0;
}


void mostrarMatriz(vector< vector<int> >& matriz){
	for(int i = 0; i < cantCiudades; i++){

		for(int j = 0; j < cantCiudades; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
} 

int listaCircular(int ciudad){
	if(ciudad > cantCiudades){
		return 1;
	}
	if(ciudad < 1){
		return cantCiudades;
	}
	return ciudad;
}