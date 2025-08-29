'釜送りコンベア
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	釜送りコンベア
'	
'===================================================================================================================

'【 初期化処理 】
if CR2008 then
    釜送りコンベアAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    釜送りコンベアAutoRun=OFF
    釜送りコンベア許可=ON
    釜送りコンベアOrgErr=OFF
    釜送りコンベアErr=OFF
    釜送りコンベアEmg=OFF
    釜送りコンベアstep=0
    釜送りコンベアErrStep=0
    釜送りコンベアOrgErrStep=0
    釜送りコンベアEmgStep=0
		
	'釜送りコンベアインターバル時間=#200 '炊飯コンベア setS05c4=49.00Hz
	tim_notPH59_釜検知炊飯機入口stack=釜送りコンベアインターバル時間
	
	ManualInite=1

	
end if
'===================================================================================================================
'【 原点 】
釜送りコンベアOrg=LS10_釜送り後退端 or 釜送りコンベア禁止

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	釜送りコンベアEmg=ON
	釜送りコンベアEmgStep=1
end if

if 釜送りコンベア禁止 then
	mMC34_釜送り正転=OFF
	mMC34_釜送り逆転=OFF
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(mMC34_釜送り正転 and not(pauseMC34_釜送り正転) and not(EmgMC34_釜送り正転) and not(釜送りコンベア禁止),tim_LS9_釜送り前進端,#130)
tmr(mMC34_釜送り逆転 and not(pauseMC34_釜送り逆転) and not(EmgMC34_釜送り逆転) and not(釜送りコンベア禁止),tim_LS10_釜送り後退端,#130)
tmr(釜送りコンベアAutoRun and PH59_釜検知炊飯機入口 and not(MC34_釜送り正転) and not(釜送りコンベア禁止),tim_PH59_釜検知炊飯機入口,#180)

if ldp(tim_PH59_釜検知炊飯機入口.B) then
	almPH59_釜検知炊飯機入口=ON
	alm渋滞警報=ON			
'	pauseMC34_釜送り正転=ON
'	pauseMC34_釜送り逆転=ON

'	釜送りコンベアErrStep=1

else if LS9_釜送り前進端 and LS10_釜送り後退端 and not(釜送りコンベア禁止) then
	almLS9_釜送り前進端=ON
	almLS10_釜送り後退端=ON
	almMC34_釜送り正転=ON
	almMC34_釜送り逆転=ON

	釜送りコンベアErrStep=1

else if ldp(tim_LS10_釜送り後退端.B) then
	errpassMC34_釜送り逆転=ON
	almMC34_釜送り逆転=ON

	釜送りコンベアErrStep=1
else if ldp(tim_LS9_釜送り前進端.B) then
	errpassMC34_釜送り正転=ON
	almMC34_釜送り正転=ON
	
	釜送りコンベアErrStep=1
end if	

if almPH59_釜検知炊飯機入口=ON then
	if ResetFlg then
		almPH59_釜検知炊飯機入口=OFF
		alm渋滞警報=OFF			
	end if
end if

'------------------------------------------------------------------------------------------------------
'釜送りコンベアインターバル時間
'------------------------------------------------------------------------------------------------------
	if ldp(INV4_コンベア動作中) then
		tim_notPH59_釜検知炊飯機入口.D=tim_notPH59_釜検知炊飯機入口stack.D
	else if ldf(INV4_コンベア動作中) then
		tim_notPH59_釜検知炊飯機入口stack.D=tim_notPH59_釜検知炊飯機入口.D
	end if
	
	if INV4_コンベア動作中 then
		tmr(not(PH59_釜検知炊飯機入口),tim_notPH59_釜検知炊飯機入口,釜送りコンベアインターバル時間)
	end if
'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 釜送りコンベアAutoMode	自動モード セレクトスイッチ
'System :: 釜送りコンベアAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 釜送りコンベアEmg	その場停止


if 釜送りコンベアEmgStep=0 then  
	
	if 釜送りコンベアErrStep=0  then

	if not(釜送りコンベアOrgErr) then

	'--------------------------------------------
	' 釜送り正転逆転
	tmr(tim_MC34_釜送り,tim_MC34_釜送り_val)
	select case MC34_釜送りstep
	case 0
	case 1
		釜送りコンベア動作中=ON

		mMC34_釜送り正転=ON
		mMC43_乗移コンベア=ON
		errpassMC34_釜送り正転=OFF
		res(notdly_PH54_釜送りトリガ.B)
		inc(MC34_釜送りstep)
	
	case 2
		tmr(not(PH54_釜送りトリガ),notdly_PH54_釜送りトリガ,#10)
		
		if LS9_釜送り前進端 or (not(PH54_釜送りトリガ) and notdly_PH54_釜送りトリガ.B) then
			搬送コンベアC排出要求=OFF
			釜送りコンベア動作中=OFF
			inc(MC34_釜送りstep)
		end if
	
	case 3
		if errpassMC34_釜送り正転 then
			inc(MC34_釜送りstep)
		else if LS9_釜送り前進端 or PH55_釜検知ステージ then
			mMC43_乗移コンベア=OFF
			inc(MC34_釜送りstep)		
		end if
	
	case 4
		if errpassMC34_釜送り正転 then
			inc(MC34_釜送りstep)
		
		else if LS9_釜送り前進端 then
			inc(MC34_釜送りstep)
		end if
	
	case 5
		mMC34_釜送り正転=OFF
		inc(MC34_釜送りstep)
	
	case 6
		tim_MC34_釜送り_val=#10 '正転 Wait
		res(tim_MC34_釜送り)
		inc(MC34_釜送りstep)
	
	case 7
		if tim_MC34_釜送り.B then
			inc(MC34_釜送りstep)
		end if

	case 8
		mMC34_釜送り逆転=ON
		errpassMC34_釜送り逆転=OFF
		inc(MC34_釜送りstep)
	
	case 9
		if errpassMC34_釜送り逆転 then
			inc(MC34_釜送りstep)
		
		else if LS10_釜送り後退端 then
			inc(MC34_釜送りstep)
		end if			
	
	case 10
		mMC34_釜送り逆転=OFF
		tim_MC34_釜送り_val=#10
		res(tim_MC34_釜送り)
		inc(MC34_釜送りstep)
		
	case 11
		if tim_MC34_釜送り.B then
			MC34_釜送りstep=0
		end if
	end select
	
	'===================================================================================================================
	'【 リフタータスク 】
	'
	if (釜送りコンベアAutoMode and 自動搬送AutoMode ) or 釜送りコンベアstep<>0 then
	

		if not(釜送りコンベアAutoMode and 自動搬送AutoMode ) then
			釜送りコンベアAutoRun=OFF
		end if

		'------------------------------------------------------------------------------------------------------
		
		tmr(tim_procstep,tim_procstep_val)

		select case 釜送りコンベアstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]

			if 釜送りコンベアAutoRun then			
				if ManualInite=1 then
					ManualInite=0
				end if
				inc(釜送りコンベアstep)
			else 
				釜送りコンベアstep=0 '終了待機
			end if

		case 2
			if INV4_コンベア動作中 then
				inc(釜送りコンベアstep)			
			else
				搬送コンベアC排出要求=OFF
				釜送りコンベア動作中=OFF			
				釜送りコンベア排出要求=OFF
				釜送りコンベアstep=1			
			end if
			
		case 3
		' [ 搬送コンベア停止確認 ]
			if INV4_コンベア動作中 and 釜送りコンベア排出要求=OFF and  搬送コンベアC動作中=OFF and 搬送コンベアC排出要求=ON then
				inc(釜送りコンベアstep)
			else
				釜送りコンベアstep=1
			end if
		
		case 4
			if PH54_釜送りトリガ then
				inc(釜送りコンベアstep)
			else
				搬送コンベアC排出要求=OFF
				釜送りコンベア動作中=OFF			
				釜送りコンベア排出要求=OFF
				釜送りコンベアstep=1
			end if
			
		case 5  '原点検出
			if 釜送りコンベアOrg and not(釜送りコンベア禁止) then
				inc(釜送りコンベアstep)
			else
				釜送りコンベアstep=1
			end if
			
		case 6
			釜送りコンベアstep=100
		'--------------------------------------------------------------------------------------------------------------
		case 100			
			if not(PH59_釜検知炊飯機入口) then
				if tim_notPH59_釜検知炊飯機入口.B then
					inc(釜送りコンベアstep)
				else
					釜送りコンベアstep=1
				end if
			else
				釜送りコンベアstep=1
			end if
			
		case 101
			MC34_釜送りstep=1
			inc(釜送りコンベアstep)
		
		case 102		
			if 	MC34_釜送りstep=0  then
				inc(釜送りコンベアstep)
			end if		

		case 103
			釜送りコンベア排出要求=OFF '常時OFF；次のステージの炊飯コンベアは常時回転
			釜送りコンベアstep=1
		
		end select
		
		
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		釜送りコンベアAutoRun=OFF
		
		釜送りコンベアstep=0 '終了
		
		if ManualInite=0 then
			ManualInite=1
		end if

		
		'--------------------------------------------
		if ldp(pnlPBMC34_釜送り正転) then
			if mMC34_釜送り正転 then
					mMC34_釜送り正転=OFF
			
			else if not(mMC34_釜送り逆転) then
				if not(PH59_釜検知炊飯機入口) and not(PH55_釜検知ステージ) then
					mMC34_釜送り正転=ON
					mMC34_釜送り逆転=OFF
				end if
			end if
		
		else if ldp(pnlPBMC34_釜送り逆転)  then
			if mMC34_釜送り逆転 then			
					mMC34_釜送り逆転=OFF
					
			else if not(mMC34_釜送り正転) then
					mMC34_釜送り正転=OFF
					mMC34_釜送り逆転=ON
			end if
		end if
		
		if mMC34_釜送り正転 and LS9_釜送り前進端 then
			mMC34_釜送り正転=OFF
		end if
		if mMC34_釜送り逆転 and LS10_釜送り後退端 then
			mMC34_釜送り逆転=OFF
		end if
		'--------------------------------------------
		

	end if
	'===================================================================================================================
	'【 釜送りコンベアOrgErr処理 】
	else
	
		if ResetFlg then
			釜送りコンベアOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		釜送りコンベアErr=ON

		mMC34_釜送り正転=OFF
		mMC34_釜送り逆転=OFF
		mMC43_乗移コンベア=OFF

		res(tim_PH59_釜検知炊飯機入口)
		res(tim_LS10_釜送り後退端)
		res(tim_LS9_釜送り前進端)

		select case 釜送りコンベアErrStep
		case 0
		
		case 1
			alm渋滞警報=ON			

			if ResetFlg then
				almPH59_釜検知炊飯機入口=OFF
				almLS10_釜送り後退端=OFF
				almLS9_釜送り前進端=OFF
				almMC34_釜送り正転=OFF
				almMC34_釜送り逆転=OFF

				alm渋滞警報=OFF			

				inc(釜送りコンベアErrStep)
			end if
		
		case 2
			inc(釜送りコンベアErrStep)

		case 3
			MC34_釜送りstep=0
			釜送りコンベアErrStep=0
			釜送りコンベアErr=OFF

		end select

	end if 'if 釜送りコンベアErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 釜送りコンベアEmgStep
	case 0
	
	case 1
		釜送りコンベアAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (釜送りコンベアAutoMode and 自動搬送AutoMode ) or 釜送りコンベアstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgMC34_釜送り正転=ON
			EmgMC34_釜送り逆転=ON
			EmgMC43_乗移コンベア=ON
			
			if timstack=OFF then
			
				tim_notPH59_釜検知炊飯機入口_stack.U=tim_notPH59_釜検知炊飯機入口.U
				tim_MC34_釜送り_stack.U=tim_MC34_釜送り.U
				notdly_PH54_釜送りトリガ_stack.U=notdly_PH54_釜送りトリガ.U
				tim_procstep_stack.U=tim_procstep.U
				
				' tmr(not(PH59_釜検知炊飯機入口),tim_notPH59_釜検知炊飯機入口,m釜送りコンベアインターバル時間)
				' tmr(tim_MC34_釜送り,tim_MC34_釜送り_val)
				' tmr(not(PH54_釜送りトリガ),notdly_PH54_釜送りトリガ,#10)
				' tmr(tim_procstep,tim_procstep_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC34_釜送り正転=OFF
			mMC34_釜送り逆転=OFF
			mMC43_乗移コンベア=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(釜送りコンベアEmgStep)
	case 2
		if ResetFlg then
			inc(釜送りコンベアEmgStep)
		end if
	case 3
		if (釜送りコンベアAutoMode and 自動搬送AutoMode ) or 釜送りコンベアstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				EmgMC34_釜送り正転=OFF
				EmgMC34_釜送り逆転=OFF
				EmgMC43_乗移コンベア=OFF


				'スタックの値をタイマー現在値にリストア
				tim_notPH59_釜検知炊飯機入口.U=tim_notPH59_釜検知炊飯機入口_stack.U
				tim_MC34_釜送り.U=tim_MC34_釜送り_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				' tmr(not(PH59_釜検知炊飯機入口),tim_notPH59_釜検知炊飯機入口,m釜送りコンベアインターバル時間)
				' tmr(tim_MC34_釜送り,tim_MC34_釜送り_val)
				' tmr(tim_procstep,tim_procstep_val)
				
				'検出タイマーのリセット
				res(notdly_PH54_釜送りトリガ)
				
				' tmr(not(PH54_釜送りトリガ),notdly_PH54_釜送りトリガ,#10)

				'---------------------------------
				inc(釜送りコンベアEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(釜送りコンベアEmgStep)		
		end if				
	case 4
		timstack=OFF
		釜送りコンベアEmgStep=0
		釜送りコンベアEmg=OFF
	end select
		
end if 'if 釜送りコンベアEmgStep=0 then
