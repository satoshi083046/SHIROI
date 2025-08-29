'むらし機釜送りコンベア
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	むらし機釜送りコンベア
'
' tmr(pauseMC17_むらしモータ,,) → pauseMC17_むらしモータの時間監視
'
'
' if むらしモータpause then
'	[] むらしモータ pause状態処理		
' else 
'-----------------------------------------------------------------
'	むらし釜送りコンベアstep	
'		
'-----------------------------------------------------------------
'0: 何もしない待機		
'		
'-----------------------------------------------------------------
'1:インバータ起動待ち
'		
'-----------------------------------------------------------------
'2:スタート時の状態検知	
'	むらしモータが途中位置		step=300
'		
'	むらし出口に釜有 			step=500
'	むらし入口に釜有			step=300
'	炊飯出口に釜有				step=200
'
'	その他 step=100 炊飯出口 （トリガ待ち）
'
'-----------------------------------------------------------------
'【 一連動作 】				
'-----------------------------------------------------------------
'100: 
'	インバータ運転検知  -> off時 step=1		
'
'	炊飯出口 釜検知 （トリガ待ち）	
'	[]むらし入口,むらし出口,pause状態 釜有エラー <むらし入口渋滞>
'
'-----------------------------------------------------------------
'200: 炊飯出口 釜搬送				
'	[]むらし出口,pause状態 釜有エラー  <むらし出口渋滞>	
'201: MC18_釜送りstep=1
'
'-----------------------------------------------------------------
'300: むらし入口釜搬送				
'	[]むらし出口,pause状態 釜有エラー  <むらし出口渋滞>		
'301: MC17_むらし機モータstep 
'
'-----------------------------------------------------------------
'400: むらし出口釜搬送				MC19_搬送モータstep
'401: 
'		
'-----------------------------------------------------------------
'500:
'	step=100 インバータ運転検知 or 炊飯出口 釜検知(トリガ待ち)
'
'===================================================================================================================
			
'【 初期化処理 】
'if CR2008 or ldp(INV4_コンベア動作中) or ldp(RLY_むらし電源確認) then '電源ON時初期化処理
if CR2008 or not(RLY_むらし電源確認) then '電源ON時初期化処理

	'INV4_インバータ運転中と同期するため、INV4_インバータ運転中  or AutoRun が起動条件になる。

    むらし機釜送りコンベアAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    むらし機釜送りコンベアAutoRun=ON
    むらし機釜送りコンベア許可=ON
    むらし機釜送りコンベアOrgErr=OFF
    むらし機釜送りコンベアErr=OFF
    むらし機釜送りコンベアEmg=OFF
    むらし機釜送りコンベアstep=0
    むらし機釜送りコンベアErrStep=0
    むらし機釜送りコンベアOrgErrStep=0
    むらし機釜送りコンベアEmgStep=0
	
	MC17_むらし機モータstep=0
	MC18_釜送りstep=0
	MC19_搬送モータstep=0

	mINV4_インバータ正転=OFF
	mINV4_インバータ停止=OFF
	mMC17_むらし機モータ=OFF
	mMC18_釜送り逆転=OFF
	mMC18_釜送り正転=OFF
	mMC19_搬送モータ=OFF

end if


'===================================================================================================================
'【 原点 】
むらし機釜送りコンベアOrg=SSW1_2_運転切換（連動） and not(MC17_むらし機モータ) and not(mMC17_むらし機モータ) and LS3_むらし機ピッチ検知
				
if mMC18_釜送り正転 and LS1_釜送り前進端 then
	mMC18_釜送り正転=OFF
end if
if mMC18_釜送り逆転 and LS2_釜送り後退端 then
	mMC18_釜送り逆転=OFF
end if

if ldp(INV4_コンベア動作中) then
	if LS31_むらし機入口センサ and not(MC17_むらし機モータ) and not(mMC17_むらし機モータ) then
		MC17_むらし機モータ起動=ON
	else
		MC17_むらし機モータ起動=OFF
	end if
end if
'--------------------------------------------------------------------
'自動起動、自動停止時の炊飯機インバータ起動、停止

	if ldp(自動搬送AutoRun) then
		mINV4_インバータ正転=ON
		mINV4_インバータ停止=OFF
	else if 自動搬送AutoMode and not(自動搬送AutoRun) then
		mINV4_インバータ正転=OFF
		mINV4_インバータ停止=ON
	end if

	if INV4_コンベア動作中 then
		mINV4_インバータ正転=OFF
	else if not(INV4_コンベア動作中) then
		mINV4_インバータ停止=OFF
	end if

	if むらし釜送りコンベア禁止 then
		mMC18_釜送り逆転=OFF		
		mMC18_釜送り正転=OFF
	end if

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	むらし機釜送りコンベアEmg=ON
	むらし機釜送りコンベアEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(not(SV41_リフト) and not(XSW47_リフト下降端) and not(pnlPBXSW47_リフト下降端),tim_notXSW47_リフト下降端,#30) '1607.98ms

if LDF(SV41_リフト) and  XSW47_リフト下降端 and XSW48_リフト上昇端 and not(pnlPBXSW47_リフト下降端) then
	SET(tim_XSW47_リフト下降端)
end if

tmr(MC18_釜送り正転 and not(pauseMC18_釜送り正転) and not(EmgMC18_釜送り正転) and not(むらし釜送りコンベア禁止),tim_MC18_釜送り正転,#120)
tmr(MC18_釜送り逆転 and not(pauseMC18_釜送り逆転) and not(EmgMC18_釜送り逆転) and not(むらし釜送りコンベア禁止),tim_MC18_釜送り逆転,#120)

'   出口にある釜を排出中       むらし機モータ回転中                        
tmr(MC17_むらし機モータ and not(LS3_むらし機ピッチ検知),tim_LS3_むらし機ピッチ検知,#215) '#215) '25.0 LSはずれまでの時間 5.48

tmr(ejectMC19_搬送モータ and not(pauseMC19_搬送モータ) and not(EmgMC19_搬送モータ),tim_ejectMC19_搬送モータ,#100)

'LS3_むらし機ピッチ検知 - LS3_むらし機ピッチ検知 までの実測値=25Sec

'リミットLSのチャタリング防止
tmr(LS3_むらし機ピッチ検知, timdlyLS3_むらし機ピッチ検知,10)
tmr(not(LS3_むらし機ピッチ検知), timnotdlyLS3_むらし機ピッチ検知,10)

'むらし入口釜送りトリガ
tmr(PH56_釜送りトリガ ,tim_PH56_釜送りトリガ,#50)

if MC17_むらし機モータ起動 and PH21_むらし機出口センサ then
	alm渋滞警報=ON			
	alm渋滞警報出口=ON
	むらし機釜送りコンベアErrStep=1	
end if

if LS1_釜送り前進端 and LS2_釜送り後退端  and not(むらし釜送りコンベア禁止) then
	errpassLS1_釜送り前進端=ON
	errpassLS2_釜送り後退端=ON
	almLS1_釜送り前進端=ON
	almMC18_釜送り正転=ON
	almLS2_釜送り後退端=ON
	almMC18_釜送り逆転=ON
	
	むらし機釜送りコンベアErrStep=1

else if ldp(tim_MC18_釜送り正転.B)  and not(むらし釜送りコンベア禁止) then
	errpassLS1_釜送り前進端=ON
	almLS1_釜送り前進端=ON
	almMC18_釜送り正転=ON
	むらし機釜送りコンベアErrStep=1

else if ldp(tim_MC18_釜送り逆転.B)  and not(むらし釜送りコンベア禁止) then
	errpassLS2_釜送り後退端=ON
	almLS2_釜送り後退端=ON
	almMC18_釜送り逆転=ON
	むらし機釜送りコンベアErrStep=1

else if ldp(tim_LS3_むらし機ピッチ検知.B) or (ldp(timdlyLS3_むらし機ピッチ検知.B) and not(PH21_むらし機出口センサ) and 0) then
	
	if tim_LS3_むらし機ピッチ検知.B then
		almLS3_むらし機ピッチ検知=ON
	else if timdlyLS3_むらし機ピッチ検知.B and not(PH21_むらし機出口センサ) then
		almPH21_むらし機出口センサ=ON
	end if
	
	
	mMC17_むらし機モータ=OFF
	
	むらし機釜送りコンベアstep=0
	manuMC17_むらし機モータstep=0
	MC17_むらし機モータstep=0	
	MC17_むらし機モータ起動=OFF
	ピッチ検知完了=OFF

	むらし機釜送りコンベアErrStep=1

else if ldp(tim_ejectMC19_搬送モータ.B) then
	almMC19_搬送モータ=ON
	ejectMC19_搬送モータ=OFF
	errpassコンベア一時停止=ON
	
	むらし機釜送りコンベアErrStep=1

else if (LDP(tim_notXSW47_リフト下降端) or LDP(tim_XSW47_リフト下降端)) and not(pnlPBXSW47_リフト下降端) then
	almXSW47_リフト下降端=ON
	pnlPBXSW47_リフト下降端=ON
	errpassコンベア一時停止=ON

	むらし機釜送りコンベアErrStep=1
end if

if MC17_むらし機モータ起動 and PH21_むらし機出口センサ then
	mMC17_むらし機モータ=OFF
	alm渋滞警報=ON			
	alm渋滞警報出口=ON
	むらし機釜送りコンベアErrStep=1
end if

'===================================================================================================================
' PLインジケータ

	if manuMC17_むらし機モータstep<>0 then
		PBL15_むらし機運転中=ON
	else
		PBL15_むらし機運転中=OFF
	end if


	'停止スイッチ
	if CSR1_ショックリレー or (not(むらし機釜送りコンベアAutoRun) and SSW1_1_運転切換（単動） and not(PB16_むらし機停止)) then
		むらし機釜送りコンベアstep=0
		mMC17_むらし機モータ=OFF
		manuMC17_むらし機モータstep=0
		MC17_むらし機モータstep=0
		MC17_むらし機モータ起動=OFF
		ピッチ検知完了=OFF

	end if

'===================================================================================================================
'むらしピッチ送りの待機(Pause)
'むらし機がピッチ送り回転中にDコンベアがエスケープリフト上のワークを搬送しようとすると、同じコンベアでむらし機出口の
'ワークまで搬送されてしまう。
'   <誤動作>
'   むらし回転中で  出口未到達  →   
'
'                                  [むらし出口のワーク]    [エスケープリフト上のワーク]  → Dコンベア搬送
'	<改善>
'   むらし回転中で  出口未到達  → [-むらし出口のワーク-]   [エスケープリフト上のワーク]
'									むらし回転、一時停止    [エスケープリフト上のワーク]  → Dコンベア搬送
'						          [-むらし出口のワーク-]  
'                                    むらし回転、一時停止解除                                  
'								  [むらし出口のワーク]
	tmr(PH22_釜検知,timdlyPH22_釜検知,2)
'	if mMC17_むらし機モータ and tim_PH21_むらし機出口センサ.B	then

	if mMC17_むらし機モータ and PH21_むらし機出口センサ then
		if timdlyPH22_釜検知.B or mMC19_搬送モータ then
			pauseMC17_むらし機モータ=ON
			
			if ldp(pauseMC17_むらし機モータ) then
				alm渋滞警報=ON			
				alm渋滞警報出口=ON
				むらし機釜送りコンベアErrStep=1
			end if
		
		else
			pauseMC17_むらし機モータ=OFF	
		end if
	else
		pauseMC17_むらし機モータ=OFF

		if alm渋滞警報出口 and mMC17_むらし機モータ=OFF then
			むらし機釜送りコンベアErrStep=1
		end if

	end if
	
	
	if INV4_コンベア動作中 and PH57_釜検知ステージ then
		tmr(INV4_コンベア動作中 and PH57_釜検知ステージ,timon_PH57_釜検知ステージ,150)
		if ldp(timon_PH57_釜検知ステージ.B) then
			alm渋滞警報=ON			
			alm渋滞警報入口=ON
			むらし機釜送りコンベアErrStep=1
		end if
	else
		res(timon_PH57_釜検知ステージ)
	end if
	

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: むらし機釜送りコンベアAutoMode	自動モード セレクトスイッチ
'System :: AutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: むらし機釜送りコンベアEmg	その場停止


if MC17_むらし機モータstep=0 and MC18_釜送りstep=0 and MC19_搬送モータstep=0 then
	
	if ldp(INV4_コンベア動作中) then
		if むらし機釜送りコンベアstep=0 then
			むらし機釜送りコンベアstep=1
		end if
		ピッチ検知完了=OFF
	end if
	
end if
'--------------------------------------------
'排出は終了まで実行
'--------------------------------------------
'MC19_搬送モータ 釜排出モータ
tmr(PH21_むらし機出口センサ,tim_PH21_むらし機出口センサ,#5) 
tmr(PH22_釜検知,tim_PH22_釜検知,#5) 

tmr(tim_MC19_搬送モータ,tim_MC19_搬送モータ_val)
select case MC19_搬送モータstep
case 0
	'mconvMC19_搬送モータ=OFF

case 1
	if PH21_むらし機出口センサ then
		errpassコンベア一時停止=OFF
		inc(MC19_搬送モータstep)
	else
		MC19_搬送モータstep=0
	end if

case 2
	if not(mMC19_搬送モータ) then
		mSV41_リフト=OFF
		errpassコンベア一時停止=OFF		
		inc(MC19_搬送モータstep)
	end if
	
case 3	
	if errpassコンベア一時停止 or ((XSW47_リフト下降端 and not(pnlPBXSW47_リフト下降端)) or passXSW47_リフト下降端) then
		ejectMC19_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC19_搬送モータstep)
	end if						

case 4
	if errpassコンベア一時停止 then
		inc(MC19_搬送モータstep)

	else if not(PH21_むらし機出口センサ) then
		res(tim_PH21_むらし機出口センサ)
		inc(MC19_搬送モータstep)
	end if
	
case 5
	if errpassコンベア一時停止 then
		inc(MC19_搬送モータstep)

	else if PH22_釜検知 then
		inc(MC19_搬送モータstep)
	end if			

case 6
	tim_MC19_搬送モータ_val=#21 'リフトセンター、位置合わせ時間
	res(tim_MC19_搬送モータ)
	inc(MC19_搬送モータstep)

case 7
	if tim_MC19_搬送モータ.B then
		ejectMC19_搬送モータ=OFF
		inc(MC19_搬送モータstep)
	end if

case 8
	'エスケープ中、フタ取りに釜、フタがあったらエスケープリフト
	if エスケープ中 or PH23_釜検知 or PH24_フタ検知 or フタ取りフタ取り中 then
		mSV41_リフト=ON
	else
		mSV41_リフト=OFF
	end if
	inc(MC19_搬送モータstep)

case 9
	MC19_搬送モータstep=0

end select
'--------------------------------------------
' 釜送り正転逆転
tmr(tim_MC18_釜送り,tim_MC18_釜送り_val)
select case MC18_釜送りstep
case 0
	'mMC18_釜送り正転=OFF
	'mMC18_釜送り逆転=OFF

case 1
  	if not(むらし釜送りコンベア禁止) then
		mMC18_釜送り正転=ON
		errpassLS1_釜送り前進端=OFF
		inc(MC18_釜送りstep)
	else
		MC18_釜送りstep=0
	end if
	
case 2
	if LS1_釜送り前進端 or errpassLS1_釜送り前進端 then
		inc(MC18_釜送りstep)
	end if			

case 3
	mMC18_釜送り正転=OFF
	tim_MC18_釜送り_val=むらし釜送り待機時間 'R=45 L=30
	res(tim_MC18_釜送り)
	inc(MC18_釜送りstep)

case 4
	if tim_MC18_釜送り.B then
		inc(MC18_釜送りstep)
	end if

case 5
	mMC18_釜送り逆転=ON
	errpassLS2_釜送り後退端=OFF
	inc(MC18_釜送りstep)

case 6
	if LS2_釜送り後退端  or errpassLS2_釜送り後退端 then
		inc(MC18_釜送りstep)
	end if

case 7
	mMC18_釜送り逆転=OFF

	if PH21_むらし機出口センサ then
		alm渋滞警報=ON			
		alm渋滞警報出口=ON
		むらし機釜送りコンベアErrStep=1
	end if

	MC17_むらし機モータ起動=ON
	MC18_釜送りstep=0

end select

'--------------------------------------------
' むらしピッチ送り
tmr(tim_MC17_むらし機モータ,tim_MC17_むらし機モータ_val)

select case MC17_むらし機モータstep
case 0
	'mMC17_むらし機モータ=OFF
case 1
	if MC17_むらし機モータ起動 then
		if PH21_むらし機出口センサ then
			alm渋滞警報=ON			
			alm渋滞警報出口=ON
			むらし機釜送りコンベアErrStep=1
			MC17_むらし機モータstep=0	
		else
			MC17_むらし機モータ起動=OFF
			mMC17_むらし機モータ=ON
			inc(MC17_むらし機モータstep)
		end if
	else 
			mMC17_むらし機モータ=ON
			inc(MC17_むらし機モータstep)
	end if
	
case 2
	if not(LS3_むらし機ピッチ検知) and timnotdlyLS3_むらし機ピッチ検知.B then
		res(timdlyLS3_むらし機ピッチ検知)
		inc(MC17_むらし機モータstep)
	end if

case 3
	if LS3_むらし機ピッチ検知  and timdlyLS3_むらし機ピッチ検知.B then
		res(timnotdlyLS3_むらし機ピッチ検知)
		inc(MC17_むらし機モータstep)
	end if

case 4
	mMC17_むらし機モータ=OFF
	MC17_むらし機モータstep=0
	
end select


if むらし機釜送りコンベアEmgStep=0 then  
	
	if むらし機釜送りコンベアErrStep=0  then

	if not(むらし機釜送りコンベアOrgErr) then

		if not(むらし機釜送りコンベアAutoMode and 自動搬送AutoMode ) then
			むらし機釜送りコンベアAutoRun=OFF
		end if

	if (INV4_コンベア動作中  or むらし機釜送りコンベアstep<>0 or MC17_むらし機モータstep<>0 or  MC18_釜送りstep<>0) and manuMC17_むらし機モータstep=0 then
	
	
	

		'===================================================================================================================
		'【 むらし釜送りコンベア 】
		'

		select case むらし機釜送りコンベアstep
		case 0
		
		case 1
			if INV4_コンベア動作中 then
				inc(むらし機釜送りコンベアstep)
			else
				むらし機釜送りコンベアstep=0
			end if
			
		'--------------------------------------------
		'運転準備
		case 2
			if ピッチ検知完了 then
				むらし機釜送りコンベアstep=100
			else
				inc(むらし機釜送りコンベアstep)
			end if
		
		case 3
			if not(LS3_むらし機ピッチ検知) then
				MC17_むらし機モータstep=1 'むらし入口側を開ける強制的にむらしコンベアを1ピッチ動作
				inc(むらし機釜送りコンベアstep)
			else
				むらし機釜送りコンベアstep=100
			end if			
			
		case 4
			if MC17_むらし機モータstep=0 then	
				むらし機釜送りコンベアstep=100
			end if
		'--------------------------------------------
		'運転			
 		case 100
			ピッチ検知完了=ON
		'--------------------------------------------
		'むらし出口側						
			if PH21_むらし機出口センサ then 
				if LS3_むらし機ピッチ検知 and not(PH22_釜検知) and not(mMC19_搬送モータ) and MC19_搬送モータstep=0 then
					MC19_搬送モータstep=1
				end if
			else
				if 	MC17_むらし機モータ起動 and LS3_むらし機ピッチ検知 and MC19_搬送モータstep=0 and MC17_むらし機モータstep=0 and MC18_釜送りstep=0 then
						MC17_むらし機モータstep=1
				end if
			end if

		'--------------------------------------------
		'むらし入口側
			if (tim_PH56_釜送りトリガ.B or むらし釜送りコンベア禁止) and MC17_むらし機モータstep=0 and MC18_釜送りstep=0 then
			 	if not(INV4_コンベア動作中) then
					むらし機釜送りコンベアstep=0
				else if not(MC17_むらし機モータ起動) then
					if not(むらし釜送りコンベア禁止) and not(LS31_むらし機入口センサ) then
						MC18_釜送りstep=1
					else if むらし釜送りコンベア禁止 and ldp(timLS31_むらし機入口センサ) then
						MC17_むらし機モータ起動=ON
					end if
				end if
			end if

			むらし機釜送りコンベアstep=1
		'--------------------------------------------
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if not(むらし機釜送りコンベアAutoRun)  or manuMC17_むらし機モータstep<>0 then 
		
		むらし機釜送りコンベアstep=0 '終了
			'--------------------------------------------
			' 手動むらしピッチ送り
			if (ldp(PB15_むらし機運転 and SSW1_1_運転切換（単動）) or (ldp(pnlPBMC17_むらし機モータ) and SSW1_2_運転切換（連動）) ) and  manuMC17_むらし機モータstep=0 then  
				if not(LS3_むらし機ピッチ検知 and PH21_むらし機出口センサ) then
				manuMC17_むらし機モータstep=1
				end if
			end if
			
			tmr(tim_manuMC17_むらし機モータ,tim_manuMC17_むらし機モータ_val)
			select case manuMC17_むらし機モータstep
			case 0
			
			case 1 
				mMC17_むらし機モータ=ON
				inc(manuMC17_むらし機モータstep)
			
			case 2
				if not(LS3_むらし機ピッチ検知) and timnotdlyLS3_むらし機ピッチ検知 then
					inc(manuMC17_むらし機モータstep)
				end if
				
			case 3
				if LS3_むらし機ピッチ検知 and timdlyLS3_むらし機ピッチ検知 then
					mMC17_むらし機モータ=OFF
					manuMC17_むらし機モータstep=0
				end if
			end select
			
			'--------------------------------------------
			if SSW1_2_運転切換（連動） then
			
				if ldp(pnlPBMC18_釜送り正転) then
					if mMC18_釜送り正転 then
						mMC18_釜送り正転=OFF
					else if not(mMC18_釜送り逆転) then
						mMC18_釜送り正転=ON
						mMC18_釜送り逆転=OFF
					end if
				else if ldp(pnlPBMC18_釜送り逆転) then
					if mMC18_釜送り逆転 then
						mMC18_釜送り逆転=OFF
					else if not(mMC18_釜送り正転) then
						mMC18_釜送り正転=OFF
						mMC18_釜送り逆転=ON	
					end if
				end if
			end if
			'--------------------------------------------
		end if
			
	end if 'むらし機釜送りコンベアAutoMode and not(むらし機釜送りコンベアOrgErrStep)

	'===================================================================================================================
	'【 むらし機釜送りコンベアOrgErr処理 】
	else
	
		if ResetFlg then
			むらし機釜送りコンベアOrgErr=OFF
		end if

	end if

	'==================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		むらし機釜送りコンベアErr=ON

		pauseMC18_釜送り正転=ON
		pauseMC18_釜送り逆転=ON
		pauseMC17_むらし機モータ=ON
		
		mINV4_インバータ停止=ON

		select case むらし機釜送りコンベアErrStep
		case 0
		case 1
			if ResetFlg then
				almXSW47_リフト下降端=OFF
				almMC19_搬送モータ=OFF
				almLS1_釜送り前進端=OFF
				almLS2_釜送り後退端=OFF
				almMC18_釜送り正転=OFF
				almMC18_釜送り逆転=OFF
				almLS3_むらし機ピッチ検知=OFF
				almPH21_むらし機出口センサ=OFF
				alm渋滞警報=OFF
				alm渋滞警報出口=OFF
				alm渋滞警報入口=OFF
				inc(むらし機釜送りコンベアErrStep)
			end if
			if timerrstack=OFF then
				timdlyLS3_むらし機ピッチ検知_stack.U=timdlyLS3_むらし機ピッチ検知.U
				timerrstack=ON
			end if
			
		case 2

			res(tim_notXSW47_リフト下降端)
			res(tim_XSW47_リフト下降端)
			res(tim_MC18_釜送り正転)
			res(tim_MC18_釜送り逆転)
			timdlyLS3_むらし機ピッチ検知.U=timdlyLS3_むらし機ピッチ検知_stack.U
			timerrstack=OFF
			
			pauseMC18_釜送り正転=OFF
			pauseMC18_釜送り逆転=OFF
			pauseMC17_むらし機モータ=OFF

			むらし機釜送りコンベアErr=OFF
			
			むらし機釜送りコンベアErrStep=0
		end select

	end if 'if むらし機釜送りコンベアErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case むらし機釜送りコンベアEmgStep
	case 0
	
	case 1
		むらし機釜送りコンベアAutoRun=OFF
		
		EmgMC17_むらし機モータ=ON
		EmgMC18_釜送り逆転=ON
		EmgMC18_釜送り正転=ON
		EmgMC19_搬送モータ=ON
		
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (INV4_コンベア動作中  or むらし機釜送りコンベアstep<>0 or MC17_むらし機モータstep<>0 or  MC18_釜送りstep<>0) and manuMC17_むらし機モータstep=0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgMC17_むらし機モータ=ON
			EmgMC18_釜送り逆転=ON
			EmgMC18_釜送り正転=ON
			EmgMC19_搬送モータ=ON
			

			if timstack=OFF then
				timdlyLS3_むらし機ピッチ検知_stack.U=timdlyLS3_むらし機ピッチ検知.U
				timnotdlyLS3_むらし機ピッチ検知_stack.U=timnotdlyLS3_むらし機ピッチ検知.U
				tim_PH56_釜送りトリガ_stack.U=tim_PH56_釜送りトリガ.U
				timdlyPH22_釜検知_stack.U=timdlyPH22_釜検知.U
				timon_PH57_釜検知ステージ_stack.U=timon_PH57_釜検知ステージ.U
				tim_PH21_むらし機出口センサ_stack.U=tim_PH21_むらし機出口センサ.U
				tim_PH22_釜検知_stack.U=tim_PH22_釜検知.U
				tim_MC19_搬送モータ_stack.U=tim_MC19_搬送モータ.U
				tim_MC18_釜送り_stack.U=tim_MC18_釜送り.U
				tim_MC17_むらし機モータ_stack.U=tim_MC17_むらし機モータ.U
				tim_manuMC17_むらし機モータ_stack.U=tim_manuMC17_むらし機モータ.U
			' tmr(LS3_むらし機ピッチ検知, timdlyLS3_むらし機ピッチ検知,2)
			' tmr(not(LS3_むらし機ピッチ検知), timnotdlyLS3_むらし機ピッチ検知,2)
			' tmr(PH56_釜送りトリガ,tim_PH56_釜送りトリガ,#50)
			' tmr(PH22_釜検知,timdlyPH22_釜検知,2)
			' tmr(INV4_コンベア動作中 and PH57_釜検知ステージ,timon_PH57_釜検知ステージ,150)
			' tmr(PH21_むらし機出口センサ,tim_PH21_むらし機出口センサ,#5) 
			' tmr(PH22_釜検知,tim_PH22_釜検知,#5) 
			' tmr(tim_MC19_搬送モータ,tim_MC19_搬送モータ_val)
			' tmr(tim_MC18_釜送り,tim_MC18_釜送り_val)
			' tmr(tim_MC17_むらし機モータ,tim_MC17_むらし機モータ_val)
			' tmr(tim_manuMC17_むらし機モータ,tim_manuMC17_むらし機モータ_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC17_むらし機モータ=OFF
			mMC18_釜送り正転=OFF
			mMC18_釜送り逆転=OFF

			manuMC17_むらし機モータstep=0
			'---------------------------------
		end if
		
		'---------------------------------
		inc(むらし機釜送りコンベアEmgStep)
	case 2
		if ResetFlg then
			inc(むらし機釜送りコンベアEmgStep)
		end if
	case 3
		EmgMC17_むらし機モータ=OFF
		EmgMC18_釜送り逆転=OFF
		EmgMC18_釜送り正転=OFF
		EmgMC19_搬送モータ=OFF

		if (INV4_コンベア動作中  or むらし機釜送りコンベアstep<>0 or MC17_むらし機モータstep<>0 or  MC18_釜送りstep<>0) and manuMC17_むらし機モータstep=0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				EmgMC17_むらし機モータ=OFF
				EmgMC18_釜送り逆転=OFF
				EmgMC18_釜送り正転=OFF
				EmgMC19_搬送モータ=OFF

				'スタックの値をタイマー現在値にリストア
				tim_PH56_釜送りトリガ.U=tim_PH56_釜送りトリガ_stack.U
				timon_PH57_釜検知ステージ.U=timon_PH57_釜検知ステージ_stack.U
				tim_MC19_搬送モータ.U=tim_MC19_搬送モータ_stack.U
				tim_MC18_釜送り.U=tim_MC18_釜送り_stack.U
				tim_MC17_むらし機モータ.U=tim_MC17_むらし機モータ_stack.U
				tim_manuMC17_むらし機モータ.U=tim_manuMC17_むらし機モータ_stack
				' tmr(PH56_釜送りトリガ,tim_PH56_釜送りトリガ,#50)
				' tmr(INV4_コンベア動作中 and PH57_釜検知ステージ,timon_PH57_釜検知ステージ,150)
				' tmr(tim_MC19_搬送モータ,tim_MC19_搬送モータ_val)
				' tmr(tim_MC18_釜送り,tim_MC18_釜送り_val)
				' tmr(tim_MC17_むらし機モータ,tim_MC17_むらし機モータ_val)
				' tmr(tim_manuMC17_むらし機モータ,tim_manuMC17_むらし機モータ_val)
				
				'検出タイマーのリセット
				res(timdlyLS3_むらし機ピッチ検知)
				res(timnotdlyLS3_むらし機ピッチ検知)
				res(timdlyPH22_釜検知)
				res(tim_PH21_むらし機出口センサ)
				res(tim_PH22_釜検知)
				' tmr(LS3_むらし機ピッチ検知, timdlyLS3_むらし機ピッチ検知,2)
				' tmr(not(LS3_むらし機ピッチ検知), timnotdlyLS3_むらし機ピッチ検知,2)
				' tmr(PH22_釜検知,timdlyPH22_釜検知,2)
				' tmr(PH21_むらし機出口センサ,tim_PH21_むらし機出口センサ,#5)
				' tmr(PH22_釜検知,tim_PH22_釜検知,#5) 

				'---------------------------------
				inc(むらし機釜送りコンベアEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(むらし機釜送りコンベアEmgStep)		
		end if				
	case 4
		timstack=OFF
		むらし機釜送りコンベアEmgStep=0
		むらし機釜送りコンベアEmg=OFF
	end select
		
		
end if 'if むらし機釜送りコンベアEmgStep=0 then
