# **So Long**

![so_long](link_para_uma_imagem_do_jogo.png)

Um pequeno jogo 2D construído em **C**, com o propósito de explorar o gerenciamento de janelas, a manipulação de eventos e a renderização de gráficos básicos. O projeto é um exercício da 42SP e tem como objetivo principal o domínio da **MiniLibX**, a biblioteca gráfica da escola.

## **Tema do Jogo**

O tema do jogo é uma interpretação da história original do projeto "So Long, and Thanks for All the Fish!". Em vez de um golfinho, a personagem principal é uma **barda** que deve coletar todas as **notas musicais** em um labirinto, enquanto evita um **inimigo** que tenta silenciá-la.

## **Funcionalidades**

### **Parte Obrigatória**

* **MiniLibx**: Uso obrigatório da biblioteca para gerenciar a janela e os eventos.
* **Controle de Movimento**: O jogador pode se mover usando as teclas **`W`**, **`A`**, **`S`** e **`D`**.
* **Validação de Mapa**: O jogo aceita um arquivo de mapa (`.ber`) como argumento e valida sua estrutura, garantindo que ele seja retangular, cercado por paredes e que contenha os componentes essenciais (**`P`**, **`E`**, **`C`**, **`0`**, **`1`**).
* **Contador de Movimentos**: O número de movimentos é exibido no terminal a cada jogada.
* **Encerramento do Jogo**: O jogo pode ser fechado de forma limpa ao pressionar **`ESC`** ou ao clicar no "X" da janela.

### **Parte Bônus**

* **Inimigo**: Um inimigo patrulheiro que faz o jogador perder se tocado.
* **Animação de Sprites**: Os sprites do jogador e do inimigo são animados, tornando a jogabilidade mais fluida.
* **Contador na Tela**: O contador de movimentos é exibido diretamente na janela do jogo, em vez do terminal.

## **Tecnologias e Ferramentas**

* **Linguagem**: C
* **Biblioteca Gráfica**: MiniLibX
* **Bibliotecas de Suporte**: [Libft](https://github.com/carolinecbahia/libft), [ft_printf](https://github.com/carolinecbahia/ft_printf)
* **Controle de Versão**: Git

## **Como Compilar e Executar**

1.  **Clone o repositório**:
    ```bash
    git clone [https://github.com/carolinecbahia/so_long.git](https://github.com/carolinecbahia/so_long.git)
    cd so_long
    ```
2.  **Compile o projeto**:
    ```bash
    make
    ```
3.  **Execute o jogo**: O programa deve receber um mapa válido (`.ber`) como argumento.
    ```bash
    ./so_long <mapa.ber>
    ```

## **Estrutura do Projeto**

* `srcs/`: Contém todos os arquivos de código-fonte do projeto.
* `includes/`: Contém os arquivos de cabeçalho (`.h`).
* `Libft/`: Contém a biblioteca **`libft`**.
* `minilibx/`: Contém a biblioteca **MiniLibX**.
* `maps/`: Contém os arquivos de mapa (`.ber`).
* `textures/`: Contém os sprites e texturas do jogo.
