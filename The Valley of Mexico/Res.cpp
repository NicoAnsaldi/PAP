#include <iostream>
#include <vector>

using namespace std;

/*
	La idea del algoritmo es pararce en una ciudad (tomarla como la primera del recorrido) y ver que tiene solo 2 opciones 
	para continuar la ruta comercial; una es la ciudad a su izquierda y la otra es la ciudad a su derecha. Esto se debe
	a que si se elige otra ciudad, alguna de estas 2 no se podrían conectar con otra ciudad sin atravezar esa ruta o 
	sin repetir alguna ciudad. Una vez que se elige alguna de las 2, esta ciudad solo tiene 2 opciones (su ciudad aledaña 
	no elegida y la opción de la primera ciudad no elegida) ya que si se elige otra ciudad pasaría lo mismo que antes.
	Entonces asi se va construyendo la ruta. La forma de elegir la ciudad es ver que camino conecta más ciudades dentro 
	de la red comercial.

	Idea de memoización: guardar intervalos de ciudades conectadas, los problemas que esto produce es si la ciudad que se
	intenta agregar a esa red previamente calculada se puede conectar con algunas de sus puntas y el otro problema que tuve
	fue como guardar esa información.

	Complejidad: ya que cada ciudad tiene 2 opciones de las cuales se elige una, la complejidad en peor caso es O(2^n) 

*/



int cantCiudades = 0;

int Backtracking(int cantCiudadesRecorridas, int ciudadActual, int posibleAIzquierda, int posibleADerecha, vector< vector<int> >& matrizRecorrido, vector< vector<int> >& tratadosComerciales);
int listaCircular(int ciudad);
void reconstruirCamino(vector< vector<int> >& matrizRecorrido, int i, int izquierda, int derecha);

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

	//Matriz cantCiudadesxcantCiudades.
	vector< vector<int> > matrizRecorrido(cantCiudades, vector<int>(cantCiudades,0));
	for(int i = 1; i <= cantCiudades; i++){
		int auxIzquierda = listaCircular(i-1);
		int auxDerecha = listaCircular(i+1);
		int res = Backtracking(1, i, auxIzquierda, auxDerecha, matrizRecorrido, tratadosComerciales);
		if(res == cantCiudades){
			reconstruirCamino(matrizRecorrido, i, listaCircular(i-1), listaCircular(i+1));
			break;
		}
	}

	return 0;
}

int Backtracking(int cantCiudadesRecorridas, int ciudadActual, int posibleAIzquierda, int posibleADerecha, vector< vector<int> >& matrizRecorrido, vector< vector<int> >& tratadosComerciales){
	int izquierda = -1;
	int derecha = -1;

	if(cantCiudadesRecorridas > cantCiudades){
		return 0;
	}

	if(tratadosComerciales[ciudadActual-1][posibleAIzquierda-1] == 1){
		izquierda = Backtracking(cantCiudadesRecorridas+1, posibleAIzquierda, listaCircular(posibleAIzquierda-1), posibleADerecha, matrizRecorrido, tratadosComerciales)+1;
	}

	if(tratadosComerciales[ciudadActual-1][posibleADerecha-1] == 1){
		derecha = Backtracking(cantCiudadesRecorridas+1, posibleADerecha, posibleAIzquierda, listaCircular(posibleADerecha+1), matrizRecorrido, tratadosComerciales)+1;
	}

	if(izquierda == -1 && derecha == -1){
		return 0;
	}

	if(izquierda >= derecha){
		if(izquierda > matrizRecorrido[ciudadActual-1][posibleAIzquierda-1]){
			matrizRecorrido[ciudadActual-1][posibleAIzquierda-1] = izquierda;
		}
		return izquierda;
	}else{
		if(derecha > matrizRecorrido[ciudadActual-1][posibleADerecha-1]){
			matrizRecorrido[ciudadActual-1][posibleADerecha-1] = derecha;
		}
		return derecha;
	}
	return 0;
}

void reconstruirCamino(vector< vector<int> >& matrizRecorrido, int i, int izquierda, int derecha){
	
	for(int j = 0; j < cantCiudades; j++){
		cout << i << endl;
		if(matrizRecorrido[i-1][izquierda-1] > matrizRecorrido[i-1][derecha-1]){
			i = izquierda;
			izquierda = listaCircular(i-1);
		}else{
			i = derecha;
			derecha = listaCircular(i+1);
		}
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