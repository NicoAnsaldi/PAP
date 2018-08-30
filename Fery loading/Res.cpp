#include <iostream>
#include <vector>
#include <algorithm>  

using namespace std;

void mostrarVector(vector<int>&);
int PD(int i, int pI, int pD, vector<int>& cars, vector<int>& res, vector< vector<int> >& matriz);
void mostrarMatriz(vector< vector<int> >&, int, int);

int main(){
	int cantCases = 0;
	int ferryLarge = 0;
	cin >> cantCases;
	
	while(cantCases > 0){
		cin >> ferryLarge;
		ferryLarge = ferryLarge*100;
		
		vector<int> cars;

		int aux = 0;
		cin >> aux;
		
		while(aux > 0){
			cars.push_back(aux);
			cin >> aux;
		}

		vector<int> res(cars.size(),-1);
		vector< vector<int> > matriz(cars.size(), vector<int>(ferryLarge+1,-1));

		PD(0, ferryLarge, ferryLarge, cars, res, matriz);
		
		//mostrarMatriz(matriz, cars.size(), ferryLarge+1);

		int i = 0;
		int acum = 0;
		while(i < res.size()){
			if(res[i] != -1){
				acum++;
			}
			i++;
		}

		cout << acum << endl;

		i=0;
		while(i < res.size()){
			if(res[i] == 1) cout << "port" << endl;
			if(res[i] == 0) cout << "starboard" << endl;
			i++;
		}
		
		cout << endl;
		cantCases --;
	}

	return 0;
}



int PD(int i, int pI, int pD, vector<int>& cars, vector<int>& res, vector< vector<int> >& matriz){

	int a = 0;
	int b = 0;

	if(i >= cars.size()){
		return 0;
	}

	if(matriz[i][pI] != -1){
		return matriz[i][pI];
	}

	if(matriz[i][pD] != -1){
		return matriz[i][pI];
	}

	if(cars[i] <= pI){
		int aux = i;
		a = PD(aux+1, pI-cars[i], pD, cars, res, matriz)+1;
	}

	if(cars[i] <= pD){
		int aux = i;
		b = PD(aux+1, pI, pD-cars[i], cars, res, matriz)+1;
	}

	if(a == 0 && b == 0){
		return 0;
	}else{
		if(a>=b){
			if(a > matriz[i][pI-cars[i]]){
				matriz[i][pI-cars[i]] = a;
				res[i] = 1;
			}
			return matriz[i][pI-cars[i]];
		}else{
			if(b > matriz[i][pD-cars[i]]){	
				matriz[i][pD-cars[i]] = b;
				res[i] = 0;
			}
			return matriz[i][pD-cars[i]];
		}
	}

	return -1;
}

void mostrarVector(vector<int>& x){
	int i = 0;
	while(i < x.size()){
		cout << x[i];
		i++;
	}
}

void mostrarMatriz(vector< vector<int> >& matriz, int cars, int ferry){
	int i = 0;
	int j = 0;

	while(i < cars){
		j = 0;
		while(j < ferry){
			cout << matriz[i][j]<< "  ";
			j++;
		}
		cout << endl<<endl;
		i++;
	}

}

