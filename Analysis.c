#include <stdio.h>
#include <stdlib.h>
#include "Analysis.h" //inclui os protótipos das funções de análise
#include "List.h" //inclui os protótipos da lista dinâmica
#include <math.h>
#define EPSILON 0.00001 //evita erros na comparação de doubles



double peak;
double low;
double plat;

//Analisa cada elemento da lista de dados a fim de mostrar os elementos percorridos, picos, mínimos e platôs.
void analyseData(List* data_strg, List* peak_strg, List* low_strg, List* plat_strg, int counter) {
    double init = get_element_at(data_strg, 0);
    
    if(counter == 0){
        printf("Primeiro Dado: %.3f\n", init);
    } else if (counter == 1){
        double sec = get_element_at(data_strg, 1);
        printf("Segundo Dado: %.3f\n", sec);
    } 
    else {
        double value = get_element_at(data_strg, counter);
        double ant_value = get_element_at(data_strg, counter - 1);
        double ant2_value = get_element_at(data_strg, counter - 2);

        //Função Constante
        if(value == ant_value){
            printf("Mesmo elemento anterior (Platô): %.3f.\n", value);
            newPlat(ant_value, plat_strg);
            if (!is_empty(peak_strg)) //Se um pico já existir, printar
                printf("Último pico local: %.3f. \n", peak);
        }
        
        //Função Crescente
        else if (value > (ant_value + EPSILON) && (ant_value > (ant2_value + EPSILON) || ant_value == (ant2_value))){
            printf("A função está crescente!\nNovo elemento: %.3f.\n", value);
            if (!is_empty(peak_strg)) //Se um pico já existir, printar
                printf("Último pico local: %.3f. \n", peak);
        }

        //Função Decrescente
        else if ((value < (ant_value + EPSILON) && (ant_value < (ant2_value + EPSILON)) || ant_value == (ant2_value))){
            printf("Ação Crítica!!! A função está decrescente. \nNovo elemento: %.3f. \n", value);
            if (!is_empty(peak_strg)) //Se um pico já existir, printar
                printf("Pico local: %.3f \n", peak);
            //Ação crítica é disparada sempre que o código encontra valores menores após um pico
        }

        //Novo Pico Local
        else if(value < (ant_value + EPSILON) && ant_value > (ant2_value + EPSILON)){ 
            printf("Novo elemento: %.3f. \n", value);
            newPeak(ant_value, peak_strg);
        }

        //Mínimo Local
        else if(value > (ant_value + EPSILON) && ant_value < (ant2_value + EPSILON)){
            printf("Mínimo local (ponto de inversão)!\nNovo elemento: %.3f. \n", value);
            newLow(ant_value, low_strg);
            if (!is_empty(peak_strg)) //Se um pico já existir, printar
                printf("Último pico local: %.3f. \n", peak);
        }
    }
}

//Cria novo elemento na lista de picos
void newPeak(double newPeakValue, List* peak_strg) {
    peak = newPeakValue;
    insert_element_tail(peak_strg, peak);
    printf("Novo pico local (ponto de inversão): %.3f \n", peak);
}

//Mostra os picos
void showPeaks(List* peak_strg){
    printf("Os picos: ");
    showList(peak_strg);
}

//Cria novo elemento na lista de mínimos
void newLow(double newLowValue, List* low_strg){
    low = newLowValue;
    insert_element_tail(low_strg, low);
    printf("Mínimo local: %.3f .\n", newLowValue);
}

//Mostra os mínimos
void showLows(List* low_strg){
    printf("Os mínimos: ");
    showList(low_strg);
}

//Cria novo elemento na lista de platôs 
void newPlat(double newPlatValue, List* plat_strg){
    plat = newPlatValue;
    insert_element_tail(plat_strg, plat);
}

//Mostra os platôs
void showPlats(List* plat_strg){
    printf("Os platôs: ");
    showList(plat_strg);
}

//Mostra os dados da lista digitada
void showData(List* data_strg){
    printf("Os seus dados: ");
    showList(data_strg);
}


