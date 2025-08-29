'納米庫
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	納米庫ユニット（米計量）
'	
'===================================================================================================================
'【 初期化処理 】
if CR2008 then

    計量AutoMode=OFF
    計量AutoRun=OFF
    計量許可=ON
    計量OrgErr=OFF
    計量Err=OFF
    計量Emg=OFF
    計量step=0
    計量ErrStep=0
    計量OrgErrStep=0
    計量EmgStep=0

	ワンサイクルflg=OFF

	浸漬タンクA動作中=OFF
	浸漬タンクB動作中=OFF
	
end if

'===================================================================================================================
'【 原点 】
計量Org=1

'===================================================================================================================
'【 Runtime処理  (データ インポート、エクスポート) 】

'張込モータは常に手動でON/OFF可能

	if not(THR1_張込用昇降機モータ) and PB33_納米庫全停止 then
		if ldp(PB1_張込用昇降ON) then
			if mMC1_張込用昇降機 then
				mMC1_張込用昇降機=OFF
			else
				mMC1_張込用昇降機=ON
			end if
		end if
	else
		mMC1_張込用昇降機=OFF
	end if
	
	PBL1_張込用昇降機=mMC1_張込用昇降機

'==============================================================================================================
'【 計測データ および 計算式 】

if 0 then
	DM_計量設定値=21

else
	if DM_計量設定値<1	then
		DM_計量設定値=1
	else if DM_計量設定値>30	then
		DM_計量設定値=30
	end if

end if

	cnt(MC3_計量機,CNT_計量現在値, DM_計量設定値,FLOS1_計量機近接センサー)
	cnt(MC3_計量機,CNT_総計量現在値, DM_計量設定値,FLOS1_計量機近接センサー)

'==============================================================================================================
'【 計測データ および 計算式 】
'2017_0921_1536変更前データ
'if 1 then
'	DM_計量設定値=21
'end if

'	cnt(MC3_計量機,CNT_計量現在値, DM_計量設定値,FLOS1_計量機近接センサー)
'	cnt(MC3_計量機,CNT_総計量現在値, DM_計量設定値,FLOS1_計量機近接センサー)

'===================================================================================================================
'【 緊急停止 】

tmr(not(ESPB1_非常停止),ESPB1_非常停止tim,2)
tmr(ESPB5_非常停止,ESPB5_非常停止tim,2)

if ESPB1_非常停止tim or ESPB5_非常停止tim then
	計量Emg=ON
	計量EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(SV12_送米切換バルブA側 and not(XSW9_送米切換A側) and not(pnlPBXSW9_送米切換A側) ,tim_notXSW9_送米切換A側,#100)
tmr(SV13_送米切換バルブB側 and not(XSW10_送米切換B側) and not(pnlPBXSW10_送米切換B側), tim_notXSW10_送米切換B側,#100)

if LDP(SV12_送米切換バルブA側) and XSW9_送米切換A側 and XSW10_送米切換B側 and not(pnlPBXSW9_送米切換A側) then
	SET(tim_XSW9_送米切換A側)
end if
if LDP(SV13_送米切換バルブB側) and XSW9_送米切換A側 and XSW10_送米切換B側 and not(pnlPBXSW10_送米切換B側) then
	SET(tim_XSW10_送米切換B側)
end if

if SV12_送米切換バルブA側 then
	KeepSV12_送米切換バルブA側=ON
	KeepSV13_送米切換バルブB側=OFF
else if SV13_送米切換バルブB側 then
	KeepSV12_送米切換バルブA側=OFF
	KeepSV13_送米切換バルブB側=ON
end if	
'passtimXSW9_送米切換A側_val=#3000
tms(SV12_送米切換バルブA側 or KeepSV12_送米切換バルブA側,passtimXSW9_送米切換A側,passtimXSW9_送米切換A側_val)
'passtimXSW10_送米切換B側_val=#3000
tms(SV13_送米切換バルブB側 or KeepSV13_送米切換バルブB側,passtimXSW10_送米切換B側,passtimXSW10_送米切換B側_val)

if (ldp(tim_XSW9_送米切換A側.B) or ldp(tim_notXSW9_送米切換A側)) and not(pnlPBXSW9_送米切換A側) then
	almXSW9_送米切換A側=ON
	pnlPBXSW9_送米切換A側=ON
	pnlPBXSW10_送米切換B側=ON
	if tim_XSW9_送米切換A側 then
		res(tim_XSW9_送米切換A側)
	end if
	計量ErrStep=1
end if
if (ldp(tim_XSW10_送米切換B側.B)or LDP(tim_notXSW10_送米切換B側)) and not(pnlPBXSW10_送米切換B側) then
	almXSW10_送米切換B側=ON
	pnlPBXSW9_送米切換A側=ON
	pnlPBXSW10_送米切換B側=ON
	if tim_XSW10_送米切換B側 then
		res(tim_XSW10_送米切換B側)
	end if
	計量ErrStep=1
end if

'===================================================================================================================
' PLインジケータ
	
	PBL5_計量機=ワンサイクルflg
	
	PBL3_排出用昇降機 = MC2_排出用昇降機 or ( SSW4_納米庫手動 and PB5_計量機ON and PB33_納米庫全停止 and not(mMC2_排出用昇降機) and CR2005) 


'===================================================================================================================
' センサー検出ディレイ―

	tmr(PDL1_パドルセンサー上限A and not(米上限A検知無効),timPDL1_パドルセンサー上限A,20)
	tmr(PDL2_パドルセンサー下限A,tim_PDL2_パドルセンサー下限A,20)
	tmr(PDL3_パドルセンサー上限B and not(米上限B検知無効),timPDL3_パドルセンサー上限B,20)
	tmr(PDL4_パドルセンサー下限B,tim_PDL4_パドルセンサー下限B,20)

if ldp(timPDL1_パドルセンサー上限A) then
	almPDL1_パドルセンサー上限A=ON
end if
if ldp(timPDL3_パドルセンサー上限B) then
	almPDL3_パドルセンサー上限B=ON
end if

if almPDL1_パドルセンサー上限A and ResetFlg then
	almPDL1_パドルセンサー上限A=OFF
end if
if almPDL3_パドルセンサー上限B and ResetFlg then
	almPDL3_パドルセンサー上限B=OFF
end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: AutoMode	自動モード セレクトスイッチ
'System :: AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 計量Emg	その場停止


tmr(tim_切換えバルブ切換え待ち,tim_切換えバルブ切換え待ち_val)
'切換えバルブ

if 計量EmgStep=0 then  
	
	if 計量ErrStep=0  then

	if not(計量OrgErr) then

	'if  (計量AutoMode and 自動搬送AutoMode) or 計量step<>0  then
	if  計量AutoMode or 計量step<>0  then

	
		if not(計量AutoMode) then
			計量AutoRun=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim計量,tim計量_val)


		select case 計量step
		case 0

		case 1
			if 計量AutoRun or ワンサイクルflg then
				浸漬タンクA動作中=OFF
				浸漬タンクB動作中=OFF				
				inc(計量step)
			else 
				計量step=100 '排出昇降遅延
			end if
		
		case 2
			if ワンサイクルflg then
				計量step=5
			else if 浸漬タンク準備完了A=OFF then
				if timPDL1_パドルセンサー上限A or DM_Aタンク送米現在値>=DM_Aタンク設定値 or DM_Aタンク設定値=0 then
					浸漬タンクAユニットStatusMsg=#0

					浸漬タンクA動作中=OFF
					浸漬タンク準備完了A=ON
					送米タンク切換え=ON
				else
					浸漬タンクAユニットStatusMsg=#11	'	送米中
					浸漬タンクBユニットStatusMsg=#0

					浸漬タンクA動作中=ON
					浸漬タンクB動作中=OFF
					if not(mSV12_送米切換バルブA側) then
						送米タンク切換え=OFF
						mSV12_送米切換バルブA側=ON
						mSV13_送米切換バルブB側=OFF
						tim_切換えバルブ切換え待ち_val=#20
						res(tim_切換えバルブ切換え待ち.B)
					else
						set(tim_切換えバルブ切換え待ち.B)
					end if
					
					inc(計量step)

				end if

			else if 浸漬タンク準備完了B=OFF then 
				if timPDL3_パドルセンサー上限B or DM_Bタンク送米現在値>=DM_Bタンク設定値 or DM_Bタンク設定値=0 then
					浸漬タンクBユニットStatusMsg=#0

					浸漬タンクB動作中=OFF
					浸漬タンク準備完了B=ON
				else 
					浸漬タンクA動作中=OFF
					浸漬タンクB動作中=ON
					if not(mSV13_送米切換バルブB側) then
						浸漬タンクAユニットStatusMsg=#0
						浸漬タンクBユニットStatusMsg=#11'	送米中

						mSV12_送米切換バルブA側=OFF
						mSV13_送米切換バルブB側=ON
						tim_切換えバルブ切換え待ち_val=#20
						res(tim_切換えバルブ切換え待ち.B)
					else
						set(tim_切換えバルブ切換え待ち.B)
					end if
					inc(計量step)
				end if
			else
				前処理計量完了=ON
				計量step=0
			end if
		

		case 3
			if tim_切換えバルブ切換え待ち.B then 'ダブルソレノイドOFFタイミング
				if  (not(送米タンク切換え) or mSV12_送米切換バルブA側) and ((XSW9_送米切換A側 and not(pnlPBXSW9_送米切換A側)) or passXSW9_送米切換A側) then
					mSV12_送米切換バルブA側=OFF
					mSV13_送米切換バルブB側=OFF
					inc(計量step)
				else if  (送米タンク切換え or mSV13_送米切換バルブB側) and ((XSW10_送米切換B側 and not(pnlPBXSW10_送米切換B側)) or passXSW10_送米切換B側) then
					mSV12_送米切換バルブA側=OFF
					mSV13_送米切換バルブB側=OFF
					inc(計量step)
				end if
			end if


		case 4
			if SSW4_納米庫自動 then
				洗米AutoRun=ON
				洗米step=1
			end if
			inc(計量step)
		'------------------------------------------
		'昇降機 ON Delay
		case 5
			計量動作中=ON
			if not(mMC2_排出用昇降機) then 
				mMC2_排出用昇降機=ON
				tim計量_val=#1200  'ON Delay あり
				res(tim計量)
			else
				set(tim計量) 'ON Delay なし
			end if

			inc(計量step)
		case 6
			if tim計量.B then
				inc(計量step)
			end if				
		'------------------------------------------
		'計量中
		case 7
			if 送米計量一時停止 then
				mMC3_計量機=OFF			
				inc(計量step)
			else if not(前処理計量完了) or ワンサイクルflg then '前処理全体の浸漬タンクA～Bへの計量完了
				res(CNT_計量現在値)
				mMC3_計量機=ON
				inc(計量step)
			else
				mMC3_計量機=OFF
				計量step=100
			end if
			
		case 8
			if not(PB33_納米庫全停止) then 
				計量AutoRun=OFF
				inc(計量step)
			else
				if CNT_計量現在値.B then '指定計量（カップ数）終了
					if ((XSW9_送米切換A側 and not(pnlPBXSW9_送米切換A側)) or passXSW9_送米切換A側) or SV12_送米切換バルブA側 then
						if DM_Aタンク設定値>0 and DM_Aタンク送米現在値=0 then
							浸漬時間計測中=ON
						end if
						inc(DM_Aタンク送米現在値) '送米釜数
					else if ((XSW10_送米切換B側 and not(pnlPBXSW10_送米切換B側)) or passXSW10_送米切換B側) or SV13_送米切換バルブB側 then
						if DM_Aタンク設定値=0 and (DM_Bタンク設定値>0 and DM_Bタンク送米現在値=0) then
							浸漬時間計測中=ON
						end if
						inc(DM_Bタンク送米現在値) '送米釜数
					end if					
					inc(計量step)
				end if
			end if
		case 9
			if not(FLOS1_計量機近接センサー) then
				inc(計量step)
			end if
		case 10
			if FLOS1_計量機近接センサー then
				inc(計量step)
			end if			
		case 11
			tim計量_val=#0 '位置合わタイマー
			res(tim計量)
			inc(計量step)				
		
		case 12
			if tim計量.B then
				mMC3_計量機=OFF
				inc(計量step)
			end if
		'------------------------------------------
		'計量機 OFF Delay
		case 13
			if ワンサイクルflg then
				ワンサイクルflg=OFF
				計量step=0
			else
				if 送米計量一時停止 then
					tim計量_val=0
				else
					if FLOS2_洗米無洗米切換検知 then
						tim計量_val=送米インターバル無洗米*10 '#180 '計量インターバルタイマ
					else 			
						tim計量_val=送米インターバル通常米*10 '#310 '計量インターバルタイマ
					end if
				end if
				res(tim計量)
				inc(計量step)

			end if
		case 14
			if tim計量.B then
				inc(計量step)
			end if
		'------------------------------------------
		'残米処理		
		case 15
			if not(浸漬タンク準備完了A) and (timPDL1_パドルセンサー上限A or DM_Aタンク送米現在値>=DM_Aタンク設定値) then
				計量step=100
			else if DM_Bタンク設定値>0 then
				inc(計量step)
			else 
				計量step=1						
			end if
			
		case 16
			if  not(浸漬タンク準備完了B) and (timPDL3_パドルセンサー上限B or DM_Bタンク送米現在値>=DM_Bタンク設定値) then
				計量step=100
			else
				inc(計量step)
			end if		
		
		case 17
				計量step=1			
		'------------------------------------------
		'排出昇降機 OFF Delay
		case 100
			tim計量_val=#600 '排出用昇降機遅延タイマー
			res(tim計量)
			inc(計量step)
		case 101
			if tim計量.B then
				mMC2_排出用昇降機=OFF
				計量動作中=OFF
				inc(計量step)	
			end if
		'------------------------------------------
		case 102
			if 洗米step=0 then
					計量step=0
			end if
		'------------------------------------------
			
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
		
		計量AutoRun=OFF
		
		計量step=0 '終了
		
		'-----------------------------------
		if not(PB33_納米庫全停止)  then
			manual排出用昇降機=OFF
			mMC1_張込用昇降機=OFF
		end if
		'-----------------------------------		
		if ldp(pnlPBMC1_張込用昇降機) then
			if mMC1_張込用昇降機 then
				mMC1_張込用昇降機=OFF
			else
				mMC1_張込用昇降機=ON
			end if
		end if	

		'-----------------------------------
		' manual昇降モータON/OFF

		if  ldp(PB3_排出用昇降ON and SSW4_納米庫手動) or ldp(pnlPBMC2_排出用昇降機) then
			if manual排出用昇降機 then
				manual排出用昇降機=OFF
			else if PB33_納米庫全停止 then
				manual排出用昇降機=ON
				mMC2_排出用昇降機=ON
			end if
		
		end if
		
		if (SSW4_納米庫自動 or not(manual排出用昇降機) ) and 計量step=0 then
			mMC2_排出用昇降機=OFF
		end if
		
		'-----------------------------------
		' manual計量step

		if (ldp(PB5_計量機ON and SSW4_納米庫手動) or ldp(pnlPBMC3_計量機)) and SSW4_納米庫手動 and  PB33_納米庫全停止 and mMC2_排出用昇降機 and 計量step=0 then
				if FLOS2_洗米無洗米切換検知 then
					無洗米モード=ON
				else
					無洗米モード=OFF
				end if

				ワンサイクルflg=ON
				計量step=1
		
		end if		
	
	end if 'AutoMode and not(計量OrgErrStep)

	'===================================================================================================================
	'【 計量OrgErr処理 】
	else
		
		計量AutoRun=OFF
		計量step=1
		
		if 計量OrgErr then
			if RestartFlg or PB34_リセット then
				if 計量AutoMode then
					計量AutoRun=ON
				end if
				計量OrgErr=OFF
			end if		
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		PL2_異常=ON

		計量AutoRun=OFF

		pauseMC2_排出用昇降機=ON
		pauseMC3_計量機=ON

		select case 計量ErrStep
		case 0
		case 1
			if ResetFlg or PB34_リセット then
				almXSW9_送米切換A側=OFF
				almXSW10_送米切換B側=OFF
				almPDL1_パドルセンサー上限A=OFF
				almPDL3_パドルセンサー上限B=OFF
				inc(計量ErrStep)
			end if
		case 2
			res(tim_XSW9_送米切換A側)
			res(tim_XSW10_送米切換B側)
			res(tim_notXSW9_送米切換A側)
			res(tim_notXSW10_送米切換B側)
		
			pauseMC2_排出用昇降機=OFF
			pauseMC3_計量機=OFF

			PL2_異常=OFF
			計量ErrStep=0
		end select

	end if 'if 計量ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 計量EmgStep
	case 0

	case 1
		計量AutoRun=OFF

		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if  (計量AutoMode and 自動搬送AutoMode) or 計量step<>0  then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			mMC1_張込用昇降機=OFF
			pauseMC2_排出用昇降機=ON
			pauseMC3_計量機=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim計量.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC1_張込用昇降機=OFF
			mMC2_排出用昇降機=OFF
			mMC3_計量機=OFF				
			'---------------------------------
		end if
		
		'---------------------------------
		inc(計量EmgStep)
	case 2
		if ResetFlg then
			inc(計量EmgStep)
		end if
	case 3
		if  (計量AutoMode and 自動搬送AutoMode) or 計量step<>0  then
			if StartFlg then

				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseMC2_排出用昇降機=OFF
				pauseMC3_計量機=OFF
				
				tim計量.U=tim_procstep_stack
				'---------------------------------
				inc(計量EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(計量EmgStep)		
		end if				
	case 4
		timstack=OFF	
		計量EmgStep=0
		計量Emg=OFF
	end select
		
end if 'if 計量EmgStep=0 then
