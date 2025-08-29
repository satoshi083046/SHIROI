'搬送コンベアA
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアA
'
'  	移動速度  161.667mm/1sec	
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

    搬送コンベアAAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアAAutoRun=OFF
    搬送コンベアA許可=ON
    搬送コンベアAOrgErr=OFF
    搬送コンベアAErr=OFF
    搬送コンベアAEmg=OFF
    搬送コンベアAstep=0
    搬送コンベアAErrStep=0
    搬送コンベアAOrgErrStep=0
    搬送コンベアAEmgStep=0
	
	SV14_ストッパstep=0
	SV15_ストッパstep=0
	MC6_搬送モータstep=0
	MC7_搬送モータstep=0
	MC8_搬送モータstep=0
		
	ManualInite=1

end if
'===================================================================================================================


'===================================================================================================================
'【 原点 】
搬送コンベアAOrg=( ((XSW12_ストッパ上昇端 and not(pnlPBXSW12_ストッパ上昇端)) or passXSW12_ストッパ上昇端) or ((XSW11_ストッパ下降端 and not(pnlPBXSW11_ストッパ下降端)) or passXSW11_ストッパ下降端) ) 
搬送コンベアAOrg=搬送コンベアAOrg and (((XSW14_ストッパ上昇端 and not(pnlPBXSW14_ストッパ上昇端)) or passXSW14_ストッパ上昇端) or ((XSW13_ストッパ下降端 and not(pnlPBXSW13_ストッパ下降端)) or passXSW13_ストッパ下降端))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアAEmg=ON
	搬送コンベアAEmgStep=1
end if


'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV14_ストッパ and not(XSW12_ストッパ上昇端) and not(pnlPBXSW12_ストッパ上昇端), tim_notXSW12_ストッパ上昇端,#20) '466.94ms
tmr(not(SV14_ストッパ) and not(XSW11_ストッパ下降端) and not(pnlPBXSW11_ストッパ下降端),tim_notXSW11_ストッパ下降端,#20) '624.85ms
tmr(SV15_ストッパ and not(XSW14_ストッパ上昇端) and not(pnlPBXSW14_ストッパ上昇端),tim_notXSW14_ストッパ上昇端,#20) '417.30ms
tmr(not(SV15_ストッパ) and not(XSW13_ストッパ下降端) and not(pnlPBXSW13_ストッパ下降端),tim_notXSW13_ストッパ下降端,#20) '580.42ms

'tmr(not(SV14_ストッパ) and XSW12_ストッパ上昇端, tim_XSW12_ストッパ上昇端,#10) '466.94ms
if LDP(SV14_ストッパ) and XSW12_ストッパ上昇端 and not(pnlPBXSW12_ストッパ上昇端) then
	SET(tim_XSW12_ストッパ上昇端)
end if
'tmr(SV14_ストッパ and XSW11_ストッパ下降端, tim_XSW11_ストッパ下降端,#10) '624.85ms
if LDF(SV14_ストッパ) and XSW11_ストッパ下降端 and not(pnlPBXSW11_ストッパ下降端) then
	SET(tim_XSW11_ストッパ下降端)
end if
'tmr(not(SV15_ストッパ) and XSW14_ストッパ上昇端 ,tim_XSW14_ストッパ上昇端,#10) '417.30ms
if LDP(SV15_ストッパ) and XSW14_ストッパ上昇端 and not(pnlPBXSW14_ストッパ上昇端) then
	SET(tim_XSW14_ストッパ上昇端)
end if
'tmr(SV15_ストッパ and XSW13_ストッパ下降端,tim_XSW13_ストッパ下降端,#10) '580.42ms
if LDF(SV15_ストッパ) and XSW13_ストッパ下降端 and not(pnlPBXSW13_ストッパ下降端) then
	SET(tim_XSW13_ストッパ下降端)
end if

'passtimXSW12_ストッパ上昇端_val=#466
tms(SV14_ストッパ , passtimXSW12_ストッパ上昇端,passtimXSW12_ストッパ上昇端_val) 
'passtimXSW11_ストッパ下降端_val=#624
tms(not(SV14_ストッパ), passtimXSW11_ストッパ下降端,passtimXSW11_ストッパ下降端_val) 
'passtimXSW14_ストッパ上昇端_val=#417
tms(SV15_ストッパ,passtimXSW14_ストッパ上昇端,passtimXSW14_ストッパ上昇端_val) 
'passtimXSW13_ストッパ下降端_val=#580
tms(not(SV15_ストッパ),passtimXSW13_ストッパ下降端,passtimXSW13_ストッパ下降端_val) 

tmr(mMC6_搬送モータ and not(pauseMC6_搬送モータ) and not(EmgMC6_搬送モータ),timerr_MC6_搬送モータ,#120)
tmr(mMC7_搬送モータ and not(pauseMC7_搬送モータ) and not(EmgMC7_搬送モータ),timerr_MC7_搬送モータ,#120)
tmr(mMC8_搬送モータ and not(pauseMC8_搬送モータ) and not(EmgMC8_搬送モータ),timerr_MC8_搬送モータ,#120)


if ldp(timerr_MC6_搬送モータ.B) then
	almMC6_搬送モータ=ON

	mMC6_搬送モータ=OFF
	mMC7_搬送モータ=OFF
	mMC8_搬送モータ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC7_搬送モータ.B) then
	almMC7_搬送モータ=ON

	mMC6_搬送モータ=OFF
	mMC7_搬送モータ=OFF
	mMC8_搬送モータ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC8_搬送モータ.B) then
	almMC8_搬送モータ=ON

	mMC6_搬送モータ=OFF
	mMC7_搬送モータ=OFF
	mMC8_搬送モータ=OFF

	コンベア一時停止=ON
	
else if ldp(almPH50_釜検知 or almPH51_フタ検知) then 
	
	コンベア一時停止=ON

end if

if (ldp(tim_XSW12_ストッパ上昇端.B) or ldp(tim_notXSW12_ストッパ上昇端.B)) and not(pnlPBXSW12_ストッパ上昇端) then
	pauseSV14_ストッパ=ON
	almXSW12_ストッパ上昇端=ON
	pnlPBXSW12_ストッパ上昇端=ON
	if tim_XSW12_ストッパ上昇端 then
		res(tim_XSW12_ストッパ上昇端)
	end if
	搬送コンベアAErrStep=1

else if (ldp(tim_XSW11_ストッパ下降端.B) or ldp(tim_notXSW11_ストッパ下降端.B)) and not(pnlPBXSW11_ストッパ下降端) then
	almXSW11_ストッパ下降端=ON
	pnlPBXSW11_ストッパ下降端=ON
	if tim_XSW11_ストッパ下降端 then
		res(tim_XSW11_ストッパ下降端)
	end if
	搬送コンベアAErrStep=1

else if (ldp(tim_XSW14_ストッパ上昇端.B) or ldp(tim_notXSW14_ストッパ上昇端.B)) and not(pnlPBXSW14_ストッパ上昇端) then
	pauseSV15_ストッパ=ON
	almXSW14_ストッパ上昇端=ON
	pnlPBXSW14_ストッパ上昇端=ON
	if tim_XSW14_ストッパ上昇端 then
		res(tim_XSW14_ストッパ上昇端)
	end if
	搬送コンベアAErrStep=1

else if (ldp(tim_XSW13_ストッパ下降端.B) or ldp(tim_notXSW13_ストッパ下降端.B)) and not(pnlPBXSW13_ストッパ下降端) then
	almXSW13_ストッパ下降端=ON
	pnlPBXSW13_ストッパ下降端=ON
	if tim_XSW13_ストッパ下降端 then
		res(tim_XSW13_ストッパ下降端)
	end if
	搬送コンベアAErrStep=1

end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアAAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアAAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアAEmg	その場停止

'釜フタ搬送:	昇降装置B  -> 搬送口

'釜浸漬搬送:   	搬送口 -> 浸漬A(浸漬B）
'フタ搬送:		搬送口 -> 浸漬B
'釜注水:		浸漬A(浸漬B）-> 注水
'フタ排出:		浸漬B -> (リフト）

'釜排出:		注水 -> （リフト）

if 搬送コンベアAEmgStep=0 then  
	
	if 搬送コンベアAErrStep=0  then

	if not(コンベア一時停止) then

	if not(搬送コンベアAOrgErr) then
	
	if (搬送コンベアAAutoMode and 自動搬送AutoMode ) or 搬送コンベアAstep<>0 then
	
		if ManualInite=1 then
			if PH1_釜検知 then
				mSV14_ストッパ=ON
			end if

			 if PH3_釜検知 then
				mSV15_ストッパ=ON
			end if

			ManualInite=0
		end if
		
		if not(搬送コンベアAAutoMode and 自動搬送AutoMode ) then
			搬送コンベアAAutoRun=OFF
		end if
	
	tmr(PH1_釜検知,timdly_PH1_釜検知,4)
	tmr(PH2_フタ検知,timdly_PH2_フタ検知,4)
	tmr(PH3_釜検知,timdly_PH3_釜検知,4)
	tmr(PH4_フタ検知,timdly_PH4_フタ検知,4)
	tmr(PH5_釜検知,timdly_PH5_釜検知,10)
	tmr(PH6_フタ検知,timdly_PH6_フタ検知,10)
	tmr(PH52_釜検知,timdly_PH52_釜検知,4)
	tmr(PH53_フタ検知,timdly_PH53_フタ検知,4)	

	'-----------------------------------------------------------------
	' ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	'SV14_ストッパ 
	tmr(tim_SV14_ストッパ,tim_SV14_ストッパ_val)
	select case SV14_ストッパstep
	case 0
	case 1
		PH50_釜起動検知=PH50_釜検知 '----搬送口
		PH51_フタ起動検知=PH51_フタ検知
		PH1_釜起動検知=PH1_釜検知 '----浸漬A
		PH2_フタ起動検知=PH2_フタ検知
		'PH3_釜検知 '----浸漬B
		'PH4_フタ検知
		inc(SV14_ストッパstep)
	
	case 2
		if PH50_釜検知 or PH51_フタ検知 or PH1_釜検知 or PH2_フタ検知 then
			inc(SV14_ストッパstep)
		else
			SV14_ストッパstep=0
		end if
	
	case 3
		mSV14_ストッパ=OFF		
		inc(SV14_ストッパstep)
		
	case 4
		if (XSW11_ストッパ下降端 and not(pnlPBXSW11_ストッパ下降端)) or passXSW11_ストッパ下降端 then
			inc(SV14_ストッパstep)
		end if				
		
	case 5
		if errpassコンベア一時停止 then
			inc(SV14_ストッパstep)
		else if not(PH50_釜検知) and not(PH51_フタ検知) and not(PH1_釜検知) and not(PH2_フタ検知) then
			inc(SV14_ストッパstep)
		end if
		
	case 6
		tim_SV14_ストッパ_val=30
		res(tim_SV14_ストッパ)
		inc(SV14_ストッパstep)
		
	case 7
		if tim_SV14_ストッパ.B then
			inc(SV14_ストッパstep)
		end if		

	case 8
		if not(PH50_釜起動検知) and  PH51_フタ起動検知 then
			mSV14_ストッパ=OFF
		else
			mSV14_ストッパ=ON		
		end if
		inc(SV14_ストッパstep)

	case 9
		if (mSV14_ストッパ and ((XSW12_ストッパ上昇端 and not(pnlPBXSW12_ストッパ上昇端)) or passXSW12_ストッパ上昇端)) or (not(mSV14_ストッパ) and ((XSW11_ストッパ下降端 and not(pnlPBXSW11_ストッパ下降端)) or passXSW11_ストッパ下降端)) then
			inc(SV14_ストッパstep)
		end if				

	case 10
		if 	PH1_釜検知 and PH2_フタ検知 then  '浸漬A
			inc(釜カウントA)
		end if

		SV14_ストッパstep=0
	
	end select	
	'--------------------------------------------
	'SV15_ストッパ
	tmr(tim_SV15_ストッパ, tim_SV15_ストッパ_val)
	select case SV15_ストッパstep
	case 0
	case 1
		PH50_釜起動検知=PH50_釜検知 '----搬送口
		PH51_フタ起動検知=PH51_フタ検知
		PH1_釜起動検知=PH1_釜検知 '----浸漬A
		PH2_フタ起動検知=PH2_フタ検知
		PH3_釜起動検知=PH3_釜検知 '----浸漬B
		PH4_フタ起動検知=PH4_フタ検知
		'PH52_釜検知 '----注水
		'PH53_フタ起動検知=PH53_フタ検知
		inc(SV15_ストッパstep)
	
	case 2
		if PH1_釜検知 or PH2_フタ検知 or PH3_釜検知 or PH4_フタ検知 then
			inc(SV15_ストッパstep)
		else
			SV15_ストッパstep=0
		end if

	case 3
		mSV15_ストッパ=OFF
		inc(SV15_ストッパstep)

	case 4
		if (XSW13_ストッパ下降端 and not(pnlPBXSW13_ストッパ下降端)) or passXSW13_ストッパ下降端 then			
			inc(SV15_ストッパstep)
		end if
		
	case 5
		if errpassコンベア一時停止 then
			inc(SV15_ストッパstep)
		else if not(PH3_釜検知) and not(PH4_フタ検知) then '----浸漬B
			inc(SV15_ストッパstep)
		end if
		
	case 6
		tim_SV15_ストッパ_val=30
		res(tim_SV15_ストッパ)
		inc(SV15_ストッパstep)
		
	case 7
		if tim_SV15_ストッパ.B then
			inc(SV15_ストッパstep)
		end if	
	
	case 8
		if not(PH1_釜起動検知) and PH2_フタ起動検知 then
			mSV15_ストッパ=OFF
		else
			mSV15_ストッパ=ON
		end if
		inc(SV15_ストッパstep)
	
	case 9
		if (mSV15_ストッパ and ((XSW14_ストッパ上昇端 and not(pnlPBXSW14_ストッパ上昇端)) or passXSW14_ストッパ上昇端)) or (not(mSV15_ストッパ) and ((XSW13_ストッパ下降端 and not(pnlPBXSW13_ストッパ下降端)) or passXSW13_ストッパ下降端)) then			
			inc(SV15_ストッパstep)
		end if		

	case 10
		if 	PH3_釜検知 and PH4_フタ検知 then  '浸漬B
			inc(釜カウントB)
		end if
		SV15_ストッパstep=0
	
	end select
	'--------------------------------------------
	'MC6_搬送モータ [搬送口->浸漬A]
	tmr(tim_MC6_搬送モータ,tim_MC6_搬送モータ_val)
	select case MC6_搬送モータstep
	case 0
	case 1
		PH50_釜起動検知=PH50_釜検知 '----搬送口
		PH51_フタ起動検知=PH51_フタ検知
		'PH1_釜検知 '----浸漬A
		'PH2_フタ検知
		inc(MC6_搬送モータstep)
		
	case 2
		if PH50_釜検知 or PH51_フタ検知 then
			inc(MC6_搬送モータstep)
		else
			MC6_搬送モータstep=0
		end if		

	case 3
		mMC6_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC6_搬送モータstep)
	
	case 4
		if errpassコンベア一時停止 then
			inc(MC6_搬送モータstep)
		
		else if not(PH50_釜検知) and not(PH51_フタ検知) and not(PH1_釜検知) and not(PH2_フタ検知) then
			inc(MC6_搬送モータstep)
		end if
	
	case 5
		if errpassコンベア一時停止 then
			inc(MC6_搬送モータstep)		
		
		else if PH50_釜起動検知 or PH51_フタ起動検知  then
			if (PH1_釜検知 and timdly_PH1_釜検知.B) or (PH2_フタ検知 and timdly_PH2_フタ検知.B) then
				inc(MC6_搬送モータstep)
			end if
		end if

	case 6
		mMC6_搬送モータ=OFF
		inc(MC6_搬送モータstep)
	
	case 7
		MC6_搬送モータstep=0
		
	end select
	'--------------------------------------------
	'MC7_搬送モータ	[搬送口,浸漬A、浸漬B,注水,リフト -> 浸漬A、浸漬B,注水,リフト ]
	tmr(tim_MC7_搬送モータ,tim_MC7_搬送モータ_val)
	select case MC7_搬送モータstep
	case 0
	case 1
		PH50_釜起動検知=PH50_釜検知 '----搬送口
		PH51_フタ起動検知=PH51_フタ検知
		PH1_釜起動検知=PH1_釜検知 '----浸漬A
		PH2_フタ起動検知=PH2_フタ検知
		PH3_釜起動検知=PH3_釜検知 '----浸漬B
		PH4_フタ起動検知=PH4_フタ検知
		PH52_釜起動検知=PH52_釜検知 '----注水
		PH53_フタ起動検知=PH53_フタ検知
		'PH5_釜検知 '----コンベアBリフト
		'PH6_フタ検知
		inc(MC7_搬送モータstep)
		
	
	case 2
		if PH50_釜検知 or PH51_フタ検知 then '----搬送口
			inc(MC7_搬送モータstep)
		else if PH1_釜検知 or PH2_フタ検知 then '----浸漬A
			inc(MC7_搬送モータstep)
		else if PH3_釜検知 or PH4_フタ検知 then  '----浸漬B
			inc(MC7_搬送モータstep)
		else if PH52_釜検知 or PH53_フタ検知 then
			inc(MC7_搬送モータstep)
		else
			MC7_搬送モータstep=0
		end if
	
	case 3
		if (not(PH1_釜起動検知) or not(PH2_フタ起動検知) ) or (PH1_釜起動検知 and PH2_フタ起動検知 and  ((XSW11_ストッパ下降端 and not(pnlPBXSW11_ストッパ下降端)) or passXSW11_ストッパ下降端) ) then 
			if (not(PH3_釜起動検知) or not(PH4_フタ起動検知) ) or (PH3_釜起動検知 and PH4_フタ起動検知 and  ((XSW13_ストッパ下降端 and not(pnlPBXSW13_ストッパ下降端)) or passXSW13_ストッパ下降端) ) then 
				inc(MC7_搬送モータstep)
			end if
		end if	
	
	case 4
		mMC7_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC7_搬送モータstep)
	
	case 5
		if errpassコンベア一時停止 then
			inc(MC7_搬送モータstep)
		
		else if not(PH50_釜検知) and not(PH51_フタ検知) then
			if not(PH1_釜検知) and not(PH2_フタ検知) then
				if not(PH3_釜検知) and not(PH4_フタ検知) then
					if not(PH52_釜検知) and  not(PH53_フタ検知) then
					inc(MC7_搬送モータstep)
					end if
				end if
			end if
		end if
	
	case 6
		if errpassコンベア一時停止 then
			inc(MC7_搬送モータstep)
		
		else if PH50_釜起動検知 or PH51_フタ起動検知 then
			if PH50_釜起動検知 then
				if (PH1_釜検知 and timdly_PH1_釜検知.B) then  '----浸漬A
					inc(MC7_搬送モータstep)
				end if
			else if PH51_フタ起動検知 then
				if (PH2_フタ検知 and timdly_PH2_フタ検知.B) then
					inc(MC7_搬送モータstep)
				end if
			end if
		
		else if PH1_釜起動検知 or PH3_釜起動検知 or PH52_釜起動検知 then
			if PH1_釜起動検知 then
				if (PH3_釜検知 and timdly_PH3_釜検知.B) then '----浸漬B
					inc(MC7_搬送モータstep)			
				end if			
			else if PH3_釜起動検知 then
				if (PH52_釜検知 and timdly_PH52_釜検知.B) then
					inc(MC7_搬送モータstep)						
				end if
			else if PH52_釜起動検知 then
				if (PH5_釜検知 and timdly_PH5_釜検知.B) then
					inc(MC7_搬送モータstep)
				end if
			end if
		
		else if PH2_フタ起動検知 or PH4_フタ起動検知 or PH53_フタ起動検知 then
			if PH2_フタ起動検知 then
				if (PH4_フタ検知 and timdly_PH4_フタ検知.B) then
					inc(MC7_搬送モータstep)
				end if
			else if PH4_フタ起動検知 then			
				if (PH53_フタ検知 and timdly_PH53_フタ検知.B) then
					inc(MC7_搬送モータstep)
				end if
			else if PH53_フタ起動検知 then
				if (PH6_フタ検知 and timdly_PH6_フタ検知.B) then
					inc(MC7_搬送モータstep)
				end if
			end if
		end if
			
	case 7
		tim_MC7_搬送モータ_val=10 'ブレークタイミング
		res(tim_MC7_搬送モータ)
		inc(MC7_搬送モータstep)
	
	case 8
		if tim_MC7_搬送モータ.B then
			inc(MC7_搬送モータstep)
		end if
	
	case 9
		'---------------------------------------------------------
		'釜移動検知
		if errpassコンベア一時停止 then
			inc(MC7_搬送モータstep)
		
				'浸漬タンクA → 浸漬タンクB                                   浸漬タンクB → 注水ユニット
		else if (not(PH1_釜起動検知) or (PH1_釜起動検知 and PH3_釜検知) ) and (not(PH3_釜起動検知) or (PH3_釜起動検知 and PH52_釜検知) ) then
			inc(MC7_搬送モータstep)
		end if	
	
	case 10
		mMC7_搬送モータ=OFF
		inc(MC7_搬送モータstep)
	
	case 11
		MC7_搬送モータstep=0
	
	end select
	'--------------------------------------------
	'MC8_搬送モータ [搬送口,浸漬A、浸漬B,注水,リフト -> 注水,リフト ]
	tmr(tim_MC8_搬送モータ,tim_MC8_搬送モータ_val)
	select case MC8_搬送モータstep
	case 0
	case 1
		PH3_釜起動検知=PH3_釜検知 '----浸漬B
		PH4_フタ起動検知=PH4_フタ検知
		PH52_釜起動検知=PH52_釜検知 '----注水
		PH53_フタ起動検知=PH53_フタ検知
		'PH5_釜検知 '----コンベアBリフト
		'PH6_フタ検知
		
		注水搬送補助=OFF
		
		inc(MC8_搬送モータstep)
	
	case 2
		if PH3_釜検知 or PH4_フタ検知 or PH52_釜検知 or PH53_フタ検知 then '----注水
			inc(MC8_搬送モータstep)
			if (PH3_釜検知 or PH4_フタ検知) and (not(PH52_釜検知) and not(PH53_フタ検知)) then
				注水搬送補助=ON
			end if
		else
			MC8_搬送モータstep=0
		end if
	
	case 3
		mMC8_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC8_搬送モータstep)

	case 4
		if errpassコンベア一時停止 then
			inc(MC8_搬送モータstep)
		
		else if not(PH3_釜検知) and not(PH4_フタ検知) and not(PH52_釜検知) and not(PH53_フタ検知) then '----注水
			inc(MC8_搬送モータstep)
		end if
	

	case 5
		if errpassコンベア一時停止 then
			inc(MC8_搬送モータstep)
			
		else if PH52_釜起動検知 or PH53_フタ起動検知 then
			if (PH5_釜検知 and timdly_PH5_釜検知.B) or (PH6_フタ検知 and timdly_PH6_フタ検知.B) then
				SV16_リフト排出step=1
				tim_MC8_搬送モータ_val=28
				res(tim_MC8_搬送モータ)

				inc(MC8_搬送モータstep)
			end if
		else
			inc(MC8_搬送モータstep)
		end if
	
	case 6
		if errpassコンベア一時停止 then
			inc(MC8_搬送モータstep)
			
		else if PH3_釜起動検知 and PH4_フタ起動検知 then
				if (PH52_釜検知 and timdly_PH52_釜検知.B) and (PH53_フタ検知  and timdly_PH53_フタ検知.B) then
					tim_MC8_搬送モータ_val=8
					res(tim_MC8_搬送モータ)
					inc(MC8_搬送モータstep)
				end if				
		else
			tim_MC8_搬送モータ_val=30
			res(tim_MC8_搬送モータ)
			inc(MC8_搬送モータstep)		
		end if
	
	case 7
		if tim_MC8_搬送モータ.B then
			inc(MC8_搬送モータstep)
		end if
	
	case 8
		mMC8_搬送モータ=OFF
		inc(MC8_搬送モータstep)
		
	case 9
		MC8_搬送モータstep=0
						
	end select
	'--------------------------------------------
	'SV1 排出タスク
	tmr(tim_SV16_リフト排出,tim_SV16_リフト排出_val)
	select case SV16_リフト排出step
	case 0
	case 1
		tim_SV16_リフト排出_val=20
		res(tim_SV16_リフト排出)
		inc(SV16_リフト排出step)
	
	case 2
		if tim_SV16_リフト排出.B then
			inc(SV16_リフト排出step)
		end if
		
	case 3
		搬送コンベアA排出要求=ON
		SV16_リフト排出step=0
	end select

	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)
		tmr(PH50_釜検知 or PH51_フタ検知, tim_搬送入口検知 , 20)

		select case 搬送コンベアAstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアAAutoRun then
				inc(搬送コンベアAstep)
			else 
				搬送コンベアAstep=0 '終了待機
			end if
		
		case 2
			if PH5_釜検知 or PH6_フタ検知 then
				搬送コンベアA動作中=OFF
				搬送コンベアA排出要求=ON
				搬送コンベアAstep=1
			else
				inc(搬送コンベアAstep)
			end if
			
		case 3
		' [ 次の搬送コンベア停止確認 ]		
			if 搬送コンベアA排出要求=OFF  and (釜フタ昇降B排出要求 or tim_搬送入口検知.B ) then
				inc(搬送コンベアAstep)
			else
				搬送コンベアAstep=1
			end if
		
		case 4
			if 浸漬タンクA排出要求 and 浸漬タンクB排出要求 and 注水排出要求 and ((XSW4_水切りシャッター閉A and not(pnlPBXSW4_水切りシャッター閉A)) or passXSW4_水切りシャッター閉A) and ((XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B)) or passXSW8_水切りシャッター閉B) then
				inc(搬送コンベアAstep)
			else
				搬送コンベアAstep=1
			end if

			
		case 5  '原点検出
			if 搬送コンベアAOrg then
				errpassコンベア一時停止=OFF
				inc(搬送コンベアAstep)
			else
				搬送コンベアAstep=1
			end if
			
		case 6
		
			if 残米処理中一時停止 then
				搬送コンベアAstep=1
			else
				搬送コンベアAstep=100
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 100
			PH50_釜起動検知=PH50_釜検知 '----搬送口
			PH51_フタ起動検知=PH51_フタ検知
			PH1_釜起動検知=PH1_釜検知 '----浸漬A
			PH2_フタ起動検知=PH2_フタ検知
			PH3_釜起動検知=PH3_釜検知 '----浸漬B
			PH4_フタ起動検知=PH4_フタ検知
			PH52_釜起動検知=PH52_釜検知 '----注水
			PH53_フタ起動検知=PH53_フタ検知
			
			if フタ検知 and not(PH50_釜検知) and PH51_フタ検知 then
				almPH51_フタ検知=ON
				釜フタ昇降B排出要求=OFF
				搬送コンベアAstep=1
			else if not(フタ検知) and PH50_釜検知 and PH51_フタ検知 then
				almPH50_釜検知=ON
				釜フタ昇降B排出要求=OFF
				搬送コンベアAstep=1
			else 
			
				if not(PH50_釜検知) and PH51_フタ検知 then 'フタ検知
						フタ検知=ON
				else if PH50_釜検知 and PH51_フタ検知 then '釜検知
						フタ検知=OFF
				end if
				inc(搬送コンベアAstep)	

			end if
			

			
		case 101
			搬送コンベアA動作中=ON
			SV14_ストッパstep=1
			SV15_ストッパstep=1
			MC6_搬送モータstep=1
			MC7_搬送モータstep=1
			MC8_搬送モータstep=1

			釜フタ昇降B排出要求=OFF
			inc(搬送コンベアAstep)
		
		case 102
			if 	SV14_ストッパstep=0 and SV15_ストッパstep=0	and MC6_搬送モータstep=0 and MC7_搬送モータstep=0 and MC8_搬送モータstep=0 then
				mMC6_搬送モータ=OFF
				mMC7_搬送モータ=OFF
				mMC8_搬送モータ=OFF
				
				inc(搬送コンベアAstep)
			end if		

		case 103
			StageDevice4=StageDevice3
			StageDevice3=StageDevice2
			StageDevice2=StageDevice1
			StageDevice1=StageDevice0
			
			
			'----------------------------------------------------------------------------
			'---- 配米インターバル ----
			'----------------------------------------------------------------------------
			if ほぐしA供給禁止 then
				配米インターバル設定値=配米インターバル配米設定値+配米インターバル水釜設定値


				if (IND_炊飯中 and IND_配米中) and PH1_釜検知 and PH2_フタ検知 then
					inc(配米インターバルCNT)
				end if
		
				
				if (IND_炊飯中 and IND_配米中) and 配米インターバル配米設定値>0 and 配米インターバル水釜設定値>0 then	
					if 配米インターバルCNT < 配米インターバル設定値 then
						if 配米インターバルCNT >= 配米インターバル配米設定値 then
							配米インターバル禁止=ON
						end if
					else
						配米インターバルCNT=0
						配米インターバル禁止=OFF		
					end if			
				else
					配米インターバルCNT=0
					配米インターバル禁止=OFF		
				end if
				
			else
				配米インターバルCNT=0
				配米インターバル禁止=OFF					
			end if
			'----------------------------------------------------------------------------			
			if 配米終了フラグ then
				if PH1_釜検知 and PH2_フタ検知 then
					inc(消火警告までの残釜数)
					inc(搬送釜数)
				end if
			else
				消火警告までの残釜数=0
				搬送釜数=0
			end if

			inc(搬送コンベアAstep)

		case 104
		
			浸漬タンクA排出要求=OFF
			浸漬タンクB排出要求=OFF
			注水排出要求=OFF
			配米完了A=OFF
			配米完了B=OFF
			注水完了=OFF

			搬送コンベアA動作中=OFF
			搬送コンベアAstep=1
			

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
		if ManualInite=0 then
			mSV14_ストッパ=OFF
			mSV15_ストッパ=OFF
			ManualInite=1
		end if
		
		搬送コンベアAAutoRun=OFF
		
		搬送コンベアAstep=0 '終了

		res(timerr_MC6_搬送モータ)
		res(timerr_MC7_搬送モータ)
		res(timerr_MC8_搬送モータ)
		
		if ldp(pnlPBMC6_搬送モータ) then
			if mMC6_搬送モータ then
				mMC6_搬送モータ=OFF
			else
				mMC6_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC7_搬送モータ) then
			if mMC7_搬送モータ then
				mMC7_搬送モータ=OFF
			else
				mMC7_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC8_搬送モータ) then
			if mMC8_搬送モータ then
				mMC8_搬送モータ=OFF
			else
				mMC8_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBSV14_ストッパ) then
			if mSV14_ストッパ then
				mSV14_ストッパ=OFF
			else
				mSV14_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV15_ストッパ) then
			if mSV15_ストッパ then
				mSV15_ストッパ=OFF
			else
				mSV15_ストッパ=ON
			end if
		end if
					
	end if '搬送コンベアAAutoMode and not(搬送コンベアAOrgErrStep)
	'===================================================================================================================
	'【 搬送コンベアAOrgErr処理 】
	else

		if ResetFlg then
			搬送コンベアAOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 搬送コンベアA一時停止処理 】
	else 

		コンベア一時停止中=ON
		alm渋滞警報=ON			

	
		if ResetFlg then
		
			almPH50_釜検知=OFF
			almPH51_フタ検知=OFF

			almMC6_搬送モータ=OFF
			almMC7_搬送モータ=OFF
			almMC8_搬送モータ=OFF

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

		搬送コンベアAErr=ON

		pauseMC6_搬送モータ=ON
		pauseMC7_搬送モータ=ON
		pauseMC8_搬送モータ=ON
		pauseMC11_搬送モータ=ON
		


		select case 搬送コンベアAErrStep
		case 0
		case 1
			alm渋滞警報=ON			
	
			if ResetFlg then
				almMC6_搬送モータ=OFF
				almMC7_搬送モータ=OFF
				almMC8_搬送モータ=OFF

				almXSW12_ストッパ上昇端=OFF
				almXSW11_ストッパ下降端=OFF
				almXSW14_ストッパ上昇端=OFF
				almXSW13_ストッパ下降端=OFF

				alm渋滞警報=OFF			

				inc(搬送コンベアAErrStep)
			end if
		case 2
			搬送コンベアAErr=OFF

			res(tim_XSW12_ストッパ上昇端.B)
			res(tim_XSW11_ストッパ下降端.B)
			res(tim_XSW14_ストッパ上昇端.B)
			res(tim_XSW13_ストッパ下降端.B)

			res(tim_notXSW12_ストッパ上昇端.B)
			res(tim_notXSW11_ストッパ下降端.B)
			res(tim_notXSW14_ストッパ上昇端.B)
			res(tim_notXSW13_ストッパ下降端.B)

			pauseMC6_搬送モータ=OFF
			pauseMC7_搬送モータ=OFF
			pauseMC8_搬送モータ=OFF
			pauseMC11_搬送モータ=OFF
			
			pauseSV14_ストッパ=OFF
			pauseSV15_ストッパ=OFF


			搬送コンベアAErrStep=0
		end select

	end if 'if 搬送コンベアAErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 搬送コンベアAEmgStep
	case 0
		
	case 1
		搬送コンベアAAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		
		'自動実行条件
		if (搬送コンベアAAutoMode and 自動搬送AutoMode ) or 搬送コンベアAstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			
			'自動実行で駆動しているモータ MC を停止
			
			EmgMC6_搬送モータ=ON
			EmgMC7_搬送モータ=ON
			EmgMC8_搬送モータ=ON

			if timstack=OFF then
				
				'現在値をスタックに記憶
				timdly_PH1_釜検知_stack.U=timdly_PH1_釜検知.U
				timdly_PH2_フタ検知_stack.U=timdly_PH2_フタ検知.U
				timdly_PH3_釜検知_stack.U=timdly_PH3_釜検知.U
				timdly_PH4_フタ検知_stack.U=timdly_PH4_フタ検知.U
				timdly_PH5_釜検知_stack.U=timdly_PH5_釜検知.U
				timdly_PH6_フタ検知_stack.U=timdly_PH6_フタ検知.U
				timdly_PH52_釜検知_stack.U=timdly_PH52_釜検知.U
				timdly_PH53_フタ検知_stack.U=timdly_PH53_フタ検知.U
				tim_SV14_ストッパ_stack.U=tim_SV14_ストッパ.U
				tim_SV15_ストッパ_stack.U=tim_SV15_ストッパ.U
				tim_MC6_搬送モータ_stack.U=tim_MC6_搬送モータ.U
				tim_MC7_搬送モータ_stack.U=tim_MC7_搬送モータ.U
				tim_MC8_搬送モータ_stack.U=tim_MC8_搬送モータ.U
				tim_SV16_リフト排出_stack.U=tim_SV16_リフト排出.U
				tim_procstep_stack.U=tim_procstep.U
				tim_搬送入口検知_stack.U=tim_搬送入口検知.U
				
				
				' tmr(PH1_釜検知,timdly_PH1_釜検知,4)
				' tmr(PH2_フタ検知,timdly_PH2_フタ検知,4)
				' tmr(PH3_釜検知,timdly_PH3_釜検知,4)
				' tmr(PH4_フタ検知,timdly_PH4_フタ検知,4)
				' tmr(PH5_釜検知,timdly_PH5_釜検知,10)
				' tmr(PH6_フタ検知,timdly_PH6_フタ検知,10)
				' tmr(PH52_釜検知,timdly_PH52_釜検知,4)
				' tmr(PH53_フタ検知,timdly_PH53_フタ検知,4)	
				' tmr(tim_SV14_ストッパ,tim_SV14_ストッパ_val)
				' tmr(tim_SV15_ストッパ, tim_SV15_ストッパ_val)
				' tmr(tim_MC6_搬送モータ,tim_MC6_搬送モータ_val)
				' tmr(tim_MC7_搬送モータ,tim_MC7_搬送モータ_val)
				' tmr(tim_MC8_搬送モータ,tim_MC8_搬送モータ_val)
				' tmr(tim_SV16_リフト排出,tim_SV16_リフト排出_val)
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(PH50_釜検知 or PH51_フタ検知, tim_搬送入口検知 , 20)
				
				
				timstack=ON
			end if
			
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			
			'手動でON/OFFしているデバイスをすべてOFFにする
			
			mMC6_搬送モータ=OFF
			mMC7_搬送モータ=OFF
			mMC8_搬送モータ=OFF
			mSV14_ストッパ=OFF
			mSV15_ストッパ=OFF
			mSV16_リフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアAEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアAEmgStep)
		end if
	case 3
		
		'自動実行条件

		if (搬送コンベアAAutoMode and 自動搬送AutoMode ) or 搬送コンベアAstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------

				'自動実行で駆動しているモータ MC をリリース

				EmgMC6_搬送モータ=OFF
				EmgMC7_搬送モータ=OFF
				EmgMC8_搬送モータ=OFF

				'スタックの値をタイマー現在値にリストア
				tim_SV14_ストッパ.U=tim_SV14_ストッパ_stack.U
				tim_SV15_ストッパ.U=tim_SV15_ストッパ_stack.U
				tim_MC6_搬送モータ.U=tim_MC6_搬送モータ_stack.U
				tim_MC7_搬送モータ.U=tim_MC7_搬送モータ_stack.U
				tim_MC8_搬送モータ.U=tim_MC8_搬送モータ_stack.U
				tim_SV16_リフト排出.U=tim_SV16_リフト排出_stack.U
				tim_procstep.U=tim_procstep_stack.U
				' tmr(tim_SV14_ストッパ,tim_SV14_モータ_val)
				' tmr(tim_MC7_搬送モータ,tim_MC7_搬送モータ_val)
				' tmr(tim_MC8_搬送モータ,tim_MC8_搬送モータ_val)
				' tmr(tim_SV16_リフト排出,tim_SV16_リフト排出_val)
				' tmr(tim_procstep,tim_procstep_val)
				
				'検出タイマーのリセット
				res(timdly_PH1_釜検知)
				res(timdly_PH2_フタ検知)
				res(timdly_PH3_釜検知)
				res(timdly_PH4_フタ検知)
				res(timdly_PH5_釜検知)
				res(timdly_PH6_フタ検知)
				res(timdly_PH52_釜検知)
				res(timdly_PH53_フタ検知)
				res(tim_搬送入口検知)
				
				' tmr(PH1_釜検知,timdly_PH1_釜検知,4)
				' tmr(PH2_フタ検知,timdly_PH2_フタ検知,4)
				' tmr(PH3_釜検知,timdly_PH3_釜検知,4)
				' tmr(PH4_フタ検知,timdly_PH4_フタ検知,4)
				' tmr(PH5_釜検知,timdly_PH5_釜検知,10)
				' tmr(PH6_フタ検知,timdly_PH6_フタ検知,10)
				' tmr(PH52_釜検知,timdly_PH52_釜検知,4)
				' tmr(PH53_フタ検知,timdly_PH53_フタ検知,4)	
				' tmr(PH50_釜検知 or PH51_フタ検知, tim_搬送入口検知 , 20)
				'---------------------------------
				inc(搬送コンベアAEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアAEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアAEmgStep=0
		搬送コンベアAEmg=OFF
	end select
		
end if 'if 搬送コンベアAEmgStep=0 then
