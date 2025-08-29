'蓋被せユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	蓋被せユニット
'
'
'	フタ被せ時のエラー回避
'	フタ被せ位置修正エラー発生  -> リトライ  ->  釜排出  (MC15搬送モータ , MC43乗移コンベア) -> フタ置き → フタ被せエラー発生
'                    (reset sw)                                                                               (reset sw)
'                    *フタ修正                                                                                *手でフタ被せ  
'
'===================================================================================================================

'【 初期化処理 】
if CR2008 then
    蓋被せユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    蓋被せユニットAutoRun=OFF
    蓋被せユニット許可=ON
    蓋被せユニットOrgErr=OFF
    蓋被せユニットErr=OFF
    蓋被せユニットEmg=OFF
    蓋被せユニットstep=0
    蓋被せユニットErrStep=0
    蓋被せユニットOrgErrStep=0
    蓋被せユニットEmgStep=0

end if
'===================================================================================================================
'【 原点 】
蓋被せユニットOrg=(XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A  
蓋被せユニットOrg=蓋被せユニットOrg and ((XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B)
蓋被せユニットOrg=蓋被せユニットOrg and ((XSW111_釜位置右後退端 and not(pnlPBXSW111_釜位置右後退端)) or passXSW111_釜位置右後退端)
蓋被せユニットOrg=蓋被せユニットOrg and ((XSW112_釜位置左後退端 and not(pnlPBXSW112_釜位置左後退端)) or passXSW112_釜位置左後退端)
蓋被せユニットOrg=蓋被せユニットOrg or not(蓋被せユニット許可) 

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	蓋被せユニットEmg=ON
	蓋被せユニットEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】
tmr(SV34_シリンダ上昇A and not(XSW39_シリンダ上昇端A) and not(pnlPBXSW39_シリンダ上昇端A),tim_notXSW39_シリンダ上昇端A,#50)
tmr(SV35_シリンダ下降A and not(XSW40_シリンダ下降端A) and not(pnlPBXSW40_シリンダ下降端A),tim_notXSW40_シリンダ下降端A,#50)
tmr(SV36_シリンダ上昇B and not(XSW41_シリンダ上昇端B) and not(pnlPBXSW41_シリンダ上昇端B),tim_notXSW41_シリンダ上昇端B,#50)
tmr(SV37_シリンダ下降B and not(XSW42_シリンダ下降端B) and not(pnlPBXSW42_シリンダ下降端B),tim_notXSW42_シリンダ下降端B,#50)
tmr(SV38_クランプ and not(XSW43_クランプ) and not(pnlPBXSW43_クランプ),tim_notXSW43_クランプ,#40)
tmr(SV39_アンクランプ and not(XSW44_アンクランプ) and not(pnlPBXSW44_アンクランプ),tim_notXSW44_アンクランプ,#40)
tmr(not(SV64_釜位置) and not(XSW111_釜位置右後退端),tim_notXSW111_釜位置右後退端,#10)
tmr(not(SV64_釜位置) and not(XSW112_釜位置左後退端),tim_notXSW112_釜位置左後退端,#10)

if LDP(SV34_シリンダ上昇A) and XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A) then
	SET(tim_XSW39_シリンダ上昇端A)
end if
if LDP(SV35_シリンダ下降A) and XSW40_シリンダ下降端A and not(pnlPBXSW40_シリンダ下降端A) then
	SET(tim_XSW40_シリンダ下降端A)
end if
if LDP(SV36_シリンダ上昇B) and XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B) then
	SET(tim_XSW41_シリンダ上昇端B)
end if
if LDP(SV37_シリンダ下降B) and XSW42_シリンダ下降端B and not(pnlPBXSW42_シリンダ下降端B) then
	SET(tim_XSW42_シリンダ下降端B)
end if
if LDP(SV38_クランプ) and XSW43_クランプ and XSW44_アンクランプ and not(pnlPBXSW43_クランプ) then
	SET(tim_XSW43_クランプ)
end if
if LDP(SV39_アンクランプ) and XSW43_クランプ and XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ) then
	SET(tim_XSW44_アンクランプ)
end if
if LDF(SV64_釜位置) and XSW111_釜位置右後退端 and not(pnlPBXSW111_釜位置右後退端) then
	SET(tim_XSW111_釜位置右後退端)
end if
if LDF(SV64_釜位置) and XSW112_釜位置左後退端 and not(pnlPBXSW112_釜位置左後退端) then
	SET(tim_XSW112_釜位置左後退端)
end if


if SV34_シリンダ上昇A then
	KeepSV34_シリンダ上昇A=ON
	KeepSV35_シリンダ下降A=OFF
else if SV35_シリンダ下降A then
	KeepSV34_シリンダ上昇A=OFF
	KeepSV35_シリンダ下降A=ON
end if
if SV36_シリンダ上昇B then
	KeepSV36_シリンダ上昇B=ON
	KeepSV37_シリンダ下降B=OFF
else if SV37_シリンダ下降B then
	KeepSV36_シリンダ上昇B=OFF
	KeepSV37_シリンダ下降B=ON
end if
if SV38_クランプ then
	KeepSV38_クランプ=ON
	KeepSV39_アンクランプ=OFF
else if SV39_アンクランプ then
	KeepSV38_クランプ=OFF
	KeepSV39_アンクランプ=ON
end if

'passtimXSW39_シリンダ上昇端A_val=#3000
tms(KeepSV34_シリンダ上昇A,passtimXSW39_シリンダ上昇端A,passtimXSW39_シリンダ上昇端A_val)
'passtimXSW40_シリンダ下降端A_val=#3000
tms(KeepSV35_シリンダ下降A,passtimXSW40_シリンダ下降端A,passtimXSW40_シリンダ下降端A_val)
'passtimXSW41_シリンダ上昇端B_val=#3000
tms(KeepSV36_シリンダ上昇B,passtimXSW41_シリンダ上昇端B,passtimXSW41_シリンダ上昇端B_val)
'passtimXSW42_シリンダ下降端B_val=#3000
tms(KeepSV37_シリンダ下降B,passtimXSW42_シリンダ下降端B,passtimXSW42_シリンダ下降端B_val)
'passtimXSW43_クランプ_val=#500
tms(KeepSV38_クランプ,passtimXSW43_クランプ,passtimXSW43_クランプ_val)
'passtimXSW44_アンクランプ_val=#500
tms(KeepSV39_アンクランプ,passtimXSW44_アンクランプ,passtimXSW44_アンクランプ_val)

'passtimXSW111_釜位置右後退端_val=#500
tms(not(SV64_釜位置),passtimXSW111_釜位置右後退端,passtimXSW111_釜位置右後退端_val)
'passtimXSW112_釜位置左後退端_val=#500
tms(not(SV64_釜位置),passtimXSW112_釜位置左後退端,passtimXSW112_釜位置左後退端_val)

if 蓋被せユニット許可 then

	if (ldp(tim_XSW39_シリンダ上昇端A.B) or ldp(tim_notXSW39_シリンダ上昇端A.B)) and not(pnlPBXSW39_シリンダ上昇端A)  then
		almXSW39_シリンダ上昇端A=ON
		pnlPBXSW39_シリンダ上昇端A=ON
		res(tim_XSW39_シリンダ上昇端A)
		蓋被せユニットErrStep=1

	else if (ldp(tim_XSW40_シリンダ下降端A.B) or ldp(tim_notXSW40_シリンダ下降端A.B)) and not(pnlPBXSW40_シリンダ下降端A)  then
		if フタ被せフタ取り中 then
			errXSW40_シリンダ下降端A=ON 'フタ被せエラー通知
			almXSW40_シリンダ下降端A=ON
			pnlPBXSW40_シリンダ下降端A=ON
			res(tim_XSW40_シリンダ下降端A)
			蓋被せユニットErrStep=1
		else
			almXSW40_シリンダ下降端A=ON
			pnlPBXSW40_シリンダ下降端A=ON
			res(tim_XSW40_シリンダ下降端A)			
			蓋被せユニットErrStep=1
		end if

	else if (ldp(tim_XSW41_シリンダ上昇端B.B) or ldp(tim_notXSW41_シリンダ上昇端B.B)) and not(pnlPBXSW41_シリンダ上昇端B) then
		almXSW41_シリンダ上昇端B=ON
		pnlPBXSW41_シリンダ上昇端B=ON
		if tim_XSW41_シリンダ上昇端B then
			res(tim_XSW41_シリンダ上昇端B)
		end if
		蓋被せユニットErrStep=1
		
	else if (ldp(tim_XSW42_シリンダ下降端B.B) or ldp(tim_notXSW42_シリンダ下降端B.B)) and not(pnlPBXSW42_シリンダ下降端B) then
		almXSW42_シリンダ下降端B=ON
		pnlPBXSW42_シリンダ下降端B=ON
		if tim_XSW42_シリンダ下降端B then
			res(tim_XSW42_シリンダ下降端B)
		end if
		蓋被せユニットErrStep=1
		
	else if (ldp(tim_XSW43_クランプ.B) or ldp(tim_notXSW43_クランプ.B)) and not(pnlPBXSW43_クランプ) then
		almXSW43_クランプ=ON
		pnlPBXSW43_クランプ=ON
		pnlPBXSW44_アンクランプ=ON
		if tim_XSW43_クランプ then
			res(tim_XSW43_クランプ)
		end if
		蓋被せユニットErrStep=1

	else if (ldp(tim_XSW44_アンクランプ.B) or ldp(tim_notXSW44_アンクランプ.B)) and not(pnlPBXSW44_アンクランプ) then
		almXSW44_アンクランプ=ON
		pnlPBXSW43_クランプ=ON
		pnlPBXSW44_アンクランプ=ON
		if tim_XSW44_アンクランプ then
			res(tim_XSW44_アンクランプ)
		end if
		蓋被せユニットErrStep=1

	else if (ldp(tim_XSW111_釜位置右後退端) or ldp(tim_notXSW111_釜位置右後退端)) and not(pnlPBXSW111_釜位置右後退端) then
		almXSW111_釜位置右後退端=ON
		pnlPBXSW111_釜位置右後退端=ON
		if tim_XSW111_釜位置右後退端 then
			res(tim_XSW111_釜位置右後退端)
		end if
		蓋被せユニットErrStep=1
	
	else if (ldp(tim_XSW112_釜位置左後退端) or ldp(tim_notXSW112_釜位置左後退端)) and not(pnlPBXSW112_釜位置左後退端) then
		almXSW112_釜位置左後退端=ON
		pnlPBXSW112_釜位置左後退端=ON
		if tim_XSW112_釜位置左後退端 then
			res(tim_XSW112_釜位置左後退端)
		end if
		蓋被せユニットErrStep=1

	end if
	
	
else
	res(tim_notXSW31_ストッパ下降端)
	res(tim_notXSW32_ストッパ上昇端)
	res(tim_notXSW35_クランプ下降端)
	res(tim_notXSW36_クランプ上昇端)
	
	res(tim_notXSW39_シリンダ上昇端A)
	res(tim_notXSW40_シリンダ下降端A)
	res(tim_notXSW41_シリンダ上昇端B)
	res(tim_notXSW42_シリンダ下降端B)
	res(tim_notXSW43_クランプ)
	res(tim_notXSW44_アンクランプ)
	res(tim_notXSW111_釜位置右後退端)
	res(tim_notXSW112_釜位置左後退端)
	

	res(tim_XSW31_ストッパ下降端)
	res(tim_XSW32_ストッパ上昇端)
	res(tim_XSW35_クランプ下降端)
	res(tim_XSW36_クランプ上昇端)

	res(tim_XSW39_シリンダ上昇端A)
	res(tim_XSW40_シリンダ下降端A)
	res(tim_XSW41_シリンダ上昇端B)
	res(tim_XSW42_シリンダ下降端B)
	res(tim_XSW43_クランプ)
	res(tim_XSW44_アンクランプ)
	res(tim_XSW111_釜位置右後退端)
	res(tim_XSW112_釜位置左後退端)

end if


tmr(not(SV32_クランプ) and not(XSW35_クランプ下降端) and not(pnlPBXSW35_クランプ下降端), tim_notXSW35_クランプ下降端, #30)
tmr(SV32_クランプ and not(XSW36_クランプ上昇端) and not(pnlPBXSW36_クランプ上昇端), tim_notXSW36_クランプ上昇端,#30)
tmr(not(SV30_ストッパ) and not(XSW31_ストッパ下降端) and not(pnlPBXSW31_ストッパ下降端),tim_notXSW31_ストッパ下降端,#30)
tmr(SV30_ストッパ and not(XSW32_ストッパ上昇端) and not(pnlPBXSW32_ストッパ上昇端),tim_notXSW32_ストッパ上昇端,#30)

if LDF(SV32_クランプ) and  XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端) then
	SET(tim_XSW35_クランプ下降端)
end if
if LDP(SV32_クランプ) and XSW36_クランプ上昇端 and not(pnlPBXSW36_クランプ上昇端) then
	SET(tim_XSW36_クランプ上昇端)
end if
if LDF(SV30_ストッパ) and XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端) then
	SET(tim_XSW31_ストッパ下降端)
end if
if LDP(SV30_ストッパ) and XSW32_ストッパ上昇端 and not(pnlPBXSW32_ストッパ上昇端) then
	SET(tim_XSW32_ストッパ上昇端)
end if

if not(搬送コンベアC動作中) and (ldp(tim_XSW35_クランプ下降端.B) or ldp(tim_notXSW35_クランプ下降端.B)) and not(pnlPBXSW35_クランプ下降端) then
	almXSW35_クランプ下降端=ON
	pnlPBXSW35_クランプ下降端=ON
	res(tim_XSW35_クランプ下降端)
	蓋被せユニットErrStep=1

else if not(搬送コンベアC動作中) and (ldp(tim_XSW36_クランプ上昇端.B) or ldp(tim_notXSW36_クランプ上昇端.B)) and not(pnlPBXSW36_クランプ上昇端) then
	pauseSV32_クランプ=ON
	almXSW36_クランプ上昇端=ON
	pnlPBXSW36_クランプ上昇端=ON
	res(tim_XSW36_クランプ上昇端)
	蓋被せユニットErrStep=1

else if not(搬送コンベアC動作中) and (ldp(tim_XSW31_ストッパ下降端.B) or ldp(tim_notXSW31_ストッパ下降端.B)) and not(pnlPBXSW31_ストッパ下降端) then
	almXSW31_ストッパ下降端=ON
	pnlPBXSW31_ストッパ下降端=ON
	res(tim_XSW31_ストッパ下降端)
	蓋被せユニットErrStep=1

else if not(搬送コンベアC動作中) and (ldp(tim_XSW32_ストッパ上昇端.B) or ldp(tim_notXSW32_ストッパ上昇端.B)) and not(pnlPBXSW32_ストッパ上昇端) then
	pauseSV30_ストッパ=ON
	almXSW32_ストッパ上昇端=ON
	pnlPBXSW32_ストッパ上昇端=ON
	res(tim_XSW32_ストッパ上昇端)
	蓋被せユニットErrStep=1

end if
'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 蓋被せユニットAutoMode	自動モード セレクトスイッチ
'System :: 蓋被せユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: 蓋被せユニットEmg	その場停止

if 蓋被せユニットEmgStep=0 then  
	
	if 蓋被せユニットErrStep=0  or errXSW40_シリンダ下降端A then
	
	if not(蓋被せユニットOrgErr) then

	if (蓋被せユニットAutoMode and 自動搬送AutoMode ) or 蓋被せユニットstep<>0 then
		
		if not(蓋被せユニットAutoMode and 自動搬送AutoMode ) then
			蓋被せユニットAutoRun=OFF
		end if
		
	'--------------------------------------------
	'MC15_搬送モータ
	tmr(tim_MC15_搬送モータ,tim_MC15_搬送モータ_val)
	
	select case MC15_搬送モータstep
	case 0
	
	case 1
		mSV30_ストッパ=OFF
		mSV32_クランプ=OFF
		inc(MC15_搬送モータstep)
		
	case 2
		PH19_釜起動検知=PH19_釜検知
		PH20_フタ起動検知=PH20_フタ検知
		'PH54_釜送りトリガ

		if PH19_釜検知 or PH20_フタ検知 then
			if ((XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端) and ((XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端) then
				mMC15_搬送モータ=ON
				inc(MC15_搬送モータstep)
			end if
		else
			MC15_搬送モータstep=0
		end if
		
	case 3
		if not(PH19_釜検知) and not(PH20_フタ検知) then
			inc(MC15_搬送モータstep)	
		end if
	
	case 4
		if PH19_釜起動検知 or PH20_フタ起動検知 then
			if PH54_釜送りトリガ then
				inc(MC15_搬送モータstep)
			end if
		end if
		
	case 5
		tim_MC15_搬送モータ_val=10 'ブレークタイミング
		res(tim_MC15_搬送モータ)
		inc(MC15_搬送モータstep)
	
	case 6
		if tim_MC15_搬送モータ.B then 
			inc(MC15_搬送モータstep)
		end if
	
	case 7
		mMC15_搬送モータ=OFF
		inc(MC15_搬送モータstep)
		
	case 8
		tim_MC15_搬送モータ_val=0
		res(tim_MC15_搬送モータ)
		inc(MC15_搬送モータstep)
	
	case 9
		if tim_MC15_搬送モータ.B then 
			inc(MC15_搬送モータstep)
		end if
	
	case 10
		MC15_搬送モータstep=0
		
	end select
		
	'--------------------------------------------
	' 乗り換えコンベア PH58 PH54+tim
	tmr(tim_MC43_乗移コンベア,tim_MC43_乗移コンベア_val)
	
	select case MC43_乗移コンベアstep
	case 0

	case 1
		if  PH19_釜検知  then
			inc(MC43_乗移コンベアstep)
		else
			MC43_乗移コンベアstep=0
		end if
		
	case 2
		mMC43_乗移コンベア=ON
		inc(MC43_乗移コンベアstep)

	case 3
		if not(PH19_釜検知) then 
			inc(MC43_乗移コンベアstep)
		end if
	
	case 4
		if PH54_釜送りトリガ then
			inc(MC43_乗移コンベアstep)
		end if			
	
	case 5
		tim_MC43_乗移コンベア_val=10 '停止タイミングタイマー
		res(tim_MC43_乗移コンベア)
		inc(MC43_乗移コンベアstep)
	
	case 6
		if tim_MC43_乗移コンベア.B then
			inc(MC43_乗移コンベアstep)		
		end if
	
	case 7
		mMC43_乗移コンベア=OFF
		inc(MC43_乗移コンベアstep)		
	
	case 8
		MC43_乗移コンベアstep=0
	
	end select



	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case 蓋被せユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
			蓋被せユニットStatusMsg=#0

		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 蓋被せユニットAutoRun then
				if フタ被せフタ取り中 then
					蓋被せユニットStatusMsg=#41	'	フタ被せ待機中（フタを持っている状態）
				else
					蓋被せユニットStatusMsg=#43	'	待機中（フタを持っていない）
				end if
				
				inc(蓋被せユニットstep)
			else 
				蓋被せユニットstep=0 '終了待機
			end if

		case 2
		' [ 蓋カマ移動停止確認 ]
			if フタ被せ排出要求=OFF and  搬送コンベアC動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH19_釜検知 and PH20_フタ検知 then
						蓋被せユニットStatusMsg=#42	'	フタ置き中
						inc(蓋被せユニットstep) 'フタ被せ
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH19_釜検知) and PH20_フタ検知 then 
							蓋被せユニットStatusMsg=#40	'	フタ取り中
							inc(蓋被せユニットstep) 'フタ取り
				
				'[ 自ステージに"釜フタ"なし ]
						else
							フタ被せ排出要求=ON
							蓋被せユニットstep=1  '終了
					end if
			
			else
			
				蓋被せユニットstep=1
			
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if 蓋被せユニット許可 then
				蓋被せユニットstep=100 'プロセス処理
			else
				フタ被せ排出要求=ON
				蓋被せユニットstep=1
			end if
		
		'--------------------------------------------------------------------------------------------------------------
		'プロセス処理
		case 100
			if フタ被せ完了 then '搬送移動でOFF
				フタ被せ排出要求=ON
				蓋被せユニットstep=1
			else
				if フタ被せフタ取り中 and  PH19_釜検知 and PH20_フタ検知 then
					inc(蓋被せユニットstep) 'フタ被せ処理
				else if not(フタ被せフタ取り中) and  not(PH19_釜検知) and PH20_フタ検知 then
					蓋被せユニットstep=150 'フタ取り処理
				else
					フタ被せ排出要求=ON
					蓋被せユニットstep=1
				end if
			end if

		'------------------------------------------------------
		case 101  'フタ被せ (アンクランプ）
			mSV34_シリンダ上昇A=OFF
			mSV35_シリンダ下降A=OFF
			mSV36_シリンダ上昇B=OFF
			mSV37_シリンダ下降B=OFF
			mSV38_クランプ=OFF
			mSV39_アンクランプ=OFF

			
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)

		case 102
			if tim_procstep.B then
				if ((XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A) and ((XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B) then 
					if ((XSW111_釜位置右後退端 and not(pnlPBXSW111_釜位置右後退端)) or passXSW111_釜位置右後退端) and ((XSW112_釜位置左後退端 and not(pnlPBXSW112_釜位置左後退端)) or passXSW112_釜位置左後退端) then
						if ((XSW43_クランプ and not(pnlPBXSW43_クランプ)) or passXSW43_クランプ) then
							inc(蓋被せユニットstep)
						else
							蓋被せユニットstep=1
						end if
					else
						蓋被せユニットstep=1						
					end if
				else
					蓋被せユニットstep=1
				end if
			end if

		'------------------------------------------------------
		case 103
			mSV64_釜位置=ON
			inc(蓋被せユニットstep)
			
		case 104
			if (not(XSW111_釜位置右後退端) or pnlPBXSW111_釜位置右後退端) and (not(XSW112_釜位置左後退端) or pnlPBXSW112_釜位置左後退端) then
				inc(蓋被せユニットstep)
			end if
		
		case 105
			tim_procstep_val=20
			res(tim_procstep)
			inc(蓋被せユニットstep)
		
		case 106
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 107
			mSV64_釜位置=OFF
			inc(蓋被せユニットstep)
			
		case 108
			if ((XSW111_釜位置右後退端 and not(pnlPBXSW111_釜位置右後退端)) or passXSW111_釜位置右後退端) and ((XSW112_釜位置左後退端 and not(pnlPBXSW112_釜位置左後退端)) or passXSW112_釜位置左後退端) then
				inc(蓋被せユニットstep)
			end if
		'------------------------------------------------------
		case 109
			mSV35_シリンダ下降A=ON
			inc(蓋被せユニットstep)

		case 110
			if (XSW40_シリンダ下降端A and not(pnlPBXSW40_シリンダ下降端A)) or passXSW40_シリンダ下降端A then
				inc(蓋被せユニットstep)
			end if
		
		case 111
			mSV35_シリンダ下降A=OFF
			tim_procstep_val=5
			res(tim_procstep)
			inc(蓋被せユニットstep)
		
		case 112
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 113
			'-- errpassXSW40_シリンダ下降端A  の場合はクランプを外さない --
			if not(errXSW40_シリンダ下降端A) then
				mSV39_アンクランプ=ON	
				errpassXSW44_アンクランプ=OFF
				inc(蓋被せユニットstep)
			else
				inc(蓋被せユニットstep)
			end if				
		
		case 114
			if not(errXSW40_シリンダ下降端A) then		
				if (XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ then
					inc(蓋被せユニットstep)
				end if
			else
				inc(蓋被せユニットstep)		
			end if
		
		case 115
			mSV39_アンクランプ=OFF
			tim_procstep_val=0 'アンクランプ待機時間
			res(tim_procstep)
			inc(蓋被せユニットstep)
		
		case 116
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 117
			mSV34_シリンダ上昇A=ON
			inc(蓋被せユニットstep)

		case 118
			if (XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A then
				inc(蓋被せユニットstep)
			end if
		
		case 119
			mSV34_シリンダ上昇A=OFF
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)
			
		
		case 120
			if tim_procstep.B then
				if not(errXSW40_シリンダ下降端A) then					
					フタ被せフタ取り中=OFF
				end if
				inc(蓋被せユニットstep)
			end if
		
		case 121
			if errXSW40_シリンダ下降端A then
				errXSW40_シリンダ下降端A=OFF
			else
				RetryMode=OFF
				フタ被せ完了=ON
				フタ被せ排出要求=ON
			end if
			蓋被せユニットstep=1
		'------------------------------------------------------
		case 150 'フタ取り  （クランプ）
			mSV34_シリンダ上昇A=OFF
			mSV35_シリンダ下降A=OFF
			mSV36_シリンダ上昇B=OFF
			mSV37_シリンダ下降B=OFF
			mSV38_クランプ=OFF
			mSV39_アンクランプ=OFF
			inc(蓋被せユニットstep)

		case 151
			mSV39_アンクランプ=ON	
			inc(蓋被せユニットstep)

		case 152
			if (XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ then
				inc(蓋被せユニットstep)
			end if
		
		case 153
			mSV39_アンクランプ=OFF
			tim_procstep_val=0 'アンクランプ待機時間
			res(tim_procstep)
			inc(蓋被せユニットstep)


		case 154
			if tim_procstep.B then
				if ((XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A) and ((XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B) then  
					if ((XSW111_釜位置右後退端 and not(pnlPBXSW111_釜位置右後退端)) or passXSW111_釜位置右後退端) and ((XSW112_釜位置左後退端 and not(pnlPBXSW112_釜位置左後退端)) or passXSW112_釜位置左後退端) then
						if ((XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ) then
							inc(蓋被せユニットstep)
						else
							蓋被せユニットstep=1
						end if
					else
						蓋被せユニットstep=1					
					end if
				else
					蓋被せユニットstep=1
				end if
			end if

		case 155
			mSV35_シリンダ下降A=ON
			mSV37_シリンダ下降B=ON
			inc(蓋被せユニットstep)

		case 156
			if (XSW40_シリンダ下降端A and not(pnlPBXSW40_シリンダ下降端A)) or passXSW40_シリンダ下降端A then
				mSV35_シリンダ下降A=OFF
				inc(蓋被せユニットstep)
			end if		
		
		case 157
			if (XSW42_シリンダ下降端B and not(pnlPBXSW42_シリンダ下降端B)) or passXSW42_シリンダ下降端B then
				mSV37_シリンダ下降B=OFF
				inc(蓋被せユニットstep)
			end if

		case 158
			tim_procstep_val=5
			res(tim_procstep)
			inc(蓋被せユニットstep)		

		case 159
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 160
			mSV38_クランプ=ON
			inc(蓋被せユニットstep)
		
		case 161
			if (XSW43_クランプ and not(pnlPBXSW43_クランプ)) or passXSW43_クランプ then
				inc(蓋被せユニットstep)
			end if
		
		case 162
			mSV38_クランプ=OFF
			inc(蓋被せユニットstep)

		case 163
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)				

		case 164
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if

		case 165
			mSV30_ストッパ=OFF 'コンベアCストッパ
			mSV32_クランプ=OFF 'コンベアCクランプ
			inc(蓋被せユニットstep)

		case 166
			if ((XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端) and ((XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端) then
				inc(蓋被せユニットstep)
			end if		

		
		case 167
			mSV36_シリンダ上昇B=ON
			mSV34_シリンダ上昇A=ON
			inc(蓋被せユニットstep)

		case 168
			if (XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B then
				mSV36_シリンダ上昇B=OFF
				inc(蓋被せユニットstep)
			end if
		
		case 169
			if (XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A then
				mSV34_シリンダ上昇A=OFF
				inc(蓋被せユニットstep)
			end if

		case 170
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)

		case 171
			if tim_procstep.B then
				フタ被せフタ取り中=ON
				inc(蓋被せユニットstep)
			end if

		case 172
			if errpassXSW40_シリンダ下降端A then
				errpassXSW40_シリンダ下降端A=OFF
			end if
			フタ被せ完了=ON
			フタ被せ排出要求=ON
			蓋被せユニットstep=1
		'------------------------------------------------------
		'蓋締めｴﾗｰ時の釜排出、フタ置き
		case 200 'フタ被せエラー時の釜排出、フタ置き
			mSV30_ストッパ=OFF 'コンベアCストッパ
			mSV32_クランプ=OFF 'コンベアCクランプ
			inc(蓋被せユニットstep)

		case 201
			if ((XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端) and ((XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端) then
				inc(蓋被せユニットstep)
			end if
			
		case 202
			if not(PH54_釜送りトリガ) then
				inc(蓋被せユニットstep)
			end if
		
		case 203
			MC15_搬送モータstep=1
			MC43_乗移コンベアstep=1
			inc(蓋被せユニットstep)
		
		case 204
			if MC15_搬送モータstep=0 and MC43_乗移コンベアstep=0 then
				inc(蓋被せユニットstep)		
			end if 
		
		case 205 'フタ外し
			mSV34_シリンダ上昇A=OFF
			mSV35_シリンダ下降A=OFF
			mSV36_シリンダ上昇B=OFF
			mSV37_シリンダ下降B=OFF
			mSV38_クランプ=OFF
			mSV39_アンクランプ=OFF
			inc(蓋被せユニットstep)


		case 206
			mSV35_シリンダ下降A=ON
			mSV37_シリンダ下降B=ON
			inc(蓋被せユニットstep)

		case 207
			if (XSW40_シリンダ下降端A and not(pnlPBXSW40_シリンダ下降端A)) or passXSW40_シリンダ下降端A then
				mSV35_シリンダ下降A=OFF
				inc(蓋被せユニットstep)
			end if		
		
		case 208
			if (XSW42_シリンダ下降端B and not(pnlPBXSW42_シリンダ下降端B)) or passXSW42_シリンダ下降端B then
				mSV37_シリンダ下降B=OFF
				inc(蓋被せユニットstep)
			end if

		case 209
			tim_procstep_val=5
			res(tim_procstep)
			inc(蓋被せユニットstep)		

		case 210
			if tim_procstep.B then
				inc(蓋被せユニットstep)
			end if
		
		case 211
			mSV39_アンクランプ=ON	
			inc(蓋被せユニットstep)
		
		case 212
			if (XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ then
				inc(蓋被せユニットstep)
			end if
		
		case 213
			mSV39_アンクランプ=OFF
			inc(蓋被せユニットstep)


		case 214
			mSV36_シリンダ上昇B=ON
			mSV34_シリンダ上昇A=ON
			inc(蓋被せユニットstep)

		case 215
			if (XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B then
				mSV36_シリンダ上昇B=OFF
				inc(蓋被せユニットstep)
			end if
		
		case 216
			if (XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A then
				mSV34_シリンダ上昇A=OFF
				inc(蓋被せユニットstep)
			end if

		case 217
			
			tim_procstep_val=0
			res(tim_procstep)
			inc(蓋被せユニットstep)

		case 218
			if tim_procstep.B then
				errXSW40_シリンダ下降端A=OFF
				EjectMode=OFF
				フタ被せフタ取り中=OFF
				フタ被せ完了=ON
				フタ被せ排出要求=ON

				almXSW40_シリンダ下降端A=ON
				蓋被せユニットErrStep=1
				
				蓋被せユニットstep=1
			end if
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		蓋被せユニットAutoRun=OFF
		
		蓋被せユニットstep=0 '終了
		フタ被せ完了=OFF


		'------------------------------------------------------
		if ldp(pnlPBSV35_シリンダ下降A) then
			if ((XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A) then
				mSV35_シリンダ下降A=ON
				mSV34_シリンダ上昇A=OFF
			end if
		else if ldp(pnlPBSV34_シリンダ上昇A) then
			if ((XSW40_シリンダ下降端A and not(pnlPBXSW40_シリンダ下降端A)) or passXSW40_シリンダ下降端A) then
				mSV35_シリンダ下降A=OFF
				mSV34_シリンダ上昇A=ON
			end if
		end if
		if mSV35_シリンダ下降A and (XSW40_シリンダ下降端A and not(pnlPBXSW40_シリンダ下降端A)) or passXSW40_シリンダ下降端A then
			mSV35_シリンダ下降A=OFF
		end if
		if mSV34_シリンダ上昇A and (XSW39_シリンダ上昇端A and not(pnlPBXSW39_シリンダ上昇端A)) or passXSW39_シリンダ上昇端A then
			mSV34_シリンダ上昇A=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV37_シリンダ下降B) then
			'下降
			if not(PH19_釜検知)  then
				if ((XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B) and ((XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ) then
					if ((XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端) and ((XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端) then
						mSV37_シリンダ下降B=ON
						mSV36_シリンダ上昇B=OFF		
					end if
				end if
			end if		
		else if ldp(pnlPBSV36_シリンダ上昇B) then
			'上昇
			if ((XSW42_シリンダ下降端B and not(pnlPBXSW42_シリンダ下降端B)) or passXSW42_シリンダ下降端B) and ((XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ) then
				mSV37_シリンダ下降B=OFF
				mSV36_シリンダ上昇B=ON
			
			else if ((XSW42_シリンダ下降端B and not(pnlPBXSW42_シリンダ下降端B)) or passXSW42_シリンダ下降端B) and  ((XSW43_クランプ and not(pnlPBXSW43_クランプ)) or passXSW43_クランプ) then 
					if ((XSW31_ストッパ下降端 and not(pnlPBXSW31_ストッパ下降端)) or passXSW31_ストッパ下降端) and ((XSW35_クランプ下降端 and not(pnlPBXSW35_クランプ下降端)) or passXSW35_クランプ下降端) then
						mSV37_シリンダ下降B=OFF
						mSV36_シリンダ上昇B=ON
					end if
			end if
		end if
		if mSV37_シリンダ下降B and ((XSW42_シリンダ下降端B and not(pnlPBXSW42_シリンダ下降端B)) or passXSW42_シリンダ下降端B) then
			mSV37_シリンダ下降B=OFF
		end if
		if mSV36_シリンダ上昇B and ((XSW41_シリンダ上昇端B and not(pnlPBXSW41_シリンダ上昇端B)) or passXSW41_シリンダ上昇端B) then
			mSV36_シリンダ上昇B=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV38_クランプ) then
			if (XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ then
				mSV38_クランプ=ON
				mSV39_アンクランプ=OFF
				
				フタ被せフタ取り中=ON
			end if
		else if ldp(pnlPBSV39_アンクランプ) then
			if (XSW43_クランプ and not(pnlPBXSW43_クランプ)) or passXSW43_クランプ then
				mSV38_クランプ=OFF
				mSV39_アンクランプ=ON
				
				フタ被せフタ取り中=OFF
			end if
		end if
		if mSV39_アンクランプ and ((XSW44_アンクランプ and not(pnlPBXSW44_アンクランプ)) or passXSW44_アンクランプ) then
			mSV39_アンクランプ=OFF
		end if
		if mSV38_クランプ and ((XSW43_クランプ and not(pnlPBXSW43_クランプ)) or passXSW43_クランプ) then
			mSV38_クランプ=OFF
		end if
		'------------------------------------------------------
		if ldp(pnlPBSV64_釜位置) then
			if mSV64_釜位置 then
				mSV64_釜位置=OFF
			else
				mSV64_釜位置=ON
			end if
		end if
		'------------------------------------------------------
			
		
		

	end if '蓋被せユニットAutoMode
	'===================================================================================================================
	'【 蓋被せユニットOrgErr処理 】
	else

		if ResetFlg then
			蓋被せユニットOrgErr=OFF
		end if		

	end if

	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else

		if フタ被せフタ取り中 then
			tmr(tim_errXSW40_シリンダ下降端,tim_errXSW40_シリンダ下降端_val)
			select case 蓋被せユニットErrStep
			case 0
			'------------------------------------------------------------------
			case 1
				蓋被せユニットErr=ON
				pauseMC15_搬送モータ=ON
				pauseMC43_乗移コンベア=ON
				
				if ResetFlg then				' 
					almXSW39_シリンダ上昇端A=OFF
					almXSW40_シリンダ下降端A=OFF
					almXSW41_シリンダ上昇端B=OFF
					almXSW42_シリンダ下降端B=OFF
					almXSW43_クランプ=OFF
					almXSW44_アンクランプ=OFF
					
					almXSW111_釜位置右後退端=OFF
					almXSW112_釜位置左後退端=OFF
					
					almXSW35_クランプ下降端=OFF
					almXSW36_クランプ上昇端=OFF
					almXSW31_ストッパ下降端=OFF
					almXSW32_ストッパ上昇端=OFF


					pauseSV32_クランプ=OFF
					pauseSV30_ストッパ=OFF
					pauseMC15_搬送モータ=OFF
					pauseMC43_乗移コンベア=OFF

					inc(蓋被せユニットErrStep)
				end if
			case 2
				if EjectMode then
					EjectMode=OFF
				else 
					if RetryMode then
						RetryMode=OFF
						EjectMode=ON
						inc(蓋被せユニットErrStep)
					else
						RetryMode=ON
						EjectMode=OFF
						inc(蓋被せユニットErrStep)
					end if
				end if
			case 3
				if EjectMode and 蓋被せユニットstep<100 then '蓋被せユニットstepが 0または1でプロセスが終了していること
					蓋被せユニットstep=200
				else if RetryMode and 蓋被せユニットstep<100 then '蓋被せユニットstepが 0または1でプロセスが終了していること
					蓋被せユニットstep=101
				end if
				inc(蓋被せユニットErrStep)
			'------------------------------------------------------------------
			case 4
				res(tim_notXSW31_ストッパ下降端)
				res(tim_notXSW32_ストッパ上昇端)				
				res(tim_notXSW35_クランプ下降端)
				res(tim_notXSW36_クランプ上昇端)
				
				res(tim_notXSW39_シリンダ上昇端A)
				res(tim_notXSW40_シリンダ下降端A)
				res(tim_notXSW41_シリンダ上昇端B)
				res(tim_notXSW42_シリンダ下降端B)
				res(tim_notXSW43_クランプ)
				res(tim_notXSW44_アンクランプ)
				res(tim_notXSW111_釜位置右後退端)
				res(tim_notXSW112_釜位置左後退端)
				
				res(tim_XSW31_ストッパ下降端)
				res(tim_XSW32_ストッパ上昇端)				
				res(tim_XSW35_クランプ下降端)
				res(tim_XSW36_クランプ上昇端)

				res(tim_XSW39_シリンダ上昇端A)
				res(tim_XSW40_シリンダ下降端A)
				res(tim_XSW41_シリンダ上昇端B)
				res(tim_XSW42_シリンダ下降端B)
				res(tim_XSW43_クランプ)
				res(tim_XSW44_アンクランプ)
				res(tim_XSW111_釜位置右後退端)
				res(tim_XSW112_釜位置左後退端)

				蓋被せユニットErr=OFF
				蓋被せユニットErrStep=0
			
			end select
		
		else
			蓋被せユニットErr=ON

			select case 蓋被せユニットErrStep
			case 0
			case 1
				if ResetFlg then
					
					almXSW39_シリンダ上昇端A=OFF
					almXSW40_シリンダ下降端A=OFF
					almXSW41_シリンダ上昇端B=OFF
					almXSW42_シリンダ下降端B=OFF
					almXSW43_クランプ=OFF
					almXSW44_アンクランプ=OFF

					almXSW111_釜位置右後退端=OFF
					almXSW112_釜位置左後退端=OFF

					almXSW35_クランプ下降端=OFF
					almXSW36_クランプ上昇端=OFF
					almXSW31_ストッパ下降端=OFF
					almXSW32_ストッパ上昇端=OFF

					
					inc(蓋被せユニットErrStep)
				end if
			case 2
					res(tim_notXSW31_ストッパ下降端)
					res(tim_notXSW32_ストッパ上昇端)				
					res(tim_notXSW35_クランプ下降端)
					res(tim_notXSW36_クランプ上昇端)
					
					res(tim_notXSW39_シリンダ上昇端A)
					res(tim_notXSW40_シリンダ下降端A)
					res(tim_notXSW41_シリンダ上昇端B)
					res(tim_notXSW42_シリンダ下降端B)
					res(tim_notXSW43_クランプ)
					res(tim_notXSW44_アンクランプ)
					res(tim_notXSW111_釜位置右後退端)
					res(tim_notXSW112_釜位置左後退端)
					
					res(tim_XSW31_ストッパ下降端)
					res(tim_XSW32_ストッパ上昇端)				
					res(tim_XSW35_クランプ下降端)
					res(tim_XSW36_クランプ上昇端)

					res(tim_XSW39_シリンダ上昇端A)
					res(tim_XSW40_シリンダ下降端A)
					res(tim_XSW41_シリンダ上昇端B)
					res(tim_XSW42_シリンダ下降端B)
					res(tim_XSW43_クランプ)
					res(tim_XSW44_アンクランプ)
					res(tim_XSW111_釜位置右後退端)
					res(tim_XSW112_釜位置左後退端)

				蓋被せユニットErr=OFF
				蓋被せユニットErrStep=0
			end select
		
		end if

	end if 'if 蓋被せユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	select case 蓋被せユニットEmgStep
	case 0
	
	case 1
		蓋被せユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (蓋被せユニットAutoMode and 自動搬送AutoMode ) or 蓋被せユニットstep<>0 then

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
			mSV35_シリンダ下降A=OFF
			mSV34_シリンダ上昇A=OFF
			mSV37_シリンダ下降B=OFF
			mSV36_シリンダ上昇B=OFF
			mSV38_クランプ=OFF
			mSV39_アンクランプ=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(蓋被せユニットEmgStep)
	case 2
		if ResetFlg then
			inc(蓋被せユニットEmgStep)
		end if
	case 3
		if (蓋被せユニットAutoMode and 自動搬送AutoMode ) or 蓋被せユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				
				'---------------------------------
				inc(蓋被せユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(蓋被せユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		蓋被せユニットEmgStep=0
		蓋被せユニットEmg=OFF
	end select
		
end if 'if 蓋被せユニットEmgStep=0 then
