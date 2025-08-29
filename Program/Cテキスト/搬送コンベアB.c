'搬送コンベアB
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアB
'
'  	移動速度  161.667mm/1sec
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

	搬送コンベアBAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアBAutoRun=OFF
    搬送コンベアB許可=ON
    搬送コンベアBOrgErr=OFF
    搬送コンベアBErr=OFF
    搬送コンベアBEmg=OFF
    搬送コンベアBstep=0
    搬送コンベアBErrStep=0
    搬送コンベアBOrgErrStep=0
    搬送コンベアBEmgStep=0
	
	SV21_ストッパstep=0
	SV22_ストッパstep=0
	MC9_モータローラstep=0
	MC16_モータローラstep=0
	MC12_搬送モータstep=0
	MC13_搬送モータstep=0
	
	ManualInite=1
	
end if

'===================================================================================================================
'【 原点 】
搬送コンベアBOrg=1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアBEmg=ON
	搬送コンベアBEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV21_ストッパ and not(XSW20_ストッパ上昇端) and not(pnlPBXSW20_ストッパ上昇端), tim_notXSW20_ストッパ上昇端,#20) '428.63ms
tmr(not(SV21_ストッパ) and not(XSW19_ストッパ下降端) and not(pnlPBXSW19_ストッパ下降端),tim_notXSW19_ストッパ下降端,#20) '474.35ms
tmr(SV22_ストッパ and not(XSW22_ストッパ上昇端) and not(pnlPBXSW22_ストッパ上昇端),tim_notXSW22_ストッパ上昇端,#20) '544.79ms
tmr(not(SV22_ストッパ) and not(XSW21_ストッパ下降端) and not(pnlPBXSW21_ストッパ下降端),tim_notXSW21_ストッパ下降端,#20) '480.27ms
tmr(SV65_ストッパ and not(XSW75_ストッパ上昇端) and not(pnlPBXSW75_ストッパ上昇端), tim_notXSW75_ストッパ上昇端,#20) '768.11ms
tmr(not(SV65_ストッパ) and not(XSW74_ストッパ下降端) and not(pnlPBXSW74_ストッパ下降端),tim_notXSW74_ストッパ下降端,#20) '626.94ms
tmr(SV33_リフト and not(XSW38_リフト上昇端) and not(pnlPBXSW38_リフト上昇端), tim_notXSW38_リフト上昇端, #30) '654.33ms
tmr(not(SV33_リフト) and not(XSW37_リフト下降端) and not(pnlPBXSW37_リフト下降端),tim_notXSW37_リフト下降端,#30) '932.62ms
tmr(SV16_リフト and not(XSW16_リフト上昇端) and not(pnlPBXSW16_リフト上昇端),tim_notXSW16_リフト上昇端,#30) '1171.94ms
tmr(not(SV16_リフト) and not(XSW15_リフト下降端) and not(pnlPBXSW15_リフト下降端),tim_notXSW15_リフト下降端,#30) '1437.09ms

'tmr(not(SV21_ストッパ) and XSW20_ストッパ上昇端, tim_XSW20_ストッパ上昇端,#10)
if LDP(SV21_ストッパ) and XSW20_ストッパ上昇端 and not(pnlPBXSW20_ストッパ上昇端) then
	SET(tim_XSW20_ストッパ上昇端)
end if
'tmr(SV21_ストッパ and XSW19_ストッパ下降端,tim_XSW19_ストッパ下降端,#10)
if LDF(SV21_ストッパ) and XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端) then
	SET(tim_XSW19_ストッパ下降端)
end if
'tmr(not(SV22_ストッパ) and XSW22_ストッパ上昇端,tim_XSW22_ストッパ上昇端,#10)
if LDP(SV22_ストッパ) and XSW22_ストッパ上昇端 and not(pnlPBXSW22_ストッパ上昇端) then
	SET(tim_XSW22_ストッパ上昇端)
end if
'tmr(SV22_ストッパ and XSW21_ストッパ下降端,tim_XSW21_ストッパ下降端,#10)
if LDF(SV22_ストッパ) and XSW21_ストッパ下降端 and not(pnlPBXSW21_ストッパ下降端) then
	SET(tim_XSW21_ストッパ下降端)
end if
'tmr(not(SV65_ストッパ) and XSW75_ストッパ上昇端, tim_XSW75_ストッパ上昇端,#10)
if LDP(SV65_ストッパ) and XSW75_ストッパ上昇端 and not(pnlPBXSW75_ストッパ上昇端) then
	SET(tim_XSW75_ストッパ上昇端)
end if
'tmr(SV65_ストッパ and XSW74_ストッパ下降端,tim_XSW74_ストッパ下降端,#10)
if LDF(SV65_ストッパ) and XSW74_ストッパ下降端 and not(pnlPBXSW74_ストッパ下降端) then
	SET(tim_XSW74_ストッパ下降端)
end if
'tmr(not(SV33_リフト) and XSW38_リフト上昇端, tim_XSW38_リフト上昇端, #10)
if LDP(SV33_リフト) and  XSW38_リフト上昇端 and not(pnlPBXSW38_リフト上昇端) then
	SET(tim_XSW38_リフト上昇端)
end if
'tmr(SV33_リフト and XSW37_リフト下降端,tim_XSW37_リフト下降端,#10)
if LDF(SV33_リフト) and  XSW37_リフト下降端 and not(pnlPBXSW37_リフト下降端) then
	SET(tim_XSW37_リフト下降端)
end if
'tmr(not(SV16_リフト) and XSW16_リフト上昇端 ,tim_XSW16_リフト上昇端,#10)
if LDP(SV16_リフト) and XSW16_リフト上昇端 and not(pnlPBXSW16_リフト上昇端) then
	SET(tim_XSW16_リフト上昇端)
end if
'tmr(SV16_リフト and XSW15_リフト下降端,tim_XSW15_リフト下降端,#10)
if LDF(SV16_リフト) and XSW15_リフト下降端 and not(pnlPBXSW15_リフト下降端) then
	SET(tim_XSW15_リフト下降端)
end if

'passtimXSW20_ストッパ上昇端_val=#428
tms(SV21_ストッパ, passtimXSW20_ストッパ上昇端,passtimXSW20_ストッパ上昇端_val)

'passtimXSW19_ストッパ下降端_val=#474
tms(not(SV21_ストッパ),passtimXSW19_ストッパ下降端,passtimXSW19_ストッパ下降端_val) 

'passtimXSW22_ストッパ上昇端_val=#544
tms(SV22_ストッパ,passtimXSW22_ストッパ上昇端,passtimXSW22_ストッパ上昇端_val)

'passtimXSW21_ストッパ下降端_val=#480
tms(not(SV22_ストッパ),passtimXSW21_ストッパ下降端,passtimXSW21_ストッパ下降端_val)

'passtimXSW16_リフト上昇端_val=#1171
tms(SV16_リフト,passtimXSW16_リフト上昇端,passtimXSW16_リフト上昇端_val) 

'passtimXSW15_リフト下降端_val=#1437
tms(not(SV16_リフト),passtimXSW15_リフト下降端,passtimXSW15_リフト下降端_val) 

tmr(mMC9_モータローラ and not(pauseMC9_モータローラ) and not(EmgMC9_モータローラ),timerr_MC9_モータローラ,#150)
tmr(mMC12_搬送モータ and not(pauseMC12_搬送モータ) and not(EmgMC12_搬送モータ),timerr_MC12_搬送モータ,#150)
tmr(mMC13_搬送モータ and not(pauseMC13_搬送モータ) and not(EmgMC13_搬送モータ),timerr_MC13_搬送モータ,#150)
tmr(mMC16_モータローラ and not(pauseMC16_モータローラ) and not(EmgMC16_モータローラ),timerr_MC16_モータローラ,#150)


if ldp(timerr_MC9_モータローラ.B) then
	almMC9_モータローラ=ON

	mMC9_モータローラ=OFF
	mMC12_搬送モータ=OFF
	mMC13_搬送モータ=OFF
	mMC16_モータローラ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC12_搬送モータ.B) then
	almMC12_搬送モータ=ON

	mMC9_モータローラ=OFF
	mMC12_搬送モータ=OFF
	mMC13_搬送モータ=OFF
	mMC16_モータローラ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC13_搬送モータ.B) then
	almMC13_搬送モータ=ON

	mMC9_モータローラ=OFF
	mMC12_搬送モータ=OFF
	mMC13_搬送モータ=OFF
	mMC16_モータローラ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC16_モータローラ.B) then
	almMC16_モータローラ=ON

	mMC9_モータローラ=OFF
	mMC12_搬送モータ=OFF
	mMC13_搬送モータ=OFF
	mMC16_モータローラ=OFF

	コンベア一時停止=ON

end if

if (ldp(tim_XSW20_ストッパ上昇端.B) or ldp(tim_notXSW20_ストッパ上昇端.B)) and not(pnlPBXSW20_ストッパ上昇端) then
	pauseSV21_ストッパ=ON
	almXSW20_ストッパ上昇端=ON
	pnlPBXSW20_ストッパ上昇端=ON
	if tim_XSW20_ストッパ上昇端 then
		res(tim_XSW20_ストッパ上昇端)
	end if
	搬送コンベアBErrStep=1

else if (ldp(tim_XSW19_ストッパ下降端.B) or ldp(tim_notXSW19_ストッパ下降端.B)) and not(pnlPBXSW19_ストッパ下降端) then
	almXSW19_ストッパ下降端=ON
	pnlPBXSW19_ストッパ下降端=ON
	if tim_XSW19_ストッパ下降端 then
		res(tim_XSW19_ストッパ下降端)
	end if
	搬送コンベアBErrStep=1

else if (ldp(tim_XSW22_ストッパ上昇端.B) or ldp(tim_notXSW22_ストッパ上昇端.B)) and not(pnlPBXSW22_ストッパ上昇端) then
	pauseSV22_ストッパ=ON
	almXSW22_ストッパ上昇端=ON
	pnlPBXSW22_ストッパ上昇端=ON
	if tim_XSW22_ストッパ上昇端 then
		res(tim_XSW22_ストッパ上昇端)
	end if
	搬送コンベアBErrStep=1

else if (ldp(tim_XSW21_ストッパ下降端.B) or ldp(tim_notXSW21_ストッパ下降端.B)) and not(pnlPBXSW21_ストッパ下降端) then
	almXSW21_ストッパ下降端=ON
	pnlPBXSW21_ストッパ下降端=ON
	if tim_XSW21_ストッパ下降端 then
		res(tim_XSW21_ストッパ下降端)
	end if
	搬送コンベアBErrStep=1

else if 搬送コンベアB動作中 and not(搬送コンベアC動作中) and (ldp(tim_XSW75_ストッパ上昇端.B) or ldp(tim_notXSW75_ストッパ上昇端.B)) and not(pnlPBXSW75_ストッパ上昇端) then
	pauseSV65_ストッパ=ON
	almXSW75_ストッパ上昇端=ON
	pnlPBXSW75_ストッパ上昇端=ON
	if tim_XSW75_ストッパ上昇端 then
		res(tim_XSW75_ストッパ上昇端)
	end if
	搬送コンベアBErrStep=1

else if 搬送コンベアB動作中 and not(搬送コンベアC動作中) and (ldp(tim_XSW74_ストッパ下降端.B) or ldp(tim_notXSW74_ストッパ下降端.B)) and not(pnlPBXSW74_ストッパ下降端) then
	almXSW74_ストッパ下降端=ON
	pnlPBXSW74_ストッパ下降端=ON
	if tim_XSW74_ストッパ下降端 then
		res(tim_XSW74_ストッパ下降端)
	end if
	搬送コンベアBErrStep=1
	
else if 搬送コンベアB動作中 and not(搬送コンベアC動作中) and (ldp(tim_XSW38_リフト上昇端.B) or ldp(tim_notXSW38_リフト上昇端.B)) and not(pnlPBXSW38_リフト上昇端) then
	pauseSV33_リフト=ON
	almXSW38_リフト上昇端=ON
	pnlPBXSW38_リフト上昇端=ON
	if tim_XSW38_リフト上昇端 then
		res(tim_XSW38_リフト上昇端)
	end if
	搬送コンベアBErrStep=1

else if 搬送コンベアB動作中 and not(搬送コンベアC動作中) and (ldp(tim_XSW37_リフト下降端.B) or ldp(tim_notXSW37_リフト下降端.B)) and not(pnlPBXSW37_リフト下降端) then
	almXSW37_リフト下降端=ON
	pnlPBXSW37_リフト下降端=ON
	if tim_XSW37_リフト下降端 then
		res(tim_XSW37_リフト下降端)
	end if
	搬送コンベアBErrStep=1

else if (ldp(tim_XSW16_リフト上昇端.B) or ldp(tim_notXSW16_リフト上昇端.B)) and not(pnlPBXSW16_リフト上昇端) then
	pauseSV16_リフト=ON
	almXSW16_リフト上昇端=ON
	pnlPBXSW16_リフト上昇端=ON
	if tim_XSW16_リフト上昇端 then
		res(tim_XSW16_リフト上昇端)
	end if
	搬送コンベアBErrStep=1

else if (ldp(tim_XSW15_リフト下降端.B) or ldp(tim_notXSW15_リフト下降端.B)) and not(pnlPBXSW15_リフト下降端) then
	almXSW15_リフト下降端=ON
	pnlPBXSW15_リフト下降端=ON
	if tim_XSW15_リフト下降端 then
		res(tim_XSW15_リフト下降端)
	end if
	搬送コンベアBErrStep=1

end if

tmr(PH5_釜検知,timdly_PH5_釜起動検知,20)
tmr(PH6_フタ検知,timdly_PH6_フタ起動検知,20)

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアBAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアBAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアBEmg	その場停止


if 搬送コンベアBEmgStep=0 then  
	
	if 搬送コンベアBErrStep=0  then

	if not(コンベア一時停止) then

	if not(搬送コンベアBOrgErr) then
	
	if (搬送コンベアBAutoMode and 自動搬送AutoMode ) or 搬送コンベアBstep<>0 then

	if ManualInite=1 then
		mSV21_ストッパ=ON
		mSV22_ストッパ=ON
		ManualInite=0
	end if

	tmr(PH11_釜検知,timdly_PH11_釜検知,5)
	tmr(PH12_フタ検知,timdly_PH12_フタ検知,5)
	tmr(PH13_釜検知,timdly_PH13_釜検知,5)
	tmr(PH14_フタ検知,timdly_PH14_フタ検知,5)
	tmr(PH15_釜検知,timdly_PH15_釜検知,5)
	tmr(PH16_フタ検知,timdly_PH16_フタ検知,5)
	
	'-----------------------------------------------------------------
	' 搬送モータ、ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	tmr(tim_SV21_ストッパ,tim_SV21_ストッパ_val)
	select case SV21_ストッパstep
	case 0
	case 1
		'PH11_釜起動検知=PH11_釜検知
		'PH12_フタ起動検知=PH12_フタ検知
		
		if PH5_釜起動検知 or PH6_フタ起動検知 or PH11_釜起動検知 or PH12_フタ起動検知 then
			mSV21_ストッパ=OFF
			inc(SV21_ストッパstep)
		else
			SV21_ストッパstep=0
		end if
	
	case 2
		if (XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端)) or passXSW19_ストッパ下降端 then
			inc(SV21_ストッパstep)
		end if
	
	case 3
		if errpassコンベア一時停止 then
			inc(SV21_ストッパstep)
			
		else if not(PH11_釜検知) and not(PH12_フタ検知) then
			inc(SV21_ストッパstep)
		end if
	
	case 4
		if errpassコンベア一時停止 then
			inc(SV21_ストッパstep)
			
		else if  PH5_釜起動検知 or PH6_フタ起動検知 then
			if (PH11_釜検知 and timdly_PH11_釜検知.B) or (PH12_フタ検知 and timdly_PH12_フタ検知.B) then
				inc(SV21_ストッパstep)
			end if
		else if PH11_釜起動検知 or PH12_フタ起動検知 then
			if (PH13_釜検知 and timdly_PH13_釜検知.B) or (PH14_フタ検知 and timdly_PH14_フタ検知.B) then
				inc(SV21_ストッパstep)
			end if
		end if
	
	case 5
		tim_SV21_ストッパ_val=0
		res(tim_SV21_ストッパ)
		inc(SV21_ストッパstep)
	
	case 6
		if tim_SV21_ストッパ.B then
			inc(SV21_ストッパstep)
		end if
		
	
	case 7
		mSV21_ストッパ=ON
		inc(SV21_ストッパstep)

	case 8
		if (XSW20_ストッパ上昇端 and not(pnlPBXSW20_ストッパ上昇端)) or passXSW20_ストッパ上昇端 then
			inc(SV21_ストッパstep)
		end if
	
	case 9
		tim_SV21_ストッパ_val=0
		res(tim_SV21_ストッパ)
		inc(SV21_ストッパstep)
	
	case 10
		if tim_SV21_ストッパ.B then
			inc(SV21_ストッパstep)
		end if
	
	case 11
		SV21_ストッパstep=0
		
	end select	

	'--------------------------------------------
	tmr(tim_SV22_ストッパ, tim_SV22_ストッパ_val)
	select case SV22_ストッパstep
	case 0
	case 1
		'PH11_釜起動検知=PH11_釜検知
		'PH12_フタ起動検知=PH12_フタ検知
		'PH13_釜起動検知=PH13_釜検知
		'PH14_フタ起動検知=PH14_フタ検知
	
		if PH11_釜起動検知 or PH12_フタ起動検知 or PH13_釜起動検知 or PH14_フタ起動検知 then
			mSV22_ストッパ=OFF
			inc(SV22_ストッパstep)
		else
			SV22_ストッパstep=0
		end if
	
	case 2
		if (XSW21_ストッパ下降端 and not(pnlPBXSW21_ストッパ下降端)) or passXSW21_ストッパ下降端 then
			inc(SV22_ストッパstep)
		end if
	
	case 3
		if errpassコンベア一時停止 then
			inc(SV22_ストッパstep)
			
		else if not(PH13_釜検知) and not(PH14_フタ検知) then
			inc(SV22_ストッパstep)
		end if
	
	case 4
		inc(SV22_ストッパstep)
	
	case 5
		if errpassコンベア一時停止 then
			inc(SV22_ストッパstep)
			
		else if PH13_釜起動検知 or PH14_フタ起動検知 then
			if (PH15_釜検知 and timdly_PH15_釜検知.B) or (PH16_フタ検知 and timdly_PH16_フタ検知.B) then
				tim_SV22_ストッパ_val=25
				res(tim_SV22_ストッパ)
				inc(SV22_ストッパstep)
			end if
		else
			inc(SV22_ストッパstep)
		end if
	
	case 6
		if tim_SV22_ストッパ.B then
			inc(SV22_ストッパstep)
		end if
	
	case 7
		mSV22_ストッパ=ON
		inc(SV22_ストッパstep)
	
	case 8
		if (XSW22_ストッパ上昇端 and not(pnlPBXSW22_ストッパ上昇端)) or passXSW22_ストッパ上昇端 then
			inc(SV22_ストッパstep)
		end if		
	
	case 9
		tim_SV22_ストッパ_val=0
		res(tim_SV22_ストッパ)
		inc(SV22_ストッパstep)
	
	case 10
		if tim_SV22_ストッパ.B then
			inc(SV22_ストッパstep)
		end if
	
	case 11
		SV22_ストッパstep=0
	
	end select	
	'--------------------------------------------
	tmr(tim_MC9_モータローラ,tim_MC9_モータローラ_val)
	select case MC9_モータローラstep
	case 0
	case 1
		if  PH5_釜起動検知 or PH6_フタ起動検知 then
			mSV16_リフト=ON
			inc(MC9_モータローラstep)
		else
			MC9_モータローラstep=0
		end if
	
	case 2
		if (XSW16_リフト上昇端 and not(pnlPBXSW16_リフト上昇端)) or passXSW16_リフト上昇端 then
			inc(MC9_モータローラstep)
		end if

	case 3
		mMC9_モータローラ=ON
		errpassコンベア一時停止=OFF
		inc(MC9_モータローラstep)

	case 4
		if errpassコンベア一時停止 then
			inc(MC9_モータローラstep)		
		
		else if not(PH5_釜検知) and not(PH11_釜検知) and not(PH12_フタ検知) then
			inc(MC9_モータローラstep)
		end if
	
	case 5
		if errpassコンベア一時停止 then
			inc(MC9_モータローラstep)		

		else if PH5_釜起動検知 or PH6_フタ起動検知 then
			if (PH11_釜検知 and timdly_PH11_釜検知.B) or (PH12_フタ検知 and timdly_PH12_フタ検知.B) then
				inc(MC9_モータローラstep)
			end if
		end if
	
	case 6
		mMC9_モータローラ=OFF
		inc(MC9_モータローラstep)
	
	case 7
		tim_MC9_モータローラ_val=0
		res(tim_MC9_モータローラ)
		inc(MC9_モータローラstep)
	
	case 8
		if tim_MC9_モータローラ.B then
			inc(MC9_モータローラstep)
		end if
	
	case 9
		mSV16_リフト=OFF
		inc(MC9_モータローラstep)
	
	case 10
		if (XSW15_リフト下降端 and not(pnlPBXSW15_リフト下降端)) or passXSW15_リフト下降端 then
			inc(MC9_モータローラstep)
		end if		
	
	case 11
		搬送コンベアA排出要求=OFF
		搬送コンベアB動作中=OFF
		MC9_モータローラstep=0
	end select
	
	
	'-----------------------------------------------------------------
	'MC12_搬送モータ
	tmr(tim_MC12_搬送モータ,tim_MC12_搬送モータ_val)
	select case MC12_搬送モータstep
	case 0
	case 1
		'PH11_釜起動検知=PH11_釜検知
		'PH12_フタ起動検知=PH12_フタ検知
		
		if PH5_釜起動検知 or PH6_フタ起動検知 or PH11_釜起動検知 or PH12_フタ起動検知 then
			if (XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端)) or passXSW19_ストッパ下降端 then
				mMC12_搬送モータ=ON
				errpassコンベア一時停止=OFF
				inc(MC12_搬送モータstep)
			end if
		else
			MC12_搬送モータstep=0
		end if
	

	case 2
		if errpassコンベア一時停止 then
			inc(MC12_搬送モータstep)
		
		else if not(PH11_釜検知) and not(PH12_フタ検知) then
			inc(MC12_搬送モータstep)
		end if
	
	case 3
		if errpassコンベア一時停止 then
			inc(MC12_搬送モータstep)
		
		else if PH5_釜起動検知 or PH6_フタ起動検知 then
			if (PH11_釜検知 and timdly_PH11_釜検知.B) or (PH12_フタ検知 and timdly_PH12_フタ検知.B) then
				inc(MC12_搬送モータstep)
			end if
		else if PH11_釜起動検知 or PH12_フタ起動検知 then
			if (PH13_釜検知 and timdly_PH13_釜検知.B) or (PH14_フタ検知 and timdly_PH14_フタ検知.B) then
				inc(MC12_搬送モータstep)
			end if
		end if
	
	case 4
		tim_MC12_搬送モータ_val=10
		res(tim_MC12_搬送モータ)
		inc(MC12_搬送モータstep)
	
	case 5
		if tim_MC12_搬送モータ.B then
			inc(MC12_搬送モータstep)
		end if

	
	case 6
		mMC12_搬送モータ=OFF
		inc(MC12_搬送モータstep)
	
	case 7
		tim_MC12_搬送モータ_val=0
		res(tim_MC12_搬送モータ)
		inc(MC12_搬送モータstep)
	
	case 8
		if tim_MC12_搬送モータ.B then
			inc(MC12_搬送モータstep)
		end if
	
	case 9
		MC12_搬送モータstep=0

	end select

	'-----------------------------------------------------------------
	'MC13_搬送モータ
	tmr(tim_MC13_搬送モータ,tim_MC13_搬送モータ_val)
	select case MC13_搬送モータstep
	case 0
	case 1
		'PH11_釜起動検知=PH11_釜検知
		'PH12_フタ起動検知=PH12_フタ検知
		'PH13_釜起動検知=PH13_釜検知
		'PH14_フタ起動検知=PH14_フタ検知
		
		if PH11_釜起動検知 or PH12_フタ起動検知 or PH13_釜起動検知 or PH14_フタ起動検知 then
			if (XSW21_ストッパ下降端 and not(pnlPBXSW21_ストッパ下降端))  or passXSW21_ストッパ下降端 then
				mMC13_搬送モータ=ON
				errpassコンベア一時停止=OFF
				inc(MC13_搬送モータstep)
			end if
		else
			MC13_搬送モータstep=0
		end if
	

		
	case 2
		if errpassコンベア一時停止 then
			inc(MC13_搬送モータstep)
		
		else if not(PH13_釜検知) and not(PH14_フタ検知) then
			inc(MC13_搬送モータstep)
		end if
	
	case 3
		if errpassコンベア一時停止 then
			inc(MC13_搬送モータstep)

		else if PH11_釜起動検知 or PH12_フタ起動検知 then
			if (PH13_釜検知 and timdly_PH13_釜検知.B) or (PH14_フタ検知 and timdly_PH14_フタ検知.B) then
				inc(MC13_搬送モータstep)
			end if
		else if PH13_釜起動検知 or PH14_フタ起動検知 then
			if (PH15_釜検知 and timdly_PH15_釜検知.B) or (PH16_フタ検知 and timdly_PH16_フタ検知.B) then
				inc(MC13_搬送モータstep)
			end if
		end if
	
	case 4
		tim_MC13_搬送モータ_val=10
		res(tim_MC13_搬送モータ)
		inc(MC13_搬送モータstep)
	
	case 5
		if tim_MC13_搬送モータ.B then
			inc(MC13_搬送モータstep)
		end if
	
	case 6
		mMC13_搬送モータ=OFF
		inc(MC13_搬送モータstep)
	
	case 7
		tim_MC13_搬送モータ_val=0
		res(tim_MC13_搬送モータ)
		inc(MC13_搬送モータstep)
	
	case 8
		if tim_MC13_搬送モータ.B then
			inc(MC13_搬送モータstep)
		end if
	
	case 9
		MC13_搬送モータstep=0

	end select
	'--------------------------------------------
	tmr(tim_MC16_モータローラ,tim_MC16_モータローラ_val)
	select case MC16_モータローラstep
	case 0
	case 1
		'PH13_釜起動検知=PH13_釜検知
		'PH14_フタ起動検知=PH14_フタ検知
		
		if PH13_釜起動検知 or PH14_フタ起動検知 then
			mSV33_リフト=ON
			mSV65_ストッパ=ON
			inc(MC16_モータローラstep)
		else
			MC16_モータローラstep=0
		end if
		
	
	case 2
		if mSV33_リフト and mSV65_ストッパ then
			if ((XSW38_リフト上昇端 and not(pnlPBXSW38_リフト上昇端)) or passXSW38_リフト上昇端) and ((XSW75_ストッパ上昇端 and not(pnlPBXSW75_ストッパ上昇端)) or passXSW75_ストッパ上昇端) then
				inc(MC16_モータローラstep)
			end if
		else
			inc(MC16_モータローラstep)
		end if

	case 3
		mMC16_モータローラ=ON
		errpassコンベア一時停止=OFF
		inc(MC16_モータローラstep)
	
	case 4
		if errpassコンベア一時停止 then
			inc(MC16_モータローラstep)

		else if not(PH13_釜検知) and not(PH14_フタ検知)  then
			inc(MC16_モータローラstep)
		end if
	
	case 5
		if errpassコンベア一時停止 then
			inc(MC16_モータローラstep)

		else if PH13_釜起動検知 or PH14_フタ起動検知 then
			if (PH15_釜検知 and timdly_PH15_釜検知.B) or (PH16_フタ検知 and timdly_PH16_フタ検知.B) then
				inc(MC16_モータローラstep)
			end if
		end if
	
	case 6
		tim_MC16_モータローラ_val=30
		res(tim_MC16_モータローラ)
		inc(MC16_モータローラstep)
	
	case 7
		if tim_MC16_モータローラ.B then
			inc(MC16_モータローラstep)
		end if

	
	case 8
		mMC16_モータローラ=OFF
		inc(MC16_モータローラstep)
	
	case 9
		tim_MC16_モータローラ_val=0
		res(tim_MC16_モータローラ)
		inc(MC16_モータローラstep)
	
	case 10
		if tim_MC16_モータローラ.B then
			inc(MC16_モータローラstep)
		end if
	
	case 11
		MC16_モータローラstep=0
		搬送コンベアB排出要求=ON
	end select
		

	'===================================================================================================================
	'【 リフタータスク 】
	'
		
		if not(搬送コンベアBAutoMode and 自動搬送AutoMode ) then
			搬送コンベアBAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアBstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアBAutoRun then
				inc(搬送コンベアBstep)
			else 
				搬送コンベアBstep=0 '終了待機
			end if
		
		case 2
			if PH15_釜検知 or PH16_フタ検知 then
				搬送コンベアB動作中=OFF
				搬送コンベアB排出要求=ON
				搬送コンベアBstep=1
			else
				inc(搬送コンベアBstep)
			end if

		case 3  '原点検出
			if 搬送コンベアBOrg or 1 then
				errpassコンベア一時停止=OFF
				inc(搬送コンベアBstep)
			else
				搬送コンベアBOrgErr=ON
			end if
				
		case 4
			if 残米処理中一時停止 then
				搬送コンベアBstep=1
			else
				inc(搬送コンベアBstep)			
			end if
		
		case 5
		' [ 次の搬送コンベア停止確認 ]
			if 搬送コンベアB排出要求=OFF and  搬送コンベアC動作中=OFF and (PH13_釜検知 or PH14_フタ検知) then
				搬送コンベアB動作中=ON
				搬送コンベアBstep=100
			else if 搬送コンベアA排出要求 then
				搬送コンベアB動作中=ON
				搬送コンベアBstep=200
			else
				搬送コンベアBstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if 搬送コンベアBOrg or 1 then
				inc(搬送コンベアBstep)
			else
				搬送コンベアBstep=1
			end if

		case 101
			'搬送コンベアAリフト
			PH5_釜起動検知=OFF
			PH6_フタ起動検知=OFF
			'待機1
			PH11_釜起動検知=OFF
			PH12_フタ起動検知=OFF
			'待機2
			PH13_釜起動検知=OFF
			PH14_フタ起動検知=OFF
		
			tim_procstep_val=15
			res(tim_procstep)
			inc(搬送コンベアBstep)

		case 102	
			'搬送コンベアAリフト
			PH5_釜起動検知=PH5_釜起動検知 or timdly_PH5_釜起動検知
			PH6_フタ起動検知=PH6_フタ起動検知 or timdly_PH6_フタ起動検知
			'待機1
			PH11_釜起動検知=PH11_釜起動検知 or PH11_釜検知
			PH12_フタ起動検知=PH12_フタ起動検知 or PH12_フタ検知
			'待機2
			PH13_釜起動検知=PH13_釜起動検知 or PH13_釜検知
			PH14_フタ起動検知=PH14_フタ起動検知 or PH14_フタ検知
			
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if		
		
		case 103
			mSV65_ストッパ=ON '上昇
			mSV33_リフト=ON '上昇
			inc(搬送コンベアBstep)

		case 104
			if mSV65_ストッパ and mSV33_リフト then
				if ((XSW75_ストッパ上昇端 and not(pnlPBXSW75_ストッパ上昇端)) or passXSW75_ストッパ上昇端)  and ((XSW38_リフト上昇端 and not(pnlPBXSW38_リフト上昇端)) or passXSW38_リフト上昇端) then
					inc(搬送コンベアBstep)
				end if
			else
				inc(搬送コンベアBstep)
			end if			
		

		case 105
			SV21_ストッパstep=1
			SV22_ストッパstep=1
			MC16_モータローラstep=1
			inc(搬送コンベアBstep)

		case 106
			tim_procstep_val=5
			res(tim_procstep)
			inc(搬送コンベアBstep)
		
		case 107
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if
			
		case 108
			MC13_搬送モータstep=1
			inc(搬送コンベアBstep)

		case 109
			tim_procstep_val=10 '<- ストッパーのアッパー状態の調整あり
			res(tim_procstep)
			inc(搬送コンベアBstep)
		
		case 110
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if

		case 111
			MC12_搬送モータstep=1
			inc(搬送コンベアBstep)

		case 112
			tim_procstep_val=15
			res(tim_procstep)
			inc(搬送コンベアBstep)
		
		case 113
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if
		
		case 114
			MC9_モータローラstep=1
			inc(搬送コンベアBstep)

		case 115
			if SV21_ストッパstep=0 and SV22_ストッパstep=0 and MC9_モータローラstep=0 and MC16_モータローラstep=0 then
				if MC12_搬送モータstep=0 and MC13_搬送モータstep=0 then
					inc(搬送コンベアBstep)
				end if
			end if
 
			
		case 116
			inc(搬送コンベアBstep)			
			
		case 117
			if PH13_釜起動検知 or PH14_フタ起動検知 then
				if PH15_釜検知 or PH16_フタ検知 then
					StageDevice7=StageDevice6
				end if
			else
				StageDevice7=0
			end if
			if PH11_釜起動検知 or PH12_フタ起動検知 then
				if PH13_釜検知 or PH14_フタ検知 then
					StageDevice6=StageDevice5
				end if
			else
			 	StageDevice6=0
			end if
			if PH5_釜起動検知 or PH6_フタ起動検知 then
				if PH11_釜検知 or PH12_フタ検知 then
					StageDevice5=StageDevice4
				end if
			else
				StageDevice5=0
			end if
		
			搬送コンベアB動作中=OFF
			搬送コンベアA排出要求=OFF
			搬送コンベアB排出要求=ON
			搬送コンベアBstep=1

		'--------------------------------------------------------------------------------------------------------------
		
		case 200
			'搬送コンベアAリフト
			PH5_釜起動検知=OFF
			PH6_フタ起動検知=OFF
			'待機1
			PH11_釜起動検知=OFF
			PH12_フタ起動検知=OFF
			'待機2
			PH13_釜起動検知=OFF
			PH14_フタ起動検知=OFF
			
			tim_procstep_val=10
			res(tim_procstep)
			inc(搬送コンベアBstep)

		case 201
			'搬送コンベアAリフト
			PH5_釜起動検知=PH5_釜起動検知 or timdly_PH5_釜起動検知
			PH6_フタ起動検知=PH6_フタ起動検知 or timdly_PH6_フタ起動検知
			'待機1
			PH11_釜起動検知=PH11_釜起動検知 or PH11_釜検知
			PH12_フタ起動検知=PH12_フタ起動検知 or PH12_フタ検知
			'待機2
			PH13_釜起動検知=PH13_釜起動検知 or PH13_釜検知
			PH14_フタ起動検知=PH14_フタ起動検知 or PH14_フタ検知
			
			if tim_procstep.B then		
				inc(搬送コンベアBstep)
			end if
			
		case 202
			'待機1空き.待機2空き
			'待機1・2空きの場合、待機位置2に移動
		
			if (not(PH11_釜起動検知) and not(PH12_フタ起動検知)) and (not(PH13_釜起動検知) and not(PH14_フタ起動検知)) then
				搬送コンベアBstep=230
			'待機1空き
			'待機1空きの場合、待機位置1に移動
			else if (not(PH11_釜起動検知) and not(PH12_フタ起動検知)) and (PH13_釜起動検知 or PH14_フタ起動検知) then
				搬送コンベアBstep=250
			'待機2空き
			'待機2空きの場合、待機位置1から待機位置2に移動
			else if (PH11_釜起動検知 or PH12_フタ起動検知) and (not(PH13_釜起動検知) and not(PH14_フタ起動検知)) then
				搬送コンベアBstep=280
			'待機空きなし 排出待ち
			else if (PH11_釜起動検知 or PH12_フタ起動検知) and (PH13_釜起動検知 or PH14_フタ起動検知) then
				搬送コンベアB動作中=OFF
				搬送コンベアBstep=1
			end if
		
		
		'----------------------
		'待機2に移動
		'----------------------
		case 230
			mSV16_リフト=ON
			mSV21_ストッパ=OFF
			mSV22_ストッパ=ON

			MC9_モータローラstep=1

			mMC12_搬送モータ=ON
			mMC13_搬送モータ=ON
			errpassコンベア一時停止=OFF
			inc(搬送コンベアBstep)
			
		case 231
			if errpassコンベア一時停止 then
				inc(搬送コンベアBstep)			

			else if ((XSW16_リフト上昇端 and not(pnlPBXSW16_リフト上昇端)) or passXSW16_リフト上昇端) and (((XSW19_ストッパ下降端 and not(pnlPBXSW19_ストッパ下降端)) or passXSW19_ストッパ下降端)) and ((XSW22_ストッパ上昇端 and not(pnlPBXSW22_ストッパ上昇端)) or passXSW22_ストッパ上昇端) then
				inc(搬送コンベアBstep)
			end if
			
		case 232
				inc(搬送コンベアBstep)
			
		case 233
			if errpassコンベア一時停止 then
				inc(搬送コンベアBstep)			

			else if not(PH5_釜検知) and not(PH6_フタ検知) then
				inc(搬送コンベアBstep)
			end if

		case 234
			if errpassコンベア一時停止 then
				inc(搬送コンベアBstep)			

			else if (PH13_釜検知 and timdly_PH13_釜検知) or (PH14_フタ検知 and timdly_PH14_フタ検知) then
				inc(搬送コンベアBstep)
			end if
			
		case 235
			tim_procstep_val=20
			res(tim_procstep)
			inc(搬送コンベアBstep)
			
		case 236
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if
			
		case 237
			mMC12_搬送モータ=OFF
			mMC13_搬送モータ=OFF
			mSV21_ストッパ=ON
			inc(搬送コンベアBstep)
			
		case 238
			if MC9_モータローラstep=0 then
				inc(搬送コンベアBstep)
			end if
			
		case 239
			mSV16_リフト=OFF
			mSV21_ストッパ=ON
			mSV22_ストッパ=ON
			if (XSW20_ストッパ上昇端 and not(pnlPBXSW20_ストッパ上昇端)) or passXSW20_ストッパ上昇端 then
				inc(搬送コンベアBstep)
			end if
		case 240

			StageDevice6=StageDevice4

			搬送コンベアA排出要求=OFF
			搬送コンベアB動作中=OFF
			搬送コンベアBstep=1
			
			
		'----------------------
		'待機1に移動
		'----------------------
		case 250
			mSV16_リフト=ON
			mSV21_ストッパ=ON
			mSV22_ストッパ=ON
			
			MC9_モータローラstep=1
			mMC12_搬送モータ=ON
			errpassコンベア一時停止=OFF
			
			inc(搬送コンベアBstep)
			
		case 251
			if ((XSW16_リフト上昇端 and not(pnlPBXSW16_リフト上昇端)) or passXSW16_リフト上昇端) and ((XSW20_ストッパ上昇端 and not(pnlPBXSW20_ストッパ上昇端)) or passXSW20_ストッパ上昇端) and ((XSW22_ストッパ上昇端 and not(pnlPBXSW22_ストッパ上昇端)) or passXSW22_ストッパ上昇端) then
				inc(搬送コンベアBStep)
			end if
			
		case 252
			inc(搬送コンベアBStep)
			
		case 253
			if errpassコンベア一時停止 then
				inc(搬送コンベアBStep)

			else if not(PH5_釜検知) and not(PH6_フタ検知) then
				inc(搬送コンベアBstep)
			end if
			
		case 254
			if errpassコンベア一時停止 then
				inc(搬送コンベアBStep)

			else if (PH11_釜検知 and timdly_PH11_釜検知) or (PH12_フタ検知 and timdly_PH12_フタ検知) then
				inc(搬送コンベアBstep)
			end if
			
		case 255
			tim_procstep_val=5
			res(tim_procstep)
			inc(搬送コンベアBstep)
			
		case 256
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if
			
		case 257
			mMC12_搬送モータ=OFF
			inc(搬送コンベアBstep)
			
		case 258
			if MC9_モータローラstep=0 then
				inc(搬送コンベアBstep)
			end if
			
		case 259
			mSV16_リフト=OFF
			mSV21_ストッパ=ON
			mSV22_ストッパ=ON

			if (XSW20_ストッパ上昇端 and not(pnlPBXSW20_ストッパ上昇端)) or passXSW20_ストッパ上昇端 then
				inc(搬送コンベアBstep)
			end if
		case 260
			StageDevice5=StageDevice4
		
			搬送コンベアB動作中=OFF
			搬送コンベアA排出要求=OFF
			搬送コンベアBstep = 1
		
		
		'----------------------
		'待機2に移動 PH5,PH6 (Stagedevice4)-> PH12,PH14(StageDevice6)
		'----------------------
		
		case 280
			mSV22_ストッパ = ON
			mMC13_搬送モータ = ON
			errpassコンベア一時停止=OFF
			inc(搬送コンベアBstep)
			
		case 281
			if (XSW22_ストッパ上昇端 and not(pnlPBXSW22_ストッパ上昇端)) or passXSW22_ストッパ上昇端 then
				inc(搬送コンベアBstep)
			end if
			
		case 282
			SV21_ストッパstep = 1
			inc(搬送コンベアBstep)
			
		case 283
			tim_procstep_val=10 '<- ストッパーのアッパー状態の調整あり			
			res(tim_procstep)
			inc(搬送コンベアBstep)
			
		case 284
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if
			
		case 285
			MC12_搬送モータstep = 1
			inc(搬送コンベアBstep)

		case 286
			tim_procstep_val=15 '<- ストッパーのアッパー状態の調整あり			
			res(tim_procstep)
			inc(搬送コンベアBstep)
			
		case 287
			if tim_procstep.B then
				inc(搬送コンベアBstep)
			end if

		case 288
			MC9_モータローラstep = 1
			inc(搬送コンベアBstep)

		
		case 289
			if (MC9_モータローラstep=0) and (SV21_ストッパstep=0) and (MC12_搬送モータstep = 0) then
				inc(搬送コンベアBstep)
			end if

		case 290
			mSV16_リフト=OFF
			mSV21_ストッパ=ON
			mSV22_ストッパ=ON
			mMC13_搬送モータ = OFF
			inc(搬送コンベアBstep)

		case 291
			StageDevice6=StageDevice5
			StageDevice5=StageDevice4		
			搬送コンベアB動作中=OFF
			搬送コンベアA排出要求=OFF
			搬送コンベアBstep = 1
					
		end select



	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ManualInite=0 then
			mSV21_ストッパ=OFF
			mSV22_ストッパ=OFF
			mSV16_リフト=OFF
			ManualInite=1
		end if
	
		搬送コンベアBAutoRun=OFF
		
		搬送コンベアBstep=0 '終了


		res(timerr_MC9_モータローラ)
		res(timerr_MC12_搬送モータ)
		res(timerr_MC13_搬送モータ)
		res(timerr_MC16_モータローラ)

		
		if ldp(pnlPBMC9_モータローラ) then
			if mMC9_モータローラ then
				mMC9_モータローラ=OFF
			else 'if XSW16_リフト上昇端 then 'インターロック
					mMC9_モータローラ=ON
			end if
		end if
		
		if ldp(pnlPBMC12_搬送モータ) then
			if mMC12_搬送モータ then
				mMC12_搬送モータ=OFF
			else
				mMC12_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC13_搬送モータ) then
			if mMC13_搬送モータ then
				mMC13_搬送モータ=OFF
			else
				mMC13_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC16_モータローラ) then
			if mMC16_モータローラ then
				mMC16_モータローラ=OFF
			else 'if XSW38_リフト上昇端 then 'インターロック
				mMC16_モータローラ=ON
			end if
		end if
		
		if ldp(pnlPBSV21_ストッパ) then
			if mSV21_ストッパ then
				mSV21_ストッパ=OFF
			else
				mSV21_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV22_ストッパ) then
			if mSV22_ストッパ then
				mSV22_ストッパ=OFF
			else
				mSV22_ストッパ=ON
			end if
		end if

		if ldp(pnlPBSV16_リフト) then
			if mSV16_リフト then
				mSV16_リフト=OFF
			else
				mSV16_リフト=ON
			end if
		end if
			
	end if '搬送コンベアBAutoMode and not(搬送コンベアBOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアBOrgErr処理 】
	else

		if ResetFlg then
			搬送コンベアBOrgErr=OFF
		end if
	
	end if
	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else

		res(timerr_MC12_搬送モータ)
		res(timerr_MC13_搬送モータ)
		res(timerr_MC9_モータローラ )
		res(timerr_MC16_モータローラ)

		コンベア一時停止中=ON
		alm渋滞警報=ON			

	
		if ResetFlg then
			almMC9_モータローラ=OFF
			almMC12_搬送モータ=OFF
			almMC13_搬送モータ=OFF	
			almMC16_モータローラ=OFF
			
			コンベア一時停止=OFF
			コンベア一時停止中=OFF
			alm渋滞警報=OFF			
	
			errpassコンベア一時停止=ON
			
		end if

	end if
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアBErr=ON

		pauseMC9_モータローラ=ON
		pauseMC12_搬送モータ=ON
		pauseMC13_搬送モータ=ON
		pauseMC16_モータローラ=ON

		select case 搬送コンベアBErrStep
		case 0
		case 1
			alm渋滞警報=ON
			
			if ResetFlg then
				almMC9_モータローラ=OFF
				almMC12_搬送モータ=OFF
				almMC13_搬送モータ=OFF
				almMC16_モータローラ=OFF

				almXSW20_ストッパ上昇端=OFF
				almXSW19_ストッパ下降端=OFF
				almXSW22_ストッパ上昇端=OFF
				almXSW21_ストッパ下降端=OFF
				almXSW75_ストッパ上昇端=OFF
				almXSW74_ストッパ下降端=OFF
				almXSW38_リフト上昇端=OFF
				almXSW37_リフト下降端=OFF
				almXSW15_リフト下降端=OFF
				almXSW16_リフト上昇端=OFF

				alm渋滞警報=OFF

				inc(搬送コンベアBErrStep)
			end if
		case 2
			搬送コンベアBErr=OFF
			
			
			res(tim_XSW15_リフト下降端)
			res(tim_XSW16_リフト上昇端)			
			res(tim_XSW20_ストッパ上昇端)
			res(tim_XSW19_ストッパ下降端)
			res(tim_XSW22_ストッパ上昇端)
			res(tim_XSW21_ストッパ下降端)
			res(tim_XSW75_ストッパ上昇端)
			res(tim_XSW74_ストッパ下降端)
			res(tim_XSW38_リフト上昇端)
			res(tim_XSW37_リフト下降端)

			res(tim_notXSW15_リフト下降端)
			res(tim_notXSW16_リフト上昇端)			
			res(tim_notXSW20_ストッパ上昇端)
			res(tim_notXSW19_ストッパ下降端)
			res(tim_notXSW22_ストッパ上昇端)
			res(tim_notXSW21_ストッパ下降端)
			res(tim_notXSW75_ストッパ上昇端)
			res(tim_notXSW74_ストッパ下降端)
			res(tim_notXSW38_リフト上昇端)
			res(tim_notXSW37_リフト下降端)

			pauseMC9_モータローラ=OFF
			pauseMC12_搬送モータ=OFF
			pauseMC13_搬送モータ=OFF
			pauseMC16_モータローラ=OFF
			
			pauseSV21_ストッパ=OFF
			pauseSV22_ストッパ=OFF
			pauseSV65_ストッパ=OFF
			pauseSV33_リフト=OFF
			pauseSV16_リフト=OFF




			搬送コンベアBErrStep=0
		end select

	end if 'if 搬送コンベアBErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	

	select case 搬送コンベアBEmgStep
	case 0
		
	case 1
		搬送コンベアBAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		
		'自動実行条件
		if (搬送コンベアBAutoMode and 自動搬送AutoMode ) or 搬送コンベアBstep<>0 then

			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------			
			
			'自動実行で駆動しているモータ MC を停止
			EmgMC9_モータローラ=ON
			EmgMC12_搬送モータ=ON
			EmgMC13_搬送モータ=ON
			EmgMC16_モータローラ=ON

			if timstack=OFF then
			
				'現在値をスタックに記憶
				timdly_PH5_釜起動検知_stack.U=timdly_PH5_釜起動検知.U
				timdly_PH6_フタ起動検知_stack.U=timdly_PH6_フタ起動検知.U
				timdly_PH11_釜検知_stack.U=timdly_PH11_釜検知.U
				timdly_PH12_フタ検知_stack.U=timdly_PH12_フタ検知.U
				timdly_PH13_釜検知_stack.U=timdly_PH13_釜検知.U
				timdly_PH14_フタ検知_stack.U=timdly_PH14_フタ検知.U
				timdly_PH15_釜検知_stack.U=timdly_PH15_釜検知.U
				timdly_PH16_フタ検知_stack.U=timdly_PH16_フタ検知.U
				tim_SV21_ストッパ_stack.U=tim_SV21_ストッパ.U
				tim_SV22_ストッパ_stack.U=tim_SV22_ストッパ.U
				tim_MC9_モータローラ_stack.U=tim_MC9_モータローラ.U
				tim_MC12_搬送モータ_stack.U=tim_MC12_搬送モータ.U
				tim_MC13_搬送モータ_stack.U=tim_MC13_搬送モータ.U
				tim_MC16_モータローラ_stack.U=tim_MC16_モータローラ.U
				tim_procstep_stack.U=tim_procstep.U

				
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			
			'手動でON/OFFしているデバイスをすべてOFFにする
			mMC9_モータローラ=OFF
			mMC12_搬送モータ=OFF
			mMC13_搬送モータ=OFF
			mMC16_モータローラ=OFF

			mSV21_ストッパ=OFF
			mSV22_ストッパ=OFF
			mSV16_リフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアBEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアBEmgStep)
		end if
	case 3
		
		'自動実行条件

		if (搬送コンベアBAutoMode and 自動搬送AutoMode ) or 搬送コンベアBstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------

				'自動実行で駆動しているモータ MC をリリース
				EmgMC9_モータローラ=OFF
				EmgMC12_搬送モータ=OFF
				EmgMC13_搬送モータ=OFF
				EmgMC16_モータローラ=OFF

				'スタックの値をタイマー現在値にリストア
				tim_SV21_ストッパ.U=tim_SV21_ストッパ_stack.U
				tim_SV22_ストッパ.U=tim_SV22_ストッパ_stack.U
				tim_MC9_モータローラ.U=tim_MC9_モータローラ_stack.U
				tim_MC12_搬送モータ.U=tim_MC12_搬送モータ_stack.U
				tim_MC13_搬送モータ.U=tim_MC13_搬送モータ_stack.U
				tim_MC16_モータローラ.U=tim_MC16_モータローラ_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				'検出タイマーのリセット
				res(timdly_PH5_釜起動検知)
				res(timdly_PH6_フタ起動検知)
				res(timdly_PH11_釜検知)
				res(timdly_PH12_フタ検知)
				res(timdly_PH13_釜検知)
				res(timdly_PH14_フタ検知)
				res(timdly_PH15_釜検知)
				res(timdly_PH16_フタ検知)
				
				
				'---------------------------------
				inc(搬送コンベアBEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアBEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアBEmgStep=0
		搬送コンベアBEmg=OFF
	end select
		
end if 'if 搬送コンベアBEmgStep=0 then
