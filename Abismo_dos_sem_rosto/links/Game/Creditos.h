

void creditos(int posx, int posy){

    char creditos[][100] = {

    " ___________________________________ ",
    "|            <-- JOGO -->           |",
    "|    D U N G E O N  C R A W L E R   |",
    "|                                   |",
    "|                                   |",
    "|              CREDITOS             |",
    "|                                   |",
    "|           JOGO FEITO POR:         |",
    "|                                   |",
    "|           Arthur Miguel           |",
    "|            Davi Duarte            |",
    "|            Lucas Banna            |",
    "|___________________________________|",
   

    };

    int tamanho = sizeof(creditos) / sizeof(creditos[0]);

    for(int i = 0; i < tamanho; i++){
    gotoxy(45+posx,i+0+posy);
    printf("%s\n", creditos[i]);
    }

    gotoxy(42+posx,15+posy);
    printf("Clique qualquer tecla para voltar para o menu");
    getch();
    system("cls");


}