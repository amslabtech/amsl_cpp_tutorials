CC=g++
SRC=main.cpp lib.cpp
OBJ=$(SRC:.cpp=.o)
INCLUDE=
TARGET=main
STATIC_LIB=static_sample
STATIC_LIB_FILE=$(addprefix lib, $(addsuffix .a, $(STATIC_LIB)))
STATIC_LIB_DIR=-L.

all: clean $(TARGET)

$(TARGET): main.o $(STATIC_LIB_FILE)
	$(CC) -o $(TARGET) main.o $(STATIC_LIB_DIR) -l$(STATIC_LIB)

main.o: main.cpp
	$(CC) -c main.cpp $(INCLUDE)

# 静的ライブラリを生成
$(STATIC_LIB_FILE): lib.cpp
	$(CC) -c lib.cpp $(INCLUDE)
	ar rc libstatic_sample.a lib.o

clean:
	rm -rf $(OBJ) $(TARGET) $(STATIC_LIB_FILE)

