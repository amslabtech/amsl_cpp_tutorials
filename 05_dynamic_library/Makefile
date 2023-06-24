CC=g++
SRC=main.cpp lib.cpp
OBJ=$(SRC:.cpp=.o)
INCLUDE=
TARGET=main
DYNAMIC_LIB=dynamic_sample
DYNAMIC_LIB_FILE=$(addprefix lib, $(addsuffix .so, $(DYNAMIC_LIB)))

all: clean $(TARGET)

$(TARGET): main.o $(DYNAMIC_LIB_FILE)
	$(CC) -o $(TARGET) main.o ./$(DYNAMIC_LIB_FILE)

main.o: main.cpp
	$(CC) -c main.cpp $(INCLUDE)

# 動的ライブラリを生成
$(DYNAMIC_LIB_FILE): lib.cpp
	$(CC) -shared lib.cpp -o $(addprefix lib, $(addsuffix .so, $(DYNAMIC_LIB))) -fPIC $(INCLUDE)

clean:
	rm -rf $(OBJ) $(TARGET) $(DYNAMIC_LIB_FILE)

