#include "VARIAVEIS/globais.h"
#include "Play.h"
#include "Creditos.h"

bool menucarregado = false;

posicao menupos;


void logoD(){

    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

    menupos.x = 25;
    menupos.y = 5;

    char bordas[13][70] = {
       " ___________________________________________________________________",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|                                                                   |",
       "|___________________________________________________________________|"
    };

    Sound hit = LoadSound("links/som/hit.wav");
    Sound slide = LoadSound("links/som/deslize.wav");
    system("cls");

    for (int x = 0; x < 13; x++) {
        gotoxy(27+menupos.x,x+2+menupos.y);
        printf("%s", bordas[x]);
        
    printf("\n");
    }



    char logo[10][81] = {
        /*
        "  ____    _   _   __  _    ____   ____    ___    __  _",
    	" |  _ \\  | | | | |  \\| |  / ___| | ___|  / _ \\  |  \\| |",
    	" | | | | | | | | |     | | |  _  | __   | | | | |     |",
 		" | |_| | | |_| | | |\\  | | |_| | | ___  |  -  | | |\\  |",
		" |____/   \\____| |_| \\_|  \\____| |____|  \\___/  |_| \\_|",
        */
        " _______   ______   _______    _______   ___      ___    ______  ",
    	"/ ____  | |      | |__   __|  /   ____| |   \\    /   |  /      \\",
		"|/____| | |  D   |    | |     |  |___   | |\\ \\  / /| | |   /\\   |",
 		"| ____  | |     <     | |      \\___  |  | | \\ \\/ / | | |   \\/   |",
		"| |   | | |  D   |  __| |__   ____/  /  | |  \\__/  | | |        | ",
    	"| |   | | |______| |_______| |______/   |_|        | |  \\______/ ",
        "                                                                     ",
        "                          D O S       ",
        "                   S E M  R O S T O S",
        
    };
    
    

    for (int x = 0; x < 6; x++) {
        gotoxy(29+menupos.x,x+4+menupos.y);
        SetConsoleTextAttribute(console,6);
        printf("%s", logo[x]);
        SetConsoleTextAttribute(console,7);
        
    if(!menucarregado)PlaySound(hit), Sleep(200);

    printf("\n");
    }

    if(!menucarregado){
    for(int y = 0; y < 31;y++ ){
       
    gotoxy(y+3+menupos.x,11+menupos.y);
    printf("%s", logo[7]);
    gotoxy(y+3+menupos.x,12+menupos.y);
    printf("%s", logo[8]);
    

    gotoxy(27+menupos.x,11+menupos.y);
    printf("%c", bordas[7][0]);
    gotoxy(27+menupos.x,12+menupos.y);
    printf("%c", bordas[8][0]);
    }
    PlaySound(slide);
    Sleep(50);
    }else{
    gotoxy(33+menupos.x,11+menupos.y);
    printf("%s", logo[7]);
    gotoxy(33+menupos.x,12+menupos.y);
    printf("%s", logo[8]);
    }
 
     UnloadSound(hit);
     UnloadSound(slide);
}



void menu(void play(),void credits()) {
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    
    while(1){
    Sound lobbysom = LoadSound("links/som/menu.mp3");
    
    
    float volume = 0.5f;
    
    SetSoundVolume(lobbysom,volume);
    
    
    system("cls");
    logoD();
    
    if(!menucarregado)PlaySound(lobbysom);

    char *texto[] = {"P L A Y","C R E D I T O S","S A I R"};
    int tamanho = sizeof(texto) / sizeof(texto[0]);

    int op = 0;
    

    menucarregado = true;
    while (kbhit()) getch();//limpando buffer de tecla clicada

    while(escolha == 0){
    

    for(int i = 0; i < tamanho;i++){

    gotoxy(52+menupos.x,i+15+menupos.y);
    if(i == op){
    if(i == 1){
    printf("-> %s\n",texto[i]);        
    }else{
    printf("->    %s\n",texto[i]);    
    }

    }
    else{
    
    gotoxy(52+menupos.x,i+15+menupos.y);
    if(i == 1){
    printf("   %s     \n",texto[i]);        
    }else{
    printf("      %s      \n",texto[i]);    
    }
    }
    
    }

    
    int tecla = getch();
    
    if((tecla == 'w' || tecla == 72) && op > 0){
    op--;
    }
    else if((tecla == 's' || tecla == 80) && op < 2){
    op++;    
    }


    if(tecla == 13){
    system("cls");
    escolha = op+1;
    }
    if(tecla == 27) break;



    }


    if(escolha == 1){
    
    int carregamento = 0;
        
        gotoxy(42+menupos.x,11+menupos.y);
        printf("C A R R E G A N D O   M U N D O");
        gotoxy(46+menupos.x,12+menupos.y);
        printf("[                      ]");

        for(int i = 0; i < 20;i++){
        gotoxy(56+menupos.x,13+menupos.y);
        
        printf("%d%% ", carregamento);//porcetagem na barra de carregamento

        carregamento+= 5;
        gotoxy(48+i+menupos.x,12+menupos.y);
        SetConsoleTextAttribute(console, 112);
        printf("%c",' ');
        SetConsoleTextAttribute(console, 7);
        Sleep(100);
        volume-= volume/15;
        SetSoundVolume(lobbysom,volume);
        }
        StopSound(lobbysom);
        UnloadSound(lobbysom);
        system("cls");

        play();
        
    }

    if(escolha == 2){
        credits(menupos.x, menupos.y);
        
        escolha = 0;
    }

    if(escolha == 3){
        printf("\n\n\tFechando...\n\n");
        break;
    }
    

    }
}



