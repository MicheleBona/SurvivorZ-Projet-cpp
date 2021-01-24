CC=g++
CCFLAGS= -Wall -Werror -std=c++11 -g
LIBFLAGS=
SRC= main.cc communaute.cc survivant.cc equipement.cc contenant.cc outil.cc sac.cc
OBJ= $(SRC:.cc=.o)
TST_DIR=tests/
TST= $(wildcard $(TST_DIR)/*.cc)
OBJ_TEST = $(filter-out main.o, $(OBJ)) $(TST:.cc=.o)
EXEC= main 


all: $(EXEC)

testcase : 
	cd $(TST_DIR) ;  make

$(EXEC): $(SRC)
	$(CC) $(LIBFLAGS) $^ -o $@  

.depend:
	g++ $(CCFLAGS) -MM $(SRC) > .depends
-include .depends

clean:
	rm -f $(OBJ) $(EXEC)

cleantest:
	cd $(TST_DIR) ; make clean

distclean : clean cleantest
