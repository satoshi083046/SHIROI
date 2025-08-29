'洗浄出口搬送
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄出口搬送
'	
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    洗浄出口搬送AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    洗浄出口搬送AutoRun=OFF
    洗浄出口搬送許可=ON
    洗浄出口搬送OrgErr=OFF
    洗浄出口搬送Err=OFF
    洗浄出口搬送Emg=OFF
    洗浄出口搬送step=0
    洗浄出口搬送ErrStep=0
    洗浄出口搬送OrgErrStep=0
    洗浄出口搬送EmgStep=0
	
	MC10_反転モータ正転step=0
	MC10_反転モータ逆転step=0
	
end if
'===================================================================================================================
'【 原点 】
洗浄出口搬送Org=LS5_空釜反転原点位置 or pnlPBLS5_空釜反転原点位置

'===================================================================================================================
'【 緊急停止 】
if not(PB非常停止) then
	洗浄出口搬送Emg=ON
	洗浄出口搬送EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(MC10_反転モータ正転 and not(pnlPBLS6_空釜反転反転位置),tim_LS6_空釜反転反転位置,#60)
tmr(MC10_反転モータ逆転 and not(pnlPBLS5_空釜反転原点位置),tim_LS5_空釜反転原点位置,#60)
tmr(mINV3_コンベアモータ正転 and not(pauseINV3_コンベアモータ正転) and not(EmgINV3_コンベアモータ正転),timerr_INV3_コンベアモータ正転,#120)
tmr( (mMC32_搬送モータ or ejectMC32_搬送モータ) and not(pauseMC32_搬送モータ) and not(EmgMC32_搬送モータ),timerr_MC32_搬送モータ,#120)

if ldp(timerr_INV3_コンベアモータ正転.B) then
	almINV3_コンベアモータ正転=ON
	
	mINV3_コンベアモータ正転=OFF
	ejectMC32_搬送モータ=OFF

	コンベア一時停止=ON
	
else if ldp(timerr_MC32_搬送モータ.B) then
	almMC32_搬送モータ=ON
	
	mINV3_コンベアモータ正転=OFF
	ejectMC32_搬送モータ=OFF
	
	コンベア一時停止=ON
end if

if (LS5_空釜反転原点位置 and not(pnlPBLS5_空釜反転原点位置)) and (LS6_空釜反転反転位置 and not(pnlPBLS6_空釜反転反転位置)) then
	errpassLS6_空釜反転反転位置=ON	
	errpassLS5_空釜反転原点位置=ON
	mMC10_反転モータ正転=OFF
	mMC10_反転モータ逆転=OFF
	almLS5_空釜反転原点位置=ON
	almLS6_空釜反転反転位置=ON
	almMC10_反転モータ正転=ON
	almMC10_反転モータ逆転=ON
	洗浄出口搬送ErrStep=1

else if ldp(tim_LS6_空釜反転反転位置.B) then
	mMC10_反転モータ正転=OFF
	mMC10_反転モータ逆転=OFF
	errpassLS6_空釜反転反転位置=ON	
	almMC10_反転モータ正転=ON
	洗浄出口搬送ErrStep=1
	
else if ldp(tim_LS5_空釜反転原点位置.B) then
	mMC10_反転モータ正転=OFF
	mMC10_反転モータ逆転=OFF
	errpassLS5_空釜反転原点位置=ON
	almMC10_反転モータ逆転=ON
	洗浄出口搬送ErrStep=1

end if


tmr(PH7_釜検知,timdly_PH7_釜検知,5)
tmr(PH8_フタ検知,timdly_PH8_フタ検知,5)
tmr(PH9_釜検知,timdly_PH9_釜検知,5)
tmr(PH10_フタ検知,timdly_PH10_フタ検知,5)

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄出口搬送AutoMode	自動モード セレクトスイッチ
'System :: 洗浄出口搬送AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄出口搬送Emg	その場停止


if 洗浄出口搬送EmgStep=0 then  
	
	if 洗浄出口搬送ErrStep=0  then

	if not(コンベア一時停止) then

	if not(洗浄出口搬送OrgErr) then

	if (洗浄出口搬送AutoMode and 自動搬送AutoMode ) or 洗浄出口搬送step<>0 or MC10_反転モータ正転step<>0 or MC10_反転モータ逆転step<>0 then
	
		if not(洗浄出口搬送AutoMode and 自動搬送AutoMode ) then
			洗浄出口搬送AutoRun=OFF
		end if
	'------------------------------------------------------------------------------------------------
	'MC10_反転モータ正転  （昇降装置->洗浄機側）
	tmr(tim_MC10_反転モータ正転,tim_MC10_反転モータ正転_val)
	
	select case MC10_反転モータ正転step
	
	case 0
	
	case 1
		mMC10_反転モータ正転=ON
		errpassLS6_空釜反転反転位置=OFF
		inc(MC10_反転モータ正転step)

	case 2
		if LS6_空釜反転反転位置 or errpassLS6_空釜反転反転位置 or pnlPBLS6_空釜反転反転位置 then
			inc(MC10_反転モータ正転step)
		end if
		
	case 3
		mMC10_反転モータ正転=OFF
		inc(MC10_反転モータ正転step)

	case 4		
		MC10_反転モータ正転step=0

	end select
	'------------------------------------------------------------------------------------------------
	'MC10_反転モータ逆転 (洗浄機側 -> 昇降機側）
	tmr(tim_MC10_反転モータ逆転,tim_MC10_反転モータ逆転_val)
	
	select case MC10_反転モータ逆転step
	
	case 0
	
	case 1
		mMC10_反転モータ逆転=ON
		errpassLS5_空釜反転原点位置=OFF
		inc(MC10_反転モータ逆転step)

	case 2
		if LS5_空釜反転原点位置 or errpassLS5_空釜反転原点位置 or pnlPBLS5_空釜反転原点位置 then
			inc(MC10_反転モータ逆転step)
		end if
	
	case 3
		mMC10_反転モータ逆転=OFF
		inc(MC10_反転モータ逆転step)
		
	case 4
		MC10_反転モータ逆転step=0

	end select

	'------------------------------------------------------------------------------------------------


	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 洗浄出口搬送step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 洗浄出口搬送AutoRun then
				inc(洗浄出口搬送step)
			else 
				洗浄出口搬送step=0 '終了待機
			end if
	
		case 2
			if timdly_PH9_釜検知 or timdly_PH10_フタ検知  then 'リフト手前位置のワーク
				洗浄出口搬送排出要求=ON
				洗浄出口搬送動作中=OFF
				洗浄出口搬送step=1
			else
				inc(洗浄出口搬送step)
			end if

		case 3
			if 洗浄出口搬送排出要求=OFF and  洗浄コンベア搬送動作中=OFF and 洗浄コンベア搬送排出要求 then
				inc(洗浄出口搬送step)
			else
				洗浄出口搬送step=1
			end if

		case 4
			if LS7_釜反転機原点位置 then
				errpassコンベア一時停止=OFF
				洗浄出口搬送step=100
			else
				洗浄出口搬送step=1			
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'釜反転機起動
		case 100 'mINV3で搬送された釜フタ確認
			洗浄出口搬送動作中=ON
			tim_procstep_val=20
			res(tim_procstep)
			
			res(timdly_PH7_釜検知)
			res(timdly_PH8_フタ検知)
			
			INC(洗浄出口搬送step) 
		
		case 101
			if tim_procstep.B then
				INC(洗浄出口搬送step) 
			end if
		
		case 102
		

		if 1 then
			if timdly_PH7_釜検知.B and timdly_PH8_フタ検知.B then
				'反転機 正転 LS5 -> LS6
				釜搬送中=ON
				洗浄出口搬送step=200
			
			else if not(timdly_PH7_釜検知.B) and timdly_PH8_フタ検知.B then
				'反転機 逆転 LS6 -> LS5
				釜搬送中=OFF
				洗浄出口搬送step=250
			
			else if not(timdly_PH7_釜検知.B) and not(timdly_PH8_フタ検知.B) then
				'何もしないで終了
				釜搬送中=OFF
				洗浄コンベア搬送排出要求=OFF
				洗浄出口搬送動作中=OFF
				洗浄出口搬送step=1
			
			end if
		end if
		
		if 0 then
		
		if StageDevice36=$80 then '釜検出
			'反転機 正転 LS5 -> LS6
			釜搬送中=ON
			洗浄出口搬送step=200
		
		else if StageDevice36=$40 then 'フタ検出
			'反転機 逆転 LS6 -> LS5
			釜搬送中=OFF
			洗浄出口搬送step=250
		
		else if StageDevice36=0 then '何もない
			'何もしないで終了
			釜搬送中=OFF
			洗浄コンベア搬送排出要求=OFF
			洗浄出口搬送動作中=OFF
			洗浄出口搬送step=1
		
		end if

		end if
		'--------------------------------------------------------
		'釜搬送
		case 200
			MC10_反転モータ正転step=1
			inc(洗浄出口搬送step)
				
		case 201
			if MC10_反転モータ正転step=0 then
				inc(洗浄出口搬送step)
			end if
		
		case 202
			if errpassLS6_空釜反転反転位置 or pnlPBLS5_空釜反転原点位置 or pnlPBLS6_空釜反転反転位置 then
				inc(洗浄出口搬送step)
			else
				setS05c3=4500
				mINV3_コンベアモータ正転=ON
				errpassコンベア一時停止=OFF
				tim_procstep_val=INV3釜挿入時間 '1号機(47) 2号機(38)
				res(tim_procstep)
				inc(洗浄出口搬送step)
			end if
			
		case 203
			if tim_procstep.B then
				inc(洗浄出口搬送step)
			end if		

		case 204
			if errpassLS6_空釜反転反転位置 or pnlPBLS5_空釜反転原点位置 or pnlPBLS6_空釜反転反転位置 then
				inc(洗浄出口搬送step)
			else
				if (not(PH7_釜検知) and not(PH8_フタ検知) ) or errpassコンベア一時停止 then
					mINV3_コンベアモータ正転=OFF
					inc(洗浄出口搬送step)
				end if
			end if
			
		case 205
			inc(洗浄出口搬送step)

		case 206
			MC10_反転モータ逆転step=1
			inc(洗浄出口搬送step)
		
		case 207

			洗浄コンベア搬送排出要求=OFF
			洗浄出口搬送動作中=OFF
			inc(洗浄出口搬送step)

		case 208
			if MC10_反転モータ逆転step=0 then
				tim_procstep_val=5
				res(tim_procstep)
				inc(洗浄出口搬送step)
			end if
		
		case 209
			if tim_procstep.B then
				if PH9_釜検知 then
					StageDevice36=0
					StageDevice37=$8000+$100 '<- StageDevice  [ 釜  ］のデータ入れ込みｽﾀｰﾄ地点
				else
					StageDevice36=0
					StageDevice37=0 '<- StageDevice  [ 釜  ］のデータ入れ込みｽﾀｰﾄ地点
				end if
				洗浄出口搬送step=1
			end if
					

		'----------------------------------------------------------------------
		'フタ搬送
		case 250
			MC10_反転モータ逆転step=1
			inc(洗浄出口搬送step)
		
		case 251
			if MC10_反転モータ逆転step=0 then
				inc(洗浄出口搬送step)
			end if		
		
		case 252
			setS05c3=6000
			mINV3_コンベアモータ正転=ON
			ejectMC32_搬送モータ=ON
			errpassコンベア一時停止=OFF
			inc(洗浄出口搬送step)
			
		case 253
			if errpassコンベア一時停止 then
				res(tim釜フタ検知監視)
				inc(洗浄出口搬送step)
			
			else if not(PH8_フタ検知) then
				res(tim釜フタ検知監視)
				inc(洗浄出口搬送step)
			end if

		case 254
			if errpassコンベア一時停止 then
				res(tim釜フタ検知監視)
				inc(洗浄出口搬送step)
			
			else if PH10_フタ検知  then
				inc(洗浄出口搬送step)
			end if

		case 255
			tim_procstep_val=6
			res(tim_procstep)
			inc(洗浄出口搬送step)
		
		case 256
			if tim_procstep.B then
				inc(洗浄出口搬送step)		
			end if
			
		case 257
			mINV3_コンベアモータ正転=OFF
			ejectMC32_搬送モータ=OFF
			inc(洗浄出口搬送step)
			
		case 258
			StageDevice36=0
			StageDevice37=0               '<- StageDevice [ フタ  ］のデータ入れ込みｽﾀｰﾄ地点
			洗浄コンベア搬送排出要求=OFF
			洗浄出口搬送動作中=OFF
			洗浄出口搬送step=1
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		洗浄出口搬送AutoRun=OFF
		
		洗浄出口搬送step=0 '終了

		res(timerr_INV3_コンベアモータ正転)
		res(timerr_MC32_搬送モータ)

		if 0 then
			if ldp(pnlPBINV3_コンベアモータ正転) then
				if mINV3_コンベアモータ正転 then
					mINV3_コンベアモータ正転=OFF
				else
					mINV3_コンベアモータ正転=ON
				end if
			end if
		end if
		
		if ldp(pnlPBMC32_搬送モータ) then
			if mMC32_搬送モータ then
				mMC32_搬送モータ=OFF
			else
				mMC32_搬送モータ=ON
			end if
		end if
		
		
		if ldp(pnlPBMC10_反転モータ正転) then
			'if LS5_空釜反転原点位置 then
				if mMC10_反転モータ正転 then
					mMC10_反転モータ正転=OFF
				else if not(mMC10_反転モータ逆転) and  not(PH7_釜検知) and not(PH8_フタ検知) then
					mMC10_反転モータ正転=ON
					mMC10_反転モータ逆転=OFF
				end if
			'end if
		else if ldp(pnlPBMC10_反転モータ逆転) then
			'if LS6_空釜反転反転位置 then
				if mMC10_反転モータ逆転 then
					mMC10_反転モータ逆転=OFF
				else if not(mMC10_反転モータ正転) and not(PH9_釜検知) and not(PH10_フタ検知) then	
					mMC10_反転モータ正転=OFF
					mMC10_反転モータ逆転=ON
				end if
			'end if
		end if
		if mMC10_反転モータ正転 and LS6_空釜反転反転位置 then
			mMC10_反転モータ正転=OFF
		end if
		if mMC10_反転モータ逆転 and LS5_空釜反転原点位置 then
			mMC10_反転モータ逆転=OFF
		end if


	end if '洗浄出口搬送AutoMode and not(洗浄出口搬送OrgErrStep)

	'===================================================================================================================
	'【 洗浄出口搬送OrgErr処理 】
	else
	
		if ResetFlg then
			洗浄出口搬送OrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
		res(timerr_INV3_コンベアモータ正転)
		res(timerr_MC32_搬送モータ)		
		
		コンベア一時停止中=ON
		alm渋滞警報=ON
		
		if ResetFlg then
			almINV3_コンベアモータ正転=OFF
			almMC32_搬送モータ=OFF

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

		洗浄出口搬送Err=ON

		洗浄出口搬送AutoRun=OFF
		
		pauseINV3_コンベアモータ正転=ON
		pauseMC32_搬送モータ=ON
		
		tmr(tim_洗浄出口搬送ErrStep,tim_洗浄出口搬送ErrStep_val)
		
		select case 洗浄出口搬送ErrStep
		case 0
		
		case 1
			alm渋滞警報=ON
	
			if ResetFlg then
				alm渋滞警報=OFF
				inc(洗浄出口搬送ErrStep)
			end if

		case 2
			almLS6_空釜反転反転位置=OFF
			almLS5_空釜反転原点位置=OFF
			almMC10_反転モータ正転=OFF
			almMC10_反転モータ逆転=OFF
			

			inc(洗浄出口搬送ErrStep)
		
		case 3
			pauseINV3_コンベアモータ正転=OFF
			pauseMC32_搬送モータ=OFF

			洗浄出口搬送Err=OFF
			洗浄出口搬送ErrStep=0
		end select

	end if 'if 洗浄出口搬送ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	'--- AutoMode
	'mMC10_反転モータ正転=ON
	'mMC10_反転モータ逆転=ON
	'ejectMC32_搬送モータ=ON
	'mINV3_コンベアモータ正転=ON

	'--- Manual
	'mMC32_搬送モータ=ON
	'mMC10_反転モータ正転=ON
	'mMC10_反転モータ逆転=ON
	'mINV3_コンベアモータ正転=ON

	select case 洗浄出口搬送EmgStep
	case 0
	
	case 1
		洗浄出口搬送AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (洗浄出口搬送AutoMode and 自動搬送AutoMode ) or 洗浄出口搬送step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC10_反転モータ逆転=ON
			pauseMC10_反転モータ正転=ON
			pauseMC32_搬送モータ=ON
			pauseINV3_コンベアモータ正転=ON
		
			if timstack=OFF then
				'tmr(PH7_釜検知,timdly_PH7_釜検知,5)
				'tmr(PH8_フタ検知,timdly_PH8_フタ検知,5)
				'tmr(PH9_釜検知,timdly_PH9_釜検知,5)
				'tmr(PH10_フタ検知,timdly_PH10_フタ検知,5)
				timdly_PH7_釜検知_stack.U=timdly_PH7_釜検知.U
				timdly_PH8_フタ検知_stack.U=timdly_PH8_フタ検知.U
				timdly_PH9_釜検知_stack.U=timdly_PH9_釜検知.U
				timdly_PH10_フタ検知_stack.U=timdly_PH10_フタ検知.U

				'tmr(tim_MC10_反転モータ正転,tim_MC10_反転モータ正転_val)
				'tmr(tim_MC10_反転モータ逆転,tim_MC10_反転モータ逆転_val)
				'tmr(tim_procstep,tim_procstep_val)
				'tmr(tim_洗浄出口搬送ErrStep,tim_洗浄出口搬送ErrStep_val)				
				tim_MC10_反転モータ正転_stack.U=tim_MC10_反転モータ正転.U
				tim_MC10_反転モータ逆転_stack.U=tim_MC10_反転モータ逆転.U
				tim_procstep_stack.U=tim_procstep.U
				tim_洗浄出口搬送ErrStep_stack.U=tim_洗浄出口搬送ErrStep.U
			
				timstack=ON
			end if

			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC32_搬送モータ=OFF
			mMC10_反転モータ正転=OFF
			mMC10_反転モータ逆転=OFF
			mINV3_コンベアモータ正転=OFF
		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄出口搬送EmgStep)
	case 2
		if ResetFlg then
			inc(洗浄出口搬送EmgStep)
		end if
	case 3
		if (洗浄出口搬送AutoMode and 自動搬送AutoMode ) or 洗浄出口搬送step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC10_反転モータ逆転=OFF
				pauseMC10_反転モータ正転=OFF
				pauseMC32_搬送モータ=OFF
				pauseINV3_コンベアモータ正転=OFF

				tim_MC10_反転モータ正転.U=tim_MC10_反転モータ正転_stack.U
				tim_MC10_反転モータ逆転.U=tim_MC10_反転モータ逆転_stack.U
				tim_procstep.U=tim_procstep_stack.U
				tim_洗浄出口搬送ErrStep.U=tim_洗浄出口搬送ErrStep_stack.U
				'---------------------------------
				res(timdly_PH7_釜検知)
				res(timdly_PH8_フタ検知)
				res(timdly_PH9_釜検知)
				res(timdly_PH10_フタ検知)
				
				inc(洗浄出口搬送EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(洗浄出口搬送EmgStep)		
		end if				
	case 4
		timstack=OFF
		洗浄出口搬送EmgStep=0
		洗浄出口搬送Emg=OFF
	end select
		
end if 'if 洗浄出口搬送EmgStep=0 then
