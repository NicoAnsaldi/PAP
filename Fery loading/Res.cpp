#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

void mostrarVector(vector<int>&);
int PD(int i, int pI, int pD, vector<int>& cars, vector< vector< pair<int,int> > >& matriz);
void mostrarMatriz(vector< vector< pair<int, int> > >&, int, int);
void inicializarMatriz(vector< vector< pair<int,int> > >& matriz, int cars, int ferryLarge);
void reconstruirCamino(vector< vector< pair<int,int> > >& matriz, vector<int>& cars, int res, int ferryLarge);

int main(){
	int cantCases = 0;
	int ferryLarge = 0;
	cin >> cantCases;
	
	while(cantCases > 0){
		cin >> ferryLarge;
		ferryLarge = ferryLarge*100;
		
		vector<int> cars;
		int res=0;

		int aux = 0;
		cin >> aux;
		
		while(aux > 0){
			cars.push_back(aux);
			cin >> aux;
		}

		vector< vector< pair<int,int> > > matriz;

		inicializarMatriz(matriz, cars.size(), ferryLarge+1);

		res = PD(0, ferryLarge, ferryLarge, cars, matriz);
		
		//mostrarMatriz(matriz, cars.size(), ferryLarge+1);
		cout << res << endl;
		reconstruirCamino(matriz, cars, res, ferryLarge);
		
		cantCases --;
		if(cantCases > 0){
			cout << endl;
		}
	}

	return 0;
}



int PD(int i, int pI, int pD, vector<int>& cars, vector< vector< pair<int,int> > >& matriz){

	int a = 0;
	int b = 0;

	if(i >= cars.size()){
		return 0;
	}

	if(matriz[i][pI].first != -1){
		return matriz[i][pI].first;
	}

	if(matriz[i][pD].first != -1){
		return matriz[i][pI].first;
	}

	if(cars[i] <= pI){
		int aux = i;
		a = PD(aux+1, pI-cars[i], pD, cars, matriz)+1;
	}

	if(cars[i] <= pD){
		int aux = i;
		b = PD(aux+1, pI, pD-cars[i], cars, matriz)+1;
	}

	if(a == 0 && b == 0){
		return 0;
	}else{
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

	return -1;
}

void reconstruirCamino(vector< vector< pair<int,int> > >& matriz, vector<int>& cars, int res, int ferryLarge){
	int i = 1;
	int ladoI = ferryLarge;
	int ladoD = ferryLarge;

	if(res > 0){
		ladoI -= cars[0];
		cout << "port" << endl;
	}

	while(i < res){
		pair<int,int> left(-1,-1);
		pair<int, int> right(-1,-1);

		int aux = (ladoI-cars[i]);
		if((matriz[i][aux].first == (res-i)) && (matriz[i][aux].second == 1)){
			ladoI = aux;
			left = matriz[i][ladoI];
			cout << "port" << endl;
		}

		aux = (ladoD-cars[i]);
		if((matriz[i][aux].first == (res-i)) && (matriz[i][aux].second == 0)){
			ladoD -= cars[i];
			right = matriz[i][ladoD]; 
			cout << "starboard" << endl;
		}

		if(left.first == -1 && right.first == -1){
			break;
		}

		i++;
	}
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

void mostrarVector(vector<int>& x){
	int i = 0;
	while(i < x.size()){
		cout << x[i];
		i++;
	}
}

void mostrarMatriz(vector< vector< pair<int,int> > >& matriz, int cars, int ferry){
	int i = 0;
	int j = 0;

	while(i < cars){
		j = 0;
		while(j < ferry){
			cout << "(" << matriz[i][j].first << " ," << matriz[i][j].second << ")" << "  ";
			j++;
		}
		cout << endl<<endl;
		i++;
	}

}

