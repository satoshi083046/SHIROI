'洗浄入口搬送
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	洗浄入口搬送
'	
'===================================================================================================================
'
'釜反転機禁止時
'	  釜：カニ爪に釜が入ったら反転モータを回さない。”洗浄機にあるスイッチ”により反転が終了したことを指示する
'			反転モータ正転ON、OFF 反転モータ逆転ON.OFFをパスする。
'			釜反転入口釜搬送中=ON  洗浄機にあるスイッチのランプを点滅
'			”洗浄機にあるスイッチ”=ON and PH45_釜検知 and PH46_フタ検知 により動作終了。
' 	フタ：通常通りの動作をし、通常通りに終了させる。
'
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    洗浄入口搬送AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    洗浄入口搬送AutoRun=OFF
    洗浄入口搬送許可=ON
    洗浄入口搬送OrgErr=OFF
    洗浄入口搬送Err=OFF
    洗浄入口搬送Emg=OFF
    洗浄入口搬送step=0
    洗浄入口搬送ErrStep=0
    洗浄入口搬送OrgErrStep=0
    洗浄入口搬送EmgStep=0
	
	MC31_反転モータ正転step=0
	MC31_反転モータ逆転step=0
	MC33_搬送モータstep=0
	INV1_コンベアモータ正転step=0
	
end if
'===================================================================================================================
'【 原点 】
洗浄入口搬送Org=LS7_釜反転機原点位置 or pnlPBLS7_釜反転機原点位置

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	洗浄入口搬送Emg=ON
	洗浄入口搬送EmgStep=1
end if


'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(MC31_反転モータ正転 and not(pnlPBLS8_釜反転機反転位置) ,tim_LS8_釜反転機反転位置,#60)
tmr(MC31_反転モータ逆転 and not(pnlPBLS7_釜反転機原点位置),tim_LS7_釜反転機原点位置,#60)
tmr(mMC33_搬送モータ and not(pauseMC33_搬送モータ) and not(EmgMC33_搬送モータ),timerr_MC33_搬送モータ,#80)
tmr(ejectINV1_コンベアモータ正転 and not(pauseINV1_コンベアモータ正転) and not(EmgINV1_コンベアモータ正転),timerr_INV1_コンベアモータ正転,#80)

if ldp(timerr_MC33_搬送モータ.B) then
	almMC33_搬送モータ=ON
	
	mMC33_搬送モータ=OFF
	ejectINV1_コンベアモータ正転=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_INV1_コンベアモータ正転.B) then
	almINV1_コンベアモータ正転=ON
	
	mMC33_搬送モータ=OFF
	ejectINV1_コンベアモータ正転=OFF
	
	コンベア一時停止=ON

end if


if (LS7_釜反転機原点位置 and not(pnlPBLS7_釜反転機原点位置)) and (LS8_釜反転機反転位置 and not(pnlPBLS8_釜反転機反転位置)) then
	errpassLS8_釜反転機反転位置=ON
	errpassLS7_釜反転機原点位置=ON
	mMC31_反転モータ逆転=OFF
	mMC31_反転モータ正転=OFF
	almLS8_釜反転機反転位置=ON
	almLS7_釜反転機原点位置=ON
	almMC31_反転モータ正転=ON
	almMC31_反転モータ逆転=ON
	
	洗浄入口搬送ErrStep=1

else if ldp(tim_LS8_釜反転機反転位置.B) then
	mMC31_反転モータ正転=OFF
	mMC31_反転モータ逆転=OFF
	almMC31_反転モータ正転=ON
	errpassLS8_釜反転機反転位置=ON
	洗浄入口搬送ErrStep=1
else if ldp(tim_LS7_釜反転機原点位置.B) then
	mMC31_反転モータ正転=OFF
	mMC31_反転モータ逆転=OFF
	almMC31_反転モータ逆転=ON
	errpassLS7_釜反転機原点位置=ON
	洗浄入口搬送ErrStep=1
end if


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗浄入口搬送AutoMode	自動モード セレクトスイッチ
'System :: 洗浄入口搬送AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗浄入口搬送Emg	その場停止


if 洗浄入口搬送EmgStep=0 then  
	
	if 洗浄入口搬送ErrStep=0  then
	
	if not(コンベア一時停止) then

	if not(洗浄入口搬送OrgErr) then

	
	'------------------------------------------------------------------------------------------------
	'釜反転装置正転
	tmr(tim_MC31_反転モータ正転,tim_MC31_反転モータ正転_val)
	
	select case MC31_反転モータ正転step
	
	case 0
	
	case 1
		mMC31_反転モータ正転=ON
		mMC31_反転モータ逆転=OFF
		errpassLS8_釜反転機反転位置=OFF
		inc(MC31_反転モータ正転step)
		
	
	case 2
		if LS8_釜反転機反転位置 or errpassLS8_釜反転機反転位置 or pnlPBLS8_釜反転機反転位置 then
			inc(MC31_反転モータ正転step)
		end if
	
	case 3
		mMC31_反転モータ正転=OFF
		inc(MC31_反転モータ正転step)
	
	case 4
		MC31_反転モータ正転step=0
		
	end select

	'------------------------------------------------------------------------------------------------
	'釜反転装置逆転
	tmr(tim_MC31_反転モータ逆転,tim_MC31_反転モータ逆転_val)
	
	select case MC31_反転モータ逆転step
	
	case 0
	
	case 1
		mMC31_反転モータ正転=OFF
		mMC31_反転モータ逆転=ON
		errpassLS7_釜反転機原点位置=OFF
		inc(MC31_反転モータ逆転step)

	case 2
		if LS7_釜反転機原点位置 or errpassLS7_釜反転機原点位置 or pnlPBLS7_釜反転機原点位置 then
			inc(MC31_反転モータ逆転step)
		end if

	case 3
		mMC31_反転モータ逆転=OFF
		inc(MC31_反転モータ逆転step)
		
	case 4
		MC31_反転モータ逆転step=0
		
	end select
	'------------------------------------------------------------------------------------------------
	'MC33_搬送モータ
	tmr(tim_MC33_搬送モータ,tim_MC33_搬送モータ_val)
	
	select case MC33_搬送モータstep
	
	case 0
	
	case 1
		mMC33_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC33_搬送モータstep)

	case 2
		if errpassコンベア一時停止 then
			inc(MC33_搬送モータstep)
		
		else if not(PH43_釜検知) and not(PH44_フタ検知) then
			inc(MC33_搬送モータstep)
		end if	

	case 3
		if errpassコンベア一時停止 then
			inc(MC33_搬送モータstep)
		
		else if PH45_釜検知 or PH46_フタ検知 then
			inc(MC33_搬送モータstep)
		end if	

	case 4
		tim_MC33_搬送モータ_val=10
		res(tim_MC33_搬送モータ)
		inc(MC33_搬送モータstep)
		
	case 5
		if tim_MC33_搬送モータ.B then
			inc(MC33_搬送モータstep)
		end if

	case 6
		mMC33_搬送モータ=OFF
		inc(MC33_搬送モータstep)
	
	case 7
		MC33_搬送モータstep=0
	
	end select
	'------------------------------------------------------------------------------------------------
	'INV1_コンベアモータ正転
	tmr(tim_INV1_コンベアモータ正転,tim_INV1_コンベアモータ正転_val)
	tmr(tim_洗浄工程終了,tim_洗浄工程終了_val)
	
	select case INV1_コンベアモータ正転step
	
	case 0
	
	case 1
		if 釜搬送中 then
			setS05c1=4000
		else
			setS05c1=6500
		end if
		
		inc(INV1_コンベアモータ正転step)


	case 2
		ejectINV1_コンベアモータ正転=ON
		errpassコンベア一時停止=OFF
		
		if 釜搬送中 then
			tim_洗浄工程終了_val=0
			if pnlPBLS7_釜反転機原点位置 or pnlPBLS8_釜反転機反転位置 then
				ejectINV1_コンベアモータ正転=OFF
			else
				tim_INV1_コンベアモータ正転_val=INV1釜排出時間 '1号機(27)  2号機(43)
			end if			
		else
			tim_洗浄工程終了_val=40
			tim_INV1_コンベアモータ正転_val=INV1フタ排出時間 '1号機(80)  2号機(83)->(78)
		end if

		res(tim_洗浄工程終了)
		res(tim_INV1_コンベアモータ正転)
		inc(INV1_コンベアモータ正転step)
		
	case 3
		if not(釜搬送中) and tim_洗浄工程終了.B then
			洗浄工程終了=ON '事前に洗浄ユニットの工程を終了させる。
		end if			
	
		if tim_INV1_コンベアモータ正転.B then
			inc(INV1_コンベアモータ正転step)
		end if

	case 4
		釜搬送中=OFF
		ejectINV1_コンベアモータ正転=OFF
		inc(INV1_コンベアモータ正転step)
	
	case 5
		tim_INV1_コンベアモータ正転_val=5
		res(tim_INV1_コンベアモータ正転)
		inc(INV1_コンベアモータ正転step)
	
	case 6
		if tim_INV1_コンベアモータ正転.B then
			inc(INV1_コンベアモータ正転step)
		end if
	
	case 7
		INV1_コンベアモータ正転step=0
	
	end select
	'------------------------------------------------------------------------------------------------

	if (洗浄入口搬送AutoMode and 自動搬送AutoMode ) or 洗浄入口搬送step<>0 then
	
		if not(洗浄入口搬送AutoMode and 自動搬送AutoMode ) then
			洗浄入口搬送AutoRun=OFF
		end if

	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 洗浄入口搬送step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 洗浄入口搬送AutoRun then
				inc(洗浄入口搬送step)
			else 
				洗浄入口搬送step=0 '終了待機
			end if
	
		case 2
			if PH45_釜検知 or PH46_フタ検知 or shiftreg釜フタ判定0<>0 then '洗浄コンベア上のワーク搬送
				洗浄入口搬送排出要求=ON
				洗浄入口搬送動作中=OFF
				洗浄入口搬送step=1
			else
				inc(洗浄入口搬送step)
			end if

		case 3
			if 洗浄入口搬送排出要求=OFF and  洗浄コンベア搬送動作中=OFF and 洗浄入口リフト排出要求 then
				errpassコンベア一時停止=OFF
				洗浄入口搬送step=100
			else
				洗浄入口搬送step=1
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 100
			if not(LS7_釜反転機原点位置 or pnlPBLS7_釜反転機原点位置) then 
				洗浄入口搬送step=1

			else if PH43_釜検知 or PH44_フタ検知 then 'チェーン搬送コンベアのワーク搬送
				洗浄入口搬送動作中=ON
				inc(洗浄入口搬送step)

			else
				洗浄入口リフト排出要求=OFF
				洗浄入口搬送step=1
			end if
			
		'--------------------------------------------------------------------------------------------------------------
		case 101
			if PH43_釜検知 and PH44_フタ検知 then
				inc(洗浄入口搬送step) '釜搬送
			else if not(PH43_釜検知) and PH44_フタ検知 then
				洗浄入口搬送step=150 'フタ搬送
			end if

		'--------------------------------------------------------------------------------------------------------------
		'釜搬送
		case 102
			釜搬送中=ON
			'mMC33_搬送モータ=ON
			tim_procstep_val=5 '釜挿入時間
			res(tim_procstep)
			inc(洗浄入口搬送step)
		
		case 103
			if tim_procstep.B then
				'mMC33_搬送モータ=OFF
				inc(洗浄入口搬送step)
			end if
		
		case 104
			MC31_反転モータ正転step=1
			inc(洗浄入口搬送step)
		
		case 105
			if MC31_反転モータ正転step=0 then
				洗浄工程終了=ON
				inc(洗浄入口搬送step)
			end if
		
		case 106
			tim_procstep_val=10
			res(tim_procstep)
			inc(洗浄入口搬送step)

		case 107
			if tim_procstep.B then
				inc(洗浄入口搬送step)
			end if			
		
		case 108
			if not(errpassLS8_釜反転機反転位置) then
				INV1_コンベアモータ正転step=1
			end if
			inc(洗浄入口搬送step)
		
		case 109
			if INV1_コンベアモータ正転step=0 then
				tim_procstep_val=5 '
				res(tim_procstep)
				inc(洗浄入口搬送step)
			end if
		
		case 110
			if tim_procstep.B then
				'mMC33_搬送モータ=OFF
				inc(洗浄入口搬送step)
			end if
			
		case 111
			洗浄入口搬送排出要求=ON '洗浄コンベア：起動
			MC31_反転モータ逆転step=1
			inc(洗浄入口搬送step)

		case 112
			if MC31_反転モータ逆転step=0 then
				inc(洗浄入口搬送step)
			end if
						
		case 113
			洗浄入口リフト排出要求=OFF	'洗浄入口リフト：リフト下降
			洗浄入口搬送動作中=OFF
			洗浄入口搬送step=1

		'------------------------------------
		'フタ搬送
		case 150
			MC33_搬送モータstep=1
			INV1_コンベアモータ正転step=1
			inc(洗浄入口搬送step)
		
		case 151
			if MC33_搬送モータstep=0 and INV1_コンベアモータ正転step=0 then
				inc(洗浄入口搬送step)
			end if
		
		case 152
			洗浄入口リフト排出要求=OFF	'洗浄入口リフト：リフト下降
			洗浄入口搬送排出要求=ON
			洗浄入口搬送動作中=OFF
			洗浄入口搬送step=1
		'--------------------------------------------------------------------------------------------------------------
			
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		洗浄入口搬送AutoRun=OFF
		
		洗浄入口搬送step=0 '終了

		res(timerr_MC33_搬送モータ)
		res(timerr_INV1_コンベアモータ正転)
		
		if ldp(pnlPBMC33_搬送モータ) then
			if mMC33_搬送モータ then
				mMC33_搬送モータ=OFF
			else
				mMC33_搬送モータ=ON
			end if
		end if
		
		
		if ldp(pnlPBMC31_反転モータ正転) then
			'if LS7_釜反転機原点位置 then
				if mMC31_反転モータ正転 then
					mMC31_反転モータ正転=OFF
				else if not(mMC31_反転モータ逆転) and not(PH45_釜検知) and not(PH46_フタ検知) then
					mMC31_反転モータ正転=ON
					mMC31_反転モータ逆転=OFF
				end if
			'end if
		else if ldp(pnlPBMC31_反転モータ逆転) then
			'if LS8_釜反転機反転位置 then
				if mMC31_反転モータ逆転 then
					mMC31_反転モータ逆転=OFF
				else if not(mMC31_反転モータ正転) and not(PH44_フタ検知) and not(PH43_釜検知) then
					mMC31_反転モータ正転=OFF
					mMC31_反転モータ逆転=ON
				end if
			'end if
		end if
		if mMC31_反転モータ正転 and LS8_釜反転機反転位置 then
			mMC31_反転モータ正転=OFF
		end if
		if mMC31_反転モータ逆転 and LS7_釜反転機原点位置 then
			mMC31_反転モータ逆転=OFF
		end if


	end if '洗浄入口搬送AutoMode and not(洗浄入口搬送OrgErrStep)

	'===================================================================================================================
	'【 洗浄入口搬送OrgErr処理 】
	else
		if ResetFlg then
			洗浄入口搬送OrgErr=OFF
		end if
	end if

	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
		res(timerr_MC33_搬送モータ)		
		res(timerr_INV1_コンベアモータ正転)
		
		コンベア一時停止中=ON
		alm渋滞警報=ON
		
		if ResetFlg then
			almMC33_搬送モータ=OFF
			almINV1_コンベアモータ正転=OFF

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

		洗浄入口搬送Err=ON

		mMC33_搬送モータ=OFF
		ejectINV1_コンベアモータ正転=OFF

		select case 洗浄入口搬送ErrStep
		case 0
		case 1
			alm渋滞警報=ON
	
			if ResetFlg then
				almLS8_釜反転機反転位置=OFF
				almLS7_釜反転機原点位置=OFF
				almMC31_反転モータ正転=OFF				
				almMC31_反転モータ逆転=OFF

				alm渋滞警報=OFF
				inc(洗浄入口搬送ErrStep)
			end if
		case 2
			洗浄入口搬送Err=OFF
			洗浄入口搬送ErrStep=0
		end select

	end if 'if 洗浄入口搬送ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else



	select case 洗浄入口搬送EmgStep
	case 0
	
	case 1
		洗浄入口搬送AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (洗浄入口搬送AutoMode and 自動搬送AutoMode ) or 洗浄入口搬送step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgINV1_コンベアモータ正転=ON
			EmgMC31_反転モータ逆転=ON
			EmgMC31_反転モータ正転=ON
			EmgMC33_搬送モータ=ON
			
			if timstack=OFF then
				
				tim_MC31_反転モータ正転_stack.U=tim_MC31_反転モータ正転.U
				tim_MC31_反転モータ逆転_stack.U=tim_MC31_反転モータ逆転.U
				tim_MC33_搬送モータ_stack.U=tim_MC33_搬送モータ.U
				tim_INV1_コンベアモータ正転_stack.U=tim_INV1_コンベアモータ正転.U
				tim_洗浄工程終了_stack.U=tim_洗浄工程終了.U
				tim_procstep_stack.U=tim_procstep.U
			' tmr(tim_MC31_反転モータ正転,tim_MC31_反転モータ正転_val)
			' tmr(tim_MC31_反転モータ逆転,tim_MC31_反転モータ逆転_val)
			' tmr(tim_MC33_搬送モータ,tim_MC33_搬送モータ_val)
			' tmr(tim_INV1_コンベアモータ正転,tim_INV1_コンベアモータ正転_val)
			' tmr(tim_洗浄工程終了,tim_洗浄工程終了_val)
			' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC33_搬送モータ=OFF
			mMC31_反転モータ正転=OFF
			mMC31_反転モータ逆転=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗浄入口搬送EmgStep)
	case 2
		if ResetFlg then
			inc(洗浄入口搬送EmgStep)
		end if
	case 3
		if (洗浄入口搬送AutoMode and 自動搬送AutoMode ) or 洗浄入口搬送step<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				EmgINV1_コンベアモータ正転=OFF
				EmgMC31_反転モータ逆転=OFF
				EmgMC31_反転モータ正転=OFF
				EmgMC33_搬送モータ=OFF
				
				tim_MC31_反転モータ正転.U=tim_MC31_反転モータ正転_stack.U
				tim_MC31_反転モータ逆転.U=tim_MC31_反転モータ逆転_stack.U
				tim_MC33_搬送モータ.U=tim_MC33_搬送モータ_stack.U
				if ejectINV1_コンベアモータ正転 then
					if 釜搬送中 then
						tim_INV1_コンベアモータ正転.U=tim_INV1_コンベアモータ正転_stack.U+17
					else
						tim_INV1_コンベアモータ正転.U=tim_INV1_コンベアモータ正転_stack.U+10
					end if					
				else
					tim_INV1_コンベアモータ正転.U=tim_INV1_コンベアモータ正転_stack.U				
				end if
				tim_洗浄工程終了.U=tim_洗浄工程終了_stack.U
				tim_procstep.U=tim_procstep_stack.U
				' tmr(tim_MC31_反転モータ正転,tim_MC31_反転モータ正転_val)
				' tmr(tim_MC31_反転モータ逆転,tim_MC31_反転モータ逆転_val)
				' tmr(tim_MC33_搬送モータ,tim_MC33_搬送モータ_val)
				' tmr(tim_INV1_コンベアモータ正転,tim_INV1_コンベアモータ正転_val)
				' tmr(tim_洗浄工程終了,tim_洗浄工程終了_val)
				' tmr(tim_procstep,tim_procstep_val)

				'検出タイマーのリセット

				'---------------------------------
				inc(洗浄入口搬送EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(洗浄入口搬送EmgStep)		
		end if				
	case 4
		timstack=OFF
		洗浄入口搬送EmgStep=0
		洗浄入口搬送Emg=OFF
	end select

end if 'if 洗浄入口搬送EmgStep=0 then
