void vitoria(){
system("cls");

posicao estrela = { 1,3};


char tela[30][50] = {
    ".........................",
    "....*.V I T O R I A .*...",
    ".... ............... ....",
    "... ................. ...",
    "... Obrigado por jogar...",
    ".... ................ ...",
    "..... .[Criadores] . ....",
    "...... ............ .....",
    "....... ..Arthur.. ......",
    "........ ..Davi.. .......",
    "......... Lucas  ........",
    "............. ...........",
};


for(int i = 0; i < 30; i ++){
gotoxy(70,i+5);
printf("%s\n", tela[i]);
}




}


void derrota(){

posicao derrota = {73,15};

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
char gameover[30][50] = {

    "  ____________________  ",
    " /                    \\ ",
    "| V O C E  M O R R E U!|",
    " \\____________________/ ",
    " |                    | ",
    " |                    | ",
    " |                    | ",
    " |                    | ",
    " |                    | ",
    " |____________________| ",
    "                        ",

};

char ops[3][30] = {"TENTE NOVAMENTE","MENU PRINCIPAL","SAIR"};

int op;

if(chances > 0){op = 0;}
else{op = 1;}


while(1){
for(int i = 0; i < 12; i ++){
for(int j = 0; j < 28; j ++){
gotoxy(j+derrota.x,i+derrota.y);
if(i == 2 && (j>= 1 && j <= 21)){
SetConsoleTextAttribute(console,4);
}else{
SetConsoleTextAttribute(console,7);
}
printf("%c\n", gameover[i][j]);
}
}



if(chances > 0){
if(op == 0){gotoxy(derrota.x+3,derrota.y+4);printf(">%s<", ops[0]);}
else{gotoxy(derrota.x+3,derrota.y+4);printf(" %s ", ops[0]);}
}else{
SetConsoleTextAttribute(console,4);
gotoxy(derrota.x+2,derrota.y+4);printf("X %s X", ops[0]);
SetConsoleTextAttribute(console,7);
}

if(op == 1){gotoxy(derrota.x+4,derrota.y+6);printf(">%s<", ops[1]);}
else{gotoxy(derrota.x+4,derrota.y+6);printf(" %s ", ops[1]);}

if(op == 2){gotoxy(derrota.x+9,derrota.y+8);printf(">%s<", ops[2]);}
else{gotoxy(derrota.x+9,derrota.y+8);printf(" %s ", ops[2]);}


gotoxy(derrota.x+6,derrota.y+9);printf("CHANCES %d/3 ", chances);
int tecla = getch();

if(chances > 0){
if(tecla == 'w' && op > 0)op--;
}else{
if(tecla == 'w' && op > 1)op--;
}


if(tecla == 's' && op < 2)op++;

if(tecla == 13){

if(op == 0 ){chances--;playerS.status.vida = playerS.status.vidamax;sangrando = false;break;}
if(op == 1 ){chances = 3;continuar = false;escolha = 0;break;}
if(op == 2 ){system("cls");continuar = false;escolha = 3;break;}

}

}

}