#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <locale.h>

int tamanhoVetor,q,p,c,s,s1,controleWhile,cabecaDeLeitura,qEtapa,contador;
int *vet;
//  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
// P e Q foram utilizados para os valores inseridos, s e s1 foram utilizados na estrutura switch, c e controleWhile foram utilizados na estruturas de repetição
// tamanhoVetor é o tamanho do vetor vet, cabecaDeLeitura indica onde esta apontando o cabeçote da máquina de turing
// qEtapa foi usado para indicar em qual estado está a máquina, contador foi usado para demonstrar o resultado da operação, indicando o número de 1's contidos no vetor vet e exibir resultado
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
main(){
    setlocale(LC_ALL,"");
    printf("---------------------------------------------\n");
    printf("|       FACULDADE MAURÍCIO DE NASSAU        |\n");
    printf("|         ENGENHARIA DA COMPUTAÇÃO          |\n");
    printf("|    COMPUTABILIDADE E LÓGICA MATEMÁTICA    |\n");
    printf("|                                           |\n");
    printf("| PROFESSOR: ANTENOR PARNAÍBA               |\n");
    printf("| ALUNO: FERNANDO ANTÔNIO DIAS TORRES FILHO |\n");
    printf("| MATRÍCULA: 01255443 | 6º PERÍODO | MANHÃ  |\n");
    printf("---------------------------------------------\n");

    printf("---------------------------------------------\n");
    printf("|              MÁQUINA DE TURING            |\n");
    printf("---------------------------------------------\n");

    outronum: //retorno para inserir novo numro
    // entrada de dados
    p,q,tamanhoVetor=0;
    printf("Digite o valor de P: ");
    scanf("%d", &p);
    if(p<0){printf("Opção inválida \n");goto outronum;}
    printf("Digite o valor de Q: ");
    scanf("%d", &q);
    if(q<0){printf("Opção inválida \n");goto outronum;}

    tamanhoVetor=(p*q)+11+((q*p)/2);
    vet = (int *) malloc (tamanhoVetor * sizeof (int));
   free(vet);

    // PREENCHER DADOS
    outraop: // retorno para trocar de operação
    for(c=0;c<tamanhoVetor;c++){
        vet[c]=0;
        }
    for(c=5;c<p+5;c++){
        vet[c]=1;
        }
    for(c=6+p; c<6+p+q ;c++){
        vet[c]=1;
        }
    printf("\n");
    // selecionar a função da maquina
    erro: // ERRO DO SWITCH
    printf("----------------------------------------------------\n");
    printf("| Digite 1 para executar a função de SOMA          |\n");
    printf("| Digite 2 para executar a função de MULTIPLICAÇÃO |\n");
    printf("----------------------------------------------------\n");
    s=getch();
    //goto teste;
    cabecaDeLeitura=4;
    switch(s){

        case 49: // CASO DE SOMA
            printf("\nSOMA\n");
            //q0 - q0
            qEtapa=0;
            while(vet[cabecaDeLeitura]==0){
                zerodireita();//escreve 0 anda a direita
            }//q0 - q1
            umdireita();//escreve 1 anda a direita
            //q1 - q1
            qEtapa=1;
            while(vet[cabecaDeLeitura]==1){
                umdireita();//escreve 1 anda a direita
            }//q1 - q2
            umdireita();//escreve 1 anda a direita
            //q2 - q2
            qEtapa=2;
            while(vet[cabecaDeLeitura]==1){
                umdireita();//escreve 1 anda a direita
            }//q2 - q3
            zeroesquerda();//escreve 0 anda a esquerda
            //q3 - q3
            qEtapa=3;
            while(vet[cabecaDeLeitura==0]){
                zeroesquerda();//escreve 0 anda a esquerda
            }//q3 - q4
            zeroesquerda();//escreve 0 anda a esquerda
            //q4 - q4
            qEtapa=4;
            while(vet[cabecaDeLeitura]==1){
                umesquerda();//escreve 1 anda a esquerda
            }
            //q4 - parada
            vet[cabecaDeLeitura]=0; //escreve 0
            EXIBE(qEtapa);
            goto final;//para a execução
                 break;
        case 50: // CASO DE MULTIPLICAÇÃO
            printf("\nMULTIPLICAÇÃO\n");
            q0:
            // Q0 -> Q2
            qEtapa=0;
            if(vet[cabecaDeLeitura]==1){
                zerodireita();//escreve 0 anda a direita
                goto q2;
            }else{
            // q0 -> q1
            zerodireita();//escreve 0 anda a direita
            goto q1;
            }
            //q2 - q2
            q2:
                qEtapa=2;
                while(vet[cabecaDeLeitura]==1){
                    umdireita();}//escreve 1 anda a direita
            // q2 -> q3
                zerodireita();//escreve 0 anda a direita
            // q3 -> q4
            q3:
                qEtapa=3;
                if(vet[cabecaDeLeitura]==1){
                    zerodireita();//escreve 0 anda a direita
                }else{
            // q3 -> q15
                    zeroesquerda();//escreve 0 anda a esquerda
                     goto q15;
                }
            // q4 - q4
            qEtapa=4;
            while(vet[cabecaDeLeitura]==1){
                umdireita();//escreve 1 anda a direita
            }
            // q4 ->5
            zerodireita();//escreve 0 anda a direita
            // q5 - q5
            qEtapa=5;
            while(vet[cabecaDeLeitura]==1){
                umdireita();//escreve 1 anda a direita
            }
            //q5 -> q6
                umesquerda();//escreve 1 anda a esquerda
            //q6 - q6
            qEtapa=6;
            while(vet[cabecaDeLeitura]==1){
            umesquerda();//escreve 1 anda a esquerda
                }
            //q6 -> q7
            zeroesquerda();//escreve 0 anda a esquerda
            //q7 -> q8
            qEtapa=7;
            if(vet[cabecaDeLeitura]==1){
            umesquerda();//escreve 1 anda a esquerda
            }else{
            //q7 -> q9
            umesquerda();//escreve 1 anda a esquerda
                goto q9;
            }
            // q8 - q8
            qEtapa=8;
            while(vet[cabecaDeLeitura]==1){
                umesquerda();//escreve 1 anda a esquerda
            }
            //q8 -> q3
            umdireita();//escreve 1 anda a direita
            goto q3;
            //q9 - q9
            q9:
                qEtapa=9;
            while(vet[cabecaDeLeitura]==1){
                umesquerda();//escreve 1 anda a esquerda

            }
            //q9 -> q10
            zeroesquerda();//escreve 0 anda a esquerda
            //q10 -> q11
            qEtapa=10;
            if(vet[cabecaDeLeitura]==1){
                umesquerda();//escreve 1 anda a esquerda
            }else{
            //q10 -> q12
                zerodireita();//escreve 0 anda a direita
                goto q12;
            }
            //q11 - q11
            qEtapa=11;
            while(vet[cabecaDeLeitura]==1){
                umesquerda();//escreve 1 anda a esquerda
            }
            //q11 -> q0
            zerodireita();//escreve 0 anda a direita
            goto q0;
            //q12 - q12
            q12:
                qEtapa=12;
                while(vet[cabecaDeLeitura]==0){
                    zerodireita();//escreve 0 anda a direita
                }
            // q12 - q13
            zerodireita();//escreve 0 anda a direita
            //q13 - q13
            qEtapa=13;
            while(vet[cabecaDeLeitura]==1){
                zerodireita();//escreve 0 anda a direita
            }
            //q13 -> parada
            vet[cabecaDeLeitura]=0; //escreva 0
            EXIBE(qEtapa);
            goto final; // para execução do programa
            //q1 -> q2
            q1:
                qEtapa=1;
                if(vet[cabecaDeLeitura]==1){
                    zerodireita();//escreve 0 anda a direita
                    goto q2;
                }else{
                //q1 -> q14
                 zerodireita(); //escreve 0 anda a direita
                }
            //q14 - q14
            qEtapa=14;
            while(vet[cabecaDeLeitura]==1){
                zerodireita();//escreve 0 anda a direita
            }
            //q14 -> parada
            zerodireita();
            //q15 - q15
            q15:
                qEtapa=15;
                while(vet[cabecaDeLeitura]==1){
                    zeroesquerda();//escreve 0 anda a esquerda
                }
            //q15 -> q16
            zeroesquerda(); //escreve 0 anda a esquerda
            //q16 - q16
            qEtapa=16;
            while(vet[cabecaDeLeitura]==1){
                zeroesquerda(); //escreve 0 anda a esquerda
            }
            // q16 -> parada
            vet[cabecaDeLeitura]=0; //escreva 0
            EXIBE(qEtapa);
            goto final; // encerra
            break;
        //valor incorreto no switch
        default:
            printf("valor incorreto \n");
            goto erro;  // RETORNO SWITCH
        break;
}final:
contador =0;
for(c=0;c<tamanhoVetor;c++){
        if(vet[c]==1){
            contador++;}}
printf("---------------------------------------------------\n");
printf("| RESULTADO: O resultado da operação é igual a: %d |\n",contador);
printf("---------------------------------------------------\n\n");
s2: // retorno segundo switch
printf("-----------------------------------------\n");
printf("| Digite 1 para inserir novo número     |\n");
printf("| Digite 2 para realizar outra operação |\n");
printf("| Digite 3 para finalizar o programa    |\n");
printf("-----------------------------------------\n");
s1=getch();
switch(s1){
    case 49:
        goto outronum;
        system("cls");
        break;
    case 50:
        goto outraop;
        system("cls");
        break;
    case 51:
         printf("-------\n");
         printf("| FIM |\n");
         printf("-------\n");
         break;

          system("exit");

        break;
    default:
         printf("Opção inválida\n");
        goto s2;
    break;
}}
EXIBE(int etapa){
controleWhile= 0;
    while(controleWhile<tamanhoVetor){
  printf("%d", vet[controleWhile]);
 if(cabecaDeLeitura==controleWhile){
                    printf("(q%d)",etapa);
 }
      controleWhile++;
}printf("\n");}

zeroesquerda(){
    vet[cabecaDeLeitura]=0;//escreva 0
    EXIBE(qEtapa);
    cabecaDeLeitura --; // ande para esquerda
}
zerodireita(){
    vet[cabecaDeLeitura]=0; //escreva 0
    EXIBE(qEtapa);
    cabecaDeLeitura ++; // ande para direita
}
umesquerda(){
    vet[cabecaDeLeitura]=1; // escreva 1
    EXIBE(qEtapa);
    cabecaDeLeitura --; // ande para esquerda
}
umdireita(){
    vet[cabecaDeLeitura]=1; // escreva 1
    EXIBE(qEtapa);
    cabecaDeLeitura ++; // ande para esquerda
}

