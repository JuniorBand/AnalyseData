#include <stdio.h>
#include "Analysis.h"
#include "List.h"

void iniateLoop(){
	double value;
	int term = 1;

	List* data_strg = create_list();
	List* peak_strg = create_list();
	List* low_strg = create_list();
	List* plat_strg = create_list();
	int counter;

	//Se tiver definido quantos dados quer inserir, use isso:
	// int count
	// printf("Deseja inserir quantos números: ");
	// scanf("%lf", &count);
	// getchar();
	//e faça: while(counter <= count)

	//Se não souber quantos dados quer inserir
	while(1){
		printf("Digite um novo dado numérico: ");
		scanf("%lf", &value);
		getchar();//limpar o buffer
		//Inserir novo dado na lista
		insert_element_tail(data_strg, value);
		
		//Analisar dados
		analyseData(data_strg, peak_strg, low_strg, plat_strg, counter);

		counter++; //conta a quantidade de dados

		if(counter >= 10){ //Ajusta quando pode sair do loop
			printf("\nDeseja continuar: Sim (Qualquer tecla) ou Não (0)? ");
			scanf("%d", &term);
			getchar();//limpar o buffer
			printf("\n");
			if (term == 0) break;
		}
	}

	//Mostrar listas e liberar memória no Heap
	showData(data_strg);
	showPeaks(peak_strg);
	showLows(low_strg);
	showPlats(plat_strg);
	free_list(data_strg);
	free_list(peak_strg);
	free_list(low_strg);
	free_list(plat_strg);

	int resp1;
	printf("\nDeseja analisar novos dados (1) ou interromper (Qualquer tecla)? ");
	scanf("%d", &resp1);
	getchar();//limpar o buffer
	printf("\n");

	if (resp1 == 1)
		iniateLoop(); //reinicia a análise de dados
}

int main () {

	iniateLoop(); //inicia a análise de dados

	return 0;

}


