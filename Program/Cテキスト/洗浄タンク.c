'洗浄タンク
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄タンクユニット
'	
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    洗浄タンクAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    洗浄タンクAutoRun=OFF
    洗浄タンク許可=ON
    洗浄タンクOrgErr=OFF
    洗浄タンクErr=OFF
    洗浄タンクEmg=OFF
    洗浄タンクstep=0
    洗浄タンクErrStep=0
    洗浄タンクOrgErrStep=0
    洗浄タンクEmgStep=0
	
	set(tim_notFLT1_タンク上限) '上限ヒステリシスタイマー
	set(tim_notFLT3_タンク上限) '上限ヒステリシスタイマー
	set(tim_notFLT5_タンク上限) '上限ヒステリシスタイマー
	set(tim_notFLT7_タンク上限) '上限ヒステリシスタイマー
	set(tim_notFLT9_タンク上限) '上限ヒステリシスタイマー
end if
'===================================================================================================================
'【 原点 】
洗浄タンクOrg=1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	洗浄タンクEmg=ON
	洗浄タンクEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出

tmr(SV69_給湯電磁弁 and not(FLT2_タンク下限) and not(pnlPBFLT2_タンク下限),tim_FLT2_タンク下限,#100)
tmr(SV69_給湯電磁弁 and FLT2_タンク下限 and not(FLT1_タンク上限) and not(pnlPBFLT1_タンク上限),tim_FLT1_タンク上限,#100)
tmr(SV75_給湯電磁弁 and not(FLT4_タンク下限) and not(pnlPBFLT4_タンク下限),tim_FLT4_タンク下限,#100)
tmr(SV75_給湯電磁弁 and FLT4_タンク下限 and not(FLT3_タンク上限) and not(pnlPBFLT3_タンク上限),tim_FLT3_タンク上限,#100)
tmr(SV81_給湯電磁弁 and not(FLT6_タンク下限) and not(pnlPBFLT6_タンク下限),tim_FLT6_タンク下限,#100)
tmr(SV81_給湯電磁弁 and FLT6_タンク下限 and not(FLT5_タンク上限) and not(pnlPBFLT5_タンク上限),tim_FLT5_タンク上限,#100)
tmr(SV87_給湯電磁弁 and not(FLT8_タンク下限) and not(pnlPBFLT8_タンク下限),tim_FLT8_タンク下限,#100)
tmr(SV87_給湯電磁弁 and FLT8_タンク下限 and not(FLT7_タンク上限) and not(pnlPBFLT7_タンク上限),tim_FLT7_タンク上限,#100)
tmr(SV93_給湯電磁弁 and not(FLT10_タンク下限) and not(pnlPBFLT10_タンク下限),tim_FLT10_タンク下限,#100)
tmr(SV93_給湯電磁弁 and FLT10_タンク下限 and not(FLT9_タンク上限) and not(pnlPBFLT9_タンク上限),tim_FLT9_タンク上限,#100)


if getEDC1_PV>85 then
	if ldp(getEDC1_PV>85)  then
	 	almSV70_蒸気電磁弁=ON
		洗浄タンクErrStep=1
	end if
	SV70_蒸気電磁弁=OFF
	mSV70_蒸気電磁弁=OFF
	pauseSV70_蒸気電磁弁=OFF
end if
if getEDC2_PV>85 then
	if ldp(getEDC2_PV>85) then
	 	almSV76_蒸気電磁弁=ON
		洗浄タンクErrStep=1
	end if
	SV76_蒸気電磁弁=OFF
	mSV76_蒸気電磁弁=OFF
	pauseSV76_蒸気電磁弁=OFF
end if
if getEDC3_PV>85 then
	if ldp(getEDC3_PV>85) then
	 	almSV82_蒸気電磁弁=ON
		洗浄タンクErrStep=1
	end if
	SV82_蒸気電磁弁=OFF
	mSV82_蒸気電磁弁=OFF
	pauseSV82_蒸気電磁弁=OFF
end if
if getEDC4_PV>85 then
	if ldp(getEDC4_PV>85) then
	 	almSV88_蒸気電磁弁=ON
		洗浄タンクErrStep=1
	end if
	SV88_蒸気電磁弁=OFF
	mSV88_蒸気電磁弁=OFF
	pauseSV88_蒸気電磁弁=OFF
end if
if getEDC5_PV>85 then
	if ldp(getEDC5_PV>85) then
	 	almSV94_蒸気電磁弁=ON
		洗浄タンクErrStep=1
	end if
	SV94_蒸気電磁弁=OFF
	mSV94_蒸気電磁弁=OFF
	pauseSV94_蒸気電磁弁=OFF
end if	

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄タンクAutoMode	自動モード セレクトスイッチ
'System :: 洗浄タンクAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄タンクEmg	その場停止

'------------------------------------------------------------------------------------------
'ヒステリシスタイマー
'------------------------------------------------------------------------------------------
tmr(tim_notFLT1_タンク上限,#100) '上限ヒステリシスタイマー
tmr(tim_notFLT3_タンク上限,#100) '上限ヒステリシスタイマー
tmr(tim_notFLT5_タンク上限,#100) '上限ヒステリシスタイマー
tmr(tim_notFLT7_タンク上限,#100) '上限ヒステリシスタイマー
tmr(tim_notFLT9_タンク上限,#100) '上限ヒステリシスタイマー
'------------------------------------------------------------------------------------------
'温度調節器制御
'
' 83℃で共振する。（推定要因：バルブの熱による共振）
'------------------------------------------------------------------------------------------
	if not(timFLT2_タンク下限.B)  then
		mSV70_蒸気電磁弁=OFF
	end if

	if not(timFLT4_タンク下限.B)  then
		mSV76_蒸気電磁弁=OFF
	end if

	if not(timFLT6_タンク下限.B) then
		mSV82_蒸気電磁弁=OFF
	end if
	
	if not(timFLT8_タンク下限.B) then
		mSV88_蒸気電磁弁=OFF
	end if
	
	if not(timFLT10_タンク下限.B) then
		mSV94_蒸気電磁弁=OFF
	end if


	if mSV70_蒸気電磁弁 then
		if ANDA(getEDC1_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8  and not(温度調節器1Alm) then
			pauseSV70_蒸気電磁弁=OFF '一時停止解除
		else
			pauseSV70_蒸気電磁弁=ON '一時停止	
		end if
	else
		pauseSV70_蒸気電磁弁=OFF '一時停止解除
	end if

	if mSV76_蒸気電磁弁 then
		if  ANDA(getEDC2_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(温度調節器2Alm) then
			pauseSV76_蒸気電磁弁=OFF
		else
			pauseSV76_蒸気電磁弁=ON
		end if
	else
		pauseSV76_蒸気電磁弁=OFF
	end if

	if mSV82_蒸気電磁弁 then
		if  ANDA(getEDC3_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(温度調節器3Alm) then
			pauseSV82_蒸気電磁弁=OFF
		else
			pauseSV82_蒸気電磁弁=ON
		end if
	else
		pauseSV82_蒸気電磁弁=OFF
	end if
	
	if mSV88_蒸気電磁弁 then
		if ANDA(getEDC4_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(温度調節器4Alm) then
			pauseSV88_蒸気電磁弁=OFF
		else
			pauseSV88_蒸気電磁弁=ON
		end if
	else
		pauseSV88_蒸気電磁弁=OFF	
	end if
	
	if mSV94_蒸気電磁弁 then
		if ANDA(getEDC5_ST1L,EDC_ST1LBT8)=EDC_ST1LBT8 and not(温度調節器5Alm) then
			pauseSV94_蒸気電磁弁=OFF
		else
			pauseSV94_蒸気電磁弁=ON
		end if
	else
		pauseSV94_蒸気電磁弁=OFF
	end if
'------------------------------------------------------------------------------------------
if not(PB45_全停止SW) and not(自動搬送AutoMode) then
		洗浄タンクAutoRun=OFF
end if

if ldp(PB36_給水SW) then
	if 洗浄タンクAutoRun and not(自動搬送AutoRun) and not(テスト運転) then
		洗浄タンクAutoRun=OFF
	else 
		洗浄タンクAutoRun=ON
	end if
end if

PBL36_給水=洗浄タンクAutoRun
PBL42_ヒータ=洗浄タンクAutoRun

'------------------------------------------------------------------------------------------



if 洗浄タンクEmgStep=0 then  
	
	if 洗浄タンクErrStep=0 then

	'if 洗浄タンクAutoMode and 自動搬送AutoMode then
	if 洗浄タンクAutoRun then

	'===================================================================================================================
	'【 プロセス処理 】
	'
		if 洗浄タンクAutoRun then
			手動初期起動=OFF

			'-----------------------
			'	1：給湯  , 蒸気
			'-----------------------			
			if timFLT2_タンク下限.B and getEDC1_PV<=85 then
				mSV70_蒸気電磁弁=ON
			else
				mSV70_蒸気電磁弁=OFF
			end if
		
			
			if not(timFLT1_タンク上限.B) and not(timFLT2_タンク下限.B) then
				mSV69_給湯電磁弁=ON	
			else if not(timFLT1_タンク上限.B) and tim_notFLT1_タンク上限.B and timFLT2_タンク下限.B  then
				mSV69_給湯電磁弁=ON	
			else if timFLT1_タンク上限.B and timFLT2_タンク下限.B then
				mSV69_給湯電磁弁=OFF
				res(tim_notFLT1_タンク上限)
			end if
			
			'-----------------------
			'	2：給湯  , 蒸気
			'-----------------------
			if timFLT4_タンク下限.B and getEDC2_PV<=85 then
				mSV76_蒸気電磁弁=ON
			else
				mSV76_蒸気電磁弁=OFF
			end if
		
			if not(timFLT3_タンク上限.B) and not(timFLT4_タンク下限.B) then
				mSV75_給湯電磁弁=ON	
			else if not(timFLT3_タンク上限.B) and tim_notFLT3_タンク上限.B and timFLT4_タンク下限.B then
				mSV75_給湯電磁弁=ON	
			else if timFLT3_タンク上限.B and timFLT4_タンク下限.B then
				mSV75_給湯電磁弁=OFF
				res(tim_notFLT3_タンク上限)
			end if
			'-----------------------
			'	3：給湯  , 蒸気
			'-----------------------
			if timFLT6_タンク下限.B and getEDC3_PV<=85 then
				mSV82_蒸気電磁弁=ON
			else 
				mSV82_蒸気電磁弁=OFF
			end if

			if not(timFLT5_タンク上限.B) and not(timFLT6_タンク下限.B) then
				mSV81_給湯電磁弁=ON	
			else if not(timFLT5_タンク上限.B) and tim_notFLT5_タンク上限.B and timFLT6_タンク下限.B then
				mSV81_給湯電磁弁=ON	
			else if timFLT5_タンク上限.B and timFLT6_タンク下限.B then
				mSV81_給湯電磁弁=OFF
				res(tim_notFLT5_タンク上限)
			end if
			'-----------------------
			'	  4：給湯  , 蒸気
			'-----------------------
			if timFLT8_タンク下限.B and getEDC4_PV<=85 then
				mSV88_蒸気電磁弁=ON
			else
				mSV88_蒸気電磁弁=OFF
			end if
			
			if not(timFLT7_タンク上限.B) and not(timFLT8_タンク下限.B) then
				mSV87_給湯電磁弁=ON	
			else if not(timFLT7_タンク上限.B) and tim_notFLT7_タンク上限.B and timFLT8_タンク下限.B then
				mSV87_給湯電磁弁=ON	
			else if timFLT7_タンク上限.B and timFLT8_タンク下限.B then
				mSV87_給湯電磁弁=OFF
				res(tim_notFLT7_タンク上限)
			end if
			'-----------------------
			'	  5：給湯  , 蒸気
			'-----------------------
			if timFLT10_タンク下限.B and getEDC5_PV<=85 then
				mSV94_蒸気電磁弁=ON
			else
				mSV94_蒸気電磁弁=OFF
			end if
		
			if not(timFLT9_タンク上限.B) and not(timFLT10_タンク下限.B) then
				mSV93_給湯電磁弁=ON	
			else if not(timFLT9_タンク上限.B) and tim_notFLT9_タンク上限.B and timFLT10_タンク下限.B then
				mSV93_給湯電磁弁=ON	
			else if timFLT9_タンク上限.B and timFLT10_タンク下限.B then
				mSV93_給湯電磁弁=OFF
				res(tim_notFLT9_タンク上限)
			end if
		
		else
			mSV70_蒸気電磁弁=OFF
			mSV69_給湯電磁弁=OFF
			
			mSV76_蒸気電磁弁=OFF
			mSV75_給湯電磁弁=OFF
			
			mSV82_蒸気電磁弁=OFF
			mSV81_給湯電磁弁=OFF
			
			mSV88_蒸気電磁弁=OFF
			mSV87_給湯電磁弁=OFF
			
			mSV94_蒸気電磁弁=OFF
			mSV93_給湯電磁弁=OFF
			
		end if
			

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		'給湯、給水は自動、手動関係なくマニュアル操作可能なこと
		'AutoモードOFFでのマニュアル動作部分はない
		
		if not(手動初期起動) then
			手動初期起動=ON

			mSV69_給湯電磁弁=OFF
			mSV70_蒸気電磁弁=OFF
	
			mSV75_給湯電磁弁=OFF
			mSV76_蒸気電磁弁=OFF

			mSV81_給湯電磁弁=OFF
			mSV82_蒸気電磁弁=OFF

			mSV87_給湯電磁弁=OFF
			mSV88_蒸気電磁弁=OFF

			mSV93_給湯電磁弁=OFF
			mSV94_蒸気電磁弁=OFF
			
			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF
		
		
			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp1SV93_給湯電磁弁=OFF
			tmp2SV93_給湯電磁弁=OFF
			tmp_蒸気電磁弁=OFF
			tmp1SV70_蒸気電磁弁=OFF
			tmp2SV70_蒸気電磁弁=OFF
			tmp1SV76_蒸気電磁弁=OFF
			tmp2SV76_蒸気電磁弁=OFF
			tmp1SV82_蒸気電磁弁=OFF
			tmp2SV82_蒸気電磁弁=OFF
			tmp1SV88_蒸気電磁弁=OFF
			tmp2SV88_蒸気電磁弁=OFF
			tmp1SV94_蒸気電磁弁=OFF
			tmp2SV94_蒸気電磁弁=OFF
		end if
		
		if ldp(pnlPBSV97_すすぎ電磁弁) then
			if mSV97_すすぎ電磁弁 then
				mSV97_すすぎ電磁弁=OFF
			else
				mSV97_すすぎ電磁弁=ON
			end if
		end if
		if ldp(pnlPBSV98_仕上げ電磁弁) then
			if mSV98_仕上げ電磁弁 then
				mSV98_仕上げ電磁弁=OFF
			else
				mSV98_仕上げ電磁弁=ON
			end if
		end if

		mSV69_給湯電磁弁=tmp1SV69_給湯電磁弁 or tmp2SV69_給湯電磁弁
		mSV75_給湯電磁弁=tmp1SV75_給湯電磁弁 or tmp2SV75_給湯電磁弁
		mSV81_給湯電磁弁=tmp1SV81_給湯電磁弁 or tmp2SV81_給湯電磁弁
		mSV87_給湯電磁弁=tmp1SV87_給湯電磁弁 or tmp2SV87_給湯電磁弁
		mSV93_給湯電磁弁=tmp1SV93_給湯電磁弁 or tmp2SV93_給湯電磁弁
		
		mSV70_蒸気電磁弁=(tmp1SV70_蒸気電磁弁 or tmp2SV70_蒸気電磁弁) and FLT2_タンク下限
		mSV76_蒸気電磁弁=(tmp1SV76_蒸気電磁弁 or tmp2SV76_蒸気電磁弁) and FLT4_タンク下限
		mSV82_蒸気電磁弁=(tmp1SV82_蒸気電磁弁 or tmp2SV82_蒸気電磁弁) and FLT6_タンク下限
		mSV88_蒸気電磁弁=(tmp1SV88_蒸気電磁弁 or tmp2SV88_蒸気電磁弁) and FLT8_タンク下限
		mSV94_蒸気電磁弁=(tmp1SV94_蒸気電磁弁 or tmp2SV94_蒸気電磁弁) and FLT10_タンク下限


		if PB45_全停止SW then 
			'----------------
			'コマンドSW操作
			'----------------
			if SEL2_1_運転切換（単動） then 'B接点
				tmp2SV69_給湯電磁弁=OFF
				tmp2SV75_給湯電磁弁=OFF
				tmp2SV81_給湯電磁弁=OFF
				tmp2SV87_給湯電磁弁=OFF
				tmp2SV93_給湯電磁弁=OFF

				tmp2SV70_蒸気電磁弁=OFF
				tmp2SV76_蒸気電磁弁=OFF
				tmp2SV82_蒸気電磁弁=OFF
				tmp2SV88_蒸気電磁弁=OFF
				tmp2SV94_蒸気電磁弁=OFF
			'--------------------------------------------------------------
				'if ldp(PB36_給水SW) then
				'	if tmp_給湯電磁弁 then
				'		tmp_給湯電磁弁=OFF
				'	else
				'		tmp_給湯電磁弁=ON
				'	end if
				'end if
				
				'tmp1SV69_給湯電磁弁=tmp_給湯電磁弁
				'tmp1SV75_給湯電磁弁=tmp_給湯電磁弁
				'tmp1SV81_給湯電磁弁=tmp_給湯電磁弁
				'tmp1SV87_給湯電磁弁=tmp_給湯電磁弁
				'tmp1SV93_給湯電磁弁=tmp_給湯電磁弁
			'--------------------------------------------------------------
				'if ldp(PB42_ヒータSW) then 
				'	if tmp_蒸気電磁弁 then
				'		tmp_蒸気電磁弁=OFF
				'	else
				'		tmp_蒸気電磁弁=ON
				'	end if
				'end if
					
				'if tmp_蒸気電磁弁 and FLT2_タンク下限 then
				'	tmp1SV70_蒸気電磁弁=ON
				'else
				'	tmp1SV70_蒸気電磁弁=OFF
				'end if
				'----------------
				'if tmp_蒸気電磁弁 and FLT4_タンク下限 then
				'	tmp1SV76_蒸気電磁弁=ON
				'else
				'	tmp1SV76_蒸気電磁弁=OFF
				'end if
				'----------------
				'if tmp_蒸気電磁弁 and FLT6_タンク下限 then
				'	tmp1SV82_蒸気電磁弁=ON
				'else
				'	tmp1SV82_蒸気電磁弁=OFF
				'end if
				'----------------			
				'if tmp_蒸気電磁弁 and FLT8_タンク下限 then
				'	tmp1SV88_蒸気電磁弁=ON
				'else
				'	tmp1SV88_蒸気電磁弁=OFF
				'end if
				'----------------
				'if tmp_蒸気電磁弁 and FLT10_タンク下限 then
				'	tmp1SV94_蒸気電磁弁=ON
				'else
				'	tmp1SV94_蒸気電磁弁=OFF
				'end if
				'----------------

			else
				tmp_給湯電磁弁=OFF
				tmp1SV69_給湯電磁弁=OFF
				tmp1SV75_給湯電磁弁=OFF
				tmp1SV81_給湯電磁弁=OFF
				tmp1SV87_給湯電磁弁=OFF
				tmp1SV93_給湯電磁弁=OFF
				tmp_蒸気電磁弁=OFF
				tmp1SV70_蒸気電磁弁=OFF
				tmp1SV76_蒸気電磁弁=OFF
				tmp1SV82_蒸気電磁弁=OFF
				tmp1SV88_蒸気電磁弁=OFF
				tmp1SV94_蒸気電磁弁=OFF
				
				'----------------			
				' パネル操作	
				'----------------			
				if ldp(pnlPBSV69_給湯電磁弁) then
					if tmp2SV69_給湯電磁弁 then
						tmp2SV69_給湯電磁弁=OFF
					else
						tmp2SV69_給湯電磁弁=ON
					end if
				end if
				'----------------						
				if ldp(pnlPBSV75_給湯電磁弁) then
					if tmp2SV75_給湯電磁弁 then
						tmp2SV75_給湯電磁弁=OFF
					else
						tmp2SV75_給湯電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV81_給湯電磁弁) then
					if tmp2SV81_給湯電磁弁 then
						tmp2SV81_給湯電磁弁=OFF
					else
						tmp2SV81_給湯電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV87_給湯電磁弁) then
					if tmp2SV87_給湯電磁弁 then
						tmp2SV87_給湯電磁弁=OFF
					else
						tmp2SV87_給湯電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV93_給湯電磁弁) then
					if tmp2SV93_給湯電磁弁 then
						tmp2SV93_給湯電磁弁=OFF
					else
						tmp2SV93_給湯電磁弁=ON
					end if
				end if
				'--------------------------------------------------------------
				if ldp(pnlPBSV70_蒸気電磁弁) then
					if tmp2SV70_蒸気電磁弁 then
						tmp2SV70_蒸気電磁弁=OFF
					else if FLT2_タンク下限 then
						tmp2SV70_蒸気電磁弁=ON
					end if
				end if
				'----------------
					if ldp(pnlPBSV76_蒸気電磁弁) then
					if tmp2SV76_蒸気電磁弁 then
						tmp2SV76_蒸気電磁弁=OFF
					else if FLT4_タンク下限 then
						tmp2SV76_蒸気電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV82_蒸気電磁弁) then
					if tmp2SV82_蒸気電磁弁 then
						tmp2SV82_蒸気電磁弁=OFF
					else if FLT6_タンク下限 then
						tmp2SV82_蒸気電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV88_蒸気電磁弁) then
					if tmp2SV88_蒸気電磁弁 then
						tmp2SV88_蒸気電磁弁=OFF
					else if FLT8_タンク下限 then
						tmp2SV88_蒸気電磁弁=ON
					end if
				end if
				'----------------
				if ldp(pnlPBSV94_蒸気電磁弁) then
					if tmp2SV94_蒸気電磁弁 then
						tmp2SV94_蒸気電磁弁=OFF
					else if FLT10_タンク下限 then
						tmp2SV94_蒸気電磁弁=ON
					end if
				end if
				'--------------------------------------------------------------
					
				

			end if
		else
			PBL36_給水=OFF
			PBL42_ヒータ=OFF
		
			mSV69_給湯電磁弁=OFF
			mSV70_蒸気電磁弁=OFF
	
			mSV75_給湯電磁弁=OFF
			mSV76_蒸気電磁弁=OFF

			mSV81_給湯電磁弁=OFF
			mSV82_蒸気電磁弁=OFF

			mSV87_給湯電磁弁=OFF
			mSV88_蒸気電磁弁=OFF

			mSV93_給湯電磁弁=OFF
			mSV94_蒸気電磁弁=OFF
		
			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF
		
			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp1SV93_給湯電磁弁=OFF
			tmp2SV93_給湯電磁弁=OFF
			tmp_蒸気電磁弁=OFF
			tmp1SV70_蒸気電磁弁=OFF
			tmp2SV70_蒸気電磁弁=OFF
			tmp1SV76_蒸気電磁弁=OFF
			tmp2SV76_蒸気電磁弁=OFF
			tmp1SV82_蒸気電磁弁=OFF
			tmp2SV82_蒸気電磁弁=OFF
			tmp1SV88_蒸気電磁弁=OFF
			tmp2SV88_蒸気電磁弁=OFF
			tmp1SV94_蒸気電磁弁=OFF
			tmp2SV94_蒸気電磁弁=OFF
		end if
		

	
	end if
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		洗浄タンクErr=ON

		if almSV70_蒸気電磁弁 or almSV76_蒸気電磁弁 or almSV82_蒸気電磁弁 or almSV88_蒸気電磁弁 or almSV94_蒸気電磁弁 then
		
			select case 洗浄タンクErrStep
			case 0
			case 1
				if ResetFlg then
					almSV70_蒸気電磁弁=OFF
					almSV76_蒸気電磁弁=OFF
					almSV82_蒸気電磁弁=OFF
					almSV88_蒸気電磁弁=OFF
					almSV94_蒸気電磁弁=OFF
					inc(洗浄タンクErrStep)
				end if
			case 2
				洗浄タンクErr=OFF

				洗浄タンクErrStep=0
			end select
		
		else 

			mSV70_蒸気電磁弁=OFF
			mSV69_給湯電磁弁=OFF
			
			mSV76_蒸気電磁弁=OFF
			mSV75_給湯電磁弁=OFF
			
			mSV82_蒸気電磁弁=OFF
			mSV81_給湯電磁弁=OFF
			
			mSV88_蒸気電磁弁=OFF
			mSV87_給湯電磁弁=OFF
			
			mSV94_蒸気電磁弁=OFF
			mSV93_給湯電磁弁=OFF


			select case 洗浄タンクErrStep
			case 0
			case 1
				if ResetFlg then
					almFLT2_タンク下限 =OFF
					almFLT1_タンク上限=OFF
					almFLT4_タンク下限=OFF
					almFLT3_タンク上限=OFF
					almFLT6_タンク下限=OFF
					almFLT10_タンク下限=OFF
					almFLT9_タンク上限=OFF

					inc(洗浄タンクErrStep)
				end if
			case 2
				洗浄タンクErr=OFF
				
				res(tim_FLT2_タンク下限.B)
				res(tim_FLT1_タンク上限.B)
				res(tim_FLT4_タンク下限.B)
				res(tim_FLT3_タンク上限.B)
				res(tim_FLT6_タンク下限.B)
				res(tim_FLT7_タンク上限.B)
				res(tim_FLT10_タンク下限.B)
				res(tim_FLT9_タンク上限.B)

				洗浄タンクErrStep=0
			end select
		
		end if

	end if
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 洗浄タンクEmgStep
	case 0

	case 1
		洗浄タンクAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------

		
		
		if 洗浄タンクAutoMode  and 自動搬送AutoMode then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
		
			mSV69_給湯電磁弁=OFF
			mSV70_蒸気電磁弁=OFF

			mSV75_給湯電磁弁=OFF
			mSV76_蒸気電磁弁=OFF

			mSV81_給湯電磁弁=OFF
			mSV82_蒸気電磁弁=OFF

			mSV87_給湯電磁弁=OFF
			mSV88_蒸気電磁弁=OFF

			mSV93_給湯電磁弁=OFF
			mSV94_蒸気電磁弁=OFF
		
		
			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp1SV93_給湯電磁弁=OFF
			tmp2SV93_給湯電磁弁=OFF
			tmp_蒸気電磁弁=OFF
			tmp1SV70_蒸気電磁弁=OFF
			tmp2SV70_蒸気電磁弁=OFF
			tmp1SV76_蒸気電磁弁=OFF
			tmp2SV76_蒸気電磁弁=OFF
			tmp1SV82_蒸気電磁弁=OFF
			tmp2SV82_蒸気電磁弁=OFF
			tmp1SV88_蒸気電磁弁=OFF
			tmp2SV88_蒸気電磁弁=OFF
			tmp1SV94_蒸気電磁弁=OFF
			tmp2SV94_蒸気電磁弁=OFF			

			if timstack=OFF then

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			PBL36_給水=OFF
			PBL42_ヒータ=OFF
		
			mSV69_給湯電磁弁=OFF
			mSV70_蒸気電磁弁=OFF
	
			mSV75_給湯電磁弁=OFF
			mSV76_蒸気電磁弁=OFF

			mSV81_給湯電磁弁=OFF
			mSV82_蒸気電磁弁=OFF

			mSV87_給湯電磁弁=OFF
			mSV88_蒸気電磁弁=OFF

			mSV93_給湯電磁弁=OFF
			mSV94_蒸気電磁弁=OFF
		
		
			tmp_給湯電磁弁=OFF
			tmp1SV69_給湯電磁弁=OFF
			tmp2SV69_給湯電磁弁=OFF
			tmp1SV75_給湯電磁弁=OFF
			tmp2SV75_給湯電磁弁=OFF
			tmp1SV81_給湯電磁弁=OFF
			tmp2SV81_給湯電磁弁=OFF
			tmp1SV87_給湯電磁弁=OFF
			tmp2SV87_給湯電磁弁=OFF
			tmp1SV93_給湯電磁弁=OFF
			tmp2SV93_給湯電磁弁=OFF
			tmp_蒸気電磁弁=OFF
			tmp1SV70_蒸気電磁弁=OFF
			tmp2SV70_蒸気電磁弁=OFF
			tmp1SV76_蒸気電磁弁=OFF
			tmp2SV76_蒸気電磁弁=OFF
			tmp1SV82_蒸気電磁弁=OFF
			tmp2SV82_蒸気電磁弁=OFF
			tmp1SV88_蒸気電磁弁=OFF
			tmp2SV88_蒸気電磁弁=OFF
			tmp1SV94_蒸気電磁弁=OFF
			tmp2SV94_蒸気電磁弁=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄タンクEmgStep)
	case 2
		if ResetFlg then
			inc(洗浄タンクEmgStep)
		end if
	case 3
		if StartFlg then
			'---------------------------------
			'緊急停止解除(自動  ワンサイクル)
			'---------------------------------

			'---------------------------------
			inc(洗浄タンクEmgStep)
		end if
	case 4
		timstack=OFF
		洗浄タンクEmgStep=0
		洗浄タンクEmg=OFF
	end select
		
		
end if 'if 洗浄タンクEmgStep=0 then
