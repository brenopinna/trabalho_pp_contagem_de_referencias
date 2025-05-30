CFLAGS = -Icontref/include

LDLIBS = -Lcontref/bin -lcontref

.PHONY: lib                                                          # vai executar sempre que eu quiser a diretiva make lib, sem dependencias

#* build do projeto com a lib ja compilada
main:
	mkdir -p bin                                                       # cria o diretorio bin, caso nao exista
	gcc -c $(CFLAGS) main.c -o bin/main.o                              # compila o obj da main na pasta bin
	gcc $(CFLAGS) bin/main.o -o bin/main $(LDLIBS)                     # compila o main.o e a lib pra bin/main
	rm bin/main.o                                                      # remove o arquivo objeto intermediario

#* build da lib
lib:
	mkdir -p contref/bin                                               # cria o diretorio contref/bin, caso nao exista
	gcc -c $(CFLAGS) contref/src/contref.c -o contref/bin/contref.o    # compila o obj da contref na pasta contref/bin
	ar rvs contref/bin/libcontref.a contref/bin/contref.o              # vai gerar o arquivo da biblioteca na pasta contref/bin
	rm contref/bin/contref.o                                           # remove o arquivo objeto intermediario

# Peguei do link: https://wiki.inf.ufpr.br/maziero/doku.php?id=c:construcao_de_bibliotecas
# r (replace): substituir versões anteriores dos arquivos na biblioteca, caso existam
# v (verbose): mostrar na tela as inclusões que estão sendo realizadas
# s (symbols): criar uma tabela dos símbolos1) que estão sendo agregados à biblioteca 

#* limpeza dos arquivos
clear:
	rm -rf main *.o *.i *.s *.a                    # vai eliminar todos os arquivos, exceto os codigos fonte
	rm -rf contref/bin                             # apaga a pasta contref/bin
	rm -rf bin                                     # apaga a pasta bin