'浸漬タンクBユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	浸漬タンクB
'
'2025/1/27
'①充填バルブ監視時間を #30->#50 に変更
'tmr(SV7_充填バルブ開B and not(XSW5_充填バルブ開B) and not(pnlPBXSW5_充填バルブ開B),tim_notXSW5_充填バルブ開B,#50)
'tmr(not(SV7_充填バルブ開B) and not(XSW6_充填バルブ閉B) and not(pnlPBXSW6_充填バルブ閉B),tim_notXSW6_充填バルブ閉B,#50)
'②1回目の第一充填開き時間を5秒から7秒に変更
'
'===================================================================================================================

'【 初期化処理 】

if CR2008 then
    浸漬タンクBユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    浸漬タンクBユニットAutoRun=OFF
    浸漬タンクBユニット許可=OFF
    浸漬タンクBユニットOrgErr=OFF
    浸漬タンクBユニットErr=OFF
    浸漬タンクBユニットEmg=OFF
    浸漬タンクBユニットstep=0
    浸漬タンクBユニットErrStep=0
    浸漬タンクBユニットOrgErrStep=0
    浸漬タンクBユニットEmgStep=0

	ワンサイクルflg=OFF
	
	配米準備step=0
	シャッター開閉step=0

end if

'===================================================================================================================
'【 原点 】
浸漬タンクBユニットOrg=not(浸漬タンクBユニット許可) or ((XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B) and ((XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B)) or passXSW8_水切りシャッター閉B)

'===================================================================================================================
'【 緊急停止 】


if not(PB非常停止) then
	浸漬タンクBユニットEmg=ON
	浸漬タンクBユニットEmgStep=1
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

tmr(SV7_充填バルブ開B and not(XSW5_充填バルブ開B) and not(pnlPBXSW5_充填バルブ開B),tim_notXSW5_充填バルブ開B,#50)
tmr(not(SV7_充填バルブ開B) and not(XSW6_充填バルブ閉B) and not(pnlPBXSW6_充填バルブ閉B),tim_notXSW6_充填バルブ閉B,#50)
tmr(SSW3_自動モード and SV9_水切りシャッター開B and not(XSW7_水切りシャッター開B) and not(pnlPBXSW7_水切りシャッター開B),tim_notXSW7_水切りシャッター開B,#50)
tmr(SSW3_自動モード and SV10_水切りシャッター閉B and not(XSW8_水切りシャッター閉B) and not(pnlPBXSW8_水切りシャッター閉B),tim_notXSW8_水切りシャッター閉B,#50)
'tmr(SV62_排水バルブ開B and not(XSW78_排水バルブ開B) and not(pnlPBXSW78_排水バルブ開B), tim_notXSW78_排水バルブ開B,#30)
'tmr(not(SV62_排水バルブ開B) and not(XSW79_排水バルブ閉B) and not(pnlPBXSW79_排水バルブ閉B),tim_notXSW79_排水バルブ閉B,#30)

if LDP(mSV7_充填バルブ開B) and XSW5_充填バルブ開B and not(pnlPBXSW5_充填バルブ開B) then
	SET(tim_XSW5_充填バルブ開B)
end if

if LDF(mSV7_充填バルブ開B) and XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B) then'
	SET(tim_XSW6_充填バルブ閉B)
end if

if LDP(SV9_水切りシャッター開B) and XSW7_水切りシャッター開B and not(pnlPBXSW7_水切りシャッター開B) then
	SET(tim_XSW7_水切りシャッター開B)
end if

if LDP(SV10_水切りシャッター閉B) and XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B) then
	SET(tim_XSW8_水切りシャッター閉B)
end if

if SV9_水切りシャッター開B and not(SV10_水切りシャッター閉B) then
	KeepSV9_水切りシャッター開B=ON
else if SV10_水切りシャッター閉B then
	KeepSV9_水切りシャッター開B=OFF
end if

if SV10_水切りシャッター閉B and not(SV9_水切りシャッター開B) then
	KeepSV10_水切りシャッター閉B=ON
else if SV9_水切りシャッター開B then
	KeepSV10_水切りシャッター閉B=OFF
end if

'passtimXSW5_充填バルブ開B_val=#2000
tms(SV7_充填バルブ開B,passtimXSW5_充填バルブ開B,passtimXSW5_充填バルブ開B_val)
'passtimXSW6_充填バルブ閉B_val=#2000
tms(not(SV7_充填バルブ開B),passtimXSW6_充填バルブ閉B,passtimXSW6_充填バルブ閉B_val)
'passtimXSW7_水切りシャッター開B_val=#1281
tms(KeepSV9_水切りシャッター開B,passtimXSW7_水切りシャッター開B,passtimXSW7_水切りシャッター開B_val)
'passtimXSW8_水切りシャッター閉B_val=#881
tms(KeepSV10_水切りシャッター閉B,passtimXSW8_水切りシャッター閉B,passtimXSW8_水切りシャッター閉B_val) 

if (ldp(tim_XSW5_充填バルブ開B.B) or ldp(tim_notXSW5_充填バルブ開B)) and not(pnlPBXSW5_充填バルブ開B) then
	almXSW5_充填バルブ開B=ON
	pnlPBXSW5_充填バルブ開B=ON
	if tim_XSW5_充填バルブ開B then
		res(tim_XSW5_充填バルブ開B)
	end if
	浸漬タンクBユニットErrStep=1

else if (ldp(tim_XSW6_充填バルブ閉B.B) or ldp(tim_notXSW6_充填バルブ閉B)) and not(pnlPBXSW6_充填バルブ閉B) then
	almXSW6_充填バルブ閉B=ON
	pnlPBXSW6_充填バルブ閉B=ON
	if tim_XSW6_充填バルブ閉B then
		res(tim_XSW6_充填バルブ閉B)
	end if
	浸漬タンクBユニットErrStep=1

else if (ldp(tim_XSW7_水切りシャッター開B.B) or ldp(tim_notXSW7_水切りシャッター開B.B)) and not(pnlPBXSW7_水切りシャッター開B) then
	almXSW7_水切りシャッター開B=ON
	pnlPBXSW7_水切りシャッター開B=ON
	if tim_XSW7_水切りシャッター開B then
		res(tim_XSW7_水切りシャッター開B)
	end if
	浸漬タンクBユニットErrStep=1		

else if (ldp(tim_XSW8_水切りシャッター閉B.B) or ldp(tim_notXSW8_水切りシャッター閉B.B)) and not(pnlPBXSW8_水切りシャッター閉B) then
	almXSW8_水切りシャッター閉B=ON
	pnlPBXSW8_水切りシャッター閉B=ON
	if tim_XSW8_水切りシャッター閉B then
		res(tim_XSW8_水切りシャッター閉B)
	end if
	浸漬タンクBユニットErrStep=1

end if
'===================================================================================================================
' PLインジケータ
	'-------------------------------------------------------------

	if アルファ化米モード then
		浸漬タンクBユニット許可=OFF
	end if
	
	'-------------------------------------------------------------

	if not(自動搬送AutoMode) or not(浸漬タンクBユニットAutoMode) or 浸漬タンクB米無し then
		PBL13_自動配米B = ワンサイクルflg and CR2006
	else
		PBL13_自動配米B=OFF
	end if

	'-------------------------------------------------------------
	PBL14_タンク給水B = SV11_給水電磁弁B

	if ldp(pnlPBSV11_給水電磁弁B or PB14_タンク給水B) then
		if mSV11_給水電磁弁B then
			mSV11_給水電磁弁B=OFF
		else
			mSV11_給水電磁弁B=ON
		end if
	end if
	'-------------------------------------------------------------
	PBL31_排水バルブ開閉B = SV62_排水バルブ開B

	if ldp(PB31_排水バルブ開閉B or pnlPBSV62_排水バルブ開B) then
		if mSV62_排水バルブ開B then
			mSV62_排水バルブ開B=OFF
		else
			mSV62_排水バルブ開B=ON
		end if
	end if
	'-------------------------------------------------------------
	PBL11_充填バルブB =SV7_充填バルブ開B and not(tPBL11_充填バルブB and CR2006)
	tmr(PB11_充填バルブB,tim_PB11_充填バルブB,#30)

	select case 充填バルブstep
	case 0
		'通常のON/OFF動作
		tPBL11_充填バルブB=OFF
		if not(mSV7_充填バルブ開B) and not(SV9_水切りシャッター開B) then
			ejectSV7_充填バルブ開B=PB11_充填バルブB
		else
			ejectSV7_充填バルブ開B=OFF
		end if
		
		if tim_PB11_充填バルブB.B then
			inc(充填バルブstep)
		end if
		
	case 1
		'PB11_充填バルブB OFF待ち		
		tPBL11_充填バルブB=ON
		if not(mSV7_充填バルブ開B) and not(SV9_水切りシャッター開B) then
			ejectSV7_充填バルブ開B=ON
		else
			ejectSV7_充填バルブ開B=OFF
		end if
		
		if not(tim_PB11_充填バルブB.B) then
			inc(充填バルブstep)
		end if


	case 2
		'PB11_充填バルブB
		tPBL11_充填バルブB=ON
		if PB11_充填バルブB or mSV7_充填バルブ開B or SV9_水切りシャッター開B then
			ejectSV7_充填バルブ開B=OFF
			inc(充填バルブstep)
		end if
	
	
	case 3
		if not(PB11_充填バルブB) then
			充填バルブstep=0
		end if
	end select

	'-------------------------------------------------------------	
	PBL12_水切りシャッターB=KeepSV9_水切りシャッター開B

	if ldp(PB12_水切りシャッターB) then
		if not(tPBL12_水切りシャッターB) and not(SV7_充填バルブ開B) then
			mSV9_水切りシャッター開B=ON
			mSV10_水切りシャッター閉B=OFF
			tPBL12_水切りシャッターB=ON

			if not(アルファ化米モード) then
				if 自動搬送AutoMode and 自動搬送AutoRun then
					if ANDA(StageDevice1,$200)=0 and ANDA(StageDevice2,$200)=0 and ANDA(StageDevice1,$400)=0 and ANDA(StageDevice2,$400)=0 then
						inc(DM_B配米現在値)
					end if
				end if
				
				StageDevice1=ORA(StageDevice1,$400)
				StageDevice2=ORA(StageDevice2,$400)
			end if
			
		else if tPBL12_水切りシャッターB then
			mSV9_水切りシャッター開B=OFF
			mSV10_水切りシャッター閉B=ON
			tPBL12_水切りシャッターB=OFF

		end if
	end if

'	if not(mSV9_水切りシャッター開B) then
'		tPBL12_水切りシャッターB=OFF
'	end if

'===================================================================================================================
' センサー検出ディレイ―

	tmr(PDL3_パドルセンサー上限B,tim_PDL3_パドルセンサー上限B,20)
	tmr(PDL4_パドルセンサー下限B or pnlPBPDL4_パドルセンサー下限B,tim_PDL4_パドルセンサー下限B,20)
	tmr(RLY5_パドルセンサ電源 and not(PDL4_パドルセンサー下限B),timnot_PDL4_パドルセンサー下限B,60)
'===================================================================================================================
' 充填バルブ開閉
	'FLOS4_LMT121
	'SV7_充填バルブ開B
	'SV8_充填バルブ閉B
	tmr(FLOS4_LMT121,timdly_FLOS4_LMT121,10)
	tmr(not(FLOS4_LMT121),timnotdly_FLOS4_LMT121,60)
	
	if pnlPB強制米有B then
		浸漬タンクB米無し=OFF
	
	else if pnlPB強制米無しB then
		浸漬タンクB米無し=ON	
	
	else if timdly_FLOS4_LMT121.B or tim_PDL4_パドルセンサー下限B.B then
		浸漬タンクB米無し=OFF '米センサーON or パドルセンサー下限  or pnlPBパドルセンサー下限

	else if timnotdly_FLOS4_LMT121.B and timnot_PDL4_パドルセンサー下限B.B then
		浸漬タンクB米無し=ON '米センサーOFF and パドルセンサー下限OFF
	end if

	if ldp(浸漬タンクBユニットAutoRun) then
		初期充填動作=ON
	end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: 浸漬タンクBユニットAutoMode	自動モード セレクトスイッチ
'System :: 浸漬タンクBユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能
'System :: 浸漬タンクBユニットEmg	その場停止


if 浸漬タンクBユニットEmgStep=0 then  
	
	if 浸漬タンクBユニットErrStep=0  then
	
	if not(浸漬タンクBユニットOrgErr) then
		'---------------------------------------------------------------------------------
		tmr(tim_配米準備,tim_配米準備_val)
		select case 配米準備step

		case 0
		'1回目_充填バルブ1秒間_開閉
		case 1
			if アルファ化米モード then 
				配米準備完了B=ON
				配米完了B=ON
				配米準備step=0
			
			else if ワンサイクルflg or  not(浸漬タンクB米無し) then
				inc(配米準備step)
			else
				配米準備完了B=ON
				配米完了B=ON
				配米準備step=0
			end if	

		case 2
			if 浸漬タンクB米無し then
				inc(配米準備step)
			else
				mSV7_充填バルブ開B=ON
				inc(配米準備step)
			end if

		case 3
			if mSV7_充填バルブ開B then
				if (XSW5_充填バルブ開B and not(pnlPBXSW5_充填バルブ開B)) or passXSW5_充填バルブ開B then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 4
			if 初期充填動作 or ワンサイクルflg then				
				tim_配米準備_val=#70 '1回目充填バルブ開き時間
				res(tim_配米準備)
			else
				tim_配米準備_val=#15 '1回目充填バルブ開き時間
				res(tim_配米準備)
			end if			
			
			inc(配米準備step)

		case 5
			if tim_配米準備.B or 浸漬タンクB米無し then
				inc(配米準備step)
			end if

		case 6
			mSV7_充填バルブ開B=OFF	
			inc(配米準備step)

		case 7
			if (XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B then
				inc(配米準備step)
			end if

		case 8
			tim_配米準備_val=#10 '充填バルブ閉時間
			res(tim_配米準備)
			inc(配米準備step)

		'2回目_充填バルブ1秒間_開閉
		case 9
			inc(配米準備step)

		case 10
			if 浸漬タンクB米無し then
				inc(配米準備step)
			else if tim_配米準備.B then
				mSV7_充填バルブ開B=ON			
				inc(配米準備step)
			end if

		case 11
			if mSV7_充填バルブ開B then
				if (XSW5_充填バルブ開B and not(pnlPBXSW5_充填バルブ開B)) or passXSW5_充填バルブ開B then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if
		case 12
			if 初期充填動作 or ワンサイクルflg then				
				tim_配米準備_val=#50 '1回目充填バルブ開き時間
				res(tim_配米準備)
			else
				tim_配米準備_val=#20 '1回目充填バルブ開き時間
				res(tim_配米準備)
			end if			

			inc(配米準備step)

		case 13
			if tim_配米準備.B or 浸漬タンクB米無し then
				inc(配米準備step)
			end if

		case 14
			mSV7_充填バルブ開B=OFF	
			inc(配米準備step)

		case 15
			if (XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B then
				inc(配米準備step)
			end if

		case 16
			tim_配米準備_val=#10 '充填バルブ閉時間
			res(tim_配米準備)
			inc(配米準備step)

		'---------------------------------------------------------------------------------
		case 17
			inc(配米準備step)

		case 18
			if 浸漬タンクB米無し then
				inc(配米準備step)
			else if tim_配米準備.B then
				mSV7_充填バルブ開B=ON
				inc(配米準備step)
			end if

		case 19
			if mSV7_充填バルブ開B then
				if (XSW5_充填バルブ開B and not(pnlPBXSW5_充填バルブ開B)) or passXSW5_充填バルブ開B then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 20
			tim_配米準備_val=#10 '充填バルブ開き時間
			res(tim_配米準備)
			inc(配米準備step)
					
		case 21
			if tim_配米準備.B or 浸漬タンクB米無し then
				inc(配米準備step)
			end if

		case 22
			'mSV8_充填バルブ閉B=ON
			mSV7_充填バルブ開B=OFF	
			inc(配米準備step)

		case 23
			if (XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B then
				inc(配米準備step)
			end if
		
		case 24
			tim_配米準備_val=#10
			res(tim_配米準備)
			inc(配米準備step)
			
		case 25
			if tim_配米準備.B then
				inc(配米準備step)
			end if

		'-------------------------------------------------------------------------
		'充填バルブ4回目
		case 26
			if 初期充填動作 or ワンサイクルflg then
				inc(配米準備step)
			else
				配米準備step=100
			end if
		
		case 27
			if 浸漬タンクB米無し then
				inc(配米準備step)
			else if tim_配米準備.B then
				mSV7_充填バルブ開B=ON
				inc(配米準備step)
			end if

		case 28
			if mSV7_充填バルブ開B then
				if (XSW5_充填バルブ開B and not(pnlPBXSW5_充填バルブ開B)) or passXSW5_充填バルブ開B then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 29
			tim_配米準備_val=#10 '充填バルブ開き時間
			res(tim_配米準備)
			inc(配米準備step)
					
		case 30
			if tim_配米準備.B or 浸漬タンクB米無し then
				inc(配米準備step)
			end if

		case 31
			mSV7_充填バルブ開B=OFF	
			inc(配米準備step)

		case 32
			if (XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B then
				inc(配米準備step)
			end if

		case 33
			tim_配米準備_val=#10
			res(tim_配米準備)
			inc(配米準備step)
			
		case 34
			if tim_配米準備.B then
				inc(配米準備step)
			end if

		'-------------------------------------------------------------------------
		'充填バルブ5回目
		case 35
			if 浸漬タンクB米無し then
				inc(配米準備step)
			else if tim_配米準備.B then
				mSV7_充填バルブ開B=ON
				inc(配米準備step)
			end if

		case 36
			if mSV7_充填バルブ開B then
				if (XSW5_充填バルブ開B and not(pnlPBXSW5_充填バルブ開B)) or passXSW5_充填バルブ開B then
					inc(配米準備step)
				end if
			else
				inc(配米準備step)			
			end if

		case 37
			'mSV7_充填バルブ開B=OFF	
			tim_配米準備_val=#10 '充填バルブ開き時間
			res(tim_配米準備)
			inc(配米準備step)
					
		case 38
			if tim_配米準備.B or 浸漬タンクB米無し then
				inc(配米準備step)
			end if

		case 39
			mSV7_充填バルブ開B=OFF	
			inc(配米準備step)

		case 40
			if (XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B then
				配米準備step=100
			end if


		'-------------------------------------------------------------------------
		'水切り時間
		case 100
			tim_配米準備_val=#20 '水切り時間
			res(tim_配米準備)
			inc(配米準備step)
			
		case 101
			if tim_配米準備.B then
				inc(配米準備step)
			end if
		
		'-------------------------------------------------------------------------
		case 102
			if 浸漬タンクB米無し then
				inc(配米準備step)		
			else 		
				mSV7_充填バルブ開B=ON
				inc(配米準備step)
			end if
			
		case 103
			if 初期充填動作 or ワンサイクルflg then
				tim_配米準備_val=#50 '充填バルブ開時間
				res(tim_配米準備)
			else
				tim_配米準備_val=#20 '充填バルブ開時間
				res(tim_配米準備)			
			end if

			inc(配米準備step)

		case 104
			tim_配米準備_val=#20 '充填バルブ開き時間
			res(tim_配米準備)
			inc(配米準備step)
					
		case 105
			if tim_配米準備.B or 浸漬タンクB米無し then
				inc(配米準備step)
			end if

		case 106
			mSV7_充填バルブ開B=OFF	
			inc(配米準備step)

		case 107
			if (XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B then
				inc(配米準備step)
			end if
		
		'-------------------------------------------------------------------------
		case 108
			tim_配米準備_val=#80 '水切り時間
			res(tim_配米準備)
			inc(配米準備step)

		case 109
			if tim_配米準備.B then
				inc(配米準備step)
			end if


		case 110
			配米準備完了B=ON
			
			if ワンサイクルflg and シャッター開閉step=0 then
				シャッター開閉step=1
			end if
			
			配米準備step=0
			初期充填動作=OFF

		end select


		'===================================================================================================================
		'シャッター開閉
		tmr(tim_シャッター開閉,tim_シャッター開閉_val)
		select case シャッター開閉step
		case 0
		case 1
'			if ワンサイクルflg or 配米準備完了B then
			if ワンサイクルflg or (not(浸漬タンクB米無し) and 配米準備完了B) then
				inc(シャッター開閉step)
			else
					if 浸漬タンクB米無し	then
						配米準備完了B = OFF
						配米完了B = OFF
					end if
				シャッター開閉step=0
			end if
		
		case 2
			mSV9_水切りシャッター開B=ON
			mSV10_水切りシャッター閉B=OFF			
			inc(シャッター開閉step)

		case 3
			if (XSW7_水切りシャッター開B and not(pnlPBXSW7_水切りシャッター開B)) or passXSW7_水切りシャッター開B then
				inc(シャッター開閉step)
			end if

		case 4
			mSV9_水切りシャッター開B=OFF
			tim_シャッター開閉_val=#10 '水切りシャッター開時間
			res(tim_シャッター開閉)				
			inc(シャッター開閉step)
				
		case 5
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if

		case 6
			mSV10_水切りシャッター閉B=ON
			inc(シャッター開閉step)

		case 7
			if (XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B)) or passXSW8_水切りシャッター閉B then
				inc(シャッター開閉step)
			end if

		case 8
			mSV10_水切りシャッター閉B=OFF
			tim_シャッター開閉_val=10	'水切りシャッター閉時間
			res(tim_シャッター開閉)
			inc(シャッター開閉step)

		case 9
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if

		'---------------------------------------------------------------------------------
		'2回目の水切りシャッター

		case 10
			mSV9_水切りシャッター開B=ON
			mSV10_水切りシャッター閉B=OFF
			inc(シャッター開閉step)

		case 11
			if (XSW7_水切りシャッター開B and not(pnlPBXSW7_水切りシャッター開B)) or passXSW7_水切りシャッター開B then
				inc(シャッター開閉step)
			end if

		case 12
			mSV9_水切りシャッター開B=OFF
			tim_シャッター開閉_val=#40 '水切りシャッター開時間
			res(tim_シャッター開閉)				
			inc(シャッター開閉step)
				
		case 13
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if

		case 14
			mSV10_水切りシャッター閉B=ON
			inc(シャッター開閉step)

		case 15
			if (XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B)) or passXSW8_水切りシャッター閉B then
				inc(シャッター開閉step)
			end if

		case 16
			mSV10_水切りシャッター閉B=OFF
			tim_シャッター開閉_val=10	'水切りシャッター閉時間
			res(tim_シャッター開閉)
			inc(シャッター開閉step)

		'---------------------------------------------------------------------------------
		case 17
			if tim_シャッター開閉.B then
				inc(シャッター開閉step)
			end if

		case 18
			配米準備完了B=OFF
			配米完了B=ON
			ワンサイクルflg=OFF
			StageDevice2=ORA(StageDevice2,$400)
			浸漬タンクB排出要求=ON

			inc(DM_B配米現在値)
			
			シャッター開閉step=0

		end select
	'===================================================================================================================
	'【 プロセス処理（配米） 】
	'
	if (not(浸漬タンクB米無し) and 浸漬タンクBユニットAutoMode and 自動搬送AutoMode ) or 浸漬タンクBユニットstep<>0 then

'		if 浸漬タンクB米無し or not(浸漬タンクBユニットAutoMode and 自動搬送AutoMode ) then
		if not(浸漬タンクBユニットAutoMode and 自動搬送AutoMode ) then	'浸漬タンクB米無し or 削除
			浸漬タンクBユニットAutoRun=OFF
		end if

		tmr(tim_procstep,tim_procstep_val)

		select case 浸漬タンクBユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if 浸漬タンクBユニットAutoRun then
				inc(浸漬タンクBユニットstep)
			else
				浸漬タンクBユニット動作中=OFF
				浸漬タンクBユニットstep=0 '終了待機
			end if
		
		case 2
		' [ 浸漬タンク釜数確認 ]
			if not(浸漬タンクB米無し) then
				inc(浸漬タンクBユニットstep)
			else
				浸漬タンクB排出要求=ON
				配米準備完了B=OFF
				配米完了B=OFF
				浸漬タンクBユニットstep=1
			end if
		
		case 3
		' [ ユニット許可検出 ]
			if 浸漬タンクBユニット許可 and (浸漬タンクA米無し or not(浸漬タンクAユニット許可)) then
				'タンク米有
				浸漬タンクBユニット動作中=ON	
				浸漬タンクAユニット動作中=OFF
				inc(浸漬タンクBユニットstep)
			else
				'タンク米無し
				浸漬タンクAユニット動作中=OFF
				浸漬タンクBユニット動作中=OFF
				配米完了B=ON
				浸漬タンクB排出要求=ON
				浸漬タンクBユニットstep=1
			end if
		

		case 4
			if 配米準備完了B then
				inc(浸漬タンクBユニットstep)
			else 
				if 配米準備step=0 then
					配米準備step=1
					浸漬タンクBユニットstep=1
				else
					浸漬タンクB排出要求=ON
					浸漬タンクBユニットstep=1				
				end if
			end if

		case 5
			if 配米完了B then
				浸漬タンクBユニットStatusMsg=#14	'	配米完了
				浸漬タンクB排出要求=ON
				浸漬タンクBユニットstep=1
			else
				inc(浸漬タンクBユニットstep)
			end if

			'---------------------------------------------------------------------------------
		case 6
		' [ 蓋カマ移動停止確認 ]
			if 浸漬タンクB排出要求=OFF and  搬送コンベアA動作中=OFF then

				'[ 自ステージに"釜"有検出 ]
					if PH3_釜検知 and PH4_フタ検知 and not(配米インターバル禁止) then
						if ANDA(StageDevice2,$200)=0 and ANDA(StageDevice2,$400)=0 then
						'if ANDA(StageDevice2,$100)=$100 and ANDA(StageDevice2,$200)=0 and ANDA(StageDevice2,$400)=0 then
							if not(配米完了B) and シャッター開閉step=0 then
								シャッター開閉step=1
							end if
						else
							浸漬タンクB排出要求=ON
						end if

						浸漬タンクBユニットstep=1					
											
						
				'[ 自ステージに"フタ"有検出 ]	
					else if not(PH3_釜検知) and PH4_フタ検知 then 
						浸漬タンクB排出要求=ON
						浸漬タンクBユニットstep=1
				
				'[ 自ステージに"釜フタ"なし ]
					else
						浸漬タンクB排出要求=ON
						浸漬タンクBユニットstep=1
					end if
			
			else
				
				浸漬タンクBユニットstep=1
			
			end if
		
		end select

	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		if 浸漬タンクBユニットstep=0 and 浸漬タンクB米無し then
			浸漬タンクB排出要求=ON
		end if

		浸漬タンクBユニットAutoRun=OFF
		
		浸漬タンクBユニットstep=0 '終了
		配米準備完了B=OFF
		配米完了B=OFF
		
		if 浸漬タンクBユニットstep=0 and 配米準備step=0 and シャッター開閉step=0 then
			if not(浸漬タンクBユニットAutoMode and 自動搬送AutoMode ) then
				'-------------------------------------------------------------
				'充填１サイクル
				if ldp(PB13_自動配米B) and ワンサイクルflg=OFF then
					if ((XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B) and ((XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B)) or passXSW8_水切りシャッター閉B) then
						mSV7_充填バルブ開B=OFF
						mSV9_水切りシャッター開B=OFF
						mSV10_水切りシャッター閉B=OFF			
						ワンサイクルflg=ON
						配米準備step=1
				
					end if
				end if
				'-------------------------------------------------------------				
				if ldp(pnlPBSV7_充填バルブ開B ) then
					if (XSW6_充填バルブ閉B and not(pnlPBXSW6_充填バルブ閉B)) or passXSW6_充填バルブ閉B then
						mSV7_充填バルブ開B=ON						
					else if (XSW5_充填バルブ開B and not(pnlPBXSW5_充填バルブ開B)) or passXSW5_充填バルブ開B then
						mSV7_充填バルブ開B=OFF
					end if
				end if
				
			end if
			'-------------------------------------------------------------
			'パネルスイッチでの開閉
			if ldp(pnlPBSV9_水切りシャッター開B) then
					mSV9_水切りシャッター開B=ON
					mSV10_水切りシャッター閉B=OFF
					tPBL12_水切りシャッターB=ON
					
					StageDevice1=ORA(StageDevice1,$400)
					StageDevice2=ORA(StageDevice2,$400)

			else if ldp(pnlPBSV10_水切りシャッター閉B) then
					mSV9_水切りシャッター開B=OFF
					mSV10_水切りシャッター閉B=ON
					tPBL12_水切りシャッターB=OFF
			end if
			
			if mSV10_水切りシャッター閉B and ( (XSW8_水切りシャッター閉B and not(pnlPBXSW8_水切りシャッター閉B)) or passXSW8_水切りシャッター閉B) then
				mSV10_水切りシャッター閉B=OFF
			end if
			if mSV9_水切りシャッター開B and ( (XSW7_水切りシャッター開B and not(pnlPBXSW7_水切りシャッター開B)) or passXSW7_水切りシャッター開B) then
				mSV9_水切りシャッター開B=OFF
			end if
			

		end if

		'-------------------------------------------------------------
		
	
	end if '浸漬タンクBユニットAutoMode and not(浸漬タンクBユニットOrgErrStep)
	'===================================================================================================================
	'【 浸漬タンクBユニットOrgErr処理 】
	else
		if ResetFlg then
			浸漬タンクBユニットOrgErr=OFF
		end if		

	end if
	
	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
	
		浸漬タンクBユニットErr=ON

		select case 浸漬タンクBユニットErrStep
		case 0
		case 1
			mSV7_充填バルブ開B=OFF
			'mSV8_充填バルブ閉B=ON
			
			if ResetFlg then
				almXSW5_充填バルブ開B=OFF
				almXSW6_充填バルブ閉B=OFF
				almXSW7_水切りシャッター開B=OFF
				almXSW8_水切りシャッター閉B=OFF

				inc(浸漬タンクBユニットErrStep)
			end if
		case 2
			mSV7_充填バルブ開B=OFF
			'mSV8_充填バルブ閉B=OFF

			浸漬タンクBユニットErr=OFF

			res(tim_XSW5_充填バルブ開B.B)
			res(tim_XSW6_充填バルブ閉B.B)
			res(tim_XSW7_水切りシャッター開B.B) 
			res(tim_XSW8_水切りシャッター閉B.B)
			
			res(tim_notXSW5_充填バルブ開B.B)
			res(tim_notXSW6_充填バルブ閉B.B)
			res(tim_notXSW7_水切りシャッター開B.B) 
			res(tim_notXSW8_水切りシャッター閉B.B)
			
			浸漬タンクBユニットErrStep=0
		end select

	end if 'if 浸漬タンクBユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else


	select case 浸漬タンクBユニットEmgStep
	case 0
	
	case 1
		浸漬タンクBユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (not(浸漬タンクB米無し) and 浸漬タンクBユニットAutoMode and 自動搬送AutoMode ) or 浸漬タンクBユニットstep<>0 then
			'---------------------------------
			'緊急停止処理(自動 ワンサイクル)		
			'---------------------------------
			pauseSV7_充填バルブ開B=ON
			'eject2SV8_充填バルブ閉B=ON
			pauseSV9_水切りシャッター開B=ON
			ejectSV10_水切りシャッター閉B=ON
			pauseSV62_排水バルブ開B=ON
			'eject2SV63_排水バルブ閉B=ON

			if not(ejectSV11_給水電磁弁B) then
				pauseSV11_給水電磁弁B=ON
			end if
			
			if timstack=OFF then
				tim_procstep_stack=tim_procstep.U
				tim_シャッター開閉_stack=tim_シャッター開閉.U
				tim_配米準備_stack=tim_配米準備.U
				timstack=ON
			end if

			'---------------------------------
		else
			'---------------------------------
			'緊急停止処理(手動）		
			'---------------------------------
			mSV7_充填バルブ開B=OFF
			mSV9_水切りシャッター開B=OFF
			mSV10_水切りシャッター閉B=ON '→Reset解除
			mSV62_排水バルブ開B=OFF
			mSV11_給水電磁弁B=OFF
			'---------------------------------
		end if
		
		'---------------------------------
		inc(浸漬タンクBユニットEmgStep)
	case 2
		if ResetFlg then
			inc(浸漬タンクBユニットEmgStep)
		end if
	case 3
		if (not(浸漬タンクB米無し) and 浸漬タンクBユニットAutoMode and 自動搬送AutoMode ) or 浸漬タンクBユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				pauseSV7_充填バルブ開B=OFF
				'eject2SV8_充填バルブ閉B=OFF
				pauseSV9_水切りシャッター開B=OFF
				ejectSV10_水切りシャッター閉B=OFF
				pauseSV62_排水バルブ開B=OFF
				'eject2SV63_排水バルブ閉B=OFF
				pauseSV11_給水電磁弁B=OFF
				
				tim_procstep.U=tim_procstep_stack
				tim_シャッター開閉.U=tim_シャッター開閉_stack
				tim_配米準備.U=tim_配米準備_stack
				
				'---------------------------------
				inc(浸漬タンクBユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------	
			mSV10_水切りシャッター閉B=OFF
			'---------------------------------
			inc(浸漬タンクBユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		浸漬タンクBユニットEmgStep=0
		浸漬タンクBユニットEmg=OFF
	end select
		
end if 'if 浸漬タンクBユニットEmgStep=0 then
