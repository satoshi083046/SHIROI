'バキュームユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	バキュームユニット
'	
'===================================================================================================================

'【 初期化処理 】
if CR2008 then
    バキュームユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    バキュームユニットAutoRun=OFF
    バキュームユニット許可=ON
    バキュームユニットOrgErr=OFF
    バキュームユニットErr=OFF
    バキュームユニットEmg=OFF
    バキュームユニットstep=0
    バキュームユニットErrStep=0
    バキュームユニットOrgErrStep=0
    バキュームユニットEmgStep=0
end if
'===================================================================================================================
'【 原点 】
バキュームユニットOrg=((XSW61_シリンダ上昇端 and not(pnlPBXSW61_シリンダ上昇端)) or passXSW61_シリンダ上昇端) and ((XSW71_バキューマリフト下降端 and not(pnlPBXSW71_バキューマリフト下降端)) or passXSW71_バキューマリフト下降端)
バキュームユニットOrg=バキュームユニットOrg or バキューム禁止
'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	バキュームユニットEmg=ON
	バキュームユニットEmgStep=1
end if


'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV52_シリンダ and not(XSW62_シリンダ下降端) and not(pnlPBXSW62_シリンダ下降端),tim_notXSW62_シリンダ下降端,#80)
tmr(not(SV52_シリンダ) and not(XSW61_シリンダ上昇端) and not(pnlPBXSW61_シリンダ上昇端),tim_notXSW61_シリンダ上昇端,#80)
tmr(SV57_バキュームリフト and not(XSW72_バキューマリフト上昇端) and not(pnlPBXSW72_バキューマリフト上昇端),tim_notXSW72_バキューマリフト上昇端,#50)
tmr(not(SV57_バキュームリフト) and not(XSW71_バキューマリフト下降端) and not(pnlPBXSW71_バキューマリフト下降端),tim_notXSW71_バキューマリフト下降端,#50)

if LDP(SV52_シリンダ) and XSW62_シリンダ下降端 and not(pnlPBXSW62_シリンダ下降端) then
	SET(tim_XSW62_シリンダ下降端)
end if
if LDF(SV52_シリンダ) and XSW61_シリンダ上昇端 and not(pnlPBXSW61_シリンダ上昇端) then
	SET(tim_XSW61_シリンダ上昇端)
end if
if LDP(SV57_バキュームリフト) and XSW72_バキューマリフト上昇端 and not(pnlPBXSW72_バキューマリフト上昇端) then
	SET(tim_XSW72_バキューマリフト上昇端)
end if
if LDF(SV57_バキュームリフト) and XSW71_バキューマリフト下降端 and not(pnlPBXSW71_バキューマリフト下降端) then
	SET(tim_XSW71_バキューマリフト下降端)
end if

'passtimXSW62_シリンダ下降端_val=#3000
tms(SV52_シリンダ,passtimXSW62_シリンダ下降端,passtimXSW62_シリンダ下降端_val)
'passtimXSW61_シリンダ上昇端_val=#3000
tms(not(SV52_シリンダ),passtimXSW61_シリンダ上昇端,passtimXSW61_シリンダ上昇端_val)
'passtimXSW72_バキューマリフト上昇端_val=#2000
tms(SV57_バキュームリフト,passtimXSW72_バキューマリフト上昇端,passtimXSW72_バキューマリフト上昇端_val)
'passtimXSW71_バキューマリフト下降端_val=#2000
tms(not(SV57_バキュームリフト),passtimXSW71_バキューマリフト下降端,passtimXSW71_バキューマリフト下降端_val)

if not(バキューム禁止) then
	if (ldp(tim_XSW62_シリンダ下降端.B) or ldp(tim_notXSW62_シリンダ下降端.B)) and not(pnlPBXSW62_シリンダ下降端) then
		almXSW62_シリンダ下降端=ON
		pnlPBXSW62_シリンダ下降端=ON
		if tim_XSW62_シリンダ下降端 then
			res(tim_XSW62_シリンダ下降端)
		end if
		バキュームユニットErrStep=1
		
	else if (ldp(tim_XSW61_シリンダ上昇端.B) or ldp(tim_notXSW61_シリンダ上昇端.B)) and not(pnlPBXSW61_シリンダ上昇端) then
		almXSW61_シリンダ上昇端=ON
		pnlPBXSW61_シリンダ上昇端=ON
		if tim_XSW61_シリンダ上昇端 then
			res(tim_XSW61_シリンダ上昇端)
		end if
		バキュームユニットErrStep=1

	else if (ldp(tim_XSW72_バキューマリフト上昇端.B) or ldp(tim_notXSW72_バキューマリフト上昇端.B)) and not(pnlPBXSW72_バキューマリフト上昇端) then
		almXSW72_バキューマリフト上昇端=ON
		pnlPBXSW72_バキューマリフト上昇端=ON
		if tim_XSW72_バキューマリフト上昇端 then
			res(tim_XSW72_バキューマリフト上昇端)
		end if
		バキュームユニットErrStep=1

	else if (ldp(tim_XSW71_バキューマリフト下降端.B) or ldp(tim_notXSW71_バキューマリフト下降端.B)) and not(pnlPBXSW71_バキューマリフト下降端) then
		almXSW71_バキューマリフト下降端=ON
		pnlPBXSW71_バキューマリフト下降端=ON
		if tim_XSW71_バキューマリフト下降端 then
			res(tim_XSW71_バキューマリフト下降端)
		end if
		バキュームユニットErrStep=1
		
	end if
else
	res(tim_XSW62_シリンダ下降端)
	res(tim_XSW61_シリンダ上昇端)
	res(tim_XSW72_バキューマリフト上昇端)
	res(tim_XSW71_バキューマリフト下降端)

	res(tim_notXSW62_シリンダ下降端)
	res(tim_notXSW61_シリンダ上昇端)
	res(tim_notXSW72_バキューマリフト上昇端)
	res(tim_notXSW71_バキューマリフト下降端)

end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: バキュームユニットAutoMode	自動モード セレクトスイッチ
'System :: バキュームユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: バキュームユニットEmg	その場停止

if 0 then
	pauseMC24_吸引ポンプ=ON
end if

if バキュームユニットEmgStep=0 then  
	
	if バキュームユニットErrStep=0  then

	if not(バキュームユニットOrgErr) then

	if (バキュームユニットAutoMode and 自動搬送AutoMode ) or バキュームユニットstep<>0 then
	
		if not(バキュームユニットAutoMode and 自動搬送AutoMode ) then
			バキュームユニットAutoRun=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)
		tmr(tim_MC24_吸引ポンプ待ち時間,tim_MC24_吸引ポンプ待ち時間_val)
		tmr(tim_MC24_吸引ポンプ,tim_MC24_吸引ポンプ_val)

		select case バキュームユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if バキュームユニットAutoRun then
				inc(バキュームユニットstep)
			else 
				バキュームユニットstep=0 '終了待機
			end if
		
		case 2
				inc(バキュームユニットstep)
		
		case 3
		' [ 蓋カマ移動停止確認 ]
			if 水抜きバキューム排出要求=OFF and  搬送コンベアD動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH27_釜検知 and PH28_フタ検知 then
						inc(バキュームユニットstep) 'プロセス処理
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH27_釜検知) and PH28_フタ検知 then 
							水抜きバキューム排出要求=ON
							バキュームユニットstep=1
				
				'[ 自ステージに"釜フタ"なし ]
						else
							水抜きバキューム排出要求=ON
							バキュームユニットstep=1  '終了
					end if
			
			else
			
				バキュームユニットstep=1
			
			end if
		
		case 4
			if ((XSW61_シリンダ上昇端 and not(pnlPBXSW61_シリンダ上昇端)) or passXSW61_シリンダ上昇端) and ((XSW71_バキューマリフト下降端 and not(pnlPBXSW71_バキューマリフト下降端)) or passXSW71_バキューマリフト下降端) then
				inc(バキュームユニットstep)
			else
				バキュームユニットstep=1
			end if

		case 5
		' [ ユニット許可検出 ]
			if not(バキューム禁止) and (強制バキューム or StageDevice200=$8000) then
				バキュームユニットstep=100 'プロセス処理
			else
				水抜きバキューム排出要求=ON
				バキュームユニットstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			if バキューム完了 then '搬送移動でOFF
				バキュームユニットstep=199
			else
				inc(バキュームユニットstep)
			end if
		
		case 101
			mSV57_バキュームリフト=ON
			inc(バキュームユニットstep)

		case 102
			if (XSW72_バキューマリフト上昇端 and not(pnlPBXSW72_バキューマリフト上昇端)) or passXSW72_バキューマリフト上昇端 then
				inc(バキュームユニットstep)
			end if			
		
		case 103
			mSV51_給水電磁弁=ON	'ポンプ冷却用給水ON
			mSV52_シリンダ=ON	'シリンダ下降
			
			tim_MC24_吸引ポンプ待ち時間_val=#30 '吸引時間待ち時間
			res(tim_MC24_吸引ポンプ待ち時間)
			
			inc(バキュームユニットstep)
			
		case 104
			if (XSW62_シリンダ下降端 and not(pnlPBXSW62_シリンダ下降端)) or passXSW62_シリンダ下降端 then
				inc(バキュームユニットstep)
			end if
		

		case 105
			if tim_MC24_吸引ポンプ待ち時間.B then
				inc(バキュームユニットstep)
			end if			

		case 106
			mMC24_吸引ポンプ=ON
			inc(バキュームユニットstep)
			
		case 107
			tim_MC24_吸引ポンプ_val=#80 '吸引時間
			res(tim_MC24_吸引ポンプ)
			inc(バキュームユニットstep)
	
		case 108
			if tim_MC24_吸引ポンプ.B then
				inc(バキュームユニットstep)
			end if

		case 109
			mMC24_吸引ポンプ=OFF
			mSV51_給水電磁弁=OFF	'ポンプ冷却用給水OFF
			mSV52_シリンダ=OFF	'シリンダ上昇
			mSV57_バキュームリフト=OFF
			inc(バキュームユニットstep)
		
		case 110
			if (XSW61_シリンダ上昇端 and not(pnlPBXSW61_シリンダ上昇端)) or passXSW61_シリンダ上昇端 then
				inc(バキュームユニットstep)
			end if	

		case 111
			if (XSW71_バキューマリフト下降端 and not(pnlPBXSW71_バキューマリフト下降端)) or passXSW71_バキューマリフト下降端 then
				inc(バキュームユニットstep)
			end if			

		case 112
			バキュームユニットstep=199

		'------------------------------------------------------
		case 199
			バキューム完了=ON
			水抜きバキューム排出要求=ON
			バキュームユニットstep=1
		'------------------------------------------------------

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		バキュームユニットAutoRun=OFF
		
		バキュームユニットstep=0 '終了
		バキューム完了=OFF
		
		if ldp(pnlPBSV52_シリンダ) then
			if mSV52_シリンダ then
				mSV52_シリンダ=OFF
				mSV51_給水電磁弁=OFF
			else
				mSV52_シリンダ=ON
			end if
		end if
		
		if LDP(pnlPBMC24_吸引ポンプ) then
			if mMC24_吸引ポンプ then
				mMC24_吸引ポンプ=OFF
			else if not(mMC24_吸引ポンプ)  and ((XSW62_シリンダ下降端 and not(pnlPBXSW62_シリンダ下降端)) or passXSW62_シリンダ下降端) then
				mMC24_吸引ポンプ=ON
			end if
		end if
				
		if LDP(pnlPBSV51_給水電磁弁) then '給水電磁弁パネル割り当て不具合
			if mSV51_給水電磁弁 then
				mSV51_給水電磁弁=OFF
			else
				mSV51_給水電磁弁=ON
			end if
		end if
		
		if LDP(pnlPBSV57_バキュームリフト) then
			if mSV57_バキュームリフト then
				mSV57_バキュームリフト=OFF
			else
				mSV57_バキュームリフト=ON
			end if
		end if
	
	end if 'バキュームユニットAutoMode and not(バキュームユニットOrgErrStep)

	'===================================================================================================================
	'【 バキュームユニットOrgErr処理 】
	else

		if ResetFlg then
			バキュームユニットOrgErr=OFF
		end if		

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		バキュームユニットErr=ON

		select case バキュームユニットErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW62_シリンダ下降端=OFF
				almXSW61_シリンダ上昇端=OFF
				almXSW71_バキューマリフト下降端=OFF
				almXSW72_バキューマリフト上昇端=OFF
				inc(バキュームユニットErrStep)
			end if
		case 2
			バキュームユニットErr=OFF
			
			res(tim_XSW62_シリンダ下降端)
			res(tim_XSW61_シリンダ上昇端)
			res(tim_XSW71_バキューマリフト下降端)
			res(tim_XSW72_バキューマリフト上昇端)
			
			res(tim_notXSW62_シリンダ下降端)
			res(tim_notXSW61_シリンダ上昇端)
			res(tim_notXSW71_バキューマリフト下降端)
			res(tim_notXSW72_バキューマリフト上昇端)

			バキュームユニットErrStep=0
		end select

	end if 'if バキュームユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case バキュームユニットEmgStep
	case 0
	
	case 1
		バキュームユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (バキュームユニットAutoMode and 自動搬送AutoMode ) or バキュームユニットstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseMC24_吸引ポンプ=ON
			pauseSV51_給水電磁弁=ON
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV52_シリンダ=OFF
			mMC24_吸引ポンプ=OFF
			mSV51_給水電磁弁=OFF
			mSV57_バキュームリフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(バキュームユニットEmgStep)
	case 2
		if ResetFlg then
			inc(バキュームユニットEmgStep)
		end if
	case 3
		if (バキュームユニットAutoMode and 自動搬送AutoMode ) or バキュームユニットstep<>0 then
			if StartFlg then
				pauseMC24_吸引ポンプ=OFF
				pauseSV51_給水電磁弁=OFF

				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				
				
				'---------------------------------
				inc(バキュームユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(バキュームユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		バキュームユニットEmgStep=0
		バキュームユニットEmg=OFF
	end select
		
end if 'if バキュームユニットEmgStep=0 then
