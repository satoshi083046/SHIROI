'タイム計測
'----------------------------------------------
'バルブが駆動してからオートスイッチ検知までの時間を計測します。

if 駆動時間測定 then
	'-----------------------------------------------
	'| 浸漬タンク  ｜
	'-----------------------------------------------
	if SV12_送米切換バルブA側 then
		if not(XSW9_送米切換A側) then
			if LDP(CR2004) then
				inc(cntXSW9_送米切換A側)
			end if
		else 
			if cntXSW9_送米切換A側>0 and cntXSW9_送米切換A側<>jdgXSW9_送米切換A側 then
				passtimXSW9_送米切換A側_val=cntXSW9_送米切換A側*10
				jdgXSW9_送米切換A側=cntXSW9_送米切換A側
			end if				
		end if
	else
		cntXSW9_送米切換A側=0
	end if
	if SV13_送米切換バルブB側 then
		if not(XSW10_送米切換B側) then
			if LDP(CR2004) then
				inc(cntXSW10_送米切換B側)
			end if
		else 
			if cntXSW10_送米切換B側>0 and cntXSW10_送米切換B側<>jdgXSW10_送米切換B側 then
				passtimXSW10_送米切換B側_val=cntXSW10_送米切換B側*10
				jdgXSW10_送米切換B側=cntXSW10_送米切換B側
			end if				
		end if
	else
		cntXSW10_送米切換B側=0
	end if
	'-----------------------------------------------
	if SV2_充填バルブ開A then
		if not(XSW1_充填バルブ開A) then
			if LDP(CR2004) then
				inc(cntXSW1_充填バルブ開A)
			end if
		else 
			if cntXSW1_充填バルブ開A>0 and cntXSW1_充填バルブ開A<>jdgXSW1_充填バルブ開A then
				passtimXSW1_充填バルブ開A_val=cntXSW1_充填バルブ開A*10
				jdgXSW1_充填バルブ開A=cntXSW1_充填バルブ開A
			end if				
		end if
	else
		cntXSW1_充填バルブ開A=0
	end if
	if not(SV2_充填バルブ開A) then
		if not(XSW2_充填バルブ閉A) then
			if LDP(CR2004) then
				inc(cntXSW2_充填バルブ閉A)
			end if
		else 
			if cntXSW2_充填バルブ閉A>0 and cntXSW2_充填バルブ閉A<>jdgXSW2_充填バルブ閉A then
				passtimXSW2_充填バルブ閉A_val=cntXSW2_充填バルブ閉A*10
				jdgXSW2_充填バルブ閉A=cntXSW2_充填バルブ閉A
			end if				
		end if
	else
		cntXSW2_充填バルブ閉A=0
	end if
	'-----------------------------------------------
	if SV4_水切りシャッター開A then
		if not(XSW3_水切りシャッター開A) then
			if LDP(CR2004) then
				inc(cntXSW3_水切りシャッター開A)
			end if
		else 
			if cntXSW3_水切りシャッター開A>0 and cntXSW3_水切りシャッター開A<>jdgXSW3_水切りシャッター開A then
				passtimXSW3_水切りシャッター開A_val=cntXSW3_水切りシャッター開A*10
				jdgXSW3_水切りシャッター開A=cntXSW3_水切りシャッター開A
			end if				
		end if
	else
		cntXSW3_水切りシャッター開A=0
	end if
	if SV5_水切りシャッター閉A then
		if not(XSW4_水切りシャッター閉A) then
			if LDP(CR2004) then
				inc(cntXSW4_水切りシャッター閉A)
			end if				
		else 
			if cntXSW4_水切りシャッター閉A>0 and cntXSW4_水切りシャッター閉A<>jdgXSW4_水切りシャッター閉A then
				passtimXSW4_水切りシャッター閉A_val=cntXSW4_水切りシャッター閉A*10
				jdgXSW4_水切りシャッター閉A=cntXSW4_水切りシャッター閉A
			end if				
		end if
	else
		cntXSW4_水切りシャッター閉A=0
	end if
	'-----------------------------------------------
	if SV7_充填バルブ開B then
		if not(XSW5_充填バルブ開B) then
			if LDP(CR2004) then
				inc(cntXSW5_充填バルブ開B)
			end if
		else 
			if cntXSW5_充填バルブ開B>0 and cntXSW5_充填バルブ開B<>jdgXSW5_充填バルブ開B then
				passtimXSW5_充填バルブ開B_val=cntXSW5_充填バルブ開B*10
				jdgXSW5_充填バルブ開B=cntXSW5_充填バルブ開B
			end if				
		end if
	else
		cntXSW5_充填バルブ開B=0
	end if
	if not(SV7_充填バルブ開B) then
		if not(XSW6_充填バルブ閉B) then
			if LDP(CR2004) then
				inc(cntXSW6_充填バルブ閉B)
			end if
		else 
			if cntXSW6_充填バルブ閉B>0 and cntXSW6_充填バルブ閉B<>jdgXSW6_充填バルブ閉B then
				passtimXSW6_充填バルブ閉B_val=cntXSW6_充填バルブ閉B*10
				jdgXSW6_充填バルブ閉B=cntXSW6_充填バルブ閉B
			end if				
		end if
	else
		cntXSW6_充填バルブ閉B=0
	end if
	'-----------------------------------------------
	if SV9_水切りシャッター開B then
		if not(XSW7_水切りシャッター開B) then
			if LDP(CR2004) then
				inc(cntXSW7_水切りシャッター開B)
			end if
		else 
			if cntXSW7_水切りシャッター開B>0 and cntXSW7_水切りシャッター開B<>jdgXSW7_水切りシャッター開B then
				passtimXSW7_水切りシャッター開B_val=cntXSW7_水切りシャッター開B*10
				jdgXSW7_水切りシャッター開B=cntXSW7_水切りシャッター開B
			end if				
		end if
	else
		cntXSW7_水切りシャッター開B=0
	end if
	if SV10_水切りシャッター閉B then
		if not(XSW8_水切りシャッター閉B) then
			if LDP(CR2004) then
				inc(cntXSW8_水切りシャッター閉B)
			end if
		else 
			if cntXSW8_水切りシャッター閉B>0 and cntXSW8_水切りシャッター閉B<>jdgXSW8_水切りシャッター閉B then
				passtimXSW8_水切りシャッター閉B_val=cntXSW8_水切りシャッター閉B*10
				jdgXSW8_水切りシャッター閉B=cntXSW8_水切りシャッター閉B
			end if				
		end if
	else
		cntXSW8_水切りシャッター閉B=0
	end if
	'-----------------------------------------------
	'| ならし装置  ｜
	'-----------------------------------------------
	if SV27_ならし前進 then
		if not(XSW28_ならし前進端) then
			if LDP(CR2004) then
				inc(cntXSW28_ならし前進端)
			end if
		else 
			if cntXSW28_ならし前進端>0 and cntXSW28_ならし前進端<>jdgXSW28_ならし前進端 then
				passtimXSW28_ならし前進端_val=cntXSW28_ならし前進端*10
				jdgXSW28_ならし前進端=cntXSW28_ならし前進端
			end if				
		end if
	else
		cntXSW28_ならし前進端=0
	end if
	if SV28_ならし後退 then
		if not(XSW27_ならし後退端) then
			if LDP(CR2004) then
				inc(cntXSW27_ならし後退端)
			end if
		else 
			if cntXSW27_ならし後退端>0 and cntXSW27_ならし後退端<>jdgXSW27_ならし後退端 then
				passtimXSW27_ならし後退端_val=cntXSW27_ならし後退端*10
				jdgXSW27_ならし後退端=cntXSW27_ならし後退端
			end if				
		end if
	else
		cntXSW27_ならし後退端=0
	end if
	'-----------------------------------------------
	if SV23_ならし前進 then
		if not(XSW24_ならし前進端) then
			if LDP(CR2004) then
				inc(cntXSW24_ならし前進端)
			end if
		else 
			if cntXSW24_ならし前進端>0 and cntXSW24_ならし前進端<>jdgXSW24_ならし前進端 then
				passtimXSW24_ならし前進端_val=cntXSW24_ならし前進端*10
				jdgXSW24_ならし前進端=cntXSW24_ならし前進端
			end if				
		end if
	else
		cntXSW24_ならし前進端=0
	end if
	if SV24_ならし後退 then
		if not(XSW23_ならし後退端) then
			if LDP(CR2004) then
				inc(cntXSW23_ならし後退端)
			end if
		else 
			if cntXSW23_ならし後退端>0 and cntXSW23_ならし後退端<>jdgXSW23_ならし後退端 then
				passtimXSW23_ならし後退端_val=cntXSW23_ならし後退端*10
				jdgXSW23_ならし後退端=cntXSW23_ならし後退端
			end if				
		end if
	else
		cntXSW23_ならし後退端=0
	end if
	'-----------------------------------------------
	if SV25_ならし下降 then
		if not(XSW26_ならし下降端) then
			if LDP(CR2004) then
				inc(cntXSW26_ならし下降端)
			end if
		else 
			if cntXSW26_ならし下降端>0 and cntXSW26_ならし下降端<>jdgXSW26_ならし下降端 then
				passtimXSW26_ならし下降端_val=cntXSW26_ならし下降端*10
				jdgXSW26_ならし下降端=cntXSW26_ならし下降端
			end if				
		end if
	else
		cntXSW26_ならし下降端=0
	end if
	if SV26_ならし上昇 then
		if not(XSW25_ならし上昇端) then
			if LDP(CR2004) then
				inc(cntXSW25_ならし上昇端)
			end if
		else 
			if cntXSW25_ならし上昇端>0 and cntXSW25_ならし上昇端<>jdgXSW25_ならし上昇端 then
				passtimXSW25_ならし上昇端_val=cntXSW25_ならし上昇端*10
				jdgXSW25_ならし上昇端=cntXSW25_ならし上昇端
			end if				
		end if
	else
		cntXSW25_ならし上昇端=0
	end if
	'-----------------------------------------------
	'| フタ被せ装置  ｜
	'-----------------------------------------------
'	if SV64_釜位置 then
'		if XSW25_ならし上昇端 or XSW112_釜位置左後退端 then
'			if LDP(CR2004) then
'				inc(cntXSW111_釜位置右後退端)
'			end if
'		else 
'			if cntXSW111_釜位置右後退端>0 and cntXSW111_釜位置右後退端<>jdgXSW111_釜位置右後退端 then
'				passtimXSW111_釜位置右後退端_val=cntXSW111_釜位置右後退端*10
'				passtimXSW112_釜位置左後退端_val=cntXSW111_釜位置右後退端*10
'				jdgXSW111_釜位置右後退端=cntXSW111_釜位置右後退端
'			end if				
'		end if
'	else
'		cntXSW111_釜位置右後退端=0
'	end if

	passtimXSW111_釜位置右後退端_val=500
	passtimXSW112_釜位置左後退端_val=500

	'-----------------------------------------------
	if SV38_クランプ then
		if not(XSW43_クランプ) then
			if LDP(CR2004) then
				inc(cntXSW43_クランプ)
			end if
		else 
			if cntXSW43_クランプ>0 and cntXSW43_クランプ<>jdgXSW43_クランプ then
				passtimXSW43_クランプ_val=cntXSW43_クランプ*10
				jdgXSW43_クランプ=cntXSW43_クランプ
			end if				
		end if
	else
		cntXSW43_クランプ=0
	end if
	if SV39_アンクランプ then
		if not(XSW44_アンクランプ) then
			if LDP(CR2004) then
				inc(cntXSW44_アンクランプ)
			end if
		else 
			if cntXSW44_アンクランプ>0 and cntXSW44_アンクランプ<>jdgXSW44_アンクランプ then
				passtimXSW44_アンクランプ_val=cntXSW44_アンクランプ*10
				jdgXSW44_アンクランプ=cntXSW44_アンクランプ
			end if				
		end if
	else
		cntXSW44_アンクランプ=0
	end if
	'-----------------------------------------------
	if SV35_シリンダ下降A then
		if not(XSW40_シリンダ下降端A) then
			if LDP(CR2004) then
				inc(cntXSW40_シリンダ下降端A)
			end if
		else 
			if cntXSW40_シリンダ下降端A>0 and cntXSW40_シリンダ下降端A<>jdgXSW40_シリンダ下降端A then
				passtimXSW40_シリンダ下降端A_val=cntXSW40_シリンダ下降端A*10
				jdgXSW40_シリンダ下降端A=cntXSW40_シリンダ下降端A
			end if				
		end if
	else
		cntXSW40_シリンダ下降端A=0
	end if
	if SV36_シリンダ上昇B then
		if not(XSW39_シリンダ上昇端A) then
			if LDP(CR2004) then
				inc(cntXSW39_シリンダ上昇端A)
			end if
		else 
			if cntXSW39_シリンダ上昇端A>0 and cntXSW39_シリンダ上昇端A<>jdgXSW39_シリンダ上昇端A then
				passtimXSW39_シリンダ上昇端A_val=cntXSW39_シリンダ上昇端A*10
				jdgXSW39_シリンダ上昇端A=cntXSW39_シリンダ上昇端A
			end if				
		end if
	else
		cntXSW39_シリンダ上昇端A=0
	end if
	'-----------------------------------------------
	if SV37_シリンダ下降B then
		if not(XSW42_シリンダ下降端B) then
			if LDP(CR2004) then
				inc(cntXSW42_シリンダ下降端B)
			end if
		else 
			if cntXSW42_シリンダ下降端B>0 and cntXSW42_シリンダ下降端B<>jdgXSW42_シリンダ下降端B then
				passtimXSW42_シリンダ下降端B_val=cntXSW42_シリンダ下降端B*10
				jdgXSW42_シリンダ下降端B=cntXSW42_シリンダ下降端B
			end if				
		end if
	else
		cntXSW42_シリンダ下降端B=0
	end if
	if SV36_シリンダ上昇B then
		if not(XSW41_シリンダ上昇端B) then
			if LDP(CR2004) then
				inc(cntXSW41_シリンダ上昇端B)
			end if
		else 
			if cntXSW41_シリンダ上昇端B>0 and cntXSW41_シリンダ上昇端B<>jdgXSW41_シリンダ上昇端B then
				passtimXSW41_シリンダ上昇端B_val=cntXSW41_シリンダ上昇端B*10
				jdgXSW41_シリンダ上昇端B=cntXSW41_シリンダ上昇端B
			end if				
		end if
	else
		cntXSW41_シリンダ上昇端B=0
	end if
	'-----------------------------------------------
	' | フタ取り装置 ｜
	'-----------------------------------------------
	if SV50_クランプ then
		if not(XSW60_クランプ) then
			if LDP(CR2004) then
				inc(cntXSW60_クランプ)
			end if
		else 
			if cntXSW60_クランプ>0 and cntXSW60_クランプ<>jdgXSW60_クランプ then
				passtimXSW60_クランプ_val=cntXSW60_クランプ*10
				jdgXSW60_クランプ=cntXSW60_クランプ
			end if				
		end if
	else
		cntXSW60_クランプ=0
	end if
	if SV49_アンクランプ then
		if not(XSW59_アンクランプ) then
			if LDP(CR2004) then
				inc(cntXSW59_アンクランプ)
			end if
		else 
			if cntXSW59_アンクランプ>0 and cntXSW59_アンクランプ<>jdgXSW59_アンクランプ then
				passtimXSW59_アンクランプ_val=cntXSW59_アンクランプ*10
				jdgXSW59_アンクランプ=cntXSW59_アンクランプ
			end if				
		end if
	else
		cntXSW59_アンクランプ=0
	end if
	'-----------------------------------------------
	if SV46_シリンダ下降A then
		if not(XSW56_シリンダ下降端A) then
			if LDP(CR2004) then
				inc(cntXSW56_シリンダ下降端A)
			end if
		else 
			if cntXSW56_シリンダ下降端A>0 and cntXSW56_シリンダ下降端A<>jdgXSW56_シリンダ下降端A then
				passtimXSW56_シリンダ下降端A_val=cntXSW56_シリンダ下降端A*10
				jdgXSW56_シリンダ下降端A=cntXSW56_シリンダ下降端A
			end if				
		end if
	else
		cntXSW56_シリンダ下降端A=0
	end if
	if SV45_シリンダ上昇A then
		if not(XSW55_シリンダ上昇端A) then
			if LDP(CR2004) then
				inc(cntXSW55_シリンダ上昇端A)
			end if
		else 
			if cntXSW55_シリンダ上昇端A>0 and cntXSW55_シリンダ上昇端A<>jdgXSW55_シリンダ上昇端A then
				passtimXSW55_シリンダ上昇端A_val=cntXSW55_シリンダ上昇端A*10
				jdgXSW55_シリンダ上昇端A=cntXSW55_シリンダ上昇端A
			end if				
		end if
	else
		cntXSW55_シリンダ上昇端A=0
	end if
	'-----------------------------------------------
	if SV48_シリンダ下降B then
		if not(XSW58_シリンダ下降端B) then
			if LDP(CR2004) then
				inc(cntXSW58_シリンダ下降端B)
			end if
		else 
			if cntXSW58_シリンダ下降端B>0 and cntXSW58_シリンダ下降端B<>jdgXSW58_シリンダ下降端B then
				passtimXSW58_シリンダ下降端B_val=cntXSW58_シリンダ下降端B*10
				jdgXSW58_シリンダ下降端B=cntXSW58_シリンダ下降端B
			end if				
		end if
	else
		cntXSW58_シリンダ下降端B=0
	end if
	if SV47_シリンダ上昇B then
		if not(XSW57_シリンダ上昇端B) then
			if LDP(CR2004) then
				inc(cntXSW57_シリンダ上昇端B)
			end if
		else 
			if cntXSW57_シリンダ上昇端B>0 and cntXSW57_シリンダ上昇端B<>jdgXSW57_シリンダ上昇端B then
				passtimXSW57_シリンダ上昇端B_val=cntXSW57_シリンダ上昇端B*10
				jdgXSW57_シリンダ上昇端B=cntXSW57_シリンダ上昇端B
			end if				
		end if
	else
		cntXSW57_シリンダ上昇端B=0
	end if
	'-----------------------------------------------
	' | ごはん検知 ｜
	'-----------------------------------------------
	if SV58_シリンダ then
		if not(XSW80_シリンダ下降端) then
			if LDP(CR2004) then
				inc(cntXSW80_シリンダ下降端)
			end if
		else 
			if cntXSW80_シリンダ下降端>0 and cntXSW80_シリンダ下降端<>jdgXSW80_シリンダ下降端 then
				passtimXSW80_シリンダ下降端_val=cntXSW80_シリンダ下降端*10
				jdgXSW80_シリンダ下降端=cntXSW80_シリンダ下降端
			end if				
		end if
	else
		cntXSW80_シリンダ下降端=0
	end if
	if not(SV58_シリンダ) then
		if not(XSW73_シリンダ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW73_シリンダ上昇端)
			end if
		else 
			if cntXSW73_シリンダ上昇端>0 and cntXSW73_シリンダ上昇端<>jdgXSW73_シリンダ上昇端 then
				passtimXSW73_シリンダ上昇端_val=cntXSW73_シリンダ上昇端*10
				jdgXSW73_シリンダ上昇端=cntXSW73_シリンダ上昇端
			end if				
		end if
	else
		cntXSW73_シリンダ上昇端=0
	end if
	'-----------------------------------------------
	' | ﾊﾞｷｭｰﾑ装置 ｜
	'-----------------------------------------------
	if SV52_シリンダ then
		if not(XSW62_シリンダ下降端) then
			if LDP(CR2004) then
				inc(cntXSW62_シリンダ下降端)
			end if
		else 
			if cntXSW62_シリンダ下降端>0 and cntXSW62_シリンダ下降端<>jdgXSW62_シリンダ下降端 then
				passtimXSW62_シリンダ下降端_val=cntXSW62_シリンダ下降端*10
				jdgXSW62_シリンダ下降端=cntXSW62_シリンダ下降端
			end if				
		end if
	else
		cntXSW62_シリンダ下降端=0
	end if
	if not(SV52_シリンダ) then
		if not(XSW61_シリンダ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW61_シリンダ上昇端)
			end if
		else 
			if cntXSW61_シリンダ上昇端>0 and cntXSW61_シリンダ上昇端<>jdgXSW61_シリンダ上昇端 then
				passtimXSW61_シリンダ上昇端_val=cntXSW61_シリンダ上昇端*10
				jdgXSW61_シリンダ上昇端=cntXSW61_シリンダ上昇端
			end if				
		end if
	else
		cntXSW61_シリンダ上昇端=0
	end if

'-----------------------------------------------
' | コンベア ストッパー、クランプ ｜
'-----------------------------------------------

	'-----------------------------------------------
	' | 釜フタ昇降装置B ｜
	'-----------------------------------------------
	if SV100_リフト下降 then
		if not(XSW17_リフト下降端) then
			if LDP(CR2004) then
				inc(cntXSW17_リフト下降端)
			end if
		else 
			if cntXSW17_リフト下降端>0 and cntXSW17_リフト下降端<>jdgXSW17_リフト下降端 then
				passtimXSW17_リフト下降端_val=cntXSW17_リフト下降端*10
				jdgXSW17_リフト下降端=cntXSW17_リフト下降端
			end if				
		end if
	else
		cntXSW17_リフト下降端=0
	end if
	if SV20_リフト上昇 then
		if not(XSW18_リフト上昇端) then
			if LDP(CR2004) then
				inc(cntXSW18_リフト上昇端)
			end if
		else 
			if cntXSW18_リフト上昇端>0 and cntXSW18_リフト上昇端<>jdgXSW18_リフト上昇端 then
				passtimXSW18_リフト上昇端_val=cntXSW18_リフト上昇端*10
				jdgXSW18_リフト上昇端=cntXSW18_リフト上昇端
			end if				
		end if
	else
		cntXSW18_リフト上昇端=0
	end if
	'-----------------------------------------------
	' | 搬送コンベアA ｜
	'-----------------------------------------------
	if SV14_ストッパ then
		if not(XSW12_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW12_ストッパ上昇端)
			end if
		else 
			if cntXSW12_ストッパ上昇端>0 and cntXSW12_ストッパ上昇端<>jdgXSW12_ストッパ上昇端 then
				passtimXSW12_ストッパ上昇端_val=cntXSW12_ストッパ上昇端*10
				jdgXSW12_ストッパ上昇端=cntXSW12_ストッパ上昇端
			end if				
		end if
	else
		cntXSW12_ストッパ上昇端=0
	end if
	if not(SV14_ストッパ) then
		if not(XSW11_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW11_ストッパ下降端)
			end if
		else 
			if cntXSW11_ストッパ下降端>0 and cntXSW11_ストッパ下降端<>jdgXSW11_ストッパ下降端 then
				passtimXSW11_ストッパ下降端_val=cntXSW11_ストッパ下降端*10
				jdgXSW11_ストッパ下降端=cntXSW11_ストッパ下降端
			end if				
		end if
	else
		cntXSW11_ストッパ下降端=0
	end if
	'-----------------------------------------------
	if SV15_ストッパ then
		if not(XSW14_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW14_ストッパ上昇端)
			end if
		else 
			if cntXSW14_ストッパ上昇端>0 and cntXSW14_ストッパ上昇端<>jdgXSW14_ストッパ上昇端 then
				passtimXSW14_ストッパ上昇端_val=cntXSW14_ストッパ上昇端*10
				jdgXSW14_ストッパ上昇端=cntXSW14_ストッパ上昇端
			end if				
		end if
	else
		cntXSW14_ストッパ上昇端=0
	end if
	if not(SV15_ストッパ) then
		if not(XSW13_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW13_ストッパ下降端)
			end if
		else 
			if cntXSW13_ストッパ下降端>0 and cntXSW13_ストッパ下降端<>jdgXSW13_ストッパ下降端 then
				passtimXSW13_ストッパ下降端_val=cntXSW13_ストッパ下降端*10
				jdgXSW13_ストッパ下降端=cntXSW13_ストッパ下降端
			end if				
		end if
	else
		cntXSW13_ストッパ下降端=0
	end if
	'-----------------------------------------------
	' | 搬送コンベアB ｜
	'-----------------------------------------------
	if SV16_リフト then
		if not(XSW16_リフト上昇端) then
			if LDP(CR2004) then
				inc(cntXSW16_リフト上昇端)
			end if
		else 
			if cntXSW16_リフト上昇端>0 and cntXSW16_リフト上昇端<>jdgXSW16_リフト上昇端 then
				passtimXSW16_リフト上昇端_val=cntXSW16_リフト上昇端*10
				jdgXSW16_リフト上昇端=cntXSW16_リフト上昇端
			end if				
		end if
	else
		cntXSW16_リフト上昇端=0
	end if
	if not(SV16_リフト) then
		if not(XSW15_リフト下降端) then
			if LDP(CR2004) then
				inc(cntXSW15_リフト下降端)
			end if
		else 
			if cntXSW15_リフト下降端>0 and cntXSW15_リフト下降端<>jdgXSW15_リフト下降端 then
				passtimXSW15_リフト下降端_val=cntXSW15_リフト下降端*10
				jdgXSW15_リフト下降端=cntXSW15_リフト下降端
			end if				
		end if
	else
		cntXSW15_リフト下降端=0
	end if
	'-----------------------------------------------
	if SV21_ストッパ then
		if not(XSW20_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW20_ストッパ上昇端)
			end if
		else 
			if cntXSW20_ストッパ上昇端>0 and cntXSW20_ストッパ上昇端<>jdgXSW20_ストッパ上昇端 then
				passtimXSW20_ストッパ上昇端_val=cntXSW20_ストッパ上昇端*10
				jdgXSW20_ストッパ上昇端=cntXSW20_ストッパ上昇端
			end if				
		end if
	else
		cntXSW20_ストッパ上昇端=0
	end if
	if not(SV21_ストッパ) then
		if not(XSW19_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW19_ストッパ下降端)
			end if
		else 
			if cntXSW19_ストッパ下降端>0 and cntXSW19_ストッパ下降端<>jdgXSW19_ストッパ下降端 then
				passtimXSW19_ストッパ下降端_val=cntXSW19_ストッパ下降端*10
				jdgXSW19_ストッパ下降端=cntXSW19_ストッパ下降端
			end if				
		end if
	else
		cntXSW19_ストッパ下降端=0
	end if
	'-----------------------------------------------
	if SV22_ストッパ then
		if not(XSW22_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW22_ストッパ上昇端)
			end if
		else 
			if cntXSW22_ストッパ上昇端>0 and cntXSW22_ストッパ上昇端<>jdgXSW22_ストッパ上昇端 then
				passtimXSW22_ストッパ上昇端_val=cntXSW22_ストッパ上昇端*10
				jdgXSW22_ストッパ上昇端=cntXSW22_ストッパ上昇端
			end if				
		end if
	else
		cntXSW22_ストッパ上昇端=0
	end if
	if not(SV22_ストッパ) then
		if not(XSW21_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW21_ストッパ下降端)
			end if
		else 
			if cntXSW21_ストッパ下降端>0 and cntXSW21_ストッパ下降端<>jdgXSW21_ストッパ下降端 then
				passtimXSW21_ストッパ下降端_val=cntXSW21_ストッパ下降端*10
				jdgXSW21_ストッパ下降端=cntXSW21_ストッパ下降端
			end if				
		end if
	else
		cntXSW21_ストッパ下降端=0
	end if
	'-----------------------------------------------
	' | 搬送コンベアC ｜
	'-----------------------------------------------
	if SV33_リフト then
		if not(XSW38_リフト上昇端) then
			if LDP(CR2004) then
				inc(cntXSW38_リフト上昇端)
			end if
		else 
			if cntXSW38_リフト上昇端>0 and cntXSW38_リフト上昇端<>jdgXSW38_リフト上昇端 then
				passtimXSW38_リフト上昇端_val=cntXSW38_リフト上昇端*10
				jdgXSW38_リフト上昇端=cntXSW38_リフト上昇端
			end if				
		end if
	else
		cntXSW38_リフト上昇端=0
	end if
	if not(SV33_リフト) then
		if not(XSW37_リフト下降端) then
			if LDP(CR2004) then
				inc(cntXSW37_リフト下降端)
			end if
		else 
			if cntXSW37_リフト下降端>0 and cntXSW37_リフト下降端<>jdgXSW37_リフト下降端 then
				passtimXSW37_リフト下降端_val=cntXSW37_リフト下降端*10
				jdgXSW37_リフト下降端=cntXSW37_リフト下降端
			end if				
		end if
	else
		cntXSW37_リフト下降端=0
	end if
	'-----------------------------------------------
	if SV65_ストッパ then
		if not(XSW75_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW75_ストッパ上昇端)
			end if
		else 
			if cntXSW75_ストッパ上昇端>0 and cntXSW75_ストッパ上昇端<>jdgXSW75_ストッパ上昇端 then
				passtimXSW75_ストッパ上昇端_val=cntXSW75_ストッパ上昇端*10
				jdgXSW75_ストッパ上昇端=cntXSW75_ストッパ上昇端
			end if				
		end if
	else
		cntXSW75_ストッパ上昇端=0
	end if	
	if not(SV65_ストッパ) then
		if not(XSW74_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW74_ストッパ下降端)
			end if
		else 
			if cntXSW74_ストッパ下降端>0 and cntXSW74_ストッパ下降端<>jdgXSW74_ストッパ下降端 then
				passtimXSW74_ストッパ下降端_val=cntXSW74_ストッパ下降端*10
				jdgXSW74_ストッパ下降端=cntXSW74_ストッパ下降端
			end if				
		end if
	else
		cntXSW74_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	if SV31_クランプ then
		if not(XSW34_クランプ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW34_クランプ上昇端)
			end if
		else 
			if cntXSW34_クランプ上昇端>0 and cntXSW34_クランプ上昇端<>jdgXSW34_クランプ上昇端 then
				passtimXSW34_クランプ上昇端_val=cntXSW34_クランプ上昇端*10
				jdgXSW34_クランプ上昇端=cntXSW34_クランプ上昇端
			end if				
		end if
	else
		cntXSW34_クランプ上昇端=0
	end if	
	if not(SV31_クランプ) then
		if not(XSW33_クランプ下降端) then
			if LDP(CR2004) then
				inc(cntXSW33_クランプ下降端)
			end if
		else 
			if cntXSW33_クランプ下降端>0 and cntXSW33_クランプ下降端<>jdgXSW33_クランプ下降端 then
				passtimXSW33_クランプ下降端_val=cntXSW33_クランプ下降端*10
				jdgXSW33_クランプ下降端=cntXSW33_クランプ下降端
			end if				
		end if
	else
		cntXSW33_クランプ下降端=0
	end if	
	'-----------------------------------------------
	if SV29_ストッパ then
		if not(XSW30_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW30_ストッパ上昇端)
			end if
		else 
			if cntXSW30_ストッパ上昇端>0 and cntXSW30_ストッパ上昇端<>jdgXSW30_ストッパ上昇端 then
				passtimXSW30_ストッパ上昇端_val=cntXSW30_ストッパ上昇端*10
				jdgXSW30_ストッパ上昇端=cntXSW30_ストッパ上昇端
			end if				
		end if
	else
		cntXSW30_ストッパ上昇端=0
	end if	
	if not(SV29_ストッパ) then
		if not(XSW29_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW29_ストッパ下降端)
			end if
		else 
			if cntXSW29_ストッパ下降端>0 and cntXSW29_ストッパ下降端<>jdgXSW29_ストッパ下降端 then
				passtimXSW29_ストッパ下降端_val=cntXSW29_ストッパ下降端*10
				jdgXSW29_ストッパ下降端=cntXSW29_ストッパ下降端
			end if				
		end if
	else
		cntXSW29_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	if SV32_クランプ then
		if not(XSW36_クランプ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW36_クランプ上昇端)
			end if
		else 
			if cntXSW36_クランプ上昇端>0 and cntXSW36_クランプ上昇端<>jdgXSW36_クランプ上昇端 then
				passtimXSW36_クランプ上昇端_val=cntXSW36_クランプ上昇端*10
				jdgXSW36_クランプ上昇端=cntXSW36_クランプ上昇端
			end if				
		end if
	else
		cntXSW36_クランプ上昇端=0
	end if	
	
	if not(SV32_クランプ) then
		if not(XSW35_クランプ下降端) then
			if LDP(CR2004) then
				inc(cntXSW35_クランプ下降端)
			end if
		else 
			if cntXSW35_クランプ下降端>0 and cntXSW35_クランプ下降端<>jdgXSW35_クランプ下降端 then
				passtimXSW35_クランプ下降端_val=cntXSW35_クランプ下降端*10
				jdgXSW35_クランプ下降端=cntXSW35_クランプ下降端
			end if				
		end if
	else
		cntXSW35_クランプ下降端=0
	end if	
	'-----------------------------------------------
	if SV30_ストッパ then
		if not(XSW32_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW32_ストッパ上昇端)
			end if
		else 
			if cntXSW32_ストッパ上昇端>0 and cntXSW32_ストッパ上昇端<>jdgXSW32_ストッパ上昇端 then
				passtimXSW32_ストッパ上昇端_val=cntXSW32_ストッパ上昇端*10
				jdgXSW32_ストッパ上昇端=cntXSW32_ストッパ上昇端
			end if				
		end if
	else
		cntXSW32_ストッパ上昇端=0
	end if	
	
	if not(SV30_ストッパ) then
		if not(XSW31_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW31_ストッパ下降端)
			end if
		else 
			if cntXSW31_ストッパ下降端>0 and cntXSW31_ストッパ下降端<>jdgXSW31_ストッパ下降端 then
				passtimXSW31_ストッパ下降端_val=cntXSW31_ストッパ下降端*10
				jdgXSW31_ストッパ下降端=cntXSW31_ストッパ下降端
			end if				
		end if
	else
		cntXSW31_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	' | 搬送コンベアD ｜
	'-----------------------------------------------
	if SV41_リフト then
		if not(XSW48_リフト上昇端) then
			if LDP(CR2004) then
				inc(cntXSW48_リフト上昇端)
			end if
		else 
			if cntXSW48_リフト上昇端>0 and cntXSW48_リフト上昇端<>jdgXSW48_リフト上昇端 then
				passtimXSW48_リフト上昇端_val=cntXSW48_リフト上昇端*10
				jdgXSW48_リフト上昇端=cntXSW48_リフト上昇端
			end if				
		end if
	else
		cntXSW48_リフト上昇端=0
	end if	
	
	if not(SV41_リフト) then
		if not(XSW47_リフト下降端) then
			if LDP(CR2004) then
				inc(cntXSW47_リフト下降端)
			end if
		else 
			if cntXSW47_リフト下降端>0 and cntXSW47_リフト下降端<>jdgXSW47_リフト下降端 then
				passtimXSW47_リフト下降端_val=cntXSW47_リフト下降端*10
				jdgXSW47_リフト下降端=cntXSW47_リフト下降端
			end if				
		end if
	else
		cntXSW47_リフト下降端=0
	end if	
	'-----------------------------------------------
	if SV40_ストッパ then
		if not(XSW46_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW46_ストッパ上昇端)
			end if
		else 
			if cntXSW46_ストッパ上昇端>0 and cntXSW46_ストッパ上昇端<>jdgXSW46_ストッパ上昇端 then
				passtimXSW46_ストッパ上昇端_val=cntXSW46_ストッパ上昇端*10
				jdgXSW46_ストッパ上昇端=cntXSW46_ストッパ上昇端
			end if				
		end if
	else
		cntXSW46_ストッパ上昇端=0
	end if	
	
	if not(SV40_ストッパ) then
		if not(XSW45_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW45_ストッパ下降端)
			end if
		else 
			if cntXSW45_ストッパ下降端>0 and cntXSW45_ストッパ下降端<>jdgXSW45_ストッパ下降端 then
				passtimXSW45_ストッパ下降端_val=cntXSW45_ストッパ下降端*10
				jdgXSW45_ストッパ下降端=cntXSW45_ストッパ下降端
			end if				
		end if
	else
		cntXSW45_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	if SV57_バキュームリフト then
		if not(XSW72_バキューマリフト上昇端) then
			if LDP(CR2004) then
				inc(cntXSW72_バキューマリフト上昇端)
			end if
		else 
			if cntXSW72_バキューマリフト上昇端>0 and cntXSW72_バキューマリフト上昇端<>jdgXSW72_バキューマリフト上昇端 then
				passtimXSW72_バキューマリフト上昇端_val=cntXSW72_バキューマリフト上昇端*10
				jdgXSW72_バキューマリフト上昇端=cntXSW72_バキューマリフト上昇端
			end if				
		end if
	else
		cntXSW72_バキューマリフト上昇端=0
	end if	
	
	if not(SV57_バキュームリフト) then
		if not(XSW71_バキューマリフト下降端) then
			if LDP(CR2004) then
				inc(cntXSW71_バキューマリフト下降端)
			end if
		else 
			if cntXSW71_バキューマリフト下降端>0 and cntXSW71_バキューマリフト下降端<>jdgXSW71_バキューマリフト下降端 then
				passtimXSW71_バキューマリフト下降端_val=cntXSW71_バキューマリフト下降端*10
				jdgXSW71_バキューマリフト下降端=cntXSW71_バキューマリフト下降端
			end if				
		end if
	else
		cntXSW71_バキューマリフト下降端=0
	end if	
	'-----------------------------------------------
	if SV42_ストッパ then
		if not(XSW50_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW50_ストッパ上昇端)
			end if
		else 
			if cntXSW50_ストッパ上昇端>0 and cntXSW50_ストッパ上昇端<>jdgXSW50_ストッパ上昇端 then
				passtimXSW50_ストッパ上昇端_val=cntXSW50_ストッパ上昇端*10
				jdgXSW50_ストッパ上昇端=cntXSW50_ストッパ上昇端
			end if				
		end if
	else
		cntXSW50_ストッパ上昇端=0
	end if	
	
	if not(SV42_ストッパ) then
		if not(XSW49_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW49_ストッパ下降端)
			end if
		else 
			if cntXSW49_ストッパ下降端>0 and cntXSW49_ストッパ下降端<>jdgXSW49_ストッパ下降端 then
				passtimXSW49_ストッパ下降端_val=cntXSW49_ストッパ下降端*10
				jdgXSW49_ストッパ下降端=cntXSW49_ストッパ下降端
			end if				
		end if
	else
		cntXSW49_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	if SV43_ストッパ then
		if not(XSW52_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW52_ストッパ上昇端)
			end if
		else 
			if cntXSW52_ストッパ上昇端>0 and cntXSW52_ストッパ上昇端<>jdgXSW52_ストッパ上昇端 then
				passtimXSW52_ストッパ上昇端_val=cntXSW52_ストッパ上昇端*10
				jdgXSW52_ストッパ上昇端=cntXSW52_ストッパ上昇端
			end if				
		end if
	else
		cntXSW52_ストッパ上昇端=0
	end if	
	
	if not(SV43_ストッパ) then
		if not(XSW51_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW51_ストッパ下降端)
			end if
		else 
			if cntXSW51_ストッパ下降端>0 and cntXSW51_ストッパ下降端<>jdgXSW51_ストッパ下降端 then
				passtimXSW51_ストッパ下降端_val=cntXSW51_ストッパ下降端*10
				jdgXSW51_ストッパ下降端=cntXSW51_ストッパ下降端
			end if				
		end if
	else
		cntXSW51_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	if SV44_リフト then
		if not(XSW54_リフト上昇端) then
			if LDP(CR2004) then
				inc(cntXSW54_リフト上昇端)
			end if
		else 
			if cntXSW54_リフト上昇端>0 and cntXSW54_リフト上昇端<>jdgXSW54_リフト上昇端 then
				passtimXSW54_リフト上昇端_val=cntXSW54_リフト上昇端*10
				jdgXSW54_リフト上昇端=cntXSW54_リフト上昇端
			end if				
		end if
	else
		cntXSW54_リフト上昇端=0
	end if	
	
	if not(SV44_リフト) then
		if not(XSW53_リフト下降端) then
			if LDP(CR2004) then
				inc(cntXSW53_リフト下降端)
			end if
		else 
			if cntXSW53_リフト下降端>0 and cntXSW53_リフト下降端<>jdgXSW53_リフト下降端 then
				passtimXSW53_リフト下降端_val=cntXSW53_リフト下降端*10
				jdgXSW53_リフト下降端=cntXSW53_リフト下降端
			end if				
		end if
	else
		cntXSW53_リフト下降端=0
	end if	
	'-----------------------------------------------
	' | 搬送コンベアE ｜
	'-----------------------------------------------
	if SV53_ストッパ then
		if not(XSW64_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW64_ストッパ上昇端)
			end if
		else 
			if cntXSW64_ストッパ上昇端>0 and cntXSW64_ストッパ上昇端<>jdgXSW64_ストッパ上昇端 then
				passtimXSW64_ストッパ上昇端_val=cntXSW64_ストッパ上昇端*10
				jdgXSW64_ストッパ上昇端=cntXSW64_ストッパ上昇端
			end if				
		end if
	else
		cntXSW64_ストッパ上昇端=0
	end if	
	
	if not(SV53_ストッパ) then
		if not(XSW63_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW63_ストッパ下降端)
			end if
		else 
			if cntXSW63_ストッパ下降端>0 and cntXSW63_ストッパ下降端<>jdgXSW63_ストッパ下降端 then
				passtimXSW63_ストッパ下降端_val=cntXSW63_ストッパ下降端*10
				jdgXSW63_ストッパ下降端=cntXSW63_ストッパ下降端
			end if				
		end if
	else
		cntXSW63_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	if SV54_ストッパ then
		if not(XSW66_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW66_ストッパ上昇端)
			end if
		else 
			if cntXSW66_ストッパ上昇端>0 and cntXSW66_ストッパ上昇端<>jdgXSW66_ストッパ上昇端 then
				passtimXSW66_ストッパ上昇端_val=cntXSW66_ストッパ上昇端*10
				jdgXSW66_ストッパ上昇端=cntXSW66_ストッパ上昇端
			end if				
		end if
	else
		cntXSW66_ストッパ上昇端=0
	end if	
	
	if not(SV54_ストッパ) then
		if not(XSW65_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW65_ストッパ下降端)
			end if
		else 
			if cntXSW65_ストッパ下降端>0 and cntXSW65_ストッパ下降端<>jdgXSW65_ストッパ下降端 then
				passtimXSW65_ストッパ下降端_val=cntXSW65_ストッパ下降端*10
				jdgXSW65_ストッパ下降端=cntXSW65_ストッパ下降端
			end if				
		end if
	else
		cntXSW65_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	' | 搬送コンベアF ｜
	'-----------------------------------------------
	if SV56_ストッパ then
		if not(XSW70_ストッパ上昇端) then
			if LDP(CR2004) then
				inc(cntXSW70_ストッパ上昇端)
			end if
		else 
			if cntXSW70_ストッパ上昇端>0 and cntXSW70_ストッパ上昇端<>jdgXSW70_ストッパ上昇端 then
				passtimXSW70_ストッパ上昇端_val=cntXSW70_ストッパ上昇端*10
				jdgXSW70_ストッパ上昇端=cntXSW70_ストッパ上昇端
			end if				
		end if
	else
		cntXSW70_ストッパ上昇端=0
	end if	
	
	if not(SV56_ストッパ) then
		if not(XSW69_ストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW69_ストッパ下降端)
			end if
		else 
			if cntXSW69_ストッパ下降端>0 and cntXSW69_ストッパ下降端<>jdgXSW69_ストッパ下降端 then
				passtimXSW69_ストッパ下降端_val=cntXSW69_ストッパ下降端*10
				jdgXSW69_ストッパ下降端=cntXSW69_ストッパ下降端
			end if				
		end if
	else
		cntXSW69_ストッパ下降端=0
	end if	
	'-----------------------------------------------
	if SV55_リフト then
		if not(XSW68_リフト上昇端) then
			if LDP(CR2004) then
				inc(cntXSW68_リフト上昇端)
			end if
		else 
			if cntXSW68_リフト上昇端>0 and cntXSW68_リフト上昇端<>jdgXSW68_リフト上昇端 then
				passtimXSW68_リフト上昇端_val=cntXSW68_リフト上昇端*10
				jdgXSW68_リフト上昇端=cntXSW68_リフト上昇端
			end if				
		end if
	else
		cntXSW68_リフト上昇端=0
	end if	
	
	if not(SV55_リフト) then
		if not(XSW67_リフト下降端) then
			if LDP(CR2004) then
				inc(cntXSW67_リフト下降端)
			end if
		else 
			if cntXSW67_リフト下降端>0 and cntXSW67_リフト下降端<>jdgXSW67_リフト下降端 then
				passtimXSW67_リフト下降端_val=cntXSW67_リフト下降端*10
				jdgXSW67_リフト下降端=cntXSW67_リフト下降端
			end if				
		end if
	else
		cntXSW67_リフト下降端=0
	end if	
	'-----------------------------------------------
	' | 洗浄コンベア ｜
	'-----------------------------------------------	
	if not(SV71_釜フタストッパ) then
		if not(XSW85_釜フタストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW85_釜フタストッパ下降端)
			end if
		else 
			if cntXSW85_釜フタストッパ下降端>0 and cntXSW85_釜フタストッパ下降端<>jdgXSW85_釜フタストッパ下降端 then
				passtimXSW85_釜フタストッパ下降端_val=cntXSW85_釜フタストッパ下降端*10
				jdgXSW85_釜フタストッパ下降端=cntXSW85_釜フタストッパ下降端
			end if				
		end if
	else
		cntXSW85_釜フタストッパ下降端=0
	end if	
	'-----------------------------------------------
	if not(SV77_釜フタストッパ) then
		if not(XSW90_釜フタストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW90_釜フタストッパ下降端)
			end if
		else 
			if cntXSW90_釜フタストッパ下降端>0 and cntXSW90_釜フタストッパ下降端<>jdgXSW90_釜フタストッパ下降端 then
				passtimXSW90_釜フタストッパ下降端_val=cntXSW90_釜フタストッパ下降端*10
				jdgXSW90_釜フタストッパ下降端=cntXSW90_釜フタストッパ下降端
			end if				
		end if
	else
		cntXSW90_釜フタストッパ下降端=0
	end if	
	'-----------------------------------------------
	if not(SV83_釜フタストッパ) then
		if not(XSW95_釜フタストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW95_釜フタストッパ下降端)
			end if
		else 
			if cntXSW95_釜フタストッパ下降端>0 and cntXSW95_釜フタストッパ下降端<>jdgXSW95_釜フタストッパ下降端 then
				passtimXSW95_釜フタストッパ下降端_val=cntXSW95_釜フタストッパ下降端*10
				jdgXSW95_釜フタストッパ下降端=cntXSW95_釜フタストッパ下降端
			end if				
		end if
	else
		cntXSW95_釜フタストッパ下降端=0
	end if	
	'-----------------------------------------------
	if not(SV89_釜フタストッパ) then
		if not(XSW100_釜フタストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW100_釜フタストッパ下降端)
			end if
		else 
			if cntXSW100_釜フタストッパ下降端>0 and cntXSW100_釜フタストッパ下降端<>jdgXSW100_釜フタストッパ下降端 then
				passtimXSW100_釜フタストッパ下降端_val=cntXSW100_釜フタストッパ下降端*10
				jdgXSW100_釜フタストッパ下降端=cntXSW100_釜フタストッパ下降端
			end if				
		end if
	else
		cntXSW100_釜フタストッパ下降端=0
	end if	
	'-----------------------------------------------
	if not(SV95_釜フタストッパ) then
		if not(XSW105_釜フタストッパ下降端) then
			if LDP(CR2004) then
				inc(cntXSW105_釜フタストッパ下降端)
			end if
		else 
			if cntXSW105_釜フタストッパ下降端>0 and cntXSW105_釜フタストッパ下降端<>jdgXSW105_釜フタストッパ下降端 then
				passtimXSW105_釜フタストッパ下降端_val=cntXSW105_釜フタストッパ下降端*10
				jdgXSW105_釜フタストッパ下降端=cntXSW105_釜フタストッパ下降端
			end if				
		end if
	else
		cntXSW105_釜フタストッパ下降端=0
	end if	
	'-----------------------------------------------
		


end if

