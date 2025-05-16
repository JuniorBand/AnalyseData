#include "List.h"


//Analisa os dados
void analyseData(List* data_strg, List* peak_strg, List* low_strg, List* plat_strg, int counter); 
void showData(List* data_strg); //Mostra elementos da lista de dados
void newPeak(double newPeakValue, List* peak_strg); //Adiciona novo pico
void showPeaks(List* peak_strg); //Mostra elementos da lista de picos
void newLow(double newLowValue, List* low_strg); //Adiciona novo mínimo
void showLows(List* low_strg); //Mostra elementos da lista de mínimos
void newPlat(double newPlatValue, List* peak_strg); //Adiciona novo platô
void showPlats(List* plats_strg); //Mostra elementos da lista de platôs

