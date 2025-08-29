'ほぐし機Bユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	ほぐし機Bユニット
'	
'===================================================================================================================

'【 初期化処理 】
if CR2008 then
    ほぐし機BユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
   	ほぐし機BユニットAutoRun=OFF
    ほぐし機Bユニット許可=ON
    ほぐし機BユニットOrgErr=OFF
    ほぐし機BユニットErr=OFF
    ほぐし機BユニットEmg=OFF
    ほぐし機Bユニットstep=0
    ほぐし機BユニットErrStep=0
    ほぐし機BユニットOrgErrStep=0
    ほぐし機BユニットEmgStep=0
	
end if
'===================================================================================================================
'【 原点 】
ほぐし機BユニットOrg= (反転ほぐし機B禁止 or 釜搬入可能信号_B) and ( (反転ほぐし釜供給中B and PH38_釜検知) or (not(反転ほぐし釜供給中B) and not(PH38_釜検知)) ) 

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	ほぐし機BユニットEmg=ON
	ほぐし機BユニットEmgStep=1
end if
'===================================================================================================================
if 自動搬送AutoRun then
	if ldp(pnlPB反転機停止指令_B) then
		if not(反転ほぐし機B禁止) then
			反転ほぐし機B禁止=ON
		else if 反転ほぐし機B禁止 and 釜搬入可能信号_B then
			反転ほぐし機B禁止=OFF
		end if
	end if

	if ldp(強制反転B) then
		反転ほぐし機B禁止=OFF
	else if ldp(反転ほぐし機B禁止) then
		強制反転B=OFF
	end if
else
	if ldp(pnlPB反転機停止指令_B) then
		if not(反転ほぐし機B禁止) then
			反転ほぐし機B禁止=ON
		else if 反転ほぐし機B禁止 then
			反転ほぐし機B禁止=OFF
		end if
	end if

	if ldp(強制反転B) then
		反転ほぐし機B禁止=OFF
	else if ldp(反転ほぐし機B禁止) then
		強制反転B=OFF
	end if

end if
'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】


if not(反転ほぐし機B禁止) and 反転機異常信号_B then
	alm反転機異常信号_B=ON
	ほぐし機BユニットErrStep=1
end if


'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System :: ほぐし機BユニットAutoMode	自動モード セレクトスイッチ
'System :: ほぐし機BユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System :: ほぐし機BユニットEmg	その場停止


if ほぐし機BユニットEmgStep=0 then  
	
	if ほぐし機BユニットErrStep=0  then

	if not(ほぐし機BユニットOrgErr) then

	if (ほぐし機BユニットAutoMode and 自動搬送AutoMode ) or ほぐし機Bユニットstep<>0 then
	
		if not(ほぐし機BユニットAutoMode and 自動搬送AutoMode ) then
			ほぐし機BユニットAutoRun=OFF
		end if

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ほぐし機Bユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if ほぐし機BユニットAutoRun and 自動搬送AutoRun then
				inc(ほぐし機Bユニットstep)
			else 
				ほぐし機Bユニットstep=0 '終了待機
			end if
		
		case 2
			'ほぐし機が停止中に受付
			if 反転ほぐし機B禁止 then
				inc(ほぐし機Bユニットstep)			
			
			else if 電源確認リレー_B and 釜搬入可能信号_B then
				inc(ほぐし機Bユニットstep)
			else			
				ほぐし機Bユニットstep=1
			end if

		case 3
			if ほぐし機Bユニット完了 then
				if PH38_釜検知 then
					ほぐし機B排出要求=ON
					ほぐし機Bユニットstep=1
				else
					inc(ほぐし機Bユニットstep)
				end if
			else
				inc(ほぐし機Bユニットstep)
			end if

		case 4
			if 反転ほぐし釜供給中B and not(ほぐし機B排出要求) and not(ほぐし機Bユニット完了) then
				inc(ほぐし機Bユニットstep)
			else
				ほぐし機Bユニットstep=1				
			end if

		case 5
			if 反転ほぐし機B禁止 then
				inc(ほぐし機Bユニットstep)			
			
			else if ほぐし機Bユニット許可 then
				inc(ほぐし機Bユニットstep)
			else
				ほぐし機B排出要求=ON
				ほぐし機Bユニット完了=ON
				ほぐし機Bユニットstep=1
			end if

		case 6
			if 反転ほぐし機B禁止 then
				inc(ほぐし機Bユニットstep)			
			
			else if (強制反転B or  ANDA(StageDevice26,$1000)=$1000) and PH38_釜検知 then
				反転機運転指令_B=ON '--指令ON
				tim_procstep_val=5 '200mSec出力
				res(tim_procstep)
				inc(ほぐし機Bユニットstep)
			else
				ほぐし機B排出要求=ON
				ほぐし機Bユニット完了=ON
				ほぐし機Bユニットstep=1
			end if
		
		case 7
			if 反転ほぐし機B禁止 then
				inc(ほぐし機Bユニットstep)			
			
			else if tim_procstep.B then
				INC(DM_排出総数)
				反転機運転指令_B=OFF
				inc(ほぐし機Bユニットstep)
			end if
		
		case 8
			if 反転ほぐし機B禁止 then
				inc(ほぐし機Bユニットstep)			
			
			else if not(反転機反転完了信号_B) or 釜搬入可能信号_B then
				tim_procstep_val=10
				res(tim_procstep)
				inc(ほぐし機Bユニットstep)			
			end if
		
		case 9
			if 反転ほぐし機B禁止 then
				inc(ほぐし機Bユニットstep)			
			
			else if tim_procstep.B then
				if 反転機反転完了信号_B or 釜搬入可能信号_B then
					inc(ほぐし機Bユニットstep)			
				end if
			end if
			
		case 10
			ほぐし機B排出要求=ON
			ほぐし機Bユニット完了=ON
			ほぐし機Bユニットstep=1
			
		
		end select
		
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		ほぐし機BユニットAutoRun=OFF
		
		ほぐし機Bユニットstep=0 '終了	
	
	
	end if 'ほぐし機BユニットAutoMode and not(ほぐし機BユニットOrgErrStep)

	'===================================================================================================================
	'【 ほぐし機BユニットOrgErr処理 】
	else

		if ResetFlg then
			ほぐし機BユニットOrgErr=OFF
		end if

	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		ほぐし機BユニットErr=ON
		
		select case ほぐし機BユニットErrStep
		case 0
		case 1
			if ResetFlg then
				alm反転機異常信号_B=OFF
				inc(ほぐし機BユニットErrStep)
			end if
		case 2
			ほぐし機Bユニットstep=0

			ほぐし機BユニットErr=OFF
			ほぐし機BユニットErrStep=0
		end select


	end if 'if ほぐし機BユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case ほぐし機BユニットEmgStep
	case 0
	
	case 1
		ほぐし機BユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (ほぐし機BユニットAutoMode and 自動搬送AutoMode ) or ほぐし機Bユニットstep<>0 then

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

			'---------------------------------
		end if
		
		'---------------------------------
		inc(ほぐし機BユニットEmgStep)
	case 2
		if ResetFlg then
			alm反転機異常信号_B=OFF
			alm電源確認リレー_B=OFF
			inc(ほぐし機BユニットEmgStep)
		end if
	case 3
		if (ほぐし機BユニットAutoMode and 自動搬送AutoMode ) or ほぐし機Bユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(ほぐし機BユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(ほぐし機BユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		ほぐし機Bユニットstep=1
		
		ほぐし機BユニットEmgStep=0
		ほぐし機BユニットEmg=OFF
	end select
		
end if 'if ほぐし機BユニットEmgStep=0 then
