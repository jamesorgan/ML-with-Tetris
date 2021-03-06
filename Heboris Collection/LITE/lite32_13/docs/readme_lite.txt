Heboris[ヘボリス] 改変バージョン LITE

更新履歴はuphistory_lite.txtにあります。

【インストール方法】
解凍したファイルのうち

replayフォルダ
scriptフォルダ
spiフォルダ
ssフォルダ
stageフォルダ
back.dat
graphics.dat
heboris.ini
stage.dat

を、ヘボリスのフォルダにコピーします。
（上書き確認が出た場合は全て上書きしてください）

【重要】
・今までセッティングユーティリティで行っていた設定の大半は
　タイトル内の「CONFIG」からでしか行えません。（設定内容はsetting.txtにて）

・Windows XPおよびVistaで動かすには、以下の手順で互換モードを有効にしてください。
　１．HEBORIS.EXEを右クリックし、[ショートカットの作成] をクリックします。
　２．作成されたショートカットを右クリックし、[プロパティ] をクリックします。
　２．[互換性] タブの [互換モードでこのプログラムを実行する] をクリックし
　　　「Windows NT 4」以外のいずれかのオプションをクリックします。
　３．OKボタンをクリックします。
　４．遊ぶときは作成されたショートカットをダブルクリックしてください。

【オリジナル版からの追加・変更事項】
　●ゲームモード
　　・BEGINNERモード
　　　　規定レベルになるまでスコアを稼ぐモードです。落下速度は遅めで初心者向けです。2種類のゲームがあります。
　　　　TAMAYA：ラインを消すと花火が上がり、花火数がそのままスコアになります。
　　　　　　　　レベル200でクリアですが、エンディング中にも花火は上がりつづけます。
　　　　NOVICE：ラインを消しても花火は上がりません。スコア計算は他のモードと似た方式が使われています。
　　　　　　　　レベル99と199ではレベルストップが発生しません。また、レベル100と200でお助けアイテムが登場します。
　　　　　　　　レベル300に到達すればクリアです。5分以内にクリアするとタイムボーナスが入ります。

　　・MASTERモード
　　　　ひたすらラインを消してレベル999を目指すメインモードです。
　　　　段位認定機能があり、現在の段位はプレイヤーの腕前に応じて変わっていきます。
　　　　以下の7種類から難易度を選ぶことができます。
　　　　EASY　　　：簡単な難易度です。スコアに応じて段位が上がっていきます。レベル500で恐怖の最高速になります。
　　　　NORMAL　　：普通の難易度です。レベル500で恐怖の最高速に突入し、その後も固定時間などが短くなっていきます。
　　　　HARD　　　：NORMALよりも高難易度です。現在の段位が表示されず、段位が変わる仕組みも異なります。
　　　　　　　　　　いいプレイをすればするほど早く速度が上昇し、最短ではレベル300で最高速に突入できます。
　　　　20G-EASY　：いきなり最高速の状態でEASYを遊びます。このモードではレベルアップによるスピードの変化はありません。
　　　　20G-NORMAL：いきなり最高速の状態でNORMALを遊びます。後半になるまで固定時間などは変わりません。
　　　　20G-HARD　：いきなり最高速の状態でHARDを遊びます。プレイヤーの腕前が高ければ前半から固定時間が短くなっていきます。
　　　　HEBO+　　 ：時々下から灰色のお邪魔ラインがせり上がってくるモードです。
　　　　　　　　　　レベル500で最高速になりますが、そのあとも固定時間は一定のままです。
　　　　　　　　　　このモードに段位認定機能はありません。

　　・DEVILモード
　　　　ブロックの落下速度が非常に早い上級者向けモードです。以下の3種類から難易度を選ぶことができます。
　　　　NORMAL：最高速の状態で始まり、少しずつ固定時間などが早くなっていきます。
　　　　　　　　規定時間内にレベル500に到達できないと強制終了です。レベル999に到達するとクリアです。
　　　　HARD　：NORMALよりも難易度が高く、レベル500〜999では定期的にせり上がりが発生します。
　　　　　　　　レベル1000に到達すればせり上がりは終わりますが、その代わり別の恐ろしい仕掛けが発動します。
　　　　DOOM　：基本ルールはHARDと同じです、が…

　　・TOMOYOモード
　　　　フィールド上に配置されたプラチナブロックを時間内に全て消せばステージクリアとなるモードです。
　　　　制限時間にはステージごとのタイム（１面あたり１分）と、全体を通してのリミットタイムがあります。
　　　　ステージタイムがなくなってもゲームオーバーにはならず、次の面がスタートします。
　　　　リミットタイムがなくなるとゲームオーバーです。
　　　　リミットタイムはプラチナブロック消去かステージクリア時の成績で回復します。
　　　
　　　　このモードでは、4つのコースの中から好きなコースを選んでプレイできます。
　　　　NORMAL　　：全20面で、成績次第ではさらにEXステージをプレイできます。リミットタイムは3分です。
　　　　EHEART　　：全18面で、ステージごとのタイムは無制限です。リミットタイムは20分です。
　　　　TRAGET　　：全21面で、ステージごとのタイムは無制限です。リミットタイムは3分です。
　　　　FLASH　　 ：全100面で、他のコースとはルールが異なります。
　　　　　　　　　　画面下にボーナス点が表示され、ブロックが操作可能な状態ではどんどん減っていきます。
　　　　　　　　　　ステージクリアすると残ったボーナス点がスコアに加算されます。
　　　　　　　　　　最初に1〜90の範囲で開始ステージを選ぶことが可能で
　　　　　　　　　　クリアすると次のステージを4つから選ぶことが出来ます。
　　　　　　　　　　途中、ステージ90をクリアしないと91〜100面は遊べません。
　　　　EDIT　　　：STAGE67以降の、自作ステージでプレイします。
　　　　　　　　　　事前にステージデータを作成しておく必要があります。
　　　　　　　　　　ステージを作成するには、TOMOYOモードを選んだ状態でC+Aを押し、EDIT MODEを選択してAを押してください。
　　　　　　　　　　フィールドエディット画面ではCを押しながら左右でブロックの色を選び、Aで配置、Dで消去できます。
　　　　FLASH-EDIT：FLASHコースの自作ステージをプレイします。
　　　　　　　　　　これも事前にステージデータを作成しておく必要があります。
　　　　　　　　　　ステージを作成するには、TOMOYOモードを選んだ状態でC+Aを押し、FLASH EDITを選択してAを押してください。

　　・ACEモード
　　　　制限時間内にラインを消していくモードです。
　　　　レベルアップ方式が独特のもので、ブロックを置くだけではレベルアップは発生しません。
　　　　10ライン消すたびにレベルが1つ上昇し、制限時間が回復します。
　　　　NORMAL〜ANOTHER2では150ライン、BASIC〜VOIDでは200ライン消去するとクリアとなります。
　　　　方向キーの左右で難易度を選べます。
　　　　NORMAL　　：落下速度が遅く制限時間も長い簡単なモードです。
　　　　HI-SPEED 1：落下速度がNORMALの中盤あたりのスピードから始まります。
　　　　HI-SPEED 2：落下速度が常に20Gです。このモードではレベルアップによるスピードの変化はありません。
　　　　ANOTHER　 ：落下速度が常に20Gです。先に進むほどブロックが固定されるまでの時間も短くなっていきます。
　　　　ANOTHER2　：最初から最後までANOTHERの最高速です。このモードではレベルアップによるスピードの変化はありません。
　　　　BASIC　　 ：スピードが遅い状態から始まりますが、いきなり制限時間が少ない状態で始まります。
　　　　HELL　　　：スピードはANOTHER2と同じですが、途中でHIDDENが始まったり、[]が出てきたりします。
　　　　HELL-X　　：HELLとスピードや制限時間は同じですが、いきなり[]が出現します。さらに進むと…
　　　　VOID　　　：　　　　　。

　　・OLD STYLEモード
　　　　このモードではHOLDや即落下、先行回転などが使えなくなります。壁際でブロックを回転できなくなります。
　　　　エンディングはなく、詰まるまで永遠に続けることができます。
　　　　HANDHELD：ブロックの絵柄がモノクロになります。10ラインごとにレベルアップします。
　　　　ARCADE　：21段目に天井が出現し、ブロックが出現した直後は回転できません。
　　　　　　　　　4ライン消す、またはしばらくラインを消さないでいるとレベルアップします。

　　・FINALモード
　　　　ヘボリスの最果てに挑戦する超上級者向けモードです。DEVILモードを上回る速度でブロックが降ってきます。
　　　　あなたはどこまで耐えられますか？

　　・MARATHONモード
　　　　スコアアタックモードです。３種類のゲームが遊べます。
　　　　NORMAL：LV15をクリアするまで得点を稼ぐモード
　　　　SQUARE：4x4の正方形を作って消すと高得点になるモード
　　　　ONI　 ：ブロックの落下速度が速い上級者向けのエンドレスモード

　　・SIMPLEモード
　　　　自分で好きな速度を設定して、40ライン消すまでの時間、または2分間に得た得点を競うモードです。
　　　　ランキングは5位まで記録され、使った速度も表示されます。
　　　　このモードではレベルアップによるスピードの変化はありません。
　　　　40LINES　　　　　 ：40ライン消すまでの時間を競う
　　　　ULTRA　　　　　　 ：2分以内にできるだけ得点を稼ぐ
　　　　40LINES ROT. RELAY：3つのルールで40LINESに挑戦（ランキングなし）
　　　　ULTRA ROT. RELAY　：3つのルールでULTRAに挑戦（ランキングなし）

　　・VERSUSモード
　　　　２人で対戦するモードです。コンピュータと対戦することも可能です。
　　　　せり上がりやアイテムを駆使して相手をゲームオーバーにさせるか、先に規定レベルに到達すれば勝利です。

　　・MISSIONモード
　　　　指定された課題を次々とクリアしていくモードです。
　　　　自分で作ることも出来ます。（mission.txt参照）

　　・PRACTICEモード
　　　　落下速度・固定までの時間など、様々な設定を変更してプレイすることが出来ます。
　　　　このモードではレベルアップによるスピードの変化はありません。
　　　　なお、SETTYAKUの値を99に設定すると、固定までの時間が無限になります。20Gの練習にオススメです。
　　　　メニューでDボタンを押すとフィールドエディット画面になります。
　　　　Aボタンでブロックを配置、Bボタンでメニューに戻る、Cを押しながら左右で配置するブロックの種類を選択
　　　　Dボタンでブロックを消去します。

　●システム
　　・HOLD
　　　 画面左上のHOLD欄にブロックを保留できる機能です。
　　　 保留したブロックは操作中のブロックと入れ替えることができますが、
　　　 一度入れ替えたブロックは、次のブロックが出現するまでHOLD欄に入れることはできません。

　　・回転法則選択
　　　 今までのルール（CLASSICルール）に加え、新たに9つのルールが選べるようになりました。
　　　　・CLASSIC+ルール
　　　　　　基本はHEBORISルールと一緒ですが、水色(T字)・赤(棒)の回転がより柔軟になりました。
　　　　・MODERNルール
　　　　　　CLASSIC・CLASSIC+ルールとは大きく異なります。
　　　　　　壁蹴り・床蹴りが起こりやすく、操作次第ではブロックを駆け上がることも可能です。
　　　　　　また、下入力ではブロックを接着させることができず、上を入れたとき瞬間落下と同時に接着されます。
　　　　　　回転したり移動したりするだけで固定されるまでの時間が延長されるので、難易度は低めです。
　　　　　　なお、デフォルトではブロックの色が他２つとは異なり、さらに回転方向も逆ですが、
　　　　　　これらは両方ともカスタマイズできます。
　　　　・MODERN+ルール
　　　　　　基本はMODERNルールと一緒ですが、回転ボタンを連打しているとなかなか接着されません。
　　　　　　ただし、高速落下の速度が落ちています。初心者に最適です。
　　　　・MIX-Aルール
　　　　　　回転法則だけがCLASSIC+ルールで、あとはMODERN+ルールという奇抜なルールです。
　　　　・MIX-Bルール
　　　　　　MIX-Aルールの上下の操作をCLASSIC+ルール形式にした以外に違いはありません。
　　　　　　CLASSIC系列の練習に最適です。
　　　　・GUIDELINEルール
　　　　　　基本はMODERN+ルールと一緒ですが、回転ボタンを連打している限り永遠に固定されません。
　　　　　　また、ブロックを置いたあとに待ち時間なしに次のブロックが出現します。
　　　　・SPECIAL-Sルール
　　　　　　基本はMODERN+ルールと一緒ですが、上下入力がCLASSIC+と同じになっています。
　　　　・SPECIAL-Dルール
　　　　　　CLASSIC系に似ているものの、一部が異なる特有の回転法則が使われます。
　　　　　　強力な回転入れや手動ARE（ブロック出現待ち時間）スキップなどの独自の要素を多数搭載しています。
　　　　・CUSTOMルール
　　　　　　設定画面で特徴を変えることができるルールです。

　　・レベルアップ方式
　　　 ブロック出現・ライン消去でレベルが上がります。デフォルトでは3・4列消しでボーナスが入ります。
　　　 ACEモードなどでは10ライン消すたびにレベルが上がります。

　　・新先行回転入力
　　　 ブロックの先行回転入力が4種類（大きく分けて2種類）になりました。
　　　 CONFIG画面で変更できます。（デフォルトはオリジナル版と同じです。）

　　・180度回転
　　　 CONFIG画面で有効にすると、Cボタンを押したときの回転が「180度回転」になります。
　　　 使い方次第ではとんでもない所にブロックをねじ込む事も可能です。

　　・メダル表示
　　　 プレイの状況に応じて4種のメダルを表示します。（AC・SK・CO・ST）
　　　 また、同じ種類のメダルでも金・銀・銅の3色があります。

　　・タイムトライアルモード＆スタッフロール
　　　 モードセレクトでDボタンを押さないでAボタンを押すと、モードごとの規定Lv到達時間を競うモードになります。
　　　 BEGINNERはLv200、MASTERはLv999、DEVILはLv1300に到達するとクリアですが、
　　　 BEGINNER以外のモードでは規定タイムを突破しないとLv500（DEVILのみLv1000でも）で強制終了です。
　　　 なお、規定タイムはheboris.iniで設定可能です。
　　　 クリアするとスタッフロールが始まり、1分間耐え切ると完全クリアとなります。
　　　 なお、順位はスコアよりもグレードやタイムが優先されます。
　　　 また、同じタイムでもスタッフロールをクリアした方が順位は上になります。

　　・せり上がり
　　　 一部の1人用モードでもせり上がりが発生します。
　　　 （DEVILモードのLV500以降、HEBO+モード）
　　　 せり上がるラインの形状や、せり上がり間隔には法則性があります。

　　・[]ブロック
　　　 DEVIL-HARDまたはDEVIL-DOOMモードで頑張ってLV1000まで行くか、ACE-HELL-XやFINALモードを選ぶと…？

　　・裏段位
　　 　□□□□　□□□□□
　　　 □□□　□□□□□□
　　　 □□　□□□□□□□
　　　 □　□□□□□□□□
　　　　 □□□□□□□□□
　　　 このように積んでいき、5段以上積むことに成功すると窒息後のリザルト画面に裏段位が表示されます。

　　・オプション画面
　　　 SOLO MODEのモードセレクト画面でCを押しながらAを押すとオプション画面が表示され
　　　 ビッグモードやアイテムモードを使うことができます。

　　・捨てゲー（GIVEUP）機能
　　　 事前に設定した捨てゲーキーを押すか、ポーズをかけてA+Bを同時押しすると
　　　 現在のゲームを強制終了してモードセレクト画面に戻ることができます。

　　・リプレイ追記もどき機能
　　　 リプレイ中にDボタンを押すと、それ以降は自分で操作できます。
　　　 この機能を使った場合はランキングには載りませんが、改変したプレイをリプレイに保存することができます。

　　・Cボタンを使った小技
　　　 メニューでCを押しながら左か右を押すと、通常よりも早く値の変更ができます。
　　　 ポーズ中のとき、Cを押している間は文字が消えます。

【軽くするには？】
・セッティングユーティリティでスクリーンモードを「ウィンドウモード (320x240)」にする
・Windows側の「画面のプロパティ」で「画面の色」を「High Color (16ビット)」にする
・CONFIG画面のGAME SETTINGでMAX PLAYERをSINGLEにする
・CONFIG画面のDISPLAY SETTINGでBREAK EFFECTを「NO EFFECT」または「SHATTER (OLD)」にする
・CONFIG画面のDISPLAY SETTINGでBACKGROUNDをOFFにする
