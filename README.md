# Sobre o projeto

Este repositório contém os arquivos fonte de uma biblioteca que implementa o algoritmo de coleta de lixo por contagem de referêcias e de um código que a consome, junto de alguns comentários ilustrando o funcionamento do algoritmo. No header file, há uma documentação da utilização das funções compatível com o formato [**Doxygen**](https://www.doxygen.nl/#google_vignette), que é automaticamente reconhecido pela Intellisense de IDEs como o VSCode.

# Compilando e executando o programa (sistemas operacionais Unix-Like)

OBS: todos os comandos aqui descritos devem ser feitos a partir da **raiz** do projeto

## Com o GNUMake

1. `make lib` => Compilando a biblioteca do algoritmo de coleta
2. `make` => Compilando os demais arquivos e embutindo a biblioteca
3. `./bin/main` => Executando o programa
4. `make clear` => Apaga os arquivos binários, deixando apenas o código fonte

## Com o GCC

### Compilando a Biblioteca:

```bash
cd contref
mkdir -p bin
gcc -c -Iinclude src/contref.c -o bin/contref.o
ar rvs bin/libcontref.a bin/contref.o
rm bin/contref.o
```

### Compilando o Programa Final:

```bash
mkdir -p bin
gcc -c -Icontref/include main.c -o bin/main.o
gcc -Icontref/include bin/main.o -o bin/main -Lcontref/bin -lcontref
rm bin/main.o
```

### Executando o programa:

```bash
./bin/main
```

### Apagando os Binários:

```bash
rm -rf main *.o *.i *.s *.a
rm -rf contref/bin
rm -rf bin
```
