#include <stdio.h>
#include <stdbool.h>


typedef struct Data {
	int dia;
	int mes;
	int ano;
} data;


bool validar(int dia, int mes, int ano, Data *data);
bool validar_string(char * str, Data *data);
bool contar_dias(Data data, int dias);
bool escreve(Data data);
Data calcula_pascoa(int ano);
void imprime_data(Data data);
