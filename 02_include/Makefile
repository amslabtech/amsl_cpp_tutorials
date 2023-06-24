CC=g++
SRC=main.cpp
OBJ=$(SRC:.cpp=.o)
# -Iオプションでインクルードディレクトリを指定
INCLUDE=-I../common
TARGET=main

all: clean $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

# インクルードディレクトリを指定してコンパイル
$(OBJ): $(SRC)
	$(CC) -c $(SRC) $(INCLUDE)

clean:
	rm -rf $(OBJ) $(TARGET)

