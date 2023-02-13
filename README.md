# Tic-tac-toe (三目並べ)
## Introduce video (紹介動画)
https://www.youtube.com/watch?v=qboU19cj8qs

## What is this?
This is my first C++ practice Tic-tac-toe program.

これはC++の練習を兼ねた三目並べのプログラムです。 (C++を用いた初めての作品)

## How to download (ダウンロード方法) ※windows only
https://github.com/natyosu3/Tic-tac-toe--sanmoku-narabe/releases/tag/ver1.0
<br>
Go to the release page and download the exe file and run it.
<br>
releaseページに移動してexeファイルを実行する。

* ## Structure (仕組み)
    * ### English

    1. The computer (opponent) goes first and gets the squares in the four corners or the center.
    2. If the computer (opponent) gets edge first
        * If the center is empty, get the center square
        * If the center is not empty, get the empty corner square
    3. If there is a square that you can win, fill it. Prevents victory if the player has reach, fills empty squares from above if there is no reach
    4. Same as 3rd act.
    5. Same as 3rd act.

    ---
    * ### 日本語

    1. コンピュータ(相手)が先攻で、4つ角または中央のマスを取得します。
    2. コンピュータ(相手)は初めに角を取得した場合
        * 中央が空いていたら、中央のマスを取得する
        * 中央が空いていなかったら、空いている角のマスを取得する
    3. 自分の勝てるマスがあれば埋める。プレイヤにリーチがあれば勝利を阻止する、リーチが無ければ空いているマスを上から埋めていく
    4. 3回目の行動と同様
    5. 3回目の行動と同様


* ## Development environment (開発環境)

    Microsoft Visual Studio 2022 Enterprise
