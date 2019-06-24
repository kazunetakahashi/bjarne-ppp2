# bjarne-ppp2

[Bjarne Stroustrup: C++ によるプログラミングの原則と実践](https://amzn.to/31Res2m) "Programming: Principles and Practice Using C++ (2nd Edition)" をやります。

## 環境構築用メモ

以下を参考にしています。

- [support code for PPP2](http://www.stroustrup.com/Programming/PPP2code/)
- [MackSix/ppp-stroustrup](https://github.com/MackSix/ppp-stroustrup)

### FLTK

Section 12-16 は GUI 環境整えるのに結構苦労しました。

#### インストール

```
brew install fltk
```

#### コンパイルに必要なオプション

```
$ fltk-config --includedir
/usr/local/Cellar/fltk/1.3.5/include
$ fltk-config --ldflags
-L/usr/local/Cellar/fltk/1.3.5/lib -lfltk -lpthread -framework Cocoa
```

これに加えて `-lfltk_images` を入れる必要があった。

#### コンパイル例

```
g++-9 -std=c++14 -I/usr/local/Cellar/fltk/1.3.5/include -L/usr/local/Cellar/fltk/1.3.5/lib -lfltk -lfltk_images -lpthread -framework Cocoa -o ./a.out Graph.cpp GUI.cpp Simple_window.cpp Window.cpp sample.cpp
```

## 謝辞

この本は、[ほしい物リスト](https://amzn.to/31Pa0S1)に登録していたら、どなたかわからないけれども、私に送ってくださったものです。大変ありがとうございます。全部読みます。