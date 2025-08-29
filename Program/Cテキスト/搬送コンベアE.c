'搬送コンベアE
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアE
'
'  	移動速度  161.667mm/1sec
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    搬送コンベアEAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアEAutoRun=OFF
    搬送コンベアE許可=ON
    搬送コンベアEOrgErr=OFF
    搬送コンベアEErr=OFF
    搬送コンベアEEmg=OFF
    搬送コンベアEstep=0
    搬送コンベアEErrStep=0
    搬送コンベアEOrgErrStep=0
    搬送コンベアEEmgStep=0

	MC23_モータローラstep=0
	SV53_ストッパstep=0
	MC25_搬送モータstep=0
	SV54_ストッパstep=0
	MC26_搬送モータstep=0
	MC27_モータローラstep=0
	
	ManualInite=1

end if
'===================================================================================================================
'【 原点 】
搬送コンベアEOrg=( ((XSW64_ストッパ上昇端 and not(pnlPBXSW64_ストッパ上昇端)) or passXSW64_ストッパ上昇端) or ((XSW63_ストッパ下降端 and not(pnlPBXSW63_ストッパ下降端)) or passXSW63_ストッパ下降端)) 
搬送コンベアEOrg=搬送コンベアEOrg and ( ((XSW66_ストッパ上昇端 and not(pnlPBXSW66_ストッパ上昇端)) or passXSW66_ストッパ上昇端) or ((XSW65_ストッパ下降端 and not(pnlPBXSW65_ストッパ下降端)) or passXSW65_ストッパ下降端))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアEEmg=ON
	搬送コンベアEEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(not(SV53_ストッパ) and not(XSW63_ストッパ下降端) and not(pnlPBXSW63_ストッパ下降端),tim_notXSW63_ストッパ下降端, #20) '427.69ms
tmr(SV53_ストッパ and not(XSW64_ストッパ上昇端) and not(pnlPBXSW64_ストッパ上昇端), tim_notXSW64_ストッパ上昇端,#20) '385.93ms
tmr(not(SV54_ストッパ) and not(XSW65_ストッパ下降端) and not(pnlPBXSW65_ストッパ下降端),tim_notXSW65_ストッパ下降端,#20) '480.90ms
tmr(SV54_ストッパ and not(XSW66_ストッパ上昇端) and not(pnlPBXSW66_ストッパ上昇端),tim_notXSW66_ストッパ上昇端,#20) '520.00ms
tmr(not(SV55_リフト) and not(XSW67_リフト下降端) and not(pnlPBXSW67_リフト下降端),tim_notXSW67_リフト下降端, #30) '808.65ms
tmr(SV55_リフト and not(XSW68_リフト上昇端) and not(pnlPBXSW68_リフト上昇端), tim_notXSW68_リフト上昇端, #30) '597.04ms
tmr(not(SV56_ストッパ) and not(XSW69_ストッパ下降端) and not(pnlPBXSW69_ストッパ下降端),tim_notXSW69_ストッパ下降端, #20) '851.59ms
tmr(SV56_ストッパ and not(XSW70_ストッパ上昇端) and not(pnlPBXSW70_ストッパ上昇端),tim_notXSW70_ストッパ上昇端, #20) '598.55ms
tmr(not(SV44_リフト) and not(XSW53_リフト下降端) and not(pnlPBXSW53_リフト下降端), tim_notXSW53_リフト下降端,#30) '758.48ms
tmr(SV44_リフト and not(XSW54_リフト上昇端) and not(pnlPBXSW54_リフト上昇端),tim_notXSW54_リフト上昇端,#30) '921.66ms

'tmr(SV53_ストッパ and XSW63_ストッパ下降端,tim_XSW63_ストッパ下降端, #10) '427.69ms
if LDF(SV53_ストッパ) and XSW63_ストッパ下降端 and not(pnlPBXSW63_ストッパ下降端) then
	SET(tim_XSW63_ストッパ下降端)
end if
'tmr(not(SV53_ストッパ) and XSW64_ストッパ上昇端, tim_XSW64_ストッパ上昇端,#10) '385.93ms
if LDP(SV53_ストッパ) and XSW64_ストッパ上昇端 and not(pnlPBXSW64_ストッパ上昇端) then
	SET(tim_XSW64_ストッパ上昇端)
end if
'tmr(SV54_ストッパ and XSW65_ストッパ下降端,tim_XSW65_ストッパ下降端,#10) '480.90ms
if LDF(SV54_ストッパ) and XSW65_ストッパ下降端 and not(pnlPBXSW65_ストッパ下降端) then
	SET(tim_XSW65_ストッパ下降端)
end if
'tmr(not(SV54_ストッパ) and XSW66_ストッパ上昇端,tim_XSW66_ストッパ上昇端,#10) '520.00ms
if LDP(SV54_ストッパ) and XSW66_ストッパ上昇端 and not(pnlPBXSW66_ストッパ上昇端) then
	SET(tim_XSW66_ストッパ上昇端)
end if
'tmr(SV55_リフト and XSW67_リフト下降端,tim_XSW67_リフト下降端, #10) '808.65ms
if LDF(SV55_リフト) and XSW67_リフト下降端 and not(pnlPBXSW67_リフト下降端) then
	SET(tim_XSW67_リフト下降端)
end if
'tmr(not(SV55_リフト) and XSW68_リフト上昇端, tim_XSW68_リフト上昇端, #10) '597.04ms
if LDP(SV55_リフト) and XSW68_リフト上昇端 and not(pnlPBXSW68_リフト上昇端) then
	SET(tim_XSW68_リフト上昇端)
end if
'tmr(SV56_ストッパ and XSW69_ストッパ下降端,tim_XSW69_ストッパ下降端, #10) '851.59ms
if LDF(SV56_ストッパ) and XSW69_ストッパ下降端 and not(pnlPBXSW69_ストッパ下降端) then
	SET(tim_XSW69_ストッパ下降端)
end if
'tmr(not(SV56_ストッパ) and XSW70_ストッパ上昇端,tim_XSW70_ストッパ上昇端, #10) '598.55ms
if LDP(SV56_ストッパ) and XSW70_ストッパ上昇端 and not(pnlPBXSW70_ストッパ上昇端) then
	SET(tim_XSW70_ストッパ上昇端)
end if
'tmr(SV44_リフト and XSW53_リフト下降端, tim_XSW53_リフト下降端,#10) '758.48ms
if LDF(SV44_リフト) and XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端) then
	SET(tim_XSW53_リフト下降端)
end if
'tmr(not(SV44_リフト) and XSW54_リフト上昇端,tim_XSW54_リフト上昇端,#10) '921.66ms
if LDP(SV44_リフト) and XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端) then
	SET(tim_XSW54_リフト上昇端)
end if

'passtimXSW63_ストッパ下降端_val=#427
tms(not(SV53_ストッパ),passtimXSW63_ストッパ下降端, passtimXSW63_ストッパ下降端_val) 

'passtimXSW64_ストッパ上昇端_val=#385
tms(SV53_ストッパ, passtimXSW64_ストッパ上昇端,passtimXSW64_ストッパ上昇端_val) 

'passtimXSW65_ストッパ下降端_val=#480
tms(not(SV54_ストッパ),passtimXSW65_ストッパ下降端,passtimXSW65_ストッパ下降端_val) 

'passtimXSW66_ストッパ上昇端_val=#520
tms(SV54_ストッパ,passtimXSW66_ストッパ上昇端,passtimXSW66_ストッパ上昇端_val) 

'passtimXSW53_リフト下降端_val=#758
tms(not(SV44_リフト), passtimXSW53_リフト下降端,passtimXSW53_リフト下降端_val) 

'passtimXSW54_リフト上昇端_val=#921
tms(SV44_リフト,passtimXSW54_リフト上昇端,passtimXSW54_リフト上昇端_val) 

tmr(mMC23_モータローラ and not(pauseMC23_モータローラ) and not(EmgMC23_モータローラ),timerr_MC23_モータローラ,#150)
tmr(mMC25_搬送モータ and not(pauseMC25_搬送モータ) and not(EmgMC25_搬送モータ),timerr_MC25_搬送モータ,#152)
tmr(mMC26_搬送モータ and not(pauseMC26_搬送モータ) and not(EmgMC26_搬送モータ),timerr_MC26_搬送モータ,#154)
tmr(mMC27_モータローラ and not(pauseMC27_モータローラ) and not(EmgMC27_モータローラ),timerr_MC27_モータローラ,#156)

if LDP(timerr_MC23_モータローラ.B) then
	almMC23_モータローラ=ON
	
	mMC23_モータローラ=OFF
	mMC25_搬送モータ=OFF
	mMC26_搬送モータ=OFF
	mMC27_モータローラ=OFF
	
	コンベア一時停止=ON
else if LDP(timerr_MC25_搬送モータ.B) then
	almMC25_搬送モータ=ON
	
	mMC23_モータローラ=OFF
	mMC25_搬送モータ=OFF
	mMC26_搬送モータ=OFF
	mMC27_モータローラ=OFF
	
	コンベア一時停止=ON

else if LDP(timerr_MC26_搬送モータ.B) then
	almMC26_搬送モータ=ON

	mMC23_モータローラ=OFF
	mMC25_搬送モータ=OFF
	mMC26_搬送モータ=OFF
	mMC27_モータローラ=OFF
	
	コンベア一時停止=ON

else if LDP(timerr_MC27_モータローラ.B) then
	almMC27_モータローラ=ON
	
	mMC23_モータローラ=OFF
	mMC25_搬送モータ=OFF
	mMC26_搬送モータ=OFF
	mMC27_モータローラ=OFF
	
	コンベア一時停止=ON

end if

if (ldp(tim_XSW63_ストッパ下降端.B) or ldp(tim_notXSW63_ストッパ下降端.B)) and not(pnlPBXSW63_ストッパ下降端)then
	almXSW63_ストッパ下降端=ON
	pnlPBXSW63_ストッパ下降端=ON
	if tim_XSW63_ストッパ下降端 then
		res(tim_XSW63_ストッパ下降端)
	end if
	搬送コンベアEErrStep=1

else if (ldp(tim_XSW64_ストッパ上昇端.B) or ldp(tim_notXSW64_ストッパ上昇端.B)) and not(pnlPBXSW64_ストッパ上昇端)then
	pauseSV53_ストッパ=ON
	almXSW64_ストッパ上昇端=ON
	pnlPBXSW64_ストッパ上昇端=ON
	if tim_XSW64_ストッパ上昇端 then
		res(tim_XSW64_ストッパ上昇端)
	end if
	搬送コンベアEErrStep=1

else if (ldp(tim_XSW65_ストッパ下降端.B) or ldp(tim_notXSW65_ストッパ下降端.B)) and not(pnlPBXSW65_ストッパ下降端)then
	almXSW65_ストッパ下降端=ON
	pnlPBXSW65_ストッパ下降端=ON
	if tim_XSW65_ストッパ下降端 then
		res(tim_XSW65_ストッパ下降端)
	end if
	搬送コンベアEErrStep=1

else if (ldp(tim_XSW66_ストッパ上昇端.B) or ldp(tim_notXSW66_ストッパ上昇端.B)) and not(pnlPBXSW66_ストッパ上昇端)then
	pauseSV54_ストッパ=ON
	almXSW66_ストッパ上昇端=ON
	pnlPBXSW66_ストッパ上昇端=ON
	if tim_XSW66_ストッパ上昇端 then
		res(tim_XSW66_ストッパ上昇端)
	end if
	搬送コンベアEErrStep=1

else if 搬送コンベアE動作中 and not(搬送コンベアF動作中) and (ldp(tim_XSW68_リフト上昇端.B) or ldp(tim_notXSW68_リフト上昇端.B)) and not(pnlPBXSW68_リフト上昇端) then
	pauseSV55_リフト=ON
	almXSW68_リフト上昇端=ON
	pnlPBXSW68_リフト上昇端=ON
	if tim_XSW68_リフト上昇端 then
		res(tim_XSW68_リフト上昇端)
	end if
	搬送コンベアEErrStep=1

else if 搬送コンベアE動作中 and not(搬送コンベアF動作中) and (ldp(tim_XSW67_リフト下降端.B) or ldp(tim_notXSW67_リフト下降端.B)) and not(pnlPBXSW67_リフト下降端) then
	almXSW67_リフト下降端=ON
	pnlPBXSW67_リフト下降端=ON
	if tim_XSW67_リフト下降端 then
		res(tim_XSW67_リフト下降端)
	end if
	搬送コンベアEErrStep=1

else if 搬送コンベアE動作中 and not(搬送コンベアF動作中) and (ldp(tim_XSW69_ストッパ下降端.B) or ldp(tim_notXSW69_ストッパ下降端.B)) and not(pnlPBXSW69_ストッパ下降端) then
	almXSW69_ストッパ下降端=ON
	pnlPBXSW69_ストッパ下降端=ON
	if tim_XSW69_ストッパ下降端 then
		res(tim_XSW69_ストッパ下降端)
	end if
	搬送コンベアEErrStep=1

else if 搬送コンベアE動作中 and not(搬送コンベアF動作中) and (ldp(tim_XSW70_ストッパ上昇端.B) or ldp(tim_notXSW70_ストッパ上昇端.B)) and not(pnlPBXSW70_ストッパ上昇端) then
	pauseSV56_ストッパ=ON
	almXSW70_ストッパ上昇端=ON
	pnlPBXSW70_ストッパ上昇端=ON
	if tim_XSW70_ストッパ上昇端 then
		res(tim_XSW70_ストッパ上昇端)
	end if
	搬送コンベアEErrStep=1

else if (ldp(tim_XSW53_リフト下降端.B) or ldp(tim_notXSW53_リフト下降端.B)) and not(pnlPBXSW53_リフト下降端) then
	almXSW53_リフト下降端=ON
	pnlPBXSW53_リフト下降端=ON
	if tim_XSW53_リフト下降端 then
		res(tim_XSW53_リフト下降端)
	end if
	搬送コンベアDErrStep=1

else if (ldp(tim_XSW54_リフト上昇端.B) or ldp(tim_notXSW54_リフト上昇端.B)) and not(pnlPBXSW54_リフト上昇端) then
	pauseSV44_リフト=ON
	almXSW54_リフト上昇端=ON
	pnlPBXSW54_リフト上昇端=ON
	if tim_XSW54_リフト上昇端 then
		res(tim_XSW54_リフト上昇端)
	end if
	搬送コンベアDErrStep=1


end if

tmr(not(PH29_釜検知),timnotdly_PH29_釜検知,3)
tmr(not(PH30_フタ検知),timnotdly_PH30_フタ検知,3)


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアEEmgStep	自動モード セレクトスイッチ
'System :: 搬送コンベアEAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアEEmg	その場停止


if 搬送コンベアEEmgStep=0 then  
	
	if 搬送コンベアEErrStep=0  then

	if not(コンベア一時停止) then

	if not(搬送コンベアEOrgErr) then

	if (搬送コンベアEAutoMode and 自動搬送AutoMode ) or 搬送コンベアEstep<>0 then
	
		if ManualInite=1 then
			mSV53_ストッパ=ON
			mSV54_ストッパ=ON

			if PH36_釜検知 or PH37_フタ検知 then
				搬送コンベアE動作中=OFF '排出動作時の動作中信号OFF
				搬送コンベアE排出要求=ON
				搬送コンベアEstep=1
			end if
			

			ManualInite=0
		end if
		
	
		if not(搬送コンベアEAutoMode and 自動搬送AutoMode ) then
			搬送コンベアEAutoRun=OFF
		end if
	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアEstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアEAutoRun then
				inc(搬送コンベアEstep)
			else 
				搬送コンベアEstep=0 '終了待機
			end if
		
		case 2
			if PH36_釜検知 or PH37_フタ検知 then
				搬送コンベアE排出要求=ON
				搬送コンベアEstep=1
			else
				inc(搬送コンベアEstep)

			end if				
		
		case 3
		' [ 次の搬送コンベア停止確認 ]
			if (搬送コンベアE排出要求=OFF and 搬送コンベアF動作中=OFF and not(コンベアF釜排出待機) and not(mMC22_搬送モータ逆転)) or 搬送コンベアD排出要求 then
				if MC21_搬送モータ正転 and not(MC22_搬送モータ正転) then
					搬送コンベアEstep=1
				else 			
					inc(搬送コンベアEstep)
				end if
			else
				搬送コンベアEstep=1
			end if
		
		case 4
			if not(PH29_釜検知) and timnotdly_PH29_釜検知 and not(PH30_フタ検知) and timnotdly_PH30_フタ検知 then
				if not(PH32_釜検知) and not(PH33_フタ検知) then
					if not(PH34_釜検知) and not(PH35_フタ検知) then
						搬送コンベアD排出要求=OFF
						搬送コンベアEstep=1
					else
						inc(搬送コンベアEstep)
					end if
				else
					inc(搬送コンベアEstep)
				end if
			else
				inc(搬送コンベアEstep)
			end if
			
		case 5  '原点検出
			if 搬送コンベアEOrg then
				errpassコンベア一時停止=OFF			
				inc(搬送コンベアEstep)
			else
				搬送コンベアEstep=1
			end if
				
		case 6 		 
			if 搬送コンベアE排出要求=OFF and 搬送コンベアF動作中=OFF and not(コンベアF釜排出待機) then
				inc(搬送コンベアEstep)
			else if 搬送コンベアD排出要求 then
				搬送コンベアE動作中=ON
				搬送コンベアEstep=200
			end if
			
		case 7
			if PH34_釜検知 or PH35_フタ検知 then
				搬送コンベアE動作中=ON
				搬送コンベアEstep=100
			else if 搬送コンベアD排出要求 then
				搬送コンベアE動作中=ON
				搬送コンベアEstep=200			
			else
				搬送コンベアEstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		' 搬送コンベアE排出
		'--------------------------------------------------------------------------------------------------------------	
		case 100		
			'搬送コンベアDリフト
			PH29_釜起動検知=OFF
			PH30_フタ起動検知=OFF
			'待機1
			PH32_釜起動検知=OFF
			PH33_フタ起動検知=OFF
			'待機2
			PH34_釜起動検知=OFF
			PH35_フタ起動検知=OFF
			
			tim_procstep_val=0 '釜フタ検出時間
			res(tim_procstep)
			
			inc(搬送コンベアEstep)
			
		case 101
			if not(MC21_搬送モータ正転) then
				'搬送コンベアDリフト
				PH29_釜起動検知=PH29_釜起動検知 or PH29_釜検知
				PH30_フタ起動検知=PH30_フタ起動検知 or PH30_フタ検知
			end if
			
			'待機1
			PH32_釜起動検知=PH32_釜起動検知 or PH32_釜検知
			PH33_フタ起動検知=PH33_フタ起動検知 or PH33_フタ検知
			'待機2
			PH34_釜起動検知=PH34_釜起動検知 or PH34_釜検知
			PH35_フタ起動検知=PH35_フタ起動検知 or PH35_フタ検知

			if tim_procstep.B then
				inc(搬送コンベアEstep)
			end if		

		
		case 102
			mSV56_ストッパ=ON '上昇
			mSV55_リフト=ON '上昇
			inc(搬送コンベアEstep)
			
		case 103
			if (XSW68_リフト上昇端 and not(pnlPBXSW68_リフト上昇端)) or passXSW68_リフト上昇端 then
				if (XSW70_ストッパ上昇端 and not(pnlPBXSW70_ストッパ上昇端)) or passXSW70_ストッパ上昇端 then
					inc(搬送コンベアEstep)
				end if
			end if
		
		case 104
			tim_procstep_val=0
			res(tim_procstep)
			MC27_モータローラstep=1
			inc(搬送コンベアEstep)
			
		case 105
			if tim_procstep.B then
				if PH32_釜検知 or PH33_フタ検知 or PH34_釜検知 or PH35_フタ検知 then
					tim_procstep_val=10
					res(tim_procstep)
					MC26_搬送モータstep=1
				end if
				inc(搬送コンベアEstep)
			end if
			
		case 106
			if tim_procstep.B then
				if PH29_釜起動検知 or PH30_フタ起動検知 or PH32_釜検知 or PH33_フタ検知 then
					tim_procstep_val=10
					res(tim_procstep)
					MC25_搬送モータstep=1
				end if
				inc(搬送コンベアEstep)
			end if		


		case 107
			if tim_procstep.B then
				MC23_モータローラstep=1
				inc(搬送コンベアEstep)
			end if		
	
		case 108
			if MC23_モータローラstep=0 and MC25_搬送モータstep=0 and MC26_搬送モータstep=0 and MC27_モータローラstep=0 then
				StageDevice24=StageDevice23
				StageDevice23=StageDevice21			
				inc(搬送コンベアEstep)
			end if

		case 109
			mSV56_ストッパ=OFF '下降
			搬送コンベアE動作中=OFF
			inc(搬送コンベアEstep)

		case 110
			if (XSW69_ストッパ下降端 and not(pnlPBXSW69_ストッパ下降端)) or passXSW69_ストッパ下降端 then
				inc(搬送コンベアEstep)
			end if

		case 111
			搬送コンベアE動作中=OFF '排出動作時の動作中信号OFF
			搬送コンベアE排出要求=ON
			搬送コンベアEstep=1

		'--------------------------------------------------------------------------------------------------------------
		' 搬送コンベアE供給（搬送コンベアD排出要求処理)
		'--------------------------------------------------------------------------------------------------------------	
		case 200
		
			'搬送コンベアDリフト
			PH29_釜起動検知=OFF
			PH30_フタ起動検知=OFF
			'待機1
			PH32_釜起動検知=OFF
			PH33_フタ起動検知=OFF
			'待機2
			PH34_釜起動検知=OFF
			PH35_フタ起動検知=OFF
			
			tim_procstep_val=0
			res(tim_procstep)
			
			inc(搬送コンベアEstep)
			
		case 201
			if not(MC21_搬送モータ正転) then
				'搬送コンベアDリフト
				PH29_釜起動検知=PH29_釜起動検知 or PH29_釜検知
				PH30_フタ起動検知=PH30_フタ起動検知 or PH30_フタ検知
			end if
			
			'待機1
			PH32_釜起動検知=PH32_釜起動検知 or PH32_釜検知
			PH33_フタ起動検知=PH33_フタ起動検知 or PH33_フタ検知
			'待機2
			PH34_釜起動検知=PH34_釜起動検知 or PH34_釜検知
			PH35_フタ起動検知=PH35_フタ起動検知 or PH35_フタ検知

			if tim_procstep.B then
				inc(搬送コンベアEstep)
			end if		
		
		case 202
			'待機1空き,待機2空き
			if not(PH32_釜起動検知) and not(PH33_フタ起動検知) and not(PH34_釜起動検知) and not(PH35_フタ起動検知) then 
				搬送コンベアEstep=230
			'待機1空き
			else if (not(PH32_釜起動検知) and not(PH33_フタ起動検知)) and (PH34_釜起動検知 or PH35_フタ起動検知) then
				搬送コンベアEstep=250		
			'待機空きなし 排出待ち
			else if (PH32_釜起動検知 or PH33_フタ起動検知) and (not(PH34_釜起動検知) and not(PH35_フタ起動検知)) then
				搬送コンベアEstep=280
				
			else if  (PH32_釜起動検知 or PH33_フタ起動検知) and (PH34_釜起動検知 or PH35_フタ起動検知) then
			
				搬送コンベアE排出要求=ON
				搬送コンベアE動作中=OFF
				搬送コンベアEstep=1			
			end if
		

		'----------------------
		'待機2に移動
		'----------------------
		case 230
			mSV44_リフト=ON
			mSV53_ストッパ=OFF
			mSV54_ストッパ=ON

			MC23_モータローラstep=1
			mMC25_搬送モータ=ON
			mMC26_搬送モータ=ON
			errpassコンベア一時停止=OFF

			inc(搬送コンベアEstep)

		case 231
			if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
				if (XSW63_ストッパ下降端 and not(pnlPBXSW63_ストッパ下降端)) or passXSW63_ストッパ下降端 then
					if (XSW66_ストッパ上昇端 and not(pnlPBXSW66_ストッパ上昇端))  or passXSW66_ストッパ上昇端 then
						inc(搬送コンベアEstep)
					end if
				end if	
			end if
		
		case 232
			inc(搬送コンベアEstep)

		case 233
			if errpassコンベア一時停止 then
				inc(搬送コンベアEstep)
			
			else if not(PH29_釜検知) and timnotdly_PH29_釜検知 and not(PH30_フタ検知) and timnotdly_PH30_フタ検知 then
				inc(搬送コンベアEstep)
			end if
				
		case 234
			if errpassコンベア一時停止 then
				inc(搬送コンベアEstep)
			
			else if PH34_釜検知 or PH35_フタ検知 then
				inc(搬送コンベアEstep)
			end if
		
		case 235
			tim_procstep_val=20
			res(tim_procstep)
			inc(搬送コンベアEstep)
		
		case 236
			if tim_procstep.B then
				inc(搬送コンベアEstep)
			end if
		
		case 237
			mMC25_搬送モータ=OFF
			mMC26_搬送モータ=OFF
			mSV53_ストッパ=ON
			inc(搬送コンベアEstep)
		
		case 238
			if MC23_モータローラstep=0 then
				inc(搬送コンベアEstep)
			end if
		
		case 239
			if (XSW64_ストッパ上昇端 and not(pnlPBXSW64_ストッパ上昇端)) or passXSW64_ストッパ上昇端 then
				inc(搬送コンベアEstep)
			end if
		
		case 240
			StageDevice24=StageDevice21
			StageDevice23=0

			搬送コンベアD排出要求=OFF
			搬送コンベアE排出要求=ON
			搬送コンベアE動作中=OFF
			搬送コンベアEstep=1

		
		'----------------------
		'待機1に移動
		'----------------------
		case 250
			mSV44_リフト=ON
			mSV53_ストッパ=ON
			mSV54_ストッパ=ON
			
			MC23_モータローラstep=1
			mMC25_搬送モータ=ON
			errpassコンベア一時停止=OFF
			
			inc(搬送コンベアEstep)

		case 251
			if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
				if (XSW64_ストッパ上昇端 and not(pnlPBXSW64_ストッパ上昇端)) or passXSW64_ストッパ上昇端 then
					if (XSW66_ストッパ上昇端 and not(pnlPBXSW66_ストッパ上昇端)) or passXSW66_ストッパ上昇端 then
						inc(搬送コンベアEstep)
					end if
				end if
			end if
			
		case 252
			inc(搬送コンベアEstep)

		case 253
			if errpassコンベア一時停止 then
				inc(搬送コンベアEstep)
			
			else if not(PH29_釜検知) and timnotdly_PH29_釜検知 and not(PH30_フタ検知) and timnotdly_PH30_フタ検知 then
				inc(搬送コンベアEstep)
			end if
				
		case 254
			if errpassコンベア一時停止 then
				inc(搬送コンベアEstep)
			
			else if PH32_釜検知 or PH33_フタ検知 then
				inc(搬送コンベアEstep)
			end if
		
		case 255
			tim_procstep_val=20
			res(tim_procstep)
			inc(搬送コンベアEstep)
		
		case 256
			if tim_procstep.B then
				inc(搬送コンベアEstep)
			end if
		
		case 257
			mMC25_搬送モータ=OFF
			inc(搬送コンベアEstep)
		
		case 258
			if MC23_モータローラstep=0 and MC25_搬送モータstep=0 then
				inc(搬送コンベアEstep)
			end if
		
		case 259
			StageDevice23=StageDevice21			
			搬送コンベアE動作中=OFF
			搬送コンベアD排出要求=OFF
			搬送コンベアE排出要求=ON
			inc(搬送コンベアEstep)
			
		case 260
			if (XSW64_ストッパ上昇端 and not(pnlPBXSW64_ストッパ上昇端)) or passXSW64_ストッパ上昇端 then
				inc(搬送コンベアEstep)
			end if
		
		case 261
			搬送コンベアEstep=1
			
		'----------------------
		'待機2に移動
		'----------------------
		case 280
			mSV44_リフト=ON
			mSV54_ストッパ=ON

			mMC26_搬送モータ=ON
			errpassコンベア一時停止=OFF
			inc(搬送コンベアEstep)
			
		case 281
			if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
				if (XSW66_ストッパ上昇端 and not(pnlPBXSW66_ストッパ上昇端)) or passXSW66_ストッパ上昇端 then
					inc(搬送コンベアEstep)
				end if
			end if
			
		case 282
			SV53_ストッパstep=1
			inc(搬送コンベアEstep)
		
		case 283
			tim_procstep_val=10
			res(tim_procstep)
			inc(搬送コンベアEstep)
		
		case 284
			if tim_procstep.B then
				inc(搬送コンベアEstep)
			end if
		
		case 285
			MC25_搬送モータstep=1
			inc(搬送コンベアEstep)
		
		case 286
			tim_procstep_val=10
			res(tim_procstep)
			inc(搬送コンベアEstep)
		
		case 287
			if tim_procstep.B then
				inc(搬送コンベアEstep)
			end if

		case 288
			MC23_モータローラstep=1
			inc(搬送コンベアEstep)

		case 289
			if MC23_モータローラstep=0 and MC25_搬送モータstep=0 and SV53_ストッパstep=0 then
				inc(搬送コンベアEstep)
			end if
		
		case 290
			mMC26_搬送モータ=OFF
			inc(搬送コンベアEstep)
		
		case 291
			StageDevice24=StageDevice23						
			StageDevice23=StageDevice21			
			搬送コンベアE動作中=OFF
			搬送コンベアD排出要求=OFF
			搬送コンベアE排出要求=ON
			搬送コンベアEstep=1

		end select

	
	'-----------------------------------------------------------------
	' 搬送モータ、ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	'リフト
	'mMC23_モータローラ
	'PH29_釜起動検知=PH29_釜検知
	'PH30_フタ起動検知=PH30_フタ検知
	
	'mMC25_搬送モータ	mSV53_ストッパ
	'PH32_釜起動検知=PH32_釜検知
	'PH33_フタ起動検知=PH33_フタ検知
	
	'mMC26_搬送モータ	mSV54_ストッパ
	'PH34_釜起動検知=PH34_釜検知
	'PH35_フタ起動検知=PH35_フタ検知
	
	'mMC27_モータローラ mSV55_リフト mSV56_ストッパ
	'PH36_釜起動検知=PH36_釜検知
	'PH37_フタ起動検知=PH37_フタ検知
	'-----------------------------------------------------------------
	tmr(tim_SV53_ストッパ,tim_SV53_ストッパ_val)
	select case SV53_ストッパstep
	case 0
	
	case 1
		inc(SV53_ストッパstep)

	case 2
		if PH29_釜起動検知 or PH30_フタ起動検知 or PH32_釜検知 or PH33_フタ検知 then
			mSV53_ストッパ=OFF
			inc(SV53_ストッパstep)
		else
			SV53_ストッパstep=0 '終了
		end if

	case 3
		if (XSW63_ストッパ下降端 and not(pnlPBXSW63_ストッパ下降端)) or passXSW63_ストッパ下降端 then
			inc(SV53_ストッパstep)
		end if

	case 4
		if errpassコンベア一時停止 then
			inc(SV53_ストッパstep)

		else if not(PH32_釜検知) and not(PH33_フタ検知) then
			tim_SV53_ストッパ_val=20
			res(tim_SV53_ストッパ)
			inc(SV53_ストッパstep)
		end if

	case 5	
		if errpassコンベア一時停止 then
			inc(SV53_ストッパstep)

		else if PH32_釜起動検知 or PH33_フタ起動検知 then
			if PH34_釜検知 or PH35_フタ検知 then
				set(tim_SV53_ストッパ)
				inc(SV53_ストッパstep)
			end if
		else
			inc(SV53_ストッパstep)
		end if

	case 6
		if errpassコンベア一時停止 then
			inc(SV53_ストッパstep)

		else if PH29_釜起動検知 and PH30_フタ起動検知 then
			if tim_SV53_ストッパ.B or PH32_釜検知 or PH33_フタ検知 then
				set(tim_SV53_ストッパ)
				inc(SV53_ストッパstep)
			end if
		else
			tim_SV53_ストッパ_val=10 '20
			res(tim_SV53_ストッパ)
			inc(SV53_ストッパstep)
		end if
	
			
	case 7
		if tim_SV53_ストッパ.B then
			inc(SV53_ストッパstep)
		end if
	
	case 8
		mSV53_ストッパ=ON
		inc(SV53_ストッパstep)
	
	case 9
		if (XSW64_ストッパ上昇端 and not(pnlPBXSW64_ストッパ上昇端)) or passXSW64_ストッパ上昇端 then
			inc(SV53_ストッパstep)
		end if	
	
	case 10
		SV53_ストッパstep=0
	
	end select
	'-----------------------------------------------------------------
	'MC23_モータローラ
	tmr(tim_MC23_モータローラ,tim_MC23_モータローラ_val)
	
	select case MC23_モータローラstep
	case 0
	case 1	
		inc(MC23_モータローラstep)

	case 2
		if PH29_釜起動検知 or PH30_フタ起動検知 then
			inc(MC23_モータローラstep)
		else
			搬送コンベアD排出要求=OFF
			搬送コンベアE動作中=OFF
			MC23_モータローラstep=0
		end if

	case 3
		mSV44_リフト=ON '上昇
		inc(MC23_モータローラstep)

	case 4
		if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
			inc(MC23_モータローラstep)
		end if
		
	case 5
		mMC23_モータローラ=ON
		errpassコンベア一時停止=OFF
		inc(MC23_モータローラstep)

	case 6
		if errpassコンベア一時停止 then
			inc(MC23_モータローラstep)		
		
		else if not(PH29_釜検知) and timnotdly_PH29_釜検知 and not(PH30_フタ検知) and timnotdly_PH30_フタ検知 then
			inc(MC23_モータローラstep)		
		end if
	
	case 7
		if errpassコンベア一時停止 then
			inc(MC23_モータローラstep)		
		else if PH29_釜起動検知 or PH30_フタ起動検知 then
			if PH32_釜検知 or PH33_フタ検知 then
				inc(MC23_モータローラstep)
			end if
		end if
	
	case 8
		tim_MC23_モータローラ_val=0
		res(tim_MC23_モータローラ)
		inc(MC23_モータローラstep)

	case 9
		if tim_MC23_モータローラ.B then
			inc(MC23_モータローラstep)
		end if
	
	case 10
		mMC23_モータローラ=OFF
		mSV44_リフト=OFF '下降
		inc(MC23_モータローラstep)
	
	case 11
		if (XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端 then
			inc(MC23_モータローラstep)
		end if
	
	case 12
		搬送コンベアD排出要求=OFF
		搬送コンベアE動作中=OFF
		MC23_モータローラstep=0
	
	end select
	
	'--------------------------------------------
	'MC25_搬送モータ
	tmr(tim_MC25_搬送モータ,tim_MC25_搬送モータ_val)
	select case MC25_搬送モータstep
	case 0
	case 1
		inc(MC25_搬送モータstep)

	case 2
		if PH29_釜起動検知 or PH30_フタ起動検知 or PH32_釜検知 or PH33_フタ検知 then
			inc(MC25_搬送モータstep)
		else
			MC25_搬送モータstep=0
		end if

	case 3
		SV53_ストッパstep=1
		inc(MC25_搬送モータstep)
	
	case 4
		if SV53_ストッパstep=0 or (not(mSV53_ストッパ) and ( (XSW63_ストッパ下降端 and not(pnlPBXSW63_ストッパ下降端)) or passXSW63_ストッパ下降端)) then
			inc(MC25_搬送モータstep)
		end if

	case 5
		mMC25_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC25_搬送モータstep)

	case 6
		tim_MC25_搬送モータ_val=10
		res(tim_MC25_搬送モータ)
		inc(MC25_搬送モータstep)
	
	case 7
		if tim_MC25_搬送モータ.B then
			inc(MC25_搬送モータstep)
		end if		
	
	case 8
		if MC23_モータローラstep=0 then
			MC23_モータローラstep=1
		end if
		inc(MC25_搬送モータstep)

	case 9
		if errpassコンベア一時停止 then
			inc(MC25_搬送モータstep)		
		
		else if not(PH32_釜検知) and  not(PH33_フタ検知)  then
			inc(MC25_搬送モータstep)		
		end if

	case 10
		if errpassコンベア一時停止 then
			inc(MC25_搬送モータstep)		
		
		else if PH29_釜起動検知 or PH30_フタ起動検知 then
			if PH32_釜検知 or PH33_フタ検知 then
				inc(MC25_搬送モータstep)
			end if
		else if PH32_釜起動検知 or PH33_フタ起動検知 then
			if PH34_釜検知 or PH35_フタ検知 then
				inc(MC25_搬送モータstep)
			end if
		end if
	
	case 11
		tim_MC25_搬送モータ_val=10
		res(tim_MC25_搬送モータ)
		inc(MC25_搬送モータstep)

	case 12
		if tim_MC25_搬送モータ.B then
			inc(MC25_搬送モータstep)
		end if
	
	case 13
		mMC25_搬送モータ=OFF
		inc(MC25_搬送モータstep)
	
	case 14
		if  SV53_ストッパstep=0 and MC23_モータローラstep=0 then
			inc(MC25_搬送モータstep)
		end if
	
	case 15
		MC25_搬送モータstep=0

	
	end select
	'--------------------------------------------
	tmr(tim_SV54_ストッパ, tim_SV54_ストッパ_val)
	select case SV54_ストッパstep
	case 0
	case 1
		if PH32_釜検知 or PH33_フタ検知 or PH34_釜検知 or PH35_フタ検知 then
			mSV54_ストッパ=OFF
			inc(SV54_ストッパstep)
		else
			SV54_ストッパstep=0 '終了
		end if

	case 2
		if (XSW65_ストッパ下降端 and not(pnlPBXSW65_ストッパ下降端)) or passXSW65_ストッパ下降端 then
			inc(SV54_ストッパstep)
		end if

	case 3
		if errpassコンベア一時停止 then
			inc(SV54_ストッパstep)
		
		else if not(PH32_釜検知) and not(PH33_フタ検知) and not(PH34_釜検知) and not(PH35_フタ検知) then
			tim_SV54_ストッパ_val=20
			res(tim_SV54_ストッパ)
			inc(SV54_ストッパstep)
		end if

	case 4
		if errpassコンベア一時停止 then
			inc(SV54_ストッパstep)
		
		else if PH32_釜起動検知 and PH33_フタ起動検知 then
			if tim_SV54_ストッパ.B or PH34_釜検知 or PH35_フタ検知 then
				tim_SV54_ストッパ_val=0
				res(tim_SV54_ストッパ)
				inc(SV54_ストッパstep)
			end if
		else if PH34_釜起動検知 or PH35_フタ起動検知 then
			if PH36_釜検知 or PH37_フタ検知 then
				tim_SV54_ストッパ_val=20
				res(tim_SV54_ストッパ)
				inc(SV54_ストッパstep)
			end if
		else
			inc(SV54_ストッパstep)
		end if

	case 5
		if tim_SV54_ストッパ.B then
			inc(SV54_ストッパstep)
		end if	

	case 6
		mSV54_ストッパ=ON
		inc(SV54_ストッパstep)
	
	case 7
		if (XSW66_ストッパ上昇端 and not(pnlPBXSW66_ストッパ上昇端)) or passXSW66_ストッパ上昇端 then
			inc(SV54_ストッパstep)
		end if	
	
	case 8
		SV54_ストッパstep=0
	
	end select
	'--------------------------------------------
	'MC26_搬送モータ
	tmr(tim_MC26_搬送モータ,tim_MC26_搬送モータ_val)
	select case MC26_搬送モータstep
	case 0
	case 1
		inc(MC26_搬送モータstep)

	case 2
		if PH32_釜検知 or PH33_フタ検知 or PH34_釜検知 or PH35_フタ検知 then
			inc(MC26_搬送モータstep)
		else
			MC26_搬送モータstep=0
		end if

	case 3
		SV54_ストッパstep=1
		inc(MC26_搬送モータstep)

	case 4
		if SV54_ストッパstep=0 or (not(mSV54_ストッパ) and ( (XSW65_ストッパ下降端 and not(pnlPBXSW65_ストッパ下降端)) or passXSW65_ストッパ下降端)) then
			inc(MC26_搬送モータstep)
		 end if
		
	case 5
		MC25_搬送モータstep=1
		mMC26_搬送モータ=ON
		inc(MC26_搬送モータstep)

	case 6
		if errpassコンベア一時停止 then
			inc(MC26_搬送モータstep)		
		
		else if  not(PH32_釜検知) and  not(PH33_フタ検知) and not(PH34_釜検知) and not(PH35_フタ検知) then
			inc(MC26_搬送モータstep)		
		end if

	case 7
		if errpassコンベア一時停止 then
			inc(MC26_搬送モータstep)		
		
		else if PH32_釜起動検知 or PH33_フタ起動検知 then
			if PH34_釜検知 or PH35_フタ検知 then
				inc(MC26_搬送モータstep)
			end if
		else if PH34_釜起動検知 or PH35_フタ起動検知 then
			if PH36_釜検知 or PH37_フタ検知 then
				inc(MC26_搬送モータstep)
			end if
		end if
	
	case 8
		tim_MC26_搬送モータ_val=25
		res(tim_MC26_搬送モータ)
		inc(MC26_搬送モータstep)

	case 9
		if tim_MC26_搬送モータ.B then
			inc(MC26_搬送モータstep)
		end if
	
	case 10
		mMC26_搬送モータ=OFF
		inc(MC26_搬送モータstep)
	
	case 11
		MC26_搬送モータstep=0

	
	end select

	'--------------------------------------------
	'MC27_モータローラ
	tmr(tim_MC27_モータローラ,tim_MC27_モータローラ_val)
	select case MC27_モータローラstep
	case 0
	case 1
		inc(MC27_モータローラstep)

	case 2
		if PH34_釜検知 or PH35_フタ検知 then
			inc(MC27_モータローラstep)
		else
			MC27_モータローラstep=0
		end if
	
	case 3
		mMC27_モータローラ=ON
		errpassコンベア一時停止=OFF
		inc(MC27_モータローラstep)

	case 4
		if errpassコンベア一時停止 then
			inc(MC27_モータローラstep)		
		
		else if not(PH34_釜検知) and not(PH35_フタ検知) then
			inc(MC27_モータローラstep)		
		end if
	
	case 5
		if errpassコンベア一時停止 then
			inc(MC27_モータローラstep)		
		
		else if PH34_釜起動検知 or PH35_フタ起動検知 then
			if PH36_釜検知 or PH37_フタ検知 then
				inc(MC27_モータローラstep)
			end if
		end if
	
	case 6
		tim_MC27_モータローラ_val=30
		res(tim_MC27_モータローラ)
		inc(MC27_モータローラstep)

	case 7
		if tim_MC27_モータローラ.B then
			inc(MC27_モータローラstep)
		end if
	
	case 8
		mMC27_モータローラ=OFF
		inc(MC27_モータローラstep)
	
	case 9
		StageDevice25=StageDevice24
	
'		搬送コンベアE動作中=OFF '排出動作時の動作中信号OFF
'		搬送コンベアE排出要求=ON
		MC27_モータローラstep=0
	
	end select
	'-----------------------------------------------------------------




	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
	
		if ManualInite=0 then
			mSV53_ストッパ=OFF
			mSV54_ストッパ=OFF		
			ManualInite=1
		end if

		搬送コンベアEAutoRun=OFF
		
		搬送コンベアEstep=0 '終了

		res(timerr_MC23_モータローラ)
		res(timerr_MC25_搬送モータ)
		res(timerr_MC26_搬送モータ)
		res(timerr_MC27_モータローラ)

		if ldp(pnlPBSV53_ストッパ) then
			if mSV53_ストッパ then
				mSV53_ストッパ=OFF
			else
				mSV53_ストッパ=ON
			end if
		end if
		
		
		if ldp(pnlPBSV54_ストッパ) then
			if mSV54_ストッパ then
				mSV54_ストッパ=OFF
			else
				mSV54_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBMC23_モータローラ) then
			if mMC23_モータローラ then
				mMC23_モータローラ=OFF
			else 'if XSW54_リフト上昇端 then
				mMC23_モータローラ=ON
			end if
		end if
		
		if ldp(pnlPBMC25_搬送モータ) then
			if mMC25_搬送モータ then
				mMC25_搬送モータ=OFF
			else
				mMC25_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC26_搬送モータ) then
			if mMC26_搬送モータ then
				mMC26_搬送モータ=OFF
			else
				mMC26_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC27_モータローラ) then
			if mMC27_モータローラ then
				mMC27_モータローラ=OFF
			else 'if XSW68_リフト上昇端 and XSW70_ストッパ上昇端 then
				mMC27_モータローラ=ON
			end if
		end if
		
				
		if ldp(pnlPBSV56_ストッパ) then
			if mSV56_ストッパ then
				mSV56_ストッパ=OFF
			else
				mSV56_ストッパ=ON
			end if
		end if
		
		
		if ldp(pnlPBSV55_リフト) then
			if mSV55_リフト then
				mSV55_リフト=OFF
			else
				mSV55_リフト=ON
			end if
		end if

			
	end if '搬送コンベアEEmgStep and not(搬送コンベアEOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアEOrgErr処理 】
	else
	
		if ResetFlg then
			搬送コンベアEOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
		res(timerr_MC25_搬送モータ)
		res(timerr_MC26_搬送モータ)
	
		コンベア一時停止中=ON
		alm渋滞警報=ON
	
		if ResetFlg then
			almMC23_モータローラ=OFF
			almMC25_搬送モータ=OFF
			almMC26_搬送モータ=OFF
			almMC27_モータローラ=OFF
			
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

		搬送コンベアEErr=ON

		pauseMC23_モータローラ=ON
		pauseMC25_搬送モータ=ON
		pauseMC26_搬送モータ=ON
		pauseMC27_モータローラ=ON
		

		select case 搬送コンベアEErrStep
		case 0
		case 1
			alm渋滞警報=ON
	
			if ResetFlg then
				almMC23_モータローラ=OFF
				almMC25_搬送モータ=OFF
				almMC26_搬送モータ=OFF
				almMC27_モータローラ=OFF

				almXSW63_ストッパ下降端=OFF
				almXSW64_ストッパ上昇端=OFF
				almXSW65_ストッパ下降端=OFF
				almXSW66_ストッパ上昇端=OFF

				almXSW68_リフト上昇端=OFF
				almXSW67_リフト下降端=OFF
				almXSW69_ストッパ下降端=OFF
				almXSW70_ストッパ上昇端=OFF

				almXSW53_リフト下降端=OFF
				almXSW54_リフト上昇端=OFF
				
				alm渋滞警報=OFF

				inc(搬送コンベアEErrStep)
			end if
		case 2

			res(tim_XSW63_ストッパ下降端.B)
			res(tim_XSW64_ストッパ上昇端.B)
			res(tim_XSW65_ストッパ下降端.B)
			res(tim_XSW66_ストッパ上昇端.B)
			
			res(tim_XSW68_リフト上昇端.B)
			res(tim_XSW67_リフト下降端.B)
			res(tim_XSW69_ストッパ下降端.B)
			res(tim_XSW70_ストッパ上昇端.B)
			
			res(tim_XSW53_リフト下降端)
			res(tim_XSW54_リフト上昇端)
			
			res(tim_notXSW63_ストッパ下降端.B)
			res(tim_notXSW64_ストッパ上昇端.B)
			res(tim_notXSW65_ストッパ下降端.B)
			res(tim_notXSW66_ストッパ上昇端.B)
			
			res(tim_notXSW68_リフト上昇端.B)
			res(tim_notXSW67_リフト下降端.B)
			res(tim_notXSW69_ストッパ下降端.B)
			res(tim_notXSW70_ストッパ上昇端.B)
			
			res(tim_notXSW53_リフト下降端)
			res(tim_notXSW54_リフト上昇端)

			pauseMC23_モータローラ=OFF
			pauseMC25_搬送モータ=OFF
			pauseMC26_搬送モータ=OFF
			pauseMC27_モータローラ=OFF

			pauseSV53_ストッパ=OFF
			pauseSV54_ストッパ=OFF
			pauseSV55_リフト=OFF
			pauseSV56_ストッパ=OFF
			pauseSV44_リフト=OFF

			搬送コンベアEErr=OFF
			搬送コンベアEErrStep=0
		end select

	end if 'if 搬送コンベアEErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 搬送コンベアEEmgStep
	case 0
	
	case 1
		搬送コンベアEAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアEAutoMode and 自動搬送AutoMode ) or 搬送コンベアEstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgMC23_モータローラ=ON
			EmgMC25_搬送モータ=ON
			EmgMC26_搬送モータ=ON
			EmgMC27_モータローラ=ON


			if timstack=OFF then
			
				timnotdly_PH29_釜検知_stack.U=timnotdly_PH29_釜検知.U
				timnotdly_PH30_フタ検知_stack.U=timnotdly_PH30_フタ検知.U
				tim_procstep_stack.U=tim_procstep.U
				tim_SV53_ストッパ_stack.U=tim_SV53_ストッパ.U
				tim_MC23_モータローラ_stack.U=tim_MC23_モータローラ.U
				tim_MC25_搬送モータ_stack.U=tim_MC25_搬送モータ.U
				tim_SV54_ストッパ_stack.U=tim_SV54_ストッパ.U
				tim_MC26_搬送モータ_stack.U=tim_MC26_搬送モータ.U
				tim_MC27_モータローラ_stack.U=tim_MC27_モータローラ.U
				
			' tmr(not(PH29_釜検知),timnotdly_PH29_釜検知,3)
			' tmr(not(PH30_フタ検知),timnotdly_PH30_フタ検知,3)
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(tim_SV53_ストッパ,tim_SV53_ストッパ_val)
			' tmr(tim_MC23_モータローラ,tim_MC23_モータローラ_val)
			' tmr(tim_MC25_搬送モータ,tim_MC25_搬送モータ_val)
			' tmr(tim_SV54_ストッパ, tim_SV54_ストッパ_val)
			' tmr(tim_MC26_搬送モータ,tim_MC26_搬送モータ_val)
			' tmr(tim_MC27_モータローラ,tim_MC27_モータローラ_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV53_ストッパ=OFF
			mSV54_ストッパ=OFF
			mMC23_モータローラ=OFF
			mMC25_搬送モータ=OFF
			mMC26_搬送モータ=OFF
			mMC27_モータローラ=OFF
			mSV56_ストッパ=OFF
			mSV55_リフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアEEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアEEmgStep)
		end if
	case 3
		if (搬送コンベアEAutoMode and 自動搬送AutoMode ) or 搬送コンベアEstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				EmgMC23_モータローラ=OFF
				EmgMC25_搬送モータ=OFF
				EmgMC26_搬送モータ=OFF
				EmgMC27_モータローラ=OFF

				'スタックの値をタイマー現在値にリストア
				tim_procstep.U=tim_procstep_stack.U
				tim_SV53_ストッパ.U=tim_SV53_ストッパ_stack.U
				tim_MC23_モータローラ.U=tim_MC23_モータローラ_stack.U
				tim_MC25_搬送モータ.U=tim_MC25_搬送モータ_stack.U
				tim_SV54_ストッパ.U=tim_SV54_ストッパ_stack.U
				tim_MC26_搬送モータ.U=tim_MC26_搬送モータ_stack.U
				tim_MC27_モータローラ.U=tim_MC27_モータローラ_stack.U
						
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(tim_SV53_ストッパ,tim_SV53_ストッパ_val)
				' tmr(tim_MC23_モータローラ,tim_MC23_モータローラ_val)
				' tmr(tim_MC25_搬送モータ,tim_MC25_搬送モータ_val)
				' tmr(tim_SV54_ストッパ, tim_SV54_ストッパ_val)
				' tmr(tim_MC26_搬送モータ,tim_MC26_搬送モータ_val)
				' tmr(tim_MC27_モータローラ,tim_MC27_モータローラ_val)

				'検出タイマーのリセット
				res(timnotdly_PH29_釜検知)
				res(timnotdly_PH30_フタ検知)
				
				' tmr(not(PH29_釜検知),timnotdly_PH29_釜検知,3)
				' tmr(not(PH30_フタ検知),timnotdly_PH30_フタ検知,3)

				'---------------------------------
				inc(搬送コンベアEEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアEEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアEEmgStep=0
		搬送コンベアEEmg=OFF
	end select
		
end if 'if 搬送コンベアEEmgStep=0 then
