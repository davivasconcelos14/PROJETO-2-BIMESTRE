// Imprime o mapa

void carregarmapa(int x,char *tela[],posicao go) {

    HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
    
    
    //Conta quantas colunas a linha tem
    for (int i = 0; i < x; i++) {
        int colunas = 0;
        while (tela[i][colunas] != '\0') colunas++;
    //Conta quantas colunas a linha tem
    
    for (int j = 0; j < colunas; j++) {
        gotoxy(go.x+j,go.y+i);

        if(tela[i][j] == '*' && mapaA != 0){SetConsoleTextAttribute(cor,112 | 7);}//parede
        else if((tela[i][j] == '.'  || tela[i][j] == ';') && mapaA != 0){SetConsoleTextAttribute(cor, 128 | 8);}//chao
        else if(tela[i][j] == '/' && mapaA != 0){SetConsoleTextAttribute(cor,3);}//
        else if(tela[i][j] == 'O' && mapaA != 0){SetConsoleTextAttribute(cor,1 | 128);}//botao
        else if(tela[i][j] == '#' && mapaA != 0){SetConsoleTextAttribute(cor, 128);}//espinhos

        else if(tela[i][j] == '.' && mapaA == 0){SetConsoleTextAttribute(cor,160 | 10);}//chao vila
        else if(tela[i][j] == '1'&& mapaA == 0){SetConsoleTextAttribute(cor,112 | 7);}//COR vila
        else if(tela[i][j] == '2'&& mapaA == 0){SetConsoleTextAttribute(cor,80 | 5);}//COR vila
        else if(tela[i][j] == '3'&& mapaA == 0){SetConsoleTextAttribute(cor,128 | 8);}//COR vila
        else if(tela[i][j] == '4'&& mapaA == 0){SetConsoleTextAttribute(cor,144 | 9);}//COR vila
        else if(tela[i][j] == '='&& mapaA == 0){SetConsoleTextAttribute(cor,128);}
        else if(tela[i][j] == ','&& mapaA == 0){SetConsoleTextAttribute(cor,32 | 2);}//trilha
        else if(tela[i][j] == 'P'&& mapaA == 0){SetConsoleTextAttribute(cor,160 | 1);}//npc
        




        else{SetConsoleTextAttribute(cor,7);} 

        printf("%c", tela[i][j]);
        
        
        

    }
    printf("\n");
    }
    

    
    
}

