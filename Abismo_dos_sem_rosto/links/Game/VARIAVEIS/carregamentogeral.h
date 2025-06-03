
/**
 *
 * @brief Controla o loop principal do mapa (renderização, combate, movimentos etc..)
 * 
 * @param lin Tamanho das linhas da matriz
 * @param mapa1 Matriz escolhida
 * @param p Posição inicial do player
 * @param po Posição da matriz no terminal
 * @param npclv1 Posição inicial do(s) mostro(s) lvl1
 * @param npclv2 Posição inicial do(s) mostro(s) lvl2
 * @param portapos Localizacao da porta
 * @param botao Localizacao do botao
 */
void Load_Map(int lin ,char *mapa1[],posicao p,posicao po,posicao npclv1,posicao chave,posicao portapos,posicao botao){

bool podecomecar;

Posicoes_iniciais(lin,mapa1,&po, &p, &npclv1,&chave,&portapos,&botao,&podecomecar);

//confirmacao para comecar jogo
if(podecomecar){
carregarmapa(lin,mapa1,po);//desenha o mapa
Load_NPCS(lin,mapa1,npclv1);
Load_Funcoes(&p,&chave,&po,&portapos,&botao,mapa1,lin,npclv1);
if(morto);

}else{
    tecla = 0;
    gotoxy(65,9);
    printf("X Ocorreu algum erro no seu codigo. X");
    gotoxy(52,11);
    printf("Possivel erro. A falta desse(s) elemento(s) no seu %d mapa", mapaA+1);
    gotoxy(52,12);
    printf("%s%s%s.", 
    (p.x == 0 ? " Player(&) ": ""),(chave.x == 0 ? " Chave(@) ": ""),(portapos.x == 0 ? " Porta(D) ": ""));
    gotoxy(50,14);
    printf("( Recomendacao: Adicione o elemento que falta na matriz do seu mapa )");
    continuar = false;
    getch();
    
gotoxy(0,30);

}
//confirmacao para comecar jogo

}

