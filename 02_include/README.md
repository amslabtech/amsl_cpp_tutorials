# 02_include

## 外部ファイルをincludeする場合のビルド(g++)
```
g++ main.cpp -I../common -o main
```
`-I`オプションに続けて対象のファイルが存在するパスを指定する。相対パスでも絶対パスでも良い

このオプションで指定したパスが、includeの検索対象に追加される

参考: https://docs.oracle.com/cd/E19957-01/806-4837/Rev.html

## 外部ファイルをincludeする場合のビルド(make)
`Makefile`の内容を参照のこと。
ビルドのためのコマンドは01と同様

## 外部ファイルをincludeする場合のビルド(cmake)
`CMakeLists.txt`の内容を参照のこと。
ビルドのためのコマンドは01と同様
