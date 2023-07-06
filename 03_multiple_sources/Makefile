CC=g++
# lib.cppを追加
SRC=main.cpp lib.cpp
OBJ=$(SRC:.cpp=.o)
INCLUDE=-I../common
TARGET=main

all: clean $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

# これでもコンパイルはできるが、SRCの内一つでも更新があった場合に全てのファイルをコンパイルしてしまう
# $(OBJ): $(SRC)
# 	$(CC) -c $(SRC) $(INCLUDE)

# main.oとlib.oを別ターゲットにすることで、更新のあった方だけコンパイルする
main.o: main.cpp
	$(CC) -c main.cpp $(INCLUDE)

lib.o: lib.cpp
	$(CC) -c lib.cpp $(INCLUDE)

clean:
	rm -rf $(OBJ) $(TARGET)

