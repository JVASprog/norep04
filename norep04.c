/* ************************************************************************ *
 *    Sorteio, V1.0                                                         *
 *    Este programa realiza um sorteio, tirando uma bola aleatoria de cada  *
 *    vez de dentro de uma caixa, sem reposição. O usuario pode escolher    *
 *    a quantidade de bolas que ficarao na caixa e o numero de vezes que    *
 *    deseja repetir o sorteio.                                             *
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

#define BOLAS (5)

int **casos, nt;
int *funcrand(int n);
void print_vect(int *vect, int len);
double *estatistica(int n);

int main(void)
{
    srand(time(NULL));
    int i, j;
    printf("\nO Sorteio sera realizado com apenas 5 bolas.\nPor favor, digite a quantidade de testes:\n");
    scanf("%d", &nt);
    casos = malloc(nt *sizeof(int*)); //alocando e zerando o vetor casos.
    
    for (i=0; i<nt; i++){
        casos[i] = funcrand(BOLAS);
        print_vect(casos[i], BOLAS);
    }

    printf("Estatistica da ordem dos numeros:\n");
    for (i=0; i<BOLAS; i++){
        double *stats = estatistica(i+1);
        printf("Bola %d =>\n", i+1);
        for (j=0; j<BOLAS; j++){
            printf("\t%da -> %.2f%%\n", j+1, stats[j]*100);
        }
        free(stats);
    }
    return 0;
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
        if (i%5==4){
            printf("\n");
        }
    }
    printf("\n");
}

double *estatistica(int b)
{
    int j, k;
    double *stats = malloc(BOLAS *sizeof(double));
    for (j=0; j<BOLAS; j++){
        stats[j] = 0;
        for (k=0; k<nt; k++){
            if (casos[k][j] == b){
                stats[j]++;
            }
        }
    }
    for (j=0; j<BOLAS; j++){
        stats[j] /= (double)nt;
    }
    return stats;
}

