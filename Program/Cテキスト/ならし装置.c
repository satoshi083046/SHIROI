'ならし装置
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	ならしユニット
'	
'===================================================================================================================

'【 初期化処理 】

if CR2008 then
    ならし装置AutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    ならし装置AutoRun=OFF
    ならし装置許可=ON
    ならし装置OrgErr=OFF
    ならし装置Err=OFF
    ならし装置Emg=OFF
    ならし装置step=0
    ならし装置ErrStep=0
    ならし装置OrgErrStep=0
    ならし装置EmgStep=0
	
	ならし排出要求=ON
	
	SV23_ならし前進step=1
	SV24_ならし後退step=0

end if

'===================================================================================================================
'【 原点 】
ならし装置Org=(XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端
ならし装置Org=ならし装置Org and (XSW27_ならし後退端 and not(pnlPBXSW27_ならし後退端)) or passXSW27_ならし後退端
ならし装置Org=ならし装置Org or not(ならし装置許可)

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then	
	ならし装置Emg=ON
	ならし装置EmgStep=1
end if

'------------------------------------------------------
'しずく受けから離脱
tmr(tim_SV23_ならし前進,tim_SV23_ならし前進_val)
select case SV23_ならし前進step
case 0
case 1
	if not(XSW24_ならし前進端) or pnlPBXSW24_ならし前進端 then
		mSV23_ならし前進=ON
		mSV24_ならし後退=OFF
	end if
	
	inc(SV23_ならし前進step)
case 2
	if (XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端  then
		inc(SV23_ならし前進step)
	end if
case 3
	mSV23_ならし前進=OFF
	mSV24_ならし後退=OFF
	SV23_ならし前進step=0
end select
'------------------------------------------------------
'しずく受けに移動
tmr(tim_SV24_ならし後退,tim_SV24_ならし後退_val)
select case SV24_ならし後退step
case 0
case 1
	if not(XSW23_ならし後退端) or pnlPBXSW23_ならし後退端 then
		mSV23_ならし前進=OFF
		mSV24_ならし後退=ON
	end if
	inc(SV24_ならし後退step)
case 2
	if (XSW23_ならし後退端 and not(pnlPBXSW23_ならし後退端)) or passXSW23_ならし後退端 then
		inc(SV24_ならし後退step)	
	end if
case 3
	mSV23_ならし前進=OFF
	mSV24_ならし後退=OFF
	SV24_ならし後退step=0
end select
'------------------------------------------------------


'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】


tmr(SV23_ならし前進 and not(XSW24_ならし前進端) and not(pnlPBXSW24_ならし前進端),tim_notXSW24_ならし前進端,#60)
tmr(SV24_ならし後退 and not(XSW23_ならし後退端) and not(pnlPBXSW23_ならし後退端),tim_notXSW23_ならし後退端,#60)
tmr(SV25_ならし下降 and not(XSW26_ならし下降端) and not(pnlPBXSW26_ならし下降端),tim_notXSW26_ならし下降端,#80)
tmr(SV26_ならし上昇 and not(XSW25_ならし上昇端) and not(pnlPBXSW25_ならし上昇端),tim_notXSW25_ならし上昇端,#80)
tmr(SV27_ならし前進 and not(XSW28_ならし前進端) and not(pnlPBXSW28_ならし前進端),tim_notXSW28_ならし前進端,#80)
tmr(SV28_ならし後退 and not(XSW27_ならし後退端) and not(pnlPBXSW27_ならし後退端),tim_notXSW27_ならし後退端,#80)

if LDP(SV23_ならし前進) and XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端) then
	SET(tim_XSW24_ならし前進端)
end if
if LDP(SV24_ならし後退) and XSW23_ならし後退端 and not(pnlPBXSW23_ならし後退端) then
	SET(tim_XSW23_ならし後退端)
end if
if LDP(SV25_ならし下降) and XSW26_ならし下降端 and not(pnlPBXSW26_ならし下降端) then
	SET(tim_XSW26_ならし下降端)
end if
if LDP(SV26_ならし上昇) and XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端) then
	SET(tim_XSW25_ならし上昇端)
end if
if LDP(SV27_ならし前進) and XSW28_ならし前進端 and not(pnlPBXSW28_ならし前進端) then
	SET(tim_XSW28_ならし前進端)
end if
if LDP(SV28_ならし後退) and XSW27_ならし後退端 and not(pnlPBXSW27_ならし後退端) then
	SET(tim_XSW27_ならし後退端)
end if	

if SV23_ならし前進 and not(SV24_ならし後退) then
	KeepSV23_ならし前進=ON
	KeepSV24_ならし後退=OFF
else if SV24_ならし後退 and not(SV23_ならし前進) then
	KeepSV23_ならし前進=OFF
	KeepSV24_ならし後退=ON
end if

if SV25_ならし下降 and not(SV26_ならし上昇) then
	KeepSV25_ならし下降=ON
	KeepSV26_ならし上昇=OFF
else if SV26_ならし上昇 and not(SV25_ならし下降) then
	KeepSV25_ならし下降=OFF
	KeepSV26_ならし上昇=ON
end if

if SV27_ならし前進 and not(SV28_ならし後退) then
	KeepSV27_ならし前進=ON
	KeepSV28_ならし後退=OFF
else if SV28_ならし後退 and not(SV27_ならし前進) then
	KeepSV27_ならし前進=OFF
	KeepSV28_ならし後退=ON
end if


'passtimXSW24_ならし前進端_val=#3000
tms(KeepSV23_ならし前進,passtimXSW24_ならし前進端,passtimXSW24_ならし前進端_val)
'passtimXSW23_ならし後退端_val=#3000
tms(KeepSV24_ならし後退,passtimXSW23_ならし後退端,passtimXSW23_ならし後退端_val)
'passtimXSW26_ならし下降端_val=#3000
tms(KeepSV25_ならし下降,passtimXSW26_ならし下降端,passtimXSW26_ならし下降端_val)
'passtimXSW25_ならし上昇端_val=#3000
tms(KeepSV26_ならし上昇,passtimXSW25_ならし上昇端,passtimXSW25_ならし上昇端_val)
'passtimXSW28_ならし前進端_val=#3000
tms(KeepSV27_ならし前進,passtimXSW28_ならし前進端,passtimXSW28_ならし前進端_val)
'passtimXSW27_ならし後退端_val=#3000
tms(KeepSV28_ならし後退,passtimXSW27_ならし後退端,passtimXSW27_ならし後退端_val)



if ならし装置許可 then
	if (ldp(tim_XSW24_ならし前進端.B) or ldp(tim_notXSW24_ならし前進端)) and not(pnlPBXSW24_ならし前進端) then
		almXSW24_ならし前進端=ON
		pnlPBXSW24_ならし前進端=ON
		if tim_XSW24_ならし前進端 then
			res(tim_XSW24_ならし前進端)
		end if
		ならし装置ErrStep=1

	else if (ldp(tim_XSW23_ならし後退端.B) or ldp(tim_notXSW23_ならし後退端)) and not(pnlPBXSW23_ならし後退端) then	
		almXSW23_ならし後退端=ON
		pnlPBXSW23_ならし後退端=ON
		if tim_XSW23_ならし後退端 then
			res(tim_XSW23_ならし後退端)
		end if
		ならし装置ErrStep=1

	else if (ldp(tim_XSW26_ならし下降端.B) or ldp(tim_notXSW26_ならし下降端)) and not(pnlPBXSW26_ならし下降端) then
		almXSW26_ならし下降端=ON
		pnlPBXSW26_ならし下降端=ON
		if tim_XSW26_ならし下降端 then
			res(tim_XSW26_ならし下降端)
		end if
		ならし装置ErrStep=1

	else if (ldp(tim_XSW25_ならし上昇端.B) or ldp(tim_notXSW25_ならし上昇端)) and not(pnlPBXSW25_ならし上昇端) then
		almXSW25_ならし上昇端=ON
		pnlPBXSW25_ならし上昇端=ON
		if tim_XSW25_ならし上昇端 then
			res(tim_XSW25_ならし上昇端)
		end if
		ならし装置ErrStep=1

	else if (ldp(tim_XSW28_ならし前進端.B) or ldp(tim_notXSW28_ならし前進端)) and not(pnlPBXSW28_ならし前進端) then
		almXSW28_ならし前進端=ON
		pnlPBXSW28_ならし前進端=ON
		if tim_XSW28_ならし前進端 then
			res(tim_XSW28_ならし前進端)
		end if
		ならし装置ErrStep=1

	else if (ldp(tim_XSW27_ならし後退端.B) or ldp(tim_notXSW27_ならし後退端)) and not(pnlPBXSW27_ならし後退端) then
		almXSW27_ならし後退端=ON
		pnlPBXSW27_ならし後退端=ON
		if tim_XSW27_ならし後退端 then
			res(tim_XSW27_ならし後退端)
		end if
		ならし装置ErrStep=1

	end if
else
	res(tim_XSW24_ならし前進端)
	res(tim_XSW23_ならし後退端)
	res(tim_XSW26_ならし下降端)
	res(tim_XSW25_ならし上昇端)
	res(tim_XSW28_ならし前進端)
	res(tim_XSW27_ならし後退端)

	res(tim_notXSW24_ならし前進端)
	res(tim_notXSW23_ならし後退端)
	res(tim_notXSW26_ならし下降端)
	res(tim_notXSW25_ならし上昇端)
	res(tim_notXSW28_ならし前進端)
	res(tim_notXSW27_ならし後退端)
end if


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: ならし装置AutoMode	自動モード セレクトスイッチ
'System :: ならし装置AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: ならし装置Emg	その場停止


if ならし装置EmgStep=0 then  
	
	if ならし装置ErrStep=0  then

	if not(ならし装置OrgErr) then

	if (ならし装置AutoMode and 自動搬送AutoMode ) or ならし装置step<>0 then
		
	if not(ならし装置AutoMode and 自動搬送AutoMode ) then
			ならし装置AutoRUn=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ならし装置step
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
				ならし装置StatusMsg=#0
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if ならし装置AutoRun then
				ならし装置StatusMsg=#30	'	待機中
				SV24_ならし後退step=1
				inc(ならし装置step)
			else 
				SV23_ならし前進step=1
				ならし装置step=0 '終了待機 
			end if
		
		case 2
				if SV24_ならし後退step=0 then
					inc(ならし装置step)
				end if
		case 3
		' [ 蓋カマ移動停止確認 ]
			if ならし排出要求=OFF and  搬送コンベアC動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH17_釜検知 and PH18_フタ検知 then
						if ANDA(StageDevice8,$200)=$200 or ANDA(StageDevice8,$400)=$400 or 1 then 
							inc(ならし装置step) 'プロセス処理
						else
							ならし排出要求=ON
							ならし装置step=1						
						end if
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH17_釜検知) and PH18_フタ検知 then 
							ならし排出要求=ON
							ならし装置step=1
				
				'[ 自ステージに"釜フタ"なし ]
						else
							ならし排出要求=ON
							ならし装置step=1  '終了
					end if
			
			else
			
				ならし装置step=1
			
			end if
		
		case 4
			if ((XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端) and ((XSW27_ならし後退端 and not(pnlPBXSW27_ならし後退端)) or pnlPBXSW27_ならし後退端) then
				inc(ならし装置step)
			else
				ならし装置step=1
			end if

		case 5
		' [ ユニット許可検出 ]
			if ならし装置許可 then
				ならし装置step=100 'プロセス処理
			else
				ならし排出要求=ON
				ならし装置step=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100		
			if ならし完了 then '搬送移動でOFF
				ならし装置step=199
			else
				inc(ならし装置step)
			end if
				
		case 101
			ならし装置StatusMsg=#31	'	ならし中
			
			DM_ならし回数現在値=0
			mSV23_ならし前進=ON	'しずく受けから離脱
			inc(ならし装置step)
			
		case 102
			if (XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端  then
				inc(ならし装置step)
			end if
		
		case 103
			mSV23_ならし前進=OFF				
			tim_procstep_val=#0
			res(tim_procstep)
			inc(ならし装置step)

		case 104
			if tim_procstep.B then
				inc(ならし装置step)
			end if
				
		case 105
			mSV25_ならし下降=ON
			inc(ならし装置step)

		case 106
			if (XSW26_ならし下降端 and not(pnlPBXSW26_ならし下降端)) or passXSW26_ならし下降端 then
				inc(ならし装置step)
			end if
		
		case 107
			mSV25_ならし下降=OFF				
			tim_procstep_val=#0
			res(tim_procstep)
			inc(ならし装置step)
			
		case 108
			if tim_procstep.B then		
				inc(ならし装置step)
			end if
		
		case 109
			inc(ならし装置step)
		
		'----------------------------------------------------
		case 110 'ならしループ  <-
			if DM_ならし回数現在値 < DM_ならし回数設定値 then
				inc(ならし装置step)
			else 
				ならし装置step=150
			end if
		
		case 111
			mSV27_ならし前進=ON
			inc(ならし装置step)
		
		case 112
			if (XSW28_ならし前進端 and not(pnlPBXSW28_ならし前進端)) or passXSW28_ならし前進端 then
				inc(ならし装置step)
			end if	
		
		case 113
			mSV27_ならし前進=OFF
			tim_procstep_val=#5
			res(tim_procstep)
			inc(ならし装置step)

		case 114
			if tim_procstep.B then
				inc(ならし装置step)
			end if
			
		case 115
			mSV28_ならし後退=ON
			inc(ならし装置step)
			
		case 116
			if (XSW27_ならし後退端 and not(pnlPBXSW27_ならし後退端)) or passXSW27_ならし後退端 then
				inc(ならし装置step)
			end if
		
		case 117
			mSV28_ならし後退=OFF
			tim_procstep_val=#5
			res(tim_procstep)
			inc(ならし装置step)

		case 118
			if tim_procstep.B then
				inc(DM_ならし回数現在値)
				ならし装置step=110 'ならしループ ->
			end if
		'----------------------------------------------------			
		case 150
			mSV26_ならし上昇=ON
			inc(ならし装置step)
			
		case 151
			if (XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端 then
				inc(ならし装置step)
			end if
		
		case 152
			mSV26_ならし上昇=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			inc(ならし装置step)
			
			ならし完了=ON
			ならし排出要求=ON

		
		case 153
			if tim_procstep.B then
				inc(ならし装置step)
			end if
		
		case 154
			mSV23_ならし前進=OFF	'しずく受けに移動
			mSV24_ならし後退=ON
			inc(ならし装置step)
			
		case 155
			if (XSW23_ならし後退端 and not(pnlPBXSW23_ならし後退端)) or passXSW23_ならし後退端 then
				inc(ならし装置step)
			end if

		case 156
			mSV24_ならし後退=OFF
			tim_procstep_val=#0
			res(tim_procstep)
			ならし装置step=199

		case 199
			ならし装置step=1

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		ならし装置AutoRun=OFF
		
		ならし装置step=0 '終了
		ならし完了=OFF

		'---------------------------------------------------------
		if ldp(pnlPBSV23_ならし前進)  then
			if ((XSW23_ならし後退端 and not(pnlPBXSW23_ならし後退端)) or passXSW23_ならし後退端) and ((XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端)then
				mSV23_ならし前進=ON
				mSV24_ならし後退=OFF		
			end if
		end if
		if ldp(pnlPBSV24_ならし後退)  then
			if ((XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端) and ((XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端) then
				mSV23_ならし前進=OFF
				mSV24_ならし後退=ON
			end if
		end if
		if mSV23_ならし前進 and ((XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端) then
			mSV23_ならし前進=OFF
		end if 
		if mSV24_ならし後退 and ((XSW23_ならし後退端 and not(pnlPBXSW23_ならし後退端)) or passXSW23_ならし後退端) then 
			mSV24_ならし後退=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBSV25_ならし下降) then
			if ((XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端) and ((XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端) then
				mSV25_ならし下降=ON
				mSV26_ならし上昇=OFF
			end if
		end if
		if ldp(pnlPBSV26_ならし上昇) then
			if ((XSW26_ならし下降端 and not(pnlPBXSW26_ならし下降端)) or passXSW26_ならし下降端) and ((XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端) then
				mSV25_ならし下降=OFF
				mSV26_ならし上昇=ON
			end if
		end if
		if mSV25_ならし下降 and ((XSW26_ならし下降端 and not(pnlPBXSW26_ならし下降端)) or passXSW26_ならし下降端) then
			mSV25_ならし下降=OFF
		end if
		if mSV26_ならし上昇 and ((XSW25_ならし上昇端 and not(pnlPBXSW25_ならし上昇端)) or passXSW25_ならし上昇端) then
			mSV26_ならし上昇=OFF
		end if
		'---------------------------------------------------------
		if ldp(pnlPBSV27_ならし前進) then
			if ((XSW27_ならし後退端 and not(pnlPBXSW27_ならし後退端)) or passXSW27_ならし後退端) and ((XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端) then
				mSV27_ならし前進=ON
				mSV28_ならし後退=OFF
			end if
		end if
		if ldp(pnlPBSV28_ならし後退) then
			if ((XSW28_ならし前進端 and not(pnlPBXSW28_ならし前進端)) or passXSW28_ならし前進端) and ((XSW24_ならし前進端 and not(pnlPBXSW24_ならし前進端)) or passXSW24_ならし前進端) then
				mSV27_ならし前進=OFF
				mSV28_ならし後退=ON
			end if
		end if
		if mSV27_ならし前進 and ((XSW28_ならし前進端 and not(pnlPBXSW28_ならし前進端)) or passXSW28_ならし前進端) then
			mSV27_ならし前進=OFF
		end if
		if mSV28_ならし後退 and ((XSW27_ならし後退端 and not(pnlPBXSW27_ならし後退端)) or passXSW27_ならし後退端) then
			mSV28_ならし後退=OFF
		end if
		'---------------------------------------------------------
	end if 'ならし装置AutoMode and not(ならし装置OrgErrStep)

	'===================================================================================================================
	'【 ならし装置OrgErr処理 】
	else

		if ResetFlg then
			ならし装置OrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		
		ならし装置Err=ON
		
		select case ならし装置ErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW24_ならし前進端=OFF
				almXSW23_ならし後退端=OFF
				almXSW26_ならし下降端=OFF
				almXSW25_ならし上昇端=OFF
				almXSW28_ならし前進端=OFF
				almXSW27_ならし後退端=OFF
			
				inc(ならし装置ErrStep)
			end if
		case 2
			res(tim_XSW24_ならし前進端)
			res(tim_XSW23_ならし後退端)
			res(tim_XSW26_ならし下降端)
			res(tim_XSW25_ならし上昇端)
			res(tim_XSW28_ならし前進端)
			res(tim_XSW27_ならし後退端)

			res(tim_notXSW24_ならし前進端)
			res(tim_notXSW23_ならし後退端)
			res(tim_notXSW26_ならし下降端)
			res(tim_notXSW25_ならし上昇端)
			res(tim_notXSW28_ならし前進端)
			res(tim_notXSW27_ならし後退端)
			
			ならし装置Err=OFF
			ならし装置ErrStep=0
		end select

	end if 'if ならし装置ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case ならし装置EmgStep
	case 0
	
	case 1
		ならし装置AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (ならし装置AutoMode and 自動搬送AutoMode ) or ならし装置step<>0 then
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
			mSV23_ならし前進=OFF
			mSV24_ならし後退=OFF
			mSV25_ならし下降=OFF
			mSV26_ならし上昇=OFF
			mSV27_ならし前進=OFF
			mSV28_ならし後退=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(ならし装置EmgStep)
	case 2
		if ResetFlg then
			inc(ならし装置EmgStep)
		end if
	case 3
		if (ならし装置AutoMode and 自動搬送AutoMode ) or ならし装置step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(ならし装置EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(ならし装置EmgStep)		
		end if				
	case 4
		timstack=OFF
		ならし装置EmgStep=0
		ならし装置Emg=OFF
	end select
end if 'if ならし装置EmgStep=0 then
