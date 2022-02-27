
# Algorítmos de teoria dos grafos

Projeto realizado para a disciplina de teoria dos grafos 2021.1.
Todos os algorítmos foram feitos em C++.



## Rodando localmente

Clone o projeto

```bash
  git clone https://github.com/clauds-macedo/TeoriaDosGrafos.git
```

Entre no diretório do projeto

```bash
  cd TeoriaDosGrafos
```

Você irá se deparar com 4 pastas: Bellman-Ford, Dijkstra, Kruskal e Prim.
Dentro de cada uma dessas pastas existe um arquivo de input, o código de seu respectivo algorítmo e o arquivo principal que servirá para executar o código do algorítmo passando os parametros "-f, -i, -l, -o, -s e -h".

### Para executar o código:

Entre no diretório do algorítmo
```bash
  cd Dijkstra
```

Em seguida, compile o arquivo principal
```bash
  g++ dijkstra_main_file.cpp -o dijkstra_main_file
```

Posteriormente, execute-o pelo terminal
```bash
  ./dijkstra_main_file -f input.txt -i 1
```

Saída:
```bash
  1:0 2:5 3:4 4:2 5:10 6:3
```
