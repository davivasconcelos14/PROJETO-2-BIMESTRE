void reset(){
    chaveP = false;
    porta = false;
    aberto = false;
    espinho = false;
}


void Playgame(){



    posicao p = {0,0} , po = {0,0},npclv = {0,0},chave = {0,0},portapos = {0,0},npcamigavel = {0,0}, 
    botao = {0,0};
    playerS.status.vidamax = rand() % 15 + 15;playerS.status.vida = playerS.status.vidamax;
    playerS.status.danomax = 5;playerS.status.danomin = playerS.status.danomax/3;
    int intervalo = playerS.status.danomax - playerS.status.danomin + 1;
    playerS.status.dano = rand() % intervalo + playerS.status.danomin;
    
    int linhas; 



    

    //*********************[ MAPAS ]********************
/*[ SIMBOLOS ]

    Player     | &
    Npc        | p
    Parede     | *
    Chao       | .
    Chave      | @
    Botao      | O
Teletransporte | >
Mostro nivel 1 | X              
Mostro nivel 2 | V   


*/


    char *mvila[] = {

    "* * * * * * * * * * * * * |   | * * * * * * * * * * * * * ",
    "*.........................,.&.,..........................*",
    "*..........................,,,...........................*",
    "*111111==...................,.......=....................*",
    "*111111=..,.................,......===...................*",
    "*111111.P.,,,,,,,,,,,,,,,,,,,.......=...................3*",
    "*111111=..,.................,..........................3.*",
    "*111111==...................,...........................3*",
    "*...............=...........,.........................222*",
    "*..............===..........,.......................22222*",
    "*...............=.........=.,.....................2222222*",
    "*........................===,......................111111*",
    "*.........................=,,,.................,..111==1=*",
    "*.....=....................,,,,,,,,,,,,,,,,,,,,,.P 1111==*",
    "*....===...................,,,.................,.....====*",
    "*.....=........==...........,............=...............*",
    "*..............===..........,...........===..............*",
    "*44.........................,............=...............*",
    "*4444...........=...........,............................*",
    "*444444........===..........,............................*",
    "*111111====.....=........,,,,............................*",
    "*111111...=,.,,,,,,,,,,,,,..,............................*",
    "*11111 P...,,,..............,............................*",
    "*.........=,...............,,,...........................*",
    "*==========...............,,,,,..........................*",
    "*........................,,|D|,,.........................*",
    "* * * * * * * * * * * * * * * * * * * * * * * * * * * * *",
   
};

    char *dungeon1[] = { 
    
    "*************| |************                                      ",
    "*.............&............*                                      ",
    "*..........................********                               ",
    "*.................................*                               ",
    "*..........................****...*                               ",
    "*..........................*  *...*                               ",
    "*******...**********...*****  *...*                               ",
    "      *...*        *...*      *...*   *********|D|************    ",
    "      *...*        *...*      *...*   *......................*    ",
    "      *...*        *...*      *...*   *......................*    ",
    "      *****        *...*      *...*   *......................*    ",
    "                   *...*      *...*   *......................*    ",
    "                   *...*      *...*   *......................*    ",
    "  ******************...****   *...*   *......................*    ",
    "  *.......................*   *...*   *......................*    ",
    "  *.@.....................*   *...*   *********...************    ",
    "  *.......................*   *...*           *...*               ",
    "  *.......................*   *...*           *...*               ",
    "  *****...*****************   *...*           *...*               ",
    "      *...*                   *...*           *...*               ",
    "*******...*********************...*           *...*               ",
    "*.................................*           *...*               ",
    "*...*******************************************...*               ",
    "*.................................................*               ",
    "*.................................................*               ",
    "***************************************************               ",
    "                                                                  ",
    "                                                                  ",


    };

    char *dungeon2[] = {

    "            ***                                         ",    
    "           *   *                                        ",
    " ***********;&;*    *********************************** ",
    "*;;;;;;;;;;;;;;*   *...................................*",
    "*;;;;;;;;;;;;;;*   *...................................*",
    "*;;;;;;;;;;;;;;*****.......*************...****........*",
    "*;;;;;;;;;;;;;;;;;;;;......*           *...*   *.......*",
    "*;;;;;;;;;;;;;;;;;;;;......*           *...*   *.......*",
    " **...*********;;;;;;......*           *...*   *.......*",
    " *.....*   *............***            *...*   *.......*",
    " *.....*   *...**********              *...*   *.......*",
    " *.....*   * D *                    ****...***  ******* ",
    " *.....*                            *........*          ",
    " *.....*                            *........*          ",
    " *.....*                            **********          ",
    " *.....*                                                ",
    "  *...*                                                 ",
    "   *...*                                                ",
    "    *...*****************************************       ",
    "     *...O....#....#.#.#..#......................*      ",
    "     *...O......#....#.#....#....................*      ",
    "      ****..#.....#.#.......#.......X........@...*      ",
    "         *..#...#...#.....#......................*      ",
    "         *..#..........#....#....................*      ",
    "          ****************************************      ",
        
    };

    char *dungeon3[] = {

    "*************************************************",
    "*;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;&  *",
    "*..********.*...*******.***********.*************",
    "*...#.....*.......*.....*.........*...........>.*",
    "*.*O*****.*******.*..**.*...****.*...*******.*..*",
    "*#......*.......*.*O*.*...#....*.*.#.*.....*.*O.*",
    "*>.****.*********.*.*.*.******.*.*...*.***.*##..*",
    "*..#..*#*...#.....*.*.*..#....*.....*...*.*.*...*",
    "*****.*.*.*********.*.*******.*...*******#*.*****",
    "*...*.*.*...#...*...*..#....*.*>...#....*.*.....*",
    "*.*.*#*.*******.*.*********.*.*********.*.*****.*",
    "*.*...*............................#....*.....*.*",
    "*.*********..#...#....#..#....****.*..******....*",
    "*....O.........#...#...........*.#.*..#.#..*.*..*",
    "*>.*******...#..............#..*#*********#..*..*",
    "*..............#.....#....V....*.........*>..*..*",
    "*.******.*...#.....#....#......*********.*****..*",
    "*.##...*.*.....................*.....*...*#.....*",
    "******.*.*****.*****...***.*.*.*.***.*.***..*****",
    "*............*.....*.....*...*...*.*...O....>...*",
    "*.**.*********.***.*..**.*********...****..***.#*",
    "*...........*.#.#.*#.#..*.........*.*......##.*#*",
    "*>.*.********.******..*.*********.*.*********.*#*",
    "*.....O.....*.........*...........*....@....*.*#*",
    "*#*********#*..********.******.***********..*.*#*",
    "*>......*........#..*.#....*#..........*........*",
    "**..****.***....***.******...*********..........*",
    "*...............................................*",
    "********************|D|**************************"


};

//*********************[ MAPAS ]********************


system("cls");
mapaA = 0;
continuar = true;

char **todosmapas[] = {mvila, dungeon1, dungeon2, dungeon3};

while(continuar){  
  
    reset();

    switch(mapaA){
    case 0:linhas = sizeof(mvila) / sizeof(mvila[0]);
    break;
    case 1:linhas = sizeof(dungeon1) / sizeof(dungeon1[0]);
    break;
    case 2:linhas = sizeof(dungeon2) / sizeof(dungeon2[0]);
    break;
    case 3:linhas = sizeof(dungeon3) / sizeof(dungeon3[0]);
    break;
    }
    
    Load_Map(linhas,todosmapas[mapaA], p,po,npclv,chave,portapos,botao);


    if(mapaA == 4){
    vitoria();
    getch();
    escolha = 0;
    continuar = false;
    }

    if(morto == true){
    derrota();
    }


}
    



}
