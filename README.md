# 🕹️ Dungeon Crawler em C
ALUNOS: Arthur Miguel, Lucas Banna e Davi Duarte :shipit:

> Um jogo 2D desenvolvido em C++ com gráficos, exploração por mapas e elementos interativos como chaves, portas, monstros e armadilhas. Desenvolvido em 4 semanas.
## 📖 História
Você é um aventureiro solitário que acorda em uma masmorra desconhecida. Ecos de criaturas sombrias ecoam pelos corredores enquanto você busca uma saída. Portas trancadas, armadilhas e monstros guardam os segredos que se escondem em cada canto. Com apenas sua coragem, você deve explorar, sobreviver e descobrir quem — ou o que — o trouxe até aqui.

---

## 🎯 Objetivo
O objetivo do jogo é atravessar todos os mapas (fases), interagindo com NPCs, coletando chaves, abrindo portas, evitando armadilhas e derrotando monstros. O jogador deve usar a lógica e explorar os ambientes para avançar, enfrentando desafios cada vez mais complexos.

---

## 🎮 Como Jogar

- **Movimentação**: Use as teclas `W`, `A`, `S`, `D` para mover o personagem.
- **Interações**:
  - `E` para interagir com portas, chaves e NPCs.
  - Passar sobre armadilhas pode causar sangramento e perda de vida.
- **Objetos e mecânicas**:
  - 🔑 **Chaves** abrem portas trancadas.
  - 🚪 **Portas** bloqueiam caminhos até que sejam desbloqueadas.
  - ⚔️ **Monstros** podem atacar o jogador — derrote-os para avançar.
  - 🧨 **Armadilhas** causam dano — evite-as!
- **HUD e Status**: Seu status (vida, chaves, etc.) é exibido no terminal.
- **Fim de jogo**: O jogo termina ao completar o último mapa... ou ao morrer tentando.
  
 ---
 
>No codigo feito para o 'MENU PRINCIPAL' foi utilizado funções diversas como: <br/>
`Kbhit() ` `Switch{}`<br/>`Getch() ` `If Else `<br/>`HANDLE  ` `char    `<br/>`While() ` `printf()`<br/>`int`

<br/>

---

## 📅 Cronograma de Desenvolvimento

### ✅ Semana 1 – Menu
- 🎨 Design da aparência
- 🧭 Navegação entre opções
- 🔘 Criação dos botões
- ✨ Animações no menu

---

### ✅ Semana 2 – Mapa 1
- 🧍 Player funcional (movimentação)
- 🧑‍🤝‍🧑 NPCs com interações básicas
- 🗺️ Mapa visual criado
- 🗣️ Interação com NPCs
- 🔑 Sistema de chave e porta
- 🧱 Colisão com paredes

---

### ✅ Semana 3 – Mapas 2 e 3
- 🗺️ Criação dos mapas 2 e 3
- 👣 Player funcional nesses mapas
- 🔑 Interação com chave e porta
- 👾 Criação dos monstros (nível 1 e 2)
- 🧨 Armadilhas ativáveis
- 🩸 Sistema de sangramento
- ⚔️ Sistema de combate
- 🔘 Botões interativos

---

### ✅ Semana 4 – Mapa 4 + Otimização
- 🗺️ Criação do mapa 4
- ♻️ Organização e simplificação do código
- 🔁 Reimplementação de player, chave, porta e paredes
- 👾 Monstro nível 2 com lógica melhorada
- 🧨 Armadilhas e combate refinado
- 🧼 Refatoração do código

---

## 🛠️ Tecnologias
- C++
- `windows.h` e outras libs nativas
- Lógica baseada em terminal (ASCII/console)
- Organização modular com headers

---

## 🎮 Imagens do jogo
> ![variaveis do mapa](https://github.com/user-attachments/assets/a10aeb9b-f8c3-483e-b3af-f6f3a94ecab0)
![Todas funcoes(pt9)](https://github.com/user-attachments/assets/bdcdabbd-599f-4e80-bdd2-f45e37a154ad)
![Todas funcoes(pt8)](https://github.com/user-attachments/assets/e0191fa3-20ac-411a-b354-5a982a3b48d1)
![Todas funcoes(pt7)](https://github.com/user-attachments/assets/b41a7054-b6e1-4034-addf-2da38fc99a37)
![Todas Funcoes(pt6)](https://github.com/user-attachments/assets/35fd1608-0be4-45e0-8e29-72f4b1576ce8)
![Todas Funcoes(pt5)](https://github.com/user-attachments/assets/dc036b2f-0da0-49c0-994f-6b4be7de2674)
![Todas Funcoes(pt4)](https://github.com/user-attachments/assets/a45f865a-690a-40ce-9dc9-1c24a7f7d971)
![Todas Funcoes(pt3)](https://github.com/user-attachments/assets/927a1c3d-2e31-4401-a3a4-1110aebb90e2)
![Todas Funcoes(pt2)](https://github.com/user-attachments/assets/88a421f0-7684-490e-a802-7435b7b04b90)
![Todas funcoes(pt1)](https://github.com/user-attachments/assets/4b786701-d318-4b2b-82ea-5e689a6b0387)
![Sistema de navegacao](https://github.com/user-attachments/assets/3fc12a7e-07d1-46b8-96f8-05f2bf5811be)
![Sistema de navegacao(cont)](https://github.com/user-attachments/assets/38c87bb6-4127-42f9-ad85-8fa00d242bd2)
![Portal](https://github.com/user-attachments/assets/f4af9034-1d3d-4a2a-b85e-1871e52f4d8d)
![Organizacao de arquivos](https://github.com/user-attachments/assets/275a108f-a6d3-40b0-8fd6-9362e9b8e20c)
![Organizacao da preparacao dos mapas e das funcoes](https://github.com/user-attachments/assets/869fcc3f-4f73-40e3-9dcd-505cf3e41a4d)
![Ordem de preparacao do mapa](https://github.com/user-attachments/assets/8cdb850a-a383-4dbd-a4ff-ea0ed9cbfd23)
![Monstro lvl 1(terminal)](https://github.com/user-attachments/assets/7b48e86f-5baf-4dd5-a378-7a16baf5d4d6)
![Menu](https://github.com/user-attachments/assets/c0b65b7e-0510-4e22-8516-e02f11ff7b52)
![Mapa 4](https://github.com/user-attachments/assets/7e3d9c43-8fa1-4ab0-9f79-9babc9e4b1a6)
![Mapa 4(terminal)](https://github.com/user-attachments/assets/9c0a04f8-fb9f-4f82-ab51-6f3c0c9724c2)
![Mapa 3](https://github.com/user-attachments/assets/51d92cb4-d07a-4c49-a1d9-ea1b73a5e134)
![Mapa 3(terminal)](https://github.com/user-attachments/assets/88a663b9-5b85-4d2b-b0c8-9358e5475676)
![Mapa 2](https://github.com/user-attachments/assets/9f7806ef-9dff-4bf5-87e4-f97ed2601c08)
![Mapa 2(terminal)](https://github.com/user-attachments/assets/ea4bf117-dbe9-4852-ac4b-8ab44fb32c43)
![Mapa 1](https://github.com/user-attachments/assets/2138177b-1176-464b-9ac9-cb031a357274)
![Mapa 1(terminal)](https://github.com/user-attachments/assets/2983804f-1d0d-4272-a85c-2fe993698acc)
![Logo](https://github.com/user-attachments/assets/d8999c31-dae1-46f4-ab00-09ad6b9b4322)
![Intercao com porta](https://github.com/user-attachments/assets/be357c82-ac39-4129-aaf0-d207d9e80dc1)
![Interacao com chave](https://github.com/user-attachments/assets/cbd1d8b2-34e4-45fe-a723-2aff325987a1)
![includes](https://github.com/user-attachments/assets/4c30e024-bcaa-4dc5-a04f-0c2e11213337)
![Funcoes separadas do windows h](https://github.com/user-attachments/assets/b8d0e2be-7443-465a-8506-a387f49ccee2)
![Funcao do play(cont)](https://github.com/user-attachments/assets/cd61295f-665d-46e0-b025-5d9c1744a475)
![Funcao do play para os mapas](https://github.com/user-attachments/assets/9cbe2eae-9be8-4232-a758-fb867d7653ca)
![Funcao desenhar mapa](https://github.com/user-attachments/assets/158d7e41-df50-4768-b5f0-4c1252f8f2c4)
![Creditos](https://github.com/user-attachments/assets/de614de0-a2bd-4e07-821f-297363af2050)
![Creditos no terminal](https://github.com/user-attachments/assets/46c6ab69-4b95-4bab-a6e0-04c5ca10a149)
![confirma se pode caarregar o mapa](https://github.com/user-attachments/assets/6438aed5-0138-49e3-bc06-aa21c9d4986f)
![Carregamento da posicao dos elementos](https://github.com/user-attachments/assets/986edb15-5ec0-4d96-b843-a0296f1da5c5)
![Carrega status NPCS](https://github.com/user-attachments/assets/ea7aa1ed-3d1c-44a1-bbd9-190edae2c7d8)
![Bordas da logo](https://github.com/user-attachments/assets/bf6ad3fb-3f66-42aa-b515-affae2cf325a)
![Armadilhas](https://github.com/user-attachments/assets/ba001b1b-5267-4e05-a267-3d80d3b35d55)

---

## 🚀 Rodando o jogo
```bash

