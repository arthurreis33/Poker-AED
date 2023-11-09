#include <stdio.h>
#include <stdlib.h>

typedef struct Card{
    int valueCard;
    int suitCard;
    struct Card *next;
    struct Card *prev;
}Card;


// vão ser precisar 3 filas: uma na mesa, uma na mão do jogador e uma do "computador"
void enqueue(Card **head, Card **tail, int cardValue, int cardSuit){
    /* enfileira as cartas na mão de cada jogador, mesa ou cpu;
    */
}

/// é util que a gente crie uma função de ordenação, para caso o jogador fizer uma sequencia
void bubbleSort(){

}

// função p concatenar a fila da mãos dos jogadores + fila das cartas da mesa
void concatenateQueues(void){

}

//função para comparar as cartas
void compare(){

}

int main(){
    Card *headPlayer = NULL, *headCPU = NULL, *headDealer = NULL;
    Card *tailPlayer = NULL, *tailCPU = NULL, *tailDealer = NULL;
    int cardValue, cardSuit;
    int fichasPlayer = 100;
    int fichasCPU = 100; 
    while(1){
        printf("Bem Vindo ao Poker");
        //selecionando cartas jogadores
        for (int i = 0; i<2; i++){
            //usar rand pra gerar numeros aleatórios
            enqueue(&headPlayer, &tailPlayer, cardValue, cardSuit);
        }
        for (int i = 0; i<2; i++){
            //usar rand pra gerar numeros aleatórios
            enqueue(&headCPU  , &tailCPU, cardValue, cardSuit);
        }
        printf("Suas Cartas: valor %d naipe %d | valor %d naipe %d", headPlayer->valueCard, headPlayer->suitCard, tailPlayer->valueCard, tailPlayer->suitCard);
        //mesa 3 iniciais

        //perguntar ao jogador se ele vai entrar no jogo; custo = 5 fichas;
        //reduzir 5 fichas no montante do jogador e da cpu;
        
        
        for (int i = 0; i<3; i++){
            enqueue(&headDealer, &tailDealer, cardValue, cardSuit); 
        }
        print("Cartas na mesa: ");//completar depois o print

        //rodada de aposta
        //jogador deve apostar primeiro, CPU deve cobrir a aposta;
        //colocar condição no inicio do jogo, caso a cpu esteja quebrada, termina o jogo e dá exit;

        //mesa 2 finais
        for (int i = 0; i<2; i++){

        }

        //rodada de aposta final
        
        compare(); //compara os jogos
        
    }
    return 0;
}

