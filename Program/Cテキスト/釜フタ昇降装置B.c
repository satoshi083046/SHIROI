'釜フタ昇降装置B
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	釜フタ昇降装置B
'	
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    釜フタ昇降装置BAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    釜フタ昇降装置BAutoRun=OFF
    釜フタ昇降装置B許可=ON
    釜フタ昇降装置BOrgErr=OFF
    釜フタ昇降装置BErr=OFF
    釜フタ昇降装置BEmg=OFF
    釜フタ昇降装置Bstep=0
    釜フタ昇降装置BErrStep=0
    釜フタ昇降装置BOrgErrStep=0
    釜フタ昇降装置BEmgStep=0
	
	MC32_搬送モータstep=0
	MC11_搬送モータstep=0
	MC11_搬送モータ排出step=0
	
	
end if
'===================================================================================================================
'【 原点 】
釜フタ昇降装置BOrg=((XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端)) or passXSW18_リフト上昇端) or ((XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端)

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	釜フタ昇降装置BEmg=ON
	釜フタ昇降装置BEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV20_リフト上昇 and not(XSW18_リフト上昇端) and not(pnlPBXSW18_リフト上昇端), tim_notXSW18_リフト上昇端,#60) '3590.35ms
tmr(SV100_リフト下降 and not(XSW17_リフト下降端) and not(pnlPBXSW17_リフト下降端), tim_notXSW17_リフト下降端,#60) '3696.96ms

'tmr(SV100_リフト下降 and XSW18_リフト上昇端, tim_XSW18_リフト上昇端,#10) '3590.35ms
if LDP(SV20_リフト上昇) and XSW18_リフト上昇端 and XSW17_リフト下降端 and not(pnlPBXSW18_リフト上昇端) then
	SET(tim_XSW18_リフト上昇端)
end if
'tmr(SV20_リフト上昇 and XSW17_リフト下降端, tim_XSW17_リフト下降端,#10) '3696.96ms
if LDP(SV100_リフト下降) and XSW18_リフト上昇端 and XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端) then
	SET(tim_XSW17_リフト下降端)
end if

if SV20_リフト上昇 then
	KeepSV20_リフト上昇=ON
	KeepSV100_リフト下降=OFF
else if SV100_リフト下降 then
	KeepSV20_リフト上昇=OFF
	KeepSV100_リフト下降=ON
end if

'passtimXSW18_リフト上昇端_val=#3590
tms(KeepSV20_リフト上昇, passtimXSW18_リフト上昇端,passtimXSW18_リフト上昇端_val) 

'passtimXSW17_リフト下降端_val=#3696
tms(KeepSV100_リフト下降, passtimXSW17_リフト下降端,passtimXSW17_リフト下降端_val) 

tmr((mMC11_搬送モータ or ejectMC11_搬送モータ) and not(pauseMC11_搬送モータ) and not(EmgMC11_搬送モータ), timerr_MC11_搬送モータ,#80)
tmr(mMC32_搬送モータ and not(pauseMC32_搬送モータ) and not(EmgMC32_搬送モータ), timerr_MC32_搬送モータ,#90)
tmr(ejectMC6_搬送モータ and not(pauseMC6_搬送モータ) and not(EmgMC6_搬送モータ),timerr_MC6_搬送モータ,#90)

if ldp(timerr_MC11_搬送モータ.B) then
	almMC11_搬送モータ=ON
	
	mMC11_搬送モータ=OFF
	mMC32_搬送モータ=OFF
	ejectMC6_搬送モータ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC32_搬送モータ.B) then
	almMC32_搬送モータ=ON
	
	mMC11_搬送モータ=OFF
	mMC32_搬送モータ=OFF
	ejectMC6_搬送モータ=OFF

	コンベア一時停止=ON
	
else if ldp(timerr_MC6_搬送モータ.B) then
	almMC6_搬送モータ=ON
	
	mMC11_搬送モータ=OFF
	mMC32_搬送モータ=OFF
	ejectMC6_搬送モータ=OFF
	
	コンベア一時停止=ON

end if


if (ldp(tim_XSW18_リフト上昇端.B) or ldp(tim_notXSW18_リフト上昇端.B)) and not(pnlPBXSW18_リフト上昇端) then
	if 釜フタ昇降装置Bstep>0 and tim_notXSW18_リフト上昇端.B then
		mSV20_リフト上昇=OFF
		mSV100_リフト下降=ON
	end if
	almXSW18_リフト上昇端=ON
	pnlPBXSW17_リフト下降端=ON
	pnlPBXSW18_リフト上昇端=ON
	if tim_XSW18_リフト上昇端 then
		res(tim_XSW18_リフト上昇端)
	end if
	釜フタ昇降装置BErrStep=1

else if (ldp(tim_XSW17_リフト下降端.B) or ldp(tim_notXSW17_リフト下降端.B)) and not(pnlPBXSW17_リフト下降端) then
	if 釜フタ昇降装置Bstep>0 and tim_notXSW17_リフト下降端.B then
		mSV20_リフト上昇=ON
		mSV100_リフト下降=OFF
	end if
	almXSW17_リフト下降端=ON
	pnlPBXSW17_リフト下降端=ON
	pnlPBXSW18_リフト上昇端=ON
	if tim_XSW17_リフト下降端 then
		res(tim_XSW17_リフト下降端)
	end if
	釜フタ昇降装置BErrStep=1

end if


'===================================================================================================================
'検知タイマー

TMR(PH50_釜検知,timdly_PH50_釜検知,4)
TMR(PH51_フタ検知,timdly_PH51_フタ検知,4)

tmr(PH39_釜検知,timdly_PH39_釜検知,4)
tmr(PH40_フタ検知,timdly_PH40_フタ検知,4)
tmr(not(PH39_釜検知),timnotdly_PH39_釜検知,4)
tmr(not(PH40_フタ検知),timnotdly_PH40_フタ検知,4)


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 釜フタ昇降装置BAutoMode	自動モード セレクトスイッチ
'System :: 釜フタ昇降装置BAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 釜フタ昇降装置BEmg	その場停止


if 釜フタ昇降装置BEmgStep=0 then  
	
	if 釜フタ昇降装置BErrStep=0  then
	
	if not(コンベア一時停止) then

	if not(釜フタ昇降装置BOrgErr) then

		
	'------------------------------------------------------------------------------------------------
	'MC32_搬送モータ
	tmr(tim_MC32_搬送モータ,tim_MC32_搬送モータ_val)
	
	select case MC32_搬送モータstep
	
	case 0
	
	case 1
		mMC32_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC32_搬送モータstep)

	case 2
		if errpassコンベア一時停止 then
				inc(MC32_搬送モータstep)
		
		else if not(PH9_釜検知) and not(PH10_フタ検知) then
				inc(MC32_搬送モータstep)
		end if

	case 3
		if errpassコンベア一時停止 then
				inc(MC32_搬送モータstep)
				
		else if PH39_釜検知 or PH40_フタ検知 then
			tim_MC32_搬送モータ_val=1 'モータ停止タイミング
			res(tim_MC32_搬送モータ)
			inc(MC32_搬送モータstep)
		end if
	
	case 4
		if tim_MC32_搬送モータ.B then
			inc(MC32_搬送モータstep)
		end if
		
	case 5
		mMC32_搬送モータ=OFF
		inc(MC32_搬送モータstep)
	
	case 6
		MC32_搬送モータstep=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_搬送モータ
	tmr(tim_MC11_搬送モータ,tim_MC11_搬送モータ_val)
	
	select case MC11_搬送モータstep	
	case 0
	case 1
		mMC11_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC11_搬送モータstep)

	case 2
		if errpassコンベア一時停止 then
			inc(MC11_搬送モータstep)
			
		else if not(PH9_釜検知) and not(PH10_フタ検知) then
				inc(MC11_搬送モータstep)
		end if
	case 3
		if errpassコンベア一時停止 then
			inc(MC11_搬送モータstep)
	
		else if PH39_釜検知 or PH40_フタ検知 then
			if 釜搬送中 or PH39_釜検知 then
				tim_MC11_搬送モータ_val=9 'モータ停止タイミング
			else if not(釜搬送中) or PH40_フタ検知 then
				tim_MC11_搬送モータ_val=5 'モータ停止タイミング
			end if			
			
			res(tim_MC11_搬送モータ)
			inc(MC11_搬送モータstep)
		end if
	
	case 4
		釜搬送中=OFF
		if tim_MC11_搬送モータ.B then
			inc(MC11_搬送モータstep)
		end if
		
	case 5
		mMC11_搬送モータ=OFF
		inc(MC11_搬送モータstep)
	
	case 6
		MC11_搬送モータstep=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC11_搬送モータ排出
	tmr(tim_MC11_搬送モータ排出,tim_MC11_搬送モータ排出_val)
	
	select case MC11_搬送モータ排出step	
	case 0
	case 1
		PH39_釜起動検知=PH39_釜検知 '----釜フタ昇降B
		PH40_フタ起動検知=PH40_フタ検知
		'PH50_釜検知 '----搬送口
		'PH51_フタ検知
		inc(MC11_搬送モータ排出step)
	
	case 2
		'mSV20_リフト=OFF
		mSV20_リフト上昇=OFF
		mSV100_リフト下降=ON
		inc(MC11_搬送モータ排出step)
		
	case 3
		if (XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端 then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 4
		tim_MC11_搬送モータ排出_val=0
		res(tim_MC11_搬送モータ排出)
		inc(MC11_搬送モータ排出step)
	
	case 5
		if tim_MC11_搬送モータ排出.B then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 6
		ejectMC11_搬送モータ=ON
		ejectMC6_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC11_搬送モータ排出step)

	case 7
		if errpassコンベア一時停止 then
			inc(MC11_搬送モータ排出step)
		
		else if not(PH39_釜検知) and not(PH40_フタ検知) then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 8
		tim_MC11_搬送モータ排出_val=55
		res(tim_MC11_搬送モータ排出)
		inc(MC11_搬送モータ排出step)
	
	case 9
		if tim_MC11_搬送モータ排出.B then
			RES(timdly_PH50_釜検知)
			RES(timdly_PH51_フタ検知)
			inc(MC11_搬送モータ排出step)
		end if

	case 10
		if errpassコンベア一時停止 then
			inc(MC11_搬送モータ排出step)
		
		else if (PH50_釜検知 and timdly_PH50_釜検知) or (PH51_フタ検知 and timdly_PH51_フタ検知) then
			inc(MC11_搬送モータ排出step)
		end if
	
	case 11
		ejectMC11_搬送モータ=OFF
		ejectMC6_搬送モータ=OFF
		inc(MC11_搬送モータ排出step)
	
	case 12
		MC11_搬送モータ排出step=0

	end select

	'===================================================================================================================
	'【 リフタータスク 】
	'
	if (釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Bstep<>0 then
	
		if not(釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) then
			釜フタ昇降装置BAutoRun=OFF
		end if


		tmr(tim_procstep,tim_procstep_val)

		select case 釜フタ昇降装置Bstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 釜フタ昇降装置BAutoRun then
				inc(釜フタ昇降装置Bstep)
			else 
				釜フタ昇降装置Bstep=0 '終了待機
			end if
		
		case 2
			if timdly_PH39_釜検知.B or timdly_PH40_フタ検知.B then
				釜フタ昇降装置Bstep=100 'リフトに釜フタあり
			else if timnotdly_PH39_釜検知.B and timnotdly_PH40_フタ検知.B then 
				釜フタ昇降装置Bstep=200 'リフトに釜フタなし
			end if
		'--------------------------------------------------------------------------------------------------------------
		’[リフト下降]
		case 100
			釜フタ昇降装置B動作中=OFF
			inc(釜フタ昇降装置Bstep)
		
		case 101
			'mSV20_リフト=OFF 'リフト下降
			mSV20_リフト上昇=OFF
			mSV100_リフト下降=ON
			inc(釜フタ昇降装置Bstep)
		
		case 102
			if (XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端 then
				inc(釜フタ昇降装置Bstep)
			end if		
	
		case 103
			釜フタ昇降装置Bstep=110
		
		'--------------------------------------------------------------------------------------------------------------
		'【リフト下降端】
		case 110
			if 釜フタ昇降B排出要求=OFF and 搬送コンベアA動作中=OFF  then '搬送コンベアA搬送移動確認
				inc(釜フタ昇降装置Bstep)
			else
				釜フタ昇降装置Bstep=1
			end if
			
		case 111
			if not(PH50_釜検知) and not(PH51_フタ検知) then
				MC11_搬送モータ排出step=1 'MC6を含む
				inc(釜フタ昇降装置Bstep)
			else
				釜フタ昇降装置Bstep=1			
			end if
			
		case 112
			if MC11_搬送モータ排出step=0 then
	 			釜フタ昇降B排出要求=ON  '排出要求
				inc(釜フタ昇降装置Bstep)
			end if			

		case 113
			if  not(PH39_釜検知) and not(PH40_フタ検知) then 'リフト上の釜フタなし確認
				inc(釜フタ昇降装置Bstep)
			end if
		
		case 114
			StageDevice0=StageDevice38
			StageDevice38=0
			釜フタ昇降装置Bstep=200

		'--------------------------------------------------------------------------------------------------------------
		'[リフト上昇]
		case 200 'リフト手前位置のワーク搬送			
			'mSV20_リフト=ON '上昇
			mSV20_リフト上昇=ON
			mSV100_リフト下降=OFF
			inc(釜フタ昇降装置Bstep)

		case 201
			if 洗浄出口搬送動作中=OFF and 洗浄出口搬送排出要求 then	
				釜フタ昇降装置Bstep=210
			else
				釜フタ昇降装置Bstep=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		'【リフト上昇端】
		case 210
			if PH9_釜検知 or PH10_フタ検知 then
				if PH9_釜検知 and PH10_フタ検知 then
					釜搬送中=ON
				else
					釜搬送中=OFF
				end if
								
				inc(釜フタ昇降装置Bstep)
			else
				釜フタ昇降装置Bstep=1
			end if
		
		case 211
			if (XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端)) or passXSW18_リフト上昇端 then
				errpassコンベア一時停止=OFF
				MC32_搬送モータstep=1
				MC11_搬送モータstep=1
				inc(釜フタ昇降装置Bstep)
			end if
		
		case 212
			if MC32_搬送モータstep=0 and MC11_搬送モータstep=0 then
				StageDevice38=StageDevice37
				StageDevice37=0
				inc(釜フタ昇降装置Bstep)
			end if

		case 213
			洗浄出口搬送排出要求=OFF
			釜フタ昇降装置B動作中=OFF
			釜フタ昇降装置Bstep=1

		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 

		釜フタ昇降装置BAutoRun=OFF	
		釜フタ昇降装置Bstep=0 '終了

		'res(tim_XSW18_リフト上昇端)
		'res(tim_XSW17_リフト下降端)

		res(timerr_MC11_搬送モータ)
		res(timerr_MC32_搬送モータ)
		res(timerr_MC6_搬送モータ)

		if ldp(pnlPBSV20_リフト上昇) then
			mSV20_リフト上昇=ON
			mSV100_リフト下降=OFF
		else if ldp(pnlPBSV100_リフト下降) then		
			mSV20_リフト上昇=OFF
			mSV100_リフト下降=ON
		end if
		if mSV20_リフト上昇 and ( (XSW18_リフト上昇端 and not(pnlPBXSW18_リフト上昇端)) or passXSW18_リフト上昇端) then
			mSV20_リフト上昇=OFF
		end if
		if mSV100_リフト下降 and ( (XSW17_リフト下降端 and not(pnlPBXSW17_リフト下降端)) or passXSW17_リフト下降端) then
			mSV100_リフト下降=OFF
		end if
				
		if ldp(pnlPBMC11_搬送モータ) then
			if mMC11_搬送モータ then
				mMC11_搬送モータ=OFF
			else 'if XSW17_リフト下降端 or XSW18_リフト上昇端 then
				mMC11_搬送モータ=ON
			end if
		end if
		
	end if '釜フタ昇降装置BAutoMode and not(釜フタ昇降装置BOrgErrStep)

	'===================================================================================================================
	'【 釜フタ昇降装置BOrgErr処理 】
	else

		if ResetFlg then
			釜フタ昇降装置BOrgErr=OFF
		end if
	
	end if
	
	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
		res(timerr_MC11_搬送モータ)		
		res(timerr_MC32_搬送モータ)		
		res(timerr_MC6_搬送モータ)		

		コンベア一時停止中=ON
		alm渋滞警報=ON
		
		if ResetFlg then
			almMC11_搬送モータ=OFF
			almMC32_搬送モータ=OFF
			almMC6_搬送モータ=OFF

			コンベア一時停止=OFF
			コンベア一時停止中=OFF
			alm渋滞警報=OFF
			
			errpassコンベア一時停止=ON
			
		end if
		
	end if



	
	'===================================================================================================================
	'【タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		釜フタ昇降装置BErr=ON

		釜フタ昇降装置BAutoRun=OFF	
		釜フタ昇降装置Bstep=0 '終了

		pauseMC11_搬送モータ=ON
		pauseMC32_搬送モータ=ON
		pauseMC6_搬送モータ=ON

		select case 釜フタ昇降装置BErrStep
		case 0
		case 1
			alm渋滞警報=ON
		
			if ResetFlg then
				almXSW18_リフト上昇端=OFF
				almXSW17_リフト下降端=OFF

				alm渋滞警報=OFF
				
				inc(釜フタ昇降装置BErrStep)
			end if
		case 2
			pauseMC11_搬送モータ=OFF
			pauseMC32_搬送モータ=OFF
			pauseMC6_搬送モータ=OFF
		
			res(tim_XSW18_リフト上昇端.B)
			res(tim_XSW17_リフト下降端.B)
			res(tim_notXSW18_リフト上昇端.B)
			res(tim_notXSW17_リフト下降端.B)

			洗浄出口搬送排出要求=OFF
			釜フタ昇降装置B動作中=OFF
			釜フタ昇降装置BErr=OFF
			釜フタ昇降装置BErrStep=0
		end select

	end if 'if 釜フタ昇降装置BErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	'mMC32_搬送モータ=ON
	'mMC11_搬送モータ=ON
	'ejectMC11_搬送モータ=ON
	'ejectMC6_搬送モータ=ON

	select case 釜フタ昇降装置BEmgStep
	case 0
	
	case 1
		釜フタ昇降装置BAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Bstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC32_搬送モータ=ON
			pauseMC11_搬送モータ=ON
			pauseMC11_搬送モータ=ON
			pauseMC6_搬送モータ=ON
		
			if timstack=OFF then
			
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC32_搬送モータ=OFF
			mMC11_搬送モータ=OFF
			ejectMC11_搬送モータ=OFF
			ejectMC6_搬送モータ=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(釜フタ昇降装置BEmgStep)
	case 2
		if ResetFlg then
			inc(釜フタ昇降装置BEmgStep)
		end if
	case 3
		if (釜フタ昇降装置BAutoMode and 自動搬送AutoMode ) or 釜フタ昇降装置Bstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC32_搬送モータ=OFF
				pauseMC11_搬送モータ=OFF
				pauseMC11_搬送モータ=OFF
				pauseMC6_搬送モータ=OFF

				'---------------------------------
				inc(釜フタ昇降装置BEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(釜フタ昇降装置BEmgStep)		
		end if				
	case 4
		timstack=OFF
		釜フタ昇降装置BEmgStep=0
		釜フタ昇降装置BEmg=OFF
	end select
		
end if 'if 釜フタ昇降装置BEmgStep=0 then
