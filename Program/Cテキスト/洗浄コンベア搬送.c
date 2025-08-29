'洗浄コンベア搬送
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄コンベア搬送
'	
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    洗浄コンベア搬送AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    洗浄コンベア搬送AutoRun=OFF
    洗浄コンベア搬送許可=ON
    洗浄コンベア搬送OrgErr=OFF
    洗浄コンベア搬送Err=OFF
    洗浄コンベア搬送Emg=OFF
    洗浄コンベア搬送step=0
    洗浄コンベア搬送ErrStep=0
    洗浄コンベア搬送OrgErrStep=0
    洗浄コンベア搬送EmgStep=0

	INV1_コンベアモータ正転step=0
	INV2_コンベアモータ正転step=0
	INV3_コンベアモータ正転step=0
	
	ワンサイクルflg=OFF
	
	ManualInite=1

end if
'===================================================================================================================
'【 原点 】洗浄搬送禁止
洗浄コンベア搬送Org=(not(SV71_釜フタストッパ) and ((XSW85_釜フタストッパ下降端 and not(pnlPBXSW85_釜フタストッパ下降端)) or passXSW85_釜フタストッパ下降端)) or (SV71_釜フタストッパ and (not(XSW85_釜フタストッパ下降端) or pnlPBXSW85_釜フタストッパ下降端))
洗浄コンベア搬送Org=洗浄コンベア搬送Org and (not(SV77_釜フタストッパ) and ((XSW90_釜フタストッパ下降端 and not(pnlPBXSW90_釜フタストッパ下降端)) or passXSW90_釜フタストッパ下降端)) or (SV77_釜フタストッパ and (not(XSW90_釜フタストッパ下降端) or pnlPBXSW90_釜フタストッパ下降端))
洗浄コンベア搬送Org=洗浄コンベア搬送Org and (not(SV83_釜フタストッパ) and ((XSW95_釜フタストッパ下降端 and not(pnlPBXSW95_釜フタストッパ下降端)) or passXSW95_釜フタストッパ下降端)) or (SV83_釜フタストッパ and (not(XSW95_釜フタストッパ下降端) or pnlPBXSW95_釜フタストッパ下降端)) 
洗浄コンベア搬送Org=洗浄コンベア搬送Org and (not(SV89_釜フタストッパ) and ((XSW100_釜フタストッパ下降端 and not(pnlPBXSW100_釜フタストッパ下降端)) or passXSW100_釜フタストッパ下降端)) or (SV89_釜フタストッパ and (not(XSW100_釜フタストッパ下降端) or pnlPBXSW100_釜フタストッパ下降端)) 
洗浄コンベア搬送Org=洗浄コンベア搬送Org and (not(SV95_釜フタストッパ) and ((XSW105_釜フタストッパ下降端 and not(pnlPBXSW105_釜フタストッパ下降端)) or passXSW105_釜フタストッパ下降端)) or (SV95_釜フタストッパ and (not(XSW105_釜フタストッパ下降端) or pnlPBXSW105_釜フタストッパ下降端))
洗浄コンベア搬送Org=洗浄コンベア搬送Org or 洗浄搬送禁止

'===================================================================================================================
'【 緊急停止 】
if not(PB非常停止) then
	洗浄コンベア搬送Emg=ON
	洗浄コンベア搬送EmgStep=1
end if
'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(not(SV71_釜フタストッパ) and not(XSW85_釜フタストッパ下降端) and not(pnlPBXSW85_釜フタストッパ下降端), tim_notXSW85_釜フタストッパ下降端,#20)
tmr(not(SV77_釜フタストッパ) and not(XSW90_釜フタストッパ下降端) and not(pnlPBXSW90_釜フタストッパ下降端), tim_notXSW90_釜フタストッパ下降端,#20)
tmr(not(SV83_釜フタストッパ) and not(XSW95_釜フタストッパ下降端) and not(pnlPBXSW95_釜フタストッパ下降端), tim_notXSW95_釜フタストッパ下降端,#20)
tmr(not(SV89_釜フタストッパ) and not(XSW100_釜フタストッパ下降端) and not(pnlPBXSW100_釜フタストッパ下降端), tim_notXSW100_釜フタストッパ下降端,#20)
tmr(not(SV95_釜フタストッパ) and not(XSW105_釜フタストッパ下降端) and not(pnlPBXSW105_釜フタストッパ下降端), tim_notXSW105_釜フタストッパ下降端,#20)

'tmr(SV71_釜フタストッパ and XSW85_釜フタストッパ下降端 and not(pnlPBXSW85_釜フタストッパ下降端), tim_XSW85_釜フタストッパ下降端,#10)
if LDF(SV71_釜フタストッパ) and XSW85_釜フタストッパ下降端 and not(pnlPBXSW85_釜フタストッパ下降端) then
	SET(tim_XSW85_釜フタストッパ下降端)
end if
'tmr(SV77_釜フタストッパ and XSW90_釜フタストッパ下降端 and not(pnlPBXSW90_釜フタストッパ下降端), tim_XSW90_釜フタストッパ下降端,#10)
if LDF(SV77_釜フタストッパ) and XSW90_釜フタストッパ下降端 and not(pnlPBXSW90_釜フタストッパ下降端) then
	SET(tim_XSW90_釜フタストッパ下降端)
end if
'tmr(SV83_釜フタストッパ and XSW95_釜フタストッパ下降端 and not(pnlPBXSW95_釜フタストッパ下降端), tim_XSW95_釜フタストッパ下降端,#10)
if LDF(SV83_釜フタストッパ) and XSW95_釜フタストッパ下降端 and not(pnlPBXSW95_釜フタストッパ下降端) then
	SET(tim_XSW95_釜フタストッパ下降端)
end if
'tmr(SV89_釜フタストッパ and XSW100_釜フタストッパ下降端 and not(pnlPBXSW100_釜フタストッパ下降端), tim_XSW100_釜フタストッパ下降端,#10)
if LDF(SV89_釜フタストッパ) and XSW100_釜フタストッパ下降端 and not(pnlPBXSW100_釜フタストッパ下降端) then
	SET(tim_XSW100_釜フタストッパ下降端)
end if
'tmr(SV95_釜フタストッパ and XSW105_釜フタストッパ下降端 and not(pnlPBXSW105_釜フタストッパ下降端), tim_XSW105_釜フタストッパ下降端,#10)
if LDF(SV95_釜フタストッパ) and XSW105_釜フタストッパ下降端 and not(pnlPBXSW105_釜フタストッパ下降端) then
	SET(tim_XSW105_釜フタストッパ下降端)
end if

'passtimXSW85_釜フタストッパ下降端_val=#500
tms(not(SV71_釜フタストッパ), passtimXSW85_釜フタストッパ下降端,passtimXSW85_釜フタストッパ下降端_val)

'passtimXSW90_釜フタストッパ下降端_val=#500
tms(not(SV77_釜フタストッパ), passtimXSW90_釜フタストッパ下降端,passtimXSW90_釜フタストッパ下降端_val)

'passtimXSW95_釜フタストッパ下降端_val=#500
tms(not(SV83_釜フタストッパ), passtimXSW95_釜フタストッパ下降端,passtimXSW95_釜フタストッパ下降端_val) 

'passtimXSW100_釜フタストッパ下降端_val=#500
tms(not(SV89_釜フタストッパ), passtimXSW100_釜フタストッパ下降端,passtimXSW100_釜フタストッパ下降端_val) 

'passtimXSW105_釜フタストッパ下降端_val=#500
tms(not(SV95_釜フタストッパ), passtimXSW105_釜フタストッパ下降端,passtimXSW105_釜フタストッパ下降端_val) 

'tmr(mINV1_コンベアモータ正転 and not(tmp2INV1_コンベアモータ正転) and not(pauseINV1_コンベアモータ正転) and not(EmgINV1_コンベアモータ正転),timerr_INV1_コンベアモータ正転,#150)
'tmr(mINV2_コンベアモータ正転 and not(tmp2INV2_コンベアモータ正転) and not(pauseINV2_コンベアモータ正転) and not(EmgINV2_コンベアモータ正転),timerr_INV2_コンベアモータ正転,#200)
'tmr(ejectINV3_コンベアモータ正転 and not(tmp2INV3_コンベアモータ正転) and not(pauseINV3_コンベアモータ正転) and not(EmgINV3_コンベアモータ正転),timerr_INV3_コンベアモータ正転,#200)

if ldp(timerr_INV1_コンベアモータ正転.B) then
	almINV1_コンベアモータ正転=ON

	mINV1_コンベアモータ正転=OFF
	mINV2_コンベアモータ正転=OFF
	ejectINV3_コンベアモータ正転=OFF
	

	洗浄コンベア搬送ErrStep=1

else if ldp(timerr_INV2_コンベアモータ正転.B) then
	almINV2_コンベアモータ正転=ON

	mINV1_コンベアモータ正転=OFF
	mINV2_コンベアモータ正転=OFF
	ejectINV3_コンベアモータ正転=OFF
	
	洗浄コンベア搬送ErrStep=1


else if ldp(timerr_INV3_コンベアモータ正転) then
	almINV3_コンベアモータ正転=ON

	mINV1_コンベアモータ正転=OFF
	mINV2_コンベアモータ正転=OFF
	ejectINV3_コンベアモータ正転=OFF
	
	洗浄コンベア搬送ErrStep=1

else if (ldp(tim_XSW85_釜フタストッパ下降端.B) or ldp(tim_notXSW85_釜フタストッパ下降端.B)) and not(pnlPBXSW85_釜フタストッパ下降端) then
	almXSW85_釜フタストッパ下降端=ON
	pnlPBXSW85_釜フタストッパ下降端=ON
	if tim_XSW85_釜フタストッパ下降端 then
		res(tim_XSW85_釜フタストッパ下降端)
	end if
	洗浄コンベア搬送ErrStep=1

else if (ldp(tim_XSW90_釜フタストッパ下降端.B) or ldp(tim_notXSW90_釜フタストッパ下降端.B)) and not(pnlPBXSW90_釜フタストッパ下降端) then
	almXSW90_釜フタストッパ下降端=ON
	pnlPBXSW90_釜フタストッパ下降端=ON
	if tim_XSW90_釜フタストッパ下降端 then
		res(tim_XSW90_釜フタストッパ下降端)
	end if
	洗浄コンベア搬送ErrStep=1

else if (ldp(tim_XSW95_釜フタストッパ下降端.B) or ldp(tim_notXSW95_釜フタストッパ下降端.B)) and not(pnlPBXSW95_釜フタストッパ下降端) then
	almXSW95_釜フタストッパ下降端=ON
	pnlPBXSW95_釜フタストッパ下降端=ON
	if tim_XSW95_釜フタストッパ下降端 then
		res(tim_XSW95_釜フタストッパ下降端)
	end if
	洗浄コンベア搬送ErrStep=1

else if (ldp(tim_XSW100_釜フタストッパ下降端.B) or ldp(tim_notXSW100_釜フタストッパ下降端.B)) and not(pnlPBXSW100_釜フタストッパ下降端) then
	almXSW100_釜フタストッパ下降端=ON
	pnlPBXSW100_釜フタストッパ下降端=ON
	if tim_XSW100_釜フタストッパ下降端 then
		res(tim_XSW100_釜フタストッパ下降端)
	end if
	洗浄コンベア搬送ErrStep=1

else if (ldp(tim_XSW105_釜フタストッパ下降端.B) or ldp(tim_notXSW105_釜フタストッパ下降端.B)) and not(pnlPBXSW105_釜フタストッパ下降端) then
	almXSW105_釜フタストッパ下降端=ON
	pnlPBXSW105_釜フタストッパ下降端=ON
	if tim_XSW105_釜フタストッパ下降端 then
		res(tim_XSW105_釜フタストッパ下降端)
	end if
	洗浄コンベア搬送ErrStep=1

end if
'===================================================================================================================
'【 フタ釜検出LSディレー】
'tmr(LS11_釜フタ検知,timdly_LS11_釜フタ検知,2)
'tmr(LS12_釜フタ検知,timdly_LS12_釜フタ検知,2)
'tmr(LS13_釜フタ検知,timdly_LS13_釜フタ検知,2)
'tmr(LS14_釜フタ検知,timdly_LS14_釜フタ検知,2)
'tmr(LS15_釜フタ検知,timdly_LS15_釜フタ検知,2)

TMR(PH7_釜検知,timdly_PH7_釜検知,4)
TMR(PH8_フタ検知,timdly_PH8_フタ検知,4)

TMR(PH45_釜検知,timdly_PH45_釜検知,4)
TMR(PH46_フタ検知,timdly_PH46_フタ検知,4)

	
if 洗浄コンベア搬送AutoRun  then	
	if not(洗浄ユニット1禁止) and (MC35_洗浄ポンプA and INV10_洗浄ポンプA運転 and  getEDC1_PV>=(setEDC1_SV-5) ) then
		配米準備釜数カウント可能=ON
	else if not(洗浄ユニット2禁止) and (MC36_洗浄ポンプB and INV11_洗浄ポンプB運転 and  getEDC2_PV>=(setEDC2_SV-5) ) then
		配米準備釜数カウント可能=ON
	else if not(洗浄ユニット3禁止) and (MC37_洗浄ポンプC and INV12_洗浄ポンプC運転 and  getEDC3_PV>=(setEDC3_SV-5) ) then
		配米準備釜数カウント可能=ON
	else if not(洗浄ユニット4禁止) and (MC38_洗浄ポンプD and INV13_洗浄ポンプD運転 and  getEDC4_PV>=(setEDC4_SV-5) ) then
		配米準備釜数カウント可能=ON
	else if not(洗浄ユニット5禁止) and (MC39_洗浄ポンプE and INV14_洗浄ポンプE運転 and  getEDC5_PV>=(setEDC5_SV-5) ) then
		配米準備釜数カウント可能=ON	
	end if
else
	配米準備釜数カウント可能=OFF
end if


if not(配米準備釜数カウント可能) then
	IND_洗浄準備中=ON
else
	IND_洗浄準備中=OFF
end if



'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄コンベア搬送AutoMode	自動モード セレクトスイッチ
'System :: 洗浄コンベア搬送AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄コンベア搬送Emg	その場停止


if not(洗浄コンベア搬送Emg) then  
	
	if 洗浄コンベア搬送ErrStep=0  then

	if not(洗浄コンベア搬送OrgErr) then

	if ワンサイクルflg or (洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) or 洗浄コンベア搬送step<>0 then
	
		if not(洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) then
			洗浄コンベア搬送AutoRun=OFF
		end if

		if ManualInite=1 then
			PBL44_コンベア=OFF
		
			mSV71_釜フタストッパ=ON
			mSV77_釜フタストッパ=ON
			mSV83_釜フタストッパ=ON
			mSV89_釜フタストッパ=ON
			mSV95_釜フタストッパ=ON

			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF
			
			manual洗浄コンベア=OFF
			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF
	
			ManualInite=0
		end if

	'------------------------------------------------------------------------------------------------
	'INV1_コンベアモータ正転
	tmr(tim_INV1_コンベアモータ正転,tim_INV1_コンベアモータ正転_val)
	
	select case INV1_コンベアモータ正転step
	
	case 0
	
	case 1
		PH45_釜起動検知=timdly_PH45_釜検知
		PH46_フタ起動検知=timdly_PH46_フタ検知		

		if PH45_釜起動検知 or PH46_フタ起動検知 then

			if PH45_釜起動検知 or PH46_フタ起動検知 then			
				if PH45_釜起動検知 and PH46_フタ起動検知 then
					shiftreg釜フタ判定0=$80

					if 配米準備釜数カウント可能 and 炊飯機点火実行確認【済】 then
						if 配米準備釜数現在値<配米準備釜数設定値 then
							inc(配米準備釜数現在値)
						end if
					end if			


					if DM_EndCnt>0 then
						dec(DM_EndCnt)
					end if
										
					
				else if not(PH45_釜起動検知) and PH46_フタ起動検知 then
					shiftreg釜フタ判定0=$40			
				end if
			else
				shiftreg釜フタ判定0=$0
			end if


			inc(INV1_コンベアモータ正転step)
		else
			INV1_コンベアモータ正転step=0
			洗浄入口搬送排出要求=OFF
		end if

	case 2
		setS05c1=6000
		setS08c1=10
		setS09c1=10
		mINV1_コンベアモータ正転=ON
		inc(INV1_コンベアモータ正転step)
	
	case 3
		if not(PH45_釜検知) and not(PH46_フタ検知) then
			'if not(LS11_釜フタ検知) then
				inc(INV1_コンベアモータ正転step)
			'end if
		end if


	case 4
		'if LS11_釜フタ検知 then
			tim_INV1_コンベアモータ正転_val=70 'モータ停止タイミング
			res(tim_INV1_コンベアモータ正転)
			inc(INV1_コンベアモータ正転step)
		'end if
	
	case 5
		if tim_INV1_コンベアモータ正転.B then
			inc(INV1_コンベアモータ正転step)
		end if
		
	case 6
		mINV1_コンベアモータ正転=OFF
		inc(INV1_コンベアモータ正転step)
	
	case 7
		洗浄入口搬送排出要求=OFF
		INV1_コンベアモータ正転step=0

	end select
	'------------------------------------------------------------------------------------------------
	'INV2_コンベアモータ正転
	tmr(tim_INV2_コンベアモータ正転,tim_INV2_コンベアモータ正転_val)
	
	select case INV2_コンベアモータ正転step
	
	case 0
	
	case 1
		tim_INV2_コンベアモータ正転_val=INV2起動待ち時間 '1号機(0) 2号機(10)
		res(tim_INV2_コンベアモータ正転)
		inc(INV2_コンベアモータ正転step)
		
	case 2
		if tim_INV2_コンベアモータ正転.B then
			inc(INV2_コンベアモータ正転step)
		end if		
	
	case 3
		inc(INV2_コンベアモータ正転step)

	case 4
		setS05c2=6000
		setS08c2=10 '<- 洗浄コンベア搬送モジュール 22/1/13 20から10に変更 
		setS09c2=20 '<-停止調整
		mINV2_コンベアモータ正転=ON

		inc(INV2_コンベアモータ正転step)
	
	case 5
		'if tim_INV2_コンベアモータ正転.B or (not(LS11_釜フタ検知) and not(LS12_釜フタ検知) and not(LS13_釜フタ検知) and not(LS14_釜フタ検知) and not(LS15_釜フタ検知) )then
			inc(INV2_コンベアモータ正転step)
		'end if
	

	
	case 6
		tim_INV2_コンベアモータ正転_val=ストッパー上昇タイミング
		res(tim_INV2_コンベアモータ正転)
		inc(INV2_コンベアモータ正転step)

	case 7
		if tim_INV2_コンベアモータ正転.B then
			mSV71_釜フタストッパ=ON	'ストッパー上昇
			mSV77_釜フタストッパ=ON
			mSV83_釜フタストッパ=ON
			mSV89_釜フタストッパ=ON
			mSV95_釜フタストッパ=ON

			tim_INV2_コンベアモータ正転_val=120 '時限停止時間
			res(tim_INV2_コンベアモータ正転)
			inc(INV2_コンベアモータ正転step)
		end if
	

	case 8	
		'if (LS12_釜フタ検知 and timdly_LS12_釜フタ検知) or (LS13_釜フタ検知 and timdly_LS13_釜フタ検知) or (LS14_釜フタ検知 and timdly_LS14_釜フタ検知) or (LS15_釜フタ検知 and timdly_LS15_釜フタ検知) or tim_INV2_コンベアモータ正転.B then
			tim_INV2_コンベアモータ正転_val=INV2ブレーキタイミング '1号機(28) 2号機(24)
			res(tim_INV2_コンベアモータ正転)
			inc(INV2_コンベアモータ正転step)
		'end if
		
	case 9
		if tim_INV2_コンベアモータ正転.B then
			inc(INV2_コンベアモータ正転step)
		end if
	
	case 10
		mINV2_コンベアモータ正転=OFF
		inc(INV2_コンベアモータ正転step)
	
	case 11
		tim_INV2_コンベアモータ正転_val=15 '終了タイミング
		res(tim_INV2_コンベアモータ正転)
		inc(INV2_コンベアモータ正転step)

	case 12
		if tim_INV2_コンベアモータ正転.B then
			inc(INV2_コンベアモータ正転step)
		end if	
	
	case 13
		INV2_コンベアモータ正転step=0

	end select
	
	'------------------------------------------------------------------------------------------------
	'INV3_コンベアモータ正転
	tmr(tim_INV3_コンベアモータ正転,tim_INV3_コンベアモータ正転_val)
	
	select case INV3_コンベアモータ正転step
	
	case 0
	
	case 1
		if PH7_釜検知 or PH8_フタ検知 then
			INV3_コンベアモータ正転step=0
		else
			inc(INV3_コンベアモータ正転step)	
		end if
	
	case 2
		setS05c3=6000
		setS08c3=5
		setS09c3=5
		ejectINV3_コンベアモータ正転=ON
		
		
		StageDevice36=shiftreg釜フタ判定5 'StageDevice37 , 釜:$80  フタ:$40


		LatchPH7_釜検知=OFF
		LatchPH8_フタ検知=OFF
		
		inc(INV3_コンベアモータ正転step)

	case 3
		if not(PH7_釜検知) and not(PH8_フタ検知) then
				tim_INV3_コンベアモータ正転_val=120 'モータ停止タイミング
				res(tim_INV3_コンベアモータ正転)
				inc(INV3_コンベアモータ正転step)
		end if

	case 4
		if (PH7_釜検知 and timdly_PH7_釜検知) or (PH8_フタ検知 and timdly_PH8_フタ検知) or tim_INV3_コンベアモータ正転.B then
		
			if SEL2_1_運転切換（単動） and tim_INV3_コンベアモータ正転.B then
				StageDevice36=0
			end if
			
			inc(INV3_コンベアモータ正転step)
		end if
		
	case 5
		ejectINV3_コンベアモータ正転=OFF
		inc(INV3_コンベアモータ正転step)
	
	case 6
		if PH7_釜検知 or PH8_フタ検知 then
			洗浄コンベア搬送排出要求=ON
		else
			洗浄コンベア搬送排出要求=OFF
		end if		
	
		
		INV3_コンベアモータ正転step=0
	
	end select
	'------------------------------------------------------------------------------------------------


	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 洗浄コンベア搬送step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 洗浄コンベア搬送AutoRun or ワンサイクルflg then
				inc(洗浄コンベア搬送step)
			else 
				洗浄コンベア搬送step=0 '終了待機
			end if

		
		case 2
			if PH7_釜検知 or PH8_フタ検知 then
				StageDevice36=shiftreg釜フタ判定6
				洗浄コンベア搬送排出要求=ON
				洗浄コンベア搬送step=1
			else
				inc(洗浄コンベア搬送step)
			end if
							

		case 3
		
		' [ 次の搬送コンベア停止確認 ]
			if (洗浄コンベア搬送排出要求=OFF or ワンサイクルflg) and  洗浄出口搬送動作中=OFF and  (洗浄入口搬送排出要求 or ワンサイクルflg)  and 洗浄ユニットOrg then
				inc(洗浄コンベア搬送step)
			else
				洗浄コンベア搬送step=1
			end if
		
		case 4
			if 洗浄完了 then
				inc(洗浄コンベア搬送step)
			else
				洗浄コンベア搬送step=1
			end if
		
		case 5
			'押さえシリンダー上昇端確認
			inc(洗浄コンベア搬送step)
		
		case 6
			inc(洗浄コンベア搬送step)
			
		case 7
			洗浄コンベア搬送動作中=ON
			洗浄コンベア搬送step=100			
		'--------------------------------------------------------------------------------------------------------------
		case 100			
			mSV71_釜フタストッパ=OFF	'ストッパー下降
			mSV77_釜フタストッパ=OFF
			mSV83_釜フタストッパ=OFF
			mSV89_釜フタストッパ=OFF
			mSV95_釜フタストッパ=OFF
			
			inc(洗浄コンベア搬送step)
		
		case 101
			'ストッパ下降端確認
			if (XSW85_釜フタストッパ下降端 and not(pnlPBXSW85_釜フタストッパ下降端)) or passXSW85_釜フタストッパ下降端 then
				if (XSW90_釜フタストッパ下降端 and not(pnlPBXSW90_釜フタストッパ下降端)) or passXSW90_釜フタストッパ下降端 then
					if (XSW95_釜フタストッパ下降端 and not(pnlPBXSW95_釜フタストッパ下降端)) or passXSW95_釜フタストッパ下降端 then
						if (XSW100_釜フタストッパ下降端 and not(pnlPBXSW100_釜フタストッパ下降端)) or passXSW100_釜フタストッパ下降端 then
							if (XSW105_釜フタストッパ下降端 and not(pnlPBXSW105_釜フタストッパ下降端)) or passXSW105_釜フタストッパ下降端 then
								inc(洗浄コンベア搬送step)
							end if
						end if
					end if
				end if
			end if

		case 102
			tim_procstep_val=10 '洗浄入口フタ釜検出時間待ち
			res(tim_procstep)
			inc(洗浄コンベア搬送step)

		case 103
			if tim_procstep.B then			
				inc(洗浄コンベア搬送step)
			end if

		case 104

			INV1_コンベアモータ正転step=1			
			INV2_コンベアモータ正転step=1
			INV3_コンベアモータ正転step=1
			
			inc(洗浄コンベア搬送step)
		
		case 105
			if INV1_コンベアモータ正転step=0 and  INV2_コンベアモータ正転step=0 and INV3_コンベアモータ正転step=0 then
				inc(洗浄コンベア搬送step)
			end if
		

		case 106
			洗浄完了=OFF
			洗浄入口搬送排出要求=OFF
			洗浄コンベア搬送動作中=OFF
			
					
			shiftreg釜フタ判定8	=	shiftreg釜フタ判定7
			shiftreg釜フタ判定7	=	shiftreg釜フタ判定6
			shiftreg釜フタ判定6	=	shiftreg釜フタ判定5
			shiftreg釜フタ判定5	=	shiftreg釜フタ判定4
			shiftreg釜フタ判定4	=	shiftreg釜フタ判定3
			shiftreg釜フタ判定3	=	shiftreg釜フタ判定2
			shiftreg釜フタ判定2	=	shiftreg釜フタ判定1
			shiftreg釜フタ判定1	=	shiftreg釜フタ判定0
			shiftreg釜フタ判定0 = 0

			inc(洗浄コンベア搬送step)

		case 107
			tim_procstep_val=30
			res(tim_procstep)
			inc(洗浄コンベア搬送step)

		case 108
			if tim_procstep.B then			
				inc(洗浄コンベア搬送step)
			end if
		
		case 109
			ワンサイクルflg=OFF

			洗浄コンベア搬送step=1

		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
		if ManualInite=0 and ワンサイクルflg=OFF then
			PBL44_コンベア=OFF
		
			mSV71_釜フタストッパ=OFF
			mSV77_釜フタストッパ=OFF
			mSV83_釜フタストッパ=OFF
			mSV89_釜フタストッパ=OFF
			mSV95_釜フタストッパ=OFF

			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF
			
			manual洗浄コンベア=OFF
			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF
			
			ManualInite=1
		end if

		洗浄コンベア搬送AutoRun=OFF
		洗浄コンベア搬送step=0 '終了
		

		'---------------------------------------------------------------------
		'釜フタストッパ下降端検出
		'---------------------------------------------------------------------
		if (not(XSW85_釜フタストッパ下降端) or pnlPBXSW85_釜フタストッパ下降端) and (not(XSW90_釜フタストッパ下降端) or pnlPBXSW90_釜フタストッパ下降端) then
			if  (not(XSW95_釜フタストッパ下降端) or pnlPBXSW95_釜フタストッパ下降端) and (not(XSW100_釜フタストッパ下降端) or pnlPBXSW100_釜フタストッパ下降端) then
				if (not(XSW105_釜フタストッパ下降端) or pnlPBXSW105_釜フタストッパ下降端) then
					釜フタストッパ下降端=ON
				else
					釜フタストッパ下降端=OFF
				end if
			else
				釜フタストッパ下降端=OFF
			end if
		else
			釜フタストッパ下降端=OFF
		end if

		'---------------------------------------------------------------------
		' 洗浄コンベア マニュアル運転
		'---------------------------------------------------------------------
		PBL44_コンベア=mINV1_コンベアモータ正転 or mINV2_コンベアモータ正転 or ejectINV3_コンベアモータ正転
		
		mINV1_コンベアモータ正転=tmp1INV1_コンベアモータ正転 or tmp2INV1_コンベアモータ正転
		mINV2_コンベアモータ正転=tmp1INV2_コンベアモータ正転 or tmp2INV2_コンベアモータ正転
		ejectINV3_コンベアモータ正転=tmp1INV3_コンベアモータ正転 or tmp2INV3_コンベアモータ正転
		
		if PB45_全停止SW and not(timdly_PH7_釜検知) and not(timdly_PH8_フタ検知) then
			
		
		
			if SEL2_1_運転切換（単動） then
				if 洗浄ユニットOrg and 洗浄コンベア搬送Org and 洗浄出口搬送Org then 
			
					tmp2INV1_コンベアモータ正転=OFF
					tmp2INV2_コンベアモータ正転=OFF
					tmp2INV3_コンベアモータ正転=OFF
					
					if ldp(PB44_コンベアSW) then
						if manual洗浄コンベア then
							manual洗浄コンベア=OFF
						else
							manual洗浄コンベア=ON
						end if
					end if
					
					tmp1INV1_コンベアモータ正転=manual洗浄コンベア
					tmp1INV2_コンベアモータ正転=manual洗浄コンベア
					tmp1INV3_コンベアモータ正転=manual洗浄コンベア
			  else
					if ldp(PB44_コンベアSW) then
						if not(洗浄ユニットOrg) then
							洗浄ユニットOrgErr=ON
						end if
						
						if not(洗浄コンベア搬送Org) then
							洗浄コンベア搬送OrgErr=ON
						end if
						
						if not(洗浄出口搬送Org) then
							洗浄出口搬送OrgErr=ON
						end if
					end if
			  end if
			else
				
					manual洗浄コンベア=OFF
					tmp1INV1_コンベアモータ正転=OFF
					tmp1INV2_コンベアモータ正転=OFF
					tmp1INV3_コンベアモータ正転=OFF

					if ldp(pnlPBINV1_コンベアモータ正転) then
						if tmp2INV1_コンベアモータ正転 then
							tmp2INV1_コンベアモータ正転=OFF
						else
							tmp2INV1_コンベアモータ正転=ON
						end if
					end if
							
				if 洗浄ユニットOrg and 洗浄コンベア搬送Org  and 洗浄出口搬送Org then 
					if ldp(pnlPBINV2_コンベアモータ正転) then
						if tmp2INV2_コンベアモータ正転 then
							tmp2INV2_コンベアモータ正転=OFF
						else
							tmp2INV2_コンベアモータ正転=ON
						end if
					end if

					if ldp(pnlPBINV3_コンベアモータ正転) then
						if tmp2INV3_コンベアモータ正転 then
							tmp2INV3_コンベアモータ正転=OFF
						else
							tmp2INV3_コンベアモータ正転=ON
						end if
					end if
				else
					if ldp(pnlPBINV2_コンベアモータ正転) or ldp(pnlPBINV3_コンベアモータ正転) then
						if not(洗浄ユニットOrg) then
							洗浄ユニットOrgErr=ON
						end if
						
						if not(洗浄コンベア搬送Org) then
							洗浄コンベア搬送OrgErr=ON
						end if
						
						if not(洗浄出口搬送Org) then
							洗浄出口搬送OrgErr=ON
						end if

					end if								
				end if
			end if

		else
			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF
			
			manual洗浄コンベア=OFF
			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF
						
		end if
		'---------------------------------------------------------------------		
		'洗浄ストッパ  マニュアル運転		
		'---------------------------------------------------------------------		
		if not(manual洗浄コンベア) then
		
			if ldp(pnlPBSV71_釜フタストッパ) then
				if mSV71_釜フタストッパ then
					mSV71_釜フタストッパ=OFF
				else
					mSV71_釜フタストッパ=ON
				end if
			end if
			
			if ldp(pnlPBSV77_釜フタストッパ) then
				if mSV77_釜フタストッパ then
					mSV77_釜フタストッパ=OFF
				else
					mSV77_釜フタストッパ=ON
				end if
			end if
			
			if ldp(pnlPBSV83_釜フタストッパ) then
				if mSV83_釜フタストッパ then
					mSV83_釜フタストッパ=OFf
				else
					mSV83_釜フタストッパ=ON
				end if
			end if
			
			if ldp(pnlPBSV89_釜フタストッパ) then
				if mSV89_釜フタストッパ then
					mSV89_釜フタストッパ=OFF
				else
					mSV89_釜フタストッパ=ON
				end if
			end if
			
			if ldp(pnlPBSV95_釜フタストッパ) then
				if mSV95_釜フタストッパ then
					mSV95_釜フタストッパ=OFF
				else
					mSV95_釜フタストッパ=ON
				end if
			end if
			
			if ldp(PB25_洗浄機単動運転) and (not(PH7_釜検知) and not(PH8_フタ検知))  and (not(PH9_釜検知) and not(PH10_フタ検知)) and  洗浄ユニットOrg then

					ワンサイクルflg=ON
					洗浄コンベア搬送step=1

			end if
			
		end if		
		
	end if '洗浄コンベア搬送AutoMode and not(洗浄コンベア搬送OrgErrStep)

	'===================================================================================================================
	'【 洗浄コンベア搬送OrgErr処理 】
	else
	
		if ResetFlg then
			洗浄コンベア搬送OrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'【タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		洗浄コンベア搬送Err=ON


		mINV1_コンベアモータ正転=OFF
		mINV2_コンベアモータ正転=OFF
		ejectINV3_コンベアモータ正転=OFF

		mSV71_釜フタストッパ=OFF
		mSV77_釜フタストッパ=OFF
		mSV83_釜フタストッパ=OFF
		mSV89_釜フタストッパ=OFF
		mSV95_釜フタストッパ=OFF
		
		INV1_コンベアモータ正転step=0
		INV2_コンベアモータ正転step=0
		INV3_コンベアモータ正転step=0
		洗浄コンベア搬送step=0
		ワンサイクルflg=OFF

		洗浄コンベア搬送動作中=OFF

		tmr(tim_洗浄コンベア搬送ErrStep,tim_洗浄コンベア搬送ErrStep_val)
		
		select case 洗浄コンベア搬送ErrStep
		case 0
		
		'------------------------------------------------------------------
		case 1
			alm渋滞警報=ON			

			if ResetFlg then
				alm渋滞警報=OFF			
		 		inc(洗浄コンベア搬送ErrStep)
			end if
			
		case 2
			almINV1_コンベアモータ正転=OFF
			almINV2_コンベアモータ正転=OFF			
			almINV3_コンベアモータ正転=OFF
			almXSW85_釜フタストッパ下降端=OFF
			almXSW90_釜フタストッパ下降端=OFF
			almXSW95_釜フタストッパ下降端=OFF
			almXSW100_釜フタストッパ下降端=OFF
			almXSW105_釜フタストッパ下降端=OFF
			almLS6_空釜反転反転位置=OFF
			almLS5_空釜反転原点位置=OFF
			almMC10_反転モータ正転=OFF			
			almMC10_反転モータ逆転=OFF

			inc(洗浄コンベア搬送ErrStep)
		case 3
			洗浄コンベア搬送Err=OFF

			res(tim_XSW85_釜フタストッパ下降端.B)
			res(tim_XSW90_釜フタストッパ下降端.B)
			res(tim_XSW95_釜フタストッパ下降端.B)
			res(tim_XSW100_釜フタストッパ下降端.B)
			res(tim_XSW105_釜フタストッパ下降端.B)

			res(tim_notXSW85_釜フタストッパ下降端.B)
			res(tim_notXSW90_釜フタストッパ下降端.B)
			res(tim_notXSW95_釜フタストッパ下降端.B)
			res(tim_notXSW100_釜フタストッパ下降端.B)
			res(tim_notXSW105_釜フタストッパ下降端.B)

			洗浄コンベア搬送step=0
			INV1_コンベアモータ正転step=0
			INV2_コンベアモータ正転step=0
			INV3_コンベアモータ正転step=0

			洗浄コンベア搬送ErrStep=0
		end select

	end if 'if 洗浄コンベア搬送ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 洗浄コンベア搬送EmgStep
	case 0
	
	case 1
		洗浄コンベア搬送AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if ワンサイクルflg or (洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) or 洗浄コンベア搬送step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC10_反転モータ逆転=ON
			pauseMC10_反転モータ正転=ON
			
			pauseINV1_コンベアモータ正転=ON
			pauseINV2_コンベアモータ正転=ON
			pauseINV3_コンベアモータ正転=ON
			
			if timstack=OFF then
				'tmr(tim_INV1_コンベアモータ正転,tim_INV1_コンベアモータ正転_val)
				'tmr(tim_INV2_コンベアモータ正転,tim_INV2_コンベアモータ正転_val)
				'tmr(tim_INV3_コンベアモータ正転,tim_INV3_コンベアモータ正転_val)
				'tmr(tim_MC10_反転モータ正転,tim_MC10_反転モータ正転_val)
				'tmr(tim_MC10_反転モータ逆転,tim_MC10_反転モータ逆転_val)
				'tmr(tim_procstep,tim_procstep_val)
				'tmr(tim_洗浄コンベア搬送ErrStep,tim_洗浄コンベア搬送ErrStep_val)

				tim_INV1_コンベアモータ正転_stack=tim_INV1_コンベアモータ正転.U
				if mINV2_コンベアモータ正転 then
					tim_INV2_コンベアモータ正転_stack=tim_INV2_コンベアモータ正転.U+20
				else
					tim_INV2_コンベアモータ正転_stack=tim_INV2_コンベアモータ正転.U
				end if				
				tim_INV3_コンベアモータ正転_stack=tim_INV3_コンベアモータ正転.U
				tim_procstep_stack=tim_procstep.U
				tim_洗浄コンベア搬送ErrStep_stack=tim_洗浄コンベア搬送ErrStep.U

				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------			
			mINV1_コンベアモータ正転=OFF
			mINV2_コンベアモータ正転=OFF
			ejectINV3_コンベアモータ正転=OFF

			mSV71_釜フタストッパ=OFF	'ストッパー下降
			mSV77_釜フタストッパ=OFF
			mSV83_釜フタストッパ=OFF
			mSV89_釜フタストッパ=OFF
			mSV95_釜フタストッパ=OFF

			tmp1INV1_コンベアモータ正転=OFF
			tmp1INV2_コンベアモータ正転=OFF
			tmp1INV3_コンベアモータ正転=OFF
			tmp2INV1_コンベアモータ正転=OFF
			tmp2INV2_コンベアモータ正転=OFF
			tmp2INV3_コンベアモータ正転=OFF

			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄コンベア搬送EmgStep)
	case 2
		if ResetFlg then
			inc(洗浄コンベア搬送EmgStep)
		end if
	case 3
		if ワンサイクルflg or (洗浄コンベア搬送AutoMode and 自動搬送AutoMode ) or 洗浄コンベア搬送step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC10_反転モータ逆転=OFF
				pauseMC10_反転モータ正転=OFF
				
				pauseINV1_コンベアモータ正転=OFF
				pauseINV2_コンベアモータ正転=OFF
				pauseINV3_コンベアモータ正転=OFF
				
				tim_INV1_コンベアモータ正転.U=tim_INV1_コンベアモータ正転_stack
				tim_INV2_コンベアモータ正転.U=tim_INV2_コンベアモータ正転_stack
				tim_INV3_コンベアモータ正転.U=tim_INV3_コンベアモータ正転_stack
				tim_procstep.U=tim_procstep_stack
				tim_洗浄コンベア搬送ErrStep.U=tim_洗浄コンベア搬送ErrStep_stack

				
				'---------------------------------
				inc(洗浄コンベア搬送EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(洗浄コンベア搬送EmgStep)		
		end if				
	case 4
		timstack=OFF
		洗浄コンベア搬送EmgStep=0
		洗浄コンベア搬送Emg=OFF
	end select

		
end if 'if Emgstep_proc=0 then
