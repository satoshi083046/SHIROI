'ほぐし機Aユニット
'===================================================================================================================
'
'<<<<<<<	ユニット	>>>>>>>>
'
'===================================================================================================================
'
'	ほぐし機Aユニット
'	
'===================================================================================================================

'【 初期化処理 】
if CR2008 then
    ほぐし機AユニットAutoMode=ON '常に自動搬送AutoMode ONLINE、OFFLINEなし
    ほぐし機AユニットAutoRun=OFF
    ほぐし機Aユニット許可=ON
    ほぐし機AユニットOrgErr=OFF
    ほぐし機AユニットErr=OFF
    ほぐし機AユニットEmg=OFF
    ほぐし機Aユニットstep=0
    ほぐし機AユニットErrStep=0
    ほぐし機AユニットOrgErrStep=0
    ほぐし機AユニットEmgStep=0
	
end if
'===================================================================================================================
'【 原点 】
ほぐし機AユニットOrg=(反転ほぐし機A禁止 or 釜搬入可能信号_A) and ( (反転ほぐし釜供給中A and PH31_釜検知) or (not(反転ほぐし釜供給中A) and not(PH31_釜検知)) )

'===================================================================================================================
'【 緊急停止 】

if not(PB非常停止) then
	ほぐし機AユニットEmg=ON
	ほぐし機AユニットEmgStep=1
end if

'===================================================================================================================
if 自動搬送AutoRun then '運転中
	if ldp(pnlPB反転機停止指令_A) then
		if not(反転ほぐし機A禁止) then
			反転ほぐし機A禁止=ON
		else if 反転ほぐし機A禁止 and 釜搬入可能信号_A then '運転中は条件付き
			反転ほぐし機A禁止=OFF
		end if
	end if
	'-- 強制反転A ON で 反転ほぐし機A禁止=OFF
	'-- 反転ほぐし機A禁止=ON で 強制反転A=OFF  
	if ldp(強制反転A) then
		反転ほぐし機A禁止=OFF
	else if ldp(反転ほぐし機A禁止) then
		強制反転A=OFF
	end if
else 
	if ldp(pnlPB反転機停止指令_A) then
		if not(反転ほぐし機A禁止) then
			反転ほぐし機A禁止=ON
		else if 反転ほぐし機A禁止 then '停止中は条件なし
			反転ほぐし機A禁止=OFF
		end if
	end if
	'-- 強制反転A ON で 反転ほぐし機A禁止=OFF
	'-- 反転ほぐし機A禁止=ON で 強制反転A=OFF  
	if ldp(強制反転A) then
		反転ほぐし機A禁止=OFF
	else if ldp(反転ほぐし機A禁止) then 
		強制反転A=OFF
	end if
end if

'===================================================================================================================
'【 タイムエラー検出および計測エラー検出】

if not(反転ほぐし機A禁止) and 反転機異常信号_A then
	alm反転機異常信号_A=ON
	ほぐし機AユニットErrStep=1
end if

'===================================================================================================================
'【 System条件 】
'次のフラグはリードコマンド（書き換え不可）
'System ::  ほぐし機AユニットAutoMode	自動モード セレクトスイッチ
'System ::  ほぐし機AユニットAutoRun	継続運転可能
'System :: 浸漬Aユニット許可 該当ユニット動作可能 
'System ::  ほぐし機AユニットEmg	その場停止


if  ほぐし機AユニットEmgStep=0 then  
	
	if ほぐし機AユニットErrStep=0  then

	if not(ほぐし機AユニットOrgErr) then

	if  (ほぐし機AユニットAutoMode and 自動搬送AutoMode ) or ほぐし機Aユニットstep<>0 then
	
		if not(ほぐし機AユニットAutoMode and 自動搬送AutoMode ) then
			ほぐし機AユニットAutoRun=OFF
		end if
		

	'===================================================================================================================
	'【 プロセス処理 】
	'
		tmr(tim_procstep,tim_procstep_val)

		select case ほぐし機Aユニットstep
		'--------------------------------------------------------------------------------------------------------------
		case 0	' 終了待機
		'--------------------------------------------------------------------------------------------------------------
		case 1	' 実行
		'--------------------------------------------------------------------------------------------------------------
		' 作業工程を振り分ける
		'--------------------------------------------------------------------------------------------------------------
		' [ 自動継続運転 ]
			if  ほぐし機AユニットAutoRun and 自動搬送AutoRun then
				inc(ほぐし機Aユニットstep)
			else 
				ほぐし機Aユニットstep=0 '終了待機
			end if
				
		case 2
			'ほぐし機が停止中に受付
			if 反転ほぐし機A禁止 then
				inc(ほぐし機Aユニットstep)			
			
			else if 電源確認リレー_A and 釜搬入可能信号_A then
				inc(ほぐし機Aユニットstep)
			
			else			
				ほぐし機Aユニットstep=1
			end if
			
		
		case 3
			if ほぐし機Aユニット完了 then
				if PH31_釜検知 then
					ほぐし機A排出要求=ON
					ほぐし機Aユニットstep=1
				else
					inc(ほぐし機Aユニットstep)
				end if
			else
				inc(ほぐし機Aユニットstep)
			end if

		case 4
			if 反転ほぐし釜供給中A and not(ほぐし機A排出要求) and not(ほぐし機Aユニット完了) then
				inc(ほぐし機Aユニットstep)
			else 
				ほぐし機Aユニットstep=1
			end if
	
		case 5
			if 反転ほぐし機A禁止 then
				inc(ほぐし機Aユニットstep)			

			else if ほぐし機Aユニット許可 then
				inc(ほぐし機Aユニットstep)
			else
				ほぐし機A排出要求=ON
				ほぐし機Aユニット完了=ON
				ほぐし機Aユニットstep=1
			end if

		case 6
			if 反転ほぐし機A禁止 then
				inc(ほぐし機Aユニットstep)			

			else if (強制反転A or  ANDA(StageDevice22,$1000)=$1000 ) and PH31_釜検知 then
				反転機運転指令_A=ON '--指令ON
				tim_procstep_val=5 '200mSec出力
				res(tim_procstep)
				inc(ほぐし機Aユニットstep)
			else
				ほぐし機A排出要求=ON
				ほぐし機Aユニット完了=ON
				ほぐし機Aユニットstep=1
			end if
		
		case 7
			if 反転ほぐし機A禁止 then
				inc(ほぐし機Aユニットstep)			

			else if tim_procstep.B then
				INC(DM_排出総数)
				反転機運転指令_A=OFF '--指令OFF
				inc(ほぐし機Aユニットstep)
			end if
		
		case 8
			if 反転ほぐし機A禁止 then
				inc(ほぐし機Aユニットstep)			

			else if not(反転機反転完了信号_A) or 釜搬入可能信号_A then
				tim_procstep_val=10
				res(tim_procstep)
				inc(ほぐし機Aユニットstep)			
			end if
		
		case 9
			if 反転ほぐし機A禁止 then
				inc(ほぐし機Aユニットstep)			
			
			else if tim_procstep.B then
				if 反転機反転完了信号_A or 釜搬入可能信号_A then
					inc(ほぐし機Aユニットstep)			
				end if
			end if
			
		case 10
			ほぐし機A排出要求=ON
			ほぐし機Aユニット完了=ON
			ほぐし機Aユニットstep=1

		
		end select
		
	'===================================================================================================================
	'【 手動スイッチマニュアル操作 】
	'  マニュアルスイッチ操作はタイムエラーを発生させない
	else 
		 ほぐし機AユニットAutoRun=OFF	
		ほぐし機Aユニットstep=0 '終了

	
	end if ' ほぐし機AユニットAutoMode and not(ほぐし機AユニットOrgErrStep)

	'===================================================================================================================
	'【 ほぐし機AユニットOrgErr処理 】
	else
	
		if ResetFlg then
			ほぐし機AユニットOrgErr=OFF
		end if
	
	end if

	'===================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
		ほぐし機AユニットErr=ON
		
		select case ほぐし機AユニットErrStep
		case 0
		case 1
			if ResetFlg then
				alm反転機異常信号_A=OFF
				inc(ほぐし機AユニットErrStep)
			end if
		case 2
			ほぐし機Aユニットstep=0		
			
			ほぐし機AユニットErr=OFF			
			ほぐし機AユニットErrStep=0
		end select
		
	end if 'if ほぐし機AユニットErrStep=0 then
	
	'===================================================================================================================
	'【 非常停止処理（その場停止） 】
else

	select case ほぐし機AユニットEmgStep
	case 0
	
	case 1
		ほぐし機AユニットAutoRun=OFF
		'---------------------------------
		'緊急停止処理		
		'---------------------------------
		if (ほぐし機AユニットAutoMode and 自動搬送AutoMode ) or ほぐし機Aユニットstep<>0 then

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
		inc(ほぐし機AユニットEmgStep)
	case 2
		if ResetFlg then
			alm反転機異常信号_A=OFF
			alm電源確認リレー_A=OFF
			inc(ほぐし機AユニットEmgStep)
		end if
		
	case 3
		if (ほぐし機AユニットAutoMode and 自動搬送AutoMode ) or ほぐし機Aユニットstep<>0 then
			if StartFlg then
				'---------------------------------
				'緊急停止解除(自動  ワンサイクル)
				'---------------------------------
				tim_procstep.U=tim_procstep_stack
				'---------------------------------
				inc(ほぐし機AユニットEmgStep)
			end if
		else
			'---------------------------------
			'緊急停止解除(手動)
			'---------------------------------
			
			
			
			'---------------------------------
			inc(ほぐし機AユニットEmgStep)		
		end if				
	case 4
		timstack=OFF
		ほぐし機AユニットEmgStep=0
		ほぐし機AユニットEmg=OFF
	end select
	
end if 'if  ほぐし機AユニットEmgStep=0 then
