#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

//definindo os estados do caminho
#define v 0 // vazio
#define p 1 // parede
#define s 2 // saida
#define comida 3 // comida

int pontos=0, linha=1, coluna=1;

//criando um mapa 13x13
int mapa[13][13] = {
    1,1,1,1,1,1,1,1,1,1,1,1,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,0,0,0,0,0,0,0,0,0,0,0,1,
    1,1,1,1,1,1,1,1,1,1,1,2,1
};

//monta um mapa vazio 
void monta_mapa_vazio (){
    int l,c;
    for(l=0; l<13; l++){
        for(c=0; c<13; c++){
            if (l==linha && c==coluna) cout << (":)") << endl;
            else{
                if (mapa[l][c]==v) cout << ("  ") << endl;
                if (mapa[l][c]==s) cout << ("##") << endl;
                if (mapa[l][c]==p) cout <<  ("%c%c",219.219) << endl;
                if (mapa[l][c]==c) cout <<  ("%c%c",4,4) << endl;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main(){
    int a, i;
    int key, saiu=0;

    monta_mapa_vazio();

    //verifica os casos 
    while (saiu==0){
        key=getch();
        if (key=='w' || key=='W'){
            linha--;
            if(mapa[linha][coluna]==p) linha++;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if (key=='a' || key=='A'){
            coluna--;
            if (mapa[linha][coluna]==p) coluna++;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if (key=='s' || key=='S'){
            linha++;
            if (mapa[linha][coluna]==p) linha--;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if (key=='d' || key=='D'){
            coluna++;
            if(mapa[linha][coluna]==p) coluna--;
            if(mapa[linha][coluna]==comida){
                pontos++;
                mapa[linha][coluna] = v;
            }
        }
        if (mapa[linha][coluna]==s) saiu++;
        system ("cls");
        monta_mapa_vazio();
    } // Término WHILE
    system ("cls");
    cout << ("Você conseguiu sair do labirinto! Você fez " << pontos << ",pontos") << endl;
    system ("pausa");
}