
//estrutura para posicao X e Y dos players
typedef struct{
    int x,y;

}posicao;
//estrutura para posicao X e Y dos players



//INFOvida
typedef struct {
    int vidamax, vida;
    int dano,danomax,danomin;
    
}info;
//INFOvida

//   [ NPC ]
typedef struct {
    int x,y;
    info status;
    int ativo;

}NPC;

typedef struct 
{
    char nome[50];
    int quant;
    bool existe;

}itens;




//   [ NPC ]

    char tecla;
    int mapaA;    
    bool chaveP;
    bool porta;
    bool aberto;
    bool continuar;
    NPC playerS;
    int escolha = 0;
    int chances = 3;

//MAPA.H

//mostros
#define MAX_NPCS 5
NPC npclv[MAX_NPCS];
bool lv1, lv2;
//mostros

//espinho
#define MAX_ESPINHOS 100
bool espinho = false;
bool sangrando = false;
posicao espinhos[MAX_ESPINHOS];
//espinho

//portais
#define MAX_PORTAIS 8
posicao portais[MAX_PORTAIS];
//portais

posicao grama = {70,25};//estrutura mapa
bool morto = false;//condicao player

//MENU INTERNO
bool menuaberto = false;
//MENU INTERNO

//NPCS
posicao npcVila[3] = {{9,5}, {48,13}, {8,22}};
//NPCS

//CLASSES
bool tabelaAberta = false;
bool classeEscolhida = false;

int cornome = 0;
bool class1 = false;
bool class2 = false;
bool class3 = false;
//CLASSES

//INV
int invAberto = false;
itens item[6];
int slot = 99;
bool listamod = false;
//INV

typedef struct{

    char nome[50];
    int quant;
    int slot;
    bool equip;
    int cura;
    int dano;
    int durabilidade;
    int durMax;

}utili;

//ITENS
utili pocao = {"pocao",0,99,false,30};
utili chaveItem = {"Chave",0,99,false};
utili espada = {"Espada",0,99,false,0,15,25,25};

//ITENS

bool mao;
int itemMao;

bool dialogo[3];
//MAPA.H
        




#include "Imprimirmapa.h"
#include "mapa.h"
#include "carregamentogeral.h"
#include "VitoriaDerrota.h"


