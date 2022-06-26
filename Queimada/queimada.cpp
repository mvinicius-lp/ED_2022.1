#include <iostrem>
#include <stdio.h>

using namespace std;

const char TREE = '#';
const char FIRE = 'o';
const char EMPTY = '.'; 

//função que mostra os elementos de uma matriz
void mostra(int nl, int nc, char mat[nl][nc]){
    for(int l = 0; l < nl; l++){
        for(int c = 0; c < nc; c++)
            cout << mat[l][c];
        final("");
    }
}

void tocar_fogo(int nl, int nc, char mat[nl][nc], int l, int c){
    if((l < 0) || (l >= nl) || (c < 0) || (c >= nc)) //verifica se a matriz é válida
        return;
    if(mat[l][c] != TREE)
        return;
    mat[l][c] = FIRE;

    //casos em que toca fogo em uma arvore
    tocar_fogo(nl, nc, mat, l, c + 1);
    tocar_fogo(nl, nc, mat, l, c - 1);
    tocar_fogo(nl, nc, mat, l - 1, c);
    tocar_fogo(nl, nc, mat, l + 1, c);
}

int main(){
    int nl = 0;
    int nc = 0;
    int l = 0;
    int c = 0;
    cin >> nl, nc, l, c;
    char mat[nl][nc];

    //preenche a matriz
    for(int l = 0; l < nl; l++)
        for(int c = 0; c < nc; c++)
            cin >> mat[l][c];
    tocar_fogo(nl, nc, mat, l, c);
    mostra(nl, nc, mat);

}