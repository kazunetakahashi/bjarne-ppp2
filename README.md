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
$ brew install fltk
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

全部一気にコンパイルする場合は以下のようになる。

```
$ g++-9 -std=c++14 -I/usr/local/Cellar/fltk/1.3.5/include -L/usr/local/Cellar/fltk/1.3.5/lib -lfltk -lfltk_images -lpthread -framework Cocoa -o ./a.out Graph.cpp GUI.cpp Simple_window.cpp Window.cpp sample.cpp
```

オブジェクトコードを生成してからリンカで実行プログラムを作成する場合は以下のようになる。

```
$ g++-9 -std=c++14 -I/usr/local/Cellar/fltk/1.3.5/include -c -o sample.o sample.cpp
$ g++-9 -L/usr/local/Cellar/fltk/1.3.5/lib -lfltk -lfltk_images -lpthread -framework Cocoa Graph.o GUI.o Simple_window.o Window.o sample.o
```

この場合は変更がないコードのコンパイルの時間が節約できる。

## その他のソース

- `Sec11/neverland_in.txt` の文章は [The Promised Neverland - Wikipedia](https://en.wikipedia.org/wiki/The_Promised_Neverland) からとりました。
- `Sec12-16/vegetable_wings.jpg` は大学入試センター試験 2019 年度 英語(リスニング)からとりました。

## 謝辞

この本は、[ほしい物リスト](https://amzn.to/31Pa0S1)に登録していたら、どなたかわからないけれども、私に送ってくださったものです。大変ありがとうございます。全部読みます。