#include <iostream>
#include <vector>

using namespace std;

int width = 0;
int height = 0;
int pieces = 0;

void mostrarMatriz(vector< vector<int> >& matriz);
void DFS(vector< vector<int> >& gird, vector< vector<int> >& matrizColoreo);

int main(){
	int cases;
	cin >> cases;
	
	for(int i = 0; i < cases; i++){
		cin >> width;
		cin >> height;
		cin >> pieces;

		vector< vector<int> > grid1(width, vector<int>(height,0));
		for(int j = 0; j < pieces; j++){
			int x = 0;
			int y = 0;
			cin >> x >> y;
			grid1[x][y] = 1;
		}

		// mostrarMatriz(grid1);
		vector< vector<int> > grid2(width, vector<int>(height,0));
		for(int j = 0; j < pieces; j++){
			int x = 0;
			int y = 0;
			cin >> x >> y;
			grid2[x][y] = 1;
		}
		//mostrarMatriz(grid2);

		vector< vector<int> > matrizColoreo(width, vector<int>(height,-1));
		
		

	}

	return 0;
}


void mostrarMatriz(vector< vector<int> >& matriz){

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			cout << matriz[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl << endl;
}