# コンパイラを指定
CC=g++
# ソースファイルを指定
SRC=main.cpp
# オブジェクトファイルを指定
# 右辺はSRCの.cppを.oに置き換える処理
# - https://stackoverflow.com/questions/12069457/how-to-change-the-extension-of-each-file-in-a-list-with-multiple-extensions-in-g
OBJ=$(SRC:.cpp=.o)
# 最終的なターゲットを指定
TARGET=main

# デフォルトターゲット
all: clean $(TARGET)

# mainターゲットをmain.oから生成
$(TARGET): $(OBJ)
	$(CC) -o $(TARGET) $(OBJ)

# main.oターゲットをmain.cppから生成
$(OBJ): $(SRC)
	$(CC) -c $(SRC)

# cleanターゲット。生成物を削除する
clean:
	rm -rf $(OBJ) $(TARGET)
