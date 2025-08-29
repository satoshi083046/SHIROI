'カレンダータイマー
'===================================================================================================================
'
'  カレンダータイマー
'
'===================================================================================================================
if CR2008 then
	if 0 then
		修正時刻・年=16
		修正時刻・月=10
		修正時刻・日=13
		修正時刻・時=15
		修正時刻・分=30
		修正時刻・秒=00
		修正時刻・曜日=4
	end if
end if


if 0 then

	経過時間・年=0
	経過時間・月=0
	経過時間・日=0
	経過時間・時=0
	経過時間・分=0
	経過時間・秒=0
	残時間・年=0
	残時間・月=0
	残時間・日=0
	残時間・時=0
	残時間・分=0
	残時間・秒=0
	予約設定時刻・時=0
	予約設定時刻・分=0

end if
'------------------------------------------------------------------------------------------------------------
'電源ON wait

tmr(wait_tim,#10)

if wait_tim.B then
'------------------------------------------------------------------------------------------------------------
'現在時刻の取得
get年=CM700
get月=CM701
get日=CM702
get時=CM703
get分=CM704
get秒=CM705
get曜日=CM706

select case get曜日 'http://www.asahi-net.or.jp/~ax2s-kmtn/ref/jisx0208.html
case 0
	get曜日コード=$93FA 'http://kanji.free.fr/kanji.php?sjis=93FA
case 1
	get曜日コード=$8C8E 'http://kanji.free.fr/kanji.php?sjis=8C8E
case 2
	get曜日コード=$89CE 'http://kanji.free.fr/kanji.php?sjis=89CE
case 3
	get曜日コード=$9085 'http://kanji.free.fr/kanji.php?sjis=9085
case 4
	get曜日コード=$96D8 'http://kanji.free.fr/kanji.php?sjis=96D8
case 5
	get曜日コード=$8BE0 'http://kanji.free.fr/kanji.php?sjis=8BE0
case 6
	get曜日コード=$9379 'http://kanji.free.fr/kanji.php?sjis=9379
end select

'------------------------------------------------------------------------------------------------------------
'選択スイッチと設定

if 0<=予約設定時刻・時 and 23>=予約設定時刻・時 and 0<=予約設定時刻・分 and 59>=予約設定時刻・分 then

	予約・時=予約設定時刻・時
	予約・分=予約設定時刻・分
	set時.U=予約・時.U		
	set分.U=予約・分.U
	set秒=0

	select case get曜日
	case 0
		if 予約設定・日 then
			予約設定flg=ON
	 		set年=CM700
			set月=CM701
			set日=CM702
		else
			予約設定flg=OFF
		end if
	case 1
		if 予約設定・月 then
			予約設定flg=ON		
	 		set年=CM700
			set月=CM701
			set日=CM702
		else
			予約設定flg=OFF
		end if
	case 2
		if 予約設定・火 then
			予約設定flg=ON
	 		set年=CM700
			set月=CM701
			set日=CM702
		else
			予約設定flg=OFF
		end if
	case 3
		if 予約設定・水 then
			予約設定flg=ON
			set年=CM700
			set月=CM701
			set日=CM702
		else
			予約設定flg=OFF
		end if
	case 4
		if 予約設定・木 then
			予約設定flg=ON
	 		set年=CM700
			set月=CM701
			set日=CM702
		else
			予約設定flg=OFF	
		end if
	case 5
		if 予約設定・金 then
			予約設定flg=ON
	 		set年=CM700
			set月=CM701
			set日=CM702
		else
			予約設定flg=OFF	
		end if
	case 6
		if 予約設定・土 then
			予約設定flg=ON	
	 		set年=CM700
			set月=CM701
			set日=CM702
		else
			予約設定flg=OFF
		end if
	end select
else
	予約設定時刻・時=予約・時
	予約設定時刻・分=予約・分


end if
'------------------------------------------------------------------------------------------------------------
'設定時刻と現在時刻の演算
'------------------------------------------------------------------------------------------------------------
if	予約設定flg=ON then

	if	0<=(sec(get年) -sec(set年)) then
		
		ONTIME=sec(set年)<=sec(get年) and (sec(set年)+59) >sec(get年) 'ON状態: 現在時刻~59秒間
		
		pasttime.D=sec(get年) -sec(set年) '設定からの経過時間
		rsec(pasttime.D,経過時間・年)
		if 1<=経過時間・月 then
			dec(経過時間・月)
		end if
		if 1<=経過時間・日 then
			dec(経過時間・日)
		end if
		
		残時間・年=0
		残時間・月=0
		残時間・日=0
		残時間・時=0
		残時間・分=0
		残時間・秒=0
	else
		ONTIME=OFF
		pasttime.D=sec(set年) -sec(get年) '設定までの残時間
		rsec(pasttime.D,残時間・年)
		if 1<=残時間・月 then
			dec(残時間・月)
		end if
		if 1<=残時間・日 then
			dec(残時間・日)
		end if

		経過時間・年=0
		経過時間・月=0
		経過時間・日=0
		経過時間・時=0
		経過時間・分=0
		経過時間・秒=0
	end if
else
		残時間・年=0
		残時間・月=0
		残時間・日=0
		残時間・時=0
		残時間・分=0
		残時間・秒=0
		経過時間・年=0
		経過時間・月=0
		経過時間・日=0
		経過時間・時=0
		経過時間・分=0
		経過時間・秒=0

		ONTIME=OFF
end if
'------------------------------------------------------------------------------------------------------------
'配米経過時間の計測
if ldp(運転準備完了) then
	配米pasttime=0
	
	配米経過時間・年=0
	配米経過時間・月=0
	配米経過時間・日=0
	配米経過時間・時=0
	配米経過時間・分=0
	配米経過時間・秒=0	

	set配米・年=get年	
	set配米・月=get月	
	set配米・日=get日
	set配米・時=get時
	set配米・分=get分
	set配米・秒=get秒	

end if

if 運転準備完了 then
	配米pasttime.D=sec(get年)-sec(set配米・年) '設定からの経過時間
	rsec(配米pasttime.D,配米経過時間・年)
else
	配米経過時間・年=0
	配米経過時間・月=0
	配米経過時間・日=0
	配米経過時間・時=0
	配米経過時間・分=0
	配米経過時間・秒=0
	

end if
'------------------------------------------------------------------------------------------------------------
'浸漬時間計測タンクA

'set浸漬時間A・年

'浸漬時間タンクA・年
'浸漬時間タンクA・月
'浸漬時間タンクA・日
'浸漬時間タンクA・時
'浸漬時間タンクA・分
'浸漬時間タンクA・秒
'浸漬時間タンクA・曜日

tmr(pnlPB強制米有A or PDL2_パドルセンサー下限A or FLOS3_LMT121,tim米有A,300)
tmr(pnlPB強制米無しA or (not(PDL2_パドルセンサー下限A) and not(FLOS3_LMT121)),tim米無しA,300)

if tim米有A then
	浸漬時間計測タンクA=ON
else if tim米無しA then
	浸漬時間計測タンクA=OFF
end if

if ldp(浸漬時間計測タンクA) then

	set浸漬時間A・年=get年	
	set浸漬時間A・月=get月	
	set浸漬時間A・日=get日
	set浸漬時間A・時=get時
	set浸漬時間A・分=get分
	set浸漬時間A・秒=get秒	

end if

if 浸漬時間計測タンクA then

	浸漬時間タンクA経過.D=sec(get年)-sec(set浸漬時間A・年) '設定からの経過時間
	rsec(浸漬時間タンクA経過.D,浸漬時間タンクA・年)

else
	浸漬時間タンクA・年=0
	浸漬時間タンクA・月=0
	浸漬時間タンクA・日=0
	浸漬時間タンクA・時=0
	浸漬時間タンクA・分=0
	浸漬時間タンクA・秒=0
end if


'------------------------------------------------------------------------------------------------------------
'浸漬時間計測タンクB

'set浸漬時間B・年

'浸漬時間タンクB・年
'浸漬時間タンクB・月
'浸漬時間タンクB・日
'浸漬時間タンクB・時
'浸漬時間タンクB・分
'浸漬時間タンクB・秒
'浸漬時間タンクB・曜日

tmr(pnlPB強制米有B or PDL4_パドルセンサー下限B or FLOS4_LMT121,tim米有B,300)
tmr(pnlPB強制米無しB or (not(PDL4_パドルセンサー下限B) and not(FLOS4_LMT121)),tim米無しB,300)

if tim米有B then
	浸漬時間計測タンクB=ON
else if tim米無しB then
	浸漬時間計測タンクB=OFF
end if

if ldp(浸漬時間計測タンクB) then

	set浸漬時間B・年=get年	
	set浸漬時間B・月=get月	
	set浸漬時間B・日=get日
	set浸漬時間B・時=get時
	set浸漬時間B・分=get分
	set浸漬時間B・秒=get秒	

end if

if 浸漬時間計測タンクB then

	浸漬時間タンクB経過.D=sec(get年)-sec(set浸漬時間B・年) '設定からの経過時間
	rsec(浸漬時間タンクB経過.D,浸漬時間タンクB・年)
	
else
	浸漬時間タンクB・年=0
	浸漬時間タンクB・月=0
	浸漬時間タンクB・日=0
	浸漬時間タンクB・時=0
	浸漬時間タンクB・分=0
	浸漬時間タンクB・秒=0
end if




'------------------------------------------------------------------------------------------------------------
'現在時刻の設定
'------------------------------------------------------------------------------------------------------------
if LDP(Difu時刻設定) then
	修正時刻・年=get年
	修正時刻・月=get月
	修正時刻・日=get日
	修正時刻・時=get時
	修正時刻・分=get分
	修正時刻・秒=get秒
	修正時刻・曜日=get曜日
	
	IND_修正日曜日=OFF
	IND_修正月曜日=OFF
	IND_修正火曜日=OFF
	IND_修正水曜日=OFF
	IND_修正木曜日=OFF
	IND_修正金曜日=OFF
	IND_修正土曜日=OFF	
	select case  修正時刻・曜日
		case 0
			IND_修正日曜日=ON
		case 1
			IND_修正月曜日=ON
		case 2
			IND_修正火曜日=ON
		case 3
			IND_修正水曜日=ON
		case 4
			IND_修正木曜日=ON
		case 5
			IND_修正金曜日=ON
		case 6
			IND_修正土曜日=ON
	end select

end if

if LDP(IND_修正日曜日) then
	IND_修正日曜日=ON
	IND_修正月曜日=OFF
	IND_修正火曜日=OFF
	IND_修正水曜日=OFF
	IND_修正木曜日=OFF
	IND_修正金曜日=OFF
	IND_修正土曜日=OFF
else if LDP(IND_修正月曜日) then
	IND_修正日曜日=OFF
	IND_修正月曜日=ON
	IND_修正火曜日=OFF
	IND_修正水曜日=OFF
	IND_修正木曜日=OFF
	IND_修正金曜日=OFF
	IND_修正土曜日=OFF
else if LDP(IND_修正火曜日) then
	IND_修正日曜日=OFF
	IND_修正月曜日=OFF
	IND_修正火曜日=ON
	IND_修正水曜日=OFF
	IND_修正木曜日=OFF
	IND_修正金曜日=OFF
	IND_修正土曜日=OFF
else if LDP(IND_修正水曜日) then
	IND_修正日曜日=OFF
	IND_修正月曜日=OFF
	IND_修正火曜日=OFF
	IND_修正水曜日=ON
	IND_修正木曜日=OFF
	IND_修正金曜日=OFF
	IND_修正土曜日=OFF
else if LDP(IND_修正木曜日) then
	IND_修正日曜日=OFF
	IND_修正月曜日=OFF
	IND_修正火曜日=OFF
	IND_修正水曜日=OFF
	IND_修正木曜日=ON
	IND_修正金曜日=OFF
	IND_修正土曜日=OFF
else if LDP(IND_修正金曜日) then
	IND_修正日曜日=OFF
	IND_修正月曜日=OFF
	IND_修正火曜日=OFF
	IND_修正水曜日=OFF
	IND_修正木曜日=OFF
	IND_修正金曜日=ON
	IND_修正土曜日=OFF
else if LDP(IND_修正土曜日) then
	IND_修正日曜日=OFF
	IND_修正月曜日=OFF
	IND_修正火曜日=OFF
	IND_修正水曜日=OFF
	IND_修正木曜日=OFF
	IND_修正金曜日=OFF
	IND_修正土曜日=ON
end if


if ldp(時刻設定) then
	if 16 <= 修正時刻・年 and 99>修正時刻・年 then
		if 1<=修正時刻・月  and 12>=修正時刻・月 then
		
			select case 修正時刻・月
			case 1 
				Days=31
			case 2 
				Days=29
			case 3 
				Days=31
			case 4 
				Days=30
			case 5 
				Days=31
			case 6 
				Days=30
			case 7 
				Days=31
			case 8 
				Days=31
			case 9 
				Days=30
			case 10	
				Days=31
			case 11	
				Days=30
			case 12	
				Days=31
			end select 

			if IND_修正日曜日 then
				修正時刻・曜日=0
			else if IND_修正月曜日 then
				修正時刻・曜日=1
			else if IND_修正火曜日 then
				修正時刻・曜日=2
			else if IND_修正水曜日 then
				修正時刻・曜日=3
			else if IND_修正木曜日 then
				修正時刻・曜日=4
			else if IND_修正金曜日 then
				修正時刻・曜日=5
			else if IND_修正土曜日 then
				修正時刻・曜日=6
			end if 

			if 1<=修正時刻・日 and Days>=修正時刻・日 then
				if 0<=修正時刻・時  and 23>=修正時刻・時 then
					if 0<=修正時刻・分 and 59>=修正時刻・分 then
						修正時刻・秒=0
						wtime(修正時刻・年,修正時刻・月,修正時刻・日,修正時刻・時,修正時刻・分,修正時刻・秒,修正時刻・曜日)
					end if
				end if
				
			end if
		end if
	end if

	
end if
'------------------------------------------------------------------------------------------------------------

end if 'wait_tim

