'搬送コンベアD
'===================================================================================================================
'
'<<<<<<<	コンベア	>>>>>>>>
'
'===================================================================================================================
'
'	搬送コンベアD
'
'  	移動速度  161.667mm/1sec
'===================================================================================================================
'【 初期化処理 】
if CR2008 then '電源ON時初期化処理
    搬送コンベアDAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    搬送コンベアDAutoRun=OFF
    搬送コンベアD許可=ON
    搬送コンベアDOrgErr=OFF
    搬送コンベアDErr=OFF
    搬送コンベアDEmg=OFF
    搬送コンベアDstep=0
    搬送コンベアDErrStep=0
    搬送コンベアDOrgErrStep=0
    搬送コンベアDEmgStep=0

	SV40_ストッパstep=0
	MC19_搬送モータstep=0
	MC20_搬送モータstep=0
	MC21_搬送モータ正転リフトstep=0
	MC21_搬送モータ正転ほぐしstep=0
	MC21_搬送モータ逆転リフトstep=0
	MC20_搬送モータLFTUPstep=0
	
	ManualInite=1

end if
'===================================================================================================================
'【 原点 】
搬送コンベアDOrg=1


'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	搬送コンベアDEmg=ON
	搬送コンベアDEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(not(SV40_ストッパ) and not(XSW45_ストッパ下降端) and not(pnlPBXSW45_ストッパ下降端),tim_notXSW45_ストッパ下降端,#20) '743,04ms
tmr(SV40_ストッパ and not(XSW46_ストッパ上昇端) and not(pnlPBXSW46_ストッパ上昇端), tim_notXSW46_ストッパ上昇端, #20) '417,92ms
tmr(SV41_リフト and not(XSW48_リフト上昇端) and not(pnlPBXSW48_リフト上昇端), tim_notXSW48_リフト上昇端,#30) '1949.25ms
tmr(not(SV41_リフト) and not(XSW47_リフト下降端) and not(pnlPBXSW47_リフト下降端),tim_notXSW47_リフト下降端,#30) '1607.98ms
tmr(not(SV42_ストッパ) and not(XSW49_ストッパ下降端) and not(pnlPBXSW49_ストッパ下降端), tim_notXSW49_ストッパ下降端, #20) '1542.97ms
tmr(SV42_ストッパ and not(XSW50_ストッパ上昇端) and not(pnlPBXSW50_ストッパ上昇端), tim_notXSW50_ストッパ上昇端,#20) '1345.63ms
tmr(not(SV43_ストッパ) and not(XSW51_ストッパ下降端) and not(pnlPBXSW51_ストッパ下降端), tim_notXSW51_ストッパ下降端, #20) '1589.02ms
tmr(SV43_ストッパ and not(XSW52_ストッパ上昇端) and not(pnlPBXSW52_ストッパ上昇端), tim_notXSW52_ストッパ上昇端, #20) '1714.07ms
tmr(not(SV44_リフト) and not(XSW53_リフト下降端) and not(pnlPBXSW53_リフト下降端), tim_notXSW53_リフト下降端, #30) '758.48ms
tmr(SV44_リフト and not(XSW54_リフト上昇端) and not(pnlPBXSW54_リフト上昇端),tim_notXSW54_リフト上昇端,#30) '921.86ms

'tmr(SV40_ストッパ and XSW45_ストッパ下降端,tim_XSW45_ストッパ下降端, #10)
if LDF(SV40_ストッパ) and XSW45_ストッパ下降端 and not(pnlPBXSW45_ストッパ下降端) then
	SET(tim_XSW45_ストッパ下降端)
end if
'tmr(not(SV40_ストッパ) and XSW46_ストッパ上昇端, tim_XSW46_ストッパ上昇端, #10)
if LDP(SV40_ストッパ) and XSW46_ストッパ上昇端 and not(pnlPBXSW46_ストッパ上昇端) then
	SET(tim_XSW46_ストッパ上昇端)
end if
'tmr(SV41_リフト and XSW47_リフト下降端,tim_XSW47_リフト下降端,#10)
if LDF(SV41_リフト) and XSW47_リフト下降端 and XSW48_リフト上昇端 and not(pnlPBXSW47_リフト下降端) then
	SET(tim_XSW47_リフト下降端)
end if
'tmr(not(SV41_リフト) and XSW48_リフト上昇端, tim_XSW48_リフト上昇端,#10)
if LDP(SV41_リフト) and XSW48_リフト上昇端 and not(pnlPBXSW48_リフト上昇端) then
	SET(tim_XSW48_リフト上昇端)
end if
'tmr(SV42_ストッパ and XSW49_ストッパ下降端, tim_XSW49_ストッパ下降端, #10)
if LDF(SV42_ストッパ) and XSW49_ストッパ下降端 and not(pnlPBXSW49_ストッパ下降端) then
	SET(tim_XSW49_ストッパ下降端)
end if
'tmr(not(SV42_ストッパ) and XSW50_ストッパ上昇端, tim_XSW50_ストッパ上昇端,#10)
if LDP(SV42_ストッパ) and XSW50_ストッパ上昇端 and not(pnlPBXSW50_ストッパ上昇端) then
	SET(tim_XSW50_ストッパ上昇端)
end if
'tmr(SV43_ストッパ and XSW51_ストッパ下降端, tim_XSW51_ストッパ下降端, #10)
if LDF(SV43_ストッパ) and XSW51_ストッパ下降端 and not(pnlPBXSW51_ストッパ下降端) then
	SET(tim_XSW51_ストッパ下降端)
end if
'tmr(not(SV43_ストッパ) and XSW52_ストッパ上昇端, tim_XSW52_ストッパ上昇端, #10)
if LDP(SV43_ストッパ) and XSW52_ストッパ上昇端 and not(pnlPBXSW52_ストッパ上昇端) then
	SET(tim_XSW52_ストッパ上昇端)
end if
'tmr(SV44_リフト and XSW53_リフト下降端, tim_XSW53_リフト下降端, #10)
if LDF(SV44_リフト) and XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端) then
	SET(tim_XSW53_リフト下降端)
end if
'tmr(not(SV44_リフト) and XSW54_リフト上昇端,tim_XSW54_リフト上昇端,#10)
if LDP(SV44_リフト) and XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端) then
	SET(tim_XSW54_リフト上昇端)
end if

'passtimXSW45_ストッパ下降端_val=#743
tms(not(SV40_ストッパ),passtimXSW45_ストッパ下降端,passtimXSW45_ストッパ下降端_val) 
'passtimXSW46_ストッパ上昇端_val=#417
tms(SV40_ストッパ, passtimXSW46_ストッパ上昇端, passtimXSW46_ストッパ上昇端_val) 
'passtimXSW48_リフト上昇端_val=#1949
tms(SV41_リフト, passtimXSW48_リフト上昇端,passtimXSW48_リフト上昇端_val) 
'passtimXSW47_リフト下降端_val=#1607
tms(not(SV41_リフト),passtimXSW47_リフト下降端,passtimXSW47_リフト下降端_val) 
'passtimXSW49_ストッパ下降端_val=#1542
tms(not(SV42_ストッパ), passtimXSW49_ストッパ下降端, passtimXSW49_ストッパ下降端_val) 
'passtimXSW50_ストッパ上昇端_val=#1345
tms(SV42_ストッパ, passtimXSW50_ストッパ上昇端,passtimXSW50_ストッパ上昇端_val) 
'passtimXSW51_ストッパ下降端_val=#1589
tms(not(SV43_ストッパ), passtimXSW51_ストッパ下降端, passtimXSW51_ストッパ下降端_val) 
'passtimXSW52_ストッパ上昇端_val=#1714
tms(SV43_ストッパ, passtimXSW52_ストッパ上昇端, passtimXSW52_ストッパ上昇端_val) 

tmr(mMC19_搬送モータ and not(pauseMC19_搬送モータ) and not(EmgMC19_搬送モータ),timerr_MC19_搬送モータ,#120)
tmr(mMC20_搬送モータ and not(pauseMC20_搬送モータ) and not(EmgMC20_搬送モータ),timerr_MC20_搬送モータ,#170)
tmr(mMC21_搬送モータ正転 and not(pauseMC21_搬送モータ正転) and not(EmgMC21_搬送モータ正転),timerr_MC21_搬送モータ正転,#170)
tmr(mMC21_搬送モータ逆転 and not(pauseMC21_搬送モータ逆転) and not(EmgMC21_搬送モータ逆転),timerr_MC21_搬送モータ逆転,#120)
tmr(mMC22_搬送モータ正転 and not(pauseMC22_搬送モータ正転) and not(EmgMC22_搬送モータ正転),timerr_MC22_搬送モータ正転,#170)
tmr(mMC22_搬送モータ逆転 and not(pauseMC22_搬送モータ逆転) and not(EmgMC22_搬送モータ逆転),timerr_MC22_搬送モータ逆転,#120)

tmr(MC20_搬送モータ and (PH23_釜検知 or PH24_フタ検知 or PH25_釜検知 or PH26_フタ検知 or (not(SV57_バキュームリフト) and (PH27_釜検知 or PH28_フタ検知))), timerr_MC20_搬送モータdec,#50) 

if ldp(timerr_MC19_搬送モータ.B) then
	almMC19_搬送モータ=ON
	
	mMC19_搬送モータ=OFF
	mMC20_搬送モータ=OFF
	mMC21_搬送モータ正転=OFF
	mMC21_搬送モータ逆転=OFF
	mMC22_搬送モータ正転=OFF
	mMC22_搬送モータ逆転=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC20_搬送モータ.B or timerr_MC20_搬送モータdec.B) then
	almMC20_搬送モータ=ON
	
	mMC19_搬送モータ=OFF
	mMC20_搬送モータ=OFF
	mMC21_搬送モータ正転=OFF
	mMC21_搬送モータ逆転=OFF
	mMC22_搬送モータ正転=OFF
	mMC22_搬送モータ逆転=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC21_搬送モータ正転.B) then
	almMC21_搬送モータ正転=ON
	
	mMC19_搬送モータ=OFF
	mMC20_搬送モータ=OFF
	mMC21_搬送モータ正転=OFF
	mMC21_搬送モータ逆転=OFF
	mMC22_搬送モータ正転=OFF
	mMC22_搬送モータ逆転=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC21_搬送モータ逆転.B) then
	almMC21_搬送モータ逆転=ON
	
	mMC19_搬送モータ=OFF
	mMC20_搬送モータ=OFF
	mMC21_搬送モータ正転=OFF
	mMC21_搬送モータ逆転=OFF
	mMC22_搬送モータ正転=OFF
	mMC22_搬送モータ逆転=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC22_搬送モータ正転.B) then
	almMC22_搬送モータ正転=ON
	
	mMC19_搬送モータ=OFF
	mMC20_搬送モータ=OFF
	mMC21_搬送モータ正転=OFF
	mMC21_搬送モータ逆転=OFF
	mMC22_搬送モータ正転=OFF
	mMC22_搬送モータ逆転=OFF
	
	コンベア一時停止=ON

else if ldp(timerr_MC22_搬送モータ逆転.B) then
	almMC22_搬送モータ逆転=ON
	
	mMC19_搬送モータ=OFF
	mMC20_搬送モータ=OFF
	mMC21_搬送モータ正転=OFF
	mMC21_搬送モータ逆転=OFF
	mMC22_搬送モータ正転=OFF
	mMC22_搬送モータ逆転=OFF
	
	コンベア一時停止=ON
	
end if

if (ldp(tim_XSW45_ストッパ下降端.B) or ldp(tim_notXSW45_ストッパ下降端.B)) and not(pnlPBXSW45_ストッパ下降端) then
	almXSW45_ストッパ下降端=ON
	pnlPBXSW45_ストッパ下降端=ON
	if tim_XSW45_ストッパ下降端 then
		res(tim_XSW45_ストッパ下降端)
	end if
	搬送コンベアDErrStep=1

else if (ldp(tim_XSW46_ストッパ上昇端.B) or ldp(tim_notXSW46_ストッパ上昇端.B)) and not(pnlPBXSW46_ストッパ上昇端) then
	pauseSV40_ストッパ=ON
	almXSW46_ストッパ上昇端=ON
	pnlPBXSW46_ストッパ上昇端=ON
	if tim_XSW46_ストッパ上昇端 then
		res(tim_XSW46_ストッパ上昇端)
	end if
	搬送コンベアDErrStep=1

else if 搬送コンベアD動作中 and not(搬送コンベアE動作中) and  (ldp(tim_XSW49_ストッパ下降端.B) or ldp(tim_notXSW49_ストッパ下降端.B)) and not(pnlPBXSW49_ストッパ下降端) then
	almXSW49_ストッパ下降端=ON
	pnlPBXSW49_ストッパ下降端=ON
	if tim_XSW49_ストッパ下降端 then
		res(tim_XSW49_ストッパ下降端)
	end if
	搬送コンベアDErrStep=1

else if 搬送コンベアD動作中 and not(搬送コンベアE動作中) and (ldp(tim_XSW50_ストッパ上昇端.B) or ldp(tim_notXSW50_ストッパ上昇端.B)) and not(pnlPBXSW50_ストッパ上昇端) then
	pauseSV42_ストッパ=ON
	almXSW50_ストッパ上昇端=ON
	pnlPBXSW50_ストッパ上昇端=ON
	if tim_XSW50_ストッパ上昇端 then
		res(tim_XSW50_ストッパ上昇端)
	end if
	搬送コンベアDErrStep=1

else if 搬送コンベアD動作中 and not(搬送コンベアE動作中) and (ldp(tim_XSW51_ストッパ下降端.B) or ldp(tim_notXSW51_ストッパ下降端.B)) and not(pnlPBXSW51_ストッパ下降端) then
	almXSW51_ストッパ下降端=ON
	pnlPBXSW51_ストッパ下降端=ON
	if tim_XSW51_ストッパ下降端 then
		res(tim_XSW51_ストッパ下降端)
	end if
	搬送コンベアDErrStep=1

else if 搬送コンベアD動作中 and not(搬送コンベアE動作中) and (ldp(tim_XSW52_ストッパ上昇端.B) or ldp(tim_notXSW52_ストッパ上昇端.B)) and not(pnlPBXSW52_ストッパ上昇端) then
	pauseSV43_ストッパ=ON
	almXSW52_ストッパ上昇端=ON
	pnlPBXSW52_ストッパ上昇端=ON
	if tim_XSW52_ストッパ上昇端 then
		res(tim_XSW52_ストッパ上昇端)
	end if
	搬送コンベアDErrStep=1

else if 搬送コンベアD動作中 and not(搬送コンベアE動作中) and (ldp(tim_XSW53_リフト下降端.B) or ldp(tim_notXSW53_リフト下降端.B)) and not(pnlPBXSW53_リフト下降端) then
	almXSW53_リフト下降端=ON
	pnlPBXSW53_リフト下降端=ON
	if tim_XSW53_リフト下降端 then
		res(tim_XSW53_リフト下降端)
	end if
	搬送コンベアDErrStep=1

else if 搬送コンベアD動作中 and not(搬送コンベアE動作中) and (ldp(tim_XSW54_リフト上昇端.B) or ldp(tim_notXSW54_リフト上昇端.B)) and not(pnlPBXSW54_リフト上昇端) then
	pauseSV44_リフト=ON
	almXSW54_リフト上昇端=ON
	pnlPBXSW54_リフト上昇端=ON
	if tim_XSW54_リフト上昇端 then
		res(tim_XSW54_リフト上昇端)
	end if
	搬送コンベアDErrStep=1

else if (ldp(tim_XSW48_リフト上昇端.B) or ldp(tim_notXSW48_リフト上昇端.B)) and not(pnlPBXSW48_リフト上昇端) then
	pauseSV41_リフト=ON
	almXSW48_リフト上昇端=ON
	pnlPBXSW48_リフト上昇端=ON
	if tim_XSW48_リフト上昇端 then
		res(tim_XSW48_リフト上昇端)
	end if
	搬送コンベアDErrStep=1

else if (ldp(tim_XSW47_リフト下降端.B) or ldp(tim_notXSW47_リフト下降端.B)) and not(pnlPBXSW47_リフト下降端) then
	almXSW47_リフト下降端=ON
	pnlPBXSW47_リフト下降端=ON
	if tim_XSW47_リフト下降端 then
		res(tim_XSW47_リフト下降端)
	end if
	搬送コンベアDErrStep=1

end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 搬送コンベアDAutoMode	自動モード セレクトスイッチ
'System :: 搬送コンベアDAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: 搬送コンベアDEmg	その場停止

if 搬送コンベアDEmgStep=0 then  
	
	if 搬送コンベアDErrStep=0  then

	if not(コンベア一時停止) then
	
	if not(搬送コンベアDOrgErr) then

	if (搬送コンベアDAutoMode and 自動搬送AutoMode ) or 搬送コンベアDstep<>0 then
				
		if not(搬送コンベアDAutoMode and 自動搬送AutoMode ) then
			搬送コンベアDAutoRun=OFF
		end if
		
		if not(搬送コンベアDAutoRun) then
			mSV41_リフト=OFF		
		end if
		
		if ManualInite then
			if PH24_フタ検知 and PH23_釜検知 then
				mSV40_ストッパ=ON		
			end if
			ManualInite=0
		end if
	'===================================================================================================================
	'【 リフタータスク 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 搬送コンベアDstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 搬送コンベアDAutoRun then
				inc(搬送コンベアDstep)
			else 
				搬送コンベアDstep=0 '終了待機
			end if
		
		case 2
			if PH29_釜検知 or PH30_フタ検知 then 'リフターに釜フタがあった場合強制的に排出命令
				搬送コンベアD排出要求=ON
				搬送コンベアDstep=1
			else
				inc(搬送コンベアDstep)
			end if
		
		case 3
		' [ 次の搬送コンベア停止確認 ]
			if 搬送コンベアD排出要求=OFF and  搬送コンベアE動作中=OFF and not(ejectMC19_搬送モータ) then
				inc(搬送コンベアDstep)
			else
				搬送コンベアDstep=1
			end if
		
		case 4
			if 	フタ取り排出要求 and ごはん検知排出要求 and 水抜きバキューム排出要求 then
				inc(搬送コンベアDstep)
			else
				搬送コンベアDstep=1
			end if

		
		case 5  '原点検出
			if 搬送コンベアDOrg then
				errpassコンベア一時停止=OFF
				inc(搬送コンベアDstep)
			else
				搬送コンベアDstep=1
			end if

		case 6
			搬送コンベアDstep=100			
		'--------------------------------------------------------------------------------------------------------------
		case 100
		'------ ほぐしAに釜が入っているとき、バキューム位置に釜が到達した場合には、ほぐしBに搬送する。
		'------ ほぐしBに搬送したことを記録して、ほぐしAを排出する。
			if コンベアD釜排出待機 then
				if ほぐし機A排出要求 then
					if ほぐし機Aユニット完了 then
						'●ほぐしA釜排出 (ほぐし機ー>リフトまでほぐし釜排出)
						搬送コンベアDstep=200
					end if
				else
					搬送コンベアDstep=1
				end if
			else
		
				if PH27_釜検知 and PH28_フタ検知 then '釜搬送 (バキューム位置が釜検出)

					if 反転ほぐし釜供給中A then
						if not(ejectMC19_搬送モータ) then 'むらし機排出停止中
						'●ほぐしB釜供給 (リフトまで釜搬送)
							ほぐしA釜要求=OFF
							搬送コンベアDstep=300
						end if
					else
						if not(ejectMC19_搬送モータ) then 'むらし機排出停止中
						'●ほぐしA釜供給 (ほぐし機まで釜搬送)
							ほぐしA釜要求=ON
							搬送コンベアDstep=300
						end if
					end if
				else if PH28_フタ検知 then 'フタ搬送
						if not(ejectMC19_搬送モータ) then 'むらし機排出停止中
							'●リフトまで釜フタ搬送
							ほぐしA釜要求=OFF
							搬送コンベアDstep=300
						end if
				
				else
						if not(ejectMC19_搬送モータ) then 'むらし機排出停止中
							搬送コンベアDstep=400			
						end if
				end if

			end if
				
		'----------------------------------------------------------------------------------------------------------------
		case 200'●ほぐし機ー>リフトまでほぐしA釜排出
				if (反転機反転完了信号_A or 釜搬入可能信号_A or 反転ほぐし機A禁止)  then
					inc(搬送コンベアDstep)
				end if
				
		case 201
				if PH31_釜検知 then '反転ほぐしA
					MC21_搬送モータ逆転リフトstep=1
					StageDevice22=$0000
				end if

				inc(搬送コンベアDstep)
		
		case 202
				if MC21_搬送モータ逆転リフトstep=0 then
					inc(搬送コンベアDstep)
				end if			

		case 203
				
				コンベアD釜排出待機=OFF
				ほぐし機A排出要求=OFF
				ほぐし機Aユニット完了=OFF
				反転ほぐし釜供給中A=OFF
				搬送コンベアD動作中=OFF
				搬送コンベアD排出要求=ON
				搬送コンベアDstep=1
				
		'----------------------------------------------------------------------------------------------------------------
		case 300'●リフト、ほぐしAまで釜フタ搬送
				
			if ほぐしA釜要求 and not(ほぐしA供給禁止) then			
				MC21_搬送モータ正転ほぐしstep=1
			else
				釜搬送中=PH27_釜検知
				MC21_搬送モータ正転リフトstep=1
			end if
			inc(搬送コンベアDstep)
		
		case 301
			if MC21_搬送モータ正転ほぐしstep=0 and MC21_搬送モータ正転リフトstep=0 then 
				inc(搬送コンベアDstep)
			end if
		
		case 302
			
			if ほぐしA釜要求  and not(ほぐしA供給禁止) then
				反転ほぐし釜供給中A=ON
				ほぐしA釜要求=OFF
				搬送コンベアDstep=1
				
			else
				if 釜搬送中 and 反転ほぐし釜供給中A  and not(ほぐしA供給禁止) then
					釜搬送中=OFF
					コンベアD釜排出待機=ON
				else
					コンベアD釜排出待機=OFF
				end if
				inc(搬送コンベアDstep)
			end if

		case 303
				搬送コンベアD排出要求=ON
				
				搬送コンベアD動作中=OFF
				搬送コンベアDstep=1
		
		'----------------------------------------------------------------------------------------------------------------
		case 400 '判定位置（バキューム位置）にワークがない場合
				MC20_搬送モータstep=1
				inc(搬送コンベアDstep)
		
		case 401
				if MC20_搬送モータstep=0 and MC20_搬送モータLFTUPstep=0 then
					inc(搬送コンベアDstep)
				end if
		
		case 402
				搬送コンベアDstep=1
		
		end select

	'-----------------------------------------------------------------	
	'mMC19_搬送モータ		
	'	むらし出口:	PH21_むらし機出口センサ	
	'	エスケープ:	PH22_釜検知
	
	'mMC20_搬送モータ
	'	フタ取り装置:PH23_釜検知 PH24_フタ検知 
	'	ごはん検知:		PH25_釜検知 PH26_フタ検知 
	'	水釜バキューム:	PH27_釜検知 PH28_フタ検知   
	
	'mMC21_搬送モータ正転
	'mMC21_搬送モータ逆転
	'mMC23_モータローラ
	'	受け渡しローラ:	PH29_釜検知 PH30_フタ検知 
	
	'mMC22_搬送モータ正転
	'mMC22_搬送モータ逆転
	'	反転ほぐしA:	PH31_釜検知
	
	'-----------------------------------------------------------------	
	'mSV40_ストッパ
	'mSV41_リフト
	'mSV42_ストッパ
	'mSV43_ストッパ
	'mSV44_リフト
	'-----------------------------------------------------------------
	' 起動時の釜判定
	'むらし出口
	'PH21_釜起動検知=PH21_むらし機出口センサ 
	
	'エスケープ
	'PH22_釜起動検知=PH22_釜検知 	
	
	'フタ取り装置
	'PH23_釜起動検知=PH23_釜検知 				
	'PH24_フタ起動検知=PH24_フタ検知
	
	'ごはん検知
	'PH25_釜起動検知=PH25_釜検知 				
	'PH26_フタ起動検知=PH26_フタ検知
	
	'水釜バキューム
	'PH27_釜起動検知=PH27_釜検知 				 
	'PH28_フタ起動検知=PH28_フタ検知
	
	'受け渡しローラ
	'PH29_釜起動検知=PH29_釜検知 				
	'PH30_フタ起動検知=PH30_フタ検知
	
	'反転ほぐしA
	'PH31_釜起動検知=PH31_釜検知 				

	'-----------------------------------------------------------------
	' 搬送モータ、ストッパON/OFFタイミングタスク
	'-----------------------------------------------------------------
	tmr(tim_SV40_ストッパ,tim_SV40_ストッパ_val) 'フタ取り装置ストッパ
	select case SV40_ストッパstep
	case 0
	
	case 1
		if (not(PH22_釜搬送禁止) and PH22_釜検知) or PH23_釜検知 or PH24_フタ検知 then
			mSV40_ストッパ=OFF
			inc(SV40_ストッパstep)
		else
			SV40_ストッパstep=0 '終了
		end if
		
	case 2
		if (XSW45_ストッパ下降端 and not(pnlPBXSW45_ストッパ下降端)) or passXSW45_ストッパ下降端 then
			inc(SV40_ストッパstep)
		end if

	case 3
		if errpassコンベア一時停止 then
			inc(SV40_ストッパstep)
		
		else if not(PH23_釜検知) and not(PH24_フタ検知) then
			tim_SV40_ストッパ_val=20
			res(tim_SV40_ストッパ)
			inc(SV40_ストッパstep)
		end if

	case 4
		if errpassコンベア一時停止 then
			inc(SV40_ストッパstep)
			
		else if not(PH22_釜搬送禁止) and PH22_釜起動検知 then
			if tim_SV40_ストッパ.B or PH23_釜検知 or PH24_フタ検知 then
				inc(SV40_ストッパstep)
			end if
		else
			inc(SV40_ストッパstep)	
		end if
	
	case 5
		if errpassコンベア一時停止 then
			inc(SV40_ストッパstep)
			
		else if PH23_釜起動検知 or PH24_フタ起動検知 then
			if PH25_釜検知 or PH26_フタ検知 then
				inc(SV40_ストッパstep)
			end if
		else
			inc(SV40_ストッパstep)
		end if		
	
	case 6
		if not(PH22_釜搬送禁止) and PH22_釜起動検知 then
			mSV40_ストッパ=ON
		else
			mSV40_ストッパ=OFF
		end if		
		inc(SV40_ストッパstep)
	
	case 7
		if mSV40_ストッパ then
			if (XSW46_ストッパ上昇端 and not(pnlPBXSW46_ストッパ上昇端)) or passXSW46_ストッパ上昇端 then
				inc(SV40_ストッパstep)
			end if
		else
			inc(SV40_ストッパstep)
		end if	
	
	case 8
		SV40_ストッパstep=0
	
	end select
	'-----------------------------------------------------------------
	'MC19_搬送モータ
	tmr(tim_MC19_搬送モータ,tim_MC19_搬送モータ_val)
	
	select case MC19_搬送モータstep
	case 0
	case 1
		if PH22_釜搬送禁止 then
			MC19_搬送モータstep=0
		else						
			'エスケープ
			PH22_釜起動検知=PH22_釜検知 	
			inc(MC19_搬送モータstep)
		end if
		
	case 2
		if PH22_釜検知 and not(フタ取りフタ取り中) then
			inc(MC19_搬送モータstep)
		else
			MC19_搬送モータstep=0
		end if
	
	case 3
		if not(ejectMC19_搬送モータ) then
			inc(MC19_搬送モータstep)
		end if		
	
	case 4	
		if not(PH22_釜搬送禁止) and mSV41_リフト then
			mSV41_リフト=OFF
			inc(MC19_搬送モータstep)
		else
			inc(MC19_搬送モータstep)
		end if
		
	case 5
		if not(mSV41_リフト) then
			if (XSW47_リフト下降端 and not(pnlPBXSW47_リフト下降端)) or passXSW47_リフト下降端 then
				inc(MC19_搬送モータstep)
			end if
		else
			inc(MC19_搬送モータstep)		
		end if
	
	case 6
		mMC19_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC19_搬送モータstep)

	case 7
		if errpassコンベア一時停止 then
			inc(MC19_搬送モータstep)		
		
		else if not(PH22_釜検知) and not(PH23_釜検知) and not(PH24_フタ検知) then
			inc(MC19_搬送モータstep)		
		end if
	
	case 8
		if errpassコンベア一時停止 then
				inc(MC19_搬送モータstep)
		
		else if PH22_釜起動検知 then
			if PH23_釜検知 or PH24_フタ検知 then
				inc(MC19_搬送モータstep)
			end if
		end if
	
	case 9
		tim_MC19_搬送モータ_val=10
		res(tim_MC19_搬送モータ)
		inc(MC19_搬送モータstep)

	case 10
		if tim_MC19_搬送モータ.B then
			inc(MC19_搬送モータstep)
		end if
	
	case 11
		mMC19_搬送モータ=OFF
		inc(MC19_搬送モータstep)
	
	case 12
		MC19_搬送モータstep=0
	
	end select
	
	'-----------------------------------------------------------------
	'MC20_搬送モータ正転
	tmr(tim_MC20_搬送モータ,tim_MC20_搬送モータ_val)
	
	select case MC20_搬送モータstep
	case 0
	case 1
		'エスケープ
		PH22_釜搬送禁止=エスケープ中
		PH22_釜起動検知=PH22_釜検知 	
		
		'フタ取り装置
		PH23_釜起動検知=PH23_釜検知 				
		PH24_フタ起動検知=PH24_フタ検知
		
		'ごはん検知
		PH25_釜起動検知=PH25_釜検知 				
		PH26_フタ起動検知=PH26_フタ検知
		
		'水釜バキューム
		PH27_釜起動検知=PH27_釜検知 				 
		PH28_フタ起動検知=PH28_フタ検知


		inc(MC20_搬送モータstep)
	
	case 2
		if (not(PH22_釜搬送禁止) and PH22_釜検知) or PH23_釜検知 or PH24_フタ検知 or PH25_釜検知 or PH26_フタ検知 or PH27_釜検知 or PH28_フタ検知 then
			inc(MC20_搬送モータstep)
		else
			MC20_搬送モータstep=0
		end if
	
	case 3
		if not(PH22_釜搬送禁止) and PH22_釜検知 then 'エスケープ
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_釜検知 then 'フタ取り
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_釜検知 then 'ごはん検知

			if ごはん検知 then
				StageDevice190=ORA(StageDevice190,$1000)
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
			StageDevice190=ORA(StageDevice190,$8000)
		
		else
			StageDevice19=0
			StageDevice190=0
		end if				
	
		if PH27_釜検知 then 'バキューム
			StageDevice200=ORA(StageDevice200,$8000)
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice200=0
			StageDevice20=0
		end if
	
	
	
		SV40_ストッパstep=1
		inc(MC20_搬送モータstep)
	
	case 4
		if SV40_ストッパstep=0 or (not(mSV40_ストッパ) and ((XSW45_ストッパ下降端 and not(pnlPBXSW45_ストッパ下降端)) or passXSW45_ストッパ下降端)) then
			inc(MC20_搬送モータstep)
		end if	
	
	case 5
		搬送コンベアD動作中=ON
		MC19_搬送モータstep=1
		inc(MC20_搬送モータstep)
		
	case 6
		if  MC19_搬送モータstep=0 or mMC19_搬送モータ then
			inc(MC20_搬送モータstep)
		end if	
		
	case 7
		mMC20_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC20_搬送モータstep)
	
	case 8
		if PH22_釜搬送禁止 or フタ取りフタ取り中 or not(PH22_釜検知) then
			inc(MC20_搬送モータstep)
		end if
	
	case 9
		if errpassコンベア一時停止 then
			inc(MC20_搬送モータstep)
		else if not(PH23_釜検知) and not(PH24_フタ検知) then
				if not(PH25_釜検知) and not(PH26_フタ検知) then
					if not(PH27_釜検知) and not(PH28_フタ検知) then
						inc(MC20_搬送モータstep)
					end if
				end if
		end if
	
	case 10
		if errpassコンベア一時停止 then
				inc(MC20_搬送モータstep)		
		
		else if not(PH22_釜搬送禁止) and PH22_釜起動検知 and not(フタ取りフタ取り中) then
			if PH23_釜検知 or PH24_フタ検知 then
				tim_MC20_搬送モータ_val=MC20ブレーキタイミング 'L=8 R=9
				res(tim_MC20_搬送モータ)
				inc(MC20_搬送モータstep)
			end if

		else if PH23_釜起動検知 or PH24_フタ起動検知 then
			if PH25_釜検知 or PH26_フタ検知 then
				tim_MC20_搬送モータ_val=8
				res(tim_MC20_搬送モータ)
				inc(MC20_搬送モータstep)
			end if
		
		else if PH25_釜起動検知 or PH26_フタ起動検知 then
			if PH27_釜検知 or PH28_フタ検知 then
				tim_MC20_搬送モータ_val=8
				res(tim_MC20_搬送モータ)
				inc(MC20_搬送モータstep)
			end if
		else if PH27_釜起動検知 or PH28_フタ起動検知 then
			if PH29_釜検知 or PH30_フタ検知 then
				tim_MC20_搬送モータ_val=8
				res(tim_MC20_搬送モータ)
				inc(MC20_搬送モータstep)
			end if
		else
			tim_MC20_搬送モータ_val=8
			res(tim_MC20_搬送モータ)
			inc(MC20_搬送モータstep)
		end if
	
	case 11
		if tim_MC20_搬送モータ.B then
			inc(MC20_搬送モータstep)
		end if
	
	case 12
		mMC20_搬送モータ=OFF
		if MC21_搬送モータ正転ほぐしstep=0 and MC21_搬送モータ逆転リフトstep=0 and MC21_搬送モータ正転リフトstep=0 then
			StageDevice20=StageDevice19
			StageDevice19=StageDevice18
			StageDevice18=StageDevice17
		end if		
		StageDevice200=StageDevice190
		inc(MC20_搬送モータstep)
		
	case 13
		if MC19_搬送モータstep=0 then
			inc(MC20_搬送モータstep)
		end if
	
	case 14
		tim_MC20_搬送モータ_val=9
		res(tim_MC20_搬送モータ)
		inc(MC20_搬送モータstep)

	case 15
		if tim_MC20_搬送モータ.B then
			inc(MC20_搬送モータstep)
		end if
	
	case 16
		if SV40_ストッパstep=0 then
			inc(MC20_搬送モータstep)
		end if

	case 17

		ごはん検知=OFF

		フタ取り完了=OFF
		ごはん検知完了=OFF
		バキューム完了=OFF
		
		フタ取り排出要求=OFF
		ごはん検知排出要求=OFF
		水抜きバキューム排出要求=OFF

		搬送コンベアD動作中=OFF

		MC20_搬送モータstep=0

	end select
	
	'-----------------------------------------------------------------
	'MC21_搬送モータ正転リフト
	tmr(tim_MC21_搬送モータ正転リフト,tim_MC21_搬送モータ正転リフト_val)
	
	select case MC21_搬送モータ正転リフトstep
	case 0
	case 1
		'水釜バキューム
		PH22_釜搬送禁止=エスケープ中
		PH27_釜起動検知=PH27_釜検知 				 
		PH28_フタ起動検知=PH28_フタ検知
		inc(MC21_搬送モータ正転リフトstep)
	
	case 2
		if PH27_釜検知 or PH28_フタ検知 then
			inc(MC21_搬送モータ正転リフトstep)
		else
			MC20_搬送モータstep=1
			MC21_搬送モータ正転リフトstep=0
		end if
	
	'------------------------
	case 3
		if not(PH22_釜搬送禁止) and PH22_釜検知 then 'エスケープ
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_釜検知 then 'フタ取り
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_釜検知 then 'ごはん検知

			if ごはん検知 then
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
		
		else
			StageDevice19=0
		end if				
	
		if PH27_釜検知 then 'バキューム
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice20=0
		end if

		mSV42_ストッパ=OFF
		mSV43_ストッパ=ON
		mSV44_リフト=OFF

		MC20_搬送モータstep=1
		mMC21_搬送モータ正転=ON
		errpassコンベア一時停止=OFF

		inc(MC21_搬送モータ正転リフトstep)

	case 4
		if (XSW49_ストッパ下降端 and not(pnlPBXSW49_ストッパ下降端)) or passXSW49_ストッパ下降端 then
			if (XSW52_ストッパ上昇端 and not(pnlPBXSW52_ストッパ上昇端)) or passXSW52_ストッパ上昇端 then
				if (XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端 then
					inc(MC21_搬送モータ正転リフトstep)
				end if
			end if
		end if

		inc(MC21_搬送モータ正転リフトstep)
	'------------------------
	case 5
		inc(MC21_搬送モータ正転リフトstep)

	case 6
		if errpassコンベア一時停止 then
			inc(MC21_搬送モータ正転リフトstep)
		
		else if not(PH27_釜検知) and not(PH28_フタ検知) then
			inc(MC21_搬送モータ正転リフトstep)
		end if		

	case 7
		if errpassコンベア一時停止 then
				inc(MC21_搬送モータ正転リフトstep)
		
		else if	PH27_釜起動検知 or PH28_フタ起動検知 then
			if PH29_釜検知 or PH30_フタ検知 then
				inc(MC21_搬送モータ正転リフトstep)
			end if
		end if
	
	case 8
		tim_MC21_搬送モータ正転リフト_val=24 'ブレーキタイミング
		res(tim_MC21_搬送モータ正転リフト)
		inc(MC21_搬送モータ正転リフトstep)
	
	case 9
		if tim_MC21_搬送モータ正転リフト.B then
			inc(MC21_搬送モータ正転リフトstep)
		end if		
	
	
	case 10
		mMC21_搬送モータ正転=OFF
		inc(MC21_搬送モータ正転リフトstep)	
	
	case 11
		tim_MC21_搬送モータ正転リフト_val=0
		res(tim_MC21_搬送モータ正転リフト)
		inc(MC21_搬送モータ正転リフトstep)
	
	case 12
		if tim_MC21_搬送モータ正転リフト.B then
			inc(MC21_搬送モータ正転リフトstep)
		end if		
	'------------------------
	case 13
		mSV43_ストッパ=ON
		mSV44_リフト=OFF
		inc(MC21_搬送モータ正転リフトstep)

	case 14
		if (XSW52_ストッパ上昇端 and not(pnlPBXSW52_ストッパ上昇端)) or passXSW52_ストッパ上昇端 then
			if (XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端 then
				inc(MC21_搬送モータ正転リフトstep)
			end if
		end if

	case 15
		tim_MC21_搬送モータ正転リフト_val=0
		res(tim_MC21_搬送モータ正転リフト)
		inc(MC21_搬送モータ正転リフトstep)
	
	case 16
		if tim_MC21_搬送モータ正転リフト.B then
			inc(MC21_搬送モータ正転リフトstep)
		end if		
	case 17
		mSV43_ストッパ=ON
		mSV44_リフト=ON
		inc(MC21_搬送モータ正転リフトstep)

	case 18
		if (XSW52_ストッパ上昇端 and not(pnlPBXSW52_ストッパ上昇端)) or passXSW52_ストッパ上昇端 then
			if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
				inc(MC21_搬送モータ正転リフトstep)
			end if
		end if

	case 19
		tim_MC21_搬送モータ正転リフト_val=0
		res(tim_MC21_搬送モータ正転リフト)
		inc(MC21_搬送モータ正転リフトstep)
	
	case 20
		if tim_MC21_搬送モータ正転リフト.B then
			inc(MC21_搬送モータ正転リフトstep)
		end if		
	
	case 21
		mSV42_ストッパ=OFF
		mSV43_ストッパ=OFF
		mSV44_リフト=ON
		inc(MC21_搬送モータ正転リフトstep)

	case 22
		if not(XSW50_ストッパ上昇端) or pnlPBXSW50_ストッパ上昇端 then
			if not(XSW52_ストッパ上昇端) or pnlPBXSW52_ストッパ上昇端 then
				if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
					inc(MC21_搬送モータ正転リフトstep)
				end if
			end if
		end if

	case 23
		if MC20_搬送モータstep=0 and MC20_搬送モータLFTUPstep=0 then
			inc(MC21_搬送モータ正転リフトstep)
		end if

	case 24
		StageDevice21=StageDevice20
		StageDevice20=StageDevice19
		StageDevice19=StageDevice18
		StageDevice18=StageDevice17

		MC21_搬送モータ正転リフトstep=0

	end select
	'-----------------------------------------------------------------
	'MC21_搬送モータ正転ほぐし (MC22_搬送モータ正転並列駆動）
	tmr(tim_MC21_搬送モータ正転ほぐし,tim_MC21_搬送モータ正転ほぐし_val)
	
	select case MC21_搬送モータ正転ほぐしstep
	case 0
	case 1
		'水釜バキューム
		PH22_釜搬送禁止=エスケープ中
		PH27_釜起動検知=PH27_釜検知 				 
		PH28_フタ起動検知=PH28_フタ検知
		inc(MC21_搬送モータ正転ほぐしstep)
	
	case 2
		MC20_搬送モータstep=1
		if PH27_釜検知 or PH28_フタ検知 then
			inc(MC21_搬送モータ正転ほぐしstep)
		else
			MC20_搬送モータstep=1
			MC21_搬送モータ正転ほぐしstep=0
		end if
	
	'------------------------
	case 3
		if not(PH22_釜搬送禁止) and PH22_釜検知 then 'エスケープ
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_釜検知 then 'フタ取り
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_釜検知 then 'ごはん検知

			if ごはん検知 then
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
		
		else
			StageDevice19=0
		end if				
	
		if PH27_釜検知 then 'バキューム
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice20=0
		end if

		mSV42_ストッパ=OFF
		mSV43_ストッパ=OFF
		mSV44_リフト=OFF

		mMC21_搬送モータ正転=ON
		mMC22_搬送モータ正転=ON
		errpassコンベア一時停止=OFF

		inc(MC21_搬送モータ正転ほぐしstep)

	case 4
		if (XSW49_ストッパ下降端 and not(pnlPBXSW49_ストッパ下降端)) or passXSW49_ストッパ下降端 then
			if (XSW51_ストッパ下降端 and not(pnlPBXSW51_ストッパ下降端)) or passXSW51_ストッパ下降端 then
				if (XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端 then
					inc(MC21_搬送モータ正転ほぐしstep)
				end if
			end if
		end if
		inc(MC21_搬送モータ正転ほぐしstep)
	'------------------------
	case 5
		inc(MC21_搬送モータ正転ほぐしstep)

	case 6
		if errpassコンベア一時停止 then
			inc(MC21_搬送モータ正転ほぐしstep)
		
		else if not(PH27_釜検知) and not(PH28_フタ検知) then
			inc(MC21_搬送モータ正転ほぐしstep)
		end if		

	case 7
		if errpassコンベア一時停止 then
			inc(MC21_搬送モータ正転ほぐしstep)
		
		else if	PH27_釜起動検知 or PH28_フタ起動検知 then
			if PH31_釜検知 then
				inc(MC21_搬送モータ正転ほぐしstep)
			end if
		end if
	
	case 8
		tim_MC21_搬送モータ正転ほぐし_val=10 'ブレーキタイミング
		res(tim_MC21_搬送モータ正転ほぐし)
		inc(MC21_搬送モータ正転ほぐしstep)
	
	case 9
		if tim_MC21_搬送モータ正転ほぐし.B then
			inc(MC21_搬送モータ正転ほぐしstep)
		end if		

	case 10
		mMC21_搬送モータ正転=OFF
		mMC22_搬送モータ正転=OFF

		inc(MC21_搬送モータ正転ほぐしstep)	
	
	case 11
		if MC20_搬送モータstep=0 and MC20_搬送モータLFTUPstep=0 then
			inc(MC21_搬送モータ正転ほぐしstep)
		end if
	'------------------------
	case 12
		StageDevice22=StageDevice20
		StageDevice20=StageDevice19
		StageDevice19=StageDevice18
		StageDevice18=StageDevice17
		StageDevice21=0

		MC21_搬送モータ正転ほぐしstep=0

	end select

	'-----------------------------------------------------------------
	'MC21_搬送モータ逆転リフト
	
	'-----------------------------------------------------------------

	tmr(tim_MC21_搬送モータ逆転リフト,tim_MC21_搬送モータ逆転リフト_val)
	
	select case MC21_搬送モータ逆転リフトstep
	case 0
	case 1
		'反転ほぐしA
		PH31_釜起動検知=PH31_釜検知 				
		inc(MC21_搬送モータ逆転リフトstep)
	
	case 2
		if PH31_釜検知 then
			inc(MC21_搬送モータ逆転リフトstep)
		else
			MC21_搬送モータ逆転リフトstep=0
		end if
	
	'------------------------
	case 3
		mSV42_ストッパ=ON
		mSV43_ストッパ=OFF
		mSV44_リフト=OFF

		mMC21_搬送モータ逆転=ON
		mMC22_搬送モータ逆転=ON
		errpassコンベア一時停止=OFF

		inc(MC21_搬送モータ逆転リフトstep)

	case 4
		if (XSW50_ストッパ上昇端 and not(pnlPBXSW50_ストッパ上昇端)) or passXSW50_ストッパ上昇端 then
			if (XSW51_ストッパ下降端 and not(pnlPBXSW51_ストッパ下降端)) or passXSW51_ストッパ下降端 then
				if (XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端 then
					inc(MC21_搬送モータ逆転リフトstep)
				end if
			end if
		end if
		inc(MC21_搬送モータ逆転リフトstep)
	'------------------------
	case 5
		inc(MC21_搬送モータ逆転リフトstep)

	case 6

		'-------------------------------------------------------------------------
		MC20_搬送モータLFTUPstep=1 '多重運転
		'-------------------------------------------------------------------------

		if errpassコンベア一時停止 then
			inc(MC21_搬送モータ逆転リフトstep)
		
		else if not(PH31_釜検知) then
			inc(MC21_搬送モータ逆転リフトstep)
		end if		

	case 7
		if errpassコンベア一時停止 then
			inc(MC21_搬送モータ逆転リフトstep)
		
		else if	PH31_釜起動検知 then
			if PH29_釜検知 and PH30_フタ検知 then
				inc(MC21_搬送モータ逆転リフトstep)
			end if
		end if

	case 8
		tim_MC21_搬送モータ逆転リフト_val=24
		res(tim_MC21_搬送モータ逆転リフト)
		inc(MC21_搬送モータ逆転リフトstep)
	
	case 9
		if tim_MC21_搬送モータ逆転リフト.B then
			inc(MC21_搬送モータ逆転リフトstep)
		end if		
	

	case 10
		mMC21_搬送モータ逆転=OFF
		mMC22_搬送モータ逆転=OFF

		inc(MC21_搬送モータ逆転リフトstep)	
	
	case 11
		tim_MC21_搬送モータ逆転リフト_val=0
		res(tim_MC21_搬送モータ逆転リフト)
		inc(MC21_搬送モータ逆転リフトstep)
	
	case 12
		if tim_MC21_搬送モータ逆転リフト.B then
			inc(MC21_搬送モータ逆転リフトstep)
		end if
		
	case 13
		mSV42_ストッパ=ON
		mSV44_リフト=OFF
		inc(MC21_搬送モータ逆転リフトstep)

	case 14
		if (XSW50_ストッパ上昇端 and not(pnlPBXSW50_ストッパ上昇端)) or passXSW50_ストッパ上昇端 then
			if (XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端 then
				inc(MC21_搬送モータ逆転リフトstep)
			end if
		end if
		
	case 15
		mSV42_ストッパ=ON
		mSV44_リフト=ON
		inc(MC21_搬送モータ逆転リフトstep)

	case 16
		if (XSW50_ストッパ上昇端 and not(pnlPBXSW50_ストッパ上昇端)) or passXSW50_ストッパ上昇端 then
			if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
				inc(MC21_搬送モータ逆転リフトstep)
			end if
		end if

	case 17
		tim_MC21_搬送モータ逆転リフト_val=0
		res(tim_MC21_搬送モータ逆転リフト)
		inc(MC21_搬送モータ逆転リフトstep)
	
	case 18
		if tim_MC21_搬送モータ逆転リフト.B then
			inc(MC21_搬送モータ逆転リフトstep)
		end if		
	
	case 19
		mSV42_ストッパ=OFF
		mSV43_ストッパ=OFF
		mSV44_リフト=ON
		inc(MC21_搬送モータ逆転リフトstep)

	case 20
		if not(XSW50_ストッパ上昇端) or pnlPBXSW50_ストッパ上昇端 then
			if not(XSW52_ストッパ上昇端) or pnlPBXSW52_ストッパ上昇端 then
				if (XSW54_リフト上昇端 and not(pnlPBXSW54_リフト上昇端)) or passXSW54_リフト上昇端 then
					inc(MC21_搬送モータ逆転リフトstep)
				end if
			end if
		end if

	case 21
		if MC20_搬送モータstep=0 and MC20_搬送モータLFTUPstep=0 then
			
			StageDevice21=0
			StageDevice22=0
			MC21_搬送モータ逆転リフトstep=0
	
		end if
	end select
	'-----------------------------------------------------------------
	'MC20_搬送モータ正転LFTUP
	tmr(tim_MC20_搬送モータLFTUP,tim_MC20_搬送モータLFTUP_val)
	
	select case MC20_搬送モータLFTUPstep
	case 0
	case 1
		'エスケープ
		PH22_釜搬送禁止=エスケープ中
		PH22_釜起動検知=PH22_釜検知 	
		
		'フタ取り装置
		PH23_釜起動検知=PH23_釜検知 				
		PH24_フタ起動検知=PH24_フタ検知
		
		'ごはん検知
		PH25_釜起動検知=PH25_釜検知 				
		PH26_フタ起動検知=PH26_フタ検知
		
		'水釜バキューム
		'PH27_釜起動検知=PH27_釜検知 				 
		'PH28_フタ起動検知=PH28_フタ検知

		inc(MC20_搬送モータLFTUPstep)
	
	case 2
	
		if PH22_釜搬送禁止 then
			MC20_搬送モータLFTUPstep=0
			
		else if ((PH25_釜検知 or PH26_フタ検知) and (PH27_釜検知 or PH28_フタ検知)) then 'ごはん検知とバキュームユニット位置
			MC20_搬送モータLFTUPstep=0
			
		else
			inc(MC20_搬送モータLFTUPstep)
		end if

	case 3
		if PH27_釜検知 or PH28_フタ検知 then 'バキューム位置
			mSV57_バキュームリフト=ON
		end if
		
		if mSV57_バキュームリフト then
			if (XSW72_バキューマリフト上昇端 and not(pnlPBXSW72_バキューマリフト上昇端)) or passXSW72_バキューマリフト上昇端 then
				inc(MC20_搬送モータLFTUPstep)
			end if
		else
			inc(MC20_搬送モータLFTUPstep)
		end if

	case 4
	
		if not(PH22_釜搬送禁止) and PH22_釜検知 then 'エスケープ 
			StageDevice17=$8000
		else
			StageDevice17=0
		end if

		if PH23_釜検知 then 'フタ取り
			StageDevice18=$8000
		else
			StageDevice18=0
		end if
		
		if PH25_釜検知 then 'ごはん検知

			if ごはん検知 then
				StageDevice190=ORA(StageDevice190,$1000)
				StageDevice19=ORA(StageDevice19,$1000)
			end if
			StageDevice19=ORA(StageDevice19,$8000)
			StageDevice190=ORA(StageDevice190,$8000)
		
		else
			StageDevice19=0
			StageDevice190=0
		end if				
	
		if PH27_釜検知 then 'バキューム
			StageDevice200=ORA(StageDevice200,$8000)
			StageDevice20=ORA(StageDevice20,$8000)
		else
			StageDevice200=0
			StageDevice20=0
		end if
	
	
	
		SV40_ストッパstep=1
		inc(MC20_搬送モータLFTUPstep)
	
	case 5
		if SV40_ストッパstep=0 or (not(mSV40_ストッパ) and ((XSW45_ストッパ下降端 and not(pnlPBXSW45_ストッパ下降端)) or passXSW45_ストッパ下降端)) then
			inc(MC20_搬送モータLFTUPstep)
		end if	
	
	case 6
		搬送コンベアD動作中=ON
		MC19_搬送モータstep=1
		inc(MC20_搬送モータLFTUPstep)
		
	case 7
		if  MC19_搬送モータstep=0 or mMC19_搬送モータ then
			inc(MC20_搬送モータLFTUPstep)
		end if	
		
	case 8
		mMC20_搬送モータ=ON
		errpassコンベア一時停止=OFF
		inc(MC20_搬送モータLFTUPstep)
	
	case 9
		if PH22_釜搬送禁止 or フタ取りフタ取り中 or not(PH22_釜検知) then
			inc(MC20_搬送モータLFTUPstep)
		end if
	
	case 10
		if errpassコンベア一時停止 then
			inc(MC20_搬送モータLFTUPstep)
		else if not(PH23_釜検知) and not(PH24_フタ検知) then
				if not(PH25_釜検知) and not(PH26_フタ検知) then
					inc(MC20_搬送モータLFTUPstep)
				end if
		end if
	
	case 11
		if errpassコンベア一時停止 then
				inc(MC20_搬送モータLFTUPstep)		
		
		else if not(PH22_釜搬送禁止) and PH22_釜起動検知 and not(フタ取りフタ取り中) then
			if PH23_釜検知 or PH24_フタ検知 then
				tim_MC20_搬送モータLFTUP_val=MC20ブレーキタイミング 'L=8 R=9
				res(tim_MC20_搬送モータLFTUP)
				inc(MC20_搬送モータLFTUPstep)
			end if

		else if PH23_釜起動検知 or PH24_フタ起動検知 then
			if PH25_釜検知 or PH26_フタ検知 then
				tim_MC20_搬送モータLFTUP_val=9
				res(tim_MC20_搬送モータLFTUP)
				inc(MC20_搬送モータLFTUPstep)
			end if
		
		else if PH25_釜起動検知 or PH26_フタ起動検知 then
			if PH27_釜検知 or PH28_フタ検知 then
				tim_MC20_搬送モータLFTUP_val=9
				res(tim_MC20_搬送モータLFTUP)
				inc(MC20_搬送モータLFTUPstep)
			end if
		else
			tim_MC20_搬送モータLFTUP_val=8
			res(tim_MC20_搬送モータLFTUP)
			inc(MC20_搬送モータLFTUPstep)
		end if
	
	case 12
		if tim_MC20_搬送モータLFTUP.B then
			inc(MC20_搬送モータLFTUPstep)
		end if
	
	case 13
		mMC20_搬送モータ=OFF
		if MC21_搬送モータ正転ほぐしstep=0 and MC21_搬送モータ逆転リフトstep=0 and MC21_搬送モータ正転リフトstep=0 then
			StageDevice20=StageDevice19
			StageDevice19=StageDevice18
			StageDevice18=StageDevice17
		end if		
		StageDevice200=StageDevice190
		inc(MC20_搬送モータLFTUPstep)
		
	case 14
		if MC19_搬送モータstep=0 then
			inc(MC20_搬送モータLFTUPstep)
		end if
	
	case 15
		tim_MC20_搬送モータLFTUP_val=9
		res(tim_MC20_搬送モータLFTUP)
		inc(MC20_搬送モータLFTUPstep)

	case 16
		if tim_MC20_搬送モータLFTUP.B then
			inc(MC20_搬送モータLFTUPstep)
		end if
	
	case 17
		if SV40_ストッパstep=0 then
			inc(MC20_搬送モータLFTUPstep)
		end if

	case 18
		if mSV57_バキュームリフト then
			mSV57_バキュームリフト=OFF
		end if
		inc(MC20_搬送モータLFTUPstep)
	
	case 19
		if (XSW71_バキューマリフト下降端 and not(pnlPBXSW71_バキューマリフト下降端)) or passXSW71_バキューマリフト下降端 then
			inc(MC20_搬送モータLFTUPstep)
		end if		

	case 20

		ごはん検知=OFF

		フタ取り完了=OFF
		ごはん検知完了=OFF
		バキューム完了=OFF
		
		フタ取り排出要求=OFF
		ごはん検知排出要求=OFF
		水抜きバキューム排出要求=OFF

		搬送コンベアD動作中=OFF

		MC20_搬送モータLFTUPstep=0

	end select






	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else
	
		if ManualInite=0 then
			mSV40_ストッパ=OFF
			mSV42_ストッパ=OFF
			mSV43_ストッパ=OFF
			ManualInite=1
		end if
	
		res(timerr_MC19_搬送モータ)
		res(timerr_MC20_搬送モータ)
		res(timerr_MC21_搬送モータ正転)
		res(timerr_MC21_搬送モータ逆転)
		res(timerr_MC22_搬送モータ正転)
		res(timerr_MC22_搬送モータ逆転)

		res(timerr_MC20_搬送モータdec)

		搬送コンベアDAutoRun=OFF
		
		搬送コンベアDstep=0 '終了
		
		if ldp(pnlPBSV41_リフト) then
			if mSV41_リフト then
				mSV41_リフト=OFF '下降
			else 'if MC17_むらし機モータ=OFF and  MC19_搬送モータ=OFF then
				mSV41_リフト=ON '上昇
			end if
		end if
		
		if ldp(pnlPBSV40_ストッパ) then
			if mSV40_ストッパ then
				mSV40_ストッパ=OFF
			else
				mSV40_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV42_ストッパ) then
			if mSV42_ストッパ then
				mSV42_ストッパ=OFF
			else
				mSV42_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV43_ストッパ) then
			if mSV43_ストッパ then
				mSV43_ストッパ=OFF
			else
				mSV43_ストッパ=ON
			end if
		end if
		
		if ldp(pnlPBSV44_リフト) then
			if mSV44_リフト then
				mSV44_リフト=OFF
			else
				mSV44_リフト=ON
			end if
		end if
			
		if ldp(pnlPBMC19_搬送モータ) then
			if mMC19_搬送モータ then
				mMC19_搬送モータ=OFF
			else if 蓋取りユニットOrg then
				mMC19_搬送モータ=ON
			end if
		end if
		
		if ldp(pnlPBMC20_搬送モータ) then
			if mMC20_搬送モータ then
				mMC20_搬送モータ=OFF
			else 
				mMC20_搬送モータ=ON
			end if
		end if

		if ldp(pnlPBMC21_搬送モータ正転)  then
			if not(mMC21_搬送モータ逆転) then
				if mMC21_搬送モータ正転 then
					mMC21_搬送モータ正転=OFF
				else if ((XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端) then 
					mMC21_搬送モータ正転=ON
				end if
			end if
		else if ldp(pnlPBMC21_搬送モータ逆転)  then
			if not(mMC21_搬送モータ正転) then
				if mMC21_搬送モータ逆転 then
					mMC21_搬送モータ逆転=OFF
				else if  ((XSW53_リフト下降端 and not(pnlPBXSW53_リフト下降端)) or passXSW53_リフト下降端) then
					mMC21_搬送モータ逆転=ON
				end if
			end if
		end if
		
		if ldp(pnlPBMC22_搬送モータ正転) then
			if not(mMC22_搬送モータ逆転) then
				if mMC22_搬送モータ正転 then
					mMC22_搬送モータ正転=OFF
				else
					mMC22_搬送モータ正転=ON
				end if
			end if
		else if ldp(pnlPBMC22_搬送モータ逆転) then
			if not(mMC22_搬送モータ正転) then
				if mMC22_搬送モータ逆転 then
					mMC22_搬送モータ逆転=OFF
				else
					mMC22_搬送モータ逆転=ON
				end if
			end if
		end if
				
			
	end if '搬送コンベアDAutoMode and not(搬送コンベアDOrgErrStep)

	'===================================================================================================================
	'【 搬送コンベアDOrgErr処理 】
	else
	
		if ResetFlg then
			搬送コンベアDOrgErr=OFF
		end if

	end if
	'===================================================================================================================
	'【 コンベア一時停止処理 】
	else
		res(timerr_MC19_搬送モータ)
		res(timerr_MC20_搬送モータ)
		res(timerr_MC21_搬送モータ正転)
		res(timerr_MC21_搬送モータ逆転)
		res(timerr_MC22_搬送モータ正転)
		res(timerr_MC22_搬送モータ逆転)
		
		コンベア一時停止中=ON
		alm渋滞警報=ON			

		
		if ResetFlg then
			almMC19_搬送モータ=OFF
			almMC20_搬送モータ=OFF
			almMC21_搬送モータ正転=OFF
			almMC21_搬送モータ逆転=OFF
			almMC22_搬送モータ正転=OFF
			almMC22_搬送モータ逆転=OFF
			

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
		
		搬送コンベアDErr=ON

		pauseMC19_搬送モータ=ON
		pauseMC20_搬送モータ=ON
		pauseMC21_搬送モータ逆転=ON
		pauseMC22_搬送モータ逆転=ON
		

		select case 搬送コンベアDErrStep
		case 0
		case 1
			alm渋滞警報=ON			
		
			if ResetFlg then
				almXSW45_ストッパ下降端=OFF
				almXSW46_ストッパ上昇端=OFF
				almXSW49_ストッパ下降端=OFF
				almXSW50_ストッパ上昇端=OFF
				almXSW51_ストッパ下降端=OFF
				almXSW52_ストッパ上昇端=OFF
				almXSW53_リフト下降端=OFF
				almXSW54_リフト上昇端=OFF
				almXSW48_リフト上昇端=OFF
				almXSW47_リフト下降端=OFF

				alm渋滞警報=OFF

				inc(搬送コンベアDErrStep)
			end if
		case 2

			res(tim_XSW48_リフト上昇端.B)
			res(tim_XSW47_リフト下降端.B)
			res(tim_XSW45_ストッパ下降端.B)
			res(tim_XSW46_ストッパ上昇端.B)
			res(tim_XSW49_ストッパ下降端.B)
			res(tim_XSW50_ストッパ上昇端.B)
			res(tim_XSW51_ストッパ下降端.B)
			res(tim_XSW52_ストッパ上昇端.B)
			res(tim_XSW53_リフト下降端.B)
			res(tim_XSW54_リフト上昇端.B)

			res(tim_notXSW48_リフト上昇端.B)
			res(tim_notXSW47_リフト下降端.B)
			res(tim_notXSW45_ストッパ下降端.B)
			res(tim_notXSW46_ストッパ上昇端.B)
			res(tim_notXSW49_ストッパ下降端.B)
			res(tim_notXSW50_ストッパ上昇端.B)
			res(tim_notXSW51_ストッパ下降端.B)
			res(tim_notXSW52_ストッパ上昇端.B)
			res(tim_notXSW53_リフト下降端.B)
			res(tim_notXSW54_リフト上昇端.B)

			pauseMC19_搬送モータ=OFF
			pauseMC20_搬送モータ=OFF
			pauseMC21_搬送モータ逆転=OFF
			pauseMC22_搬送モータ逆転=OFF
			
			pauseSV40_ストッパ=OFF
			pauseSV42_ストッパ=OFF
			pauseSV43_ストッパ=OFF
			pauseSV44_リフト=OFF
			pauseSV41_リフト=OFF

			搬送コンベアDErr=OFF
			搬送コンベアDErrStep=0
		end select

	end if 'if 搬送コンベアDErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 搬送コンベアDEmgStep
	case 0
	
	case 1
		搬送コンベアDAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (搬送コンベアDAutoMode and 自動搬送AutoMode ) or 搬送コンベアDstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			EmgMC19_搬送モータ=ON
			EmgMC20_搬送モータ=ON
			EmgMC21_搬送モータ正転=ON
			EmgMC21_搬送モータ逆転=ON
			EmgMC22_搬送モータ正転=ON
			EmgMC22_搬送モータ逆転=ON

			if timstack=OFF then
			
				tim_procstep_stack.U=tim_procstep.U
				tim_SV40_ストッパ_stack.U=tim_SV40_ストッパ.U
				tim_MC19_搬送モータ_stack.U=tim_MC19_搬送モータ.U
				tim_MC20_搬送モータ_stack.U=tim_MC20_搬送モータ.U
				tim_MC21_搬送モータ正転リフト_stack.U=tim_MC21_搬送モータ正転リフト.U
				tim_MC21_搬送モータ正転ほぐし_stack.U=tim_MC21_搬送モータ正転ほぐし.U
				tim_MC21_搬送モータ逆転リフト_stack.U=tim_MC21_搬送モータ逆転リフト.U
				tim_MC20_搬送モータLFTUP_stack.U=tim_MC20_搬送モータLFTUP.U
				
			' tmr(tim_procstep,tim_procstep_val)
			' tmr(tim_SV40_ストッパ,tim_SV40_ストッパ_val) 'フタ取り装置ストッパ
			' tmr(tim_MC19_搬送モータ,tim_MC19_搬送モータ_val)
			' tmr(tim_MC20_搬送モータ,tim_MC20_搬送モータ_val)
			' tmr(tim_MC21_搬送モータ正転リフト,tim_MC21_搬送モータ正転リフト_val)
			' tmr(tim_MC21_搬送モータ正転ほぐし,tim_MC21_搬送モータ正転ほぐし_val)
			' tmr(tim_MC21_搬送モータ逆転リフト,tim_MC21_搬送モータ逆転リフト_val)
			
				timstack=ON
			end if
			'---------------------------------
		
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mMC19_搬送モータ=OFF
			mMC20_搬送モータ=OFF
			mMC21_搬送モータ正転=OFF
			mMC21_搬送モータ逆転=OFF
			mMC22_搬送モータ正転=OFF
			mMC22_搬送モータ逆転=OFF
			mSV41_リフト=OFF
			mSV40_ストッパ=OFF
			mSV42_ストッパ=OFF
			mSV43_ストッパ=OFF
			mSV44_リフト=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(搬送コンベアDEmgStep)
	case 2
		if ResetFlg then
			inc(搬送コンベアDEmgStep)
		end if
	case 3
		if (搬送コンベアDAutoMode and 自動搬送AutoMode ) or 搬送コンベアDstep<>0 then
			if ldp(StartFlg) then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				EmgMC19_搬送モータ=OFF
				EmgMC20_搬送モータ=OFF
				EmgMC21_搬送モータ正転=OFF
				EmgMC21_搬送モータ逆転=OFF
				EmgMC22_搬送モータ正転=OFF
				EmgMC22_搬送モータ逆転=OFF

				'スタックの値をタイマー現在値にリストア
				tim_procstep.U=tim_procstep_stack.U
				tim_SV40_ストッパ.U=tim_SV40_ストッパ_stack.U
				tim_MC19_搬送モータ.U=tim_MC19_搬送モータ_stack.U
				tim_MC20_搬送モータ.U=tim_MC20_搬送モータ_stack.U
				tim_MC21_搬送モータ正転リフト.U=tim_MC21_搬送モータ正転リフト_stack.U
				tim_MC21_搬送モータ正転ほぐし.U=tim_MC21_搬送モータ正転ほぐし_stack.U
				tim_MC21_搬送モータ逆転リフト.U=tim_MC21_搬送モータ逆転リフト_stack.U
				tim_MC20_搬送モータLFTUP.U=tim_MC20_搬送モータLFTUP_stack.U
				
				' tmr(tim_procstep,tim_procstep_val)
				' tmr(tim_SV40_ストッパ,tim_SV40_ストッパ_val) 'フタ取り装置ストッパ
				' tmr(tim_MC19_搬送モータ,tim_MC19_搬送モータ_val)
				' tmr(tim_MC20_搬送モータ,tim_MC20_搬送モータ_val)
				' tmr(tim_MC21_搬送モータ正転リフト,tim_MC21_搬送モータ正転リフト_val)
				' tmr(tim_MC21_搬送モータ正転ほぐし,tim_MC21_搬送モータ正転ほぐし_val)
				' tmr(tim_MC21_搬送モータ逆転リフト,tim_MC21_搬送モータ逆転リフト_val)

				
				'検出タイマーのリセット


				'---------------------------------
				inc(搬送コンベアDEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(搬送コンベアDEmgStep)		
		end if				
	case 4
		timstack=OFF
		搬送コンベアDEmgStep=0
		搬送コンベアDEmg=OFF
	end select

end if 'if 搬送コンベアDEmgStep=0 then
