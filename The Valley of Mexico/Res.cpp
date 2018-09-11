#include <iostream>
#include <vector>

using namespace std;

void mostrarMatriz(vector< vector<int> >& tratadosComerciales, int cantCiudades);
int PD(vector<int> ciudadesAConectar, vector< vector<int> >& tratadosComerciales);


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
	vector<int> ciudadesAConectar;
	for(int i = 1; i <= cantCiudades; i++){
		ciudadesAConectar.push_back(i);
	}

	PD(ciudadesAConectar, tratadosComerciales);



	return 0;
}

int PD(vector<int> ciudadesAConectar, vector< vector<int> >& tratadosComerciales){
	int ciudadAUnir = ciudadesAConectar[0];
	for(int i = 0; i < ciudadesAConectar.size(); i++){
		if(tratadosComerciales[ciudadAUnir-1][ciudadesAConectar[i]-1] == 1){
			vector<int> ciudadADerecha;
			vector<int> ciudadAIzquierda;

			for(int j = ; j < )
		}
	}




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