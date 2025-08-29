'前処理工程
'===================================================================================================================
'
'<<<<<<<	前処理工程	>>>>>>>>
'
'===================================================================================================================
'
'	前処理工程
'	
'	前処理注水完了  －  浸漬タンク準備完了A  -    前処理計量完了  -   前処理完了
'	                        DM_Aタンク設定値
'  		                    DM_Aタンク送米現在値
'
'                   -   浸漬タンク準備完了B
'                        	DM_Bタンク設定値
'                        	DM_Bタンク送米現在値
'
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理

    前処理工程AutoMode=OFF
    前処理工程AutoRun=OFF
    前処理工程許可=ON
    前処理工程OrgErr=OFF
    前処理工程Err=OFF
    前処理工程Emg=OFF
    前処理工程step=0
    前処理工程ErrStep=0
    前処理工程OrgErrStep=0
    前処理工程EmgStep=0
    
    前処理工程StatusMsg=0

end if

tmr(StartUpTim,10)

'===================================================================================================================
'【 緊急停止 】
tmr(not(ESPB1_非常停止),ESPB1_非常停止tim,2)
tmr(ESPB5_非常停止,ESPB5_非常停止tim,2)

if ESPB1_非常停止tim or ESPB5_非常停止tim then
	前処理工程Emg=ON
	前処理工程EmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

if almPS1_エアー圧力 or almPS2_エアー圧力 or almPS3_エアー圧力 then
	
	if 前処理工程step<>0 then '1サイクルは動作させる
		前処理工程AutoRun=OFF
	else
		前処理工程ErrStep=1
	end if
	
end if
'===================================================================================================================
' PLインジケータ
	PL19_即時運転=即時運転モード or (即時運転モードEndWait and CR2006)
	PBL20_予約運転=(予約運転モード or 洗浄タンク予約運転モード) or (予約運転モードEndWait and CR2006)

	浸漬タンクA水位現在値=R41000.U
	浸漬タンクB水位現在値=R41100.U




'===================================================================================================================

tmr(tim_RLY_レベルスイッチ,10)
RLY_レベルスイッチ用電源=not(tim_RLY_レベルスイッチ.B)


'===================================================================================================================
'納米庫コマンドスイッチ処理

'-------------------------------
'メイン操作ボックス
'
'PB19_即時運転
'PB20_予約運転
'PB21_前処理停止
'
'--------------------------------
'納米庫操作ボックス
'
'SSW4_納米庫手動
'SSW4_納米庫自動
'PB1_張込用昇降ON
'PB3_排出用昇降ON
'PB5_計量機ON
'PB33_納米庫全停止 'モータOFF、計量モータ＝近接でOFF、
'
'--------------------------------
'
'PL10_異常
'PL19_即時運転
'PBL20_予約運転
'PBL22_自動運転
'
'--------------------------------
'初期化処理
'--------------------------------
if CR2008 then
	前処理工程手動許可step=0
end if
	
浸漬タンクA水位= 浸漬タンクA水位現在値
浸漬タンクB水位= 浸漬タンクB水位現在値

'--------------------------------
'タイマー処理	
'--------------------------------
tmr(FLOS3_LMT121,timdly_FLOS03_LMT121,20) '10 -> 20に変更
tmr(not(FLOS3_LMT121),timnotdly_FLOS03_LMT121,20) '10 -> 20に変更
if timdly_FLOS03_LMT121 or 浸漬タンクA米有り then
	浸漬タンクA米有り=ON
end if
if (浸漬タンクA米有り and timnotdly_FLOS03_LMT121 and not(PDL2_パドルセンサー下限A) ) or (前処理工程AutoRun=OFF and 計量step=0 and 洗米step=0 and (timnotdly_FLOS03_LMT121 and not(PDL2_パドルセンサー下限A)) ) then
	if not(運転準備完了) then
		DM_Aタンク送米現在値=0
	end if
	浸漬タンクA米有り=OFF
end if

tmr(FLOS4_LMT121,timdly_FLOS4_LMT121,20) '10 -> 20に変更
tmr(not(FLOS4_LMT121),timnotdly_FLOS4_LMT121,20) '10 -> 20に変更
if timdly_FLOS4_LMT121 or 浸漬タンクB米有り then
	浸漬タンクB米有り=ON
end if
if (浸漬タンクB米有り and timnotdly_FLOS4_LMT121 and not(PDL4_パドルセンサー下限B) ) or (前処理工程AutoRun=OFF and 計量step=0 and 洗米step=0 and (timnotdly_FLOS4_LMT121 and not(PDL4_パドルセンサー下限B)) ) then
	'DM_浸漬タンクB貯米釜数=0 'コメント化
	if not(運転準備完了) then
		DM_Bタンク送米現在値=0
	end if
	浸漬タンクB米有り=OFF
end if

'--------------------------------
'コマンド処理
'--------------------------------

if RLY_電源確認納米庫  then


	if 前処理工程AutoRun=OFF and 計量step=0 and 洗米step=0 then
		即時運転モードEndWait=OFF
		予約運転モードEndWait=OFF
	end if

	'米センサーが入ってから PB21_前処理停止 を許可する
	if not(予約運転モード) and 前処理注水完了 and DM_Aタンク設定値>0  then
		if not(FLOS3_LMT121) and ((XSW9_送米切換A側 and not(pnlPBXSW9_送米切換A側)) or passXSW9_送米切換A側) then
			浸漬タンクA停止許可=OFF
		else
			浸漬タンクA停止許可=ON
		end if
	else
		浸漬タンクA停止許可=ON
	end if
	
	
	if not(予約運転モード) and 前処理注水完了 and DM_Bタンク設定値>0 then
		if not(FLOS4_LMT121) and ((XSW10_送米切換B側 and not(pnlPBXSW10_送米切換B側)) or passXSW10_送米切換B側 )then
			浸漬タンクB停止許可=OFF
		else
			浸漬タンクB停止許可=ON
		end if
	else
		浸漬タンクB停止許可=ON			
	end if

	
	tmr(not(FLOS3_LMT121),nottim_FLOS3_LMT121,10)
	tmr(not(FLOS4_LMT121),nottim_FLOS4_LMT121,10)


	if not(PB21_前処理停止) or SSW4_納米庫手動 or 前処理計量完了 then
		前処理工程AutoRun=OFF
		計量AutoRun=OFF
		
		if SSW4_納米庫手動 then
			洗米AutoRun=OFF
		end if
		
		if 即時運転モード and (計量step<>0 or 洗米step<>0) then
			即時運転モードEndWait=ON
		end if
		即時運転モード=OFF
		
		if 予約運転モード and (計量step<>0 or 洗米step<>0) then
			予約運転モードEndWait=ON
		end if
		予約運転モード=OFF
		
		洗浄タンク予約運転モード=OFF
		

	
	end if
	'-------------------------------------------------------------------------------------------------------------
	' 納米庫手動切り替えアラーム
	'-------------------------------------------------------------------------------------------------------------
	
	if ldp(SSW4_納米庫手動) then
		almSSW4_納米庫手動=ON
	end if
	if almSSW4_納米庫手動 and ResetFlg then
		almSSW4_納米庫手動=OFF
	end if
	

	'-------------------------------------------------------------------------------------------------------------
	' 予約および即時のスタートチェック
	'-------------------------------------------------------------------------------------------------------------
	if almSSW4_納米庫自動 then
		if ResetFlg then
			almSSW4_納米庫自動=OFF
		end if
	else if almSV2_充填バルブ開A or almSV4_水切りシャッター開A or almSV60_排水バルブ開A or almSV6_給水電磁弁A then
		if ResetFlg then
			almSV2_充填バルブ開A=OFF
			almSV4_水切りシャッター開A=OFF
			almSV60_排水バルブ開A=OFF
			almSV6_給水電磁弁A=OFF
		end if
	else if almSV7_充填バルブ開B or almSV9_水切りシャッター開B or almSV62_排水バルブ開B or almSV11_給水電磁弁B then  
		if ResetFlg then	
			almSV7_充填バルブ開B=OFF
			almSV9_水切りシャッター開B=OFF
			almSV62_排水バルブ開B=OFF
			almSV11_給水電磁弁B=OFF
		end if
	else if almPDL1_パドルセンサー上限A or almPDL3_パドルセンサー上限B then
		if ResetFlg then	
			almPDL1_パドルセンサー上限A=OFF
			almPDL3_パドルセンサー上限B=OFF
		end if
		
	'-------------------------------------------------------------------------------------------------------------
	else if 前処理工程step=0 and (ldp(PB19_即時運転) or ldp(PB20_予約運転) ) then

		'-----------------------------------------------------------
		if not(SSW4_納米庫自動) then
			almSSW4_納米庫自動=ON
		'-----------------------------------------------------------
		else if timPDL1_パドルセンサー上限A then
			almPDL1_パドルセンサー上限A=ON
		else if timPDL3_パドルセンサー上限B then
			almPDL3_パドルセンサー上限B=ON
		'-----------------------------------------------------------
		else if SV2_充填バルブ開A then
			almSV2_充填バルブ開A=ON
		else if KeepSV4_水切りシャッター開A then 
			almSV4_水切りシャッター開A=ON
		else if	SV60_排水バルブ開A then
			almSV60_排水バルブ開A=ON
		'-----------------------------------------------------------
		else if SV7_充填バルブ開B then
			almSV7_充填バルブ開B=ON
		else if KeepSV9_水切りシャッター開B then
			almSV9_水切りシャッター開B=ON
		else if	SV62_排水バルブ開B then
			almSV62_排水バルブ開B=ON
		'-----------------------------------------------------------
		end if
	
	'-------------------------------------------------------------------------------------------------------------
	else
	
		if ldp(PB19_即時運転) and not(PB20_予約運転) and SSW4_納米庫自動 and PB21_前処理停止 then' and 前処理設定完了 then
			res(tim_RLY_レベルスイッチ)
			if not(前処理工程AutoRun) and 前処理工程step=0 and 計量step=0 and 洗米step=0 and (DM_Aタンク送米現在値<DM_Aタンク設定値 or DM_Bタンク送米現在値<DM_Bタンク設定値) then
			
				if (DM_Aタンク設定値>0 and DM_Aタンク送米現在値=0) or (DM_Bタンク設定値>0 and DM_Bタンク送米現在値=0) then
					浸漬時間計測中=OFF
				end if
			
			
				'if nottim_FLOS3_LMT121.B then '浸漬タンクA米なし
				'	DM_Aタンク送米現在値=0
				'end if
				
				'if nottim_FLOS4_LMT121.B then '浸漬タンクB米なし
				'	DM_Bタンク送米現在値=0
				'end if
					
				
				if DM_Aタンク送米現在値>=DM_Aタンク設定値 then
					浸漬タンク準備完了A=ON
				else
					浸漬タンク準備完了A=OFF
				end if
				
				if DM_Bタンク送米現在値>=DM_Bタンク設定値 then
					浸漬タンク準備完了B=ON
				else 
					浸漬タンク準備完了B=OFF
				end if
				
				前処理注水完了=OFF
				前処理計量完了=OFF
				前処理完了=OFF

				前処理工程AutoMode=ON
				前処理工程AutoRun=ON		
				前処理工程step=1

				mSV1_給水電磁弁_給水中=OFF
				
				if FLOS2_洗米無洗米切換検知 then
					無洗米モード=ON
				else
					無洗米モード=OFF
				end if
				
				給水Inite=OFF

				即時運転モード=ON		
				予約運転モード=OFF
			
			end if
		end if

		if ldp(PB20_予約運転) and not(即時運転モード) and SSW4_納米庫自動 and not(PB19_即時運転) and PB21_前処理停止 and PB33_納米庫全停止 then 'and 前処理設定完了 then
			res(tim_RLY_レベルスイッチ)
			if not(前処理工程AutoRun) and  前処理工程step=0 and 計量step=0 and 洗米step=0 and (DM_Aタンク送米現在値<DM_Aタンク設定値 or DM_Bタンク送米現在値<DM_Bタンク設定値) then
				'完了フラグ=OFF
				
				if (DM_Aタンク設定値>0 and DM_Aタンク送米現在値=0) or (DM_Bタンク設定値>0 and DM_Bタンク送米現在値=0) then
					浸漬時間計測中=OFF
				end if
				
				
				if nottim_FLOS3_LMT121.B then '浸漬タンクA米なし
					DM_Aタンク送米現在値=0
				end if
				
				if nottim_FLOS4_LMT121.B then '浸漬タンクB米なし
					DM_Bタンク送米現在値=0
				end if

				if DM_Aタンク送米現在値>=DM_Aタンク設定値 then
					浸漬タンク準備完了A=ON
				else
					浸漬タンク準備完了A=OFF
				end if
				
				if DM_Bタンク送米現在値>=DM_Bタンク設定値 then
					浸漬タンク準備完了B=ON
				else 
					浸漬タンク準備完了B=OFF
				end if

				前処理注水完了=OFF
				前処理計量完了=OFF
				前処理完了=OFF

				即時運転モード=OFF		
				予約運転モード=ON

				mSV1_給水電磁弁_給水中=OFF

			end if
		end if
	

	end if
	'----------------------------------------------------------------------------------------------------------
	'洗浄タンク予約モード
	if 0 then
	if 洗浄タンク予約運転モード then
	
		if ldp(PB20_予約運転) or 即時運転モード or (SSW3_自動モード and PB22_自動運転) then
		    洗浄タンクAutoRun=OFF
			洗浄タンク予約運転モード=OFF
		end if
	
		if ldp(洗浄タンクONTIME) then
			    洗浄タンクAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
			    洗浄タンクAutoRun=ON
		else
			
			if (timFLT1_タンク上限.B and timFLT2_タンク下限.B) then
				if (timFLT3_タンク上限.B and timFLT4_タンク下限.B) then
					if (timFLT5_タンク上限.B and timFLT6_タンク下限.B) then
						if (timFLT7_タンク上限.B and timFLT8_タンク下限.B) then
							if (timFLT9_タンク上限.B and timFLT10_タンク下限.B) then
								洗浄タンク予約運転モード=OFF
							end if
						end if
					end if
				end if
			end if
			
		end if		
			
	else if ldp(PB20_予約運転) and not(即時運転モード) then
		洗浄タンク予約運転モード=ON		
	end if
	end if
	'----------------------------------------------------------------------------------------------------------

	

	if 予約運転モード  then

		if ldp(ONTIME) and 前処理完了=OFF and 前処理工程step=0 then
			if FLOS2_洗米無洗米切換検知 then
				無洗米モード=ON
			else
				無洗米モード=OFF
			end if

			予約運転モード=ON		
			
			前処理注水完了=OFF
			浸漬タンク準備完了A=OFF
			浸漬タンク準備完了B=OFF
			前処理計量完了=OFF
			前処理完了=OFF

			前処理工程AutoMode=ON
			前処理工程AutoRun=ON		
			前処理工程step=1
			
						
			mSV60_排水バルブ開A=OFF
			mSV2_充填バルブ開A=OFF
			ejectSV2_充填バルブ開A=OFF
			
			mSV62_排水バルブ開B=OFF
			mSV7_充填バルブ開B=OFF
			ejectSV7_充填バルブ開B=OFF			
			
			
		end if
		
	else
		'セレクトスイッチ=手動  納米庫全停止-> 前処理工程AutoRun=OFF
		'原点で停止中  -> セレクタスイッチでモード切替
		if SSW4_納米庫自動 and not(SSW4_納米庫手動) then
			前処理工程手動要求=OFF
			前処理工程AutoMode=ON
		else
			前処理工程AutoMode=OFF		
		end if

	end if

else

		即時運転モード=OFF
		即時運転モードEndWait=OFF
		洗浄タンク予約運転モード=OFF
		'予約運転モード=OFF
		予約運転モードEndWait=OFF
		前処理工程AutoMode=OFF
		前処理工程AutoRun=OFF
		前処理工程ErrStep=1
end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 前処理工程AutoMode	自動モード セレクトスイッチ
'System :: AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: 前処理工程Emg	その場停止



if 前処理工程EmgStep=0 then  
	
	if 前処理工程ErrStep=0  then
	
	if not(前処理工程OrgErr) then

	if 前処理工程AutoMode or 前処理工程step<>0 then
		
		if not(前処理工程AutoMode)  then
			計量AutoMode=OFF			
			前処理工程AutoRun=OFF
		else
			計量AutoMode=ON
		end if
	
		tmr(tim_procstep,tim_procstep_val)

		'--------------------------------------------------------------------------------------------------------------
		if 前処理完了 then
			前処理工程StatusMsg=#21	'	浸漬中
		else
			前処理工程StatusMsg=#20	'	前処理中;
		end if

		select case 前処理工程step
		case 0	' 終了待機
			前処理工程StatusMsg=#24	'	停止中
		case 1	' 実行
		' [ 自動継続運転 ]
			if 前処理工程AutoRun  then
				前処理工程StatusMsg=#22	'	自動運転中
				inc(前処理工程step)
			else 
				計量AutoRun=OFF
				if not(前処理注水完了) then '給水中
					mSV1_給水電磁弁=OFF
					ejectSV6_給水電磁弁A=OFF
					ejectSV11_給水電磁弁B=OFF				
				end if
				前処理工程step=0 '終了待機
			end if

		
		case 2
		' [ 注水準備完了 ]
			if 前処理注水完了  then
				inc(前処理工程step)
			else
				前処理工程step=1000 '注水準備
			end if
		
		case 3
		if not(前処理完了) then
			
			if not(前処理計量完了) then

				if 計量step=0 then	'計量
					if FLOS2_洗米無洗米切換検知 then
						無洗米モード=ON
					else
						無洗米モード=OFF
					end if

					計量step=1
					インターバル給水中=ON

				end if
				計量AutoRun=ON
					
			else
				
				if 計量step=0 and 洗米step=0 then
					前処理完了=ON
				end if

			end if
		
			前処理工程step=1
		else
		
			if 計量step=0 and 洗米step=0 then
				前処理工程step=0
			else
				前処理工程step=1
			end if			
			
		end if
		'--------------------------------------------------------------------------------------------------------------
		'タンク注水処理
		
		case 1000
		
			'浸漬タンクA 上限値 R41000=3670
			'浸漬タンクB 上限値 R41100=3670
			
		
			前処理注水完了=OFF
			前処理完了=OFF
			前処理計量完了=OFF
			
			
			
			if mSV1_給水電磁弁_給水中=OFF then '洗米機
				mSV1_給水電磁弁_給水中=ON
				tim_mSV1_給水電磁弁_val=#600
				res(tim_mSV1_給水電磁弁)
				mSV1_給水電磁弁=ON
			end if
			
			if DM_Aタンク設定値<>0 and DM_Aタンク送米現在値<DM_Aタンク設定値 and 浸漬タンクA水位現在値<3650 then  '浸漬タンクA
				浸漬タンクAユニットStatusMsg=#10	'	給水中
				ejectSV6_給水電磁弁A=ON
			else
				ejectSV6_給水電磁弁A=OFF
			end if
			
			if DM_Bタンク設定値<>0 and DM_Bタンク送米現在値<DM_Bタンク設定値 and 浸漬タンクB水位現在値<3650 then  '浸漬タンクB
				浸漬タンクBユニットStatusMsg=#10	'	給水中
				ejectSV11_給水電磁弁B=ON
			else 
				ejectSV11_給水電磁弁B=OFF
			end if
				
			inc(前処理工程step)
			
		case 1001
			tmr(mSV1_給水電磁弁 and RS1_水タンク上限センサー, tim_mSV1_給水電磁弁, tim_mSV1_給水電磁弁_val)
			if RS1_水タンク上限センサー and tim_mSV1_給水電磁弁.B  then
				mSV1_給水電磁弁=OFF
			end if

			if ejectSV6_給水電磁弁A and 浸漬タンクA水位現在値>3650 then
				ejectSV6_給水電磁弁A=OFF
			end if

			if ejectSV11_給水電磁弁B and 浸漬タンクB水位現在値>3650 then
				ejectSV11_給水電磁弁B=OFF
			end if

			if not(mSV1_給水電磁弁) and not(ejectSV6_給水電磁弁A) and not(ejectSV11_給水電磁弁B) then
				tim_procstep_val=0
				res(tim_procstep)	
				inc(前処理工程step)
			end if

			if not(PB21_前処理停止) or SSW4_納米庫手動 then
				mSV1_給水電磁弁=OFF
				ejectSV6_給水電磁弁A=OFF
				ejectSV11_給水電磁弁B=OFF
				前処理工程step=1		
			end if
						
						
		case 1002
			if DM_Aタンク設定値<>0 and DM_Aタンク送米現在値<DM_Aタンク設定値 then  '浸漬タンクA
				ejectSV6_給水電磁弁A=ON
			else
				ejectSV6_給水電磁弁A=OFF
			end if
			
			if DM_Bタンク設定値<>0 and DM_Bタンク送米現在値<DM_Bタンク設定値 then  '浸漬タンクB
				ejectSV11_給水電磁弁B=ON
			else 
				ejectSV11_給水電磁弁B=OFF
			end if
			
			if tim_procstep.B then
				ejectSV6_給水電磁弁A=OFF
				ejectSV11_給水電磁弁B=OFF
				inc(前処理工程step)
			end if		

			if not(PB21_前処理停止) or SSW4_納米庫手動 then
				mSV1_給水電磁弁=OFF
				ejectSV6_給水電磁弁A=OFF
				ejectSV11_給水電磁弁B=OFF
				前処理工程step=1		
			end if

		case 1003	
			前処理注水完了=ON			
			前処理工程step=1

		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		
		前処理工程AutoRun=OFF
		前処理工程step=0 '終了
		
		計量AutoRun=OFF
		if 計量step=0 then
			計量AutoMode=OFF
		end if
		
		洗米AutoRun=OFF
		if 洗米step=0 then
			洗米AutoMode=OFF
		end if

	end if '前処理工程AutoMode and not(前処理工程OrgErrStep)

	'===================================================================================================================
	'【 前処理工程OrgErr 】
	else

		前処理工程AutoRun=OFF
		前処理工程step=1

		計量AutoRun=OFF

		if 前処理工程OrgErr then
			if RestartFlg or PB34_リセット then
				if 前処理工程AutoMode then
					前処理工程AutoRun=ON
				end if
				前処理工程OrgErr=OFF
			end if		
		end if
		
	end if	
	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		前処理工程AutoRun=OFF

		PL2_異常=ON

		select case 前処理工程ErrStep
		case 0
		case 1
			if ResetFlg then
				inc(前処理工程ErrStep)
			end if
		case 2
			PL2_異常=OFF

			前処理工程ErrStep=0
		end select

	end if 'if 前処理工程ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 前処理工程EmgStep
	case 0
	
	case 1
		即時運転モード=OFF
		前処理工程AutoRun=OFF

		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if 前処理工程AutoMode or 前処理工程step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgSV1_給水電磁弁=ON
			EmgSV6_給水電磁弁A=ON
			EmgSV11_給水電磁弁B=ON
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_mSV1_給水電磁弁_stack=tim_mSV1_給水電磁弁.U
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV1_給水電磁弁=OFF
			ejectSV6_給水電磁弁A=OFF
			ejectSV11_給水電磁弁B=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(前処理工程EmgStep)
	case 2
		if ResetFlg then
			inc(前処理工程EmgStep)
		end if
	case 3
		if 前処理工程AutoMode or 前処理工程step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				EmgSV1_給水電磁弁=OFF
				EmgSV6_給水電磁弁A=OFF
				EmgSV11_給水電磁弁B=OFF

				tim_procstep.U=tim_procstep_stack
				tim_mSV1_給水電磁弁.U=tim_mSV1_給水電磁弁_stack
				'---------------------------------
				inc(前処理工程EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(前処理工程EmgStep)		
		end if				
	case 4
		timstack=OFF
		if 計量EmgStep=0 and 洗米EmgStep=0 then
			前処理工程EmgStep=0
			前処理工程Emg=OFF
		end if
	end select
		
end if 'if 前処理工程EmgStep=0 then
