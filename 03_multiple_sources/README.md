# 03_multiple_sources

## ソースファイルが複数ある場合のビルド(g++)
```
g++ main.cpp lib.cpp -I../common -o main
```
ソースファイル名を並べれば良い

## ソースファイルが複数ある場合のビルド(make)
`Makefile`の内容を参照のこと。
ビルドのためのコマンドは01と同様

## ソースファイルが複数ある場合のビルド(cmake)
`CMakeLists.txt`の内容を参照のこと。
ビルドのためのコマンドは01と同様
