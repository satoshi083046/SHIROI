'洗浄入口リフト
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄入口リフト
'	
'===================================================================================================================

'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

	 '洗浄入口リフトAutoMode  と  洗浄入口リフトAutoRun  は再起動の際に突然OFFになるため、
	 '洗浄入口リフトAutoMode -> 洗浄入口搬送AutoMode  洗浄入口リフトAutoRun -> 洗浄入口搬送AutoRun に変更

    '洗浄入口リフトAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    '洗浄入口リフトAutoRun=OFF
    洗浄入口リフト許可=ON
    洗浄入口リフトOrgErr=OFF
    洗浄入口リフトErr=OFF
    洗浄入口リフトEmg=OFF
    洗浄入口リフトstep=0
    洗浄入口リフトErrStep=0
    洗浄入口リフトOrgErrStep=0
    洗浄入口リフトEmgStep=0
	
	MC30_搬送モータstep=0
	
end if
'===================================================================================================================
'【 原点 】
洗浄入口リフトOrg=1 'not(洗浄搬送禁止 and (PH48_釜検知 or PH49_フタ検知))

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	洗浄入口リフトEmg=ON
	洗浄入口リフトEmgStep=1
end if


'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(mMC30_搬送モータ and not(pauseMC30_搬送モータ) and not(EmgMC30_搬送モータ),timerr_MC30_搬送モータ,#150)
tmr(ejectMC33_搬送モータ and not(pauseMC33_搬送モータ) and not(EmgMC33_搬送モータ),timerr_MC33_搬送モータ,#100)

if ldp(timerr_MC30_搬送モータ.B) then
	almMC30_搬送モータ=ON
	
	mMC30_搬送モータ=OFF
	ejectMC33_搬送モータ=OFF
	コンベア一時停止=ON

else if ldp(timerr_MC33_搬送モータ.B) then
	almMC33_搬送モータ=ON

	mMC30_搬送モータ=OFF
	ejectMC33_搬送モータ=OFF
	コンベア一時停止=ON
end if

tmr(not(PH48_釜検知) and not(PH49_フタ検知),timoffdly_PH48PH49,#20) 


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄入口リフトAutoMode	自動モード セレクトスイッチ
'System :: 洗浄入口リフトAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄入口リフトEmg	その場停止


if 洗浄入口リフトEmgStep=0 then  
	
	if 洗浄入口リフトErrStep=0  then

	if not(コンベア一時停止) then

	if not(洗浄入口リフトOrgErr) then

	if (洗浄入口搬送AutoMode and 自動搬送AutoMode ) or 洗浄入口リフトstep<>0 then
	
		if not(洗浄入口搬送AutoMode and 自動搬送AutoMode ) then
			洗浄入口搬送AutoRun=OFF
		end if
	
	'------------------------------------------------------------------------------------------------
	'MC30_搬送モータ, MC33_搬送モータ 
	tmr(tim_MC30_搬送モータ,tim_MC30_搬送モータ_val)
	
	select case MC30_搬送モータstep
	case 0
	case 1
		mMC30_搬送モータ=ON
		ejectMC33_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC30_搬送モータstep)
	case 2
		if errpassコンベア一時停止 then
			inc(MC30_搬送モータstep)
		
		else if not(PH48_釜検知) and not(PH49_フタ検知) then
			inc(MC30_搬送モータstep)
		end if	
	case 3
		if errpassコンベア一時停止 then
			inc(MC30_搬送モータstep)
		
		else if PH43_釜検知 or PH44_フタ検知 then
			inc(MC30_搬送モータstep)
		end if	

	case 4
		if 釜搬送中 then
			tim_MC30_搬送モータ_val=10
		else
			tim_MC30_搬送モータ_val=5 '3 'フタの停止位置
		end if
		
		res(tim_MC30_搬送モータ)
		inc(MC30_搬送モータstep)

	case 5
		if tim_MC30_搬送モータ.B then
			mMC30_搬送モータ=OFF
			ejectMC33_搬送モータ=OFF

			洗浄入口リフト排出要求=ON
			搬送コンベアF排出要求=OFF
			inc(MC30_搬送モータstep)
		end if

	case 6
		洗浄入口リフト動作中=OFF
		inc(MC30_搬送モータstep)

	case 7
		MC30_搬送モータstep=0
	
	end select
	'------------------------------------------------------------------------------------------------

	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 洗浄入口リフトstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 洗浄入口搬送AutoRun then
				inc(洗浄入口リフトstep)
			else 
				洗浄入口リフトstep=0 '終了待機
			end if

		case 2		
			if not(洗浄搬送禁止) and (PH43_釜検知 or PH44_フタ検知) then '洗浄コンベア上のワーク搬送
				洗浄入口リフト排出要求=ON
				洗浄入口リフト動作中=OFF
				洗浄入口リフトstep=1
			else
				inc(洗浄入口リフトstep)
			end if
			
		case 3
			if  洗浄入口リフト排出要求=OFF and  搬送コンベアF排出要求 then
				errpassコンベア一時停止=OFF
				洗浄入口リフトstep=100
			else
				洗浄入口リフトstep=1
			end if

		'--------------------------------------------------------------------------------------------------------------
		case 100
			if PH48_釜検知 or PH49_フタ検知 then '通常搬送：リフトのワーク搬送
				洗浄入口リフトstep=200
			else
				搬送コンベアF排出要求=OFF
				洗浄入口リフトstep=1			
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 200 'リフト上昇 -> 指定待機位置に釜フタ搬送
			洗浄入口リフト動作中=ON
			inc(洗浄入口リフトstep)
			
		case 201
			if 洗浄搬送禁止 then
				if timoffdly_PH48PH49 then
					搬送コンベアF排出要求=OFF
					洗浄入口リフト排出要求=OFF
					洗浄入口リフト動作中=OFF
				end if			
					洗浄入口リフトstep=1
			else
				inc(洗浄入口リフトstep)
			end if

			'------------------------------------------------------
			' 洗浄入口搬送待機
		case 202
			if 洗浄入口リフト排出要求=OFF and  洗浄入口搬送動作中=OFF then
				inc(洗浄入口リフトstep) '釜搬送
			else
				洗浄入口リフトstep=1
			end if

		case 203
			if not(PH43_釜検知) and not(PH44_フタ検知) then
				inc(洗浄入口リフトstep)
			end if				
		
		case 204
			tim_procstep_val=0
			res(tim_procstep)
			inc(洗浄入口リフトstep)

		case 205
			if tim_procstep.B then
				inc(洗浄入口リフトstep)
			end if

		case 206
			if PH48_釜検知 and PH49_フタ検知 then
				釜搬送中=ON
			else if not(PH48_釜検知) and PH49_フタ検知 then
				釜搬送中=OFF
			end if
			inc(洗浄入口リフトstep) '釜搬送
		
			'------------------------------------------------------
			' 釜搬送
		case 207
			MC30_搬送モータstep=1
			inc(洗浄入口リフトstep)
		
		case 208
			if MC30_搬送モータstep=0 then
				inc(洗浄入口リフトstep)
			end if
		
		case 209
			搬送コンベアF排出要求=OFF
			洗浄入口リフト動作中=OFF
			洗浄入口リフトstep=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		洗浄入口搬送AutoRun=OFF
		
		洗浄入口リフトstep=0 '終了
	
		res(timerr_MC30_搬送モータ)
		res(timerr_MC33_搬送モータ)
		
		
		if ldp(pnlPBMC30_搬送モータ) then
			if mMC30_搬送モータ then
				mMC30_搬送モータ=OFF
			else 'if XSW72_リフト上昇端 then
				mMC30_搬送モータ=ON
			end if
		end if
		

	end if '洗浄入口リフトAutoMode and not(洗浄入口リフトOrgErrStep)

	'===================================================================================================================
	'【 洗浄入口リフトOrgErr処理 】
	else
	
		if ResetFlg then
			洗浄入口リフトOrgErr=OFF
		end if

	end if
	
	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
		res(timerr_MC30_搬送モータ)
		res(timerr_MC33_搬送モータ)	
		
		コンベア一時停止中=ON
		alm渋滞警報=ON
		
		if ResetFlg then
			almMC30_搬送モータ=OFF
			almMC33_搬送モータ=OFF

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

		pauseMC30_搬送モータ=ON
		pauseMC33_搬送モータ=ON
		
		洗浄入口リフトErr=ON


		select case 洗浄入口リフトErrStep
		case 0
		case 1
			alm渋滞警報=ON

			if ResetFlg then
				alm渋滞警報=OFF
				inc(洗浄入口リフトErrStep)
			end if
		case 2

			pauseMC30_搬送モータ=OFF
			pauseMC33_搬送モータ=OFF

			洗浄入口リフトErr=OFF
			洗浄入口リフトErrStep=0
			
			洗浄入口リフトstep=0 '終了待機

		end select

	end if 'if 洗浄入口リフトErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else


	select case 洗浄入口リフトEmgStep
	case 0
	
	case 1
		洗浄入口リフトAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (洗浄入口リフトAutoMode and 自動搬送AutoMode ) or 洗浄入口リフトstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgMC30_搬送モータ=ON
			EmgMC33_搬送モータ=ON


			if timstack=OFF then
			
				tim_MC30_搬送モータ_stack.U=tim_MC30_搬送モータ.U
				tim_procstep_stack.U=tim_procstep.U
			' tmr(tim_MC30_搬送モータ,tim_MC30_搬送モータ_val)
			' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC30_搬送モータ=OFF
			
			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄入口リフトEmgStep)
	case 2
		if ResetFlg then
			inc(洗浄入口リフトEmgStep)
		end if
	case 3
		if (洗浄入口リフトAutoMode and 自動搬送AutoMode ) or 洗浄入口リフトstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				EmgMC30_搬送モータ=OFF
				EmgMC33_搬送モータ=OFF
				
				tim_MC30_搬送モータ.U=tim_MC30_搬送モータ_stack.U
				tim_procstep.U=tim_procstep_stack.U
				' tmr(tim_MC30_搬送モータ,tim_MC30_搬送モータ_val)
				' tmr(tim_procstep,tim_procstep_val)

				'検出タイマーのリセット

				'---------------------------------
				inc(洗浄入口リフトEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(洗浄入口リフトEmgStep)		
		end if				
	case 4
		timstack=OFF
		洗浄入口リフトEmgStep=0
		洗浄入口リフトEmg=OFF
	end select
		
end if 'if 洗浄入口リフトEmgStep=0 then
