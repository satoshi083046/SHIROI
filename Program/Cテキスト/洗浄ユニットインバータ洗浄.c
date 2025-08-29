'洗浄ユニットインバータ洗浄
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄ユニット
'		
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    洗浄ユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    洗浄ユニットAutoRun=OFF
    洗浄ユニット許可=ON
    洗浄ユニットOrgErr=OFF
    洗浄ユニットErr=OFF
    洗浄ユニットEmg=OFF
    洗浄ユニットstep=0
    洗浄ユニットErrStep=0
    洗浄ユニットOrgErrStep=0
    洗浄ユニットEmgStep=0
	
	洗浄中=OFF
	
	ManualInite=1

	洗浄ユニット1禁止=洗浄ユニット1禁止
	洗浄ユニット2禁止=洗浄ユニット2禁止
	洗浄ユニット3禁止=洗浄ユニット3禁止
	洗浄ユニット4禁止=洗浄ユニット4禁止
	洗浄ユニット5禁止=洗浄ユニット5禁止

	
	if not(洗浄ユニット1禁止) then
		mMC35_洗浄ポンプA=ON
	end if	
	if not(洗浄ユニット2禁止) then
		mMC36_洗浄ポンプB=ON
	end if	
	if not(洗浄ユニット3禁止) then
		mMC37_洗浄ポンプC=ON
	end if	
	if not(洗浄ユニット4禁止) then
		mMC38_洗浄ポンプD=ON
	end if	
	if not(洗浄ユニット5禁止) then
		mMC39_洗浄ポンプE=ON
	end if	
	
end if

if ldf(洗浄ユニット1禁止) and not(THR35_洗浄ポンプA) then
	mMC35_洗浄ポンプA=ON
end if	
if ldf(洗浄ユニット2禁止) and not(THR36_洗浄ポンプB) then
	mMC36_洗浄ポンプB=ON
end if	
if ldf(洗浄ユニット3禁止) and not(THR37_洗浄ポンプC) then
	mMC37_洗浄ポンプC=ON
end if	
if ldf(洗浄ユニット4禁止) and not(THR38_洗浄ポンプD) then
	mMC38_洗浄ポンプD=ON
end if	
if ldf(洗浄ユニット5禁止) and not(THR39_洗浄ポンプE) then
	mMC39_洗浄ポンプE=ON
end if	


INV10_洗浄ポンプA運転=(mINV10_洗浄ポンプA運転 or ejectINV10_洗浄ポンプA運転 or extINV10_洗浄ポンプA運転) and not(pauseINV10_洗浄ポンプA運転) and not(EmgINV10_洗浄ポンプA運転) and timINV10_洗浄ポンプA運転
INV11_洗浄ポンプB運転=(mINV11_洗浄ポンプB運転 or ejectINV11_洗浄ポンプB運転 or extINV11_洗浄ポンプB運転) and not(pauseINV11_洗浄ポンプB運転) and not(EmgINV11_洗浄ポンプB運転) and timINV11_洗浄ポンプB運転
洗浄剤投入機=(mINV12_洗浄ポンプC運転 or ejectINV12_洗浄ポンプC運転 or extINV12_洗浄ポンプC運転) and not(pauseINV12_洗浄ポンプC運転) and not(EmgINV12_洗浄ポンプC運転) 
INV12_洗浄ポンプC運転=(mINV12_洗浄ポンプC運転 or ejectINV12_洗浄ポンプC運転 or extINV12_洗浄ポンプC運転) and not(pauseINV12_洗浄ポンプC運転) and not(EmgINV12_洗浄ポンプC運転) and timINV12_洗浄ポンプC運転
INV13_洗浄ポンプD運転=(mINV13_洗浄ポンプD運転 or ejectINV13_洗浄ポンプD運転 or extINV13_洗浄ポンプD運転) and not(pauseINV13_洗浄ポンプD運転) and not(EmgINV13_洗浄ポンプD運転) and timINV13_洗浄ポンプD運転
INV14_洗浄ポンプE運転=(mINV14_洗浄ポンプE運転 or ejectINV14_洗浄ポンプE運転 or extINV14_洗浄ポンプE運転) and not(pauseINV14_洗浄ポンプE運転) and not(EmgINV14_洗浄ポンプE運転) and timINV14_洗浄ポンプE運転



'--------------------------------------------------------
'洗浄終了後2秒間 FWD信号をOFFにしてフリーラン動作をさせる
'--------------------------------------------------------
tmr(timINV10_洗浄ポンプA運転,#20)
tmr(timINV11_洗浄ポンプB運転,#20)
tmr(timINV12_洗浄ポンプC運転,#20)
tmr(timINV13_洗浄ポンプD運転,#20)
tmr(timINV14_洗浄ポンプE運転,#20)
	
if ldf(INV10_洗浄ポンプA洗浄) then
	res(timINV10_洗浄ポンプA運転)
end if
if ldf(INV11_洗浄ポンプB洗浄) then
	res(timINV11_洗浄ポンプB運転)
end if
if ldf(INV12_洗浄ポンプC洗浄) then
	res(timINV12_洗浄ポンプC運転)
end if
if ldf(INV13_洗浄ポンプD洗浄) then
	res(timINV13_洗浄ポンプD運転)
end if
if ldf(INV14_洗浄ポンプE洗浄) then
	res(timINV14_洗浄ポンプE運転)
end if

'===================================================================================================================
'【 原点 】
洗浄ユニットOrg= (XSW81_釜フタ押さえ上昇端A and XSW83_釜フタ押さえ上昇端B) or 洗浄ユニット1禁止
洗浄ユニットOrg= 洗浄ユニットOrg and ((XSW86_釜フタ押さえ上昇端A and XSW88_釜フタ押さえ上昇端B) or 洗浄ユニット2禁止) 
洗浄ユニットOrg= 洗浄ユニットOrg and ((XSW91_釜フタ押さえ上昇端A and XSW93_釜フタ押さえ上昇端B) or 洗浄ユニット3禁止)
洗浄ユニットOrg= 洗浄ユニットOrg and ((XSW96_釜フタ押さえ上昇端A and XSW98_釜フタ押さえ上昇端B) or 洗浄ユニット4禁止)
洗浄ユニットOrg= 洗浄ユニットOrg and ((XSW101_釜フタ押さえ上昇端A and XSW103_釜フタ押さえ上昇端B) or 洗浄ユニット5禁止)

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	洗浄ユニットEmg=ON
	洗浄ユニットEmgStep=1
end if


if 洗浄ユニットEmgStep<>0 then
	
	pauseINV10_洗浄ポンプA運転=ON
	pauseINV11_洗浄ポンプB運転=ON
	pauseINV12_洗浄ポンプC運転=ON
	pauseINV13_洗浄ポンプD運転=ON
	pauseINV14_洗浄ポンプE運転=ON

	洗浄ユニットEmg=ON

else
	pauseINV10_洗浄ポンプA運転=not(FLT1_タンク上限検知確認) or not(FLT2_タンク下限) or 洗浄ユニット1禁止
	pauseINV11_洗浄ポンプB運転=not(FLT3_タンク上限検知確認) or not(FLT4_タンク下限) or 洗浄ユニット2禁止
	pauseINV12_洗浄ポンプC運転=not(FLT5_タンク上限検知確認) or not(FLT6_タンク下限) or 洗浄ユニット3禁止
	pauseINV13_洗浄ポンプD運転=not(FLT7_タンク上限検知確認) or not(FLT8_タンク下限) or 洗浄ユニット4禁止
	pauseINV14_洗浄ポンプE運転=not(FLT9_タンク上限検知確認) or not(FLT10_タンク下限) or 洗浄ユニット5禁止

	洗浄ユニットEmg=OFF

end if
'===================================================================================================================
'洗浄ポンプ水圧切り替え

	if CR2008 then '電源ON時初期化処理
		if not(洗浄ユニット1禁止) then
			mMC35_洗浄ポンプA=ON
		end if	
		if not(洗浄ユニット2禁止) then
			mMC36_洗浄ポンプB=ON
		end if	
		if not(洗浄ユニット3禁止) then
			mMC37_洗浄ポンプC=ON
		end if	
		if not(洗浄ユニット4禁止) then
			mMC38_洗浄ポンプD=ON
		end if	
		if not(洗浄ユニット5禁止) then
			mMC39_洗浄ポンプE=ON
		end if	
	end if

	if not(MC35_洗浄ポンプA) then
		mINV10_洗浄ポンプA運転=OFF
		INV10_洗浄ポンプA洗浄=OFF
	else if not(MC36_洗浄ポンプB) then
		mINV11_洗浄ポンプB運転=OFF
		INV11_洗浄ポンプB洗浄=OFF	
	else if not(MC37_洗浄ポンプC) then
		mINV12_洗浄ポンプC運転=OFF
		INV12_洗浄ポンプC洗浄=OFF		
	else if not(MC38_洗浄ポンプD) then
		mINV13_洗浄ポンプD運転=OFF
		INV13_洗浄ポンプD洗浄=OFF		
	else if not(MC39_洗浄ポンプE) then
		mINV14_洗浄ポンプE運転=OFF
		INV14_洗浄ポンプE洗浄=OFF		
	end if

	tmr(MC35_洗浄ポンプA,tim_INV10_洗浄ポンプA電源dly,#30)
	tmr(MC36_洗浄ポンプB,tim_INV11_洗浄ポンプB電源dly,#30)
	tmr(MC37_洗浄ポンプC,tim_INV12_洗浄ポンプC電源dly,#30)
	tmr(MC38_洗浄ポンプD,tim_INV13_洗浄ポンプD電源dly,#30)
	tmr(MC39_洗浄ポンプE,tim_INV14_洗浄ポンプE電源dly,#30)

	'----------------------------------------------------------------------------------------------------------------------------------
	'----- INV10_洗浄ポンプA異常  北部もインバータからの異常信号接点はA接点 -----
	if ldp(tim_INV10_洗浄ポンプA電源dly and INV10_洗浄ポンプA異常 and not(洗浄ユニット1禁止)) then 'インバータのアラーム出力検知
	 	almINV10_洗浄ポンプA異常=ON
		洗浄ユニットErrStep=1
	else if ldp(tim_INV11_洗浄ポンプB電源dly and INV11_洗浄ポンプB異常 and not(洗浄ユニット2禁止)) then 'インバータのアラーム出力検知
		almINV11_洗浄ポンプB異常=ON
		洗浄ユニットErrStep=1
	else if ldp(tim_INV12_洗浄ポンプC電源dly and INV12_洗浄ポンプC異常 and not(洗浄ユニット3禁止)) then 'インバータのアラーム出力検知
		almINV12_洗浄ポンプC異常=ON
		洗浄ユニットErrStep=1
	else if ldp(tim_INV13_洗浄ポンプD電源dly and INV13_洗浄ポンプD異常 and not(洗浄ユニット4禁止)) then 'インバータのアラーム出力検知
		almINV13_洗浄ポンプD異常=ON
		洗浄ユニットErrStep=1
	else if ldp(tim_INV14_洗浄ポンプE電源dly and INV14_洗浄ポンプE異常 and not(洗浄ユニット5禁止)) then 'インバータのアラーム出力検知
		almINV14_洗浄ポンプE異常=ON
		洗浄ユニットErrStep=1
	end if
	'----------------------------------------------------------------------------------------------------------------------------------
		
	if INV10_洗浄ポンプA洗浄 then
		setS05c10=洗浄ポンプA洗浄水圧
	else
		setS05c10=洗浄ポンプA待機水圧
	end if
	setS08c10=#10 '洗浄ポンプA立ち上がり時間
	setS09c10=#30
	
	if INV11_洗浄ポンプB洗浄 then
		setS05c11=洗浄ポンプB洗浄水圧
	else
		setS05c11=洗浄ポンプB待機水圧
	end if
	setS08c11=#10 '洗浄ポンプB立ち上がり時間
	setS09c11=#30
	
	if INV12_洗浄ポンプC洗浄 then
		setS05c12=洗浄ポンプC洗浄水圧
	else
		setS05c12=洗浄ポンプC待機水圧
	end if
	setS08c12=#10 '洗浄ポンプC立ち上がり時間
	setS09c12=#30
	
	if INV13_洗浄ポンプD洗浄 then
		setS05c13=洗浄ポンプD洗浄水圧
	else
		setS05c13=洗浄ポンプD待機水圧
	end if
	setS08c13=#10 '洗浄ポンプD立ち上がり時間
	setS09c13=#30
	
	if INV14_洗浄ポンプE洗浄 then
		setS05c14=洗浄ポンプE洗浄水圧
	else
		setS05c14=洗浄ポンプE待機水圧
	end if
	setS08c14=#10 '洗浄ポンプE立ち上がり時間
	setS09c14=#30

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
'---- 洗浄ユニット1 ----
tmr(SV67_釜フタ押さえ下降A and not(LatchXSW82_釜フタ押さえ下降端A) and not(pnlPBXSW82_釜フタ押さえ下降端A),tim_XSW82_釜フタ押さえ下降端A,#80)
if ldp(SV67_釜フタ押さえ下降A) then
	res(passtimXSW82_釜フタ押さえ下降端A)
end if
tmr(not(SV67_釜フタ押さえ下降A) and not(XSW81_釜フタ押さえ上昇端A) and not(pnlPBXSW81_釜フタ押さえ上昇端A),tim_XSW81_釜フタ押さえ上昇端A,#80)
if ldf(SV67_釜フタ押さえ下降A) then
	res(passtimXSW81_釜フタ押さえ上昇端A)
end if

tmr(SV68_釜フタ押さえ下降B and not(LatchXSW84_釜フタ押さえ下降端B) and not(pnlPBXSW84_釜フタ押さえ下降端B),tim_XSW84_釜フタ押さえ下降端B,#80)
if ldp(SV68_釜フタ押さえ下降B) then
	res(passtimXSW84_釜フタ押さえ下降端B)
end if

tmr(not(SV68_釜フタ押さえ下降B) and not(XSW83_釜フタ押さえ上昇端B) and not(pnlPBXSW83_釜フタ押さえ上昇端B),tim_XSW83_釜フタ押さえ上昇端B,#80)
if ldf(SV68_釜フタ押さえ下降B) then
	res(passtimXSW83_釜フタ押さえ上昇端B)
end if

'---- 洗浄ユニット2 ----
tmr(SV73_釜フタ押さえ下降A and not(LatchXSW87_釜フタ押さえ下降端A) and not(pnlPBXSW87_釜フタ押さえ下降端A),tim_XSW87_釜フタ押さえ下降端A,#80)
if ldp(SV73_釜フタ押さえ下降A) then
	res(passtimXSW87_釜フタ押さえ下降端A)
end if
tmr(not(SV73_釜フタ押さえ下降A) and not(XSW86_釜フタ押さえ上昇端A) and not(pnlPBXSW86_釜フタ押さえ上昇端A),tim_XSW86_釜フタ押さえ上昇端A,#80)
if ldf(SV73_釜フタ押さえ下降A) then
	res(passtimXSW86_釜フタ押さえ上昇端A)
end if

tmr(SV74_釜フタ押さえ下降B and not(LatchXSW89_釜フタ押さえ下降端B) and not(pnlPBXSW89_釜フタ押さえ下降端B),tim_XSW89_釜フタ押さえ下降端B,#80)
if ldp(SV74_釜フタ押さえ下降B) then
	res(passtimXSW89_釜フタ押さえ下降端B)
end if
tmr(not(SV74_釜フタ押さえ下降B) and not(XSW88_釜フタ押さえ上昇端B) and not(pnlPBXSW88_釜フタ押さえ上昇端B),tim_XSW88_釜フタ押さえ上昇端B,#80)
if ldf(SV74_釜フタ押さえ下降B) then
	res(passtimXSW88_釜フタ押さえ上昇端B)
end if

'---- 洗浄ユニット3 ----
tmr(SV79_釜フタ押さえ下降A and not(LatchXSW92_釜フタ押さえ下降端A) and not(pnlPBXSW92_釜フタ押さえ下降端A),tim_XSW92_釜フタ押さえ下降端A,#80)
if ldp(SV79_釜フタ押さえ下降A) then
	res(passtimXSW92_釜フタ押さえ下降端A)
end if
tmr(not(SV79_釜フタ押さえ下降A) and not(XSW91_釜フタ押さえ上昇端A) and not(pnlPBXSW91_釜フタ押さえ上昇端A),tim_XSW91_釜フタ押さえ上昇端A,#80)
if ldf(SV79_釜フタ押さえ下降A) then
	res(XSW91_釜フタ押さえ上昇端A)
end if

tmr(SV80_釜フタ押さえ下降B and not(LatchXSW94_釜フタ押さえ下降端B) and not(pnlPBXSW94_釜フタ押さえ下降端B),tim_XSW94_釜フタ押さえ下降端B,#80)
if ldp(SV80_釜フタ押さえ下降B) then
	res(passtimXSW94_釜フタ押さえ下降端B)
end if

tmr(not(SV80_釜フタ押さえ下降B) and not(XSW93_釜フタ押さえ上昇端B) and not(pnlPBXSW93_釜フタ押さえ上昇端B),tim_XSW93_釜フタ押さえ上昇端B,#80)
if ldf(SV80_釜フタ押さえ下降B) then
	res(passtimXSW93_釜フタ押さえ上昇端B)
end if

'---- 洗浄ユニット4 ----
tmr(SV85_釜フタ押さえ下降A and not(LatchXSW97_釜フタ押さえ下降端A) and not(pnlPBXSW97_釜フタ押さえ下降端A),tim_XSW97_釜フタ押さえ下降端A,#80)
if ldp(SV85_釜フタ押さえ下降A) then
	res(passtimXSW97_釜フタ押さえ下降端A)
end if
tmr(not(SV85_釜フタ押さえ下降A) and not(XSW96_釜フタ押さえ上昇端A) and not(pnlPBXSW96_釜フタ押さえ上昇端A),tim_XSW96_釜フタ押さえ上昇端A,#80)
if ldf(SV85_釜フタ押さえ下降A) then
	res(passtimXSW96_釜フタ押さえ上昇端A)
end if

tmr(SV86_釜フタ押さえ下降B and not(LatchXSW99_釜フタ押さえ下降端B) and not(pnlPBXSW99_釜フタ押さえ下降端B),tim_XSW99_釜フタ押さえ下降端B,#80)
if ldp(SV86_釜フタ押さえ下降B) then
	res(passtimXSW99_釜フタ押さえ下降端B)
end if
tmr(not(SV86_釜フタ押さえ下降B) and not(XSW98_釜フタ押さえ上昇端B) and not(pnlPBXSW98_釜フタ押さえ上昇端B),tim_XSW98_釜フタ押さえ上昇端B,#80)
if ldf(SV86_釜フタ押さえ下降B) then
	res(passtimXSW98_釜フタ押さえ上昇端B)
end if

'---- 洗浄ユニット5 ----
tmr(SV91_釜フタ押さえ下降A and not(LatchXSW102_釜フタ押さえ下降端A) and not(pnlPBXSW102_釜フタ押さえ下降端A),tim_XSW102_釜フタ押さえ下降端A,#80)
if ldp(SV91_釜フタ押さえ下降A) then
	res(passtimXSW102_釜フタ押さえ下降端A)
end if
tmr(not(SV91_釜フタ押さえ下降A) and not(XSW101_釜フタ押さえ上昇端A) and not(pnlPBXSW101_釜フタ押さえ上昇端A),tim_XSW101_釜フタ押さえ上昇端A,#80)
if ldf(SV91_釜フタ押さえ下降A) then
	res(passtimXSW101_釜フタ押さえ上昇端A)
end if

tmr(SV92_釜フタ押さえ下降B and not(LatchXSW104_釜フタ押さえ下降端B) and not(pnlPBXSW104_釜フタ押さえ下降端B),tim_XSW104_釜フタ押さえ下降端B,#80)
if ldp(SV92_釜フタ押さえ下降B) then
	res(passtimXSW104_釜フタ押さえ下降端B)
end if
tmr(not(SV92_釜フタ押さえ下降B) and not(XSW103_釜フタ押さえ上昇端B) and not(pnlPBXSW103_釜フタ押さえ上昇端B),tim_XSW103_釜フタ押さえ上昇端B,#80)
if ldf(SV92_釜フタ押さえ下降B) then
	res(passtimXSW103_釜フタ押さえ上昇端B)
end if


if ldp(tim_XSW82_釜フタ押さえ下降端A.B) and not(洗浄ユニット1禁止) then
	almXSW82_釜フタ押さえ下降端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW81_釜フタ押さえ上昇端A.B)  and not(洗浄ユニット1禁止) then
	almXSW81_釜フタ押さえ上昇端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW84_釜フタ押さえ下降端B.B)  and not(洗浄ユニット1禁止) then
	almXSW84_釜フタ押さえ下降端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW83_釜フタ押さえ上昇端B.B)  and not(洗浄ユニット1禁止) then
	almXSW83_釜フタ押さえ上昇端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW87_釜フタ押さえ下降端A.B)  and not(洗浄ユニット2禁止) then
	almXSW87_釜フタ押さえ下降端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW86_釜フタ押さえ上昇端A.B)  and not(洗浄ユニット2禁止) then
	almXSW86_釜フタ押さえ上昇端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW89_釜フタ押さえ下降端B.B)  and not(洗浄ユニット2禁止) then
	almXSW89_釜フタ押さえ下降端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW88_釜フタ押さえ上昇端B.B)  and not(洗浄ユニット2禁止) then
	almXSW88_釜フタ押さえ上昇端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW92_釜フタ押さえ下降端A.B)  and not(洗浄ユニット3禁止) then
	almXSW92_釜フタ押さえ下降端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW91_釜フタ押さえ上昇端A.B)  and not(洗浄ユニット3禁止) then
	almXSW91_釜フタ押さえ上昇端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW94_釜フタ押さえ下降端B.B)  and not(洗浄ユニット3禁止) then
	almXSW94_釜フタ押さえ下降端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW93_釜フタ押さえ上昇端B.B)  and not(洗浄ユニット3禁止) then
	almXSW93_釜フタ押さえ上昇端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW97_釜フタ押さえ下降端A.B)  and not(洗浄ユニット4禁止) then
	almXSW97_釜フタ押さえ下降端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW96_釜フタ押さえ上昇端A.B)  and not(洗浄ユニット4禁止) then
	almXSW96_釜フタ押さえ上昇端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW99_釜フタ押さえ下降端B.B)  and not(洗浄ユニット4禁止) then
	almXSW99_釜フタ押さえ下降端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW98_釜フタ押さえ上昇端B.B)  and not(洗浄ユニット4禁止) then
	almXSW98_釜フタ押さえ上昇端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW102_釜フタ押さえ下降端A.B)  and not(洗浄ユニット5禁止) then
	almXSW102_釜フタ押さえ下降端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW101_釜フタ押さえ上昇端A.B)  and not(洗浄ユニット5禁止) then
	almXSW101_釜フタ押さえ上昇端A=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW104_釜フタ押さえ下降端B.B)  and not(洗浄ユニット5禁止) then
	almXSW104_釜フタ押さえ下降端B=ON
	洗浄ユニットErrStep=1

else if ldp(tim_XSW103_釜フタ押さえ上昇端B.B)  and not(洗浄ユニット5禁止) then
	almXSW103_釜フタ押さえ上昇端B=ON
	洗浄ユニットErrStep=1

end if

'===================================================================================================================
tmr(not(FLT2_タンク下限),nottimdly_FLT2_タンク下限,#30)
tmr(not(FLT4_タンク下限),nottimdly_FLT4_タンク下限,#30)
tmr(not(FLT6_タンク下限),nottimdly_FLT6_タンク下限,#30)
tmr(not(FLT8_タンク下限),nottimdly_FLT8_タンク下限,#30)
tmr(not(FLT10_タンク下限),nottimdly_FLT10_タンク下限,#30)

tmr(not(FLT1_タンク上限),nottimdly_FLT1_タンク上限,#200)
tmr(not(FLT3_タンク上限),nottimdly_FLT3_タンク上限,#200)
tmr(not(FLT5_タンク上限),nottimdly_FLT5_タンク上限,#200)
tmr(not(FLT7_タンク上限),nottimdly_FLT7_タンク上限,#200)
tmr(not(FLT9_タンク上限),nottimdly_FLT9_タンク上限,#200)


if FLT1_タンク上限 then
	FLT1_タンク上限検知確認=ON
else if not(FLT2_タンク下限) then
	FLT1_タンク上限検知確認=OFF
end if

if FLT3_タンク上限 then
	FLT3_タンク上限検知確認=ON
else if not(FLT4_タンク下限) then
	FLT3_タンク上限検知確認=OFF
end if

if FLT5_タンク上限 then
	FLT5_タンク上限検知確認=ON
else if not(FLT6_タンク下限) then
	FLT5_タンク上限検知確認=OFF
end if

if FLT7_タンク上限 then
	FLT7_タンク上限検知確認=ON
else if not(FLT8_タンク下限) then
	FLT7_タンク上限検知確認=OFF
end if

if FLT9_タンク上限 then
	FLT9_タンク上限検知確認=ON
else if not(FLT10_タンク下限) then
	FLT9_タンク上限検知確認=OFF
end if

tmr(PH46_フタ検知 or PH45_釜検知,tim_洗浄入口フタ釜検知,20) '手動運転時の洗浄入口ワーク検知

'===================================================================================================================
'PLインジケータ

	PBL25_洗浄機単動運転=ワンサイクルflg

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄ユニットAutoMode	自動モード セレクトスイッチ
'System :: 洗浄ユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄ユニットEmg	その場停止


if not(洗浄ユニットEmg) then  
	
	if 洗浄ユニットErrStep=0  then

	if not(洗浄ユニットOrgErr) then

	if (洗浄ユニットAutoMode and 自動搬送AutoMode ) or 洗浄ユニットstep<>0  then
	
		if not(洗浄ユニットAutoMode and 自動搬送AutoMode ) then
			洗浄ユニットAutoRun=OFF
		end if

		'すすぎ電磁弁, 仕上げ電磁弁
		if 洗浄ユニットAutoRun then	
			if すすぎ禁止 then
				mSV97_すすぎ電磁弁=OFF
				mSV98_仕上げ電磁弁=OFF
			else
				mSV97_すすぎ電磁弁=ON
				mSV98_仕上げ電磁弁=ON
			end if
		else
			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF
		end if
				
				
		if ManualInite=1 then
			PBL43_洗浄ポンプ=OFF
			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF

			mINV10_洗浄ポンプA運転=OFF
			mINV11_洗浄ポンプB運転=OFF
			mINV12_洗浄ポンプC運転=OFF
			mINV13_洗浄ポンプD運転=OFF
			mINV14_洗浄ポンプE運転=OFF		

			INV10_洗浄ポンプA洗浄=OFF
			INV11_洗浄ポンプB洗浄=OFF
			INV12_洗浄ポンプC洗浄=OFF
			INV13_洗浄ポンプD洗浄=OFF
			INV14_洗浄ポンプE洗浄=OFF


			tmp洗浄ポンプ=OFF
			tmp1SV97_すすぎ電磁弁=OFF
			tmp1SV98_仕上げ電磁弁=OFF
			tmp1INV10_洗浄ポンプA運転=OFF
			tmp1INV11_洗浄ポンプB運転=OFF
			tmp1INV12_洗浄ポンプC運転=OFF
			tmp1INV13_洗浄ポンプD運転=OFF
			tmp1INV14_洗浄ポンプE運転=OFF
			
			tmp2SV97_すすぎ電磁弁=OFF
			tmp2SV98_仕上げ電磁弁=OFF
			tmp2INV10_洗浄ポンプA運転=OFF
			tmp2INV11_洗浄ポンプB運転=OFF
			tmp2INV12_洗浄ポンプC運転=OFF
			tmp2INV13_洗浄ポンプD運転=OFF
			tmp2INV14_洗浄ポンプE運転=OFF

			ManualInite=0
		end if
		

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 洗浄ユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
			洗浄ユニットStatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 洗浄ユニットAutoRun or ワンサイクルflg then
				洗浄ユニットStatusMsg=#70	'	待機中
				mINV10_洗浄ポンプA運転=ON
				mINV11_洗浄ポンプB運転=ON
				mINV12_洗浄ポンプC運転=ON
				mINV13_洗浄ポンプD運転=ON
				mINV14_洗浄ポンプE運転=ON

				if 洗浄中 then
					洗浄ユニットstep=200
				else
					inc(洗浄ユニットstep)
				end if


			else

				mINV10_洗浄ポンプA運転=OFF
				mINV11_洗浄ポンプB運転=OFF
				mINV12_洗浄ポンプC運転=OFF
				mINV13_洗浄ポンプD運転=OFF
				mINV14_洗浄ポンプE運転=OFF

				mSV97_すすぎ電磁弁=OFF
				mSV98_仕上げ電磁弁=OFF
				
				INV10_洗浄ポンプA洗浄=OFF
				INV11_洗浄ポンプB洗浄=OFF
				INV12_洗浄ポンプC洗浄=OFF
				INV13_洗浄ポンプD洗浄=OFF
				INV14_洗浄ポンプE洗浄=OFF
				
				if 洗浄中 then
					洗浄解除=ON
					洗浄ユニットstep=200
				else
					洗浄ユニットstep=0
				end if
			end if
		
		
		
		case 2
		' [ 蓋カマ移動停止確認 ]
			if 洗浄完了=OFF and  洗浄コンベア搬送動作中=OFF then
				inc(洗浄ユニットstep)
			else
				洗浄ユニットstep=1
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if 洗浄ユニット許可 then
				inc(洗浄ユニットstep) 'プロセス処理
			else
				洗浄完了=ON
				洗浄ユニットstep=1
			end if
		
		case 4
			if 洗浄ユニットOrg then
				洗浄ユニットstep=100
			else
				洗浄ユニットstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			tmp洗浄ユニット1禁止=洗浄ユニット1禁止
			tmp洗浄ユニット2禁止=洗浄ユニット2禁止
			tmp洗浄ユニット3禁止=洗浄ユニット3禁止
			tmp洗浄ユニット4禁止=洗浄ユニット4禁止
			tmp洗浄ユニット5禁止=洗浄ユニット5禁止
		
			洗浄工程終了=OFF
			洗浄ユニットStatusMsg=#72	'	運転中
			
			if not(tmp洗浄ユニット1禁止) then
				if shiftreg釜フタ判定1=$80 then '釜検出			
					mSV68_釜フタ押さえ下降B=ON
				else if shiftreg釜フタ判定1=$40 then 'フタ検出
					mSV67_釜フタ押さえ下降A=ON
					mSV68_釜フタ押さえ下降B=ON
				end if
			else
				mSV67_釜フタ押さえ下降A=OFF
				mSV68_釜フタ押さえ下降B=OFF
			end if


			if not(tmp洗浄ユニット2禁止) then
				if shiftreg釜フタ判定2=$80 then '釜検出			
					mSV74_釜フタ押さえ下降B=ON
				else if shiftreg釜フタ判定2=$40 then 'フタ検出
					mSV73_釜フタ押さえ下降A=ON
					mSV74_釜フタ押さえ下降B=ON
				end if
			else
				mSV73_釜フタ押さえ下降A=OFF
				mSV74_釜フタ押さえ下降B=OFF
			end if
			
			if not(tmp洗浄ユニット3禁止) then
				if shiftreg釜フタ判定3=$80 then '釜検出			
					mSV80_釜フタ押さえ下降B=ON
				else if shiftreg釜フタ判定3=$40 then 'フタ検出
					mSV79_釜フタ押さえ下降A=ON
					mSV80_釜フタ押さえ下降B=ON
				end if
			else
				mSV79_釜フタ押さえ下降A=OFF
				mSV80_釜フタ押さえ下降B=OFF
			end if

			if not(tmp洗浄ユニット4禁止) then
				if shiftreg釜フタ判定4=$80 then '釜検出			
					mSV86_釜フタ押さえ下降B=ON
				else if shiftreg釜フタ判定4=$40 then 'フタ検出
					mSV85_釜フタ押さえ下降A=ON
					mSV86_釜フタ押さえ下降B=ON
				end if
			else
				mSV85_釜フタ押さえ下降A=OFF
				mSV86_釜フタ押さえ下降B=OFF
			end if
			
			if not(tmp洗浄ユニット5禁止) then
				if shiftreg釜フタ判定5=$80 then '釜検出			
					mSV92_釜フタ押さえ下降B=ON
				else if shiftreg釜フタ判定5=$40 then 'フタ検出
					mSV91_釜フタ押さえ下降A=ON
					mSV92_釜フタ押さえ下降B=ON
				end if
			else
				mSV91_釜フタ押さえ下降A=OFF
				mSV92_釜フタ押さえ下降B=OFF
			end if
			
			LatchXSW82_釜フタ押さえ下降端A=OFF
			LatchXSW84_釜フタ押さえ下降端B=OFF
			LatchXSW87_釜フタ押さえ下降端A=OFF
			LatchXSW89_釜フタ押さえ下降端B=OFF
			LatchXSW92_釜フタ押さえ下降端A=OFF
			LatchXSW94_釜フタ押さえ下降端B=OFF
			LatchXSW97_釜フタ押さえ下降端A=OFF
			LatchXSW99_釜フタ押さえ下降端B=OFF
			LatchXSW102_釜フタ押さえ下降端A=OFF
			LatchXSW104_釜フタ押さえ下降端B=OFF
		
			inc(洗浄ユニットstep)
			
		case 101
			if tmp洗浄ユニット1禁止 then
				inc(洗浄ユニットstep)			
			else if shiftreg釜フタ判定1=$80 and mSV67_釜フタ押さえ下降A then '釜検出			
				if (LatchXSW82_釜フタ押さえ下降端A or passXSW82_釜フタ押さえ下降端A) then
					inc(洗浄ユニットstep)
				end if
			else if shiftreg釜フタ判定1=$40 and mSV67_釜フタ押さえ下降A and mSV68_釜フタ押さえ下降B then 'フタ検出
				if (LatchXSW82_釜フタ押さえ下降端A or passXSW82_釜フタ押さえ下降端A) and (LatchXSW84_釜フタ押さえ下降端B or passXSW84_釜フタ押さえ下降端B) then
					inc(洗浄ユニットstep)
				end if
			else 
				inc(洗浄ユニットstep)
			end if
		
		case 102
			if tmp洗浄ユニット2禁止 then
				inc(洗浄ユニットstep)			
			else if shiftreg釜フタ判定2=$80 and mSV73_釜フタ押さえ下降A then '釜検出			
				if (LatchXSW87_釜フタ押さえ下降端A or passXSW87_釜フタ押さえ下降端A) then
					inc(洗浄ユニットstep)
				end if
			else if shiftreg釜フタ判定2=$40 and mSV73_釜フタ押さえ下降A and mSV74_釜フタ押さえ下降B then 'フタ検出
				if (LatchXSW87_釜フタ押さえ下降端A or passXSW87_釜フタ押さえ下降端A)  and (LatchXSW89_釜フタ押さえ下降端B or passXSW89_釜フタ押さえ下降端B) then
					inc(洗浄ユニットstep)
				end if
			else
				inc(洗浄ユニットstep)
			end if
		
		case 103
			if tmp洗浄ユニット3禁止 then
				inc(洗浄ユニットstep)			
			else if shiftreg釜フタ判定3=$80 and mSV79_釜フタ押さえ下降A then '釜検出			
				if (LatchXSW92_釜フタ押さえ下降端A or passXSW92_釜フタ押さえ下降端A) then
					inc(洗浄ユニットstep)
				end if
			else if shiftreg釜フタ判定3=$40 and mSV79_釜フタ押さえ下降A and mSV80_釜フタ押さえ下降B then 'フタ検出
				if (LatchXSW92_釜フタ押さえ下降端A or passXSW92_釜フタ押さえ下降端A) and (LatchXSW94_釜フタ押さえ下降端B or passXSW94_釜フタ押さえ下降端B) then
					inc(洗浄ユニットstep)
				end if
			else
				inc(洗浄ユニットstep)
			end if		
		
		case 104
			if tmp洗浄ユニット4禁止 then
				inc(洗浄ユニットstep)			
			else if shiftreg釜フタ判定4=$80 and mSV85_釜フタ押さえ下降A then '釜検出	
				if (LatchXSW97_釜フタ押さえ下降端A or passXSW97_釜フタ押さえ下降端A) then
					inc(洗浄ユニットstep)
				end if			
			else if shiftreg釜フタ判定4=$40 and mSV85_釜フタ押さえ下降A and mSV86_釜フタ押さえ下降B then 'フタ検出
				if (LatchXSW97_釜フタ押さえ下降端A or passXSW97_釜フタ押さえ下降端A) and (LatchXSW99_釜フタ押さえ下降端B or passXSW99_釜フタ押さえ下降端B) then
					inc(洗浄ユニットstep)
				end if			
			else
				inc(洗浄ユニットstep)
			end if
		
		case 105
			if tmp洗浄ユニット5禁止 then
				inc(洗浄ユニットstep)			
			else if shiftreg釜フタ判定5=$80 and mSV91_釜フタ押さえ下降A then '釜検出			
				if (LatchXSW102_釜フタ押さえ下降端A or passXSW102_釜フタ押さえ下降端A) then
					inc(洗浄ユニットstep)
				end if			
			else if shiftreg釜フタ判定5=$40 and mSV91_釜フタ押さえ下降A and mSV92_釜フタ押さえ下降B then 'フタ検出
				if (LatchXSW102_釜フタ押さえ下降端A or passXSW102_釜フタ押さえ下降端A)  and (LatchXSW104_釜フタ押さえ下降端B or passXSW104_釜フタ押さえ下降端B) then
					inc(洗浄ユニットstep)
				end if			
			else
				inc(洗浄ユニットstep)
			end if
		
		case 106
			tim_procstep_val=#5
			res(tim_procstep)
			inc(洗浄ユニットstep)
		
		
		case 107
			if tim_procstep.B then
				inc(洗浄ユニットstep)
			end if
		
		case 108
			if tmp洗浄ユニット1禁止 then
				INV10_洗浄ポンプA洗浄=OFF
			else if shiftreg釜フタ判定1=$80 then '釜検出			
				INV10_洗浄ポンプA洗浄=ON
			else if shiftreg釜フタ判定1=$40 then 'フタ検出
				INV10_洗浄ポンプA洗浄=ON
			end if
			
			if tmp洗浄ユニット2禁止 then
				INV11_洗浄ポンプB洗浄=OFF
			else if shiftreg釜フタ判定2=$80 then '釜検出			
				INV11_洗浄ポンプB洗浄=ON
			else if shiftreg釜フタ判定2=$40 then 'フタ検出
				INV11_洗浄ポンプB洗浄=ON
			end if
			
			if tmp洗浄ユニット3禁止 then
				INV12_洗浄ポンプC洗浄=OFF
			else if shiftreg釜フタ判定3=$80 then '釜検出			
				INV12_洗浄ポンプC洗浄=ON
			else if shiftreg釜フタ判定3=$40 then 'フタ検出
				INV12_洗浄ポンプC洗浄=ON
			end if
			
			if tmp洗浄ユニット4禁止 then
				INV13_洗浄ポンプD洗浄=OFF
			else if shiftreg釜フタ判定4=$80 then '釜検出			
				INV13_洗浄ポンプD洗浄=ON
			else if shiftreg釜フタ判定4=$40 then 'フタ検出
				INV13_洗浄ポンプD洗浄=ON
			end if
			
			if tmp洗浄ユニット5禁止 then
				INV14_洗浄ポンプE洗浄=OFF			
			else if shiftreg釜フタ判定5=$80 then '釜検出			
				INV14_洗浄ポンプE洗浄=ON
			else if shiftreg釜フタ判定5=$40 then 'フタ検出
				INV14_洗浄ポンプE洗浄=ON
			end if

			
			
			tim_procstep_val=DM_洗浄時間
			res(tim_procstep)
			
			洗浄中=ON
			洗浄解除=OFF
			
			洗浄ユニットstep=200

		case 200
			'if  ( (ワンサイクルflg or 洗浄解除)  and (tim_procstep.B or (ワンサイクルflg and tim_洗浄入口フタ釜検知)) ) or (not(ワンサイクルflg or 洗浄解除) and (洗浄入口搬送排出要求 or 洗浄工程終了)) then
			if  ( (ワンサイクルflg or 洗浄解除)  and (tim_procstep.B or (ワンサイクルflg and tim_洗浄入口フタ釜検知)) ) or (not(ワンサイクルflg or 洗浄解除) and 洗浄入口搬送排出要求) then
				INV10_洗浄ポンプA洗浄=OFF
				INV11_洗浄ポンプB洗浄=OFF
				INV12_洗浄ポンプC洗浄=OFF
				INV13_洗浄ポンプD洗浄=OFF
				INV14_洗浄ポンプE洗浄=OFF
				
				tim_procstep_val=40
				res(tim_procstep)
				inc(洗浄ユニットstep)
			else
				洗浄ユニットstep=1
			end if
		
		case 201
			洗浄工程終了=OFF

			if tim_procstep.B then
				mSV67_釜フタ押さえ下降A=OFF
				mSV73_釜フタ押さえ下降A=OFF
				mSV79_釜フタ押さえ下降A=OFF
				mSV85_釜フタ押さえ下降A=OFF
				mSV91_釜フタ押さえ下降A=OFF

				inc(洗浄ユニットstep)
			end if
		
		case 202
			if (XSW81_釜フタ押さえ上昇端A or passXSW81_釜フタ押さえ上昇端A or tmp洗浄ユニット1禁止) then
				if (XSW86_釜フタ押さえ上昇端A or passXSW86_釜フタ押さえ上昇端A or tmp洗浄ユニット2禁止) then
					if (XSW91_釜フタ押さえ上昇端A or passXSW91_釜フタ押さえ上昇端A  or tmp洗浄ユニット3禁止) then
						if (XSW96_釜フタ押さえ上昇端A or passXSW96_釜フタ押さえ上昇端A  or tmp洗浄ユニット4禁止) then
							if (XSW101_釜フタ押さえ上昇端A or passXSW101_釜フタ押さえ上昇端A or tmp洗浄ユニット5禁止)then
								inc(洗浄ユニットstep)
							end if
						end if
					end if
				end if
			end if		
		
		case 203
				tim_procstep_val=0
				res(tim_procstep)
				inc(洗浄ユニットstep)
		
		case 204
			if tim_procstep.B then
				inc(洗浄ユニットstep)			
			end if
		
		case 205
				mSV68_釜フタ押さえ下降B=OFF
				mSV74_釜フタ押さえ下降B=OFF
				mSV80_釜フタ押さえ下降B=OFF
				mSV86_釜フタ押さえ下降B=OFF
				mSV92_釜フタ押さえ下降B=OFF
				inc(洗浄ユニットstep)
		
		case 206			
			if (XSW83_釜フタ押さえ上昇端B or passXSW83_釜フタ押さえ上昇端B or tmp洗浄ユニット1禁止) then
				if (XSW88_釜フタ押さえ上昇端B or passXSW88_釜フタ押さえ上昇端B or tmp洗浄ユニット2禁止) then
					if (XSW93_釜フタ押さえ上昇端B or passXSW93_釜フタ押さえ上昇端B or tmp洗浄ユニット3禁止) then
						if (XSW98_釜フタ押さえ上昇端B or passXSW98_釜フタ押さえ上昇端B or tmp洗浄ユニット4禁止) then
							if (XSW103_釜フタ押さえ上昇端B or passXSW103_釜フタ押さえ上昇端B or tmp洗浄ユニット5禁止) then
								inc(洗浄ユニットstep)
							end if
						end if
					end if
				end if
			end if
			
		case 207
			tim_procstep_val=0
			res(tim_procstep)
			inc(洗浄ユニットstep)
			
		case 208
			if tim_procstep.B then
				inc(洗浄ユニットstep)	
			end if
		
		case 209
			洗浄完了=ON
			洗浄中=OFF
			ワンサイクルflg=OFF
			洗浄ユニットstep=1
			
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
		'res(tim_XSW82_釜フタ押さえ下降端A)
		'res(tim_XSW81_釜フタ押さえ上昇端A)
		'res(tim_XSW84_釜フタ押さえ下降端B)
		'res(tim_XSW83_釜フタ押さえ上昇端B)
		'res(tim_XSW87_釜フタ押さえ下降端A)
		'res(tim_XSW86_釜フタ押さえ上昇端A)
		'res(tim_XSW89_釜フタ押さえ下降端B)
		'res(tim_XSW88_釜フタ押さえ上昇端B)
		'res(tim_XSW92_釜フタ押さえ下降端A)
		'res(tim_XSW91_釜フタ押さえ上昇端A)
		'res(tim_XSW94_釜フタ押さえ下降端B)
		'res(tim_XSW93_釜フタ押さえ上昇端B)
		'res(tim_XSW97_釜フタ押さえ下降端A)
		'res(tim_XSW96_釜フタ押さえ上昇端A)
		'res(tim_XSW99_釜フタ押さえ下降端B)
		'res(tim_XSW98_釜フタ押さえ上昇端B)
		'res(tim_XSW102_釜フタ押さえ下降端A)
		'res(tim_XSW101_釜フタ押さえ上昇端A)
		'res(tim_XSW104_釜フタ押さえ下降端B)
		'res(tim_XSW103_釜フタ押さえ上昇端B)

		洗浄ユニットAutoRun=OFF
		
		洗浄ユニットstep=0 '終了
		
		洗浄完了=OFF
		
		if ManualInite=0 then
			PBL43_洗浄ポンプ=OFF
			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF

			mINV10_洗浄ポンプA運転=OFF
			mINV11_洗浄ポンプB運転=OFF
			mINV12_洗浄ポンプC運転=OFF
			mINV13_洗浄ポンプD運転=OFF
			mINV14_洗浄ポンプE運転=OFF
			
			INV10_洗浄ポンプA洗浄=OFF
			INV11_洗浄ポンプB洗浄=OFF
			INV12_洗浄ポンプC洗浄=OFF
			INV13_洗浄ポンプD洗浄=OFF
			INV14_洗浄ポンプE洗浄=OFF

			マニュアルポンプstep=0

			tmp洗浄ポンプ=OFF
			tmp1SV97_すすぎ電磁弁=OFF
			tmp1SV98_仕上げ電磁弁=OFF
			tmp1INV10_洗浄ポンプA運転=OFF
			tmp1INV11_洗浄ポンプB運転=OFF
			tmp1INV12_洗浄ポンプC運転=OFF
			tmp1INV13_洗浄ポンプD運転=OFF
			tmp1INV14_洗浄ポンプE運転=OFF
			
			tmp2SV97_すすぎ電磁弁=OFF
			tmp2SV98_仕上げ電磁弁=OFF
			tmp2INV10_洗浄ポンプA運転=OFF
			tmp2INV11_洗浄ポンプB運転=OFF
			tmp2INV12_洗浄ポンプC運転=OFF
			tmp2INV13_洗浄ポンプD運転=OFF
			tmp2INV14_洗浄ポンプE運転=OFF

			ManualInite=1
		end if
		
		
		if PB45_全停止SW  and not(manual洗浄コンベア) then '洗浄コンベア強制排出時はすべてのシリンダが強制上昇します。
			if ldp(pnlPBSV67_釜フタ押さえ下降A) then
				if mSV67_釜フタ押さえ下降A then
					mSV67_釜フタ押さえ下降A=OFF
				else
					mSV67_釜フタ押さえ下降A=ON
				end if
			end if
			
			if ldp(pnlPBSV68_釜フタ押さえ下降B) then
				if mSV68_釜フタ押さえ下降B then
					mSV68_釜フタ押さえ下降B=OFF
				else
					mSV68_釜フタ押さえ下降B=ON
				end if
			end if
			
			if ldp(pnlPBSV73_釜フタ押さえ下降A) then
				if mSV73_釜フタ押さえ下降A then
					mSV73_釜フタ押さえ下降A=OFF
				else
					mSV73_釜フタ押さえ下降A=ON
				end if
			end if
			
			if ldp(pnlPBSV74_釜フタ押さえ下降B) then
				if mSV74_釜フタ押さえ下降B then
					mSV74_釜フタ押さえ下降B=OFF
				else
					mSV74_釜フタ押さえ下降B=ON
				end if
			end if
			
			if ldp(pnlPBSV79_釜フタ押さえ下降A) then
				if mSV79_釜フタ押さえ下降A then
					mSV79_釜フタ押さえ下降A=OFF
				else
					mSV79_釜フタ押さえ下降A=ON
				end if
			end if
			
			if ldp(pnlPBSV80_釜フタ押さえ下降B) then
				if mSV80_釜フタ押さえ下降B then
					mSV80_釜フタ押さえ下降B=OFF
				else
					mSV80_釜フタ押さえ下降B=ON
				end if
			end if
			
			if ldp(pnlPBSV85_釜フタ押さえ下降A) then
				if mSV85_釜フタ押さえ下降A then
					mSV85_釜フタ押さえ下降A=OFF
				else
					mSV85_釜フタ押さえ下降A=ON
				end if
			end if
			
			if ldp(pnlPBSV86_釜フタ押さえ下降B) then
				if mSV86_釜フタ押さえ下降B then
					mSV86_釜フタ押さえ下降B=OFF
				else
					mSV86_釜フタ押さえ下降B=ON
				end if
			end if
			
			if ldp(pnlPBSV91_釜フタ押さえ下降A) then
				if mSV91_釜フタ押さえ下降A then
					mSV91_釜フタ押さえ下降A=OFF
				else
					mSV91_釜フタ押さえ下降A=ON
				end if
			end if
			
			if ldp(pnlPBSV92_釜フタ押さえ下降B) then
				if mSV92_釜フタ押さえ下降B then
					mSV92_釜フタ押さえ下降B=OFF
				else
					mSV92_釜フタ押さえ下降B=ON
				end if
			end if
		else		
			mSV67_釜フタ押さえ下降A=OFF
			mSV68_釜フタ押さえ下降B=OFF
			mSV73_釜フタ押さえ下降A=OFF
			mSV74_釜フタ押さえ下降B=OFF
			mSV79_釜フタ押さえ下降A=OFF
			mSV80_釜フタ押さえ下降B=OFF
			mSV85_釜フタ押さえ下降A=OFF
			mSV86_釜フタ押さえ下降B=OFF
			mSV91_釜フタ押さえ下降A=OFF
			mSV92_釜フタ押さえ下降B=OFF
		end if
		
		
		PBL43_洗浄ポンプ=mINV10_洗浄ポンプA運転 or mINV11_洗浄ポンプB運転 or mINV12_洗浄ポンプC運転 or mINV13_洗浄ポンプD運転 or mINV14_洗浄ポンプE運転
		mINV10_洗浄ポンプA運転=(tmp1INV10_洗浄ポンプA運転 or tmp2INV10_洗浄ポンプA運転) and (FLT2_タンク下限 or not(nottimdly_FLT2_タンク下限.B))
		mINV11_洗浄ポンプB運転=(tmp1INV11_洗浄ポンプB運転 or tmp2INV11_洗浄ポンプB運転) and (FLT4_タンク下限 or not(nottimdly_FLT4_タンク下限.B))
		mINV12_洗浄ポンプC運転=(tmp1INV12_洗浄ポンプC運転 or tmp2INV12_洗浄ポンプC運転) and (FLT6_タンク下限 or not(nottimdly_FLT6_タンク下限.B))
		mINV13_洗浄ポンプD運転=(tmp1INV13_洗浄ポンプD運転 or tmp2INV13_洗浄ポンプD運転) and (FLT8_タンク下限 or not(nottimdly_FLT8_タンク下限.B))
		mINV14_洗浄ポンプE運転=(tmp1INV14_洗浄ポンプE運転 or tmp2INV14_洗浄ポンプE運転) and (FLT10_タンク下限 or not(nottimdly_FLT10_タンク下限.B))
		
		mSV97_すすぎ電磁弁=tmp1SV97_すすぎ電磁弁 or tmp2SV97_すすぎ電磁弁
		mSV98_仕上げ電磁弁=tmp1SV98_仕上げ電磁弁 or tmp2SV98_仕上げ電磁弁

		
		
		if PB45_全停止SW and not(manual洗浄コンベア) then
			if SEL2_1_運転切換（単動） then
				'コマンドスイッチ操作
			
				'pnlPBでの設定値をクリア
				tmp2SV97_すすぎ電磁弁=OFF
				tmp2SV98_仕上げ電磁弁=OFF
				tmp2INV10_洗浄ポンプA運転=OFF
				tmp2INV11_洗浄ポンプB運転=OFF
				tmp2INV12_洗浄ポンプC運転=OFF
				tmp2INV13_洗浄ポンプD運転=OFF
				tmp2INV14_洗浄ポンプE運転=OFF

				tmp2SV97_すすぎ電磁弁=OFF
				tmp2SV98_仕上げ電磁弁=OFF
				
				INV10_洗浄ポンプA洗浄=OFF
				INV11_洗浄ポンプB洗浄=OFF
				INV12_洗浄ポンプC洗浄=OFF
				INV13_洗浄ポンプD洗浄=OFF
				INV14_洗浄ポンプE洗浄=OFF

				'------------------------------------------------------------
				if ldp(PB43_洗浄ポンプSW) then
					inc(マニュアルポンプstep)
					if マニュアルポンプstep>2 then
						マニュアルポンプstep=0
					end if
				end if

				if マニュアルポンプstep>0 then
					if (FLT2_タンク下限 or not(nottimdly_FLT2_タンク下限.B)) or (FLT4_タンク下限 or not(nottimdly_FLT4_タンク下限.B)) or (FLT6_タンク下限 or not(nottimdly_FLT6_タンク下限.B)) or (FLT8_タンク下限 or not(nottimdly_FLT8_タンク下限.B)) or (FLT10_タンク下限 or not(nottimdly_FLT10_タンク下限.B))  then
						マニュアルポンプstep=マニュアルポンプstep
					else
						マニュアルポンプstep=0
					end if				
				end if

				select case マニュアルポンプstep				
				case 0
					tmp洗浄ポンプ=OFF
					INV10_洗浄ポンプA洗浄=OFF
					INV11_洗浄ポンプB洗浄=OFF
					INV12_洗浄ポンプC洗浄=OFF
					INV13_洗浄ポンプD洗浄=OFF
					INV14_洗浄ポンプE洗浄=OFF
				case 1
					tmp洗浄ポンプ=ON
					INV10_洗浄ポンプA洗浄=OFF
					INV11_洗浄ポンプB洗浄=OFF
					INV12_洗浄ポンプC洗浄=OFF
					INV13_洗浄ポンプD洗浄=OFF
					INV14_洗浄ポンプE洗浄=OFF
				case 2
					tmp洗浄ポンプ=ON
					INV10_洗浄ポンプA洗浄=ON
					INV11_洗浄ポンプB洗浄=ON
					INV12_洗浄ポンプC洗浄=ON
					INV13_洗浄ポンプD洗浄=ON
					INV14_洗浄ポンプE洗浄=ON
				end select


				tmp1SV97_すすぎ電磁弁=tmp洗浄ポンプ
				tmp1SV98_仕上げ電磁弁=tmp洗浄ポンプ
				tmp1INV10_洗浄ポンプA運転=tmp洗浄ポンプ and (FLT2_タンク下限 or not(nottimdly_FLT2_タンク下限.B)) 
				tmp1INV11_洗浄ポンプB運転=tmp洗浄ポンプ and (FLT4_タンク下限 or not(nottimdly_FLT4_タンク下限.B))
				tmp1INV12_洗浄ポンプC運転=tmp洗浄ポンプ and (FLT6_タンク下限 or not(nottimdly_FLT6_タンク下限.B))
				tmp1INV13_洗浄ポンプD運転=tmp洗浄ポンプ and (FLT8_タンク下限 or not(nottimdly_FLT8_タンク下限.B))
				tmp1INV14_洗浄ポンプE運転=tmp洗浄ポンプ and (FLT10_タンク下限 or not(nottimdly_FLT10_タンク下限.B))
				
				
			else
				'パネルスイッチ操作

				'コマンドPBでの設定値クリア
				
				マニュアルポンプstep=0
				
				tmp洗浄ポンプ=OFF
				tmp1SV97_すすぎ電磁弁=OFF
				tmp1SV98_仕上げ電磁弁=OFF
				tmp1INV10_洗浄ポンプA運転=OFF
				tmp1INV11_洗浄ポンプB運転=OFF
				tmp1INV12_洗浄ポンプC運転=OFF
				tmp1INV13_洗浄ポンプD運転=OFF
				tmp1INV14_洗浄ポンプE運転=OFF
				
				tmp1SV97_すすぎ電磁弁=OFF
				tmp1SV98_仕上げ電磁弁=OFF
				'------------------------------------------------------------
				if ldp(pnlPBINV10_洗浄ポンプA運転)then
					if tmp2INV10_洗浄ポンプA運転 then
						tmp2INV10_洗浄ポンプA運転=OFF
					else
						tmp2INV10_洗浄ポンプA運転=ON
					end if
				end if
				tmp2INV10_洗浄ポンプA運転=tmp2INV10_洗浄ポンプA運転 and FLT2_タンク下限
				'--------------------------------------
				if ldp(pnlPBINV11_洗浄ポンプB運転) then
					if tmp2INV11_洗浄ポンプB運転 then
						tmp2INV11_洗浄ポンプB運転=OFF
					else
						tmp2INV11_洗浄ポンプB運転=ON
					end if
				end if
				tmp2INV11_洗浄ポンプB運転=tmp2INV11_洗浄ポンプB運転 and FLT4_タンク下限
				'--------------------------------------
				if ldp(pnlPBINV12_洗浄ポンプC運転) then
					if tmp2INV12_洗浄ポンプC運転 then
						tmp2INV12_洗浄ポンプC運転=OFF
					else
						tmp2INV12_洗浄ポンプC運転=ON
					end if
				end if
				tmp2INV12_洗浄ポンプC運転=tmp2INV12_洗浄ポンプC運転 and FLT6_タンク下限
				'--------------------------------------
				if ldp(pnlPBINV13_洗浄ポンプD運転) then
					if tmp2INV13_洗浄ポンプD運転 then
						tmp2INV13_洗浄ポンプD運転=OFF
					else
						tmp2INV13_洗浄ポンプD運転=ON
					end if
				end if
				tmp2INV13_洗浄ポンプD運転=tmp2INV13_洗浄ポンプD運転 and FLT8_タンク下限
				'--------------------------------------
				if ldp(pnlPBINV14_洗浄ポンプE運転) then
					if tmp2INV14_洗浄ポンプE運転 then
						tmp2INV14_洗浄ポンプE運転=OFF
					else
						tmp2INV14_洗浄ポンプE運転=ON
					end if
				end if
				tmp2INV14_洗浄ポンプE運転=tmp2INV14_洗浄ポンプE運転 and FLT10_タンク下限
				'--------------------------------------
				if ldp(pnlPBSV97_すすぎ電磁弁) then
					if tmp2SV97_すすぎ電磁弁 then
						tmp2SV97_すすぎ電磁弁=OFF
					else
						tmp2SV97_すすぎ電磁弁=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBSV98_仕上げ電磁弁) then
					if tmp2SV98_仕上げ電磁弁 then
						tmp2SV98_仕上げ電磁弁=OFF
					else
						tmp2SV98_仕上げ電磁弁=ON
					end if
				end if					
				'--------------------------------------
				if ldp(pnlPBINV10_洗浄ポンプA洗浄) then
					if INV10_洗浄ポンプA洗浄 then
						INV10_洗浄ポンプA洗浄=OFF
					else
						INV10_洗浄ポンプA洗浄=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV11_洗浄ポンプB洗浄) then
					if INV11_洗浄ポンプB洗浄 then
						INV11_洗浄ポンプB洗浄=OFF
					else
						INV11_洗浄ポンプB洗浄=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV12_洗浄ポンプC洗浄) then
					if INV12_洗浄ポンプC洗浄 then
						INV12_洗浄ポンプC洗浄=OFF
					else
						INV12_洗浄ポンプC洗浄=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV13_洗浄ポンプD洗浄) then
					if INV13_洗浄ポンプD洗浄 then
						INV13_洗浄ポンプD洗浄=OFF
					else
						INV13_洗浄ポンプD洗浄=ON
					end if
				end if
				'--------------------------------------
				if ldp(pnlPBINV14_洗浄ポンプE洗浄) then
					if INV14_洗浄ポンプE洗浄 then
						INV14_洗浄ポンプE洗浄=OFF
					else
						INV14_洗浄ポンプE洗浄=ON
					end if
				end if
				'--------------------------------------

			end if	
				
		else
			PBL43_洗浄ポンプ=OFF
			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF

			mINV10_洗浄ポンプA運転=OFF
			mINV11_洗浄ポンプB運転=OFF
			mINV12_洗浄ポンプC運転=OFF
			mINV13_洗浄ポンプD運転=OFF
			mINV14_洗浄ポンプE運転=OFF
			
			INV10_洗浄ポンプA洗浄=OFF
			INV11_洗浄ポンプB洗浄=OFF
			INV12_洗浄ポンプC洗浄=OFF
			INV13_洗浄ポンプD洗浄=OFF
			INV14_洗浄ポンプE洗浄=OFF

			マニュアルポンプstep=0
			
			tmp洗浄ポンプ=OFF
			tmp1SV97_すすぎ電磁弁=OFF
			tmp1SV98_仕上げ電磁弁=OFF
			tmp1INV10_洗浄ポンプA運転=OFF
			tmp1INV11_洗浄ポンプB運転=OFF
			tmp1INV12_洗浄ポンプC運転=OFF
			tmp1INV13_洗浄ポンプD運転=OFF
			tmp1INV14_洗浄ポンプE運転=OFF
			
			tmp2SV97_すすぎ電磁弁=OFF
			tmp2SV98_仕上げ電磁弁=OFF
			tmp2INV10_洗浄ポンプA運転=OFF
			tmp2INV11_洗浄ポンプB運転=OFF
			tmp2INV12_洗浄ポンプC運転=OFF
			tmp2INV13_洗浄ポンプD運転=OFF
			tmp2INV14_洗浄ポンプE運転=OFF

			
		end if

		if not(manual洗浄コンベア) then
			if ldp(PB25_洗浄機単動運転) and (not(PH7_釜検知) and not(PH8_フタ検知)) and (not(PH9_釜検知) and not(PH10_フタ検知)) and  洗浄ユニットOrg  then
				ワンサイクルflg=ON
				洗浄完了=ON '洗浄コンベア搬送 搬送待ちをするため、強制的に洗浄完了をONさせておく。
				洗浄ユニットstep=1
			end if
		end if	
	end if '洗浄ユニットAutoMode and not(洗浄ユニットOrgErrStep)

	'===================================================================================================================
	'【 洗浄ユニットOrgErr処理 】
	else

		if ResetFlg then
			洗浄ユニットOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		洗浄ユニットErr=ON
		
		if almXSW82_釜フタ押さえ下降端A or almXSW81_釜フタ押さえ上昇端A or almXSW84_釜フタ押さえ下降端B or almXSW83_釜フタ押さえ上昇端B or INV10_洗浄ポンプA異常 then
			洗浄ユニット1Err=ON
		else
			洗浄ユニット1Err=OFF
		end if
		if almXSW87_釜フタ押さえ下降端A or almXSW86_釜フタ押さえ上昇端A or almXSW89_釜フタ押さえ下降端B or almXSW88_釜フタ押さえ上昇端B or INV11_洗浄ポンプB異常 then
			洗浄ユニット2Err=ON
		else
			洗浄ユニット2Err=OFF
		end if
		if almXSW92_釜フタ押さえ下降端A or almXSW91_釜フタ押さえ上昇端A or almXSW94_釜フタ押さえ下降端B or almXSW93_釜フタ押さえ上昇端B or INV12_洗浄ポンプC異常 then
			洗浄ユニット3Err=ON
		else
			洗浄ユニット3Err=OFF
		end if
		if almXSW97_釜フタ押さえ下降端A or almXSW96_釜フタ押さえ上昇端A or almXSW99_釜フタ押さえ下降端B or almXSW98_釜フタ押さえ上昇端B or INV13_洗浄ポンプD異常 then
			洗浄ユニット4Err=ON
		else
			洗浄ユニット4Err=OFF
		end if
		if almXSW102_釜フタ押さえ下降端A or almXSW101_釜フタ押さえ上昇端A or almXSW104_釜フタ押さえ下降端B or almXSW103_釜フタ押さえ上昇端B or INV14_洗浄ポンプE異常 then
			洗浄ユニット5Err=ON
		else
			洗浄ユニット5Err=OFF
		end if

		PBL43_洗浄ポンプ=OFF

		mINV10_洗浄ポンプA運転=OFF
		mINV11_洗浄ポンプB運転=OFF
		mINV12_洗浄ポンプC運転=OFF
		mINV13_洗浄ポンプD運転=OFF
		mINV14_洗浄ポンプE運転=OFF


		mSV97_すすぎ電磁弁=OFF
		mSV98_仕上げ電磁弁=OFF
		
		INV10_洗浄ポンプA洗浄=OFF
		INV11_洗浄ポンプB洗浄=OFF
		INV12_洗浄ポンプC洗浄=OFF
		INV13_洗浄ポンプD洗浄=OFF
		INV14_洗浄ポンプE洗浄=OFF

	
		tmr(tim_洗浄ユニットErrStep,tim_洗浄ユニットErrStep_val)
		
		select case 洗浄ユニットErrStep
		case 0

		case 1
			tim_洗浄ユニットErrStep_val=20
			res(tim_洗浄ユニットErrStep)
			inc(洗浄ユニットErrStep)
		
		case 2
			if tim_洗浄ユニットErrStep.B then
				inc(洗浄ユニットErrStep)
			end if
		
		case 3

			mSV67_釜フタ押さえ下降A=OFF
			mSV68_釜フタ押さえ下降B=OFF

			mSV73_釜フタ押さえ下降A=OFF
			mSV74_釜フタ押さえ下降B=OFF
			
			mSV79_釜フタ押さえ下降A=OFF
			mSV80_釜フタ押さえ下降B=OFF

			mSV85_釜フタ押さえ下降A=OFF
			mSV86_釜フタ押さえ下降B=OFF

			mSV91_釜フタ押さえ下降A=OFF
			mSV92_釜フタ押さえ下降B=OFF

		
			inc(洗浄ユニットErrStep)
		
		case 4
			if ResetFlg then
				almXSW82_釜フタ押さえ下降端A=OFF 'mSV67_釜フタ押さえ下降A
				almXSW81_釜フタ押さえ上昇端A=OFF
				almXSW84_釜フタ押さえ下降端B=OFF 'mSV68_釜フタ押さえ下降B
				almXSW83_釜フタ押さえ上昇端B=OFF
				
				almXSW87_釜フタ押さえ下降端A=OFF 'mSV73_釜フタ押さえ下降A 
				almXSW86_釜フタ押さえ上昇端A=OFF
				almXSW89_釜フタ押さえ下降端B=OFF 'mSV74_釜フタ押さえ下降B
				almXSW88_釜フタ押さえ上昇端B=OFF
				
				almXSW92_釜フタ押さえ下降端A=OFF 'mSV79_釜フタ押さえ下降A
				almXSW91_釜フタ押さえ上昇端A=OFF
				almXSW94_釜フタ押さえ下降端B=OFF 'mSV80_釜フタ押さえ下降B
				almXSW93_釜フタ押さえ上昇端B=OFF
				
				almXSW97_釜フタ押さえ下降端A=OFF 'mSV85_釜フタ押さえ下降A
				almXSW96_釜フタ押さえ上昇端A=OFF
				almXSW99_釜フタ押さえ下降端B=OFF 'mSV86_釜フタ押さえ下降B
				almXSW98_釜フタ押さえ上昇端B=OFF
				
				almXSW102_釜フタ押さえ下降端A=OFF 'mSV91_釜フタ押さえ下降A
				almXSW101_釜フタ押さえ上昇端A=OFF
				almXSW104_釜フタ押さえ下降端B=OFF 'mSV92_釜フタ押さえ下降B
				almXSW103_釜フタ押さえ上昇端B=OFF
				
		
				if almINV10_洗浄ポンプA異常 then
					インバータ10リセット=ON
				else if	almINV11_洗浄ポンプB異常 then
					インバータ11リセット=ON
				else if almINV12_洗浄ポンプC異常 then
					インバータ12リセット=ON
				else if almINV13_洗浄ポンプD異常 then
					インバータ13リセット=ON
				else if almINV14_洗浄ポンプE異常 then
					インバータ14リセット=ON							
				end if
			
			 	almINV10_洗浄ポンプA異常=OFF
			 	almINV11_洗浄ポンプB異常=OFF
			 	almINV12_洗浄ポンプC異常=OFF
			 	almINV13_洗浄ポンプD異常=OFF
			 	almINV14_洗浄ポンプE異常=OFF

				inc(洗浄ユニットErrStep)
			end if

		
		case 5
			洗浄ユニットErr=OFF
			洗浄ユニット1Err=OFF
			洗浄ユニット2Err=OFF
			洗浄ユニット3Err=OFF
			洗浄ユニット4Err=OFF
			洗浄ユニット5Err=OFF

			INV10_洗浄ポンプA洗浄=OFF
			INV11_洗浄ポンプB洗浄=OFF
			INV12_洗浄ポンプC洗浄=OFF
			INV13_洗浄ポンプD洗浄=OFF
			INV14_洗浄ポンプE洗浄=OFF

			res(tim_XSW82_釜フタ押さえ下降端A)
			res(tim_XSW81_釜フタ押さえ上昇端A)
			res(tim_XSW84_釜フタ押さえ下降端B)
			res(tim_XSW83_釜フタ押さえ上昇端B)
			res(tim_XSW87_釜フタ押さえ下降端A)
			res(tim_XSW86_釜フタ押さえ上昇端A)
			res(tim_XSW89_釜フタ押さえ下降端B)
			res(tim_XSW88_釜フタ押さえ上昇端B)
			res(tim_XSW92_釜フタ押さえ下降端A)
			res(tim_XSW91_釜フタ押さえ上昇端A)
			res(tim_XSW94_釜フタ押さえ下降端B)
			res(tim_XSW93_釜フタ押さえ上昇端B)
			res(tim_XSW97_釜フタ押さえ下降端A)
			res(tim_XSW96_釜フタ押さえ上昇端A)
			res(tim_XSW99_釜フタ押さえ下降端B)
			res(tim_XSW98_釜フタ押さえ上昇端B)
			res(tim_XSW102_釜フタ押さえ下降端A)
			res(tim_XSW101_釜フタ押さえ上昇端A)
			res(tim_XSW104_釜フタ押さえ下降端B)
			res(tim_XSW103_釜フタ押さえ上昇端B)

			洗浄ユニットStep=201
			洗浄ユニットErrStep=0
		end select

	end if 'if 洗浄ユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 洗浄ユニットEmgStep
	case 0

	case 1
		洗浄ユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		
		if 洗浄ユニットstep<>0 or ワンサイクルflg then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			mINV10_洗浄ポンプA運転=OFF
			mINV11_洗浄ポンプB運転=OFF
			mINV12_洗浄ポンプC運転=OFF
			mINV13_洗浄ポンプD運転=OFF
			mINV14_洗浄ポンプE運転=OFF

			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF
			INV10_洗浄ポンプA洗浄=OFF
			INV11_洗浄ポンプB洗浄=OFF
			INV12_洗浄ポンプC洗浄=OFF
			INV13_洗浄ポンプD洗浄=OFF
			INV14_洗浄ポンプE洗浄=OFF

			tmp洗浄ポンプ=OFF
			tmp1SV97_すすぎ電磁弁=OFF
			tmp1SV98_仕上げ電磁弁=OFF
			tmp1INV10_洗浄ポンプA運転=OFF
			tmp1INV11_洗浄ポンプB運転=OFF
			tmp1INV12_洗浄ポンプC運転=OFF
			tmp1INV13_洗浄ポンプD運転=OFF
			tmp1INV14_洗浄ポンプE運転=OFF
			
			tmp2SV97_すすぎ電磁弁=OFF
			tmp2SV98_仕上げ電磁弁=OFF
			tmp2INV10_洗浄ポンプA運転=OFF
			tmp2INV11_洗浄ポンプB運転=OFF
			tmp2INV12_洗浄ポンプC運転=OFF
			tmp2INV13_洗浄ポンプD運転=OFF
			tmp2INV14_洗浄ポンプE運転=OFF

			if timstack=OFF then
				
				tim_洗浄入口フタ釜検知_stack.U=tim_洗浄入口フタ釜検知.U
				tim_procstep_stack.U=tim_procstep.U
				tim_洗浄ユニットErrStep_stack.U=tim_洗浄ユニットErrStep.U
			' tmr(PH46_フタ検知 or PH45_釜検知,tim_洗浄入口フタ釜検知,20)
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(tim_洗浄ユニットErrStep,tim_洗浄ユニットErrStep_val)

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mINV10_洗浄ポンプA運転=OFF
			mINV11_洗浄ポンプB運転=OFF
			mINV12_洗浄ポンプC運転=OFF
			mINV13_洗浄ポンプD運転=OFF
			mINV14_洗浄ポンプE運転=OFF

			mSV97_すすぎ電磁弁=OFF
			mSV98_仕上げ電磁弁=OFF
			INV10_洗浄ポンプA洗浄=OFF
			INV11_洗浄ポンプB洗浄=OFF
			INV12_洗浄ポンプC洗浄=OFF
			INV13_洗浄ポンプD洗浄=OFF
			INV14_洗浄ポンプE洗浄=OFF

			tmp洗浄ポンプ=OFF
			tmp1SV97_すすぎ電磁弁=OFF
			tmp1SV98_仕上げ電磁弁=OFF
			tmp1INV10_洗浄ポンプA運転=OFF
			tmp1INV11_洗浄ポンプB運転=OFF
			tmp1INV12_洗浄ポンプC運転=OFF
			tmp1INV13_洗浄ポンプD運転=OFF
			tmp1INV14_洗浄ポンプE運転=OFF
			
			tmp2SV97_すすぎ電磁弁=OFF
			tmp2SV98_仕上げ電磁弁=OFF
			tmp2INV10_洗浄ポンプA運転=OFF
			tmp2INV11_洗浄ポンプB運転=OFF
			tmp2INV12_洗浄ポンプC運転=OFF
			tmp2INV13_洗浄ポンプD運転=OFF
			tmp2INV14_洗浄ポンプE運転=OFF

			mSV67_釜フタ押さえ下降A=OFF
			mSV68_釜フタ押さえ下降B=OFF
			mSV73_釜フタ押さえ下降A=OFF
			mSV74_釜フタ押さえ下降B=OFF
			mSV79_釜フタ押さえ下降A=OFF
			mSV80_釜フタ押さえ下降B=OFF
			mSV85_釜フタ押さえ下降A=OFF
			mSV86_釜フタ押さえ下降B=OFF
			mSV91_釜フタ押さえ下降A=OFF
			mSV92_釜フタ押さえ下降B=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄ユニットEmgStep)
	case 2
		if ResetFlg then
			inc(洗浄ユニットEmgStep)
		end if
	case 3
		if  洗浄ユニットstep<>0  or ワンサイクルflg then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------				
				tim_洗浄入口フタ釜検知.U=tim_洗浄入口フタ釜検知_stack.U
				tim_procstep.U=tim_procstep_stack.U
				tim_洗浄ユニットErrStep.U=tim_洗浄ユニットErrStep_stack.U
				' tmr(PH46_フタ検知 or PH45_釜検知,tim_洗浄入口フタ釜検知,20)
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(tim_洗浄ユニットErrStep,tim_洗浄ユニットErrStep_val)
				
				'---------------------------------
				inc(洗浄ユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------

			
			
			'---------------------------------
			inc(洗浄ユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		洗浄ユニットEmgStep=0
		洗浄ユニットEmg=OFF
	end select
		
end if 'if Emgstep_proc=0 then
