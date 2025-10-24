#include <stdio.h>
#include <stdlib.h>
#include "List.h" //inclui os protótipos da lista dinâmica

typedef struct element Elem;

struct element { //Cria um nó
    double data;
    struct element *prox;
};

//OR for shortness:
// typedef struct { //Cria um nó
//     double data;
//     struct element *prox;
// } Elem;


List* create_list(){ //cria o primeiro ponteiro pro primeiro nó = NULL
    List* li = (List*) malloc(sizeof(List));
    if (li != NULL){
        *li = NULL;
    }
    return li;
}

//insert an element at the end of your list
int insert_element_tail(List* li, double newElement){
    if (li == NULL){
        return 0; //lista não criada
    }
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if (no == NULL){
       return 0; //erro na criação do nó
    } 
    no->data = newElement;
    no->prox = NULL;
    if((*li) == NULL){
        *li = no; //se o primeiro elemento não existe, ele é criado
    } else {
        Elem *aux = *li; 
        while(aux->prox != NULL) {
            aux = aux->prox; //percorre até o fim da lista
        }
        aux->prox = no; //o novo nó é apontado pelo último nó
    }
    return 1; //all right
}


int get_length(List* li){
    if(li == NULL){ //there is no list
        return 0;
    }
    int count = 0; 
    Elem* no = *li;
    while(no != NULL){
        count++;
        no = no->prox; //até o último
    }
    return count;
}

//is the list empty?
int is_empty(List* li){
    if(li == NULL){
        return 1; //true
    }
    if(*li == NULL){
        return 1; //true
    }
    return 0; //false
}

//free the memory of your list
void free_list(List* li){
    if (li != NULL){ //lista foi criada
        Elem* no = NULL;
        while ((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no); //libera cada elemento no Heap
        }
        free(li); //libera o ponteiro no Heap
    }

}    

double get_element_at(List* li, int index){
    if (li == NULL || index < 0 || index >= get_length(li)) return 0;

    Elem* atual = *li;
    int i = 0;
    while (atual != NULL && i < index) {
        atual = atual->prox;
        i++;
    }
    if (atual == NULL) return -1; //fora do tamanho do array
    
    return atual->data;// retorna valor do elemento desejado
}

//show the array
void showList(List* li) {
    if (li == NULL || *li == NULL) { //Lista Vazia
        printf("Lista vazia\n"); 
        return;
    }
    Elem* atual = *li;
    while (atual != NULL) { //print de cada elemento
        printf("%.3f -> ", atual->data);
        atual = atual->prox;
    }
    printf("FIM!\n");
}

//O elemento existe?
int exists(List* li, double element) {
    if (li == NULL || *li == NULL) return 0; // lista vazia ou não existente

    Elem* atual = *li;
    while (atual != NULL) {
        if (atual->data == element) {
            return 1; // já existe
        }
        atual = atual->prox;
    }

    return 0; // não existe
}

// //insert an element in the right order of an ordered list
// int insert_list_ordered(List* li, double newElement){
//     if (li == NULL){
//         return 0;
//     }
//     Elem *no;
//     no = (Elem*) malloc(sizeof(Elem));
//     if(no == NULL){
//         return 0;
//     }
//     no->data = newElement;
//     if((*li) == NULL){ //lista vazia, insere no início
//         no->prox = NULL;
//         *li = no;
//         return 1; //right
//     } else { //lista que já contenha elementos
//         Elem *ant, *atual = *li;
//         while (atual != NULL &&  atual->data < newElement){
//             ant = atual;
//             atual = atual->prox;
//         }
//         if(atual == *li){ //insere no início
//             no -> prox = (*li);
//             *li = no;
//         }else {
//             no->prox = atual;
//             ant->prox = no;
//         }
//         return 1;//no transforma-se no último da lista
//     }
// }

// int saveLists(List * li1, List* li2, List* li3, List* li4){
//     int resp;
// 	printf("Deseja sobrescrever os arquivos existentes (1), acumular os dados (2) ou descartar (Qualquer tecla)? ");
// 	scanf("%d", &resp);
// 	saveListToFile(li1, "dados.txt", resp);
// 	saveListToFile(li2, "picos.txt", resp);
// 	saveListToFile(li3, "minimos.txt", resp);
// 	saveListToFile(li4, "platos.txt", resp);

// 	int resp1;
// 	printf("Deseja analisar novos dados (1) ou interromper (Qualquer tecla)? ");
// 	scanf("%d", &resp1);
//     return resp1;
// }

// void saveListToFile(List* li, const char* filename, int resp) {
//     if (resp != 1 || resp != 2){
// 		return;
// 	}

// 	if (li == NULL || *li == NULL) {
//         printf("Lista vazia, nada a salvar em %s\n", filename);
//         return;
//     }

// 	FILE* file; 

// 	if (resp == 1){
// 		file = fopen(filename, "a");
// 	} else {
// 		file = fopen(filename, "w");
// 	}
	
//     if (file == NULL) {
//         perror("Erro ao abrir arquivo");
//         return;
//     }

//     Elem* atual = *li;
//     while (atual != NULL) {
//         fprintf(file, "%.3f\n", atual->data);
//         atual = atual->prox;
//     }

//     fclose(file);
//     printf("Lista salva em '%s'\n", filename);
// }

