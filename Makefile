CPP = g++
CFLAGS = -Wall -Wextra -Werror


treetest: tree_test.cpp AVL.o Node.o
	$(CPP) $(CFLAGS) -o treetest $^

AVL.o: AVL.h AVL.cpp
	$(CPP) $(CFLAGS) -c AVL.cpp

ntest: node_test.cpp Node.o
	$(CPP) $(CFLAGS) -o ntest node_test.cpp Node.o

Node.o: Node.h Node.cpp
	$(CPP) $(CFLAGS) -c Node.cpp

clean:
	rm -f *.o;
	rm -f ntest; rm -f ttest; rm -f treetest;
	rm -f *~;
