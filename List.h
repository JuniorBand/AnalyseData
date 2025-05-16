#ifndef LIST_H
#define LIST_H


typedef struct element* List;

List* create_list(); //cria lista dinâmica
void free_list(List* li); //libera memória da lista do Heap
int insert_element_tail(List* li, double newElement); //insere novo elemento no fim da lista
int get_length(List* li); //return length
int is_empty(List* li); //return 1 for true and return 0 for false se a lista estiver vazia
void showList(List* li); //printa a lista
int remove_element(List* li, double element); //remove um elemento da lista 
double get_element_at(List* li, int index); //localizar um elemento da lista
int exists(List* li, double element); //retornar 1 se o elemento existir e 0 se não;

//List* grow_list(List* pastList, List* newList);
//int insert_list_ordered(List* li, double newElement);
//int saveLists(List * li1, List* li2, List* li3, List* li4);
//void saveListToFile(List* li, const char* filename, int resp);

#endif