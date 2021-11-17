//Jogo da velha com matriz 3x3;
//para 2 jogadores;
#include<iostream>
#include<locale.h>
/*retornar -1 (ninguem ganhou),
retornar 0 (player 1 ganhou), retornar 1 (player 2 ganhou);*/
int VseGanho(char Ptab[][3]); 

/*verifica se tem espaço para marcar 'X' ou  'O',
se tiver retornar 1, se não tiver retornar 0;*/
bool VseEspac(char Ptab[][3], int x,int y);

//mostrar a matriz
void Mostrar_Matrx (char Ptab[][3]);
using namespace std;
int main(void){ int x,y; bool ocupa ,vitoria = false; 
 short int vv,jogada=0;
 char tab[3][3];     /*{0,0,0,   <- -//neste formato
                       0,0,0,
                       0,0,0};*/    //tabuleiro 3x3
     for(int i=0; i<3; i++)
        for(int j=0; j<3; j++)
    tab[i][j] = '-';
    cout << "\t___BEM-VINDO!___";
    cout << "\n\t ___INICIALIZANDO O JOGO DA VELHA___\n";
    system("pause");

 do{ Mostrar_Matrx(tab);
     jogada++; //Conta o numero de jogadas;
    bool jogo = (jogada%2==0); //'jogo', só pode ser 0 ou 1;
     switch(jogo){ 
        //se a variavel 'jogo' for 'false', vez do jogador 1;
   do{ 
      case 0: cout << "\t\n Jogador 1 faca sua jogada"<<"___VOCE E 'X'";
         cout <<"\n\t Escolha linha e coluna, de 1 a 3"; 
         cout <<"\nLinha\n";
         cin >> x; 
         cout <<"\nColuna\n";
         cin>>y;     
         x--, y--; //tratando os dados;
         bool esp = 0;
         if((x<3 && y<3)&&(x>-1 && y>-1)) //faixa de casas ok;   
            esp = VseEspac(tab,x,y);
            else cout <<" \n Entrada invalida!"; 
         if(esp){
            tab[x][y]='X'; ocupa=false;}
            else {cout<<"\n Casa ocupada! ou Entrada invalida!";
             ocupa = true;
            }
            vv=VseGanho(tab);
       if(vv==0)
         vitoria=true;   
      }while((ocupa)&&(jogada<10));
     break;
     //se a variavel 'jogo' for 'true', vez do jogador 2;
   do{ 
      case 1: cout << "\t\n Jogador 2 faca sua jogada"<<"___VOCEE E 'O'";
         cout <<"\n\t Escolha linha e coluna, de 1 a 3"; 
         cout <<"\nLinha\n";
         cin >> x; 
         cout <<"\nColuna\n";
         cin>>y;     
         x--, y--; //tratando os dados;
         bool esp = 0;
         if((x<3 && y<3)&&(x>-1 && y>-1))   
            esp = VseEspac(tab,x,y);
            else cout <<" \n Entrada invalida!"; 
         if(esp){
            tab[x][y]='O'; ocupa=false;}
            else {cout<<"\n Casa ocupada! ou Entrada invalida!";
             ocupa = true;
            }
         vv = VseGanho(tab);   
      if(vv==1)
         vitoria=true;
      }while((ocupa)&&(jogada<10)); 
     break;
    // Limite de 9 jogadas, para o laço while;
    }}while((vitoria==false)&&(jogada<10)); 
   Mostrar_Matrx(tab);
   //Resultado final;
   switch(vv){
       case -1: cout <<"\n Empate!, FIM DE JOGO! \o/";
      break;
       case 0: cout <<"\n Jogador 1 venceu!, FIM DE JOGO!\o/";
      break;
       case 1: cout <<"\n Jogador 2 venceu!, FIM DE JOGO!\o/";
   }
    system("pause");
}

int VseGanho(char Ptab [][3] ){
short int win = -1; //flag confira se ganhou;
 for(int i=0; i<3; i++){ // testa as colunas ;
     if(Ptab[0][i]=='X' && Ptab[1][i]=='X' && Ptab[2][i]=='X')
     win = 0;
    }
 if(win==-1){
     for(int i=0; i<3; i++){ // testa as linhas ;
     if(Ptab[i][0]=='X' && Ptab[i][1]=='X' && Ptab[i][2]=='X')
     win = 0;}
    }
 if(win==-1){ //diagonais
     if (Ptab[0][0]=='X' && Ptab[1][1]=='X' && Ptab[2][2]=='X')
     win = 0; //diagonal 1;
     else if (Ptab[2][0]=='X' && Ptab[1][1]=='X' && Ptab[0][2]=='X')
     win = 0; //diagonal 2;
    }
 
  //abaixo testa o 'player 2' ;
     for(int i=0; i<3; i++){ // testa as colunas
     if(Ptab[0][i]=='O' && Ptab[1][i]=='O' && Ptab[2][i]=='O')
     win = 1; 
    }
 if(win==-1){
     for(int i=0; i<3; i++){ // testa as linhas
     if(Ptab[i][0]=='O' && Ptab[i][1]=='O' && Ptab[i][2]=='O')
        win = 1;}
    }
 if(win==-1){ //diagonais 
     if (Ptab[0][0]=='O' && Ptab[1][1]=='O' && Ptab[2][2]=='O')
        win = 1; //diagonal 1
     else if(Ptab[2][0]=='O' && Ptab[1][1]=='O' && Ptab[0][2]=='O')  
        win = 1; //diagonal 2 
  }
   return win;
}
bool VseEspac(char Ptab[][3], int x,int y){
 bool esp = 0;
 if(Ptab[x][y]=='-')
  esp = true;
 else
  {esp = false;}
  return esp;
}

void Mostrar_Matrx (char Ptab[][3]){
   unsigned short int cont = 1;
   for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(cont%3==0)
               cout <<"\t"<<Ptab[i][j]<<"\n";
               else cout <<"\t"<<Ptab[i][j]<<"\t";
               cont++; 
     }   
   }
}