# 05_dynamic_library

## 動的ライブラリ(g++)
動的ライブラリは、ビルド時には実行ファイルにリンクのみされる。実行時に動的ライブラリを自動的に探して使うため、実行ファイルだけでなく動的ライブラリも用意する必要がある
```
g++ -shared lib.cpp -o libdynamic_sample.so -fPIC
g++ main.cpp -L. -ldynamic_sample -o main
```
参考: http://0xcc.net/blog/archives/000107.html

## 動的ライブラリ(make)
`Makefile`の内容を参照のこと。
ビルドのためのコマンドは01と同様

## 動的ライブラリ(cmake)
`CMakeLists.txt`の内容を参照のこと。
ビルドのためのコマンドは01と同様
