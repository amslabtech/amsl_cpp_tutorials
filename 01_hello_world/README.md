# 01_hello_world

## C++ソースコードのビルド(g++)
```
g++ main.cpp -o main
```
- ビルドには`g++`コマンドを用いる
- `-o`は出力される実行ファイルの名前を指定するオプション
  - 指定しない場合`a.out`になる

生成物の実行は以下の通り
```
./main
```

コンパイルしてからリンクする場合
```
g++ -c main.cpp
# オブジェクトファイルmain.oが生成される
g++ main.o -o main
```

## C++ソースコードのビルド(make)
上記のようなビルドの手順を`Makefile`に記載しておくことで、`make`コマンドを用いてビルドできるようになる

`Makefile`は
```Makefile
ターゲット: 依存ターゲット
  実行するコマンド
```
のように書く

参考: http://omilab.naist.jp/~mukaigawa/misc/Makefile.html

`Makefile`があるディレクトリで単に`make`を実行すると、`Makefile`内の一番上に定義されたターゲットが実行される。`make ターゲット`として、ターゲットを指定して実行することもできる

例えばこのディレクトリで`make clean`を実行すると、これまでに生成した`main`や`main.o`が削除される。`make`を実行するとこれらが再度生成される

`make`の実際の処理は、そのターゲットの依存対象に更新があったときのみ実行される。例えばこのディレクトリで`make clean`してから`make main`を2回実行すると、1回目はビルドが実行されて`main`及び`main.o`が生成されるが、2回目は`make: 'main' is up to date.`と表示され、処理がスキップされる

## C++ソースコードのビルド(cmake)
クロスプラットフォーム・非コンパイラ依存で様々な環境向けの`Makefile`の生成などができるツール

参考: https://cmake.org/

```
# ビルドシステムの生成
# -S: Source Treeの指定。そのプロジェクトで最上位のCMakeLists.txtがあるディレクトリ
# -B: Build Treeの指定。生成物が置かれるディレクトリとなる。無ければ作られる
# build以下にMakefileが生成される
cmake -S . -B build

# ビルド実行
# --buildにはBuild Treeのディレクトリを与える
# build以下に生成物が置かれる
cmake --build build
```
なお、古いcmakeでは以下のようにビルドする
```
mkdir build
cd build
cmake ..
make
```
