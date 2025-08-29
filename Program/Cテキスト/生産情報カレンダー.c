'生産情報カレンダー
'-----------------------------------------------------------------------------------------------------
'ファイル読み出し
'
'	ReadFileName.T="UserDoc\"+"生産情報"+"20"+STR(カレンダー年)+STR(カレンダー月)+"."+"CSV" 'ファイル名
'	
'生産情報ファイル書込み
'
'	WriteFileName.T="UserDoc\"+"生産情報"+"20"+STR(CM700)+STR(CM701)+"."+"CSV" 'ファイル名
'
'	WriteStatstr="エラー発生"
'	WriteStatstr="送米開始"
'	WriteStatstr="送米完了"
'	WriteStatstr="配米開始"
'	WriteStatstr="配米終了"
'	WriteStatstr="炊飯完了"
'
'	'生産情報
'	WriteStr.T=str(CM700)+"/"+str(CM701)+"/"+str(CM702)+" "+str(CM703)+":"+STR(CM704)+"," '日付
'	WriteStr.T=WriteStr.T+WriteStatstr+"," '運転状態
'
'	WriteStepstr="アイテム"+","+EM4001.T+","
'	WriteStepstr=WriteStepstr+"設定水量"+","+DASC(DM_設定水量基準値.U,1)+","
'	WriteStepstr=WriteStepstr+"水量補正値"+","+DASC(DM_水量補正値,1)+"," '+/- あり
'	WriteStepstr=WriteStepstr+"Aタンク送米設定値" +","+ DASC(DM_Aタンク設定値.U,1)+","
'	WriteStepstr=WriteStepstr+"Aタンク送米現在値" +","+ DASC(DM_Aタンク送米現在値.U,1)+","
'	WriteStepstr=WriteStepstr+"Bタンク送米設定値" +","+ DASC(DM_Bタンク設定値.U,1)+","
'	WriteStepstr=WriteStepstr+"Bタンク送米現在値" +","+ DASC(DM_Bタンク送米現在値.U,1)+","
'	WriteStepstr=WriteStepstr+"配米総数"+","+DASC(DM_配米総数.U,1)+","
'	WriteStepstr=WriteStepstr+"反転数"+","+DASC(DM_排出総数.U,1)
'	WriteStr.T=WriteStr.T+CHR($0D) 

'	1		2023/8/12 12:11    
'	2		エラー発生,送米開始,送米完了,配米開始,配米終了,炊飯完了
'	3,4		アイテム,EM4001.T,
'	5,6		配米総数,DM_配米総数.U,
'	7,8		設定水量,DM_設定水量基準値.U,
'	9,10	水量補正値,DM_水量補正値
'	11,12	Aタンク送米設定値,DM_Aタンク設定値.U
'	13,14	Aタンク送米現在値,DM_Aタンク送米現在値.U
'	15,16	Bタンク送米設定値,DM_Bタンク設定値.U
'	17,18	Bタンク送米現在値,DM_Bタンク送米現在値.U
'	19,20	反転数,DM_排出総数.U
'
'	ReadStr
'	1		strReadDATE
'	2		strReadStat
'	3,4		strReadLABEL1,strReadアイテム,
'	5,6		strReadLABEL2,strRead配米総数,
'	7,8		strReadLABEL3,strRead設定水量,
'	9,10	strReadLABEL4,strRead水量補正値,
'	11,12	strReadLABEL5,strReadAタンク送米設定値,
'	13,14	strReadLABEL6,strReadAタンク送米現在値,
'	15,16	strReadLABEL7,strReadBタンク送米設定値,
'	17,18	strReadLABEL8,strReadBタンク送米現在値,
'	19,20	strReadLABEL9,strRead反転数
'
'ReadStr.T="1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20"
'ReadCnt=SPLIT(ReadStr,",",strReadDATE,strReadStat,strReadLABEL1,strReadアイテム,strReadLABEL2,strRead配米総数,strReadLABEL3,strRead設定水量,strReadLABEL4,strTemp1)

'-----------------------------------------------------------------------------------------------------
if メインTP_表示中ページNo=213 or サブTP_表示中ページNo=213 or むらしTP_表示中ページNo=213 then

	
	if init=OFF then
		init=ON
		'--------------------------------------------------------------
		'表示バッファのクリア
		for loop=0 to 36 step 1
			ADRSET(生産アイテム1,ptr生産アイテム) '生産アイテム
			ADRADD(loop*16,ptr生産アイテム)
			*ptr生産アイテム=0
			生産釜数[loop]=RDASC(strRead配米総数)
			生産設定水量[loop]=RDASC(strRead設定水量)
		next
		アイテム表示日BIT0.U=0
		アイテム表示日BIT1.U=0
		アイテム表示日BIT2.U=0
		アイテム表示日BIT3.U=0
		'--------------------------------------------------------------
		カレンダー年 = 2000 + CM700
		カレンダー月 = CM701
		dsp更新=ON
	end if

	if dsp更新=OFF and  ReadFileStep=0 and ItemReadFileStep=0 then	
		if ldp(pnlPBel左移動) then
			if カレンダー月>1 then
				dec(カレンダー月)
				dsp更新=ON
			else if カレンダー年>2023 then
				dec(カレンダー年)
				カレンダー月=12
				dsp更新=ON
			else
				カレンダー月=1			
			end if
		else if ldp(pnlPBel右移動) then
			if カレンダー月<12 then
				inc(カレンダー月)
				dsp更新=ON
			else if カレンダー年<2050 then
				inc(カレンダー年)
				カレンダー月=1
				dsp更新=ON
			else
				カレンダー月=12			
			end if
		end if
	end if
	
	if ldp(dsp更新) then
	
		カレンダー年月 = STR(カレンダー年) +"/"+STR(カレンダー月)+"/1"
		カレンダー曜日=0
		カレンダー日数=0
		for loop=0 to 39 step 1
			カレンダー日付[loop]=0
		next
		for loop=0 to 3 step 1
			カレンダー表示日[loop]=0
		next

		'-------------------------------------------------------
		'曜日ラベル.csv 参照
		RES(readwaittim)
		ReadFileStep=1

		dsp更新=0
		
	end if

else
	init=OFF
end if

'--------------------------------------------------------------
if ReadFileStep>0 or ItemReadFileStep>0 then
	FileLoading表示=ON
else
	FileLoading表示=OFF
end if
'------------------------------------------------------------------------------------------'-----------------------------------------------------------------------------------------------------
select case ReadFileStep

case 0

case 1
	if readwaittim then
		inc(ReadFileStep)
	end if

case 2
	'--------------------------------------------------------------
	'表示バッファのクリア
	for loop=0 to 36 step 1
		ADRSET(生産アイテム1.T,ptr生産アイテム) '生産アイテム
		ADRADD(loop*16,ptr生産アイテム)
		*ptr生産アイテム=0
		生産釜数[loop]=RDASC(strRead配米総数)
		生産設定水量[loop]=RDASC(strRead設定水量)
	next
	アイテム表示日BIT0.U=0
	アイテム表示日BIT1.U=0
	アイテム表示日BIT2.U=0
	アイテム表示日BIT3.U=0
	'--------------------------------------------------------------

	ReadFileName.T="曜日ラベル.csv" 'ファイル名 曜日ラベル.csv
	initFileread=ON
	linecnt=0
	readpar[0]=0  '最初の行から読込
	readpar[1]=0  '最初の行から読込
	readpar[2]=200 '最大読込文字列
	inc(ReadFileStep)

case 3
	if initFileread or readerr[0] then
		if MREADL(ReadFileName,ReadStr,readpar,readerr) then
			inc(linecnt)
			ReadCnt=SPLIT(ReadStr.T,",",tmp日付,tmp曜日,tmp日数)
			
			if ReadCnt>=3 then
				if linecnt>=2 then
					loop=linecnt-2
						if tmp日付.T=カレンダー年月.T then
							カレンダー曜日=RDASC(tmp曜日)
							カレンダー日数=RDASC(tmp日数)
							days=0
							for loop=0 to カレンダー日数-1 step 1
								inc(days)
								カレンダー日付[カレンダー曜日+loop]=days
							next
							'--------------------------------------------
							カレンダー表示日[0]=$FFFF
							カレンダー表示日[1]=$FFFF
							カレンダー表示日[2]=$1F
							'--------------------------------------------
							if カレンダー日付[0]=0 then
								EM3300.00=OFF
							end if
							if カレンダー日付[1]=0 then
								EM3300.01=OFF
							end if
							if カレンダー日付[2]=0 then
								EM3300.02=OFF
							end if
							if カレンダー日付[3]=0 then
								EM3300.03=OFF
							end if
							if カレンダー日付[4]=0 then
								EM3300.04=OFF
							end if
							if カレンダー日付[5]=0 then
								EM3300.05=OFF
							end if
							if カレンダー日付[6]=0 then
								EM3300.06=OFF
							end if							
							'--------------------------------------------
							if カレンダー日付[28]=0 then
								EM3301.12=OFF
							end if
							if カレンダー日付[29]=0 then
								EM3301.13=OFF
							end if
							if カレンダー日付[30]=0 then
								EM3301.14=OFF
							end if
							if カレンダー日付[31]=0 then
								EM3301.15=OFF
							end if
							if カレンダー日付[32]=0 then
								EM3302.00=OFF
							end if
							if カレンダー日付[33]=0 then
								EM3302.01=OFF
							end if
							if カレンダー日付[34]=0 then
								EM3302.02=OFF
							end if
							'--------------------------------------------
							if カレンダー日付[35]=0 then
								EM3302.03=OFF
							end if
							if カレンダー日付[36]=0 then
								EM3302.04=OFF
							end if
							'--------------------------------------------
						end if
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
	
	'アイテム情報ファイル読込
	RES(readwaittim)
	ItemReadFileStep=1
	
end select


'-----------------------------------------------------------------------------------------------------------------------------
'生産情報ファイル読込
'-----------------------------------------------
'カレンダーへの日付書込み
'曜日ラベル.csvからy/m/1を検索して先頭の曜日と月の日数を取得し、カレンダー日付とカレンダー表示日のビットセットをする。
'	カレンダー年		1ワード符号なし整数	EM3200		検索する年
'	カレンダー月		1ワード符号なし整数	EM3201		検索する月
'	カレンダー年月		文字列[16]	EM3202				検索する年月の先頭2023/2/1
'	カレンダー曜日		1ワード符号なし整数	EM3222		検索する年月の先頭1日の曜日（月曜=0)
'	カレンダー日数		1ワード符号なし整数	EM3223		検索する年月の日数
'	カレンダー日付		1ワード符号なし整数[40]	EM3240	セルに表示する日にち(1~31)
'	カレンダー表示日	ビット[40]	EM3300				セルに表示・非表示設定 1=表示
'LOCAL	
'	炊飯日				ファイルに記憶された炊飯日 例  2023/8/12 8:23   -> 12 				
'	dspSEL =カレンダー曜日+炊飯日  １日のセル＋ファイルに記憶された炊飯日
'-----------------------------------------------
'カレンダーへの表示項目
'	生産アイテム1~40	文字列[16]
'	生産設定水量		1ワード符号なし整数[40]
'	生産釜数			1ワード符号なし整数[40]

'--------------------------------------------------------
'dspSEL =カレンダー曜日+炊飯日	登録するセルのアドレス
'--------------------------------------------------------
'[炊飯日の抽出]
'teststring="2023/9/11 9:22"

'ReadCnt=SPLIT(teststring,"/",tmpY,tmpM,tmpD)
'ReadCnt=SPLIT(tmpD," ",tmpDAY,tmpTIME)
'炊飯日=RDASC(tmpDAY)
'--------------------------------------------------------
'[カレンダーセルへのアイテム登録]
'strReadアイテム.T=""

'ADRSET(生産アイテム1.T,ptr生産アイテム) '生産アイテム
'ADRADD((dspSEL)*16,ptr生産アイテム)
'*ptr生産アイテム.T=""
'*ptr生産アイテム.T=strReadアイテム.
'生産釜数[dspSEL]=RDASC(strRead配米総数)
'生産設定水量[dspSEL]=RDASC(strRead設定水量)
'--------------------------------------------------------


TMR(readwaittim,#5)

'--------------------------------------------------------
select case ItemReadFileStep

case 0


case 1
	if readwaittim.B then
		inc(ItemReadFileStep)
	end if

case 2

	'--------------------------------------------------------------
	'表示バッファのクリア
	for loop=0 to 36 step 1
		ADRSET(生産アイテム1,ptr生産アイテム) '生産アイテム
		ADRADD(loop*16,ptr生産アイテム)
		*ptr生産アイテム=0
		生産釜数[loop]=RDASC(strRead配米総数)
		生産設定水量[loop]=RDASC(strRead設定水量)
	next
	アイテム表示日BIT0.U=0
	アイテム表示日BIT1.U=0
	アイテム表示日BIT2.U=0
	アイテム表示日BIT3.U=0	
	'--------------------------------------------------------------
	ReadFileName.T="UserDoc\"+"生産情報"+STR(カレンダー年)+STR(カレンダー月)+"."+"CSV" 'ファイル名
	initFileread=ON
	linecnt=0
	readpar[0]=0  '最初の行から読込
	readpar[1]=0  '最初の行から読込
	readpar[2]=200 '最大読込文字列
	'--------------------------------------------------------------
	inc(ItemReadFileStep)
	
case 3
	if initFileread or readerr[0] then
		if MREADL(ReadFileName,ReadStr,readpar,readerr) then
			inc(linecnt)

			ReadCnt=SPLIT(ReadStr,",",strReadDATE,strReadStat,strReadLABEL1,strReadアイテム,strReadLABEL2,strRead配米総数,strReadLABEL3,strRead設定水量,strReadLABEL4,strTemp1)
			
			if ReadCnt>=10 then
				if linecnt>=2 then
					loop=linecnt-2 '読み込んだ行数の何行目
						if strReadStat="炊飯完了" then
							ReadCnt=SPLIT(strReadDATE,"/",tmpY,tmpM,tmpD)
							ReadCnt=SPLIT(tmpD," ",tmpDAY,tmpTIME)
							炊飯日=RDASC(tmpDAY)
							
							dspSEL =カレンダー曜日+炊飯日-1
							ADRSET(生産アイテム1.T,ptr生産アイテム) '生産アイテム
							ADRADD(dspSEL*16,ptr生産アイテム)
							*ptr生産アイテム.T=strReadアイテム.T
							生産釜数[dspSEL]=RDASC(strRead配米総数)
							生産設定水量[dspSEL]=RDASC(strRead設定水量)
							アイテム表示日BIT0:dspSEL=ON
						end if
				end if 
			end if
				if initFileread or readparstak<>readpar[0] then
					readparstak=readpar[0]
					initFileread=OFF
				else
					inc(ItemReadFileStep)
				end if
		end if
	end if

case 4
	ItemReadFileStep=0
	
end select

'--------------------------------------------------------
