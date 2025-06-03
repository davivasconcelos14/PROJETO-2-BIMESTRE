void tabelaPlayer(posicao playerstatus){
    HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
    //tabela player

    char stats[15][30] = {
    " _________________",
    "|                 |", 
    "|                 |", 
    "|                 |", 
    "|                 |", 
    "|                 |", 
    "|                 |", 
    "|                 |", 
    "|                 |",
    "|                 |",
    "|                 |",
    "|                 |",
    "|                 |",
    "|                 |",
    "|_________________|", 
    
    };

    for(int i = 0; i < 15;i++){
    gotoxy(playerstatus.x-3,playerstatus.y+i-2);
    printf("%s",stats[i]);  
    }

    
    gotoxy(playerstatus.x,playerstatus.y);
    if(cornome == 1){SetConsoleTextAttribute(cor,5);}
    else if(cornome == 2){SetConsoleTextAttribute(cor,1);}
    else if(cornome == 3){SetConsoleTextAttribute(cor,4);}
    else{SetConsoleTextAttribute(cor,14);}
    printf("   PLAYER");
    SetConsoleTextAttribute(cor,7);
    gotoxy(playerstatus.x,playerstatus.y+2);
    printf(" HP: %2d/%d ", playerS.status.vida,playerS.status.vidamax);
    gotoxy(playerstatus.x,playerstatus.y+3);
    printf(" DMG: %d ~ %d ", playerS.status.danomin,playerS.status.danomax);
    if(espada.equip){
    gotoxy(playerstatus.x-2,playerstatus.y+5);
    }else{
    gotoxy(playerstatus.x,playerstatus.y+5);
    }

    if(mao){
    printf("MAO:%5s",item[itemMao].nome);
    if(espada.equip){printf("(%d/%d)",espada.durabilidade,espada.durMax);}
    gotoxy(playerstatus.x,playerstatus.y+6);
    printf(" Deseq. [F] ");
    }else{
    gotoxy(playerstatus.x,playerstatus.y+5);
    printf("MAO: vazia ");
    }

    gotoxy(playerstatus.x-1,playerstatus.y+8);
    printf("Inventario [I] ");

    gotoxy(playerstatus.x,playerstatus.y+11);
    if(cornome == 1){SetConsoleTextAttribute(cor,5);printf("   MAGO");}
    else if(cornome == 2){SetConsoleTextAttribute(cor,1);printf(" PALADINO");}
    else if(cornome == 3){SetConsoleTextAttribute(cor,4);printf(" INQUISIDOR");}
    else{SetConsoleTextAttribute(cor,2);printf(" CAMPONES");}
    SetConsoleTextAttribute(cor,7);
    gotoxy(playerstatus.x,playerstatus.y+10);
    printf("  CLASSE:");
    //tabela player

}

void Equipado(utili *item, int *maoEquip){

    if(tecla == item->slot){
    *maoEquip = item->slot-49;
    item->equip = true;

    }else if(!mao){
    item->equip = false;
    *maoEquip = 99;
    }

    
}

void adicionaritem(itens item[],utili *itemAdd){
    
    for(int i = 0;i < 6;i++){
    
    if(itemAdd->quant <= 0){
    item[itemAdd->slot-49].existe = false;
    itemAdd->slot = 99;
    itemAdd->equip = false;
    break;
    }else if(!item[i].existe && itemAdd->slot == 99){
    strcpy(item[i].nome,itemAdd->nome);
    item[i].quant = itemAdd->quant;
    item[i].existe = true;
    itemAdd->slot = i+49;
    break;
    }else if((tecla >= '1' && tecla <= '6') || tecla == 'e'){
    item[itemAdd->slot-49].quant = itemAdd->quant;
    break;
    }
    }


}

void gramaDesenho(posicao grama){
HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(cor,32);
    gotoxy(grama.x,grama.y);printf("%c", 177);
    gotoxy(grama.x,grama.y+1);printf("%c", 176);
    gotoxy(grama.x+1,grama.y);printf("%c", 176);
    gotoxy(grama.x+1,grama.y+1);printf("%c", 177);
    gotoxy(grama.x+2,grama.y+1);printf("%c", 177);
    
    

    //GRAMA FRENTE CASA
    gotoxy(grama.x-8,grama.y-9);
    printf("%c", 176);
    gotoxy(grama.x-8,grama.y-8);
    printf("%c", 177);
    gotoxy(grama.x-7,grama.y-8);
    printf("%c", 176);
    gotoxy(grama.x-8,grama.y-12);
    printf("%c", 176);
    gotoxy(grama.x-8,grama.y-11);
    printf("%c", 177);
    gotoxy(grama.x-7,grama.y-12);
    printf("%c", 177);
    for(int i = 38; i <= 41;i++){
    gotoxy(grama.x+i,grama.y-1);
    printf("%c", rand() % 2 + 176);
    }
    for(int i = 40; i <= 41;i++){
    gotoxy(grama.x+i,grama.y-2);
    printf("%c", rand() % 2 + 176);
    }
    gotoxy(grama.x+41,grama.y-3);
    printf("%c", rand() % 2 + 176);

    for(int i = -8; i <= -5;i++){
    SetConsoleTextAttribute(cor,160);
    gotoxy(grama.x+i,grama.y+5);
    printf("%c", 197);
    }
    SetConsoleTextAttribute(cor,160);
    gotoxy(grama.x+-5,grama.y+6);
    printf("%c", 180);

    SetConsoleTextAttribute(cor,160);
    gotoxy(grama.x+-5,grama.y+8);
    printf("%c", 180);

    for(int i = -14; i <= -5;i++){
    SetConsoleTextAttribute(cor,160);
    gotoxy(grama.x+i,grama.y+9);
    printf("%c", 197);
    }

    //GRAMA FRENTE CASA
    
}

void inventario(itens* item, posicao inv){

    char inventario[9][100] = {
    " ____________________________________",
    "|             INVENTARIO             |", 
    "|           |           |            |", 
    "|           |           |            |", 
    "|           |           |            |", 
    "|           |           |            |", 
    "|           |           |            |", 
    "|           |           |            |", 
    "|____________________________________|", 
    
    };

    for(int i = 0; i < 9;i++){
    gotoxy(inv.x,inv.y+i);
    printf("%s",inventario[i]);    
    }

    int vx = 1,vy = 3;
    for(int i = 0;i < 6;i++){
    if(item[i].existe){
    gotoxy(inv.x+vx,inv.y+vy);
    printf("%d-%1dx %6s",i+1,item[i].quant,item[i].nome);
    vx+=12;
    }

    if(vx > 26){
    vx=2;
    vy+=3;
    }
    if(vy > 6){
    vy = 3;
    }

    
    }


}

void tabelaClasses(){
HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);

    while(!classeEscolhida){
    char *mago[] = {

        "     C L A S S E S     ",
        "                       ",
        "        M A G O        ",
        "                       ",
        " VIDA: 40 A 75         ",
        "                       ",
        " DANO: 25              ",
        "                       ",
    };

    char *paladino[] = {
        
        "                       ",
        "    P A L A D I N O    ",
        "                       ",
        " VIDA: 40 A 150        ",
        "                       ",
        " DANO: 15              ",
        "                       ",
    };

    char *inquisidor[] = {

        "                       ",
        "  I N Q U I S I D O R  ",
        "                       ",
        " VIDA: 40 A 100        ",
        "                       ",
        " DANO: 10              ",
        "                       ",
    };

    static int op = 1; 
   

    for(int i = 0; i < 8;i++){//MAGO
   
    for(int j = 0; j < 23;j++){
    gotoxy(115+j,10+i);

    if(i > 2 ){

    if(op == 1){
    SetConsoleTextAttribute(cor, 112);
    }else{
    SetConsoleTextAttribute(cor, 128);
    }

    printf("%c", mago[i][j]);
    SetConsoleTextAttribute(cor, 7);
    }
    else if(i == 2){

    if(op == 1){    
    SetConsoleTextAttribute(cor, 80 | 15);
    }else{
    SetConsoleTextAttribute(cor, 208 | 15);
    }

    
    printf("%c", mago[i][j]);
    SetConsoleTextAttribute(cor, 7);
    }else{
    printf("%c", mago[i][j]);
    }

    }
    }


    for(int i = 0; i < 7;i++){//PALADINO
    for(int j = 0; j < 23;j++){
    gotoxy(115+j,18+i);
    if(i > 1){

    if(op == 2){
    SetConsoleTextAttribute(cor, 112);
    }else{
    SetConsoleTextAttribute(cor, 128);
    }

    printf("%c", paladino[i][j]);
    SetConsoleTextAttribute(cor, 7);
    }else if(i== 1){

    if(op == 2){    
    SetConsoleTextAttribute(cor, 16 | 15);
    }else{
    SetConsoleTextAttribute(cor, 144 | 15);
    }    
    
    printf("%c", paladino[i][j]);
    SetConsoleTextAttribute(cor, 7);
    }else{
    printf("%c", paladino[i][j]);
    }
    
    }
    }


    for(int i = 0; i < 7;i++){//INQUISIDOR
    for(int j = 0; j < 23;j++){
    gotoxy(115+j,25+i);
    if(i > 1){

    if(op == 3){
    SetConsoleTextAttribute(cor, 112);
    }else{
    SetConsoleTextAttribute(cor, 128);
    }

    printf("%c", inquisidor[i][j]);
    SetConsoleTextAttribute(cor, 7);
    }else if(i == 1){

    if(op == 3){    
    SetConsoleTextAttribute(cor, 64 | 15);
    }else{
    SetConsoleTextAttribute(cor, 192 | 15);
    }

    
    printf("%c", inquisidor[i][j]);
    SetConsoleTextAttribute(cor, 7);
    }else{
    printf("%c", inquisidor[i][j]);
    }
    
    }
    }





    tecla = getch();


    if(tecla == 'w' && op > 1)op--;
    if(tecla == 's' && op < 3)op++;
    

    if(tecla == 13){

    if(op == 1){
    class1 = true;
    }

    if(op == 2){
    class2 = true;
    }

    if(op == 3){
    class3 = true;
    }

    classeEscolhida = true;
    for(int i = 0; i < 22;i++){
    gotoxy(115,10+i);
    printf("                       ");
    }
    break;
    }

    }

    


}

void arvore(int arvoreX, int arvoreY){
HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);

SetConsoleTextAttribute(cor,32);
//arvore
    gotoxy(arvoreX+2,arvoreY-1);

    printf("%c", 176);
    gotoxy(arvoreX+1,arvoreY-1);printf("%c", 176);
    gotoxy(arvoreX,arvoreY-1);printf("%c", 176);
    gotoxy(arvoreX+1,arvoreY-2);printf("%c", 176);

    SetConsoleTextAttribute(cor,14);
    gotoxy(arvoreX+1,arvoreY);printf("%c", 219);
    SetConsoleTextAttribute(cor,7);
    //arvore
}

void texto(char *texto[],int frases, int delay,int x,int y){
HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);

    int linhass = 0;
    int delayA = delay;
    char blocotxt[6][100] = {     

    "|                                                                 |", 
    "|                                                                 |", 
    "|                                                                 |", 
    "|                                                                 |", 
    "|                                                                 |", 
    "|                                                                 |", 
    
    };



    for(int i = 0; i < 6;i++){
    for(int j = 0; j < 100;j++){
    gotoxy(j+x,i+y);
    if(blocotxt[i][j] == '|'){
    SetConsoleTextAttribute(cor,112 | 7); 
    printf("%c",blocotxt[i][j]);
    }else{
    SetConsoleTextAttribute(cor,7); 
    printf("%c",blocotxt[i][j]);
    }
    SetConsoleTextAttribute(cor,7); 

    }
    }

    
    SetConsoleTextAttribute(cor, 15);
    gotoxy(x+10,y+6);
    printf(" [P] Proximo ");
    gotoxy(x+42,y+6);
    printf(" [F] Pular ");
    SetConsoleTextAttribute(cor,7);
    

    for(int i = 0; i < frases;i++){
    delay = delayA;
    x = 51;
    y = 2;
    linhass = 0;
    int tamanho = strlen(texto[i]);
    for(int j = 0; j < tamanho;j++){
    gotoxy(x+j+2,y+1);
    SetConsoleTextAttribute(cor,15 );
    printf("%c",texto[i][j]);
    SetConsoleTextAttribute(cor,7);
    linhass++;
    if(linhass == 63){
    x -= 63;
    y++;
    linhass = 0;
    }

    if(kbhit()){
        tecla = getch();
    }




    if(tecla == 'f'){
    delay = 0;
    }
    
    
    Sleep(delay);
    }
    
    while(1){
    x = 52;
    y = 3;
    
    tecla = getch();
    if(tecla == 'p'){

    if(tabelaAberta && !classeEscolhida){
    tabelaClasses();
    tabelaAberta = false;
    }

    for(int i = 0;i<4;i++){//limpa todo bloco de texto
    gotoxy(x,y+i);
    SetConsoleTextAttribute(cor,7);
    printf("                                                                 ");
    
    }
    break;
    }

    }

    }

    

    x = 51;
    y = 0;
    
    for(int i = 0;i<9;i++){//limpa todo bloco de texto
    gotoxy(x,y+i);
    SetConsoleTextAttribute(cor,7);
    printf("                                                                   ");
    }    

    

   

}

void Posicoes_iniciais(int lin,char *mapa[],posicao* telapos, posicao* player, posicao* npc, 
posicao* chave, posicao* porta,posicao* botao,bool *podecomecar){
int S = 0, T = 0;
  
    for(int i = 0; i < lin;i++){
    int colunas = strlen(mapa[i]); // conta quantas colunas tem
    for(int j = 0; j < colunas;j++){
        
    if(mapa[i][j] == '&'){player->x = j, player->y = i;}

    if(mapa[i][j] == '@'){chave->x = j, chave->y = i;}
    
    if(mapa[i][j] == 'D'){porta->x = j, porta->y = i;}

    if(mapa[i][j] == 'O'){botao->x = j, botao->y = i;}

    if(mapa[i][j] == '#'){ espinhos[S] = (posicao) {i,j}; S++;}
    
    if(mapa[i][j] == 'X'){npc->x = j, npc->y = i; lv1 = true; lv2 = false;}

    if(mapa[i][j] == 'V'){npc->x = j, npc->y = i; lv1 = false; lv2 = true;}

    if(mapa[i][j] == '>'){portais[T] = (posicao) {j,i}; T++;}
    

    }   
    }
    
    telapos->x = 55;telapos->y = 10;//posicao tela
    
    if(lv1){
    for(int i = 0; i < MAX_NPCS;i++){
    npclv[i].status.vidamax = rand() % 20+40;
    //DANO NPC
    npclv[i].status.danomax = rand() % 10 + 5;
    npclv[i].status.danomin = npclv[i].status.danomax/3 ;
    int intervalo = npclv[i].status.danomax - npclv[i].status.danomin + 1;
    npclv[i].status.dano = rand() % intervalo + npclv[i].status.danomin;//dano de 5 a 15
    //DANO NPC
    }
    }
    if(lv2){
    for(int i = 0; i < MAX_NPCS;i++){
    npclv[i].status.vidamax = rand() % 30 + 70;
    //DANO NPC
    npclv[i].status.danomax = 25;
    npclv[i].status.danomin = npclv[i].status.danomax / 3;
    int intervalo = npclv[i].status.danomax - npclv[i].status.danomin + 1;
    npclv[i].status.dano = rand() % intervalo + npclv[i].status.danomin;//dano de 8 a 25
    //DANO NPC
    }
    }

    
    if((player->x != 0 && player->y != 0) && (chave->x != 0 && chave->y != 0) && (porta->x !=0 && porta->y != 0)){
    *podecomecar = 1;
    }else{
    player->x;
    player->y;
    if(mapaA != 0){
    *podecomecar = 0; 
    }else{
    *podecomecar = 1; 
    }

    }
    

}

void Load_NPCS(int linhas,char *mapa[],posicao npc){

    if(npc.x != 0 && npc.y != 0){
        
    // Inicializa npclv ao entrar no mapa
        for (int i = 0; i < MAX_NPCS; i++) {//carrega todos npcs
            int x, y;
            
            do {

                y = rand() % linhas;//randomiza a posicao da linha de cada um
                int colunas = strlen(mapa[y]); // conta quantas colunas tem
                x = rand() % colunas;//randomiza a posicao da coluna de cada um
                

            } while (mapa[y][x] != '.');//npc nao nasce se nao for na posicao do caracter

            npclv[i].x = x;//posicao x npc
            npclv[i].y = y;//posicao y npc
            npclv[i].status.vida = npclv[i].status.vidamax;//vida maxima
            npclv[i].ativo = 1;//define se ele ta vivo 

        }
    // Inicializa goblins ao entrar no mapa
    }

}

void Load_Funcoes(posicao* p, posicao* chave, posicao* po, posicao* portapos,posicao* botao, char *mapaatual[], int lin,posicao npc) {
    HANDLE cor = GetStdHandle(STD_OUTPUT_HANDLE);
    int colunas = (int)strlen(mapaatual[0]);
    int linhas = lin;
    bool mover;
    int movimento = 0;
    int novox;
    int novoy;
    chaveItem.quant = 0;

    posicao interacao = {70,39};
    posicao inv = {15, 26};
    posicao npcstatus = {120,10}, playerstatus = {37,13};

    
    if(mapaA == 0){
    gramaDesenho(grama);
    arvore(po->x+15,po->y+10);
    arvore(po->x+25,po->y+12);
    arvore(po->x+5,po->y+15);
    arvore(po->x+35,po->y+5);
    arvore(po->x+40,po->y+17);
    arvore(po->x+15,po->y+20);
    }
    
    
    while(1){

    // Guarda a posição antiga do player
    novox = p->x;
    novoy = p->y;
    
 

    if(npc.x != 0 && npc.y != 0){
    //apaga posicaoinicial do npc
    SetConsoleTextAttribute(cor, 8 | 128);
    gotoxy(po->x + npc.x, po->y + npc.y);
    printf(" ");
    SetConsoleTextAttribute(cor, 7);
    }


    //                 interação com chave | porta (inicio)
    if ((p->x >= chave->x - 1 && p->x <= chave->x + 1) && (p->y >= chave->y - 1 && p->y <= chave->y + 1) && !chaveP) {
        SetConsoleTextAttribute(cor, 112);
        gotoxy(interacao.x+5, interacao.y); printf("     [ CHAVE ]     ");
        SetConsoleTextAttribute(cor, 128 | 15);
        gotoxy(interacao.x+4, interacao.y+1); printf("   [E] pegar chave   ");
        SetConsoleTextAttribute(cor, 7);
        if (tecla == 'e') {
            chaveP = true;
            chaveItem.quant = 1;
        }
    }

    if ((p->x >= portapos->x - 1 && p->x <= portapos->x + 1) && (p->y >= portapos->y - 1 && p->y <= portapos->y + 1)) {

        if((chaveP && !porta) && chaveItem.equip){//chave pega
            SetConsoleTextAttribute(cor, 112);
            gotoxy(interacao.x+1, interacao.y); printf("       [ PORTA ]      ");
            SetConsoleTextAttribute(cor, 128 | 15);
            gotoxy(interacao.x, interacao.y+1); printf(" [E] usar chave (ABRIR) ");

            if (tecla == 'e') {
                
                porta = true;
                chaveP = false;
                mao = false;
                chaveItem.quant = 0;
                tecla = 0;
                
            }
            
        }else if(!porta){//porta fechada
        SetConsoleTextAttribute(cor, 112);
        gotoxy(interacao.x+1, interacao.y); printf("        [ PORTA ]       ");
        SetConsoleTextAttribute(cor, 128 | 15);
        gotoxy(interacao.x, interacao.y+1); printf("       * TRANCADA *       ");
        SetConsoleTextAttribute(cor, 7);
        gotoxy(interacao.x, interacao.y+2); printf("(use a Chave(@) para abrir)");
        
        }

         
    if (porta){//porta aberta
        SetConsoleTextAttribute(cor, 7);
        gotoxy(po->x + portapos->x, po->y + portapos->y);
        printf(" ");
        gotoxy(po->x + chave->x, po->y + chave->y);
        

        if(porta){//porta aberta
            SetConsoleTextAttribute(cor, 112);
            gotoxy(interacao.x+1, interacao.y);  printf("       [ PORTA ]       ");
            SetConsoleTextAttribute(cor, 128 | 15);
            gotoxy(interacao.x, interacao.y+1); printf("  [E] interagir(ENTRAR)  ");
            SetConsoleTextAttribute(cor, 7);
            if (tecla == 'e') {
                mapaA++;
                system("cls");
                break;
            }
        }
        }

        }
    if(chaveP){
        if(mapaA != 0){
        SetConsoleTextAttribute(cor, 8 | 128);
        }else{
        SetConsoleTextAttribute(cor, 2 | 160);
        }
        gotoxy(po->x + chave->x, po->y + chave->y);
        printf(".");
        SetConsoleTextAttribute(cor, 7);
    

    }else if(!porta){
        SetConsoleTextAttribute(cor, 80);
        gotoxy(po->x + portapos->x, po->y + portapos->y);
        printf(" ");
        SetConsoleTextAttribute(cor, 7);
    }
    if(!chaveP && !porta){
        if(mapaA != 0){
        SetConsoleTextAttribute(cor, 5 | 128);
        }else{
        SetConsoleTextAttribute(cor, 5 | 160);
        }
        gotoxy(po->x + chave->x, po->y + chave->y);
        printf("@");
        SetConsoleTextAttribute(cor, 7);
    }
     
    //                 interação com chave | porta (fim)
    

    //BOTAO 

    if(mapaatual[p->y][p->x] == 'O'){
    gotoxy(0,10);
    printf("BOTAO PISADO");
    espinho = true;
    }else{
    gotoxy(0,10);
    printf("            ");
    
    }


    //BOTAO 

    //   ESPINHOS 
    static int passos = 0;

    for(int i = 0; i < MAX_ESPINHOS;i++){
    gotoxy(po->x + espinhos[i].y, po->y + espinhos[i].x);
    if(espinho){SetConsoleTextAttribute(cor,128);}//aparece
    if(!espinho){SetConsoleTextAttribute(cor,128 | 8);}//invisivel
    printf("#");
    SetConsoleTextAttribute(cor,7);
    }
    
    if(mapaatual[p->y][p->x] == '#' && espinho){//dmg espinho
    playerS.status.vida--;
    sangrando = true;
    }

    if(sangrando && mapaatual[p->y][p->x] != '#'){
    playerS.status.vida--;
    passos++;
    }

    if(passos >= 5){
    sangrando = false;
    passos = 0;    
    }
    
    //   ESPINHOS 

        
    
    // Espera tecla valida
    while (aberto) {
        tecla = getch();
        
        if (tecla == 'w' || tecla == 's' || tecla == 'a' || tecla == 'd' || tecla == 'e' || tecla == 'i' || 
           tecla == 'f' || (tecla >= '1' && tecla <= '6'))break;
               
    }

    // Apaga o rastro do player na posicao antiga
    gotoxy(po->x + novox, po->y + novoy);
    if(mapaatual[novoy][novox] == 'O')SetConsoleTextAttribute(cor, 1 | 128);
    else if(mapaA != 0){SetConsoleTextAttribute(cor,128 | 8 );}
    else if(mapaA == 0 && mapaatual[novoy][novox] == ',')SetConsoleTextAttribute(cor, 32 | 2);
    else{SetConsoleTextAttribute(cor, 160 | 10);}
    printf("%c", mapaatual[novoy][novox]);
    SetConsoleTextAttribute(cor, 7);

    
    // Atualiza posição do player conforme tecla
         if (tecla == 'w') novoy--;
    else if (tecla == 's') novoy++;
    else if (tecla == 'a') novox--;
    else if (tecla == 'd') novox++;


    // Valida se pode mover para o novo local
    if (mapaatual[novoy][novox] == '.' || mapaatual[novoy][novox] == ';' ||
    mapaatual[novoy][novox] == '@' || mapaatual[novoy][novox] == 'X' ||
    mapaatual[novoy][novox] == 'V' || mapaatual[novoy][novox] == '&' || 
    mapaatual[novoy][novox] == 'O' || mapaatual[novoy][novox] == '#' || mapaatual[novoy][novox] == '>' ||
    (mapaatual[novoy][novox] == ',' && mapaA == 0)) {
        p->x = novox;
        p->y = novoy;
    }

    // Desenha o player na posição atual
    if(mapaA != 0){SetConsoleTextAttribute(cor,128 | 6);}
    else if(mapaA == 0 && mapaatual[novoy][novox] == ',')SetConsoleTextAttribute(cor, 32 | 15);
    else{SetConsoleTextAttribute(cor, 160 | 15);}
    gotoxy(po->x + p->x, po->y + p->y);
    printf("&");
    SetConsoleTextAttribute(cor, 7);

    gotoxy(0, 0);

    //   PORTAIS

    for(int i = 0; i < MAX_PORTAIS;i++){
    gotoxy(po->x + portais[i].x, po->y + portais[i].y);
    SetConsoleTextAttribute(cor,128);
    printf(">");
    SetConsoleTextAttribute(cor,7);
    }

    for(int i = 0; i < MAX_PORTAIS-1;i+=2){

    if(p->x == portais[i].x && p->y == portais[i].y){
    p->x = portais[i+1].x+1;
    p->y = portais[i+1].y;
    }
    if(p->x == portais[i+1].x && p->y == portais[i+1].y){
    p->x = portais[i].x+1;
    p->y = portais[i].y;
    }

    }
    
    //   PORTAIS


    aberto = true;
   
    //apaga escrita
    gotoxy(interacao.x, interacao.y); printf("                          ");
    gotoxy(interacao.x, interacao.y+1); printf("                          ");
    gotoxy(interacao.x, interacao.y+2); printf("                           ");

    SetConsoleTextAttribute(cor, 7);

     

    //MOVIMENTO INIMIGO

    // Movimento dos NPCs com sistema de cansaço
        if (movimento > 6) {
            movimento = 0;
            mover = false;
        } else {
            movimento++;
            mover = true;
        }

    if(movimento > 6){//sistema de 'cansaço'
    movimento = 0; mover = false;

    }else{movimento++; mover = true;}


        if (mover) {
        for (int i = 0; i < MAX_NPCS; i++) {
        if (npclv[i].ativo && npclv[i].status.vida > 0){

        if(lv1){
        // Desenha goblin na nova posição
        gotoxy(po->x + npclv[i].x, po->y + npclv[i].y);
        SetConsoleTextAttribute(cor, 128);
        printf("X");
        SetConsoleTextAttribute(cor, 7);
        }
        if(lv2){
        // Desenha goblin na nova posição
        gotoxy(po->x + npclv[i].x, po->y + npclv[i].y);
        SetConsoleTextAttribute(cor, 128);
        printf("V");
        SetConsoleTextAttribute(cor, 7);
        }

        // Movimento do NPC
        int dx = p->x - npclv[i].x;
        int dy = p->y - npclv[i].y;
        int movs[4][2] = 
        {{0, 1}, //[0] move para baixo y+1 
        {0, -1}, //[1] move para cima y-1 
        {1, 0},  //[2] move para direita x+1 
        {-1, 0}};//[3]move para esquerda x-1
        int ordem[4];


        if(abs(dx) + abs(dy) == 1 ){//combate
        npclv[i].status.vida -= playerS.status.dano; 
        playerS.status.vida -= npclv[i].status.dano; 
        }
        

        if (abs(dx) > abs(dy) && abs(dx) < 7 && abs(dy) < 7) {//
        // Prioriza movimento horizontal se dentro do campo de visao 
        ordem[0] = (dx > 0) ? 2 : 3;
        ordem[1] = (dy > 0) ? 0 : 1;
        ordem[2] = (dy > 0) ? 1 : 0;
        ordem[3] = (dx > 0) ? 3 : 2;

        gotoxy(npcstatus.x+3,npcstatus.y+i+1);
        SetConsoleTextAttribute(cor,4);
        printf("%2d|HP: %2d/%2d|DMG %d ~ %2d |",i+1,npclv[i].status.vida,npclv[i].status.vidamax,npclv[i].status.danomin,npclv[i].status.danomax);
        

        } else if (abs(dy) < 7 && abs(dx) < 7) {
        // Prioriza movimento vertical se dentro do campo de visao
        ordem[0] = (dy > 0) ? 0 : 1;
        ordem[1] = (dx > 0) ? 2 : 3;
        ordem[2] = (dx > 0) ? 3 : 2;
        ordem[3] = (dy > 0) ? 1 : 0;
        gotoxy(npcstatus.x+3,npcstatus.y+i+1);
        SetConsoleTextAttribute(cor,4);
        printf("%2d|HP: %2d/%2d|DMG %d ~ %2d |",i+1,npclv[i].status.vida,npclv[i].status.vidamax,npclv[i].status.danomin,npclv[i].status.danomax);
        
        
        }else{
        // Player muito longe: não se move
        gotoxy(npcstatus.x+12,npcstatus.y);
        printf("%s",lv1 ? "LVL 1" : "LVL 2");

        gotoxy(npcstatus.x-2,npcstatus.y+i+1);
        printf("| NPC  |                     |");
        
        
        continue;
        }   
        SetConsoleTextAttribute(cor,7);

        

        // Desenha goblin na nova posição
        gotoxy(po->x + npclv[i].x, po->y + npclv[i].y);
        SetConsoleTextAttribute(cor, 128);
        printf(" ");
        SetConsoleTextAttribute(cor, 7);

        for (int j = 0; j < 4; j++) {
            int nx = npclv[i].x + movs[ordem[j]][0]; // nx = nova coluna (x)
            int ny = npclv[i].y + movs[ordem[j]][1]; // ny = nova linha (y)

            // Verifica limites corretamente e se pode andar (mapaatual[linha][coluna])
            if (nx >= 0 && nx < colunas && ny >= 0 && ny < linhas &&
                ((mapaatual[ny][nx] == '.' || mapaatual[ny][nx] == ';' || mapaatual[ny][nx] == 'O') && (mapaatual[ny][nx] != 'X' || mapaatual[ny][nx] != 'V') ) && !(nx == p->x && ny == p->y)) {

                npclv[i].x = nx;
                npclv[i].y = ny;
                break;
            }
        }

        if(lv1){
        // Desenha goblin na nova posição
        gotoxy(po->x + npclv[i].x, po->y + npclv[i].y);
        SetConsoleTextAttribute(cor, 128);
        printf("X");
        SetConsoleTextAttribute(cor, 7);
        }
        if(lv2){
        // Desenha goblin na nova posição
        gotoxy(po->x + npclv[i].x, po->y + npclv[i].y);
        SetConsoleTextAttribute(cor, 128);
        printf("V");
        SetConsoleTextAttribute(cor, 7);
        }
        
        if(npclv[i].status.vida <= 0){
        npclv[i].ativo = false;

        if(lv1){
        // Desenha goblin na nova posição
        gotoxy(po->x + npclv[i].x, po->y + npclv[i].y);
        SetConsoleTextAttribute(cor, 128 | 8);
        printf(".");
        SetConsoleTextAttribute(cor, 7);
        }
        if(lv2){
        // Desenha goblin na nova posição
        gotoxy(po->x + npclv[i].x, po->y + npclv[i].y);
        SetConsoleTextAttribute(cor, 128 | 8);
        printf(".");
        SetConsoleTextAttribute(cor, 7);
        }

        }


        }
        if(npclv[i].status.vida <= 0 && npc.x != 0){
        gotoxy(npcstatus.x+3,npcstatus.y+i+1);
        SetConsoleTextAttribute(cor,4);
        printf("%2d MORTO                  ",i+1);
        SetConsoleTextAttribute(cor,7);
        }

        }
        }

    //MOVIMENTO INIMIGO

    

    // DIALOGO COM NPCS    
    
    int frases;

    if(p->x == npcVila[0].x && p->y == npcVila[0].y && mapaA == 0){//NPC 1
    
    SetConsoleTextAttribute(cor, 112);
    gotoxy(77,6);
    printf("  ELDRIC     ");
    SetConsoleTextAttribute(cor,128 | 15);
    gotoxy(76,7);
    printf(" [E] Interagir ");
    SetConsoleTextAttribute(cor,7);

    if(tecla == 'e'){
    int caixax = 51,caixay = 2;

    SetConsoleTextAttribute(cor,112);
    gotoxy(70,0);
    printf("                             ");
    gotoxy(70,1);
    printf("         E L D R I C         ");
    SetConsoleTextAttribute(cor,7);
    
    if(!dialogo[0]){
    char *NPCTEXTO1[] = 
    {"...Voce e... de verdade? Por um momento, achei que fosse so    mais um deles... com o rosto vazio, o olhar morto. Mas voce... voce ainda tem alma nos olhos. Algo que quase ninguem mais tem por aqui...",

     "Vieram ao amanhecer. Sem aviso. Sem piedade. As paredes cairam,as laminas falharam. Os gritos... ninguem respondeu. Foi como  se o mundo tivesse acabado em poucos minutos.",

     "Minha filha foi levada. Nao gritou. Eles ja estavam nela.      Os olhos dela se apagaram. Como se algo tivesse entrado e      arrancado tudo por dentro. Como se ela nunca tivesse existido.",

     "Dizem que o Exercito Final caiu. Que Meridiana esta condenada. Mas voce... voce carrega algo diferente. Tem algo antigo ai    dentro. Algo que eu nao vejo desde antes da guerra.",

     "Sinto ecos em voce. Vozes velhas. Como os herois das historias que contavamos pras criancas. Se for verdade... entao va. Nao  perca tempo com um velho quebrado como eu.",

     "Faca com que a morte deles tenha algum sentido. Que o sangue nao tenha sido em vao. Que a vila, mesmo destruida, ainda tenha  deixado algo que vale a pena lutar com todas as forcas.",

     "Ela usava isso... minha menina. Um amuleto simples. Nao deve servir pra muito, mas talvez te lembre do que esta protegendo.   Pegue. Nao quero que se perca aqui com o resto.",

     "Va. Antes que eles voltem. Ou pior... antes que ninguem mais   sobre. Se voce for nossa ultima chance... entao faca valer.    Mesmo que seja so por mais uma noite viva.",

     "Eu guardei isso... por teimosia ou desespero. Sao so algumas   porcoes. Nao curam tudo, mas podem manter voce de pe por mais  um pouco. Pegue. Nao vai servir pra mais ninguem aqui.",

    };

    
    frases = sizeof(NPCTEXTO1) / sizeof(NPCTEXTO1[0]);

    texto(NPCTEXTO1,frases,25,caixax,caixay);

    
    pocao.quant = 5;

    if(invAberto){
    inventario(item, inv);
    }

    char *NPCTEXTO1_1[] = {
    "* 5x Porcoes adquiridas *",
    };

    frases = sizeof(NPCTEXTO1_1) / sizeof(NPCTEXTO1_1[0]);

    texto(NPCTEXTO1_1,frases,25,caixax,caixay);
    dialogo[0] = true;
    }else{
    char *NPCTEXTO1_2[] = {
    "Ja te dei tudo que eu tinha. Agora so posso esperar. Se voce falhar... pelo menos saberei que tentamos. Mesmo no fim, ainda restava uma fagulha.",
    };

    frases = sizeof(NPCTEXTO1_2) / sizeof(NPCTEXTO1_2[0]);

    texto(NPCTEXTO1_2,frases,25,caixax,caixay);
    }
    
    }
    }

    else if(p->x == npcVila[1].x && p->y == npcVila[1].y && mapaA == 0){//NPC 2
    
    SetConsoleTextAttribute(cor, 80 | 15);
    gotoxy(76,6);
    printf(" Malgron(Mago)  ");
    SetConsoleTextAttribute(cor,128 | 15);
    gotoxy(75,7);
    printf("  [E] Interagir   ");
    SetConsoleTextAttribute(cor,7);

    if(tecla == 'e'){
    int caixax = 51,caixay = 2;

    SetConsoleTextAttribute(cor,80 | 15);
    gotoxy(70,0);
    printf("                             ");
    gotoxy(70,1);
    printf("   M A L G R O N ( Mago )    ");
    SetConsoleTextAttribute(cor,7);
    



    if(!dialogo[1]){
    char *NPCTEXTO2[] = 
    {"Entao... voce e o eco escolhido pelas vozes antigas. Curioso.  Eu vi a queda do primeiro portao, e mesmo assim, ainda estou   aqui. Estudando, esperando... sobrevivendo.",

     "Os Sem-Rosto nao lutam por poder. Eles devoram. Eles assimilam. O que tomam, nao devolvem. Nem a carne, nem a memoria. Nem a  alma.",

     "A mente-colmeia cresce a cada suspiro roubado. E agora, ate as estrelas parecem escurecer quando eles passam. Esta preparado  para enfrentar isso?",

     "Eu estudei suas origens. Nao foram criados... foram chamados.  Alguem, em algum lugar, abriu uma porta que jamais deveria ter sido tocada.",

     "Eles absorvem tudo. Espadas e fe, medo e coragem. So o que e   esquecido escapa. Ha poder no esquecimento, mas ha um preco.",

     "Tome isto. Uma chave. Ferro antigo, mas ainda responde ao que resta de magia neste mundo. Abrira o portao esquecido na colina. Alem dele, a caverna onde tudo comecou.",


    };

    frases = sizeof(NPCTEXTO2) / sizeof(NPCTEXTO2[0]);

    texto(NPCTEXTO2,frases,25,caixax,caixay);

    //chave adquirida
    chaveP = true;
    chaveItem.quant = 1;
    adicionaritem(item,&chaveItem);

    if(invAberto){
    inventario(item, inv);
    
    }
    //chave adquirida

    char *NPCTEXTO2_1[] = {

    " * CHAVE ADQUIRIDA * ",

    "La dentro, o ar e mais denso. Os ecos sao mais vivos. E voce...vai sentir que esta sendo observado. Isso e normal. So nao fale com as vozes, mesmo que parecam familiares.",

     "Agora incline-se. Voce carrega um espirito dentro de si.       Um fragmento antigo de fe ou furia. Vou despertar o que esta adormecido, e sua forma se completara neste ritual.",
    };

    SetConsoleTextAttribute(cor,80 | 15);
    gotoxy(70,0);
    printf("                             ");
    gotoxy(70,1);
    printf("   M A L G R O N ( Mago )    ");
    SetConsoleTextAttribute(cor,7);

    frases = sizeof(NPCTEXTO2_1) / sizeof(NPCTEXTO2_1[0]);

    texto(NPCTEXTO2_1,frases,25,caixax,caixay);
    
    tabelaAberta = true;

    char *NPCTEXTO2_2[] = 
    {"Se for monge, seus musculos se tornarao leves e sua energia fluira como agua. Se for paladino, sua armadura selara a fe nos ossos. Se for inquisidor... prepare-se para o peso.",};

    frases = sizeof(NPCTEXTO2_2) / sizeof(NPCTEXTO2_2[0]);

    texto(NPCTEXTO2_2,frases,25,caixax,caixay);

    char *NPCTEXTO2_3[2]; 
    if(class1){

    NPCTEXTO2_3[0] = "Agilidade... fluidez... como a correnteza. Voce se move como se ja conhecesse o caminho antes mesmo de dar o passo. A disciplina te reconhece como um dos seus...";

    }
    else if(class2){
    NPCTEXTO2_3[0] = "Eu senti... a fe em sua carne, o juramento silencioso. A armadura nao te pesa. Voce nasceu para proteger, mesmo que o mundo desabe. O fogo da ordem desperta em voce...";

    }
    else if(class3){
    NPCTEXTO2_3[0] = "O silencio... o peso... sua alma carrega cicatrizes que nem mesmo voce lembra. O julgamento e sua arma. A dor nao te assusta. So os verdadeiros inquisidores andam assim...";

    }

    NPCTEXTO2_3[1] = "O espirito que habita voce so despertou o que ja estava ai. Nenhuma alma recebe um fardo que nao possa carregar. Agora, va. O mundo espera pela sua queda... ou ascensao.";

    frases = sizeof(NPCTEXTO2_3) / sizeof(NPCTEXTO2_3[0]);

    texto(NPCTEXTO2_3,frases,25,caixax,caixay);
    dialogo[1] = true;
    }else{
        
    char *NPCTEXTO2_4[] = {

    "A casa esta vazia. As vozes se foram. Mas, por algum motivo,   ainda me pego olhando a porta.Talvez esperando por voce. Talvez por um milagre. Cuidado la fora.",

    };

    frases = sizeof(NPCTEXTO2_4) / sizeof(NPCTEXTO2_4[0]);

    texto(NPCTEXTO2_4,frases,25,caixax,caixay);
    }




    }
    }

    else if(p->x == npcVila[2].x && p->y == npcVila[2].y && mapaA == 0){//NPC 3
    
    SetConsoleTextAttribute(cor, 144 | 15);
    gotoxy(76,6);
     printf(" Tharn(Ferreiro) ");
    SetConsoleTextAttribute(cor,128 | 15);
    gotoxy(75,7);
    printf("   [E] Interagir   ");
    SetConsoleTextAttribute(cor,7);

    if(tecla == 'e'){
    int caixax = 51,caixay = 2;

    SetConsoleTextAttribute(cor,144 | 15);
    gotoxy(70,0);
    printf("                             ");
    gotoxy(70,1);
    printf("    T H A R N (ferreiro)     ");
    SetConsoleTextAttribute(cor,7);
    
    if(!dialogo[2]){
    char *NPCTEXTO3[] = {  
    "...Voce esta inteiro... isso ja e raro hoje em dia.Eu sou Tharn. Ferreiro. Ou... era. Agora so tenho o que sobrou da forja  e um martelo que nao quer quebrar.",
    
    "Quando vieram, eu fiquei. Nao por coragem. Por covardia mesmo. Nao consegui correr. Tranquei tudo, segurei o fole com as maos tremendo. Eles passaram... por enquanto.",
    
    "Pegue isso. Uma lamina simples. Fraca, mas melhor que os punhos. Se conseguir trazer metal mais puro, posso melhorar. Ate la.. sobreviva. E tente fazer valer o esforco.",
    };

    frases = sizeof(NPCTEXTO3) / sizeof(NPCTEXTO3[0]);

    texto(NPCTEXTO3,frases,25,caixax,caixay);

    espada.quant = 1;

    if(invAberto){
    inventario(item, inv);
    }

    char *NPCTEXTO3_1[] = {  
    "* Espada(raridade) Adquirida * ",
    };

    frases = sizeof(NPCTEXTO3_1) / sizeof(NPCTEXTO3_1[0]);

    texto(NPCTEXTO3_1,frases,25,caixax,caixay);



    dialogo[2] = true;
    }else{
    char *NPCTEXTO3_1[] = { 
    "Voce de novo... Isso e bom. Sinal de que ainda esta vivo. Nem todo mundo tem essa sorte por aqui.",
    
    };

    frases = sizeof(NPCTEXTO3_1) / sizeof(NPCTEXTO3_1[0]);

    texto(NPCTEXTO3_1,frases,25,caixax,caixay);

    }

    }
    }
    
    else{
    gotoxy(76,6);
    printf("                     ");
    gotoxy(75,7);
    printf("                       ");
    
    }
  
    // DIALOGO COM NPCS


    //EQUIPAMENTO

    static bool equipado = true;
    if(espada.equip){  
    
    if(equipado){  
    playerS.status.danomax += espada.dano;
    equipado = false;
    }
    }else{
    
    if(!equipado){  
    playerS.status.danomax -= espada.dano;
    equipado = true;
    }
    }

    //EQUIPAMENTO


    //STATUS DE CADA CLASSE
    if(mapaA == 0 && class1){
    playerS.status.vidamax = rand() % 40 + 35;playerS.status.vida = playerS.status.vidamax;
    class1 = false;
    cornome = 1;
    playerS.status.danomax = 25;
        
    }
    if(mapaA == 0 && class2){
    playerS.status.vidamax = rand() % 40 + 110;playerS.status.vida = playerS.status.vidamax;
    class2 = false;
    cornome = 2;

    playerS.status.danomax = 15;
    }
    if(mapaA == 0 && class3){
    playerS.status.vidamax = rand() % 40 + 60;playerS.status.vida = playerS.status.vidamax;
    class3 = false;
    cornome = 3;

    playerS.status.danomax = 10;
    }
    playerS.status.danomin = playerS.status.danomax/3;
    int intervalo = playerS.status.danomax - playerS.status.danomin + 1;
    playerS.status.dano = rand() % intervalo + playerS.status.danomin;
    //STATUS DE CADA CLASSE


    //CURA
    if(pocao.equip){
    gotoxy(interacao.x+5,interacao.y);
    printf("[E] Usar pocao");
    

    if(tecla == 'e'){

    if(playerS.status.vidamax > playerS.status.vida){
    playerS.status.vida+=pocao.cura;
    pocao.quant--;
    }else{
    gotoxy(interacao.x+5,interacao.y+1);
    printf("  (Vida Cheia)");
    }
    if(playerS.status.vidamax < playerS.status.vida){
    playerS.status.vida = playerS.status.vidamax;
    }

    }
    }
    //CURA


    //INVETARIO

    if(tecla == 'i'){
    invAberto = !invAberto;
    }
    
    if(tecla == 'f'){mao = false;chaveItem.equip = false;pocao.equip = false;espada.equip=false;}

    if(invAberto){

    if((tecla >= '1' && tecla <= '6') || tecla == 'f'){


    mao = true;
    chaveItem.equip = false;
    pocao.equip = false;

    if(tecla == 'f'){mao = false;}
    
    Equipado(&pocao,&itemMao);
    Equipado(&chaveItem,&itemMao);
    Equipado(&espada,&itemMao);

    }

    adicionaritem(item,&pocao);//para existir tem que ter pelo menos 1 de quant
    adicionaritem(item,&chaveItem);//para existir tem que ter pelo menos 1 de quant
    adicionaritem(item,&espada);//para existir tem que ter pelo menos 1 de quant

    inventario(item, inv);
    
    }
    else{
    for(int i = 0; i < 9;i++){
    gotoxy(inv.x,inv.y+i);
    printf("                                      ");
    }
    }

    //INVETARIO
    

    tabelaPlayer(playerstatus);
    
    

    if(playerS.status.vida <= 0 && mapaA < 4){   
    morto = true;

    break;
    }


}

}
