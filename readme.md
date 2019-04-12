# UFRPE 2019.1 Algo-Graphs

```
Team: Aldan Andrade, João Uchoa, Lucas Francisco, Givanildo Júnior, Elias
Professor: Rodrigo de Souza
```

## Build [![Build Status](https://travis-ci.org/JampaUchoa/GRAPH-ALG-BCC.svg?branch=master)](https://travis-ci.org/JampaUchoa/GRAPH-ALG-BCC)

To build in a UNIX command line use 
```
gcc main.c GRAPH_LST.c GRAPH_MTX.c -o a.out
```

And to run

```
./a.out    
```

One off command:

```
gcc main.c GRAPH_LST.c GRAPH_MTX.c -o a.out && ./a.out; rm ./a.out
```

## Como enviar codigo
A branch master é protegida contra push diretos, para que ninguem quebre o codigo e impeça os outros membros, para enviar:

* Clone o projeto
* De `$ git checkout -b sua_branch`
* Atualize seu codigo com `git add .` e `git commit`
* De push remoto da sua nova branch
* Va no github e faça uma pull request, caso esteja rodando voce mesmo pode mandar ela para master
