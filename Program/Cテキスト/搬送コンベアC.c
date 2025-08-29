	'搬送コンベアC
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアC
'
'  	移動速度  161.667mm/1sec
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

    搬送コンベアCAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアCAutoRun=OFF
    搬送コンベアC許可=ON
    搬送コンベアCOrgErr=OFF
    搬送コンベアCErr=OFF
    搬送コンベアCEmg=OFF
    搬送コンベアCstep=0
    搬送コンベアCErrStep=0
    搬送コンベアCOrgErrStep=0
    搬送コンベアCEmgStep=0

	SV29_ストッパstep=0
	SV30_ストッパstep=0
	MC14_搬送モータstep=0
	MC15_搬送モータstep=0
	MC43_乗移コンベアstep=0

	ManualInite=1
	
end if
'===================================================================================================================
'【 原点 】
搬送コンベアCOrg= ((XSW29_ストッパ下降端 and not(pnlPBXSW29_ストッパ下降端)) or passXSW29_ストッパ下降端) or ((XSW30_ストッパ上昇端 and not(pnlPBXSW30_ストッパ上昇端)) or passXSW30_ストッパ上昇端)
搬送コンベアCOrg= 搬送コンベアCOrg and (((XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端) or ((XSW32_ストッパ上昇端 and not(pnlPBXSW32_ストッパ上昇端)) or passXSW32_ストッパ上昇端))
搬送コンベアCOrg= 搬送コンベアCOrg and (((XSW33_クランプ下降端 and not(pnlPBXSW33_クランプ下降端)) or passXSW33_クランプ下降端) or ((XSW34_クランプ上昇端 and not(pnlPBXSW34_クランプ上昇端)) or passXSW34_クランプ上昇端))
搬送コンベアCOrg= 搬送コンベアCOrg and (((XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端) or ((XSW36_クランプ上昇端 and not(pnlPBXSW36_クランプ上昇端)) or passXSW36_クランプ上昇端))


'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアCEmg=ON
	搬送コンベアCEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(not(SV65_ストッパ) and not(XSW74_ストッパ下降端) and not(pnlPBXSW74_ストッパ下降端),tim_notXSW74_ストッパ下降端,#20) '626.94ms
tmr(SV65_ストッパ and not(XSW75_ストッパ上昇端) and not(pnlPBXSW75_ストッパ上昇端),tim_notXSW75_ストッパ上昇端,#20) '768.11ms
tmr(not(SV31_クランプ) and not(XSW33_クランプ下降端) and not(pnlPBXSW33_クランプ下降端),tim_notXSW33_クランプ下降端,#20) '484.28ms
tmr(SV31_クランプ and not(XSW34_クランプ上昇端) and not(pnlPBXSW34_クランプ上昇端),tim_notXSW34_クランプ上昇端,#20) '363.10ms
tmr(not(SV29_ストッパ) and not(XSW29_ストッパ下降端) and not(pnlPBXSW29_ストッパ下降端), tim_notXSW29_ストッパ下降端,#20) '1230.35ms
tmr(SV29_ストッパ and not(XSW30_ストッパ上昇端) and not(pnlPBXSW30_ストッパ上昇端), tim_notXSW30_ストッパ上昇端,#20) '396.88ms
tmr(not(SV32_クランプ) and not(XSW35_クランプ下降端) and not(pnlPBXSW35_クランプ下降端), tim_notXSW35_クランプ下降端,#20) '493.49ms
tmr(SV32_クランプ and not(XSW36_クランプ上昇端) and not(pnlPBXSW36_クランプ上昇端), tim_notXSW36_クランプ上昇端,#20) '724.98ms
tmr(not(SV30_ストッパ) and not(XSW31_ストッパ下降端) and not(pnlPBXSW31_ストッパ下降端),tim_notXSW31_ストッパ下降端,#20) '980.32ms
tmr(SV30_ストッパ and not(XSW32_ストッパ上昇端) and not(pnlPBXSW32_ストッパ上昇端),tim_notXSW32_ストッパ上昇端,#20) '819.96ms
tmr(not(SV33_リフト) and not(XSW37_リフト下降端) and not(pnlPBXSW37_リフト下降端),tim_notXSW37_リフト下降端,#30) '932.62ms
tmr(SV33_リフト and not(XSW38_リフト上昇端) and not(pnlPBXSW38_リフト上昇端),tim_notXSW38_リフト上昇端,#30) '654.33ms

'tmr(SV65_ストッパ and XSW74_ストッパ下降端,tim_XSW74_ストッパ下降端,#10)
if LDF(SV65_ストッパ) and XSW74_ストッパ下降端 and not(pnlPBXSW74_ストッパ下降端) then
	SET(tim_XSW74_ストッパ下降端)
end if
'tmr(not(SV65_ストッパ) and XSW75_ストッパ上昇端,tim_XSW75_ストッパ上昇端,#10)
if LDP(SV65_ストッパ) and  XSW75_ストッパ上昇端 and not(pnlPBXSW75_ストッパ上昇端) then
	SET(tim_XSW75_ストッパ上昇端)
end if
'tmr(SV31_クランプ and XSW33_クランプ下降端,tim_XSW33_クランプ下降端,#10)
if LDF(SV31_クランプ) and XSW33_クランプ下降端 and not(pnlPBXSW33_クランプ下降端) then
	SET(tim_XSW33_クランプ下降端)
end if
'tmr(not(SV31_クランプ) and XSW34_クランプ上昇端,tim_XSW34_クランプ上昇端,#10)
if LDP(SV31_クランプ) and XSW34_クランプ上昇端 and not(pnlPBXSW34_クランプ上昇端) then
	SET(tim_XSW34_クランプ上昇端)
end if
'tmr(SV29_ストッパ and XSW29_ストッパ下降端, tim_XSW29_ストッパ下降端,#10)
if LDF(SV29_ストッパ) and XSW29_ストッパ下降端 and not(pnlPBXSW29_ストッパ下降端) then
	SET(tim_XSW29_ストッパ下降端)
end if
'tmr(not(SV29_ストッパ) and XSW30_ストッパ上昇端, tim_XSW30_ストッパ上昇端,#10)
if LDP(SV29_ストッパ) and XSW30_ストッパ上昇端 and not(pnlPBXSW30_ストッパ上昇端) then
	SET(tim_XSW30_ストッパ上昇端)
end if
'tmr(SV32_クランプ and XSW35_クランプ下降端, tim_XSW35_クランプ下降端,#10)
if LDF(SV32_クランプ) and XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端) then
	SET(tim_XSW35_クランプ下降端)
end if
'tmr(not(SV32_クランプ) and XSW36_クランプ上昇端, tim_XSW36_クランプ上昇端,#10)
if LDP(SV32_クランプ) and  XSW36_クランプ上昇端 and not(pnlPBXSW36_クランプ上昇端) then
	SET(tim_XSW36_クランプ上昇端)
end if
'tmr(SV30_ストッパ and XSW31_ストッパ下降端,tim_XSW31_ストッパ下降端,#10)
if LDF(SV30_ストッパ) and  XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端) then
	SET(tim_XSW31_ストッパ下降端)
end if
'tmr(not(SV30_ストッパ) and XSW32_ストッパ上昇端,tim_XSW32_ストッパ上昇端,#10)
if LDP(SV30_ストッパ) and  XSW32_ストッパ上昇端 and not(pnlPBXSW32_ストッパ上昇端) then
	SET(tim_XSW32_ストッパ上昇端)
end if
'tmr(SV33_リフト and XSW37_リフト下降端,tim_XSW37_リフト下降端,#10)
if LDF(SV33_リフト) and XSW37_リフト下降端 and not(pnlPBXSW37_リフト下降端) then
	SET(tim_XSW37_リフト下降端)
end if
'tmr(not(SV33_リフト) and XSW38_リフト上昇端,tim_XSW38_リフト上昇端,#10)
if LDP(SV33_リフト) and XSW38_リフト上昇端 and not(pnlPBXSW38_リフト上昇端) then
	SET(tim_XSW38_リフト上昇端)
end if

'passtimXSW74_ストッパ下降端_val=#626
tms(not(SV65_ストッパ),passtimXSW74_ストッパ下降端,passtimXSW74_ストッパ下降端_val) 

'passtimXSW75_ストッパ上昇端_val=#768
tms(SV65_ストッパ,passtimXSW75_ストッパ上昇端,passtimXSW75_ストッパ上昇端_val) 

'passtimXSW33_クランプ下降端_val=#484
tms(not(SV31_クランプ),passtimXSW33_クランプ下降端,passtimXSW33_クランプ下降端_val) 

'passtimXSW34_クランプ上昇端_val=#363
tms(SV31_クランプ,passtimXSW34_クランプ上昇端,passtimXSW34_クランプ上昇端_val)

'passtimXSW29_ストッパ下降端_val=#1230
tms(not(SV29_ストッパ), passtimXSW29_ストッパ下降端,passtimXSW29_ストッパ下降端_val) 

'passtimXSW30_ストッパ上昇端_val=#396
tms(SV29_ストッパ, passtimXSW30_ストッパ上昇端,passtimXSW30_ストッパ上昇端_val) 

'passtimXSW35_クランプ下降端_val=#493
tms(not(SV32_クランプ), passtimXSW35_クランプ下降端,passtimXSW35_クランプ下降端_val) 

'passtimXSW36_クランプ上昇端_val=#724
tms(SV32_クランプ, passtimXSW36_クランプ上昇端,passtimXSW36_クランプ上昇端_val) 

'passtimXSW31_ストッパ下降端_val=#980
tms(not(SV30_ストッパ),passtimXSW31_ストッパ下降端,passtimXSW31_ストッパ下降端_val) 

'passtimXSW32_ストッパ上昇端_val=#819
tms(SV30_ストッパ,passtimXSW32_ストッパ上昇端,passtimXSW32_ストッパ上昇端_val) 

'passtimXSW37_リフト下降端_val=#932
tms(not(SV33_リフト),passtimXSW37_リフト下降端,passtimXSW37_リフト下降端_val) 

'passtimXSW38_リフト上昇端_val=#654
tms(SV33_リフト,passtimXSW38_リフト上昇端,passtimXSW38_リフト上昇端_val) 

tmr(mMC14_搬送モータ and not(pauseMC14_搬送モータ) and not(EmgMC14_搬送モータ),timerr_MC14_搬送モータ,#150)
tmr(mMC15_搬送モータ and not(pauseMC15_搬送モータ) and not(EmgMC15_搬送モータ),timerr_MC15_搬送モータ,#150)
tmr(mMC43_乗移コンベア and not(pauseMC43_乗移コンベア) and not(EmgMC43_乗移コンベア),timerr_MC43_乗移コンベア,#150)

if ldp(timerr_MC14_搬送モータ.B) then
	almMC14_搬送モータ=ON

	mMC14_搬送モータ=OFF
	mMC15_搬送モータ=OFF
	mMC43_乗移コンベア=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC15_搬送モータ.B) then
	almMC15_搬送モータ=ON

	mMC14_搬送モータ=OFF
	mMC15_搬送モータ=OFF
	mMC43_乗移コンベア=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC43_乗移コンベア.B) then
	almMC43_乗移コンベア=ON

	mMC14_搬送モータ=OFF
	mMC15_搬送モータ=OFF
	mMC43_乗移コンベア=OFF
	
	コンベア一時停止=ON

end if

if (ldp(tim_XSW74_ストッパ下降端) or ldp(tim_notXSW74_ストッパ下降端)) and not(pnlPBXSW74_ストッパ下降端) then
	almXSW74_ストッパ下降端=ON
	pnlPBXSW74_ストッパ下降端=ON
	if tim_XSW74_ストッパ下降端 then
		res(tim_XSW74_ストッパ下降端)
	end if
	搬送コンベアCErrStep=1
	
else if	(ldp(tim_XSW75_ストッパ上昇端) or ldp(tim_notXSW75_ストッパ上昇端)) and not(pnlPBXSW75_ストッパ上昇端) then
	pauseSV65_ストッパ=ON
	almXSW75_ストッパ上昇端=ON
	pnlPBXSW75_ストッパ上昇端=ON
	if tim_XSW75_ストッパ上昇端 then
		res(tim_XSW75_ストッパ上昇端)
	end if
	搬送コンベアCErrStep=1	

else if (ldp(tim_XSW33_クランプ下降端.B) or ldp(tim_notXSW33_クランプ下降端.B)) and not(pnlPBXSW33_クランプ下降端) then
	almXSW33_クランプ下降端=ON
	pnlPBXSW33_クランプ下降端=ON
	if tim_XSW33_クランプ下降端 then
		res(tim_XSW33_クランプ下降端)
	end if
	搬送コンベアCErrStep=1

else if (ldp(tim_XSW34_クランプ上昇端.B) or ldp(tim_notXSW34_クランプ上昇端.B)) and not(pnlPBXSW34_クランプ上昇端) then
	pauseSV31_クランプ=ON
	almXSW34_クランプ上昇端=ON
	pnlPBXSW34_クランプ上昇端=ON
	if tim_XSW34_クランプ上昇端 then
		res(tim_XSW34_クランプ上昇端)
	end if
	搬送コンベアCErrStep=1

else if (ldp(tim_XSW29_ストッパ下降端.B) or ldp(tim_notXSW29_ストッパ下降端.B)) and not(pnlPBXSW29_ストッパ下降端) then
	almXSW29_ストッパ下降端=ON
	pnlPBXSW29_ストッパ下降端=ON
	if tim_XSW29_ストッパ下降端 then
		res(tim_XSW29_ストッパ下降端)
	end if
	搬送コンベアCErrStep=1

else if (ldp(tim_XSW30_ストッパ上昇端.B) or ldp(tim_notXSW30_ストッパ上昇端.B)) and not(pnlPBXSW30_ストッパ上昇端) then
	pauseSV29_ストッパ=ON
	almXSW30_ストッパ上昇端=ON
	pnlPBXSW30_ストッパ上昇端=ON
	if tim_XSW30_ストッパ上昇端 then
		res(tim_XSW30_ストッパ上昇端)
	end if
	搬送コンベアCErrStep=1
	
else if (ldp(tim_XSW35_クランプ下降端.B) or ldp(tim_notXSW35_クランプ下降端.B)) and not(pnlPBXSW35_クランプ下降端) then
	almXSW35_クランプ下降端=ON
	pnlPBXSW35_クランプ下降端=ON
	res(tim_XSW35_クランプ下降端)
	搬送コンベアCErrStep=1

else if (ldp(tim_XSW36_クランプ上昇端.B) or ldp(tim_notXSW36_クランプ上昇端.B)) and not(pnlPBXSW36_クランプ上昇端) then
	pauseSV32_クランプ=ON
	almXSW36_クランプ上昇端=ON
	pnlPBXSW35_クランプ下降端=ON
	if tim_XSW36_クランプ上昇端 then
		res(tim_XSW36_クランプ上昇端)
	end if
	搬送コンベアCErrStep=1	

else if (ldp(tim_XSW31_ストッパ下降端.B) or ldp(tim_notXSW31_ストッパ下降端.B)) and not(pnlPBXSW31_ストッパ下降端) then
	almXSW31_ストッパ下降端=ON
	pnlPBXSW31_ストッパ下降端=ON
	if tim_XSW31_ストッパ下降端 then
		res(tim_XSW31_ストッパ下降端)
	end if
	搬送コンベアCErrStep=1

else if (ldp(tim_XSW32_ストッパ上昇端.B) or ldp(tim_notXSW32_ストッパ上昇端.B)) and not(pnlPBXSW32_ストッパ上昇端) then
	pauseSV30_ストッパ=ON
	almXSW32_ストッパ上昇端=ON
	pnlPBXSW32_ストッパ上昇端=ON
	if tim_XSW32_ストッパ上昇端 then
		res(tim_XSW32_ストッパ上昇端)
	end if
	搬送コンベアCErrStep=1

else if (ldp(tim_XSW37_リフト下降端) or ldp(tim_notXSW37_リフト下降端)) and not(pnlPBXSW37_リフト下降端) then
	almXSW37_リフト下降端=ON
	pnlPBXSW37_リフト下降端=ON
	if tim_XSW37_リフト下降端 then
		res(tim_XSW37_リフト下降端)
	end if
	搬送コンベアCErrStep=1

else if (ldp(tim_XSW38_リフト上昇端) or ldp(tim_notXSW38_リフト上昇端)) and not(pnlPBXSW38_リフト上昇端) then
	pauseSV33_リフト=ON
	almXSW38_リフト上昇端=ON
	pnlPBXSW38_リフト上昇端=ON
	if tim_XSW38_リフト上昇端 then
		res(tim_XSW38_リフト上昇端)
	end if
	搬送コンベアCErrStep=1

end if

	

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアCAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアCAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアCEmg	その場停止


if 搬送コンベアCEmgStep=0 then  
	
	if 搬送コンベアCErrStep=0  then

	if not(コンベア一時停止) then
	
	if not(搬送コンベアCOrgErr) then

	if (搬送コンベアCAutoMode and 自動搬送AutoMode ) or 搬送コンベアCstep<>0 then
	
		if ManualInite=1 then		
			mSV65_ストッパ=ON
			mSV29_ストッパ=ON
			mSV30_ストッパ=ON

			'mSV32_クランプ=ON
			'mSV31_クランプ=ON
			ManualInite=0
		end if
	
		if not(搬送コンベアCAutoMode and 自動搬送AutoMode ) then
			搬送コンベアCAutoRun=OFF
		end if
	
	tmr(PH17_釜検知,timdly_PH17_釜検知,5)
	tmr(PH18_フタ検知,timdly_PH18_フタ検知,5)
	tmr(PH19_釜検知,timdly_PH19_釜検知,5)
	tmr(PH20_フタ検知,timdly_PH20_フタ検知,5)
	tmr(PH54_釜送りトリガ,timdly_PH54_釜送りトリガ,5)
	
	'-----------------------------------------------------------------
	' ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	tmr(tim_SV29_ストッパ,tim_SV29_ストッパ_val) 'ならしストッパ、クランプ
	select case SV29_ストッパstep
	case 0
		
	case 1
		PH15_釜起動検知=LatchPH15_釜検知
		PH16_フタ起動検知=LatchPH16_フタ検知
		PH17_釜起動検知=PH17_釜検知
		PH18_フタ起動検知=PH18_フタ検知
		
		if LatchPH15_釜検知 or LatchPH16_フタ検知 or PH17_釜検知 or PH18_フタ検知 then '前のステージ(搬送コンベアBリフト）
			
			mSV65_ストッパ=OFF 'リフトストッパ解除
			mSV29_ストッパ=OFF 'ストッパ下降
			mSV31_クランプ=OFF 'クランプ下降
			inc(SV29_ストッパstep)
		else
			SV29_ストッパstep=0
		end if
		
	case 2
		if (XSW29_ストッパ下降端 and not(pnlPBXSW29_ストッパ下降端)) or passXSW29_ストッパ下降端 then
			if (XSW33_クランプ下降端 and not(pnlPBXSW33_クランプ下降端)) or passXSW33_クランプ下降端 then
				if (XSW74_ストッパ下降端 and not(pnlPBXSW74_ストッパ下降端)) or passXSW74_ストッパ下降端 then 			
					inc(SV29_ストッパstep)
				end if
			end if
		end if
	
	case 3
		if errpassコンベア一時停止 then
			inc(SV29_ストッパstep)
		
		else if not(PH17_釜検知) and not(PH18_フタ検知) then
			inc(SV29_ストッパstep)
		end if
		
	case 4
		tim_SV29_ストッパ_val=30
		res(tim_SV29_ストッパ)
		inc(SV29_ストッパstep)

	case 5
		if tim_SV29_ストッパ.B then
			inc(SV29_ストッパstep)
		end if
	
	case 6
		mSV29_ストッパ=ON 'ストッパ上昇
		inc(SV29_ストッパstep)

	case 7
		if (XSW30_ストッパ上昇端 and not(pnlPBXSW30_ストッパ上昇端)) or passXSW30_ストッパ上昇端 then
			inc(SV29_ストッパstep)
		end if		
		

	case 8
		if errpassコンベア一時停止 then
				inc(SV29_ストッパstep)
		
		else if PH15_釜起動検知 or PH16_フタ起動検知 then
			if (PH17_釜検知 and timdly_PH17_釜検知.B) or (PH18_フタ検知 and timdly_PH18_フタ検知.B) then
				inc(SV29_ストッパstep)
			end if
		else if PH17_釜起動検知 or PH18_フタ起動検知 then
			if (PH19_釜検知 and timdly_PH19_釜検知.B) or (PH20_フタ検知 and timdly_PH20_フタ検知.B) then
				inc(SV29_ストッパstep)
			end if
		else
			inc(SV29_ストッパstep)
		end if
		
	case 9
		mSV65_ストッパ=ON 'リフトストッパ上昇
		mSV29_ストッパ=ON 'ストッパ上昇
		mSV33_リフト=ON
		inc(SV29_ストッパstep)

	case 10
		if ((XSW30_ストッパ上昇端 and not(pnlPBXSW30_ストッパ上昇端)) or passXSW30_ストッパ上昇端) and ((XSW75_ストッパ上昇端 and not(pnlPBXSW75_ストッパ上昇端)) or passXSW75_ストッパ上昇端) then		
			inc(SV29_ストッパstep)
		end if
		
	case 11
		tim_SV29_ストッパ_val=10 
		res(tim_SV29_ストッパ)
		inc(SV29_ストッパstep)
	
	case 12
		if tim_SV29_ストッパ.B then
			inc(SV29_ストッパstep)
		end if

	case 13
		if PH17_釜検知 or PH18_フタ検知 then
			mSV31_クランプ=ON 'クランプ上昇			
			inc(SV29_ストッパstep)
		else
			inc(SV29_ストッパstep)
		end if
		
	case 14
		if mSV31_クランプ then
			if (XSW34_クランプ上昇端 and not(pnlPBXSW34_クランプ上昇端)) or passXSW34_クランプ上昇端 then
				inc(SV29_ストッパstep)
			end if
		else
			inc(SV29_ストッパstep)
		end if

	case 15
		SV29_ストッパstep=0

	end select	
	'--------------------------------------------
	tmr(tim_SV30_ストッパ, tim_SV30_ストッパ_val) 'フタ被せストッパー、クランプ
	select case SV30_ストッパstep
	case 0

	case 1
		PH17_釜起動検知=PH17_釜検知
		PH18_フタ起動検知=PH18_フタ検知
		PH19_釜起動検知=PH19_釜検知
		PH20_フタ起動検知=PH20_フタ検知
		
		if PH17_釜検知 or PH18_フタ検知 or PH19_釜検知 or PH20_フタ検知 then 
			mSV32_クランプ=OFF '下降
			mSV30_ストッパ=OFF '下降	
			inc(SV30_ストッパstep)
		else
			SV30_ストッパstep=0
		end if
		
	case 2
		if (XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端 then
			if (XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端 then 
				inc(SV30_ストッパstep)
			end if
		end if
	
	case 3
		if errpassコンベア一時停止 then
			inc(SV30_ストッパstep)
		
		else if not(PH19_釜検知) and not(PH20_フタ検知) then		
			inc(SV30_ストッパstep)
		end if
	
	case 4
		tim_SV30_ストッパ_val=30
		res(tim_SV30_ストッパ)
		inc(SV30_ストッパstep)

	case 5
		if tim_SV30_ストッパ.B then
			inc(SV30_ストッパstep)
		end if
	
	case 6
		mSV30_ストッパ=ON '上昇	
		inc(SV30_ストッパstep)
	
	case 7
		if (XSW32_ストッパ上昇端 and not(pnlPBXSW32_ストッパ上昇端)) or passXSW32_ストッパ上昇端 then
			inc(SV30_ストッパstep)
		end if

	case 8
		if errpassコンベア一時停止 then
				inc(SV30_ストッパstep)
		
		else if PH17_釜起動検知 or PH18_フタ起動検知 then			
			if (PH19_釜検知 and timdly_PH19_釜検知.B) or (PH20_フタ検知 and timdly_PH20_フタ検知.B) then
				inc(SV30_ストッパstep)
			end if
		else
			inc(SV30_ストッパstep)
		end if
		
	case 9
		if errpassコンベア一時停止 then
				inc(SV30_ストッパstep)
	
		else if PH19_釜起動検知 or PH20_フタ起動検知 then
			if PH54_釜送りトリガ then
				inc(SV30_ストッパstep)
			end if			
		else
			inc(SV30_ストッパstep)
		end if	
		
	case 10
		mSV30_ストッパ=ON '上昇	
		inc(SV30_ストッパstep)
	
	case 11
		if (XSW32_ストッパ上昇端 and not(pnlPBXSW32_ストッパ上昇端)) or passXSW32_ストッパ上昇端 then
			inc(SV30_ストッパstep)
		end if

	case 12
		tim_SV30_ストッパ_val=10 'クランプ上昇タイミング
		res(tim_SV30_ストッパ)
		inc(SV30_ストッパstep)
	
	case 13
		if tim_SV30_ストッパ.B then
			inc(SV30_ストッパstep)
		end if
	
	case 14
		if PH19_釜検知 and  PH20_フタ検知 then
			mSV32_クランプ=ON '上昇
			inc(SV30_ストッパstep)
		else if 蓋被せユニット許可 and (not(PH19_釜検知) and PH20_フタ検知) then 
			mSV32_クランプ=ON '上昇
			inc(SV30_ストッパstep)
		else
			inc(SV30_ストッパstep)
		end if
	
	case 15
		if mSV32_クランプ then
			if (XSW36_クランプ上昇端 and not(pnlPBXSW36_クランプ上昇端)) or passXSW36_クランプ上昇端 then
				inc(SV30_ストッパstep)
			end if
		else
			inc(SV30_ストッパstep)
		end if
		
	case 16
		SV30_ストッパstep=0

	end select
	'--------------------------------------------
	'MC14_搬送モータ
	tmr(tim_MC14_搬送モータ,tim_MC14_搬送モータ_val)
	
	select case MC14_搬送モータstep
	case 0
	
	case 1
		inc(MC14_搬送モータstep)
		
	case 2
		PH15_釜起動検知=LatchPH15_釜検知
		PH16_フタ起動検知=LatchPH16_フタ検知
		PH17_釜起動検知=PH17_釜検知
		PH18_フタ起動検知=PH18_フタ検知
		'PH19_釜検知
		'PH20_フタ検知
		
		if LatchPH15_釜検知 or LatchPH16_フタ検知 or PH17_釜検知 or PH18_フタ検知 then
				if (XSW29_ストッパ下降端 and not(pnlPBXSW29_ストッパ下降端)) or passXSW29_ストッパ下降端 then
					if (XSW33_クランプ下降端 and not(pnlPBXSW33_クランプ下降端)) or passXSW33_クランプ下降端 then
						mMC14_搬送モータ=ON
						errpassコンベア一時停止=OFF
						inc(MC14_搬送モータstep)
					end if
				end if
		else
			MC14_搬送モータstep=0
		end if
		
	case 3
		if errpassコンベア一時停止 then
			inc(MC14_搬送モータstep)
		
		else if not(PH15_釜検知) and not(PH16_フタ検知) and not(PH17_釜検知) and not(PH18_フタ検知) then
			inc(MC14_搬送モータstep)
		end if
	
	case 4
		if errpassコンベア一時停止 then
			inc(MC14_搬送モータstep)
		
		else if PH15_釜起動検知 or PH16_フタ起動検知 then
			if (PH17_釜検知 and timdly_PH17_釜検知.B) or (PH18_フタ検知 and timdly_PH18_フタ検知.B) then
				inc(MC14_搬送モータstep)
			end if
		else if PH17_釜起動検知 or PH18_フタ起動検知 then
			if (PH19_釜検知 and timdly_PH19_釜検知.B) or (PH20_フタ検知 and timdly_PH20_フタ検知.B) then
				inc(MC14_搬送モータstep)
			end if
		end if
	
	case 5
		tim_MC14_搬送モータ_val=10
		res(tim_MC14_搬送モータ)
		inc(MC14_搬送モータstep)
	
	case 6
		if tim_MC14_搬送モータ.B then
			inc(MC14_搬送モータstep)
		end if
	
	case 7
		mMC14_搬送モータ=OFF
		inc(MC14_搬送モータstep)

	case 8
		MC14_搬送モータstep=0
	
	end select
	'--------------------------------------------
	'MC15_搬送モータ
	tmr(tim_MC15_搬送モータ,tim_MC15_搬送モータ_val)
	
	select case MC15_搬送モータstep
	case 0
	case 1
		inc(MC15_搬送モータstep)
	
	case 2
		PH17_釜起動検知=PH17_釜検知
		PH18_フタ起動検知=PH18_フタ検知
		PH19_釜起動検知=PH19_釜検知
		PH20_フタ起動検知=PH20_フタ検知
		'PH54_釜送りトリガ
		
		if PH17_釜検知 or PH18_フタ検知 or PH19_釜検知 or PH20_フタ検知 then
			if (XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端 then
				if (XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端 then
					mMC15_搬送モータ=ON
					errpassコンベア一時停止=OFF
					inc(MC15_搬送モータstep)
				end if
			end if
		else
			MC15_搬送モータstep=0
		end if
		
	case 3
		if errpassコンベア一時停止 then
			inc(MC15_搬送モータstep)	
		
		else if not(PH17_釜検知) and not(PH18_フタ検知) and not(PH19_釜検知) and not(PH20_フタ検知) then
			inc(MC15_搬送モータstep)	
		end if
	
	case 4
		if errpassコンベア一時停止 then
				inc(MC15_搬送モータstep)
		
		else if PH17_釜起動検知 or PH18_フタ起動検知 then
			if (PH19_釜検知 and timdly_PH19_釜検知.B) or (PH20_フタ検知 and timdly_PH20_フタ検知.B) then
				inc(MC15_搬送モータstep)
			end if
		else if PH19_釜起動検知 or PH20_フタ起動検知 then
			if (PH54_釜送りトリガ and timdly_PH54_釜送りトリガ.B) then
				inc(MC15_搬送モータstep)
			end if
		end if
		
	case 5
		tim_MC15_搬送モータ_val=10 'ブレークタイミング
		res(tim_MC15_搬送モータ)
		inc(MC15_搬送モータstep)
	
	case 6
		if tim_MC15_搬送モータ.B then 
			inc(MC15_搬送モータstep)
		end if
	
	case 7
		mMC15_搬送モータ=OFF
		inc(MC15_搬送モータstep)
		
	case 8
		StageDevice9=StageDevice8			
		StageDevice8=StageDevice7tmp
		MC15_搬送モータstep=0
		
	end select
		
	'--------------------------------------------
	' 乗り換えコンベア PH58 PH54+tim
	tmr(tim_MC43_乗移コンベア,tim_MC43_乗移コンベア_val)
	
	select case MC43_乗移コンベアstep
	case 0

	case 1
		if  PH19_釜検知  then
			inc(MC43_乗移コンベアstep)
		else
			MC43_乗移コンベアstep=0
		end if
		
	case 2
		mMC43_乗移コンベア=ON
		errpassコンベア一時停止=OFF
		inc(MC43_乗移コンベアstep)

	case 3
		if errpassコンベア一時停止 then
			inc(MC43_乗移コンベアstep)
		
		else if not(PH19_釜検知) then 
			inc(MC43_乗移コンベアstep)
		end if
	
	case 4
		if errpassコンベア一時停止 then
			inc(MC43_乗移コンベアstep)
		
		else if PH54_釜送りトリガ and timdly_PH54_釜送りトリガ.B then
			inc(MC43_乗移コンベアstep)
		end if			
	
	case 5
		tim_MC43_乗移コンベア_val=5 '停止タイミングタイマー
		res(tim_MC43_乗移コンベア)
		inc(MC43_乗移コンベアstep)
	
	case 6
		if tim_MC43_乗移コンベア.B then
			inc(MC43_乗移コンベアstep)		
		end if
	
	case 7
		mMC43_乗移コンベア=OFF
		inc(MC43_乗移コンベアstep)		
	
	case 8
		MC43_乗移コンベアstep=0
	
	end select

	'===================================================================================================================
	'【 炊飯入口コンベア 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアCstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアCAutoRun then
				inc(搬送コンベアCstep)
			else 
				搬送コンベアCstep=0 '終了待機
			end if

		case 2
		' [ 搬送コンベア停止確認 ]
			if (搬送コンベアC排出要求=OFF or (not(PH19_釜検知) and not(PH20_フタ検知)) ) and  釜送りコンベア動作中=OFF and 搬送コンベアB排出要求  then
				inc(搬送コンベアCstep)
			else
				搬送コンベアCstep=1
			end if

		case 3
			if PH54_釜送りトリガ and (PH19_釜検知 or PH20_フタ検知) then
					搬送コンベアC排出要求=ON
					搬送コンベアC動作中=OFF
					搬送コンベアCstep=1
			else
				inc(搬送コンベアCstep)
			end if					

		case 4
			if 	ならし排出要求  and フタ被せ排出要求 then
				inc(搬送コンベアCstep)
			else
				搬送コンベアCstep=1
			end if
	
		case 5 
		'[ 原点検出 ]
			if 搬送コンベアCOrg and ならし装置Org and 蓋被せユニットOrg then
				errpassコンベア一時停止=OFF
				inc(搬送コンベアCstep)
			else
				搬送コンベアCstep=1
			end if
		
		case 6
			LatchPH15_釜検知=OFF
			LatchPH16_フタ検知=OFF
			
			搬送コンベアC動作中=ON
			搬送コンベアCstep=100
			
		'--------------------------------------------------------------------------------------------------------------
		' 【 プロセス処理 】
		case 100
			LatchPH15_釜検知=PH15_釜検知
			LatchPH16_フタ検知=PH16_フタ検知
			
			if LatchPH15_釜検知 or LatchPH16_フタ検知 then
				mSV33_リフト=OFF 'リフト下降
				inc(搬送コンベアCstep)			
			else
				inc(搬送コンベアCstep)						
			end if
		case 101
			if not(mSV33_リフト) then
				if (XSW37_リフト下降端 and not(pnlPBXSW37_リフト下降端)) or passXSW37_リフト下降端 then
					inc(搬送コンベアCstep)
				end if
			else
				inc(搬送コンベアCstep)
			end if
		case 102
				StageDevice7tmp=StageDevice7
				SV29_ストッパstep=1
				SV30_ストッパstep=1
				MC14_搬送モータstep=1
				MC15_搬送モータstep=1
				MC43_乗移コンベアstep=1
				inc(搬送コンベアCstep)
		
		case 103
			if SV29_ストッパstep=0 and SV30_ストッパstep=0 and MC14_搬送モータstep=0 and MC15_搬送モータstep=0 and MC43_乗移コンベアstep=0 then
				inc(搬送コンベアCstep)
			end if			
		
		case 104

		
			搬送コンベアB排出要求=OFF
			
			
			ならし完了=OFF
			ならし排出要求=OFF
			
			フタ被せ完了=OFF
			フタ被せ排出要求=OFF
			
			搬送コンベアC排出要求=ON
			搬送コンベアC動作中=OFF

			搬送コンベアCstep=1
			
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ManualInite=0 then
			mSV65_ストッパ=OFF
			mSV31_クランプ=OFF
			mSV29_ストッパ=OFF
			mSV32_クランプ=OFF
			mSV30_ストッパ=OFF
		
			ManualInite=1
		end if
	
		搬送コンベアCAutoRun=OFF
		
		搬送コンベアCstep=0 '終了

		res(timerr_MC14_搬送モータ)
		res(timerr_MC15_搬送モータ)
		res(timerr_MC43_乗移コンベア)

		
		if ldp(pnlPBMC14_搬送モータ) then
			if mMC14_搬送モータ then
				mMC14_搬送モータ=OFF
			else if ならし装置Org and 蓋被せユニットOrg then
				mMC14_搬送モータ=ON
			end if
		end if
		

		if ldp(pnlPBMC15_搬送モータ) then
			if mMC15_搬送モータ then
				mMC15_搬送モータ=OFF
			else if ならし装置Org and 蓋被せユニットOrg then
				mMC15_搬送モータ=ON
			end if
		end if

		if ldp(pnlPBMC43_乗移コンベア) then
			if mMC43_乗移コンベア then
				mMC43_乗移コンベア=OFF
			else
				mMC43_乗移コンベア=ON
			end if
		end if


		if ldp(pnlPBSV65_ストッパ) then
			if mSV65_ストッパ then
				mSV65_ストッパ=OFF
			else
				mSV65_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV33_リフト) then
			if mSV33_リフト then
				mSV33_リフト=OFF
			else
				mSV33_リフト=ON
			end if
		end if
		
		if ldp(pnlPBSV31_クランプ) then
			if mSV31_クランプ then
				mSV31_クランプ=OFF
			else
				mSV31_クランプ=ON
			end if
		end if
		
		if ldp(pnlPBSV29_ストッパ) then
			if mSV29_ストッパ then
				mSV29_ストッパ=OFF
			else
				mSV29_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV32_クランプ) then
			if mSV32_クランプ then
				mSV32_クランプ=OFF
			else
				mSV32_クランプ=ON
			end if
		end if
		
		if ldp(pnlPBSV30_ストッパ) then
			if mSV30_ストッパ then
				mSV30_ストッパ=OFF
			else 
				mSV30_ストッパ=ON
			end if
		end if
		

	end if '搬送コンベアCAutoMode and not(搬送コンベアCOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアCOrgErr処理 】
	else
	
		if ResetFlg then
			搬送コンベアCOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
	'tmr(自動搬送AutoMode and MC14_搬送モータ,timerr_MC14_搬送モータ,#150)
	'tmr(自動搬送AutoMode and MC15_搬送モータ,timerr_MC15_搬送モータ,#150)
	'tmr(自動搬送AutoMode and MC43_乗移コンベア ,timerr_MC43_乗移コンベア,#150)
	res(timerr_MC14_搬送モータ)
	res(timerr_MC15_搬送モータ)
	res(timerr_MC43_乗移コンベア)
	
	コンベア一時停止中=ON
	alm渋滞警報=ON			

	
		if ResetFlg then
			almMC14_搬送モータ=OFF
			almMC15_搬送モータ=OFF
			almMC43_乗移コンベア=OFF	
			
			pauseMC43_乗移コンベア=OFF	

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
	
		搬送コンベアCErr=ON

		pauseMC14_搬送モータ=ON
		pauseMC15_搬送モータ=ON
		pauseMC43_乗移コンベア=ON
		

		
		select case 搬送コンベアCErrStep
		case 0
		case 1
			alm渋滞警報=ON			
	
			if ResetFlg then
				almMC14_搬送モータ=OFF
				almMC15_搬送モータ=OFF
				almMC43_乗移コンベア=OFF

				almXSW37_リフト下降端=OFF
				almXSW38_リフト上昇端=OFF
				almXSW74_ストッパ下降端=OFF
				almXSW75_ストッパ上昇端=OFF
				almXSW33_クランプ下降端=OFF
				almXSW34_クランプ上昇端=OFF
				almXSW29_ストッパ下降端=OFF
				almXSW30_ストッパ上昇端=OFF
				almXSW35_クランプ下降端=OFF
				almXSW36_クランプ上昇端=OFF
				almXSW31_ストッパ下降端=OFF
				almXSW32_ストッパ上昇端=OFF
				
				alm渋滞警報=OFF			


				inc(搬送コンベアCErrStep)
			end if
		case 2
			搬送コンベアCErr=OFF

			res(tim_XSW37_リフト下降端)
			res(tim_XSW38_リフト上昇端)
			res(tim_XSW74_ストッパ下降端)
			res(tim_XSW75_ストッパ上昇端)
			res(tim_XSW33_クランプ下降端)
			res(tim_XSW34_クランプ上昇端)
			res(tim_XSW29_ストッパ下降端)
			res(tim_XSW30_ストッパ上昇端)
			res(tim_XSW35_クランプ下降端)
			res(tim_XSW36_クランプ上昇端)
			res(tim_XSW31_ストッパ下降端)
			res(tim_XSW32_ストッパ上昇端)

			res(tim_notXSW37_リフト下降端)
			res(tim_notXSW38_リフト上昇端)
			res(tim_notXSW74_ストッパ下降端)
			res(tim_notXSW75_ストッパ上昇端)
			res(tim_notXSW33_クランプ下降端)
			res(tim_notXSW34_クランプ上昇端)
			res(tim_notXSW29_ストッパ下降端)
			res(tim_notXSW30_ストッパ上昇端)
			res(tim_notXSW35_クランプ下降端)
			res(tim_notXSW36_クランプ上昇端)
			res(tim_notXSW31_ストッパ下降端)
			res(tim_notXSW32_ストッパ上昇端)

			pauseMC14_搬送モータ=OFF
			pauseMC15_搬送モータ=OFF
			pauseMC43_乗移コンベア=OFF
		
			pauseSV65_ストッパ=OFF
			pauseSV31_クランプ=OFF
			pauseSV29_ストッパ=OFF
			pauseSV32_クランプ=OFF
			pauseSV30_ストッパ=OFF
			pauseSV33_リフト=OFF

			搬送コンベアCErrStep=0
		end select

	end if 'if 搬送コンベアCErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 搬送コンベアCEmgStep
	case 0
	
	case 1
		搬送コンベアCAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアCAutoMode and 自動搬送AutoMode ) or 搬送コンベアCstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgMC14_搬送モータ=ON
			EmgMC15_搬送モータ=ON
			EmgMC43_乗移コンベア=ON

			if timstack=OFF then
			
				timdly_PH17_釜検知_stack.U=timdly_PH17_釜検知.U
				timdly_PH18_フタ検知_stack.U=timdly_PH18_フタ検知.U
				timdly_PH19_釜検知_stack.U=timdly_PH19_釜検知.U
				timdly_PH20_フタ検知_stack.U=timdly_PH20_フタ検知.U
				timdly_PH54_釜送りトリガ_stack.U=timdly_PH54_釜送りトリガ.U
				tim_SV29_ストッパ_stack.U=tim_SV29_ストッパ.U
				tim_SV30_ストッパ_stack.U=tim_SV30_ストッパ.U
				tim_MC14_搬送モータ_stack.U=tim_MC14_搬送モータ.U
				tim_MC15_搬送モータ_stack.U=tim_MC15_搬送モータ.U
				tim_MC43_乗移コンベア_stack.U=tim_MC43_乗移コンベア.U
				tim_procstep_stack.U=tim_procstep.U
				
				
				' tmr(PH17_釜検知,timdly_PH17_釜検知,2)
				' tmr(PH18_フタ検知,timdly_PH18_フタ検知,2)
				' tmr(PH19_釜検知,timdly_PH19_釜検知,2)
				' tmr(PH20_フタ検知,timdly_PH20_フタ検知,2)
				' tmr(PH54_釜送りトリガ,timdly_PH54_釜送りトリガ,2)
				' tmr(tim_SV29_ストッパ,tim_SV29_ストッパ_val) 'ならしストッパ、クランプ
				' tmr(tim_SV30_ストッパ, tim_SV30_ストッパ_val) 'フタ被せストッパー、クランプ
				' tmr(tim_MC14_搬送モータ,tim_MC14_搬送モータ_val)
				' tmr(tim_MC15_搬送モータ,tim_MC15_搬送モータ_val)
				' tmr(tim_MC43_乗移コンベア,tim_MC43_乗移コンベア_val)
				' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC14_搬送モータ=OFF
			mMC15_搬送モータ=OFF
			mSV65_ストッパ=OFF
			mSV33_リフト=OFF
			mSV31_クランプ=OFF
			mSV29_ストッパ=OFF
			mSV32_クランプ=OFF
			mSV30_ストッパ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアCEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアCEmgStep)
		end if
	case 3
		if (搬送コンベアCAutoMode and 自動搬送AutoMode ) or 搬送コンベアCstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				EmgMC14_搬送モータ=OFF
				EmgMC15_搬送モータ=OFF
				EmgMC43_乗移コンベア=OFF

				'スタックの値をタイマー現在値にリストア
				tim_SV29_ストッパ.U=tim_SV29_ストッパ_stack.U
				tim_SV30_ストッパ.U=tim_SV30_ストッパ_stack.U
				tim_MC14_搬送モータ.U=tim_MC14_搬送モータ_stack.U
				tim_MC15_搬送モータ.U=tim_MC15_搬送モータ_stack.U
				tim_MC43_乗移コンベア.U=tim_MC43_乗移コンベア_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				' tmr(tim_SV29_ストッパ,tim_SV29_ストッパ_val) 'ならしストッパ、クランプ
				' tmr(tim_SV30_ストッパ, tim_SV30_ストッパ_val) 'フタ被せストッパー、クランプ
				' tmr(tim_MC14_搬送モータ,tim_MC14_搬送モータ_val)
				' tmr(tim_MC15_搬送モータ,tim_MC15_搬送モータ_val)
				' tmr(tim_MC43_乗移コンベア,tim_MC43_乗移コンベア_val)
				' tmr(tim_procstep,tim_procstep_val)
				
				'検出タイマーのリセット
				res(timdly_PH17_釜検知)
				res(timdly_PH18_フタ検知)
				res(timdly_PH19_釜検知)
				res(timdly_PH20_フタ検知)
				res(timdly_PH54_釜送りトリガ)
				
				' tmr(PH17_釜検知,timdly_PH17_釜検知,2)
				' tmr(PH18_フタ検知,timdly_PH18_フタ検知,2)
				' tmr(PH19_釜検知,timdly_PH19_釜検知,2)
				' tmr(PH20_フタ検知,timdly_PH20_フタ検知,2)
				' tmr(PH54_釜送りトリガ,timdly_PH54_釜送りトリガ,2)

				'---------------------------------
				inc(搬送コンベアCEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアCEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアCEmgStep=0
		搬送コンベアCEmg=OFF
	end select
		
end if 'if 搬送コンベアCEmgStep=0 then
