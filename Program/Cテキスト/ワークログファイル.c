'ワークログファイル
'
'-----------------------------------------------------------------------------------------------------------------------------
'<IOMAP.XLS / パネルインターフェース> 
'----------------------------------
'【グローバルラベル】
'pnlPBel今日	ビット	MR00100
'pnlPBel日	ビット	MR00101
'pnlPBel週	ビット	MR00102
'pnlPBel月	ビット	MR00103
'pnlPBel左移動	ビット	MR00104
'pnlPBel右移動	ビット	MR00105
'pnlPBel下移動	ビット	MR00106
'pnlPBel下限移動	ビット	MR00107
'pnlPBel上移動	ビット	MR00108
'pnlPBel上限移動	ビット	MR00109
'pnlPBel更新	ビット	MR00110
'pnlPBelALL	ビット	MR00111
'pnlPBel運転中	ビット	MR00112
'pnlPBel自動モード	ビット	MR00113
'pnlPBelテスト運転	ビット	MR00114
'pnlPBel非常停止	ビット	MR00115
'pnlPBel前処理運転中	ビット	MR00200
'init今日	ビット	MR00201
'init日	ビット	MR00202
'init週	ビット	MR00203
'init月	ビット	MR00204
'		
'Filewritestep	1ワード符号なし整数	DM1000
'Filereadstep	1ワード符号なし整数	DM1001
'ErrAnalyzestep	1ワード符号なし整数	DM1002
'ErrAnalyzeStatcheckBit	1ワード符号なし整数	DM1003
'ErrAnlyzeTotalCnt	1ワード符号なし整数	DM1004
'dspErrAnalOffset	1ワード符号なし整数	DM1005
'el現在ページNO	1ワード符号なし整数	DM1006
'dspErrAnalIndex	1ワード符号なし整数	DM1007
'wFilewritestep	1ワード符号なし整数	DM1008
'		
'setFindStart年月日	1ワード符号なし整数[6]	DM1010
'setFindEnd年月日	1ワード符号なし整数[6]	DM1020
'FindStart年月日	1ワード符号なし整数[6]	DM1030
'FindEnd年月日	1ワード符号なし整数[6]	DM1040 
'ErrAnalyzeCode	1ワード符号なし整数[50]	DM1100
'ErrAnalyzePersent	1ワード符号なし整数[50]	DM1150
'ErrAnalyzeCnt	1ワード符号なし整数[50]	DM1200
'----------------------------------------------------------------------------------
'【ローカルラベル】
'FileErr	ビット[2]
'WriteFileName	文字列[40]
'WriteSec	2ワード符号なし整数
'WriteSecStr	文字列[20]
'WriteStatstr	文字列[20]
'WriteStepstr	文字列[500]
'WriteStr	文字列[600]
'realFileErr	ビット[2]
'realFilewritestep	1ワード符号なし整数
'realWriteFileName	文字列[40]
'realWriteSec	2ワード符号なし整数
'realWriteSecStr	文字列[20]
'realWriteStatstr	文字列[200]
'realWriteStepstr	文字列[300]
'realWriteStr	文字列[600]
'realインターバル	タイマ
'反転残数	1ワード符号なし整数
'-----------------------------------------------------------------------------------------------------------------------------
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
	wFilewritestep=0
	realFilewritestep=0
end if
'-----------------------------------------------------------------------------------------------------------------------------
if ldp(自動搬送ErrStep>0 or OtherErrStep>0 or 計量ErrStep>0) then
	WriteStatstr="エラー発生"
	wFilewritestep=1

else if ldp(前処理工程AutoRun) then
	WriteStatstr="送米開始"
	wFilewritestep=1

else if ldp(前処理完了) then
	WriteStatstr="送米完了"
	wFilewritestep=1

else if ldp(IND_配米中 and (浸漬タンクAユニット許可 or 浸漬タンクBユニット許可) ) then
	WriteStatstr="配米開始"
	wFilewritestep=1

else if ldp(配米終了フラグ) then 
	WriteStatstr="配米終了"
	wFilewritestep=1

else if ldp(IND_炊飯完了) then
	WriteStatstr="炊飯完了"
	wFilewritestep=1
end if

'-----------------------------------------------------------------------------------------------------------------------------
'生産情報ファイル書込み

	select case wFilewritestep
	'----------------------------------------------------------------------
	case 1
		MMKDIR("UserDoc",FileErr)
		INC(wFilewritestep)

	case 2
		if FileErr[0] then '完了
			INC(wFilewritestep)
		end if
	
	case 3
		if FileErr[1] then '異常終了
		end if
		INC(wFilewritestep)

	
	'----------------------------------------------------------------------
	case 4
		'-------------------------------
		'運転状態
		'イベントにより設定済み
		'-------------------------------
		'生産情報
		WriteStepstr="アイテム"+","+EM4001.T+","
		WriteStepstr=WriteStepstr+"配米総数"+","+DASC(DM_配米総数.U,1)+","
		WriteStepstr=WriteStepstr+"設定水量"+","+DASC(DM_設定水量基準値.U,1)+","
		WriteStepstr=WriteStepstr+"水量補正値"+","+DASC(DM_水量補正値,1)+"," '+/- あり
		WriteStepstr=WriteStepstr+"Aタンク送米設定値" +","+ DASC(DM_Aタンク設定値.U,1)+","
		WriteStepstr=WriteStepstr+"Aタンク送米現在値" +","+ DASC(DM_Aタンク送米現在値.U,1)+","
		WriteStepstr=WriteStepstr+"Bタンク送米設定値" +","+ DASC(DM_Bタンク設定値.U,1)+","
		WriteStepstr=WriteStepstr+"Bタンク送米現在値" +","+ DASC(DM_Bタンク送米現在値.U,1)+","
		WriteStepstr=WriteStepstr+"反転数"+","+DASC(DM_排出総数.U,1)
		'----------------------------------------------------------------------
		'ファイル書込み文字列		
		WriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '日付
		WriteStr.T=WriteStr.T+WriteStatstr+"," '運転状態
		WriteStr.T=WriteStr.T+WriteStepstr ''生産情報
		'-------------------------------
		WriteStr.T=WriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'ファイル書込み
		WriteFileName.T="UserDoc\"+"生産情報"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" 'ファイル名
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)

		INC(wFilewritestep)
	
	case 5
		if FileErr[0] then '完了
			INC(wFilewritestep)
		end if
	
	case 6
		if FileErr[1] then '異常終了
		end if
		INC(wFilewritestep)

	case 7
		
		wFilewritestep=0
		
	end select

'-----------------------------------------------------------------------------------------------------------------------------
'現在情報ファイル書込み 

if 0 then 'SDの耐久性保持のため休止中
	tmr(CM703>=5 and CM703<12,realインターバル,200) '5:00 ~ 11:59 まで書込み

	if ldp(realインターバル.B) then
		res(realインターバル)
		realFilewritestep=1
	end if
end if

	'---------------------------------------
	if 自動搬送ErrStep>0 or OtherErrStep>0 or 計量ErrStep>0 then
		realWriteStatstr="エラー発生中"+","
	else if EmgFlg then
		realWriteStatstr="非常停止中"+","	
	else
		realWriteStatstr="エラー無し"+","
	end if
	'---------------------------------------
	if 前処理工程AutoRun then
		realWriteStatstr=realWriteStatstr+"送米中"+","
	else
		realWriteStatstr=realWriteStatstr+"送米停止中"+","
	end if
	'---------------------------------------
	if 自動搬送AutoRun then
		realWriteStatstr=realWriteStatstr+"コンベア運転中"+","
	else
		realWriteStatstr=realWriteStatstr+"コンベア停止中"+","
	end if	
	'---------------------------------------
	反転残数=DM_配米総数-DM_排出総数
	
	if 運転準備中 then	
		realWriteStatstr=realWriteStatstr+"運転準備中"+","
	else if IND_配米中 then
		realWriteStatstr=realWriteStatstr+"配米中"+","
	else if IND_炊飯中 then
		realWriteStatstr=realWriteStatstr+"炊飯中"+","
	else if not(IND_配米中) and not(IND_炊飯中) and not(IND_炊飯完了) and 反転残数>0 then
		realWriteStatstr=realWriteStatstr+"反転搬送中"+","
	else if IND_炊飯完了 then
		realWriteStatstr=realWriteStatstr+"炊飯完了"+","
	else
		realWriteStatstr=realWriteStatstr+"工程完了"+","	
	end if
	'---------------------------------------
	if 自動搬送AutoMode then
		realWriteStatstr=realWriteStatstr+"自動"+","
	else
		realWriteStatstr=realWriteStatstr+"手動"+","
	end if
	'---------------------------------------
	if テスト運転 then
		realWriteStatstr=realWriteStatstr+"テスト運転=ON
	else
		realWriteStatstr=realWriteStatstr+"テスト運転=OFF"
	end if
	
	
	'----------------------------------------------------------------------
	select case realFilewritestep

	case 1
		MDEL("リアルタイム情報.CSV",realFileErr)
		INC(realFilewritestep)

	case 2
		if realFileErr[0] then '完了
			INC(realFilewritestep)
		end if
	
	case 3
		if realFileErr[1] then '異常終了
		end if
		INC(realFilewritestep)

	
	'----------------------------------------------------------------------
	case 4
		'-------------------------------
		'生産情報
		realWriteStepstr=realWriteStepstr+"配米総数"+","+DASC(DM_配米総数.U,1)+","
		realWriteStepstr=realWriteStepstr+"設定水量"+","+DASC(DM_設定水量基準値.U,1)+","
		realWriteStepstr=realWriteStepstr+"水量補正値"+","+DASC(DM_水量補正値,1)+"," '+/- あり
		realWriteStepstr="Aタンク送米設定値" +","+ DASC(DM_Aタンク設定値.U,1)+","
		realWriteStepstr=realWriteStepstr+"Aタンク送米現在値" +","+ DASC(DM_Aタンク送米現在値.U,1)+","
		realWriteStepstr=realWriteStepstr+"Bタンク送米設定値" +","+ DASC(DM_Bタンク設定値.U,1)+","
		realWriteStepstr=realWriteStepstr+"Bタンク送米現在値" +","+ DASC(DM_Bタンク送米現在値.U,1)+","
		realWriteStepstr=realWriteStepstr+"反転数"+","+DASC(DM_排出総数.U,1)
		'----------------------------------------------------------------------
		'ファイル書込み文字列		
		realWriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '日付
		realWriteStr.T=realWriteStr.T+realWriteStatstr+"," '運転状態
		realWriteStr.T=realWriteStr.T+realWriteStepstr '生産情報
		'-------------------------------
		realWriteStr.T=realWriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'ファイル書込み
		realWriteFileName.T="リアルタイム情報.CSV" 'ファイル名
		MPRINT(realWriteFileName.T,realWriteStr.T,realFileErr)

		INC(realFilewritestep)
	
	case 5
		if realFileErr[0] then '完了
			INC(realFilewritestep)
		end if
	
	case 6
		if realFileErr[1] then '異常終了
		end if
		INC(realFilewritestep)

	case 7
		realFilewritestep=0	
	end select

'-----------------------------------------------------------------------------------------------------------------------------
