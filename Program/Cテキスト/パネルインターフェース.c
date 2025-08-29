'パネルインターフェース
'----------------------------------------------------------------------------------
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
'FindEndSec	2ワード符号なし整数
'FindStartSec	2ワード符号なし整数
'Find年月日	1ワード符号なし整数[6]
'dsp更新	ビット
'todaySec	2ワード符号なし整数
'-----------------------------------------------------------------------------------------------------------------------------
'ページ移動
	el現在ページNO=dspErrAnalIndex+1
	dspErrAnalOffset=dspErrAnalIndex*10

	if ldp(pnlPBel下限移動) then
		dspErrAnalIndex=4
	
	else if ldp(pnlPBel下移動) then
		
		if dspErrAnalIndex>=4 then
			dspErrAnalIndex=4
		else
			dspErrAnalIndex=dspErrAnalIndex+1
		end if
		
	else if ldp(pnlPBel上限移動) then
		dspErrAnalIndex=0
	
	else if ldp(pnlPBel上移動) then
		if dspErrAnalIndex>0 then
			dspErrAnalIndex=dspErrAnalIndex-1
		else
			dspErrAnalIndex=0
		end if
	end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel更新) or dsp更新 then
	FindStart年月日[0]=setFindStart年月日[0]
	FindStart年月日[1]=setFindStart年月日[1]
	FindStart年月日[2]=setFindStart年月日[2]
	setFindStart年月日[3]=0
	setFindStart年月日[4]=0
	setFindStart年月日[5]=0
	setFindEnd年月日[3]=23
	setFindEnd年月日[4]=59
	setFindEnd年月日[5]=0

	FindEnd年月日[0]=setFindEnd年月日[0]
	FindEnd年月日[1]=setFindEnd年月日[1]
	FindEnd年月日[2]=setFindEnd年月日[2]
	FindStart年月日[3]=0
	FindStart年月日[4]=0
	FindStart年月日[5]=0
	FindEnd年月日[3]=23
	FindEnd年月日[4]=59
	FindEnd年月日[5]=0
	
	Filereadstep=1
	dspErrAnalIndex=0
	dsp更新=OFF
	
end if

'----------------------------------------------------------------------------------
if ldp(pnlPBel今日) then
	pnlPBel今日=ON
	pnlPBel日=OFF
	pnlPBel週=OFF
	pnlPBel月=OFF
	init今日=ON	
else if ldp(pnlPBel日) then
	pnlPBel今日=OFF
	pnlPBel日=ON
	pnlPBel週=OFF
	pnlPBel月=OFF
	init日=ON
else if ldp(pnlPBel週) then
	pnlPBel今日=OFF
	pnlPBel日=OFF
	pnlPBel週=ON
	pnlPBel月=OFF
	init週=ON
else if ldp(pnlPBel月) then
	pnlPBel今日=OFF
	pnlPBel日=OFF
	pnlPBel週=OFF
	pnlPBel月=ON
	init月=ON
end if
'----------------------------------------------------------------------------------
if 	pnlPBel今日 then
	if init今日 then
		init今日=OFF	
	
		setFindStart年月日[0]=CM700
		setFindStart年月日[1]=CM701
		setFindStart年月日[2]=CM702
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702
	
		dspErrAnalIndex=0
		dsp更新=ON
	else if CM700<>FindStart年月日[0] or CM701<>FindStart年月日[1] or  CM702<>FindStart年月日[2] then
		
		setFindStart年月日[0]=CM700
		setFindStart年月日[1]=CM701
		setFindStart年月日[2]=CM702
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702
		
		dsp更新=ON
	
	end if

	

else if pnlPBel日 then
	if init日 then
		init日=OFF
		
		setFindStart年月日[0]=CM700
		setFindStart年月日[1]=CM701
		setFindStart年月日[2]=CM702
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702

		dspErrAnalIndex=0
		dsp更新=ON
	else if setFindStart年月日[0]<>FindStart年月日[0] or setFindStart年月日[1]<>FindStart年月日[1] or  setFindStart年月日[2]<>FindStart年月日[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702			
		else
			RSEC(FindStartSec,setFindStart年月日)
			RSEC(FindStartSec,setFindEnd年月日)			
		end if
		
		dsp更新=ON

	end if

	if ldp(pnlPBel左移動) then
		FindStartSec=SEC(setFindStart年月日)-86400
		RSEC(FindStartSec,setFindStart年月日)
		RSEC(FindStartSec,setFindEnd年月日)			
		
		dsp更新=ON

	else if ldp(pnlPBel右移動) then
	
		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=CM702
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		
		todaySec=SEC(Find年月日)
		
		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702			
		else
			FindStartSec=SEC(setFindStart年月日)+86400
			RSEC(FindStartSec,setFindStart年月日)
			RSEC(FindStartSec,setFindEnd年月日)			
		end if

		dsp更新=ON
	
	end if
	

else if pnlPBel週 then
	if init週 then
		init週=OFF

		FindStartSec=SEC(CM700)-518400
		RSEC(FindStartSec,setFindStart年月日)
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702

		dspErrAnalIndex=0
		dsp更新=ON
	else if setFindStart年月日[0]<>FindStart年月日[0] or setFindStart年月日[1]<>FindStart年月日[1] or  setFindStart年月日[2]<>FindStart年月日[2] then

		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
		else
			RSEC(FindStartSec,setFindStart年月日)	
		end if
		FindEndSec=SEC(setFindEnd年月日)+518400-1 '1週間
		if FindEndSec>=todaySec then
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd年月日)
		end if
		
		dsp更新=ON
		
	end if
	
	if ldp(pnlPBel左移動) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)-518400
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
		else
			RSEC(FindStartSec,setFindStart年月日)		
		end if
		
		FindEndSec=SEC(setFindStart年月日)+518400-1 '1週間
		if FindEndSec>=todaySec then
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd年月日)
		end if
		
		dsp更新=ON

	
	else if ldp(pnlPBel右移動) then
		todaySec=SEC(CM700)

		FindStartSec=SEC(setFindStart年月日)+518400
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=CM702
		else
			RSEC(FindStartSec,setFindStart年月日)
		end if
		FindEndSec=SEC(setFindStart年月日)+518400-1 '1週間
		if FindEndSec>=todaySec then
			setFindEnd年月日[0]=CM700
			setFindEnd年月日[1]=CM701
			setFindEnd年月日[2]=CM702
		else
			RSEC(FindEndSec,setFindEnd年月日)
		end if
		
		dsp更新=ON


	end if

else if	pnlPBel月 then
	setFindEnd年月日[0]=CM700
	setFindEnd年月日[1]=CM701
	setFindEnd年月日[2]=CM702

	if init月 then
		init月=OFF

		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		FindStartSec=SEC(Find年月日)
		RSEC(FindStartSec,setFindStart年月日)
		setFindEnd年月日[0]=CM700
		setFindEnd年月日[1]=CM701
		setFindEnd年月日[2]=CM702

		dspErrAnalIndex=0
		dsp更新=ON

	else if setFindStart年月日[0]<>FindStart年月日[0] or setFindStart年月日[1]<>FindStart年月日[1] or  setFindStart年月日[2]<>FindStart年月日[2] then

		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		todaySec=SEC(Find年月日)
		
		setFindStart年月日[2]=1 '強制的に1日にする
		
		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=1
		else
			RSEC(FindStartSec,setFindStart年月日)
		end if
		dsp更新=ON
		
	end if
	
	if ldp(pnlPBel左移動) then
		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		todaySec=SEC(Find年月日)

		setFindStart年月日[2]=1 '強制的に1日にする
		
		if setFindStart年月日[1]>=2 and setFindStart年月日[1]<=12 then
			setFindStart年月日[1]=setFindStart年月日[1]-1
		else if setFindStart年月日[1]=1 then
			setFindStart年月日[0]=setFindStart年月日[0]-1
			setFindStart年月日[1]=12
		end if
		
		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=1
		else
			RSEC(FindStartSec,setFindStart年月日)		
		end if
		
		dsp更新=ON

	
	else if ldp(pnlPBel右移動) then
		Find年月日[0]=CM700
		Find年月日[1]=CM701
		Find年月日[2]=1
		Find年月日[3]=0
		Find年月日[4]=0
		Find年月日[5]=0
		todaySec=SEC(Find年月日)

		setFindStart年月日[2]=1 '強制的に1日にする
		
		if setFindStart年月日[1]>=1 and setFindStart年月日[1]<12 then
			setFindStart年月日[1]=setFindStart年月日[1]+1
		else if setFindStart年月日[1]=12 then
			setFindStart年月日[0]=setFindStart年月日[0]+1
			setFindStart年月日[1]=1
		end if

		FindStartSec=SEC(setFindStart年月日)
		if FindStartSec>=todaySec then
			setFindStart年月日[0]=CM700
			setFindStart年月日[1]=CM701
			setFindStart年月日[2]=1
		else
			RSEC(FindStartSec,setFindStart年月日)
		end if

		dsp更新=ON


	end if

end if

'----------------------------------------------------------------------------------
' 切替ページ
if CR2008 then '電源ON時初期化処理
	
	メインTP_切替ページＮｏ=スタートアップ画面
	サブTP_切替ページＮｏ=スタートアップ画面
	むらしTP_切替ページＮｏ=スタートアップ画面
	
	
	MainStatusMsg=0
	前処理工程StatusMsg=0
	自動搬送StatusMsg=0
	計量StatusMsg=0
	洗米StatusMsg=0
	浸漬タンクAStatusMsg=0
	浸漬タンクBStatusMsg=0
	浸漬タンクAユニットStatusMsg=0
	浸漬タンクBユニットStatusMsg=0
	計水ユニットStatusMsg=0
	ならし装置StatusMsg=0
	蓋被せユニットStatusMsg=0
	蓋取りユニットStatusMsg=0
	ごはん検知StatusMsg=0
	バキュームユニットStatusMsg=0
	ほぐし機AユニットStatusMsg=0
	ほぐし機BユニットStatusMsg=0
	搬送コンベアAStatusMsg=0
	搬送コンベアBStatusMsg=0
	搬送コンベアCStatusMsg=0
	釜送りコンベアStatusMsg=0
	むらし機釜送りコンベアStatusMsg=0
	搬送コンベアDStatusMsg=0
	搬送コンベアEStatusMsg=0
	搬送コンベアFStatusMsg=0
	釜フタ昇降装置AStatusMsg=0
	釜反転入口StatusMsg=0
	洗浄入口リフトStatusMsg=0
	洗浄入口搬送StatusMsg=0
	洗浄ユニットStatusMsg=0
	洗浄タンクStatusMsg=0
	洗浄コンベア搬送StatusMsg=0
	洗浄出口搬送StatusMsg=0
	釜フタ昇降装置BStatusMsg=0	

else

	'--------------------------------------------------------------------------------	
	'異常履歴画面
	if ldp(自動搬送ErrStep<>0) then
		メインTP_切替ページＮｏ=異常履歴画面
		サブTP_切替ページＮｏ=異常履歴画面
		むらしTP_切替ページＮｏ=異常履歴画面
	
	'--------------------------------------------------------------------------------	
	'予約内容確認画面
	else if 予約確認 then
			if DM_Aタンク設定値<>0 or DM_Bタンク設定値<>0 then
				前処理設定完了=ON
				メインTP_切替ページＮｏ=12 '予約内容確認画面
			else
				前処理設定完了=OFF		
			end if
	'--------------------------------------------------------------------------------	
	end if

end if



'--------------------------------------------------------------------------------	
'----------------------------------------------------------------------------------
'アイテムアドレス参照
'
'
'ITEM TABLE
'       配米重量    計量水重量  アイテム名称
' 1		EM1020		EM1021(+1)	EM1030(+10)
' 2		EM1040(+20)	EM1041		EM1050
' 3		EM1060		EM1061		EM1070
' 4		EM1080		EM1081		EM1090

	'アイテム設定NO
	DM_ITEMNO=DM_ITEMNO

	if DM_ITEMNO>0 then
	
'			DM_計水目標下限1=DM_設定水量基準値+DM_水量補正値
'			DM_空釜計水目標下限1=DM_準備水量基準値+DM_水量補正値
		if 0 then
			'【配米重量】
			ADRSET(EM1020,ptrアイテム配米重量)
			ADRADD(20 * (DM_ITEMNO-1),ptrアイテム配米重量)
			DM_設定水量基準値=*ptrアイテム配米重量.U
			
			'【計量水重量】
			ADRSET(EM1021,ptrアイテム計量水重量)
			ADRADD(20 * (DM_ITEMNO-1),ptrアイテム計量水重量)
			DM_準備水量基準値=*ptrアイテム計量水重量
			
			'【アイテム名称】
			ADRSET(EM1030,ptrアイテム名称)
			ADRADD(20 * (DM_ITEMNO-1),ptrアイテム名称)
			' -- 文字バッファクリア --
			ADRSET(EM4001.U,loopptr)
			FOR loop=1 TO 10
				*loopptr.U=0
				inc(loopptr)
			NEXT
			'-- 文字列コピー
			EM4001.T=*ptrアイテム名称.T
		else
			'【配米重量】
			DM_設定水量基準値=アイテム設定水量[DM_ITEMNO]			
			'【計量水重量】
			DM_準備水量基準値=アイテム準備水量[DM_ITEMNO]
			
			' -- 文字バッファクリア --
			ADRSET(EM4001.U,loopptr)
			FOR loop=1 TO 10
				*loopptr.U=0
				inc(loopptr)
			NEXT
			'-- 文字列コピー
			ADRSET(アイテム名称1,ptrアイテム名称)
			ADRADD((DM_ITEMNO-1)*16,ptrアイテム名称)
			EM4001.T=*ptrアイテム名称.T
			
			
		
		end if

		
		
	else if DM_ITEMNO=0 then
		' -- 文字バッファクリア --
		ADRSET(EM4001.U,loopptr)
		FOR loop=1 TO 10
			*loopptr.U=0
			inc(loopptr)
		NEXT
		'-- 文字列空白
		EM4001.T=""	
	
	end if

	'--------------------------------------------------------------------------------------------
	' アルファ化米のビットセット
	'   ア             ル              フ            ァ              化              米
if 0 then
	if EM4001.U=$4183 and EM4002.U=$8B83 and EM4003.U=$7483 and EM4004.U=$4083 and EM4005.U=$BB89 and EM4006.U=$C495 then
		アルファ化米モード=ON
	else 
		アルファ化米モード=OFF
	end if
else
	if EM4001.U=$8341 and EM4002.U=$838B and EM4003.U=$8374 and EM4004.U=$8340 and EM4005.U=$89BB and EM4006.U=$95C4 then
		アルファ化米モード=ON
	else 
		アルファ化米モード=OFF
	end if
end if

'----------------------------------------------------------------------------------
' タッチパネルに登録されたメッセージ番号を書き込む
' xxxxStatusMsg=（メッセージ番号）
'
'----------------------------------------------------------------------------------
'	メッセージコード			
'		#0	'	メッセージなし
'----------------------------------------------------------------------------------
'	シーケンシャル運転状態
'	MainStatusMsg=0
'		MainStatusMsg=#100 '洗浄機タンク給湯中
'		MainStatusMsg=#102 '洗浄機タンク加熱中
'		MainStatusMsg=#103 '洗浄機タンク給湯中、加熱中
'		MainStatusMsg=#101 '洗浄機タンク準備完了
'		MainStatusMsg=#110 '炊飯運転スイッチを押してください。搬送コンベアが動作します。ご注意ください。
'		MainStatusMsg=#111 '炊飯機着火確認
'		MainStatusMsg=#112 '配米の準備が完了しました。
'		MainStatusMsg=#113 '自動運転中
'		MainStatusMsg=#120 '停止準備中
'		MainStatusMsg=#121 '停止準備中。炊飯機消火可能です。
'----------------------------------------------------------------------------------
'	前処理工程			
'	前処理工程StatusMsg=0
'		前処理工程StatusMsg=#20	'	前処理中
'		前処理工程StatusMsg=#21	'	浸漬中
'		前処理工程StatusMsg=#22	'	自動運転中
'		前処理工程StatusMsg=#23	'	停止準備中
'		前処理工程StatusMsg=#24	'	停止中
'----------------------------------------------------------------------------------
'	浸漬タンク		'	
'	浸漬タンクAユニットStatusMsg=0
'		浸漬タンクAユニットStatusMsg=#10	'	給水中
'		浸漬タンクAユニットStatusMsg=#11	'	送米中
'		浸漬タンクAユニットStatusMsg=#12	'	浸漬中
'		浸漬タンクAユニットStatusMsg=#13	'	配米中
'		浸漬タンクAユニットStatusMsg=#14	'	配米完了
'	浸漬タンクBユニットStatusMsg=0
'		浸漬タンクBユニットStatusMsg=#10	'	給水中
'		浸漬タンクBユニットStatusMsg=#11	'	送米中
'		浸漬タンクBユニットStatusMsg=#12	'	浸漬中
'		浸漬タンクBユニットStatusMsg=#13	'	配米中
'		浸漬タンクBユニットStatusMsg=#14	'	配米完了
'----------------------------------------------------------------------------------
'	ならし機		'
'	ならし装置StatusMsg=0
'		ならし装置StatusMsg=#30	'	待機中
'		ならし装置StatusMsg=#31	'	ならし中
'----------------------------------------------------------------------------------
'	フタ被せ
'	蓋被せユニットStatusMsg=0
'		蓋被せユニットStatusMsg=#40	'	フタ取り中
'		蓋被せユニットStatusMsg=#41	'	フタ被せ待機中（フタを持っている状態）
'		蓋被せユニットStatusMsg=#42	'	フタ置き中
'		蓋被せユニットStatusMsg=#43	'	待機中（フタを持っていない）
'----------------------------------------------------------------------------------
'	フタ取り
'	蓋取りユニットStatusMsg=0
'		蓋取りユニットStatusMsg=#45	'	待機中
'		蓋取りユニットStatusMsg=#46	'	フタ取り中
'		蓋取りユニットStatusMsg=#47	'	フタ置き中
'----------------------------------------------------------------------------------
'	炊飯釜確認装置
'	ごはん検知StatusMsg=0
'		ごはん検知StatusMsg=#50	'	待機中
'		ごはん検知StatusMsg=#51	'	確認中
'		ごはん検知StatusMsg=#56	'	水釜
'		ごはん検知StatusMsg=#57	'	米飯釜
'----------------------------------------------------------------------------------
'	水釜バキューマ
'	バキュームユニットStatusMsg=0
'		バキュームユニットStatusMsg=#60	'	待機中
'		バキュームユニットStatusMsg=#61	'	吸水中
'----------------------------------------------------------------------------------
'	釜洗浄機
'	洗浄ユニットStatusMsg=0
'		洗浄ユニットStatusMsg=#70	'	待機中
'		洗浄ユニットStatusMsg=#71	'	準備中
'		洗浄ユニットStatusMsg=#72	'	運転中
'----------------------------------------------------------------------------------

System変更通知=洗浄ユニット1禁止 or 洗浄ユニット2禁止 or 洗浄ユニット3禁止 or 洗浄ユニット4禁止 or 洗浄ユニット5禁止  
System変更通知=System変更通知 or not(計水ユニット許可) or not(ならし装置許可) or not(蓋被せユニット許可) or not(蓋取りユニット許可)

'----------------------------------------------------------------------------------

IND_配米準備=IND_配米準備
IND_配米中=IND_配米中
IND_炊飯中=IND_炊飯中
IND_炊飯完了=IND_炊飯完了
IND_停止待機=IND_停止待機
IND_洗浄準備中=IND_洗浄準備中

'----------------------------------------------------------------------------------

if PH25_釜検知 and StageDevice19=$9000 then
	IND_StageDevice19=ON
else
	IND_StageDevice19=OFF
end if

if PH27_釜検知 and StageDevice20=$9000 then
	IND_StageDevice20=ON
else
	IND_StageDevice20=OFF
end if

if PH29_釜検知 and StageDevice21=$9000 then
	IND_StageDevice21=ON
else
	IND_StageDevice21=OFF
end if

if PH31_釜検知 and StageDevice22=$9000 then
	IND_StageDevice22=ON
else
	IND_StageDevice22=OFF
end if

if PH32_釜検知 and StageDevice23=$9000 then
	IND_StageDevice23=ON
else
	IND_StageDevice23=OFF
end if

if PH34_釜検知 and StageDevice24=$9000 then
	IND_StageDevice24=ON
else
	IND_StageDevice24=OFF
end if

if PH36_釜検知 and StageDevice25=$9000 then
	IND_StageDevice25=ON
else
	IND_StageDevice25=OFF
end if

if PH38_釜検知 and StageDevice26=$9000 then
	IND_StageDevice26=ON
else
	IND_StageDevice26=OFF
end if

IND_StageDevice27=OFF
IND_StageDevice28=OFF


'----------------------------------------------------------------------------------
'強制米無し 

	pnlPBL強制米有A=pnlPB強制米有A and CR2006
	pnlPBL強制米無しA=pnlPB強制米無しA and CR2006
	
	pnlPBL強制米有B=pnlPB強制米有B and CR2006
	pnlPBL強制米無しB=pnlPB強制米無しB and CR2006

'----------------------------------------------------------------------------------
' 異常画面から戻るときにアラーム確定時のビットをクリアする

if INDalmビットクリア then
 FMOV(0,R90000.U,58)  'R90000 ~ R95715
end if

if ldp(バキューム禁止) then
	強制バキューム=OFF
else if ldp(強制バキューム) then
	バキューム禁止=OFF
end if 

if ldp(反転ほぐし機A禁止) then
	強制反転A=OFF
else if ldp(強制反転A) then
	反転ほぐし機A禁止=OFF
end if

if ldp(反転ほぐし機B禁止) then
	強制反転B=OFF
else if ldp(強制反転B) then
	反転ほぐし機B禁止=OFF
end if
'----------------------------------------------------------------------------------
'運転モニタ コンベア  pnlXSWxxx
INDpnlPBXSW=pnlPBXSW11_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW12_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW13_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW14_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW15_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW16_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW17_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW18_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW19_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW20_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW21_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW22_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW74_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW75_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW37_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW38_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW33_クランプ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW34_クランプ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW29_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW30_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW35_クランプ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW36_クランプ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW31_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW32_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW47_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW48_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW45_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW46_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW71_バキューマリフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW72_バキューマリフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW49_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW50_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW53_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW54_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW51_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW52_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW63_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW64_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW65_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW66_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW67_リフト下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW68_リフト上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW69_ストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW70_ストッパ上昇端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW85_釜フタストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW90_釜フタストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW95_釜フタストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW100_釜フタストッパ下降端
INDpnlPBXSW=INDpnlPBXSW or pnlPBXSW105_釜フタストッパ下降端
'運転モニタ コンベア  pnlXSWxxx + コンベア禁止箇所
INDpnlPBXSW禁止 = INDpnlPBXSW 
INDpnlPBXSW禁止 = INDpnlPBXSW禁止 or pnlPBLS5_空釜反転原点位置
INDpnlPBXSW禁止 = INDpnlPBXSW禁止 or pnlPBLS6_空釜反転反転位置
INDpnlPBXSW禁止 = INDpnlPBXSW禁止 or pnlPBLS7_釜反転機原点位置
INDpnlPBXSW禁止 = INDpnlPBXSW禁止 or pnlPBLS8_釜反転機反転位置
INDpnlPBXSW禁止 = INDpnlPBXSW禁止 or 釜送りコンベア禁止
INDpnlPBXSW禁止 = INDpnlPBXSW禁止 or むらし釜送りコンベア禁止
INDpnlPBXSW禁止 = INDpnlPBXSW禁止 or 洗浄搬送禁止
'運転モニタ ユニット pnlXSWxxx
INDpnlPBXSWUnit=pnlPBXSW1_充填バルブ開A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW2_充填バルブ閉A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW3_水切りシャッター開A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW4_水切りシャッター閉A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW5_充填バルブ開B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW6_充填バルブ閉B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW7_水切りシャッター開B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW8_水切りシャッター閉B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW9_送米切換A側
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW10_送米切換B側
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW23_ならし後退端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW24_ならし前進端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW25_ならし上昇端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW26_ならし下降端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW27_ならし後退端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW28_ならし前進端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW111_釜位置右後退端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW112_釜位置左後退端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW39_シリンダ上昇端A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW40_シリンダ下降端A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW41_シリンダ上昇端B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW42_シリンダ下降端B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW43_クランプ
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW44_アンクランプ
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW55_シリンダ上昇端A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW56_シリンダ下降端A
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW57_シリンダ上昇端B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW58_シリンダ下降端B
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW59_アンクランプ
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW60_クランプ
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW73_シリンダ上昇端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW80_シリンダ下降端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW61_シリンダ上昇端
INDpnlPBXSWUnit=INDpnlPBXSWUnit or pnlPBXSW62_シリンダ下降端
'オートスイッチが破損しています。サービスマンに連絡してください。
MSGXSWl破損 = INDpnlPBXSW or INDpnlPBXSWUnit
