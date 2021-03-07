# ライフゲーム

## はじめに．

ライフゲームとは，生命の誕生や衰退をシミュレーションする計算のことです．
![demo](https://raw.github.com/wiki/KazuhisaMiyazawa/LifeGame/images/movie.gif)

私は，C言語でライフゲームのシミュレーションを行い，出力したデータをgnuplotにより可視化しました．

ここでは，私が作成したプログラムやスクリプトをお見せします．

下記の方法を実行するためには，Bash および gnuplot をターミナル上から実行できる環境が必要です．



## 使い方．

まず，src ディレクトリでソースをコンパイルします．ターミナル上で

```shell
$ sh icon.sh	
```

 と実行すると，実行プログラム「MAIN」が生成されます．

つぎに，sample ディレクトリで「main.sh」を実行します．

```shell
$ sh main.sh
```

これにより，「MAIN」が実行されます．

得られたデータはその後， gnuplot によって可視化され，pngファイルに保存されます．

「main.sh」の処理が完了すると，sample/png ディレクトリ内に000.png から999.png のファイルが生成されます．このあとは必要に応じて Gif ファイルに変換してください．

