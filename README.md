# 🕹️ Dungeon Crawler em C++
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
> *(Adicione aqui screenshots ou gifs de gameplay para mostrar o resultado)*

---

## 🚀 Rodando o jogo
```bash
g++ main.cpp -o jogo
./jogo
