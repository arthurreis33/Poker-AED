#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Card{
    int valueCard;
    int suitCard; // 0 para espadas, 1 para paus, 2 para copas, 3 para ouro.
    struct Card *next;
    struct Card *prev;
}Card;

void enqueue(Card **head, Card **tail, int cardValue, int cardSuit);
void initCards(Card **head, Card **tail);
int currentLengthCards(Card *head);
void deliverCards();
void insertionSort(Card *head); 
void displayCards(Card *head, int i);
void concatenateQueues(Card **head_01, Card **tail_01, Card **head_02, Card **tail_02); 
int compare();
void removeAtAnyPoint(Card **head, Card **tail, int i);

int main(){

    Card *headPlayer = NULL, *headCPU = NULL, *headDealer = NULL, *headCheap = NULL;
    Card *tailPlayer = NULL, *tailCPU = NULL, *tailDealer = NULL, *tailCheap = NULL;
    
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

        displayCards(headPlayer, 0);//cartas jogador
        //mesa 3 iniciais

        //perguntar ao jogador se ele vai entrar no jogo; custo = 5 fichas;
        //reduzir 5 fichas no montante do jogador e da cpu;
        
        for (int i = 0; i<3; i++){
            enqueue(&headDealer, &tailDealer, cardValue, cardSuit); 
        }

        displayCards(headDealer, 1); //cartas da mesa
        //completar depois o print
        //rodada de aposta
        //jogador deve apostar primeiro, CPU deve cobrir a aposta;
        //colocar condição no inicio do jogo, caso a cpu esteja quebrada, termina o jogo e dá exit;
        //mesa 2 finais

        for(int i = 0; i<2; i++){
            enqueue(&headDealer, &tailDealer, cardValue, cardSuit); 
        }
        //rodada de aposta final
        compare(); //compara os jogos
        
    }

    return 0;
}

void enqueue(Card **head, Card **tail, int cardValue, int cardSuit){
    /* enfileira as cartas na mão de cada jogador, mesa ou cpu;
    */
   Card *newcard = (Card*)malloc(sizeof(Card));

   if(newcard != NULL){

        newcard->suitCard = cardSuit;
        newcard->valueCard = cardValue;

        if(*head == NULL){
            newcard->prev = NULL;
            *head = newcard;
            *tail = newcard;
        }else{
            (*tail)->next = newcard;
            newcard->prev = *tail;
            *tail = newcard;
        }
   }
}

void initCards(Card **head, Card **tail){ //criação baralho 

    for(int i = 0; i < 4; i++){

        for(int j = 1; j < 14; j++){

            enqueue(&head, &tail, j, i);

        }
    }
}

int currentLengthCards(Card *head){

    Card *current = head;

    int length = 0;

    while(current != NULL){
        length++;
        current=current->next;
    }

    return length;
}

void deliverCards(Card **sourceHead, Card **sourceTail,  Card **destinationHead, Card **destinationTail, int i){
    // for de 1 a qtd de cartas a ser distribuida (i)

    // outro for pra escolher qual carta vai ser distribuida usando o rand, mas lembrar de percorrer até o retorno de currentLength

    // se estiver na ultima execução, enqueue a carta 

    for(int j = 0; j<i; j++){
        int currentLength = currentLengthCards(sourceHead);
        int cardNumber = rand() % currentLength;

        Card *current = *sourceHead;

        for(int a = 0; a <= cardNumber; a++){

            if(a == cardNumber){
                enqueue(&destinationHead, &destinationTail, current->valueCard, current->suitCard);
                removeAtAnyPoint(&destinationHead, &destinationTail, a);
            }

            current=current->next;

        }
    }
}

void insertionSort(Card *head) {
    
    if (head == NULL || head->next == NULL) {
        return; 
    }
    
    Card *sorted = NULL; 

    while (head != NULL) {
        Card *current = head;
        head = head->next;

        if (sorted == NULL || current->valueCard <= sorted->valueCard) {
            current->next = sorted;
            current->prev = NULL;
            if (sorted != NULL) {
                sorted->prev = current;
            }
            
            sorted = current;
                
        } else {
            Card *temp = sorted;
            while (temp->next != NULL && temp->next->valueCard < current->valueCard) {
                temp = temp->next;
            }
        
            current->next = temp->next;
        
            if (temp->next != NULL) {
                temp->next->prev = current;
            }
        
            temp->next = current;
            current->prev = temp;
        }
    }    
    head = sorted;
}



void displayCards(Card *head, int i){
    char flag[23];
    
    if(i==0){
        strcpy("Suas cartas são", flag);
    }
    else{
        strcpy("As cartas da mesa são", flag);
    } 
    
    printf("%s: ", flag); 
    
    while(head != NULL){
        if (head->suitCard = 0){ //naipe de espadas
            if(head->valueCard = 1){//Ás de Espadas
                printf("A|Espadas");
            }
            else if(head->valueCard = 11){//Valete de Espadas
                printf("J|Espadas");
            }
            else if(head->valueCard = 12){//Rainha de Espadas
                printf("Q|Espadas");
            }
            else if(head->valueCard = 13){//Rei de Espadas
                printf("K|Espadas");
            }
            else{// valor 2<=x<=10 de espadas
                printf("%d|Espadas", head->valueCard); 
            }
        }else if (head->suitCard = 1){ //naipe de paus
            if(head->valueCard = 1){//Ás de Paus
                printf("A|Paus");
            }
            else if(head->valueCard = 11){//Valete de Paus
                printf("J|Paus");
            }
            else if(head->valueCard = 12){//Rainha de Paus
                printf("Q|Paus");
            }
            else if(head->valueCard = 13){//Rei de Paus
                printf("K|Paus");
            }
            else{// valor 2<=x<=10 de Paus
                printf("%d|Paus", head->valueCard);
            }
        }else if (head->suitCard = 2){ //naipe de Copas
            if(head->valueCard = 1){//Ás de Copas
                printf("A|Copas");
            }
            else if(head->valueCard = 11){//Valete de Copas
                printf("J|Copas");
            }
            else if(head->valueCard = 12){//Rainha de Copas
                printf("Q|Copas");
            }
            else if(head->valueCard = 13){//Rei de Copas
                printf("K|Copas");  
            }
            else{// valor 2<=x<=10 de Copas
                printf("%d|Copas", head->valueCard);
            }
        }else if (head->suitCard = 3){ //naipe de Ouro
            if(head->valueCard = 1){//Ás de Ouro
                printf("A|Ouro");
            }
            else if(head->valueCard = 11){//Valete de Ouro
                printf("J|Ouro");
            }
            else if(head->valueCard = 12){//Rainha de Ouro
                printf("Q|Ouro");
            }
            else if(head->valueCard = 13){//Rei de Ouro
                printf("K|Ouro");
            }
            else{// valor 2<=x<=10 de Ouro
                printf("%d|Ouro", head->valueCard);
            }
        }
        head = head->next; 
    }
}

// função p concatenar a fila da mãos dos jogadores + fila das cartas da mesa
void concatenateQueues(Card **head_01, Card **tail_01, Card **head_02, Card **tail_02) {
    if (*tail_01 != NULL && *head_02 != NULL) {
        (*tail_01)->next = *head_02;
        if (*head_02 != NULL) {
            (*head_02)->prev = *tail_01;
        }
        *tail_01 = *tail_02;
        *head_02 = *head_01;
        *head_01 = NULL;
    }
}

void removeAtAnyPoint(Card **head, Card **tail, int i){

}

void removeAtAnyPoin(Card **head, Card **tail, Card *nodeToRemove) {
    if (*head == NULL || nodeToRemove == NULL) {
        // List is empty or node to remove is not provided
        return;
    }

    if (nodeToRemove->prev != NULL) {
        // Update the previous node's next pointer
        nodeToRemove->prev->next = nodeToRemove->next;
    } else {
        // Node to remove is the head, update the head
        *head = nodeToRemove->next;
    }

    if (nodeToRemove->next != NULL) {
        // Update the next node's previous pointer
        nodeToRemove->next->prev = nodeToRemove->prev;
    } else {
        // Node to remove is the tail, update the tail
        *tail = nodeToRemove->prev;
    }

    // Free the memory of the removed node
    free(nodeToRemove);
}


//função para comparar as cartas
int compare(){
    
    // regras para cada mão

    // royal straight flush - sequencia mais alta ou seja de 9 a Ás, de mesmo naipe 

    // straight flush - sequencia de mesmo naipe

    // four of a kind - 4 cartas de mesmo valor

    // full house - uma trinca e um par

    // flush - todas as cartas do mesmo naipe

    // straight - sequencia, de qualquer naipe 

    // trinca - 3 cartas de mesmo valor

    // dois pares - bem óbvio essa né, qualquer naipe

    // um par - bem obvio essa tb

    // carta mais alta - caso nenhum jogador possuir nenhuma combinação, ganha quem tiver a carta mais alta

    return -1; // so pra não dar erro

}