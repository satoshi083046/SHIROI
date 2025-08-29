'搬送コンベアF
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアF 
'
'  	移動速度  161.667mm/1sec
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    搬送コンベアFAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアFAutoRun=OFF
    搬送コンベアF許可=ON
    搬送コンベアFOrgErr=OFF
    搬送コンベアFErr=OFF
    搬送コンベアFEmg=OFF
    搬送コンベアFstep=0
    搬送コンベアFErrStep=0
    搬送コンベアFOrgErrStep=0
    搬送コンベアFEmgStep=0

	MC30_搬送モータstep=0
	MC29_搬送モータ正転step=0
	MC29_搬送モータ逆転step=0
	MC28_搬送モータ正転step=0
	MC28_搬送モータ逆転step=0
	昇降リフト供給step=0
	
	ManualInite=1

end if

'===================================================================================================================
'【 原点 】
搬送コンベアFOrg=1

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアFEmg=ON
	搬送コンベアFEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(PH36_釜検知,timdly_PH36_釜検知,4)
tmr(PH37_フタ検知,timdly_PH37_フタ検知,4)

tmr(SV55_リフト and not(XSW68_リフト上昇端) and not(pnlPBXSW68_リフト上昇端),tim_notXSW68_リフト上昇端, #40) '597.04ms
tmr(not(SV55_リフト) and not(XSW67_リフト下降端) and not(pnlPBXSW67_リフト下降端),tim_notXSW67_リフト下降端, #40) '808.65ms
tmr(SV56_ストッパ and not(XSW70_ストッパ上昇端) and not(pnlPBXSW70_ストッパ上昇端),tim_notXSW70_ストッパ上昇端, #40) '598.55ms
tmr(not(SV56_ストッパ) and not(XSW69_ストッパ下降端) and not(pnlPBXSW69_ストッパ下降端),tim_notXSW69_ストッパ下降端, #40) '851.59ms

'tmr(not(SV55_リフト) and XSW68_リフト上昇端,tim_XSW68_リフト上昇端, #10) '597.04ms
if LDP(SV55_リフト) and  XSW68_リフト上昇端 and not(pnlPBXSW68_リフト上昇端) then
	SET(tim_XSW68_リフト上昇端)
end if
'tmr(SV55_リフト and XSW67_リフト下降端,tim_XSW67_リフト下降端, #10) '808.65ms
if LDF(SV55_リフト) and XSW67_リフト下降端 and not(pnlPBXSW67_リフト下降端) then
	SET(tim_XSW67_リフト下降端)
end if
'tmr(not(SV56_ストッパ) and XSW70_ストッパ上昇端,tim_XSW70_ストッパ上昇端, #10) '598.55ms
if LDP(SV56_ストッパ) and XSW70_ストッパ上昇端 and not(pnlPBXSW70_ストッパ上昇端) then
	SET(tim_XSW70_ストッパ上昇端)
end if
'tmr(SV56_ストッパ and XSW69_ストッパ下降端,tim_XSW69_ストッパ下降端, #10) '851.59ms
if LDF(SV56_ストッパ) and XSW69_ストッパ下降端 and not(pnlPBXSW69_ストッパ下降端) then
	SET(tim_XSW69_ストッパ下降端)
end if

'passtimXSW68_リフト上昇端_val=#597
tms(SV55_リフト,passtimXSW68_リフト上昇端, passtimXSW68_リフト上昇端_val) 

'passtimXSW67_リフト下降端_val=#808
tms(not(SV55_リフト),passtimXSW67_リフト下降端,passtimXSW67_リフト下降端_val)  

'passtimXSW70_ストッパ上昇端_val=#598
tms(SV56_ストッパ,passtimXSW70_ストッパ上昇端, passtimXSW70_ストッパ上昇端_val) 

'passtimXSW69_ストッパ下降端_val=#851
tms(not(SV56_ストッパ),passtimXSW69_ストッパ下降端, passtimXSW69_ストッパ下降端_val) 

tmr(MC28_搬送モータ正転 and not(pauseMC28_搬送モータ正転) and not(EmgMC28_搬送モータ正転),timerr_MC28_搬送モータ正転,#80)
tmr(MC28_搬送モータ逆転 and not(pauseMC28_搬送モータ逆転) and not(EmgMC28_搬送モータ逆転),timerr_MC28_搬送モータ逆転,#150)
tmr(MC29_搬送モータ正転 and not(pauseMC29_搬送モータ正転) and not(EmgMC29_搬送モータ正転),timerr_MC29_搬送モータ正転,#80)
tmr(MC29_搬送モータ逆転 and not(pauseMC29_搬送モータ逆転) and not(EmgMC29_搬送モータ逆転),timerr_MC29_搬送モータ逆転,#150)
tmr(ejectMC30_搬送モータ and not(MC30_搬送モータ) and not(pauseMC30_搬送モータ) and not(EmgMC30_搬送モータ),timerr_MC30_搬送モータ,#150)


if ldp(timerr_MC28_搬送モータ正転.B) then
	almMC28_搬送モータ正転=ON
	
	mMC28_搬送モータ正転=OFF
	mMC28_搬送モータ逆転=OFF
	mMC29_搬送モータ正転=OFF
	mMC29_搬送モータ逆転=OFF
	ejectMC30_搬送モータ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC29_搬送モータ逆転.B) then
	almMC28_搬送モータ逆転=ON
	
	mMC28_搬送モータ正転=OFF
	mMC28_搬送モータ逆転=OFF
	mMC29_搬送モータ正転=OFF
	mMC29_搬送モータ逆転=OFF
	ejectMC30_搬送モータ=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC29_搬送モータ正転.B) then
	almMC29_搬送モータ正転=ON
	
	mMC28_搬送モータ正転=OFF
	mMC28_搬送モータ逆転=OFF
	mMC29_搬送モータ正転=OFF
	mMC29_搬送モータ逆転=OFF
	ejectMC30_搬送モータ=OFF

	コンベア一時停止=ON

else if ldp(timerr_MC29_搬送モータ逆転.B) then
	almMC29_搬送モータ逆転=ON
	
	mMC28_搬送モータ正転=OFF
	mMC28_搬送モータ逆転=OFF
	mMC29_搬送モータ正転=OFF
	mMC29_搬送モータ逆転=OFF
	ejectMC30_搬送モータ=OFF
	
	コンベア一時停止=ON
	
else if ldp(timerr_MC30_搬送モータ.B) then
	almMC30_搬送モータ=ON
	
	mMC28_搬送モータ正転=OFF
	mMC28_搬送モータ逆転=OFF
	mMC29_搬送モータ正転=OFF
	mMC29_搬送モータ逆転=OFF
	ejectMC30_搬送モータ=OFF

	コンベア一時停止=ON
end if

if (ldp(tim_XSW68_リフト上昇端.B) or ldp(tim_notXSW68_リフト上昇端.B)) and not(pnlPBXSW68_リフト上昇端) then
	pauseSV55_リフト=ON
	almXSW68_リフト上昇端=ON
	pnlPBXSW68_リフト上昇端=ON
	if tim_XSW68_リフト上昇端 then
		res(tim_XSW68_リフト上昇端)
	end if
	搬送コンベアFErrStep=1

else if (ldp(tim_XSW67_リフト下降端.B) or ldp(tim_notXSW67_リフト下降端.B)) and not(pnlPBXSW67_リフト下降端) then
	almXSW67_リフト下降端=ON
	pnlPBXSW67_リフト下降端=ON
	if tim_XSW67_リフト下降端 then
		res(tim_XSW67_リフト下降端)
	end if
	搬送コンベアFErrStep=1

else if (ldp(tim_XSW69_ストッパ下降端.B) or ldp(tim_notXSW69_ストッパ下降端.B)) and not(pnlPBXSW69_ストッパ下降端) then
	almXSW69_ストッパ下降端=ON
	pnlPBXSW69_ストッパ下降端=ON
	if tim_XSW69_ストッパ下降端 then
		res(tim_XSW69_ストッパ下降端)
	end if
	搬送コンベアFErrStep=1

else if (ldp(tim_XSW70_ストッパ上昇端.B) or ldp(tim_notXSW70_ストッパ上昇端.B)) and not(pnlPBXSW70_ストッパ上昇端) then
	pauseSV56_ストッパ=ON
	almXSW70_ストッパ上昇端=ON
	pnlPBXSW70_ストッパ上昇端=ON
	if tim_XSW70_ストッパ上昇端 then
		res(tim_XSW70_ストッパ上昇端)
	end if
	搬送コンベアFErrStep=1
	
end if



'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアFAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアFAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアFEmg	その場停止


if 搬送コンベアFEmgStep=0 then  
	
	if 搬送コンベアFErrStep=0  then
	
	if not(コンベア一時停止) then

	if not(搬送コンベアFOrgErr) then

	if (搬送コンベアFAutoMode and 自動搬送AutoMode ) or 搬送コンベアFstep<>0 then
	
		if not(搬送コンベアFAutoMode and 自動搬送AutoMode ) then
			搬送コンベアFAutoRun=OFF
		end if
		
	if ManualInite=1 then
		mSV55_リフト=ON
		ManualInite=0
	end if

	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアFstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアFAutoRun then
				inc(搬送コンベアFstep)
			else 
				搬送コンベアFstep=0 '終了待機
			end if
				
		case 2
			if PH48_釜検知 or PH49_フタ検知 then '待機位置に釜フタがある限り昇降リフト供給を繰り返す
				搬送コンベアF排出要求=ON
				if not(反転ほぐし釜供給中B) then
					inc(搬送コンベアFstep)
				else
					搬送コンベアFstep=1
				end if
				
			else
				inc(搬送コンベアFstep)
			end if			
		
		case 3
			if not(搬送コンベアF動作中) and not(MC27_モータローラ) then
				inc(搬送コンベアFstep)
			else
				搬送コンベアFstep=1
			end if

		case 4
			if ほぐし機B排出要求 or 搬送コンベアE排出要求 then '起動トリガ
				inc(搬送コンベアFstep)
			else
				搬送コンベアFstep=1
			end if
		
		
		case 5  '原点検出
			if  搬送コンベアFOrg then
				errpassコンベア一時停止=OFF
				inc(搬送コンベアFstep)
			else
				搬送コンベアFstep=1
			end if
			
		case 6
				
				搬送コンベアFstep=100			
		'--------------------------------------------------------------------------------------------------------------
		case 100				
			
			if コンベアF釜排出待機 then
			
				if not(PH48_釜検知) and not(PH49_フタ検知) and not(timdly_PH36_釜検知.B) and not(timdly_PH37_フタ検知.B) and  反転ほぐし釜供給中B and ほぐし機B排出要求 then '次の次がB釜だったらB釜排出
					'●ほぐしB釜排出
					
					if ほぐし機Bユニット完了 then
						搬送コンベアFstep=200
					end if
				else
					搬送コンベアFstep=1
				end if
				
			else			
				if not(反転ほぐし釜供給中B) and timdly_PH36_釜検知.B and timdly_PH37_フタ検知.B and ((ANDA(StageDevice25,$8000)=$8000) or (PH34_釜検知 and PH36_釜検知)) then 'リフト上の釜がB釜だったらB釜供給
				'●ほぐしB釜供給
					
					搬送コンベアFstep=300
					
				else if not(PH48_釜検知) and not(PH49_フタ検知) and (timdly_PH36_釜検知.B or timdly_PH37_フタ検知.B) then
				'●フタ、ほぐしA釜排出
					
					搬送コンベアFstep=400
				else if not(timdly_PH36_釜検知.B) and not(timdly_PH37_フタ検知.B) then
					搬送コンベアE排出要求=OFF
					搬送コンベアFstep=1
					
				else
					搬送コンベアFstep=1
				end if
			
			end if
		'--------------------------------------------------------------------------------------------------------------
		case 200 '●ほぐしB釜排出
				搬送コンベアF動作中=ON
				mSV56_ストッパ=OFF '下降
				mSV55_リフト=OFF '下降
				inc(搬送コンベアFstep)
			
		case 201
			if (XSW67_リフト下降端 and not(pnlPBXSW67_リフト下降端)) or passXSW67_リフト下降端 then
				if (XSW69_ストッパ下降端 and not(pnlPBXSW69_ストッパ下降端)) or passXSW69_ストッパ下降端 then
					inc(搬送コンベアFstep)
				end if
			end if

		case 202
				mMC28_搬送モータ逆転=ON
				mMC29_搬送モータ逆転=ON
				ejectMC30_搬送モータ=ON
				errpassコンベア一時停止=OFF
				inc(搬送コンベアFstep)
				
		case 203
				if errpassコンベア一時停止 then
					inc(搬送コンベアFstep)
				
				else if not(PH38_釜検知) then
					inc(搬送コンベアFstep)
				end if
		
		case 204
				if PH48_釜検知 or PH49_フタ検知 or errpassコンベア一時停止 then
					mSV55_リフト=ON
					mSV56_ストッパ=ON
					コンベアF釜排出待機=OFF
					搬送コンベアF動作中=OFF
					搬送コンベアE排出要求=OFF
					inc(搬送コンベアFstep)
				end if
		
		case 205
				tim_procstep_val=7 '釜フタ検出オンディレー
				res(tim_procstep)
				inc(搬送コンベアFstep)
		
		case 206
				if tim_procstep.B then
					inc(搬送コンベアFstep)
				end if				
		
		
		case 207
				mMC28_搬送モータ逆転=OFF
				mMC29_搬送モータ逆転=OFF
				ejectMC30_搬送モータ=OFF
				inc(搬送コンベアFstep)
		
		case 208
				tim_procstep_val=0
				res(tim_procstep)
				inc(搬送コンベアFstep)
				
		case 209
				if tim_procstep.B then
					inc(搬送コンベアFstep)
				end if
		
		case 210
				if MC29_搬送モータ正転step=0 then 
					搬送コンベアFstep=299
				end if
		case 299
				コンベアF釜排出待機=OFF
				反転ほぐし釜供給中B=OFF
				ほぐし機B排出要求=OFF				
				ほぐし機Bユニット完了=OFF
				搬送コンベアF動作中=OFF
				搬送コンベアE排出要求=OFF
				搬送コンベアFstep=1
				
		'--------------------------------------------------------------------------------------------------------------
		case 300 '●ほぐしB釜供給
				搬送コンベアF動作中=ON
				mSV55_リフト=OFF '下降				
				mSV56_ストッパ=OFF '下降
				inc(搬送コンベアFstep)
		
		case 301
			if (XSW67_リフト下降端 and not(pnlPBXSW67_リフト下降端)) or passXSW67_リフト下降端 then 
				inc(搬送コンベアFstep)
			end if

		case 302
			if (XSW69_ストッパ下降端 and not(pnlPBXSW69_ストッパ下降端)) or passXSW69_ストッパ下降端 then
				inc(搬送コンベアFstep)
			end if

		case 303
			tim_procstep_val=0
			res(tim_procstep)
			inc(搬送コンベアFstep)
		
		case 304
			if tim_procstep.B then
				inc(搬送コンベアFstep)
			end if			

		case 305
				mMC29_搬送モータ正転=ON
				mMC28_搬送モータ正転=ON
				
				errpassコンベア一時停止=OFF
				inc(搬送コンベアFstep)
				
		case 306
				if errpassコンベア一時停止 then
					inc(搬送コンベアFstep)
				
				else if not(PH36_釜検知) and not(PH37_フタ検知) then
					inc(搬送コンベアFstep)
				end if
		
		case 307
				if PH38_釜検知 or errpassコンベア一時停止 then
					mSV55_リフト=ON
					mSV56_ストッパ=ON
					inc(搬送コンベアFstep)
				end if
		
		case 308
				tim_procstep_val=9 '10 '釜フタ検出オンディレー
				res(tim_procstep)
				inc(搬送コンベアFstep)
		
		case 309
				if tim_procstep.B then
					mMC29_搬送モータ正転=OFF
					mMC28_搬送モータ正転=OFF
					inc(搬送コンベアFstep)
				end if
				
		case 310
				搬送コンベアFstep=399

		case 399
				StageDevice26=StageDevice25
				
				反転ほぐし釜供給中B=ON
				搬送コンベアF動作中=OFF
				搬送コンベアE排出要求=OFF
				搬送コンベアFstep=1
		'--------------------------------------------------------------------------------------------------------------
		case 400 '●フタ、ほぐしA釜排出

				フタ搬送中=not(PH36_釜検知) and  PH37_フタ検知
				
				搬送コンベアF動作中=ON
				mSV55_リフト=OFF '下降
				mSV56_ストッパ=OFF '下降
				inc(搬送コンベアFstep)
			
		case 401
				if (XSW67_リフト下降端 and not(pnlPBXSW67_リフト下降端)) or passXSW67_リフト下降端 then
					inc(搬送コンベアFstep)
				end if
		case 402
				if (XSW69_ストッパ下降端 and not(pnlPBXSW69_ストッパ下降端)) or passXSW69_ストッパ下降端 then
					inc(搬送コンベアFstep)
				end if					
		
		case 403
				tim_procstep_val=0
				res(tim_procstep)
				inc(搬送コンベアFstep)
		
		case 404
				if tim_procstep.B then
					inc(搬送コンベアFstep)
				end if			

		case 405		
				mMC29_搬送モータ逆転=ON
				ejectMC30_搬送モータ=ON
				errpassコンベア一時停止=OFF
				inc(搬送コンベアFstep)
		
		case 406
				if errpassコンベア一時停止 then
					inc(搬送コンベアFstep)
				
				else if not(PH36_釜検知) and not(PH37_フタ検知) then
					inc(搬送コンベアFstep)
				end if

		case 407
				if not(反転ほぐし釜供給中B) then
					if PH48_釜検知 or PH49_フタ検知 or errpassコンベア一時停止 then
						mSV55_リフト=ON
						mSV56_ストッパ=ON
						搬送コンベアF動作中=OFF
						inc(搬送コンベアFstep)
					end if
				else
					inc(搬送コンベアFstep)
				end if

		case 408
				if errpassコンベア一時停止 then
					inc(搬送コンベアFstep)
					
				else if PH48_釜検知 or PH49_フタ検知 then
					inc(搬送コンベアFstep)
				end if

		case 409
				tim_procstep_val=7 '釜フタ検出オンディレー
				res(tim_procstep)
				inc(搬送コンベアFstep)
		
		case 410
				if tim_procstep.B then
					inc(搬送コンベアFstep)
				end if

		case 411
				mMC29_搬送モータ逆転=OFF
				ejectMC30_搬送モータ=OFF
				搬送コンベアFstep=499

		case 499
				if フタ搬送中 and 反転ほぐし釜供給中B then
					コンベアF釜排出待機=ON
					フタ搬送中=OFF
				else
					コンベアF釜排出待機=OFF				
				end if
				
				搬送コンベアF動作中=OFF
				搬送コンベアE排出要求=OFF
				搬送コンベアFstep=1
		'--------------------------------------------------------------------------------------------------------------
		end select
		
	
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		搬送コンベアFAutoRun=OFF
		
		搬送コンベアFstep=0 '終了
		
		if ManualInite=0 then
			mSV55_リフト=OFF
			ManualInite=1
		end if

		res(timerr_MC28_搬送モータ正転)
		res(timerr_MC28_搬送モータ逆転)
		res(timerr_MC29_搬送モータ正転)
		res(timerr_MC29_搬送モータ逆転)
		res(timerr_MC30_搬送モータ)
		
		if ldp(pnlPBMC28_搬送モータ正転)  then
			if not(mMC28_搬送モータ逆転) then
				if mMC28_搬送モータ正転 then
					mMC28_搬送モータ正転=OFF
					mMC28_搬送モータ逆転=OFF
				else
					mMC28_搬送モータ正転=ON
					mMC28_搬送モータ逆転=OFF
				end if
			end if
		else if ldp(pnlPBMC28_搬送モータ逆転) then
			if not(mMC28_搬送モータ正転) then
				if mMC28_搬送モータ逆転 then
					mMC28_搬送モータ正転=OFF
					mMC28_搬送モータ逆転=OFF
				else
					mMC28_搬送モータ正転=OFF
					mMC28_搬送モータ逆転=ON
				end if
			end if
		end if
		
		if ldp(pnlPBMC29_搬送モータ正転) then
			if not(mMC29_搬送モータ逆転) then
				if mMC29_搬送モータ正転 then
					mMC29_搬送モータ正転=OFF
					mMC29_搬送モータ逆転=OFF
				else
					mMC29_搬送モータ正転=ON
					mMC29_搬送モータ逆転=OFF
				end if
			end if
		else if ldp(pnlPBMC29_搬送モータ逆転) then
			if not(mMC29_搬送モータ正転) then
				if mMC29_搬送モータ逆転 then
					mMC29_搬送モータ正転=OFF
					mMC29_搬送モータ逆転=OFF
				else
					mMC29_搬送モータ正転=OFF
					mMC29_搬送モータ逆転=ON
				end if
			end if
		end if
			
	end if '搬送コンベアFAutoMode and not(搬送コンベアFOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアFOrgErr処理 】
	else

		if ResetFlg then
			搬送コンベアFOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
		res(timerr_MC28_搬送モータ正転)
		res(timerr_MC28_搬送モータ逆転)
		res(timerr_MC29_搬送モータ正転)
		res(timerr_MC29_搬送モータ逆転)
		res(timerr_MC30_搬送モータ)
		
		コンベア一時停止中=ON
		alm渋滞警報=ON
		
		if ResetFlg then
			almMC28_搬送モータ正転=OFF		
			almMC28_搬送モータ逆転=OFF		
			almMC29_搬送モータ正転=OFF
			almMC29_搬送モータ逆転=OFF
			almMC30_搬送モータ=OFF
			
			pauseMC29_搬送モータ逆転=OFF
			pauseMC28_搬送モータ逆転=OFF

			コンベア一時停止=OFF
			コンベア一時停止中=OFF
			alm渋滞警報=OFF
			
			errpassコンベア一時停止=ON
			
		end if
		
	end if
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		搬送コンベアFErr=ON

		pauseMC28_搬送モータ正転=ON
		pauseMC28_搬送モータ逆転=ON
		pauseMC29_搬送モータ正転=ON
		pauseMC29_搬送モータ逆転=ON
		

		select case 搬送コンベアFErrStep
		case 0
		case 1
			alm渋滞警報=ON

			if ResetFlg then
				almXSW68_リフト上昇端=OFF
				almXSW67_リフト下降端=OFF
				almXSW69_ストッパ下降端=OFF
				almXSW70_ストッパ上昇端=OFF
				
				alm渋滞警報=OFF
				
				inc(搬送コンベアFErrStep)
			end if
		case 2

			res(tim_XSW68_リフト上昇端)
			res(tim_XSW67_リフト下降端)
			res(tim_XSW69_ストッパ下降端)
			res(tim_XSW70_ストッパ上昇端)
		
			res(tim_notXSW68_リフト上昇端)
			res(tim_notXSW67_リフト下降端)
			res(tim_notXSW69_ストッパ下降端)
			res(tim_notXSW70_ストッパ上昇端)

			pauseMC28_搬送モータ正転=OFF
			pauseMC28_搬送モータ逆転=OFF
			pauseMC29_搬送モータ正転=OFF
			pauseMC29_搬送モータ逆転=OFF

			pauseSV55_リフト=OFF
			pauseSV56_ストッパ=OFF

			搬送コンベアFErr=OFF
			搬送コンベアFErrStep=0

		end select

	end if 'if 搬送コンベアFErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case 搬送コンベアFEmgStep
	case 0
	
	case 1
		搬送コンベアFAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアFAutoMode and 自動搬送AutoMode ) or 搬送コンベアFstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgMC28_搬送モータ正転=ON
			EmgMC28_搬送モータ逆転=ON
			EmgMC29_搬送モータ正転=ON
			EmgMC29_搬送モータ逆転=ON
			EmgMC30_搬送モータ=ON

			if timstack=OFF then
			
				tim_MC30_搬送モータ_stack.U=tim_MC30_搬送モータ.U
				tim_MC29_搬送モータ正転_stack.U=tim_MC29_搬送モータ正転.U
				tim_MC29_搬送モータ逆転_stack.U=tim_MC29_搬送モータ逆転.U
				tim_MC28_搬送モータ正転_stack.U=tim_MC28_搬送モータ正転.U
				tim_MC28_搬送モータ逆転_stack.U=tim_MC28_搬送モータ逆転.U
				tim_昇降リフト供給_stack.U=tim_昇降リフト供給.U
				tim_procstep_stack.U=tim_procstep.U
				timdly_PH36_釜検知_stack.U=timdly_PH36_釜検知.U
				timdly_PH37_フタ検知_stack.U=timdly_PH37_フタ検知.U
				
			' tmr(tim_MC30_搬送モータ,tim_MC30_搬送モータ_val)
			' tmr(tim_MC29_搬送モータ正転,tim_MC29_搬送モータ正転_val)
			' tmr(tim_MC29_搬送モータ逆転,tim_MC29_搬送モータ逆転_val)
			' tmr(tim_MC28_搬送モータ正転,tim_MC28_搬送モータ正転_val)
			' tmr(tim_MC28_搬送モータ逆転,tim_MC28_搬送モータ逆転_val)
			' tmr(tim_昇降リフト供給,tim_昇降リフト供給_val)
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(PH36_釜検知,timdly_PH36_釜検知,4)
			' tmr(PH37_フタ検知,timdly_PH37_フタ検知,4)
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC28_搬送モータ正転=OFF
			mMC28_搬送モータ逆転=OFF
			mMC29_搬送モータ正転=OFF
			mMC29_搬送モータ逆転=OFF
			mMC30_搬送モータ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアFEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアFEmgStep)
		end if
	case 3
		if (搬送コンベアFAutoMode and 自動搬送AutoMode ) or 搬送コンベアFstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				EmgMC28_搬送モータ正転=OFF
				EmgMC28_搬送モータ逆転=OFF
				EmgMC29_搬送モータ正転=OFF
				EmgMC29_搬送モータ逆転=OFF
				EmgMC30_搬送モータ=OFF

				'スタックの値をタイマー現在値にリストア
				tim_MC30_搬送モータ.U=tim_MC30_搬送モータ_stack.U
				tim_MC29_搬送モータ正転.U=tim_MC29_搬送モータ正転_stack.U
				tim_MC29_搬送モータ逆転.U=tim_MC29_搬送モータ逆転_stack.U
				tim_MC28_搬送モータ正転.U=tim_MC28_搬送モータ正転_stack.U
				tim_MC28_搬送モータ逆転.U=tim_MC28_搬送モータ逆転_stack.U
				tim_昇降リフト供給.U=tim_昇降リフト供給_stack.U
				tim_procstep.U=tim_procstep_stack.U
				
				' tmr(tim_MC30_搬送モータ,tim_MC30_搬送モータ_val)
				' tmr(tim_MC29_搬送モータ正転,tim_MC29_搬送モータ正転_val)
				' tmr(tim_MC29_搬送モータ逆転,tim_MC29_搬送モータ逆転_val)
				' tmr(tim_MC28_搬送モータ正転,tim_MC28_搬送モータ正転_val)
				' tmr(tim_MC28_搬送モータ逆転,tim_MC28_搬送モータ逆転_val)
				' tmr(tim_昇降リフト供給,tim_昇降リフト供給_val)
				' tmr(tim_procstep,tim_procstep_val)


				'検出タイマーのリセット
				res(timdly_PH36_釜検知)
				res(timdly_PH37_フタ検知)
				
				' tmr(PH36_釜検知,timdly_PH36_釜検知,4)
				' tmr(PH37_フタ検知,timdly_PH37_フタ検知,4)

				'---------------------------------
				inc(搬送コンベアFEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアFEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアFEmgStep=0
		搬送コンベアFEmg=OFF
	end select
		
end if 'if 搬送コンベアFEmgStep=0 then
