/* ************************************************************************ *
 *    NoRep, v2.0                                                           *
 *    Este programa realiza 'n' sorteios com 'k' bolas ditas pelo usuario   *
 *    e imprime a tabelacao dos sorteios, as estatisticas e a quantidade de *
 *    vezes que o padrao se repete.                                         *
 *                                                                          *
 *    Copyright (C) 2017 by Jose Vogeley Alves de Sa                        *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Jose Vogeley Alves de Sa <josevogeleysa2016@gmail.com>                *
 *    Webpage: ----------------------                                       *
 *    Phone: +55 (81) 99780-8888                                            *
 * ************************************************************************ *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **casos, nt, nb;
int *funcrand(int n);
void print_vect(int *vect, int len);
double *estatistica(int n);
int repeticao(int ordem, int reps);

int main(void)
{
    srand(time(NULL));
    int i, j, k;
    printf("\nPor favor, digite a quantidade de bolas que desejas sortear:\n");
    scanf("%d", &nb);
    printf("Por favor, digite a quantidade de testes que deseja realizar:\n");
    scanf("%d", &nt);
    casos = malloc(nt *sizeof(int*));
    for (i=0; i<nt; i++){
        casos[i] = funcrand(nb);
        print_vect(casos[i], nb);
    }

    printf("Estatistica da ordem dos numeros:\n");
    for (i=0; i<nb; i++){
        double *stats = estatistica(i+1);
        printf("Bola %d =>\n", i+1);
        for (j=0; j<nb; j++){
            printf("\t%da -> %.2f%%\n", j+1, stats[j]*100);
        }
        free(stats);
    }

    printf("Por favor, informe a ordem da bola que se repete:\n");
    scanf("%d", &k);
    printf("Por favor, informe a quantidade de repeticoes:\n");
    scanf("%d", &j);
    printf("Esse padrao se repete %d vezes.\n", repeticao(k, j));
    
    return EXIT_SUCCESS;
}

int *funcrand(int n)
{
    int i, aux, r;
    int *vect = malloc(n*sizeof(int));
    for (i=0; i<n; i++){
        vect[i] = i+1;
    }
    for (i=0; i<n; i++){
        r = rand()%n;

        aux = vect[r];
        vect[r] = vect[i];
        vect[i] = aux;
    }
    return vect;
}

void print_vect(int *vect, int len)
{
    int i;
    for (i=0; i<len; i++){
        printf("%d\t", vect[i]);
        if (i%5==nb){
            printf("\n");
        }
    }
    printf("\n");
}

double *estatistica(int b)
{
    int j, k;
    double *stats = malloc(nb*sizeof(double));
    for (j=0; j<nb; j++){
        stats[j] = 0;
        for (k=0; k<nt; k++){
            if (casos[k][j] == b){
                stats[j]++;
            }
        }
    }
    for (j=0; j<nb; j++){
        stats[j] /= (double)nt;
    }
    return stats;
}

int repeticao(int ordem, int reps)
{
    if (ordem > nb || ordem <= 0){
        return 0;
    }
    int i, r=0, t=0;
    for (i=1; i<nt; i++){
        if (casos[i][ordem-1] == casos[i-1][ordem-1]){
            r++;
        }
        else{
            r = 0;
        }
        if (r >= reps){
            t++;
        }
    }
    return t;
}
