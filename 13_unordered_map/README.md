# 13_unordered_map

STL(Standard Template Library)のコンテナの一種で、連想配列

他言語でいう辞書型に相当する

[`std::map`](https://cpprefjp.github.io/reference/map/map.html)と異なりhash mapとして実装されており、ソートされない。そのためunorderdという名前になっている

要素へのアクセスの計算量は、`std::map`はO(log(N)), `std::unordered_map`はO(1)である。そのため、keyの大小によるソートが必要ない限り、`std::unordered_map`を使うと良い

参考:
- https://cpprefjp.github.io/reference/unordered_map/unordered_map.html
- https://cpprefjp.github.io/reference/map/map.html
