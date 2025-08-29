'KV21Lc2port2_ModbusMaster

if CR2008 then

'------------------------------------------
' 各ﾕﾆｯﾄをModbusID登録
'------------------------------------------
	AD4410c1=#1
	AD4410c2=#2
	AD4532c1=#10


'使用する(1)  使用しない(0)
	AD4410c1USE=0
	AD4410c2USE=0
	AD4532c1USE=1

end if
'------------------------------------------
' KV-L21Vのアドレス
' R39000
' DM11000
'------------------------------------------
'port1
	'①KV BUILDER で使用
	'占有個数 R (1ch) 16個 	DM 0個
	'②MODBUS MASTER で使用
	'占有個数 R (2ch) 32個 	DM 600個

'port2
	Z3=390*16 + (1*16)	'port2 rlayの先頭ｱﾄﾞﾚｽ
	Z4=11000 + (0) 'port2 DMの先頭ｱﾄﾞﾚｽ


'---------------------------------------------------------

'------------------------------------------
'Modbus Master Addres Map
'------------------------------------------
'KV-L21V	KV-N10L
'------------------------------------------
'R001:Z3	CR6601	ｺﾏﾝﾄﾞ送信
'R004:Z3	CR6604	通信設定変更要求
'R101:Z3	CR6701	実行完了
'R102:Z3	CR6702	実行失敗
'R103:Z3	CR6703	実行中
'R104:Z3	CR6704	通信設定変更完了
'R108:Z3	CR6708	ER状態
'R109:Z3	CR6709	CD状態
'R110:Z3	CR6710	DR状態
'R111:Z3	CR6711	RS状態
'R112:Z3	CR6712	CS状態
'------------------------------------------
'DM20000	エラーコード
'DM001:Z4	CM6001	ｽﾚｰﾌﾞ局番
'DM002:Z4	CM6002	ﾌｧﾝｸｼｮﾝｺｰﾄﾞ
'DM003:Z4	CM6003	ｻﾌﾞﾌｧﾝｸｼｮﾝｺｰﾄﾞ
'DM006:Z4	CM6006	ﾃﾞｰﾀ格納単位
'DM007:Z4	CM6007	読み出し先頭ｱﾄﾞﾚｽ
'DM008:Z4	CM6008	読み出し点数
'DM310:Z4	CM6310	読み出しﾊﾞｲﾄ数
'DM311~563:Z4	CM6311~CM6563	読み出しBuff[0] ~ [252]
'DM009:Z4		CM6009	書き込み先頭ｱﾄﾞﾚｽ
'DM010:Z4		CM6010	書き込み点数
'DM011~263:Z4	CM6011~CM6263	書き込みﾃﾞｰﾀBuff[0] ~ [252]
'DM300:Z4	CM6300	ｴﾗｰｺｰﾄﾞ
'------------------------------------------
'DM570:Z4	CM6570	受信ﾀｲﾑｱｳﾄ
'DM571:Z4	CM6571	送信ｳｪｲﾄ
'DM572:Z4	CM6572	ﾘﾄﾗｲ回数
'DM573:Z4	CM6573	ﾘﾄﾗｲｳｪｲﾄ
'DM574:Z4	CM6574	ﾌﾞﾛｰﾄﾞｷｬｽﾄﾃﾞｨﾚｲﾀｲﾑ
'DM580:Z4	CM6580	設定済み受信ﾀｲﾑｱｳﾄ
'DM581:Z4	CM6581	設定済み送信ｳｪｲﾄ
'DM582:Z4	CM6582	設定済みﾘﾄﾗｲ回数
'DM583:Z4	CM6583	設定済みﾘﾄﾗｲｳｪｲﾄ
'DM584:Z4	CM6584	設定済みﾌﾞﾛｰﾄﾞｷｬｽﾄﾃﾞｨﾚｲﾀｲﾑ
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
	if AD4410c1USE=1 and not(DispMsg1Item=AD4410c1) then
		AD4410c1Act=1
	else
		AD4410c1Act=0
	end if
	'--------------------------
	if AD4410c2USE=1 and not(DispMsg1Item=AD4410c2) then
		AD4410c2Act=1
	else
		AD4410c2Act=0
	end if
	'--------------------------
	if AD4532c1USE=1 and not(DispMsg1Item=AD4532c1) then
		AD4532c1Act=1
	else
		AD4532c1Act=0
	end if
	'--------------------------
	ModbusC2AlmID=DispMsg1Item

	flgADR4410c1_RegEdit=1
	flgADR4410c2_RegEdit=1
	flgADR4532c1_RegEdit=1

'------------------------------------------
' 通信設定変更
'------------------------------------------
' 駆動ﾄﾘｶﾞ  CR2008 電源ON時
' R004:Z3	通信設定変更要求
' R104:Z3	通信設定変更完了

	if CR2008 then

		DM570:Z4=10	'受信ﾀｲﾑｱｳﾄ (初期値 0:10～2000[×10ms])
		DM571:Z4=0	'送信ｳｪｲﾄ (初期値 x10ms)
		DM572:Z4=2	'ﾘﾄﾗｲ回数 (初期値 0回)
		DM573:Z4=20	'ﾘﾄﾗｲｳｪｲﾄ (初期値 0:1～1000[×10ms] 初期値 0 の場合300mSec)
		DM574:Z4=200	'ﾌﾞﾛｰﾄﾞｷｬｽﾄﾃﾞｨﾚｲﾀｲﾑ (初期値 200)

		'--- 読み出し専用 格納ﾚｼﾞｽﾀ ---
		'DM580:Z4	'設定済み受信ﾀｲﾑｱｳﾄ
		'DM581:Z4	'設定済み送信ｳｪｲﾄﾀｲﾑ
		'DM582:Z4	'設定済みﾘﾄﾗｲｳｪｲﾄ
		'DM583:Z4	'設定済みﾘﾄﾗｲｳｪｲﾄﾀｲﾑ
		'DM584:Z4	'設定済みﾌﾞﾛｰﾄﾞｷｬｽﾄｳｪｲﾄﾀｲﾑ

		R004:Z3 = ON

	end if
	
	if LDP(R104:Z3) then
		R004:Z3 = OFF
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
' KV-L21V 送受信
'---------------------------------------------------------------------------
	'-----------------------------------------------------------------------
	select case readstep  '読み込み処理
	'-----------------------------------------------------------------------
		case 0
		'-------------------------------------------------------------------
		'コイル読み出し [01]
		'ModbusID : スレーブID
		'ReadAdr : 読み出し先頭ｱﾄﾞﾚｽ
		'ReadCnt : 連続するコイルの点数
		'adrset(true,xxx,readstackptr) :データを格納するｱﾄﾞﾚｽ
		'-------------------------------------------------------------------
		case 10
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then
			
				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#1
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt

				R001:Z3 = ON
				inc(readstep)
			end if
		case 11
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					*readstackptr=DM311:Z4
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 12
			readstep=0
		'-------------------------------------------------------------------
		'入力読み出し [02]
		'ModbusID : スレーブID
		'ReadAdr : 読み出し先頭ｱﾄﾞﾚｽ
		'ReadCnt : 連続するレジスタの点数
		'adrset(true,xxx,readstackptr) :データを格納するｱﾄﾞﾚｽ
		'-------------------------------------------------------------------
		case 20
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then
			
				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#2
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt

				R001:Z3 = ON
				inc(readstep)
			end if
		case 21
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					readstackcnt=asra(DM310:Z4,1)
					adrset(true,DM311:Z4,readbuffptr)
					for loopi=1 to readstackcnt step 1
						*readstackptr=*readbuffptr
						adrinc(readstackptr)
						adrinc(readbuffptr)
					next
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 22
			readstep=0
		'-------------------------------------------------------------------
		'保持レジスタの連続読み出し [03]
		'ModbusID : スレーブID
		'ReadAdr : 読み出し先頭ｱﾄﾞﾚｽ
		'ReadCnt : 連続するレジスタの点数
		'adrset(true,xxx,readstackptr) :データを格納するｱﾄﾞﾚｽ
		'-------------------------------------------------------------------
		case 30
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#3
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt
				
				R001:Z3 = ON
				inc(readstep)
			end if
		case 31
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					readstackcnt=asra(DM310:Z4,1)
					adrset(true,DM311:Z4,readbuffptr)
					for loopi=1 to readstackcnt step 1
						*readstackptr=*readbuffptr
						adrinc(readstackptr)
						adrinc(readbuffptr)
					next
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 32
			readstep=0

		'-------------------------------------------------------------------
		'入力レジスタの連続読み出し [04]
		'ModbusID : スレーブID
		'ReadAdr : 読み出し先頭ｱﾄﾞﾚｽ
		'ReadCnt : 連続するレジスタの点数
		'adrset(true,xxx,readstackptr) :データを格納するｱﾄﾞﾚｽ
		'-------------------------------------------------------------------
		case 40
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#4
				DM007:Z4=ReadAdr
				DM008:Z4=ReadCnt

				R001:Z3 = ON
				inc(readstep)
			end if
		case 41
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then

					readstackcnt=asra(DM310:Z4,1)
					adrset(true,DM311:Z4,readbuffptr)
					for loopi=1 to readstackcnt step 1
						*readstackptr=*readbuffptr
						adrinc(readstackptr)
						adrinc(readbuffptr)
					next
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(readstep)
			end if
		case 42
			readstep=0


	end select

	'-----------------------------------------------------------------------
	select case writestep '書き込み処理
	'-----------------------------------------------------------------------
		case 0
		
		'-------------------------------------------------------------------
		'コイル1点書き込み [05]
		'ModbusID : スレーブID
		'WriteAdr : 書き込みコイルｱﾄﾞﾚｽ
		'setCoilval : コイルの設定値 setCoilval [ off(0)  or on(not 0) ]
		'-------------------------------------------------------------------
		case 10
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#5
				DM009:Z4=WriteAdr
				DM011:Z4=setCoilval
				
				R001:Z3 = ON
				inc(writestep)
			end if
		case 11
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					''*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 12
			writestep=0

		'-------------------------------------------------------------------
		'コイル連続書き込み [15 ($0F)]
		'ModbusID : スレーブID
		'WriteAdr : 書き込みコイルｱﾄﾞﾚｽ
		'WriteCnt ：書き込みコイル数(ビット数）
		'adrset(true, xxx, setvalptr) : 書き込みコイル値（16bitレジスタ）
		'-------------------------------------------------------------------
		case 20
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#15
				DM009:Z4=WriteAdr
				DM010:Z4=WriteCnt
				DM011:Z4=*setvalptr'(最大個数16個を想定）

				R001:Z3 = ON
				inc(writestep)
			end if
		case 21
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					'*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 22
			writestep=0
		'-------------------------------------------------------------------
		'保持レジスタ1点書き込み [6]
		'ModbusID : スレーブID
		'WriteAdr : 書き込みｱﾄﾞﾚｽ
		'adrset(true, xxx, setvalptr) : 書き込みレジスタ値（16bitレジスタ）
		'-------------------------------------------------------------------
		case 30
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#6
				DM009:Z4=WriteAdr
				DM011:Z4=*setvalptr

				R001:Z3 = ON
				inc(writestep)
			end if
		case 31
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					'*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 32
			writestep=0
		'-------------------------------------------------------------------
		'保持レジスタ連続書き込み [16 (0x10)]
		'ModbusID : スレーブID
		'WriteAdr : 書き込み先頭ｱﾄﾞﾚｽ
		'WriteCnt ：書き込みレジスタ（16bitレジスタ）数
		'adrset(true, xxx, setvalptr) : 書き込みレジスタ先頭ｱﾄﾞﾚｽ（16bitレジスタ）
		'-------------------------------------------------------------------
		case 40
			if not(R101:Z3) and not(R102:Z3) and not(R103:Z3) then

				DM006:Z4=0 '16bit単位
				DM001:Z4=ModbusID
				DM002:Z4=#16
				DM009:Z4=WriteAdr
				DM010:Z4=WriteCnt

				adrset(true, DM011:Z4, writebuffptr)
				for loopi=1 to WriteCnt step 1
					*writebuffptr=*setvalptr
					adrinc(writebuffptr)
					adrinc(setvalptr)
				next


				R001:Z3 = ON
				inc(writestep)
			end if
		case 41
			if LDP(R101:Z3) and not(R103:Z3) then

				if not(R102:Z3) then
					'*getvalptr = *setvalptr
				end if
				if R102:Z3 then
					errcode = DM300:Z4
				end if
				
				R001:Z3= OFF
				inc(writestep)
			end if
		case 42
			writestep=0
		'-------------------------------------------------------------------

	end select

'------------------------------------------
' 電源ON時の初期化
'------------------------------------------

	if CR2008 then
	
		'--------------------------
		' ﾌﾗｸﾞｸﾘｱ
		'--------------------------
		errcode =0
		comstep =0
		readstep =0
		writestep =0
		setcoilstep=0
		
		getvalptr =0
		setvalptr =0
		readstackptr =0
		ReadAdr =0
		WriteAdr =0
		ModbusID =0

		'--------------------------
		'入力レジスタの0クリア
		'--------------------------
		getADR4532c1_Decimal=0
		getADR4532c1_Unit=0
		getADR4532c1_Raw=0
		getADR4532c1_Sampl=0

		'--------------------------
		'保持レジスタの読み取り値を消去
		'--------------------------
		getADR4410c1_NearZero=0
		getADR4410c1_Up=0
		getADR4410c1_Low=0

		getADR4410c2_NearZero=0
		getADR4410c2_Up=0
		getADR4410c2_Low=0

		getADR4532c1_Up=0
		getADR4532c1_Low=0
		getADR4532c1_Up1=0
		getADR4532c1_Low1=0
		getADR4532c1_Up2=0
		getADR4532c1_Low2=0
		getADR4532c1_Up3=0
		getADR4532c1_Low3=0
		getADR4532c1_Up4=0
		getADR4532c1_Low4=0
		getADR4532c1_Up5=0
		getADR4532c1_Low5=0
		getADR4532c1_Starttime1=0
		getADR4532c1_Endtime1=0
		getADR4532c1_Starttime2=0
		getADR4532c1_Endtime2=0
		getADR4532c1_Starttime3=0
		getADR4532c1_Endtime3=0
		getADR4532c1_Starttime4=0
		getADR4532c1_Endtime4=0
		getADR4532c1_Starttime5=0
		getADR4532c1_Endtime5=0
		getADR4532c1_Offset=0
		getADR4532c1_NearZero=0
		getADR4532c1_Hys=0
		getADR4532c1_HysTime=0
		getADR4532c1_HysMode=0
		getADR4532c1_HoldTime=0
		getADR4532c1_CompMode=0

		'--------------------------
		ModbusStartWaitTim=0
		ModbusStartWait=false
		
	end if

'------------------------------------------
'通信回線遮断時(xxxAct=0),現在値を0クリア
'------------------------------------------

if AD4410c1Act=0 then
	getADR4410c1_Unit=0
	getADR4410c1_Decimal=0
	getADR4410c1_風袋=0
	getADR4410c1_総量=0
	getADR4410c1_正味=0
	getADR4410c1_Stat1=0
	getADR4410c1_Stat2=0
	getADR4410c1_Stat3=0
end if

if AD4410c2Act=0 then
	getADR4410c2_Unit=0
	getADR4410c2_Decimal=0
	getADR4410c2_風袋=0
	getADR4410c2_総量=0
	getADR4410c2_正味=0
	getADR4410c2_Stat1=0
	getADR4410c2_Stat2=0
	getADR4410c2_Stat3=0
end if

if AD4532c1Act=0 then
	getADR4532c1_Decimal=0
	getADR4532c1_Unit=0
	getADR4532c1_Raw=0
	getADR4532c1_Sampl=0
end if

'------------------------------------------------------------------------------
' 通信工程
'------------------------------------------------------------------------------

tms(true, msec_wait, msec_wait_val)


	'--------------------------------------------------------------------------
	if ModbusStartWait=true and errcode= 0 then '電源時間待ち and 通信ｴﾗｰなし
	'--------------------------------------------------------------------------
	
		if  readstep=0 and writestep=0 then
			'------------------------------------------------------------------
			select case comstep '送受信工程
			'------------------------------------------------------------------
			'------------------------------------------------------------------
			'AD4410c1
			'------------------------------------------------------------------
				case 0
					if AD4410c1Act=0 then
						comstep=7
					else 
						inc(comstep)
					end if
				case 1
					'AD4410
					'出力コイルの読み込み
					if 0 then
						ModbusID=AD4410c1
						ReadAdr=1
						ReadCnt=16
						adrset(true,getADR4410c1_Output,readstackptr)
						readstep=Func01
					end if					
					inc(comstep)
				case 2
					'出力コイルの書き込み
					if AD4410c1Act<>0 then
						ModbusID=AD4410c1
						WriteAdr=0
						WriteCnt=16 'ビット数
						adrset(true, setADR4410c1_Output, setvalptr)
						writestep=Func15
					end if
					inc(comstep)
				case 3
					'入力レジスタの読み込み
					if AD4410c1Act<>0 then
						ModbusID=AD4410c1
						ReadAdr=ADR4410_Unit
						ReadCnt=11 'レジスタ数
						adrset(true,getADR4410c1_Unit,readstackptr)
						readstep=Func04
					end if
					inc(comstep)

				case 4
					'保持レジスタの読み込み
					if AD4410c1Act<>0 then
						if flgADR4410c1_RegEdit<>0 then					'編集可能タイミング
							ModbusID=AD4410c1
							ReadAdr=ADR4410_NearZero_L
							ReadCnt=6 'レジスタ数
							adrset(true,getADR4410c1_NearZero,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 5
				
					'保持レジスタの書き込み
					if AD4410c1Act<>0 then

						if flgADR4410c1_RegEdit<>0 then
							ModbusID=AD4410c1
							adrset(true,getADR4410c1_NearZero,getvalptr)
							adrset(true,setADR4410c1_NearZero,setvalptr)
							for loopi=0 to 5 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4410_NearZero_L + loopi
									WriteCnt=1
									writestep=Func16
								break
									else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					
					end if

					inc(comstep)
				case 6
					inc(comstep)
			'------------------------------------------------------------------
			'AD4410c2
			'------------------------------------------------------------------
				case 7
					if AD4410c2Act=0 then
						comstep=14
					else 
						inc(comstep)
					end if
				case 8
					'AD4410
					'出力コイルの読み込み
					if 0 then
						ModbusID=AD4410c2
						ReadAdr=1
						ReadCnt=16
						adrset(true,getADR4410c2_Output,readstackptr)
						readstep=Func01
					end if
					inc(comstep)

				case 9
					'出力コイルの書き込み
					if AD4410c2Act<>0 then
						ModbusID=AD4410c2
						WriteAdr=0
						WriteCnt=16 'ビット数
						adrset(true, setADR4410c2_Output, setvalptr)
						writestep=Func15
					end if
					inc(comstep)

				case 10
					'入力レジスタの読み込み
					if AD4410c2Act<>0 then
						ModbusID=AD4410c2
						ReadAdr=ADR4410_Unit
						ReadCnt=11 'レジスタ数
						adrset(true,getADR4410c2_Unit,readstackptr)
						readstep=Func04
					end if
					inc(comstep)

				case 11
					'保持レジスタの読み込み
					if AD4410c2Act<>0 then
						if flgADR4410c2_RegEdit<>0 then					'編集可能タイミング
							ModbusID=AD4410c2
							ReadAdr=ADR4410_NearZero_L
							ReadCnt=6 'レジスタ数
							adrset(true,getADR4410c2_NearZero,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 12
					'保持レジスタの書き込み
					if AD4410c2Act<>0 then
						if flgADR4410c2_RegEdit<>0 then
							ModbusID=AD4410c2
							adrset(true,getADR4410c2_NearZero,getvalptr)
							adrset(true,setADR4410c2_NearZero,setvalptr)
							for loopi=0 to 5 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4410_NearZero_L + loopi
									WriteCnt=1
									writestep=Func16
								break
									else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					end if
					inc(comstep)
				case 13
					inc(comstep)

			'------------------------------------------------------------------
			'AD4532c1
			'------------------------------------------------------------------
				case 14
					if AD4532c1Act=0 then
						comstep=25
					else
						inc(comstep)
					end if
				case 15
					'AD4532
					'出力コイルの読み込み
					if 0 then
						ModbusID=AD4532c1
						ReadAdr=0
						ReadCnt=5
						adrset(true,getADR4532c1_Output,readstackptr)
						readstep=Func01
					end if
					
					inc(comstep)

				case 16
					'出力コイルの書き込み
					if AD4532c1Act<>0 then
					
						select case setcoilstep 
						case 0
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_SetHold
								setCoilval=anda(setADR4532c1_Output,2^0)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 1
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_ClrHold
								setCoilval=anda(setADR4532c1_Output,2^1)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 2
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_SetZero
								setCoilval=anda(setADR4532c1_Output,2^2)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 3
							if 1 then
								ModbusID=AD4532c1
								WriteAdr=ADR4532_ClrZero
								setCoilval=anda(setADR4532c1_Output,2^3)
								writestep=Func05
							end if
								inc(setcoilstep)
						case 4
								setcoilstep=0
								inc(comstep)
						end select
					else
						setcoilstep=0
						inc(comstep)
					end if					

				case 17
					'入力ステータスの読み込み
					if AD4532c1Act<>0 then
						ModbusID=AD4532c1
						ReadAdr=ADR4532_Hold
						ReadCnt=23 'ビット数
						adrset(true,getADR4532c1_InputL,readstackptr)
						readstep=Func02
					end if
					inc(comstep)

				case 18
					'入力レジスタの読み込み
					if AD4532c1Act<>0 then
						ModbusID=AD4532c1
						ReadAdr=ADR4532_Decimal
						ReadCnt=6 'レジスタ数
						adrset(true,getADR4532c1_Decimal,readstackptr)
						readstep=Func04
					end if
					inc(comstep)

				case 19
					'保持レジスタの読み込み
					if AD4532c1Act<>0  then 
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							ReadAdr=ADR4532_Up_L
							ReadCnt=24
							adrset(true,getADR4532c1_Up,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 20
					if AD4532c1Act<>0 and 0 then
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							ReadAdr=ADR4532_Starttime1_L
							ReadCnt=20
							adrset(true,getADR4532c1_Starttime1,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)
				case 21
					if AD4532c1Act<>0 and 0 then
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							ReadAdr=ADR4532_Offset_L
							ReadCnt=10
							adrset(true,getADR4532c1_Offset,readstackptr)
							readstep=Func03
						end if
					end if
					inc(comstep)

				case 22
					'保持レジスタの書き込み
					if AD4532c1Act<>0 then
						if flgADR4532c1_RegEdit<>0 then 
							ModbusID=AD4532c1
							adrset(true,getADR4532c1_Up,getvalptr)
							adrset(true,setADR4532c1_Up,setvalptr)
							for loopi=0 to 23 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4532_Up_L+loopi
									WriteCnt=1
									writestep=Func16
									break
								else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					end if
					inc(comstep)
				case 23
					if AD4532c1Act<>0 and 0 then
						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							adrset(true,getADR4532c1_Starttime1,getvalptr)
							adrset(true,setADR4532c1_Starttime1,setvalptr)
							for loopi=0 to 19 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4532_Starttime1_L + loopi
									WriteCnt=1
									writestep=Func16
									break
								else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
					end if
					inc(comstep)

				case 24
					if AD4532c1Act<>0 and 0 then

						if flgADR4532c1_RegEdit<>0 then
							ModbusID=AD4532c1
							adrset(true,getADR4532c1_Offset,getvalptr)
							adrset(true,setADR4532c1_Offset,setvalptr)
							for loopi=0 to 9 step 1
								if *getvalptr<>*setvalptr then
									WriteAdr=ADR4532_Offset_L + loopi
									WriteCnt=1
									writestep=Func16
								break
									else
									adrinc(getvalptr)
									adrinc(setvalptr)
								end if
							next
						end if
						
					end if
					inc(comstep)

				case 25
					comstep=100

				'--------------------------------------------------------------
				case 100
					comstep=0
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
			case $0401	'未応答：ｽﾚｰﾌﾞの通信ﾊﾟﾗﾒｰﾀ、通信速度再確認				ErrCodeNo=1000+401
				DispMsg2Item= 30
				DispMsg3Item= 31
			
			end select
			
			'DispMsg1Relay=ON

		errcode = 0

		end if

		
		
		
	end if 'if errcode
 

