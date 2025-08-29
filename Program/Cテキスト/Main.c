'Main
'===================================================================================================================
'
'<<<<<<<	Main操作部	>>>>>>>>
'
'===================================================================================================================
'-------------------------------------------------------------------------------------------------------------------
'
'	●号機名称
'
'  192.168.4.10	
'	+----[攪拌]-[フタ被せ]- <炊飯>---[フタ取り][検知][バキューム]---[ほぐしA]
'   |                                     		                  |
'	+---[注水]--[B槽]--[A槽] - [洗浄機] ----------------------------[ほぐしB]
'
'-------------------------------------------------------------------------------------------------------------------
' 禁止項目
'	配米A禁止、配米B禁止、加水禁止、ならし禁止、フタ被せ禁止、フタ取禁止、
'
'-------------------------------------------------------------------------------------------------------------------
'【前処理工程】
'	前処理
'		注水			DM_Aタンク設定値 > 0
'		送米			DM_Aタンク送米現在値 < DM_Aタンク設定値
'
'		貯米カウント 	DM_浸漬タンクA貯米釜数=DM_Aタンク送米現在値 - DM_A配米現在値
'
'		手動・浸漬タンク排水 and 米無し 	DM_Aタンク送米現在値=0 DM_浸漬タンクA貯米釜数=0
'
'	搬送コンベア運転
'
'		加水釜数現在値>=加水釜数設定値
'			*炊飯器に着火するタイミング
'		配米準備釜数現在値>=配米準備釜数設定値 and  ldp(PB22_自動運転 and 自動搬送AutoMode)  DM_A配米現在値=0
'			*配米準備釜数：配米可能な洗浄された釜
'
'		配米			DM_浸漬タンクA貯米釜数>0
'		配米終了		DM_A配米設定値=0 or DM_A配米現在値>=DM_A配米設定値 or 米無し
'
'		消火警告までの残釜数>=消火警告までの残釜数設定値
'
'		DM_排出残数=0
'			*自動終了タイミング(炊飯された釜が洗浄終了されるタイミング)
'
'-------------------------------------------------------------------------------------------------------------------
'デバックモニター
'
DM_計量現在値.U=CNT_計量現在値.U

DM_Aタンク設定値=DM_Aタンク設定値
DM_Aタンク送米現在値=DM_Aタンク送米現在値
DM_Aタンク送米現在値残数=DM_Aタンク設定値-DM_Aタンク送米現在値
if DM_Aタンク送米現在値残数<0 then
	DM_Aタンク送米現在値残数=0
end if
DM_浸漬タンクA貯米釜数=DM_浸漬タンクA貯米釜数
DM_A配米設定値=DM_Aタンク設定値+DM_Aタンク補正値 'DM_Aタンク補正値 (初期値=5)
DM_A配米現在値=DM_A配米現在値
DM_A配米現在値残数=DM_A配米設定値-DM_A配米現在値
if DM_A配米現在値残数<0 then
	DM_A配米現在値残数=0
end if


	if DM_A配米現在値=0 then
		配米現在値Aグラフ=0
	else if DM_A配米現在値>=DM_Aタンク設定値 then
		配米現在値Aグラフ=100
	else
		配米現在値Aグラフ=(DM_A配米現在値*100)/ DM_Aタンク設定値
	end if


'
DM_Bタンク設定値=DM_Bタンク設定値
DM_Bタンク送米現在値=DM_Bタンク送米現在値
DM_Bタンク送米現在値残数=DM_Bタンク設定値-DM_Bタンク送米現在値
if DM_Bタンク送米現在値残数<0 then
	DM_Bタンク送米現在値残数=0
end if
DM_浸漬タンクB貯米釜数=DM_浸漬タンクB貯米釜数
DM_B配米設定値=DM_Bタンク設定値+DM_Bタンク補正値 'DM_Bタンク補正値 (初期値=5)
DM_B配米現在値=DM_B配米現在値


	if DM_B配米現在値=0 then
		配米現在値Bグラフ=0
	else if DM_B配米現在値 >= DM_Bタンク設定値 then
		配米現在値Bグラフ=100
	else
		配米現在値Bグラフ= (DM_B配米現在値*100) / DM_Bタンク設定値
	end if


DM_B配米現在値残数=DM_B配米設定値-DM_B配米現在値
if DM_B配米現在値残数<0 then
	DM_B配米現在値残数=0
end if

DM_配米総数設定値=DM_Aタンク設定値+DM_Bタンク設定値
DM_配米総数=DM_A配米現在値+DM_B配米現在値
DM_排出残数=DM_配米総数-DM_排出総数
if DM_排出残数<0 or (DM_排出残数>=0 and pnlPB排出残数リセット) then
	DM_排出総数=DM_配米総数
	DM_排出残数=0	
end if

	if DM_排出総数=0 then
		反転釜現在値グラフ=0
		反転釜残数グラフ=0
	else if DM_排出総数>=DM_配米総数 then
		反転釜現在値グラフ=100
		反転釜残数グラフ=0
	else
		反転釜現在値グラフ=(DM_排出総数*100) / DM_配米総数
		反転釜残数グラフ=100-((DM_排出総数*100) / DM_配米総数)
	end if


運転準備中=運転準備中
運転準備完了=運転準備完了


加水釜数設定値=加水釜数設定値 '(初期値=25) 
加水釜数現在値=加水釜数現在値
加水釜数現在値残数=加水釜数設定値-加水釜数現在値
if 加水釜数現在値残数<0 then
	加水釜数現在値残数=0
end if

配米準備釜数設定値=配米準備釜数設定値 '(初期値=5)
配米準備釜数現在値=配米準備釜数現在値
配米準備釜数現在値残数=配米準備釜数設定値-配米準備釜数現在値
if 配米準備釜数現在値残数<0 then
	配米準備釜数現在値残数=0
end if

消火警告までの残釜数設定値=消火警告までの残釜数設定値 '(初期値=30)
消火警告までの残釜数=消火警告までの残釜数
消火警告までの残釜数残数=消火警告までの残釜数設定値-消火警告までの残釜数
if 消火警告までの残釜数残数<0 then
	消火警告までの残釜数残数=0
end if

配米終了フラグ=配米終了フラグ


'-------------------------------------------------------------------------------------------------------------------
'	<<< 川崎南仕様  フロー案B	>>> 
'-------------------------------------------------------------------------------------------------------------------
'
'操作概要
'運転開始から停止までのフロー

'===================================================================================================================
'【 初期化処理 】
'-------------------------------------------------------
if CR2008 then '電源ON時初期化処理
	if PB34_リセット then

		加水釜数現在値=0
		配米準備釜数現在値=0
		DM_A配米現在値=0
		DM_B配米現在値=0
		DM_排出総数=0
		
		消火警告までの残釜数=0
		空釜搬送釜数=0
		釜カウントA=0
		釜カウントB=0
				
		運転準備中=OFF
		配米待機中=OFF
		運転準備完了=OFF
		
		自動停止=OFF
		IND_自動停止可能=OFF
		
		インターバル給水中=OFF
	
	end if
	
end if

'-------------------------------------------------------
if ldp(テスト運転) then 'テスト運転立ち上がり ↑
	浸漬タンクAユニット許可=OFF
	浸漬タンクBユニット許可=OFF
	洗浄タンクAutoMode=ON
	洗浄タンクAutoRun=ON
	すすぎ禁止=ON

else if ldf(テスト運転) then  'テスト運転立下り ↓
		洗浄タンクAutoMode=OFF
		洗浄タンクAutoRun=OFF
		すすぎ禁止=OFF
end if

'-------------------------------------------------------
if ldp(炊飯機点火実行確認【済】) then
	IND_炊飯中=ON
end if

if ldp(炊飯機消火警告【済】) then
	IND_炊飯中=OFF
end if


'-------------------------------------------------------
'各工程処理 
if テスト運転 then
	自動停止=OFF
	IND_自動停止可能=OFF
end if

if not(テスト運転) then

'--運転準備中
if 運転準備中 then
	if Main手順初期化 then
		Main手順初期化=OFF
		
		tmsg運転準備開始確認=OFF
		tmsg運転準備開始確認消去=OFF
		
		tmsg運転準備完了=OFF
		tmsg運転準備完了消去=OFF
		
	end if

	IND_配米準備=ON
	IND_配米中=OFF
	IND_炊飯中=OFF
	IND_炊飯完了=OFF
	IND_停止待機=OFF

	
	浸漬タンクAユニット許可=OFF
	浸漬タンクBユニット許可=OFF
	
	if 炊飯機点火実行確認【済】 then

		tmsg運転準備開始確認=OFF
		tmsg運転準備開始確認消去=ON		
		'洗浄タンク=ON

		if 自動搬送AutoMode and 自動搬送AutoRun then
			洗浄タンクAutoMode=ON
			洗浄タンクAutoRun=ON
		end if

		tmsg炊飯機点火実行警告=OFF


		if 配米準備釜数現在値>=配米準備釜数設定値 or 洗浄搬送禁止 then '加水釜を炊飯機に搬送済み
			運転準備中=OFF
			配米待機中=ON
			運転準備完了=OFF

			tmsg運転準備完了=ON
			tmsg運転準備完了消去=OFF
			
			MainStatusMsg=#110
		
		end if
		

	else if 運転準備開始確認【済】 then '洗浄タンクAutoRun済み

		'洗浄タンク=ON
		tmsg運転準備開始確認=OFF
		tmsg運転準備開始確認消去=ON
		
		if 自動搬送AutoMode and 自動搬送AutoRun then
			洗浄タンクAutoMode=ON
			洗浄タンクAutoRun=ON
		end if
	
		if 加水釜数現在値>=加水釜数設定値 then
			tmsg炊飯機点火実行警告=ON
		end if
		
		if pnlPBOK then
			炊飯機点火実行確認【済】=ON
			tmsg炊飯機点火実行警告=OFF

			配米準備釜数現在値=0
		end if				

	else
	
		メインTP_切替ページＮｏ=22
		tmsg運転準備開始確認=ON
		tmsg運転準備開始確認消去=OFF


		if ldp(PB22_自動運転 and 自動搬送AutoMode) and PB23_自動停止  then 'and 自動搬送AutoRun then

			'洗浄タンク=ON
			運転準備開始確認【済】=ON
			tmsg運転準備開始確認=OFF
			tmsg運転準備開始確認消去=ON
			
			洗浄タンクAutoMode=ON
			洗浄タンクAutoRun=ON

		end if
	
	end if
	
	

'--配米待機中
else if 配米待機中 then

		運転準備中=OFF
		配米待機中=ON
		運転準備完了=OFF
	
		if 自動搬送AutoMode then
			tmsg運転準備完了=ON
			tmsg運転準備完了消去=OFF
		else 
			tmsg運転準備完了=OFF
			tmsg運転準備完了消去=ON
		end if	
		
		if 自動搬送AutoMode and 自動搬送AutoRun then
			洗浄タンクAutoMode=ON
			洗浄タンクAutoRun=ON
		end if

		IND_配米中=CR2006

		if 自動搬送AutoMode and (ldp(pnlPBOK) or ldp(pnlPB配米中)) then 'and 自動搬送AutoRun then

			運転準備中=OFF
			配米待機中=OFF
			運転準備完了=ON			
			
			炊飯機消火警告【済】=OFF
			炊飯完了停止【済】=OFF
			配米終了フラグ=OFF

			'-------------------------------------------------------
			'データクリア
			'-------------------------------------------------------			
			DM_A配米現在値=0
			DM_B配米現在値=0
			DM_排出総数=0
			
			'tmsgxxxx=OFF
			tmsg運転準備開始確認=OFF
			tmsg運転準備開始確認消去=ON
			
			tmsg炊飯機点火実行警告=OFF

			tmsg運転準備完了=OFF
			tmsg運転準備完了消去=ON

			tmsg炊飯機消火警告表示=OFF
			tmsg炊飯機消火警告消去=ON
			
			tmsg炊飯完了表示=OFF '炊飯完了通知
			tmsg炊飯完了消去=ON '炊飯完了通知

			'-------------------------------------------------------
			StageDevice37=0 '釜反転位置(反転位置）
			StageDevice38=0 'リフト位置
			StageDevice0=0 '【搬送口】 搬送コンベアA MC6
			StageDevice1=0 '【浸漬タンクA】 搬送コンベアA MC6-MC7
			StageDevice2=0 '【浸漬タンクB】 搬送コンベアA MC7
			StageDevice3=0 '【注水】 搬送コンベアA MC7－MC8
			StageDevice4=0 '【リフト位置】 搬送コンベアA MC8－MC9
			StageDevice5=0 '【待機位置1】 搬送コンベアB MC9－MC12
			StageDevice6=0 '【待機位置2】 搬送コンベアB MC12－MC13
			StageDevice7=0 '【リフト位置】 搬送コンベアB MC13－MC16
			StageDevice8=0 '【ならし位置】 搬送コンベアC MC16－MC14
			StageDevice9=0 '【フタ被せ位置】 搬送コンベアC MC14－MC15
			'-------------------------------------------------------

			運転初期化=OFF
		end if



'--運転準備完了 (配米運転）
else if 運転準備完了 then

	運転準備初期化=OFF
	Main手順初期化=OFF
	
	if 自動搬送AutoMode and 自動搬送AutoRun then
		洗浄タンクAutoMode=ON
		洗浄タンクAutoRun=ON
	end if
	
	if not(運転初期化) then '運転初期化する<処理内容>未登録
		'<処理内容>
		運転初期化=ON
		
		IND_配米準備=OFF
		IND_配米中=OFF
		IND_炊飯中=ON
		IND_炊飯完了=OFF
		IND_停止待機=OFF
		
		浸漬タンクAユニット許可=ON
		浸漬タンクBユニット許可=ON
	end if

	if アルファ化米モード then
		浸漬タンクAユニット許可=OFF
		浸漬タンクBユニット許可=OFF
		
		if 配米終了フラグ or (DM_配米総数>DM_配米総数設定値 or DM_配米総数=DM_配米総数設定値) then
			配米終了フラグ=ON
			IND_配米中=OFF		
		else
			配米終了フラグ=OFF
			IND_配米中=ON		
		end if
	
	else
		if 配米終了フラグ or (not(浸漬タンクAユニット許可) and not(浸漬タンクBユニット許可)) then
			IND_配米中=OFF
		else
			IND_配米中=ON
		end if
		
		'-- A配米完了 and B配米完了
		if (DM_Aタンク設定値=0 or 浸漬タンクA米無し) and  (DM_Bタンク設定値=0 or 浸漬タンクB米無し) then
			配米終了フラグ=ON
		else 
			配米終了フラグ=OFF
		end if
	end if
	
	if IND_配米中 then
		if ldp(浸漬タンクA米無し) then
			pnlPB強制米無しA=ON
		else if ldp(浸漬タンクB米無し) then
			pnlPB強制米無しB=ON
		end if
		
	end if
	
		
	'-- グローバル画面表示
	if tmsg配米完了表示=ON then
		if pnlPB戻る then
				配米終了フラグ=OFF
				tmsg配米完了表示=OFF '配米完了表示
				tmsg配米完了消去=ON '配米完了表示
		end if
	end if
		
	if 配米終了フラグ then
		
		if not(配米完了表示【済】) and not(炊飯機消火警告【済】) and not(炊飯完了停止【済】)  then

				tmsg配米完了表示=ON '配米完了表示
				tmsg配米完了消去=OFF '配米完了表示

				if pnlPBOK or 消火警告までの残釜数>=消火警告までの残釜数設定値 then
				
					if pnlPBOK then
						消火警告までの残釜数=0
					end if
					tmsg配米完了表示=OFF '配米完了表示
					tmsg配米完了消去=ON '配米完了表示
					配米完了表示【済】=ON
				
				end if
	
		else if 配米完了表示【済】 and not(炊飯機消火警告【済】) and not(炊飯完了停止【済】)  then
			インターバル給水中=OFF
		
			if 消火警告までの残釜数>=消火警告までの残釜数設定値 or DM_排出残数<=0 or tmsg炊飯機消火警告表示 then
	
					MainStatusMsg=#121 '停止準備中。炊飯機消火可能です。
					tmsg炊飯機消火警告表示=ON
					tmsg炊飯機消火警告消去=OFF

					if ldp(pnlPBOK) or DM_排出残数<=0 then
						tmsg炊飯機消火警告表示=OFF
						tmsg炊飯機消火警告消去=ON

						DM_EndCnt=6
						自動停止=OFF
						IND_自動停止可能=OFF

						炊飯機消火警告【済】=ON
					end if
					
			end if
					
			
		else if  配米完了表示【済】 and 炊飯機消火警告【済】 and not(炊飯完了停止【済】) then
		
			if DM_排出残数<=0 or tmsg炊飯完了表示 then

					MainStatusMsg=#120 '停止準備中		
					tmsg炊飯完了表示=ON '炊飯完了通知
					tmsg炊飯完了消去=OFF '炊飯完了通知

					IND_炊飯完了=ON
					IND_炊飯中=OFF

					IND_停止待機=CR2006
					
					

					if not(PB23_自動停止) or not(PB35_停止) or not(PB17_搬送停止) or 自動停止 then
						tmsg炊飯完了表示=OFF '炊飯完了通知
						tmsg炊飯完了消去=ON '炊飯完了通知

						炊飯完了停止【済】=ON
					end if
			else
				DM_EndCnt=6
				自動停止=OFF
				IND_自動停止可能=OFF
			end if
			

			select case DM_EndCnt
			case 0
				IND_EndCnt1=OFF
				IND_EndCnt2=OFF
				IND_EndCnt3=OFF
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
				
				if 自動停止設定 then
					自動停止=ON
				else 
					自動停止=OFF
				end if
				IND_自動停止可能=ON
				
			case 1
				IND_EndCnt1=ON
				IND_EndCnt2=OFF
				IND_EndCnt3=OFF
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 2
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=OFF
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 3
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=OFF
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 4
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=OFF
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 5
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=OFF
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 6
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=ON
				IND_EndCnt7=OFF
				IND_EndCnt8=OFF
			case 7
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=ON
				IND_EndCnt7=ON
				IND_EndCnt8=OFF
			case 8
				IND_EndCnt1=ON
				IND_EndCnt2=ON
				IND_EndCnt3=ON
				IND_EndCnt4=ON
				IND_EndCnt5=ON
				IND_EndCnt6=ON
				IND_EndCnt7=ON
				IND_EndCnt8=ON
			end select
			

			if IND_炊飯完了=ON then
				if	ほぐし機Aユニットstep=1 and ほぐし機Aユニット完了 then
					反転ほぐし機A禁止=ON
				end if
				if	ほぐし機Bユニットstep=1 and ほぐし機Bユニット完了 then
					反転ほぐし機B禁止=ON
				end if
			end if
			
		else if  配米完了表示【済】 and 炊飯機消火警告【済】 and 炊飯完了停止【済】 then
		
				tmsg炊飯完了表示=OFF '炊飯完了通知
				tmsg炊飯完了消去=ON  '炊飯完了通知					

				IND_炊飯完了=OFF
				IND_停止待機=OFF
				運転準備完了=OFF
				
				pnlPB強制米無しA=OFF
				pnlPB強制米無しB=OFF
				
	
		end if
	
	else

		配米完了表示【済】=OFF
		炊飯機消火警告【済】=OFF
		炊飯完了停止【済】=OFF

	end if
	
	
else '運転準備=OFF 運転準備完了=OFF
	if not(PB23_自動停止) then

		メインTP_切替ページＮｏ=22

		'tmsgxxxx=OFF
		tmsg運転準備開始確認=OFF
		tmsg運転準備開始確認消去=OFF
		
		tmsg運転準備完了=OFF
		tmsg運転準備完了消去=OFF
		
		tmsg炊飯機点火実行警告=OFF
		
		tmsg炊飯機消火警告表示=OFF
		tmsg炊飯機消火警告消去=OFF

		tmsg炊飯完了表示=OFF
		tmsg炊飯完了消去=OFF

	else 

	IND_配米準備=OFF
	IND_配米中=OFF
	IND_炊飯中=OFF
	IND_炊飯完了=OFF
	IND_停止待機=OFF
			
	運転準備中=OFF
	配米待機中=OFF
	運転準備完了=OFF
	
	自動停止=OFF
	IND_自動停止可能=OFF



		if メインTP_切替ページＮｏ=15 then

			if 換気設備確認【済】 and 浸漬タンク米投入確認【済】 and 浸漬タンク米投入確認【済】 and 排水栓確認【済】 then
				if pnlPBOK then
				
					運転準備中=ON
					配米待機中=OFF
					運転準備完了=OFF
					メインTP_切替ページＮｏ15【済】=ON
					換気設備確認【済】=OFF
					浸漬タンク米投入確認【済】=OFF
					浸漬タンク米投入確認【済】=OFF
					排水栓確認【済】=OFF
					
	
				end if
			end if

		else if ldp(PB22_自動運転) and PB23_自動停止 and 自動搬送AutoMode then
			
			'運転準備のための初期設定
			メインTP_切替ページＮｏ=15
			
			'xxx【済】=OFF
			メインTP_切替ページＮｏ15【済】=OFF
			換気設備確認【済】=OFF
			浸漬タンク米投入確認【済】=OFF
			浸漬タンク米投入確認【済】=OFF
			排水栓確認【済】=OFF					

			運転準備開始確認【済】=OFF
			炊飯機点火実行確認【済】=OFF
			配米終了フラグ=OFF
			配米完了表示【済】=OFF

			shiftreg釜フタ判定0=0
			shiftreg釜フタ判定1=0
			shiftreg釜フタ判定2=0
			shiftreg釜フタ判定3=0
			shiftreg釜フタ判定4=0
			shiftreg釜フタ判定5=0
			
		else		
			if not(Main手順初期化) then
				
				洗浄タンクAutoMode=OFF
				洗浄タンクAutoRun=OFF
				
				Main手順初期化=ON
			end if

			if not(運転準備初期化) then
				
				メインTP_切替ページＮｏ=22
				メインTP_切替ページＮｏ15【済】=OFF
				加水釜数現在値=0
				配米準備釜数現在値=0
				DM_A配米現在値=0
				DM_B配米現在値=0
				DM_排出総数=0

				消火警告までの残釜数=0
				搬送釜数=0
				空釜搬送釜数=0
				釜カウントA=0
				釜カウントB=0
				
				配米終了フラグ=OFF
			
				運転準備初期化=ON

			end if
			
			加水釜数現在値=0
			配米準備釜数現在値=0
			DM_A配米現在値=0
			DM_B配米現在値=0
			DM_排出総数=0
			
			消火警告までの残釜数=0
			空釜搬送釜数=0
			釜カウントA=0
			釜カウントB=0
			

		end if
		
	end if
	
end if

end if

'===================================================================================================================
'表示信号がONのとき、消去信号をすべてOFFにする。
tmr(tブザー警報,tim_tブザー警報,#20)
ブザー警報=tブザー警報 and not(tim_tブザー警報.B) 

if tmsg運転準備開始確認 or tmsg炊飯機点火実行警告 or tmsg運転準備完了 or tmsg配米完了表示 or tmsg炊飯機消火警告表示 or tmsg炊飯完了表示 then

	tブザー警報=ON
	tmsg運転準備開始確認消去=OFF
	tmsg運転準備完了消去=OFF
	tmsg炊飯完了消去=OFF
	tmsg炊飯機消火警告消去=OFF
	tmsg配米完了消去=OFF
else
	tブザー警報=OFF
end if

'===================================================================================================================
'msg信号(2sec)確定出力

if (20<=メインTP_表示中ページNo and メインTP_表示中ページNo<=29) and (20<=サブTP_表示中ページNo and サブTP_表示中ページNo<=29) and (20<=むらしTP_表示中ページNo and むらしTP_表示中ページNo<=29) then

	tmr(tmsg運転準備開始確認,tim_tmsg運転準備開始確認,20)
	msg運転準備開始確認=tmsg運転準備開始確認 and not(tim_tmsg運転準備開始確認.B)
	tmr(tmsg運転準備開始確認消去,tim_tmsg運転準備開始確認消去,20)
	msg運転準備開始確認消去=tmsg運転準備開始確認消去 and not(tim_tmsg運転準備開始確認消去.B)

	tmr(tmsg運転準備完了,tim_tmsg運転準備完了,20)
	msg運転準備完了=tmsg運転準備完了 and not(tim_tmsg運転準備完了.B)
	tmr(tmsg運転準備完了消去,tim_tmsg運転準備完了消去,20)
	msg運転準備完了消去=tmsg運転準備完了消去 and not(tim_tmsg運転準備完了消去.B)

	tmr(tmsg炊飯機消火警告表示,tim_tmsg炊飯機消火警告表示,20)
	msg炊飯機消火警告表示=tmsg炊飯機消火警告表示 and not(tim_tmsg炊飯機消火警告表示.B)
	tmr(tmsg炊飯機消火警告消去,tim_tmsg炊飯機消火警告消去,20)
	msg炊飯機消火警告消去=tmsg炊飯機消火警告消去 and not(tim_tmsg炊飯機消火警告消去.B) 

	tmr(tmsg炊飯機点火実行警告,tim_tmsg炊飯機点火実行警告,20)
	msg炊飯機点火実行警告=tmsg炊飯機点火実行警告 and not(tim_tmsg炊飯機点火実行警告.B)
	'---
	tmr(tmsg配米完了表示,tim_tmsg配米完了表示,20)
	msg配米完了表示=tmsg配米完了表示 and not(tim_tmsg配米完了表示.B)
	tmr(tmsg配米完了消去,tim_tmsg配米完了消去,20)
	msg配米完了消去=tmsg配米完了消去 and not(tim_tmsg配米完了消去.B)
	'---
	tmr(tmsg炊飯完了表示,tim_tmsg炊飯完了表示,20)
	msg炊飯完了表示=tmsg炊飯完了表示 and not(tim_tmsg炊飯完了表示.B)
	tmr(tmsg炊飯完了消去,tim_tmsg炊飯完了消去,20)
	msg炊飯完了消去=tmsg炊飯完了消去 and not(tim_tmsg炊飯完了消去.B)

else 
	msg運転準備開始確認=OFF
	msg運転準備開始確認消去=ON
	
	msg炊飯機点火実行警告=OFF
	
	msg運転準備完了=OFF
	msg運転準備完了消去=ON
	
	msg配米完了表示=OFF	
	msg配米完了消去=ON
	
	msg炊飯完了表示=OFF
	msg炊飯完了消去=ON
	
	msg炊飯機消火警告表示=OFF
	msg炊飯機消火警告消去=ON

end if

tmr(msgFleshCycl,#40)
if ldp(msgFleshCycl.B) then
	res(msgFleshCycl)

	res(tim_tmsg運転準備開始確認)
	res(tim_tmsg運転準備開始確認消去)	
	res(tim_tmsg運転準備完了)
	res(tim_tmsg運転準備完了消去)
	res(tim_tmsg炊飯完了表示)
	res(tim_tmsg炊飯完了消去)
	res(tim_tmsg炊飯機消火警告表示)
	res(tim_tmsg炊飯機消火警告消去)
	res(tim_tmsg炊飯機点火実行警告)
	res(tim_tmsg配米完了表示)
	res(tim_tmsg配米完了消去)

end if

'===================================================================================================================

'===================================================================================================================
'	メイン操作ボックス					サブボックス				むらし操作ボックス
'-------------------------------------------------------------------------------------------------------------------
'	PL9_運転中							PBL11_運転中				PBL14_むらし運転中
'	PL10_異常							PBL12_異常					PL7_むらし機異常
'
'	PB22_自動運転	PBL22_自動運転		
'	PB23_自動停止						PB35_停止					PB17_搬送停止
'
'	PB34_リセット						PB24_リセット				PB6_リセット
'
'	SSW3_手動モード													SEL2_1_運転切換（単動）
'	SSW3_自動モード													SEL2_2_運転切換（連動）
'
'																	PB18_エスケープ
'===================================================================================================================
'

	PTL1_パトライト赤=パトライト赤 and CR2006
	PTL2_パトライト赤=パトライト赤 and CR2006
	PTL3_パトライト赤=パトライト赤 and CR2006
	PTL4_パトライト赤=パトライト赤 and CR2006
	PTL5_パトライト赤=パトライト赤 and CR2006
	'
	PTL1_パトライト黄=パトライト黄 and CR2006
	PTL2_パトライト黄=パトライト黄 and CR2006
	PTL3_パトライト黄=パトライト黄 and CR2006
	PTL4_パトライト黄=パトライト黄 and CR2006
	PTL5_パトライト黄=パトライト黄 and CR2006
	'
	PTL1_パトライト青=パトライト青 and CR2006
	PTL2_パトライト青=パトライト青 and CR2006
	PTL3_パトライト青=パトライト青 and CR2006
	PTL4_パトライト青=パトライト青 and CR2006
	PTL5_パトライト青=パトライト青 and CR2006

if 1 then
	PTL1_パトライトブザー=alm渋滞警報 or (ブザー警報 and CR2006) 
	PTL2_パトライトブザー=alm渋滞警報 or (ブザー警報 and CR2006)
	PTL3_パトライトブザー=alm渋滞警報 or (ブザー警報 and CR2006)
	PTL4_パトライトブザー=alm渋滞警報 or (ブザー警報 and CR2006)
	PTL5_パトライトブザー=alm渋滞警報 or (ブザー警報 and CR2006)
end if

	if 自動搬送ErrStep<>0 or 自動搬送EmgStep<>0 then
		パトライト赤=ON
		パトライト黄=OFF
		パトライト青=OFF	
	else if OtherErrStep<>0 or コンベア一時停止中 then
		パトライト赤=OFF
		パトライト黄=ON
		パトライト青=OFF
	else if 自動搬送AutoRun then
		パトライト赤=OFF
		パトライト黄=OFF
		パトライト青=ON
	else
		パトライト赤=OFF
		パトライト黄=OFF
		パトライト青=OFF	
	end if	
	

' PLインジケータ

	PBL22_自動運転=運転準備完了 and 自動搬送AutoRun
	
	'--------------------------------
	if 自動搬送AutoRun then
		PL9_運転中=ON
		PBL11_運転中=ON
		PBL14_むらし運転中=ON
	else
		if OtherStep<>0 then
			if CR2006 then
				PL9_運転中=ON
				PBL11_運転中=ON
				PBL14_むらし運転中=ON
			else
				PL9_運転中=OFF
				PBL11_運転中=OFF
				PBL14_むらし運転中=OFF

			end if
		else
			PL9_運転中=OFF
			PBL11_運転中=OFF
			PBL14_むらし運転中=OFF
		end if
		
	end if

	'--------------------------------
	if 自動搬送ErrStep<>0 or OtherEmgStep<>0 or OtherErrStep<>0  or コンベア一時停止中 then

		if CR2006 then
			PL10_異常=ON
			PBL12_異常=ON
			PL7_むらし機異常=ON
		else
			PL10_異常=OFF
			PBL12_異常=OFF
			PL7_むらし機異常=OFF
		end if

	else

		PL10_異常=OFF
		PBL12_異常=OFF
		PL7_むらし機異常=OFF

	end if
	'--------------------------------
'===================================================================================================================
'エスケープ
	if ldp(PB18_エスケープ) then
		if エスケープ中 then
			PBL18_エスケープ中=OFF
			エスケープ中=OFF
		else
			PBL18_エスケープ中=ON
			エスケープ中=ON

			if not(搬送コンベアDAutoRun) and 搬送コンベアDstep=0 and MC19_搬送モータ=OFF then
				if PH22_釜検知 then
					mSV41_リフト=ON
				end if
			end if
		
		end if
	end if
		
'===================================================================================================================
'洗浄タンク給水 予約運転モード
if 洗浄タンク即時運転モード or (洗浄タンク予約運転モード and ldp(洗浄タンクONTIME)) then
	洗浄タンクAutoMode=ON
	洗浄タンクAutoRun=ON
end if


'===================================================================================================================
'非常停止フラグ
	tmr(ESPB5_非常停止,ESPB5_非常停止tim,2)
	tmr(not(ESPB1_非常停止),ESPB1_非常停止tim,2)
	tmr(not(ESPB2_非常停止),ESPB2_非常停止tim,2)
	tmr(not(ESPB3_非常停止IN),ESPB3_非常停止INtim,2)
	tmr(not(ESPB4_非常停止IN),ESPB4_非常停止INtim,2)
	tmr(not(PB26_コンベア停止),PB26_コンベア停止tim,2)
	tmr(not(PB27_コンベア停止),PB27_コンベア停止tim,2)
	tmr(not(PB28_コンベア停止),PB28_コンベア停止tim,2)
	tmr(not(PB29_コンベア停止),PB29_コンベア停止tim,2)
	
	PB非常停止= not(ESPB5_非常停止tim or ESPB1_非常停止tim or ESPB2_非常停止tim or ESPB3_非常停止INtim or  ESPB4_非常停止INtim or PB26_コンベア停止tim or PB27_コンベア停止tim or PB28_コンベア停止tim or PB29_コンベア停止tim)
	ESPBL1_非常停止 =not(PB非常停止) and CR2006
	EmgFlg=not(PB非常停止) or EmgFlg
	if not(PB非常停止)  then
		if ESPB5_非常停止 then '洗米機
			almESPB5_非常停止=ON
		else if not(ESPB1_非常停止) then 'メイン制御盤
			almESPB1_非常停止=ON
		else if not(ESPB2_非常停止) then 'サブ制御盤
			almESPB2_非常停止=ON
		else if not(ESPB3_非常停止IN) then 'むらし制御盤
			almESPB3_非常停止IN=ON
		else if not(ESPB4_非常停止IN) then  'むらし背面
			almESPB4_非常停止IN=ON
		else if not(PB26_コンベア停止) then
			almPB26_コンベア停止=ON
		else if not(PB27_コンベア停止) then
			almPB27_コンベア停止=ON
		else if not(PB28_コンベア停止) then
			almPB28_コンベア停止=ON 
		else if not(PB29_コンベア停止) then
			almPB29_コンベア停止=ON
		end if
			自動搬送EmgStep=1
	end if
	
'リセットフラグ

	ResetFlg=PB34_リセット or PB24_リセット or PB6_リセット

'===================================================================================================================
'ステージシグナル 
'===================================================================================================================
OtherOrgErr= 浸漬タンクAユニットOrgErr
OtherOrgErr= OtherOrgErr or 浸漬タンクBユニットOrgErr
OtherOrgErr= OtherOrgErr or 計水ユニットOrgErr
OtherOrgErr= OtherOrgErr or ならし装置OrgErr
OtherOrgErr= OtherOrgErr or 蓋被せユニットOrgErr
OtherOrgErr= OtherOrgErr or 蓋取りユニットOrgErr
OtherOrgErr= OtherOrgErr or ごはん検知OrgErr
OtherOrgErr= OtherOrgErr or バキュームユニットOrgErr
OtherOrgErr= OtherOrgErr or ほぐし機AユニットOrgErr
OtherOrgErr= OtherOrgErr or ほぐし機BユニットOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアAOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアBOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアCOrgErr
OtherOrgErr= OtherOrgErr or 釜送りコンベアOrgErr
OtherOrgErr= OtherOrgErr or むらし機釜送りコンベアOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアDOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアEOrgErr
OtherOrgErr= OtherOrgErr or 搬送コンベアFOrgErr
OtherOrgErr= OtherOrgErr or 洗浄入口リフトOrgErr
OtherOrgErr= OtherOrgErr or 洗浄入口搬送OrgErr
OtherOrgErr= OtherOrgErr or 洗浄ユニットOrgErr
'OtherOrgErr= OtherOrgErr or 洗浄タンクOrgErr
OtherOrgErr= OtherOrgErr or 洗浄コンベア搬送OrgErr
OtherOrgErr= OtherOrgErr or 洗浄出口搬送OrgErr
OtherOrgErr= OtherOrgErr or 釜フタ昇降装置BOrgErr
OtherOrgErr= OtherOrgErr or むらし出口OrgErr

'===================================================================================================================
OtherErr= 浸漬タンクAユニットErr
OtherErr= OtherErr or 浸漬タンクBユニットErr
OtherErr= OtherErr or 計水ユニットErr
OtherErr= OtherErr or ならし装置Err
OtherErr= OtherErr or 蓋被せユニットErr
OtherErr= OtherErr or 蓋取りユニットErr
OtherErr= OtherErr or ごはん検知Err
OtherErr= OtherErr or バキュームユニットErr
OtherErr= OtherErr or ほぐし機AユニットErr
OtherErr= OtherErr or ほぐし機BユニットErr
OtherErr= OtherErr or 搬送コンベアAErr
OtherErr= OtherErr or 搬送コンベアBErr
OtherErr= OtherErr or 搬送コンベアCErr
OtherErr= OtherErr or 釜送りコンベアErr
OtherErr= OtherErr or むらし機釜送りコンベアErr
OtherErr= OtherErr or 搬送コンベアDErr
OtherErr= OtherErr or 搬送コンベアEErr
OtherErr= OtherErr or 搬送コンベアFErr
OtherErr= OtherErr or 洗浄入口リフトErr
OtherErr= OtherErr or 洗浄入口搬送Err
OtherErr= OtherErr or 洗浄ユニットErr
OtherErr= OtherErr or 洗浄タンクErr
OtherErr= OtherErr or 洗浄コンベア搬送Err
OtherErr= OtherErr or 洗浄出口搬送Err
OtherErr= OtherErr or 釜フタ昇降装置BErr
'==================================================================================================================
OtherEmg=浸漬タンクAユニットEmg
OtherEmg=OtherEmg or 浸漬タンクBユニットEmg
OtherEmg=OtherEmg or 計水ユニットEmg
OtherEmg=OtherEmg or ならし装置Emg
OtherEmg=OtherEmg or 蓋被せユニットEmg
OtherEmg=OtherEmg or 蓋取りユニットEmg
OtherEmg=OtherEmg or ごはん検知Emg
OtherEmg=OtherEmg or バキュームユニットEmg
OtherEmg=OtherEmg or ほぐし機AユニットEmg
OtherEmg=OtherEmg or ほぐし機BユニットEmg
OtherEmg=OtherEmg or 搬送コンベアAEmg
OtherEmg=OtherEmg or 搬送コンベアBEmg
OtherEmg=OtherEmg or 搬送コンベアCEmg
OtherEmg=OtherEmg or 釜送りコンベアEmg
OtherEmg=OtherEmg or むらし機釜送りコンベアEmg
OtherEmg=OtherEmg or 搬送コンベアDEmg
OtherEmg=OtherEmg or 搬送コンベアEEmg
OtherEmg=OtherEmg or 搬送コンベアFEmg
OtherEmg=OtherEmg or 洗浄入口リフトEmg
OtherEmg=OtherEmg or 洗浄入口搬送Emg
OtherEmg=OtherEmg or 洗浄ユニットEmg
'OtherEmg=OtherEmg or 洗浄タンクEmg
OtherEmg=OtherEmg or 洗浄コンベア搬送Emg
OtherEmg=OtherEmg or 洗浄出口搬送Emg
OtherEmg=OtherEmg or 釜フタ昇降装置BEmg
'===================================================================================================================
OtherOrg=浸漬タンクAユニットOrg
OtherOrg= OtherOrg and 浸漬タンクBユニットOrg
OtherOrg= OtherOrg and 計水ユニットOrg
OtherOrg= OtherOrg and ならし装置Org
OtherOrg= OtherOrg and 蓋被せユニットOrg
OtherOrg= OtherOrg and 蓋取りユニットOrg
OtherOrg= OtherOrg and ごはん検知Org
OtherOrg= OtherOrg and バキュームユニットOrg
OtherOrg= OtherOrg and ほぐし機AユニットOrg
OtherOrg= OtherOrg and ほぐし機BユニットOrg
OtherOrg= OtherOrg and 搬送コンベアAOrg
OtherOrg= OtherOrg and 搬送コンベアBOrg
OtherOrg= OtherOrg and 搬送コンベアCOrg
OtherOrg= OtherOrg and 釜送りコンベアOrg
OtherOrg= OtherOrg and むらし機釜送りコンベアOrg
OtherOrg= OtherOrg and 搬送コンベアDOrg
OtherOrg= OtherOrg and 搬送コンベアEOrg
OtherOrg= OtherOrg and 搬送コンベアFOrg
OtherOrg= OtherOrg and 洗浄入口リフトOrg
OtherOrg= OtherOrg and 洗浄入口搬送Org
OtherOrg= OtherOrg and 洗浄ユニットOrg
'OtherOrg= OtherOrg and 洗浄タンクOrg
OtherOrg= OtherOrg and 洗浄コンベア搬送Org
OtherOrg= OtherOrg and 洗浄出口搬送Org
OtherOrg= OtherOrg and 釜フタ昇降装置BOrg
OtherOrg= OtherOrg and not(PH21_むらし機出口センサ)
'===================================================================================================================
OtherStep= 浸漬タンクAユニットstep
OtherStep= ORA(OtherStep,浸漬タンクBユニットstep)
OtherStep= ORA(OtherStep,計水ユニットstep)
OtherStep= ORA(OtherStep,ならし装置step)
OtherStep= ORA(OtherStep,蓋被せユニットstep)
OtherStep= ORA(OtherStep,蓋取りユニットstep)
OtherStep= ORA(OtherStep,ごはん検知step)
OtherStep= ORA(OtherStep,バキュームユニットstep)
OtherStep= ORA(OtherStep,ほぐし機Aユニットstep)
OtherStep= ORA(OtherStep,ほぐし機Bユニットstep)
OtherStep= ORA(OtherStep,搬送コンベアAstep)
OtherStep= ORA(OtherStep,搬送コンベアBstep)
OtherStep= ORA(OtherStep,搬送コンベアCstep)
OtherStep= ORA(OtherStep,釜送りコンベアstep)
'OtherStep= ORA(OtherStep,むらし機釜送りコンベアstep)
OtherStep= ORA(OtherStep,搬送コンベアDstep)
OtherStep= ORA(OtherStep,搬送コンベアEstep)
OtherStep= ORA(OtherStep,搬送コンベアFstep)
OtherStep= ORA(OtherStep,洗浄入口リフトstep)
OtherStep= ORA(OtherStep,洗浄入口搬送step)
OtherStep= ORA(OtherStep,洗浄ユニットstep)
'OtherStep= ORA(OtherStep,洗浄タンクstep)
OtherStep= ORA(OtherStep,洗浄コンベア搬送step)
OtherStep= ORA(OtherStep,洗浄出口搬送step)
OtherStep= ORA(OtherStep,釜フタ昇降装置Bstep)
'===================================================================================================================
OtherOrgErrStep=浸漬タンクAユニットErrStep
OtherOrgErrStep= ORA(OtherOrgErrStep,浸漬タンクBユニットErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,計水ユニットErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,ならし装置ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,蓋被せユニットErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,蓋取りユニットErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,ごはん検知ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,バキュームユニットErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,ほぐし機AユニットErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,ほぐし機BユニットErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアAErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアBErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアCErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,釜送りコンベアErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,むらし機釜送りコンベアErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアDErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアEErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,搬送コンベアFErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄入口リフトErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄入口搬送ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄ユニットErrStep)
'OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄タンクErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄コンベア搬送ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,洗浄出口搬送ErrStep)
OtherOrgErrStep= ORA(OtherOrgErrStep,釜フタ昇降装置BErrStep)
'===================================================================================================================
OtherErrStep=浸漬タンクAユニットErrStep
OtherErrStep= ORA(OtherErrStep,浸漬タンクBユニットErrStep)
OtherErrStep= ORA(OtherErrStep,計水ユニットErrStep)
OtherErrStep= ORA(OtherErrStep,ならし装置ErrStep)
OtherErrStep= ORA(OtherErrStep,蓋被せユニットErrStep)
OtherErrStep= ORA(OtherErrStep,蓋取りユニットErrStep)
OtherErrStep= ORA(OtherErrStep,ごはん検知ErrStep)
OtherErrStep= ORA(OtherErrStep,バキュームユニットErrStep)
OtherErrStep= ORA(OtherErrStep,ほぐし機AユニットErrStep)
OtherErrStep= ORA(OtherErrStep,ほぐし機BユニットErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアAErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアBErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアCErrStep)
OtherErrStep= ORA(OtherErrStep,釜送りコンベアErrStep)
OtherErrStep= ORA(OtherErrStep,むらし機釜送りコンベアErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアDErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアEErrStep)
OtherErrStep= ORA(OtherErrStep,搬送コンベアFErrStep)
OtherErrStep= ORA(OtherErrStep,洗浄入口リフトErrStep)
OtherErrStep= ORA(OtherErrStep,洗浄入口搬送ErrStep)
OtherErrStep= ORA(OtherErrStep,洗浄ユニットErrStep)
'OtherErrStep= ORA(OtherErrStep,洗浄タンクErrStep)
OtherErrStep= ORA(OtherErrStep,洗浄コンベア搬送ErrStep)
OtherErrStep= ORA(OtherErrStep,洗浄出口搬送ErrStep)
OtherErrStep= ORA(OtherErrStep,釜フタ昇降装置BErrStep)
'===================================================================================================================
OtherEmgStep=浸漬タンクAユニットEmgStep
OtherEmgStep= ORA(OtherEmgStep,浸漬タンクBユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,計水ユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,ならし装置EmgStep)
OtherEmgStep= ORA(OtherEmgStep,蓋被せユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,蓋取りユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,ごはん検知EmgStep)
OtherEmgStep= ORA(OtherEmgStep,バキュームユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,ほぐし機AユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,ほぐし機BユニットEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアAEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアBEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアCEmgStep)
OtherEmgStep= ORA(OtherEmgStep,釜送りコンベアEmgStep)
OtherEmgStep= ORA(OtherEmgStep,むらし機釜送りコンベアEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアDEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアEEmgStep)
OtherEmgStep= ORA(OtherEmgStep,搬送コンベアFEmgStep)
OtherEmgStep= ORA(OtherEmgStep,洗浄入口リフトEmgStep)
OtherEmgStep= ORA(OtherEmgStep,洗浄入口搬送EmgStep)
OtherEmgStep= ORA(OtherEmgStep,洗浄ユニットEmgStep)
'OtherEmgStep= ORA(OtherEmgStep,洗浄タンクEmgStep)
OtherEmgStep= ORA(OtherEmgStep,洗浄コンベア搬送EmgStep)
OtherEmgStep= ORA(OtherEmgStep,洗浄出口搬送EmgStep)
OtherEmgStep= ORA(OtherEmgStep,釜フタ昇降装置BEmgStep)
'==================================================================================================================
'【  デバイスへの給電  】


'	if 前処理工程AutoRun or 浸漬タンクAユニットAutoRun or 浸漬タンクBユニットAutoRun then
'		RLY5_パドルセンサ電源=ON
'	else
'		RLY5_パドルセンサ電源=OFF
'	end if

	mMC1_インバータ用電源=ON

	'RLY_投光側電源OFF=ON

'===================================================================================================================
'【 初期化処理 】
if CR2008 then

    自動搬送AutoMode=OFF
    自動搬送OrgErr=OFF
    自動搬送Err=OFF
    自動搬送Emg=OFF
    自動搬送step=0
    自動搬送ErrStep=0
    自動搬送OrgErrStep=0
    自動搬送EmgStep=0
	
	OtherEmgStep=0
	OtherErrStep=0
	OtherOrgErr=0
	
	自動搬送手動許可step=0
	むらし搬送手動許可step=0
	洗浄機手動許可step=0
	
end if

'===================================================================================================================
'【 緊急停止 】
if 自動搬送Emg  then
	自動搬送EmgStep=1
end if

'===================================================================================================================


'===================================================================================================================
'  コマンド処理
'===================================================================================================================
' 自動搬送コマンド処理
'
if 洗浄搬送禁止 then
		洗浄入口搬送AutoRun=OFF
		洗浄ユニットAutoRun=OFF
		洗浄タンクAutoRun=OFF
		洗浄コンベア搬送AutoRun=OFF
		洗浄出口搬送AutoRun=OFF				
		釜フタ昇降装置BAutoRun=OFF
end if


if 自動搬送EmgStep=0 and OtherEmgStep=0 then  

	if 自動搬送ErrStep=0  and OtherErrStep=0 then
	
		if not(自動搬送OrgErr) and not(OtherOrgErr) then

			if not(PB23_自動停止) or not(PB35_停止) or not(PB17_搬送停止)  or 自動搬送停止 or ldp(自動停止) then
			
				自動搬送AutoRun=OFF

				浸漬タンクAユニットAutoRun=OFF
				浸漬タンクBユニットAutoRun=OFF
				計水ユニットAutoRun=OFF
				ならし装置AutoRun=OFF
				蓋被せユニットAutoRun=OFF
				蓋取りユニットAutoRun=OFF
				ごはん検知AutoRun=OFF
				バキュームユニットAutoRun=OFF
				ほぐし機AユニットAutoRun=OFF
				ほぐし機BユニットAutoRun=OFF
				搬送コンベアAAutoRun=OFF
				搬送コンベアBAutoRun=OFF
				搬送コンベアCAutoRun=OFF
				釜送りコンベアAutoRun=OFF
				むらし機釜送りコンベアAutoRun=OFF
				搬送コンベアDAutoRun=OFF
				搬送コンベアEAutoRun=OFF
				搬送コンベアFAutoRun=OFF
				洗浄入口リフトAutoMode=OFF
				洗浄入口搬送AutoRun=OFF
				洗浄ユニットAutoRun=OFF
				洗浄タンクAutoRun=OFF
				洗浄コンベア搬送AutoRun=OFF
				洗浄出口搬送AutoRun=OFF				
				釜フタ昇降装置BAutoRun=OFF

			else
				'-------------------------------------------------------------------------------------
				'メイン              むらし                  洗浄機
				'SSW3_自動モード     SSW1_2_運転切換（連動） SEL2_2_運転切換（連動）
				'-------------------------------------------------------------------------------------
				' 自動搬送 自動 - 手動  (2ステップ切り替え）
				'メイン操作ボックス部 SSW3_手動モード  SSW3_自動モード
				if 	not(自動搬送手動切替済み) and SSW3_手動モード and  not(SSW3_自動モード) then
				
					select case 自動搬送手動許可step
					case 0
						自動搬送手動要求=ON
						inc(自動搬送手動許可step)
					case 1
						if 自動搬送手動許可 then

							自動搬送AutoMode=OFF
					
							'----- 前処理工程を外す --------
							'前処理工程AutoMode=OFF
							'前処理工程AutoRun=OFF
							'計量AutoRun=OFF
							
							'if 即時運転モード and (計量step<>0 or 洗米step<>0) then
							'	即時運転モードEndWait=ON
							'end if
							'即時運転モード=OFF
							
							'if 予約運転モード and (計量step<>0 or 洗米step<>0) then
							'	予約運転モードEndWait=ON
							'end if
							'予約運転モード=OFF

							inc(自動搬送手動許可step)
						else if 自動搬送手動禁止 then
							自動搬送AutoMode=ON
							inc(自動搬送手動許可step)
						end if
					case 2
						自動搬送手動要求=OFF
						inc(自動搬送手動許可step)
					case 3
						自動搬送手動切替済み=ON
						inc(自動搬送手動許可step)
						'自動搬送手動許可step=0
						
					end select
				
				else if SSW3_自動モード and not(SSW3_手動モード) then
					自動搬送手動切替済み=OFF
					自動搬送手動許可step=0
					自動搬送手動要求=OFF
					自動搬送AutoMode=ON
				end if

				'-------------------------------------------------------------------------------------
				' 使用しない 2019/7/ むらし機  自動 - 手動 (2ステップ切り替え） 
				if 0 then '-- 使用しない
		
				if  not(自動搬送AutoMode) then 'and  SSW1_1_運転切換（単動） and not(SSW1_2_運転切換（連動）) then
		
					むらし機釜送りコンベアAutoMode=OFF

				else 'if 自動搬送AutoMode and SSW1_2_運転切換（連動） and not(SSW1_1_運転切換（単動）) then
					
					むらし機釜送りコンベアAutoMode=ON
				
				end if
				

				'-------------------------------------------------------------------------------------
				' 使用しない 2017/07 洗浄機 自動 - 手動  (2ステップ切り替え）
				
				if not(自動搬送AutoMode) then 'and SEL2_1_運転切換（単動） and not(SEL2_2_運転切換（連動）) then
				
				 	洗浄コンベア搬送AutoMode=OFF
					洗浄ユニットAutoMode=OFF
					洗浄タンクAutoMode=OFF
				
				else 'if SEL2_2_運転切換（連動） and not(SEL2_1_運転切換（単動）) then

				 	洗浄コンベア搬送AutoMode=ON
					洗浄ユニットAutoMode=ON
					洗浄タンクAutoMode=ON

				end if
		
				end if '-- 使用しない
				'-------------------------------------------------------------------------------------
				' 起動
				if 自動搬送AutoMode and OtherStep=0 then
					if ldp(PB22_自動運転) and (運転準備中 or 配米待機中 or 運転準備完了 or テスト運転) and not(OtherOrg)  then
					
						浸漬タンクAユニットOrgErr=not(浸漬タンクAユニットOrg)
						浸漬タンクBユニットOrgErr=not(浸漬タンクBユニットOrg)
						計水ユニットOrgErr=not(計水ユニットOrg)
						ならし装置OrgErr=not(ならし装置Org)
						蓋被せユニットOrgErr=not(蓋被せユニットOrg)
						蓋取りユニットOrgErr=not(蓋取りユニットOrg)
						ごはん検知OrgErr=not(ごはん検知Org)
						バキュームユニットOrgErr=not(バキュームユニットOrg)
						ほぐし機AユニットOrgErr=not(ほぐし機AユニットOrg)
						ほぐし機BユニットOrgErr=not(ほぐし機BユニットOrg)
						搬送コンベアAOrgErr=not(搬送コンベアAOrg)
						搬送コンベアBOrgErr=not(搬送コンベアBOrg)
						搬送コンベアCOrgErr=not(搬送コンベアCOrg)
						釜送りコンベアOrgErr=not(釜送りコンベアOrg)
						むらし機釜送りコンベアOrgErr=not(むらし機釜送りコンベアOrg)
						搬送コンベアDOrgErr=not(搬送コンベアDOrg)
						搬送コンベアEOrgErr=not(搬送コンベアEOrg)
						搬送コンベアFOrgErr=not(搬送コンベアFOrg)
						洗浄入口リフトOrgErr=not(洗浄入口リフトOrg)
						洗浄入口搬送OrgErr=not(洗浄入口搬送Org)
						洗浄ユニットOrgErr=not(洗浄ユニットOrg)
						'洗浄タンクOrgErr=not(洗浄タンクOrg)
						洗浄コンベア搬送OrgErr=not(洗浄コンベア搬送Org)
						洗浄出口搬送OrgErr=not(洗浄出口搬送Org)
						釜フタ昇降装置BOrgErr=not(釜フタ昇降装置BOrg)
						むらし出口OrgErr=PH21_むらし機出口センサ
						
					end if
				end if
				
				if 自動搬送AutoMode and OtherOrg and OtherStep=0 and not(PH21_むらし機出口センサ) then
					if ldp(PB22_自動運転) and (運転準備中 or 配米待機中 or 運転準備完了 or テスト運転 ) then
						
						自動搬送AutoRun=ON
						
						'------------------------------------------------------
						浸漬タンクAユニットAutoRun=ON
						浸漬タンクBユニットAutoRun=ON
						計水ユニットAutoRun=ON
						ならし装置AutoRun=ON
						蓋被せユニットAutoRun=ON
						蓋取りユニットAutoRun=ON
						ごはん検知AutoRun=ON
						バキュームユニットAutoRun=ON
						ほぐし機AユニットAutoRun=ON
						ほぐし機BユニットAutoRun=ON
						搬送コンベアAAutoRun=ON
						搬送コンベアBAutoRun=ON
						搬送コンベアCAutoRun=ON
						釜送りコンベアAutoRun=ON
						'むらし機釜送りコンベアAutoRun=ON
						搬送コンベアDAutoRun=ON
						搬送コンベアEAutoRun=ON
						搬送コンベアFAutoRun=ON
						洗浄入口リフトAutoRun=ON
						if not(洗浄搬送禁止) then
							洗浄入口搬送AutoRun=ON
							洗浄ユニットAutoRun=ON
							洗浄タンクAutoRun=ON
							洗浄コンベア搬送AutoRun=ON
							洗浄出口搬送AutoRun=ON
							釜フタ昇降装置BAutoRun=ON
						else
							洗浄入口搬送AutoRun=OFF
							洗浄ユニットAutoRun=OFF
							洗浄タンクAutoRun=OFF
							洗浄コンベア搬送AutoRun=OFF
							洗浄出口搬送AutoRun=OFF
							釜フタ昇降装置BAutoRun=OFF
						end if
						'------------------------------------------------------
						浸漬タンクAユニットstep=1
						浸漬タンクBユニットstep=1
						計水ユニットstep=1
						ならし装置step=1
						蓋被せユニットstep=1
						蓋取りユニットstep=1
						ごはん検知step=1
						バキュームユニットstep=1
						ほぐし機Aユニットstep=1
						ほぐし機Bユニットstep=1
						搬送コンベアAstep=1
						搬送コンベアBstep=1
						搬送コンベアCstep=1
						釜送りコンベアstep=1
						'むらし機釜送りコンベアstep=1
						搬送コンベアDstep=1
						搬送コンベアEstep=1
						搬送コンベアFstep=1
						洗浄入口搬送step=1
						洗浄入口リフトstep=1
						
						if not(洗浄搬送禁止) then
							洗浄ユニットstep=1
							洗浄タンクstep=1
							洗浄コンベア搬送step=1
							洗浄出口搬送step=1
							釜フタ昇降装置Bstep=1	
						else 
							洗浄ユニットstep=0
							洗浄タンクstep=0
							洗浄コンベア搬送step=0
							洗浄出口搬送step=0
							釜フタ昇降装置Bstep=0	
						end if
						
						'------------------------------------------------------
						搬送コンベアA排出要求=OFF
						搬送コンベアB排出要求=OFF
						搬送コンベアC排出要求=OFF
						搬送コンベアD排出要求=OFF
						搬送コンベアE排出要求=OFF
						搬送コンベアF排出要求=OFF
						洗浄入口搬送排出要求=OFF
						洗浄入口リフト排出要求=OFF
						洗浄コンベア搬送排出要求=OFF
						洗浄出口搬送排出要求=OFF
						釜フタ昇降B排出要求=OFF						
						釜送りコンベア排出要求=OFF						
						'------------------------------------------------------						
						搬送コンベアA動作中=OFF
						搬送コンベアB動作中=OFF
						搬送コンベアC動作中=OFF
						釜送りコンベア動作中=OFF
						むらし機釜送りコンベア動作中=OFF
						搬送コンベアD動作中=OFF
						搬送コンベアE動作中=OFF
						搬送コンベアF動作中=OFF
						釜フタ昇降装置A動作中=OFF
						釜反転入口動作中=OFF
						洗浄入口リフト動作中=OFF
						洗浄入口搬送動作中=OFF
						洗浄ユニット動作中=OFF
						洗浄タンク動作中=OFF
						洗浄コンベア搬送動作中=OFF
						洗浄出口搬送動作中=OFF
						釜フタ昇降装置B動作中=OFF
						'------------------------------------------------------						
						
					end if	
				end if				
				'-------------------------------------------------------------------------------------
				
			end if


	'==================================================================================================================
	'【 原点異常 】
	
	
		else
			自動搬送手動切替済み=OFF
			自動搬送手動許可step=0
			自動搬送手動要求=OFF
		
			if ResetFlg then

				浸漬タンクAユニットOrgErr=OFF
				浸漬タンクBユニットOrgErr=OFF
				計水ユニットOrgErr=OFF
				ならし装置OrgErr=OFF
				蓋被せユニットOrgErr=OFF
				蓋取りユニットOrgErr=OFF
				ごはん検知OrgErr=OFF
				バキュームユニットOrgErr=OFF
				ほぐし機AユニットOrgErr=OFF
				ほぐし機BユニットOrgErr=OFF
				搬送コンベアAOrgErr=OFF
				搬送コンベアBOrgErr=OFF
				搬送コンベアCOrgErr=OFF
				釜送りコンベアOrgErr=OFF
				むらし機釜送りコンベアOrgErr=OFF
				搬送コンベアDOrgErr=OFF
				搬送コンベアEOrgErr=OFF
				搬送コンベアFOrgErr=OFF
				洗浄入口リフトOrgErr=OFF
				洗浄入口搬送OrgErr=OFF
				洗浄ユニットOrgErr=OFF
				'洗浄タンクOrgErr=OFF
				洗浄コンベア搬送OrgErr=OFF
				洗浄出口搬送OrgErr=OFF
				釜フタ昇降装置BOrgErr=OFF
				むらし出口OrgErr=OFF
				
				OtherOrgErr=OFF

			end if
			
		end if
	'==================================================================================================================
	'【 タイムアウトエラー処理 】
	' タイムアウトエラーは”ResetFlg"発効後、 継続運転が可能
	else
			自動搬送手動切替済み=OFF
			自動搬送手動許可step=0
			自動搬送手動要求=OFF

			自動搬送AutoRun=OFF

			浸漬タンクAユニットAutoRun=OFF
			浸漬タンクBユニットAutoRun=OFF
			計水ユニットAutoRun=OFF
			ならし装置AutoRun=OFF
			蓋被せユニットAutoRun=OFF
			蓋取りユニットAutoRun=OFF
			ごはん検知AutoRun=OFF
			バキュームユニットAutoRun=OFF
			ほぐし機AユニットAutoRun=OFF
			ほぐし機BユニットAutoRun=OFF
			搬送コンベアAAutoRun=OFF
			搬送コンベアBAutoRun=OFF
			搬送コンベアCAutoRun=OFF
			釜送りコンベアAutoRun=OFF
			むらし機釜送りコンベアAutoRun=OFF
			搬送コンベアDAutoRun=OFF
			搬送コンベアEAutoRun=OFF
			搬送コンベアFAutoRun=OFF
			洗浄入口リフトAutoRun=OFF
			洗浄入口搬送AutoRun=OFF
			洗浄ユニットAutoRun=OFF
			洗浄タンクAutoRun=OFF
			洗浄コンベア搬送AutoRun=OFF
			洗浄出口搬送AutoRun=OFF			
			釜フタ昇降装置BAutoRun=OFF
		

		select case 自動搬送ErrStep
		case 0
		
		case 1
			パトライト赤=ON

			if PB34_リセット or PB24_リセット or PB6_リセット then
				
				パトライト赤=OFF
			
				almRLY_電源確認納米庫=OFF
				almRLY_浸漬電源確認=OFF
				almRLY_搬送コンベアB電源確認=OFF
				almRLY_むらし電源確認=OFF
				almRLY12_電源確認リレー=OFF
				alm電源確認リレー_A=OFF
				alm電源確認リレー_B=OFF
				almINV4_コンベア電源確認=OFF
			
				almPS1_エアー圧力=OFF
				almPS2_エアー圧力=OFF
				almPS3_エアー圧力=OFF
			
				almTHR4_送米ポンプ=OFF
				almTHR5_洗米羽根=OFF
				almTHR1_張込用昇降機モータ=OFF
				almTHR2_排出用昇降機モータ=OFF
				almTHR3_計量機モータ=OFF
				almTHR6_搬送モータ=OFF
				almTHR7_搬送モータ=OFF
				almTHR8_搬送モータ=OFF
				almTHR12_搬送モータ=OFF
				almTHR13_搬送モータ=OFF
				almTHR14_搬送モータ=OFF
				almTHR15_搬送モータ=OFF
				almTHR34_釜送りコンベア=OFF
				almTHR43_乗移コンベア=OFF
				almTHR18_釜送りコンベア=OFF
				almTHR17_むらし機モータ=OFF
				almCSR1_ショックリレー=OFF
				almTHR19_搬送モータ=OFF
				almTHR20_搬送モータ=OFF
				almTHR21_搬送モータ=OFF
				almTHR22_搬送モータ=OFF
				almTHR24_吸引ポンプ=OFF
				almTHR25_搬送モータ=OFF
				almTHR26_搬送モータ=OFF
				almTHR28_搬送モータ=OFF
				almTHR29_搬送モータ=OFF
				almTHR30_搬送モータ=OFF
				almTHR31_反転モータ=OFF
				almTHR10_反転モータ=OFF
				
				almINV1_コンベア異常=OFF
				almINV2_コンベア異常=OFF
				almINV3_コンベア異常=OFF
				almINV4_コンベア異常=OFF
				
				インバータ1リセット=ON
				インバータ2リセット=ON
				インバータ3リセット=ON
				インバータ4リセット=ON

				
				almPH51_フタ検知=OFF
				almPH2_フタ検知=OFF
				almPH4_フタ検知=OFF
				almPH53_フタ検知=OFF
				almPH6_フタ検知=OFF
				almPH12_フタ検知=OFF
				almPH14_フタ検知=OFF
				almPH16_フタ検知=OFF
				almPH18_フタ検知=OFF
				almPH20_フタ検知=OFF
				almPH24_フタ検知=OFF
				almPH26_フタ検知=OFF
				almPH28_フタ検知=OFF
				almPH30_フタ検知=OFF
				almPH33_フタ検知=OFF
				almPH35_フタ検知=OFF
				almPH37_フタ検知=OFF
				almPH49_フタ検知=OFF
				almPH42_フタ検知=OFF
				almPH44_フタ検知=OFF
				almPH46_フタ検知=OFF
				almPH8_フタ検知=OFF
				almPH10_フタ検知=OFF
				almPH40_フタ検知=OFF

				inc(自動搬送ErrStep)

			end if

		case 2
			if OtherErrStep=0 then
				自動搬送ErrStep=0
			end if
			
		end select

	end if
	
	'==================================================================================================================
	'【 非常停止処理（その場停止） 】
else
	自動搬送手動切替済み=OFF
	自動搬送手動許可step=0
	自動搬送手動要求=OFF
	
	
	select case 自動搬送EmgStep
	case 0
	case 1
		'非常停止処理
		ESPBL1_非常停止=CR2006
		PBL22_自動運転=OFF
		page非常停止表示=ON

		inc(自動搬送EmgStep)
	case 2
		ESPBL1_非常停止=CR2006

		if PB34_リセット or PB24_リセット or PB6_リセット then
			almESPB5_非常停止=OFF
			almESPB1_非常停止=OFF
			almESPB2_非常停止=OFF
			almESPB3_非常停止IN=OFF
			almESPB4_非常停止IN=OFF
			almPB26_コンベア停止=OFF
			almPB27_コンベア停止=OFF
			almPB28_コンベア停止=OFF
			almPB29_コンベア停止=OFF

			ESPBL1_非常停止=OFF
			inc(自動搬送EmgStep)
		end if

	case 3

		page非常停止表示=OFF
		ESPBL1_非常停止=OFF
		PBL22_自動運転=CR2006
		if ldp(PB22_自動運転) then
			StartFlg=ON
			自動搬送AutoRun=OFF
			inc(自動搬送EmgStep)
		end if		

	case 4
		PBL22_自動運転=OFF
		EmgFlg=OFF	
		inc(自動搬送EmgStep)
		
	case 5	
		if 前処理工程EmgStep=0 and  OtherEmgStep=0 and not(PB22_自動運転) then
			StartFlg=OFF
			自動搬送ErrStep=0
			自動搬送EmgStep=0
		end if
		
	end select

end if
