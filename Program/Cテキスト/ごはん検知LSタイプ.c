'ごはん検知LSタイプ
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'LSタイプ

'XSW73_シリンダ上昇端		ビット	R43000
'XSW80_シリンダ下降端		ビット	R43001
'DLR1_ごはん検知 			ビット	R43002		*pLS4_ごはん検知
'DLR1_ごはん検知安定動作	ビット	R43003
'DLR2_ごはん検知			ビット	R43004
'DLR2_ごはん検知安定動作	ビット	R43005
'DLR3_ごはん検知			ビット	R43006
'DLR3_ごはん検知安定動作	ビット	R43007
'SV58_シリンダ				ビット	R46800
'送風ファン					ビット	R46801


ADRSET(DLR1_ごはん検知.B,pLS4_ごはん検知.D)

'===================================================================================================================
'
'	ごはん検知ユニット
'	
'===================================================================================================================
'【 初期化処理 】
if CR2008 then
    ごはん検知AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    ごはん検知AutoRun=OFF
    ごはん検知許可=ON
    ごはん検知OrgErr=OFF
    ごはん検知Err=OFF
    ごはん検知Emg=OFF
    ごはん検知step=0
    ごはん検知ErrStep=0
    ごはん検知OrgErrStep=0
    ごはん検知EmgStep=0
end if
'===================================================================================================================
'【 原点 】
ごはん検知Org=(XSW73_シリンダ上昇端 and not(pnlPBXSW73_シリンダ上昇端)) or passXSW73_シリンダ上昇端
ごはん検知Org=ごはん検知Org or ごはん検知禁止
'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	ごはん検知Emg=ON
	ごはん検知EmgStep=1
end if

if not(ごはん検知禁止) then
	強制ごはん有り=OFF
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(SV58_シリンダ and not(XSW80_シリンダ下降端) and not(pnlPBXSW80_シリンダ下降端),tim_notXSW80_シリンダ下降端,#50)
tmr(not(SV58_シリンダ) and not(XSW73_シリンダ上昇端) and not(pnlPBXSW73_シリンダ上昇端),tim_notXSW73_シリンダ上昇端,#50)

tms(SV58_シリンダ,passtimXSW80_シリンダ下降端,passtimXSW80_シリンダ下降端_val)
tms(not(SV58_シリンダ),passtimXSW73_シリンダ上昇端,passtimXSW73_シリンダ上昇端_val)

if LDP(SV58_シリンダ) and XSW80_シリンダ下降端 and not(pnlPBXSW80_シリンダ下降端) then
	SET(tim_XSW80_シリンダ下降端)
end if
if LDF(SV58_シリンダ) and XSW73_シリンダ上昇端 and not(pnlPBXSW73_シリンダ上昇端) then
	SET(tim_XSW73_シリンダ上昇端)
end if

if not(ごはん検知禁止) then
	if (ldp(tim_XSW80_シリンダ下降端.B) or ldp(tim_notXSW80_シリンダ下降端.B)) and not(pnlPBXSW80_シリンダ下降端) then
		almXSW80_シリンダ下降端=ON
		pnlPBXSW80_シリンダ下降端=ON
		if tim_XSW80_シリンダ下降端 then
			res(tim_XSW80_シリンダ下降端)
		end if
		ごはん検知ErrStep=1

	else if (ldp(tim_XSW73_シリンダ上昇端.B) or ldp(tim_notXSW73_シリンダ上昇端.B)) and not(pnlPBXSW73_シリンダ上昇端) then
		almXSW73_シリンダ上昇端=ON
		pnlPBXSW73_シリンダ上昇端=ON
		if tim_XSW73_シリンダ上昇端 then
			res(tim_XSW73_シリンダ上昇端)
		end if
		ごはん検知ErrStep=1
	end if
else
	res(tim_XSW80_シリンダ下降端)
	res(tim_XSW73_シリンダ上昇端)

	res(tim_notXSW80_シリンダ下降端)
	res(tim_notXSW73_シリンダ上昇端)
end if

tmr(*pLS4_ごはん検知.B,timdly_LS4_ごはん検知,#4) 'チャタリング防止
tmr(not(*pLS4_ごはん検知.B),timnotdly_LS4_ごはん検知,#4) 'チャタリング防止

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: ごはん検知AutoMode	自動モード セレクトスイッチ
'System :: ごはん検知AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: ごはん検知Emg	その場停止

if ごはん検知EmgStep=0 then  
	
	if ごはん検知ErrStep=0  then

	if not(ごはん検知OrgErr) then

	if (ごはん検知AutoMode and 自動搬送AutoMode ) or ごはん検知step<>0 then
	
		if not(ごはん検知AutoMode and 自動搬送AutoMode ) then
			ごはん検知AutoRun=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ごはん検知step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if ごはん検知AutoRun  then

				ごはん検知StatusMsg=#50	'	待機中
				inc(ごはん検知step)
			else
				
				ごはん検知step=0 '終了待機
			end if
		case 2
				inc(ごはん検知step)
		
		case 3
		' [ 蓋カマ移動停止確認 ]
			if ごはん検知排出要求=OFF and  搬送コンベアD動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH25_釜検知 and PH26_フタ検知 then
						inc(ごはん検知step) 'プロセス処理
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH25_釜検知) and PH26_フタ検知 then 
							ごはん検知排出要求=ON
							ごはん検知step=1
				
				'[ 自ステージに"釜フタ"なし ]
					else
							ごはん検知排出要求=ON
							ごはん検知step=1  '終了
					end if
			
			else
			
				ごはん検知step=1
			
			end if
		
		case 4
		' [ ユニット許可検出 ]
			if not(ごはん検知禁止) then
				ごはん検知step=100 'プロセス処理
			else
				ごはん検知=強制ごはん有り
				ごはん検知排出要求=ON
				ごはん検知step=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
		
			if ごはん検知完了 then '搬送移動でOFF
				ごはん検知排出要求=ON
				ごはん検知step=1
			else
				ごはん検知=OFF
				inc(ごはん検知step)
			end if
		case 101
			if (XSW73_シリンダ上昇端 and not(pnlPBXSW73_シリンダ上昇端)) or passXSW73_シリンダ上昇端 then
				inc(ごはん検知step)
			else
				ごはん検知OrgErr=ON
			end if
				
		case 102
			mSV58_シリンダ=ON
			inc(ごはん検知step)
		
		case 103
			if (XSW80_シリンダ下降端 and not(pnlPBXSW80_シリンダ下降端)) or passXSW80_シリンダ下降端 then
				inc(ごはん検知step)
			end if

		case 104
			tim_procstep_val=15
			res(tim_procstep)
			res(timdly_LS4_ごはん検知)
			res(timnotdly_LS4_ごはん検知)			
			inc(ごはん検知step)

		case 105
			if timdly_LS4_ごはん検知.B then
				ごはん検知=ON
			else if timnotdly_LS4_ごはん検知.B then
				ごはん検知=OFF
			end if

			if tim_procstep.B or ((timdly_LS4_ごはん検知.B and ごはん検知) or (timnotdly_LS4_ごはん検知.B and not(ごはん検知)))  then
				inc(ごはん検知step)
			end if
		
		
		case 106
			tim_procstep_val=0 
			res(tim_procstep)
			inc(ごはん検知step)
			
		case 107
			if tim_procstep.B then
				inc(ごはん検知step)
			end if

		case 108
			mSV58_シリンダ=OFF
			inc(ごはん検知step)
		
		case 109
			if (XSW73_シリンダ上昇端 and not(pnlPBXSW73_シリンダ上昇端)) or passXSW73_シリンダ上昇端 then
				inc(ごはん検知step)
			end if	
		
		case 110
			tim_procstep_val=#0 '上昇端安定時間
			res(tim_procstep)
			inc(ごはん検知step)
			
		case 111
			if tim_procstep.B then
				ごはん検知step=199
			end if
			
		case 199
			ごはん検知完了=ON
			ごはん検知排出要求=ON
			ごはん検知step=1

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if ldp(pnlPBSV58_シリンダ) then
			if mSV58_シリンダ then
				mSV58_シリンダ=OFF
			else
				mSV58_シリンダ=ON
			end if
		end if
		
	
	end if 'ごはん検知AutoMode and not(ごはん検知OrgErrStep)

	'===================================================================================================================
	'【 ごはん検知OrgErr処理 】
	else
		if ResetFlg then
			ごはん検知OrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		ごはん検知Err=ON
		
		select case ごはん検知ErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW80_シリンダ下降端=OFF
				almXSW73_シリンダ上昇端=OFF
				inc(ごはん検知ErrStep)
			end if
		case 2
			
			res(tim_XSW80_シリンダ下降端)
			res(tim_XSW73_シリンダ上昇端)
			
			res(tim_notXSW80_シリンダ下降端)
			res(tim_notXSW73_シリンダ上昇端)

			ごはん検知Err=OFF
			ごはん検知ErrStep=0
		end select

	end if 'if ごはん検知ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case ごはん検知EmgStep
	case 0
	
	case 1
		ごはん検知AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (ごはん検知AutoMode and 自動搬送AutoMode ) or ごはん検知step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV58_シリンダ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(ごはん検知EmgStep)
	case 2
		if ResetFlg then
			inc(ごはん検知EmgStep)
		end if
	case 3
		if (ごはん検知AutoMode and 自動搬送AutoMode ) or ごはん検知step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				
				
				'---------------------------------
				inc(ごはん検知EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(ごはん検知EmgStep)		
		end if				
	case 4
		timstack=OFF
		ごはん検知EmgStep=0
		ごはん検知Emg=OFF
	end select
		
end if 'if ごはん検知EmgStep=0 then
