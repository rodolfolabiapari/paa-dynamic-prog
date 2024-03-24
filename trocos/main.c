/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: pripyat
 *
 * Created on 11 de Julho de 2016, 22:23
 */

#include <stdio.h>
#include <stdlib.h>
const int moedas[6] = {1, 5, 10, 25, 50, 100};
int n_moedas = 3;
int T[600];

int troco_top_down(int t){
	int i = 0, maior = - 1, temp;
	
	if (t == 0)
		return 0;
	if (t < 0)
		return t;
	
	while (i < n_moedas){
		temp = troco_top_down(t - moedas[i]); 
		
		if (temp >= 0) {
			if (t - temp > maior)
				maior = moedas[i];
		}
		
		i++;
	}
	
	if (maior == -1)
		return 0;
	else {
		T[t] = maior;
		return maior;
	}
}


void troco_bottom_up(int t){
	int i = n_moedas - 1;
	
	while (t > 0){
		if (t - moedas[i] >= 0) {
			T[t] = moedas[i];
			t = t - moedas[i];
		} else 
			i--;
	}
	
	if (t == 0)
		return;
	else
		exit;
}

int main(int argc, char** argv) {
	int i;
	char top_down = 0;
	
	if (top_down)
		troco_top_down(16);
	else 
		troco_bottom_up(16);
	
	for (i = 0; i < 17; i++) 
		printf("%d -> ", T[i]);
	fflush(stdout);
	
	return (EXIT_SUCCESS);
}

