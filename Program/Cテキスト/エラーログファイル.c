'エラーログファイル

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
'FindEndSec	2ワード符号なし整数
'FindStartSec	2ワード符号なし整数
'OffsetAddres	2ワード符号なし整数
'ReadCnt	1ワード符号なし整数
'ReadErrCode	2ワード符号なし整数
'ReadErrCodeStr	文字列[20]
'ReadFileName	文字列[40]
'ReadSec	2ワード符号なし整数
'ReadSecStr	文字列[20]
'ReadStr	文字列[1500]
'StackEnablebit	ビット
'WriteAlmstr	文字列[40]
'WriteErrAddres	2ワード符号なし整数
'WriteErrCode	2ワード符号なし整数
'WriteErrCodeStr	文字列[20]
'WriteFileName	文字列[40]
'WriteSec	2ワード符号なし整数
'WriteSecStr	文字列[20]
'WriteStatstr	文字列[100]
'WriteStepstr	文字列[1000]
'WriteStr	文字列[1500]
'anloop	1ワード符号なし整数
'dmystr	文字列[25]
'elFindStart年月日	1ワード符号なし整数[6]
'elStatBitstr	文字列[20]
'elテスト運転	1ワード符号なし整数
'elテスト運転str	文字列[20]
'el前処理運転中	1ワード符号なし整数
'el前処理運転中str	文字列[20]
'el自動モード	1ワード符号なし整数
'el自動モードstr	文字列[20]
'el運転中	1ワード符号なし整数
'el運転中str	文字列[20]
'el非常t停止str	文字列[20]
'el非常停止	1ワード符号なし整数
'initFileread	ビット
'linecnt	1ワード符号なし整数
'loop	1ワード符号なし整数
'readerr	ビット[4]
'readpar	1ワード符号なし整数[4]
'readparstak	2ワード符号なし整数
'tmpreadstr	文字列[100]
'-----------------------------------------------------------------------------------------------------------------------------
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
	Filewritestep=0
	Filereadstep=0
	ErrAnalyzestep=0
end if

'-----------------------------------------------------------------------------------------------------------------------------
'エラーファイル書込み

	select case Filewritestep
	'----------------------------------------------------------------------
	case 1
		MMKDIR("Machine",FileErr)
		INC(Filewritestep)

	case 2
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 3
		if FileErr[1] then '異常終了
		end if
		INC(Filewritestep)

	
	'----------------------------------------------------------------------
	case 4
		if 0 then 'テスト用アドレス
		    adrset(almRS1_水タンク上限センサー,WriteErrAddres)
		    WriteAlmstr="almRS1_水タンク上限センサー"
			
			前処理工程step=120
		end if

		'-------------------------------
		if alm渋滞警報入口 then
			WriteErrCode=6901
		else if alm渋滞警報出口 then
			WriteErrCode=6902
		else 
			ADRSET(R82000,OffsetAddres) 'almxxxxの先頭アドレス
			WriteErrCode=(WriteErrAddres-OffsetAddres)+7001
		end if
		WriteErrCodeStr.T=DASC(WriteErrCode.D,1)
		WriteSec=SEC(CM700)
		WriteSecStr.T=DASC(WriteSec.D,1)		
		'-------------------------------
		if 自動搬送AutoMode then
			WriteStatstr="自動"+","
		else
			WriteStatstr="手動"+","
		end if
		if 自動搬送step>0 or OtherStep>0 or 前処理工程step>0 then
			WriteStatstr=WriteStatstr+"運転中"+","
		else
			WriteStatstr=WriteStatstr+"停止中"+","
		end if
		if テスト運転 then
			WriteStatstr=WriteStatstr+"テスト運転"+","+"ON"+","
		else
			WriteStatstr=WriteStatstr+"テスト運転"+","+"OFF"+","
		end if
		if EmgFlg then
			WriteStatstr=WriteStatstr+"非常停止"+","+"ON"+","
		else
			WriteStatstr=WriteStatstr+"非常停止"+","+"OFF"+","
		end if
		if 前処理工程step<>0 then
			WriteStatstr=WriteStatstr+"前処理運転中"+","+"ON"
		else
			WriteStatstr=WriteStatstr+"前処理運転中"+","+"OFF"
		end if
		'-------------------------------
		'運転step WriteStep 20x30
		WriteStepstr="前処理工程step"+","+DASC(前処理工程step.U,1)+","
		WriteStepstr=WriteStepstr+"計量step"+","+DASC(計量step.U,1)+","
		WriteStepstr=WriteStepstr+"洗米step"+","+DASC(洗米step.U,1)+","
		WriteStepstr=WriteStepstr+"浸漬タンクAユニットstep"+","+DASC(浸漬タンクAユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"浸漬タンクBユニットstep"+","+DASC(浸漬タンクBユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"計水ユニットstep"+","+DASC(計水ユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"ならし装置step"+","+DASC(ならし装置step.U,1)+","
		WriteStepstr=WriteStepstr+"蓋被せユニットstep"+","+DASC(蓋被せユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"蓋取りユニットstep"+","+DASC(蓋取りユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"ごはん検知step"+","+DASC(ごはん検知step.U,1)+","
		WriteStepstr=WriteStepstr+"バキュームユニットstep"+","+DASC(バキュームユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"ほぐし機Aユニットstep"+","+DASC(ほぐし機Aユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"ほぐし機Bユニットstep"+","+DASC(ほぐし機Bユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアAstep"+","+DASC(搬送コンベアAstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアBstep"+","+DASC(搬送コンベアBstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアCstep"+","+DASC(搬送コンベアCstep.U,1)+","
		WriteStepstr=WriteStepstr+"釜送りコンベアstep"+","+DASC(釜送りコンベアstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアDstep"+","+DASC(搬送コンベアDstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアEstep"+","+DASC(搬送コンベアEstep.U,1)+","
		WriteStepstr=WriteStepstr+"搬送コンベアFstep"+","+DASC(搬送コンベアFstep.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄入口搬送step"+","+DASC(洗浄入口搬送step.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄入口リフトstep"+","+DASC(洗浄入口リフトstep.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄ユニットstep"+","+DASC(洗浄ユニットstep.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄タンクstep"+","+DASC(洗浄タンクstep.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄コンベア搬送step"+","+DASC(洗浄コンベア搬送step.U,1)+","
		WriteStepstr=WriteStepstr+"洗浄出口搬送step"+","+DASC(洗浄出口搬送step.U,1)+","
		WriteStepstr=WriteStepstr+"釜フタ昇降装置Bstep"+","+DASC(釜フタ昇降装置Bstep.U,1)
		'----------------------------------------------------------------------
		'ファイル書込み文字列		
		WriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '日付
		WriteStr.T=WriteStr.T+WriteAlmstr+"," 'アラーム名称
		WriteStr.T=WriteStr.T+WriteStatstr+"," '運転状態
		WriteStr.T=WriteStr.T+WriteStepstr 'ユニットSTEP
		'-------------------------------
		WriteStr.T=WriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'ファイル書込み
		WriteFileName.T="Machine\"+"ERRLOG"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" 'ファイル名
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)

		INC(Filewritestep)
	
	case 5
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 6
		if FileErr[1] then '異常終了
		end if
		INC(Filewritestep)

	'----------------------------------------------------------------------
	case 7
		MMKDIR("Machine",FileErr)
		INC(Filewritestep)

	case 8
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 9
		if FileErr[1] then '異常終了
		end if
		INC(Filewritestep)

	'----------------------------------------------------------------------
	case 10
		'-------------------------------
		if 自動搬送AutoMode then
			elStatBitstr="1"+","
		else
			elStatBitstr="0"+","
		end if
		if 自動搬送step>0 or OtherStep>0 or 前処理工程step>0 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if テスト運転 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if EmgFlg then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if 前処理工程step<>0 then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if 
		if 自動搬送AutoRun then 'これはフォーマット上の予備です
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if 自動搬送AutoRun then
			elStatBitstr=elStatBitstr+"1"+","
		else
			elStatBitstr=elStatBitstr+"0"+","
		end if
		if 自動搬送AutoRun then
			elStatBitstr=elStatBitstr+"1"
		else
			elStatBitstr=elStatBitstr+"0"
		end if
		'----------------------------------------------------------------------
		WriteStr.T=WriteSecStr.T+","+WriteErrCodeStr.T+","+elStatBitstr.T
		WriteStr.T=WriteStr.T+CHR($0D)
		'----------------------------------------------------------------------
		'ファイル書込み
		WriteFileName.T="Machine\"+"ERRAnal"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" 'ファイル名
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)
	
		INC(Filewritestep)
		
	case 11
		if FileErr[0] then '完了
			INC(Filewritestep)
		end if
	
	case 12
		if FileErr[1] then '異常終了
		end if
		
		Filewritestep=0
		
	end select

'-----------------------------------------------------------------------------------------------------------------------------
'エラーファイル読み出し

'ErrAnalxxx.CSV
'Lineフレーム		6000181416"",1234"",1"",1"",1"",1"",1"",1"",1"",1""cr
'                     (11),       (5),  (2),(2),(2),(2),(2),(2),(2),(2),1 = 
	select case Filereadstep
	
	case 1

		FindStartSec=sec(FindStart年月日)
		FindEndSec=sec(FindEnd年月日)
	
		ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindStart年月日[0])+STR(FindStart年月日[1])+"."+"CSV"
		initFileread=ON
		linecnt=0
		readpar[0]=0  '最初の行から読込
		readpar[1]=0  '最初の行から読込
		readpar[2]=50 '最大読込文字列

		'クリア
		for loop=0 to 49 step 1
			ErrAnalyzeCode[loop]=0
			ErrAnalyzeCnt[loop]=0
		next		
		
		INC(Filereadstep)
	
	case 2
	
		if initFileread or (readerr[0] and ErrAnalyzestep=0) then
			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
				inc(linecnt)
				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el自動モードstr,el運転中str,elテスト運転str,el非常t停止str,el前処理運転中str,el自動モードstr,el自動モードstr,el自動モードstr)
				if ReadCnt>=7 then
					ReadSec.D=RDASC(ReadSecStr)
					ReadErrCode.D=RDASC(ReadErrCodeStr)
					if LEN(el自動モードstr)>0 then
						el自動モード.U=RDASC(el自動モードstr)
					else
						el自動モード=0
					end if
					
					if LEN(el運転中str)>0 then
						el運転中.U=RDASC(el運転中str)
					else
						el運転中=0
					end if
					
					if LEN(elテスト運転str)>0 then
						elテスト運転.U=RDASC(elテスト運転str)
					else 
						elテスト運転=0
					end if
					
					if LEN(el非常t停止str)>0 then
						el非常停止.U=RDASC(el非常t停止str)
					else
						el非常停止=0
					end if
					
					if LEN(el前処理運転中str)>0 then
						el前処理運転中.U=RDASC(el前処理運転中str)
					else
						el前処理運転中=0
					end if					
					StackEnablebit=not(pnlPBel自動モード) or (pnlPBel自動モード and el自動モード=1) '自動モードのみ
					StackEnablebit=StackEnablebit and (not(pnlPBel運転中) or (pnlPBel運転中 and el運転中=1)) '運転中のみ
					StackEnablebit=StackEnablebit and (not(pnlPBelテスト運転) or (pnlPBelテスト運転 and elテスト運転=0)) 'テスト運転除外
					StackEnablebit=StackEnablebit and (not(pnlPBel非常停止) or (pnlPBel非常停止 and el非常停止=0)) '非常停止除外
					StackEnablebit=StackEnablebit and (not(pnlPBel前処理運転中) or (pnlPBel前処理運転中 and el前処理運転中=0)) '前処理運転除外
					if pnlPBelALL then
						StackEnablebit=ON
					end if
					'----------------------------------------
					'エラー統計プログラム	
					if ReadSec>=FindStartSec and ReadSec<=FindEndSec then
						if StackEnablebit then
							for loop=0 to 49 step 1
								if ErrAnalyzeCode[loop]=0 or ErrAnalyzeCode[loop]=TOU(ReadErrCode) then
									ErrAnalyzeCode[loop]=TOU(ReadErrCode)
									INC(ErrAnalyzeCnt[loop])
									break
								end if
							next
						end if
					end if
					'----------------------------------------
				end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					ErrAnalyzestep=1
					inc(Filereadstep)		
				end if
				
			end if
		end if

	case 3
		'週検索で月をまたぐ場合にはFindEnd年月日の月のファイルを1日から指定日まで再集計する
		' FindStart年月日 2018年12月29日  FindEnd年月日 2019年1月5日
		' (case1,2) 2018年12月29日~末日（集計）(case3,4) 2019年1月1日~2019年1月5日（再集計）
		
		
		if not(pnlPBel週) or (pnlPBel週 and FindStart年月日[1]=FindEnd年月日[1]) then
			Filereadstep=0
		else 
		
			elFindStart年月日[0]=FindEnd年月日[0]
			elFindStart年月日[1]=FindEnd年月日[1]
			elFindStart年月日[2]=1
			elFindStart年月日[3]=0
			elFindStart年月日[4]=0
			elFindStart年月日[5]=0
			
		
			FindStartSec=sec(elFindStart年月日)
			FindEndSec=sec(FindEnd年月日)
		
			ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindEnd年月日[0])+STR(FindEnd年月日[1])+"."+"CSV"
			initFileread=ON
			linecnt=0
			readpar[0]=0  '最初の行から読込
			readpar[1]=0  '最初の行から読込
			readpar[2]=50 '最大読込文字列

			INC(Filereadstep)
		end if


	case 4

		if initFileread or (readerr[0] and ErrAnalyzestep=0) then
			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
				inc(linecnt)
				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el自動モードstr,el運転中str,elテスト運転str,el非常t停止str,el前処理運転中str,el自動モードstr,el自動モードstr,el自動モードstr)
				if ReadCnt>=7 then
					ReadSec.D=RDASC(ReadSecStr)
					ReadErrCode.D=RDASC(ReadErrCodeStr)
					if LEN(el自動モードstr)>0 then
						el自動モード.U=RDASC(el自動モードstr)
					else
						el自動モード=0
					end if
					
					if LEN(el運転中str)>0 then
						el運転中.U=RDASC(el運転中str)
					else
						el運転中=0
					end if
					
					if LEN(elテスト運転str)>0 then
						elテスト運転.U=RDASC(elテスト運転str)
					else 
						elテスト運転=0
					end if
					
					if LEN(el非常t停止str)>0 then
						el非常停止.U=RDASC(el非常t停止str)
					else
						el非常停止=0
					end if
					
					if LEN(el前処理運転中str)>0 then
						el前処理運転中.U=RDASC(el前処理運転中str)
					else
						el前処理運転中=0
					end if
					StackEnablebit=not(pnlPBel自動モード) or (pnlPBel自動モード and el自動モード=1) '自動モードのみ
					StackEnablebit=StackEnablebit and (not(pnlPBel運転中) or (pnlPBel運転中 and el運転中=1)) '運転中のみ
					StackEnablebit=StackEnablebit and (not(pnlPBelテスト運転) or (pnlPBelテスト運転 and elテスト運転=0)) 'テスト運転除外
					StackEnablebit=StackEnablebit and (not(pnlPBel非常停止) or (pnlPBel非常停止 and el非常停止=0)) '非常停止除外
					StackEnablebit=StackEnablebit and (not(pnlPBel前処理運転中) or (pnlPBel前処理運転中 and el前処理運転中=0)) '前処理運転除外
					if pnlPBelALL then
						StackEnablebit=ON
					end if
					'----------------------------------------
					'エラー統計プログラム	
					if ReadSec>=FindStartSec and ReadSec<=FindEndSec then
						if StackEnablebit then
							for loop=0 to 49 step 1
								if ErrAnalyzeCode[loop]=0 or ErrAnalyzeCode[loop]=TOU(ReadErrCode) then
									ErrAnalyzeCode[loop]=TOU(ReadErrCode)
									INC(ErrAnalyzeCnt[loop])
									break
								end if
							next
						end if
					end if
					'----------------------------------------
				end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					ErrAnalyzestep=1
					inc(Filereadstep)		
				end if
				
			end if
		end if

	
	case 5
		Filereadstep=0
	end select
	
'-----------------------------------------------------------------------------------------------------------------------------
'Analysis ％計算

	select case ErrAnalyzestep
	
	case 1
		ErrAnlyzeTotalCnt=0
		for anloop=0 to 49 step 1
			ErrAnalyzePersent[anloop]=0
		next
		inc(ErrAnalyzestep)
	case 2
		for anloop=0 to 49 step 1
			ErrAnlyzeTotalCnt=ErrAnlyzeTotalCnt+ ErrAnalyzeCnt[anloop]
		next
		inc(ErrAnalyzestep)	
	case 3
		if ErrAnlyzeTotalCnt>0 then
			for anloop=0 to 49 step 1
			
				if ErrAnalyzeCnt[anloop]>0 then
					ErrAnalyzePersent[anloop]=(ErrAnalyzeCnt[anloop]*10000)/ErrAnlyzeTotalCnt
				else
					ErrAnalyzePersent[anloop]=0
				end if
				
			next
		end if
		inc(ErrAnalyzestep)	
	case 4
		ErrAnalyzestep=0
	end select
'-----------------------------------------------------------------------------------------------------------------------------
if ldp(alm渋滞警報入口) then
    WriteAlmstr.T="alm渋滞警報入口"
    Filewritestep=1
end if
if ldp(alm渋滞警報出口) then
    WriteAlmstr.T="alm渋滞警報出口"
    Filewritestep=1
end if
if ldp(almTHR4_送米ポンプ) then
    adrset(almTHR4_送米ポンプ,WriteErrAddres)
    WriteAlmstr.T="almTHR4_送米ポンプ"
    Filewritestep=1
end if
if ldp(almTHR5_洗米羽根) then
    adrset(almTHR5_洗米羽根,WriteErrAddres)
    WriteAlmstr.T="almTHR5_洗米羽根"
    Filewritestep=1
end if
if ldp(almRS1_水タンク上限センサー) then
    adrset(almRS1_水タンク上限センサー,WriteErrAddres)
    WriteAlmstr.T="almRS1_水タンク上限センサー"
    Filewritestep=1
end if
if ldp(almESPB5_非常停止) then
    adrset(almESPB5_非常停止,WriteErrAddres)
    WriteAlmstr.T="almESPB5_非常停止"
    Filewritestep=1
end if
if ldp(almMC4_送米ポンプ) then
    adrset(almMC4_送米ポンプ,WriteErrAddres)
    WriteAlmstr.T="almMC4_送米ポンプ"
    Filewritestep=1
end if
if ldp(almMC5_洗米羽根) then
    adrset(almMC5_洗米羽根,WriteErrAddres)
    WriteAlmstr.T="almMC5_洗米羽根"
    Filewritestep=1
end if
if ldp(almSV1_給水電磁弁) then
    adrset(almSV1_給水電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV1_給水電磁弁"
    Filewritestep=1
end if
if ldp(almSV58_洗米バルブA) then
    adrset(almSV58_洗米バルブA,WriteErrAddres)
    WriteAlmstr.T="almSV58_洗米バルブA"
    Filewritestep=1
end if
if ldp(almRLY_レベルスイッチ用電源) then
    adrset(almRLY_レベルスイッチ用電源,WriteErrAddres)
    WriteAlmstr.T="almRLY_レベルスイッチ用電源"
    Filewritestep=1
end if
if ldp(almSSW3_手動モード) then
    adrset(almSSW3_手動モード,WriteErrAddres)
    WriteAlmstr.T="almSSW3_手動モード"
    Filewritestep=1
end if
if ldp(almSSW3_自動モード) then
    adrset(almSSW3_自動モード,WriteErrAddres)
    WriteAlmstr.T="almSSW3_自動モード"
    Filewritestep=1
end if
if ldp(almESPB1_非常停止IN) then
    adrset(almESPB1_非常停止IN,WriteErrAddres)
    WriteAlmstr.T="almESPB1_非常停止IN"
    Filewritestep=1
end if
if ldp(almPTL1_パトライト赤) then
    adrset(almPTL1_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL1_パトライト黄) then
    adrset(almPTL1_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL1_パトライト青) then
    adrset(almPTL1_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL1_パトライトブザー) then
    adrset(almPTL1_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL1_パトライトブザー"
    Filewritestep=1
end if
if ldp(almTHR1_張込用昇降機モータ) then
    adrset(almTHR1_張込用昇降機モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR1_張込用昇降機モータ"
    Filewritestep=1
end if
if ldp(almTHR2_排出用昇降機モータ) then
    adrset(almTHR2_排出用昇降機モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR2_排出用昇降機モータ"
    Filewritestep=1
end if
if ldp(almTHR3_計量機モータ) then
    adrset(almTHR3_計量機モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR3_計量機モータ"
    Filewritestep=1
end if
if ldp(almFLOS1_計量機近接センサー) then
    adrset(almFLOS1_計量機近接センサー,WriteErrAddres)
    WriteAlmstr.T="almFLOS1_計量機近接センサー"
    Filewritestep=1
end if
if ldp(almFLOS2_洗米無洗米切換検知) then
    adrset(almFLOS2_洗米無洗米切換検知,WriteErrAddres)
    WriteAlmstr.T="almFLOS2_洗米無洗米切換検知"
    Filewritestep=1
end if
if ldp(almRLY_電源確認納米庫) then
    adrset(almRLY_電源確認納米庫,WriteErrAddres)
    WriteAlmstr.T="almRLY_電源確認納米庫"
    Filewritestep=1
end if
if ldp(almSSW4_納米庫手動) then
    adrset(almSSW4_納米庫手動,WriteErrAddres)
    WriteAlmstr.T="almSSW4_納米庫手動"
    Filewritestep=1
end if
if ldp(almSSW4_納米庫自動) then
    adrset(almSSW4_納米庫自動,WriteErrAddres)
    WriteAlmstr.T="almSSW4_納米庫自動"
    Filewritestep=1
end if
if ldp(almMC1_張込用昇降機) then
    adrset(almMC1_張込用昇降機,WriteErrAddres)
    WriteAlmstr.T="almMC1_張込用昇降機"
    Filewritestep=1
end if
if ldp(almMC2_排出用昇降機) then
    adrset(almMC2_排出用昇降機,WriteErrAddres)
    WriteAlmstr.T="almMC2_排出用昇降機"
    Filewritestep=1
end if
if ldp(almMC3_計量機) then
    adrset(almMC3_計量機,WriteErrAddres)
    WriteAlmstr.T="almMC3_計量機"
    Filewritestep=1
end if
if ldp(almXSW9_送米切換A側) then
    adrset(almXSW9_送米切換A側,WriteErrAddres)
    WriteAlmstr.T="almXSW9_送米切換A側"
    Filewritestep=1
end if
if ldp(almXSW10_送米切換B側) then
    adrset(almXSW10_送米切換B側,WriteErrAddres)
    WriteAlmstr.T="almXSW10_送米切換B側"
    Filewritestep=1
end if
if ldp(almRLY5_パドルセンサ電源) then
    adrset(almRLY5_パドルセンサ電源,WriteErrAddres)
    WriteAlmstr.T="almRLY5_パドルセンサ電源"
    Filewritestep=1
end if
if ldp(almSV12_送米切換バルブA側) then
    adrset(almSV12_送米切換バルブA側,WriteErrAddres)
    WriteAlmstr.T="almSV12_送米切換バルブA側"
    Filewritestep=1
end if
if ldp(almSV13_送米切換バルブB側) then
    adrset(almSV13_送米切換バルブB側,WriteErrAddres)
    WriteAlmstr.T="almSV13_送米切換バルブB側"
    Filewritestep=1
end if
if ldp(almPTL5_パトライト赤) then
    adrset(almPTL5_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL5_パトライト黄) then
    adrset(almPTL5_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL5_パトライト青) then
    adrset(almPTL5_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL5_パトライトブザー) then
    adrset(almPTL5_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL5_パトライトブザー"
    Filewritestep=1
end if
if ldp(almXSW1_充填バルブ開A) then
    adrset(almXSW1_充填バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almXSW1_充填バルブ開A"
    Filewritestep=1
end if
if ldp(almXSW2_充填バルブ閉A) then
    adrset(almXSW2_充填バルブ閉A,WriteErrAddres)
    WriteAlmstr.T="almXSW2_充填バルブ閉A"
    Filewritestep=1
end if
if ldp(almXSW3_水切りシャッター開A) then
    adrset(almXSW3_水切りシャッター開A,WriteErrAddres)
    WriteAlmstr.T="almXSW3_水切りシャッター開A"
    Filewritestep=1
end if
if ldp(almXSW4_水切りシャッター閉A) then
    adrset(almXSW4_水切りシャッター閉A,WriteErrAddres)
    WriteAlmstr.T="almXSW4_水切りシャッター閉A"
    Filewritestep=1
end if
if ldp(almPDL1_パドルセンサー上限A) then
    adrset(almPDL1_パドルセンサー上限A,WriteErrAddres)
    WriteAlmstr.T="almPDL1_パドルセンサー上限A"
    Filewritestep=1
end if
if ldp(almPDL2_パドルセンサー下限A) then
    adrset(almPDL2_パドルセンサー下限A,WriteErrAddres)
    WriteAlmstr.T="almPDL2_パドルセンサー下限A"
    Filewritestep=1
end if
if ldp(almXSW76_排水バルブ開A) then
    adrset(almXSW76_排水バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almXSW76_排水バルブ開A"
    Filewritestep=1
end if
if ldp(almXSW77_排水バルブ閉A) then
    adrset(almXSW77_排水バルブ閉A,WriteErrAddres)
    WriteAlmstr.T="almXSW77_排水バルブ閉A"
    Filewritestep=1
end if
if ldp(almFLOS3_LMT121) then
    adrset(almFLOS3_LMT121,WriteErrAddres)
    WriteAlmstr.T="almFLOS3_LMT121"
    Filewritestep=1
end if
if ldp(almPS1_エアー圧力) then
    adrset(almPS1_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS1_エアー圧力"
    Filewritestep=1
end if
if ldp(almSV2_充填バルブ開A) then
    adrset(almSV2_充填バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almSV2_充填バルブ開A"
    Filewritestep=1
end if
if ldp(almSV4_水切りシャッター開A) then
    adrset(almSV4_水切りシャッター開A,WriteErrAddres)
    WriteAlmstr.T="almSV4_水切りシャッター開A"
    Filewritestep=1
end if
if ldp(almSV5_水切りシャッター閉A) then
    adrset(almSV5_水切りシャッター閉A,WriteErrAddres)
    WriteAlmstr.T="almSV5_水切りシャッター閉A"
    Filewritestep=1
end if
if ldp(almSV6_給水電磁弁A) then
    adrset(almSV6_給水電磁弁A,WriteErrAddres)
    WriteAlmstr.T="almSV6_給水電磁弁A"
    Filewritestep=1
end if
if ldp(almSV60_排水バルブ開A) then
    adrset(almSV60_排水バルブ開A,WriteErrAddres)
    WriteAlmstr.T="almSV60_排水バルブ開A"
    Filewritestep=1
end if
if ldp(almXSW5_充填バルブ開B) then
    adrset(almXSW5_充填バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almXSW5_充填バルブ開B"
    Filewritestep=1
end if
if ldp(almXSW6_充填バルブ閉B) then
    adrset(almXSW6_充填バルブ閉B,WriteErrAddres)
    WriteAlmstr.T="almXSW6_充填バルブ閉B"
    Filewritestep=1
end if
if ldp(almXSW7_水切りシャッター開B) then
    adrset(almXSW7_水切りシャッター開B,WriteErrAddres)
    WriteAlmstr.T="almXSW7_水切りシャッター開B"
    Filewritestep=1
end if
if ldp(almXSW8_水切りシャッター閉B) then
    adrset(almXSW8_水切りシャッター閉B,WriteErrAddres)
    WriteAlmstr.T="almXSW8_水切りシャッター閉B"
    Filewritestep=1
end if
if ldp(almPDL3_パドルセンサー上限B) then
    adrset(almPDL3_パドルセンサー上限B,WriteErrAddres)
    WriteAlmstr.T="almPDL3_パドルセンサー上限B"
    Filewritestep=1
end if
if ldp(almPDL4_パドルセンサー下限B) then
    adrset(almPDL4_パドルセンサー下限B,WriteErrAddres)
    WriteAlmstr.T="almPDL4_パドルセンサー下限B"
    Filewritestep=1
end if
if ldp(almXSW78_排水バルブ開B) then
    adrset(almXSW78_排水バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almXSW78_排水バルブ開B"
    Filewritestep=1
end if
if ldp(almXSW79_排水バルブ閉B) then
    adrset(almXSW79_排水バルブ閉B,WriteErrAddres)
    WriteAlmstr.T="almXSW79_排水バルブ閉B"
    Filewritestep=1
end if
if ldp(almFLOS4_LMT121) then
    adrset(almFLOS4_LMT121,WriteErrAddres)
    WriteAlmstr.T="almFLOS4_LMT121"
    Filewritestep=1
end if
if ldp(almSV7_充填バルブ開B) then
    adrset(almSV7_充填バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almSV7_充填バルブ開B"
    Filewritestep=1
end if
if ldp(almSV9_水切りシャッター開B) then
    adrset(almSV9_水切りシャッター開B,WriteErrAddres)
    WriteAlmstr.T="almSV9_水切りシャッター開B"
    Filewritestep=1
end if
if ldp(almSV10_水切りシャッター閉B) then
    adrset(almSV10_水切りシャッター閉B,WriteErrAddres)
    WriteAlmstr.T="almSV10_水切りシャッター閉B"
    Filewritestep=1
end if
if ldp(almSV11_給水電磁弁B) then
    adrset(almSV11_給水電磁弁B,WriteErrAddres)
    WriteAlmstr.T="almSV11_給水電磁弁B"
    Filewritestep=1
end if
if ldp(almSV62_排水バルブ開B) then
    adrset(almSV62_排水バルブ開B,WriteErrAddres)
    WriteAlmstr.T="almSV62_排水バルブ開B"
    Filewritestep=1
end if
if ldp(almAD4532_HI) then
    adrset(almAD4532_HI,WriteErrAddres)
    WriteAlmstr.T="almAD4532_HI"
    Filewritestep=1
end if
if ldp(almAD4532_OK) then
    adrset(almAD4532_OK,WriteErrAddres)
    WriteAlmstr.T="almAD4532_OK"
    Filewritestep=1
end if
if ldp(almAD4532_LO) then
    adrset(almAD4532_LO,WriteErrAddres)
    WriteAlmstr.T="almAD4532_LO"
    Filewritestep=1
end if
if ldp(almXSW106_計水バルブ開) then
    adrset(almXSW106_計水バルブ開,WriteErrAddres)
    WriteAlmstr.T="almXSW106_計水バルブ開"
    Filewritestep=1
end if
if ldp(almXSW107_計水バルブ閉) then
    adrset(almXSW107_計水バルブ閉,WriteErrAddres)
    WriteAlmstr.T="almXSW107_計水バルブ閉"
    Filewritestep=1
end if
if ldp(almSV17_計水タンク給水（大）) then
    adrset(almSV17_計水タンク給水（大）,WriteErrAddres)
    WriteAlmstr.T="almSV17_計水タンク給水（大）"
    Filewritestep=1
end if
if ldp(almSV18_計水タンク給水（小）) then
    adrset(almSV18_計水タンク給水（小）,WriteErrAddres)
    WriteAlmstr.T="almSV18_計水タンク給水（小）"
    Filewritestep=1
end if
if ldp(almSV19_計水電磁弁_A) then
    adrset(almSV19_計水電磁弁_A,WriteErrAddres)
    WriteAlmstr.T="almSV19_計水電磁弁_A"
    Filewritestep=1
end if
if ldp(almAD4532_ZERO) then
    adrset(almAD4532_ZERO,WriteErrAddres)
    WriteAlmstr.T="almAD4532_ZERO"
    Filewritestep=1
end if
if ldp(almAD4532_ON) then
    adrset(almAD4532_ON,WriteErrAddres)
    WriteAlmstr.T="almAD4532_ON"
    Filewritestep=1
end if
if ldp(almAD4532_COMP1) then
    adrset(almAD4532_COMP1,WriteErrAddres)
    WriteAlmstr.T="almAD4532_COMP1"
    Filewritestep=1
end if
if ldp(almAD4532_COMP2) then
    adrset(almAD4532_COMP2,WriteErrAddres)
    WriteAlmstr.T="almAD4532_COMP2"
    Filewritestep=1
end if
if ldp(almTHR6_搬送モータ) then
    adrset(almTHR6_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR6_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR7_搬送モータ) then
    adrset(almTHR7_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR7_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR8_搬送モータ) then
    adrset(almTHR8_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR8_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW11_ストッパ下降端) then
    adrset(almXSW11_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW11_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW12_ストッパ上昇端) then
    adrset(almXSW12_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW12_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW13_ストッパ下降端) then
    adrset(almXSW13_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW13_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW14_ストッパ上昇端) then
    adrset(almXSW14_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW14_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW15_リフト下降端) then
    adrset(almXSW15_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW15_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW16_リフト上昇端) then
    adrset(almXSW16_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW16_リフト上昇端"
    Filewritestep=1
end if
if ldp(almPH1_釜検知) then
    adrset(almPH1_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH1_釜検知"
    Filewritestep=1
end if
if ldp(almPH2_フタ検知) then
    adrset(almPH2_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH2_フタ検知"
    Filewritestep=1
end if
if ldp(almPH3_釜検知) then
    adrset(almPH3_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH3_釜検知"
    Filewritestep=1
end if
if ldp(almPH4_フタ検知) then
    adrset(almPH4_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH4_フタ検知"
    Filewritestep=1
end if
if ldp(almPH5_釜検知) then
    adrset(almPH5_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH5_釜検知"
    Filewritestep=1
end if
if ldp(almPH6_フタ検知) then
    adrset(almPH6_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH6_フタ検知"
    Filewritestep=1
end if
if ldp(almMC6_搬送モータ) then
    adrset(almMC6_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC6_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC7_搬送モータ) then
    adrset(almMC7_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC7_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC8_搬送モータ) then
    adrset(almMC8_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC8_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC9_モータローラ) then
    adrset(almMC9_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC9_モータローラ"
    Filewritestep=1
end if
if ldp(almSV14_ストッパ) then
    adrset(almSV14_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV14_ストッパ"
    Filewritestep=1
end if
if ldp(almSV15_ストッパ) then
    adrset(almSV15_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV15_ストッパ"
    Filewritestep=1
end if
if ldp(almSV16_リフト) then
    adrset(almSV16_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV16_リフト"
    Filewritestep=1
end if
if ldp(almPH50_釜検知) then
    adrset(almPH50_釜検知,WriteErrAddres)
    WriteAlmstr.T="搬送口 釜-釜重複検知"
    Filewritestep=1
end if
if ldp(almPH51_フタ検知) then
    adrset(almPH51_フタ検知,WriteErrAddres)
    WriteAlmstr.T="搬送口 フタ-フタ重複検知"
    Filewritestep=1
end if
if ldp(almPH52_釜検知) then
    adrset(almPH52_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH52_釜検知"
    Filewritestep=1
end if
if ldp(almPH53_フタ検知) then
    adrset(almPH53_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH53_フタ検知"
    Filewritestep=1
end if
if ldp(almTHR10_反転モータ) then
    adrset(almTHR10_反転モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR10_反転モータ"
    Filewritestep=1
end if
if ldp(almPH7_釜検知) then
    adrset(almPH7_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH7_釜検知"
    Filewritestep=1
end if
if ldp(almPH8_フタ検知) then
    adrset(almPH8_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH8_フタ検知"
    Filewritestep=1
end if
if ldp(almPH9_釜検知) then
    adrset(almPH9_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH9_釜検知"
    Filewritestep=1
end if
if ldp(almPH10_フタ検知) then
    adrset(almPH10_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH10_フタ検知"
    Filewritestep=1
end if
if ldp(almLS6_空釜反転反転位置) then
    adrset(almLS6_空釜反転反転位置,WriteErrAddres)
    WriteAlmstr.T="almLS6_空釜反転反転位置"
    Filewritestep=1
end if
if ldp(almLS5_空釜反転原点位置) then
    adrset(almLS5_空釜反転原点位置,WriteErrAddres)
    WriteAlmstr.T="almLS5_空釜反転原点位置"
    Filewritestep=1
end if
if ldp(almMC10_反転モータ正転) then
    adrset(almMC10_反転モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC10_反転モータ正転"
    Filewritestep=1
end if
if ldp(almMC10_反転モータ逆転) then
    adrset(almMC10_反転モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC10_反転モータ逆転"
    Filewritestep=1
end if
if ldp(almMC32_搬送モータ) then
    adrset(almMC32_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC32_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW17_リフト下降端) then
    adrset(almXSW17_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW17_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW18_リフト上昇端) then
    adrset(almXSW18_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW18_リフト上昇端"
    Filewritestep=1
end if
if ldp(almPH39_釜検知) then
    adrset(almPH39_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH39_釜検知"
    Filewritestep=1
end if
if ldp(almPH40_フタ検知) then
    adrset(almPH40_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH40_フタ検知"
    Filewritestep=1
end if
if ldp(almMC11_搬送モータ) then
    adrset(almMC11_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC11_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV20_リフト上昇) then
    adrset(almSV20_リフト上昇,WriteErrAddres)
    WriteAlmstr.T="almSV20_リフト上昇"
    Filewritestep=1
end if
if ldp(almSV100_リフト下降) then
    adrset(almSV100_リフト下降,WriteErrAddres)
    WriteAlmstr.T="almSV100_リフト下降"
    Filewritestep=1
end if
if ldp(almTHR30_搬送モータ) then
    adrset(almTHR30_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR30_搬送モータ"
    Filewritestep=1
end if
if ldp(almPH41_釜検知) then
    adrset(almPH41_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH41_釜検知"
    Filewritestep=1
end if
if ldp(almPH42_フタ検知) then
    adrset(almPH42_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH42_フタ検知"
    Filewritestep=1
end if
if ldp(almMC30_搬送モータ) then
    adrset(almMC30_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC30_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR12_搬送モータ) then
    adrset(almTHR12_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR12_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR13_搬送モータ) then
    adrset(almTHR13_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR13_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW19_ストッパ下降端) then
    adrset(almXSW19_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW19_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW20_ストッパ上昇端) then
    adrset(almXSW20_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW20_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW21_ストッパ下降端) then
    adrset(almXSW21_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW21_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW22_ストッパ上昇端) then
    adrset(almXSW22_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW22_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almPH11_釜検知) then
    adrset(almPH11_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH11_釜検知"
    Filewritestep=1
end if
if ldp(almPH12_フタ検知) then
    adrset(almPH12_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH12_フタ検知"
    Filewritestep=1
end if
if ldp(almPH13_釜検知) then
    adrset(almPH13_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH13_釜検知"
    Filewritestep=1
end if
if ldp(almPH14_フタ検知) then
    adrset(almPH14_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH14_フタ検知"
    Filewritestep=1
end if
if ldp(almRLY_搬送コンベアB電源確認) then
    adrset(almRLY_搬送コンベアB電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_搬送コンベアB電源確認"
    Filewritestep=1
end if
if ldp(almMC12_搬送モータ) then
    adrset(almMC12_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC12_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC13_搬送モータ) then
    adrset(almMC13_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC13_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV21_ストッパ) then
    adrset(almSV21_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV21_ストッパ"
    Filewritestep=1
end if
if ldp(almSV22_ストッパ) then
    adrset(almSV22_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV22_ストッパ"
    Filewritestep=1
end if
if ldp(almXSW23_ならし後退端) then
    adrset(almXSW23_ならし後退端,WriteErrAddres)
    WriteAlmstr.T="almXSW23_ならし後退端"
    Filewritestep=1
end if
if ldp(almXSW24_ならし前進端) then
    adrset(almXSW24_ならし前進端,WriteErrAddres)
    WriteAlmstr.T="almXSW24_ならし前進端"
    Filewritestep=1
end if
if ldp(almXSW25_ならし上昇端) then
    adrset(almXSW25_ならし上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW25_ならし上昇端"
    Filewritestep=1
end if
if ldp(almXSW26_ならし下降端) then
    adrset(almXSW26_ならし下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW26_ならし下降端"
    Filewritestep=1
end if
if ldp(almXSW27_ならし後退端) then
    adrset(almXSW27_ならし後退端,WriteErrAddres)
    WriteAlmstr.T="almXSW27_ならし後退端"
    Filewritestep=1
end if
if ldp(almXSW28_ならし前進端) then
    adrset(almXSW28_ならし前進端,WriteErrAddres)
    WriteAlmstr.T="almXSW28_ならし前進端"
    Filewritestep=1
end if
if ldp(almSV23_ならし前進) then
    adrset(almSV23_ならし前進,WriteErrAddres)
    WriteAlmstr.T="almSV23_ならし前進"
    Filewritestep=1
end if
if ldp(almSV24_ならし後退) then
    adrset(almSV24_ならし後退,WriteErrAddres)
    WriteAlmstr.T="almSV24_ならし後退"
    Filewritestep=1
end if
if ldp(almSV25_ならし下降) then
    adrset(almSV25_ならし下降,WriteErrAddres)
    WriteAlmstr.T="almSV25_ならし下降"
    Filewritestep=1
end if
if ldp(almSV26_ならし上昇) then
    adrset(almSV26_ならし上昇,WriteErrAddres)
    WriteAlmstr.T="almSV26_ならし上昇"
    Filewritestep=1
end if
if ldp(almSV27_ならし前進) then
    adrset(almSV27_ならし前進,WriteErrAddres)
    WriteAlmstr.T="almSV27_ならし前進"
    Filewritestep=1
end if
if ldp(almSV28_ならし後退) then
    adrset(almSV28_ならし後退,WriteErrAddres)
    WriteAlmstr.T="almSV28_ならし後退"
    Filewritestep=1
end if
if ldp(almFL001_HH_Aタンク) then
    adrset(almFL001_HH_Aタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_HH_Aタンク"
    Filewritestep=1
end if
if ldp(almFL001_H_Aタンク) then
    adrset(almFL001_H_Aタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_H_Aタンク"
    Filewritestep=1
end if
if ldp(almFL001_L_Aタンク) then
    adrset(almFL001_L_Aタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_L_Aタンク"
    Filewritestep=1
end if
if ldp(almFL001_LL_Aタンク) then
    adrset(almFL001_LL_Aタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_LL_Aタンク"
    Filewritestep=1
end if
if ldp(almFL001_HH_Bタンク) then
    adrset(almFL001_HH_Bタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_HH_Bタンク"
    Filewritestep=1
end if
if ldp(almFL001_H_Bタンク) then
    adrset(almFL001_H_Bタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_H_Bタンク"
    Filewritestep=1
end if
if ldp(almFL001_L_Bタンク) then
    adrset(almFL001_L_Bタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_L_Bタンク"
    Filewritestep=1
end if
if ldp(almFL001_LL_Bタンク) then
    adrset(almFL001_LL_Bタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_LL_Bタンク"
    Filewritestep=1
end if
if ldp(almFL001_ALMC_Aタンク) then
    adrset(almFL001_ALMC_Aタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_ALMC_Aタンク"
    Filewritestep=1
end if
if ldp(almFL001_ALMC_Bタンク) then
    adrset(almFL001_ALMC_Bタンク,WriteErrAddres)
    WriteAlmstr.T="almFL001_ALMC_Bタンク"
    Filewritestep=1
end if
if ldp(almCSR2_ショックリレー) then
    adrset(almCSR2_ショックリレー,WriteErrAddres)
    WriteAlmstr.T="almCSR2_ショックリレー"
    Filewritestep=1
end if
if ldp(almRLY_浸漬電源確認) then
    adrset(almRLY_浸漬電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_浸漬電源確認"
    Filewritestep=1
end if
if ldp(almTHR14_搬送モータ) then
    adrset(almTHR14_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR14_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR15_搬送モータ) then
    adrset(almTHR15_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR15_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW29_ストッパ下降端) then
    adrset(almXSW29_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW29_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW30_ストッパ上昇端) then
    adrset(almXSW30_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW30_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW31_ストッパ下降端) then
    adrset(almXSW31_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW31_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW32_ストッパ上昇端) then
    adrset(almXSW32_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW32_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW33_クランプ下降端) then
    adrset(almXSW33_クランプ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW33_クランプ下降端"
    Filewritestep=1
end if
if ldp(almXSW34_クランプ上昇端) then
    adrset(almXSW34_クランプ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW34_クランプ上昇端"
    Filewritestep=1
end if
if ldp(almXSW35_クランプ下降端) then
    adrset(almXSW35_クランプ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW35_クランプ下降端"
    Filewritestep=1
end if
if ldp(almXSW36_クランプ上昇端) then
    adrset(almXSW36_クランプ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW36_クランプ上昇端"
    Filewritestep=1
end if
if ldp(almXSW37_リフト下降端) then
    adrset(almXSW37_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW37_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW38_リフト上昇端) then
    adrset(almXSW38_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW38_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW74_ストッパ下降端) then
    adrset(almXSW74_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW74_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW75_ストッパ上昇端) then
    adrset(almXSW75_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW75_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almPH15_釜検知) then
    adrset(almPH15_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH15_釜検知"
    Filewritestep=1
end if
if ldp(almPH16_フタ検知) then
    adrset(almPH16_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH16_フタ検知"
    Filewritestep=1
end if
if ldp(almPH17_釜検知) then
    adrset(almPH17_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH17_釜検知"
    Filewritestep=1
end if
if ldp(almPH18_フタ検知) then
    adrset(almPH18_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH18_フタ検知"
    Filewritestep=1
end if
if ldp(almPH19_釜検知) then
    adrset(almPH19_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH19_釜検知"
    Filewritestep=1
end if
if ldp(almPH20_フタ検知) then
    adrset(almPH20_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH20_フタ検知"
    Filewritestep=1
end if
if ldp(almPS2_エアー圧力) then
    adrset(almPS2_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS2_エアー圧力"
    Filewritestep=1
end if
if ldp(almMC14_搬送モータ) then
    adrset(almMC14_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC14_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC15_搬送モータ) then
    adrset(almMC15_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC15_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC16_モータローラ) then
    adrset(almMC16_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC16_モータローラ"
    Filewritestep=1
end if
if ldp(almSV29_ストッパ) then
    adrset(almSV29_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV29_ストッパ"
    Filewritestep=1
end if
if ldp(almSV30_ストッパ) then
    adrset(almSV30_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV30_ストッパ"
    Filewritestep=1
end if
if ldp(almSV31_クランプ) then
    adrset(almSV31_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV31_クランプ"
    Filewritestep=1
end if
if ldp(almSV32_クランプ) then
    adrset(almSV32_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV32_クランプ"
    Filewritestep=1
end if
if ldp(almSV33_リフト) then
    adrset(almSV33_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV33_リフト"
    Filewritestep=1
end if
if ldp(almSV65_ストッパ) then
    adrset(almSV65_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV65_ストッパ"
    Filewritestep=1
end if
if ldp(almXSW39_シリンダ上昇端A) then
    adrset(almXSW39_シリンダ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW39_シリンダ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW40_シリンダ下降端A) then
    adrset(almXSW40_シリンダ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW40_シリンダ下降端A"
    Filewritestep=1
end if
if ldp(almXSW41_シリンダ上昇端B) then
    adrset(almXSW41_シリンダ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW41_シリンダ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW42_シリンダ下降端B) then
    adrset(almXSW42_シリンダ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW42_シリンダ下降端B"
    Filewritestep=1
end if
if ldp(almXSW43_クランプ) then
    adrset(almXSW43_クランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW43_クランプ"
    Filewritestep=1
end if
if ldp(almXSW44_アンクランプ) then
    adrset(almXSW44_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW44_アンクランプ"
    Filewritestep=1
end if
if ldp(almXSW111_釜位置右後退端) then
    adrset(almXSW111_釜位置右後退端,WriteErrAddres)
    WriteAlmstr.T="almXSW111_釜位置右後退端"
    Filewritestep=1
end if
if ldp(almXSW112_釜位置左後退端) then
    adrset(almXSW112_釜位置左後退端,WriteErrAddres)
    WriteAlmstr.T="almXSW112_釜位置左後退端"
    Filewritestep=1
end if
if ldp(almSV34_シリンダ上昇A) then
    adrset(almSV34_シリンダ上昇A,WriteErrAddres)
    WriteAlmstr.T="almSV34_シリンダ上昇A"
    Filewritestep=1
end if
if ldp(almSV35_シリンダ下降A) then
    adrset(almSV35_シリンダ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV35_シリンダ下降A"
    Filewritestep=1
end if
if ldp(almSV36_シリンダ上昇B) then
    adrset(almSV36_シリンダ上昇B,WriteErrAddres)
    WriteAlmstr.T="almSV36_シリンダ上昇B"
    Filewritestep=1
end if
if ldp(almSV37_シリンダ下降B) then
    adrset(almSV37_シリンダ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV37_シリンダ下降B"
    Filewritestep=1
end if
if ldp(almSV38_クランプ) then
    adrset(almSV38_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV38_クランプ"
    Filewritestep=1
end if
if ldp(almSV39_アンクランプ) then
    adrset(almSV39_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almSV39_アンクランプ"
    Filewritestep=1
end if
if ldp(almSV64_釜位置) then
    adrset(almSV64_釜位置,WriteErrAddres)
    WriteAlmstr.T="almSV64_釜位置"
    Filewritestep=1
end if
if ldp(almTHR34_釜送りコンベア) then
    adrset(almTHR34_釜送りコンベア,WriteErrAddres)
    WriteAlmstr.T="almTHR34_釜送りコンベア"
    Filewritestep=1
end if
if ldp(almLS9_釜送り前進端) then
    adrset(almLS9_釜送り前進端,WriteErrAddres)
    WriteAlmstr.T="almLS9_釜送り前進端"
    Filewritestep=1
end if
if ldp(almLS10_釜送り後退端) then
    adrset(almLS10_釜送り後退端,WriteErrAddres)
    WriteAlmstr.T="almLS10_釜送り後退端"
    Filewritestep=1
end if
if ldp(almPH54_釜送りトリガ) then
    adrset(almPH54_釜送りトリガ,WriteErrAddres)
    WriteAlmstr.T="almPH54_釜送りトリガ"
    Filewritestep=1
end if
if ldp(almPH55_釜検知ステージ) then
    adrset(almPH55_釜検知ステージ,WriteErrAddres)
    WriteAlmstr.T="almPH55_釜検知ステージ"
    Filewritestep=1
end if
if ldp(almPH58_釜検知前ステージ) then
    adrset(almPH58_釜検知前ステージ,WriteErrAddres)
    WriteAlmstr.T="almPH58_釜検知前ステージ"
    Filewritestep=1
end if
if ldp(almPH59_釜検知炊飯機入口) then
    adrset(almPH59_釜検知炊飯機入口,WriteErrAddres)
    WriteAlmstr.T="almPH59_釜検知炊飯機入口"
    Filewritestep=1
end if
if ldp(almTHR43_乗移コンベア) then
    adrset(almTHR43_乗移コンベア,WriteErrAddres)
    WriteAlmstr.T="almTHR43_乗移コンベア"
    Filewritestep=1
end if
if ldp(almMC34_釜送り正転) then
    adrset(almMC34_釜送り正転,WriteErrAddres)
    WriteAlmstr.T="almMC34_釜送り正転"
    Filewritestep=1
end if
if ldp(almMC34_釜送り逆転) then
    adrset(almMC34_釜送り逆転,WriteErrAddres)
    WriteAlmstr.T="almMC34_釜送り逆転"
    Filewritestep=1
end if
if ldp(almMC43_乗移コンベア) then
    adrset(almMC43_乗移コンベア,WriteErrAddres)
    WriteAlmstr.T="almMC43_乗移コンベア"
    Filewritestep=1
end if
if ldp(almTHR18_釜送りコンベア) then
    adrset(almTHR18_釜送りコンベア,WriteErrAddres)
    WriteAlmstr.T="almTHR18_釜送りコンベア"
    Filewritestep=1
end if
if ldp(almLS1_釜送り前進端) then
    adrset(almLS1_釜送り前進端,WriteErrAddres)
    WriteAlmstr.T="almLS1_釜送り前進端"
    Filewritestep=1
end if
if ldp(almLS2_釜送り後退端) then
    adrset(almLS2_釜送り後退端,WriteErrAddres)
    WriteAlmstr.T="almLS2_釜送り後退端"
    Filewritestep=1
end if
if ldp(almPH56_釜送りトリガ) then
    adrset(almPH56_釜送りトリガ,WriteErrAddres)
    WriteAlmstr.T="almPH56_釜送りトリガ"
    Filewritestep=1
end if
if ldp(almPH57_釜検知ステージ) then
    adrset(almPH57_釜検知ステージ,WriteErrAddres)
    WriteAlmstr.T="almPH57_釜検知ステージ"
    Filewritestep=1
end if
if ldp(almMC18_釜送り逆転) then
    adrset(almMC18_釜送り逆転,WriteErrAddres)
    WriteAlmstr.T="almMC18_釜送り逆転"
    Filewritestep=1
end if
if ldp(almMC18_釜送り正転) then
    adrset(almMC18_釜送り正転,WriteErrAddres)
    WriteAlmstr.T="almMC18_釜送り正転"
    Filewritestep=1
end if
if ldp(almTHR17_むらし機モータ) then
    adrset(almTHR17_むらし機モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR17_むらし機モータ"
    Filewritestep=1
end if
if ldp(almCSR1_ショックリレー) then
    adrset(almCSR1_ショックリレー,WriteErrAddres)
    WriteAlmstr.T="almCSR1_ショックリレー"
    Filewritestep=1
end if
if ldp(almSSW1_1_運転切換（単動）) then
    adrset(almSSW1_1_運転切換（単動）,WriteErrAddres)
    WriteAlmstr.T="almSSW1_1_運転切換（単動）"
    Filewritestep=1
end if
if ldp(almSSW1_2_運転切換（連動）) then
    adrset(almSSW1_2_運転切換（連動）,WriteErrAddres)
    WriteAlmstr.T="almSSW1_2_運転切換（連動）"
    Filewritestep=1
end if
if ldp(almLS3_むらし機ピッチ検知) then
    adrset(almLS3_むらし機ピッチ検知,WriteErrAddres)
    WriteAlmstr.T="almLS3_むらし機ピッチ検知"
    Filewritestep=1
end if
if ldp(almPH21_むらし機出口センサ) then
    adrset(almPH21_むらし機出口センサ,WriteErrAddres)
    WriteAlmstr.T="almPH21_むらし機出口センサ"
    Filewritestep=1
end if
if ldp(almLS31_むらし機入口センサ) then
    adrset(almLS31_むらし機入口センサ,WriteErrAddres)
    WriteAlmstr.T="almLS31_むらし機入口センサ"
    Filewritestep=1
end if
if ldp(almRLY_むらし電源確認) then
    adrset(almRLY_むらし電源確認,WriteErrAddres)
    WriteAlmstr.T="almRLY_むらし電源確認"
    Filewritestep=1
end if
if ldp(almMC17_むらし機モータ) then
    adrset(almMC17_むらし機モータ,WriteErrAddres)
    WriteAlmstr.T="almMC17_むらし機モータ"
    Filewritestep=1
end if
if ldp(almPTL2_パトライト赤) then
    adrset(almPTL2_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL2_パトライト黄) then
    adrset(almPTL2_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL2_パトライト青) then
    adrset(almPTL2_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL2_パトライトブザー) then
    adrset(almPTL2_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL2_パトライトブザー"
    Filewritestep=1
end if
if ldp(almTHR19_搬送モータ) then
    adrset(almTHR19_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR19_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR20_搬送モータ) then
    adrset(almTHR20_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR20_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR21_搬送モータ) then
    adrset(almTHR21_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR21_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR22_搬送モータ) then
    adrset(almTHR22_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR22_搬送モータ"
    Filewritestep=1
end if
if ldp(almPS3_エアー圧力) then
    adrset(almPS3_エアー圧力,WriteErrAddres)
    WriteAlmstr.T="almPS3_エアー圧力"
    Filewritestep=1
end if
if ldp(almXSW45_ストッパ下降端) then
    adrset(almXSW45_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW45_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW46_ストッパ上昇端) then
    adrset(almXSW46_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW46_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW47_リフト下降端) then
    adrset(almXSW47_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW47_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW48_リフト上昇端) then
    adrset(almXSW48_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW48_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW49_ストッパ下降端) then
    adrset(almXSW49_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW49_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW50_ストッパ上昇端) then
    adrset(almXSW50_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW50_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW51_ストッパ下降端) then
    adrset(almXSW51_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW51_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW52_ストッパ上昇端) then
    adrset(almXSW52_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW52_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW53_リフト下降端) then
    adrset(almXSW53_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW53_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW54_リフト上昇端) then
    adrset(almXSW54_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW54_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW71_バキューマリフト下降端) then
    adrset(almXSW71_バキューマリフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW71_バキューマリフト下降端"
    Filewritestep=1
end if
if ldp(almXSW72_バキューマリフト上昇端) then
    adrset(almXSW72_バキューマリフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW72_バキューマリフト上昇端"
    Filewritestep=1
end if
if ldp(almPH22_釜検知) then
    adrset(almPH22_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH22_釜検知"
    Filewritestep=1
end if
if ldp(almPH23_釜検知) then
    adrset(almPH23_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH23_釜検知"
    Filewritestep=1
end if
if ldp(almPH24_フタ検知) then
    adrset(almPH24_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH24_フタ検知"
    Filewritestep=1
end if
if ldp(almPH25_釜検知) then
    adrset(almPH25_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH25_釜検知"
    Filewritestep=1
end if
if ldp(almPH26_フタ検知) then
    adrset(almPH26_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH26_フタ検知"
    Filewritestep=1
end if
if ldp(almPH27_釜検知) then
    adrset(almPH27_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH27_釜検知"
    Filewritestep=1
end if
if ldp(almPH28_フタ検知) then
    adrset(almPH28_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH28_フタ検知"
    Filewritestep=1
end if
if ldp(almPH29_釜検知) then
    adrset(almPH29_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH29_釜検知"
    Filewritestep=1
end if
if ldp(almPH30_フタ検知) then
    adrset(almPH30_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH30_フタ検知"
    Filewritestep=1
end if
if ldp(almPH31_釜検知) then
    adrset(almPH31_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH31_釜検知"
    Filewritestep=1
end if
if ldp(almMC19_搬送モータ) then
    adrset(almMC19_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC19_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC20_搬送モータ) then
    adrset(almMC20_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC20_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC21_搬送モータ正転) then
    adrset(almMC21_搬送モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC21_搬送モータ正転"
    Filewritestep=1
end if
if ldp(almMC21_搬送モータ逆転) then
    adrset(almMC21_搬送モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC21_搬送モータ逆転"
    Filewritestep=1
end if
if ldp(almMC22_搬送モータ正転) then
    adrset(almMC22_搬送モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC22_搬送モータ正転"
    Filewritestep=1
end if
if ldp(almMC22_搬送モータ逆転) then
    adrset(almMC22_搬送モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC22_搬送モータ逆転"
    Filewritestep=1
end if
if ldp(almMC23_モータローラ) then
    adrset(almMC23_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC23_モータローラ"
    Filewritestep=1
end if
if ldp(almSV40_ストッパ) then
    adrset(almSV40_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV40_ストッパ"
    Filewritestep=1
end if
if ldp(almSV41_リフト) then
    adrset(almSV41_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV41_リフト"
    Filewritestep=1
end if
if ldp(almSV42_ストッパ) then
    adrset(almSV42_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV42_ストッパ"
    Filewritestep=1
end if
if ldp(almSV43_ストッパ) then
    adrset(almSV43_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV43_ストッパ"
    Filewritestep=1
end if
if ldp(almSV44_リフト) then
    adrset(almSV44_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV44_リフト"
    Filewritestep=1
end if
if ldp(almSV57_バキュームリフト) then
    adrset(almSV57_バキュームリフト,WriteErrAddres)
    WriteAlmstr.T="almSV57_バキュームリフト"
    Filewritestep=1
end if
if ldp(almXSW55_シリンダ上昇端A) then
    adrset(almXSW55_シリンダ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW55_シリンダ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW56_シリンダ下降端A) then
    adrset(almXSW56_シリンダ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW56_シリンダ下降端A"
    Filewritestep=1
end if
if ldp(almXSW57_シリンダ上昇端B) then
    adrset(almXSW57_シリンダ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW57_シリンダ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW58_シリンダ下降端B) then
    adrset(almXSW58_シリンダ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW58_シリンダ下降端B"
    Filewritestep=1
end if
if ldp(almXSW59_アンクランプ) then
    adrset(almXSW59_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW59_アンクランプ"
    Filewritestep=1
end if
if ldp(almXSW60_クランプ) then
    adrset(almXSW60_クランプ,WriteErrAddres)
    WriteAlmstr.T="almXSW60_クランプ"
    Filewritestep=1
end if
if ldp(almSV45_シリンダ上昇A) then
    adrset(almSV45_シリンダ上昇A,WriteErrAddres)
    WriteAlmstr.T="almSV45_シリンダ上昇A"
    Filewritestep=1
end if
if ldp(almSV46_シリンダ下降A) then
    adrset(almSV46_シリンダ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV46_シリンダ下降A"
    Filewritestep=1
end if
if ldp(almSV47_シリンダ上昇B) then
    adrset(almSV47_シリンダ上昇B,WriteErrAddres)
    WriteAlmstr.T="almSV47_シリンダ上昇B"
    Filewritestep=1
end if
if ldp(almSV48_シリンダ下降B) then
    adrset(almSV48_シリンダ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV48_シリンダ下降B"
    Filewritestep=1
end if
if ldp(almSV49_アンクランプ) then
    adrset(almSV49_アンクランプ,WriteErrAddres)
    WriteAlmstr.T="almSV49_アンクランプ"
    Filewritestep=1
end if
if ldp(almSV50_クランプ) then
    adrset(almSV50_クランプ,WriteErrAddres)
    WriteAlmstr.T="almSV50_クランプ"
    Filewritestep=1
end if
if ldp(almTHR25_搬送モータ) then
    adrset(almTHR25_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR25_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR26_搬送モータ) then
    adrset(almTHR26_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR26_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW63_ストッパ下降端) then
    adrset(almXSW63_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW63_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW64_ストッパ上昇端) then
    adrset(almXSW64_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW64_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almXSW65_ストッパ下降端) then
    adrset(almXSW65_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW65_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW66_ストッパ上昇端) then
    adrset(almXSW66_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW66_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almPH32_釜検知) then
    adrset(almPH32_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH32_釜検知"
    Filewritestep=1
end if
if ldp(almPH33_フタ検知) then
    adrset(almPH33_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH33_フタ検知"
    Filewritestep=1
end if
if ldp(almPH34_釜検知) then
    adrset(almPH34_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH34_釜検知"
    Filewritestep=1
end if
if ldp(almPH35_フタ検知) then
    adrset(almPH35_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH35_フタ検知"
    Filewritestep=1
end if
if ldp(almTHR24_吸引ポンプ) then
    adrset(almTHR24_吸引ポンプ,WriteErrAddres)
    WriteAlmstr.T="almTHR24_吸引ポンプ"
    Filewritestep=1
end if
if ldp(almXSW61_シリンダ上昇端) then
    adrset(almXSW61_シリンダ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW61_シリンダ上昇端"
    Filewritestep=1
end if
if ldp(almXSW62_シリンダ下降端) then
    adrset(almXSW62_シリンダ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW62_シリンダ下降端"
    Filewritestep=1
end if
if ldp(almMC24_吸引ポンプ) then
    adrset(almMC24_吸引ポンプ,WriteErrAddres)
    WriteAlmstr.T="almMC24_吸引ポンプ"
    Filewritestep=1
end if
if ldp(almSV51_給水電磁弁) then
    adrset(almSV51_給水電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV51_給水電磁弁"
    Filewritestep=1
end if
if ldp(almSV52_シリンダ) then
    adrset(almSV52_シリンダ,WriteErrAddres)
    WriteAlmstr.T="almSV52_シリンダ"
    Filewritestep=1
end if
if ldp(almMC25_搬送モータ) then
    adrset(almMC25_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC25_搬送モータ"
    Filewritestep=1
end if
if ldp(almMC26_搬送モータ) then
    adrset(almMC26_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC26_搬送モータ"
    Filewritestep=1
end if
if ldp(almSV53_ストッパ) then
    adrset(almSV53_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV53_ストッパ"
    Filewritestep=1
end if
if ldp(almSV54_ストッパ) then
    adrset(almSV54_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV54_ストッパ"
    Filewritestep=1
end if
if ldp(almTHR28_搬送モータ) then
    adrset(almTHR28_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR28_搬送モータ"
    Filewritestep=1
end if
if ldp(almTHR29_搬送モータ) then
    adrset(almTHR29_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR29_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW67_リフト下降端) then
    adrset(almXSW67_リフト下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW67_リフト下降端"
    Filewritestep=1
end if
if ldp(almXSW68_リフト上昇端) then
    adrset(almXSW68_リフト上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW68_リフト上昇端"
    Filewritestep=1
end if
if ldp(almXSW69_ストッパ下降端) then
    adrset(almXSW69_ストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW69_ストッパ下降端"
    Filewritestep=1
end if
if ldp(almXSW70_ストッパ上昇端) then
    adrset(almXSW70_ストッパ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW70_ストッパ上昇端"
    Filewritestep=1
end if
if ldp(almPH36_釜検知) then
    adrset(almPH36_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH36_釜検知"
    Filewritestep=1
end if
if ldp(almPH37_フタ検知) then
    adrset(almPH37_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH37_フタ検知"
    Filewritestep=1
end if
if ldp(almPH48_釜検知) then
    adrset(almPH48_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH48_釜検知"
    Filewritestep=1
end if
if ldp(almPH49_フタ検知) then
    adrset(almPH49_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH49_フタ検知"
    Filewritestep=1
end if
if ldp(almPH38_釜検知) then
    adrset(almPH38_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH38_釜検知"
    Filewritestep=1
end if
if ldp(almMC28_搬送モータ正転) then
    adrset(almMC28_搬送モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC28_搬送モータ正転"
    Filewritestep=1
end if
if ldp(almMC28_搬送モータ逆転) then
    adrset(almMC28_搬送モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC28_搬送モータ逆転"
    Filewritestep=1
end if
if ldp(almMC29_搬送モータ正転) then
    adrset(almMC29_搬送モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC29_搬送モータ正転"
    Filewritestep=1
end if
if ldp(almMC29_搬送モータ逆転) then
    adrset(almMC29_搬送モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC29_搬送モータ逆転"
    Filewritestep=1
end if
if ldp(almMC27_モータローラ) then
    adrset(almMC27_モータローラ,WriteErrAddres)
    WriteAlmstr.T="almMC27_モータローラ"
    Filewritestep=1
end if
if ldp(almSV55_リフト) then
    adrset(almSV55_リフト,WriteErrAddres)
    WriteAlmstr.T="almSV55_リフト"
    Filewritestep=1
end if
if ldp(almSV56_ストッパ) then
    adrset(almSV56_ストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV56_ストッパ"
    Filewritestep=1
end if
if ldp(almTHR31_反転モータ) then
    adrset(almTHR31_反転モータ,WriteErrAddres)
    WriteAlmstr.T="almTHR31_反転モータ"
    Filewritestep=1
end if
if ldp(almPH43_釜検知) then
    adrset(almPH43_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH43_釜検知"
    Filewritestep=1
end if
if ldp(almPH44_フタ検知) then
    adrset(almPH44_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH44_フタ検知"
    Filewritestep=1
end if
if ldp(almPH45_釜検知) then
    adrset(almPH45_釜検知,WriteErrAddres)
    WriteAlmstr.T="almPH45_釜検知"
    Filewritestep=1
end if
if ldp(almPH46_フタ検知) then
    adrset(almPH46_フタ検知,WriteErrAddres)
    WriteAlmstr.T="almPH46_フタ検知"
    Filewritestep=1
end if
if ldp(almLS7_釜反転機原点位置) then
    adrset(almLS7_釜反転機原点位置,WriteErrAddres)
    WriteAlmstr.T="almLS7_釜反転機原点位置"
    Filewritestep=1
end if
if ldp(almLS8_釜反転機反転位置) then
    adrset(almLS8_釜反転機反転位置,WriteErrAddres)
    WriteAlmstr.T="almLS8_釜反転機反転位置"
    Filewritestep=1
end if
if ldp(almMC31_反転モータ正転) then
    adrset(almMC31_反転モータ正転,WriteErrAddres)
    WriteAlmstr.T="almMC31_反転モータ正転"
    Filewritestep=1
end if
if ldp(almMC31_反転モータ逆転) then
    adrset(almMC31_反転モータ逆転,WriteErrAddres)
    WriteAlmstr.T="almMC31_反転モータ逆転"
    Filewritestep=1
end if
if ldp(almMC33_搬送モータ) then
    adrset(almMC33_搬送モータ,WriteErrAddres)
    WriteAlmstr.T="almMC33_搬送モータ"
    Filewritestep=1
end if
if ldp(almXSW73_シリンダ上昇端) then
    adrset(almXSW73_シリンダ上昇端,WriteErrAddres)
    WriteAlmstr.T="almXSW73_シリンダ上昇端"
    Filewritestep=1
end if
if ldp(almXSW80_シリンダ下降端) then
    adrset(almXSW80_シリンダ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW80_シリンダ下降端"
    Filewritestep=1
end if
if ldp(almDLR1_ごはん検知) then
    adrset(almDLR1_ごはん検知,WriteErrAddres)
    WriteAlmstr.T="almDLR1_ごはん検知"
    Filewritestep=1
end if
if ldp(almDLR1_ごはん検知安定動作) then
    adrset(almDLR1_ごはん検知安定動作,WriteErrAddres)
    WriteAlmstr.T="almDLR1_ごはん検知安定動作"
    Filewritestep=1
end if
if ldp(almESPB3_非常停止IN) then
    adrset(almESPB3_非常停止IN,WriteErrAddres)
    WriteAlmstr.T="almESPB3_非常停止IN"
    Filewritestep=1
end if
if ldp(almESPB4_非常停止IN) then
    adrset(almESPB4_非常停止IN,WriteErrAddres)
    WriteAlmstr.T="almESPB4_非常停止IN"
    Filewritestep=1
end if
if ldp(almSV58_シリンダ) then
    adrset(almSV58_シリンダ,WriteErrAddres)
    WriteAlmstr.T="almSV58_シリンダ"
    Filewritestep=1
end if
if ldp(almPTL3_パトライト赤) then
    adrset(almPTL3_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL3_パトライト黄) then
    adrset(almPTL3_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL3_パトライト青) then
    adrset(almPTL3_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL3_パトライトブザー) then
    adrset(almPTL3_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL3_パトライトブザー"
    Filewritestep=1
end if
if ldp(almTHR35_洗浄ポンプA) then
    adrset(almTHR35_洗浄ポンプA,WriteErrAddres)
    WriteAlmstr.T="almTHR35_洗浄ポンプA"
    Filewritestep=1
end if
if ldp(almTHR36_洗浄ポンプB) then
    adrset(almTHR36_洗浄ポンプB,WriteErrAddres)
    WriteAlmstr.T="almTHR36_洗浄ポンプB"
    Filewritestep=1
end if
if ldp(almTHR37_洗浄ポンプC) then
    adrset(almTHR37_洗浄ポンプC,WriteErrAddres)
    WriteAlmstr.T="almTHR37_洗浄ポンプC"
    Filewritestep=1
end if
if ldp(almTHR38_洗浄ポンプD) then
    adrset(almTHR38_洗浄ポンプD,WriteErrAddres)
    WriteAlmstr.T="almTHR38_洗浄ポンプD"
    Filewritestep=1
end if
if ldp(almTHR39_洗浄ポンプE) then
    adrset(almTHR39_洗浄ポンプE,WriteErrAddres)
    WriteAlmstr.T="almTHR39_洗浄ポンプE"
    Filewritestep=1
end if
if ldp(almMC35_洗浄ポンプA) then
    adrset(almMC35_洗浄ポンプA,WriteErrAddres)
    WriteAlmstr.T="almMC35_洗浄ポンプA"
    Filewritestep=1
end if
if ldp(almMC36_洗浄ポンプB) then
    adrset(almMC36_洗浄ポンプB,WriteErrAddres)
    WriteAlmstr.T="almMC36_洗浄ポンプB"
    Filewritestep=1
end if
if ldp(almMC37_洗浄ポンプC) then
    adrset(almMC37_洗浄ポンプC,WriteErrAddres)
    WriteAlmstr.T="almMC37_洗浄ポンプC"
    Filewritestep=1
end if
if ldp(almMC38_洗浄ポンプD) then
    adrset(almMC38_洗浄ポンプD,WriteErrAddres)
    WriteAlmstr.T="almMC38_洗浄ポンプD"
    Filewritestep=1
end if
if ldp(almMC39_洗浄ポンプE) then
    adrset(almMC39_洗浄ポンプE,WriteErrAddres)
    WriteAlmstr.T="almMC39_洗浄ポンプE"
    Filewritestep=1
end if
if ldp(almMC1_インバータ用電源) then
    adrset(almMC1_インバータ用電源,WriteErrAddres)
    WriteAlmstr.T="almMC1_インバータ用電源"
    Filewritestep=1
end if
if ldp(almXSW83_釜フタ押さえ上昇端B) then
    adrset(almXSW83_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW83_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW84_釜フタ押さえ下降端B) then
    adrset(almXSW84_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW84_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almXSW81_釜フタ押さえ上昇端A) then
    adrset(almXSW81_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW81_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW82_釜フタ押さえ下降端A) then
    adrset(almXSW82_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW82_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW85_釜フタストッパ下降端) then
    adrset(almXSW85_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW85_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV10_洗浄ポンプA異常) then
    adrset(almINV10_洗浄ポンプA異常,WriteErrAddres)
    WriteAlmstr.T="almINV10_洗浄ポンプA異常"
    Filewritestep=1
end if
if ldp(almFLT1_タンク上限) then
    adrset(almFLT1_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT1_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT2_タンク下限) then
    adrset(almFLT2_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT2_タンク下限"
    Filewritestep=1
end if
if ldp(almSV67_釜フタ押さえ下降A) then
    adrset(almSV67_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV67_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV68_釜フタ押さえ下降B) then
    adrset(almSV68_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV68_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV69_給湯電磁弁) then
    adrset(almSV69_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV69_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV70_蒸気電磁弁) then
    adrset(almSV70_蒸気電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV70_蒸気電磁弁"
    Filewritestep=1
end if
if ldp(almSV71_釜フタストッパ) then
    adrset(almSV71_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV71_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV72_下洗浄電磁弁) then
    adrset(almSV72_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV72_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almXSW88_釜フタ押さえ上昇端B) then
    adrset(almXSW88_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW88_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW89_釜フタ押さえ下降端B) then
    adrset(almXSW89_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW89_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almXSW86_釜フタ押さえ上昇端A) then
    adrset(almXSW86_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW86_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW87_釜フタ押さえ下降端A) then
    adrset(almXSW87_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW87_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW90_釜フタストッパ下降端) then
    adrset(almXSW90_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW90_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV11_洗浄ポンプB異常) then
    adrset(almINV11_洗浄ポンプB異常,WriteErrAddres)
    WriteAlmstr.T="almINV11_洗浄ポンプB異常"
    Filewritestep=1
end if
if ldp(almFLT3_タンク上限) then
    adrset(almFLT3_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT3_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT4_タンク下限) then
    adrset(almFLT4_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT4_タンク下限"
    Filewritestep=1
end if
if ldp(almSV73_釜フタ押さえ下降A) then
    adrset(almSV73_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV73_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV74_釜フタ押さえ下降B) then
    adrset(almSV74_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV74_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV75_給湯電磁弁) then
    adrset(almSV75_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV75_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV76_蒸気電磁弁) then
    adrset(almSV76_蒸気電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV76_蒸気電磁弁"
    Filewritestep=1
end if
if ldp(almSV77_釜フタストッパ) then
    adrset(almSV77_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV77_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV78_下洗浄電磁弁) then
    adrset(almSV78_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV78_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almXSW93_釜フタ押さえ上昇端B) then
    adrset(almXSW93_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW93_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW94_釜フタ押さえ下降端B) then
    adrset(almXSW94_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW94_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almXSW91_釜フタ押さえ上昇端A) then
    adrset(almXSW91_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW91_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW92_釜フタ押さえ下降端A) then
    adrset(almXSW92_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW92_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW95_釜フタストッパ下降端) then
    adrset(almXSW95_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW95_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV12_洗浄ポンプC異常) then
    adrset(almINV12_洗浄ポンプC異常,WriteErrAddres)
    WriteAlmstr.T="almINV12_洗浄ポンプC異常"
    Filewritestep=1
end if
if ldp(almFLT5_タンク上限) then
    adrset(almFLT5_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT5_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT6_タンク下限) then
    adrset(almFLT6_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT6_タンク下限"
    Filewritestep=1
end if
if ldp(almSV79_釜フタ押さえ下降A) then
    adrset(almSV79_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV79_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV80_釜フタ押さえ下降B) then
    adrset(almSV80_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV80_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV81_給湯電磁弁) then
    adrset(almSV81_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV81_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV82_蒸気電磁弁) then
    adrset(almSV82_蒸気電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV82_蒸気電磁弁"
    Filewritestep=1
end if
if ldp(almSV83_釜フタストッパ) then
    adrset(almSV83_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV83_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV84_下洗浄電磁弁) then
    adrset(almSV84_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV84_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almXSW98_釜フタ押さえ上昇端B) then
    adrset(almXSW98_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW98_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW99_釜フタ押さえ下降端B) then
    adrset(almXSW99_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW99_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almXSW96_釜フタ押さえ上昇端A) then
    adrset(almXSW96_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW96_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW97_釜フタ押さえ下降端A) then
    adrset(almXSW97_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW97_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW100_釜フタストッパ下降端) then
    adrset(almXSW100_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW100_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV13_洗浄ポンプD異常) then
    adrset(almINV13_洗浄ポンプD異常,WriteErrAddres)
    WriteAlmstr.T="almINV13_洗浄ポンプD異常"
    Filewritestep=1
end if
if ldp(almFLT7_タンク上限) then
    adrset(almFLT7_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT7_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT8_タンク下限) then
    adrset(almFLT8_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT8_タンク下限"
    Filewritestep=1
end if
if ldp(almSV85_釜フタ押さえ下降A) then
    adrset(almSV85_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV85_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV86_釜フタ押さえ下降B) then
    adrset(almSV86_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV86_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV87_給湯電磁弁) then
    adrset(almSV87_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV87_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV88_蒸気電磁弁) then
    adrset(almSV88_蒸気電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV88_蒸気電磁弁"
    Filewritestep=1
end if
if ldp(almSV89_釜フタストッパ) then
    adrset(almSV89_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV89_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV90_下洗浄電磁弁) then
    adrset(almSV90_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV90_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almXSW103_釜フタ押さえ上昇端B) then
    adrset(almXSW103_釜フタ押さえ上昇端B,WriteErrAddres)
    WriteAlmstr.T="almXSW103_釜フタ押さえ上昇端B"
    Filewritestep=1
end if
if ldp(almXSW104_釜フタ押さえ下降端B) then
    adrset(almXSW104_釜フタ押さえ下降端B,WriteErrAddres)
    WriteAlmstr.T="almXSW104_釜フタ押さえ下降端B"
    Filewritestep=1
end if
if ldp(almXSW101_釜フタ押さえ上昇端A) then
    adrset(almXSW101_釜フタ押さえ上昇端A,WriteErrAddres)
    WriteAlmstr.T="almXSW101_釜フタ押さえ上昇端A"
    Filewritestep=1
end if
if ldp(almXSW102_釜フタ押さえ下降端A) then
    adrset(almXSW102_釜フタ押さえ下降端A,WriteErrAddres)
    WriteAlmstr.T="almXSW102_釜フタ押さえ下降端A"
    Filewritestep=1
end if
if ldp(almXSW105_釜フタストッパ下降端) then
    adrset(almXSW105_釜フタストッパ下降端,WriteErrAddres)
    WriteAlmstr.T="almXSW105_釜フタストッパ下降端"
    Filewritestep=1
end if
if ldp(almINV14_洗浄ポンプE異常) then
    adrset(almINV14_洗浄ポンプE異常,WriteErrAddres)
    WriteAlmstr.T="almINV14_洗浄ポンプE異常"
    Filewritestep=1
end if
if ldp(almFLT9_タンク上限) then
    adrset(almFLT9_タンク上限,WriteErrAddres)
    WriteAlmstr.T="almFLT9_タンク上限"
    Filewritestep=1
end if
if ldp(almFLT10_タンク下限) then
    adrset(almFLT10_タンク下限,WriteErrAddres)
    WriteAlmstr.T="almFLT10_タンク下限"
    Filewritestep=1
end if
if ldp(almSV91_釜フタ押さえ下降A) then
    adrset(almSV91_釜フタ押さえ下降A,WriteErrAddres)
    WriteAlmstr.T="almSV91_釜フタ押さえ下降A"
    Filewritestep=1
end if
if ldp(almSV92_釜フタ押さえ下降B) then
    adrset(almSV92_釜フタ押さえ下降B,WriteErrAddres)
    WriteAlmstr.T="almSV92_釜フタ押さえ下降B"
    Filewritestep=1
end if
if ldp(almSV93_給湯電磁弁) then
    adrset(almSV93_給湯電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV93_給湯電磁弁"
    Filewritestep=1
end if
if ldp(almSV94_蒸気電磁弁) then
    adrset(almSV94_蒸気電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV94_蒸気電磁弁"
    Filewritestep=1
end if
if ldp(almSV95_釜フタストッパ) then
    adrset(almSV95_釜フタストッパ,WriteErrAddres)
    WriteAlmstr.T="almSV95_釜フタストッパ"
    Filewritestep=1
end if
if ldp(almSV96_下洗浄電磁弁) then
    adrset(almSV96_下洗浄電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV96_下洗浄電磁弁"
    Filewritestep=1
end if
if ldp(almRLY12_電源確認リレー) then
    adrset(almRLY12_電源確認リレー,WriteErrAddres)
    WriteAlmstr.T="almRLY12_電源確認リレー"
    Filewritestep=1
end if
if ldp(almSEL2_1_運転切換（単動）) then
    adrset(almSEL2_1_運転切換（単動）,WriteErrAddres)
    WriteAlmstr.T="almSEL2_1_運転切換（単動）"
    Filewritestep=1
end if
if ldp(almSEL2_2_運転切換（連動）) then
    adrset(almSEL2_2_運転切換（連動）,WriteErrAddres)
    WriteAlmstr.T="almSEL2_2_運転切換（連動）"
    Filewritestep=1
end if
if ldp(almPB26_コンベア停止) then
    adrset(almPB26_コンベア停止,WriteErrAddres)
    WriteAlmstr.T="almPB26_コンベア停止"
    Filewritestep=1
end if
if ldp(almPB27_コンベア停止) then
    adrset(almPB27_コンベア停止,WriteErrAddres)
    WriteAlmstr.T="almPB27_コンベア停止"
    Filewritestep=1
end if
if ldp(almPB28_コンベア停止) then
    adrset(almPB28_コンベア停止,WriteErrAddres)
    WriteAlmstr.T="almPB28_コンベア停止"
    Filewritestep=1
end if
if ldp(almPB29_コンベア停止) then
    adrset(almPB29_コンベア停止,WriteErrAddres)
    WriteAlmstr.T="almPB29_コンベア停止"
    Filewritestep=1
end if
if ldp(almSV97_すすぎ電磁弁) then
    adrset(almSV97_すすぎ電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV97_すすぎ電磁弁"
    Filewritestep=1
end if
if ldp(almSV98_仕上げ電磁弁) then
    adrset(almSV98_仕上げ電磁弁,WriteErrAddres)
    WriteAlmstr.T="almSV98_仕上げ電磁弁"
    Filewritestep=1
end if
if ldp(almPTL4_パトライト赤) then
    adrset(almPTL4_パトライト赤,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライト赤"
    Filewritestep=1
end if
if ldp(almPTL4_パトライト黄) then
    adrset(almPTL4_パトライト黄,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライト黄"
    Filewritestep=1
end if
if ldp(almPTL4_パトライト青) then
    adrset(almPTL4_パトライト青,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライト青"
    Filewritestep=1
end if
if ldp(almPTL4_パトライトブザー) then
    adrset(almPTL4_パトライトブザー,WriteErrAddres)
    WriteAlmstr.T="almPTL4_パトライトブザー"
    Filewritestep=1
end if
if ldp(almINV1_コンベアモータ正転) then
    adrset(almINV1_コンベアモータ正転,WriteErrAddres)
    WriteAlmstr.T="almINV1_コンベアモータ正転"
    Filewritestep=1
end if
if ldp(almINV1_コンベア異常) then
    adrset(almINV1_コンベア異常,WriteErrAddres)
    WriteAlmstr.T="almINV1_コンベア異常"
    Filewritestep=1
end if
if ldp(almINV2_コンベアモータ正転) then
    adrset(almINV2_コンベアモータ正転,WriteErrAddres)
    WriteAlmstr.T="almINV2_コンベアモータ正転"
    Filewritestep=1
end if
if ldp(almINV2_コンベア異常) then
    adrset(almINV2_コンベア異常,WriteErrAddres)
    WriteAlmstr.T="almINV2_コンベア異常"
    Filewritestep=1
end if
if ldp(almINV3_コンベアモータ正転) then
    adrset(almINV3_コンベアモータ正転,WriteErrAddres)
    WriteAlmstr.T="almINV3_コンベアモータ正転"
    Filewritestep=1
end if
if ldp(almINV3_コンベア異常) then
    adrset(almINV3_コンベア異常,WriteErrAddres)
    WriteAlmstr.T="almINV3_コンベア異常"
    Filewritestep=1
end if
if ldp(alm電源確認リレー_A) then
    adrset(alm電源確認リレー_A,WriteErrAddres)
    WriteAlmstr.T="alm電源確認リレー_A"
    Filewritestep=1
end if
if ldp(alm釜搬入可能信号_A) then
    adrset(alm釜搬入可能信号_A,WriteErrAddres)
    WriteAlmstr.T="alm釜搬入可能信号_A"
    Filewritestep=1
end if
if ldp(alm反転機反転完了信号_A) then
    adrset(alm反転機反転完了信号_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機反転完了信号_A"
    Filewritestep=1
end if
if ldp(alm反転機異常信号_A) then
    adrset(alm反転機異常信号_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機異常信号_A"
    Filewritestep=1
end if
if ldp(alm反転機運転指令_A) then
    adrset(alm反転機運転指令_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機運転指令_A"
    Filewritestep=1
end if
if ldp(alm反転機停止指令_A) then
    adrset(alm反転機停止指令_A,WriteErrAddres)
    WriteAlmstr.T="alm反転機停止指令_A"
    Filewritestep=1
end if
if ldp(alm電源確認リレー_B) then
    adrset(alm電源確認リレー_B,WriteErrAddres)
    WriteAlmstr.T="alm電源確認リレー_B"
    Filewritestep=1
end if
if ldp(alm釜搬入可能信号_B) then
    adrset(alm釜搬入可能信号_B,WriteErrAddres)
    WriteAlmstr.T="alm釜搬入可能信号_B"
    Filewritestep=1
end if
if ldp(alm反転機反転完了信号_B) then
    adrset(alm反転機反転完了信号_B,WriteErrAddres)
    WriteAlmstr.T="alm反転機反転完了信号_B"
    Filewritestep=1
end if
if ldp(alm反転機異常信号_B) then
    adrset(alm反転機異常信号_B,WriteErrAddres)
    WriteAlmstr.T="alm反転機異常信号_B"
    Filewritestep=1
end if
if ldp(alm反転機運転指令_B) then
    adrset(alm反転機運転指令_B,WriteErrAddres)
    WriteAlmstr.T="alm反転機運転指令_B"
    Filewritestep=1
end if
if ldp(alm反転機停止指令_B) then
    adrset(alm反転機停止指令_B,WriteErrAddres)
    WriteAlmstr.T="alm反転機停止指令_B"
    Filewritestep=1
end if
if ldp(almINV4_コンベア異常) then
    adrset(almINV4_コンベア異常,WriteErrAddres)
    WriteAlmstr.T="almINV4_コンベア異常"
    Filewritestep=1
end if
if ldp(almINV4_コンベア電源確認) then
    adrset(almINV4_コンベア電源確認,WriteErrAddres)
    WriteAlmstr.T="almINV4_コンベア電源確認"
    Filewritestep=1
end if
if ldp(almINV4_コンベア動作中) then
    adrset(almINV4_コンベア動作中,WriteErrAddres)
    WriteAlmstr.T="almINV4_コンベア動作中"
    Filewritestep=1
end if
if ldp(almINV4_インバータ正転) then
    adrset(almINV4_インバータ正転,WriteErrAddres)
    WriteAlmstr.T="almINV4_インバータ正転"
    Filewritestep=1
end if
if ldp(almINV4_インバータ停止) then
    adrset(almINV4_インバータ停止,WriteErrAddres)
    WriteAlmstr.T="almINV4_インバータ停止"
    Filewritestep=1
end if

