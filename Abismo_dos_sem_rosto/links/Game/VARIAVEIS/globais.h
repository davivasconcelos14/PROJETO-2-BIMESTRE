#include <stdio.h>
#include <raylib.h>
#include <conio.h>
#include <stdlib.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include <locale.h>
#include "funcoes.h"
#include "Variaveis.h"




/*                    [EXEMPLO ANSI]
    printf("\033[31mAgora funciona texto vermelho!\033[0m\n");
    Cor vermelha: \033[31m
    reseta a cor: \033[0m


     
    [-CORES-]                [TEXTO]  | [FUNDO]
    Preto	                \033[30m  |	\033[40m
    Vermelho	            \033[31m  | \033[41m
    Verde	                \033[32m  |	\033[42m
    Amarelo	                \033[33m  |	\033[43m
    Azul	                \033[34m  |	\033[44m
    Magenta (Roxo)	        \033[35m  |	\033[45m
    Ciano (Azul Claro)	    \033[36m  |	\033[46m
    Branco (Cinza Claro)	\033[37m  |	\033[47m

    Mover cursor	\033[linha;colunaH
    Limpar tela	    \033[2J
    Resetar cor	    \033[0m    

    
*/
