'アイテムファイル
'アイテム情報をCSVファイル書き込み、読み出しをするモジュ

'ファイル名 アイテム情報.CSV

'アイテム個数 20個
'アイテム名称 半角16文字         
'アイテム設定水量 1ワード符号なし整数  0 ~ 9999
'アイテム準備水量 1ワード符号なし整数  0 ~ 9999
'アイテム備考 半角22文字 11文字
'------------------------------------------------------------------------------------------
'【ローカルラベル】
'ReadFileStep   1ワード符号なし整数
'WriteFileStep	1ワード符号なし整数
'loop 1ワード符号なし整数
'FileErr	ビット[2]
'WriteFileName	文字列[40]
'WriteStr	文字列[200]
'ptrアイテム名称 2ワード符号なし整数
'ptrアイテム備考 2ワード符号なし整数
'------------------------------------------------------------------------------------------
'アイテム情報読み出し
'ファイル名 アイテム情報.csv

'		ReadFileName.T="Machine\"+"ERRAnal"+"20"+STR(FindStart年月日[0])+STR(FindStart年月日[1])+"."+"CSV"
'		initFileread=ON
'		linecnt=0
'		readpar[0]=0  '最初の行から読込
'		readpar[1]=0  '最初の行から読込
'		readpar[2]=50 '最大読込文字列
'
'		'クリア
'		for loop=0 to 49 step 1
'			ErrAnalyzeCode[loop]=0
'			ErrAnalyzeCnt[loop]=0
'		next		
'		
'		INC(Filereadstep)
'	
'	case 2
'	
'		if initFileread or readerr[0]) then
'			if MREADL(ReadFileName.T,ReadStr,readpar,readerr) then
'				inc(linecnt)
'				ReadCnt=SPLIT(ReadStr.T,",",ReadSecStr,ReadErrCodeStr,el自動モードstr,el運転中str,elテスト運転str,el非常t停止str,el前処理運転中str,el自動モードstr,el自動モードstr,el自動モードstr)
'				if ReadCnt>=7 then
'					'//格納処理
'				end if
'				if initFileread or readparstak<>readpar[0] then
'					readparstak=readpar[0]
'					initFileread=OFF
'				else
'					inc(Filereadstep)		
'				end if
'				
'			end if
'		end if
'------------------------------------------------------------------------------------------

if ReadFileStep=0 and WriteFileStep=0 and ldp(ItemLoad) then
	linecnt=0
	ReadFileStep=1
else if ReadFileStep=0 and WriteFileStep=0 and ldp(ItemSave) then
	linecnt=0
	WriteFileStep=1
end if



select case ReadFileStep

case 0

case 1
	ReadFileName.T="UserDoc\"+"アイテム情報"+"."+"CSV" 'ファイル名
	initFileread=ON
	linecnt=0
	readpar[0]=0  '最初の行から読込
	readpar[1]=0  '最初の行から読込
	readpar[2]=200 '最大読込文字列
	inc(ReadFileStep)

case 2
	if 0 then
	for loop=0 to 19 step 1
		ptrアイテム名称=ptrアイテム名称+(loop*16)
		*ptrアイテム名称.T=""
		ptrアイテム備考=ptrアイテム備考+(loop*22)
		*ptrアイテム備考.T=""
		アイテム設定水量[loop+1].U=0
		アイテム準備水量[loop+1].U=0
	next
	end if
	inc(ReadFileStep)

case 3
	if initFileread or readerr[0] then
		if MREADL(ReadFileName,ReadStr,readpar,readerr) then
			inc(linecnt)
			ReadCnt=SPLIT(ReadStr.T,",",アイテム名称str,アイテム設定水量str,アイテム準備水量str,アイテム備考str)
			if ReadCnt>=4 then
				if linecnt>=2 then
					loop=linecnt-2
					ADRSET(アイテム名称1,ptrアイテム名称)
					ADRSET(アイテム備考1,ptrアイテム備考)
					ptrアイテム名称=ptrアイテム名称+(loop*16)
					*ptrアイテム名称.T=アイテム名称str.T
					ptrアイテム備考=ptrアイテム備考+(loop*22)
					*ptrアイテム備考.T=アイテム備考str.T
					アイテム設定水量[loop+1].U=RDASC(アイテム設定水量str)
					アイテム準備水量[loop+1].U=RDASC(アイテム準備水量str)
				end if 
			end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					inc(ReadFileStep)
				end if
		end if
	end if

case 4
	ReadFileStep=0
	
end select


'------------------------------------------------------------------------------------------
'アイテム情報書き込み
select case WriteFileStep

	case 0
	case 1
		MMKDIR("UserDoc",FileErr)
		INC(WriteFileStep)

	case 2
		if FileErr[0] then '完了
			INC(WriteFileStep)
		end if
	
	case 3
		if FileErr[1] then '異常終了
		end if
		INC(WriteFileStep)
	
	case 4
		WriteFileName.T="UserDoc\"+"アイテム情報"+"."+"CSV" 'ファイル名
		MDEL(WriteFileName,FileErr)
		INC(WriteFileStep)
	
	case 5
		if FileErr[0] then '完了
			INC(WriteFileStep)
		end if
	
	case 6
		if FileErr[1] then '異常終了
		end if
		INC(WriteFileStep)
	
	case 7 '-->
		
		ADRSET(アイテム名称1,ptrアイテム名称)
		ADRSET(アイテム備考1,ptrアイテム備考)
		ptrアイテム名称=ptrアイテム名称+(linecnt*16)
		ptrアイテム備考=ptrアイテム備考+(linecnt*22)
		DELETE(WriteStr,200,0)
		WriteStr.T=*ptrアイテム名称.T+","
		WriteStr.T=WriteStr.T+DASC(アイテム設定水量[linecnt+1].U,1)+","
		WriteStr.T=WriteStr.T+DASC(アイテム準備水量[linecnt+1].U,1)+","
		WriteStr.T=WriteStr.T+*ptrアイテム備考.T
		WriteStr.T=WriteStr.T+CHR($0D) 
		'----------------------------------------------------------------------
		'ファイル書込みb
		MPRINT(WriteFileName.T,WriteStr.T,FileErr)

		INC(WriteFileStep)
	
	case 8
		if FileErr[0] then '完了
			INC(WriteFileStep)
		end if
	
	case 9
		if FileErr[1] then '異常終了
		end if
		INC(WriteFileStep)

	case 10
		if linecnt>=19 then
			WriteFileStep=0
		else 
			inc(linecnt)
			WriteFileStep=7
		end if
end select
'------------------------------------------------------------------------------------------
