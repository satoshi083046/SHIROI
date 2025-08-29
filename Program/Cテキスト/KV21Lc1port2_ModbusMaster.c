'KV21Lc1port2_ModbusMaster
if CR2008 then
'------------------------------------------
' 各ﾕﾆｯﾄをModbusID登録
'------------------------------------------
	EDC1=#1
	EDC2=#2
	EDC3=#3
	EDC4=#4
	EDC5=#5
	EDC6=#6
	Frenic1=#10
	Frenic2=#11
	Frenic3=#12
	Frenic4=#13
	
	'洗浄ポンプ用インバータ
	'型式  FRN5.5C2S-2J 富士電機	
	Frenic10=#20
	Frenic11=#21
	Frenic12=#22
	Frenic13=#23
	Frenic14=#24
	

'使用する(1)  使用しない(0)
	EDC1USE=1
	EDC2USE=1
	EDC3USE=1
	EDC4USE=1
	EDC5USE=1
	EDC6USE=1
	Frenic1USE=1
	Frenic2USE=1
	Frenic3USE=1
	Frenic4USE=1

	Frenic10USE=1
	Frenic11USE=1
	Frenic12USE=1
	Frenic13USE=1
	Frenic14USE=1
	
end if
'------------------------------------------
'インバータのアラームリセット
'インバータがFWD信号を受けて、回転中に通信が途絶えると回転を停止してアラームを発生させます。
'解除方法： FED信号（起動リレー）をOFFにし、setS14c1=1 を送信させ、getS14c1 で 1を確認後、setS14c1=0 を送信します。

if CR2008 then

	'PLC立ち上げ時にインバータのアラームをクリアさせる。
	if Frenic1USE=1 then
		インバータ1リセット=ON
		INV1ResetStep=0
	end if
	
	if Frenic2USE=1 then
		インバータ2リセット=ON
		INV2ResetStep=0
	end if
	
	if Frenic3USE=1 then
		インバータ3リセット=ON
		INV3ResetStep=0
	end if

	if Frenic4USE=1 then
		インバータ4リセット=ON
		INV4ResetStep=0
	end if
	


	if Frenic10USE=1 then
		インバータ10リセット=ON
		INV10ResetStep=0
	end if
	if Frenic11USE=1 then
		インバータ11リセット=ON
		INV11ResetStep=0
	end if
	if Frenic12USE=1 then
		インバータ12リセット=ON
		INV12ResetStep=0
	end if
	if Frenic13USE=1 then
		インバータ13リセット=ON
		INV13ResetStep=0
	end if
	if Frenic14USE=1 then
		インバータ14リセット=ON
		INV14ResetStep=0
	end if

end if

	if インバータ1リセット then
		tmr(tim_INV1Reset,tim_INV1Reset_val)
		
		select case INV1ResetStep
		case 0
			mINV1_コンベアモータ正転=OFF
			tim_INV1Reset_val=2
			res(tim_INV1Reset)
			inc(INV1ResetStep)
			
		case 1
			if tim_INV1Reset.B then
				setS14c1=1
				inc(INV1ResetStep)
			end if
		
		case 2
			if getS14c1=1 then
				setS14c1=0
				inc(INV1ResetStep)
			end if
		
		case 3
			インバータ1リセット=OFF
		end select
	else
		INV1ResetStep=0
	end if

	if インバータ2リセット then
		tmr(tim_INV2Reset,tim_INV2Reset_val)
		
		select case INV2ResetStep
		case 0
			mINV2_コンベアモータ正転=OFF
			tim_INV2Reset_val=2
			res(tim_INV2Reset)
			inc(INV2ResetStep)
			
		case 1
			if tim_INV2Reset.B then
				setS14c2=1
				inc(INV2ResetStep)
			end if
		
		case 2
			if getS14c2=1 then
				setS14c2=0
				inc(INV2ResetStep)
			end if
		
		case 3
			インバータ2リセット=OFF
		end select
	else
		INV2ResetStep=0
	end if

	if インバータ3リセット then
		tmr(tim_INV3Reset,tim_INV3Reset_val)
		
		select case INV3ResetStep
		case 0
			mINV3_コンベアモータ正転=OFF
			tim_INV3Reset_val=2
			res(tim_INV3Reset)
			inc(INV3ResetStep)
			
		case 1
			if tim_INV3Reset.B then
				setS14c3=1
				inc(INV3ResetStep)
			end if
		
		case 2
			if getS14c3=1 then
				setS14c3=0
				inc(INV3ResetStep)
			end if
		
		case 3
			インバータ3リセット=OFF
		end select
	else
		INV3ResetStep=0
	end if
	
	if インバータ4リセット then
		tmr(tim_INV4Reset,tim_INV4Reset_val)
		
		select case INV4ResetStep
		case 0
			mINV4_インバータ正転=OFF
			tim_INV4Reset_val=2
			res(tim_INV4Reset)
			inc(INV4ResetStep)
			
		case 1
			if tim_INV4Reset.B then
				setS14c4=1
				inc(INV4ResetStep)
			end if
		
		case 2
			if getS14c4=1 then
				setS14c4=0
				inc(INV4ResetStep)
			end if
		
		case 3
			インバータ4リセット=OFF
		end select
	else
		INV4ResetStep=0
	end if

	'洗浄ポンプ

	if インバータ10リセット then
		tmr(tim_INV10Reset,tim_INV10Reset_val)
		
		select case INV10ResetStep
		case 0
			mINV10_洗浄ポンプA運転=OFF
			INV10_洗浄ポンプA洗浄=OFF
			setS05c10=1000
			tim_INV10Reset_val=2
			res(tim_INV10Reset)
			inc(INV10ResetStep)
			
		case 1
			if tim_INV10Reset.B then
				setS14c10=1
				inc(INV10ResetStep)
			end if
		
		case 2
			if getS14c10=1 then
				setS14c10=0
				inc(INV10ResetStep)
			end if
		
		case 3
			インバータ10リセット=OFF
		end select
	else
		INV10ResetStep=0
	end if

	if インバータ11リセット then
		tmr(tim_INV11Reset,tim_INV11Reset_val)
		
		select case INV11ResetStep
		case 0
			mINV11_洗浄ポンプB運転 =OFF
			INV11_洗浄ポンプB洗浄=OFF
			tim_INV11Reset_val=2
			res(tim_INV11Reset)
			inc(INV11ResetStep)
			
		case 1
			if tim_INV11Reset.B then
				setS14c11=1
				inc(INV11ResetStep)
			end if
		
		case 2
			if getS14c11=1 then
				setS14c11=0
				inc(INV11ResetStep)
			end if
		
		case 3
			インバータ11リセット=OFF
		end select
	else
		INV11ResetStep=0
	end if

	if インバータ12リセット then
		tmr(tim_INV12Reset,tim_INV12Reset_val)
		
		select case INV12ResetStep
		case 0
			mINV12_洗浄ポンプC運転=OFF
			INV12_洗浄ポンプC洗浄=OFF
			tim_INV12Reset_val=2
			res(tim_INV12Reset)
			inc(INV12ResetStep)
			
		case 1
			if tim_INV12Reset.B then
				setS14c12=1
				inc(INV12ResetStep)
			end if
		
		case 2
			if getS14c12=1 then
				setS14c12=0
				inc(INV12ResetStep)
			end if
		
		case 3
			インバータ12リセット=OFF
		end select
	else
		INV12ResetStep=0
	end if
	
	if インバータ13リセット then
		tmr(tim_INV13Reset,tim_INV13Reset_val)
		
		select case INV13ResetStep
		case 0
			mINV13_洗浄ポンプD運転=OFF
			INV13_洗浄ポンプD洗浄=OFF 
			tim_INV13Reset_val=2
			res(tim_INV13Reset)
			inc(INV13ResetStep)
			
		case 1
			if tim_INV13Reset.B then
				setS14c13=1
				inc(INV13ResetStep)
			end if
		
		case 2
			if getS14c13=1 then
				setS14c13=0
				inc(INV13ResetStep)
			end if
		
		case 3
			インバータ13リセット=OFF
		end select
	else
		INV13ResetStep=0
	end if

	if インバータ14リセット then
		tmr(tim_INV14Reset,tim_INV14Reset_val)
		
		select case INV14ResetStep
		case 0
			mINV14_洗浄ポンプE運転=OFF	
			INV14_洗浄ポンプE洗浄=OFF
			tim_INV14Reset_val=2
			res(tim_INV14Reset)
			inc(INV14ResetStep)
			
		case 1
			if tim_INV14Reset.B then
				setS14c14=1
				inc(INV14ResetStep)
			end if
		
		case 2
			if getS14c14=1 then
				setS14c14=0
				inc(INV14ResetStep)
			end if
		
		case 3
			インバータ14リセット=OFF
		end select
	else
		INV14ResetStep=0
	end if




'------------------------------------------
' test program
if 0 then
	if 1 then
		if getEDC1_SV>=100 then 
			setEDC1_SV=1
		else
			setEDC1_SV=getEDC1_SV+1
		end if
	end if

	if 1 then
		if getEDC2_SV>=100 then 
			setEDC2_SV=1
		else
			setEDC2_SV=getEDC2_SV+1
		end if
	end if

	if 1 then
		if getEDC3_SV>=100 then 
			setEDC3_SV=1
		else
			setEDC3_SV=getEDC3_SV+1
		end if
	end if
	
	if 1 then
		if getEDC4_SV>=100 then 
			setEDC4_SV=1
		else
			setEDC4_SV=getEDC4_SV+1
		end if
	end if

	if 1 then
		if getEDC5_SV>=100 then 
			setEDC5_SV=1
		else
			setEDC5_SV=getEDC5_SV+1
		end if
	end if
	
	if 1 then
		if getEDC6_SV>=100 then 
			setEDC6_SV=1
		else
			setEDC6_SV=getEDC6_SV+1
		end if
	end if

	'インバータ
	if 0 then
		random.U=RND(random.U)
		if random<6000 and random>100 then
			setS05c1=random
		end if
	else
		setS05c1=3000
		setS08c1=10
		setS09c1=10
	end if
	
	
	if 0 then
		random.U=RND(random.U)
		if random<6000 and random>100 then
			setS05c2=random
		end if
	else
		setS05c2=3000
		setS08c2=10
		setS09c2=10
	end if

	if 0 then
		random.U=RND(random.U)
		if random<6000 and random>100 then
			setS05c3=random
		end if
	else
		setS05c3=3000	
		setS08c3=10
		setS09c3=10
	end if


end if

'------------------------------------------
' KV-L21Vのアドレス
' R38000
' DM10300
'------------------------------------------
'port1
	'①KV BUILDER で使用
	'占有個数 R (1ch) 16個 	DM 0個
	'②MODBUS MASTER で使用
	'占有個数 R (2ch) 32個 	DM 600個

'port2
	Z1=380*16 + (1*16) 'port2 rlayの先頭ｱﾄﾞﾚｽ
	Z2=10300 + (0) 'port2 DMの先頭ｱﾄﾞﾚｽ
	
'------------------------------------------
'Modbus Master Addres Map
'------------------------------------------
'KV-L21V	KV-N10L
'------------------------------------------
'R001:Z1	CR6601	ｺﾏﾝﾄﾞ送信
'R004:Z1	CR6604	通信設定変更要求
'R101:Z1	CR6701	実行完了
'R102:Z1	CR6702	実行失敗
'R103:Z1	CR6703	実行中
'R104:Z1	CR6704	通信設定変更完了
'R108:Z1	CR6708	ER状態
'R109:Z1	CR6709	CD状態
'R110:Z1	CR6710	DR状態
'R111:Z1	CR6711	RS状態
'R112:Z1	CR6712	CS状態
'------------------------------------------
'DM20000	エラーコード
'DM001:Z2	CM6001	ｽﾚｰﾌﾞ局番
'DM002:Z2	CM6002	ﾌｧﾝｸｼｮﾝｺｰﾄﾞ
'DM003:Z2	CM6003	ｻﾌﾞﾌｧﾝｸｼｮﾝｺｰﾄﾞ
'DM006:Z2	CM6006	ﾃﾞｰﾀ格納単位
'DM007:Z2	CM6007	読み出し先頭ｱﾄﾞﾚｽ
'DM008:Z2	CM6008	読み出し点数
'DM310:Z2	CM6310	読み出しﾊﾞｲﾄ数
'DM311~563:Z2	CM6311~CM6563	読み出しBuff[0] ~ [252]
'DM009:Z2		CM6009	書き込み先頭ｱﾄﾞﾚｽ
'DM010:Z2		CM6010	書き込み点数
'DM011~263:Z2	CM6011~CM6263	書き込みﾃﾞｰﾀBuff[0] ~ [252]
'DM300:Z2	CM6300	ｴﾗｰｺｰﾄﾞ
'------------------------------------------
'DM570:Z2	CM6570	受信ﾀｲﾑｱｳﾄ
'DM571:Z2	CM6571	送信ｳｪｲﾄ
'DM572:Z2	CM6572	ﾘﾄﾗｲ回数
'DM573:Z2	CM6573	ﾘﾄﾗｲｳｪｲﾄ
'DM574:Z2	CM6574	ﾌﾞﾛｰﾄﾞｷｬｽﾄﾃﾞｨﾚｲﾀｲﾑ
'DM580:Z2	CM6580	設定済み受信ﾀｲﾑｱｳﾄ
'DM581:Z2	CM6581	設定済み送信ｳｪｲﾄ
'DM582:Z2	CM6582	設定済みﾘﾄﾗｲ回数
'DM583:Z2	CM6583	設定済みﾘﾄﾗｲｳｪｲﾄ
'DM584:Z2	CM6584	設定済みﾌﾞﾛｰﾄﾞｷｬｽﾄﾃﾞｨﾚｲﾀｲﾑ
'------------------------------------------

	'2秒以内に接続が回避されたらエラーをクリアして回復する
	if  errcode=0 and DispMsg1Item<>0 then
		tmr(true, retry_reset_wait, 20)
		if retry_reset_wait.B then
			DispMsg1Item=0
		end if
	else
		res(true,retry_reset_wait.B)
	end if


	'--------------------------
	if EDC1USE=1 and not(DispMsg1Item=EDC1) and RLY12_電源確認リレー then
		EDC1Act=1
	else 
		EDC1Act=0
	end if
	'--------------------------
	if EDC2USE=1 and not(DispMsg1Item=EDC2) and RLY12_電源確認リレー then
		EDC2Act=1
	else 
		EDC2Act=0
	end if
	'--------------------------
	if EDC3USE=1 and not(DispMsg1Item=EDC3) and RLY12_電源確認リレー then
		EDC3Act=1
	else 
		EDC3Act=0
	end if
	'--------------------------
	if EDC4USE=1 and not(DispMsg1Item=EDC4) and RLY12_電源確認リレー then
		EDC4Act=1
	else 
		EDC4Act=0
	end if
	'--------------------------
	if EDC5USE=1 and not(DispMsg1Item=EDC5) and RLY12_電源確認リレー then
		EDC5Act=1
	else 
		EDC5Act=0
	end if
	'--------------------------
	if EDC6USE=1 and not(DispMsg1Item=EDC6) and RLY12_電源確認リレー then
		EDC6Act=1
	else 
		EDC6Act=0
	end if
	'--------------------------
	if Frenic1USE=1 and not(DispMsg1Item=Frenic1) and RLY12_電源確認リレー then
		Frenic1Act=1
	else
		Frenic1Act=0
	end if
	'--------------------------
	if Frenic2USE=1 and not(DispMsg1Item=Frenic2) and RLY12_電源確認リレー then
		Frenic2Act=1
	else
		Frenic2Act=0
	end if
	'--------------------------
	if Frenic3USE=1 and not(DispMsg1Item=Frenic3) and RLY12_電源確認リレー then
		Frenic3Act=1
	else
		Frenic3Act=0
	end if
	'--------------------------
	if Frenic4USE=1 and not(DispMsg1Item=Frenic4) and INV4_コンベア電源確認 then
		Frenic4Act=1
	else
		Frenic4Act=0
	end if
	'--------------------------
	if Frenic10USE=1 and not(DispMsg1Item=Frenic10) and RLY12_電源確認リレー and MC35_洗浄ポンプA then
		Frenic10Act=1
	else
		Frenic10Act=0
	end if
	'--------------------------
	if Frenic11USE=1 and not(DispMsg1Item=Frenic11) and RLY12_電源確認リレー and MC36_洗浄ポンプB then
		Frenic11Act=1
	else
		Frenic11Act=0
	end if
	'--------------------------
	if Frenic12USE=1 and not(DispMsg1Item=Frenic12) and RLY12_電源確認リレー and MC37_洗浄ポンプC then
		Frenic12Act=1
	else
		Frenic12Act=0
	end if
	'--------------------------
	if Frenic13USE=1 and not(DispMsg1Item=Frenic13) and RLY12_電源確認リレー and MC38_洗浄ポンプD then
		Frenic13Act=1
	else
		Frenic13Act=0
	end if
	'--------------------------
	if Frenic14USE=1 and not(DispMsg1Item=Frenic14) and RLY12_電源確認リレー and MC39_洗浄ポンプE then
		Frenic14Act=1
	else
		Frenic14Act=0
	end if
	'--------------------------
	ModbusC1AlmID=DispMsg1Item

'------------------------------------------
' 通信設定変更
'------------------------------------------
' 駆動ﾄﾘｶﾞ  CR2008 電源ON時
' R004:Z1	通信設定変更要求
' R104:Z1	通信設定変更完了

	if CR2008 then

		DM570:Z2=10	'受信ﾀｲﾑｱｳﾄ (初期値 2000ms=200x10ms)
		DM571:Z2=0	'送信ｳｪｲﾄ (初期値 x10ms)
		DM572:Z2=2	'ﾘﾄﾗｲ回数 (初期値 0回)
		DM573:Z2=20	'ﾘﾄﾗｲｳｪｲﾄ (初期値 300ms=30x10ms)
		DM574:Z2=200	'ﾌﾞﾛｰﾄﾞｷｬｽﾄﾃﾞｨﾚｲﾀｲﾑ (初期値 200)
		
		'--- 読み出し専用 格納ﾚｼﾞｽﾀ ---
		'DM580:Z2	'設定済み受信ﾀｲﾑｱｳﾄ
		'DM581:Z2	'設定済み送信ｳｪｲﾄﾀｲﾑ
		'DM582:Z2	'設定済みﾘﾄﾗｲｳｪｲﾄ
		'DM583:Z2	'設定済みﾘﾄﾗｲｳｪｲﾄﾀｲﾑ
		'DM584:Z2	'設定済みﾌﾞﾛｰﾄﾞｷｬｽﾄｳｪｲﾄﾀｲﾑ

		R004:Z1 = ON

		'
		setH30c1=8	
		setH30c2=8	
		setH30c3=8	
		setH30c4=8	

		setS06c1=0
		setS06c2=0
		setS06c3=0
		setS06c4=0
		
	end if
	
	if LDP(R104:Z1) then
		R004:Z1 = OFF
	end if
'------------------------------------------
'Modbusｽﾀｰﾄｱｯﾌﾟﾀｲﾏｰ
'------------------------------------------
	if not(ModbusStartWait) then
		if ldp(CR2006) then	'1s
			if ModbusStartWaitTim<3 then
				inc(ModbusStartWaitTim)
			else 
				ModbusStartWait=true
			end if
 		end if
	end if 
'---------------------------------------------------------------------------
' KV-N11L 送受信
'---------------------------------------------------------------------------
	'-----------------------------------------------------------------------
	select case readstep  '読み込み処理
	'-----------------------------------------------------------------------
		case 0
		'-------------------------------------------------------------------
		'Frenic,PanasonicSUNX mode 1レジスタ読み込み *readstackptrはword
		'-------------------------------------------------------------------
		case 1
		
			if not(R101:Z1) and not(R102:Z1) and not(R103:Z1) then
				DM006:Z2 = 0 'word type input
				DM001:Z2 = ModbusID
				DM002:Z2 = 3
				DM007:Z2 = ReadAdr
				DM008:Z2 = 1 'read count
				R001:Z1 = ON
				inc(readstep)
			end if
		
		case 2
			if LDP(R101:Z1) and not(R103:Z1) then

				if not(R102:Z1) then
					*readstackptr = DM311:Z2
				end if
				if R102:Z1 then
					errcode = DM300:Z2
				end if
				
				R001:Z1= OFF
				inc(readstep)
			end if
		case 3
			readstep=0
		'-------------------------------------------------------------------

	end select

	'-----------------------------------------------------------------------
	select case writestep '書き込み処理
	'-----------------------------------------------------------------------
		case 0
		'-------------------------------------------------------------------
		'Frenic,PanasonicSUNX mode 1レジスタ書き込み *setvalptrはword
		'-------------------------------------------------------------------
		case 1
			if not(R101:Z1) and not(R102:Z1) and not(R103:Z1) then

		        '保持レジスタ1個書き込み
				DM006:Z2 = 0  'word type input
				DM001:Z2 = ModbusID
				DM002:Z2 = 6
				DM009:Z2 = WriteAdr
				DM011:Z2 = *setvalptr
				
				R001:Z1 = ON
				inc(writestep)
			end if
		case 2
			if LDP(R101:Z1) and not(R103:Z1) then

				if not(R102:Z1) then
					*getvalptr = *setvalptr
				end if
				if R102:Z1 then
					errcode = DM300:Z2
				end if
				
				R001:Z1= OFF
				inc(writestep)
			end if
		case 3
			writestep=0

	end select

'------------------------------------------
' 電源ON時の初期化
'------------------------------------------

	if CR2008 then
	
		'--------------------------
		' ﾌﾗｸﾞｸﾘｱ
		errcode =0
		comstep =0
		readstep =0
		writestep =0
		
		readitem1=0
		readitem2=0
		readitem3=0
		readitem4=0
		readitem5=0
		readitem6=0

		readitem10=0
		readitem11=0
		readitem12=0

		getvalptr =0
		setvalptr =0
		readstackptr =0
		ReadAdr =0
		WriteAdr =0
		ModbusID =0

		'--------------------------
		adrset(true,getEDC1_SV,getvalptr)
		for loopi=0 to 3 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getEDC2_SV,getvalptr)
		for loopi=0 to 3 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getEDC3_SV,getvalptr)
		for loopi=0 to 3 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getEDC4_SV,getvalptr)
		for loopi=0 to 3 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getEDC5_SV,getvalptr)
		for loopi=0 to 3 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next
		
		adrset(true,getEDC6_SV,getvalptr)
		for loopi=0 to 3 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getS05c1,getvalptr)
		for loopi=0 to 5 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getS05c2,getvalptr)
		for loopi=0 to 5 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getS05c3,getvalptr)
		for loopi=0 to 5 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next

		adrset(true,getS05c4,getvalptr)
		for loopi=0 to 5 step 1
			*getvalptr=0
			adrinc(getvalptr)
		next
		
		'--------------------------
		ModbusStartWaitTim=0
		ModbusStartWait=false
		
	end if


'------------------------------------------
'通信回線遮断時、受信した温度ﾃﾞｰﾀを 0 ｸﾘｱ
'------------------------------------------
	if EDC1Act=0 then
		getEDC1_SV=0
		getEDC1_PV=0
	end if	
	if EDC2Act=0 then
		getEDC2_SV=0
		getEDC2_PV=0
	end if	
 	if EDC3Act=0 then
		getEDC3_SV=0
		getEDC3_PV=0
 	end if
 	if EDC4Act=0 then
		getEDC4_SV=0
		getEDC4_PV=0
 	end if
 	if EDC5Act=0 then
		getEDC5_SV=0
		getEDC5_PV=0
 	end if
 	if EDC6Act=0 then
		getEDC6_SV=0
		getEDC6_PV=0
 	end if
'------------------------------------------------------------------------------
' 通信工程
'------------------------------------------------------------------------------

	'--------------------------------------------------------------------------
	if ModbusStartWait=true and errcode= 0 then '電源時間待ち and 通信ｴﾗｰなし
	'--------------------------------------------------------------------------
	
		if  readstep=0 and writestep=0 then
			'------------------------------------------------------------------
			select case comstep '送受信工程
			'------------------------------------------------------------------

			'------------------------------------------------------------------
			' OMRON EDC
			'------------------------------------------------------------------
				case 0
					if EDC1Act=0 then
						comstep=3
					else 
						inc(comstep)
					end if
				case 1
					if EDC1Act<>0 then
						ModbusID=EDC1
						
						select case readitem1
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0 '目標値
								ReadAdr=EDCADR_SV
								adrset(true, getEDC1_SV,readstackptr)
								readstep=1
								inc(readitem1)
							case 1 '調節感度(ON_OFF制御幅)
								ReadAdr=EDCADR_HYS
								adrset(true, getEDC1_HYS,readstackptr)
								readstep=1
								inc(readitem1)
							case 2	'警報値１
								ReadAdr=EDCADR_AL1
								adrset(true, getEDC1_AL1,readstackptr)
								readstep=1
								inc(readitem1)
							case 3	'警報値２
								ReadAdr=EDCADR_AL2
								adrset(true, getEDC1_AL2,readstackptr)
								readstep=1
								inc(readitem1)
							case 4	'現在値
								ReadAdr=EDCADR_PV
								adrset(true, getEDC1_PV,readstackptr)
								readstep=1
								inc(readitem1)
							case 5	'ステータス １L
								ReadAdr=EDCADR_ST1L
								adrset(true, getEDC1_ST1L,readstackptr)
								readstep=1
								inc(readitem1)
							case 6	'ステータス １H
								ReadAdr=EDCADR_ST1H
								adrset(true, getEDC1_ST1H,readstackptr)
								readstep=1
								'inc(readitem1)

								readitem1=0
						end select
					else
						readitem1=0
					end if

					inc(comstep)

				'--------------------------------------------------------------
				case 2
					if EDC1Act<>0 then
					
						ModbusID=EDC1
						adrset(true,getEDC1_SV,getvalptr)
						adrset(true,setEDC1_SV,setvalptr)
						for loopi=0 to 3 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=EDCADR_SV
									case 1 
										'HYS=0は通信エラーになる。
										if setEDC1_HYS < 2 then
											setEDC1_HYS=2
										end if
										WriteAdr=EDCADR_HYS
									case 2 
										WriteAdr=EDCADR_AL1
									case 3
										WriteAdr=EDCADR_AL2
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			'EDC2
			'------------------------------------------------------------------
				case 3
					if EDC2Act=0 then
						comstep=6
					else 
						inc(comstep)
					end if
				case 4
					if EDC2Act<>0 then
					
						ModbusID=EDC2
						
						select case readitem2
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0 '目標値
								ReadAdr=EDCADR_SV
								adrset(true, getEDC2_SV,readstackptr)
								readstep=1
								inc(readitem2)
							case 1 '調節感度(ON_OFF制御幅)
								ReadAdr=EDCADR_HYS
								adrset(true, getEDC2_HYS,readstackptr)
								readstep=1
								inc(readitem2)
							case 2	'警報値１
								ReadAdr=EDCADR_AL1
								adrset(true, getEDC2_AL1,readstackptr)
								readstep=1
								inc(readitem2)
							case 3	'警報値２
								ReadAdr=EDCADR_AL2
								adrset(true, getEDC2_AL2,readstackptr)
								readstep=1
								inc(readitem2)
							case 4	'現在値
								ReadAdr=EDCADR_PV
								adrset(true, getEDC2_PV,readstackptr)
								readstep=1
								inc(readitem2)
							case 5	'ステータス １L
								ReadAdr=EDCADR_ST1L
								adrset(true, getEDC2_ST1L,readstackptr)
								readstep=1
								inc(readitem2)
							case 6	'ステータス １H
								ReadAdr=EDCADR_ST1H
								adrset(true, getEDC2_ST1H,readstackptr)
								readstep=1
								'inc(readitem2)

								readitem2=0
						end select
					else
						readitem2=0
					end if
					
						inc(comstep)

				'--------------------------------------------------------------
				case 5
					if EDC2Act<>0 then

						ModbusID=EDC2
						adrset(true,getEDC2_SV,getvalptr)
						adrset(true,setEDC2_SV,setvalptr)
						for loopi=0 to 3 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=EDCADR_SV
									case 1 
										'HYS=0は通信エラーになる。
										if setEDC2_HYS < 2 then
											setEDC2_HYS=2
										end if
										WriteAdr=EDCADR_HYS
									case 2 
										WriteAdr=EDCADR_AL1
									case 3
										WriteAdr=EDCADR_AL2
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next

					end if
						inc(comstep)
			'------------------------------------------------------------------
			'EDC3
			'------------------------------------------------------------------
				case 6
					if EDC3Act=0 then
						comstep=9
					else 
						inc(comstep)
					end if
				case 7
					if EDC3Act<>0 then
						ModbusID=EDC3
						
						select case readitem3
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0 '目標値
								ReadAdr=EDCADR_SV
								adrset(true, getEDC3_SV,readstackptr)
								readstep=1
								inc(readitem3)
							case 1 '調節感度(ON_OFF制御幅)
								ReadAdr=EDCADR_HYS
								adrset(true, getEDC3_HYS,readstackptr)
								readstep=1
								inc(readitem3)
							case 2	'警報値１
								ReadAdr=EDCADR_AL1
								adrset(true, getEDC3_AL1,readstackptr)
								readstep=1
								inc(readitem3)
							case 3	'警報値２
								ReadAdr=EDCADR_AL2
								adrset(true, getEDC3_AL2,readstackptr)
								readstep=1
								inc(readitem3)
							case 4	'現在値
								ReadAdr=EDCADR_PV
								adrset(true, getEDC3_PV,readstackptr)
								readstep=1
								inc(readitem3)
							case 5	'ステータス １L
								ReadAdr=EDCADR_ST1L
								adrset(true, getEDC3_ST1L,readstackptr)
								readstep=1
								inc(readitem3)
							case 6	'ステータス １H
								ReadAdr=EDCADR_ST1H
								adrset(true, getEDC3_ST1H,readstackptr)
								readstep=1
								'inc(readitem3)

								readitem3=0
						end select
					else
						readitem3=0
					end if
					
						inc(comstep)

				'--------------------------------------------------------------
				case 8
					if EDC3Act<>0 then
						ModbusID=EDC3
						adrset(true,getEDC3_SV,getvalptr)
						adrset(true,setEDC3_SV,setvalptr)
						for loopi=0 to 3 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=EDCADR_SV
									case 1 
										'HYS=0は通信エラーになる。
										if setEDC3_HYS < 2 then
											setEDC3_HYS=2
										end if
										WriteAdr=EDCADR_HYS
									case 2 
										WriteAdr=EDCADR_AL1
									case 3
										WriteAdr=EDCADR_AL2
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
					
					inc(comstep)
			'------------------------------------------------------------------
			'EDC4
			'------------------------------------------------------------------
				case 9
					if EDC4Act=0 then
						comstep=12
					else 
						inc(comstep)
					end if
				case 10
					if EDC4Act<>0 then
						ModbusID=EDC4
						
						select case readitem4
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0 '目標値
								ReadAdr=EDCADR_SV
								adrset(true, getEDC4_SV,readstackptr)
								readstep=1
								inc(readitem4)
							case 1 '調節感度(ON_OFF制御幅)
								ReadAdr=EDCADR_HYS
								adrset(true, getEDC4_HYS,readstackptr)
								readstep=1
								inc(readitem4)
							case 2	'警報値１
								ReadAdr=EDCADR_AL1
								adrset(true, getEDC4_AL1,readstackptr)
								readstep=1
								inc(readitem4)
							case 3	'警報値２
								ReadAdr=EDCADR_AL2
								adrset(true, getEDC4_AL2,readstackptr)
								readstep=1
								inc(readitem4)
							case 4	'現在値
								ReadAdr=EDCADR_PV
								adrset(true, getEDC4_PV,readstackptr)
								readstep=1
								inc(readitem4)
							case 5	'ステータス １L
								ReadAdr=EDCADR_ST1L
								adrset(true, getEDC4_ST1L,readstackptr)
								readstep=1
								inc(readitem4)
							case 6	'ステータス １H
								ReadAdr=EDCADR_ST1H
								adrset(true, getEDC4_ST1H,readstackptr)
								readstep=1
								'inc(readitem4)

								readitem4=0
						end select
					else
						readitem4=0
					end if
					inc(comstep)

				'--------------------------------------------------------------
				case 11
					if EDC4Act<>0 then
						ModbusID=EDC4
						adrset(true,getEDC4_SV,getvalptr)
						adrset(true,setEDC4_SV,setvalptr)
						for loopi=0 to 3 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=EDCADR_SV
									case 1 
										'HYS=0は通信エラーになる。
										if setEDC4_HYS < 2 then
											setEDC4_HYS=2
										end if
										WriteAdr=EDCADR_HYS
									case 2 
										WriteAdr=EDCADR_AL1
									case 3
										WriteAdr=EDCADR_AL2
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						
						inc(comstep)
			'------------------------------------------------------------------
			'EDC5
			'------------------------------------------------------------------
				case 12
					if EDC5Act=0 then
						comstep=15
					else 
						inc(comstep)
					end if
				case 13
				if EDC5Act<>5 then
					ModbusID=EDC5
					
					select case readitem5
						'-------------------------------------------------
						'設定ﾚｼﾞｽﾀの読み込み
						case 0 '目標値
							ReadAdr=EDCADR_SV
							adrset(true, getEDC5_SV,readstackptr)
							readstep=1
							inc(readitem5)
						case 1 '調節感度(ON_OFF制御幅)
							ReadAdr=EDCADR_HYS
							adrset(true, getEDC5_HYS,readstackptr)
							readstep=1
							inc(readitem5)
						case 2	'警報値１
							ReadAdr=EDCADR_AL1
							adrset(true, getEDC5_AL1,readstackptr)
							readstep=1
							inc(readitem5)
						case 3	'警報値２
							ReadAdr=EDCADR_AL2
							adrset(true, getEDC5_AL2,readstackptr)
							readstep=1
							inc(readitem5)
						case 4	'現在値
							ReadAdr=EDCADR_PV
							adrset(true, getEDC5_PV,readstackptr)
							readstep=1
							inc(readitem5)
						case 5	'ステータス １L
							ReadAdr=EDCADR_ST1L
							adrset(true, getEDC5_ST1L,readstackptr)
							readstep=1
							inc(readitem5)
						case 6	'ステータス １H
							ReadAdr=EDCADR_ST1H
							adrset(true, getEDC5_ST1H,readstackptr)
							readstep=1
							'inc(readitem5)

							readitem5=0
					end select
				else
					readitem5=0
				end if

					inc(comstep)

				'--------------------------------------------------------------
				case 14
					if EDC5Act<>0 then
						ModbusID=EDC5
						adrset(true,getEDC5_SV,getvalptr)
						adrset(true,setEDC5_SV,setvalptr)
						for loopi=0 to 3 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=EDCADR_SV
									case 1 
										'HYS=0は通信エラーになる。
										if setEDC5_HYS < 2 then
											setEDC5_HYS=2
										end if
										WriteAdr=EDCADR_HYS
									case 2 
										WriteAdr=EDCADR_AL1
									case 3
										WriteAdr=EDCADR_AL2
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						
						inc(comstep)
			'------------------------------------------------------------------
			'EDC6
			'------------------------------------------------------------------
				case 15
					if EDC6Act=0 then
						comstep=18
					else 
						inc(comstep)
					end if
				case 16
					if EDC6Act<>0 then
						ModbusID=EDC6
						
						select case readitem6
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0 '目標値
								ReadAdr=EDCADR_SV
								adrset(true, getEDC6_SV,readstackptr)
								readstep=1
								inc(readitem6)
							case 1 '調節感度(ON_OFF制御幅)
								ReadAdr=EDCADR_HYS
								adrset(true, getEDC6_HYS,readstackptr)
								readstep=1
								inc(readitem6)
							case 2	'警報値１
								ReadAdr=EDCADR_AL1
								adrset(true, getEDC6_AL1,readstackptr)
								readstep=1
								inc(readitem6)
							case 3	'警報値２
								ReadAdr=EDCADR_AL2
								adrset(true, getEDC6_AL2,readstackptr)
								readstep=1
								inc(readitem6)
							case 4	'現在値
								ReadAdr=EDCADR_PV
								adrset(true, getEDC6_PV,readstackptr)
								readstep=1
								inc(readitem6)
							case 5	'ステータス １L
								ReadAdr=EDCADR_ST1L
								adrset(true, getEDC6_ST1L,readstackptr)
								readstep=1
								inc(readitem6)
							case 6	'ステータス １H
								ReadAdr=EDCADR_ST1H
								adrset(true, getEDC6_ST1H,readstackptr)
								readstep=1
								'inc(readitem6)

								readitem6=0
						end select
					else
						readitem6=0
					end if

						inc(comstep)

				'--------------------------------------------------------------
				case 17
					if EDC6Act<>0 then
						ModbusID=EDC6
						adrset(true,getEDC6_SV,getvalptr)
						adrset(true,setEDC6_SV,setvalptr)
						for loopi=0 to 3 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=EDCADR_SV
									case 1 
										'HYS=0は通信エラーになる。
										if setEDC6_HYS < 2 then
											setEDC6_HYS=2
										end if
										WriteAdr=EDCADR_HYS
									case 2 
										WriteAdr=EDCADR_AL1
									case 3
										WriteAdr=EDCADR_AL2
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic1 
			'------------------------------------------------------------------
				case 18
					if Frenic1Act=0 then
						comstep=21
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 19
					if Frenic1Act<>0 then
						ModbusID=Frenic1

						getS05c1=getM05c1
						getS06c1=anda(getM13c1,3)


						if readitem10>100 and setS05c1<>getS05c1 then
							readitem10=100
						else 
							if readitem10>100 and setS06c1<>getS06c1 then
								readitem10=102
							end if
						end if
					
						select case readitem10
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c1,readstackptr)
								readstep=1
								inc(readitem10)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c1,readstackptr)
								readstep=1
								inc(readitem10)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c1,readstackptr)
								readstep=1
								inc(readitem10)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c1,readstackptr)
								readstep=1
								inc(readitem10)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c1,readstackptr)
								readstep=1
								readitem10=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c1,readstackptr)
								readstep=1
								inc(readitem10)
							case 101
								if getM05c1<>setS05c1 then
									dec(readitem10) '再読み込み
								else
									inc(readitem10)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c1,readstackptr)
								readstep=1
								inc(readitem10)
								
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c1,readstackptr)
								readstep=1
								inc(readitem10)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c1,readstackptr)
								readstep=1
								inc(readitem10)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c1,readstackptr)
								'readstep=1
								inc(readitem10)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c1,readstackptr)
								'readstep=1
								inc(readitem10)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c1,readstackptr)
								readstep=1
								inc(readitem10)

							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c1,readstackptr)
								readstep=1
								inc(readitem10)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c1,readstackptr)
								readstep=1
								inc(readitem10)

							case 110
								readitem10=100

						end select
						
					else
						readitem10=0
					end if
						
						inc(comstep)
				'--------------------------------------------------------------
				case 20
					if Frenic1Act<>0 then
						ModbusID=Frenic1
						'readstackptr=0
						adrset(true,getS05c1,getvalptr)
						adrset(true,setS05c1,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic2 
			'------------------------------------------------------------------
				case 21
					if Frenic2Act=0 then
						comstep=24
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 22
				if Frenic2Act<>0 then
					ModbusID=Frenic2

					getS05c2=getM05c2
					getS06c2=anda(getM13c2,3)

					if readitem11>100 and setS05c2<>getS05c2 then
						readitem11=100
					else 
						if readitem11>100 and setS06c2<>getS06c2 then
							readitem11=102
						end if
					end if
				
					select case readitem11
						'-------------------------------------------------
						'設定ﾚｼﾞｽﾀの読み込み
						case 0
							ReadAdr=ADRS05
							adrset(true,getS05c2,readstackptr)
							readstep=1
							inc(readitem11)
						case 1
							ReadAdr=ADRS06
							adrset(true,getS06c2,readstackptr)
							readstep=1
							inc(readitem11)
						case 2
							ReadAdr=ADRS08
							adrset(true,getS08c2,readstackptr)
							readstep=1
							inc(readitem11)
						case 3
							ReadAdr=ADRS09
							adrset(true,getS09c2,readstackptr)
							readstep=1
							inc(readitem11)
						case 4
							ReadAdr=ADRS14
							adrset(true,getS14c2,readstackptr)
							readstep=1
							readitem11=100
						'-------------------------------------------------
						'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
						case 100
							ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
							adrset(true,getM05c2,readstackptr)
							readstep=1
							inc(readitem11)
						case 101
							if getM05c2<>setS05c2 then
								dec(readitem11) '再読み込み
							else
								inc(readitem11)
							end if
						case 102
							ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
							adrset(true,getM13c2,readstackptr)
							readstep=1
							inc(readitem11)
						case 103
							ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
							adrset(true,getM16c2,readstackptr)
							readstep=1
							inc(readitem11)

						case 104
							ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
							adrset(true,getM17c2,readstackptr)
							readstep=1
							inc(readitem11)

						case 105
							'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
							'adrset(true,getM18c2,readstackptr)
							'readstep=1
							inc(readitem11)

						case 106
							'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
							'adrset(true,getM19c2,readstackptr)
							'readstep=1
							inc(readitem11)

						case 107
							ReadAdr=ADRM20	'累積時間
							adrset(true,getM20c2,readstackptr)
							readstep=1
							inc(readitem11)
							
						case 108
							ReadAdr=ADRM14 '運転状態
							adrset(true,getM14c2,readstackptr)
							readstep=1
							inc(readitem11)

						case 109
							ReadAdr=ADRH30
							adrset(true,getH30c2,readstackptr)
							readstep=1
							inc(readitem11)

						case 110
							readitem11=100

					end select
				else
					readitem11=0
				end if

					inc(comstep)
				'------------------------------------------------------------
				case 23
					if Frenic2Act<>0 then
						ModbusID=Frenic2
						'readstackptr=0
						adrset(true,getS05c2,getvalptr)
						adrset(true,setS05c2,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic3
			'------------------------------------------------------------------
				case 24
					if Frenic3Act=0 then
						comstep=27
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 25
					if Frenic3Act<>0 then
						ModbusID=Frenic3

						getS05c3=getM05c3
						getS06c3=anda(getM13c3,3)

						if readitem12>100 and setS05c3<>getS05c3 then
							readitem12=100
						else 
							if readitem12>100 and setS06c3<>getS06c3 then
								readitem12=102
							end if
						end if
					
						select case readitem12
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c3,readstackptr)
								readstep=1
								inc(readitem12)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c3,readstackptr)
								readstep=1
								inc(readitem12)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c3,readstackptr)
								readstep=1
								inc(readitem12)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c3,readstackptr)
								readstep=1
								inc(readitem12)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c3,readstackptr)
								readstep=1
								readitem12=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c3,readstackptr)
								readstep=1
								inc(readitem12)
							case 101
								if getM05c3<>setS05c3 then
									dec(readitem12) '再読み込み
								else
									inc(readitem12)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c3,readstackptr)
								readstep=1
								inc(readitem12)							
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c3,readstackptr)
								readstep=1
								inc(readitem12)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c3,readstackptr)
								readstep=1
								inc(readitem12)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c3,readstackptr)
								'readstep=1
								inc(readitem12)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c3,readstackptr)
								'readstep=1
								inc(readitem12)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c3,readstackptr)
								readstep=1
								inc(readitem12)
								
							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c3,readstackptr)
								readstep=1
								inc(readitem12)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c3,readstackptr)
								readstep=1
								inc(readitem12)
								
							case 110
								readitem12=100

						end select
					else
						readitem12=0
					end if

						inc(comstep)
				'------------------------------------------------------------
				case 26
					if Frenic3Act<>0 then

						ModbusID=Frenic3
						'readstackptr=0
						adrset(true,getS05c3,getvalptr)
						adrset(true,setS05c3,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic4
			'------------------------------------------------------------------
				case 27
					if Frenic4Act=0 then
						comstep=30
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 28
					if Frenic4Act<>0 then
						ModbusID=Frenic4

						getS05c4=getM05c4
						getS06c4=anda(getM13c4,3)

						if readitem13>100 and setS05c4<>getS05c4 then
							readitem13=100
						else 
							if readitem13>100 and setS06c4<>getS06c4 then
								readitem13=102
							end if
						end if
					
						select case readitem13
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c4,readstackptr)
								readstep=1
								inc(readitem13)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c4,readstackptr)
								readstep=1
								inc(readitem13)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c4,readstackptr)
								readstep=1
								inc(readitem13)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c4,readstackptr)
								readstep=1
								inc(readitem13)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c4,readstackptr)
								readstep=1
								readitem13=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c4,readstackptr)
								readstep=1
								inc(readitem13)
							case 101
								if getM05c4<>setS05c4 then
									dec(readitem13) '再読み込み
								else
									inc(readitem13)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c4,readstackptr)
								readstep=1
								inc(readitem13)							
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c4,readstackptr)
								readstep=1
								inc(readitem13)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c4,readstackptr)
								readstep=1
								inc(readitem13)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c4,readstackptr)
								'readstep=1
								inc(readitem13)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c4,readstackptr)
								'readstep=1
								inc(readitem13)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c4,readstackptr)
								readstep=1
								inc(readitem13)
								
							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c4,readstackptr)
								readstep=1
								inc(readitem13)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c4,readstackptr)
								readstep=1
								inc(readitem13)
								
							case 110
								readitem13=100

						end select
					else
						readitem13=0
					end if

						inc(comstep)
				'------------------------------------------------------------
				case 29
					if Frenic4Act<>0 then
						ModbusID=Frenic4
						'readstackptr=0
						adrset(true,getS05c4,getvalptr)
						adrset(true,setS05c4,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)

			'------------------------------------------------------------------
			' Frenic10
			'------------------------------------------------------------------
				case 30
					if Frenic10Act=0 then
						comstep=33
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 31
					if Frenic10Act<>0 then
						ModbusID=Frenic10

						getS05c10=getM05c10
						getS06c10=anda(getM13c10,3)

						if readItem20>100 and setS05c10<>getS05c10 then
							readItem20=100
						else 
							if readItem20>100 and setS06c10<>getS06c10 then
								readItem20=102
							end if
						end if
					
						select case readItem20
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c10,readstackptr)
								readstep=1
								inc(readItem20)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c10,readstackptr)
								readstep=1
								inc(readItem20)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c10,readstackptr)
								readstep=1
								inc(readItem20)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c10,readstackptr)
								readstep=1
								inc(readItem20)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c10,readstackptr)
								readstep=1
								readItem20=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c10,readstackptr)
								readstep=1
								inc(readItem20)
							case 101
								if getM05c10<>setS05c10 then
									dec(readItem20) '再読み込み
								else
									inc(readItem20)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c10,readstackptr)
								readstep=1
								inc(readItem20)							
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c10,readstackptr)
								readstep=1
								inc(readItem20)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c10,readstackptr)
								readstep=1
								inc(readItem20)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c10,readstackptr)
								'readstep=1
								inc(readItem20)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c10,readstackptr)
								'readstep=1
								inc(readItem20)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c10,readstackptr)
								readstep=1
								inc(readItem20)
								
							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c10,readstackptr)
								readstep=1
								inc(readItem20)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c10,readstackptr)
								readstep=1
								inc(readItem20)
								
							case 110
								readItem20=100

						end select
					else
						readItem20=0
					end if

						inc(comstep)
				'------------------------------------------------------------
				case 32
					if Frenic10Act<>0 then
						ModbusID=Frenic10
						'readstackptr=0
						adrset(true,getS05c10,getvalptr)
						adrset(true,setS05c10,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic11
			'------------------------------------------------------------------
				case 33
					if Frenic11Act=0 then
						comstep=36
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 34
					if Frenic11Act<>0 then
						ModbusID=Frenic11

						getS05c11=getM05c11
						getS06c11=anda(getM13c11,3)

						if readItem21>100 and setS05c11<>getS05c11 then
							readItem21=100
						else 
							if readItem21>100 and setS06c11<>getS06c11 then
								readItem21=102
							end if
						end if
					
						select case readItem21
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c11,readstackptr)
								readstep=1
								inc(readItem21)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c11,readstackptr)
								readstep=1
								inc(readItem21)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c11,readstackptr)
								readstep=1
								inc(readItem21)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c11,readstackptr)
								readstep=1
								inc(readItem21)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c11,readstackptr)
								readstep=1
								readItem21=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c11,readstackptr)
								readstep=1
								inc(readItem21)
							case 101
								if getM05c11<>setS05c11 then
									dec(readItem21) '再読み込み
								else
									inc(readItem21)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c11,readstackptr)
								readstep=1
								inc(readItem21)							
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c11,readstackptr)
								readstep=1
								inc(readItem21)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c11,readstackptr)
								readstep=1
								inc(readItem21)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c11,readstackptr)
								'readstep=1
								inc(readItem21)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c11,readstackptr)
								'readstep=1
								inc(readItem21)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c11,readstackptr)
								readstep=1
								inc(readItem21)
								
							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c11,readstackptr)
								readstep=1
								inc(readItem21)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c11,readstackptr)
								readstep=1
								inc(readItem21)
								
							case 110
								readItem21=100

						end select
					else
						readItem21=0
					end if

						inc(comstep)
				'------------------------------------------------------------
				case 35
					if Frenic11Act<>0 then
						ModbusID=Frenic11
						'readstackptr=0
						adrset(true,getS05c11,getvalptr)
						adrset(true,setS05c11,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic12
			'------------------------------------------------------------------
				case 36
					if Frenic12Act=0 then
						comstep=39
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 37
					if Frenic12Act<>0 then
						ModbusID=Frenic12

						getS05c12=getM05c12
						getS06c12=anda(getM13c12,3)

						if readItem22>100 and setS05c12<>getS05c12 then
							readItem22=100
						else 
							if readItem22>100 and setS06c12<>getS06c12 then
								readItem22=102
							end if
						end if
					
						select case readItem22
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c12,readstackptr)
								readstep=1
								inc(readItem22)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c12,readstackptr)
								readstep=1
								inc(readItem22)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c12,readstackptr)
								readstep=1
								inc(readItem22)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c12,readstackptr)
								readstep=1
								inc(readItem22)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c12,readstackptr)
								readstep=1
								readItem22=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c12,readstackptr)
								readstep=1
								inc(readItem22)
							case 101
								if getM05c12<>setS05c12 then
									dec(readItem22) '再読み込み
								else
									inc(readItem22)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c12,readstackptr)
								readstep=1
								inc(readItem22)							
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c12,readstackptr)
								readstep=1
								inc(readItem22)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c12,readstackptr)
								readstep=1
								inc(readItem22)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c12,readstackptr)
								'readstep=1
								inc(readItem22)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c12,readstackptr)
								'readstep=1
								inc(readItem22)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c12,readstackptr)
								readstep=1
								inc(readItem22)
								
							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c12,readstackptr)
								readstep=1
								inc(readItem22)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c12,readstackptr)
								readstep=1
								inc(readItem22)
								
							case 110
								readItem22=100

						end select
					else
						readItem22=0
					end if

						inc(comstep)
				'------------------------------------------------------------
				case 38
					if Frenic12Act<>0 then
						ModbusID=Frenic12
						'readstackptr=0
						adrset(true,getS05c12,getvalptr)
						adrset(true,setS05c12,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic13
			'------------------------------------------------------------------
				case 39
					if Frenic13Act=0 then
						comstep=42
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 40
					if Frenic13Act<>0 then
						ModbusID=Frenic13

						getS05c13=getM05c13
						getS06c13=anda(getM13c13,3)

						if readItem23>100 and setS05c13<>getS05c13 then
							readItem23=100
						else 
							if readItem23>100 and setS06c13<>getS06c13 then
								readItem23=102
							end if
						end if
					
						select case readItem23
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c13,readstackptr)
								readstep=1
								inc(readItem23)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c13,readstackptr)
								readstep=1
								inc(readItem23)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c13,readstackptr)
								readstep=1
								inc(readItem23)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c13,readstackptr)
								readstep=1
								inc(readItem23)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c13,readstackptr)
								readstep=1
								readItem23=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c13,readstackptr)
								readstep=1
								inc(readItem23)
							case 101
								if getM05c13<>setS05c13 then
									dec(readItem23) '再読み込み
								else
									inc(readItem23)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c13,readstackptr)
								readstep=1
								inc(readItem23)							
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c13,readstackptr)
								readstep=1
								inc(readItem23)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c13,readstackptr)
								readstep=1
								inc(readItem23)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c13,readstackptr)
								'readstep=1
								inc(readItem23)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c13,readstackptr)
								'readstep=1
								inc(readItem23)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c13,readstackptr)
								readstep=1
								inc(readItem23)
								
							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c13,readstackptr)
								readstep=1
								inc(readItem23)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c13,readstackptr)
								readstep=1
								inc(readItem23)
								
							case 110
								readItem23=100

						end select
					else
						readItem23=0
					end if

						inc(comstep)
				'------------------------------------------------------------
				case 41
					if Frenic13Act<>0 then
						ModbusID=Frenic13
						'readstackptr=0
						adrset(true,getS05c13,getvalptr)
						adrset(true,setS05c13,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						inc(comstep)
			'------------------------------------------------------------------
			' Frenic14
			'------------------------------------------------------------------
				case 42
					if Frenic14Act=0 then
						comstep=100
					else 
						inc(comstep)
					end if
			'------------------------------------------------------------------
				case 43
					if Frenic14Act<>0 then
						ModbusID=Frenic14

						getS05c14=getM05c14
						getS06c14=anda(getM13c14,3)

						if readItem24>100 and setS05c14<>getS05c14 then
							readItem24=100
						else 
							if readItem24>100 and setS06c14<>getS06c14 then
								readItem24=102
							end if
						end if
					
						select case readItem24
							'-------------------------------------------------
							'設定ﾚｼﾞｽﾀの読み込み
							case 0
								ReadAdr=ADRS05
								adrset(true,getS05c14,readstackptr)
								readstep=1
								inc(readItem24)
							case 1
								ReadAdr=ADRS06
								adrset(true,getS06c14,readstackptr)
								readstep=1
								inc(readItem24)
							case 2
								ReadAdr=ADRS08
								adrset(true,getS08c14,readstackptr)
								readstep=1
								inc(readItem24)
							case 3
								ReadAdr=ADRS09
								adrset(true,getS09c14,readstackptr)
								readstep=1
								inc(readItem24)
							case 4
								ReadAdr=ADRS14
								adrset(true,getS14c14,readstackptr)
								readstep=1
								readItem24=100
							'-------------------------------------------------
							'ﾓﾆﾀｰﾚｼﾞｽﾀの読み込み
							case 100
								ReadAdr=ADRM05	'周波数指令ﾓﾆﾀｰ
								adrset(true,getM05c14,readstackptr)
								readstep=1
								inc(readItem24)
							case 101
								if getM05c14<>setS05c14 then
									dec(readItem24) '再読み込み
								else
									inc(readItem24)
								end if
							case 102
								ReadAdr=ADRM13	'運転操作指令ﾓﾆﾀｰ
								adrset(true,getM13c14,readstackptr)
								readstep=1
								inc(readItem24)							
							case 103
								ReadAdr=ADRM16 'ｱﾗｰﾑ内容(最新)
								adrset(true,getM16c14,readstackptr)
								readstep=1
								inc(readItem24)

							case 104
								ReadAdr=ADRM17	'ｱﾗｰﾑ内容(1回前)
								adrset(true,getM17c14,readstackptr)
								readstep=1
								inc(readItem24)

							case 105
								'ReadAdr=ADRM18	'ｱﾗｰﾑ内容(2回前)
								'adrset(true,getM18c14,readstackptr)
								'readstep=1
								inc(readItem24)

							case 106
								'ReadAdr=ADRM19	'ｱﾗｰﾑ内容(3回前)
								'adrset(true,getM19c14,readstackptr)
								'readstep=1
								inc(readItem24)

							case 107
								ReadAdr=ADRM20	'累積時間
								adrset(true,getM20c14,readstackptr)
								readstep=1
								inc(readItem24)
								
							case 108
								ReadAdr=ADRM14 '運転状態
								adrset(true,getM14c14,readstackptr)
								readstep=1
								inc(readItem24)

							case 109
								ReadAdr=ADRH30
								adrset(true,getH30c14,readstackptr)
								readstep=1
								inc(readItem24)
								
							case 110
								readItem24=100

						end select
					else
						readItem24=0
					end if

						inc(comstep)
				'------------------------------------------------------------
				case 44
					if Frenic14Act<>0 then
						ModbusID=Frenic14
						'readstackptr=0
						adrset(true,getS05c14,getvalptr)
						adrset(true,setS05c14,setvalptr)
						for loopi=0 to 4 step 1
							if *getvalptr <> *setvalptr then
								select case loopi
									case 0 
										WriteAdr=ADRS05
									case 1 
										WriteAdr=ADRS06
									case 2 
										WriteAdr=ADRS08
									case 3 
										WriteAdr=ADRS09
									case 4 
										WriteAdr=ADRS14
								end select
								
								writestep=1
								
								break
							else
								adrinc(getvalptr)
								adrinc(setvalptr)
							end if
						next
					end if
						comstep=100

				'--------------------------------------------------------------
				case 100
					comstep=0
				'--------------------------------------------------------------
			end select
		
		end if 'if witestep=0 and readstep=0 
	'-----------------------------------------------------------------------
	' 通信ｴﾗｰ検出
	'-----------------------------------------------------------------------
	else

		if errcode<>0 then
			DispMsg1Item=ModbusID
		
			select case errcode
			
			case $0001	'ｽﾚｰﾌﾞ局が未対応のﾌｧﾝｸｼｮﾝを送信しました。
				ErrCodeNo=1000+1
				DispMsg2Item= 10
				DispMsg3Item= 11
			case $0002	'ｽﾚｰﾌﾞ局が未対応のﾃﾞﾊﾞｲｽを送信しました。
				ErrCodeNo=1000+2
				DispMsg2Item= 12
				DispMsg3Item= 13
			case $0003	'ｽﾚｰﾌﾞ局が未対応の読み書き点数を送信しました。
				ErrCodeNo=1000+3
				DispMsg2Item= 14
				DispMsg3Item= 15
			case $0004	'ｽﾚｰﾌﾞ局が復帰できない状態になっています。
				ErrCodeNo=1000+4
				DispMsg2Item= 16
				DispMsg3Item= 17
			case $0101	'ｽﾚｰﾌﾞｱﾄﾞﾚｽｴﾗｰ
				ErrCodeNo=1000+101
				DispMsg2Item= 18
				DispMsg3Item= 19
			case $0102	'ﾌｧﾝｸｼｮﾝｴﾗｰ
				ErrCodeNo=1000+102
				DispMsg2Item= 20
				DispMsg3Item= 21
			case $0103	'ｺｲﾙ、ﾃﾞﾊﾞｲｽｱﾄﾞﾚｽｴﾗｰ
				ErrCodeNo=1000+103
				DispMsg2Item= 22
				DispMsg3Item= 23
			case $0201	'ﾚｽﾎﾟﾝｽｺﾏﾝﾄﾞｴﾗｰ
				ErrCodeNo=1000+201
				DispMsg2Item= 24
				DispMsg3Item= 25
			case $0301	'ﾚｽﾎﾟﾝｽﾌﾚｰﾑｴﾗｰ、ﾉｲｽﾞ等によるｴﾗｰ
				ErrCodeNo=1000+301
				DispMsg2Item= 26
				DispMsg3Item= 27
			case $0302	'
				ErrCodeNo=1000+302
				DispMsg2Item= 28
				DispMsg3Item= 29
			case $0401	'未応答：ｽﾚｰﾌﾞの通信ﾊﾟﾗﾒｰﾀ、通信速度再確認
				ErrCodeNo=1000+401
				DispMsg2Item= 30
				DispMsg3Item= 31
			
			end select
			
			'DispMsg1Relay=ON
		errcode=0
		end if
		
		
	end if 'if errcode
	
'------------------------------------------------------------------------------
'ｲﾝﾊﾞｰﾀ運転状態検出
'------------------------------------------------------------------------------

	select case FrenicStatJudge
		case 0
		'------------------------------------------------
		'ｲﾝﾊﾞｰﾀ運転状態検出
		case 1
		'------------------------------------------------
			'adrset(true,getM14c1,FrenicStatPtr)
			'adrset(true,getM16c1,FrenicAlmRegPtr)

				'正転中
				if anda(*FrenicStatPtr,statFWD)=statFWD then
				end if
				'逆転中
				if anda(*FrenicStatPtr,statREV)=statREV then
				end if
				'直流制動中
				if anda(*FrenicStatPtr,statEXT)=statEXT then
				end if
				'ｲﾝﾊﾞｰﾀ遮断
				if anda(*FrenicStatPtr,statINT)=statINT then
				end if
				'制動中（Miniは0固定）
				if anda(*FrenicStatPtr,statBRK)=statBRK then
				end if
				'直流中間確立
				if anda(*FrenicStatPtr,statNUV)=statNUV then
				end if
				'ﾄﾙｸ制限中(Miniは0)
				if anda(*FrenicStatPtr,statTL)=statTL then
				end if
				'電圧制限中
				if anda(*FrenicStatPtr,statVL)=statVL then		
				end if
				'電流制限中
				if anda(*FrenicStatPtr,statIL)=statIL then
				end if
				'加速中
				if anda(*FrenicStatPtr,statACC)=statACC then
				end if
				'減速中
				if anda(*FrenicStatPtr,statDEC)=statDEC then		
				end if
				'一括ｱﾗｰﾑ
				if anda(*FrenicStatPtr,statALM)=statALM then		
					
					DispMsg1Item=ModbusID
					ErrCodeNo=3000+*FrenicAlmRegPtr
					
					select case *FrenicAlmRegPtr
						case	almOC1	'	過電流(加速中）
							DispMsg2Item= 100
							DispMsg3Item= 101
						case	almOC2	'	過電流(減速中）
							DispMsg2Item= 100
							DispMsg3Item= 101
						case	almOC3	'	過電流（一定速中）
							DispMsg2Item= 100
							DispMsg3Item= 101

						case	almOU1	'	過電圧（加速中）
							DispMsg2Item= 102
							DispMsg3Item= 103
						case	almOU2	'	過電圧(減速中）
							DispMsg2Item= 102
							DispMsg3Item= 103
						case	almOU3	'	過電圧（一定速中または停止中）
							DispMsg2Item= 102
							DispMsg3Item= 103

						case	almEF	'	地絡
							DispMsg2Item= 104
							DispMsg3Item= 105

						case	almLU	'	不足電圧
							DispMsg2Item= 106
							DispMsg3Item= 107

						case	almLin	'	入力欠相
							DispMsg2Item= 108
							DispMsg3Item= 109

						case	almFUS	'	ﾋｭｰｽﾞ断
							DispMsg2Item= 110
							DispMsg3Item= 111

						case	almPbF	'	充電回路異常
							DispMsg2Item= 112
							DispMsg3Item= 113

						case	almOH1	'	冷却ﾌｨﾝ過熱
							DispMsg2Item= 114
							DispMsg3Item= 115

						case	almOH2	'	外部ｱﾗｰﾑ
							DispMsg2Item= 116
							DispMsg3Item= 117

						case	almOH3	'	ｲﾝﾊﾞｰﾀ内過熱
							DispMsg2Item= 118
							DispMsg3Item= 119

						case	almOH4	'	ﾓｰﾀ保護
							DispMsg2Item= 120
							DispMsg3Item= 121

						case	almdbH	'	制動抵抗器過熱
							DispMsg2Item= 122
							DispMsg3Item= 123

						case	almOL1	'	ﾓｰﾀ過負荷
							DispMsg2Item= 124
							DispMsg3Item= 125

						case	almOL2	'	ﾓｰﾀ過負荷・ﾓｰﾀ2
							DispMsg2Item= 124
							DispMsg3Item= 125

						case	almOLU	'	ｲﾝﾊﾞｰﾀ過負荷
							DispMsg2Item= 126
							DispMsg3Item= 127

						case	almOS	'	過速度保護
							DispMsg2Item= 128
							DispMsg3Item= 129

						case	almPG	'	PG断線
							DispMsg2Item= 130
							DispMsg3Item= 131

						case	almnrb	'	NTC断線ｴﾗｰ
							DispMsg2Item= 132
							DispMsg3Item= 133
							
						case	almER1	'	ﾒﾓﾘｴﾗｰ
							DispMsg2Item= 134
							DispMsg3Item= 135

						case	almER2	'	ﾀｯﾁﾊﾟﾈﾙ通信ｴﾗｰ
							DispMsg2Item= 136
							DispMsg3Item= 137

						case	almER3	'	CPUｴﾗｰ
							DispMsg2Item= 138
							DispMsg3Item= 139

						case	almER4	'	ｵﾌﾟｼｮﾝ通信ｴﾗｰ
							DispMsg2Item= 140
							DispMsg3Item= 141

						case	almER5	'	ｵﾌﾟｼｮﾝｴﾗｰ
							DispMsg2Item= 142
							DispMsg3Item= 143

						case	almER6	'	運転動作ｴﾗｰ
							DispMsg2Item= 144
							DispMsg3Item= 145

						case	almER7	'	ﾁｭｰﾆﾝｸﾞｴﾗｰ
							DispMsg2Item= 146
							DispMsg3Item= 147

						case	almER8	'	RS-485通信ｴﾗｰ(ﾎﾟｰﾄ1）
							DispMsg2Item= 148
							DispMsg3Item= 149

						case	almOL3	'	ﾓｰﾀ過負荷・ﾓｰﾀ3
							DispMsg2Item= 124
							DispMsg3Item= 125

						case	almOL4	'	ﾓｰﾀ過負荷・ﾓｰﾀ4
							DispMsg2Item= 124
							DispMsg3Item= 125

						case	almOPL	'	出力欠相
							DispMsg2Item= 150
							DispMsg3Item= 151

						case	almErE	'	速度不一致・速度偏差過大
							DispMsg2Item= 152
							DispMsg3Item= 153

						case	almErF	'	不足電圧時ﾃﾞｰﾀｾｰﾌﾞｴﾗｰ
							DispMsg2Item= 154
							DispMsg3Item= 155

						case	almErP	'	RS-485通信ｴﾗｰ(ﾎﾟｰﾄ2)
							DispMsg2Item= 156
							DispMsg3Item= 157

						case	almErH	'	ﾊｰﾄﾞｳｪｱｴﾗｰ
							DispMsg2Item= 158
							DispMsg3Item= 159

						case	almCoF	'	PIDﾌｨｰﾄﾞﾊﾞｯｸ断線検出
							DispMsg2Item= 160
							DispMsg3Item= 161

						case	almdbA	'	DBﾄﾗﾝｼﾞｽﾀ故障
							DispMsg2Item= 162
							DispMsg3Item= 163

						case	almFAL	'	DCﾌｧﾝﾛｯｸ検出
							DispMsg2Item= 164
							DispMsg3Item= 165

						case	almOL	'	ﾓｰﾀ過負荷予報
							DispMsg2Item= 166
							DispMsg3Item= 167

						case	almOH	'	冷却ﾌｨﾝ過熱予報
							DispMsg2Item= 168
							DispMsg3Item= 169

						case	almLiF	'	寿命予報
							DispMsg2Item= 170
							DispMsg3Item= 171

						case	almrEF	'	指令ﾛｽ
							DispMsg2Item= 172
							DispMsg3Item= 173

						case	almPid	'	PID警報出力
							DispMsg2Item= 174
							DispMsg3Item= 175

						case	almUL	'	低ﾄﾙｸ検出
							DispMsg2Item= 176
							DispMsg3Item= 177

						case	almPC	'	ｻｰﾐｽﾀ検出(PTC)
							DispMsg2Item= 178
							DispMsg3Item= 179

						case	almrE	'	機械寿命（運転積算時間）
							DispMsg2Item= 180
							DispMsg3Item= 181
							
						case	almCn	'	機械寿命(起動回数）
							DispMsg2Item= 182
							DispMsg3Item= 183

						case	almErr	'	模擬故障	
							DispMsg2Item= 184
							DispMsg3Item= 185
					end select				
			
					'DispMsg1Relay=ON

				end if
				'通信有効
				if anda(*FrenicStatPtr,statRL)=statRL then		
				end if
				'機能ｺｰﾄﾞﾃﾞｰﾀ書き込み中
				if anda(*FrenicStatPtr,statBUSY)=statBUSY then		
				end if
		
			inc(FrenicStatJudge)

		'------------------------------------------------
		'ｲﾝﾊﾞｰﾀ汎用出力端子情報
		case 2
		'------------------------------------------------
			'adrset(true,getM15c1,FrenicOutStatPtr)

				if anda(*FrenicOutStatPtr,outFrenicY1)=outFrenicY1 then  '汎用出力
				end if
				if anda(*FrenicOutStatPtr,outFrenicY2)=outFrenicY2 then  '汎用出力
				end if
				if anda(*FrenicOutStatPtr,outFrenicY3)=outFrenicY3 then  '汎用出力
				end if
				if anda(*FrenicOutStatPtr,outFrenicY4)=outFrenicY4 then  '汎用出力
				end if
				if anda(*FrenicOutStatPtr,outFrenicY5)=outFrenicY5 then  '汎用出力
				end if
				if anda(*FrenicOutStatPtr,outFrenic30)=outFrenic30 then 'ｱﾗｰﾑ出力
					select case ModbusID
					case 10
						インバータ1Alm=ON
					case 11
						インバータ2Alm=ON
					case 12
						インバータ3Alm=ON
					case 13
						インバータ4Alm=ON
					end select
				end if
				if anda(*FrenicOutStatPtr,outFrenicY1A)=outFrenicY1A then 'ﾘﾚｰｵﾌﾟｼｮﾝ出力Y1A
				end if
				if anda(*FrenicOutStatPtr,outFrenicY2A)=outFrenicY2A then 'ﾘﾚｰｵﾌﾟｼｮﾝ出力Y2A
				end if
				if anda(*FrenicOutStatPtr,outFrenicY3A)=outFrenicY3A then 'ﾘﾚｰｵﾌﾟｼｮﾝ出力Y3A
				end if

			inc(FrenicStatJudge)

		'------------------------------------------------
		'ｲﾝﾊﾞｰﾀ汎用入力端子情報
		case 3
		'------------------------------------------------

			'adrset(true,getM71c1,FrenicInputStatPtr)

				if anda(*FrenicInputStatPtr,inFrenicFWD)=inFrenicFWD then  '正転指令
				end if

				if anda(*FrenicInputStatPtr,inFrenicREV)=inFrenicREV then  '逆転指令
				end if

				if anda(*FrenicInputStatPtr,inFrenicX1)=inFrenicX1 then  '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX2)=inFrenicX2 then  '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX3)=inFrenicX3 then  '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX4)=inFrenicX4 then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX5)=inFrenicX5 then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX6)=inFrenicX6 then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX7)=inFrenicX7 then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX8)=inFrenicX8 then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicX9)=inFrenicX9 then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicXF)=inFrenicXF then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicXR)=inFrenicXR then '汎用入力
				end if

				if anda(*FrenicInputStatPtr,inFrenicRST)=inFrenicRST then 'ｱﾗｰﾑﾘｾｯﾄ
				end if

			inc(FrenicStatJudge)

		'------------------------------------------------
		'待機
		case 4
			FrenicStatJudge=0
		'------------------------------------------------
		
		end select

