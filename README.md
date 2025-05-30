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
