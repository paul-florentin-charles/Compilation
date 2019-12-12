LEX=flex
YACC=bison
CFLAGS=-Wall -g -O0
CC=gcc
PROG=lcc

SRC_D=./src
BIN_D=./bin
TEST_D=./test
TEST_D_BIS=./resultat
BUILD_D=./build

DEPS = Table_des_symboles.o Table_des_registres.o Table_des_fonctions.o Table_des_chaines.o semact_decl.o semact_fun.o semact_exp.o semact_bool.o utile.o semact_aff.o semact_app.o arglist.o

DEPS_O = $(patsubst %,$(BUILD_D)/%,$(DEPS))

all: $(BIN_D)/$(PROG)

tests: all
	sh run_tests.sh

$(BIN_D)/$(PROG): $(BUILD_D)/lang.tab.o $(BUILD_D)/lex.yy.o $(DEPS_O)
	$(CC) $(CFLAGS) -o $@ $^

$(SRC_D)/lex.yy.c: $(SRC_D)/lang.l
	$(LEX) -o $@ $<

$(SRC_D)/lang.tab.h: $(SRC_D)/lang.y
	$(YACC) -y -d -v $< -o $@

$(SRC_D)/lang.tab.c: $(SRC_D)/lang.y
	$(YACC) -d -v $< -o $@

$(BUILD_D)/%.o: $(SRC_D)/%.c $(SRC_D)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_D)/lex.yy.o: $(SRC_D)/lex.yy.c $(SRC_D)/lex.yy.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_D)/lex.yy.h:


clean:
	@rm -f $(SRC_D)/lex.yy.c $(BUILD_D)/* $(SRC_D)/lang.tab.h $(SRC_D)/lang.tab.c $(BIN_D)/$(PROG) $(SRC_D)/lang.output $(TEST_D)/*.ll $(TEST_D)/*.txt $(TEST_D_BIS)/*.ll $(TEST_D_BIS)/*.txt
