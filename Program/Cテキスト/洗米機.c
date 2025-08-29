'洗米機
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	洗米ユニット
'	
'===================================================================================================================
'【 初期化処理 】
if CR2008 then
    洗米AutoMode=OFF
    洗米AutoRun=OFF
    洗米許可=ON
    洗米OrgErr=OFF
    洗米Err=OFF
    洗米Emg=OFF
    洗米step=0
    洗米ErrStep=0
    洗米OrgErrStep=0
    洗米EmgStep=0

end if
'===================================================================================================================
'【 原点 】
洗米Org=1


'===================================================================================================================
'【 緊急停止 】

tmr(not(ESPB1_非常停止),ESPB1_非常停止tim,2)
tmr(ESPB5_非常停止,ESPB5_非常停止tim,2)

if ESPB1_非常停止tim or ESPB5_非常停止tim then
	洗米Emg=ON
	洗米EmgStep=1
end if

'===================================================================================================================
' PLインジケータ

	PL3_無洗米切換 = FLOS2_洗米無洗米切換検知
	PBL46_送米ポンプ起動 = MC4_送米ポンプ
	
'===================================================================================================================
' センサー検出ディレイ―

	'tmr(PDL1_パドルセンサー上限A,tim_PDL1_パドルセンサー上限A,20)
	tmr(PDL2_パドルセンサー下限A,tim_PDL2_パドルセンサー下限A,20)
	'tmr(PDL3_パドルセンサー上限B,tim_PDL3_パドルセンサー上限B,20)
	tmr(PDL4_パドルセンサー下限B,tim_PDL4_パドルセンサー下限B,20)


'	tmr(MC4_送米ポンプ and not(RS1_水タンク上限センサー), nottimdly_RS1_水タンク上限センサー, #50)
'	if MC4_送米ポンプ and nottimdly_RS1_水タンク上限センサー.B  then

	tmr(mMC4_送米ポンプ and not(RS1_水タンク上限センサー), nottimdly_RS1_水タンク上限センサー, #50)
	if nottimdly_RS1_水タンク上限センサー.B  then
		pauseMC4_送米ポンプ=ON
	else
		pauseMC4_送米ポンプ=OFF	
	end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 洗米AutoMode	自動モード セレクトスイッチ
'System :: 洗米AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 洗米Emg	その場停止


if 洗米EmgStep=0 then  
	
	if 洗米ErrStep=0  then

	if not(洗米OrgErr) then

	if 洗米AutoMode or 洗米step<>0 then

		'if not(洗米AutoMode) then
			'洗米AutoRun=OFF
		'end if
		

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim洗米機,tim洗米機_val)

		
		select case 洗米step
		case 0

		case 1
			if 洗米AutoRun then
				inc(洗米step)			
			else
				mSV1_給水電磁弁=OFF
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=OFF
				洗米step=0
			end if
				
		case 2
			inc(洗米step)			

		case 3
			if not(計量動作中) then	'終了条件
				if 計量AutoMode or ((timPDL1_パドルセンサー上限A or DM_Aタンク送米現在値>=DM_Aタンク設定値) or (timPDL3_パドルセンサー上限B or DM_Bタンク送米現在値>=DM_Bタンク設定値)) then
					DM_洗米運転モード=2 '残米処理
					洗米step=40
				else
					tim洗米機_val=100
					res(tim洗米機)
					洗米step=50
				end if
			else
				inc(洗米step)
			end if
			
		case 4
			if 無洗米モード then
				DM_洗米運転モード=1 '無洗米処理
				洗米step=20
			else 
				DM_洗米運転モード=0 '洗米処理
				洗米step=10

			end if
		
		case 10 '洗米モード
			mSV1_給水電磁弁=ON
			mSV58_洗米バルブA=ON
			mMC5_洗米羽根=ON
			mMC4_送米ポンプ=ON
			洗米step=1
		
		case 20 '無洗米モード
			mSV1_給水電磁弁=ON
			mSV58_洗米バルブA=ON
			mMC5_洗米羽根=OFF
			mMC4_送米ポンプ=ON
			洗米step=1

		'----------------------------------------------------------
		' 残米処理
		case 40 
			if not(洗米AutoRun) then
				洗米step=1
			else if tim洗米機.B then
				mSV1_給水電磁弁=ON
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=ON

				tim洗米機_val=100  '送米ポンプ  送米待ち時間
				res(tim洗米機)
				inc(洗米step)
			end if					

		case 41
			if not(洗米AutoRun) then
				洗米step=1
			else if tim洗米機.B then
				mSV1_給水電磁弁=ON
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=OFF
				
				res(TIM_洗米バルブAON)
				res(TIM_洗米バルブAOFF)
				res(TIM_洗米バルブBON)
				res(TIM_洗米バルブBOFF)
				res(TIM_洗米羽根ON)
				res(TIM_洗米羽根OFF)

				tim洗米機_val=10 '送米ポンプ  完全停止待ち時間
				res(tim洗米機)
					
					'7分間残米処理
				
				
				if 無洗米モード then
					tim_インチング_val=インチング時間_無洗米 '1200 '2分=2x60=120.0
					res(tim_インチング)
				else
					tim_インチング_val=インチング時間_洗米 '4200 '7分=7x60=420.0
					res(tim_インチング)
				end if
				
				
				inc(洗米step)
			end if					
		case 42
			if not(洗米AutoRun) then
				洗米step=1		
			else if tim洗米機.B then
				mSV1_給水電磁弁=ON
				mMC4_送米ポンプ=ON
				
				if 無洗米モード then
					TIM_洗米バルブAON_val=洗米バルブAON時間_無洗米
					TIM_洗米バルブAOFF_val=洗米バルブAOFF時間_無洗米
					TIM_洗米バルブBON_val=洗米バルブBON時間_無洗米
					TIM_洗米バルブBOFF_val=洗米バルブBOFF時間_無洗米
					TIM_洗米羽根ON_val=洗米羽根ON時間_無洗米
					TIM_洗米羽根OFF_val=洗米羽根OFF時間_無洗米
				else
					TIM_洗米バルブAON_val=洗米バルブAON時間_洗米
					TIM_洗米バルブAOFF_val=洗米バルブAOFF時間_洗米
					TIM_洗米バルブBON_val=洗米バルブBON時間_洗米
					TIM_洗米バルブBOFF_val=洗米バルブBOFF時間_洗米
					TIM_洗米羽根ON_val=洗米羽根ON時間_洗米
					TIM_洗米羽根OFF_val=洗米羽根OFF時間_洗米
				end if
				
				tmr(TIM_洗米バルブAON,TIM_洗米バルブAON_val)
				tmr(TIM_洗米バルブAOFF,TIM_洗米バルブAOFF_val)
				tmr(TIM_洗米バルブBON,TIM_洗米バルブBON_val)
				tmr(TIM_洗米バルブBOFF,TIM_洗米バルブBOFF_val)
				tmr(TIM_洗米羽根ON,TIM_洗米羽根ON_val)
				tmr(TIM_洗米羽根OFF,TIM_洗米羽根OFF_val)
			
				
				if ldp(TIM_洗米バルブAOFF.B) then
					res(TIM_洗米バルブAON.B)
				else if ldp(TIM_洗米バルブAON.B) then
					res(TIM_洗米バルブAOFF.B)
				else if not(TIM_洗米バルブAON.B) then 'ON
					mSV58_洗米バルブA=ON
				else if not(TIM_洗米バルブAOFF.B) then 'OFF
					mSV58_洗米バルブA=OFF
				end if
			
				if ldp(TIM_洗米バルブBOFF.B) then
					res(TIM_洗米バルブBON.B)
				else if ldp(TIM_洗米バルブBON.B) then
					res(TIM_洗米バルブBOFF.B)
				end if
			
				if not(無洗米モード) then
				
					if ldp(TIM_洗米羽根OFF.B) then
						res(TIM_洗米羽根ON.B)
					else if ldp(TIM_洗米羽根ON.B) then
						res(TIM_洗米羽根OFF.B)
					else if not(TIM_洗米羽根ON.B) then 'ON
						mMC5_洗米羽根=ON
					else if not(TIM_洗米羽根OFF.B) then 'OFF
						mMC5_洗米羽根=OFF
					end if
				
				end if

				tmr(tim_インチング,tim_インチング_val)
				if tim_インチング.B then
					mSV58_洗米バルブA=OFF
					mMC5_洗米羽根=OFF
					inc(洗米step)
				end if

			end if					
		case 43
			if not(洗米AutoRun) then
				洗米step=1		
			else if tim洗米機.B then
				mSV1_給水電磁弁=ON
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=ON

				tim洗米機_val=100 '送米ポンプ  送米待ち時間
				res(tim洗米機)
				inc(洗米step)
			end if
		case 44
			if not(洗米AutoRun) then
				洗米step=1		
			else if tim洗米機.B then
				mSV1_給水電磁弁=ON
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=OFF

				tim洗米機_val=100 '送米ポンプ  送米停止待ち時間(送米タンクに水を張る）
				res(tim洗米機)
				inc(洗米step)
			end if
		case 45
			if not(洗米AutoRun) then
				洗米step=1		
			else if tim洗米機.B then
				mSV1_給水電磁弁=ON
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=ON

				tim洗米機_val=100 '送米ポンプ  送米待ち時間
				res(tim洗米機)
				inc(洗米step)
			end if
		case 46			
			if not(洗米AutoRun) then
				洗米step=1		
			else if tim洗米機.B then
				mSV1_給水電磁弁=OFF
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=OFF
				inc(洗米step)
			end if
		case 47
				洗米AutoRun=OFF
				洗米step=0

		case 50		
			if not(洗米AutoRun) then
				洗米step=1		
			else if tim洗米機.B then
				mSV1_給水電磁弁=OFF
				mSV58_洗米バルブA=OFF
				mMC5_洗米羽根=OFF
				mMC4_送米ポンプ=OFF
				洗米step=0
			end if
		end select
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		
		'洗米AutoRun=OFF
		if not(PB47_送米ポンプ停止) then '停止スイッチによる停止
				mMC4_送米ポンプ=OFF
		else if ldp(PB46_送米ポンプ起動) then '起動スイッチによるポンプON
			if RS1_水タンク上限センサー then
				mMC4_送米ポンプ=ON
			end if
		else if ldp(pnlPBMC4_送米ポンプ) then 'パネルスイッチによるポンプON/OFF
			if mMC4_送米ポンプ or pauseMC4_送米ポンプ then
				mMC4_送米ポンプ=OFF
				pauseMC4_送米ポンプ=OFF
			else if RS1_水タンク上限センサー then
				mMC4_送米ポンプ=ON
			end if
		end if
		
		if ldp(pnlPBMC5_洗米羽根) then
			if mMC5_洗米羽根 then
				mMC5_洗米羽根=OFF
			else
				mMC5_洗米羽根=ON
			end if
		end if

		if ldp(pnlPBSV1_給水電磁弁) then
			if mSV1_給水電磁弁 then
				mSV1_給水電磁弁=OFF
			else
				mSV1_給水電磁弁=ON
			end if
		end if
		
		if ldp(pnlPBSV58_洗米バルブA) then
			if mSV58_洗米バルブA then
				mSV58_洗米バルブA=OFF
			else
				mSV58_洗米バルブA=ON
			end if
		end if
		
		if ldp(pnlPBSV12_送米切換バルブA側) and not(mSV12_送米切換バルブA側) then
				mSV12_送米切換バルブA側=ON
				mSV13_送米切換バルブB側=OFF
		else if ldp(pnlPBSV13_送米切換バルブB側) and not(mSV13_送米切換バルブB側) then
				mSV12_送米切換バルブA側=OFF
				mSV13_送米切換バルブB側=ON
		end if
		
	
	end if '洗米AutoMode and not(洗米OrgErrStep)

	'===================================================================================================================
	'【 洗米OrgErr処理 】
	else
	
		洗米AutoRun=OFF
		洗米step=1
		
		if 洗米OrgErr then
			if ResetFlg then
				if 洗米AutoMode then
					洗米AutoRun=ON
				end if
				洗米OrgErr=OFF
			end if		
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		PL2_異常=ON

		pauseMC4_送米ポンプ=ON
		pauseMC5_洗米羽根=ON


		select case 洗米ErrStep
		case 0
		case 1
			if ResetFlg then
				inc(洗米ErrStep)
			end if
		case 2

			pauseMC4_送米ポンプ=OFF
			pauseMC5_洗米羽根=OFF

			PL2_異常=OFF
			洗米ErrStep=0
		end select

	end if 'if 洗米ErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else


	select case 洗米EmgStep
	case 0

	case 1
		洗米AutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (洗米AutoMode and 自動搬送AutoMode) or 洗米step<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseSV1_給水電磁弁=ON
			pauseSV58_洗米バルブA=ON
			pauseMC5_洗米羽根=ON
			pauseMC4_送米ポンプ=ON			
			pauseSV12_送米切換バルブA側=ON
			pauseSV13_送米切換バルブB側=ON

			if timstack=OFF then
				tim_procstep_stack=tim洗米機.U
				TIM_洗米バルブAON_stack=TIM_洗米バルブAON.U
				TIM_洗米バルブAOFF_stack=TIM_洗米バルブAOFF.U
				TIM_洗米バルブBON_stack=TIM_洗米バルブBON.U
				TIM_洗米バルブBOFF_stack=TIM_洗米バルブBOFF.U
				TIM_洗米羽根ON_stack=TIM_洗米羽根ON.U
				TIM_洗米羽根OFF_stack=TIM_洗米羽根OFF.U
				tim_インチング_stack=tim_インチング.U
				timstack=ON
			end if
			
			'---------------------------------
		else
			'---------------------------------
			'緊急停止処理(手動）
			'---------------------------------
			mSV1_給水電磁弁=OFF
			mSV58_洗米バルブA=OFF
			mMC5_洗米羽根=OFF
			mMC4_送米ポンプ=OFF
			mSV12_送米切換バルブA側=OFF
			mSV13_送米切換バルブB側=OFF		
			'---------------------------------
		end if
		
		'---------------------------------
		inc(洗米EmgStep)
	case 2
		if ResetFlg then
			inc(洗米EmgStep)
		end if
	case 3
		if (洗米AutoMode and 自動搬送AutoMode) or 洗米step<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseSV1_給水電磁弁=OFF
				pauseSV58_洗米バルブA=OFF
				pauseMC5_洗米羽根=OFF
				pauseMC4_送米ポンプ=OFF
				pauseSV12_送米切換バルブA側=OFF
				pauseSV13_送米切換バルブB側=OFF

				tim洗米機.U=tim_procstep_stack
				TIM_洗米バルブAON.U=TIM_洗米バルブAON_stack
				TIM_洗米バルブAOFF.U=TIM_洗米バルブAOFF_stack
				TIM_洗米バルブBON.U=TIM_洗米バルブBON_stack
				TIM_洗米バルブBOFF.U=TIM_洗米バルブBOFF_stack
				TIM_洗米羽根ON.U=TIM_洗米羽根ON_stack
				TIM_洗米羽根OFF.U=TIM_洗米羽根OFF_stack
				tim_インチング.U=tim_インチング_stack
				
				'---------------------------------
				inc(洗米EmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(洗米EmgStep)		
		end if				
	case 4
		timstack=OFF	
		洗米EmgStep=0
		洗米Emg=OFF
	end select
		
end if 'if 洗米EmgStep=0 then
