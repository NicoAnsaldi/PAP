#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int width = 0;
int height = 0;
int pieces = 0;

void mostrarMatriz(vector< vector< pair<int,int> > >& matriz);
void DFS(vector< vector<int> >& gird, vector< vector<int> >& matrizColoreo);

int main(){
	int cases;
	cin >> cases;
	
	for(int i = 0; i < cases; i++){
		cin >> width;
		cin >> height;
		cin >> pieces;

		vector< vector< pair<int,int> > > grid1(width, vector< pair<int,int> >(height,pair<int,int>(0,-1)));
		for(int j = 0; j < pieces; j++){
			int x = 0;
			int y = 0;
			cin >> x >> y;
			grid1[x][y].first = 1;
		}

		 mostrarMatriz(grid1);
		vector< vector< pair<int,int> > > grid2 (width, vector< pair<int,int> >(height,pair<int,int>(0,-1)));
		for(int j = 0; j < pieces; j++){
			int x = 0;
			int y = 0;
			cin >> x >> y;
			grid2[x][y].first = 1;
		}
		mostrarMatriz(grid2);
	}

	return 0;
}


void mostrarMatriz(vector< vector< pair<int,int> > >& matriz){

	for(int i = 0; i < width; i++){
		for(int j = 0; j < height; j++){
			cout << "("<< matriz[i][j].first << ", " << matriz[i][j].second << ") ";
		}
		cout << endl;
	}
	cout << endl << endl;
}