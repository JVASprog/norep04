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

int **vect, nt, nb;
int *funcrand(int n);
void print_vect(int *vect, int len);
int main(void)
{
    srand(time(NULL));
    int i;
    printf("Digite a quantidade de bolas que deseja sortear:\n");
    scanf("%d", &nb);
    printf("Digite a quantidade de testes(repeticoes) que deseja realizar:\n");
    scanf("%d", &nt);
    vect = malloc(nt*sizeof(int*));
    for (i=0; i<nb; i++){
        vect[i] = funcrand(nb);
    }
    void print_vect();
    return 0;
}

int *funcrand(int n)
{    
    int i, aux;
    int *vect = malloc(n*sizeof(int));
    for (i=0; i<n; i++){
        vect[i] = i+1;
    }
    for (i=0; i<n; i++){
        int r = rand()%n;
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
