#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

int PD(int i, int pI, int pD, vector<int>& cars, vector< vector< pair<int,int> > >& matriz);
void inicializarMatriz(vector< vector< pair<int,int> > >& matriz, int cars, int ferryLarge);
void reconstruirSolucion(vector< vector< pair<int,int> > >& matriz, vector<int>& cars, int res, int ferryLarge);

int main(){
	int cantCases = 0;
	int ferryLarge = 0;
	cin >> cantCases;
	
	while(cantCases > 0){
		cin >> ferryLarge;
		ferryLarge = ferryLarge*100; //Esto es para trabajar todo en cm.
		
		vector<int> cars;
		int res=0;

		//Aca construyo el vector de autos (longitudes).
		int aux = 0;
		cin >> aux;
		while(aux > 0){
			cars.push_back(aux);
			cin >> aux;
		}

		/*
		La idea del algoritmo es tener una matríz (cant de autos x long del ferry+1) de tuplas
		donde cada tupla representa la cantidad de autos cargados que se consigue
		al cargar el auto i a uno de lados (0=starboard, 1=port). El peso esta para la 
		memoización, para facilitar la creación de la matríz y para buscar la solución óptima. 
		La razón de tomar long del ferry + 1 es por el caso donde no agregue autos todavía a 
		algunos de los lados.
		*/
		vector< vector< pair<int,int> > > matriz;
		inicializarMatriz(matriz, cars.size(), ferryLarge+1);

		res = PD(0, ferryLarge, ferryLarge, cars, matriz);
		
		cout << res << endl;
		reconstruirSolucion(matriz, cars, res, ferryLarge);
		
		cantCases --;
		//Este if es para pasar el juez que no tiene un salto de linea final.
		if(cantCases > 0){
			cout << endl;
		}
	}

	return 0;
}

void inicializarMatriz(vector< vector< pair<int,int> > >& matriz, int cars, int ferryLarge){
	pair<int,int> valorInicial(-1,-1);
	int i = 0;
	while(i < cars){
		vector< pair<int,int> > a(ferryLarge, valorInicial);
		matriz.push_back(a);
		i++;
	}
}

int PD(int i, int pI, int pD, vector<int>& cars, vector< vector< pair<int,int> > >& matriz){

	int a = 0;
	int b = 0;

	//Caso base
	if(i >= cars.size()){
		return 0;
	}

	//Memoización, si llegue a un caso que ya calcule antes entonces no hago la recursión.
	if(matriz[i][pI].first != -1){
		return matriz[i][pI].first;
	}

	if(matriz[i][pD].first != -1){
		return matriz[i][pI].first;
	}

	//Si el auto i puede subir al lado port entonces lo agrego y hago la recursión.
	//Actualizo el i y el peso total que queda del lado port.
	if(cars[i] <= pI){
		int aux = i;
		a = PD(aux+1, pI-cars[i], pD, cars, matriz)+1;
	}

	//Aca lo mismo que antes pero para el lado starboard.
	if(cars[i] <= pD){
		int aux = i;
		b = PD(aux+1, pI, pD-cars[i], cars, matriz)+1;
	}

	//Este caso es cuando no puedo subir el auto i a ninguno de los lados, entonces no hago la recursión y devuelvo 0
	//que representa que no agregue autos al ferry.
	if(a == 0 && b == 0){
		return 0;
	}else{
		/*
		Luego veo cual de las dos ramas me dio mas grande (en cantidad de autos agregados) y agrego el 
		auto i al lado que dio más grande. Antes de hacer eso chequeo que la solución sea mejor que 
		una que ya hubiese calculado.
		*/
		if(a>=b){
			if(a > matriz[i][pI-cars[i]].first){
				pair<int,int> aux(a, 1);
				matriz[i][pI-cars[i]] = aux;
			}
			return matriz[i][pI-cars[i]].first;
		}else{
			if(b > matriz[i][pD-cars[i]].first){
				pair<int,int> aux(b, 0);
				matriz[i][pD-cars[i]] = aux;
			}
			return matriz[i][pD-cars[i]].first;
		}
	}

	return 0;
}

void reconstruirSolucion(vector< vector< pair<int,int> > >& matriz, vector<int>& cars, int res, int ferryLarge){
	//La idea de la funcíon es imprimir por pantalla como son cargados los autos al ferry respetando el orden 
	//que estos tienen.
	int i = 1;
	int ladoI = ferryLarge;
	int ladoD = ferryLarge;

	//El primer auto, mientras entre en el ferry, puede ir a cualquiera de los 2 lados. 
	//Siempre va al lado port.
	if(res > 0){
		ladoI -= cars[0];
		cout << "port" << endl;
	}
	/*
	Luego recorro la matriz para cargar los otros autos. Aca estoy usando el valor que me devolvio la 
	función PD que es la máxima cantidad de autos que puedo cargar en el ferry.
	Como los autos son cargados en el orden original y solo puedo cargarlos en port o starboard, solo recorro
	los 2 posibles caminos de la matriz. Para esto uso aux que es la longitud restante de uno de los lados
	menos la longitud del siguiente auto a, de ser posible, ser cargado al ferry.
	*/
	while(i < res){
		int aux = (ladoI-cars[i]);
		if((matriz[i][aux].first == (res-i)) && (matriz[i][aux].second == 1)){
			ladoI = aux;
			cout << "port" << endl;
		}

		aux = (ladoD-cars[i]);
		if((matriz[i][aux].first == (res-i)) && (matriz[i][aux].second == 0)){
			ladoD = aux;
			cout << "starboard" << endl;
		}
		i++;
	}
}


//En peor caso estoy llenando la matriz de tuplas, luego la funcion PD tarda O(n*k), donde n es la cantidad de autos
//y k es la cantidad de longitudes posibles [0,long de ferry], y como la función que reconstruye la solución 
//es O(n) la complejidad total del ejercicio es O(n*k).